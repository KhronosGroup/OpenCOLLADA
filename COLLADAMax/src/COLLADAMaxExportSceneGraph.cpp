/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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
