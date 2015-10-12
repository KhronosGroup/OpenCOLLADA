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

#include "COLLADASWSource.h"
#include "COLLADASWBaseInputElement.h"
#include "COLLADASWInputList.h"
#include "COLLADASWExtraTechnique.h"


namespace COLLADAMaya
{

#undef VALIDATE_DATA


    // --------------------------------------------------------
    GeometryPolygonExporter::GeometryPolygonExporter (
    	COLLADASW::StreamWriter* _streamWriter,
        DocumentExporter* _documentExporter )
        : COLLADASW::LibraryGeometries ( _streamWriter )
        , mDocumentExporter ( _documentExporter )
        , mPolygonSources ( NULL )
        , mVertexSources ( NULL )
        , triangulated ( false )
        , holeCount ( 0 )
        , mHasFaceVertexNormals ( false )
        , mShaderPosition ( 0 )
    {
    }

    // --------------------------------------------------------
    GeometryPolygonExporter::~GeometryPolygonExporter ( void ) {}

    // --------------------------------------------------------
    void GeometryPolygonExporter::exportPolygonSources (
        const MObject& mesh,
        const String& meshId,
        MStringArray& uvSetNames,
        MStringArray& colorSetNames,
        Sources* polygonSources,
        Sources* vertexSources,
        const bool hasFaceVertexNorms )
    {
        MFnMesh fnMesh(mesh);
        // Initialize the members
        mMeshId = meshId;
        mUvSetNames = uvSetNames;
        mPolygonSources = polygonSources;
        mVertexSources = vertexSources;
        mHasFaceVertexNormals = hasFaceVertexNorms;
        mColorSetNames = colorSetNames;

        // If triangulation is requested, verify that it is
        // feasible by checking with all the mesh polygons
        if ( ExportOptions::exportTriangles() )
        {
            triangulated = true;

            for ( MItMeshPolygon polyIt ( mesh ); triangulated && !polyIt.isDone(); polyIt.next() )
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

        // Find how many shaders are used by this instance of the mesh.
        // Each instance may apply a number of different materials to different faces.
        // We can use the getConnectedShaders member function of MFnMesh to find out
        // this shader information for each instance.
        mShaders.clear(); mShaderIndices.clear();
        fnMesh.getConnectedShaders ( 0, mShaders, mShaderIndices );

        // Find the polygons that correspond to each materials and export them.
        uint realShaderCount = ( uint ) mShaders.length();
        uint numShaders = ( uint ) std::max ( ( size_t ) 1, ( size_t ) mShaders.length() );

        for ( uint shaderPosition=0; shaderPosition<numShaders; ++shaderPosition )
        {
            // Set the current shader position
            mShaderPosition = shaderPosition;

            // Export the polygons of the current shader
            exportShaderPolygons ( mesh );
        }
    }

    //---------------------------------------------------------------
    void GeometryPolygonExporter::exportShaderPolygons (
        const MObject& mesh)
    {
        // Get the polygons count.
        uint numPolygons = getShaderPolygonsCount ( mesh );

        // Just create a polylist, if there are polygons to export
        // If we have holes in the polygon, we have to use <polygons> instead of <polylist>.
        // If we want to export as triangles, we have to use <triangles>.
        COLLADASW::PrimitivesBase* primitivesBasePoly = NULL;

        // Just create the polylist, if there are polygons in the shader to export
        if ( numPolygons > 0 )
        {
            // Retrieves the information, if we have a hole in any polygon under the current shape
            // (then we have to create a polygon element, instead of a polylist element).
            bool isHoledShape = verifyPolygonsForHoles ( mesh );

            // Determine the export type (polylist/polygon/triangles)
            uint exportType = determinePrimitivesBaseExportType ( isHoledShape );

            // If we should export a polylist and all polygons of the current mesh
            // are triangles, we will export triangles instead of polygons!
            if ( exportType == PolygonSource::POLYLIST )
            {
                if ( verifyTriangulation( mesh ) )
                {
                    exportType = PolygonSource::TRIANGLES;
                    triangulated = true;
                }
            }

            // Create the polylist/polygon/triangles element and set the
            // materials and the vertices count list before writing the
            // list of the polylist/polygon/triangles vertices.
            primitivesBasePoly = preparePrimitivesBase( mesh, numPolygons, exportType );

            // Retrieve the shader polygon vertices and write them directly into the collada file.
            writeShaderPolygons( primitivesBasePoly, exportType, mesh );

        }

        // Delete the created primitivesBasePoly
        if ( primitivesBasePoly != NULL )
        {
            delete primitivesBasePoly;
            primitivesBasePoly = NULL;
        }
    }

    // ----------------------------------------
    bool GeometryPolygonExporter::verifyTriangulation ( const MObject &mesh )
    {
        // Iterate through all polygons of the current mesh
        MItMeshPolygon meshPolygonsIter ( mesh );
        for ( meshPolygonsIter.reset(); !meshPolygonsIter.isDone(); meshPolygonsIter.next() )
        {
            // Is this polygon shaded by this shader?
            uint realShaderCount = ( uint ) mShaders.length();
            uint polyIndex = meshPolygonsIter.index();
            if ( mShaderPosition < realShaderCount &&
                ( uint ) mShaderIndices[polyIndex] != mShaderPosition ) continue;
            if ( mShaderPosition >= realShaderCount &&
                polyIndex < mShaderIndices.length() &&
                ( mShaderIndices[polyIndex] >= 0 &&
                mShaderIndices[polyIndex] < ( int ) realShaderCount ) ) continue;

            // Get the number of vertices in the current mesh's polygon
            if ( meshPolygonsIter.polygonVertexCount() != 3) return false;
        }

        // All polygons are triangles
        return true;
    }

    // ----------------------------------------
    void GeometryPolygonExporter::writeShaderPolygons(
        COLLADASW::PrimitivesBase* primitivesBasePoly,
        const uint exportType,
        const MObject & mesh )
    {
        // Number of polygons (could also be triangles)
        uint numPolygons = 0;

        // Generate the polygon set inputs.
        Sources polygonSetInputs;
        getVerticesInputAttributes( polygonSetInputs );

        // Iterate through all polygons of the current mesh and create them to export
        MItMeshPolygon meshPolygonsIter ( mesh );
        for ( meshPolygonsIter.reset(); !meshPolygonsIter.isDone(); meshPolygonsIter.next() )
        {
            // Is this polygon shaded by this shader?
            uint realShaderCount = ( uint ) mShaders.length();
            uint polyIndex = meshPolygonsIter.index();
            if ( mShaderPosition < realShaderCount &&
                ( uint ) mShaderIndices[polyIndex] != mShaderPosition ) continue;
            if ( mShaderPosition >= realShaderCount &&
                polyIndex < mShaderIndices.length() &&
                ( mShaderIndices[polyIndex] >= 0 &&
                mShaderIndices[polyIndex] < ( int ) realShaderCount ) ) continue;

            // Create a polygon to store the vertex indexes to export
            PolygonSource polygon ( polygonSetInputs );

            // Create the polygon with the initialization data
            MIntArray vertexIndices;
            uint numPolygons = 0, numVertices = 0;
            initializePolygonSource ( mesh, meshPolygonsIter, polygon, vertexIndices, numPolygons, numVertices );

             // If we have polygons to export, push it into the polygon list
            if ( numPolygons > 0 )
            {
                writeElementVertexIndices ( primitivesBasePoly, &polygon, mesh, meshPolygonsIter, exportType, vertexIndices, numPolygons, numVertices );
            }
        }

        primitivesBasePoly->finish();
    }

    // --------------------------------------------------------
    void GeometryPolygonExporter::initializePolygonSource(
        const MObject& mesh,
        MItMeshPolygon &meshPolygonsIter,
        PolygonSource &polygon,
        MIntArray &vertexIndices,
        uint &numPolygons,
        uint &numVertices )
    {
        // Collect data in order to handle triangle-only export option

        // Retrieve the vertex indices and establish the number of polygons (in case of
        // triangulation more than one is possible) and the number of vertexes in the polygon.
        retrieveVertexIndices (
            vertexIndices,
            meshPolygonsIter,
            numPolygons,
            numVertices );

        // Iterate through the polygons (normally just one polygon,
        // just in case of triangulation it could be more than one)
        for ( uint polygonPosition=0; polygonPosition<numPolygons; ++polygonPosition )
        {
            // Put the current face in the list of faces
            polygon.getFaceVertexCounts().push_back ( numVertices );

            // Get the index of the current polygon
            int polyIndex = meshPolygonsIter.index();

            // Iterate through the vertexes of the current polygon
            for ( uint vertexPosition=0; vertexPosition<numVertices; vertexPosition++ )
            {
                // Handle front face vs back face by walking the vertexes backward on the back-face
                int iteratorVertexIndex = vertexIndices[polygonPosition * numVertices + vertexPosition];
                int vertexIndex = meshPolygonsIter.vertexIndex ( iteratorVertexIndex );

                // Look for holes in this polygon
                // ASSUMPTION: Holes are automatically removed by triangulation.
                // ASSUMPTION: The iterator gives the hole vertices at the end of the enumeration.
                // ASSUMPTION: Hole vertices are never used as surface vertices or repeated between holes or inside a hole.
                if ( meshPolygonsIter.isHoled() && !triangulated )
                {
                    handleHoledPolygon(polygon, polyIndex, vertexIndex, numVertices, iteratorVertexIndex);
                }
            }
        }
    }

    // --------------------------------------------------------
    void GeometryPolygonExporter::writeElementVertexIndices(
        COLLADASW::PrimitivesBase* primitivesBasePoly,
        PolygonSource* polygon,
        const MObject& mesh,
        MItMeshPolygon &meshPolygonsIter,
        const uint exportType,
        const MIntArray &vertexIndices,
        const uint numPolygons,
        const uint numVertices )
    {
        MFnMesh fnMesh(mesh);

        // Add the open tags for the polygons
        if ( exportType == PolygonSource::POLYGONS )
        {
            if ( polygon->isHoled() )
            {
                ( ( COLLADASW::Polygons* ) primitivesBasePoly )->openPolylistHoleElement();
            }
        }

        // The face index
        uint currentFaceIndex = 0;

        // Check if the current face is a normal polygon or a hole and open the corresponding tag.
        if ( exportType == PolygonSource::POLYGONS )
        {
            openPolygonOrHoleElement (
                primitivesBasePoly,
                polygon,
                currentFaceIndex );
        }

        // Get the index of the current polygon
        int polyIndex = meshPolygonsIter.index();

        // Buffer the face normal indices
        MIntArray normalIndices;
        if ( mHasFaceVertexNormals )
        {
            fnMesh.getFaceNormalIds ( polyIndex, normalIndices );
        }

        // Iterate through the polygons (normally just one polygon,
        // just in case of triangulation it could be more than one)
        for ( uint polygonPosition=0; polygonPosition<numPolygons; ++polygonPosition )
        {
            // Initialize the data for polygons with holes
            size_t numFaceVertices = polygon->getFaceVertexCounts().size();
            uint currentFaceIndex = 0;
            uint faceVertexCounts = polygon->getFaceVertexCounts()[currentFaceIndex];

            // Iterate through the vertexes of the current polygon
            for ( uint vertexPosition=0; vertexPosition<numVertices; ++vertexPosition )
            {
                // Handle front face vs back face by walking the vertexes backward on the back-face
                uint vertexIndexPosition = polygonPosition * numVertices + vertexPosition;
                int iteratorVertexIndex = vertexIndices[vertexIndexPosition];
                int vertexIndex = meshPolygonsIter.vertexIndex ( iteratorVertexIndex );

                // If we write a holed polygon and the actual vertex position is the last
                // position of the current face, then go to the next face in the list.
                if ( exportType == PolygonSource::POLYGONS &&
                     polygon->isHoled() &&
                     vertexPosition == faceVertexCounts )
                {
                    // Increment, cause we have found the next face
                    ++currentFaceIndex;

                    // Close the tag for the last face
                    ( ( COLLADASW::Polygons* ) primitivesBasePoly )->closeElement();

                    // Get the vertex count of the current face
                    uint currentFaceVertexCount = polygon->getFaceVertexCounts()[currentFaceIndex];
                    // Add the vertex count of the current face to the sum of face vertexes
                    faceVertexCounts += currentFaceVertexCount;

                    // Check if the current face is a normal polygon or a hole and open the corresponding tag.
                    openPolygonOrHoleElement ( primitivesBasePoly, polygon, currentFaceIndex );
                }

                // Write the vertex indices
                writeVertexIndices ( primitivesBasePoly, polygon, vertexIndex, normalIndices, iteratorVertexIndex, meshPolygonsIter, mesh, polyIndex );
            }
        }

        // Add the tags for the polygons
        if ( exportType == PolygonSource::POLYGONS )
        {
            if ( polygon->isHoled() )
                ( ( COLLADASW::Polygons* ) primitivesBasePoly )->closeElement();

            ( ( COLLADASW::Polygons* ) primitivesBasePoly )->closeElement();
        }
    }

    // ----------------------------------------
    bool GeometryPolygonExporter::verifyPolygonsForHoles(
        const MObject &mesh )
    {
        // If we want to export triangles, holes aren't of note.
        if ( triangulated ) return false;

        // Iterate through all polygons of the current mesh and
        // verify their polygons for holes.
        MItMeshPolygon meshPolygonsIter ( mesh );
        for ( meshPolygonsIter.reset(); !meshPolygonsIter.isDone(); meshPolygonsIter.next() )
        {
            // Is this polygon shaded by this shader?
            uint polyIndex = meshPolygonsIter.index();
            uint realShaderCount = ( uint ) mShaders.length();
            if ( mShaderPosition < realShaderCount &&
                ( uint ) mShaderIndices[polyIndex] != mShaderPosition ) continue;
            if ( mShaderPosition >= realShaderCount &&
                polyIndex < mShaderIndices.length() &&
                ( mShaderIndices[polyIndex] >= 0 &&
                mShaderIndices[polyIndex] < ( int ) realShaderCount ) ) continue;

            // Look for holes in this polygon
            // ASSUMPTION: Holes are automatically removed by triangulation.
            // ASSUMPTION: The iterator gives the hole vertices at the end of the enumeration.
            // ASSUMPTION: Hole vertices are never used as surface vertices or repeated between holes or inside a hole.
            if ( meshPolygonsIter.isHoled() && !triangulated )
            {
                return true;
            }
        }

        return false;
    }

    // ----------------------------------------
    void GeometryPolygonExporter::writeVertexCountList(
        COLLADASW::PrimitivesBase* primitivesBase,
        const MObject &mesh )
    {
        // Iterate through all polygons of the current mesh.
        // Check their polygons for holes and retrieve the vertexCountList.
        MItMeshPolygon meshPolygonsIter ( mesh );
        for ( meshPolygonsIter.reset(); !meshPolygonsIter.isDone(); meshPolygonsIter.next() )
        {
            // Is this polygon shaded by this shader?
            uint polyIndex = meshPolygonsIter.index();
            uint realShaderCount = ( uint ) mShaders.length();
            if ( mShaderPosition < realShaderCount &&
                ( uint ) mShaderIndices[polyIndex] != mShaderPosition ) continue;
            if ( mShaderPosition >= realShaderCount &&
                polyIndex < mShaderIndices.length() &&
                ( mShaderIndices[polyIndex] >= 0 &&
                mShaderIndices[polyIndex] < ( int ) realShaderCount ) ) continue;

            // Get the polygon count
            unsigned long vertexCount;
            if ( getPolygonVertexCount ( meshPolygonsIter, vertexCount ) )
                primitivesBase->appendValues( vertexCount );
        }
    }

    // ----------------------------------------
    bool GeometryPolygonExporter::getPolygonVertexCount(
        MItMeshPolygon &meshPolygonsIter,
        unsigned long &numVertices )
    {
        bool addVertexCount = false;

        // Establish the number of vertexes in the polygon.
        // We don't need the vertex count list for triangulation
        if ( triangulated ) return addVertexCount;

        // The number of vertices
        numVertices = 0;

        // Retrieve the vertices and increment polygon count
        // Get the number of vertices in the current mesh's polygon
        unsigned long polygonVertexCount = meshPolygonsIter.polygonVertexCount();
        if ( polygonVertexCount >= 3 )
        {
#ifdef VALIDATE_DATA
            // Skip over any duplicate vertices in this face.
            // Very rarely, a cunning user manages to corrupt
            // a face entry on the mesh and somehow configure
            // a face to include the same vertex multiple times.
            // This will cause the read-back of this data to
            // reject the face, and can crash other COLLADA
            // consumers, so better to lose the data here
            MIntArray vertexIndices;
            vertexIndices.setLength ( polygonVertexCount );
            for ( int pv = 0; pv < polygonVertexCount; ++pv )
            {
                vertexIndices[pv] = pv;
            }

            for ( uint n = 0; n < vertexIndices.length() - 1; ++n )
            {
                for ( uint m = n + 1; m < vertexIndices.length(); )
                {
                    if ( vertexIndices[n] == vertexIndices[m] )
                    {
                        vertexIndices.remove ( m );
                    }
                    else ++m;
                }
            }
            // Get the number of vertices of the current polygon.
            numVertices = vertexIndices.length();
#else
            // Get the number of vertices of the current polygon.
            numVertices = polygonVertexCount;
#endif

            addVertexCount = true;
        }

        return addVertexCount;
    }

    // ----------------------------------------
    uint GeometryPolygonExporter::getShaderPolygonsCount(
        const MObject &mesh )
    {
        uint numPolygons = 0;

        // Iterate through all polygons of the current mesh.
        // Check their polygons for holes and retrieve the vertexCountList.
        MItMeshPolygon meshPolygonsIter ( mesh );
        for ( meshPolygonsIter.reset(); !meshPolygonsIter.isDone(); meshPolygonsIter.next() )
        {
            // Is this polygon shaded by this shader?
            uint polyIndex = meshPolygonsIter.index();
            uint realShaderCount = ( uint ) mShaders.length();
            if ( mShaderPosition < realShaderCount &&
                ( uint ) mShaderIndices[polyIndex] != mShaderPosition ) continue;
            if ( mShaderPosition >= realShaderCount &&
                polyIndex < mShaderIndices.length() &&
                ( mShaderIndices[polyIndex] >= 0 &&
                mShaderIndices[polyIndex] < ( int ) realShaderCount ) ) continue;

            // Get the polygon count
            uint numMeshPolygons = 0, numVertices = 0;

            // Get the number of vertices in the current mesh's polygon
            int polygonVertexCount = meshPolygonsIter.polygonVertexCount();
            if ( triangulated && polygonVertexCount > 3 )
            {
                int numTriangles;
                meshPolygonsIter.numTriangles ( numTriangles );
                if ( numTriangles > 0 ) numMeshPolygons = (uint) numTriangles;
            }
            else if ( polygonVertexCount >= 3 )
            {
                numMeshPolygons = 1;
            }

           numPolygons += numMeshPolygons;
        }

        return numPolygons;
    }

    // --------------------------------------------------------
    void GeometryPolygonExporter::retrieveVertexIndices (
        MIntArray &vertexIndices,
        MItMeshPolygon &meshPolygonsIter,
        uint &numPolygons,
        uint &numVertices )
    {
        // Get the number of vertices in the current mesh's polygon
        int polygonVertexCount = meshPolygonsIter.polygonVertexCount();
        if ( triangulated && polygonVertexCount > 3 )
        {
            int numTriangles;
            meshPolygonsIter.numTriangles ( numTriangles );
            if ( numTriangles > 0 )
            {
                numVertices = 3;
                MPointArray vertexPositions;
                MIntArray meshVertexIndices;
                meshPolygonsIter.getTriangles ( vertexPositions, meshVertexIndices );
                vertexIndices.setLength ( meshVertexIndices.length() );
                numPolygons = meshVertexIndices.length() / numVertices;

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
                    vertexIndices[mvi] = iteratorVertexIndex;
                }
            }
            else numPolygons = 0;
        }
        else if ( polygonVertexCount >= 3 )
        {
            numPolygons = 1;
            vertexIndices.setLength ( polygonVertexCount );
            for ( int pv = 0; pv < polygonVertexCount; ++pv )
            {
                vertexIndices[pv] = pv;
            }

#ifdef VALIDATE_DATA
            // Skip over any duplicate vertices in this face.
            // Very rarely, a cunning user manages to corrupt
            // a face entry on the mesh and somehow configure
            // a face to include the same vertex multiple times.
            // This will cause the read-back of this data to
            // reject the face, and can crash other COLLADA
            // consumers, so better to lose the data here
            for ( uint n = 0; n < vertexIndices.length() - 1; ++n )            {
                for ( uint m = n + 1; m < vertexIndices.length(); )
                {
                    if ( vertexIndices[n] == vertexIndices[m] )
                    {
                        vertexIndices.remove ( m );
                    }
                    else ++m;
                }
            }
            // Get the number of vertices of the current polygon.
            numVertices = vertexIndices->length();
#else
            // Get the number of vertices of the current polygon.
            numVertices = polygonVertexCount;
#endif
        }
    }

