/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaGeometryPolygonExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaSceneGraph.h"
#include <algorithm>
#include <assert.h>
#include <time.h>

#include <maya/MItDependencyNodes.h>
#include <maya/MFnMesh.h>
#include <maya/MItMeshPolygon.h>
#include <maya/MItMeshVertex.h>
#include <maya/MItDag.h>

#include "COLLADASource.h"
#include "COLLADABaseInputElement.h"
#include "COLLADAInputList.h"
#include "COLLADAExtraTechnique.h"


namespace COLLADAMaya
{

    // --------------------------------------------------------
    GeometryPolygonExporter::GeometryPolygonExporter ( COLLADA::StreamWriter* _streamWriter,
            DocumentExporter* _documentExporter )
            : COLLADA::LibraryGeometries ( _streamWriter )
            , mDocumentExporter ( _documentExporter )
            , mPolygonSources ( NULL )
            , mVertexSources ( NULL )
            , triangulated ( false )
            , holeCount ( 0 )
    {
    }

    // --------------------------------------------------------
    GeometryPolygonExporter::~GeometryPolygonExporter ( void ) {}

    // -----------------------------------------------------------------------------------
    void GeometryPolygonExporter::exportPolygonSources ( MFnMesh &fnMesh,
            String meshId,
            MStringArray uvSetNames,
            ColourSetList &colorSets,
            Sources* polygonSources,
            Sources* vertexSources,
            bool hasFaceVertexNorms )
    {
        // Initialize the members
        mMeshId = meshId;
        mUvSetNames = uvSetNames;
        mPolygonSources = polygonSources;
        mVertexSources = vertexSources;
        mHasFaceVertexNormals = hasFaceVertexNorms;
        mColorSets = colorSets;

        // If triangulation is requested, verify that it is feasible by checking with all the mesh polygons

        if ( ExportOptions::exportTriangles() )
        {
            triangulated = true;

            for ( MItMeshPolygon polyIt ( fnMesh.object() ); triangulated && !polyIt.isDone(); polyIt.next() )
            {
                triangulated = polyIt.hasValidTriangulation();
            }
        }

        // If we have a hole in a polygon, we can't write a <polylist>.
        // Either we write <polygons> with holes or we write triangles.
        // Get hole information from the mesh node.
        // The format for the holes information is explained in the MFnMesh documentation.
        MStatus status;
        fnMesh.getHoles ( mHoleInfoArray, mHoleVertexArray, &status );
        holeCount = ( status != MStatus::kSuccess ) ? 0 : ( mHoleInfoArray.length() / 3 );

        // Find how many shaders are used by this instance of the mesh
        MObjectArray shaders;
        MIntArray shaderIndices;
        fnMesh.getConnectedShaders ( 0, shaders, shaderIndices );

        // Find the polygons that correspond to each materials and export them
        uint realShaderCount = ( uint ) shaders.length();
        uint numShaders = ( uint ) max ( ( size_t ) 1, ( size_t ) shaders.length() );

#ifdef _DEBUG
        clock_t startClock, endClock;
#endif
        for ( uint shaderPosition = 0; shaderPosition<numShaders; ++shaderPosition )
        {
            // Export the polygons of the current shader
#ifdef _DEBUG
            startClock = clock();
#endif
            exportShaderPolygons ( fnMesh,
                                   shaderPosition,
                                   realShaderCount,
                                   shaders,
                                   shaderIndices );
#ifdef _DEBUG
            endClock = clock();
            cout << "           Export shader polygons: " << endClock - startClock << endl;
#endif
        }
    }

