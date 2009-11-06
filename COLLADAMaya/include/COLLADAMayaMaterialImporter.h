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

#ifndef __COLLADA_MAYA_MATERIAL_IMPORTER_H__
#define __COLLADA_MAYA_MATERIAL_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"
#include "COLLADAMayaShadingBinding.h"
#include "COLLADAMayaGeometryBinding.h"

#include "MayaDMDependNode.h"
#include "MayaDMShadingEngine.h"
#include "MayaDMMaterialInfo.h"
#include "MayaDMTransform.h"
#include "MayaDMUvChooser.h"

#include "COLLADAFWInstanceGeometry.h"


namespace COLLADAMaya
{

    /** Declares the importer class for import materials. */
    class MaterialImporter : public BaseImporter
    {

    public:

        /** The name of maya's initial shading engine. */
        static const String INITIAL_SHADING_ENGINE_NAME;

        /** The name of maya's initial material info. */
        static const String INITIAL_MATERIAL_INFO_NAME;

    private:

        /** The standard name for a shading engine. */
        static const String SHADING_ENGINE_NAME;

        /** The standard name for a material info. */
        static const String MATERIAL_INFO_NAME;

        /** The standard name for a material without name. */
        static const String MATERIAL_NAME;

        /** The name of maya's default shader list. */
        static const String DEFAULT_SHADER_LIST;
        static const String ATTR_SHADERS;

        static const String DEFAULT_RENDER_PARTITION;

        /** The name for an uv chooser. */
        static const String UV_CHOOSER_NAME;

    public:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::DependNode*> UniqueIdMayaMaterialMap;

    public:

        /**
         * The maya shading engine and material info.
         * Holds the shadingEngine and the materialInfo.
         */
        class ShadingData
        {
        private:
            MayaDM::ShadingEngine mShadingEngine; 
            MayaDM::MaterialInfo mMaterialInfo;

        public:
            ShadingData () {}
            ShadingData ( const MayaDM::ShadingEngine& shadingEngine, const MayaDM::MaterialInfo& materialInfo ) 
                : mShadingEngine ( shadingEngine )
                , mMaterialInfo ( materialInfo )
            {}

            const MayaDM::ShadingEngine& getShadingEngine () const { return mShadingEngine; }
            const MayaDM::MaterialInfo& getMaterialInfo () const { return mMaterialInfo; }
        };
        /** 
         * Holds for a material id the shadingEngine and materialInfo. 
         */
        typedef std::map<COLLADAFW::UniqueId, ShadingData*> ShadingDataMap;

        /**
        * Used to store informations about multiple input sets of an primitive element in an
        * TEXCOORD or COLOR input element. 
        */
        class BindingInputSet
        {
        private:
            COLLADAFW::UniqueId mGeometryId;
            COLLADAFW::UniqueId mInstanciatedObjectId;
            COLLADAFW::UniqueId mTransformNodeId;
            const COLLADAFW::UniqueId* mControllerId;
            size_t mInputSetIndex;
            COLLADAFW::TextureMapId mTextureMapId;
            COLLADAFW::UniqueId mMaterialId;
            COLLADAFW::MaterialId mShadingEngineId;
            MayaDM::UvChooser mUvChooser;
            size_t mPhysicalIndex;
            bool mHasChooser;

        public:
            BindingInputSet () : mHasChooser ( false ) {}
            virtual ~BindingInputSet() {}

            const COLLADAFW::UniqueId& getGeometryId () const { return mGeometryId; }
            void setGeometryId ( const COLLADAFW::UniqueId& val ) { mGeometryId = val; }

            const COLLADAFW::UniqueId& getInstanciatedObjectId () const { return mInstanciatedObjectId; }
            void setInstanciatedObjectId ( const COLLADAFW::UniqueId& val ) { mInstanciatedObjectId = val; }

            const COLLADAFW::UniqueId& getTransformNodeId () const { return mTransformNodeId; }
            void setTransformNodeId ( const COLLADAFW::UniqueId& val ) { mTransformNodeId = val; }

            const COLLADAFW::UniqueId* getControllerId () const { return mControllerId; }
            void setControllerId ( const COLLADAFW::UniqueId* val ) { mControllerId = val; }

            const size_t& getInputSetIndex () const { return mInputSetIndex; }
            void setInputSetIndex ( const size_t& val ) { mInputSetIndex = val; }

            const COLLADAFW::UniqueId& getMaterialId () const { return mMaterialId; }
            void setMaterialId ( const COLLADAFW::UniqueId& val ) { mMaterialId = val; }

            const COLLADAFW::MaterialId& getShadingEngineId () const { return mShadingEngineId; }
            void setShadingEngineId ( const COLLADAFW::MaterialId& val ) { mShadingEngineId = val; }

            const MayaDM::UvChooser* getUvChooser () const { if ( mHasChooser ) return &mUvChooser; else return 0; }
            void setUvChooser ( const MayaDM::UvChooser& val ) { mUvChooser = val; mHasChooser = true; }

            const size_t getPhysicalIndex () const { return mPhysicalIndex; }
            void setPhysicalIndex ( const size_t val ) { mPhysicalIndex = val; }

            const COLLADAFW::TextureMapId& getTextureMapId () const { return mTextureMapId; }
            void setTextureMapId ( const COLLADAFW::TextureMapId& val ) { mTextureMapId = val; }
        };

    private:

        /**
        * The map holds for every material a list of multiple texcoord input elements 
        * with the input set indices for every primitive element in the source.
        */
        std::map<COLLADAFW::UniqueId, std::vector<BindingInputSet> > mBindingTexCoordInputSetsMap;

