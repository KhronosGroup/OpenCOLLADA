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
#ifndef __COLLADA_MAYA_GEOMETRY_POLYGON_EXPORTER_H__
#define __COLLADA_MAYA_GEOMETRY_POLYGON_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaMeshHelper.h"
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaGeometryExporter.h"
#include <vector>

#include <maya/MFnMesh.h>
#include <maya/MDagPath.h>
#include <maya/MItMeshPolygon.h>
#include <maya/MVector.h>
#include <maya/MItMeshPolygon.h>

#include "COLLADAStreamWriter.h"
#include "COLLADAElementWriter.h"
#include "COLLADALibraryGeometries.h"
#include "COLLADAInputList.h"
#include "COLLADAPrimitves.h"

class DocumentExporter;
class ElementWriter;


namespace COLLADAMaya
{


    /************************************************************************/
    /* This class writes the <polylist> elements in the <library_geometries>.                                                                     */
    /************************************************************************/

    class GeometryPolygonExporter : public COLLADA::LibraryGeometries
    {

    public:

        /** The list of v-counts. */
        typedef std::vector<unsigned long> VCountList;

    private:

        /** The unique id of the mesh object */
        String mMeshId;

        /** The array with the uvs */
        MStringArray mUvSetNames;

        /** Flag, if face vertex normals exist */
        bool mHasFaceVertexNormals;

        /** The list with the color sets */
        ColourSetList mColorSets;

        /** true, if triangles should be exported. */
        bool triangulated;

        /** Number of holes in the current mesh */
        uint holeCount;

        /**
        * Array of integer triples, one for each hole in the mesh.
        * The first element in each triple represents the index of the holed face.
        * The next two elements represent the number of vertexes in the hole and the
        * hole's start index in list of hole vertexes in holeVertexArray, respectively.
        * For example, if holeInfoArray = [ 0, 3, 0, 1, 4, 3 ], then this means that
        * face 0 contains a 3-vertex hole whose vertex indices are stored in elements
        * 0, 1, 2 of holeVertexArray, and face 1 contains a 4-vertex hole whose vertex
        * indices are stored in elements 3, 4, 5, 6 of holeVertexArray.
        */
        MIntArray mHoleInfoArray;

        /**
        * An array consisting of the vertex indices of every hole in the mesh.
        * The third element of each triple in holeInfoArray is the index of the
        * start of a particular hole's vertex list in this array.
        */
        MIntArray mHoleVertexArray;

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /** A pointer to the geometry sources input list, which is filled from geometry exporter. */
        Sources* mPolygonSources;

        /** A pointer to the vertexes list, which is filled from geometry exporter. */
        Sources* mVertexSources;

        /** Vector with the indices of faces which are holes. */
        std::vector<uint> mHoleFaces;


        /**
        * Defines the export binding type of geometric primitives and vertex attributes for a mesh.
        */
        enum exportType
        {
            POLYLIST = 0, // Export a polylist
            POLYGONS,  // Export a polygon (just used with holes)
            TRIANGLES  // Export triangles
        };

        /**
         * The class for the lists of vertex indexes of each polygon.
         */
        class PolygonSource
        {

        private:

            /** The export type of the current polygon (POLYLIST, POLYGONS OR TRIANGLES) */
            uint mExportType;

            /** The list with the count of vertex attributes of the polygon. */
            VCountList mVertexCountList;

            /** The list of the vertex attributes of the polygon. */
            Sources mVertexAttributes;

            /** Vector with the number of vertexes for every face. */
            std::vector<uint> mFaceVertexCounts;

            /** Vector with the indices of faces which are holes. */
            std::vector<uint> mHoleFaces;

            /** True, if the current polygon has one or more holes. */
            bool mIsHoled;

            /** To store the number of indices (don't hold the indices directly) */
            uint numVertexIndexes;

        public:

            /** Constructor */
            PolygonSource ( const Sources& vertexAttributes, uint exportType=POLYLIST )
            : mVertexAttributes ( vertexAttributes )
            , mExportType ( exportType )
            , mIsHoled ( false )
            {}