    //---------------------------------------------------------------
    void GeometryPolygonExporter::exportShaderPolygons ( MFnMesh &fnMesh,
            uint shaderPosition,
            uint realShaderCount,
            MObjectArray shaders,
            const MIntArray shaderIndices )
    {
        /** To get the time */
        clock_t startClock, endClock;

        // The list with the shader polygons with the vertex indexes
        PolygonSourceList shaderPolygons;

        // Just create a polylist, if there are polygons to export
        // If we have holes in the polygon, we have to use <polygons> instead of <polylist>.
        // If we want to export as triangles, we have to use <triangles>.
        COLLADA::PrimitivesBase dummyPrimitivesBase ( mSW );

        // true, if the current shape has one or more polygons, which have one or more holes.
        bool currentShapeIsHoled = false;

        // --------------------------------------------
        // Iterate through all polygons of the current mesh and create them to export
#ifdef _DEBUG
        startClock = clock();
#endif
        uint numPolygons = createShaderPolygons(
            fnMesh, shaderPosition, realShaderCount, shaderIndices, 
            &dummyPrimitivesBase, shaderPolygons, currentShapeIsHoled);
#ifdef _DEBUG
        endClock = clock();
        cout << "                " << shaderPolygons.size() << " Polygons created: " << endClock - startClock << endl;
#endif

        // Just create a polylist, if there are polygons to export
        // If we have holes in the polygon, we have to use <polygons> instead of <polylist>.
        // If we want to export as triangles, we have to use <triangles>.
        COLLADA::PrimitivesBase* primitivesBasePoly = NULL;

        // Just create the polylist, if there are polygons to export
        if ( numPolygons > 0 )
        {
            // Determine the export type
            uint exportType = determinePrimitivesBaseExportType ( currentShapeIsHoled );

            // Now create the real Polylist/Polygons/Triangles element in depend
            // of the current export type. If the export type is POLYLIST, set the vertex count list.
            primitivesBasePoly = createPrimitivesBase ( dummyPrimitivesBase, exportType );

            // Set the number of polygons
            primitivesBasePoly->setCount ( numPolygons );

            // Set the vertex count list, if we have a POLYLIST
            if ( exportType == POLYLIST )
            {
                setVertexCountList ( primitivesBasePoly, &shaderPolygons );
            }

            // Check if the material should be set
            if ( shaderPosition < realShaderCount )
            {
                // Add shader-specific parameters (TexCoords sets).
                // Add symbolic name for the material used on this polygon set.
                MFnDependencyNode shaderFn ( shaders[shaderPosition] );
                String shaderName = shaderFn.name().asChar();
                String materialName = mDocumentExporter->mayaNameToColladaName ( shaderFn.name() );
                primitivesBasePoly->setMaterial ( materialName );
            }

            // Prepare the list for add the vertex indexes
            preparePrimitiveBase ( primitivesBasePoly, exportType );

            // Iterate through the list of polygons and 
            // write them into the collada file.
#ifdef _DEBUG
            startClock = clock();
#endif
            writeShaderPolygons(shaderPolygons, primitivesBasePoly, exportType);
#ifdef _DEBUG
            endClock = clock();
            cout << "                " << shaderPolygons.size() << " Polygons exported: " << endClock - startClock << endl;
#endif
        }

        // Delete the created primitivesBasePoly
        if ( primitivesBasePoly != NULL )
        {
            delete primitivesBasePoly;
            primitivesBasePoly = NULL;
        }

        // Delete the polygons in the list
        for ( uint p=0; p<shaderPolygons.size(); ++p )
        {
            PolygonSource* polygon = shaderPolygons[p];
            delete polygon;
            polygon = NULL;
        }
        shaderPolygons.clear();
    }

