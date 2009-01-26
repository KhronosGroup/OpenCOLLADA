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

#include "MayaDMTransform.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWSkew.h"

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
    public:
        
        typedef std::map<const COLLADAFW::UniqueId, std::set<const COLLADAFW::UniqueId>> UniqueIdUniqueIdsMap;

        typedef std::map<const COLLADAFW::UniqueId, String> UniqueIdNamesMap;

    private:

        /*
         * The map holds for every unique id of a geometry a list of transform node unique ids.
         * We need it for the creation of the geometry, to set the parent transform nodes.
         */
        UniqueIdUniqueIdsMap mGeometryNodesMap;

        /** The map holds the unique ids of the nodes to the names. */
        UniqueIdNamesMap mNodeNamesMap;

        /*
         *	Helper class, to handle the transformations.
         */
        class MayaTransformation
        {
        public:
            MayaTransformation () 
                : phase (0)
                , translate1 ( 0,0,0 ) 
                , translate2 ( 0,0,0 ) 
                , translate3 ( 0,0,0 ) 
                , scale ( 1,1,1 ) 
            {}
            virtual ~MayaTransformation () {}

            static const size_t PHASE_TRANS1 = 1;
            static const size_t PHASE_ROTATE = 2;
            static const size_t PHASE_TRANS2 = 3;
            static const size_t PHASE_SCALE = 4;
            static const size_t PHASE_TRANS3 = 5;

            MVector translate1; // = 0,0,0
            MQuaternion rotation; // = 1,0,0,0
            MVector translate2; // = 0,0,0
            MVector scale; // = 1,1,1
            MVector translate3; // = 0,0,0
            MVector skew;

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

        /*
         * Imports the data of the current node.
         */
        void importNode ( 
            const COLLADAFW::Node* rootNode, 
            const COLLADAFW::UniqueId* parentNodeId = 0 );

        /*
        * The map holdes for every geometry (identified by it's unique id ) a list of all 
        * transform nodes (identified by their names, which are unique!).
        * We need it for the creation of the geometry, to set the parent transform nodes.
        */
        const UniqueIdUniqueIdsMap& getGeometryNodesMap () const { return mGeometryNodesMap; }

        /**
         * The map with the node unique ids and the names for it.
         */
        const UniqueIdNamesMap& getNodeNamesMap () const { return mNodeNamesMap; }

    private:

        /*
        * The map holdes for every unique id of a geometry a list of transform node unique ids.
        * We need it for the creation of the geometry, to set the parent transform nodes.
        */
        UniqueIdUniqueIdsMap& getGeometryNodesMap() { return mGeometryNodesMap; }

        /**
         *	Save the transformation ids to the geometry ids.
         */
        bool readGeometryInstances (
            const COLLADAFW::Node* node, 
            MayaDM::Transform* transformNode );

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
            MayaTransformation& mayaTransform );

        /**
         * Set the transform values.
         */
        void importDecomposedTransform ( 
            const MayaTransformation &mayaTransform, 
            MayaDM::Transform* transformNode );

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
            const COLLADAFW::UniqueId* parentNodeId );

        /**
        * Converts the skew into a matrix.
        */
        void skewValuesToMayaMatrix ( const COLLADAFW::Skew* skew, MMatrix& matrix ) const;

    };
}

#endif // __COLLADA_MAYA_VISUAL_SCENE_IMPORTER_H__