            /** Destructor */
            virtual ~PolygonSource(){};

            /**
             * Returns a reference to the list with the counts of vertex attributes of the polygon.
             * @return std::vector<unsigned long>& 
             *          Reference to the list with the counts of vertex attributes of the polygon. 
             */
            VCountList& getVertexCountList() { return mVertexCountList; }

            /**
             * Returns the list with the counts of vertex attributes of the polygon.
             * @return std::vector<unsigned long>& 
             *          The list with the counts of vertex attributes of the polygon. 
             */
            const VCountList getVertexCountList() const { return mVertexCountList; }

            /**
             * Returns true, if the current polygon has one or more holes.
             * @return bool True, if the current polygon has one or more holes.
             */
            bool isHoled() const { return mIsHoled; }
            
            /**
             * Set the @mIsHoled flag.
             * @param holed Value for the @mIsHoled flag.
             */
            void isHoled( bool holed ) { mIsHoled = holed; }

            /**
             * Returns the list of the vertex attributes of the polygon.
             * @return Sources The list of the vertex attributes of the polygon.
             */
            const Sources getVertexAttributes() const { return mVertexAttributes; }

            /**
             * Returns a reference to the list of the vertex attributes of the polygon.
             * @return Sources& Reference to the list of the vertex attributes of the polygon.
             */
            Sources& getVertexAttributes() { return mVertexAttributes; }

            /**
             * Returns a reference to the Vector with the number of vertexes for every face.
             * @return std::vector<uint> 
             *              Reference to the Vector with the number of vertexes for every face.
             */
            std::vector<uint>& getFaceVertexCounts() { return mFaceVertexCounts; }

            /**
             * Returns a const of the Vector with the number of vertexes for every face.
             * @return const std::vector<uint>
             *          Const of the Vector with the number of vertexes for every face.
             */
            const std::vector<uint> getFaceVertexCounts() const { return mFaceVertexCounts; }

            /** Vector with the indices of faces which are holes. */
            /**
             * Returns a reference to the vector with the indices of faces which are holes.
             * @return std::vector<uint>&
             *          Reference to the vector with the indices of faces which are holes.
             */
            std::vector<uint>& getHoleFaces() { return mHoleFaces; }

            /**
             * Returns the const vector with the indices of faces which are holes.
             * @return const std::vector<uint>
             *          Const vector with the indices of faces which are holes.
             */
            const std::vector<uint> getHoleFaces() const { return mHoleFaces; }

        };

        typedef std::vector<PolygonSource*> PolygonSourceList;


        struct TangentialVertex
        {
            float* normalPointer;
            float* texCoordPointer;
            MVector tangent;
            uint count;
            uint tangentId;
            uint binormalId;
        };

        typedef std::vector<TangentialVertex> TangentialVertexList;

    public:

        /* @param streamWriter The stream the output will be written to                                                                     */
        GeometryPolygonExporter ( COLLADA::StreamWriter* _streamWriter,
                                  DocumentExporter* _documentExporter );
        virtual ~GeometryPolygonExporter ( void );

        /**
        * Exports the data of all polygons from the shaders in the mesh.
        */
        void exportPolygonSources ( 
            MFnMesh &fnMesh,
            String meshId,
            MStringArray uvSetNames,
            ColourSetList &colorSets,
            Sources* geometrySourcesList,
            Sources* vertexes,
            bool hasFaceVertexNorms );

    private:

        /**
        * Exports the data of all polygons of the current shader.
        */
        void exportShaderPolygons ( 
            MFnMesh &fnMesh,
            const uint shaderPosition,
            const uint realShaderCount,
            MObjectArray shaders,
            const MIntArray& shaderIndices );

        /**
         * Verify the polygons of the meshes shader for holes.
         * @param fnMesh The current mesh object.
         * @param shaderPosition Position of the current shader.
         * @param realShaderCount The number of valid shaders.
         * @param shaderIndices List of shader indices.
         * @return bool True, if the shader has a holed polygon.
         */
        bool verifyPolygonsForHoles( 
            const MFnMesh &fnMesh,
            const uint shaderPosition, 
            const uint realShaderCount, 
            const MIntArray& shaderIndices );

