/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxControllerExporter.h"
#include "COLLADAUtils.h"

#include <sstream>
#include <iostream>

namespace COLLADAMax
{

	const String ExportSceneGraph::HELPER_GEOMETRY_ID_SUFFIX ="-helper_geometry";

    ExportSceneGraph::ExportSceneGraph ( INode * iNode )
            : mExportSelection ( false ),
            mRootNode ( iNode ),
            mRootExportNode ( 0 ),
			mBoneCount(0)
    {}


	const String ExportSceneGraph::JOINT_SID_BASE_NAME = "joint";


    //---------------------------------------------------------------
    bool ExportSceneGraph::create ( bool exportSelection )
    {
        mExportSelection = exportSelection;

        if ( mRootExportNode )
            delete mRootExportNode;

		bool isNotEmpty;
		mRootExportNode = create ( mRootNode, 0, isNotEmpty );

		findReferencedObjects(mRootExportNode);

        return isNotEmpty;
    }

    //---------------------------------------------------------------
    ExportNode * ExportSceneGraph::create ( INode *iNode, ExportNode* parent, bool& isInVisualScene)
    {

        ExportNode * exportNode = new ExportNode ( iNode, parent );

		isInVisualScene = isNodeInVisualScene(iNode);

        int numberOfChildren = iNode->NumberOfChildren();

        String name = iNode->GetName();

        for ( int i = 0; i < numberOfChildren; ++i )
        {
            INode * child = iNode->GetChildNode ( i );
			bool isChildInVisualScene;
            ExportNode * childExportNode = create ( child, exportNode, isChildInVisualScene );

			exportNode->add( childExportNode );

            if ( isChildInVisualScene )
               isInVisualScene = true;
        }

 //       if ( exportCurrentNode )
        {

            exportNode->setId ( mNodeIdList.addId ( exportNode->getINode()->GetName() ) );
			mINodeExportNodeMap[iNode] = exportNode;
			exportNode->createControllerList();
			exportNode->setIsInVisualScene(isInVisualScene);
            return exportNode;
        }
/*		else
		{
			delete exportNode;
			return 0;
		}
		*/
    }


    //---------------------------------------------------------------
    bool ExportSceneGraph::isNodeInVisualScene ( INode * iNode )
    {
        return ! ( mExportSelection && !iNode->Selected() ) && !iNode->IsHidden();

    }

	//---------------------------------------------------------------
	COLLADA::String ExportSceneGraph::createJointSid()
	{
		return JOINT_SID_BASE_NAME + COLLADA::Utils::toString(mBoneCount++);
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
		id += COLLADA::Utils::toString(morphControllerHelperGeometry.channelBankindex);
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