    // -----------------------------------------------------------------------------------
    void GeometryPolygonExporter::writeShaderPolygons( 
        PolygonSourceList &shaderPolygons, 
        COLLADA::PrimitivesBase* primitivesBasePoly,
        uint exportType)
    {
        // Iterate through the list of polygons and 
        // write them into the collada file.
        uint numPolygons = shaderPolygons.size();
        for ( uint pp=0; pp<numPolygons; ++pp )
        {
            PolygonSource* currentPolygon = shaderPolygons[pp];

            // Add the open tags for the polygons
            if ( exportType == POLYGONS )
            {
                if ( currentPolygon->isHoled() )
                {
                    ( ( COLLADA::Polygons* ) primitivesBasePoly )->openPolylistHole();
                }
            }

            // Insert the list of indices of the vertex attributes for the polygon list
            Sources& vertexAttributes = currentPolygon->getVertexAttributes();

            uint numVertices = 0;
            size_t numAttributes = vertexAttributes.size();
            if ( numAttributes > 0 )
                numVertices = vertexAttributes[0].mIndexes.size();

            // Initialize the data for polygons with holes
            uint numFaceVertices = currentPolygon->getFaceVertexCounts().size();
            uint currentFaceIndex = 0;
            uint sumOfFaceVertexCounts = currentPolygon->getFaceVertexCounts()[currentFaceIndex];

            // Check if the current face is a normal polygon or a hole and open the corresponding tag.
            if ( exportType == POLYGONS ) 
                openPolygonOrHoleElement ( 
                    primitivesBasePoly, 
                    currentPolygon,
                    currentFaceIndex );

            // --------------------------------------------
            // For every vertex
            for ( uint vertexPosition=0; vertexPosition<numVertices; ++vertexPosition )
            {
                // If we write a holed polygon and the actual vertex position is the last
                // position of the current face, then go to the next face in the list.
                if ( exportType == POLYGONS &&
                    currentPolygon->isHoled() &&
                    vertexPosition == sumOfFaceVertexCounts )
                {
                    // Increment, cause we have found the next face
                    ++currentFaceIndex;

                    // Close the tag for the last face
                    ( ( COLLADA::Polygons* ) primitivesBasePoly )->closeElement();

                    // Get the vertex count of the current face
                    uint currentFaceVertexCount = currentPolygon->getFaceVertexCounts()[currentFaceIndex];

                    // Add the vertex count of the current face to the sum of face vertexes
                    sumOfFaceVertexCounts += currentFaceVertexCount;

                    // Check if the current face is a normal polygon or a hole and open the corresponding tag.
                    openPolygonOrHoleElement ( primitivesBasePoly, currentPolygon, currentFaceIndex );
                }

                // --------------------------------------
                // Write every vertex attribute

                for ( uint kk=0; kk<numAttributes; ++kk )
                {
                    SourceInput& sourceInput = vertexAttributes[kk];
                    std::vector<int>& indexes = sourceInput.mIndexes;

                    if ( vertexPosition < indexes.size() )
                    {
                        int index = indexes[vertexPosition];
                        primitivesBasePoly->appendValues ( index );
                    }
                    else
                    {
                        // Assert, cause the index position is wrong. 
                        // There is something wrong with the created polygons!
                        MGlobal::displayError ( "Index position in vertex attribute is wrong!" );
                        assert ( vertexPosition < indexes.size() ); 
                        return;
                    }
                }
            }

            // Add the tags for the polygons
            if ( exportType == POLYGONS )
            {
                if ( currentPolygon->isHoled() ) ( ( COLLADA::Polygons* ) primitivesBasePoly )->closeElement();

                ( ( COLLADA::Polygons* ) primitivesBasePoly )->closeElement();
            }
        }

        // Finish writing the values of the primitives base. 
        primitivesBasePoly->finish();
    }

    // ----------------------------------------------------------------------------------
    void GeometryPolygonExporter::setVertexCountList ( COLLADA::PrimitivesBase* primitivesBasePoly,
            PolygonSourceList* polygons )
    {
        PolygonSource* polygon;
        std::vector<unsigned long> polyonVertexCountList;

        // Iterate through the polygons
        uint numPolygons = polygons->size();

        for ( uint p=0; p<numPolygons; ++p )
        {
            polygon = ( *polygons ) [p];
            polyonVertexCountList = polygon->getVertexCountList();

            // Iterate through the polygons vertex count list

            for ( uint v=0; v<polyonVertexCountList.size(); ++v )
            {
                // Set vertex count in the list of the POLYLIST
                unsigned long polyonVertexCount = polyonVertexCountList[v];
                primitivesBasePoly->getVCountList().push_back ( polyonVertexCount );
            }
        }
    }

    // ----------------------------------------------------------------------------------
    uint GeometryPolygonExporter::determinePrimitivesBaseExportType ( bool currentShapeIsHoled )
    {
        uint exportType;

        // Just create the polylist, if there are polygons to export

        if ( currentShapeIsHoled && !triangulated )
        {
            exportType = POLYGONS;
        }

        else if ( triangulated )
        {
            exportType = TRIANGLES;
        }

        else
        {
            exportType = POLYLIST;
        }

        return exportType;
    }

    // ----------------------------------------------------------------------------------
    COLLADA::PrimitivesBase* GeometryPolygonExporter::createPrimitivesBase ( COLLADA::PrimitivesBase dummyPoly,
            uint exportType )
    {
        COLLADA::PrimitivesBase* primitivesBasePoly;

        switch ( exportType )
        {

        case POLYGONS:
            primitivesBasePoly = new COLLADA::Polygons ( dummyPoly );
            break;

        case TRIANGLES:
            primitivesBasePoly = new COLLADA::Triangles ( dummyPoly );
            break;

        case POLYLIST:

        default:
            primitivesBasePoly = new COLLADA::Polylist ( dummyPoly );
            break;
        }

        return primitivesBasePoly;
    }

