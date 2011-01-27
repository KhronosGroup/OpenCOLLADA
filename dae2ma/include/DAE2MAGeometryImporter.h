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

#ifndef __DAE2MA_GEOMETRY_IMPORTER_H__
#define __DAE2MA_GEOMETRY_IMPORTER_H__

#include "DAE2MAStableHeaders.h"
#include "DAE2MABaseImporter.h"
#include "DAE2MANode.h"
#include "DAE2MAShadingBinding.h"

#include "COLLADAFWMesh.h"
#include "COLLADAFWController.h"

#include "Math/COLLADABUMathVector3.h"

#include "MayaDMTypes.h"
#include "MayaDMMesh.h"
#include "MayaDMGroupId.h"

#include <vector>

#ifdef __GNUC__
#include <ext/hash_map>
#else
#include <hash_map>
#endif


namespace DAE2MA
{

    /** Declares the importer implementation to import the geometries. */
    class GeometryImporter : public BaseImporter
    {

    private:

        /** The standard name for geometry without name. */
        static const String GEOMETRY_NAME;

        /** The list for the edge indices. */
        typedef std::vector<COLLADAFW::Edge> EdgeList;

        /** The map for searching edge indices. */
#ifndef __GNUC__
        typedef stdext::hash_map<COLLADAFW::Edge,size_t> EdgeMap;
#else        
        typedef __gnu_cxx::hash_map<COLLADAFW::Edge,size_t> EdgeMap;
#endif
        
    public:

        /**
        * Assign the group to the unique geometry id, the transform node 
        * to the mesh instance and the index of the geometry's primitives.
        */
        class GroupAssignment
        {
        private:
            MayaDM::GroupId mGroupId;
            COLLADAFW::MaterialId mShadingEngineId;
            size_t mGeometryInstanceIndex;
            size_t mPrimitiveIndex;
        public:
            GroupAssignment () {}
            virtual ~GroupAssignment () {}

            const MayaDM::GroupId& getGroupId () const { return mGroupId; }
            void setGroupId ( MayaDM::GroupId& val ) { mGroupId = val; }

            const COLLADAFW::MaterialId& getShadingEngineId () const { return mShadingEngineId; }
            void setShadingEngineId ( const COLLADAFW::MaterialId& val ) { mShadingEngineId = val; }

            const size_t getGeometryInstanceIndex () const { return mGeometryInstanceIndex; }
            void setGeometryInstanceIndex ( const size_t val ) { mGeometryInstanceIndex = val; }

            const size_t getPrimitiveIndex () const { return mPrimitiveIndex; }
            void setPrimitiveIndex ( const size_t val ) { mPrimitiveIndex = val; }
        };

        /** 
         * Store the information of the controller id, the geometryId and the transformId in the 
         * combination of the original mesh node object and the controller mesh object.
         */
        class MeshControllerData 
        {
        private:
            COLLADAFW::Controller::ControllerType mControllerType;
            COLLADAFW::UniqueId mControllerId;

            COLLADAFW::UniqueId mGeometryId;
            COLLADAFW::UniqueId mTransformId;

            /** 
             * True, if the current controller is the initial instance of the controller object. 
             * False, if it is just an instance of the original initial object. 
             */
            bool mIsInitialInstance;

            /** 
             * The original mesh node is needed to hold the real data (vertices, edges and faces).
             * It's worldMesh will be connected with the inputGeometry of the skinCluster's or the
             * blendShape's tweak groupParts.
             */
            MayaDM::Mesh mOriginalMeshNode;

            /**
             * The controller mesh node is used to make all the other connections between the 
             * skinCluster of blendShape object and the geometry.
             */
            MayaDM::Mesh mControllerMeshNode;

        public:
            MeshControllerData ( 
                const COLLADAFW::Controller::ControllerType& controllerType, 
                const COLLADAFW::UniqueId& controllerId ) 
                : mControllerType ( controllerType )
                , mControllerId ( controllerId )
                , mIsInitialInstance ( true )
            {}
            virtual ~MeshControllerData () {}

            const COLLADAFW::Controller::ControllerType& getControllerType () const { return mControllerType; }

            const COLLADAFW::UniqueId& getControllerId () const { return mControllerId; }

            const COLLADAFW::UniqueId& getGeometryId () const { return mGeometryId; }
            void setGeometryId ( const COLLADAFW::UniqueId& val ) { mGeometryId = val; }

