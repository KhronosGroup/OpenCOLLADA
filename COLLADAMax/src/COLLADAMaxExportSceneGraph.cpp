/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAMaxStableHeaders.h"

#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxControllerExporter.h"

#include <sstream>
#include <iostream>

namespace COLLADAMax
{

	const String ExportSceneGraph::HELPER_GEOMETRY_ID_SUFFIX ="-helper_geometry";
	const String ExportSceneGraph::JOINT_SID_BASE_NAME = "joint";

	ExportSceneGraph::ExportSceneGraph ( INode * iNode, const COLLADASW::URI& maxFileUri, COLLADABU::IDList& xRefExportFileNames )
            : mExportSelection ( false ),
            mRootNode ( iNode ),
			mMaxFileUri(maxFileUri),
			mXRefExportFileNames(xRefExportFileNames),
            mRootExportNode ( 0 ),
			mBoneCount(0)
    {
		if ( mMaxFileUri.getScheme().empty() )
			mMaxFileUri.setScheme(COLLADASW::URI::SCHEME_FILE);
	}


	//---------------------------------------------------------------
	ExportSceneGraph::~ExportSceneGraph()
	{
		for ( XRefSceneGraphList::iterator it = mXRefSceneGraphList.begin(); it!=mXRefSceneGraphList.end(); ++it)
			delete it->exportSceneGraph;
	}


    //---------------------------------------------------------------
    bool ExportSceneGraph::create ( bool exportSelection )
    {
        mExportSelection = exportSelection;

        if ( mRootExportNode )
            delete mRootExportNode;

		bool isNotEmpty;
		mRootExportNode = create ( mRootNode, 0, isNotEmpty );

		findReferencedObjects(mRootExportNode);

		int xRefFileCount = mRootNode->GetXRefFileCount();

		for ( int i = 0; i < xRefFileCount; ++i)
		{
			XRefSceneGraph xRefScene;
#ifdef MAX_2010_OR_NEWER
			const char* XRefFileName = mRootNode->GetXRefFile(i).GetFileName().data();
#else
			const char* XRefFileName = mRootNode->GetXRefFileName(i).data();
#endif
			COLLADASW::URI uri(COLLADASW::URI::nativePathToUri(NativeString(XRefFileName)));
			xRefScene.exportFileBaseName = mXRefExportFileNames.addId(uri.getPathFileBase(), false);
			xRefScene.exportSceneGraph = new ExportSceneGraph(mRootNode->GetXRefTree(i), uri, mXRefExportFileNames);
			if ( xRefScene.exportSceneGraph->create(exportSelection) )
			{
				mXRefSceneGraphList.push_back(xRefScene);
				isNotEmpty = true;
			}
			else
			{
				delete xRefScene.exportSceneGraph;
			}
		}

        return isNotEmpty;
    }

    //---------------------------------------------------------------
    ExportNode * ExportSceneGraph::create ( INode *iNode, ExportNode* parent, bool& isInVisualScene)
    {

        ExportNode * exportNode = new ExportNode ( iNode, parent );

		isInVisualScene = isNodeInVisualScene(iNode);

        int numberOfChildren = iNode->NumberOfChildren();

        for ( int i = 0; i < numberOfChildren; ++i )
        {
            INode * child = iNode->GetChildNode ( i );
			bool isChildInVisualScene;
            ExportNode * childExportNode = create ( child, exportNode, isChildInVisualScene );

			exportNode->add( childExportNode );

            if ( isChildInVisualScene )
               isInVisualScene = true;
        }

		exportNode->setId ( mNodeIdList.addId ( NativeString(iNode->GetName()) ) );
		mINodeExportNodeMap[iNode] = exportNode;
		exportNode->createControllerList();
		//createBones(exportNode);
		exportNode->setIsInVisualScene(isInVisualScene);

		return exportNode;
    }

