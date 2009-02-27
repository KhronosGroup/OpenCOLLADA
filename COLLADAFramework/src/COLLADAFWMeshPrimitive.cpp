/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWMeshPrimitive.h"
#include "COLLADAFWPolygons.h"
#include "COLLADAFWMeshPrimitiveWithFaceVertexCount.h"
#include "COLLADAFWTrifans.h"
#include "COLLADAFWTristrips.h"


namespace COLLADAFW
{



    //-----------------------------
	MeshPrimitive::MeshPrimitive()
		: mPrimitiveType ( UNDEFINED_PRIMITIVE_TYPE )
	    , mFaceCount ( 0 )
		, mMaterialId(0)
		, mPositionIndices(UIntValuesArray::OWNER)
		, mNormalIndices(UIntValuesArray::OWNER)
		, mColorIndicesArray(UIntValuesArray::OWNER)
		, mUVCoordIndicesArray(UIntValuesArray::OWNER)
	{
	}

    //-----------------------------
	MeshPrimitive::MeshPrimitive( PrimitiveType primitiveType )
		: mPrimitiveType ( primitiveType )
		, mFaceCount ( 0 )
		, mMaterialId(0)
		, mPositionIndices(UIntValuesArray::OWNER)
		, mNormalIndices(UIntValuesArray::OWNER)
		, mColorIndicesArray(UIntValuesArray::OWNER)
		, mUVCoordIndicesArray(UIntValuesArray::OWNER)
	{
	}

    //-----------------------------
    const int MeshPrimitive::getGroupedVerticesVertexCount( const size_t faceIndex ) const
    {
        switch ( mPrimitiveType )
        {
        case TRIANGLES:
            return 3;
            break;
        case TRIANGLE_FANS:
            return ((Trifans*)this)->getGroupedVerticesVertexCount ( faceIndex );
            break;
        case TRIANGLE_STRIPS:
            return ((Tristrips*)this)->getGroupedVerticesVertexCount ( faceIndex );
            break;
        case POINTS:
            return 1;
            break;
        case LINES:
        case LINE_STRIPS:
            return 2;
            break;
        case POLYGONS:
        case POLYLIST:
            return ((Polygons*)this)->getGroupedVerticesVertexCount ( faceIndex );
            break;
        default:
            std::cerr << "Unknown primitive type: " << mPrimitiveType << std::endl;
            return 0;
        }
    }

    //-----------------------------
    void MeshPrimitive::appendEdgeIndices (
        std::vector<Edge>& edgeIndices,
        std::map<Edge,size_t>& edgeIndicesMap )
    {
        COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = this->getPrimitiveType ();
        switch ( primitiveType )
        {
        case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
            appendTrifansEdgeIndices ( edgeIndices, edgeIndicesMap );
            break;
        case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
            appendTristripsEdgeIndices ( edgeIndices, edgeIndicesMap );
            break;
        case COLLADAFW::MeshPrimitive::POLYGONS:
        case COLLADAFW::MeshPrimitive::POLYLIST:
        case COLLADAFW::MeshPrimitive::TRIANGLES:
            appendPolygonEdgeIndices(edgeIndices, edgeIndicesMap);
            break;
        default:
            std::cerr << "Primitive type not implemented!" << std::endl;
            assert ( "Primitive type not implemented!");
        }
    }

