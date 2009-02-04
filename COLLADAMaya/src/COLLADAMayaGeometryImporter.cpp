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
#include "MayaDMCommands.h"

#include "COLLADAFWPolygons.h"


namespace COLLADAMaya
{
    
    // --------------------------------------------
    GeometryImporter::GeometryImporter( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
    {}

    // --------------------------------------------
    bool GeometryImporter::importGeometry ( const COLLADAFW::Geometry* geometry )
    {
        if ( geometry == 0 ) return false;

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
        // Get the unique framework mesh id 
        const COLLADAFW::UniqueId& meshUniqueId = mesh->getUniqueId ();

        // Get the transform node of the current mesh.
        DocumentImporter* documentImporter = getDocumentImporter ();
        VisualSceneImporter* visualSceneImporter = documentImporter->getVisualSceneImporter ();

        // Get all visual scene nodes, which use this geometry an make the parent connection
       const std::set<const COLLADAFW::UniqueId>* transformNodesSet = 
            visualSceneImporter->getGeometryTransformIds ( meshUniqueId );
        size_t numNodes = transformNodesSet->size ();
        std::set<const COLLADAFW::UniqueId>::const_iterator nodesIter = transformNodesSet->begin ();
        while ( nodesIter != transformNodesSet->end () )
        {
            // Get the maya node of the current transform node.
            const COLLADAFW::UniqueId& transformNodeUniqueId = *nodesIter;
            MayaNode* mayaTransformNode = visualSceneImporter->getMayaTransformNode ( transformNodeUniqueId );
            String transformNodeName = mayaTransformNode->getName ();

            // The first reference is a direct one, the others are instances.
            if ( nodesIter == transformNodesSet->begin() )
            {
                // Create the current mesh node.
                createMesh ( mesh, mayaTransformNode );
            }
            else
            {
                // Get the path to the mesh and the parent transform node
                String transformNodePath = mayaTransformNode->getNodePath ();

                // We need the path of the mesh.
                const COLLADAFW::UniqueId& uniqueId = mesh->getUniqueId ();
                MayaNode* mayaMeshNode = getMayaMeshNode ( uniqueId );
                String meshNodePath = mayaMeshNode->getNodePath ();

                // parent -shape -noConnections -relative -addObject "|pCube1|pCubeShape1" "pCube2";
                FILE* file = getDocumentImporter ()->getFile ();
                MayaDM::parentShape ( file, meshNodePath, transformNodePath, false, true, true, true );
            }

            ++nodesIter;
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::createMesh ( 
        const COLLADAFW::Mesh* mesh, 
        MayaNode* mayaTransformNode )
    {
        // Create a unique name.
        String meshName = mMeshNodeIdList.addId ( mesh->getName () );

        // Create a maya node object of the current node and push it into the map.
        const COLLADAFW::UniqueId& uniqueId = mesh->getUniqueId ();
        MayaNode mayaMeshNode ( uniqueId, meshName, mayaTransformNode );
        mMayaMeshNodesMap [ uniqueId ] = mayaMeshNode;

        // Get the parent node name.
        assert ( mayaTransformNode != NULL );
        String transformNodePath = mayaTransformNode->getNodePath ();

        // Create the current mesh node.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Mesh meshNode ( file, mesh->getName (), transformNodePath );

        // Write the vertex positions. 
        // Just write the values, they will be referenced from the edges and the faces.
        if ( !writeVertexPositions ( mesh, meshNode ) ) return false;

        // Write the normals. 
        if ( !writeNormals ( mesh, meshNode ) ) return false;

        // Write the uv corrdinates.
        writeUVSets ( mesh, meshNode );

        // TODO Implementation: set current uv set
//        writeCurrentUVSet ( mesh, meshNode );

        // Write the uv corrdinates.
        writeColorSets ( mesh, meshNode );

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
            assert ( it != edgeIndicesMap.end() );
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

        const COLLADAFW::MeshVertexData& positions = mesh->getPositions ();
        const COLLADAFW::MeshVertexData::DataType type = positions.getType ();
        switch ( type )
        {
        case COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::ArrayPrimitiveType<float>* values = positions.getFloatValues ();
                size_t count = positions.getValuesCount ();
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
        case COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::ArrayPrimitiveType<double>* values = positions.getDoubleValues ();
                size_t count = positions.getValuesCount ();
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
        const COLLADAFW::MeshVertexData& normals = mesh->getNormals ();

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
                const COLLADAFW::MeshVertexData::DataType type = normals.getType ();
                switch ( type )
                {
                case COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT:
                    {
                        const COLLADAFW::ArrayPrimitiveType<float>* values = normals.getFloatValues ();
                        meshNode.appendNormals ( (*values)[pos] );
                        meshNode.appendNormals ( (*values)[pos+1] );
                        meshNode.appendNormals ( (*values)[pos+2] );
                    }
                    break;
                case COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE:
                    {
                        const COLLADAFW::ArrayPrimitiveType<double>* values = normals.getDoubleValues ();
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
    bool GeometryImporter::writeUVSets ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode )
    {
        // Set the number of uv sets.
        const COLLADAFW::MeshVertexData& uvCoords = mesh->getUVCoords ();
        size_t sumUVSetPoints = uvCoords.getNumInputInfos ();
        if ( sumUVSetPoints == 0 ) return false;
        meshNode.setUvSize ( sumUVSetPoints );

        // Write the values 
        size_t initialIndex = 0;
        const COLLADAFW::MeshVertexData::DataType type = uvCoords.getType ();
        switch ( type )
        {
        case COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::ArrayPrimitiveType<float>* values = uvCoords.getFloatValues ();
                for ( size_t i=0; i<sumUVSetPoints; ++i )
                {
                    meshNode.setUvSetName ( i, uvCoords.getName ( i ) );
                    
                    size_t stride = uvCoords.getStride ( i );
                    assert ( stride > 1 && stride <= 4 );
                    if ( stride != 2 ) 
                        MGlobal::displayWarning ( "Just 2d uv set data will be imported! ");

                    size_t indicesCount = uvCoords.getLength ( i );
                    meshNode.startUvSetPoints ( i, 0, (indicesCount/stride)-1 ); 

                    unsigned int index = 0;
                    for ( size_t i=0; i<indicesCount; i+=stride )
                    {
                        meshNode.appendUvSetPoints ( (*values)[initialIndex+i] );
                        meshNode.appendUvSetPoints ( (*values)[initialIndex+i+1] );
                    }
                    meshNode.endUvSetPoints (); 

                    initialIndex += indicesCount;
                }
                break;
            }
        case COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::ArrayPrimitiveType<double>* values = uvCoords.getDoubleValues ();
                for ( size_t i=0; i<sumUVSetPoints; ++i )
                {
                    meshNode.setUvSetName ( i, uvCoords.getName ( i ) );

                    size_t stride = uvCoords.getStride ( i );
                    assert ( stride > 1 && stride <= 4 );
                    if ( stride != 2 ) 
                        MGlobal::displayWarning ( "Just 2d uv set data will be imported! ");

                    size_t indicesCount = uvCoords.getLength ( i );
                    meshNode.startUvSetPoints ( i, 0, (indicesCount/stride)-1 ); 

                    unsigned int index = 0;
                    for ( size_t i=0; i<indicesCount; i+=stride )
                    {
                        meshNode.appendUvSetPoints ( (float) (*values)[initialIndex+i] );
                        meshNode.appendUvSetPoints ( (float) (*values)[initialIndex+i+1] );
                    }
                    meshNode.endUvSetPoints (); 

                    initialIndex += indicesCount;
                }
            }
            break;
        default:
            std::cerr << "No valid data type for uv coordinates: " << type << std::endl;
            return false;
        }

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::writeColorSets ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode )
    {
        // Set the number of uv sets.
        const COLLADAFW::MeshVertexData& colors = mesh->getColors ();
        size_t sumUVSetPoints = colors.getNumInputInfos ();
        if ( sumUVSetPoints == 0 ) return false;
//        meshNode.setColorSetSize ( sumUVSetPoints );

        // Write the values 
        size_t initialIndex = 0;
        const COLLADAFW::MeshVertexData::DataType type = colors.getType ();
        switch ( type )
        {
        case COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::ArrayPrimitiveType<float>* values = colors.getFloatValues ();
                for ( size_t i=0; i<sumUVSetPoints; ++i )
                {
                    meshNode.setColorName ( i, colors.getName ( i ) );

                    size_t stride = colors.getStride ( i );
                    assert ( stride == 1 || stride == 3 || stride <= 4 );

                    unsigned int representation = 2; // RGBA = 2 DEFAULT
                    if ( stride == 1 ) representation = 1; // A = 1
                    else if ( stride == 3 ) representation = 3; // RGB = 3
                    meshNode.setRepresentation ( i, representation );

                    size_t indicesCount = colors.getLength ( i );
                    meshNode.startColorSetPoints ( i, 0, (indicesCount/stride)-1 ); 

                    unsigned int index = 0;
                    for ( size_t i=0; i<indicesCount; i+=stride )
                    {
                        for ( size_t j=0; j<stride; ++j ) 
                        {
                            meshNode.appendColorSetPoints ( (*values)[initialIndex+i+j] );
                        }
                    }
                    meshNode.endColorSetPoints (); 

                    initialIndex += indicesCount;
                }
                break;
            }
        case COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::ArrayPrimitiveType<double>* values = colors.getDoubleValues ();
                for ( size_t i=0; i<sumUVSetPoints; ++i )
                {
                    meshNode.setColorName ( i, colors.getName ( i ) );

                    size_t stride = colors.getStride ( i );
                    assert ( stride == 1 || stride == 3 || stride <= 4 );

                    unsigned int representation = 2; // RGBA = 2 DEFAULT
                    if ( stride == 1 ) representation = 1; // A = 1
                    else if ( stride == 3 ) representation = 3; // RGB = 3
                    meshNode.setRepresentation ( i, representation );

                    size_t indicesCount = colors.getLength ( i );
                    meshNode.startColorSetPoints ( i, 0, (indicesCount/stride)-1 ); 

                    unsigned int index = 0;
                    for ( size_t i=0; i<indicesCount; i+=stride )
                    {
                        for ( size_t j=0; j<stride; ++j ) 
                        {
                            meshNode.appendColorSetPoints ( ( float ) (*values)[initialIndex+i+j] );
                        }
                    }
                    meshNode.endColorSetPoints (); 

                    initialIndex += indicesCount;
                }
            }
            break;
        default:
            std::cerr << "No valid data type for colors: " << type << std::endl;
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
            if ( !appendPolyFaces ( mesh, primitiveElement, edgeIndicesMap, meshNode ) ) return false;
        }

        // End the face element.
        meshNode.endFace ();

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::appendPolyFaces ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::Mesh &meshNode )
    {
        size_t positionIndex=0;
        size_t uvSetIndicesIndex = 0;
        size_t colorIndicesIndex = 0;

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

            // Create the poly face
            MayaDM::polyFaces polyFace;

            // Handle the face infos.
            setFaceInfos ( mesh, primitiveElement, edgeIndicesMap, polyFace, numEdges, positionIndex, polygonPoints );

            // Handle the uv set infos.
            setUVSetInfos ( mesh, primitiveElement, polyFace, uvSetIndicesIndex, numEdges );

            // Handle the uv set infos.
            setColorInfos ( mesh, primitiveElement, polyFace, colorIndicesIndex, numEdges );

            // Write the polyFace data in the maya file.
            meshNode.appendFace ( polyFace );
        }

        // Delete the points.
        size_t pSize = polygonPoints.size ();
        for ( size_t i=0; i<pSize; ++i) 
            delete polygonPoints [i];
        polygonPoints.clear ();

        return true;
    }

    // --------------------------------------------
    void GeometryImporter::setFaceInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::polyFaces &polyFace, 
        int &numEdges, 
        size_t &positionIndex, 
        std::vector<COLLADABU::Math::Vector3*> &polygonPoints )
    {
        // Handle faces
        if ( numEdges >= 0 )
            setFaceInfo ( mesh, primitiveElement, edgeIndicesMap, polyFace, numEdges, positionIndex, polygonPoints );
        else
            setHoleInfo ( mesh, primitiveElement, edgeIndicesMap, polyFace, numEdges, positionIndex, polygonPoints );
    }