            const COLLADAFW::UniqueId& getTransformId () const { return mTransformId; }
            void setTransformId ( const COLLADAFW::UniqueId& val ) { mTransformId = val; }

            /** Make a copy of the original mesh node and set it. */
            void setOriginalMeshNode ( const MayaDM::Mesh val ) { mOriginalMeshNode = val; }
            MayaDM::Mesh& getOriginalMeshNode () { return mOriginalMeshNode; }
            const MayaDM::Mesh& getOriginalMeshNode () const { return mOriginalMeshNode; }

            /** Make a copy of the controller mesh node and set it. */
            void setControllerMeshNode ( const MayaDM::Mesh val ) { mControllerMeshNode = val; }
            MayaDM::Mesh& getControllerMeshNode () { return mControllerMeshNode; }
            const MayaDM::Mesh& getControllerMeshNode () const { return mControllerMeshNode; }

            /** True, if the current controller is just an instance of the original controller object. */
            const bool& getIsInitialInstance () const { return mIsInitialInstance; }
            void setIsInitialInstance ( const bool& val ) { mIsInitialInstance = val; }
        };

        /**
         * Used to store a geometry id with the primitive index element.
         */
        typedef std::pair<COLLADAFW::UniqueId, size_t> GeometryPrimitivePair;

        /**
         * Used to store the shading engine id for every primitive element of a geometry.
         */
        struct GeometryShadingEngine
        {
            size_t mPrimitiveIndex;
            COLLADAFW::MaterialId mShadingEngineId;
        };

        /**
        * Used to store informations about multiple input sets of an primitive element in an
        * TEXCOORD or COLOR input element. 
        */
        struct PrimitiveInputSet
        {
        private:
            COLLADAFW::UniqueId mGeometryId;
            COLLADAFW::MaterialId mShadingEngineId;
            String inputSetName;
            size_t mPhysicalIndex;
            size_t mInputSetIndex;

        public:
            PrimitiveInputSet () {}
            virtual ~PrimitiveInputSet () {}

            const COLLADAFW::UniqueId& getGeometryId () const { return mGeometryId; }
            void setGeometryId ( const COLLADAFW::UniqueId& val ) { mGeometryId = val; }

            const COLLADAFW::MaterialId& getShadingEngineId () const { return mShadingEngineId; }
            void setShadingEngineId ( const COLLADAFW::MaterialId& val ) { mShadingEngineId = val; }

            const String& getInputSetName () const { return inputSetName; }
            void setInputSetName ( const String& val ) { inputSetName = val; }

            const size_t getPhysicalIndex () const { return mPhysicalIndex; }
            void setPhysicalIndex ( const size_t val ) { mPhysicalIndex = val; }

            const size_t& getInputSetIndex () const { return mInputSetIndex; }
            void setInputSetIndex ( const size_t& val ) { mInputSetIndex = val; }
        };

    private:

        /**
         * Store the uv-sets in a list to know the indices for the uv-choosers 
         * (to organize multiple texture coordinate binding).
         */ 
        std::map<COLLADAFW::UniqueId, std::vector<String> > mGeometryUvSetNamesMap;

        /**
        * The map holds for every geometry a list of multiple texcoord input elements 
        * with the input set indices for every primitive element.
        */
        std::map<COLLADAFW::UniqueId, std::vector<PrimitiveInputSet> > mTexCoordInputSetsMap;

        /**
        * The map holds for every geometry a list of multiple color input elements 
        * with the input set indices for every primitive element.
        */
        std::map<COLLADAFW::UniqueId, std::vector<PrimitiveInputSet> > mColorInputSetsMap;

        /** 
         * The map holds the unique ids of the geometry nodes to the maya specific nodes. 
         */
        UniqueIdMayaNodeMap mMayaMeshNodesMap;

        /** 
        * The map holds the unique ids of the geometry nodes to the maya controller mesh nodes. 
        */
        UniqueIdMayaDMMeshMap mMayaDMControllerMeshNodesMap;

        /** 
        * The map holds the unique ids of the geometry nodes to the specific nodes. 
        */
        UniqueIdMayaDMMeshMap mMayaDMMeshNodesMap;

        /** 
         * The map holds the number of primitive elements to the geometry id.
         */
        UniqueIdSizeTMap mGeometryIdPrimitivesCountMap;

        /**
         * Assign the group to the unique geometry id, the transform node 
         * to the mesh instance and the shading engine.
         */
        ShadingBindingGroupInfoMap mShadingBindingGroupMap;

