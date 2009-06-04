/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADAMayaException.h"
#include "COLLADAMayaVisualSceneImporter.h"
#include "COLLADAMayaImportOptions.h"
#include "COLLADAMayaControllerImporter.h"


#include <maya/MFnMesh.h>
#include <maya/MFnTransform.h>
#include <maya/MDagModifier.h>

#pragma warning(disable:4172)

#include "MayaDMTransform.h"
#include "MayaDMCommands.h"

#include "COLLADAFWPolygons.h"
#include "COLLADAFWTrifans.h"
#include "COLLADAFWTristrips.h"
#include "COLLADAFWEdge.h"


namespace COLLADAMaya
{
    
    const String GeometryImporter::GEOMETRY_NAME = "Geometry";


    // --------------------------------------------
    GeometryImporter::GeometryImporter( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
    {}

    // --------------------------------------------
    GeometryImporter::~GeometryImporter ()
    {
        UniqueIdMayaNodeMap::iterator it = mMayaMeshNodesMap.begin ();
        while ( it != mMayaMeshNodesMap.end () )
        {
            MayaNode* mayaNode = it->second;
            delete mayaNode;
            ++it;
        }
        mMayaMeshNodesMap.clear ();
    }

    // --------------------------------------------
    void GeometryImporter::importGeometry ( const COLLADAFW::Geometry* geometry )
    {
        if ( geometry == 0 ) return;

        // Check if the current geometry is already imported.
        const COLLADAFW::UniqueId& geometryId = geometry->getUniqueId ();
        if ( findMayaMeshNode ( geometryId ) != 0 ) return;

        COLLADAFW::Geometry::GeometryType type = geometry->getType ();
        switch ( type )
        {
        case COLLADAFW::Geometry::GEO_TYPE_CONVEX_MESH:
            std::cerr << "Import of convex_mesh not supported!" << std::endl;
            MGlobal::displayError ( "Import of convex_mesh not supported!" );
            return;
        case COLLADAFW::Geometry::GEO_TYPE_SPLINE:
            std::cerr << "Import of spline not supported!" << std::endl;
            MGlobal::displayError ( "Import of spline not supported!" );
            return;
        case COLLADAFW::Geometry::GEO_TYPE_MESH:
            {
                COLLADAFW::Mesh* mesh = ( COLLADAFW::Mesh* ) geometry;

                // Import the mesh data, if it is referenced from a transform node.
                importMesh ( mesh );

                // Import the mesh data, if the geometry is referenced from a transform node.
                bool meshImported = importMesh ( mesh );

                // If a skinControllerData object is referenced from multiple controllers,
                // just the first one has to create the original mesh object.

                // Import the controller mesh data, if the mesh is referenced from a controller.
                importController ( mesh, meshImported );

                break;
            }
        default:
            return;
        }

        return;
    }

    // --------------------------------------------
    void GeometryImporter::importController ( 
        const COLLADAFW::Mesh* mesh, 
        bool meshAlreadyImported )
    {
        // Get the unique id.
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();

        // Check, if the mesh is referenced from a controller object.
        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
        const std::vector<COLLADAFW::SkinController*>* skinControllers = controllerImporter->findSkinControllersBySourceId ( geometryId );
        if ( skinControllers == 0 ) return;

        for ( size_t i=0; i<skinControllers->size (); ++i )
        {
            // Every skin controller needs his own controller mesh object. All connections of 
            // skinController elements, materials and groups will be done directly to this mesh.
            // The original mesh geometry object has to be created just once, either as an intermediate
            // object or, if it is referenced from an instance geometry, directly as normal mesh.
            const COLLADAFW::SkinController* skinController = (*skinControllers) [i];

            // Create an original mesh object under the transform node of the skin controller.
            const COLLADAFW::UniqueId& controllerId = skinController->getUniqueId ();

            // Get the node instances.
            VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
            const UniqueIdVec* controllerTransformIds = visualSceneImporter->findControllerTransformIds ( controllerId );
            if ( controllerTransformIds == 0 ) continue;

            // Make the mesh instances and import the mesh data.
            importMesh ( mesh, controllerTransformIds, &controllerId, meshAlreadyImported );
            meshAlreadyImported = true;
        }
    }

    // --------------------------------------------
    bool GeometryImporter::importMesh ( const COLLADAFW::Mesh* mesh )
    {
        // Get the unique framework mesh id 
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();

        // Get the transform node(s) of the current mesh.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const UniqueIdVec* transformNodeIds = visualSceneImporter->findGeometryTransformIds ( geometryId );
        if ( transformNodeIds == 0 ) return false;

        // Make the mesh instances and import the mesh data.
        importMesh ( mesh, transformNodeIds );

        return true;
    }

    // --------------------------------------------
    void GeometryImporter::importMesh ( 
        const COLLADAFW::Mesh* mesh, 
        const UniqueIdVec* transformNodeIds, 
        const COLLADAFW::UniqueId* controllerId /*= 0*/,
        const bool meshAlreadyImported /*= false*/ )
    {
        // Get the node instances.
        UniqueIdVec::const_iterator nodesIter = transformNodeIds->begin ();
        size_t numNodeInstances = transformNodeIds->size ();

        // The index value of the current geometry instance.
        size_t geometryInstanceIndex = 0;

        // Go through the node instances and create / instance the mesh. 
        while ( nodesIter != transformNodeIds->end () )
        {
            // Get the maya node of the current transform node.
            const COLLADAFW::UniqueId& transformNodeId = *nodesIter;
            VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
            MayaNodesList* transformNodes = visualSceneImporter->findMayaTransformNode ( transformNodeId );
            if ( transformNodes->size () == 0 )
            {
                MGlobal::displayError ( "The referenced transform node doesn't exist!" );
                std::cerr << "The referenced transform node doesn't exist!" << endl;
                return;
            }
            MayaNode* mayaTransformNode = (*transformNodes) [0];
            String transformNodeName = mayaTransformNode->getName ();

            // Get the path to the parent transform node.
            String transformNodePath = mayaTransformNode->getNodePath ();

            // The first reference is a direct one, the others are instances.
            if ( nodesIter == transformNodeIds->begin() )
            {
                // Create the current mesh node.
                createMesh ( mesh, mayaTransformNode, controllerId, meshAlreadyImported );
            }
            else
            {
                // Make the parent connections.
                const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
                MayaNode* mayaMeshNode = findMayaMeshNode ( geometryId );
                String meshNodePath = mayaMeshNode->getNodePath ();

                // parent -shape -noConnections -relative -addObject "|pCube1|pCubeShape1" "pCube2";
                FILE* file = getDocumentImporter ()->getFile ();
                MayaDM::parentShape ( file, meshNodePath, transformNodePath, false, true, true, true );
            }

            // Create maya groupId objects for every mesh primitive (if there is more than one).
            // This method is called for every geometry instance.
            createGroupNodes ( mesh, transformNodeId, geometryInstanceIndex, controllerId );

            ++nodesIter;
        }
    }

    // --------------------------------------------
    void GeometryImporter::createMesh ( 
        const COLLADAFW::Mesh* mesh, 
        MayaNode* mayaTransformNode, 
        const COLLADAFW::UniqueId* controllerId /*= 0*/, 
        const bool meshAlreadyImported /*= false*/ )
    {
        // Create a unique name.
        String meshName = mesh->getName ();
        if ( COLLADABU::Utils::equals ( meshName, "" ) ) 
            meshName = GEOMETRY_NAME;
        meshName = DocumentImporter::frameworkNameToMayaName ( meshName );
        meshName = mMeshNodeIdList.addId ( meshName );

        // TODO
        // Add the name also to the id list of the materials, about the name of a material 
        // can't be the same as the name of a geometry or a node.

        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the parent transform node name.
        const COLLADAFW::UniqueId& transformNodeId = mayaTransformNode->getUniqueId ();
        String transformNodePath = mayaTransformNode->getNodePath ();

        // Get the unique object id.
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();

        // Create a maya node object of the current node and push it into the map.
        MayaNode* mayaMeshNode = new MayaNode ( geometryId, meshName, mayaTransformNode );
        mMayaMeshNodesMap [ geometryId ] = mayaMeshNode;

        // We just need a MeshControllerData element, if we have a mesh controller object
        // to store the information of the controllerId, geometryId and transformId with the 
        // combination of the original mesh node object and the controller mesh object.
        MeshControllerData meshControllerData;

        // Create the controller mesh object first.
        if ( controllerId )
        {
            meshControllerData.setControllerId ( *controllerId );
            meshControllerData.setGeometryId ( geometryId );
            meshControllerData.setTransformId ( transformNodeId );

            // Create the mesh node - no special settings...
            MayaDM::Mesh controllerMeshNode ( file, meshName, transformNodePath );
            meshControllerData.setControllerMeshNode ( controllerMeshNode );

            // Check if the original mesh is already created. If not, we have to create it 
            // here as a intermediate object, otherwise we can return here.
            if ( meshAlreadyImported ) 
            {
                // Get the original mesh node from the list of maya mesh nodes.
                MayaDM::Mesh* originalMeshNode = findMayaDMMeshNode ( geometryId );
                meshControllerData.setOriginalMeshNode ( *originalMeshNode );

                // Store the meshControllerData object.
                mMeshControllerDataList.push_back ( meshControllerData );

                // The original mesh is already created, we can leave the creation.
                return;
            }

//             // Push the controller mesh node in the list of mayaDMMeshNodes.
//             mMayaDMMeshNodesMap [geometryId] = controllerMeshNode;

            // Create the original mesh as an intermediate object.
            meshName += "Orig";
            meshName = mMeshNodeIdList.addId ( meshName );
        }

        // Create the current maya data model mesh node.
        MayaDM::Mesh meshNode ( file, meshName, transformNodePath );
        mMayaDMMeshNodesMap [geometryId] = meshNode;

        if ( controllerId )
        {
            // Handle a mesh which is instanced from a controller object.
            // Boolean attribute that specifies whether the dagNode is an intermediate object resulting 
            // from a construction history operation. dagNodes with this attribute set to true are not 
            // visible and/or rendered.
            meshNode.setIntermediateObject ( true );

            // Set the original mesh data.
            meshControllerData.setOriginalMeshNode ( meshNode );

            // Store the meshControllerData object.
            mMeshControllerDataList.push_back ( meshControllerData );
        }

        // Add the original id attribute.
        String colladaId = mesh->getOriginalId ();
        if ( !COLLADABU::Utils::equals ( colladaId, "" ) )
        {
            MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string" );
            MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, "", "string", colladaId );
        }

        // Writes the object groups for every mesh primitive and
        // gets all shader engines, which are used by the primitive elements of the mesh.
        writeObjectGroups ( mesh, meshNode, transformNodeId );

        // Write the vertex positions. 
        writeVertexPositions ( mesh, meshNode );

        // Write the normals. 
        if ( ImportOptions::importNormals () )
            writeNormals ( mesh, meshNode );

        // Write the uv corrdinates.
        writeUVSets ( mesh, meshNode );

        // Write the uv corrdinates.
        writeColorSets ( mesh, meshNode );

        // The vector of edge indices. We use it to write the list of edges into 
        // the maya file. The vector is already sorted.
        std::vector<COLLADAFW::Edge> edgeIndices;

        // We store the edge indices also in a sorted map. The dublicate data holding 
        // is reasonable, because we need the index of a given edge. The search of  
        // values in a map is much faster than in a vector!
        std::map<COLLADAFW::Edge,size_t> edgeIndicesMap;

        // Iterates over the mesh primitives and reads the edge indices.
        getEdgeIndices ( mesh, edgeIndices, edgeIndicesMap );

        // Write the edge indices of all primitive elements into the maya file.
        writeEdges ( mesh, edgeIndices, meshNode );

        // Write the face informations of all primitive elements into the maya file.
        writeFaces ( mesh, edgeIndicesMap, meshNode );

        // Fills the PrimitivesMap and the ShadingEnginePrimitivesMap. 
        // Used to create the connections between the shading engines and the geometries.
        setMeshPrimitiveShadingEngines ( mesh );
    }