    //-----------------------------
    void MeshPrimitive::appendPolygonEdgeIndices (
        std::vector<Edge>& edgeIndices,
        std::map<Edge,size_t>& edgeIndicesMap )
    {
        // Get the number of grouped vertex elements (faces, holes, tristrips or trifans).
        int groupedVertexElementsCount = getGroupedVertexElementsCount ();

        // Make the count positive, if we have a hole.
        if ( groupedVertexElementsCount < 0 ) groupedVertexElementsCount *= -1;

        // Get the position indices.
        const COLLADAFW::UIntValuesArray& positionIndices = getPositionIndices ();

        // The points of an edge
        int edgeStartVertexIndex=0, edgeEndVertexIndex=0;

        // The current index in the positions list.
        size_t positionIndex=0;

        // Iterate over the faces and get the edges.
        for ( int faceIndex=0; faceIndex<groupedVertexElementsCount; ++faceIndex )
        {
            // The number of edges is always the same
            // than the number of vertices in the current face.
            int numEdges = getGroupedVerticesVertexCount ( (size_t)faceIndex );

            // Reverse for holes.
            if ( numEdges < 0 ) numEdges *= -1;

            // Go through the edges of the current face and determine the edge values.
            for ( int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
            {
                // Set the edge vertex index values into an edge object.
                edgeStartVertexIndex = positionIndices[positionIndex];

                if ( edgeIndex<(numEdges-1) )
                    edgeEndVertexIndex = positionIndices[++positionIndex];
                else
                    edgeEndVertexIndex = positionIndices[positionIndex-numEdges+1];

                Edge edge ( edgeStartVertexIndex, edgeEndVertexIndex );

                // Appends the data of an edge to the edgeIndices list,
                // if it is not already in the list.
                appendEdge ( edge, edgeIndices, edgeIndicesMap );
            }

            // Increment the positions index for the next face, if it is a triangle or polygon.
            // A trifan has the first edge of the next face always at the position of the last edge.
            ++positionIndex;
        }
    }

    //-----------------------------
    void MeshPrimitive::appendTrifansEdgeIndices (
        std::vector<Edge>& edgeIndices,
        std::map<Edge,size_t>& edgeIndicesMap )
    {
        // Get the position indices.
        const COLLADAFW::UIntValuesArray& positionIndices = getPositionIndices ();

        // The points of an edge
        int edgeStartVtxIndex=0, edgeEndVtxIndex=0;

        // The current index in the positions list.
        size_t initialPositionIndex=0;
        size_t positionIndex=0;

        // Iterate over the grouped vertices and get the edges for every group.
        COLLADAFW::Trifans* trifans = (COLLADAFW::Trifans*) this;
        COLLADAFW::Trifans::VertexCountArray& vertexCountArray =
            trifans->getGroupedVerticesVertexCountArray ();
        size_t groupedVertexElementsCount = vertexCountArray.getCount ();
        for ( size_t groupedVerticesIndex=0; groupedVerticesIndex<groupedVertexElementsCount; ++groupedVerticesIndex )
        {
            // A trifan has always triangles, which have 3 edges
            size_t triangleEdgeCounter = 0;

            // The number of vertices in the current vertex group.
            unsigned int vertexCount = vertexCountArray [groupedVerticesIndex];

            // Determine the number of edges and iterate over it.
            unsigned int numEdges = ( vertexCount - 3 ) * 3 + 3;
            for ( unsigned int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
            {
                // Increment the current triangle edge counter, so we know if we have the full triangle.
                ++triangleEdgeCounter;

                // Get the start edge index
                if ( triangleEdgeCounter > 1 )
                    edgeStartVtxIndex = positionIndices[positionIndex];
                else edgeStartVtxIndex = positionIndices[initialPositionIndex];

                // With the third edge of a triangle, we have to go back to the trifans root.
                if ( triangleEdgeCounter < 3 )
                    edgeEndVtxIndex = positionIndices[++positionIndex];
                else edgeEndVtxIndex = positionIndices[initialPositionIndex];

                Edge edge ( edgeStartVtxIndex, edgeEndVtxIndex );

                // Appends the data of an edge to the edgeIndices list,
                // if it is not already in the list.
                appendEdge ( edge, edgeIndices, edgeIndicesMap );

                // Reset the edge counter, if we have all three edges of a triangle.
                if ( triangleEdgeCounter == 3 )
                {
                    triangleEdgeCounter = 0;
                    --positionIndex;
                }
            }

            // Increment the initial trifan position index for the next trifan object.
            initialPositionIndex += vertexCount;
            positionIndex += 2;
        }
    }

    //-----------------------------
    void MeshPrimitive::appendTristripsEdgeIndices (
        std::vector<Edge>& edgeIndices,
        std::map<Edge,size_t>& edgeIndicesMap )
    {
        // Get the position indices.
        const COLLADAFW::UIntValuesArray& positionIndices = getPositionIndices ();

        // The points of an edge
        int edgeStartVtxIndex=0, edgeEndVtxIndex=0;

        // The current index in the positions list.
        size_t initialPositionIndex=0;
        size_t positionIndex=0;

        // Iterate over the grouped vertices and get the edges for every group.
        COLLADAFW::Tristrips* trifans = (COLLADAFW::Tristrips*) this;
        COLLADAFW::Tristrips::VertexCountArray& vertexCountArray =
            trifans->getGroupedVerticesVertexCountArray ();
        size_t groupedVertexElementsCount = vertexCountArray.getCount ();
        for ( size_t groupedVerticesIndex=0; groupedVerticesIndex<groupedVertexElementsCount; ++groupedVerticesIndex )
        {
            // A trifan has always triangles, which have 3 edges
            size_t triangleEdgeCounter = 0;

            // The number of vertices in the current vertex group.
            unsigned int vertexCount = vertexCountArray [groupedVerticesIndex];

            // Determine the number of edges and iterate over it.
            unsigned int numEdges = ( vertexCount - 3 ) * 3 + 3;
            for ( unsigned int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
            {
                // Increment the current triangle edge counter, so we know if we have the full triangle.
                ++triangleEdgeCounter;

                // Get the start edge index
                edgeStartVtxIndex = positionIndices[positionIndex];

                // With the third edge of a triangle, we have to go back to the trifans root.
                if ( triangleEdgeCounter < 3 )
                    edgeEndVtxIndex = positionIndices[++positionIndex];
                else edgeEndVtxIndex = positionIndices[initialPositionIndex];

                Edge edge ( edgeStartVtxIndex, edgeEndVtxIndex );

                // Appends the data of an edge to the edgeIndices list,
                // if it is not already in the list.
                appendEdge ( edge, edgeIndices, edgeIndicesMap );

                // Reset the edge counter, if we have all three edges of a triangle.
                if ( triangleEdgeCounter == 3 )
                {
                    triangleEdgeCounter = 0;
                    --positionIndex;
                    initialPositionIndex = positionIndex;
                }
            }

            // Increment the initial tristrip position index for the next tristrip object.
            positionIndex += 2;
            initialPositionIndex = positionIndex;
        }
    }

    //-----------------------------
    int MeshPrimitive::getGroupedVertexElementsCount () const
    {
        // Get the number of grouped vertex elements (faces, holes, tristrips or trifans).
        int groupedVertexElementsCount = 0;

        COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = this->getPrimitiveType ();
        switch ( primitiveType )
        {
        case COLLADAFW::MeshPrimitive::TRIANGLES:
            {
                groupedVertexElementsCount = (int) this->getFaceCount ();
                break;
            }
        case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
            {
                COLLADAFW::Trifans* trifans = (COLLADAFW::Trifans*) this;
                groupedVertexElementsCount = (int) trifans->getTrifanCount ();
                break;
            }
        case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
            {
                COLLADAFW::Tristrips* tristrips = (COLLADAFW::Tristrips*) this;
                groupedVertexElementsCount = (int) tristrips->getTristripCount ();
                break;
            }
        case COLLADAFW::MeshPrimitive::POLYGONS:
        case COLLADAFW::MeshPrimitive::POLYLIST:
            {
                COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*) this;
                COLLADAFW::Polygons::VertexCountArray& vertexCountArray =
                    polygons->getGroupedVerticesVertexCountArray ();
                groupedVertexElementsCount = (int) vertexCountArray.getCount ();
            }
            break;
        default:
            std::cerr << "Primitive type not supported: " << primitiveType << std::endl;
            assert ( "Primitive type not supported: " + primitiveType );
            return 0;
        }

        return groupedVertexElementsCount;
    }

    //-----------------------------
    void MeshPrimitive::appendEdge (
        const Edge& edge,
        std::vector<Edge>& edgeIndices,
        std::map<Edge,size_t>& edgeIndicesMap )
    {
        // Check if the current edge already exists in the map of edges.
        std::map<Edge,size_t>::iterator it = edgeIndicesMap.find ( edge );
        if ( it != edgeIndicesMap.end () ) return;

        // Push the new edge into the map with it's index value.
        edgeIndicesMap[edge] = edgeIndices.size ();

        // Push the new edge into the vector of edge indices.
        // We use it to write the list of edges into
        // the maya file. The vector is already sorted.
        edgeIndices.push_back ( edge );
    }

}
