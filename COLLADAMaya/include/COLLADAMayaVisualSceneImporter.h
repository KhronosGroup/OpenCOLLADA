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

#ifndef __COLLADA_MAYA_VISUAL_SCENE_IMPORTER_H__
#define __COLLADA_MAYA_VISUAL_SCENE_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"
#include "COLLADAMayaNode.h"

#include "MayaDMTransform.h"
#include "MayaDMShadingEngine.h"
#include "MayaDMMaterialInfo.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWSkew.h"

#include "COLLADABUIDList.h"

#include "Math/COLLADABUMathUtils.h"
#include "Math/COLLADABUMathMatrix4.h"
#include "Math/COLLADABUMathQuaternion.h"

#include <map>
#include <set>


namespace COLLADAMaya
{

    /** Declares the importer implementation to import the visual scene nodes. */
    class VisualSceneImporter : public BaseImporter
    {

    private:

        class ShaderData
        {
        private:
            MayaDM::ShadingEngine* mShadingEngine; 
            MayaDM::MaterialInfo* mMaterialInfo;

        public:
            ShaderData () : mShadingEngine (0), mMaterialInfo (0) {}
            ShaderData ( 
                MayaDM::ShadingEngine* shadingEngine, 
                MayaDM::MaterialInfo* materialInfo ) 
                : mShadingEngine ( shadingEngine )
                , mMaterialInfo ( materialInfo )
            {}
            virtual ~ShaderData() {}

            MayaDM::ShadingEngine* getShadingEngine () const { return mShadingEngine; }
            MayaDM::MaterialInfo* getMaterialInfo () const { return mMaterialInfo; }

        private:
            /** Disable default copy ctor. */
            ShaderData( const ShaderData& pre );
            /** Disable default assignment operator. */
            const ShaderData& operator= ( const ShaderData& pre );

        };

        typedef std::map<COLLADAFW::MaterialId, ShaderData*> ShaderDataMap;

    private:

        /** The standard name for a transform node without name. */
        static const String TRANSFORM_NODE_NAME;

        /** The standard name for a shading engine. */
        static const String SHADING_ENGINE_NAME;

        /** The standard name for a material info. */
        static const String MATERIAL_INFO_NAME;

    private:

        /**
         * The list of the unique maya transform node names.
         */
        COLLADABU::IDList mTransformNodeIdList;

        /*
         * The map holds for every unique id of a geometry a list of transform node unique ids.
         * We need it for the creation of the geometry, to set the parent transform nodes.
         */
        UniqueIdUniqueIdsMap mGeometryTransformIdsMap;

        /** 
        * The map holds the unique ids of the nodes to the full node pathes (contains the name). 
        */
        UniqueIdMayaNodesMap mMayaTransformNodesMap;

        /**
        * The list of the unique maya shading engine names.
        */
        COLLADABU::IDList mShadingEngineIdList;
        COLLADABU::IDList mMaterialInfoIdList;

        /**
         * The map with the unique ids of the shading engine to the shading engines itself. 
         */
        ShaderDataMap mShaderDataMap;

        /*
         *	Helper class, to handle the transformations.
         */
        class MayaTransformation
        {
        public:
            MayaTransformation () 
                : phase (0)
                , translate1 ( 0,0,0 ) 
                , translate1Vec (0)
                , numTranslate1 (0)
                , translate2 ( 0,0,0 ) 
                , translate2Vec (0)
                , numTranslate2 (0)
                , translate3 ( 0,0,0 ) 
                , translate3Vec (0)
                , numTranslate3 (0)
                , scale ( 1,1,1 ) 
                , skew ( 0,0,0 )
            {}
            virtual ~MayaTransformation () {}

            static const size_t PHASE_TRANS1 = 1;
            static const size_t PHASE_ROTATE = 2;
            static const size_t PHASE_TRANS2 = 3;
            static const size_t PHASE_SCALE = 4;
            static const size_t PHASE_TRANS3 = 5;

            MVector translate1; // = 0,0,0
            std::vector<MVector> translate1Vec;
            size_t numTranslate1;

            MQuaternion rotation; // = 1,0,0,0

            MVector translate2; // = 0,0,0
            std::vector<MVector> translate2Vec;
            size_t numTranslate2;

            MVector skew; // = 0,0,0
            MVector scale; // = 1,1,1

