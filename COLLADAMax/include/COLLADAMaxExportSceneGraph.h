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


#ifndef __COLLADAMAX_EXPORTSCENEGRAPH_H__
#define __COLLADAMAX_EXPORTSCENEGRAPH_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAMaxExportNode.h"
#include "COLLADAIDList.h"

#include <map>

namespace COLLADAMax
{

    /** Class to build a scene graph of all nodes that should be exported. It
     allows to store additional data for each node.*/

    class ExportSceneGraph
    {

    private:
        /** True if only the selection should be exported, false if the entire scene should be exported.*/
        bool mExportSelection;

        /** The root export node.*/
        ExportNode * mRootExportNode;

        /** The root INode.*/
        INode * mRootNode;

        /** Holds the unique ids of the nodes.*/
        COLLADA::IDList mNodeIdList;

    public:
        ExportSceneGraph ( INode * iNode );
        ~ExportSceneGraph()
        {}

        /** Creates the export scene graph.
        @a return returns true if there are nodes to export and false otherwise.*/
        bool create ( bool exportSelection );

        /** Returns the root export node.*/
        ExportNode * getRootExportNode() const
        {
            return mRootExportNode;
        }

    private:
        ExportSceneGraph ( const ExportSceneGraph & exportSceneGraph );
        ExportSceneGraph & operator= ( const ExportSceneGraph & exportSceneGraph );

        /** Creates the export scene graph.*/
        ExportNode * create ( INode *iNode );

        /** Returns true if @a iNode should be exported, false otherwise.
        The result of this member function depends on user options and on the selection status of the INode.*/
        bool exportThisNode ( INode * iNode );


    };
}


#endif //__EXPORTSCENEGRAPH_H__
