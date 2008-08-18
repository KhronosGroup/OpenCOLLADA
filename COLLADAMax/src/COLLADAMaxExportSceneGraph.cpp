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
#include "COLLADAUtils.h"

#include <sstream>
#include <iostream>

namespace COLLADAMax
{


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

        return ( mRootExportNode = create ( mRootNode ) ) != 0;
    }

    //---------------------------------------------------------------
    ExportNode * ExportSceneGraph::create ( INode *iNode )
    {
        bool exportCurrentNode = exportThisNode ( iNode );

        ExportNode * exportNode;

        exportNode = new ExportNode ( iNode );

        int numberOfChildren = iNode->NumberOfChildren();

        String name = iNode->GetName();

        for ( int i = 0; i < numberOfChildren; ++i )
        {
            INode * child = iNode->GetChildNode ( i );
            ExportNode * childExportNode = create ( child );

            if ( childExportNode )
            {

                exportNode->add
                ( childExportNode );

                exportCurrentNode = true;
            }
        }

        if ( exportCurrentNode )
        {

            exportNode->setId ( mNodeIdList.addId ( exportNode->getINode()->GetName() ) );
			mINodeExportNodeMap[iNode] = exportNode;
            return exportNode;
        }
		else
		{
			delete exportNode;
			return 0;
		}
    }


    //---------------------------------------------------------------
    bool ExportSceneGraph::exportThisNode ( INode * iNode )
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
}