    // ----------------------------------------------------------------------------------
    uint GeometryPolygonExporter::determinePrimitivesBaseExportType ( const bool currentShapeIsHoled )
    {
        uint exportType;

        // Just create the polylist, if there are polygons to export
        if ( currentShapeIsHoled && !triangulated )
        {
            exportType = PolygonSource::POLYGONS;
        }
        else if ( triangulated )
        {
            exportType = PolygonSource::TRIANGLES;
        }
        else
        {
            exportType = PolygonSource::POLYLIST;
        }

        return exportType;
    }

    // ----------------------------------------------------------------------------------
    COLLADASW::PrimitivesBase* GeometryPolygonExporter::createPrimitivesBase ( const uint baseExportType )
    {
        COLLADASW::PrimitivesBase* primitivesBasePoly;

        switch ( baseExportType )
        {
        case PolygonSource::POLYGONS:
            primitivesBasePoly = new COLLADASW::Polygons ( mSW );
            break;
        case PolygonSource::TRIANGLES:
            primitivesBasePoly = new COLLADASW::Triangles ( mSW );
            break;
        case PolygonSource::POLYLIST:
        default:
            primitivesBasePoly = new COLLADASW::Polylist ( mSW );
            break;
        }

        return primitivesBasePoly;
    }

    // ----------------------------------------------------------------------------------
    void GeometryPolygonExporter::openPolygonOrHoleElement (
        COLLADASW::PrimitivesBase* polylist,
        PolygonSource* poly,
        const uint currentFaceIndex )
    {
        bool currentFaceIsHole = checkForHole ( poly, currentFaceIndex );
        if ( currentFaceIsHole )
        {
            ( ( COLLADASW::Polygons* ) polylist )->openHoleElement();
        }
        else
        {
            ( ( COLLADASW::Polygons* ) polylist )->openPolylistElement();
        }
    }