	/*
	void ExportSceneGraph::createBones(INode *iNode, ExportNode* exportNode, bool& isInVisualScene)
	{
		if ( !exportNode->getType() == ExportNode::MESH )
			return;

		ControllerList* controllers = exportNode->getControllerList();
		size_t controllerCount = controllers->getControllerCount();
		for ( size_t i = 0; i < controllerCount; ++i)
		{
			Controller* controller = controllers->getReferencedJoints()
		}

		
		
	}
*/
    //---------------------------------------------------------------
    bool ExportSceneGraph::isNodeInVisualScene ( INode * iNode )
    {
        return ! ( mExportSelection && !iNode->Selected() ) && !iNode->IsHidden();

    }

	//---------------------------------------------------------------
	COLLADASW::String ExportSceneGraph::createJointSid()
	{
		return JOINT_SID_BASE_NAME + COLLADASW::Utils::toString(mBoneCount++);
	}

	//---------------------------------------------------------------
	ExportNode * ExportSceneGraph::getExportNode( INode* iNode ) const
	{
		INodeExportNodeMap::const_iterator it = mINodeExportNodeMap.find(iNode);

		if ( it != mINodeExportNodeMap.end() )
			return it->second;
		else
			return 0;
	}

	//---------------------------------------------------------------
	void ExportSceneGraph::findReferencedObjects( ExportNode* exportNode )
	{
		if ( exportNode->hasControllers() )
		{
			ControllerList* controllerList = exportNode->getControllerList();

			size_t controllerCount = controllerList->getControllerCount();

			for ( size_t j = 0; j < controllerCount; ++j)
			{
				Controller* controller = controllerList->getController(j);

				if ( controller->getType() != Controller::MORPH )
					continue;

				MorphController* morphController = (MorphController*)controller;

				MorphR3* morpher = morphController->getMorph();

				size_t channelBankCount = morpher->chanBank.size();
				for ( size_t i = 0; i<channelBankCount; ++i)
				{
					morphChannel& channel = morpher->chanBank[i];

					if (!channel.mActive || channel.mNumPoints == 0) 
						continue;

					INode* targetINode = channel.mConnection;

					if ( !targetINode )
					{
						MorphControllerHelperGeometry morphControllerHelperGeometry;
						morphControllerHelperGeometry.exportNode = exportNode;
						morphControllerHelperGeometry.morphController = morphController;
						morphControllerHelperGeometry.controllerId = ControllerExporter::getControllerId(*exportNode, controllerCount - j, controllerList->getController(j)->getType());
						morphControllerHelperGeometry.channelBankindex = i;
						mMorphControllerHelperGeometryList.push_back(morphControllerHelperGeometry);
					}
					else
					{
						ExportNode* targetExportNode = getExportNode(targetINode);
						targetExportNode->setIsReferenced(true);
					}
				}

			}
		}

		size_t numberOfChildren = exportNode->getNumberOfChildren();

		for ( size_t i = 0; i < numberOfChildren; ++i )
			findReferencedObjects(exportNode->getChild(i));

	}

	//---------------------------------------------------------------
	String ExportSceneGraph::getMorphControllerHelperId( const MorphControllerHelperGeometry& morphControllerHelperGeometry )
	{
		String id = morphControllerHelperGeometry.controllerId;
		id += HELPER_GEOMETRY_ID_SUFFIX;
		id += COLLADASW::Utils::toString(morphControllerHelperGeometry.channelBankindex);
		id += "-";
		id += morphControllerHelperGeometry.morphController->getMorph()->chanBank[morphControllerHelperGeometry.channelBankindex].mName;
		return id;
	}

	//---------------------------------------------------------------
	bool MorphControllerHelperGeometry::operator<( const MorphControllerHelperGeometry& rhs ) const
	{
		if ( exportNode < rhs.exportNode)
			return true;

		if ( exportNode > rhs.exportNode)
			return false;

		if ( morphController < rhs.morphController)
			return true;

		if ( morphController > rhs.morphController)
			return false;

		if ( channelBankindex < rhs.channelBankindex)
			return true;

		if ( channelBankindex > rhs.channelBankindex)
			return false;

		return false;
	}
}
