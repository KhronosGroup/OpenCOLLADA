/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_VISUAL_SCENE_IMPORTER_H__
#define __DAE2MA_VISUAL_SCENE_IMPORTER_H__

#include "DAE2MAStableHeaders.h"
#include "DAE2MABaseImporter.h"
#include "DAE2MANode.h"
#include "DAE2MAAnimationImporter.h"
#include "DAE2MATransformAnimation.h"

#include "MayaDMTransform.h"
#include "MayaDMJoint.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWLibraryNodes.h"
#include "COLLADAFWSkew.h"

#include "Math/COLLADABUMathUtils.h"
#include "Math/COLLADABUMathMatrix4.h"
#include "Math/COLLADABUMathQuaternion.h"

#include <map>
#include <set>


namespace DAE2MA
{

    /** Declares the importer implementation to import the visual scene nodes. */
    class VisualSceneImporter : public BaseImporter
    {

    private:

        /** The standard name for a transform node without name. */
        static const String TRANSFORM_NODE_NAME;

    private:

        /**
         * The dummy maya root node.
         */
        MayaNode mDummyRootMayaNode;

        /** 
        * The map holds the unique ids of the nodes to the full node pathes (contains the name). 
        */
        UniqueIdMayaNodesMap mMayaTransformNodesMap;

        /**
         * The map holds for every unique transform node id the maya data model transform object
         * of the transform node.
         */
        std::map< COLLADAFW::UniqueId, MayaDM::Transform > mMayaDMTransformMap;

        /**
         * The map holds for every transform node a list of all existing parent transform nodes
         * (this are the nodes, which hold an instance of the current transform node).
         */
        UniqueIdUniqueIdsMap mTransformInstancesMap;

        /**
         * The map holds for every unique id of a geometry a list of transform node unique ids.
         * We need it for the creation of the geometry, to set the parent transform nodes.
         */
        UniqueIdUniqueIdsMap mGeometryTransformIdsMap;

        /**
        * The map holds for every unique id of a camera a list of transform node unique ids.
        * We need it for the creation of the camera, to set the parent transform nodes.
        */
        UniqueIdUniqueIdsMap mCameraTransformIdsMap;

        /**
        * The map holds for every unique id of a light a list of transform node unique ids.
        * We need it for the creation of the light, to set the parent transform nodes.
        */
        UniqueIdUniqueIdsMap mLightTransformIdsMap;

        /**
        * The map holds for every unique id of a controller a list of transform node unique ids.
        * We need it for the creation of the controller, to set the parent transform nodes.
        */
        UniqueIdUniqueIdsMap mControllerTransformIdsMap;

        /**
         * Set the center of interest distance value in a map to the current transform node.
         */
        std::map<COLLADAFW::UniqueId, double> mCenterOfInterestDistances;

        /**
         * The map holds for every animationListId the unique id of corresponding node.
         */
        std::map <COLLADAFW::UniqueId, TransformAnimation> mTransformAnimationMap;

    public:

        /** Constructor. */
        VisualSceneImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~VisualSceneImporter ();

        /** 
         * Import the current visual scene with all scene nodes and transforms. 
         */
        void importVisualScene ( const COLLADAFW::VisualScene* visualScene );

//         /** 
//         * Import the library nodes with all nodes. 
//         */
//         void importLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes );

        /**
        * Write the parenting informations about node instances into the maya ascii file.
        */
        void writeNodeInstances ();

        /** 
        * The map holds the unique ids of the nodes to the full node pathes (contains the name). 
        */
        const UniqueIdMayaNodesMap& getMayaTransformNodesMap () const { return mMayaTransformNodesMap; }

        /** 
        * The map holds the unique ids of the nodes to the full node pathes (contains the name). 
        */
        MayaNodesList* findMayaTransformNodes ( const COLLADAFW::UniqueId& transformId );

        /** 
        * The map holds the unique ids of the nodes to the full node pathes (contains the name). 
        */
        const MayaNodesList* findMayaTransformNodes ( const COLLADAFW::UniqueId& transformId ) const;