    // ----------------------------------------------------------------------------------
    bool GeometryPolygonExporter::checkForHole ( const PolygonSource* polygon, const uint currentFaceIndex )
    {
        // Check if the current face is a normal polygon or a hole
        bool currentFaceIsHole = false;
        size_t numHoles = polygon->getHoleFaces().size();
        for ( size_t holeIndex=0; holeIndex<numHoles && !currentFaceIsHole; ++holeIndex )
        {
            uint holeFaceIndex = polygon->getHoleFaces()[holeIndex];
            if ( holeFaceIndex == currentFaceIndex )
            {
                currentFaceIsHole = true;
            }
        }

        return currentFaceIsHole;
    }

    // ---------------------------------------------
    void GeometryPolygonExporter::handleHoledPolygon(
        PolygonSource &polygon,
        const int polyIndex,
        const int vertexIndex,
        const int numVertices,
        const int iteratorVertexIndex )
    {
        // Set the flag to the polygon, that it is a holed one
        polygon.isHoled(true);

        // Put the index of the hole in the list of holes and put the face in the list of faces
        for ( uint holePosition=0; holePosition<holeCount; ++holePosition )
        {
            if ( mHoleInfoArray[holePosition*3] == polyIndex )
            {
                uint holeVertexOffset = mHoleInfoArray[holePosition*3+2];
                if ( holeVertexOffset <= mHoleVertexArray.length() &&
                    mHoleVertexArray[holeVertexOffset] == vertexIndex )
                {
                    // Decrement the index of the last face for the index of the hole face
                    size_t faceIndex = polygon.getFaceVertexCounts().size();
                    polygon.getFaceVertexCounts()[faceIndex-1] -= ( numVertices - iteratorVertexIndex );

                    // Put the index of the hole in the list of holes
                    polygon.getHoleFaces().push_back ( ( uint ) faceIndex );

                    // put the face in the list of faces
                    polygon.getFaceVertexCounts().push_back ( numVertices - iteratorVertexIndex );
                }
            }
        }
    }

