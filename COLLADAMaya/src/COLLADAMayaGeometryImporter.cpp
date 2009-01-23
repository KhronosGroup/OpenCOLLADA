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
#include "ColladaMayaException.h"
#include "COLLADAMayaVisualSceneImporter.h"

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
    , mGeometry ( 0 )
    , mMesh ( 0 )
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
        // Set the current mesh member variable
        mMesh = mesh;

        String id = mesh->getId ();
        String name = mesh->getName ();

        // Get the current maya ascii file to write the data.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the transform node of the current mesh.
//        MayaDM::Transform transformNode ( file, "pCube1", "" );
        const DocumentImporter* documentImporter = getDocumentImporter ();
        const VisualSceneImporter* visualSceneImporter = documentImporter->getVisualSceneImporter ();
        const UniqueIdToUniqueIdsMap& geometryNodesMap = visualSceneImporter->getGeometryNodesMap ();

        const COLLADAFW::UniqueId& geometryID = mesh->getUniqueId ();
        //geometryNodesMap [ geometryID ];
        UniqueIdToUniqueIdsMap::const_iterator it = geometryNodesMap.find ( geometryID );
        if ( it == geometryNodesMap.end () ) 
        {
            std::cerr << "No transform node for the current geometry!" << endl;
            return false;
        }

        const std::set<const COLLADAFW::UniqueId>& nodesSet = ( *it ).second;
        size_t numNodes = nodesSet.size ();

        std::set<const COLLADAFW::UniqueId>::const_iterator it2 = nodesSet.begin ();
        const COLLADAFW::UniqueId& nodeId = *it2;

        const UniqueIdNamesMap& nodeNamesMap = visualSceneImporter->getNodeNamesMap ();