        /**
         * The map holds for every transform node a list of all existing parent transform nodes
         * (this are the nodes, which hold an instance of the current transform node).
         */
        const UniqueIdVec* findTransformInstances ( const COLLADAFW::UniqueId& transformId ) const;

        /*
        * The map holdes for every geometry (identified by it's unique id ) a list of all 
        * transform nodes (identified by their names, which are unique!).
        * We need it for the creation of the geometry, to set the parent transform nodes.
        */
        const UniqueIdVec* findGeometryTransformIds ( const COLLADAFW::UniqueId& geometryId ) const;

        /*
        * The map holdes for every camera (identified by it's unique id ) a list of all 
        * transform nodes (identified by their names, which are unique!).
        * We need it for the creation of the camera, to set the parent transform nodes.
        */
        const UniqueIdVec* findCameraTransformIds ( const COLLADAFW::UniqueId& cameraId ) const;

        /*
        * The map holdes for every light (identified by it's unique id ) a list of all 
        * transform nodes (identified by their names, which are unique!).
        * We need it for the creation of the light, to set the parent transform nodes.
        */
        const UniqueIdVec* findLightTransformIds ( const COLLADAFW::UniqueId& lightId ) const;

        /*
        * The map holdes for every controller (identified by it's unique id ) a list of all 
        * transform nodes (identified by their names, which are unique!).
        * We need it for the creation of the controller, to set the parent transform nodes.
        */
        const UniqueIdVec* findControllerTransformIds ( const COLLADAFW::UniqueId& controllerId ) const;

        /**
         * Determines the number of transform node instances.
         */
        size_t getNumTransformInstances ( 
            const COLLADAFW::UniqueId& transformId, 
            const bool recursive = false );

        /**
         * Returns a filled list of all existing pathes to all instances to the current node.
         */
        void getTransformPathes ( 
            std::vector<String>& transformPathes, 
            const COLLADAFW::UniqueId& transformId, 
            const String childSubPath = EMPTY_STRING );

        /*
        * The center of interest distance value in a map to the current transform node.
        */
        const std::map<COLLADAFW::UniqueId, double>& getCenterOfInterestDistances () const { return mCenterOfInterestDistances; }

        /*
        * The center of interest distance value in a map to the current transform node.
        */
        bool findCenterOfInterestDistance ( 
            const COLLADAFW::UniqueId& transformId, 
            double& centerOfInterestDistance );

        /**
        * The map holds for every animationListId the unique id of corresponding node.
        */
        const TransformAnimation* findTransformAnimation ( const COLLADAFW::UniqueId& animationListId );

        /**
        * The map holds for every unique transform node id the maya data model transform object
        * of the transform node.
        */
        MayaDM::Transform* findMayaDMTransform ( const COLLADAFW::UniqueId& transformId );

        /**
        * The map holds for every unique transform node id the maya data model transform object
        * of the transform node.
        */
        const MayaDM::Transform* findMayaDMTransform ( const COLLADAFW::UniqueId& transformId ) const;

    private:

        /*
        * Imports the data of the current node.
        * Returns the generated maya node.
        */
        MayaNode* importNode ( 
            const COLLADAFW::Node* node, 
            const COLLADAFW::Node* parentNode = NULL, 
            MayaNode* parentMayaNode = NULL );

        /**
        * Handle the node instances. 
        */
        bool importNodeInstances ( 
            const COLLADAFW::Node* node, 
            MayaNode* parentMayaNode );
        
        /**
        * Handle the node instances. 
        */
        bool readNodeInstances ( const COLLADAFW::Node* node );

        /**
         *	Save the transformation ids to the geometry ids.
         */
        bool readGeometryInstances ( const COLLADAFW::Node* node );

        /**
        *	Save the transformation ids to the camera ids.
        */
        bool readCameraInstances ( const COLLADAFW::Node* node );

        /**
        *	Save the transformation ids to the light ids.
        */
        bool readLightInstances ( const COLLADAFW::Node* node );

        /**
        *	Save the transformation ids to the controller ids.
        */
        bool readControllerInstances ( const COLLADAFW::Node* node );