    // ---------------------------------------------
    void GeometryPolygonExporter::getVerticesInputAttributes( Sources &vertexAttributes )
    {
        // Generate the polygon set inputs.
        int nextIdx = 1, normalsIdx = -1, textureIdx = -1;
        int offset = 0; // Offset for the input list

        size_t inputCount = mPolygonSources->size();
        for ( size_t p = 0; p < inputCount; ++p )
        {
            const SourceInput param = ( *mPolygonSources ) [p];
            const COLLADASW::SourceBase source = param.getSource();
            const COLLADASW::InputSemantic::Semantics type = param.getType();

            // Figure out which idx this parameter will use
            int foundIdx = -1;

            // For geometric tangents and bi-normals, use the same idx as the normals.
            if ( type == COLLADASW::InputSemantic::TANGENT || type == COLLADASW::InputSemantic::BINORMAL )
            {
                foundIdx = normalsIdx;
            }
            // For texture tangents and bi-normals, group together for each UV set.
            if ( type == COLLADASW::InputSemantic::TEXBINORMAL )
            {
                foundIdx = textureIdx;
            }

            // Check for duplicate vertex attributes to use their idx
            if ( foundIdx == -1 )
            {
                size_t vertexAttributeCount = vertexAttributes.size();
                for ( size_t v = 0; v < vertexAttributeCount; ++v )
                {
                    if ( vertexAttributes[v].getType() == type &&
                        vertexAttributes[v].getIdx() == param.getIdx() )
                    {
                        foundIdx = ( int ) v;
                        break;
                    }
                }
            }

            // New vertex attribute, so generate a new idx
            bool newIdx = (foundIdx == -1);
            if ( newIdx )
            {
                // param for the last time.
                vertexAttributes.push_back ( SourceInput(param) );
            }

            // For geometric tangents and bi-normals, use the same idx as the normals.
            if ( type == COLLADASW::InputSemantic::NORMAL )
            {
                normalsIdx = (int)vertexAttributes.size () - 1;
            }
            // For texture tangents and bi-normals, group together for each UV set.
            if ( type == COLLADASW::InputSemantic::TEXTANGENT )
            {
                textureIdx = (int)vertexAttributes.size () - 1;
            }
        }
    }

