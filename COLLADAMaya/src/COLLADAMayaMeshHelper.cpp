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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaMeshHelper.h"
#include "COLLADAMayaDagHelper.h"

#include <maya/MDagPathArray.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MFnDirectionalLight.h>
#include <maya/MFnLight.h>
#include <maya/MFnMesh.h>
#include <maya/MFnTransform.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MItMeshPolygon.h>
#include <maya/MTransformationMatrix.h>
#include <maya/MSelectionMask.h>
#include <maya/MSelectionList.h>


namespace COLLADAMaya
{

    // Find all the history nodes of a specific type
    void MeshHelper::getHistoryNodes ( const MObject& mesh, MFn::Type nodeType, MObjectArray& historyNodes )
    {
        MFnDagNode meshFn ( mesh );

        // Look for the given node type in the mesh's history.
        MStringArray historyNodeNames;
        MGlobal::executeCommand ( MString ( "listHistory  -bf -pdo true " ) + meshFn.fullPathName() + ";", historyNodeNames );
        uint historyNodeCount = historyNodeNames.length();

        for ( uint i = 0; i < historyNodeCount; ++i )
        {
            MObject historyNode = DagHelper::getNode ( historyNodeNames[i] );

            if ( historyNode.hasFn ( nodeType ) ) historyNodes.append ( historyNode );
        }
    }

    // Retrieve the color set information for this mesh
    void MeshHelper::getMeshValidColorSets ( const MObject &mesh, ColourSetList &colorSets )
    {
        if ( !mesh.hasFn ( MFn::kMesh ) ) return;

        MFnMesh meshFn ( mesh );

        uint colorSetCount = 0;

        MStringArray colorSetNames;

        // Starting from Maya 7.0, Color sets are the way to go!
#if MAYA_API_VERSION >= 700

        // Collect the color set names;
        meshFn.getColorSetNames ( colorSetNames );

        colorSetCount = colorSetNames.length();

        // Fill in the return information
        for ( uint i = 0; i < colorSetCount; ++i )
        {
            ColourSet* set = new ColourSet();
            set->name = colorSetNames[i];
            set->isBlankSet = false;
            colorSets.push_back ( set );
        }

#endif

        // Look for polyColorPerVertex nodes
        // Match them with the color set names.
        ColourSet* blankSet = NULL;

        MObjectArray polyColorPerVertexNodes;

        getHistoryNodes ( mesh, MFn::kPolyColorPerVertex, polyColorPerVertexNodes );

        for ( uint i = 0; i < polyColorPerVertexNodes.length(); ++i )
        {
            MFnDependencyNode nodeFn ( polyColorPerVertexNodes[i] );
            MPlug colorSetNamePlug = nodeFn.findPlug ( ATTR_COLOR_NAME ); // "colorName"
            MString nameString;
            colorSetNamePlug.getValue ( nameString );

            if ( nameString.length() == 0 && blankSet == NULL )
            {
                // Support finding/exporting one blank polyColorPerVertex node
                blankSet = new ColourSet();
                blankSet->name = BLANK_COLORSET_NAME;
                blankSet->polyColorPerVertexNode = polyColorPerVertexNodes[i];
                blankSet->isBlankSet = true;
                colorSets.push_back ( blankSet );
            }

            uint colorSetIndex;

            for ( colorSetIndex = 0; colorSetIndex < colorSetCount; ++colorSetIndex )
            {
                if ( colorSetNames[colorSetIndex] == nameString )
                {
                    colorSets[colorSetIndex]->polyColorPerVertexNode = polyColorPerVertexNodes[i];
                    break;
                }
            }
        }

#if MAYA_API_VERSION < 700

        if ( blankSet == NULL )
        {
            // Support checking the mesh directly for a color set, as it
            // has the same interface as the polyColorPerVertex node for pre-Maya 7.0 vertex colors
            blankSet = new ColourSet();
            blankSet->name = BLANK_COLORSET_NAME;
            blankSet->polyColorPerVertexNode = mesh;
            blankSet->isBlankSet = true;
            colorSets.push_back ( blankSet );
        }

#else

        // Get the base plug for the color sets information
        // and figure out the logical index for each color set name
        MPlug basePlug = meshFn.findPlug ( ATTR_COLORSET );

        uint basePlugElementCount = basePlug.numElements();

        for ( uint i = 0; i < basePlugElementCount; ++i )
        {
            MPlug elementPlug = basePlug.elementByPhysicalIndex ( i );
            MPlug namePlug = DagHelper::getChildPlug ( elementPlug, ATTR_COLORSET_NAME ); // "colorSetName"
            MString nameString;
            namePlug.getValue ( nameString );

            if ( nameString.length() == 0 ) continue;

            for ( uint j = 0; j < colorSetCount; ++j )
            {
                if ( colorSetNames[j] == nameString )
                {
                    MPlug p = DagHelper::getChildPlug ( elementPlug, ATTR_COLORSET_POINTS ); // "colorSetPoints"
                    colorSets[j]->arrayPlug = p;
                }
            }
        }

#endif
    }

}