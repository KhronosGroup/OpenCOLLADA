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

#include "DAE2MAStableHeaders.h"
#include "DAE2MAGeometryImporter.h"
#include "DAE2MAVisualSceneImporter.h"
#include "DAE2MAImportOptions.h"
#include "DAE2MAControllerImporter.h"
#include "DAE2MAMaterialImporter.h"

#pragma warning(disable:4172)

#include "MayaDMTransform.h"
#include "MayaDMCommands.h"

#include "COLLADAFWPolygons.h"
#include "COLLADAFWTrifans.h"
#include "COLLADAFWTristrips.h"
#include "COLLADAFWEdge.h"
#include "COLLADAFWMorphController.h"


namespace DAE2MA
{
    
    const String GeometryImporter::GEOMETRY_NAME = "geom";


    // --------------------------------------------
    GeometryImporter::GeometryImporter( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
	, mCount2013Workarounds( 0 )
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
            return;
        case COLLADAFW::Geometry::GEO_TYPE_SPLINE:
            std::cerr << "Import of spline not supported!" << std::endl;
            return;
        case COLLADAFW::Geometry::GEO_TYPE_MESH:
            {
                COLLADAFW::Mesh* mesh = ( COLLADAFW::Mesh* ) geometry;
                
                // Import the mesh data, if the geometry is referenced from a transform node.
                bool meshAlreadyImported = importMesh ( mesh );

                // Import the controller mesh data, if the mesh is referenced from a controller.
                // If a skinControllerData object is referenced from multiple controllers,
                // just the first one has to create the original mesh object.
                importController ( mesh, meshAlreadyImported );

                break;
            }
        default:
            return;
        }