    // ---------------------------------------------
    void GeometryPolygonExporter::getPolygonInputAttributes ( COLLADASW::InputList &inputList )
    {
        // Generate the polygon set inputs.
        int nextIdx = 1, normalsIdx = -1;
        int offset = 0; // Offset for the input list

        size_t inputCount = mPolygonSources->size();
        for ( size_t p = 0; p < inputCount; ++p )
        {
            const SourceInput param = ( *mPolygonSources ) [p];
            const COLLADASW::SourceBase source = param.getSource();
            const COLLADASW::InputSemantic::Semantics type = param.getType();

            // Check if the vertex is already registered
            bool isVertexSource = SourceInput::containsSourceBase ( mVertexSources, &source );

            // Add the per-face, per-vertex input to the polygons description
            if ( !isVertexSource )
            {
                // Get the generated id of the source for reference
                String sourceId = source.getId();

                // The vertex sources must reference to the vertexes element
                if ( type == COLLADASW::InputSemantic::VERTEX )
                {
                    String suffix = getSuffixBySemantic ( type );
                    sourceId = mMeshId + suffix;
                }

                if ( type == COLLADASW::InputSemantic::TEXCOORD )
                {
                    // For texture coordinate-related inputs: set the 'set' attribute.
                    if ( param.getIdx () >= 0 )
                        inputList.push_back ( COLLADASW::Input ( type, COLLADASW::URI ( EMPTY_STRING, sourceId ), offset++, param.getIdx() ) );
                    else
                        inputList.push_back ( COLLADASW::Input ( type, COLLADASW::URI ( EMPTY_STRING, sourceId ), offset++ ) );
                }
                else if ( type == COLLADASW::InputSemantic::TANGENT || type == COLLADASW::InputSemantic::BINORMAL || type == COLLADASW::InputSemantic::TEXBINORMAL )
                {
                    // Tangents and binormals can use the same index than the normals.
                    // Texture binormals can use the index list of texture tangents.
                    if ( param.getIdx () >= 0 )
                        inputList.push_back ( COLLADASW::Input ( type, COLLADASW::URI ( EMPTY_STRING, sourceId ), offset-1, param.getIdx() ) );
                    else
                        inputList.push_back ( COLLADASW::Input ( type, COLLADASW::URI ( EMPTY_STRING, sourceId ), offset-1 ) );
                }
                else
                {
                    if ( param.getIdx () >= 0 )
                        inputList.push_back ( COLLADASW::Input ( type, COLLADASW::URI ( EMPTY_STRING, sourceId ), offset++, param.getIdx () ) );
                    else
                        inputList.push_back ( COLLADASW::Input ( type, COLLADASW::URI ( EMPTY_STRING, sourceId ), offset++ ) );
                }
            }
        }
    }

