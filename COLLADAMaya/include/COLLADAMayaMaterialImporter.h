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

#ifndef __COLLADA_MAYA_MATERIAL_IMPORTER_H__
#define __COLLADA_MAYA_MATERIAL_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADABUIDList.h"

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

    private:

        /** The standard name for a shading engine. */
        static const String SHADING_ENGINE_NAME;

        /** The standard name for a material info. */
        static const String MATERIAL_INFO_NAME;

        /** The standard name for a material without name. */
        static const String MATERIAL_NAME;

        /** The name of maya's default shader list. */
        static const String DEFAULT_SHADER_LIST;
        static const String INITIAL_SHADING_ENGINE;
        static const String ATTR_SHADERS;

    public:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::DependNode*> UniqueIdMayaMaterialMap;

    private:

        /**
         * The maya shading engine and material info.
         */
        class ShadingData
        {
        private:
            MayaDM::ShadingEngine* mShadingEngine; 
            MayaDM::MaterialInfo* mMaterialInfo;

        public:
            ShadingData () : mShadingEngine (0), mMaterialInfo (0) {}
            ShadingData ( 
                MayaDM::ShadingEngine* shadingEngine, 
                MayaDM::MaterialInfo* materialInfo ) 
                : mShadingEngine ( shadingEngine )
                , mMaterialInfo ( materialInfo )
            {}
            virtual ~ShadingData() 
            {
                delete mShadingEngine;
                delete mMaterialInfo;
            }

            MayaDM::ShadingEngine* getShadingEngine () const { return mShadingEngine; }
            MayaDM::MaterialInfo* getMaterialInfo () const { return mMaterialInfo; }
        };
        typedef std::map<COLLADAFW::UniqueId, ShadingData*> ShadingDataMap;

        /**
         * The binding of a geometry instance to a material.
         */
        class ShadingBinding
        {
        private:
            COLLADAFW::UniqueId mGeometryId;
            COLLADAFW::UniqueId mTransformNodeId;
            COLLADAFW::UniqueId mMaterialId;

        public:
            ShadingBinding () {}
            virtual ~ShadingBinding () {}

            const COLLADAFW::UniqueId& getGeometryId () const { return mGeometryId; }
            void setGeometryId ( const COLLADAFW::UniqueId& val ) { mGeometryId = val; }

            const COLLADAFW::UniqueId& getTransformNodeId () const { return mTransformNodeId; }
            void setTransformNodeId ( const COLLADAFW::UniqueId& val ) { mTransformNodeId = val; }

            const COLLADAFW::UniqueId& getMaterialId () const { return mMaterialId; }
            void setMaterialId ( const COLLADAFW::UniqueId& val ) { mMaterialId = val; }
        };
        typedef std::map<COLLADAFW::MaterialId, std::set<ShadingBinding*>> ShadingEngineBindingMap;

    private:

        /**
        * The list of the unique maya material names.
        */
        COLLADABU::IDList mMaterialIdList;

        /** 
        * The map holds the unique ids of the nodes to the maya material name. 
        */
        UniqueIdNamesMap mMayaMaterialNamesMap;

        /**
         * The map holds the maya material objects.
         */
        UniqueIdMayaMaterialMap mMayaMaterialMap;

        /**
         * The map holds the unique effect ids to a material id.
         */
        UniqueIdUniqueIdMap mMaterialIdEffectIdMap;

        /**
        * The list of the unique maya shading engine names.
        */
        COLLADABU::IDList mShadingEngineIdList;
        COLLADABU::IDList mMaterialInfoIdList;

        /**
        * The map with the unique ids of the shading engine to the shading engines itself. 
        */
        ShadingDataMap mShaderDataMap;

        /**
         * The map holds for every shader engine a list of geometry ids, which use this shader engine.
         */
        ShadingEngineBindingMap mShadingEngineBindingMap;

    public:

        /** Constructor. */
        MaterialImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~MaterialImporter ();

        /** Imports the given material. */
        bool importMaterial ( const COLLADAFW::Material* material );

        /** Write the shader data into the maya file. */
        void writeShaderData ( 
            const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding, 
            const COLLADAFW::UniqueId& transformNodeId, 
            const COLLADAFW::InstanceGeometry* instanceGeometry );

        /** 
        * Writes the connection attributes into the maya ascii file. 
        */
        void writeConnections ();

        /**
        * The map holds the maya material objects.
        */
        MayaDM::DependNode* findMayaMaterial ( const COLLADAFW::UniqueId& val ) const;

    private:

        /** Connect the material with the shading engine and the material info. */
        void connectShadingEngines ();

        /** Connect the material with the depending geometries. */
        void connectGeometries ();

        /** If there are some object groups, we have to connect them with the geometries. */
        void connectGeometryGroups ();

        /**
         * Connects the default shader list with the materials.
         */
        void connectDefaultShaderList ();

        /**
        * The map holds the maya material objects.
        */
        const UniqueIdMayaMaterialMap& getMayaMaterialMap () const { return mMayaMaterialMap; }

        /**
        * The map holds the maya material objects.
        */
        void appendMaterial ( const COLLADAFW::UniqueId& id, MayaDM::DependNode* materialNode );

        /**
        * The list of the unique maya shading engine names.
        */
        const COLLADABU::IDList& getShadingEngineIdList () const { return mShadingEngineIdList; }

        /**
        * The map with the unique ids of the shading engine to the shading engines itself. 
        */
        const ShadingDataMap& getShadingEnginesMap () const { return mShaderDataMap; }

        /**
        * The map with the unique ids of the shading engine to the shading engines itself. 
        */
        ShadingData* findShaderData ( const COLLADAFW::UniqueId& val );

        /**
         * Returns the effect id of the material.
         */
        const COLLADAFW::UniqueId* findEffectId ( const COLLADAFW::UniqueId& materialId );

        /**
        * The map with the unique ids of the shading engine to the shading engines itself. 
        */
        void appendShaderData ( 
            const COLLADAFW::UniqueId& uniqueMaterialId, 
            MayaDM::ShadingEngine* shadingEngine, 
            MayaDM::MaterialInfo* materialInfo );

        /**
        * Find the index of the transform node of the current geometry instance.
        * This is the geometry instance index we use to set the current connection to.
        */
        size_t getGeometryInstanceIndex ( 
            const COLLADAFW::UniqueId& geometryId, 
            const COLLADAFW::UniqueId& transformNodeId );

    };
}

#endif // __COLLADA_MAYA_MATERIAL_IMPORTER_H__