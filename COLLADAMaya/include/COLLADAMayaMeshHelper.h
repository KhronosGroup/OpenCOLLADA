/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_MESH_HELPER_H__
#define __COLLADA_MAYA_MESH_HELPER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADASWSource.h"

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
