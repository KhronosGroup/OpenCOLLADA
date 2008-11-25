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

#ifndef __COLLADA_MAYA_GEOMETRY_IMPORTER_H__
#define __COLLADA_MAYA_GEOMETRY_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADAFWMesh.h"


namespace COLLADAMaya
{

    /** Declares the importer implementation to import the geometries. */
    class GeometryImporter : public BaseImporter
    {

    private:

        /** The current transform object, for which the geometries should be created. */
        MObject mTransformObject;

        /** A pointer to the current geometry instance to import. */
        domGeometryRef mGeometryRef;

        /** A pointer to the current mesh object to import. */
        domMeshRef mMeshRef;

    public:

        /** Constructor. */
        GeometryImporter ( DocumentImporter* documentImporter, daeDocument* daeDoc );

        /** Destructor. */
        virtual ~GeometryImporter () {}

        /** Imports all geometries of the current dae element. */
        void importGeometries ( MObject& transformObject, domNode& node );

    private:

        /** Imports the data of the current geometry element. */
        void importGeometry ( domInstance_geometryRef instanceGeometryRef );

        /** Imports the data of the current mesh element. */
        bool importMesh ( const COLLADAFW::Mesh* mesh );

        /**
         * Creates a maya mesh object from the current polylist array.
         * @param mesh A pointer to the COLLADAFramework mesh object, which holds all required 
         *              data to create the mesh.
         * @param positionsSource A pointer to the mesh's position source element.
         */
        MObject createMeshFromPolylist ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::Source<COLLADAFW::Long64ArrayElement>* positionsSource );