            MVector translate3; // = 0,0,0
            std::vector<MVector> translate3Vec;
            size_t numTranslate3;
            

            // 5 phases
            size_t phase;
        };

    public:

        /** Constructor. */
        VisualSceneImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~VisualSceneImporter () {}

        /** 
         * Import the current visual scene with all scene nodes and transforms. 
         */
        bool importVisualScene ( const COLLADAFW::VisualScene* visualScene );

        /** 
        * The map holds the unique ids of the nodes to the full node pathes (contains the name). 
        */
        const MayaNode* getMayaTransformNode ( const COLLADAFW::UniqueId& uniqueId ) const;

        /** 
        * The map holds the unique ids of the nodes to the full node pathes (contains the name). 
        */
        MayaNode* getMayaTransformNode ( const COLLADAFW::UniqueId& uniqueId );

        /*
        * The map holdes for every geometry (identified by it's unique id ) a list of all 
        * transform nodes (identified by their names, which are unique!).
        * We need it for the creation of the geometry, to set the parent transform nodes.
        */
        const std::set<const COLLADAFW::UniqueId>* getGeometryTransformIds ( 
            const COLLADAFW::UniqueId& geometryId ) const;

    private:

        /*
        * Imports the data of the current node.
        */
        void importNode ( 
            const COLLADAFW::Node* rootNode, 
            const COLLADAFW::UniqueId* parentNodeId = NULL );

        /**
         *	Save the transformation ids to the geometry ids.
         */
        bool readGeometryInstances (
            const COLLADAFW::Node* node, 
            MayaDM::Transform* transformNode );

        /**
         * Read the shading engines.
         */
        void readMaterialInstances ( const COLLADAFW::InstanceGeometry* instanceGeometry );

        /**
         * Handle the node instances. 
         */
        bool readNodeInstances ( const COLLADAFW::Node* node );

        /*
         *	Transform the input matrix and convert it in a double[4][4] matrix.
         */
        void convertMatrix4ToTransposedDouble4x4 ( 
            const COLLADABU::Math::Matrix4& inputMatrix, 
            double outputMatrix[][4] );

        /** 
         * Imports the current transformations. 
         */
        bool importTransformations ( 
            const COLLADAFW::Node* rootNode, 
            MayaDM::Transform* transformNode );

        /**
         * Returns true, if the transform values from the framework is conform to the maya 
         * transformation and fills the maya transform values.
         */
        bool isValidMayaTransform ( 
            const COLLADAFW::Node* rootNode, 
            MayaTransformation& mayaTransform, 
            bool& hasRotatePivot,
            bool& hasScalePivot );

        /**
         * Set the transform values.
         */
        void importDecomposedTransform ( 
            const MayaTransformation &mayaTransform, 
            MayaDM::Transform* transformNode, 
            const bool hasRotatePivot,
            const bool hasScalePivot );

        /**
         * Imports the transform values from a transform matrix.
         * Data loss: no animation possible!
         */
        void importMatrixTransform ( 
            const COLLADAFW::Node* rootNode, 
            MayaDM::Transform* transformNode );

        /**
        * Creates a node or joint object.
        */
        MayaDM::Transform* createNode ( 
            const COLLADAFW::Node* node, 
            const String& nodeName, 
            const String& parentNodeName );

        /**
        * Converts the skew into a matrix.
        */
        void skewValuesToMayaMatrix ( const COLLADAFW::Skew* skew, MMatrix& matrix ) const;

        /**
        * The list of the unique maya shading engine names.
        */
        const COLLADABU::IDList& getShadingEngineIdList () const { return mShadingEngineIdList; }

        /**
        * The map with the unique ids of the shading engine to the shading engines itself. 
        */
        const ShaderDataMap& getShadingEnginesMap () const { return mShaderDataMap; }

        /**
        * The map with the unique ids of the shading engine to the shading engines itself. 
        */
        ShaderData* findShaderData ( const COLLADAFW::MaterialId& val );

        /**
        * The map with the unique ids of the shading engine to the shading engines itself. 
        */
        void appendShaderData ( 
            const COLLADAFW::MaterialId& val, 
            MayaDM::ShadingEngine* shadingEngine, 
            MayaDM::MaterialInfo* materialInfo );

    };
}

#endif // __COLLADA_MAYA_VISUAL_SCENE_IMPORTER_H__