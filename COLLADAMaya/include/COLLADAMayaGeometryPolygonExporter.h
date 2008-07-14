/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
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


        /** Vector with the number of vertexes for every face. */
        std::vector<uint> faceVertexCounts;

        /** Vector with the indices of faces which are holes. */
        std::vector<uint> holeFaces;


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

        public:

            /** The list of v-counts. */
            typedef std::vector<unsigned long> VCountList;

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

        public:

            /** Constructor */
            PolygonSource ( const Sources& vertexAttributes, uint exportType=POLYLIST )
                    : mVertexAttributes ( vertexAttributes ), mExportType ( exportType ), mIsHoled ( false )
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
        void exportPolygonSources ( MFnMesh &fnMesh,
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
        void exportShaderPolygons ( MFnMesh &fnMesh,
                                    const uint shaderPosition,
                                    const uint realShaderCount,
                                    MObjectArray shaders,
                                    const MIntArray shaderIndices );

        /**
         * Creates the polygon sources of the current shader polygon.
         * @param fnMesh The mesh object.
         * @param shaderPosition The position of the current shader polygon.
         * @param realShaderCount The num of real shaders.
         * @param shaderIndices The list of shader indices.
         * @param dummyPrimitivesBase The collada source.
         * @param shaderPolygons The polygon shader sources.
         * @param currentShapeIsHoled True, if the current shape is holded.
         * @return uint Number of polygons (could also be triangles)
         */
        uint createShaderPolygons( 
            MFnMesh &fnMesh, 
            const uint shaderPosition, 
            const uint realShaderCount, 
            const MIntArray shaderIndices, 
            COLLADA::PrimitivesBase *dummyPrimitivesBase, 
            PolygonSourceList &shaderPolygons, 
            bool &currentShapeIsHoled );

        /**
         * Exports the created polygon sources of the current shader polygon 
         * into the collada document.
         * @param shaderPolygons List of the polygon sources to export.
         * @param primitivesBasePoly The collada object to export.
         * @param exportType The type of the polygon source.
         */
        void writeShaderPolygons( PolygonSourceList &shaderPolygons, 
                                  COLLADA::PrimitivesBase* primitivesBasePoly,
                                  uint exportType);
  
        /**
        * Sets the vertex count list in the primitivesBasePoly from all polygons.
        */
        void setVertexCountList ( COLLADA::PrimitivesBase* primitivesBasePoly,
                                  PolygonSourceList* polygons );

        /**
        * Determines the export type of the current primitives base.
        */
        uint determinePrimitivesBaseExportType ( bool currentShapeIsHoled );

        /**
        * Create the real Polylist/Polygons/Triangles element.
        */
        COLLADA::PrimitivesBase* createPrimitivesBase ( 
            COLLADA::PrimitivesBase dummyPoly,
            uint exportType );

        /**
        * Prepare the list for add the vertex indexes.
        */
        void preparePrimitiveBase ( COLLADA::PrimitivesBase* polylist, uint exportType );

        /**
        * Check if the current face is a normal polygon or a hole and open the corresponding tag.
        */
        void openPolygonOrHoleElement ( COLLADA::PrimitivesBase* polylist,
                                        PolygonSource* poly,
                                        uint currentFaceIndex );

        /**
        * Check if the current face is a normal polygon or a hole.
        */
        bool checkForHole ( PolygonSource* polygon, uint currentFaceIndex );

        /**
        * Exports the vertices of the current polygon.
        * @return
        *   returns the number of exported polygons (triangles)
        */
        int exportPolygonVertices ( MFnMesh &fnMesh,
                                    MItMeshPolygon &meshPolygonsIter,
                                    COLLADA::PrimitivesBase* polylist,
                                    PolygonSource* polygon );

        /**
        * Retrieve the vertex indices and establish the number of polygons (in case of
        * triangulation more than one is possible) and the number of vertexes in the polygon.
        */
        void retrieveVertexIndices ( MIntArray* vertexIndices,
                                     MItMeshPolygon &meshPolygonsIter,
                                     COLLADA::PrimitivesBase* polylist,
                                     int &numPolygons,
                                     int &numVertices,
                                     std::vector<unsigned long> &vertexCountList );

        /**
        * Export the indices of the current vertex.
        */
        void exportVertexIndices ( MFnMesh &fnMesh,
                                   MItMeshPolygon &meshPolygonsIter,
                                   PolygonSource* polygon,
                                   MIntArray &normalIndices,
                                   int iteratorVertexIndex,
                                   int numVertices );

        /*
        * Generate the list of the polygon set inputs.
        */
        void generatePolygonSetInputs ( COLLADA::PrimitivesBase* polylist, Sources* vertexAttributes );

        /** Adds a new hole identifier.
        The face-vertex count entry should already exist and the identifier will be place
        in increasing order within the current list of entries within the face-vertex count list.
        @param index The index of the hole within the face-vertex count list. */
        void addHole ( uint index );
    };
}

#endif //__COLLADA_MAYA_GEOMETRY_POLYGON_EXPORTER_H__