        /** 
        * The map holds the unique ids of the material nodes to the maya specific nodes. 
        */
        UniqueIdMayaNodeMap mMayaMaterialNodesMap;

        /**
         * The map holds the unique effect id to a material id.
         */
        UniqueIdUniqueIdMap mMaterialIdEffectIdMap;

        /**
         * The map holds for every unique material id the original collada id.
         */
        UniqueIdStringMap mMaterialIdOriginalColladaId;

        /**
        * The map with the unique ids of the shading engine to the shading engines itself. 
        */
        ShadingDataMap mShaderDataMap;

        /**
         * The map holds for every shader engine a list of geometry ids, which use this shader engine.
         */
        GeometryMaterialBindingsMap mGeometryMaterialBindingsMap;

        /**
        * The map holds for every material all already bound chooser names.
        */
        std::map<COLLADAFW::UniqueId, std::vector<String> > mChooserMaterialConnections; 

        /**
        * The map holds for every geometry all already bound chooser names.
        */
        std::map<COLLADAFW::UniqueId, std::vector<String> > mChooserGeometryConnections; 

    public:

        /** Constructor. */
        MaterialImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~MaterialImporter ();

        /** Imports the given material. */
        bool importMaterial ( const COLLADAFW::Material* material );

        /** Write the shader data into the maya file. */
        void writeShaderData ( 
            const COLLADAFW::UniqueId& transformNodeId, 
            const COLLADAFW::InstanceGeometry* instanceGeometry,
            const COLLADAFW::UniqueId* controllerId );

        /**
         * Create the shader engine and the material info objects and returns them.
         */
        ShadingData* createShaderData ( 
            const COLLADAFW::UniqueId& materialId, 
            String shadingEngineName = EMPTY_STRING );

        /**
        * Create the necessary uv chooser objects for texture uv set binding.
        */
        void createBindingInputSets ( 
            const COLLADAFW::UniqueId& transformNodeId, 
            const COLLADAFW::InstanceGeometry* instanceGeometry,
            const COLLADAFW::UniqueId* controllerId );

        /**
         * An uv-chooser will be generated, if
         * 1.) a material uses a texture and
         * 2.) the material is used by one or more primitive element of one or more geometries and
         * 3.) the primitive element of the geometry has more than one uv-set and
         * 4.) the scenegraph uses this texture with an uv-set-index, which is not the first one.
         * 
         * We need one uv-chooser for every texture in a material, if the points above are right. 
         * If there exist multiple instances of the geometry, we can't change the uv-mapping in maya!
         * If the material is referenced for multiple times (multiple geometries use the material),
         * we use for every reference just the next index of the material's texture's uv-chooser's uv-set.
         * 
         * The uv-chooser has to be generated, AFTER the import of the geometries!
        */
        void createUVChoosers ();

        /** 
        * Writes the connection attributes into the maya ascii file. 
        */
        void writeConnections ();

        /**
        * The map with the unique ids of the shading engine to the shading engines itself. 
        */
        const ShadingDataMap& getShadingEnginesMap () const { return mShaderDataMap; }

        /**
        * The map with the unique id of material to the shading engine data. 
        */
        ShadingData* findShaderData ( const COLLADAFW::UniqueId& materialId );

        /**
        * Returns the maya node of the given material id.
        */
        MayaNode* findMayaMaterialNode ( const COLLADAFW::UniqueId& materialId );

        /**
        * The map holds for every unique material id the original collada id.
        */
        const String& findOriginalColladaId ( const COLLADAFW::UniqueId& materialId );

    private:

        /** 
         * Connect the material with the shading engine and the material info. 
         */
        void connectShadingEngines ();

        /**
         * Connects the shading engines with the object groups.
         */
        void connectShadingEngineObjectGroups ();

        /** 
         * Connects the material with the depending geometries. 
         */
        void connectGeometries ();

        /**
        * Connects the uv chooser with the texture placements and the uv sets of the meshes.
        */
        void connectUVChooser ();

        /**
         * Returns true, if the uvChooser is already bound to the given material.
         */
        const bool chooserIsMaterialConnected ( 
            const COLLADAFW::UniqueId& materialId, 
            const String& uvChooserName ) const;

        /**
        * Returns true, if the uvChooser is already bound to the given geometry.
        */
        const bool chooserIsGeometryConnected ( 
            const COLLADAFW::UniqueId& geometryId, 
            const String& uvChooserName ) const;

        /**
         * Returns the number of already connected geometries to the current uv-chooser.
         */
        const size_t getNumGeometryConnections ( 
            const String& uvChooserName ) const;

        /**
         * Connects the default shader list with the materials.
         */
        void connectDefaultShaderList ();

        /**
         * Returns the effect id of the material.
         */
        const COLLADAFW::UniqueId* findEffectId ( const COLLADAFW::UniqueId& materialId );

        /**
        * The map holds for every geometry a list of multiple texcoord input elements 
        * with the input set indices.
        */
        const std::vector<BindingInputSet>* findBindingTexCoordInputSets ( 
            const COLLADAFW::UniqueId& materialId );

        /**
        * The map holds for every geometry a list of multiple texcoord input elements 
        * with the input set indices.
        */
        const BindingInputSet* findBindingTexCoordInputSet ( 
            const COLLADAFW::UniqueId& sourceId, 
            const COLLADAFW::UniqueId& materialId, 
            const size_t inputSetIndex );

        /**
        * Get the uv chooser of the current instanciated obect and material.
        */
        const MayaDM::UvChooser* findUvChooser ( 
            const COLLADAFW::UniqueId& materialId, 
            const COLLADAFW::TextureMapId& textureMapId );


    };
}

#endif // __COLLADA_MAYA_MATERIAL_IMPORTER_H__