/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_MATERIAL_EXPORTER_H__
#define __COLLADA_MAYA_MATERIAL_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"
#include <map>

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryMaterials.h"

#include <maya/MObject.h>

class DocumentExporter;

namespace COLLADAMaya
{
    /** Map for the materials. */
    typedef std::map<String, MObject> MaterialMap;

    /** This class writes the <library_materials>. It uses informations created by the effect exporter*/

    class MaterialExporter : public COLLADA::LibraryMaterials
    {

    private:

        /** Holds information about an already exported effect*/

        class ExportedEffect
        {
            MObject* shader; // The shader object, that was use to export the effect
            DWORD mColor;  // The color that was used to export the effect
        };

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /** maps already exported materials to the corresponding collada material id*/
        MaterialMap mMaterialMap;

        /** true, if the material std::map is already read in */
        bool materialMapInitialized;

        /**
        * false, if the materials shouldn't be written.
        * If you call the @exportMaterials() function, just the list with all materials will be filled.
        */
        bool mWriteMaterials;

        /** list already exported materials with the corresponding collada material id*/
        std::vector<String> mExportedMaterials;

    public:

        /**
        @param streamWriter The stream the output will be written to
        @paramdocumentExporter The document exporter this material exporter is used in*/
        MaterialExporter ( COLLADA::StreamWriter* streamWriter, DocumentExporter* documentExporter );

        /** Exports all Materials which are in the material list @mMaterialsMap for export */
        MaterialMap* exportMaterials ( bool writeMaterials=true );

        /** Returns the std::map with all the materials */
        MaterialMap* getExportedMaterialsMap();

    private:

        /**
        * Get all shaders, which are in the default shader list.
        * Unfortunately, you will not get the default initialShadingGroup elements,
        * which are directly connected to an object, if no other material (shader) is
        * connected to the object.
        */
        void exportMaterialsByShaderPlug();

        /**
         * Go through scene graph and find all shaders, connected to the meshes.
         * So you can find the default shaders of an object.
         */
        void exportMaterialsBySceneGraph();

        /** Puts all materials which are connected to the current scene element (if it is a mesh)
        and does the same recursive for all elements children. */
        void exportConnectedMaterials ( SceneElement* sceneElement );

        /** Writes the material of the shading engine into the collada document
        and adds the material into the materials list. */
        void exportMaterial ( MObject shadingEngine );

    };
}

#endif //__COLLADA_MAYA_MATERIAL_EXPORTER_H__