        /**
         * Prepares the polylist in the collada file to add the list values.
         * @param dummyPrimitivesBase The collada source.
         * @param numPolygons Number of polygons.
         * @param vCountList List with the vertex counts.
         * @param shaderPosition Position of the current shader for the materials.
         * @param realShaderCount Shader count to append the materials.
         * @param currentShapeIsHoled True, if we have to implement a polygon instead of a polylist element.
         * @param shaders List with the mesh materials.
         * @return COLLADA::PrimitivesBase* Pointer to the created Template object.
         */
        COLLADA::PrimitivesBase* preparePrimitivesBase( 
            COLLADA::PrimitivesBase& dummyPrimitivesBase, 
            uint numPolygons, 
            std::vector<unsigned long>& vCountList, 
            uint shaderPosition, 
            uint realShaderCount, 
            uint currentShapeIsHoled, 
            MObjectArray shaders );
        
        /**
         * Retrieve the shader polygon vertices and write them directly into the collada file.
         * @param primitivesBasePoly The collada object to export.
         * @param exportType The type of the polygon source.
         */
        void writeShaderPolygons( 
            COLLADA::PrimitivesBase* primitivesBasePoly,
            const uint baseExportType,
            MFnMesh &fnMesh, 
            const MIntArray& shaderIndices, 
            const uint shaderPosition, 
            const uint realShaderCount );

        /**
         * Retrieve the vertex indices and establish the number of polygons (in case of
         * triangulation more than one is possible) and the number of vertexes in the polygon.
         * @param fnMesh The mesh object.
         * @param meshPolygonsIter Iterator of the mesh's polygons.
         * @param polygon The collada source to hold the polygon data.
         * @param vertexIndices List of the vertex indices of the current polygon.
         * @param numPolygons Number of polygons in the current mesh.
         * @param numVertices Number of vertices in the current mesh.
         */
        void initializePolygonSource(
            const MFnMesh &fnMesh, 
            MItMeshPolygon &meshPolygonsIter,
            PolygonSource &polygon,
            MIntArray &vertexIndices, 
            uint &numPolygons, 
            uint &numVertices );

        /**
         * Writes the vertex indices into the collada file.
         * @param primitivesBasePoly The collada file element (polylist, polygons or triangles).
         * @param polygon Data of the current polygon (for the face vertices).
         * @param fnMesh The current mesh object.
         * @param meshPolygonsIter Iterator of the mesh's polygons.
         * @param baseExportType The type of the primitivesBasePoly.
         * @param vertexIndices List of the vertex indices of the current polygon.
         * @param numPolygons Number of polygons in the current mesh.
         * @param numVertices Number of vertices in the current mesh.
         */
        void writeElementVertexIndices( 
            COLLADA::PrimitivesBase* primitivesBasePoly,
            PolygonSource* polygon, 
            MFnMesh &fnMesh, 
            MItMeshPolygon &meshPolygonsIter,
            const uint baseExportType,
            const MIntArray &vertexIndices, 
            const uint &numPolygons, 
            const uint &numVertices );

        /**
         * Determines the export type of the current primitives base.
         * @param isHoledShape True, if the current shape is holed.
         * @return uint The export Type (polylist, polygons or triangles)
         */
        uint determinePrimitivesBaseExportType ( const bool isHoledShape );

        /**
        * Create the real Polylist/Polygons/Triangles element.
        */
        COLLADA::PrimitivesBase* createPrimitivesBase ( 
            COLLADA::PrimitivesBase dummyPoly,
            const uint baseExportType );

        /**
        * Prepare the list for add the vertex indexes.
        */
        void preparePrimitivesBaseToAppendValues ( COLLADA::PrimitivesBase* polylist, const uint baseExportType );

