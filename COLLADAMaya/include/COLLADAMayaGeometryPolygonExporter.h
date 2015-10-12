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
#ifndef __COLLADA_MAYA_GEOMETRY_POLYGON_EXPORTER_H__
#define __COLLADA_MAYA_GEOMETRY_POLYGON_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaPolygonSource.h"
#include <vector>

#include <maya/MFnMesh.h>
#include <maya/MDagPath.h>
#include <maya/MItMeshPolygon.h>
#include <maya/MVector.h>
#include <maya/MItMeshPolygon.h>

#include "COLLADASWStreamWriter.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWLibraryGeometries.h"
#include "COLLADASWInputList.h"
#include "COLLADASWPrimitves.h"

class DocumentExporter;
class ElementWriter;


namespace COLLADAMaya
{


    /************************************************************************/
    /* This class writes the <polylist> elements in the <library_geometries>.                                                                     */
    /************************************************************************/

    class GeometryPolygonExporter : public COLLADASW::LibraryGeometries
    {

    private:

        /** The unique id of the mesh object */
        String mMeshId;

        /** The array with the uvs */
        MStringArray mUvSetNames;

        /** Flag, if face vertex normals exist */
        bool mHasFaceVertexNormals;

        /** The shaders of the current mesh. */
        MObjectArray mShaders;

        /** The shader indices of the current mesh. */
        MIntArray mShaderIndices;

        /** The position of the current shader. */
        uint mShaderPosition;

        /** The list with the color sets */
        MStringArray mColorSetNames;

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


    public:

        /* @param streamWriter The stream the output will be written to                                                                     */
        GeometryPolygonExporter ( COLLADASW::StreamWriter* _streamWriter,
                                  DocumentExporter* _documentExporter );
        virtual ~GeometryPolygonExporter ( void );

        /**
        * Exports the data of all polygons from the shaders in the mesh.
        */
        void exportPolygonSources ( 
            const MObject& mesh,
            const String& meshId,
            MStringArray& uvSetNames,
            MStringArray& colorSetNames,
            Sources* geometrySourcesList,
            Sources* vertexes,
            const bool hasFaceVertexNorms );

    private:

        /**
        * Exports the data of all polygons of the current shader.
        * @param fnMesh The current mesh object.
        */
        void exportShaderPolygons(const MObject& mesh);

        /**
         * Verify the polygons of the meshes shader for holes.
         * @param fnMesh The current mesh object.
         * @return bool True, if the shader has a holed polygon.
         */
        bool verifyPolygonsForHoles(const MObject& mesh);

        /**
         * Prepares the polylist in the collada file to add the list values.
         * @param fnMesh The current mesh object.
         * @param numPolygons Number of polygons.
         * @param currentShapeIsHoled True, if we have to implement a polygon instead of a polylist element.
         * @return COLLADASW::PrimitivesBase* Pointer to the created Template object.
         */
        COLLADASW::PrimitivesBase* preparePrimitivesBase( 
            const MObject& mesh,
            const uint numPolygons, 
            const uint currentShapeIsHoled );
        
        /**
         * Retrieve the shader polygon vertices and write them directly into the collada file.
         * @param primitivesBasePoly The collada object to export.
         * @param exportType The type of the polygon source.
         */
        void writeShaderPolygons( 
            COLLADASW::PrimitivesBase* primitivesBasePoly,
            const uint baseExportType,
            const MObject& mesh);

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
            const MObject& mesh,
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
            COLLADASW::PrimitivesBase* primitivesBasePoly,
            PolygonSource* polygon, 
            const MObject& mesh,
            MItMeshPolygon &meshPolygonsIter,
            const uint baseExportType,
            const MIntArray &vertexIndices, 
            const uint numPolygons, 
            const uint numVertices );

        /**
         * Determines the export type of the current primitives base.
         * @param isHoledShape True, if the current shape is holed.
         * @return uint The export Type (polylist, polygons or triangles)
         */
        uint determinePrimitivesBaseExportType ( const bool isHoledShape );

        /**
         * If we should export a polylist and all polygons of the current mesh 
         * are triangles, we will export triangles instead of polygons! 
         * @param fnMesh The current mesh object.
         * @return bool True, if all polygons in the mesh are triangles.
         */
        bool verifyTriangulation(const MObject& mesh);

        /**
        * Create the real Polylist/Polygons/Triangles element.
        */
        COLLADASW::PrimitivesBase* createPrimitivesBase ( const uint baseExportType );

        /**
        * Check if the current face is a normal polygon or a hole and open the corresponding tag.
        */
        void openPolygonOrHoleElement ( COLLADASW::PrimitivesBase* polylist,
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
        void retrieveVertexIndices ( 
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
            COLLADASW::PrimitivesBase* primitivesBasePoly,
            PolygonSource *polygon, 
            const int vertexIndex, 
            const MIntArray &normalIndices, 
            const int iteratorVertexIndex, 
            MItMeshPolygon &meshPolygonsIter, 
            const MObject& mesh,
            const int polyIndex );

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
        void getPolygonInputAttributes ( COLLADASW::InputList& inputList );

        /** Retrieve the list of vertex attributes. 
            That's the input list of vertexes in the collada document. */
        void getVerticesInputAttributes( Sources& vertexAttributes );

        /** Adds a new hole identifier.
        The face-vertex count entry should already exist and the identifier will be place
        in increasing order within the current list of entries within the face-vertex count list.
        @param index The index of the hole within the face-vertex count list. */
        void addHole ( uint index );

        /**
         * Retrieves the number of polygons and the vertex count list to export.
         * @param primitivesBase The collada element to write.
         * @param fnMesh The mesh object.
         */
        void writeVertexCountList( 
            COLLADASW::PrimitivesBase* primitivesBase, 
            const MObject& mesh);
        
        /**
         * Counts the number of polygons in the current shape.
         * @param fnMesh The mesh object.
         * @return uint Number of polygons in the current shape.
         */
        uint getShaderPolygonsCount(const MObject& mesh);

        /**
         * Establish the number of vertexes in the polygon.
         * @param meshPolygonsIter The current shapes mesh polygons itertator.
         * @param numVertices The current vertex count.
         * return True, if the vertex count should be added to the list.
         */
        bool getPolygonVertexCount( 
            MItMeshPolygon& meshPolygonsIter,
            unsigned long& numVertices );
    };
}

#endif //__COLLADA_MAYA_GEOMETRY_POLYGON_EXPORTER_H__