    // --------------------------------------------
    void GeometryImporter::createGroupNodes ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::UniqueId& transformNodeId, 
        size_t& geometryInstanceIndex,
        const COLLADAFW::UniqueId* controllerId /*= 0*/ )
    {
        // This method is called for every geometry instance.

        // The maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the unique id of the current geometry.
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();

        // Look for a list of componentLists of the current geometry.
        const std::vector<MayaDM::componentList>* componentLists = findComponentLists ( geometryId );
        size_t componentListsCount = 0;
        if ( componentLists ) componentListsCount = componentLists->size ();

        // Create a group for every mesh primitive of every instanciated geometry 
        // and every transform instance, which has a reference to the geometry.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();

        // Get the number of transform node instances.
        size_t numTransformInstances = visualSceneImporter->getNumTransformInstances ( transformNodeId );

        // Iterate over the instances and create the group nodes.
        for ( size_t transformInstanceIndex=0; transformInstanceIndex<numTransformInstances; ++transformInstanceIndex )
        {
            // We have to go through every mesh primitive.
            const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mesh->getMeshPrimitives ();
            size_t meshPrimitivesCount = meshPrimitives.getCount ();

            // We don't need to create groups if we just have one primitive.
            if ( meshPrimitivesCount <= 1 ) return;
            if ( meshPrimitivesCount != componentListsCount )
            {
                std::cerr << "No component lists generated for the current geometry's primitives!" << endl;
                return;
            }

            // Create a group for every primitive.
            for ( size_t primitiveIndex=0; primitiveIndex<meshPrimitivesCount; ++primitiveIndex )
            {
                // Get the current mesh primitive shader id
                const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives [primitiveIndex];
                const COLLADAFW::MaterialId shadingEngineId = meshPrimitive->getMaterialId ();

                // Assign the group to the unique geometry id, the transform node 
                // to the mesh instance and the index of the geometry's primitives.
                ShadingBinding shadingBinding ( geometryId, transformNodeId, shadingEngineId, controllerId );

                // Create the maya groupId object 
                String groupName = getDocumentImporter ()->getGroupIdIdList ().addId ( GROUP_ID_NAME, true, true );
                MayaDM::GroupId groupId ( file, groupName );
                groupId.setIsHistoricallyInteresting (0);

                // Create a groupInfo object and push it in the map of shading binding groupInfos.
                GroupInfo groupInfo ( groupId, shadingEngineId, transformInstanceIndex, primitiveIndex );

                // If we have a controller element, we need also groupParts to manage the group objects.
                ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
                bool hasController = ( controllerImporter->findSkinControllersBySourceId ( geometryId ) != 0 );
                if ( hasController )
                {
                    String groupPartsName = getDocumentImporter ()->getGroupPartsIdList ().addId ( GROUP_PARTS_NAME, true, true );
                    MayaDM::GroupParts groupParts ( file, groupPartsName );

                    // Get the component list of the geometry's primitive element, which contains 
                    // the string with the face informations for the component list.
                    MayaDM::componentList componentList = (*componentLists) [primitiveIndex];

                    // setAttr ".inputComponents" -type "componentList" 1 "f[0:5]";
                    groupParts.setInputComponents ( componentList );

                    // Set the groupParts object.
                    groupInfo.setGroupParts ( groupParts );
                }

                // Push the groupInfo object in the map of shading binding groupInfos.
                mShadingBindingGroupMap [shadingBinding].push_back ( groupInfo );
            }

            ++geometryInstanceIndex;
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeObjectGroups ( 
        const COLLADAFW::Mesh* mesh, 
        MayaDM::Mesh &meshNode,
        const COLLADAFW::UniqueId& transformNodeId )
    {
        // Create the object group instances and the object groups and write it into the maya file.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();

        // setAttr -size 2 ".instObjGroups"; // for every instance
        // setAttr -size 2 ".instObjGroups[0].objectGroups"; // for every mesh primitive
        // setAttr ".instObjGroups[0].objectGroups[0].objectGrpCompList" -type "componentList" 1 "f[0:5]";
        // setAttr ".instObjGroups[0].objectGroups[1].objectGrpCompList" -type "componentList" 1 "f[6:11]";

        // We have to go through every mesh primitive.
        const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mesh->getMeshPrimitives ();
        size_t meshPrimitivesCount = meshPrimitives.getCount ();

        // We don't need this, if we have just one primitive.
        if ( meshPrimitivesCount <= 1 ) return;

        // For every geometry instance
        //  For every transform instance
        //      For every mesh primitive 
        //          addAttr (objectGrpCompList)

        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
        size_t globalInstanceCount = 0;

        // Count the geometry instances.
        const UniqueIdVec* geometryInstanceTransformIds = visualSceneImporter->findGeometryTransformIds ( geometryId );
        if ( geometryInstanceTransformIds )
        {
            size_t numGeometryInstancesTransformIds = geometryInstanceTransformIds->size ();
            for ( size_t n=0; n<numGeometryInstancesTransformIds; ++n )
            {
                // Count the transform node instances, which have the geometry as a child.
                const COLLADAFW::UniqueId& currentTransformNodeId = (*geometryInstanceTransformIds) [n];
                size_t numTransformNodeInstances = visualSceneImporter->getNumTransformInstances ( currentTransformNodeId );
                globalInstanceCount += numTransformNodeInstances;
            }
        }

        // Iterate over the mesh primitives
        size_t initialFaceIndex = 0;
        for ( size_t i=0; i<meshPrimitivesCount; ++i )
        {
            // Get the number of faces of the current primitive element.
            const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives [ i ];

            // TODO Is this also with trifans, etc. the right number???
//            size_t numFaces = meshPrimitive->getGroupedVertexElementsCount ();
            size_t numFaces = meshPrimitive->getFaceCount ();

//             COLLADAFW::Trifans* trifans = (COLLADAFW::Trifans*) primitiveElement;
//             COLLADAFW::Trifans::VertexCountArray& vertexCountArray = 
//                trifans->getGroupedVerticesVertexCountArray ();
//             size_t faceCount2 = meshPrimitive->getGroupedVerticesVertexCount (i);

            // Create the string with the face informations for the component list.
            String val = "f[" + COLLADABU::Utils::toString ( initialFaceIndex ) 
                + ":" + COLLADABU::Utils::toString ( numFaces-1 + initialFaceIndex ) + "]";

            // Create the component list.
            MayaDM::componentList componentList;
            componentList.push_back ( val );

            // Set the component list in the list of components of the current mesh
            // (will be needed for the organisation of the material groups in groupParts), 
            // if we use a controller element, which also handles groups).
            mMeshComponentLists [geometryId].push_back ( componentList );

            // Increment the initial face index.
            initialFaceIndex += numFaces;

            // Iterate over the object instances.
            for ( size_t j=0; j<globalInstanceCount; ++j )
            {
                // Write instance object group component list data into the file.
                meshNode.setObjectGrpCompList ( j, i, componentList );
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::setMeshPrimitiveShadingEngines ( const COLLADAFW::Mesh* mesh )
    {
        // Get the geometry id.
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();

        // We have to go through every mesh primitive.
        const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mesh->getMeshPrimitives ();
        size_t meshPrimitivesCount = meshPrimitives.getCount ();

        // Push the number of primitive elements to the geometry in the map.
        mGeometryIdPrimitivesCountMap [geometryId] = meshPrimitivesCount;

        // Iterate over the mesh primitive elements and set the shading engines.
        for ( size_t primitiveIndex=0; primitiveIndex<meshPrimitivesCount; ++primitiveIndex )
        {
            // Get the current primitive element.
            const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives [ primitiveIndex ];

            // Get the shader engine id.
            String shadingEngineName = meshPrimitive->getMaterial ();
            COLLADAFW::MaterialId shadingEngineId = meshPrimitive->getMaterialId ();

            // Fills the ShadingEnginePrimitivesMap. Used to create the connections between the 
            // shading engines and the geometries.
            // The map holds for every geometry's shading engine a list of the index values of the 
            // geometry's primitives. 
            setShadingEnginePrimitiveIndex ( geometryId, shadingEngineId, primitiveIndex );
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeVertexPositions ( 
        const COLLADAFW::Mesh* mesh, 
        MayaDM::Mesh &meshNode )
    {
        // We have always a stride of three (x, y and z values)
        size_t stride = 3;

        const COLLADAFW::MeshVertexData& positions = mesh->getPositions ();
        if ( positions.getValuesCount () == 0 ) return;

        size_t count = positions.getValuesCount ();
        size_t numVertices = (count/stride)-1;

        // Write blocks with 4000KB for maya.
        size_t blockSize = MAYA_BLOCK_SIZE / ( 3* sizeof ( double ) );
        size_t endPosition;

        COLLADABU::Math::Vector3 converted;

        for ( size_t i=0, index=0; i<count; i+=stride, ++index )
        {
            // Start the block if necessary.
            if ( index % blockSize == 0 )
            {
                endPosition = index+blockSize-1;
                if ( endPosition > numVertices ) endPosition = numVertices;
                meshNode.startVrts ( index, endPosition ); 
            }

            const COLLADAFW::MeshVertexData::DataType type = positions.getType ();
            switch ( type )
            {
            case COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT:
                {
                    const COLLADAFW::ArrayPrimitiveType<float>* values = positions.getFloatValues ();
                    toLinearUnit ( (*values)[i], (*values)[i+1], (*values)[i+2], converted );
                }
                break;
            case COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE:
                {
                    const COLLADAFW::ArrayPrimitiveType<double>* values = positions.getDoubleValues ();
                    toLinearUnit ( (*values)[i], (*values)[i+1], (*values)[i+2], converted );
                }
                break;
            default:
                std::cerr << "No valid data type for positions: " << type << std::endl;
                MGlobal::displayError ( "No valid data type for positions: " + type );
                assert ( "No valid data type for positions: " + type );
            }

            meshNode.appendVrts ( (float)converted[0] );
            meshNode.appendVrts ( (float)converted[1] );
            meshNode.appendVrts ( (float)converted[2] );

            // End the block if necessary.
            if ( index == endPosition ) 
                meshNode.endVrts (); 
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeNormals ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode )
    {
        // Count the number of normals to write into the maya file.
        size_t numNormals = mesh->getNormalsCount ();

        // Write the normals into the maya file.
        if ( numNormals <= 0 ) return;

        // Write blocks with 4000KB for maya
        size_t blockSize = MAYA_BLOCK_SIZE / ( 3* sizeof ( double ) );
        size_t endPosition = 0, index = 0; 

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
            for ( size_t j=0; j<indexCount; ++j, ++index )
            {
                // Get the index of the current normal.
                unsigned int normalIndex = normalIndices [ j ];

                // Get the position in the values list to read.
                unsigned int pos = normalIndex * (unsigned int)stride;

                // Start the block if necessary.
                if ( index % blockSize == 0 )
                {
                    endPosition = index+blockSize-1;
                    if ( endPosition > numNormals-1 ) endPosition = numNormals-1;
                    meshNode.startNormals ( index, endPosition ); 
                }
                
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
                    MGlobal::displayError ( "No valid data type for normals: " + type );
                    assert ( "No valid data type for normals: " + type );
                }

                // End the block if necessary.
                if ( index == endPosition ) 
                    meshNode.endNormals (); 
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeUVSets ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode )
    {
        // Set the number of uv sets.
        const COLLADAFW::MeshVertexData& uvCoords = mesh->getUVCoords ();
        size_t numUVSets = uvCoords.getNumInputInfos ();
        if ( numUVSets == 0 ) return;
        meshNode.setUvSize ( (double)numUVSets );

        // Write blocks with 4000KB for maya
        size_t blockSize = MAYA_BLOCK_SIZE / ( 2* sizeof ( double ) );
        
        // Go through the uv sets.
        for ( size_t i=0; i<numUVSets; ++i )
        {
            // Set the name of the current uv set.
            String uvSetName = uvCoords.getName ( i );
            meshNode.setUvSetName ( i, uvSetName );
            if ( i == 0 ) meshNode.setCurrentUVSet ( uvSetName );

            size_t stride = uvCoords.getStride ( i );
            assert ( stride > 1 && stride <= 4 );
            if ( stride != 2 ) 
                MGlobal::displayWarning ( "Just 2d uv set data will be imported! ");

            size_t indicesCount = uvCoords.getLength ( i );
            size_t numUvSetPoints = (indicesCount/stride)-1;
            size_t endPosition = 0, index=0; 
            size_t initialIndex = 0;

            for ( size_t j=0; j<indicesCount; j+=stride, ++index )
            {
                // Start the block if necessary
                if ( index % blockSize == 0 )
                {
                    endPosition = index+blockSize-1;
                    if ( endPosition > numUvSetPoints ) endPosition = numUvSetPoints;
                    meshNode.startUvSetPoints ( i, index, endPosition ); 
                }

                // Write the values 
                const COLLADAFW::MeshVertexData::DataType type = uvCoords.getType ();
                switch ( type )
                {
                case COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT:
                    {
                        const COLLADAFW::ArrayPrimitiveType<float>* values = uvCoords.getFloatValues ();
                        meshNode.appendUvSetPoints ( (*values)[initialIndex+j] );
                        meshNode.appendUvSetPoints ( (*values)[initialIndex+j+1] );
                    }
                    break;
                case COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE:
                    {
                        const COLLADAFW::ArrayPrimitiveType<double>* values = uvCoords.getDoubleValues ();
                        meshNode.appendUvSetPoints ( (float) (*values)[initialIndex+j] );
                        meshNode.appendUvSetPoints ( (float) (*values)[initialIndex+j+1] );
                    }
                    break;
                default:
                    std::cerr << "No valid data type for uv coordinates: " << type << std::endl;
                    MGlobal::displayError ( "No valid data type for uv coordinates: " + type );
                    assert ( "No valid data type for uv coordinates: " + type );
                }

                // End the block if necessary.
                if ( index == endPosition ) 
                    meshNode.endUvSetPoints (); 
            }

            initialIndex += indicesCount;
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeColorSets ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode )
    {
        // Set the number of uv sets.
        const COLLADAFW::MeshVertexData& colors = mesh->getColors ();
        size_t numColorSets = colors.getNumInputInfos ();
        if ( numColorSets == 0 ) return;
//        meshNode.setColorSetSize ( sumUVSetPoints );

        size_t initialIndex = 0;

        // Write blocks with 4000KB for maya
        size_t blockSize = MAYA_BLOCK_SIZE / ( 4* sizeof ( double ) );

        // Go through the color sets.
        for ( size_t c=0; c<numColorSets; ++c )
        {
            // Set the name of the current color set.
            String colorName = colors.getName ( c );
            meshNode.setColorName ( c, colorName );
            if ( c == 0 ) meshNode.setCurrentColorSet ( colorName );

            size_t stride = colors.getStride ( c );
            assert ( stride == 1 || stride == 3 || stride <= 4 );

            unsigned int representation = 2; // RGBA = 2 DEFAULT
            if ( stride == 1 ) representation = 1; // A = 1
            else if ( stride == 3 ) representation = 3; // RGB = 3
            meshNode.setRepresentation ( c, representation );

            size_t indicesCount = colors.getLength ( c );
            size_t numColorSetPoints = (indicesCount/stride)-1;
            size_t endPosition = 0, index=0; 
            
            for ( size_t i=0; i<indicesCount; i+=stride, ++index )
            {
                // Start the block if necessary
                if ( index % blockSize == 0 )
                {
                    endPosition = index+blockSize-1;
                    if ( endPosition > numColorSetPoints ) endPosition = numColorSetPoints;
                    meshNode.startColorSetPoints ( c, index, endPosition ); 
                }

                for ( size_t j=0; j<stride; ++j ) 
                {
                    // Write the values 
                    const COLLADAFW::MeshVertexData::DataType type = colors.getType ();
                    switch ( type )
                    {
                    case COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT:
                        {
                            const COLLADAFW::ArrayPrimitiveType<float>* values = colors.getFloatValues ();
                            meshNode.appendColorSetPoints ( (*values)[initialIndex+i+j] );
                        }
                        break;
                    case COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE:
                        {
                            const COLLADAFW::ArrayPrimitiveType<double>* values = colors.getDoubleValues ();
                            meshNode.appendColorSetPoints ( ( float ) (*values)[initialIndex+i+j] );
                        }
                        break;
                    default:
                        std::cerr << "No valid data type for colors: " << type << std::endl;
                        MGlobal::displayError ( "No valid data type for colors: " + type );
                        assert ( "No valid data type for colors: " + type );
                    }
                }

                // End the block if necessary.
                if ( index == endPosition ) 
                    meshNode.endColorSetPoints (); 
            }

            initialIndex += indicesCount;
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeEdges (  
        const COLLADAFW::Mesh* mesh, 
        const std::vector<COLLADAFW::Edge> &edgeIndices, 
        MayaDM::Mesh &meshNode )
    {
        size_t numEdges = edgeIndices.size ();
        if ( numEdges > 0 )
        {
            // We always have per vertex normals.
            // With normals, it doesn't matter if we have hard or soft edges, 
            // because the normals make the edge smoothing.
            int edgh = 1;
            if ( !ImportOptions::importSoftEdges () )
            {
                edgh = 0;
            }
            
            // Without normals, we need to use soft edges (1) (per vertex normals),
            // with normals, we have to use hard edges (0) (per face normals).
//             if ( mesh->getNormalsCount () > 0 )
//                 edgh = 0;

            
            // Write blocks with 4000KB for maya
            size_t blockSize = MAYA_BLOCK_SIZE / ( 3* sizeof ( double ) );
            size_t endPosition = 0, index=0; 
            
            // Go through the edges and write them.
            for ( size_t index=0; index<numEdges; ++index )
            {
                // Start the block if necessary
                if ( index % blockSize == 0 )
                {
                    endPosition = index+blockSize-1;
                    if ( endPosition > numEdges-1 ) endPosition = numEdges-1;
                    meshNode.startEdge ( index, endPosition ); 
                }
                
                const COLLADAFW::Edge& edge = edgeIndices [index];
                meshNode.appendEdge ( edge[0] );
                meshNode.appendEdge ( edge[1] );
                meshNode.appendEdge ( edgh );
                
                // End the block if necessary.
                if ( index == endPosition ) 
                    meshNode.endEdge (); 
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeFaces ( 
        const COLLADAFW::Mesh* mesh, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::Mesh &meshNode )
    {
        // Get the number of faces in the current mesh.
        size_t numGlobalFaces = mesh->getFacesCount ();
        if ( numGlobalFaces <= 0 ) return;

        // Go through the primitive elements and write the face values.
        const COLLADAFW::MeshPrimitiveArray& primitiveElementsArray = mesh->getMeshPrimitives ();
        size_t count = primitiveElementsArray.getCount ();

        // Write blocks with 4000KB for maya
        size_t blockSize = 500; //MAYA_BLOCK_SIZE / ( 3* sizeof ( double ) );
        size_t endPosition = 0; 
        size_t globalFaceIndex = 0;

        // Determine the face values.
        for ( size_t index=0; index<count; ++index )
        {
            // Get the primitive element.
            COLLADAFW::MeshPrimitive* primitiveElement = primitiveElementsArray [ index ];

            // Write the face informations into the maya file.
            COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = primitiveElement->getPrimitiveType ();
            switch ( primitiveType )
            {
            case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
                appendTrifansPolyFaces ( mesh, primitiveElement, edgeIndicesMap, meshNode, blockSize, numGlobalFaces, globalFaceIndex, endPosition );
                break;
            case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
                appendTristripsPolyFaces ( mesh, primitiveElement, edgeIndicesMap, meshNode, blockSize, numGlobalFaces, globalFaceIndex, endPosition );
                break;
            case COLLADAFW::MeshPrimitive::POLYGONS:
            case COLLADAFW::MeshPrimitive::POLYLIST:
            case COLLADAFW::MeshPrimitive::TRIANGLES:
                appendPolygonPolyFaces ( mesh, primitiveElement, edgeIndicesMap, meshNode, blockSize, numGlobalFaces, globalFaceIndex, endPosition );
                break;
            default:
                std::cerr << "Primitive type not implemented!" << std::endl;
                MGlobal::displayError ( "Primitive type not implemented!" );
                assert ( "Primitive type not implemented!");
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::appendPolygonPolyFaces ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::Mesh &meshNode,
        const size_t blockSize, 
        const size_t numGlobalFaces, 
        size_t& globalFaceIndex, 
        size_t& endPosition )
    {
        size_t positionIndex=0;
        size_t uvSetIndicesIndex = 0;
        size_t colorIndicesIndex = 0;

        // The number of grouped vertex elements (faces, holes, tristrips or trifans).
        int groupedVtxCount = primitiveElement->getGroupedVertexElementsCount ();
        if ( groupedVtxCount < 0 ) groupedVtxCount *= (-1);

        // To handle polygons with holes:
        // Flag, if the actual face is clockwise orientated. We need this information to handle
        // polygons with holes, because this need the opposite direction of their polygons. 
        bool faceClockwiseOriented = true;

        // Polygons with holes: we have always first one polygon for any number of holes.
        // We need the first three vertexes to determine the orientation of any polygon.
        std::vector<COLLADABU::Math::Vector3*> polygonPoints;

        // Iterate over all grouped vertex elements (faces, holes, tristrips or trifans)
        // and determine the values for the maya polyFace object.
        for ( int groupedVtxIndex=0; groupedVtxIndex<groupedVtxCount; ++groupedVtxIndex )
        {
            // The number of edges is always the same than the number of vertices in the current 
            // grouped vertices object. If the number is negative, the grouped object is a hole.
            int numEdges = primitiveElement->getGroupedVerticesVertexCount ( (size_t)groupedVtxIndex );

            // Create the poly face
            MayaDM::polyFaces polyFace;

            // Handle the face infos.
            bool isHole = (numEdges<0);
            if ( !isHole )
                setPolygonFaceInfos ( mesh, primitiveElement, edgeIndicesMap, polyFace, numEdges, positionIndex, polygonPoints );
            else
                setPolygonHoleInfos ( mesh, primitiveElement, edgeIndicesMap, polyFace, numEdges, positionIndex, polygonPoints );

            // Handle the uv set infos.
            setUVSetInfos ( mesh, primitiveElement, polyFace, uvSetIndicesIndex, numEdges );

            // Handle the color infos.
            setColorInfos ( mesh, primitiveElement, polyFace, colorIndicesIndex, numEdges );

            // Start the block if necessary (Maya doesn't count hole elements, about this,
            // if the current element is a hole, don't start, except it is the very first element!)
            if ( globalFaceIndex % blockSize == 0 )
            {
                if ( !isHole )
                {
                    endPosition = globalFaceIndex+blockSize-1;
                    if ( endPosition > numGlobalFaces-1 ) 
                        endPosition = numGlobalFaces-1;
                    meshNode.startFace ( globalFaceIndex, endPosition ); 
                }
            }

            // Write the polyFace data in the maya file.
            meshNode.appendFace ( polyFace );

            // Check if the next element is a hole.
            bool nextElementIsHole = false;
            if ( groupedVtxIndex+1 < groupedVtxCount )
            {
                int nextElementNumEdges = primitiveElement->getGroupedVerticesVertexCount ( (size_t)groupedVtxIndex+1 );
                nextElementIsHole = (nextElementNumEdges<0);
            }

            // End the block if necessary (if the next element is a hole, don't close).
            if ( globalFaceIndex == endPosition && !nextElementIsHole ) 
                meshNode.endFace (); 

            // Increment the face index (if it is not a hole, this will not be counted).
            if ( !nextElementIsHole )
                ++globalFaceIndex;
        }

        // Delete the points.
        size_t pSize = polygonPoints.size ();
        for ( size_t i=0; i<pSize; ++i) 
            delete polygonPoints [i];
        polygonPoints.clear ();
    }

    // --------------------------------------------
    void GeometryImporter::appendTrifansPolyFaces ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::Mesh &meshNode,
        const size_t blockSize, 
        const size_t numGlobalFaces, 
        size_t& globalFaceIndex, 
        size_t& endPosition )
    {
        // Get the position indices.
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // The points of an edge
        int edgeStartVtxIndex=0, edgeEndVtxIndex=0;

        // The current index in the positions list.
        size_t initialPositionIndex=0;
        size_t positionIndex=0;

        size_t uvSetIndicesIndex = 0;
        size_t colorIndicesIndex = 0;

        // Iterate over the grouped vertices and get the edges for every group.
        COLLADAFW::Trifans* trifans = (COLLADAFW::Trifans*) primitiveElement;
        COLLADAFW::Trifans::VertexCountArray& vertexCountArray = trifans->getGroupedVerticesVertexCountArray ();
        size_t groupedVtxCount = vertexCountArray.getCount ();
        for ( size_t groupedVtxIndex=0; groupedVtxIndex<groupedVtxCount; ++groupedVtxIndex )
        {
            // Create the poly face
            MayaDM::polyFaces polyFace;

            // A trifan has always triangles, which have 3 edges
            size_t triangleEdgeCounter = 0;

            // The number of vertices in the current vertex group.
            unsigned int vertexCount = vertexCountArray [groupedVtxIndex];

            // Determine the number of edges and iterate over it.
            unsigned int numEdges = ( vertexCount - 3 ) * 3 + 3;
            for ( unsigned int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
            {
                if ( triangleEdgeCounter == 0 )
                {
                    // Handle the edge informations.
                    polyFace.f.faceEdgeCount = 3;
                    polyFace.f.edgeIdValue = new int[3];
                }

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

                // Set the edge vertex index values into an edge object.
                COLLADAFW::Edge edge ( edgeStartVtxIndex, edgeEndVtxIndex );

                // Variable for the current edge index.
                int edgeIndexValue;

                // Get the edge index value from the edge list.
                getEdgeIndex ( edge, edgeIndicesMap, edgeIndexValue );

                // Set the edge list index into the poly face
                polyFace.f.edgeIdValue[triangleEdgeCounter-1] = edgeIndexValue;

                // Reset the edge counter, if we have all three edges of a triangle.
                if ( triangleEdgeCounter == 3 ) 
                {
                    triangleEdgeCounter = 0;
                    --positionIndex;

                    // Handle the uv set infos.
                    setUVSetInfos ( mesh, primitiveElement, polyFace, uvSetIndicesIndex, 3 );
                    uvSetIndicesIndex -= 2;

                    // Handle the uv set infos.
                    setColorInfos ( mesh, primitiveElement, polyFace, colorIndicesIndex, 3 );
                    colorIndicesIndex -= 2;

                    // Start the block if necessary
                    if ( globalFaceIndex % blockSize == 0 )
                    {
                        endPosition = globalFaceIndex+blockSize-1;
                        if ( endPosition > numGlobalFaces-1 ) 
                            endPosition = numGlobalFaces-1;
                        meshNode.startFace ( globalFaceIndex, endPosition ); 
                    }

                    // Write the polyFace data in the maya file.
                    meshNode.appendFace ( polyFace );

                    // End the block if necessary.
                    if ( globalFaceIndex == endPosition ) 
                        meshNode.endFace (); 

                    // Increment the face index.
                    ++globalFaceIndex;
                }
            }

            // Increment the initial trifan position index for the next trifan object.
            positionIndex += 2;
            initialPositionIndex += vertexCount;

            uvSetIndicesIndex += 2;
            colorIndicesIndex += 2;
        }
    }

    // --------------------------------------------
    void GeometryImporter::appendTristripsPolyFaces ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap, 
        MayaDM::Mesh &meshNode,
        const size_t blockSize, 
        const size_t numGlobalFaces, 
        size_t& globalFaceIndex, 
        size_t& endPosition )
    {
        // Get the position indices.
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // The points of an edge
        int edgeStartVtxIndex=0, edgeEndVtxIndex=0;

        // The current index in the positions list.
        size_t initialPositionIndex=0;
        size_t positionIndex=0;

        size_t uvSetIndicesIndex = 0;
        size_t colorIndicesIndex = 0;

        // Iterate over the grouped vertices and get the edges for every group.
        COLLADAFW::Tristrips* tristrips = (COLLADAFW::Tristrips*) primitiveElement;
        COLLADAFW::Tristrips::VertexCountArray& vertexCountArray = tristrips->getGroupedVerticesVertexCountArray ();
        size_t groupedVtxCount = vertexCountArray.getCount ();
        for ( size_t groupedVtxIndex=0; groupedVtxIndex<groupedVtxCount; ++groupedVtxIndex )
        {
            // Create the poly face
            MayaDM::polyFaces polyFace;

            // A trifan has always triangles, which have 3 edges
            size_t triangleEdgeCounter = 0;

            // The number of vertices in the current vertex group.
            unsigned int vertexCount = vertexCountArray [groupedVtxIndex];

            // We have to turn the direction of every second triangle.
            bool changeDirection = true;

            // Determine the number of edges and iterate over it.
            unsigned int numEdges = ( vertexCount - 3 ) * 3 + 3;
            for ( unsigned int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
            {
                if ( triangleEdgeCounter == 0 )
                {
                    // Change the direction for every second triangle.
                    changeDirection = !changeDirection;

                    // Handle the edge informations.
                    polyFace.f.faceEdgeCount = 3;
                    polyFace.f.edgeIdValue = new int[3];
                }

                // Increment the current triangle edge counter, so we know if we have the full triangle.
                ++triangleEdgeCounter;

                // Get the start edge index
                edgeStartVtxIndex = positionIndices[positionIndex];

                // With the third edge of a triangle, we have to go back to the trifans root.
                if ( triangleEdgeCounter < 3 )
                    edgeEndVtxIndex = positionIndices[++positionIndex];
                else edgeEndVtxIndex = positionIndices[initialPositionIndex];

                // Set the edge vertex index values into an edge object.
                COLLADAFW::Edge edge ( edgeStartVtxIndex, edgeEndVtxIndex );

                // Variable for the current edge index.
                int edgeIndexValue;

                // Get the edge index value from the edge list.
                getEdgeIndex ( edge, edgeIndicesMap, edgeIndexValue );

                // Set the edge list index into the poly face
                if ( changeDirection )
                {
                    edgeIndexValue = -( edgeIndexValue + 1 );

                    if ( triangleEdgeCounter == 1 ) 
                        polyFace.f.edgeIdValue[0] = edgeIndexValue;
                    if ( triangleEdgeCounter == 2 ) 
                        polyFace.f.edgeIdValue[2] = edgeIndexValue;
                    if ( triangleEdgeCounter == 3 ) 
                        polyFace.f.edgeIdValue[1] = edgeIndexValue;
                }
                else
                {
                    polyFace.f.edgeIdValue[triangleEdgeCounter-1] = edgeIndexValue;
                }

                // Reset the edge counter, if we have all three edges of a triangle.
                if ( triangleEdgeCounter == 3 ) 
                {
                    triangleEdgeCounter = 0;
                    --positionIndex;
                    initialPositionIndex = positionIndex;

                    // Handle the uv set infos.
                    setUVSetInfos ( mesh, primitiveElement, polyFace, uvSetIndicesIndex, 3 );
                    uvSetIndicesIndex -= 2;

                    // Handle the uv set infos.
                    setColorInfos ( mesh, primitiveElement, polyFace, colorIndicesIndex, 3 );
                    colorIndicesIndex -= 2;

                    // Start the block if necessary
                    if ( globalFaceIndex % blockSize == 0 )
                    {
                        endPosition = globalFaceIndex+blockSize-1;
                        if ( endPosition > numGlobalFaces-1 ) 
                            endPosition = numGlobalFaces-1;
                        meshNode.startFace ( globalFaceIndex, endPosition ); 
                    }

                    // Write the polyFace data in the maya file.
                    meshNode.appendFace ( polyFace );

                    // End the block if necessary.
                    if ( globalFaceIndex == endPosition ) 
                        meshNode.endFace (); 

                    // Increment the face index.
                    ++globalFaceIndex;
                }
            }

            // Increment the initial tristrip position index for the next tristrip object.
            positionIndex += 2;
            initialPositionIndex = positionIndex;

            uvSetIndicesIndex -= 2;
            colorIndicesIndex -= 2;
        }
    }

    // --------------------------------------------
    void GeometryImporter::setPolygonFaceInfos ( 
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
    void GeometryImporter::setPolygonHoleInfos ( 
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
                polyFace.mu[i].uvIdValue [j] = currentIndex - (unsigned int)initialIndex;
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
                polyFace.mc[i].colorIdValue [j] = currentIndex - (unsigned int)initialIndex;
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
            std::cerr << "GeometryImporter::appendPolyFaces:: Unknown data type!" << std::endl;
            MGlobal::displayError ( "GeometryImporter::appendPolyFaces:: Unknown data type!" );
            assert ( "GeometryImporter::appendPolyFaces:: Unknown data type!" );
            return 0;
        }

        // Store the vertex positions of the current start point.
        return new COLLADABU::Math::Vector3 ( dx, dy, dz );
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
    const MayaNode* GeometryImporter::findMayaMeshNode ( const COLLADAFW::UniqueId& uniqueId ) const
    {
        UniqueIdMayaNodeMap::const_iterator it = mMayaMeshNodesMap.find ( uniqueId );
        if ( it != mMayaMeshNodesMap.end () )
            return it->second;

        return NULL;
    }

    // --------------------------------------------
    MayaNode* GeometryImporter::findMayaMeshNode ( const COLLADAFW::UniqueId& uniqueId )
    {
        UniqueIdMayaNodeMap::iterator it = mMayaMeshNodesMap.find ( uniqueId );
        if ( it != mMayaMeshNodesMap.end () )
            return it->second;

        return NULL;
    }

    // --------------------------------------------
    const MayaDM::Mesh* GeometryImporter::findMayaDMMeshNode ( const COLLADAFW::UniqueId& uniqueId ) const
    {
        UniqueIdMayaDMMeshMap::const_iterator it = mMayaDMMeshNodesMap.find ( uniqueId );
        if ( it != mMayaDMMeshNodesMap.end () )
            return &(*it).second;

        return NULL;
    }

    // --------------------------------------------
    const MayaDM::Mesh* GeometryImporter::findMayaDMControllerMeshNode ( const COLLADAFW::UniqueId& uniqueId ) const
    {
        UniqueIdMayaDMMeshMap::const_iterator it = mMayaDMControllerMeshNodesMap.find ( uniqueId );
        if ( it != mMayaDMControllerMeshNodesMap.end () )
            return &(*it).second;

        return NULL;
    }
    
    // --------------------------------------------
    MayaDM::Mesh* GeometryImporter::findMayaDMControllerMeshNode ( const COLLADAFW::UniqueId& uniqueId ) 
    {
        UniqueIdMayaDMMeshMap::iterator it = mMayaDMControllerMeshNodesMap.find ( uniqueId );
        if ( it != mMayaDMControllerMeshNodesMap.end () )
            return &(*it).second;

        return NULL;
    }

    // --------------------------------------------
    MayaDM::Mesh* GeometryImporter::findMayaDMMeshNode ( const COLLADAFW::UniqueId& uniqueId )
    {
        UniqueIdMayaDMMeshMap::iterator it = mMayaDMMeshNodesMap.find ( uniqueId );
        if ( it != mMayaDMMeshNodesMap.end () )
            return &(*it).second;

        return NULL;
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
    void GeometryImporter::getEdgeIndices ( 
        const COLLADAFW::Mesh* mesh, 
        std::vector<COLLADAFW::Edge>& edgeIndices, 
        std::map<COLLADAFW::Edge,size_t>& edgeIndicesMap )
    {
        // Implementation for multiple primitive elements.
        const COLLADAFW::MeshPrimitiveArray& primitiveElementsArray = mesh->getMeshPrimitives ();
        size_t count = primitiveElementsArray.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            COLLADAFW::MeshPrimitive* primitiveElement = primitiveElementsArray [ i ];

            // Determine the edge indices (unique edges, also for multiple primitive elements).
            primitiveElement->appendEdgeIndices ( edgeIndices, edgeIndicesMap );
        }
    }

    // --------------------------------------------
    std::vector<size_t>* GeometryImporter::getShadingEnginePrimitiveIndices ( 
        const COLLADAFW::UniqueId& geometryId, 
        const COLLADAFW::MaterialId shadingEngineId )
    {
        UniqueIdMaterialIdPair combinedId ( geometryId, shadingEngineId );
        CombinedIdIndicesMap::iterator it = mShadingEnginePrimitivesMap.find ( combinedId );
        if ( it == mShadingEnginePrimitivesMap.end () )
        {
            return 0;
        }
        return &it->second;
    }

    // --------------------------------------------
    void GeometryImporter::setShadingEnginePrimitiveIndex ( 
        const COLLADAFW::UniqueId& geometryId, 
        const COLLADAFW::MaterialId shadingEngineId, 
        const size_t primitiveIndex )
    {
        UniqueIdMaterialIdPair combinedId ( geometryId, shadingEngineId );
        mShadingEnginePrimitivesMap [combinedId].push_back ( primitiveIndex );
    }

    // --------------------------------------------
    std::vector<GroupInfo>* GeometryImporter::findShadingBindingGroups ( 
        const COLLADAFW::UniqueId& geometryId, 
        const COLLADAFW::UniqueId& transformId,
        const COLLADAFW::MaterialId& shadingEngineId )
    {
        ShadingBinding shadingBinding ( geometryId, transformId, shadingEngineId );
        ShadingBindingGroupInfoMap::iterator it = mShadingBindingGroupMap.find ( shadingBinding );
        if ( it == mShadingBindingGroupMap.end () )
        {
            return 0;
        }
        return &(it->second);
    }

    // --------------------------------------------
    std::vector<GroupInfo>* GeometryImporter::findShadingBindingGroups ( 
        const ShadingBinding& shadingBinding )
    {
        ShadingBindingGroupInfoMap::iterator it = mShadingBindingGroupMap.find ( shadingBinding );
        if ( it == mShadingBindingGroupMap.end () )
        {
            return 0;
        }
        return &(it->second);
    }

    // --------------------------------------------
    const size_t GeometryImporter::findPrimitivesCount ( const COLLADAFW::UniqueId& geometryId )
    {
        UniqueIdElementCountMap::const_iterator it = mGeometryIdPrimitivesCountMap.find ( geometryId );
        if ( it == mGeometryIdPrimitivesCountMap.end () )
        {
            return 0;
        }
        return it->second;
    }

    // --------------------------------------------
    const std::vector<MayaDM::componentList>* GeometryImporter::findComponentLists ( 
        const COLLADAFW::UniqueId& geometryId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<MayaDM::componentList> >::const_iterator it;
        it = mMeshComponentLists.find ( geometryId );
        if ( it != mMeshComponentLists.end () )
            return &(it->second);
        return 0;
    }

    // --------------------------------------------
    GeometryImporter::MeshControllerData* GeometryImporter::findMeshControllerDataByControllerAndTransformId ( 
        const COLLADAFW::UniqueId& controllerId, 
        const COLLADAFW::UniqueId& transformId )
    {
        for ( size_t i=0; i<mMeshControllerDataList.size (); ++i )
        {
            MeshControllerData& meshControllerData = mMeshControllerDataList [i];
            if ( meshControllerData.getControllerId () == controllerId &&
                meshControllerData.getTransformId () == transformId )
            {
                return &meshControllerData;
            }
        }
        return 0;
    }

    // --------------------------------------------
    void GeometryImporter::writeConnections ()
    {
        // If there exist a controller for the current mesh, we also need to organize the 
        // groupIds of the mesh's primitive elements in groupParts. 
        // For this, we always have to connect the groupParts ids with the groupId ids.
        // In addition, we have to connect the inputGeometry attribute of the first primitive 
        // element's groupParts object with the first outputGeometry attribute of the 
        // controller's mesh skinCluster object. The following primitive element groupParts 
        // inputGeometry attribute has to be connected to the previous groupParts outputGeometry 
        // attribute. 
        // The outputGeometry attribute of the last primitive element groupParts has to be 
        // connected to the inMesh attribute of  the current mesh object.

        // Get a pointer to the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Store the previous groupId and groupParts objects.
        const MayaDM::GroupParts* previousGroupParts = 0;
        const MayaDM::GroupId* previousGroupId = 0;

        ShadingBindingGroupInfoMap::const_iterator it = mShadingBindingGroupMap.begin ();
        while ( it != mShadingBindingGroupMap.end () )
        {
            const ShadingBinding& shadingBinding = it->first;
            const COLLADAFW::UniqueId& geometryId = shadingBinding.getGeometryId ();
            const COLLADAFW::UniqueId& transformId = shadingBinding.getTransformId();
            const COLLADAFW::UniqueId* controllerId = shadingBinding.getControllerId ();

            // Get the count of primitive elements in the current geometry.
            const size_t numPrimitiveElements = findPrimitivesCount ( geometryId );

            if ( controllerId )
            {
                // Get the current controller object.
                ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
                const COLLADAFW::SkinController* skinController = controllerImporter->findSkinController ( *controllerId );

                // Get the skinCluster object.
                const COLLADAFW::UniqueId& skinControllerDataId = skinController->getSkinControllerData ();
                const ControllerImporter::MayaSkinClusterData* mayaSkinClusterData = controllerImporter->findMayaSkinClusterData ( *controllerId );
                if ( mayaSkinClusterData == 0 )
                {
                    std::cerr << "No skin cluster data for the current controller!" << endl;
                    ++it;
                    continue;
                }
                const MayaDM::SkinCluster& skinCluster = mayaSkinClusterData->getSkinCluster ();

                // Iterate over the groupInfos.
                const std::vector<GroupInfo>& groupInfos = it->second;
                size_t numGroupInfos = groupInfos.size ();
                for ( size_t i=0; i<numGroupInfos; ++i )
                {
                    // Get the current group info.
                    const GroupInfo& groupInfo = groupInfos [i];

                    // Get the groupParts object for the current mesh primitive.
                    const bool hasGroupParts = groupInfo.getHasGroupParts ();
                    if ( !hasGroupParts )
                    {
                        std::cerr << "No groupParts defined!" << endl;
                        continue;
                    }
                    const MayaDM::GroupParts& groupParts = groupInfo.getGroupParts ();

                    // Get the groupId object for the current mesh primitive.
                    const MayaDM::GroupId& groupId = groupInfo.getGroupId ();                            

                    // Handle the primitive element in depend on the primitive index.
                    size_t primitiveIndex = groupInfo.getPrimitiveIndex ();
                    if ( primitiveIndex == 0 )
                    {
                        // connectAttr "skinCluster1.outputGeometry[0]" "groupParts3.inputGeometry";
                        connectAttr ( file, skinCluster.getOutputGeometry (0), groupParts.getInputGeometry () );
                    }
                    else
                    {
                        if ( previousGroupParts == 0 )
                        {
                            std::cerr << "No previous groupParts object!" << endl;
                            continue;
                        }

                        // connectAttr "groupParts3.outputGeometry" "groupParts4.inputGeometry";
                        connectAttr ( file, previousGroupParts->getOutputGeometry (), groupParts.getInputGeometry () );
                    }

                    // connectAttr "groupId3.groupId" "groupParts3.groupId";
                    connectAttr ( file, groupId.getGroupId (), groupParts.getGroupId () );

                    // Handle the last primitive element connections.
                    if ( primitiveIndex == numPrimitiveElements-1 )
                    {
                        // Get the current mesh (either the original object, or if we have a mesh
                        // controller, we need the mesh controller object.
                        MayaDM::Mesh* mesh = 0;
                        if ( controllerId == 0 )
                        {
                            mesh = findMayaDMMeshNode ( geometryId );
                        }
                        else
                        {
                            // If the current mesh has a mesh controller object, 
                            // we need the controller mesh element instead of the original.
                            MeshControllerData* meshControllerData = findMeshControllerDataByControllerAndTransformId ( *controllerId, transformId );
                            mesh = meshControllerData->getControllerMeshNode ();
                        }
                        if ( mesh == 0 )
                        {
                            std::cerr << "No mesh object exist!" << endl;
                            continue;
                        }
                        // connectAttr "groupParts5.outputGeometry" "polySurfaceShape1.inMesh";
                        connectAttr ( file, groupParts.getOutputGeometry (), mesh->getInMesh () );
                    }

                    // Store the groupId and groupParts objects.
                    previousGroupId = &groupId;
                    previousGroupParts = &groupParts;
                }
            }

            ++it;
        }
    }
}