        /** Create the mesh from the current polygons array. */
        MObject createMeshFromPolygons ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::Source<COLLADAFW::Long64ArrayElement>* positionsSource );

        /**
         * Fill the maya array of vertex counts for each polygon.
         * @param positionsSource Pointer to the COLLADAFramework positions source element.
         * @param vertexArray Maya array of vertex counts for each polygon.
         * @param numVertices Variable for the sum of all existing vertices in all polygons.
         */
        void getVertexArray ( 
            const COLLADAFW::Source<COLLADAFW::Long64ArrayElement>* positionsSource, 
            MFloatPointArray &vertexArray, 
            size_t& numVertices );

        /**
         * Fill the list with the count of vertices for every polygon and calculate 
         * the number of polygons and the sum of vertices for all polygons.
         * @param polylist Reference to a polylist element.
         * @param vertexCountsPerPolygon List of vertex counts per polygon.
         */
        void getVertexCountsPerPolygon ( 
            const COLLADAFW::Polylist& polylist, 
            MIntArray& vertexCountsPerPolygon );

        /**
         * Get the vertex offset and the vertex set of the current polygons vertex input element.
         * Also establish the the maximum offset value of the current polygons input elements.
         * @param polylist The current polylist element.
         * @param vertexOffset Variable for the vertex offset.
         * @param vertexSet Variable for the vertex set.
         * @param maxOffset Variable for the maximum offset value of the polygons input elements.
         */
        void getPolygonsOffsetValues ( 
            const COLLADAFW::Polylist& polylist, 
            size_t &vertexOffset, 
            size_t &vertexSet, 
            size_t &maxOffset );

        /**
         * Get the vertex offset and the vertex set of the current polygons vertex input element.
         * Also establish the the maximum offset value of the current polygons input elements.
         * @param polygonsRef Pointer to the current polygons element.
         * @param vertexOffset Variable for the vertex offset.
         * @param vertexSet Variable for the vertex set.
         * @param maxOffset Variable for the maximum offset value of the polygons input elements.
         */
        void getPolygonsOffsetValues ( 
            const COLLADAFW::Polygons& polygons, 
            size_t& vertexOffset, 
            size_t& vertexSet, 
            size_t& maxOffset );

        /**
         * Go through the primitives, get the vertex connections for each 
         * polygon and write them into the array of vertex connections. 
         * @param polygonsRef Pointer to a polylist element in the collada document.
         * @param vertexCountsPerPolygon List of vertex counts per polygon.
         * @param numPolygons Number of all existing polygons.
         * @param maxOffset Maximum offset value of the polygons input elements.
         * @param vertexOffset The vertex offset.
         * @param polygonConnects Vertex connections for each polygon.
         */
        void getVertexConnections ( 
            const COLLADAFW::Polylist& polylist, 
            const MIntArray vertexCountsPerPolygon, 
            const size_t numPolygons, 
            const size_t maxOffset, 
            const size_t vertexOffset, 
            MIntArray &polygonConnects );

        /**
         * Fills the list with the count of vertices for every polygon and calculates the number of
         * polygons and the sum of vertices for all polygons. Goes through the primitives, get the 
         * vertex connections for each polygon and write them into the array of vertex connections. 
         * Gets the polygons from the <p> and the <ph> elements.
         * @param polygons COLLADAFramework polygons array.
         * @param numPolygons Number of all existing polygons.
         * @param numInputElements The number of input elements in the current polygon element.
         * @param vertexOffset The current vertex offset from the input list.
         * @param vertexCountsPerPolygon List of vertex counts per polygon to fill.
         * @param polygonConnects The vertex connections for each polygon to fill.
         * @return size_t Return the number of handled polygons.
         */
        size_t getVertexInformations ( 
            const COLLADAFW::Polygons& polygons, 
            const size_t numInputElements, 
            const size_t vertexOffset, 
            MIntArray& vertexCountsPerPolygon, 
            MIntArray& polygonConnects );

        /**
         * Fills the list with the count of vertices for every polygon and calculates the number of
         * polygons and the sum of vertices for all polygons. Goes through the primitives, get the 
         * vertex connections for each polygon and write them into the array of vertex connections. 
         * Gets the polygons from the <ph> elements.
         * @param polygons COLLADAFramework polygons array.
         * @param numPolygons Number of all existing polygons.
         * @param numInputElements The number of input elements in the current polygon element.
         * @param vertexOffset The current vertex offset from the input list.
         * @param vertexCountsPerPolygon List of vertex counts per polygon to fill.
         * @param polygonConnects The vertex connections for each polygon to fill.
         * @return size_t Return the number of handled polygons.
         */
        size_t getPHVertexInfos ( 
            const COLLADAFW::Polygons &polygons, 
            const size_t numInputElements, 
            const size_t vertexOffset, 
            MIntArray &vertexCountsPerPolygon, 
            MIntArray &polygonConnects );

        /**
         * Fills the list with the count of vertices for every polygon and calculates the number of
         * polygons and the sum of vertices for all polygons. Goes through the primitives, get the 
         * vertex connections for each polygon and write them into the array of vertex connections. 
         * Gets the polygons from the <h> element of the <ph> element.
         * @param polygons COLLADAFramework polygons array.
         * @param numPolygons Number of all existing polygons.
         * @param numInputElements The number of input elements in the current polygon element.
         * @param vertexOffset The current vertex offset from the input list.
         * @param vertexCountsPerPolygon List of vertex counts per polygon to fill.
         * @param polygonConnects The vertex connections for each polygon to fill.
         * @return size_t Return the number of handled polygons.
         */
        size_t getHVertexInfosFromPHElement ( 
            const COLLADAFW::PHElement& phElement, 
            const size_t numInputElements, 
            const size_t vertexOffset, 
            MIntArray &vertexCountsPerPolygon, 
            MIntArray &polygonConnects );

        /**
         * Fills the list with the count of vertices for every polygon and calculates the number of
         * polygons and the sum of vertices for all polygons. Goes through the primitives, get the 
         * vertex connections for each polygon and write them into the array of vertex connections. 
         * Gets the polygons from the <p> element of a <ph> element.
         * @param polygons COLLADAFramework polygons array.
         * @param numPolygons Number of all existing polygons.
         * @param numInputElements The number of input elements in the current polygon element.
         * @param vertexOffset The current vertex offset from the input list.
         * @param vertexCountsPerPolygon List of vertex counts per polygon to fill.
         * @param polygonConnects The vertex connections for each polygon to fill.
         * @return size_t Return the number of handled polygons.
         */
        size_t getPVertexInfosFromPHElement ( 
            const COLLADAFW::PHElement& phElement, 
            const size_t numInputElements, 
            const size_t vertexOffset, 
            MIntArray &vertexCountsPerPolygon, 
            MIntArray &polygonConnects );

        /**
         * Fills the list with the count of vertices for every polygon and calculates the number of
         * polygons and the sum of vertices for all polygons. Goes through the primitives, get the 
         * vertex connections for each polygon and write them into the array of vertex connections. 
         * Gets the polygons from the <p> elements.
         * @param polygons COLLADAFramework polygons array.
         * @param numInputElements The number of input elements in the current polygon element.
         * @param vertexOffset The current vertex offset from the input list.
         * @param numPolygons Variable to count the number of polygons.
         * @param vertexCountsPerPolygon List of vertex counts per polygon to fill.
         * @param polygonConnects The vertex connections for each polygon to fill.
         * @return size_t Return the number of handled polygons.
         */
        size_t getPVertexInfos ( 
            const COLLADAFW::Polygons &polygons, 
            const size_t numInputElements, 
            const size_t vertexOffset, 
            MIntArray &vertexCountsPerPolygon, 
            MIntArray &polygonConnects );

        /**
         * Create a maya mesh element.
         * @param numVertices Number of vertices.
         * @param numPolygons Number of polygons.
         * @param vertexArray Point (vertex) array. This should include all the vertices in the 
         *          mesh, and no extras. For example, a cube could have the vertices: 
         *          { (-1,-1,-1), (1,-1,-1), (1,-1,1), (-1,-1,1), (-1,1,-1), (-1,1,1), (1,1,1), (1,1,-1) } 
         * @param vertexCountsPerPolygon Array of vertex counts for each polygon. For example the 
         *          cube would have 6 faces, each of which had 4 verts, so the polygonCounts would 
         *          be {4,4,4,4,4,4}. 
         * @param polygonConnects Array of vertex connections for each polygon. For example, in the 
         *          cube, we have 4 vertices for every face, so we list the vertices for face0, 
         *          face1, etc consecutively in the array. These are specified by indexes in the 
         *          vertexArray: e.g for the cube: 
         *          { 0, 1, 2, 3, 4, 5, 6, 7, 3, 2, 6, 5, 0, 3, 5, 4, 0, 4, 7, 1, 1, 7, 6, 2 } 
         * @return MObject The maya mesh object.
         */
        MObject createMesh ( 
            const size_t numVertices, 
            const size_t numPolygons, 
            const MFloatPointArray vertexArray, 
            const MIntArray vertexCountsPerPolygon, 
            const MIntArray polygonConnects );

    };

}

#endif // __COLLADA_MAYA_GEOMETRY_IMPORTER_H__