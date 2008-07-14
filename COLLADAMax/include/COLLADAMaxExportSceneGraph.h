/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
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
