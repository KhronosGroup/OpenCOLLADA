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

#ifndef __COLLADA_MAYA_GEOMETRY_IMPORTER_H__
#define __COLLADA_MAYA_GEOMETRY_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"
#include "COLLADAMayaNode.h"

#include "COLLADAFWMesh.h"

#include "COLLADABUIDList.h"
#include "Math/COLLADABUMathVector3.h"

#include "MayaDMTypes.h"
#include "MayaDMMesh.h"
#include "MayaDMGroupId.h"

#include <vector>


namespace COLLADAMaya
{

    /** Declares the importer implementation to import the geometries. */
    class GeometryImporter : public BaseImporter
    {

    private:

        /** The standard name for geometry without name. */
        static const String GEOMETRY_NAME;

        /** The standard name for a maya group. */
        static const String GROUPID_NAME;

    public:

        /**
        * Assign the group to the unique geometry id, the transform node 
        * to the mesh instance and the index of the geometry's primitives.
        */
        class GroupIdAssignment
        {
        private:
            MayaDM::GroupId mGroupId;
            COLLADAFW::UniqueId mGeometryId;
            size_t mGeometryInstanceIndex;
            size_t mPrimitiveIndex;
        public:
            GroupIdAssignment () {}
            GroupIdAssignment ( 
                MayaDM::GroupId& groupId, 
                const COLLADAFW::UniqueId& geometryId, 
                const size_t geometryInstanceIndex,
                const size_t primitiveIndex )
                : mGroupId (groupId)
                , mGeometryId (geometryId)
                , mGeometryInstanceIndex (geometryInstanceIndex)
                , mPrimitiveIndex (primitiveIndex)
            {}
            virtual ~GroupIdAssignment () {}

            const MayaDM::GroupId& getGroupId () const { return mGroupId; }
            void setGroupId ( MayaDM::GroupId& val ) { mGroupId = val; }

            const COLLADAFW::UniqueId& getGeometryId () const { return mGeometryId; }
            void setGeometryId ( const COLLADAFW::UniqueId& val ) { mGeometryId = val; }

            const size_t getGeometryInstanceIndex () const { return mGeometryInstanceIndex; }
            void setGeometryInstanceIndex ( const size_t val ) { mGeometryInstanceIndex = val; }

            const size_t getPrimitiveIndex () const { return mPrimitiveIndex; }
            void setPrimitiveIndex ( const size_t val ) { mPrimitiveIndex = val; }
        };
        typedef std::vector<GroupIdAssignment> GroupIdAssignments;

    private:

        /**
        * The list of the unique maya mesh node names.
        */
        COLLADABU::IDList mMeshNodeIdList;

        /**
        * The list of the unique maya group id names.
        */
        COLLADABU::IDList mGroupIdList;

        /** 
         * The map holds the unique ids of the geometry nodes to the maya specific nodes. 
         */
        UniqueIdMayaNodesMap mMayaMeshNodesMap;

        /** 
        * The map holds the unique ids of the nodes to the  specific nodes. 
        */
        UniqueIdMayaDMMeshMap mMayaDMMeshNodesMap;

        /**
         * The map holds for every geometry's shading engine a list of 
         * the index values of the geometry's primitives.
         */
        CombinedIdIndicesMap mShadingEnginePrimitivesMap;

        /**
         * Assign the group to the unique geometry id, the transform node 
         * to the mesh instance and the index of the geometry's primitives.
         */
        GroupIdAssignments mGroupIdAssignments;

    public:

        /** Constructor. */
        GeometryImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~GeometryImporter () {}

        /** Imports the geometry element. */
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
         * Returns a pointer to the vector of indices of the given geometry and shading engine.
         * The map holds for every geometry's shading engine a list of the index values of the 
         * geometry's primitives.
         */
        std::vector<size_t>* getShadingEnginePrimitiveIndices ( 
            const COLLADAFW::UniqueId& geometryId, 
            const COLLADAFW::MaterialId shadingEngineId );

        /**
        * Assign the group to the unique geometry id, the transform node 
        * to the mesh instance and the index of the geometry's primitives.
        */
        const GroupIdAssignments& getGroupIdAssignments () const { return mGroupIdAssignments; }

    private:

        /** 
        * Imports the data of the current mesh element. 
        */
        void importMesh ( const COLLADAFW::Mesh* mesh );

