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

#ifndef __COLLADA_MAYA_MESH_HELPER_H__
#define __COLLADA_MAYA_MESH_HELPER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADASource.h"

#include <maya/MPlug.h>
#include <maya/MIntArray.h>

namespace COLLADAMaya
{

    struct ColourSet
    {
        MString name;
        MObject polyColorPerVertexNode;
        MPlug arrayPlug;
        MIntArray indices;
        bool isBlankSet;
        bool isVertexColor;
        int whiteColorIndex;
    };

    typedef std::vector<ColourSet*> ColourSetList;

    class MeshHelper
    {

    public:
        /** Find all the history nodes of a specific type */
        static void getHistoryNodes ( const MObject& mesh, MFn::Type nodeType, MObjectArray& historyNodes );

        /** Get the mesh's color sets information (Maya 7.0+) */
        static void getMeshValidColorSets ( const MObject& mesh, ColourSetList& colorSets );

    private:

        /** Don't create an object of this class. */
        MeshHelper() {};

    };
}

#endif // __COLLADA_MAYA_MESH_HELPER_H__
