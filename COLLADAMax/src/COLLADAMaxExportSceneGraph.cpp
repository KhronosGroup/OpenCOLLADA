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

#include "COLLADAMaxControllerExporter.h"
#include "COLLADAMaxDocumentExporter.h"
#include "COLLADAMaxExportSceneGraph.h"

#include <sstream>
#include <iostream>

namespace COLLADAMax
{

	const String ExportSceneGraph::HELPER_GEOMETRY_ID_SUFFIX ="-helper_geometry";
	const String ExportSceneGraph::JOINT_SID_BASE_NAME = "joint";

	ExportSceneGraph::ExportSceneGraph ( INode * iNode, const COLLADASW::URI& maxFileUri, DocumentExporter const& documentExporter, COLLADABU::IDList& xRefExportFileNames )
            : mExportSelection ( false ),
            mRootNode ( iNode ),
			mMaxFileUri(maxFileUri),
            mDocumentExporter(documentExporter),
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
        for ( INodeXRefSceneGraphListMap::iterator i = mINodeXRefSceneGraphListMap.begin(); i != mINodeXRefSceneGraphListMap.end(); ++i )
        {
            for ( XRefSceneGraphList::iterator j = i->second.begin(); j != i->second.end(); ++j )
            {
			    delete j->exportSceneGraph;
            }
        }
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

        bool shouldExportXRefedFiles = mDocumentExporter.getOptions().getIncludeXRefs();
        bool shouldAddInstanceNodesForXRefs = true;

		int xRefFileCount = mRootNode->GetXRefFileCount();

		for ( int i = 0; i < xRefFileCount; ++i)
		{
#ifdef MAX_2010_OR_NEWER
            if ( mRootNode->GetXRefFlags(i) & XREF_DISABLED )
            {
                continue;
            }
#endif

#ifdef MAX_2010_OR_NEWER
 #ifdef UNICODE
            std::string XRefFileNameString = COLLADABU::StringUtils::wideString2utf8String(mRootNode->GetXRefFile(i).GetFileName().data());
            const char* XRefFileName = XRefFileNameString.c_str();
 #else
			const char* XRefFileName = mRootNode->GetXRefFile(i).GetFileName().data();
 #endif
#else
			const char* XRefFileName = mRootNode->GetXRefFileName(i).data();
#endif
			COLLADASW::URI uri(COLLADASW::URI::nativePathToUri(NativeString(XRefFileName)));
            
			XRefSceneGraph xRefScene;
			xRefScene.exportFileBaseName = mXRefExportFileNames.addId(uri.getPathFileBase(), false);
            xRefScene.exportSceneGraph = new ExportSceneGraph(mRootNode->GetXRefTree(i), uri, mDocumentExporter, mXRefExportFileNames);

            INode* xRefParent = mRootNode->GetXRefParent(i);

            if ( shouldAddInstanceNodesForXRefs )
            {
                mINodeXRefSceneGraphListMap[xRefParent ? xRefParent : mRootNode].push_back(xRefScene);

				isNotEmpty = true;
            }

            if ( shouldExportXRefedFiles )
            {
			    if ( xRefScene.exportSceneGraph->create(false) )
			    {
				    isNotEmpty = true;
			    }
            }
            else
            {
                if ( shouldAddInstanceNodesForXRefs )
                {
                    xRefScene.exportSceneGraph->create(true);
                }
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
    const ExportSceneGraph::XRefSceneGraphList* ExportSceneGraph::getXRefSceneGraphList(INode* node) const
    {
		INodeXRefSceneGraphListMap::const_iterator i = mINodeXRefSceneGraphListMap.find(node);

        if ( i == mINodeXRefSceneGraphListMap.end() )
        {
            return NULL;
        }

        return &i->second;
    }

    const ExportSceneGraph::XRefSceneGraphList ExportSceneGraph::findAllXRefScenes() const
    {
        std::set<const XRefSceneGraph*> set;

		for (INodeXRefSceneGraphListMap::const_iterator i = mINodeXRefSceneGraphListMap.begin(); i != mINodeXRefSceneGraphListMap.end(); ++i)
        {
            for ( XRefSceneGraphList::const_iterator j = i->second.begin(); j != i->second.end(); ++j )
            {
                set.insert(&*j);
            }
        }

        //double copying... could have been evaded by changing return type
        //but I do not want to create/force new conventions... anyway it should
        //not be a big problem since it is, at most, called once per scene.

        ExportSceneGraph::XRefSceneGraphList result;

		for (std::set<const XRefSceneGraph*>::const_iterator i = set.begin(); i != set.end(); ++i)
        {
            result.push_back(**i);
        }

        return result;
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
#ifdef UNICODE
        id += COLLADABU::StringUtils::wideString2utf8String(morphControllerHelperGeometry.morphController->getMorph()->chanBank[morphControllerHelperGeometry.channelBankindex].mName.data());
#else
		id += morphControllerHelperGeometry.morphController->getMorph()->chanBank[morphControllerHelperGeometry.channelBankindex].mName;
#endif
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
