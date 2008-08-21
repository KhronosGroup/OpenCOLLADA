/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_GEOMETRYEXPORTER_H__
#define __COLLADAMAX_GEOMETRYEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryGeometries.h"
#include "COLLADAPrimitves.h"

#include "COLLADAMaxGeometriesExporter.h"
#include "COLLADAMaxEffectExporter.h"

namespace COLLADAMax
{

    class ExportNode;
	struct MorphControllerHelperGeometry;

    /** Class to export a single geometry.*/

    class GeometryExporter
    {

    private:
        /** List of channels.*/
        typedef std::vector<int> ChannelList;

        /** List of max materials.*/
        typedef std::vector<Mtl*> MaterialList;

    public:
        /** Symbol used for simple color materials.*/
        static const String COLOR_MATERIAL_SYMBOL;

    private:
        /** The export node which geometry should be exported.*/
        ExportNode * mExportNode;

		/** The helper geometry that should be exported.*/
		const MorphControllerHelperGeometry * mMorphControllerHelperGeometry;

		
		/** The id of the geometry.*/
        String mId;

        GeometriesExporter * mGeometriesExporter;

        DocumentExporter * mDocumentExporter;

		/** Maps material and channels to the IParamBlock of the corresponding StdUVGen*/
		const EffectExporter::MaterialChannelPairParamBlockMap & mMaterialChannelPairParamBlockMap; 

        /** The geometry as a PolyObject.*/
        PolyObject * mPolyObject;

        /** The geometry as a TriObject.*/
        TriObject * mTriObject;

        /** The geometry as a GeomObject.*/
        GeomObject * mGeomObject;

        /** True if object must be deleted by us.*/
        bool mDeleteObject;

        static const String SYMBOL_NAME_PREFIX;

    public:
        /** Constructor
        @param exportNode The node which geometry should be exported
        @param geometriesExporter The geometries exporter
        @param documentExporter The document exporter this exporter belongs to
        */
        GeometryExporter ( ExportNode * exportNode, GeometriesExporter * geometriesExporter, DocumentExporter * documentExporter );

		/** Constructor
		@param helperGeometry The helper geometry that should be exported
		@param geometriesExporter The geometries exporter
		@param documentExporter The document exporter this exporter belongs to
		*/
		GeometryExporter ( const MorphControllerHelperGeometry * helperGeometry, GeometriesExporter * geometriesExporter, DocumentExporter * documentExporter );


        /** Exports the geometry.*/
        void doExport();

        /** Returns the suffix of a texture that corresponds to channel @a channel.*/
        static String getTextureSourceIdSuffix ( int channel );


    private:
        GeometryExporter ( const GeometryExporter & geometryExporter );
        GeometryExporter & operator= ( const GeometryExporter & geometryExporter );

        /** Retrieves the base object and its super class id.*/
        void GeometryExporter::getBaseObjectAndID ( Object*& object, SClass_ID& sid );

        /** Classifies the object, i.e. check if it is a triObject or a polyObject.*/
        void GeometryExporter::classifyObject ( Object* object /*, bool affectsControllers*/ );

        /** Returns true if the current geometry is an editable polygon, false if it is a triangle mesh.*/
        bool isEditablePoly()
        {
            return mTriObject == 0;
        }

        /** Exports all the geometries in @a node and all its child nodes.*/
        void doExport ( const ExportNode* exportNode );

        /** Exports the positions of the mesh.*/
        void exportPositions();

		/** Exports the positions of the mesh retrieved from the morph controller.*/
		void exportMorphHelperPositions();

        /** Exports the normals of the mesh.*/
        void exportNormals();

        /** Exports the normals of a triangle mesh.*/
        void exportTriangleMeshNormals();

        /** Exports the normals of a editable poly mesh. */
        void exportEditablePolyNormals();

        /** Exports the textures of @a mesh.*/
        void exportTextures ( const ChannelList & channelList, Mtl* material );

        /** Exports the texture channel of @a mesh.*/
        void exportTextureChannel ( int channelIndex, Mtl* material );

        /** Exports the vertices element.*/
        void exportVertices ( const String & meshId );

        /** Exports the mesh as triangles.*/
        void exportTriangles ( const String & symbol, unsigned long numberOfFaces, int matId, size_t numMaterials, const ChannelList & channelList );

        /** Exports the mesh as a polylist.*/
        void exportPolylist ( const String & symbol, COLLADA::Polylist & polylist, int matId, size_t numMaterials, const ChannelList & channelList );

        /** Create list of materials used by this geometry.*/
        void flattenMaterials ( Mtl* material, MaterialList& mtlMap, int materialIndex = -1 );
    };

}

#endif //__COLLADAMAX_GEOMETRYEXPORTER_H__




