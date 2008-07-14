/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
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
