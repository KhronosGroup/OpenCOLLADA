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
#ifndef __COLLADA_MAYA_GEOMETRY_EXPORTER_H__
#define __COLLADA_MAYA_GEOMETRY_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaSourceInput.h"

#include <vector>
#include <time.h>

#include <maya/MFnMesh.h>
#include <maya/MDagPath.h>
#include <maya/MItMeshPolygon.h>

#include "COLLADASWStreamWriter.h"
#include "COLLADASWSource.h"
#include "COLLADASWLibraryGeometries.h"
#include "COLLADASWInputList.h"
#include "COLLADASWPrimitves.h"
#include "COLLADABUIDList.h"


namespace COLLADAMaya
{

    class DocumentExporter;
    class ElementWriter;


    /************************************************************************/
    /* This class writes the <library_geometries>.                                                                     */
    /************************************************************************/
    class GeometryExporter : public COLLADASW::LibraryGeometries
    {

    private:

        /**
        * The list of the unique collada ids.
        */
        COLLADABU::IDList mGeometryIdList;

        /** 
         * Pointer to the document exporter. 
         */
        DocumentExporter* mDocumentExporter;

        /**
        * A collada id for every maya id.
        */
        StringToStringMap mMayaIdColladaIdMap;

        /**
        * Holds all the polygon sources of the geometry of the current mesh.
        * This can be vertexSource, normalSource, tangentSource, binormalSource,
        * colorSource or texCoordSource.
        */
        Sources mPolygonSources;

        /**
        * Holds all the vertex sources of the geometry of the current mesh.
        * This can be vertexSource, normalSource, tangentSource, binormalSource,
        * colorSource or texCoordSource.
        */
        Sources mVertexSources;

    public:

        /* @param streamWriter The stream the output will be written to                                                                     */
        GeometryExporter ( COLLADASW::StreamWriter* streamWriter, DocumentExporter* documentExporter );
        virtual ~GeometryExporter();

        /** Walk through the scene graph and export all geometries. */
        void exportGeometries();

        /** closes the geometry tags in the collada document */
        void endExport();

        /** Generate the collada id, if not done before and stores it in the scene element. */
        const String generateColladaMeshId ( const MDagPath dagPath );

        /** Handle the geometry in depend on it is a controller or not. */
        void exportControllerOrGeometry ( SceneElement* sceneElement );

        /** Returns the collada geometry id of the current mesh node. */
        const String& getColladaGeometryId ( MDagPath dagPath );

    private:

        /**
        * A collada id for every maya id.
        */
        const String& findColladaGeometryId ( const String& mayaGeometryId );

        /** Returns the tolerance value for double value comparison. */
        const double getTolerance () const 
        {
            return mDocumentExporter->getTolerance ();
        }

        /** Exports the current scene element and all it's children. */
        void exportGeometries ( SceneElement* sceneElement, bool isVisible );

        /** Handle controller geometries. */
        void handleControllers ( SceneElement* sceneElement );

        /** Exports the geometry data of the current object, if it is a valid mesh object to export. */
        bool exportGeometry ( SceneElement* sceneElement );

        /** Exports all geometry data of the current mesh. */
        bool exportMesh ( MFnMesh& fnMesh, const String& meshId, const String& meshName );

        /**
         * Get the uv set names of the current mesh.
         * @param fnMesh The mesh object.
         * @param uvSetNames String array for the uv set names.
         */
        void getUVSetNames( const MFnMesh &fnMesh, MStringArray &uvSetNames );

        /** Exports an extra tag. */
        void exportExtraTechniqueParameters ( const MFnMesh& fnMesh, const String& mayaMeshName );

        /** Exports the double sided extra tag. */
        bool isDoubleSided ( const MFnMesh& fnMesh );

        /** Export the vertex positions of the current mesh */
        void exportVertexPositions ( const MFnMesh& fnMesh, const String& meshId );

        /** Export the vertex normals of the current mesh */
        bool exportVertexNormals ( const MFnMesh& fnMesh, const String& meshId );

        /** Implement TangentSource and BinormalSource. */
        void exportTangentsAndBinormals( 
            const MFnMesh& fnMesh, 
            const String& meshId, 
            const bool perVertexNormals, 
            const MFloatVectorArray& normals );

        /** Calculate the geometric tangents and binormals(T/Bs). */
        void getTangents( 
            const MFnMesh& fnMesh, 
            const MFloatVectorArray& normals, 
            uint normalCount, 
            MVectorArray& binormals, 
            MVectorArray& tangents );

        /** Calculate the geometric tangents and binormals(T/Bs) in case of "per vertex normals". */
        void getPerVertexNormalsTangents( 
            const MFnMesh& fnMesh, 
            const MFloatVectorArray& normals, 
            MVectorArray& tangents, 
            MVectorArray& binormals );

        /** Implement NormalSource. */
        bool exportNormals( 
            const MFnMesh& fnMesh, 
            const String& meshId, 
            MFloatVectorArray& normals );

        /**
         * Returns a list of names for each texcoord id that corresponds to the equivalent
         * Maya uv set name, as returned by MFnMesh.getUVSetNames().
         */
        std::vector<String> generateTexCoordIds ( 
            const MStringArray& uvSetNames, 
            const String& meshId );

        /**
         * Export the texture coordinates listed in the two arrays given in argument,
         * that correspond respectively to the Maya uv set name and the collada texcoord id.
         */
        void exportTextureCoords ( const MFnMesh& fnMesh,
                                   const String& meshId,
                                   const MStringArray& uvSetNames );

        /**
        * Export the color sets. Returns true if we should proceed to export the given color set Ids.
         */
        void exportColorSets ( const MFnMesh& fnMesh, const String& meshId, MStringArray& colorSetNames );

        /** Export the vertices tag with a link to the positions. */
        void exportVertices ( const String& meshId );

        /**
         * Export the texture tangents and binormals.
         */
        void exportTextureTangentsAndBinormals ( const MFnMesh &fnMesh, const String& meshId );

    };
}

#endif //__COLLADA_MAYA_GEOMETRY_EXPORTER_H__
