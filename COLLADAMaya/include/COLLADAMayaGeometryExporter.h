/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_GEOMETRY_EXPORTER_H__
#define __COLLADA_MAYA_GEOMETRY_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaMeshHelper.h"

#include <vector>
#include <time.h>

#include <maya/MFnMesh.h>
#include <maya/MDagPath.h>
#include <maya/MItMeshPolygon.h>

#include "COLLADAStreamWriter.h"
#include "COLLADASource.h"
#include "COLLADALibraryGeometries.h"
#include "COLLADAInputList.h"
#include "COLLADAPrimitves.h"


namespace COLLADAMaya
{

    class DocumentExporter;

    class ElementWriter;

    class SourceInput;

    typedef std::vector<SourceInput> Sources;

    /** A generic Input attribute */
    class SourceInput
    {

    public:
        /** Collada source */
        COLLADA::SourceBase mSource;

        /** Index list. */
        std::vector<int> mIndexes;
        int mIdx;

        /** Type of the source. */
        COLLADA::Semantics mType;

    public:

        /** Constructor */
        SourceInput ( COLLADA::SourceBase& source, COLLADA::Semantics type, int idx = -1 )
                : mSource ( source ), mType ( type ), mIdx ( idx ) {}

        /** Destructor */
        virtual ~SourceInput() {}

        /**
         * Returns true, if the given list contains the given SourceInput.
         */
        static bool containsSourceBase ( Sources* sources, COLLADA::SourceBase* searchedSourceBase );

        /**
        * Returns true, if the given list contains the given SourceInput and erased sucessful.
        */
        static bool eraseSourceBase ( Sources* sources, COLLADA::SourceBase* searchedSourceBase );
    };



    /************************************************************************/
    /* This class writes the <library_geometries>.                                                                     */
    /************************************************************************/

    class GeometryExporter : public COLLADA::LibraryGeometries
    {

    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /** List of the exported geometries. */
        std::vector<String> mExportedGeometries;

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
        GeometryExporter ( COLLADA::StreamWriter* streamWriter, DocumentExporter* documentExporter );
        virtual ~GeometryExporter();

        /** Walk through the scene graph and export all geometries. */
        void exportGeometries();

        /** Exports the current scene element and all it's children. */
        void exportGeometries ( SceneElement* sceneElement );

        /** Exports the geometry data of the current object, if it is a valid mesh object to export. */
        void exportGeometry ( const MDagPath& dagPath );

        /** closes the geometry tags in the collada document */
        void endExport();

    private:

        /** Exports all geometry data of the current mesh. */
        void exportMesh ( MFnMesh& fnMesh, String meshId, String& meshName );

        /**
         * Get the uv set names of the current mesh.
         * @param fnMesh The mesh object.
         * @param uvSetNames String array for the uv set names.
         */
        void getUVSetNames( MFnMesh &fnMesh, MStringArray &uvSetNames );

        /** Exports an extra tag. */
        void exportExtra ( const MFnMesh& fnMesh );

        /** Exports the double sided extra tag. */
        bool isDoubleSided ( const MFnMesh& fnMesh );

        /** Export the vertex positions of the current mesh */
        void exportVertexPositions ( const MFnMesh& fnMesh, const String& meshId );

        /** Export the vertex normals of the current mesh */
        bool exportVertexNormals ( const MFnMesh& fnMesh, const String& meshId );

        /**
         * Returns a list of names for each texcoord id that corresponds to the equivalent
         * Maya uv set name, as returned by MFnMesh.getUVSetNames().
         */
        std::vector<String> generateTexCoordIds ( const MStringArray& uvSetNames, const String& meshId );

        /**
         * Export the texture coordinates listed in the two arrays given in argument,
         * that correspond respectively to the Maya uv set name and the collada texcoord id.
         */
        void exportTextureCoords ( const MFnMesh& fnMesh,
                                   const String& meshId,
                                   const MStringArray& uvSetNames,
                                   const std::vector<String>& texcoordIds );

        /**
         * Comment from Feeling-Software:
         *
         * Per-Vertex Blind Data
         * The plug-in now supports the import/export of per-vertex blind data. Unfortunately, we are ahead
         * of the COLLADA specifications once again. A new semantic was the<refore added, unofficially, to
         * the mesh <vertices><input> node: "EXTRA", which points towards the source of per-vertex blind data.
         */
        void exportVertexBlindData ( const MFnMesh& fnMesh );

        /**
        * Export the color sets. Returns true if we should proceed to export the given color set Ids.
         */
        void exportColorSets ( const MFnMesh& fnMesh, const String& meshId, ColourSetList& colorSets );

        /** Export the vertices tag with a link to the positions. */
        void exportVertices ( const String& meshId );

        /** Gets the mesh color sets */
        void getMeshColorSet ( const MObject& mesh, std::vector<float> &meshColorSet, ColourSet& colorSet );

    };
}

#endif //__COLLADA_MAYA_GEOMETRY_EXPORTER_H__
