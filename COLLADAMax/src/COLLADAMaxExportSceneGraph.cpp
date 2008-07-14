/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxExportSceneGraph.h"

#include <sstream>
#include <iostream>

namespace COLLADAMax
{


    ExportSceneGraph::ExportSceneGraph ( INode * iNode )
            : mExportSelection ( false ),
            mRootNode ( iNode ),
            mRootExportNode ( 0 )
    {}


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

            exportNode->setId ( mNodeIdList.addId ( exportNode->getINode() ->GetName() ) );
            return exportNode;
        }

        delete exportNode;

        return 0;
    }


    //---------------------------------------------------------------
    bool ExportSceneGraph::exportThisNode ( INode * iNode )
    {
        return ! ( mExportSelection && !iNode->Selected() ) && !iNode->IsHidden();

    }

}
