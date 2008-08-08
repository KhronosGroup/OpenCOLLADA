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
#include "COLLADAMayaControllerExporter.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaConvert.h"
#include <assert.h>

#include "COLLADAMathUtils.h"
#include "COLLADABaseInputElement.h"

#include <maya/MItDependencyGraph.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MFnSkinCluster.h>
#include <maya/MItGeometry.h>
#include <maya/MFnWeightGeometryFilter.h>


namespace COLLADAMaya
{

    const String ControllerExporter::PARAM_TYPE_TRANSFORM    = "TRANSFORM";
    const String ControllerExporter::PARAM_TYPE_JOINT        = "JOINT";
    const String ControllerExporter::PARAM_TYPE_WEIGHT       = "WEIGHT";

    //------------------------------------------------------
    ControllerExporter::ControllerExporter ( COLLADA::StreamWriter* streamWriter,
                                           DocumentExporter* documentExporter )
    : COLLADA::LibraryControllers ( streamWriter )
    , mDocumentExporter ( documentExporter )
    , mExportedControllers ( NULL )
    {}

    //------------------------------------------------------
    ControllerExporter::~ControllerExporter()
    {
        importedMorphControllers.clear();
        skinControllers.clear();
    }

    //------------------------------------------------------
    void ControllerExporter::exportControllers()
    {
        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        uint length = exportNodesTree->size();
        for ( uint i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            exportControllers ( sceneElement );
        }

        closeLibrary();
    }

