/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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