//        String nodeName = nodeNamesMap [ nodeId ];
        UniqueIdNamesMap::const_iterator it3 = nodeNamesMap.find ( nodeId );
        if ( it3 == nodeNamesMap.end () ) 
        {
            std::cerr << "No name for the transform node!" << endl;
            assert ( "No name for the transform node!" );
            return false;
        }
        String nodeName = (*it3).second;

        // Create the current mesh node.
        MayaDM::Mesh meshNode ( file, mesh->getName (), nodeName );
        
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
        std::map<COLLADAFW::Edge,size_t> edgeIndicesMap;

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
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        int& edgeIndex )
    {
        // Find the index of the edge in the map of edges to get the index in the list.
        std::map<COLLADAFW::Edge,size_t>::const_iterator it = edgeIndicesMap.find ( edge );
        if ( it == edgeIndicesMap.end() ) 
        {
            // The edge has to be in the map!!!
            MString message ( "Edge not found: " ); message += edge[0] + ", " + edge[1];
            MGlobal::displayError ( message );
            std::cerr << message.asChar () << std::endl;
            return false;
        }
        edgeIndex = (int)it->second; 
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
                    meshNode.appendVrts ( (*values)[i] );
                    meshNode.appendVrts ( (*values)[i+1] );
                    meshNode.appendVrts ( (*values)[i+2] );
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
                    meshNode.appendVrts ( (float)(*values)[i] );
                    meshNode.appendVrts ( (float)(*values)[i+1] );
                    meshNode.appendVrts ( (float)(*values)[i+2] );
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
                        meshNode.appendNormals ( (*values)[pos] );
                        meshNode.appendNormals ( (*values)[pos+1] );
                        meshNode.appendNormals ( (*values)[pos+2] );
                    }
                    break;
                case COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_DOUBLE:
                    {
                        const COLLADAFW::ArrayPrimitiveType<double>* values = normals.getDoubleNormals ();
                        meshNode.appendNormals ( (float)(*values)[pos] );
                        meshNode.appendNormals ( (float)(*values)[pos+1] );
                        meshNode.appendNormals ( (float)(*values)[pos+2] );
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
        size_t stride = (size_t)uvCoords.getStride ();
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
                    meshNode.appendUvSetPoints ( (*values)[i] );
                    meshNode.appendUvSetPoints ( (*values)[i+1] );
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
                    meshNode.appendUvSetPoints ( (float)(*values)[i] );
                    meshNode.appendUvSetPoints ( (float)(*values)[i+1] );
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
            meshNode.startEdge ( 0, numEdges-1 );
            for ( size_t k=0; k<numEdges; ++k )
            {
                const COLLADAFW::Edge& edge = edgeIndices [k];
                meshNode.appendEdge ( edge[0] );
                meshNode.appendEdge ( edge[1] );
                meshNode.appendEdge ( edgh );
            }
            meshNode.endEdge ();
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::writeFaces ( 
        const COLLADAFW::Mesh* mesh, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::Mesh &meshNode )
    {
        // Get the number of faces in the current mesh.
        size_t numFaces = mesh->getFacesCount ();
        if ( numFaces <= 0 ) return true;

        // Start to write the faces into the maya file
        meshNode.startFace ( 0, numFaces-1 );

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
        meshNode.endFace ();

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::appendPolyFaces ( 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::Mesh &meshNode )
    {
        // Triangles: every face has 3 vertices.
        size_t positionIndex=0;

        // Get the position indices
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // The vertex index values of an edge.
        int edgeStartVtxIndex=0, edgeEndVtxIndex=0;

        // The number of grouped vertex elements (faces, holes, tristrips or trifans).
        size_t groupedVerticesCount = getGroupedVerticesCount ( primitiveElement );

        // To handle polygons with holes:
        // Flag, if the actual face is clockwise orientated. We need this information to handle
        // polygons with holes, because this need the opposite direction of their polygons. 
        bool faceClockwiseOriented = true;

        // Polygons with holes: we have always first one polygon for any number of holes.
        // We need the first three vertexes to determine the orientation of any polygon.
        std::vector<COLLADABU::Math::Vector3*> polygonPoints;

        // Iterate over all grouped vertex elements (faces, holes, tristrips or trifans)
        // and determine the values for the maya polyFace object.
        for ( size_t groupedVtxIndex=0; groupedVtxIndex<groupedVerticesCount; ++groupedVtxIndex )
        {
            // The number of edges is always the same than the number of vertices in the current 
            // grouped vertices object. If the number is negative, the grouped object is a hole.
            int numEdges = primitiveElement->getGroupedVerticesVertexCount ( groupedVtxIndex );

            // Handle faces
            if ( numEdges >= 0 )
            {
                // Create the poly face
                MayaDM::polyFaces polyFace;
                polyFace.f.faceEdgeCount = numEdges;
                polyFace.f.edgeIdValue = new int[numEdges];

                // Go through the edges and determine the face values.
                for ( int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
                {
                    // Set the edge vertex index values into an edge object.
                    edgeStartVtxIndex = positionIndices[positionIndex];
                    if ( edgeIndex<(numEdges-1) )
                        edgeEndVtxIndex = positionIndices[++positionIndex];
                    else edgeEndVtxIndex = positionIndices[positionIndex-numEdges+1];
                    COLLADAFW::Edge edge ( edgeStartVtxIndex, edgeEndVtxIndex );

                    // Polygons with holes: Get the first three polygon vertices to determine 
                    // the polygon's orientation.
                    COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = primitiveElement->getPrimitiveType ();
                    if ( primitiveType == COLLADAFW::MeshPrimitive::POLYGONS && edgeIndex < 3 )
                    {
                        // Delete the old points, if they still exist.
                        if ( edgeIndex == 0 && polygonPoints.size () > 0 )
                        {
                            // Delete the points.
                            size_t pSize = polygonPoints.size ();
                            for ( size_t i=0; i<pSize; ++i) 
                                delete polygonPoints [i];
                            polygonPoints.clear ();
                        }
                        // Store the vertex positions of the current start point.
                        polygonPoints.push_back ( getVertexPosition ( edgeStartVtxIndex ) );
                    }

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

                // The orientation of a hole has always to be the opposite direction of his
                // parenting polygon. About this, we have to determine the hole's orientation.
                // We just need the first three vectors to determine the polygon's orientation.
                std::vector<COLLADABU::Math::Vector3*> holePoints;

                // Create the poly face
                MayaDM::polyFaces polyFace;
                polyFace.h.holeEdgeCount = numEdges;
                polyFace.h.edgeIdValue = new int[numEdges];

                // Go through the edges and determine the face values.
                for ( int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
                {
                    // Set the edge vertex index values into an edge object.
                    edgeStartVtxIndex = positionIndices[positionIndex];
                    if ( edgeIndex<(numEdges-1) )
                        edgeEndVtxIndex = positionIndices[++positionIndex];
                    else edgeEndVtxIndex = positionIndices[positionIndex-numEdges+1];
                    COLLADAFW::Edge edge ( edgeStartVtxIndex, edgeEndVtxIndex );

                    // Polygons with holes: Get the first three polygon vertices to determine 
                    // the polygon's orientation.
                    if ( edgeIndex < 3 )
                    {
                        // Store the vertex positions of the current start point.
                        holePoints.push_back ( getVertexPosition ( edgeStartVtxIndex ) );
                    }

                    // The current edge index.
                    int edgeIndexValue;

                    // Get the edge index value from the edge list.
                    if ( !getEdgeIndex ( edge, edgeIndicesMap, edgeIndexValue ) ) return false;

                    // Set the edge list index into the poly face
                    polyFace.h.edgeIdValue[edgeIndex] = edgeIndexValue;
                }

                // Check if we have to change the orientation of the current hole.
                if ( changeHoleOrientation ( polygonPoints, holePoints ) )
                {
                    changePolyFaceHoleOrientation ( polyFace );
                }
                // Delete the points.
                size_t hSize = holePoints.size ();
                for ( size_t i=0; i<holePoints.size (); ++i) 
                    delete holePoints [i];
                holePoints.clear ();
                
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

        // Delete the points.
        size_t pSize = polygonPoints.size ();
        for ( size_t i=0; i<pSize; ++i) 
            delete polygonPoints [i];
        polygonPoints.clear ();

        return true;
    }

    // --------------------------------------------
    COLLADABU::Math::Vector3* GeometryImporter::getVertexPosition ( size_t vertexIndex )
    {
        // Get the points of the current edge.
        const COLLADAFW::MeshPositions& meshPositions = mMesh->getPositions ();

        // Get the vertex position values of the start position of the current edge.
        double dx, dy, dz; 
        if ( meshPositions.getType () == COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_FLOAT )
        {
            dx = (double)((*(meshPositions.getFloatValues ()))[(vertexIndex*3)]);
            dy = (double)((*(meshPositions.getFloatValues ()))[(vertexIndex*3)+1]);
            dz = (double)((*(meshPositions.getFloatValues ()))[(vertexIndex*3)+2]);
        }
        else if ( meshPositions.getType () == COLLADAFW::MeshFloatDoubleInputs::DATA_TYPE_DOUBLE )
        {
            dx = (*(meshPositions.getDoubleValues ()))[(vertexIndex*3)];
            dy = (*(meshPositions.getDoubleValues ()))[(vertexIndex*3)+1];
            dz = (*(meshPositions.getDoubleValues ()))[(vertexIndex*3)+2];
        }
        else
        {
            throw new ColladaMayaException ("GeometryImporter::appendPolyFaces:: Unknown data type!");
            std::cerr << "GeometryImporter::appendPolyFaces:: Unknown data type!" << std::endl;
        }

        // Store the vertex positions of the current start point.
        return new COLLADABU::Math::Vector3 ( dx, dy, dz );;
    }

    // --------------------------------------------
    bool GeometryImporter::changeHoleOrientation ( 
        std::vector<COLLADABU::Math::Vector3*>& polygonPoints, 
        std::vector<COLLADABU::Math::Vector3*>& holePoints )
    {
        // Flag, if the orientation of the hole element has to be changed.
        bool changeOrientation = false;

        // Get the cross product of the parenting polygon.
        COLLADABU::Math::Vector3 p1 = *polygonPoints [1] - *polygonPoints [0];
        COLLADABU::Math::Vector3 p2 = *polygonPoints [2] - *polygonPoints [0];
        COLLADABU::Math::Vector3 polyCrossProduct = p1.crossProduct ( p2 );

        // Get the cross product of the hole.
        COLLADABU::Math::Vector3 h1 = *holePoints [1] - *holePoints [0];
        COLLADABU::Math::Vector3 h2 = *holePoints [2] - *holePoints [0];
        COLLADABU::Math::Vector3 holeCrossProduct = h1.crossProduct ( h2 );

        // If they have the same orientation, we have to change the holes orientation.
        if ( polyCrossProduct.dotProduct ( holeCrossProduct ) > 0 )
        {
            // Change the hole's orientation.
            changeOrientation = true;
        }	
        
        return changeOrientation;
    }

    // --------------------------------------------
    size_t GeometryImporter::getGroupedVerticesCount ( 
        const COLLADAFW::MeshPrimitive* primitiveElement )
    {
        size_t groupedVerticesCount = 0;

        COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = primitiveElement->getPrimitiveType ();
        switch ( primitiveType )
        {
        case COLLADAFW::MeshPrimitive::TRIANGLES:
        case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
        case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
            {
                groupedVerticesCount = primitiveElement->getFaceCount ();
                break;
            }
        case COLLADAFW::MeshPrimitive::POLYGONS:
        case COLLADAFW::MeshPrimitive::POLYLIST:
            {
                COLLADAFW::Polygons* polygons = (COLLADAFW::Polygons*)primitiveElement;
                COLLADAFW::Polygons::VertexCountArray& vertexCountArray = 
                    polygons->getGroupedVerticesVertexCountArray ();
                groupedVerticesCount = vertexCountArray.getCount ();
                break;
            }
        default:
            {
                String message = "GeometryImporter::getGroupedVerticesCount:: Primitive type not supported: " + primitiveType;
                std::cerr << message << std::endl;
                throw new ColladaMayaException ( message );
                break;
            }
        }

        return groupedVerticesCount;
    }

    // --------------------------------------------
    void GeometryImporter::changePolyFaceHoleOrientation ( MayaDM::polyFaces &polyFace )
    {
        // Get the edge indices in the different order and change the orientation.
        std::vector<int> valueVec;

        // Edge count
        int numEdges = polyFace.h.holeEdgeCount;

        // Change the orientation and write it into the valueVec.
        for ( int edgeIndex=numEdges-1; edgeIndex>=0; --edgeIndex )
        {
            int edgeIndexValue = polyFace.h.edgeIdValue[edgeIndex];
            edgeIndexValue = ( edgeIndexValue + 1 ) * (-1);
            valueVec.push_back ( edgeIndexValue );
        }
        // Write the edge list index from the valueVec into polyFace.
        for ( size_t edgeIndex=0; edgeIndex<valueVec.size (); ++edgeIndex )
        {
            polyFace.h.edgeIdValue[edgeIndex] = valueVec[edgeIndex];
        }
    }
}