        /**
         * The map holds the list of components of a mesh. Needed for the groupParts of a mesh's 
         * material, if the mesh element has a controller element (then the groups has to be 
         * organised in groupParts).
         */
        std::map<COLLADAFW::UniqueId, std::vector<MayaDM::componentList> > mMeshComponentLists;

        /** 
        * Store the information of the controller id, the geometryId and the transformId in the 
        * combination of the original mesh node object and the controller mesh object.
        * There can be multiple objects per any uniqueId, but there can be only one object per 
        * combination of controllerId and transformId.
        */
        std::vector<MeshControllerData> mMeshControllerDataList;

        /**
         * Stores for the geometry for every primitive element the shading engine id.
         */
        std::map<COLLADAFW::UniqueId, std::vector<GeometryShadingEngine> > mGeometryShadingEnginesMap;

    public:

        /** Constructor. */
        GeometryImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~GeometryImporter ();

        /** 
        * Imports the geometry element. 
        */
        void importGeometry ( const COLLADAFW::Geometry* geometry );

        /** 
        * The map holds the unique ids of the nodes to the maya specific nodes. 
        */
        const MayaNode* findMayaMeshNode ( const COLLADAFW::UniqueId& uniqueId ) const;

        /** 
        * The map holds the unique ids of the nodes to the maya specific nodes. 
        */
        MayaNode* findMayaMeshNode ( const COLLADAFW::UniqueId& uniqueId );

        /** 
        * The map holds the unique ids of the nodes to the  specific nodes. 
        */
        MayaDM::Mesh* findMayaDMMeshNode ( const COLLADAFW::UniqueId& uniqueId );

        /** 
        * The map holds the unique ids of the nodes to the  specific nodes. 
        */
        const MayaDM::Mesh* findMayaDMMeshNode ( const COLLADAFW::UniqueId& uniqueId ) const;

        /** 
        * The map holds the unique ids of the nodes to the  specific nodes. 
        */
        MayaDM::Mesh* findMayaDMControllerMeshNode ( const COLLADAFW::UniqueId& uniqueId );

        /** 
        * The map holds the unique ids of the nodes to the  specific nodes. 
        */
        const MayaDM::Mesh* findMayaDMControllerMeshNode ( const COLLADAFW::UniqueId& uniqueId ) const;

        /** 
        * The map holds the number of primitive elements to the geometry id.
        */
        const size_t findPrimitivesCount ( const COLLADAFW::UniqueId& geometryId );

        /**
         * Returns a pointer to the vector of indices of the given geometry and shading engine.
         * The map holds for every geometry's shading engine a list of the index values of the 
         * geometry's primitives.
         */
        const std::vector<GeometryImporter::GeometryShadingEngine>* findGeomtryShadingEngines ( 
            const COLLADAFW::UniqueId& geometryId );

        /**
        * Assign the group to the unique geometry id, the transform node 
        * to the mesh instance and the index of the geometry's primitives.
        */
        const ShadingBindingGroupInfoMap& getShadingBindingGroupMap () const { return mShadingBindingGroupMap; }

        /**
        * Get the groupId assignement data for the current geometry under the transform.
        */
        std::vector<GroupInfo>* findShadingBindingGroups ( 
            const COLLADAFW::UniqueId& geometryId, 
            const COLLADAFW::UniqueId& transformId, 
            const COLLADAFW::MaterialId& shadingEngineId );

        /**
        * The map holds the list of components of a mesh. Needed for the groupParts of a mesh's 
        * material, if the mesh element has a controller element (then the groups has to be 
        * organised in groupParts).
        */
        const std::vector<MayaDM::componentList>* findComponentLists ( const COLLADAFW::UniqueId& geometryId );

        /** 
        * Store the information of the controller id, the geometryId and the transformId in the 
        * combination of the original mesh node object and the controller mesh object.
        */
        MeshControllerData* findMeshControllerDataByControllerAndTransformId ( 
            const COLLADAFW::UniqueId& controllerId, 
            const COLLADAFW::UniqueId& transformId );

        /** 
        * Store the information of the controller id, the geometryId and the transformId in the 
        * combination of the original mesh node object and the controller mesh object.
        */
        MeshControllerData* findMeshControllerDataByControllerId ( 
            const COLLADAFW::UniqueId& controllerId );

        /**
        * Returns a pointer to the geometry id, if it exist. This is either the source id or the 
        * the geometry id, which is connected over the controller.
        */
        const COLLADAFW::UniqueId* findGeometryId ( 
            const COLLADAFW::UniqueId& sourceId, 
            const COLLADAFW::UniqueId& transformId, 
            const COLLADAFW::UniqueId* controllerId );