    // ----------------------------------------------------------------------------------
    void GeometryPolygonExporter::preparePrimitiveBase ( COLLADA::PrimitivesBase* polylist,
            uint exportType )
    {
        switch ( exportType )
        {

        case POLYGONS:
            ( ( COLLADA::Polygons* ) polylist )->prepareToAppendValues();
            break;

        case TRIANGLES:
            ( ( COLLADA::Triangles* ) polylist )->prepareToAppendValues();
            break;

        case POLYLIST:

        default:
            ( ( COLLADA::Polylist* ) polylist )->prepareToAppendValues();
            break;
        }
    }

    // ----------------------------------------------------------------------------------
    void GeometryPolygonExporter::openPolygonOrHoleElement ( COLLADA::PrimitivesBase* polylist,
            PolygonSource* poly,
            uint currentFaceIndex )
    {
        bool currentFaceIsHole = checkForHole ( poly, currentFaceIndex );

        if ( currentFaceIsHole )
        {
            ( ( COLLADA::Polygons* ) polylist )->openHole();
        }

        else
        {
            ( ( COLLADA::Polygons* ) polylist )->openPolylist();
        }
    }

    // ----------------------------------------------------------------------------------
    bool GeometryPolygonExporter::checkForHole ( PolygonSource* polygon, uint currentFaceIndex )
    {
        // Check if the current face is a normal polygon or a hole
        bool currentFaceIsHole = false;
        uint numHoles = polygon->getHoleFaces().size();
        for ( uint holeIndex=0; holeIndex<numHoles && !currentFaceIsHole; ++holeIndex )
        {
            uint holeFaceIndex = polygon->getHoleFaces()[holeIndex];
            if ( holeFaceIndex == currentFaceIndex )
            {
                currentFaceIsHole = true;
            }
        }

        return currentFaceIsHole;
    }

    // ----------------------------------------------------------------------------------
    int GeometryPolygonExporter::exportPolygonVertices ( 
            MFnMesh &fnMesh,
            MItMeshPolygon &meshPolygonsIter,
            COLLADA::PrimitivesBase* polylist,
            PolygonSource* polygon )
    {
        // Collect data in order to handle triangle-only export option
        int numPolygons = 0, numVertices = 0;

        // Retrieve the vertex indices and establish the number of polygons (in case of
        // triangulation more than one is possible) and the number of vertexes in the polygon.
        MIntArray vertexIndices;
        retrieveVertexIndices ( &vertexIndices,
                                meshPolygonsIter,
                                polylist,
                                numPolygons,
                                numVertices,
                                polygon->getVertexCountList() );

        // Iterate through the polygons (normally just one polygon,
        // just in case of triangulation it could be more than one)
        for ( int polygonPosition=0; polygonPosition<numPolygons; ++polygonPosition )
        {
            // Put the current face in the list of faces
            uint faceIndex = faceVertexCounts.size();
            faceVertexCounts.push_back ( numVertices );
            polygon->getFaceVertexCounts().push_back ( numVertices );

            // Get the index of the current polygon
            int polyIndex = meshPolygonsIter.index();

            // Buffer the face normal indices
            MIntArray normalIndices;
            if ( mHasFaceVertexNormals )
            {
                fnMesh.getFaceNormalIds ( polyIndex, normalIndices );
            }

            // Iterate through the vertexes of the current polygon
            for ( int j = 0; j < numVertices; j++ )
            {
                // Handle front face vs back face by walking
                // the vertexes backward on the back-face
                int iteratorVertexIndex = vertexIndices[polygonPosition * numVertices + j];

                // Exports the indices of the current vertex
                exportVertexIndices ( fnMesh,
                                      meshPolygonsIter,
                                      polygon,
                                      normalIndices,
                                      iteratorVertexIndex,
                                      numVertices );
            }
        }

        return numPolygons;
    }