        /**
        * Writes the geometry of the current mesh.
        */
        void createMesh ( 
            const COLLADAFW::Mesh* mesh, 
            MayaNode* parentMayaNode, 
            size_t numNodeInstances );

        /**
         * Create maya group ids for every mesh primitive (if there is more than one).
         */
        void createGroupNodes ( 
            const COLLADAFW::Mesh* mesh, 
            const size_t geometryInstanceIndex );

        /**
         * Create the object group instances and the object groups and write it into the maya file.
         */
        void writeObjectGroups ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode, 
            size_t numNodeInstances );

        /**
         * Iterates over the mesh primitives and reads the edge indices.
         */
        void getEdgeIndices ( 
            const COLLADAFW::Mesh* mesh, 
            std::vector<COLLADAFW::Edge>& edgeIndices, 
            std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap );

        /*
         *	Write the face informations into the maya file.
         */
        void writeFaces ( 
            const COLLADAFW::Mesh* mesh, 
            const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
            MayaDM::Mesh &meshNode );

        /*
         *	Write the face values of the given primitive element into the maya file.
         */
        void appendPolygonPolyFaces ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
            MayaDM::Mesh &meshNode );

        /*
        *	Write the face values of the given primitive element into the maya file.
        */
        void appendTrifansPolyFaces (
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
            MayaDM::Mesh &meshNode );

        /*
        *	Write the face values of the given primitive element into the maya file.
        */
        void appendTristripsPolyFaces (
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
            MayaDM::Mesh &meshNode );

        /**
         * Set the face infos into the maya poly face element.
         */
        void setPolygonFaceInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
            MayaDM::polyFaces &polyFace, 
            int &numEdges, 
            size_t &positionIndex, 
            std::vector<COLLADABU::Math::Vector3*> &polygonPoints );

        void setPolygonHoleInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
            MayaDM::polyFaces &polyFace, 
            int &numEdges, 
            size_t &positionIndex, 
            std::vector<COLLADABU::Math::Vector3*> & polygonPoints );

        /**
         * Set the uv set infos into the maya poly face element.
         * Increments the initial value for the uv set indices index.
         */
        void setUVSetInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            MayaDM::polyFaces &polyFace, 
            size_t& uvSetIndicesIndex,
            const int numEdges );

        /**
        * Set the color infos into the maya poly face element.
        * Increments the initial value for the color indices index.
        */
        void setColorInfos ( 
            const COLLADAFW::Mesh* mesh, 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            MayaDM::polyFaces &polyFace, 
            size_t& colorIndicesIndex, 
            const int numEdges );

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
         *	Write the edges into the maya file.
         */
        void writeEdges ( 
            const std::vector<COLLADAFW::Edge> &edgeIndices, 
            MayaDM::Mesh &meshNode );

        /*
         *	Write the uv coordinates into the maya file.
         */
        void writeUVSets ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode );

        /*
        *	Write the uv coordinates into the maya file.
        */
        void writeColorSets ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode );

        /*
         *	Write the normals values into the maya file.
         */
        void writeNormals ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode );

        /*
         *	Appends the normal values of all mesh primitive elements into the maya file.
         */
        void appendNormalValues ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode );

        /*
         *	Write the vertex position values into the maya file.
         */
        void writeVertexPositions ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode );

        /*
         * Gets the index value of the current edge. 
         * Returns false, if the search for the index value was not sucessful.
         */
        bool getEdgeIndex ( 
            const COLLADAFW::Edge& edge, 
            const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
            int& edgeIndex );

        /**
        * The map holds for every geometry's shading engine a list of 
        * the index values of the geometry's primitives.
        */
        void setShadingEnginePrimitiveIndex ( 
            const COLLADAFW::UniqueId& geometryId, 
            const COLLADAFW::MaterialId shadingEngineId, 
            const size_t primitiveIndex );

        /**
        * Fills the ShadingEnginePrimitivesMap. Used to create the connections between the 
        * shading engines and the geometries.
        * The map holds for every geometry's shading engine a list of the index values of the 
        * geometry's primitives.
        */
        void setMeshPrimitiveShadingEngines ( const COLLADAFW::Mesh* mesh );

    };

}

#endif // __COLLADA_MAYA_GEOMETRY_IMPORTER_H__