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


namespace COLLADAFW
{



    //-----------------------------
	MeshPrimitive::MeshPrimitive() 
		: mPrimitiveType ( UNDEFINED_PRIMITIVE_TYPE )
		, mPositionIndices(UIntValuesArray::OWNER)
		, mNormalIndices(UIntValuesArray::OWNER)
		, mColorIndices(UIntValuesArray::OWNER)
		, mUVCoordIndicesArray(UIntValuesArray::OWNER)
		, mFaceCount ( 0 )
	{
	}

    //-----------------------------
	MeshPrimitive::MeshPrimitive( PrimitiveType primitiveType ) 
		: mPrimitiveType ( primitiveType )
		, mPositionIndices(UIntValuesArray::OWNER)
		, mNormalIndices(UIntValuesArray::OWNER)
		, mColorIndices(UIntValuesArray::OWNER)
		, mUVCoordIndicesArray(UIntValuesArray::OWNER)
		, mFaceCount ( 0 )
	{
	}

    //-----------------------------
    const int MeshPrimitive::getGroupedVerticesVertexCount( const size_t faceIndex ) const
    {
        switch ( mPrimitiveType )
        {
        case TRIANGLES:
        case TRIANGLE_FANS:
        case TRIANGLE_STRIPS:
            return 3; 
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
        // Get the number of grouped vertex elements (faces, holes, tristrips or trifans).
        int groupedVertexElementsCount = 0;

        COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = this->getPrimitiveType ();
        switch ( primitiveType )
        {
        case COLLADAFW::MeshPrimitive::TRIANGLES:
        case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
        case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
            groupedVertexElementsCount = (int)this->getFaceCount ();
            break;
        case COLLADAFW::MeshPrimitive::POLYGONS:
        case COLLADAFW::MeshPrimitive::POLYLIST:
            {
                COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*)this;
                COLLADAFW::Polygons::VertexCountArray& vertexCountArray = 
                    polygons->getGroupedVerticesVertexCountArray ();
                groupedVertexElementsCount = (int)vertexCountArray.getCount ();
            }
            break;
        default:
            std::cerr << "Primitive type not supported: " << primitiveType << std::endl;
            return;
        }

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
                else edgeEndVertexIndex = positionIndices[positionIndex-numEdges+1];
                Edge edge ( edgeStartVertexIndex, edgeEndVertexIndex );

                // Appends the data of an edge to the edgeIndices list, 
                // if it is not already in the list.
                appendEdge ( edge, edgeIndices, edgeIndicesMap );
            }

            // Increment the positions index for the next face
            ++positionIndex;
        }
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