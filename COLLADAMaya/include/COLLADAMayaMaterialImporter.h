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

    private:

        /**
        * The list of the unique maya material names.
        */
        COLLADABU::IDList mMaterialIdList;

        /**
        * The list of the unique maya shading engine names.
        */
        COLLADABU::IDList mShadingEngineIdList;

        /**
        * The list of the unique maya material info names.
        */
        COLLADABU::IDList mMaterialInfoIdList;

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
        GeometryBindingMaterialInfosMap mGeometryBindingMaterialInfosMap;

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
            String shadingEngineName = "" );

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
         * Connects the default shader list with the materials.
         */
        void connectDefaultShaderList ();

        /**
        * The list of the unique maya shading engine names.
        */
        const COLLADABU::IDList& getShadingEngineIdList () const { return mShadingEngineIdList; }

        /**
         * Returns the effect id of the material.
         */
        const COLLADAFW::UniqueId* findEffectId ( const COLLADAFW::UniqueId& materialId );

    };
}

#endif // __COLLADA_MAYA_MATERIAL_IMPORTER_H__