        return;
    }

    // --------------------------------------------
    void GeometryImporter::importController ( 
        COLLADAFW::Mesh* mesh, 
        bool meshAlreadyImported )
    {
        // Import the geometries, which are referenced with a skin or morph controller.
        importControllerGeometry ( mesh, meshAlreadyImported );
        if ( meshAlreadyImported ) return;
        
        // Import the geometries, which are referenced with a target of a morph controller.
        importMorphTargetGeometry ( mesh, meshAlreadyImported );
    }

    // --------------------------------------------
    void GeometryImporter::importMorphTargetGeometry ( 
        COLLADAFW::Mesh* mesh, 
        bool &meshIsImported )
    {
        // Get the unique id.
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();

        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();

        // Check if we need to import the geometry, about it is referenced from a morph target.
        const std::vector<COLLADAFW::MorphController*>* morphControllers = controllerImporter->findMorphControllersByMorphTargetId ( geometryId );
        if ( morphControllers == 0 ) return;

        for ( size_t i=0; i<morphControllers->size (); ++i )
        {
            // Every skin controller needs his own controller mesh object. All connections of 
            // skinController elements, materials and groups will be done directly to this mesh.
            // The original mesh geometry object has to be created just once, either as an intermediate
            // object or, if it is referenced from an instance geometry, directly as normal mesh.
            const COLLADAFW::MorphController* morphController = (*morphControllers) [i];

            // Create an original mesh object under the transform node of the skin controller.
            const COLLADAFW::UniqueId& morphControllerId = morphController->getUniqueId ();

            // Get the node instances, if the morph controller is directly referenced from the scene graph.
            const UniqueIdVec* morphControllerTransformIds = visualSceneImporter->findControllerTransformIds ( morphControllerId );
            if ( morphControllerTransformIds == 0 ) 
            {
                // A morph controller can also be referenced from a skin controller. 
                // In this case, we have to check, if the skin controller is referenced from 
                // the scene graph. If so, we can start to import the geometry.
                const std::vector<COLLADAFW::SkinController*>* skinControllers = controllerImporter->findSkinControllersBySourceId ( morphControllerId );
                if ( skinControllers == 0 || skinControllers->size () == 0 ) continue;

                for ( size_t j=0; j<skinControllers->size (); ++j )
                {
                    const COLLADAFW::SkinController* skinController = (*skinControllers) [j];
                    const COLLADAFW::UniqueId& skinControllerId = skinController->getUniqueId ();

                    // Get the node instances.
                    const UniqueIdVec* skinControllerTransformIds = visualSceneImporter->findControllerTransformIds ( skinControllerId );
                    if ( skinControllerTransformIds != 0 ) 
                    {
                        // Import the mesh data (just once!).
                        const COLLADAFW::UniqueId& transformId = (*skinControllerTransformIds) [0];
                        UniqueIdVec controllerTransformIds;
                        controllerTransformIds.push_back ( transformId );
                        meshIsImported = importMesh ( mesh, &controllerTransformIds, 0, meshIsImported, false, false );
                    }
                }
            }
            else
            {
                // Import the mesh data (just once!).
                const COLLADAFW::UniqueId& transformId = (*morphControllerTransformIds) [0];
                UniqueIdVec controllerTransformIds;
                controllerTransformIds.push_back ( transformId );
                meshIsImported = importMesh ( mesh, &controllerTransformIds, 0, false, false, false );
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::importControllerGeometry (
        COLLADAFW::Mesh* mesh,
        bool &isImported )
    {
        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();

        // The flag is used to know, if the current mesh is a valid, visible geometry (this means,
        // that the geometry is directly instantiated in an <instance_geometry> tag). If the 
        // geometry is at this point of import already imported, we must have a geometry instance.
        // Then we have to change the bind material objects (@see MaterialImporter::connectGeometries ()).
        bool hasGeometryInstance = isImported;

        // Check, if the mesh is directly referenced from a controller object.
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
        std::vector<COLLADAFW::Controller*> controllers = controllerImporter->findControllersBySourceId ( geometryId );
        if ( controllers.size () == 0 ) return;
        for ( size_t i=0; i<controllers.size (); ++i )
        {
            // Every skin controller needs his own controller mesh object. All connections of 
            // skinController elements, materials and groups will be done directly to this mesh.
            // The original mesh geometry object has to be created just once, either as an intermediate
            // object or, if it is referenced from an instance geometry, directly as normal mesh.
            const COLLADAFW::Controller* controller = (controllers) [i];

            // Import the geometry for any controller, which use the geometry directly.
            if ( importSkinOrMorphControlledGeometry ( mesh, controller, isImported, hasGeometryInstance ) ) 
                isImported = true;

            // Check if the current controller is a morph controller.
            if ( controller->getControllerType () == COLLADAFW::Controller::CONTROLLER_TYPE_MORPH )
            {
                // Import the geometry for skin controllers, which use a morph controller, which use the geometry.
                const COLLADAFW::MorphController* morphController = (COLLADAFW::MorphController*)controller;
                if ( importSkinAndMorphControlledGeometry ( mesh, morphController, isImported, hasGeometryInstance ) )
                    isImported = true;
            }
        }
    }

    // --------------------------------------------
    bool GeometryImporter::importSkinOrMorphControlledGeometry ( 
        COLLADAFW::Mesh* mesh, 
        const COLLADAFW::Controller* controller, 
        const bool isImported, 
        const bool hasGeometryInstance )
    {
        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();

        bool retValue = isImported;

        // Create an original mesh object under the transform node of the skin controller.
        const COLLADAFW::UniqueId& controllerId = controller->getUniqueId ();

        // Get the node instances.
        const UniqueIdVec* controllerTransformIds = visualSceneImporter->findControllerTransformIds ( controllerId );
        if ( controllerTransformIds != 0 )              
        {
            // Make the mesh instances and import the mesh data.
            const COLLADAFW::Controller::ControllerType& controllerType = controller->getControllerType ();
            MeshControllerData meshControllerData ( controllerType, controllerId );

            // If the current controller, who reference the geometry, is a morph controller, we 
            // must check if the morph controller is referenced from one or more skin controllers. 
            // In this case, we have to create a mesh controller node for every skin controller.
            if ( importMesh ( mesh, controllerTransformIds, &meshControllerData, retValue ) ) retValue = true;
            mMeshControllerDataList.push_back ( meshControllerData );
        }

        return retValue;
    }

    // --------------------------------------------
    bool GeometryImporter::importSkinAndMorphControlledGeometry ( 
        COLLADAFW::Mesh* mesh,
        const COLLADAFW::MorphController* morphController, 
        const bool meshImported, 
        const bool hasGeometryInstance )
    {
        ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();

        // Flag, if the geometry is imported.
        bool retValue = meshImported;

        // Get the controller id.
        const COLLADAFW::UniqueId& morphControllerId = morphController->getUniqueId ();

        // Get all skin controllers, who reference the current morph controller.
        const std::vector<COLLADAFW::SkinController*>* skinControllers = controllerImporter->findSkinControllersBySourceId ( morphControllerId );
        if ( skinControllers == 0 || skinControllers->size () == 0 ) return retValue;
        const size_t numSkinControllers = skinControllers->size ();

        // Check if the morph meshControllerData is already imported.
        bool deleteMorphMeshControllerData = false;
        bool morphAlreadyImported = true;

        // The current morph meshController.
        MeshControllerData* morphMeshControllerData = 0;

        // Create the skin controllers.
        for ( size_t scInstance=0; scInstance<numSkinControllers; ++scInstance )
        {
            // Do it in the loop, about the list will be changed.
            morphMeshControllerData = findMeshControllerDataByControllerId ( morphControllerId );
            if ( morphMeshControllerData == 0 )
            {
                // Create a MeshControllerData object for the current morph controller.
                morphMeshControllerData = new MeshControllerData ( COLLADAFW::Controller::CONTROLLER_TYPE_MORPH, morphControllerId );
                deleteMorphMeshControllerData = true;
                morphAlreadyImported = false;
            }

            // Get the current skin controller.
            const COLLADAFW::SkinController* skinController = (*skinControllers) [scInstance];
            const COLLADAFW::UniqueId& skinControllerId = skinController->getUniqueId ();

            // Get the node instances. If there are no instances, the skin controller is 
            // not referenced from the scene graph and we don't need to create it.
            const UniqueIdVec* controllerTransformIds = visualSceneImporter->findControllerTransformIds ( skinControllerId );
            if ( controllerTransformIds == 0 ) continue;

            // Create a MeshControllerData object for the current skin controller.
            MeshControllerData skinMeshControllerData ( COLLADAFW::Controller::CONTROLLER_TYPE_SKIN, skinControllerId );
            if ( importMesh ( mesh, controllerTransformIds, &skinMeshControllerData, retValue ) ) retValue = true;

            // Just create the morph mesh controller data once.
            if ( !morphAlreadyImported )
            {
                bool intermediateObject = true;
                if ( importMesh ( mesh, controllerTransformIds, morphMeshControllerData, retValue, intermediateObject ) ) retValue = true;
                mMeshControllerDataList.push_back ( *morphMeshControllerData );
                morphAlreadyImported = true;

                // Delete the generated object again.
                if ( deleteMorphMeshControllerData ) delete morphMeshControllerData;
            }

            // Get the object again, because the list could have changed or the object deletet.
            morphMeshControllerData = findMeshControllerDataByControllerId ( morphControllerId );

            // We have to change the original mesh nodes of the skin controller to the
            // controller mesh node of the morph controller.
            const MayaDM::Mesh& morphControllerMeshNode = morphMeshControllerData->getControllerMeshNode ();
            skinMeshControllerData.setOriginalMeshNode ( morphControllerMeshNode );
            mMeshControllerDataList.push_back ( skinMeshControllerData );
        }

        return retValue;
    }

    // --------------------------------------------
    bool GeometryImporter::importMesh ( COLLADAFW::Mesh* mesh )
    {
        // Get the unique framework mesh id 
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();

        // Get the transform node(s) of the current mesh.
        VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
        const UniqueIdVec* transformNodeIds = visualSceneImporter->findGeometryTransformIds ( geometryId );
        if ( transformNodeIds == 0 ) return false;

        // Make the mesh instances and import the mesh data.
        bool meshImported = importMesh ( mesh, transformNodeIds );

        return meshImported;
    }

    // --------------------------------------------
    bool GeometryImporter::importMesh ( 
        COLLADAFW::Mesh* mesh, 
        const UniqueIdVec* transformNodeIds, 
        MeshControllerData* meshControllerData /*= 0*/,
        const bool isImported /*= false*/, 
        const bool intermediateObject /*= false*/,
        const bool visible /*= true*/ )
    {
        // The return flag.
        bool retValue = isImported;

        // The index value of the current geometry instance.
        size_t geometryInstanceIndex = 0;

        // The transform node path of the original instance.
        String instanceTransformNodePath;

        // Go through the node instances and create / instanciate the mesh. 
        size_t numNodeInstances = transformNodeIds->size ();
        UniqueIdVec::const_iterator nodesIter = transformNodeIds->begin ();
        while ( nodesIter != transformNodeIds->end () )
        {
            // Get the maya node of the current transform node.
            const COLLADAFW::UniqueId& transformId = *nodesIter;
            VisualSceneImporter* visualSceneImporter = getDocumentImporter ()->getVisualSceneImporter ();
            MayaNodesList* transformNodes = visualSceneImporter->findMayaTransformNodes ( transformId );
            if ( transformNodes->size () == 0 )
            {
                std::cerr << "The referenced transform node doesn't exist!" << std::endl;
                return false;
            }
            // We always take the first transform node to create the instance. 
            // All other transform nodes will instanciate the main instance mesh node.
            MayaNode* mayaTransformNode = (*transformNodes) [0];
            String transformNodeName = mayaTransformNode->getName ();

            // Get the path to the parent transform node.
            String transformNodePath = mayaTransformNode->getNodePath ();

            // The first reference is a direct one, the others are instances.
            if ( nodesIter == transformNodeIds->begin() )
            {
                // Create the current mesh node.
                if ( createMesh ( mesh, mayaTransformNode, meshControllerData, retValue, intermediateObject, visible ) ) 
                    retValue = true;
                instanceTransformNodePath = transformNodePath;
            }
            else
            {
                // If the mesh is skin controlled, we have to copy the meshControllerData object.
                if ( !meshControllerData )
                {
                    // Make the parent connections.
                    const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
                    MayaNode* mayaMeshNode = findMayaMeshNode ( geometryId );
                    String meshNodePath = mayaMeshNode->getNodePath ();

                    // parent -shape -noConnections -relative -addObject "|pCube1|pCubeShape1" "pCube2";
                    FILE* file = getDocumentImporter ()->getFile ();
                    MayaDM::parentShape ( file, meshNodePath, transformNodePath, false, true, true, true );
                }
                else
                {
                    MeshControllerData meshControllerDataInstance ( *meshControllerData );
                    meshControllerDataInstance.setTransformId ( transformId );
                    meshControllerDataInstance.setIsInitialInstance ( false );
                    mMeshControllerDataList.push_back ( meshControllerDataInstance );

                    // parent -shape -noConnections -relative -addObject "|pCube1|pCubeShape1" "pCube2";
                    String meshName = meshControllerDataInstance.getControllerMeshNode ().getName ();
                    size_t pos = meshName.find_last_of ( "|" );
                    String name = meshName.substr ( pos+1 );
                    String meshNodePath = instanceTransformNodePath + "|" + name;
                    FILE* file = getDocumentImporter ()->getFile ();

                    MayaDM::parentShape ( file, meshNodePath, transformNodePath, false, true, true, true );
                }
            }

            // Create maya groupId objects for every mesh primitive (if there is more than one) to
            // connect the materials. This method is called for every geometry instance.
            // If the current mesh is an intermediate object or it is invisible, then we don't need 
            // the object groups for the material connections for it.
            //if ( !intermediateObject && visible )
            if ( !intermediateObject )
            {
                if ( meshControllerData )
                {
                    const COLLADAFW::UniqueId& controllerId = meshControllerData->getControllerId ();
                    createGroupNodes ( mesh, geometryInstanceIndex, transformId, numNodeInstances, controllerId );
                }
                else
                {
                    createGroupNodes ( mesh, geometryInstanceIndex, transformId, numNodeInstances );
                }
            }

            ++nodesIter;
        }

        return retValue;
    }

    // --------------------------------------------
    bool GeometryImporter::createMesh ( 
        COLLADAFW::Mesh* mesh, 
        MayaNode* mayaTransformNode, 
        MeshControllerData* meshControllerData /*= 0*/, 
        const bool meshIsImported /*= false*/,
        const bool intermediateObject /*= false*/,
        const bool visible /*= true*/ )
    {
        // Get the unique object id.
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();

        // Make the maya name unique and manage it in all necessary lists.
        String meshName = mesh->getName ();
        if ( meshName.empty () ) meshName = GEOMETRY_NAME;
        meshName = DocumentImporter::frameworkNameToMayaName ( meshName );
        const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
        String originalMayaId = getOriginalMayaId ( callbackHandler, geometryId, COLLADASaxFWL15::HASH_ELEMENT_GEOMETRY );
        if ( !originalMayaId.empty () ) meshName = originalMayaId;
        meshName = generateUniqueDagNodeName ( meshName, mayaTransformNode );

        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the parent transform node name.
        const COLLADAFW::UniqueId& transformNodeId = mayaTransformNode->getUniqueId ();
        String transformNodePath = mayaTransformNode->getNodePath ();

        // Create a maya node object of the current node and push it into the map.
        if ( findMayaMeshNode ( geometryId ) == 0 )
        {
            MayaNode* mayaMeshNode = new MayaNode ( geometryId, meshName, mayaTransformNode );
            mMayaMeshNodesMap [ geometryId ] = mayaMeshNode;
        }

        // We just need a MeshControllerData element, if we have a mesh controller object
        // to store the information of the controllerId, geometryId and transformId with the 
        // combination of the original mesh node object and the controller mesh object.
        if ( meshControllerData )
        {
            meshControllerData->setGeometryId ( geometryId );
            meshControllerData->setTransformId ( transformNodeId );

            // Create the controller mesh object first.
            // Create the mesh node - no special settings...
            MayaDM::Mesh controllerMeshNode ( file, meshName, transformNodePath );

            // Now set the node path in front of the name.
            controllerMeshNode.setName ( transformNodePath + "|" + meshName );

            // Add the original id attribute.
            String colladaId = mesh->getOriginalId ();
            if ( !colladaId.empty () )
            {
                MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
                MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
            }

//             // TODO Write all the extra datas of the mesh and the primitive elements into the maya file.
//             COLLADAFW::ExtraDataArray& meshExtraDataArray = getAllExtraData ( mesh );
//             setExtraData ( meshExtraDataArray );

            if ( intermediateObject ) controllerMeshNode.setIntermediateObject ( intermediateObject );

            // We have to set the texture coordinates and the colors to the current mesh.
            writeUVSets ( mesh, controllerMeshNode, false );
            writeColorSets ( mesh, controllerMeshNode, false );

            // Set the mesh as the controller mesh.
            meshControllerData->setControllerMeshNode ( controllerMeshNode );

            // Check if the original mesh is already created. If not, we have to create it 
            // here as a intermediate object, otherwise we can return here.
            if ( meshIsImported ) 
            {
                // Get the original mesh node from the list of maya mesh nodes.
                MayaDM::Mesh* originalMeshNode = findMayaDMMeshNode ( geometryId );
                meshControllerData->setOriginalMeshNode ( *originalMeshNode );

                // The original mesh is already created, we can leave the creation.
                return true;
            }

            // Create the original mesh as an intermediate object.
            meshName += "Orig";
            meshName = generateUniqueDagNodeName ( meshName, mayaTransformNode );
        }

        // Create the current maya data model mesh node.
        MayaDM::Mesh meshNode ( file, meshName, transformNodePath );

        // Now set the node path in front of the name.
        meshNode.setName ( transformNodePath + "|" + meshName );

        if ( !visible ) meshNode.setVisibility ( visible );
        mMayaDMMeshNodesMap [geometryId] = meshNode;

        if ( meshControllerData )
        {
            // Handle a mesh which is instanced from a controller object.
            // Boolean attribute that specifies whether the dagNode is an intermediate object 
            // resulting  from a construction history operation. dagNodes with this attribute set 
            // to true are not visible and/or rendered.
            meshNode.setIntermediateObject ( true );

            // Set the original mesh data.
            meshControllerData->setOriginalMeshNode ( meshNode );
        }
        else
        {
            // Add the original id attribute.
            String colladaId = mesh->getOriginalId ();
            if ( !colladaId.empty () )
            {
                MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
                MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
            }

//             // TODO Write all the extra datas of the mesh and the primitive elements into the maya file.
//             COLLADAFW::ExtraDataArray& meshExtraDataArray = getAllExtraData ( mesh );
//             setExtraData ( meshExtraDataArray );
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
        EdgeList edgeIndices;

        // We store the edge indices also in a sorted map. The dublicate data holding 
        // is reasonable, because we need the index of a given edge. The search of  
        // values in a map is much faster than in a vector!
        EdgeMap edgeIndicesMap;

        // We need also a list where we store the information about the vertices of an edge 
        // and the index position of the vertex in the mesh's primitive lists. Because the indices
        // in the primitive's vertex indices list are always the same like the indices in the 
        // primitive's uv or color indices lists. 

        // Iterates over the mesh primitives and reads the edge indices.
        getEdgeIndices ( mesh, edgeIndices, edgeIndicesMap );

        // Write the edge indices of all primitive elements into the maya file.
        writeEdges ( mesh, edgeIndices, meshNode );

        // Write the face informations of all primitive elements into the maya file.
        writeFaces ( mesh, edgeIndicesMap, meshNode );

        // Write the face vertex normals. 
//         if ( ImportOptions::importNormals () )
//             writeFaceVertexNormals ( mesh, meshNode );
            
        // Fills the PrimitivesMap and the ShadingEnginePrimitivesMap. 
        // Used to create the connections between the shading engines and the geometries.
        setMeshPrimitiveShadingEngines ( mesh );
        
        // Return the flag, that the mesh is imported.
        return true;
    }

//     // --------------------------------------------
//     COLLADAFW::ExtraDataArray& GeometryImporter::getAllExtraData ( COLLADAFW::Mesh* mesh )
//     {
//         // Add the attributes for all the extra tags (from the mesh the extra data of the 
//         // geometry, the mesh, and the vertices).
//         COLLADAFW::ExtraDataArray& meshExtraDataArray = mesh->getExtraDataArray ();
// 
//         // Handle the mesh primitive elements.
//         const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mesh->getMeshPrimitives ();
//         for ( size_t i=0; i<meshPrimitives.getCount (); ++i )
//         {
//             const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives [i];
//             const COLLADAFW::ExtraDataArray& primitiveExtraDataArray = meshPrimitive->getExtraDataArray ();
// 
//             meshExtraDataArray.appendValues ( primitiveExtraDataArray );
//         }
// 
//         return meshExtraDataArray;
//     }

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
            COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = meshPrimitive->getPrimitiveType();
            // Get the normal indices of the current primitive.
            const COLLADAFW::UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices ();

            switch ( primitiveType )
            {
            case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
                {
                    size_t initialGroupedPosition = 0;

                    COLLADAFW::Trifans* trifans = (COLLADAFW::Trifans*) meshPrimitive;
                    COLLADAFW::Trifans::VertexCountArray& vertexCountArray = trifans->getGroupedVerticesVertexCountArray ();
                    size_t groupedVtxCount = vertexCountArray.getCount ();

					if( normalIndices.getCount() == 0 )
						continue;

                    for ( size_t groupedVtxIndex=0; groupedVtxIndex<groupedVtxCount; ++groupedVtxIndex )
                    {
                        // Iterate over the indices and write their normal values into the maya file.
                        size_t indexCount   = vertexCountArray[groupedVtxIndex]; 
                        size_t numTriangles = indexCount - 2;

                        unsigned int triIndices[3];

                        // Increment the initial position for every vertex group.
                        size_t initialPosition = initialGroupedPosition;
                        initialGroupedPosition += indexCount;

                        // The first vertex is always the same (per group).
                        triIndices[0] = normalIndices [ initialPosition ];

                        for ( size_t j=2; j<indexCount; ++j )
                        {
                            triIndices[1] = normalIndices [ initialPosition+j-1 ];
                            triIndices[2] = normalIndices [ initialPosition+j ];

                            // Iterate over the three normals of the current tristrip.
                            for ( size_t n=0; n<3; ++n, ++index )
                            {
                                // Start the block if necessary.
                                if ( index % blockSize == 0 )
                                {
                                    endPosition = index+blockSize-1;
                                    if ( endPosition > numNormals-1 ) endPosition = numNormals-1;
                                    meshNode.startNormals ( index, endPosition ); 
                                }

                                // Get the position in the values list to read.
                                unsigned int pos = triIndices[n] * (unsigned int)stride;                            

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
                                    break;
                                }

                                // End the block if necessary.
                                if ( index == endPosition ) 
                                    meshNode.endNormals (); 
                            }                        
                        }

                        // Increment the initial position for every vertex group.
                        initialPosition += indexCount;
                    }
                }
                break;
            case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
                {
                    size_t initialGroupedPosition = 0;

                    COLLADAFW::Tristrips* tristrips = (COLLADAFW::Tristrips*) meshPrimitive;
                    COLLADAFW::Tristrips::VertexCountArray& vertexCountArray = tristrips->getGroupedVerticesVertexCountArray ();
                    size_t groupedVtxCount = vertexCountArray.getCount ();

					if( normalIndices.getCount() == 0 )
						continue;

                    for ( size_t groupedVtxIndex=0; groupedVtxIndex<groupedVtxCount; ++groupedVtxIndex )
                    {
                        // Iterate over the indices and write their normal values into the maya file.
                        size_t indexCount   = vertexCountArray[groupedVtxIndex]; 
                        size_t numTriangles = indexCount - 2;

                        unsigned int triIndices[3];

                        // Increment the initial position for every vertex group.
                        size_t initialPosition = initialGroupedPosition;
                        initialGroupedPosition += indexCount;

                        for ( size_t j=0; j<numTriangles; ++j )
                        {
                            // Every second tristrip has to go into the other direction.
                            if ( j%2 == 0 )
                            {
                                triIndices[0] = normalIndices [ initialPosition+j ];
                                triIndices[1] = normalIndices [ initialPosition+j+1 ];
                                triIndices[2] = normalIndices [ initialPosition+j+2 ];
                            }
                            else
                            {
                                triIndices[0] = normalIndices [ initialPosition+j+1 ];
                                triIndices[1] = normalIndices [ initialPosition+j ];
                                triIndices[2] = normalIndices [ initialPosition+j+2 ];
                            }

                            // Iterate over the three normals of the current tristrip.
                            for ( size_t n=0; n<3; ++n, ++index)
                            {
                                // Start the block if necessary.
                                if ( index % blockSize == 0 )
                                {
                                    endPosition = index+blockSize-1;
                                    if ( endPosition > numNormals-1 ) endPosition = numNormals-1;
                                    meshNode.startNormals ( index, endPosition ); 
                                }

                                // Get the position in the values list to read.
                                unsigned int pos = triIndices[n] * (unsigned int)stride;                            

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
                                }

                                // End the block if necessary.
                                if ( index == endPosition ) 
                                    meshNode.endNormals (); 
                            }                        
                        }

                        // Increment the initial position for every vertex group.
                        initialPosition += indexCount;
                    }
                }
                break;
            case COLLADAFW::MeshPrimitive::POLYGONS:
            case COLLADAFW::MeshPrimitive::POLYLIST:
            case COLLADAFW::MeshPrimitive::TRIANGLES:
                {
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
                            break;
                        }

                        // End the block if necessary.
                        if ( index == endPosition ) 
                            meshNode.endNormals (); 
                    }
                }
                break;
            default:
                std::cerr << "Primitive type not implemented!" << std::endl;
                continue;
            }            
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeFaceVertexNormals ( 
        const COLLADAFW::Mesh* mesh, 
        MayaDM::Mesh &meshNode )
    {
        // Get the mesh normals values.
        const COLLADAFW::MeshVertexData& normals = mesh->getNormals ();
        if ( normals.getValuesCount () == 0 ) return;

        size_t globalFaceIndex = 0;

        // We have to go through every mesh primitive and append every element. 
        const COLLADAFW::MeshPrimitiveArray& meshPrimitives = mesh->getMeshPrimitives ();
        size_t count = meshPrimitives.getCount ();
        for ( size_t primitiveIndex=0; primitiveIndex<count; ++primitiveIndex )
        {
            // Get the current primitive element.
            const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives [ primitiveIndex ];
            const COLLADAFW::MeshPrimitive::PrimitiveType& primitiveType = meshPrimitive->getPrimitiveType ();

            // Get the normal indices of the current primitive.
            const COLLADAFW::UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices ();
            const COLLADAFW::UIntValuesArray& vertexIndices = meshPrimitive->getPositionIndices ();

            // Get the number of faces of the current primitive element.
            const size_t primitiveFaceCount = meshPrimitive->getFaceCount ();
            const size_t groupedVertexElementsCount = meshPrimitive->getGroupedVertexElementsCount ();

            size_t primitiveVertexIndex = 0;

            // Iterate over the faces/groupedVertexElements and write the normals for every vertex in the current face.
            for ( size_t faceIndex=0; faceIndex<groupedVertexElementsCount; ++faceIndex )
            {
                // Get the number of vertices in the current face/groupedVertexElement.
                int numFaceVerticesH = meshPrimitive->getGroupedVerticesVertexCount ( faceIndex );
                const size_t numFaceVertices = numFaceVerticesH < 0 ? (size_t)numFaceVerticesH*-1 : (size_t)numFaceVerticesH;

                // Handle holes: if we write the normals of a hole, 
                // we don't have to increment the maya face count.
                if ( numFaceVerticesH < 0 ) --globalFaceIndex;

                size_t firstGroupedVertexElementPrimitiveVertexIndex = 0;

                // Iterate over the face vertices and get the normals for every vertex in the current face.
                for ( size_t faceVertexIndex=0; faceVertexIndex<numFaceVertices; ++faceVertexIndex )
                {
                    switch ( primitiveType )
                    {
                    case COLLADAFW::MeshPrimitive::POLYGONS:
                    case COLLADAFW::MeshPrimitive::POLYLIST:
                    case COLLADAFW::MeshPrimitive::TRIANGLES:
                        {
                            // Set the normal and increment the vertex index of the current primitive element.
                            setFaceVertexNormal ( meshNode, meshPrimitive, normals, primitiveVertexIndex, globalFaceIndex );
                            ++primitiveVertexIndex;
                        }
                        break;
                    case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
                        {
                            if ( faceVertexIndex == 0 )
                                firstGroupedVertexElementPrimitiveVertexIndex = primitiveVertexIndex;

                            // After the third vertex in a grouped vertex element, every next vertex 
                            // defines a triangle with the first, the last and the new vertex.
                            if ( faceVertexIndex >= 3 )
                            {
                                // We have the next face.
                                ++globalFaceIndex;

                                // Set the normal of the first vertex.
                                setFaceVertexNormal ( meshNode, meshPrimitive, normals, firstGroupedVertexElementPrimitiveVertexIndex, globalFaceIndex );

                                // Set the normal of the last vertex.
                                --primitiveVertexIndex;
                                setFaceVertexNormal ( meshNode, meshPrimitive, normals, primitiveVertexIndex, globalFaceIndex );
                                ++primitiveVertexIndex;

                                // Set the normal of the new vertex.
                                setFaceVertexNormal ( meshNode, meshPrimitive, normals, primitiveVertexIndex, globalFaceIndex );
                                ++primitiveVertexIndex;
                            }
                            else
                            {
                                // Set the normal of the new vertex.
                                setFaceVertexNormal ( meshNode, meshPrimitive, normals, primitiveVertexIndex, globalFaceIndex );
                                ++primitiveVertexIndex;
                            }
                        }
                        break;
                    case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
                        {
                            // After the third vertex in a grouped vertex element, every next vertex 
                            // defines a triangle with the next to last, the last and the new vertex.
                            if ( faceVertexIndex >= 3 )
                            {
                                // We have the next face.
                                ++globalFaceIndex;

                                // Write the normals for the last two vertices in the current face.
                                primitiveVertexIndex -= 2;

                                // Set the normal of the next to last vertex.
                                setFaceVertexNormal ( meshNode, meshPrimitive, normals, primitiveVertexIndex, globalFaceIndex );
                                ++primitiveVertexIndex;

                                // Set the normal of the last vertex.
                                setFaceVertexNormal ( meshNode, meshPrimitive, normals, primitiveVertexIndex, globalFaceIndex );
                                ++primitiveVertexIndex;
                            }

                            // Set the normal of the new vertex.
                            setFaceVertexNormal ( meshNode, meshPrimitive, normals, primitiveVertexIndex, globalFaceIndex );
                            ++primitiveVertexIndex;
                        }
                        break;
                    default:
                        std::cerr << "Import of normals of primitive element from type " << primitiveType << " not implemented." << std::endl;
                        break;
                    }
                }

                // Increment the global face index by the number of faces of the current primitive element.
                ++globalFaceIndex;
            }
        }
    }    

    // --------------------------------------------
    void GeometryImporter::setFaceVertexNormal ( 
        MayaDM::Mesh &meshNode, 
        const COLLADAFW::MeshPrimitive* meshPrimitive, 
        const COLLADAFW::MeshVertexData &normals, 
        const size_t primitiveVertexIndex, 
        const size_t globalFaceIndex )
    {
        // Get the normal indices of the current primitive.
        const COLLADAFW::UIntValuesArray& normalIndices = meshPrimitive->getNormalIndices ();
        const COLLADAFW::UIntValuesArray& vertexIndices = meshPrimitive->getPositionIndices ();

        // Get the vertex index.
        unsigned int vertexIndex = vertexIndices [ primitiveVertexIndex ];

        // Get the index of the current normal.
        unsigned int normalIndex = normalIndices [ primitiveVertexIndex ];

        // Get the position in the values list to read.
        const size_t stride = 3; // Always a x,y and z component of a normal vector.
        unsigned int pos = normalIndex * (unsigned int)stride;

        // Write the normal values on the index values.
        const COLLADAFW::MeshVertexData::DataType type = normals.getType ();
        switch ( type )
        {
        case COLLADAFW::MeshVertexData::DATA_TYPE_FLOAT:
            {
                const COLLADAFW::ArrayPrimitiveType<float>* values = normals.getFloatValues ();
                meshNode.setVertexFaceNormalXYZ ( vertexIndex, globalFaceIndex, MayaDM::float3 ((*values)[pos],(*values)[pos+1],(*values)[pos+2]) );
            }
            break;
        case COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE:
            {
                const COLLADAFW::ArrayPrimitiveType<double>* values = normals.getDoubleValues ();
                meshNode.setVertexFaceNormalXYZ ( vertexIndex, globalFaceIndex, MayaDM::float3 ((float)(*values)[pos],(float)(*values)[pos+1],(float)(*values)[pos+2]) );
            }
            break;
        default:
            std::cerr << "No valid data type for normals: " << type << std::endl;
        }
    }

    // --------------------------------------------
    void GeometryImporter::createGroupNodes ( 
        const COLLADAFW::Mesh* mesh,
        size_t& geometryInstanceIndex, 
        const COLLADAFW::UniqueId& transformId, 
        const size_t numNodeInstances,
        const COLLADAFW::UniqueId& controllerId /*= COLLADAFW::UniqueId ()*/ )
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
        size_t numTransformInstances = visualSceneImporter->getNumTransformInstances ( transformId );

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
                std::cerr << "No component lists generated for the current geometry's primitives!" << std::endl;
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
                ShadingBinding shadingBinding ( geometryId, transformId, shadingEngineId, controllerId );
                shadingBinding.setNumInstances ( numNodeInstances );
                shadingBinding.setInstanceIndex ( geometryInstanceIndex );

                // Create the maya groupId object 
                String groupName =  generateUniqueDependNodeName ( GROUP_ID_NAME, true, true );
                MayaDM::GroupId groupId ( file, groupName );
                groupId.setIsHistoricallyInteresting (0);

                // Create a groupInfo object and push it in the map of shading binding groupInfos.
                GroupInfo groupInfo ( groupId, shadingEngineId, transformInstanceIndex, primitiveIndex );

                // If we have a controller element, we need also groupParts to manage the group objects.
                if ( controllerId.isValid () )
                {
                    String groupPartsName =  generateUniqueDependNodeName ( GROUP_PARTS_NAME, true, true );
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
            size_t numFaces = meshPrimitive->getFaceCount ();

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

        // Iterate over the mesh primitive elements and store for the geometry for every 
        // primitive element the shadingEngineId.
        for ( size_t primitiveIndex=0; primitiveIndex<meshPrimitivesCount; ++primitiveIndex )
        {
            // Get the current primitive element.
            const COLLADAFW::MeshPrimitive* meshPrimitive = meshPrimitives [ primitiveIndex ];

            // Get the shader engine id.
            String shadingEngineName = meshPrimitive->getMaterial ();
            COLLADAFW::MaterialId shadingEngineId = meshPrimitive->getMaterialId ();

            // Store for the geometry for every primitive element the shading engine id.
            GeometryShadingEngine geometryShadingEngine;
            geometryShadingEngine.mPrimitiveIndex = primitiveIndex;
            geometryShadingEngine.mShadingEngineId = shadingEngineId;

            // Fills the GeometryShadingEngineMap. Used to create the connections between the 
            // shading engines and the geometries. The map holds for every geometry's primitive
            // element the used shading engine. 
            mGeometryShadingEnginesMap [geometryId].push_back ( geometryShadingEngine );
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
                continue;
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
    void GeometryImporter::writeUVSets ( 
        const COLLADAFW::Mesh* mesh, 
        MayaDM::Mesh &meshNode,
        const bool originalMesh )
    {
        // Set the number of uv sets.
        const COLLADAFW::MeshVertexData& uvCoords = mesh->getUVCoords ();
        size_t numUVSets = uvCoords.getNumInputInfos ();
        if ( numUVSets == 0 ) return;
        meshNode.setUvSize ( (double)numUVSets );

        // Get the unique id.
        const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();

        // Write blocks with 4000KB for maya
        size_t blockSize = MAYA_BLOCK_SIZE / ( 2* sizeof ( double ) );
        
        // Initialise the initial index.
        size_t initialIndex = 0;

        // Go through the uv sets.
        for ( size_t i=0; i<numUVSets; ++i )
        {
            // Set the name of the current uv set.
            String uvSetName = uvCoords.getName ( i );
            meshNode.setUvSetName ( i, uvSetName );
            if ( i == 0 ) meshNode.setCurrentUVSet ( uvSetName );

            if ( originalMesh )
            {
                // Store the uv-sets in a list to know the indices for the uv-choosers 
                // (to organize multiple texture coordinate binding)
                mGeometryUvSetNamesMap [geometryId].push_back ( uvSetName );

                size_t stride = uvCoords.getStride ( i );
				COLLADABU_ASSERT ( stride > 1 && stride <= 4 );
//                 if ( stride != 2 ) 
//                     std::cerr << "Just 2d uv set data will be imported! " << std::endl;

                size_t indicesCount = uvCoords.getLength ( i );
                size_t numUvSetPoints = (indicesCount/stride)-1;
                size_t endPosition = 0, index=0; 

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
                            meshNode.appendUvSetPoints ( toLinearUnit ((*values)[initialIndex+j]) );
                            meshNode.appendUvSetPoints ( toLinearUnit ((*values)[initialIndex+j+1]) );
                        }
                        break;
                    case COLLADAFW::MeshVertexData::DATA_TYPE_DOUBLE:
                        {
                            const COLLADAFW::ArrayPrimitiveType<double>* values = uvCoords.getDoubleValues ();
                            meshNode.appendUvSetPoints ( (float) toLinearUnit ((*values)[initialIndex+j]) );
                            meshNode.appendUvSetPoints ( (float) toLinearUnit ((*values)[initialIndex+j+1]) );
                        }
                        break;
                    default:
                        std::cerr << "No valid data type for uv coordinates: " << type << std::endl;
                        continue;
                    }

                    // End the block if necessary.
                    if ( index == endPosition ) 
                        meshNode.endUvSetPoints (); 
                }

                initialIndex += indicesCount;
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeColorSets ( 
        const COLLADAFW::Mesh* mesh, 
        MayaDM::Mesh& meshNode,
        const bool originalMesh )
    {
        // Set the number of uv sets.
        const COLLADAFW::MeshVertexData& colors = mesh->getColors ();
        size_t numColorSets = colors.getNumInputInfos ();
        if ( numColorSets == 0 ) return;

//        meshNode.setColorSetSize ( sumUVSetPoints );
        meshNode.setDisplayColors ( true );

        // Initialise the initial index.
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

            if ( originalMesh )
            {
                size_t stride = colors.getStride ( c );
                COLLADABU_ASSERT ( stride == 1 || stride == 3 || stride == 4 );

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
                            continue;
                        }
                    }

                    // End the block if necessary.
                    if ( index == endPosition ) 
                        meshNode.endColorSetPoints (); 
                }

                initialIndex += indicesCount;
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::writeEdges (  
        const COLLADAFW::Mesh* mesh, 
        const EdgeList &edgeIndices, 
        MayaDM::Mesh &meshNode )
    {
        size_t numEdges = edgeIndices.size ();
        if ( numEdges > 0 )
        {
            // Without normals, we need to use soft edges (1).
            int edgh = 1;

            // With normals, it normally doesn't matter if we have hard or soft edges, because the 
            // normals make the edge smoothing. But if we have holes, we need hard edges.
            if ( ImportOptions::importNormals () ) 
                edgh = 0;

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
        EdgeMap& edgeIndicesMap, 
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
        for ( size_t primitiveIndex=0; primitiveIndex<count; ++primitiveIndex )
        {
            // Get the primitive element.
            COLLADAFW::MeshPrimitive* primitiveElement = primitiveElementsArray [ primitiveIndex ];

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
                continue;
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::appendPolygonPolyFaces ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        EdgeMap& edgeIndicesMap, 
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
        const size_t groupedVtxCount = primitiveElement->getGroupedVertexElementsCount ();

        // To handle polygons with holes:
        // Flag, if the actual face is clockwise orientated. We need this information to handle
        // polygons with holes, because this need the opposite direction of their polygons. 
        bool faceClockwiseOriented = true;

        // Polygons with holes: we have always first one polygon for any number of holes.
        // We need the first three vertexes to determine the orientation of any polygon.
        std::vector<COLLADABU::Math::Vector3*> polygonPoints;

        // Iterate over all grouped vertex elements (faces, holes, tristrips or trifans)
        // and determine the values for the maya polyFace object.
        for ( size_t groupedVtxIndex = 0; groupedVtxIndex < groupedVtxCount; ++groupedVtxIndex )
        {
            // The number of edges is always the same than the number of vertices in the current 
            // grouped vertices object. If the number is negative, the grouped object is a hole.
            int numEdges = primitiveElement->getGroupedVerticesVertexCount ( groupedVtxIndex );

            // Create the poly face
            MayaDM::polyFaces polyFace;

            // Handle the face infos.
            bool isHole = (numEdges<0);
            if ( !isHole )
                setPolygonFaceInfos ( mesh, primitiveElement, edgeIndicesMap, polyFace, numEdges, positionIndex, polygonPoints );
            else
                setPolygonHoleInfos ( mesh, primitiveElement, edgeIndicesMap, polyFace, numEdges, positionIndex, polygonPoints );

            // Handle the uv set infos.
            setPolygonUVSetInfos ( mesh, primitiveElement, polyFace, uvSetIndicesIndex, numEdges );

            // Handle the color infos.
            setPolygonColorInfos ( mesh, primitiveElement, polyFace, colorIndicesIndex, numEdges );

			//--- @Workaround for maya 2013 with single face geometries
			bool duplicateSingleFaceWorkaround = false;
			//---------------------------------------------------------

            // Start the block if necessary (Maya doesn't count hole elements, about this,
            // if the current element is a hole, don't start, except it is the very first element!)
            if ( globalFaceIndex % blockSize == 0 )
            {
                if ( !isHole )
                {
                    endPosition = globalFaceIndex+blockSize-1;
                    if ( endPosition > numGlobalFaces-1 ) 
                        endPosition = numGlobalFaces-1;
					
					//--- @Workaround for maya 2013 with single face geometries
					String versionString = getDocumentImporter()->getMayaVersion();
					if(groupedVtxCount == 1 && versionString >= "2013")
					{
						if( globalFaceIndex == 0 && endPosition == globalFaceIndex )
						{
							++mCount2013Workarounds;
							duplicateSingleFaceWorkaround = true;
							endPosition = 1;
						}
					}
					//---------------------------------------------------------

                    meshNode.startFace ( globalFaceIndex, endPosition ); 
                }
            }

            // Write the polyFace data in the maya file.
            meshNode.appendFace ( polyFace );

			//--- @Workaround for maya 2013 with single face geometries
			if( duplicateSingleFaceWorkaround )
				meshNode.appendFace ( polyFace );
			//---------------------------------------------------------

            // Check if the next element is a hole.
            bool nextElementIsHole = false;
            if ( groupedVtxIndex+1 < groupedVtxCount )
            {
                int nextElementNumEdges = primitiveElement->getGroupedVerticesVertexCount ( (size_t)groupedVtxIndex+1 );
                nextElementIsHole = (nextElementNumEdges<0);
            }

            // End the block if necessary (if the next element is a hole, don't close).
            if ( duplicateSingleFaceWorkaround || (globalFaceIndex == endPosition && !nextElementIsHole) ) 
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
        const EdgeMap& edgeIndicesMap, 
        MayaDM::Mesh &meshNode,
        const size_t blockSize, 
        const size_t numGlobalFaces, 
        size_t& globalFaceIndex, 
        size_t& endPosition )
    {
        // Get the position and the normal indices.
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // The points of an edge
        int edgeStartVertexIdx=0, edgeEndVertexIdx=0;

        // The current index in the positions list.
        size_t initialPositionIndex=0;
        size_t positionIndex=0;

        size_t uvSetIndicesIndex = 0;
        size_t colorIndicesIndex = 0;

        COLLADAFW::Edge edge;

        // Iterate over the grouped vertices and get the edges for every group.
        COLLADAFW::Trifans* trifans = (COLLADAFW::Trifans*) primitiveElement;
        COLLADAFW::Trifans::VertexCountArray& vertexCountArray = trifans->getGroupedVerticesVertexCountArray ();
        size_t groupedVtxCount = vertexCountArray.getCount ();
        for ( size_t groupedVtxIndex=0; groupedVtxIndex<groupedVtxCount; ++groupedVtxIndex )
        {
            size_t initialUVSetIndicesIndex = uvSetIndicesIndex;
            size_t initialColorIndicesIndex = colorIndicesIndex;

            // A trifan has always triangles, which have 3 edges
            size_t triangleEdgeCounter = 0;

            // The number of vertices in the current vertex group.
            unsigned int vertexCount = vertexCountArray [groupedVtxIndex];

            // The poly face element pointer.
            MayaDM::polyFaces* polyFace;

            // Determine the number of edges and iterate over it.
            unsigned int numEdges = ( vertexCount - 3 ) * 3 + 3;

			//--- @Workaround for maya 2013 with single face geometries
			bool duplicateSingleFaceWorkaround = false;
			//---------------------------------------------------------

            for ( unsigned int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
            {
                if ( triangleEdgeCounter == 0 )
                {
                    // Create the poly face
                    polyFace = new MayaDM::polyFaces ();

                    // Handle the edge informations.
                    polyFace->f.faceEdgeCount = 3;
                    polyFace->f.edgeIdValue = new int[3];
                }

                // Increment the current triangle edge counter, so we know if we have the full triangle.
                ++triangleEdgeCounter;

                // Get the start edge index
                if ( triangleEdgeCounter > 1 )
                    edgeStartVertexIdx = positionIndices[positionIndex];
                else edgeStartVertexIdx = positionIndices[initialPositionIndex];

                // With the third edge of a triangle, we have to go back to the trifans root.
                if ( triangleEdgeCounter < 3 )
                    edgeEndVertexIdx = positionIndices[++positionIndex];
                else edgeEndVertexIdx = positionIndices[initialPositionIndex];

                // Set the edge vertex index values into an edge object.
                edge.setVertexIndices ( edgeStartVertexIdx, edgeEndVertexIdx );

                // Variable for the current edge index.
                int edgeIndexValue = 0;

                // Get the edge index value from the edge list.
                getEdgeIndex ( edge, edgeIndicesMap, edgeIndexValue );

                // Set the edge list index into the poly face
                polyFace->f.edgeIdValue [triangleEdgeCounter-1] = edgeIndexValue;

                // Reset the edge counter, if we have all three edges of a triangle.
                if ( triangleEdgeCounter == 3 ) 
                {
                    triangleEdgeCounter = 0;
                    --positionIndex;

                    // Handle the uv set infos.
                    setTrifansUVSetInfos ( mesh, primitiveElement, *polyFace, initialUVSetIndicesIndex, uvSetIndicesIndex );
                    ++uvSetIndicesIndex;

                    // Handle the uv set infos.
                    setTrifansColorInfos ( mesh, primitiveElement, *polyFace, initialColorIndicesIndex, colorIndicesIndex );
                    ++colorIndicesIndex;

                    // Start the block if necessary
                    if ( globalFaceIndex % blockSize == 0 )
                    {
                        endPosition = globalFaceIndex+blockSize-1;
                        if ( endPosition > numGlobalFaces-1 ) 
                            endPosition = numGlobalFaces-1;

						//--- @Workaround for maya 2013 with single face geometries
						String versionString = getDocumentImporter()->getMayaVersion();
						if(numEdges == 3 && versionString == "2013")
						{
							if( globalFaceIndex == 0 && endPosition == globalFaceIndex )
							{
								++mCount2013Workarounds;
								duplicateSingleFaceWorkaround = true;
								endPosition = 1;
							}
						}
						//---------------------------------------------------------

                        meshNode.startFace ( globalFaceIndex, endPosition ); 
                    }

                    // Write the polyFace data in the maya file.
                    meshNode.appendFace ( *polyFace );

					//--- @Workaround for maya 2013 with single face geometries
					if( duplicateSingleFaceWorkaround )
						meshNode.appendFace ( *polyFace );
					//---------------------------------------------------------

                    // End the block if necessary.
                    if ( duplicateSingleFaceWorkaround || globalFaceIndex == endPosition ) 
                        meshNode.endFace (); 

                    // Increment the face index.
                    ++globalFaceIndex;

                    // We don't need the poly face object anymore.
                    delete polyFace;
                }
            }

            // Increment the initial trifan position index for the next trifan object.
            positionIndex += 2;
            initialPositionIndex += vertexCount;

            // Get the next tristrips <p> element.
            uvSetIndicesIndex += 2;
            colorIndicesIndex += 2;
        }
    }

    // --------------------------------------------
    void GeometryImporter::appendTristripsPolyFaces ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const EdgeMap& edgeIndicesMap, 
        MayaDM::Mesh &meshNode,
        const size_t blockSize, 
        const size_t numGlobalFaces, 
        size_t& globalFaceIndex, 
        size_t& endPosition )
    {
        // Get the position indices.
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // The points of an edge
        int edgeStartVertexIdx=0, edgeEndVertexIdx=0;

        // The current index in the positions list.
        size_t initialPositionIndex=0;
        size_t positionIndex=0;

        size_t uvSetIndicesIndex = 0;
        size_t colorIndicesIndex = 0;

        COLLADAFW::Edge edge;

        // Iterate over the grouped vertices and get the edges for every group.
        COLLADAFW::Tristrips* tristrips = (COLLADAFW::Tristrips*) primitiveElement;
        COLLADAFW::Tristrips::VertexCountArray& vertexCountArray = tristrips->getGroupedVerticesVertexCountArray ();
        size_t groupedVtxCount = vertexCountArray.getCount ();
        for ( size_t groupedVtxIndex=0; groupedVtxIndex<groupedVtxCount; ++groupedVtxIndex )
        {
            // The poly face pointer.
            MayaDM::polyFaces* polyFace;

            // A trifan has always triangles, which have 3 edges
            size_t triangleEdgeCounter = 0;

            // The number of vertices in the current vertex group.
            unsigned int vertexCount = vertexCountArray [groupedVtxIndex];

            // We have to turn the direction of every second triangle.
            bool changeDirection = true;

            // Determine the number of edges and iterate over it.
            unsigned int numEdges = ( vertexCount - 3 ) * 3 + 3;

			//--- @Workaround for maya 2013 with single face geometries
			bool duplicateSingleFaceWorkaround = false;
			//---------------------------------------------------------

			for ( unsigned int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
            {
                if ( triangleEdgeCounter == 0 )
                {
                    // Create the poly face
                    polyFace = new MayaDM::polyFaces ();

                    // Change the direction for every second triangle.
                    changeDirection = !changeDirection;

                    // Handle the edge informations.
                    polyFace->f.faceEdgeCount = 3;
                    polyFace->f.edgeIdValue = new int[3];
                }

                // Increment the current triangle edge counter, so we know if we have the full triangle.
                ++triangleEdgeCounter;

                // Get the start edge index
                edgeStartVertexIdx = positionIndices[positionIndex];

                // With the third edge of a triangle, we have to go back to the trifans root.
                if ( triangleEdgeCounter < 3 )
                    edgeEndVertexIdx = positionIndices[++positionIndex];
                else edgeEndVertexIdx = positionIndices[initialPositionIndex];

                // Set the edge vertex index values into an edge object.
                edge.setVertexIndices ( edgeStartVertexIdx, edgeEndVertexIdx );

                // Variable for the current edge index.
                int edgeIndexValue;

                // Get the edge index value from the edge list.
                getEdgeIndex ( edge, edgeIndicesMap, edgeIndexValue );

                // Set the edge list index into the poly face
                if ( changeDirection )
                {
                    edgeIndexValue = -( edgeIndexValue + 1 );

                    if ( triangleEdgeCounter == 1 ) 
                        polyFace->f.edgeIdValue[0] = edgeIndexValue;
                    if ( triangleEdgeCounter == 2 ) 
                        polyFace->f.edgeIdValue[2] = edgeIndexValue;
                    if ( triangleEdgeCounter == 3 ) 
                        polyFace->f.edgeIdValue[1] = edgeIndexValue;
                }
                else
                {
                    polyFace->f.edgeIdValue[triangleEdgeCounter-1] = edgeIndexValue;
                }

                // Reset the edge counter, if we have all three edges of a triangle.
                if ( triangleEdgeCounter == 3 ) 
                {
                    triangleEdgeCounter = 0;
                    --positionIndex;
                    initialPositionIndex = positionIndex;

                    // Handle the uv set infos.
                    setTristripsUVSetInfos ( mesh, primitiveElement, *polyFace, uvSetIndicesIndex, changeDirection );
                    ++uvSetIndicesIndex;

                    // Handle the uv set infos.
                    setTristripsColorInfos ( mesh, primitiveElement, *polyFace, colorIndicesIndex, changeDirection );
                    ++colorIndicesIndex;

                    // Start the block if necessary
                    if ( globalFaceIndex % blockSize == 0 )
                    {
                        endPosition = globalFaceIndex+blockSize-1;
                        if ( endPosition > numGlobalFaces-1 ) 
                            endPosition = numGlobalFaces-1;
						
						//--- @Workaround for maya 2013 with single face geometries
						String versionString = getDocumentImporter()->getMayaVersion();
						if(versionString == "2013")
						{
							if( globalFaceIndex == 0 && endPosition == globalFaceIndex )
							{
								++mCount2013Workarounds;
								duplicateSingleFaceWorkaround = true;
								endPosition = 1;
							}
						}
						//---------------------------------------------------------

                        meshNode.startFace ( globalFaceIndex, endPosition ); 
                    }

                    // Write the polyFace data in the maya file.
                    meshNode.appendFace ( *polyFace );

					//--- @Workaround for maya 2013 with single face geometries
					if( duplicateSingleFaceWorkaround )
						meshNode.appendFace ( *polyFace );
					//---------------------------------------------------------

                    // End the block if necessary.
                    if ( duplicateSingleFaceWorkaround || globalFaceIndex == endPosition ) 
                        meshNode.endFace (); 

                    // Increment the face index.
                    ++globalFaceIndex;

                    // We don't need the poly face object anymore.
                    delete polyFace;
                }
            }

            // Increment the initial tristrip position index for the next tristrip object.
            positionIndex += 2;
            initialPositionIndex = positionIndex;

            // Get the next tristrips <p> element.
            uvSetIndicesIndex += 2;
            colorIndicesIndex += 2;
        }
    }

    // --------------------------------------------
    void GeometryImporter::setPolygonFaceInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        const EdgeMap& edgeIndicesMap, 
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

        int edgeStartVertexIdx=0, edgeEndVertexIdx=0;

        COLLADAFW::Edge edge;

        // Go through the edges and determine the face values.
        for ( int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
        {
            // Set the edge vertex index values into an edge object.
            edgeStartVertexIdx = positionIndices[positionIndex];
            edgeEndVertexIdx = 0;

            if ( edgeIndex<(numEdges-1) )
                edgeEndVertexIdx = positionIndices[++positionIndex];
            else edgeEndVertexIdx = positionIndices[positionIndex-numEdges+1];

            // Create the edge.
            edge.setVertexIndices ( edgeStartVertexIdx, edgeEndVertexIdx );

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
                polygonPoints.push_back ( getVertexPosition ( mesh, edgeStartVertexIdx ) );
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
        const EdgeMap& edgeIndicesMap, 
        MayaDM::polyFaces &polyFace, 
        int &numEdges, 
        size_t &positionIndex, 
        std::vector<COLLADABU::Math::Vector3*> & polygonPoints )
    {
        // Get the position indices
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();
        int edgeStartVertexIdx=0, edgeEndVertexIdx=0;

        // Handle a hole element.
        numEdges *= -1;

        COLLADAFW::Edge edge;

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
            edgeStartVertexIdx = positionIndices[positionIndex];
            edgeEndVertexIdx = 0;
            if ( edgeIndex<(numEdges-1) )
                edgeEndVertexIdx = positionIndices[++positionIndex];
            else edgeEndVertexIdx = positionIndices[positionIndex-numEdges+1];

            // Create the edge.
            edge.setVertexIndices ( edgeStartVertexIdx, edgeEndVertexIdx );

            // Polygons with holes: Get the first three polygon vertices to determine 
            // the polygon's orientation.
            if ( edgeIndex < 3 )
            {
                // Store the vertex positions of the current start point.
                holePoints.push_back ( getVertexPosition ( mesh, edgeStartVertexIdx ) );
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
    void GeometryImporter::setTristripsUVSetInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        MayaDM::polyFaces &polyFace, 
        const size_t uvSetIndicesIndex, 
        const bool changeDirection )
    {
        const int numEdges = 3;

        const COLLADAFW::IndexListArray& uvSetIndicesArray = primitiveElement->getUVCoordIndicesArray ();
        size_t numUVSets = uvSetIndicesArray.getCount ();
        if ( numUVSets == 0 ) return;

        polyFace.mu = new MayaDM::polyFaces::MU [ numUVSets ];
        polyFace.muCount = numUVSets;
        for ( size_t i=0; i<numUVSets; ++i )
        {
            // Get the index of the uv set
            const COLLADAFW::IndexList* uvCoordIndices = primitiveElement->getUVCoordIndices ( i );
            String uvSetName = uvCoordIndices->getName ();
            size_t uvSetPhysicalIndex = mesh->getUVSetIndexByName ( uvSetName );

            // Store the information about the used set of the input element.
            size_t uvSetIndex = uvCoordIndices->getSetIndex ();
            const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
            PrimitiveInputSet primitiveInputSet;
            primitiveInputSet.setGeometryId ( geometryId );
            primitiveInputSet.setShadingEngineId ( primitiveElement->getMaterialId () );
            primitiveInputSet.setInputSetName ( uvSetName );
            primitiveInputSet.setPhysicalIndex ( uvSetPhysicalIndex ); 
            primitiveInputSet.setInputSetIndex ( uvSetIndex );
            mTexCoordInputSetsMap [geometryId].push_back ( primitiveInputSet );

            const COLLADAFW::MeshVertexData& meshUVCoords = mesh->getUVCoords ();
            polyFace.mu[i].uvSet = (int) uvSetPhysicalIndex;
            polyFace.mu[i].faceUVCount = numEdges;
            polyFace.mu[i].uvIdValue = new int [numEdges];

            if ( !changeDirection )
            {
                for ( size_t j=0; j<numEdges; ++j )
                {
                    size_t currentIndexPosition = j + (size_t)uvSetIndicesIndex;
                    unsigned int currentIndex = uvCoordIndices->getIndex ( currentIndexPosition );

                    // Decrement the index values
                    size_t initialIndex = uvCoordIndices->getInitialIndex ();
                    polyFace.mu[i].uvIdValue [j] = currentIndex - (unsigned int)initialIndex;
                }
            }
            else
            {
                // We want the order 1 - 0 - 2 instead of 0 - 1 - 2
                for ( size_t j=0; j<numEdges; ++j )
                {
                    size_t index = 0; 
                    switch ( j )
                    {
                    case 0: index = 1; break;
                    case 1: index = 0; break;
                    case 2: index = 2; break;
                    }
                    size_t currentIndexPosition = index + (size_t)uvSetIndicesIndex;
                    unsigned int currentIndex = uvCoordIndices->getIndex ( currentIndexPosition );

                    // Decrement the index values
                    size_t initialIndex = uvCoordIndices->getInitialIndex ();
                    polyFace.mu[i].uvIdValue [j] = currentIndex - (unsigned int)initialIndex;
                }
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::setTristripsColorInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        MayaDM::polyFaces &polyFace, 
        const size_t colorIndicesIndex, 
        const bool changeDirection )
    {
        const int numEdges = 3; 

        const COLLADAFW::IndexListArray& colorIndicesArray = primitiveElement->getColorIndicesArray ();
        size_t numColorInputs = colorIndicesArray.getCount ();
        if ( numColorInputs == 0 ) return;

        polyFace.mc = new MayaDM::polyFaces::MC [ numColorInputs ];
        polyFace.mcCount = numColorInputs;
        for ( size_t i=0; i<numColorInputs; ++i )
        {
            // Get the index of the uv set
            const COLLADAFW::IndexList* colorIndices = primitiveElement->getColorIndices ( i );
            String colorInputName = colorIndices->getName ();
            size_t colorPhysicalIndex = mesh->getColorIndexByName ( colorInputName );

            // Store the information about the used set of the input element.
            size_t colorSetIndex = colorIndices->getSetIndex ();
            const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
            PrimitiveInputSet primitiveInputSet;
            primitiveInputSet.setGeometryId ( geometryId );
            primitiveInputSet.setShadingEngineId ( primitiveElement->getMaterialId () );
            primitiveInputSet.setPhysicalIndex ( colorPhysicalIndex ); 
            primitiveInputSet.setInputSetIndex ( colorSetIndex );
            mColorInputSetsMap [geometryId].push_back ( primitiveInputSet );

            const COLLADAFW::MeshVertexData& meshColors = mesh->getColors ();
            polyFace.mc[i].colorSet = (int) colorPhysicalIndex;
            polyFace.mc[i].faceColorCount = numEdges;
            polyFace.mc[i].colorIdValue = new int [numEdges];

            if ( !changeDirection )
            {
                for ( int j=0; j<numEdges; ++j )
                {
                    size_t currentIndexPosition = j + colorIndicesIndex;
                    unsigned int currentIndex = colorIndices->getIndex ( currentIndexPosition );

                    // Decrement the index values
                    size_t initialIndex = colorIndices->getInitialIndex ();
                    polyFace.mc[i].colorIdValue [j] = currentIndex - (unsigned int)initialIndex;
                }
            }
            else
            {
                for ( int j=0; j<numEdges; ++j )
                {
                    size_t index = 0; 
                    switch ( j )
                    {
                    case 0: index = 1; break;
                    case 1: index = 0; break;
                    case 2: index = 2; break;
                    }
                    size_t currentIndexPosition = index + colorIndicesIndex;
                    unsigned int currentIndex = colorIndices->getIndex ( currentIndexPosition );

                    // Decrement the index values
                    size_t initialIndex = colorIndices->getInitialIndex ();
                    polyFace.mc[i].colorIdValue [j] = currentIndex - (unsigned int)initialIndex;
                }
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::setPolygonUVSetInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        MayaDM::polyFaces &polyFace, 
        size_t& uvSetIndicesIndex, 
        const int numEdges )
    {
        const COLLADAFW::IndexListArray& uvSetIndicesArray = primitiveElement->getUVCoordIndicesArray ();
        size_t numUVSets = uvSetIndicesArray.getCount ();
        if ( numUVSets == 0 ) return;

        polyFace.mu = new MayaDM::polyFaces::MU [ numUVSets ];
        polyFace.muCount = numUVSets;
        for ( size_t i=0; i<numUVSets; ++i )
        {
            // Get the index of the uv set
            const COLLADAFW::IndexList* uvCoordIndices = primitiveElement->getUVCoordIndices ( i );
            String uvSetName = uvCoordIndices->getName ();
            size_t uvSetPhysicalIndex = mesh->getUVSetIndexByName ( uvSetName );

            // Store the information about the used set of the input element.
            size_t uvSetSetIndex = uvCoordIndices->getSetIndex ();
            const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
            PrimitiveInputSet primitiveInputSet;
            primitiveInputSet.setGeometryId ( geometryId );
            primitiveInputSet.setShadingEngineId ( primitiveElement->getMaterialId () );
            primitiveInputSet.setInputSetName ( uvSetName );
            primitiveInputSet.setPhysicalIndex ( uvSetPhysicalIndex ); 
            primitiveInputSet.setInputSetIndex ( uvSetSetIndex );
            mTexCoordInputSetsMap [geometryId].push_back ( primitiveInputSet );

            const COLLADAFW::MeshVertexData& meshUVCoords = mesh->getUVCoords ();
            polyFace.mu[i].uvSet = (int) uvSetPhysicalIndex;
            polyFace.mu[i].faceUVCount = numEdges;
            polyFace.mu[i].uvIdValue = new int [numEdges];

            for ( int j=0; j<numEdges; ++j )
            {
                size_t currentIndexPosition = j + uvSetIndicesIndex;
                unsigned int currentIndex = uvCoordIndices->getIndex ( currentIndexPosition );

                // Decrement the index values
                size_t initialIndex = uvCoordIndices->getInitialIndex ();
                polyFace.mu[i].uvIdValue [j] = currentIndex - (unsigned int)initialIndex;
            }
        }
        // Increment the current uv set index for the number of edges.
        uvSetIndicesIndex += numEdges;
    }

    // --------------------------------------------
    void GeometryImporter::setPolygonColorInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        MayaDM::polyFaces &polyFace, 
        size_t& colorIndicesIndex, 
        const int numEdges )
    {
        const COLLADAFW::IndexListArray& colorIndicesArray = primitiveElement->getColorIndicesArray ();
        size_t numColorInputs = colorIndicesArray.getCount ();
        if ( numColorInputs == 0 ) return;

        polyFace.mc = new MayaDM::polyFaces::MC [ numColorInputs ];
        polyFace.mcCount = numColorInputs;
        for ( size_t i=0; i<numColorInputs; ++i )
        {
            // Get the index of the uv set
            const COLLADAFW::IndexList* colorIndices = primitiveElement->getColorIndices ( i );
            String colorInputName = colorIndices->getName ();
            size_t colorPhysicalIndex = mesh->getColorIndexByName ( colorInputName );

            // Store the information about the used set of the input element.
            size_t colorSetIndex = colorIndices->getSetIndex ();
            const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
            PrimitiveInputSet primitiveInputSet;
            primitiveInputSet.setGeometryId ( geometryId );
            primitiveInputSet.setShadingEngineId ( primitiveElement->getMaterialId () );
            primitiveInputSet.setPhysicalIndex ( colorPhysicalIndex ); 
            primitiveInputSet.setInputSetIndex ( colorSetIndex );
            mColorInputSetsMap [geometryId].push_back ( primitiveInputSet );

            const COLLADAFW::MeshVertexData& meshColors = mesh->getColors ();
            polyFace.mc[i].colorSet = (int) colorPhysicalIndex;
            polyFace.mc[i].faceColorCount = numEdges;
            polyFace.mc[i].colorIdValue = new int [numEdges];

            for ( int j=0; j<numEdges; ++j )
            {
                size_t currentIndexPosition = j + colorIndicesIndex;
                unsigned int currentIndex = colorIndices->getIndex ( currentIndexPosition );

                // Decrement the index values
                size_t initialIndex = colorIndices->getInitialIndex ();
                polyFace.mc[i].colorIdValue [j] = currentIndex - (unsigned int)initialIndex;
            }
        }
        // Increment the current uv set index for the number of edges.
        colorIndicesIndex += numEdges;
    }

    // --------------------------------------------
    void GeometryImporter::setTrifansUVSetInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        MayaDM::polyFaces &polyFace, 
        const size_t initialUVSetIndicesIndex, 
        const size_t uvSetIndicesIndex )
    {
        const int numEdges = 3;

        const COLLADAFW::IndexListArray& uvSetIndicesArray = primitiveElement->getUVCoordIndicesArray ();
        size_t numUVSets = uvSetIndicesArray.getCount ();
        if ( numUVSets == 0 ) return;

        polyFace.mu = new MayaDM::polyFaces::MU [ numUVSets ];
        polyFace.muCount = numUVSets;
        for ( size_t i=0; i<numUVSets; ++i )
        {
            // Get the index of the uv set
            const COLLADAFW::IndexList* uvCoordIndices = primitiveElement->getUVCoordIndices ( i );
            String uvSetName = uvCoordIndices->getName ();
            size_t uvSetPhysicalIndex = mesh->getUVSetIndexByName ( uvSetName );

            // Store the information about the used set of the input element.
            size_t uvSetIndex = uvCoordIndices->getSetIndex ();
            const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
            PrimitiveInputSet primitiveInputSet;
            primitiveInputSet.setGeometryId ( geometryId );
            primitiveInputSet.setShadingEngineId ( primitiveElement->getMaterialId () );
            primitiveInputSet.setInputSetName ( uvSetName );
            primitiveInputSet.setPhysicalIndex ( uvSetPhysicalIndex ); 
            primitiveInputSet.setInputSetIndex ( uvSetIndex );
            mTexCoordInputSetsMap [geometryId].push_back ( primitiveInputSet );

            const COLLADAFW::MeshVertexData& meshUVCoords = mesh->getUVCoords ();
            polyFace.mu[i].uvSet = (int) uvSetPhysicalIndex;
            polyFace.mu[i].faceUVCount = numEdges;
            polyFace.mu[i].uvIdValue = new int [numEdges];

            for ( int j=0; j<numEdges; ++j )
            {
                size_t currentIndexPosition = 0;
                if ( j== 0 ) currentIndexPosition = initialUVSetIndicesIndex;
                else currentIndexPosition = j + uvSetIndicesIndex;
                unsigned int currentIndex = uvCoordIndices->getIndex ( currentIndexPosition );

                // Decrement the index values
                size_t initialIndex = uvCoordIndices->getInitialIndex ();
                polyFace.mu[i].uvIdValue [j] = currentIndex - (unsigned int)initialIndex;
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::setTrifansColorInfos ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::MeshPrimitive* primitiveElement, 
        MayaDM::polyFaces &polyFace, 
        const size_t initialColorIndicesIndex,
        const size_t colorIndicesIndex )
    {
        const int numEdges = 3;

        const COLLADAFW::IndexListArray& colorIndicesArray = primitiveElement->getColorIndicesArray ();
        size_t numColorInputs = colorIndicesArray.getCount ();
        if ( numColorInputs == 0 ) return;

        polyFace.mc = new MayaDM::polyFaces::MC [ numColorInputs ];
        polyFace.mcCount = numColorInputs;
        for ( size_t i=0; i<numColorInputs; ++i )
        {
            // Get the index of the uv set
            const COLLADAFW::IndexList* colorIndices = primitiveElement->getColorIndices ( i );
            String colorInputName = colorIndices->getName ();
            size_t colorPhysicalIndex = mesh->getColorIndexByName ( colorInputName );

            // Store the information about the used set of the input element.
            size_t colorSetIndex = colorIndices->getSetIndex ();
            const COLLADAFW::UniqueId& geometryId = mesh->getUniqueId ();
            PrimitiveInputSet primitiveInputSet;
            primitiveInputSet.setGeometryId ( geometryId );
            primitiveInputSet.setShadingEngineId ( primitiveElement->getMaterialId () );
            primitiveInputSet.setPhysicalIndex ( colorPhysicalIndex ); 
            primitiveInputSet.setInputSetIndex ( colorSetIndex );
            mColorInputSetsMap [geometryId].push_back ( primitiveInputSet );

            const COLLADAFW::MeshVertexData& meshColors = mesh->getColors ();
            polyFace.mc[i].colorSet = (int) colorPhysicalIndex;
            polyFace.mc[i].faceColorCount = numEdges;
            polyFace.mc[i].colorIdValue = new int [numEdges];

            for ( int j=0; j<numEdges; ++j )
            {
                size_t currentIndexPosition = 0;
                if ( j== 0 ) currentIndexPosition = initialColorIndicesIndex;
                else currentIndexPosition = j + colorIndicesIndex;
                unsigned int currentIndex = colorIndices->getIndex ( currentIndexPosition );

                // Decrement the index values
                size_t initialIndex = colorIndices->getInitialIndex ();
                polyFace.mc[i].colorIdValue [j] = currentIndex - (unsigned int)initialIndex;
            }
        }
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

        // COLLADAFW::Edge count
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
    bool GeometryImporter::getEdgeIndex ( 
        const COLLADAFW::Edge& edge, 
        const EdgeMap& edgeIndicesMap, 
        int& edgeIndex )
    {
        // Find the index of the edge in the map of edges to get the index in the list.
        EdgeMap::const_iterator it = edgeIndicesMap.find ( edge );
        if ( it == edgeIndicesMap.end() ) 
        {
            // The edge has to be in the map!
            std::cerr << "Edge not found: " << edge[0] << ", " << edge[1] << std::endl;
            return false;
        }
        edgeIndex = (int)it->second; 

        // Revert it, if the order is different.
        if ( edge.isReverse () ) 
            edgeIndex = -( edgeIndex + 1 );

        return true;
    }

    // --------------------------------------------
    void GeometryImporter::getEdgeIndices ( 
        const COLLADAFW::Mesh* mesh, 
        EdgeList& edgeIndices, 
        EdgeMap& edgeIndicesMap )
    {
        // Implementation for multiple primitive elements.
        const COLLADAFW::MeshPrimitiveArray& primitiveElementsArray = mesh->getMeshPrimitives ();
        size_t count = primitiveElementsArray.getCount ();
        for ( size_t i=0; i<count; ++i )
        {
            const COLLADAFW::MeshPrimitive* primitiveElement = primitiveElementsArray [ i ];

            // Determine the edge indices (unique edges, also for multiple primitive elements).
            appendEdgeIndices ( primitiveElement, edgeIndices, edgeIndicesMap );
        }
    }

    //-----------------------------
    void GeometryImporter::appendEdgeIndices (
        const COLLADAFW::MeshPrimitive* primitiveElement,
        EdgeList& edgeIndices,
        EdgeMap& edgeIndicesMap )
    {
        COLLADAFW::MeshPrimitive::PrimitiveType primitiveType = primitiveElement->getPrimitiveType ();
        switch ( primitiveType )
        {
        case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
            appendTrifansEdgeIndices ( primitiveElement, edgeIndices, edgeIndicesMap );
            break;
        case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
            appendTristripsEdgeIndices ( primitiveElement, edgeIndices, edgeIndicesMap );
            break;
        case COLLADAFW::MeshPrimitive::POLYGONS:
        case COLLADAFW::MeshPrimitive::POLYLIST:
        case COLLADAFW::MeshPrimitive::TRIANGLES:
            appendPolygonEdgeIndices ( primitiveElement, edgeIndices, edgeIndicesMap );
            break;
        default:
            std::cerr << "Primitive type not implemented!" << std::endl;
            COLLADABU_ASSERT ( "Primitive type not implemented!");
        }
    }

    //-----------------------------
    void GeometryImporter::appendPolygonEdgeIndices (
        const COLLADAFW::MeshPrimitive* primitiveElement,
        EdgeList& edgeIndices,
        EdgeMap& edgeIndicesMap )
    {
        // Get the number of grouped vertex elements (faces, holes, tristrips or trifans).
        const size_t groupedVertexElementsCount = primitiveElement->getGroupedVertexElementsCount ();

        // Get the position indices.
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // The points of an edge
        int edgeStartVertexIdx=0, edgeEndVertexIdx=0;

        // The current index in the positions list.
        size_t positionIndex=0;

        // TODO Possibility to be faster, if we preallocate the memory of the vector...
//         // Iterate over the faces and count the edges of the current primitive element.
//         int numPrimitiveEdges = 0;
//         for ( size_t i=0; i<groupedVertexElementsCount; ++i )
//         {
//             // The number of edges is always the same
//             // than the number of vertices in the current face.
//             numPrimitiveEdges += primitiveElement->getGroupedVerticesVertexCount ( i );
//         }
// 
//         // Get the current number of already written edges.
//         size_t edgeIndicesIndex = 0;
//         if ( edgeIndices.size () > 0 ) 
//             edgeIndicesIndex = edgeIndices.size () - 1;
// 
//         // Preallocate the memory in the vector
//         edgeIndices.reserve ( edgeIndices.size () + numPrimitiveEdges );

        // The new generated edge.
        COLLADAFW::Edge edge;

        // Iterate over the faces and get the edges.
        for ( size_t faceIndex=0; faceIndex<groupedVertexElementsCount; ++faceIndex )
        {
            // The number of edges is always the same
            // than the number of vertices in the current face.
            int numEdges = primitiveElement->getGroupedVerticesVertexCount ( faceIndex );

            // Reverse for holes.
            if ( numEdges < 0 ) numEdges *= -1;

            // Go through the edges of the current face and determine the edge values.
            for ( int edgeIndex=0; edgeIndex<numEdges; ++edgeIndex )
            {
                // Set the edge vertex index values into an edge object.
                edgeStartVertexIdx = positionIndices[positionIndex];

                if ( edgeIndex<(numEdges-1) )
                    edgeEndVertexIdx = positionIndices[++positionIndex];
                else edgeEndVertexIdx = positionIndices[positionIndex-numEdges+1];

                // The order in an edge will be changed, if the endIndex is greater then the start index.
                edge.setVertexIndices ( edgeStartVertexIdx, edgeEndVertexIdx );

                // Appends the data of an edge to the edgeIndices list,
                // if it is not already in the list.
                appendEdge ( edge, edgeIndices, edgeIndicesMap );
            }

            // Increment the positions index for the next face, if it is a triangle or polygon.
            // A trifan has the first edge of the next face always at the position of the last edge.
            ++positionIndex;
        }

//         // Just reserve the really used memory.
//         edgeIndices.reserve ( edgeIndices.size () );
    }

    //-----------------------------
    void GeometryImporter::appendEdge (
        const COLLADAFW::Edge& edge,
        EdgeList& edgeIndices,
        EdgeMap& edgeIndicesMap )
    {
        // Check if the current edge already exists in the map of edges.
        EdgeMap::iterator it = edgeIndicesMap.find ( edge );
        if ( it != edgeIndicesMap.end () ) return;

        // Push the new edge into the map with it's index value.
        edgeIndicesMap[edge] = edgeIndices.size ();

        // Push the new edge into the vector of edge indices.
        // We use it to write the list of edges into
        // the maya file. The vector is already sorted.
        edgeIndices.push_back ( edge );
    }

    //-----------------------------
    void GeometryImporter::appendTrifansEdgeIndices (
        const COLLADAFW::MeshPrimitive* primitiveElement,
        EdgeList& edgeIndices,
        EdgeMap& edgeIndicesMap )
    {
        // Get the position indices.
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // The points of an edge
        int edgeStartVertexIdx=0, edgeEndVertexIdx=0;

        // The current index in the positions list.
        size_t initialPositionIndex=0;
        size_t positionIndex=0;

        // Iterate over the grouped vertices and get the edges for every group.
        COLLADAFW::Trifans* trifans = (COLLADAFW::Trifans*) primitiveElement;
        COLLADAFW::Trifans::VertexCountArray& vertexCountArray = trifans->getGroupedVerticesVertexCountArray ();
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
                    edgeStartVertexIdx = positionIndices[positionIndex];
                else edgeStartVertexIdx = positionIndices[initialPositionIndex];

                // With the third edge of a triangle, we have to go back to the trifans root.
                if ( triangleEdgeCounter < 3 )
                    edgeEndVertexIdx = positionIndices[++positionIndex];
                else edgeEndVertexIdx = positionIndices[initialPositionIndex];

                COLLADAFW::Edge edge ( edgeStartVertexIdx, edgeEndVertexIdx );

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
    void GeometryImporter::appendTristripsEdgeIndices (
        const COLLADAFW::MeshPrimitive* primitiveElement,
        EdgeList& edgeIndices,
        EdgeMap& edgeIndicesMap )
    {
        // Get the position indices.
        const COLLADAFW::UIntValuesArray& positionIndices = primitiveElement->getPositionIndices ();

        // The points of an edge
        int edgeStartVertexIdx=0, edgeEndVertexIdx=0;

        // The current index in the positions list.
        size_t initialPositionIndex=0;
        size_t positionIndex=0;

        // Iterate over the grouped vertices and get the edges for every group.
        COLLADAFW::Tristrips* trifans = (COLLADAFW::Tristrips*) primitiveElement;
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
                edgeStartVertexIdx = positionIndices[positionIndex];

                // With the third edge of a triangle, we have to go back to the trifans root.
                if ( triangleEdgeCounter < 3 )
                    edgeEndVertexIdx = positionIndices[++positionIndex];
                else edgeEndVertexIdx = positionIndices[initialPositionIndex];

                COLLADAFW::Edge edge ( edgeStartVertexIdx, edgeEndVertexIdx );

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

    // --------------------------------------------
    const std::vector<GeometryImporter::GeometryShadingEngine>* GeometryImporter::findGeomtryShadingEngines ( 
        const COLLADAFW::UniqueId& geometryId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<GeometryShadingEngine> >::const_iterator it;
        it = mGeometryShadingEnginesMap.find ( geometryId );
        if ( it == mGeometryShadingEnginesMap.end () )
        {
            return 0;
        }
        return &it->second;
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
    const size_t GeometryImporter::findPrimitivesCount ( const COLLADAFW::UniqueId& geometryId )
    {
        UniqueIdSizeTMap::const_iterator it = mGeometryIdPrimitivesCountMap.find ( geometryId );
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
    GeometryImporter::MeshControllerData* GeometryImporter::findMeshControllerDataByControllerId ( 
        const COLLADAFW::UniqueId& controllerId )
    {
        for ( size_t i=0; i<mMeshControllerDataList.size (); ++i )
        {
            MeshControllerData& meshControllerData = mMeshControllerDataList [i];
            if ( meshControllerData.getControllerId () == controllerId )
            {
                return &meshControllerData;
            }
        }
        return 0;
    }

    // --------------------------------------------
    const std::vector<GeometryImporter::PrimitiveInputSet>* GeometryImporter::findTexCoordInputSets ( 
        const COLLADAFW::UniqueId& geometryId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<PrimitiveInputSet> >::const_iterator it;
        it = mTexCoordInputSetsMap.find ( geometryId );
        if ( it != mTexCoordInputSetsMap.end () )
        {
            return &it->second;
        }
        return 0;
    }

    // --------------------------------------------
    const std::vector<GeometryImporter::PrimitiveInputSet>* GeometryImporter::findColorInputSets ( 
        const COLLADAFW::UniqueId& geometryId )
    {
        std::map<COLLADAFW::UniqueId, std::vector<PrimitiveInputSet> >::const_iterator it = mColorInputSetsMap.find ( geometryId );
        if ( it != mColorInputSetsMap.end () )
        {
            return &it->second;
        }
        return 0;
    }

    // --------------------------------------------
    const COLLADAFW::UniqueId* GeometryImporter::findGeometryId ( 
        const COLLADAFW::UniqueId& sourceId, 
        const COLLADAFW::UniqueId& transformId, 
        const COLLADAFW::UniqueId* controllerId )
    {
        // Handle controller
        const COLLADAFW::UniqueId* geometryId = 0;
        if ( controllerId && controllerId->isValid () )
        {
            // Get the geometryId of the current controller element.
            ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
            GeometryImporter::MeshControllerData* meshControllerData = findMeshControllerDataByControllerAndTransformId ( sourceId, transformId );
            if ( meshControllerData == 0 )
            {
                std::cerr << "No meshControllerData exist for the current geometry and transform!" << std::endl;
                return 0;
            }
            geometryId = &meshControllerData->getGeometryId ();
        }
        else 
        {
            geometryId = &sourceId;
        }

        return geometryId;
    }

    // --------------------------------------------
    const size_t GeometryImporter::findGeometryUvSetIndex ( 
        const COLLADAFW::UniqueId& geometryId, 
        const String& uvSetName )
    {
        std::map<COLLADAFW::UniqueId, std::vector<String> >::const_iterator it = mGeometryUvSetNamesMap.find ( geometryId );
        if ( it != mGeometryUvSetNamesMap.end () )
        {
            const std::vector<String>& uvSetNames = it->second;
            for ( size_t i=0; i<uvSetNames.size (); ++i )
            {
                if ( COLLADABU::Utils::equals ( uvSetName, uvSetNames[i] ) )
                    return i;
            }
        }
        return 0;
    }

    // --------------------------------------------
    void GeometryImporter::writeConnections ()
    {
        connectControllerGroups();

    }

    // --------------------------------------------
    void GeometryImporter::connectControllerGroups ()
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

        // Store the geometry and the controller ids.
        COLLADAFW::UniqueId previousGeometryId;
        COLLADAFW::UniqueId previousControllerId;

        // Get the shadingBindings of the same geometries and group their groups.
        ShadingBindingGroupInfoMap::const_iterator it = mShadingBindingGroupMap.begin ();
        while ( it != mShadingBindingGroupMap.end () )
        {
            const ShadingBinding& shadingBinding = it->first;
            const COLLADAFW::UniqueId& geometryId = shadingBinding.getGeometryId ();
            const COLLADAFW::UniqueId& transformId = shadingBinding.getTransformId();
            const COLLADAFW::UniqueId& controllerId = shadingBinding.getControllerId ();

            // Just connect the groups of controllers.
            if ( controllerId.isValid () )
            {
                // Get the current controller object.
                ControllerImporter* controllerImporter = getDocumentImporter ()->getControllerImporter ();
                const COLLADAFW::Controller* controller = controllerImporter->findController ( controllerId );

                // Get the geometryFileter object (skinCluster or blendShape).
                const ControllerImporter::GeometryFilterData* geometryFilterData = controllerImporter->findGeometryFilterData ( controllerId );
                if ( geometryFilterData == 0 )
                {
                    std::cerr << "No geometry filter for the current controller!" << std::endl;
                    ++it; continue;
                }
                const MayaDM::GeometryFilter* geometryFilter = geometryFilterData->getGeometryFilter ();

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
                        std::cerr << "No groupParts defined!" << std::endl;
                        continue;
                    }
                    const MayaDM::GroupParts& groupParts = groupInfo.getGroupParts ();

                    // Get the groupId object for the current mesh primitive.
                    const MayaDM::GroupId& groupId = groupInfo.getGroupId ();                            

                    // Get the number of controller instances and the current instance index.
                    size_t numInstances = shadingBinding.getNumInstances ();
                    size_t instanceIndex = shadingBinding.getInstanceIndex ();

                    // Handle the primitive element of the first controller instance.
                    size_t primitiveIndex = groupInfo.getPrimitiveIndex ();
                    if ( instanceIndex == 0 && primitiveIndex == 0 )
                    {
                        // connectAttr "skinCluster1.outputGeometry[0]" "groupParts3.inputGeometry";
                        connectAttr ( file, geometryFilter->getOutputGeometry (0), groupParts.getInputGeometry () );
                    }
                    else
                    {
                        if ( previousGroupParts == 0 )
                        {
                            std::cerr << "No previous groupParts object!" << std::endl;
                            continue;
                        }

                        // connectAttr "groupParts3.outputGeometry" "groupParts4.inputGeometry";
                        connectAttr ( file, previousGroupParts->getOutputGeometry (), groupParts.getInputGeometry () );
                    }
                    
                    // connectAttr "groupId3.groupId" "groupParts3.groupId";
                    connectAttr ( file, groupId.getGroupId (), groupParts.getGroupId () );

                    // If we handle the last primitive element of the last controller instance, 
                    // we have to connect the groupId to the current mesh's input mesh.
                    const size_t numPrimitiveElements = findPrimitivesCount ( geometryId );
                    if ( instanceIndex == numInstances-1 && 
                         primitiveIndex == numPrimitiveElements-1 )
                    {
                        // Get the current mesh (either the original object, or if we have a mesh
                        // controller, we need the mesh controller object.
                        MayaDM::Mesh* mesh = 0;
                        if ( !controllerId.isValid () )
                        {
                            mesh = findMayaDMMeshNode ( geometryId );
                        }
                        else
                        {
                            // If the current mesh has a mesh controller object, 
                            // we need the controller mesh element instead of the original.
                            MeshControllerData* meshControllerData = findMeshControllerDataByControllerAndTransformId ( controllerId, transformId );
                            if ( meshControllerData == 0 )
                            {
                                std::cerr << "No meshControllerData object for the current controller!" << std::endl;
                                continue;
                            }
                            mesh = &meshControllerData->getControllerMeshNode ();
                        }
                        if ( mesh == 0 )
                        {
                            std::cerr << "No mesh object exist!" << std::endl;
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

            // Store the ids.
            previousGeometryId = geometryId;
            previousControllerId = controllerId;

            ++it;
        }
    }

}