    // --------------------------------------------------------
    void GeometryPolygonExporter::addHole ( uint index )
    {
        // The hole mustn't already be inserted in the hole faces list.
        std::vector<uint>::iterator searchIter;
        searchIter = find ( mHoleFaces.begin(), mHoleFaces.end(), index );
		COLLADABU_ASSERT ( searchIter != mHoleFaces.end() );

        // Ordered insert
        std::vector<uint>::iterator it = mHoleFaces.begin();
        for ( ; it != mHoleFaces.end(); ++it )
        {
            if ( index < ( *it ) ) break;
        }

        mHoleFaces.insert ( searchIter, index );
    }

    // --------------------------------------------------------
    void GeometryPolygonExporter::writeVertexIndices (
        COLLADASW::PrimitivesBase* primitivesBasePoly,
        PolygonSource *polygon,
        const int vertexIndex,
        const MIntArray &normalIndices,
        const int iteratorVertexIndex,
        MItMeshPolygon &meshPolygonsIter,
        const MObject& mesh,
        const int polyIndex )
    {
        MFnMesh fnMesh(mesh);

        // Dump the indices
        size_t numAttributes = polygon->getVertexAttributes().size();

        // Output each vertex attribute we need
        for ( size_t kk=0; kk<numAttributes; ++kk )
        {
            const SourceInput& vertexAttributes = polygon->getVertexAttributes()[kk];
            COLLADASW::InputSemantic::Semantics type = vertexAttributes.getType();
            switch ( vertexAttributes.getType() )
            {
            case COLLADASW::InputSemantic::VERTEX:
            case COLLADASW::InputSemantic::POSITION:
                primitivesBasePoly->appendValues ( vertexIndex );
                break;
            case COLLADASW::InputSemantic::NORMAL:
            case COLLADASW::InputSemantic::TANGENT:
            case COLLADASW::InputSemantic::BINORMAL:
                {
                    if (mHasFaceVertexNormals)
                    {
                        // The tangent and the binormal can use the index of the normal
                        int currentVertexIndex = normalIndices [iteratorVertexIndex];
                        primitivesBasePoly->appendValues ( currentVertexIndex );
                    }
                    else
                    {
                        // Assert, if we don't have initialized the normal indices,
                        // but want to read them out here!
                        MGlobal::displayError("No face vertex normals to proceed!");
                        COLLADABU_ASSERT ( mHasFaceVertexNormals );
                        return;
                    }
                }
                break;
            case COLLADASW::InputSemantic::TEXTANGENT:
            case COLLADASW::InputSemantic::TEXBINORMAL:
                {
                    // The texture binormal can use the index of the texture tangent.
                    unsigned int texTangentIndex2 = meshPolygonsIter.tangentIndex ( iteratorVertexIndex );
                    primitivesBasePoly->appendValues ( texTangentIndex2 );
                }
                break;
            case COLLADASW::InputSemantic::TEXCOORD:
                {
                    int uvIndex = 0;
                    int idx = vertexAttributes.getIdx();
                    meshPolygonsIter.getUVIndex ( iteratorVertexIndex, uvIndex, &mUvSetNames[idx] );
                    primitivesBasePoly->appendValues ( uvIndex );
                }
                break;
            case COLLADASW::InputSemantic::COLOR:
                {
                    MString& colorSetName = mColorSetNames[vertexAttributes.getIdx()];
                    int colorIndex = 0;
                    {
#if MAYA_API_VERSION >= 700
						MStatus status = fnMesh.getColorIndex ( polyIndex, iteratorVertexIndex, colorIndex, &colorSetName );
						if (status && colorIndex == -1)
						{
							// if vertex has no color, use default color (last color in color source)
							MColorArray colors;
							fnMesh.getColors(colors, &colorSetName);
							colorIndex = colors.length();
						}
#else
                        fnMesh.getFaceVertexColorIndex ( polyIndex, iteratorVertexIndex, colorIndex );
#endif
                    }
                    primitivesBasePoly->appendValues ( colorIndex );
                }
                break;
            case COLLADASW::InputSemantic::UNKNOWN:
            case COLLADASW::InputSemantic::UV:
//            case COLLADASW::EXTRA:
            default:
                break; // Not exported/supported
            }
        }
    }