        /**
        * The map holds for every geometry a list of multiple texcoord input elements 
        * with the input set indices.
        */
        const std::vector<PrimitiveInputSet>* findTexCoordInputSets ( 
            const COLLADAFW::UniqueId& geometryId );

        /**
        * The map holds for every geometry a list of multiple color input elements 
        * with the input set indices.
        */
        const std::vector<PrimitiveInputSet>* findColorInputSets ( 
            const COLLADAFW::UniqueId& geometryId );

        /**
        * Returns the index position of the uv set with the searched name.
        */
        const size_t findGeometryUvSetIndex ( 
            const COLLADAFW::UniqueId& geometryId, 
            const String& uvSetName );

        /**
         * Writes the connection attributes into the maya ascii file. 
         * If there exist a controller for the current mesh, we also need to organize the groupIds 
         * of the mesh's primitive elements in groupParts (make the connections for this). 
         */
        void writeConnections ();

        void connectControllerGroups ();

    private:

        /** 
        * Imports the data of the current mesh element. 
        */
        bool importMesh ( COLLADAFW::Mesh* mesh );

        /**
         * Make the mesh instances and import the mesh data.
         */
        bool importMesh ( 
            COLLADAFW::Mesh* mesh, 
            const UniqueIdVec* transformNodeIds,
            MeshControllerData* meshControllerData = 0, 
            const bool meshAlreadyImported = false,
            const bool intermediateObject = false,
            const bool visible = true );

        /** 
        * Imports the data of the current mesh element. 
        */
        void importController ( 
            COLLADAFW::Mesh* mesh, 
            bool meshAlreadyImported );

        void importMorphTargetGeometry ( 
            COLLADAFW::Mesh* mesh, 
            bool &meshAlreadyImported );

        /**
         * Imports the geometries of the elements, which are referenced from a controller object.
         */
        void importControllerGeometry ( 
            COLLADAFW::Mesh* mesh, 
            bool &meshAlreadyImported );

        /**
        * Import the geometry for any controllers, which use the geometry directly.
        */
        bool importSkinOrMorphControlledGeometry ( 
            COLLADAFW::Mesh* mesh, 
            const COLLADAFW::Controller* controller, 
            const bool meshImported, 
            const bool hasGeometryInstance );

        /**
         * Import the geometry for skin controllers, which use a morph controller, which use the geometry.
         */
        bool importSkinAndMorphControlledGeometry ( 
            COLLADAFW::Mesh* mesh,
            const COLLADAFW::MorphController* morphController, 
            const bool meshImported, 
            const bool hasGeometryInstance );

        /**
        * Writes the geometry of the current mesh.
        */
        bool createMesh ( 
            COLLADAFW::Mesh* mesh, 
            MayaNode* parentMayaNode, 
            MeshControllerData* meshControllerData = 0, 
            const bool meshAlreadyImported = false,
            const bool intermediateObject = false,
            const bool visible = true );

//         /**
//          * Combine the extra data of the mesh (contains extra data of the mesh and the vertices)
//          * and the extra data of the mesh's primitive elements.
//          */
//         COLLADAFW::ExtraDataArray& getAllExtraData ( COLLADAFW::Mesh* mesh );

        /**
         * Create maya group ids for every mesh primitive (if there is more than one).
         */
        void createGroupNodes ( 
            const COLLADAFW::Mesh* mesh,
            size_t& geometryInstanceIndex, 
            const COLLADAFW::UniqueId& transformId, 
            const size_t numNodeInstances, 
            const COLLADAFW::UniqueId& controllerId = COLLADAFW::UniqueId () );

        /**
         * Create the object group instances and the object groups and write it into the maya file.
         */
        void writeObjectGroups ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode, 
            const COLLADAFW::UniqueId& transformNodeId );

        /**
         * Iterates over the mesh primitives and reads the edge indices.
         */
        void getEdgeIndices ( 
            const COLLADAFW::Mesh* mesh, 
            EdgeList& edgeIndices, 
            EdgeMap& edgeIndicesMap );

        /*
         *	Write the face informations into the maya file.
         */
        void writeFaces ( 
            const COLLADAFW::Mesh* mesh, 
            EdgeMap& edgeIndicesMap, 
            MayaDM::Mesh &meshNode );