    // ----------------------------------------------------------------------------------
    void GeometryPolygonExporter::exportVertexIndices ( 
            MFnMesh &fnMesh,
            MItMeshPolygon &meshPolygonsIter,
            PolygonSource* polygon,
            MIntArray &normalIndices,
            int iteratorVertexIndex,
            int numVertices )
    {
        // Handle front face vs back face by walking the vertices backward on the backface
        int vertexIndex = meshPolygonsIter.vertexIndex ( iteratorVertexIndex );

        // Get the index of the current Polygon
        int polyIndex = meshPolygonsIter.index();

        // Look for holes in this polygon
        // ASSUMPTION: Holes are automatically removed by triangulation.
        // ASSUMPTION: The iterator gives the hole vertices at the end of the enumeration.
        // ASSUMPTION: Hole vertices are never used as surface vertices or repeated between holes or inside a hole.

        if ( meshPolygonsIter.isHoled() && !triangulated )
        {
            // Set the flag to the polygon, that it is a holed one
            polygon->isHoled(true);

            // Put the index of the hole in the list of holes and put the face in the list of faces
            for ( uint holePosition = 0; holePosition < holeCount; ++holePosition )
            {
                if ( mHoleInfoArray[holePosition*3] == polyIndex )
                {
                    uint holeVertexOffset = mHoleInfoArray[holePosition*3+2];
                    if ( holeVertexOffset <= mHoleVertexArray.length() &&
                            mHoleVertexArray[holeVertexOffset] == vertexIndex )
                    {
                        // Decrement the index of the last face for the index of the hole face
                        size_t faceIndex = polygon->getFaceVertexCounts().size();
                        polygon->getFaceVertexCounts()[faceIndex-1] -= ( numVertices - iteratorVertexIndex );

                        // Put the index of the hole in the list of holes
                        polygon->getHoleFaces().push_back ( ( uint ) faceIndex );

                        // put the face in the list of faces
                        polygon->getFaceVertexCounts().push_back ( numVertices - iteratorVertexIndex );
                    }
                }
            }
        }

        // Dump the indices
        size_t numAttributes = polygon->getVertexAttributes().size();

        // Output each vertex attribute we need
        for ( size_t kk = 0; kk < numAttributes; ++kk )
        {
            SourceInput& vertexAttributes = polygon->getVertexAttributes()[kk];

            switch ( vertexAttributes.mType )
            {

            case COLLADA::VERTEX:

            case COLLADA::POSITION:
                vertexAttributes.mIndexes.push_back ( vertexIndex );
                break;

            case COLLADA::NORMAL:

            case COLLADA::GEOTANGENT:

            case COLLADA::GEOBINORMAL:
            {
                if (mHasFaceVertexNormals)
                {
                    int currentVertexIndex = normalIndices[iteratorVertexIndex];
                    vertexAttributes.mIndexes.push_back ( currentVertexIndex );
                }
                else
                {
                    // Assert, if we don't have initialized the normal indices, 
                    // but want to read them out here!
                    MGlobal::displayError("No face vertex normals to proceed!");
                    assert ( mHasFaceVertexNormals );
                    return;
                }
                break;
            }

            case COLLADA::TEXCOORD:
            {
                int uvIndex = 0;
                meshPolygonsIter.getUVIndex ( iteratorVertexIndex, uvIndex, &mUvSetNames[vertexAttributes.mIdx] );
                vertexAttributes.mIndexes.push_back ( uvIndex );
                break;
            }

            case COLLADA::COLOR:
            {
                ColourSet& set = *mColorSets[vertexAttributes.mIdx];
                int colorIndex = 0;

                if ( set.indices.length() > 0 )
                {
                    fnMesh.getFaceVertexColorIndex ( polyIndex, iteratorVertexIndex, colorIndex );

                    if ( colorIndex >= 0 && colorIndex < ( int ) set.indices.length() )
                        colorIndex = set.indices[colorIndex];
                }

                else
                {
#if MAYA_API_VERSION >= 700
                    fnMesh.getColorIndex ( polyIndex, iteratorVertexIndex, colorIndex, &set.name );
#else
                    fnMesh.getFaceVertexColorIndex ( polyIndex, iteratorVertexIndex, colorIndex );
#endif
                }

                // Its possible for colorIndex to be -1, however COLLADA doesn't support
                // non-colored vertexes, so simply use the white color index

                if ( colorIndex < 0 ) colorIndex = set.whiteColorIndex;

                vertexAttributes.mIndexes.push_back ( colorIndex );

                break;
            }

            case COLLADA::UNKNOWN:

            case COLLADA::UV:

            case COLLADA::EXTRA:

            default:
                break; // Not exported/supported
            }
        }
    }

