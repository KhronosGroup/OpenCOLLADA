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

#ifndef __COLLADA_MAYA_MATERIAL_EXPORTER_H__
#define __COLLADA_MAYA_MATERIAL_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryMaterials.h"
#include "COLLADASWSampler.h"
#include "COLLADASWValueType.h"

#include "COLLADABUIDList.h"

#include <cgfxAttrDef.h>

#include <maya/MObject.h>

#include <map>

class DocumentExporter;

namespace COLLADAMaya
{
    /** Map for the materials. */
    typedef std::map<String, MObject> MaterialMap;


    /** This class writes the <library_materials>. It uses informations created by the effect exporter*/
    class MaterialExporter : public COLLADASW::LibraryMaterials
    {
    private:

        /** Holds information about an already exported effect*/
        class ExportedEffect
        {
            MObject* shader; // The shader object, that was used to export the effect
            unsigned long mColor;  // The color that was used to export the effect
        };

	public:
		
		typedef std::set<String> SidSet;
		static SidSet mSurfaceSidList;

    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /**
        * The list of the unique collada ids.
        */
        COLLADABU::IDList mMaterialIdList;

        /**
        * The list of the unique collada ids.
        */
        COLLADABU::IDList mEffectIdList;

        /** 
         * Maps already exported materials to the corresponding collada material id.
         */
        MaterialMap mMaterialMap;

        /**
         * A collada effect id for every maya material id.
         */
        StringToStringMap mMayaIdColladaEffectIdMap;

        /**
        * A collada material id for every maya material id.
        */
        StringToStringMap mMayaIdColladaMaterialIdMap;

        /** true, if the material std::map is already read in */
        bool materialMapInitialized;

        /**
        * false, if the materials shouldn't be written.
        * If you call the @exportMaterials() function, just the list with all materials will be filled.
        */
        bool mWriteMaterials;

        /** list already exported materials with the corresponding collada material id*/
        std::vector<String> mExportedMaterials;

        /** The filename of the current shader to export. */
        COLLADASW::URI mShaderFxFileUri;

        /** 
         * Avoid export of dublicate sampler params. 
         */
        std::set<String> mSamplers;

    public:

        /**
        @param streamWriter The stream the output will be written to
        @paramdocumentExporter The document exporter this material exporter is used in*/
        MaterialExporter ( COLLADASW::StreamWriter* streamWriter, DocumentExporter* documentExporter );

        /** Exports all Materials which are in the material list @mMaterialsMap for export */
        MaterialMap* exportMaterials ( bool writeMaterials=true );

        /** Returns the std::map with all the materials */
        MaterialMap* getExportedMaterialsMap();

        /**
        * A collada effect id for every maya material id.
        */
        const String findColladaEffectId ( const String& mayaMaterialId );

        /**
        * A collada effect id for every maya material id.
        */
        const String findColladaMaterialId ( const String& mayaMaterialId );

    private:

        /** Returns the tolerance value for double value comparison. */
        const double getTolerance () const 
        {
            return mDocumentExporter->getTolerance ();
        }

        /** Set the filename of the current shader to export. */
        void setShaderFxFileUri ( const COLLADASW::URI& shaderFxFileName );

        /** Returns the filename of the current shader fx file. */
        const COLLADASW::URI& getShaderFxFileUri () const;

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

        /** Export the reference to the effect and, in case of an hardware shader, 
            the effect technique reference and the hardware shader parameters. */
        void exportEffectInstance ( 
            const String& mayaMaterialId, 
            const String& colladaMaterialId, 
            MObject& shader );

        /** Exports the data for a custom hardware shader node. */
        void exportCustomHwShaderNode ( COLLADASW::InstanceEffect &effectInstance, MObject shader );

        /** Adds the technique hint and the effect attributes to the collada document. */
        void exportCgfxShaderNode ( COLLADASW::InstanceEffect &effectInstance, cgfxShaderNode *fnNode );

        /** Adds a <setparam> of the given attribute to the collada document. */
        void setSetParam ( const cgfxShaderNode* shaderNodeCgfx, const cgfxAttrDef* attribute );

        /** Adds the <setparam> element of the attributes texture. */
        void setSetParamTexture (
            const cgfxAttrDef* attribute, 
            MObject textureNode, 
            COLLADASW::Sampler::SamplerType samplerType, 
            COLLADASW::ValueType::ColladaType samplerValueType );

    };
}

#endif //__COLLADA_MAYA_MATERIAL_EXPORTER_H__
