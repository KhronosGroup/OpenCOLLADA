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

#include <vector>


namespace COLLADAMaya
{

    /** Declares the importer implementation to import the geometries. */
    class GeometryImporter : public BaseImporter
    {

    private:

        /**
        * The list of the unique maya mesh node names.
        */
        COLLADABU::IDList mMeshNodeIdList;

        /** 
         * The map holds the unique ids of the nodes to the maya specific nodes. 
         */
        UniqueIdMayaNodesMap mMayaMeshNodesMap;

    public:

        /** Constructor. */
        GeometryImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~GeometryImporter () {}

        /** Imports the geometry element. */
        bool importGeometry ( const COLLADAFW::Geometry* geometry );

    private:

        /** 
        * The map holds the unique ids of the nodes to the maya specific nodes. 
        */
        const MayaNode* getMayaMeshNode ( const COLLADAFW::UniqueId& uniqueId ) const;

        /** 
        * The map holds the unique ids of the nodes to the maya specific nodes. 
        */
        MayaNode* getMayaMeshNode ( const COLLADAFW::UniqueId& uniqueId );

        /** 
         * Imports the data of the current mesh element. 
         */
        void importMesh ( const COLLADAFW::Mesh* mesh );

        /**
         * Writes the geometry of the current mesh.
         */
        void createMesh ( 
            const COLLADAFW::Mesh* mesh, 
            MayaNode* parentMayaNode );

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
    };

}

#endif // __COLLADA_MAYA_GEOMETRY_IMPORTER_H__