    // ----------------------------------------------------------------------------------
    /**
    * Generate the polygon set inputs.
    */
    void GeometryPolygonExporter::generatePolygonSetInputs ( 
        COLLADA::PrimitivesBase* polylist,
        Sources* vertexAttributes )
    {
        // Generate the polygon set inputs.
        int nextIdx = 1, normalsIdx = -1;
        int offset = 0; // Offset for the input list
        size_t inputCount = mPolygonSources->size();

        for ( size_t p = 0; p < inputCount; ++p )
        {
            SourceInput param = ( *mPolygonSources ) [p];
            COLLADA::SourceBase source = param.mSource;
            COLLADA::Semantics type = param.mType;

            // Figure out which idx this parameter will use
            int foundIdx = -1;

            // For geometric tangents and bi-normals, use the same idx as the normals.
            // For texture tangents and bi-normals, group together for each UV set.

            if ( type == COLLADA::NORMAL || type == COLLADA::GEOTANGENT || type == COLLADA::GEOBINORMAL )
            {
                foundIdx = normalsIdx;
            }

            // Check for duplicate vertex attributes to use their idx

            if ( foundIdx == -1 )
            {
                size_t vertexAttributeCount = vertexAttributes->size();

                for ( size_t v = 0; v < vertexAttributeCount; ++v )
                {
                    if ( ( *vertexAttributes ) [v].mType == type &&
                            ( *vertexAttributes ) [v].mIdx == param.mIdx )
                    {
                        foundIdx = ( int ) v;
                        break;
                    }
                }
            }

            // Check if the vertex is already registered
            bool isVertexSource = SourceInput::containsSourceBase ( mVertexSources, &source );

            // New vertex attribute, so generate a new idx
            bool newIdx = foundIdx == -1;

            if ( newIdx )
            {
                // Assign it the correct offset/idx.
                foundIdx = ( !isVertexSource ) ? nextIdx++ : 0;

                if ( type == COLLADA::NORMAL || type == COLLADA::GEOTANGENT || type == COLLADA::GEOBINORMAL )
                {
                    normalsIdx = foundIdx;
                }
            }

            // Add the per-face, per-vertex input to the polygons description

            if ( !isVertexSource )
            {
                // Get the input list
                COLLADA::InputList* inputList = &polylist->getInputList();

                // Get the generated id of the source for reference
                String sourceId = source.getId();

                // The vertex sources must reference to the vertexes element

                if ( type == COLLADA::VERTEX )
                {
                    String suffix = getSuffixBySemantic ( type );
                    sourceId = mMeshId + suffix;
                }

                if ( type == COLLADA::TEXCOORD )
                {
                    // For texture coordinate-related inputs: set the 'set' attribute.
                    inputList->push_back ( COLLADA::Input ( type, "#" + sourceId, offset++, param.mIdx ) );
                }

                else
                {
                    inputList->push_back ( COLLADA::Input ( type, "#" + sourceId, offset++ ) );
                }
            }


            if ( newIdx )
            {
                // param for the last time.
                vertexAttributes->push_back ( SourceInput(param) );
            }

        }

    }

    // --------------------------------------------------------
    void GeometryPolygonExporter::addHole ( uint index )
    {
        // The hole mustn't already be inserted in the hole faces list.
        std::vector<uint>::iterator searchIter;
        searchIter = find ( holeFaces.begin(), holeFaces.end(), index );
        assert ( searchIter != holeFaces.end() );

        // Ordered insert
        std::vector<uint>::iterator it = holeFaces.begin();

        for ( ; it != holeFaces.end(); ++it )
        {
            if ( index < ( *it ) ) break;
        }

        holeFaces.insert ( searchIter, index );
    }