    // --------------------------------------------
    void GeometryImporter::setFaceInfo ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::polyFaces &polyFace, 
        int& numEdges, 
        size_t& positionIndex, 
        std::vector<COLLADABU::Math::Vector3*> &polygonPoints )
    {
        // Handle the edge informations.
        polyFace.f.faceEdgeCount = numEdges;
        polyFace.f.edgeIdValue = new int[numEdges];

        // Get the position indices
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // Go through the edges and determine the face values.
        for ( int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
        {
            // Set the edge vertex index values into an edge object.
            int edgeStartVtxIndex = positionIndices[positionIndex];
            int edgeEndVtxIndex = 0;
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
                polygonPoints.push_back ( getVertexPosition ( mesh, edgeStartVtxIndex ) );
            }

            // Variable for the current edge index.
            int edgeIndexValue;

            // Get the edge index value from the edge list.
            getEdgeIndex ( edge, edgeIndicesMap, edgeIndexValue );

            // Set the edge list index into the poly face
            polyFace.f.edgeIdValue[edgeIndex] = edgeIndexValue;
        }

        // Increment the positions index for the next face
        ++positionIndex;
    }

    // --------------------------------------------
    void GeometryImporter::setHoleInfo ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::polyFaces &polyFace, 
        int &numEdges, 
        size_t &positionIndex, 
        std::vector<COLLADABU::Math::Vector3*> & polygonPoints )
    {
        // Get the position indices
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // Handle a hole element.
        numEdges *= -1;

        // The orientation of a hole has always to be the opposite direction of his
        // parenting polygon. About this, we have to determine the hole's orientation.
        // We just need the first three vectors to determine the polygon's orientation.
        std::vector<COLLADABU::Math::Vector3*> holePoints;

        polyFace.h.holeEdgeCount = numEdges;
        polyFace.h.edgeIdValue = new int[numEdges];

        // Go through the edges and determine the face values.
        for ( int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
        {
            // Set the edge vertex index values into an edge object.
            int edgeStartVtxIndex = positionIndices[positionIndex];
            int edgeEndVtxIndex = 0;
            if ( edgeIndex<(numEdges-1) )
                edgeEndVtxIndex = positionIndices[++positionIndex];
            else edgeEndVtxIndex = positionIndices[positionIndex-numEdges+1];
            COLLADAFW::Edge edge ( edgeStartVtxIndex, edgeEndVtxIndex );

            // Polygons with holes: Get the first three polygon vertices to determine 
            // the polygon's orientation.
            if ( edgeIndex < 3 )
            {
                // Store the vertex positions of the current start point.
                holePoints.push_back ( getVertexPosition ( mesh, edgeStartVtxIndex ) );
            }

            // The current edge index.
            int edgeIndexValue;

            // Get the edge index value from the edge list.
            getEdgeIndex ( edge, edgeIndicesMap, edgeIndexValue );

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
    }

    // --------------------------------------------
    void GeometryImporter::setUVSetInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        MayaDM::polyFaces &polyFace, 
        size_t& uvSetIndicesIndex, 
        const int numEdges )
    {
        const COLLADAFW::IndexListArray& uvSetIndicesArray = primitiveElement->getUVCoordIndicesArray ();
        size_t numUVSets = uvSetIndicesArray.getCount ();
        polyFace.mu = new MayaDM::polyFaces::MU [ numUVSets ];
        polyFace.muCount = numUVSets;
        for ( size_t i=0; i<numUVSets; ++i )
        {
            // Get the index of the uv set
            const COLLADAFW::IndexList* indexList = primitiveElement->getUVCoordIndices ( i );
            String uvSetName = indexList->getName ();
            size_t index = mesh->getUVSetIndexByName ( uvSetName );

            const COLLADAFW::MeshVertexData& meshUVCoords = mesh->getUVCoords ();
            polyFace.mu[i].uvSet = (int) index;
            polyFace.mu[i].faceUVCount = numEdges;
            polyFace.mu[i].uvIdValue = new int [numEdges];

            for ( int j=0; j<numEdges; ++j )
            {
                size_t currentIndexPosition = j + uvSetIndicesIndex;
                unsigned int currentIndex = indexList->getIndex ( currentIndexPosition );
                // Decrement the index values
                size_t initialIndex = indexList->getInitialIndex ();
                polyFace.mu[i].uvIdValue [j] = currentIndex - initialIndex;
            }
        }
        // Increment the current uv set index for the number of edges.
        uvSetIndicesIndex += numEdges;
    }

    // --------------------------------------------
    void GeometryImporter::setColorInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        MayaDM::polyFaces &polyFace, 
        size_t& colorIndicesIndex, 
        const int numEdges )
    {
        const COLLADAFW::IndexListArray& colorIndicesArray = primitiveElement->getColorIndicesArray ();
        size_t numColorInputs = colorIndicesArray.getCount ();
        polyFace.mc = new MayaDM::polyFaces::MC [ numColorInputs ];
        polyFace.mcCount = numColorInputs;
        for ( size_t i=0; i<numColorInputs; ++i )
        {
            // Get the index of the uv set
            const COLLADAFW::IndexList* indexList = primitiveElement->getColorIndices ( i );
            String colorInputName = indexList->getName ();
            size_t index = mesh->getColorIndexByName ( colorInputName );

            const COLLADAFW::MeshVertexData& meshColors = mesh->getColors ();
            polyFace.mc[i].colorSet = (int) index;
            polyFace.mc[i].faceColorCount = numEdges;
            polyFace.mc[i].colorIdValue = new int [numEdges];

            for ( int j=0; j<numEdges; ++j )
            {
                size_t currentIndexPosition = j + colorIndicesIndex;
                unsigned int currentIndex = indexList->getIndex ( currentIndexPosition );
                // Decrement the index values
                size_t initialIndex = indexList->getInitialIndex ();
                polyFace.mc[i].colorIdValue [j] = currentIndex - initialIndex;
            }
        }
        // Increment the current uv set index for the number of edges.
        colorIndicesIndex += numEdges;
    }

    // --------------------------------------------
    COLLADABU::Math::Vector3* GeometryImporter::getVertexPosition ( 
        const COLLADAFW::Mesh* mesh , 
        const size_t vertexIndex )
    {
        // Get the points of the current edge.
        const COLLADAFW::MeshVertexData& meshPositions = mesh->getPositions ();

        // Get the vertex position values of the start position of the current edge.
        double dx, dy, dz; 
        if ( meshPositions.getType () == COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT )
        {
            dx = (double)((*(meshPositions.getFloatValues ()))[(vertexIndex*3)]);
            dy = (double)((*(meshPositions.getFloatValues ()))[(vertexIndex*3)+1]);
            dz = (double)((*(meshPositions.getFloatValues ()))[(vertexIndex*3)+2]);
        }
        else if ( meshPositions.getType () == COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE )
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

    // --------------------------------------------
    const MayaNode* GeometryImporter::getMayaMeshNode ( const COLLADAFW::UniqueId& uniqueId ) const
    {
        UniqueIdMayaNodesMap::const_iterator it = mMayaMeshNodesMap.find ( uniqueId );
        if ( it != mMayaMeshNodesMap.end () )
            return &(*it).second;

        return NULL;
    }

    // --------------------------------------------
    MayaNode* GeometryImporter::getMayaMeshNode ( const COLLADAFW::UniqueId& uniqueId )
    {
        UniqueIdMayaNodesMap::iterator it = mMayaMeshNodesMap.find ( uniqueId );
        if ( it != mMayaMeshNodesMap.end () )
            return &(*it).second;

        return NULL;
    }

}