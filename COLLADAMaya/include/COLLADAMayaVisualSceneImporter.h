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
                , translate1 (3, 0) 
                , translate2 (3, 0) 
                , translate3 (3, 0) 
                , scale (3, 1) 
            {}
            virtual ~MayaTransformation () {}

            static const size_t PHASE_TRANS1 = 1;
            static const size_t PHASE_ROTATE = 2;
            static const size_t PHASE_TRANS2 = 3;
            static const size_t PHASE_SCALE = 4;
            static const size_t PHASE_TRANS3 = 5;

            std::vector<double> translate1; // = 0,0,0
            MQuaternion rotation; // = 1,0,0,0
            std::vector<double> translate2; // = 0,0,0
            std::vector<double> scale; // = 1,1,1
            std::vector<double> translate3; // = 0,0,0

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

        /*
         *	Save the transformation ids to the geometry ids.
         */
        bool readGeometryInstances (
            MayaDM::Transform* transformNode, 
            const COLLADAFW::Node* node );

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
            MayaDM::Transform* transformNode, 
            const COLLADAFW::Node* rootNode );

    };
}

#endif // __COLLADA_MAYA_VISUAL_SCENE_IMPORTER_H__