    // --------------------------------------------------------
    void GeometryPolygonExporter::retrieveVertexIndices ( MIntArray* vertexIndices,
            MItMeshPolygon &meshPolygonsIter,
            COLLADA::PrimitivesBase* polylist,
            int &numPolygons,
            int &numVertices,
            std::vector<unsigned long> &vertexCountList )
    {
        // Get the number of vertices in the current mesh's polygon
        int polygonVertexCount = meshPolygonsIter.polygonVertexCount();
        if ( triangulated && polygonVertexCount > 3 )
        {
            meshPolygonsIter.numTriangles ( numPolygons );
            if ( numPolygons > 0 )
            {
                numVertices = 3;
                MPointArray vertexPositions;
                MIntArray meshVertexIndices;
                meshPolygonsIter.getTriangles ( vertexPositions, meshVertexIndices );
                vertexIndices->setLength ( meshVertexIndices.length() );
                numPolygons = meshVertexIndices.length() / 3;

                // Map the vertex indices to iterator vertex indices so that we can
                // get information from the iterator about normals and such.
                uint meshVertexIndexCount = meshVertexIndices.length();

                for ( uint mvi = 0; mvi < meshVertexIndexCount; ++mvi )
                {
                    int meshVertexIndex = meshVertexIndices[mvi];
                    int polygonVertexCount = meshPolygonsIter.polygonVertexCount();
                    int iteratorVertexIndex = 0;

                    for ( int pv = 0; pv < polygonVertexCount; ++pv )
                    {
                        if ( ( int ) meshPolygonsIter.vertexIndex ( pv ) == meshVertexIndex )
                        {
                            iteratorVertexIndex = pv;
                        }
                    }

                    ( *vertexIndices ) [mvi] = iteratorVertexIndex;
                }

                // Push the number of vertices of the current polygon in the vcount list.
                vertexCountList.push_back ( meshVertexIndexCount );
            }

            else numPolygons = 0;
        }

        else if ( polygonVertexCount >= 3 )
        {
            numPolygons = 1;
            vertexIndices->setLength ( polygonVertexCount );

            for ( int pv = 0; pv < polygonVertexCount; ++pv )
            {
                ( *vertexIndices ) [pv] = pv;
            }

#ifdef VALIDATE_DATA
            // Skip over any duplicate vertices in this face.
            // Very rarely, a cunning user manages to corrupt
            // a face entry on the mesh and somehow configure
            // a face to include the same vertex multiple times.
            // This will cause the read-back of this data to
            // reject the face, and can crash other COLLADA
            // consumers, so better to lose the data here
            //
            for ( uint n = 0; n < vertexIndices->length() - 1; ++n )
            {
                for ( uint m = n + 1; m < vertexIndices->length(); )
                {
                    if ( ( *vertexIndices ) [n] == ( *vertexIndices ) [m] )
                    {
                        vertexIndices->remove ( m );
                    }

                    else ++m;
                }
            }

#endif

            // Get the number of vertices of the current polygon.
            numVertices = ( int ) vertexIndices->length();

            // Push the number of vertices of the current polygon in the vcount list.
            vertexCountList.push_back ( numVertices );
        }
    }

   // --------------------------------------------------------
   uint GeometryPolygonExporter::createShaderPolygons( 
       MFnMesh &fnMesh, 
       const uint shaderPosition, 
       const uint realShaderCount, 
       const MIntArray shaderIndices, 
       COLLADA::PrimitivesBase *dummyPrimitivesBase, 
       PolygonSourceList &shaderPolygons, 
       bool &currentShapeIsHoled )
    {
        // Number of polygons (could also be triangles)
        uint numPolygons = 0; 

        // List for the polygon set inputs.
        Sources polygonSetInputs;

        // Iterate through all polygons of the current mesh and create them to export
        MItMeshPolygon meshPolygonsIter ( fnMesh.object() );
        for ( meshPolygonsIter.reset(); !meshPolygonsIter.isDone(); meshPolygonsIter.next() )
        {
            // Is this polygon shaded by this shader?
            int polyIndex = meshPolygonsIter.index();

            if ( shaderPosition < realShaderCount && 
                ( uint ) shaderIndices[polyIndex] != shaderPosition ) 
                continue;

            if ( shaderPosition >= realShaderCount && 
                ( shaderIndices[polyIndex] >= 0 && 
                shaderIndices[polyIndex] < ( int ) realShaderCount ) ) 
                continue;

            // Initialize the polylist if it is the first polygon to export
            if ( numPolygons == 0 )
            {
                // Generate the polygon set inputs.
                generatePolygonSetInputs ( dummyPrimitivesBase, &polygonSetInputs );
            }

            // Create a polygon to store the vertex indexes to export
            PolygonSource* polygon = new PolygonSource ( polygonSetInputs );

            // Export the vertices and increment polygon count
            uint currentNumPolygons = exportPolygonVertices ( 
                fnMesh,
                meshPolygonsIter,
                dummyPrimitivesBase,
                polygon );

            numPolygons += currentNumPolygons;

            // If we have polygons to export, push it into the polygon list
            if ( currentNumPolygons > 0 )
            {
                shaderPolygons.push_back ( polygon );
                if ( polygon->isHoled() ) currentShapeIsHoled = true;
            }
            else
            {
                delete polygon;
            }
        }

        return numPolygons;
    }
}