        /**
        * Check if the current face is a normal polygon or a hole and open the corresponding tag.
        */
        void openPolygonOrHoleElement ( COLLADA::PrimitivesBase* polylist,
                                        PolygonSource* poly,
                                        const uint currentFaceIndex );

        /**
        * Check if the current face is a normal polygon or a hole.
        */
        bool checkForHole ( const PolygonSource* polygon, const uint currentFaceIndex );

        /**
        * Retrieve the vertex indices and establish the number of polygons (in case of
        * triangulation more than one is possible) and the number of vertexes in the polygon.
        */
        MIntArray& retrieveVertexIndices ( 
            MIntArray &vertexIndices,
            MItMeshPolygon &meshPolygonsIter,
            uint &numPolygons,
            uint &numVertices );

        /**
         * Determines the vertex indices and writes them into the collada file.
         * @param primitivesBasePoly The collada element to write the vertex indices.
         * @param polygon The polygon with the face vertex data.
         * @param vertexIndex The list of the vertex indices.
         * @param normalIndices The normal indices.
         * @param iteratorVertexIndex The current vertex index.
         * @param meshPolygonsIter The current mesh polygon to write.
         * @param fnMesh The current mesh object.
         * @param polyIndex The current polygon index.
         */
        void writeVertexIndices(
            COLLADA::PrimitivesBase* primitivesBasePoly,
            PolygonSource *polygon, 
            int vertexIndex, 
            MIntArray &normalIndices, 
            int iteratorVertexIndex, 
            MItMeshPolygon &meshPolygonsIter, 
            MFnMesh &fnMesh, 
            int polyIndex );

        /**
         * Handles the data of a holed polygon element.
         * @param polygon The polygon to hold the data.
         * @param polyIndex Index of the current polygon.
         * @param vertexIndex Index of the current vertex.
         * @param numVertices Number of vertices in the polygon.
         * @param iteratorVertexIndex Vertex iterator index.
         */
        void handleHoledPolygon( 
            PolygonSource &polygon, 
            int polyIndex, 
            int vertexIndex, 
            int numVertices, 
            int iteratorVertexIndex );

        /*
        * Generate the list of the polygon set inputs.
        */
        void generatePolygonSetInputs ( COLLADA::PrimitivesBase* polylist, Sources* vertexAttributes );

        /** Adds a new hole identifier.
        The face-vertex count entry should already exist and the identifier will be place
        in increasing order within the current list of entries within the face-vertex count list.
        @param index The index of the hole within the face-vertex count list. */
        void addHole ( uint index );

        /**
         * Retrieves the number of polygons and the vertex count list to export.
         * @param fnMesh The mesh object.
         * @param shaderPosition The position of the current shader polygon.
         * @param realShaderCount The number of real shaders.
         * @param shaderIndices The list of shader indices.
         * @param currentShapeIsHoled
         * @param vertexCountList
         * @param faceVertexCounts
         */
        void getVertexCountList( 
            const MFnMesh &fnMesh, 
            const uint shaderPosition, 
            const uint realShaderCount, 
            const MIntArray& shaderIndices,
            std::vector<unsigned long>& vertexCountList );
        
        /**
         * Counts the number of polygons in the current shape.
         * @param fnMesh The mesh object.
         * @param shaderPosition The position of the current shader polygon.
         * @param realShaderCount The number of real shaders.
         * @param shaderIndices The list of shader indices.
         * @return uint Number of polygons in the current shape.
         */
        uint getShaderPolygonsCount(
            const MFnMesh &fnMesh, 
            const uint shaderPosition, 
            const uint realShaderCount, 
            const MIntArray& shaderIndices );

        /**
         * Establish the number of vertexes in the polygon.
         * @param meshPolygonsIter
         * @param vertexCountList
         */
        void getPolygonVertexCounts( 
            MItMeshPolygon &meshPolygonsIter, 
            std::vector<unsigned long>& vertexCountList );
    };
}

#endif //__COLLADA_MAYA_GEOMETRY_POLYGON_EXPORTER_H__
