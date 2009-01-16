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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaGeometryImporter.h"

#include <maya/MFnMesh.h>
#include <maya/MFnTransform.h>
#include <maya/MDagModifier.h>

#pragma warning(disable:4172)

#include "MayaDMTransform.h"
#include "MayaDMPolyCube.h"

#include "COLLADAFWPolygons.h"


namespace COLLADAMaya
{
    
    // --------------------------------------------
    GeometryImporter::GeometryImporter( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
    , mTransformObject ( MObject::kNullObj )
    {}

    // --------------------------------------------
    bool GeometryImporter::importGeometry ( const COLLADAFW::Geometry* geometry )
    {
        if ( geometry == 0 ) return false;

        mGeometry = geometry;

//        const COLLADAFW::GeometricElement* geometricElement = geometry->getGeometricElement ();
        COLLADAFW::Geometry::GeometryType type = geometry->getType ();
        switch ( type )
        {
        case COLLADAFW::Geometry::GEO_TYPE_CONVEX_MESH:
            std::cerr << "Import of convex_mesh not supported!" << std::endl;
            return false;
        case COLLADAFW::Geometry::GEO_TYPE_SPLINE:
            std::cerr << "Import of spline not supported!" << std::endl;
            return false;
        case COLLADAFW::Geometry::GEO_TYPE_MESH:
            {
                COLLADAFW::Mesh* mesh = ( COLLADAFW::Mesh* ) geometry;
                importMesh ( mesh );
                break;
            }
        default:
            return false;
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::importMesh ( const COLLADAFW::Mesh* mesh )
    {
        String id = mesh->getId ();
        String name = mesh->getName ();

        // TODO Import triangles
        size_t numVertices = 3;

        COLLADAFW::Geometry::GeometryType type = mesh->getType ();

        // Get the current maya ascii file to write the data.
        FILE* file = getDocumentImporter ()->getFile ();

        // TODO Get the transform node of the current mesh.
        MayaDM::Transform transformNode ( file, "pCube1", "" );

        // Create the current mesh node.
        MayaDM::Mesh meshNode ( file, mesh->getName (), transformNode.getName () );
        
        // Write the vertex positions. 
        // Just write the values, they will be referenced from the edges and the faces.
        if ( !writeVertexPositions ( mesh, meshNode ) ) return false;

        // Write the normals. 
        if ( !writeNormals ( mesh, meshNode ) ) return false;

        // Write the uv corrdinates.
        writeUVCoords ( mesh, meshNode );

        // The vector of edge indices. We use it to write the list of edges into 
        // the maya file. The vector is already sorted.
        std::vector<COLLADAFW::Edge> edgeIndices;

        // We store the edge indices also in a sorted map. The dublicate data holding 
        // is reasonable, because we need the index of a given edge. The search of  
        // values in a map is much faster than in a vector!
        std::map<COLLADAFW::Edge,int> edgeIndicesMap;

        // Implementation for multiple primitive elements.
        const COLLADAFW::MeshPrimitiveArray& primitiveElementsArray = mesh->getMeshPrimitives ();
        size_t count = primitiveElementsArray.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            COLLADAFW::MeshPrimitive* primitiveElement = primitiveElementsArray [ i ];

            // Determine the edge indices (unique edges, also for multiple primitive elements).
            primitiveElement->appendEdgeIndices ( edgeIndices, edgeIndicesMap );
        }

        // Write the edge indices of all primitive elements into the maya file.
        writeEdges ( edgeIndices, meshNode );

        // Write the face informations of all primitive elements into the maya file.
        writeFaces ( mesh, edgeIndicesMap, meshNode );

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::getEdgeIndex ( 
        const COLLADAFW::Edge& edge, 
        const std::map<COLLADAFW::Edge,int>& edgeIndicesMap, 
        int& edgeIndex )
    {
        // Find the index of the edge in the map of edges to get the index in the list.
        std::map<COLLADAFW::Edge,int>::const_iterator it = edgeIndicesMap.find ( edge );
        if ( it == edgeIndicesMap.end() ) 
        {
            // The edge has to be in the map!!!
            MString message ( "Edge not found: " ); message += edge[0] + ", " + edge[1];
            MGlobal::displayError ( message );
            std::cerr << message.asChar () << std::endl;
            return false;
        }
        edgeIndex = it->second; 
        if ( edge.isReverse() ) edgeIndex = -( edgeIndex + 1 );

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::writeVertexPositions ( 
        const COLLADAFW::Mesh* mesh, 
        MayaDM::Mesh &meshNode )
    {
        // We have always a stride of three (x, y and z values)
        size_t stride = 3;

        const COLLADAFW::MeshPositions& positions = mesh->getPositions ();
        const COLLADAFW::MeshFloatDoubleInputs::DataType type = positions.getType ();
        switch ( type )
        {
        case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::ArrayPrimitiveType<float>* values = positions.getFloatPositions ();
                size_t count = positions.getPositionsCount ();
                meshNode.startVrts ( 0, (count/stride)-1 ); 
                for ( size_t i=0, index=0; i<count; i+=stride, ++index )
                {
                    meshNode.appendVrtx ( (*values)[i], (*values)[i+1], (*values)[i+2] );
                }
                meshNode.endVrts (); 
            }
            break;
        case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::ArrayPrimitiveType<double>* values = positions.getDoublePositions ();
                size_t count = positions.getPositionsCount ();
                meshNode.startVrts ( 0, (count/stride)-1 ); 
                for ( size_t i=0, index=0; i<count; i+=stride, ++index )
                {
                    meshNode.appendVrtx ( (float)(*values)[i], (float)(*values)[i+1], (float)(*values)[i+2] );
                }
                meshNode.endVrts (); 
            }
            break;
        default:
            std::cerr << "No valid data type for positions: " << type << std::endl;
            return false;
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::writeNormals ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode )
    {
        // Count the number of normals to write into the maya file.
        size_t numNormals = mesh->getNormalsCount ();

        // Write the normals into the maya file.
        if ( numNormals > 0 )
        {
            meshNode.startNormals ( 0, numNormals-1 ); 
            if ( !appendNormalValues ( mesh, meshNode ) ) return false;
            meshNode.endNormals (); 
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::appendNormalValues ( 
        const COLLADAFW::Mesh* mesh, 
        MayaDM::Mesh &meshNode )
    {
        // Get the mesh normals values.
        const COLLADAFW::MeshNormals& normals = mesh->getNormals ();

        size_t stride = 3; // x, y, z

        // We have to go through every mesh primitive and append every element. 
        const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mesh->getMeshPrimitives ();
        size_t count = meshPrimitives.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            // Get the current primitive element.
            const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives [ i ];

            // Get the normal indices of the current primitive.
            const COLLADAFW::UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices ();

            // Iterate over the indices and write their normal values into the maya file.
            size_t indexCount = normalIndices.getCount ();
            for ( size_t j=0; j<indexCount; ++j )
            {
                // Get the index of the current normal.
                unsigned int normalIndex = normalIndices [ j ];

                // Get the position in the values list to read.
                unsigned int pos = normalIndex * stride;

                // Write the normal values on the index values.
                const COLLADAFW::MeshFloatDoubleInputs::DataType type = normals.getType ();
                switch ( type )
                {
                case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_FLOAT:
                    {
                        const COLLADAFW::ArrayPrimitiveType<float>* values = normals.getFloatNormals ();
                        meshNode.appendNormal ( (*values)[pos], (*values)[pos+1], (*values)[pos+2] );
                    }
                    break;
                case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_DOUBLE:
                    {
                        const COLLADAFW::ArrayPrimitiveType<double>* values = normals.getDoubleNormals ();
                        meshNode.appendNormal ( (float)(*values)[pos], (float)(*values)[pos+1], (float)(*values)[pos+2] );
                    }
                    break;
                default:
                    std::cerr << "No valid data type for normals: " << type << std::endl;
                    return false;
                }
            }
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::writeUVCoords ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode )
    {
        const COLLADAFW::MeshUVCoords& uvCoords = mesh->getUVCoords ();
        size_t stride = uvCoords.getStride ();
        const COLLADAFW::MeshFloatDoubleInputs::DataType type = uvCoords.getType ();
        switch ( type )
        {
        case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::ArrayPrimitiveType<float>* values = uvCoords.getFloatUVCoords ();
                size_t count = uvCoords.getUVCoordsCount ();
                meshNode.startUvSetPoints ( 0, 0, (count/2)-1 ); 
                for ( size_t i=0, index=0; i<count; i+=stride, ++index )
                {
                    meshNode.appendUvSetPoint ( (*values)[i], (*values)[i+1] );
                }
                meshNode.endUvSetPoints (); 
            }
            break;
        case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::ArrayPrimitiveType<double>* values = uvCoords.getDoubleUVCoords ();
                size_t count = uvCoords.getUVCoordsCount ();
                meshNode.startUvSetPoints ( 0, 0, (count/2)-1 ); 
                for ( size_t i=0, index=0; i<count; i+=stride, ++index )
                {
                    meshNode.appendUvSetPoint ( (float)(*values)[i], (float)(*values)[i+1] );
                }
                meshNode.endUvSetPoints (); 
            }
            break;
        default:
            std::cerr << "No valid data type for uv coordinates: " << type << std::endl;
            return false;
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::writeEdges (  
        const std::vector<COLLADAFW::Edge> &edgeIndices, 
        MayaDM::Mesh &meshNode )
    {
        size_t numEdges = edgeIndices.size ();
        if ( numEdges > 0 )
        {
            // We tell allways, that we have hard edges, so every vertex has a normal.
            int edgh = 0;

            // Go through the edges and write them
            meshNode.startEdges ( 0, numEdges-1 );
            for ( size_t k=0; k<numEdges; ++k )
            {
                const COLLADAFW::Edge& edge = edgeIndices [k];
                meshNode.appendEdge ( edge[0], edge[1], edgh );
            }
            meshNode.endEdges ();
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::writeFaces ( 
        const COLLADAFW::Mesh* mesh, 
        const std::map<COLLADAFW::Edge,int>& edgeIndicesMap, 
        MayaDM::Mesh &meshNode )
    {
        // Get the number of faces in the current mesh.
        size_t numFaces = mesh->getFacesCount ();
        if ( numFaces <= 0 ) return true;

        // Start to write the faces into the maya file
        meshNode.startFaces ( 0, numFaces-1 );

        // Go through the primitive elements and write the face values.
        const COLLADAFW::MeshPrimitiveArray& primitiveElementsArray = mesh->getMeshPrimitives ();
        size_t count = primitiveElementsArray.getCount ();

        // Determine the face values.
        for ( size_t i=0; i<count; ++i )
        {
            // Get the primitive element.
            COLLADAFW::MeshPrimitive* primitiveElement = primitiveElementsArray [ i ];

            // Write the face informations into the maya file.
            if ( !appendPolyFaces ( primitiveElement, edgeIndicesMap, meshNode ) ) return false;
        }

        // End the face element.
        meshNode.endFaces ();

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::appendPolyFaces ( 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const std::map<COLLADAFW::Edge,int>& edgeIndicesMap, 
        MayaDM::Mesh &meshNode )
    {
        // Triangles: every face has 3 vertices.
        size_t positionIndex=0;

        // Get the position indices
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // The vertex index values of an edge.
        int edgeStartVertexIndex=0, edgeEndVertexIndex=0;

        // The number of grouped vertex elements (faces, holes, tristrips or trifans).
        size_t groupedVertexElementsCount = 0;

        COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = primitiveElement->getPrimitiveType ();
        switch ( primitiveType )
        {
        case COLLADAFW::MeshPrimitive::TRIANGLES:
        case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
        case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
            groupedVertexElementsCount = primitiveElement->getFaceCount ();
            break;
        case COLLADAFW::MeshPrimitive::POLYGONS:
        case COLLADAFW::MeshPrimitive::POLYLIST:
            {
                COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*)primitiveElement;
                COLLADAFW::Polygons::VertexCountArray& vertexCountArray = 
                    polygons->getGroupedVerticesVertexCountArray ();
                groupedVertexElementsCount = vertexCountArray.getCount ();
            }
            break;
        default:
            std::cerr << "Primitive type not supported: " << primitiveType << std::endl;
            return false;
        }
        

        // Iterate over all grouped vertex elements (faces, holes, tristrips or trifans)
        // and determine the values for the maya polyFace object.
        for ( size_t faceIndex=0; faceIndex<groupedVertexElementsCount; ++faceIndex )
        {
            // The number of edges is always the same than the number of vertices in the current 
            // grouped vertices object. If the number is negative, the grouped object is a hole.
            int numEdges = primitiveElement->getFaceVertexCount ( faceIndex );

            // Handle faces
            if ( numEdges >= 0 )
            {
                // Create the poly face
                MayaDM::polyFaces polyFace;
                polyFace.f.faceEdgeCount = numEdges;
                polyFace.f.edgeIdValue = new int[numEdges];

                // Go through the edges and determine the face values.
                for ( size_t edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
                {
                    // Set the edge vertex index values into an edge object.
                    edgeStartVertexIndex = positionIndices[positionIndex];
                    if ( edgeIndex<(numEdges-1) )
                        edgeEndVertexIndex = positionIndices[++positionIndex];
                    else edgeEndVertexIndex = positionIndices[positionIndex-numEdges+1];
                    COLLADAFW::Edge edge ( edgeStartVertexIndex, edgeEndVertexIndex );

                    // Variable for the current edge index.
                    int edgeIndexValue;

                    // Get the edge index value from the edge list.
                    if ( !getEdgeIndex ( edge, edgeIndicesMap, edgeIndexValue ) ) return false;

                    // Set the edge list index into the poly face
                    polyFace.f.edgeIdValue[edgeIndex] = edgeIndexValue;
                }

                // Increment the positions index for the next face
                ++positionIndex;

//             //mu 0 4 0 1 3 2
//             polyFace.mu.uvSet = 0;
//             polyFace.mu.faceUVCount = 4;
//             polyFace.mu.uvIdValue = new int[4];
//             polyFace.mu.uvIdValue[0] = 0;
//             polyFace.mu.uvIdValue[1] = 1;
//             polyFace.mu.uvIdValue[2] = 3;
//             polyFace.mu.uvIdValue[3] = 2;

                meshNode.appendFace ( polyFace );
            }
            else
            {
                // Handle a hole element.
                numEdges *= -1;

                // Create the poly face
                MayaDM::polyFaces polyFace;
                polyFace.h.holeEdgeCount = numEdges;
                polyFace.h.edgeIdValue = new int[numEdges];

                // Go through the edges and determine the face values.
                for ( size_t edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
                {
                    // Set the edge vertex index values into an edge object.
                    edgeStartVertexIndex = positionIndices[positionIndex];
                    if ( edgeIndex<(numEdges-1) )
                        edgeEndVertexIndex = positionIndices[++positionIndex];
                    else edgeEndVertexIndex = positionIndices[positionIndex-numEdges+1];
                    COLLADAFW::Edge edge ( edgeStartVertexIndex, edgeEndVertexIndex );

                    // Variable for the current edge index.
                    int edgeIndexValue;

                    // Get the edge index value from the edge list.
                    if ( !getEdgeIndex ( edge, edgeIndicesMap, edgeIndexValue ) ) return false;

                    // Set the edge list index into the poly face
                    polyFace.h.edgeIdValue[edgeIndex] = edgeIndexValue;
                }

                // Increment the positions index for the next face
                ++positionIndex;

//             //mu 0 4 0 1 3 2
//             polyFace.mu.uvSet = 0;
//             polyFace.mu.faceUVCount = 4;
//             polyFace.mu.uvIdValue = new int[4];
//             polyFace.mu.uvIdValue[0] = 0;
//             polyFace.mu.uvIdValue[1] = 1;
//             polyFace.mu.uvIdValue[2] = 3;
//             polyFace.mu.uvIdValue[3] = 2;

                meshNode.appendFace ( polyFace );
            }

        }

        return true;
    }
}