    // --------------------------------------------------------
    COLLADASW::PrimitivesBase* GeometryPolygonExporter::preparePrimitivesBase(
        const MObject& mesh,
        const uint numPolygons,
        const uint exportType )
    {
        // Just create a polylist, if there are polygons to export
        // If we have holes in the polygon, we have to use <polygons> instead of <polylist>.
        // If we want to export as triangles, we have to use <triangles>.
        COLLADASW::PrimitivesBase* primitivesBasePoly = createPrimitivesBase ( exportType );

        // Begin to write.
        primitivesBasePoly->openPrimitiveElement();

        // Check if the material should be set
        uint realShaderCount = ( uint ) mShaders.length();
        if ( mShaderPosition < realShaderCount )
        {
            // Add shader-specific parameters (TexCoords sets).
            // Add symbolic name for the material used on this polygon set.
            MFnDependencyNode shaderFn ( mShaders[mShaderPosition] );
            String shaderName = shaderFn.name().asChar();
            String materialName = DocumentExporter::mayaNameToColladaName ( shaderFn.name() );
            primitivesBasePoly->appendMaterial ( materialName );
        }

        // Set the number of polygons
        primitivesBasePoly->appendCount ( numPolygons );

        // Get the polygon input list
        COLLADASW::InputList& inputList = primitivesBasePoly->getInputList();
        getPolygonInputAttributes ( inputList );
        primitivesBasePoly->appendInputList();

        // Set the vertex count list, if we have a POLYLIST
        if ( exportType == PolygonSource::POLYLIST )
        {
            // Retrieve the vertex count list for the polylist element.
            primitivesBasePoly->openVertexCountListElement();
            writeVertexCountList ( primitivesBasePoly, mesh );
            primitivesBasePoly->closeElement();
        }

        if ( exportType != PolygonSource::POLYGONS )
        {
            // Prepare the list for add the vertex indexes
            primitivesBasePoly->openPolylistElement();
        }

        return primitivesBasePoly;
    }

}