        /**
         * Read the shading engines.
         */
        template<COLLADAFW::ClassId classId>
        void readMaterialInstances ( 
            const COLLADAFW::UniqueId& transformId, 
            const COLLADAFW::InstanceBindingBase<classId>* instanceBinding,
            const COLLADAFW::UniqueId* controllerId = 0 );

        /** 
         * Imports the current transformations. 
         */
        bool importTransformations ( 
            const COLLADAFW::Node* node, 
            MayaDM::Transform* transformNode, 
            const COLLADAFW::Node* parentNode = NULL );

        /**
         * Imports a camera lookat transformation.
         * @return Center of interest distance. We need it for creating the camera.
         */
        bool importLookatTransform ( 
            const COLLADAFW::Node* node,
            const COLLADAFW::Transformation* transformation,
            MayaDM::Transform* transformNode );

        /**
         * Returns true, if the transform values from the framework is conform to the maya 
         * transformation and fills the maya transform values.
         */
        bool readMayaTransformations ( 
            const COLLADAFW::Node* node, 
            MayaTransform& mayaTransform, 
            MayaDM::Transform* transformNode, 
            std::vector<TransformAnimation>& transformAnimations,
            bool& hasRotatePivot,
            bool& hasScalePivot,
            bool& isLookatTransform );

        void createTransformAnimation ( 
            const COLLADAFW::UniqueId& transformId, 
            const COLLADAFW::Transformation* transformation, 
            const MayaTransform::TransformPhase& transformPhase,
            const bool isJointTransform,
            std::vector<TransformAnimation>& transformAnimations );

        void handleTranslateValues ( 
            MayaTransform &mayaTransform, 
            const COLLADAFW::Transformation* transformation );

        bool checkPivotValues ( 
            MayaTransform &mayaTransform,
            bool &hasScalePivot, 
            bool &hasRotatePivot );

        bool handleTransformRotateValues ( 
            MayaTransform &mayaTransform, 
            const COLLADAFW::Transformation* transformation );

        bool handleJointRotateValues ( 
            MayaTransform &mayaTransform, 
            const COLLADAFW::Transformation* transformation );

        /**
         * Set the transform values.
         */
        void importDecomposedNodeTransform ( 
            const MayaTransform &mayaTransform, 
            MayaDM::Transform* transformNode, 
            const bool hasRotatePivot,
            const bool hasScalePivot );

        /**
        * Set the transform values.
        */
        void importDecomposedJointTransform ( 
            const MayaTransform &mayaTransform, 
            MayaDM::Joint* jointNode );

        /** 
         * Returns the rotation order of the three vectors. 
         */
        MayaTransform::RotationOrder getRotationOrder ( 
            const COLLADABU::Math::Vector3 axis1, 
            const COLLADABU::Math::Vector3 axis2, 
            const COLLADABU::Math::Vector3 axis3 );

        /**
         * Imports the transform values from a transform matrix.
         * Data loss: no animation possible!
         */
        void importMatrixJointTransform ( 
            const COLLADAFW::Node* node, 
            MayaDM::Transform* transformNode,
            const COLLADAFW::Node* parentNode = NULL );

        /**
        * Imports the transform values from a transform matrix.
        * Data loss: no animation possible!
        */
        void importMatrixNodeTransform ( 
            const COLLADAFW::Node* node, 
            MayaDM::Transform* transformNode );

        /**
        * Imports the transform values from a transform matrix.
        * Data loss: no animation possible!
        */
        bool importMatrixTransform ( 
            const COLLADABU::Math::Matrix4& transformMatrix,
            MayaDM::Transform* transformNode );

        /**
        * Creates a node or joint object.
        */
        MayaDM::Transform* createMayaDMNode ( 
            const COLLADAFW::Node* node, 
            const String& nodeName, 
            const String& parentNodeName );

//         /**
//         * Converts the skew into a matrix.
//         */
//         void skewValuesToMayaMatrix ( const COLLADAFW::Skew* skew, MMatrix& matrix );

    };
}

#endif // __DAE2MA_VISUAL_SCENE_IMPORTER_H__