    //------------------------------------------------------
    void ControllerExporter::exportControllers( SceneElement* sceneElement )
    {
        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Check if it is a mesh and an export node
        if ( sceneElement->getType() == SceneElement::MESH &&
            sceneElement->getIsExportNode() )
        {
            // Create a skin/morph transform object and export the controller.
            bool exported = exportController ( sceneElement );
        }

        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportControllers ( childElement );
        }
    }

    //------------------------------------------------------
    bool ControllerExporter::exportController( SceneElement* sceneElement )
    {
        // Get the current mesh node.
        MDagPath dagPath = sceneElement->getPath();
        MObject meshNode = dagPath.node();

        // The stacks of the controllers for the affected nodes.
        ControllerStack stack;
        ControllerMeshStack meshStack;

        // Iterate upstream finding all the nodes which affect the mesh.
        if ( !findAffectedNodes( meshNode, stack, meshStack ) ) 
        {
            return false;
        }

        // Disable any effects on the nodes.
        setControllerNodeStatesToNoEffect ( stack );
        // Set all meshes as visible and not intermediate.
        setValidMeshParameters ( meshStack );

        // Exports all the mesh affected nodes in the controller stack.
        exportControllerStack( sceneElement, stack );

        // Reset the intermediate and visibility mesh parameters.
        resetMeshParameters( meshStack );
        // Reset the controller node states.
        resetControllerNodeStates( stack );
        // Delete the controller stack items and clear the stack.
        deleteControllerStackItems( stack );

        return true;
    }

    //------------------------------------------------------
    void ControllerExporter::exportControllerStack( 
        SceneElement *sceneElement, 
        const ControllerStack &stack )
    {
        // Get the current path and the mesh node.
        MDagPath dagPath = sceneElement->getPath();
        MObject meshNode = dagPath.node();

        // We cannot express more than one skin per geometry instance...
        bool alreadyHasSkin = false; 

        // Export the controller stack
        for ( intptr_t i=stack.size()-1; i>=0; --i )
        {
            ControllerStackItem* item = stack[i];
            if ( item->isSkin )
            {
                if ( ExportOptions::exportJointsAndSkin() && !alreadyHasSkin )
                {
                    // Correctly avoid chained joint-clusters: only export the first 
                    // joint cluster which exports the subsequent joint-clusters with it.
                    MObject skinControllerNode = item->skinControllerNode;
                    if ( !skinControllerNode.hasFn ( MFn::kJointCluster ) ||
                        i == 0 || 
                        !stack[i-1]->isSkin ||
                        !stack[i-1]->skinControllerNode.hasFn ( MFn::kJointCluster ) )
                    {
                        // TODO
                        exportSkinController(sceneElement, skinControllerNode, MDagPath::getAPathTo( meshNode ));
                //      target = exportSkinController(item->skinControllerNode, MDagPath::getAPathTo(node), target);
                //      doc->GetEntityManager()->ExportEntity(item->skinControllerNode, target->entity);
                        alreadyHasSkin = true;
                    }
                }
            }
            else
            {
                // TODO
                //     target = exportMorphController(sceneNode, item->morphControllerNodes, target);
                //     doc->GetEntityManager()->ExportEntity(item->morphControllerNodes[0], target->entity);
            }
        }
    }

    //------------------------------------------------------
    void ControllerExporter::exportSkinController(
        SceneElement* sceneElement, 
        const MObject controllerNode, 
        MDagPath outputShape )
    {
        // Get the current path.
        MDagPath targetDagPath = sceneElement->getPath();

        // Create the unique controller ID
//         String controllerId = mDocumentExporter->dagPathToColladaId( targetDagPath ) + 
//                                 LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;
        String controllerId;
        if ( !sceneElement->getNodeId().empty() )
        {
            controllerId = sceneElement->getNodeId() + 
                COLLADA::LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;
        }
        else
        {
            controllerId = sceneElement->getNodeName() + 
                COLLADA::LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;
        }
        
        // Check if the controller isn't already exported
        std::vector<String>::iterator controllerIter;
        controllerIter = find ( mExportedControllers.begin(), mExportedControllers.end(), controllerId );
        if ( controllerIter != mExportedControllers.end() ) return;

        // Push the exported controller in the export list
        mExportedControllers.push_back ( controllerId );

        // Attach a function set to the controller node.
        MStatus status;
        MFnMesh meshFn ( controllerNode, &status );

        // Figure out which type of skin controller we currently have: mesh-centric or joint-centric
        bool isJointCluster = controllerNode.hasFn(MFn::kJointCluster);
        bool isSkinCluster = controllerNode.hasFn(MFn::kSkinClusterFilter);
        if (!isJointCluster && !isSkinCluster) return;

        // Retrieve the instance information for this skinned character
        MFnGeometryFilter clusterFn(controllerNode);
        uint clusterIndex = retrieveInstanceInformation( meshFn, clusterFn, outputShape );

        // Create the controller name
        MString mayaControllerName = ( isSkinCluster ) ? clusterFn.name() : outputShape.partialPathName();
        String controllerName = mayaControllerName.asChar();

        // Get the skin target
        MFnDependencyNode fn ( outputShape.node() );
        String skinTarget =  fn.name().asChar();

        // Create an skin controller to hold the data
        ColladaSkinController colladaSkinController( controllerId, controllerName );

        // Push the controller into the list of controllers.
        skinControllers.push_back( &colladaSkinController );

        // Get the transform matrix for the shape.
        getBindShapeTransform( &colladaSkinController, clusterFn, isJointCluster, clusterIndex );

        // The weight filters to fill in.
        MObjectArray weightFilters;

        // Gather the list of joints
        gatherJoints( &colladaSkinController, controllerNode, weightFilters, clusterIndex );

        // Set the joint entry into the other scene element, shich use this joints.
        MDagPathArray influences = colladaSkinController.getInfluences();
        if ( influences.length() > 0 )
        {
            MDagPath skeletonPath = influences[0];
            String skeletonId = mDocumentExporter->dagPathToColladaId( skeletonPath ); 
            sceneElement->setSkeletonId( skeletonId );

            // Set the id on the other instanced nodes.
            bool isInstanced = targetDagPath.isInstanced ();
            uint instanceNumber = targetDagPath.instanceNumber ();
            MDagPathArray pathes;
            MDagPath::getAllPathsTo( targetDagPath.node(), pathes );
            for (uint i=0; i<pathes.length(); ++i)
            {
                SceneElement* foundElement = mDocumentExporter->getSceneGraph()->findElement( pathes[i] );
                if ( foundElement != NULL ) 
                    foundElement->setSkeletonId( skeletonId );
            }
        }

        gatherBindMatrices( &colladaSkinController, controllerNode );

        // Collect the vertex weights into the collada skin controller.
        uint numInfluences = colladaSkinController.getInfluences().length();
        collectVertexWeights( 
            &colladaSkinController, 
            controllerNode, 
            outputShape, 
            weightFilters, 
            clusterIndex, 
            numInfluences );

        // Create the joints
        createJoints ( &colladaSkinController );

        // Export the data into the collada document.
        exportController( skinTarget, colladaSkinController );

    }

    //------------------------------------------------------
    void ControllerExporter::collectVertexWeights( 
        ColladaSkinController* colladaSkinController, 
        const MObject &controllerNode, 
        const MDagPath &outputShape,
        const MObjectArray &weightFilters, 
        const uint clusterIndex,
        uint numInfluences )
    {
        // Attach a function set to the output shape.
        MFnMesh meshFn( outputShape );

        // Collect all the weights
        uint numVertices = meshFn.numVertices();
        SkinControllerVertices& colladaInfluences = colladaSkinController->getColladaVertexInfluences();
        colladaInfluences.resize(numVertices);

        if (controllerNode.apiType() == MFn::kSkinClusterFilter)
        {
            collectSkinClusterFilterVertexWeights(
                colladaInfluences, controllerNode, outputShape, numInfluences);
        }
        else if (controllerNode.apiType() == MFn::kJointCluster)
        {
            collectJointClusterVertexWeights(
                colladaInfluences, weightFilters, outputShape, clusterIndex );
        }
    }

    //------------------------------------------------------
    void ControllerExporter::collectSkinClusterFilterVertexWeights( 
        SkinControllerVertices& colladaInfluences, 
        const MObject& controllerNode, 
        const MDagPath& outputShape, 
        uint numInfluences )
    {
        MFnSkinCluster skinClusterFn(controllerNode);
        for (MItGeometry componentIt(outputShape); !componentIt.isDone(); componentIt.next())
        {
            int index = componentIt.index();
            SkinControllerVertex& vertex = colladaInfluences[index];

            MWeightArray weights;
            MObject component = componentIt.component();
            if (skinClusterFn.getWeights(outputShape, component, weights, numInfluences) != MS::kSuccess)
            {
                weights.clear();
            }

            uint weightCount = weights.length();
            for (uint i = 0; i < weightCount; ++i)
            {
                if (!COLLADA::MathUtils::equals(weights[i], MWeight(0)))
                {
                    vertex[i] = (float)weights[i];
                }
            }
        }
    }

    //------------------------------------------------------
    void ControllerExporter::collectJointClusterVertexWeights( 
        SkinControllerVertices& colladaInfluences, 
        const MObjectArray &weightFilters, 
        const MDagPath &outputShape, 
        const uint clusterIndex )
    {
        // Get the weight for each of the clusters
        uint weightFilterCount = weightFilters.length();
        for (uint i = 0; i < weightFilterCount; ++i)
        {
            MFnWeightGeometryFilter filterFn(weightFilters[i]);
            MObject deformSet = filterFn.deformerSet();
            MFnSet setFn(deformSet);

            // Get all the components affected by this joint cluster
            MSelectionList clusterSetList;
            setFn.getMembers(clusterSetList, true);

            MDagPath shapePath;
            MObject components;
            uint setListCount = clusterSetList.length();
            for (uint s = 0; s < setListCount; ++s)
            {
                clusterSetList.getDagPath(s, shapePath, components);
                if (shapePath.node() == outputShape.node()) break;
            }

            MFloatArray weights;
            filterFn.getWeights(clusterIndex, components, weights);

            uint counter = 0;
            for (MItGeometry componentIt(shapePath, components); 
                !componentIt.isDone() && counter < weights.length(); 
                componentIt.next())
            {
                // append the weight at its correct position: i
                float weight = weights[counter++];
                if (COLLADA::MathUtils::equals(weight, 0.0f))
                {
                    SkinControllerVertex& vertex = colladaInfluences[componentIt.index()];
                    vertex[i] = weight;
                }
            }
        }
    }

    //------------------------------------------------------
    void ControllerExporter::gatherJoints( 
        ColladaSkinController* colladaSkinController, 
        const MObject &controllerNode, 
        MObjectArray &weightFilters, 
        const uint clusterIndex )
{
        // Gather the list of joints
        MDagPathArray& influences = colladaSkinController->getInfluences();
        if (controllerNode.apiType() == MFn::kSkinClusterFilter)
        {
            MStatus status;
            MFnSkinCluster skinClusterFn( controllerNode );
            skinClusterFn.influenceObjects(influences, &status);
        }
        else if (controllerNode.apiType() == MFn::kJointCluster)
        {
            // Support for joint clusters pipeline
            getJointClusterInfluences(controllerNode, influences, weightFilters, clusterIndex);
        }
    }

    //------------------------------------------------------
    void ControllerExporter::gatherBindMatrices( 
        ColladaSkinController* colladaSkinController, 
        const MObject& controllerNode )
    {
        // The list of joints
        MDagPathArray& influences = colladaSkinController->getInfluences();

        // Request a change in capacity
        uint numInfluences = influences.length();
        std::vector<MMatrix>& bindPoses = colladaSkinController->getBindPoses();
        bindPoses.reserve(numInfluences);

        // Gather the bind matrices
        for (uint i = 0; i < numInfluences; ++i)
        {
            MObject influence = influences[i].node();
            MMatrix mayaBindPoseMatrix = DagHelper::getBindPoseInverse(controllerNode, influence);
            bindPoses.push_back( mayaBindPoseMatrix );
        }
    }

    //------------------------------------------------------
    void ControllerExporter::createJoints( 
        ColladaSkinController* colladaSkinController )
    {
        // Gather the list of joints
        const MDagPathArray& influences = colladaSkinController->getInfluences();

        // Create the joints with their ids.
        SkinControllerJoints& joints = colladaSkinController->getColladaJoints();
        uint numInfluences = influences.length();
        joints.resize( numInfluences );

        for (uint i=0; i<numInfluences; ++i)
        {
            MDagPath dagPath = influences[i];

            SkinControllerJoint &joint = joints[i];
            joint.first = mDocumentExporter->dagPathToColladaId ( dagPath );
            joint.second = colladaSkinController->getBindPoses()[i];
        }
    }

    //------------------------------------------------------
    void ControllerExporter::getJointClusterInfluences(
        const MObject &controllerNode, 
        MDagPathArray &influences, 
        MObjectArray &weightFilters, 
        const uint clusterIndex )
    {
        MObject cluster( controllerNode );
        while ( cluster.apiType() == MFn::kJointCluster )
        {
            weightFilters.append(cluster);

            MObject joint = DagHelper::getNodeConnectedTo( cluster, ATTR_MATRIX );
            MDagPath jointPath = MDagPath::getAPathTo( joint );
            influences.append(jointPath);

            MStatus status;
            MPlug plug = ShaderHelper::findPlug(MFnDependencyNode(cluster), ATTR_INPUt, &status);
            if (status != MStatus::kSuccess) 
            { MGlobal::displayError("Unable to get joint cluster input plug."); return; }

            plug = plug.elementByLogicalIndex(clusterIndex, &status);
            if (status != MStatus::kSuccess) 
            { MGlobal::displayError("Unable to get joint cluster input plug first element."); return; }

            plug = DagHelper::getChildPlug(plug, ATTR_INPUT_GEOMETRY, &status); // "inputGeometry"
            if (status != MStatus::kSuccess) 
            { MGlobal::displayError("Unable to get joint cluster input geometry plug."); return; }

            cluster = DagHelper::getSourceNodeConnectedTo(plug);
        }
    }

    //------------------------------------------------------
    void ControllerExporter::getBindShapeTransform(
        ColladaSkinController* skinController,
        const MFnGeometryFilter &clusterFn,
        const bool isJointCluster,
        const uint index )
    {
        // Add the bind-shape bind matrix
        MMatrix mayaBindShapeMatrix;
        MPlug bindShapeMatrixPlug = clusterFn.findPlug( ATTR_GEOM_MATRIX );

        if ( isJointCluster ) 
            bindShapeMatrixPlug = bindShapeMatrixPlug.elementByLogicalIndex(index);

        DagHelper::getPlugValue( bindShapeMatrixPlug, mayaBindShapeMatrix );

        skinController->setBindShapeTransform( mayaBindShapeMatrix );
    }

    //------------------------------------------------------
    bool ControllerExporter::hasController ( const MObject& node )
    {
        return hasSkinController ( node ) || hasMorphController ( node );
    }

    //------------------------------------------------------
    bool ControllerExporter::hasSkinController ( const MObject& node )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( ATTR_IN_MESH, &status );

        if ( !status || !plug.isConnected() ) return false;

        MItDependencyGraph dgIt ( plug,
            MFn::kInvalid,
            MItDependencyGraph::kUpstream,
            MItDependencyGraph::kBreadthFirst,
            MItDependencyGraph::kNodeLevel,
            &status );
        if ( status != MS::kSuccess ) return false;

        dgIt.disablePruningOnFilter();

        while ( !dgIt.isDone() )
        {
            MObject thisNode = dgIt.thisNode();
            if ( thisNode.hasFn ( MFn::kSkinClusterFilter ) || thisNode.hasFn ( MFn::kJointCluster ) )
            {
                return true;
            }

            dgIt.next();
        }

        return false;
    }

    //------------------------------------------------------
    bool ControllerExporter::hasMorphController ( const MObject& node )
    {
        MPlug plug = MFnDependencyNode ( node ).findPlug ( ATTR_IN_MESH );

        if ( plug.isConnected() )
        {
            MItDependencyGraph dgIt ( plug,
                MFn::kInvalid,
                MItDependencyGraph::kUpstream,
                MItDependencyGraph::kDepthFirst,
                MItDependencyGraph::kPlugLevel );

            dgIt.disablePruningOnFilter();

            for ( ; ! dgIt.isDone(); dgIt.next() )
            {
                MObject thisNode = dgIt.thisNode();

                if ( thisNode.hasFn ( MFn::kBlendShape ) ) return true;
            }
        }

        return false;
    }

    //------------------------------------------------------
    uint ControllerExporter::retrieveInstanceInformation( 
        const MFnMesh &fnMesh, 
        const MFnGeometryFilter &clusterFn, 
        MDagPath &outputShape )
    {
        MStatus status;

        uint idx = clusterFn.indexForOutputShape(outputShape.node());
        if (idx == ~0u)
        {
            // Alternate method for retrieving the index?
            MPlug meshConnection = fnMesh.findPlug( ATTR_IN_MESH );
            MItDependencyGraph dgIt(
                meshConnection, 
                MFn::kMesh, 
                MItDependencyGraph::kUpstream, 
                MItDependencyGraph::kBreadthFirst, 
                MItDependencyGraph::kNodeLevel, 
                &status);
            CHECK_MSTATUS_AND_RETURN(status, NULL);
            dgIt.disablePruningOnFilter(); 

            for (; ! dgIt.isDone(); dgIt.next())
            {
                MObject thisNode = dgIt.thisNode();
                idx = clusterFn.indexForOutputShape(thisNode);
                if (idx != ~0u)
                {
                    outputShape = MDagPath::getAPathTo(thisNode);
                    break;
                }
            }
        }
        return idx;
    }

    //------------------------------------------------------
    void ControllerExporter::exportJointSource( const ColladaSkinController &colladaSkinController )
    {
        COLLADA::NameSource jointSource( mDocumentExporter->getStreamWriter() );
        String controllerId = colladaSkinController.getControllerId();
        jointSource.setId ( controllerId + JOINTS_SOURCE_ID_SUFFIX );
        jointSource.setNodeName ( controllerId + JOINTS_SOURCE_ID_SUFFIX );
        jointSource.setArrayId ( controllerId + JOINTS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        jointSource.setAccessorStride ( 1 );

        // Retrieves the vertex positions.
        const MDagPathArray& influences = colladaSkinController.getInfluences();
        uint numInfluences = influences.length();
        jointSource.setAccessorCount ( numInfluences );

        jointSource.getParameterNameList().push_back ( PARAM_TYPE_JOINT );
        jointSource.prepareToAppendValues();

        const SkinControllerJoints& joints = colladaSkinController.getColladaJoints();
        SkinControllerJoints::const_iterator it = joints.begin();
        for (; it<joints.end(); ++it)
        {
            String boneId = (*it).first;
            jointSource.appendValues ( boneId );
        }
        jointSource.finish();
    }

    //------------------------------------------------------
    void ControllerExporter::exportBindPosesSource( const ColladaSkinController &colladaSkinController )
    {
        COLLADA::Float4x4Source bindPosesSource( mDocumentExporter->getStreamWriter() );
        String controllerId = colladaSkinController.getControllerId();
        bindPosesSource.setId ( controllerId + BIND_POSES_SOURCE_ID_SUFFIX );
        bindPosesSource.setNodeName ( controllerId + BIND_POSES_SOURCE_ID_SUFFIX );
        bindPosesSource.setArrayId ( controllerId + BIND_POSES_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        bindPosesSource.setAccessorStride ( 16 );

        // Retrieves the vertex positions.
        const MDagPathArray& influences = colladaSkinController.getInfluences();
        uint numInfluences = influences.length();
        bindPosesSource.setAccessorCount ( numInfluences );

        bindPosesSource.getParameterNameList().push_back ( PARAM_TYPE_TRANSFORM );
        bindPosesSource.prepareToAppendValues();

        const std::vector<MMatrix>& bindPosesVec = colladaSkinController.getBindPoses();
        uint numBindPoses = bindPosesVec.size();
        for (uint i=0; i<bindPosesVec.size(); ++i)
        {
            double bindPoses[4][4];
            MMatrix mayaBindPoses = bindPosesVec[i];
            MConvert::convertMMatrixToDouble4x4(bindPoses, mayaBindPoses);
            bindPosesSource.appendValues ( bindPoses );
        }
        bindPosesSource.finish();
    }

    //------------------------------------------------------
    void ControllerExporter::exportWeightSource( 
        const String controllerId, 
        const ColladaSkinController &colladaSkinController )
    {
        COLLADA::FloatSourceF weightSource( mDocumentExporter->getStreamWriter() );
        weightSource.setId ( controllerId + WEIGHTS_SOURCE_ID_SUFFIX );
        weightSource.setNodeName ( controllerId + WEIGHTS_SOURCE_ID_SUFFIX );
        weightSource.setArrayId ( controllerId + WEIGHTS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        weightSource.setAccessorStride ( 1 );

        // Create the vertex list
        std::vector<float> vertexVec;

        // Push a single one weight in front of the list. The vertex_weights array
        // can always reference to it, if we have a one weight.
        vertexVec.push_back(1.0f);
        uint numVertexPoints = 1;

        const SkinControllerVertices& vertexes = colladaSkinController.getColladaVertexInfluences();
        for (uint i=0; i<vertexes.size(); ++i)
        {
            SkinControllerVertex vertex = vertexes[i];
            for (uint j=0; j<vertex.size(); ++j)
            {
                // We don't need to write the zero weight, cause then there is no 
                // influence. We don't write the one weights, cause we have written 
                // (see below) a one weight in front of the vertex_weights array and 
                // always reference to it from the vertex_weights array.
                if ( !COLLADA::MathUtils::equalsZero( vertex[j] ) && 
                     !COLLADA::MathUtils::equals( vertex[j], 1.0f ) ) 
                {
                    vertexVec.push_back(vertex[j]);
                    ++numVertexPoints;
                }
            }
        }
        weightSource.setAccessorCount ( numVertexPoints );

        weightSource.getParameterNameList().push_back ( PARAM_TYPE_WEIGHT );
        weightSource.prepareToAppendValues();
        weightSource.appendValues ( vertexVec );
        weightSource.finish();
    }

    //------------------------------------------------------
    void ControllerExporter::exportBindShapeTransform( const ColladaSkinController &colladaSkinController )
    {
        // Write the bind shape transform matrix in the collada document.
        const MMatrix& mayaBindShapeMatrix = colladaSkinController.getBindShapeTransform();
        double bindShapeMatrix[4][4] ;
        MConvert::convertMMatrixToDouble4x4 ( bindShapeMatrix, mayaBindShapeMatrix );
        addBindShapeTransform( bindShapeMatrix );
    }

    //------------------------------------------------------
    void ControllerExporter::exportController( 
        const String skinTarget, 
        const ColladaSkinController &colladaSkinController )
    {
        // Get the unique id and the name of the current controller.
        String controllerId = colladaSkinController.getControllerId();
        String controllerName = colladaSkinController.getControllerName();

        // Opens the skin tag in the collada document.
        openSkin ( controllerId , controllerName, skinTarget );
        
        exportBindShapeTransform( colladaSkinController );
        exportJointSource( colladaSkinController );
        exportBindPosesSource( colladaSkinController );
        exportWeightSource( controllerId, colladaSkinController );
        exportElementJoints( colladaSkinController );
        exportElementVertexWeights( colladaSkinController );

        // Close the opened skin tag.
        closeSkin();

        // Close the opened controller tag.
        closeController();
    }

    //------------------------------------------------------
    void ControllerExporter::exportElementVertexWeights( const ColladaSkinController &colladaSkinController )
    {
        String controllerId = colladaSkinController.getControllerId();
        String jointSourceId = controllerId + JOINTS_SOURCE_ID_SUFFIX;
        String weightSourceId = controllerId + WEIGHTS_SOURCE_ID_SUFFIX;

        uint offset = 0;
        COLLADA::VertexWeightsElement vertexWeightsElement( mDocumentExporter->getStreamWriter() );
        COLLADA::InputList &inputList = vertexWeightsElement.getInputList();
        inputList.push_back ( COLLADA::Input ( COLLADA::JOINT, "#" + jointSourceId, offset++ ) );
        inputList.push_back ( COLLADA::Input ( COLLADA::WEIGHT, "#" + weightSourceId, offset++ ) );

        // The list for the vertex values.
        std::vector<unsigned long> vertexMatches;

        // The input data 
        const SkinControllerVertices& vertexes = colladaSkinController.getColladaVertexInfluences();

        // Counter for the influence counts
        uint influenceCount = vertexes.size();
        vertexWeightsElement.setCount( influenceCount );

        // Generate the vertex count and match value strings and export the <v> and <vcount> elements
        uint weightOffset = 1;
        for (size_t j=0; j<influenceCount; ++j)
        {
            SkinControllerVertex vertex = vertexes[j];
            vertexWeightsElement.getVCountList().push_back( vertex.size() );

            std::map<int, float>::const_iterator it = vertex.begin();
            for (; it!=vertex.end(); ++it)
            {
                vertexMatches.push_back( (*it).first );

                if ( !COLLADA::MathUtils::equals( (*it).second, 1.0f ) ) 
                    vertexMatches.push_back( weightOffset++ );
                else 
                    // There is a one in the first position of the weight source array.
                    // We will always reference to this element, if the weight is a one.
                    vertexMatches.push_back ( 0 );
            }
        }
        // TODO In FCollada, the last element was erased?!?
//        if (!vertexMatches.empty()) vertexMatches.pop_back();
        
        vertexWeightsElement.prepareToAppendValues();
        vertexWeightsElement.appendValues( vertexMatches );
        vertexWeightsElement.finish();
    }

    //------------------------------------------------------
    void ControllerExporter::exportElementJoints( const ColladaSkinController &colladaSkinController )
    {
        String controllerId = colladaSkinController.getControllerId();
        String jointSourceId = controllerId + JOINTS_SOURCE_ID_SUFFIX;
        String jointBindSourceId = controllerId + BIND_POSES_SOURCE_ID_SUFFIX;

        COLLADA::JointsElement jointsElement( mDocumentExporter->getStreamWriter() );
        COLLADA::InputList &jointsInputList = jointsElement.getInputList();
        jointsInputList.push_back ( COLLADA::Input ( COLLADA::JOINT, "#" + jointSourceId ) );
        jointsInputList.push_back ( COLLADA::Input ( COLLADA::BINDMATRIX, "#" + jointBindSourceId ) );
        jointsElement.add();
    }

    //------------------------------------------------------
    void ControllerExporter::completeControllerExport()
    {
        // Attach the skin controllers next
        for (ControllerList::iterator it = skinControllers.begin(); it != skinControllers.end(); ++it)
        {
            BaseController* baseController = (*it);
//             ColladaSkinController* colladaSkin = ((BaseController*) &*(c->entity))->GetSkinController();
//             if (colladaSkin != NULL)
//             {
//                 for (FCDControllerInstanceList::iterator itI = c->instances.begin(); itI != c->instances.end(); ++itI)
                {
                    completeInstanceExport( baseController );
//                    completeInstanceExport(*itI, (FCDController*) &*c->entity);
                }
//            }
        }

        // Release the skin controllers
        for (ControllerList::iterator it = skinControllers.begin(); it != skinControllers.end(); ++it)
        {
            BaseController* baseController = (*it);
            delete baseController;
        }
        skinControllers.clear();
    }

    //------------------------------------------------------
    void ControllerExporter::completeInstanceExport(BaseController* colladaController)
    {
        if (colladaController->isSkinController())
        {
            // Gather our required info.
            ColladaSkinController* colladaSkin = (ColladaSkinController*)colladaController;

//             // We don't preserve any <skeleton> information.
//             DaeController*  daeController = (DaeController*)colladaController->GetUserHandle();
//             colladaInstance->ResetJoints();

            uint count = colladaSkin->getInfluences().length();

//             bool initColladaSkin = (colladaSkin->GetJointCount() != count);
//             if (initColladaSkin) colladaSkin->SetJointCount(count);
// 
//             for (uint i = 0; i < count; ++i)
//             {
//                 DaeEntity* element = doc->GetSceneGraph()->FindElement(daeController->influences[i]);
//                 if (element != NULL && element->entity != NULL && element->entity->GetObjectType() == FCDSceneNode::GetClassType())
//                 {
//                     FCDSceneNode* sceneNode = (FCDSceneNode*) &*(element->entity);
//                     colladaInstance->AddJoint(sceneNode);
//                     if (initColladaSkin)
//                     {
//                         if (sceneNode->GetSubId().empty())
//                         {
//                             FUSStringBuilder boneId("bone"); 
//                             boneId.append(boneCounter);
//                             boneCounter++;
//                             sceneNode->SetSubId(boneId.ToCharPtr());
//                         }
//                         FCDSkinControllerJoint* joint = colladaSkin->GetJoint(i);
//                         joint->SetBindPoseInverse(daeController->bindPoses[i]);
//                         joint->SetId(sceneNode->GetSubId());
//                     }
//                 }
// #ifdef _DEBUG
//                 else
//                 {
//                     MString ss = daeController->influences[i].fullPathName();
//                     const char* tt = ss.asChar();
//                     FUFail(tt);
//                 }
// #endif // _DEBUG
//             }
//             colladaInstance->CalculateRootIds();
//         }
//         else
//         {
//             // Nothing to export for morph instances.
//         }
        }
    }

    //------------------------------------------------------
    bool ControllerExporter::findAffectedNodes( 
        const MObject& node, 
        ControllerStack &stack, 
        ControllerMeshStack &meshStack )
    {
        MStatus stat;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( ATTR_IN_MESH );

        if ( plug.isConnected() )
        {
            MItDependencyGraph dgIt ( plug,
                MFn::kInvalid,
                MItDependencyGraph::kUpstream,
                MItDependencyGraph::kBreadthFirst,
                MItDependencyGraph::kNodeLevel,
                &stat );
            if ( MS::kSuccess != stat ) return false;

            dgIt.disablePruningOnFilter();
            for ( ; ! dgIt.isDone(); dgIt.next() )
            {
                MObject thisNode = dgIt.thisNode();
                if ( thisNode.hasFn ( MFn::kSkinClusterFilter ) || thisNode.hasFn ( MFn::kJointCluster ) )
                {
                    // Append the skin controller node.
                    ControllerStackItem* item = new ControllerStackItem();
                    item->isSkin = true;
                    item->skinControllerNode = thisNode;
                    stack.push_back ( item );
                }
                // TODO Test!
                else if ( thisNode.hasFn ( MFn::kBlendShape ) )
                {
                    // Check for subsequent, multiple blend shape deformers.
                    if ( stack.size() > 0 && !stack.back()->isSkin )
                    {
                        stack.back()->morphControllerNodes.append ( thisNode );
                    }
                    else
                    {
                        ControllerStackItem* item = new ControllerStackItem();
                        item->isSkin = false;
                        item->morphControllerNodes.append ( thisNode );
                        stack.push_back ( item );
                    }
                }
                else if ( thisNode.hasFn ( MFn::kMesh ) )
                {
                    // Queue up this mesh.
                    ControllerMeshItem item;
                    item.mesh = thisNode;
                    meshStack.push_back ( item );
                }
            }
        }

        return true;
    }

    //------------------------------------------------------
    void ControllerExporter::setControllerNodeStatesToNoEffect( ControllerStack &stack )
    {
        // Set the controller node states
        for ( size_t i=0; i<stack.size(); ++i )
        {
            ControllerStackItem* item = stack[i];

            // Disable the skin controller node
            if ( item->isSkin )
            {
                int nodeState;
                DagHelper::getPlugValue ( item->skinControllerNode, ATTR_NODE_STATE, nodeState );
                DagHelper::setPlugValue ( item->skinControllerNode, ATTR_NODE_STATE, 1 ); // pass-through.
                item->nodeStates.push_back ( nodeState );
            }

            // Disable the morph controllers
            for ( uint j=0; j<item->morphControllerNodes.length(); ++j )
            {
                int nodeState;
                DagHelper::getPlugValue ( item->morphControllerNodes[j], ATTR_NODE_STATE, nodeState );
                DagHelper::setPlugValue ( item->morphControllerNodes[j], ATTR_NODE_STATE, 1 ); // pass-through.
                item->nodeStates.push_back( nodeState );
            }
        }
    }

    //------------------------------------------------------
    void ControllerExporter::resetControllerNodeStates( ControllerStack &stack )
    {
        // Reset all the controller node states
        for ( size_t i=0; i<stack.size(); ++i )
        {
            ControllerStackItem* item = stack[i];
            if ( item->isSkin )
            {
                // Reset the skin controller node state.
                uint nodeStateSize = item->nodeStates.size();
                assert ( nodeStateSize >= 1 );
                long nodeState = item->nodeStates.front();
                DagHelper::setPlugValue ( item->skinControllerNode, ATTR_NODE_STATE, nodeState );

                // Maybe there are some morph controllers to reset.
                for ( uint i=0; i<item->morphControllerNodes.length(); ++i )
                {
                    assert ( nodeStateSize < i+1 );
                    nodeState = item->nodeStates[i+1];
                    DagHelper::setPlugValue ( item->morphControllerNodes[i], ATTR_NODE_STATE, nodeState );
                }
            }
            else
            {
                // Reset the morph controller node states.
                uint nodeStateSize = item->nodeStates.size();
                for ( uint j=0; j<item->morphControllerNodes.length(); ++j )
                {
                    assert ( nodeStateSize < j );
                    long nodeState = item->nodeStates[j];
                    DagHelper::setPlugValue ( item->morphControllerNodes[j], ATTR_NODE_STATE, nodeState );
                }
            }
        }
    }

    //------------------------------------------------------
    void ControllerExporter::setValidMeshParameters( ControllerMeshStack &meshStack )
    {
        // Set valid mesh parameters (visible and not intermediate).
        for ( size_t i=0; i<meshStack.size(); ++i )
        {
            ControllerMeshItem& item = meshStack[i];

            DagHelper::getPlugValue ( item.mesh, ATTR_INTERMEDIATE_OBJECT, item.isIntermediate );
            DagHelper::getPlugValue ( item.mesh, ATTR_VISIBILITY, item.isVisible );
            DagHelper::setPlugValue ( item.mesh, ATTR_INTERMEDIATE_OBJECT, false );
            DagHelper::setPlugValue ( item.mesh, ATTR_VISIBILITY, true );
        }
    }

    //------------------------------------------------------
    void ControllerExporter::resetMeshParameters( ControllerMeshStack &meshStack )
    {
        // Reset all the intermediate and visibility mesh parameters.
        while ( !meshStack.empty() )
        {
            ControllerMeshItem& item = meshStack.back();

            DagHelper::setPlugValue ( item.mesh, ATTR_INTERMEDIATE_OBJECT, item.isIntermediate );
            DagHelper::setPlugValue ( item.mesh, ATTR_VISIBILITY, item.isVisible );

            meshStack.pop_back();
        }
    }

    //------------------------------------------------------
    void ControllerExporter::deleteControllerStackItems( ControllerStack &stack )
    {
        // Delete the controllerStack items
        for ( size_t i=0; i<stack.size(); ++i )
        {
            ControllerStackItem* item = stack[i];
            delete item;
        }

        stack.clear();
    }

}