        /*
         *	Write the face values of the given primitive element into the maya file.
         */
        void appendPolygonPolyFaces ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            EdgeMap& edgeIndicesMap, 
            MayaDM::Mesh &meshNode,
            const size_t blockSize, 
            const size_t numGlobalFaces, 
            size_t& globalFaceIndex, 
            size_t& endPosition );

        /*
        *	Write the face values of the given primitive element into the maya file.
        */
        void appendTrifansPolyFaces (
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const EdgeMap& edgeIndicesMap, 
            MayaDM::Mesh &meshNode,
            const size_t blockSize, 
            const size_t numGlobalFaces, 
            size_t& globalFaceIndex, 
            size_t& endPosition );

        /*
        * Write the face values of the given primitive element into the maya file.
        */
        void appendTristripsPolyFaces (
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const EdgeMap& edgeIndicesMap, 
            MayaDM::Mesh &meshNode,
            const size_t blockSize, 
            const size_t numGlobalFaces, 
            size_t& globalFaceIndex, 
            size_t& endPosition );

        /**
         * Set the face infos into the maya poly face element.
         */
        void setPolygonFaceInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const EdgeMap& edgeIndicesMap, 
            MayaDM::polyFaces &polyFace, 
            int &numEdges, 
            size_t &positionIndex, 
            std::vector<COLLADABU::Math::Vector3*> &polygonPoints );

        void setPolygonHoleInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const EdgeMap& edgeIndicesMap, 
            MayaDM::polyFaces &polyFace, 
            int &numEdges, 
            size_t &positionIndex, 
            std::vector<COLLADABU::Math::Vector3*>& polygonPoints );

        /**
         * Set the uv set infos into the maya poly face element.
         * Increments the initial value for the uv set indices index.
         */
        void setPolygonUVSetInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            MayaDM::polyFaces &polyFace, 
            size_t& uvSetIndicesIndex,
            const int numEdges );

        /**
        * Set the color infos into the maya poly face element.
        * Increments the initial value for the color indices index.
        */
        void setPolygonColorInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            MayaDM::polyFaces &polyFace, 
            size_t& colorIndicesIndex, 
            const int numEdges );

        /**
        * Set the uv set infos into the maya poly face element.
        * Increments the initial value for the uv set indices index.
        */
        void setTristripsUVSetInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            MayaDM::polyFaces &polyFace, 
            const size_t uvSetIndicesIndex,
            const bool changeDirection );

        /**
        * Set the color infos into the maya poly face element.
        * Increments the initial value for the color indices index.
        */
        void setTristripsColorInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            MayaDM::polyFaces &polyFace, 
            const size_t colorIndicesIndex, 
            const bool changeDirection );

        /**
        * Set the uv set infos into the maya poly face element.
        * Increments the initial value for the uv set indices index.
        */
        void setTrifansUVSetInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            MayaDM::polyFaces &polyFace, 
            const size_t initialUVSetIndicesIndex,
            const size_t uvSetIndicesIndex );

        /**
        * Set the color infos into the maya poly face element.
        * Increments the initial value for the color indices index.
        */
        void setTrifansColorInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            MayaDM::polyFaces &polyFace, 
            const size_t initialColorIndicesIndex,
            const size_t colorIndicesIndex );

        /*
         *	Changes the orientation of a polyFace hole element.
         */
        void changePolyFaceHoleOrientation( MayaDM::polyFaces &polyFace );

        /*
         *	Returns true, if we have to change the orientation of the current hole.
         */
        bool changeHoleOrientation ( 
            std::vector<COLLADABU::Math::Vector3*>& polygonPoints, 
            std::vector<COLLADABU::Math::Vector3*>& holePoints );

        /*
         * Returns a class which stores the x, y and z values of the vertex point 
         * at the given index position.
         */
        COLLADABU::Math::Vector3* getVertexPosition ( 
            const COLLADAFW::Mesh* mesh, const size_t vertexIndex );

        /*
        * Determine the edge indices (unique edges, also for multiple primitive elements)
        * and write it into the lists (the indices referes on the position indices).
        * Does it for triangle elements, polygons or polylist. Trifans and tristrips are a little 
        * bit special.
        * @param edgeIndices 
        *           A vector of edge indices. We use it to write the list of edges into the maya 
        *           file. The vector is already sorted.
        * @param edgeIndicesMap 
        *           We store the edge indices also in a sorted map. The dublicate data holding 
        *           is reasonable, because we need the index of a given edge. The search of  
        *           values in a map is much faster than in a vector!
        */
        void appendEdgeIndices ( 
            const COLLADAFW::MeshPrimitive* primitiveElement,
            EdgeList& edgeIndices,
            EdgeMap& edgeIndicesMap );

        /*
        * Determine the edge indices (unique edges, also for multiple primitive elements)
        * and write it into the lists (the indices referes on the position indices).
        * Does it for triangle elements, polygons or polylist. 
        * @param edgeIndices 
        *           A vector of edge indices. We use it to write the list of edges into the maya 
        *           file. The vector is already sorted.
        * @param edgeIndicesMap 
        *           We store the edge indices also in a sorted map. The dublicate data holding 
        *           is reasonable, because we need the index of a given edge. The search of  
        *           values in a map is much faster than in a vector!
        */
        void appendPolygonEdgeIndices ( 
            const COLLADAFW::MeshPrimitive* primitiveElement,
            EdgeList& edgeIndices,
            EdgeMap& edgeIndicesMap );

        /*
        * Determine the edge indices (unique edges, also for multiple primitive elements)
        * and write it into the lists (the indices referes on the position indices).
        * Does it for trifans.
        * @param edgeIndices 
        *           A vector of edge indices. We use it to write the list of edges into the maya 
        *           file. The vector is already sorted.
        * @param edgeIndicesMap 
        *           We store the edge indices also in a sorted map. The dublicate data holding 
        *           is reasonable, because we need the index of a given edge. The search of  
        *           values in a map is much faster than in a vector!
        */
        void appendTrifansEdgeIndices (
            const COLLADAFW::MeshPrimitive* primitiveElement,
            EdgeList& edgeIndices,
            EdgeMap& edgeIndicesMap );

        /*
        * Determine the edge indices (unique edges, also for multiple primitive elements)
        * and write it into the lists (the indices referes on the position indices).
        * Does it for tristrips.
        * @param edgeIndices 
        *           A vector of edge indices. We use it to write the list of edges into the maya 
        *           file. The vector is already sorted.
        * @param edgeIndicesMap 
        *           We store the edge indices also in a sorted map. The dublicate data holding 
        *           is reasonable, because we need the index of a given edge. The search of  
        *           values in a map is much faster than in a vector!
        */
        void appendTristripsEdgeIndices (
            const COLLADAFW::MeshPrimitive* primitiveElement,
            EdgeList& edgeIndices,
            EdgeMap& edgeIndicesMap );

        /*
        * Appends the data of an edge, if it is not already in the list.
        */
        void appendEdge( 
            const COLLADAFW::Edge& edge, 
            EdgeList& edgeIndices,
            EdgeMap& edgeIndicesMap );

        /*
         *	Write the edges into the maya file.
         */
        void writeEdges ( 
            const COLLADAFW::Mesh* mesh, 
            const EdgeList& edgeIndices, 
            MayaDM::Mesh &meshNode );

        /*
         * Write the uv coordinates into the maya file.
         */
        void writeUVSets ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode, 
            const bool originalMesh = true );

        /*
        *	Write the uv coordinates into the maya file.
        */
        void writeColorSets ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode,
            const bool originalMesh = true );

        /*
         *	Write the normals values into the maya file.
         */
        void writeFaceVertexNormals ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode );

        void setFaceVertexNormal ( 
            MayaDM::Mesh &meshNode, 
            const COLLADAFW::MeshPrimitive* meshPrimitive, 
            const COLLADAFW::MeshVertexData &normals, 
            const size_t primitiveVertexIndex, 
            const size_t globalFaceIndex );

        /*
         *	Write the vertex position values into the maya file.
         */
        void writeVertexPositions ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode );

        /*
         * Gets the index value of the current edge. 
         * Returns false, if the search for the index value of the edge was not sucessful.
         */
        bool getEdgeIndex ( 
            const COLLADAFW::Edge& edge, 
            const EdgeMap& edgeIndicesMap, 
            int& edgeIndex );

        /**
        * Fills the ShadingEnginePrimitivesMap. Used to create the connections between the 
        * shading engines and the geometries.
        * The map holds for every geometry's shading engine a list of the index values of the 
        * geometry's primitives.
        */
        void setMeshPrimitiveShadingEngines ( const COLLADAFW::Mesh* mesh );
        

        /**
         * Write the normal values into the maya file.
         * @param mesh
         * @param meshNode
         * @return void
         */
        void writeNormals ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode );
    };

}

#endif // __DAE2MA_GEOMETRY_IMPORTER_H__
