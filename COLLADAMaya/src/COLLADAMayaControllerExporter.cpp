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
    , boneCounter(0)
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
#ifdef _DEBUG
            cout << "   Start export " << sceneElement->getNodeName() << endl;
#endif
            exportControllers ( sceneElement );
        }

        closeLibrary();
    }

    //------------------------------------------------------
    void ControllerExporter::exportControllers(SceneElement* sceneElement)
    {
        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Check if it is a mesh and an export node
        if ( sceneElement->getType() == SceneElement::MESH &&
            sceneElement->getIsExportNode() )
        {
            // Create a skin/morph transform object and export the controller
            clock_t startClock, endClock;
            startClock = clock();
            bool exported = exportController ( sceneElement );
            endClock = clock();
#ifdef _DEBUG
            if (exported)
                cout << "   End export controller "  << sceneElement->getNodeName() << ": "  << endClock - startClock << endl;
#endif
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
        if (!findAffectedNodes(meshNode, stack, meshStack)) 
        {
            // TODO Don't export the geometry of the current scene element!
            sceneElement->setIsForced(true);
            return false;
        }

        // Exports all the mesh affected nodes in the controller stack.
        exportControllerStack( sceneElement, stack );

        // Reset all the intermediate mesh parameters.
        while ( !meshStack.empty() )
        {
            ControllerMeshItem& item = meshStack.back();

            DagHelper::setPlugValue ( item.mesh, ATTR_INTERMEDIATE_OBJECT, item.isIntermediate );
            DagHelper::setPlugValue ( item.mesh, ATTR_VISIBILITY, item.isVisible );

            meshStack.pop_back();
        }

        // Reset all the controller node states
        for ( size_t i = 0; i < stack.size(); ++i )
        {
            ControllerStackItem* item = stack[i];
            if ( item->isSkin )
            {
                DagHelper::setPlugValue ( 
                    item->skinControllerNode, ATTR_NODE_STATE, item->nodeStates.front() );
            }
            else
            {
                for ( uint j = 0; j < item->morphControllerNodes.length(); ++j )
                {
                    DagHelper::setPlugValue ( 
                        item->morphControllerNodes[j], ATTR_NODE_STATE, item->nodeStates[j] );
                }
            }
            delete item;
        }
        stack.clear();


//         //  if (target != NULL) target->SetNode(node);
//         //  return target;
        return true;
    }

    //------------------------------------------------------
    void ControllerExporter::exportControllerStack( 
        const SceneElement *sceneElement, 
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
                        exportSkinController(sceneElement, skinControllerNode, MDagPath::getAPathTo(meshNode));
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
        const SceneElement* sceneElement, 
        const MObject controllerNode, 
        MDagPath outputShape )
    {
        // Get the current path and the mesh node.
        MDagPath targetDagPath = sceneElement->getPath();

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

        // Create the unique controller IDs
        String controllerId = mDocumentExporter->dagPathToColladaId( targetDagPath ) + 
                                LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;
        MString mayaControllerName = ( isSkinCluster ) ? clusterFn.name() : outputShape.partialPathName();
        String controllerName = mayaControllerName.asChar();

        // Get the skin target
        String skinTarget = mDocumentExporter->dagPathToColladaId( outputShape );

        // --------------------------------
        // Create the COLLADA controller and its ColladaMaya equivalent.
        MayaController* targetController = new MayaController( controllerId, controllerName );

        // Push the controller into the list of controllers.
        skinControllers.push_back( targetController );

        // --------------------------------
        // Create an skin controller to hold the data
        ColladaSkinController colladaSkinController( controllerId );

        // Get the transform matrix for the shape.
        getBindShapeTransform( &colladaSkinController, clusterFn, isJointCluster, clusterIndex );

        // The weight filters to fill in.
        MObjectArray weightFilters;

        // Gather the list of joints
        gatherJoints( targetController, controllerNode, weightFilters, clusterIndex );
        gatherBindMatrices( targetController, controllerNode );

        // Collect the vertex weights into the collada skin controller.
        uint numInfluences = targetController->influences.length();
        collectVertexWeights( 
            &colladaSkinController, 
            controllerNode, 
            outputShape, 
            weightFilters, 
            clusterIndex, 
            numInfluences );

        // TODO Have to calculate bind poses!

        // Export the data into the collada document.
        exportController( skinTarget, colladaSkinController, targetController );

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
        std::vector<SkinControllerVertex>& colladaInfluences = colladaSkinController->colladaVertexInfluences;
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
        std::vector<SkinControllerVertex>& colladaInfluences, 
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
                else
                {
                    double value = weights[i];
                    //float vertexValue = vertex[i];
                    bool equal = COLLADA::MathUtils::equals(weights[i], MWeight(0));
                    String bla = "blubber";
                }
            }
        }
    }

    //------------------------------------------------------
    void ControllerExporter::collectJointClusterVertexWeights( 
        std::vector<SkinControllerVertex>& colladaInfluences, 
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
        MayaController *targetController, 
        const MObject &controllerNode, 
        MObjectArray &weightFilters, 
        const uint clusterIndex )
{
        // Gather the list of joints
        MDagPathArray& influences = targetController->influences;
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
        MayaController* targetController, 
        const MObject& controllerNode )
    {
        // The list of joints
        MDagPathArray& influences = targetController->influences;

        // Request a change in capacity
        uint numInfluences = influences.length();
        targetController->bindPoses.reserve(numInfluences);

        // Gather the bind matrices
        for (uint i = 0; i < numInfluences; ++i)
        {
            MObject influence = influences[i].node();
            MMatrix mayaBindPoseMatrix = DagHelper::getBindPoseInverse(controllerNode, influence);
            targetController->bindPoses.push_back( mayaBindPoseMatrix );
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

        skinController->bindShapeTransform = mayaBindShapeMatrix;
    }

    //------------------------------------------------------
    bool ControllerExporter::exportController ( SceneElement* sceneNode, const MObject& node )
    {
        // Get the current's element path
        MDagPath dagPath = sceneNode->getPath();

        // The stacks of the controllers for the affected nodes.
        ControllerStack stack;
        ControllerMeshStack meshStack;

        // Iterate upstream finding all the nodes which affect the mesh.
        if (!findAffectedNodes(node, stack, meshStack)) return false;

        // Already done in the geometry! 
        // TODO Don't export the geometry, if we don't have affected nodes!
        // At the end, export the base mesh
//        mDocumentExporter->getGeometryExporter()->exportGeometry ( dagPath );

//  DaeEntity* target = doc->GetGeometryLibrary()->exportMesh(node);

        // Exports all the mesh affected nodes in the controller stack.
        exportControllerStack( sceneNode, stack );

        // Reset all the intermediate mesh parameters.
        while ( !meshStack.empty() )
        {
            ControllerMeshItem& item = meshStack.back();

            DagHelper::setPlugValue ( item.mesh, ATTR_INTERMEDIATE_OBJECT, item.isIntermediate );
            DagHelper::setPlugValue ( item.mesh, ATTR_VISIBILITY, item.isVisible );

            meshStack.pop_back();
        }

        // Reset all the controller node states
        for ( size_t i = 0; i < stack.size(); ++i )
        {
            ControllerStackItem* item = stack[i];
            if ( item->isSkin )
            {
                DagHelper::setPlugValue ( item->skinControllerNode, ATTR_NODE_STATE, item->nodeStates.front() );
            }
            else
            {
                for ( uint j = 0; j < item->morphControllerNodes.length(); ++j )
                {
                    DagHelper::setPlugValue ( item->morphControllerNodes[j], ATTR_NODE_STATE, item->nodeStates[j] );
                }
            }
            delete item;
        }

        stack.clear();

//  if (target != NULL) target->SetNode(node);
//  return target;
        return false;
    }

    //------------------------------------------------------
    void ControllerExporter::exportController ( 
        SceneElement* sceneNode,
        bool isSkin,
        bool instantiate )
    {
        // Get the current's element path
        MDagPath dagPath = sceneNode->getPath();

        // Controllers are tricky: they cannot be on an animated node
        // and in the case of skin controllers,
        // the bind-shape matrix must be taken out.
        bool exported = exportController ( sceneNode, dagPath.node() );
        if ( !exported ) return;

        SceneElement* pivotNode = NULL;

        //  FCDSceneNode* pivotNode = NULL;
        MFnTransform transformFn ( dagPath.transform() );

        if ( isSkin )
        {
            // Calculate the number of visible children.
            uint visibleChildCount = 0;

            for ( uint i = 0; i < transformFn.childCount(); ++i )
            {
                bool isVisible = false;
                MFnDagNode dagFn ( transformFn.child ( i ) );
                dagFn.findPlug ( ATTR_VISIBILITY ).getValue ( isVisible );

                if ( !dagFn.isIntermediateObject() &&
                    ( !ExportOptions::exportInvisibleNodes() || isVisible ) )
                    ++visibleChildCount;
            }

            if ( visibleChildCount > 1 )
            {
                // Create a new scene node
                SceneElement* parentNode = sceneNode->getParent();
                if ( parentNode == NULL ) 
                {
                    MGlobal::displayError( "Parent node can't be null!" ); // shouldn't happen.
                    return;
                }

                parentNode->addChildElement ( pivotNode );
                pivotNode->addParentElement ( parentNode );

                //    pivotNode = parentNode->AddChildNode();
                //    FCDSceneNode* parentNode = sceneNode->GetParent();
                //    FUAssert(parentNode != NULL, return NULL); // shouldn't happen.

                // TODO
                // Create a new node entity for the pivot.
                //    DaeEntity* pivotEntity = new DaeEntity(doc, pivotNode, dagPath.transform());

                // TODO
                //     // Process the previously imported scene node
                //     if (!pivotEntity->isOriginal)
                //     {
                //      // Take out the transforms: they are fair-game, for now.
                //      while (pivotNode->GetTransformCount() > 0) pivotNode->GetTransform(0)->Release();
                //
                //      // Mark the instances/children to be able to later delete the unused ones.
                //      size_t pivotInstanceCount = pivotNode->GetInstanceCount();
                //      for (size_t pi = 0; pi < pivotInstanceCount; ++pi)
                //      {
                //       pivotNode->GetInstance(pi)->SetUserHandle((void*) 1);
                //      }
                //     }
                //     else
                {
                    // Get the node ID and name
                    pivotNode->setId ( mDocumentExporter->dagPathToColladaId ( dagPath ) );
                }

                pivotNode->setNodeName ( mDocumentExporter->dagPathToColladaName ( dagPath ) );

                //     pivotEntity->instanceCount = 1;
                //     doc->GetSceneGraph()->AddElement(pivotEntity);
                //     pivotEntity->transform = new DaeTransform(doc, pivotNode);
                //     pivotEntity->transform->SetTransform(transformFn.object());
                //     pivotEntity->transform->SetTransformation(transformFn.transformation());
            }

            else
            {
                // Reset the local transformation.
                //     DaeEntity* currentEntity = (DaeEntity*) sceneNode->GetUserHandle();
                //     currentEntity->transform->SetTransformation(transformFn.transformation());
            }
        }

        // Export the instance on the pivot, if it exists.
        //   if (pivotNode == NULL) pivotNode = sceneNode;
        //   if (instantiate) doc->GetSceneGraph()->ExportInstance(pivotNode, entity->entity);

        //  return entity;
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
                    int nodeState;
                    DagHelper::getPlugValue ( thisNode, ATTR_NODE_STATE, nodeState );

                    // Append and disable the skin controller node.
                    ControllerStackItem* item = new ControllerStackItem();
                    item->isSkin = true;
                    item->skinControllerNode = thisNode;
                    item->nodeStates.push_back ( nodeState );
                    stack.push_back ( item );

                    DagHelper::setPlugValue ( thisNode, ATTR_NODE_STATE, 1 ); // pass-through.
                }
                else if ( thisNode.hasFn ( MFn::kBlendShape ) )
                {
                    int nodeState;
                    DagHelper::getPlugValue ( thisNode, ATTR_NODE_STATE, nodeState );

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

                    stack.back()->nodeStates.push_back ( nodeState );

                    DagHelper::setPlugValue ( thisNode, ATTR_NODE_STATE, 1 ); // pass-through.
                }
                else if ( thisNode.hasFn ( MFn::kMesh ) )
                {
                    // Queue up this mesh and set valid object parameters
                    ControllerMeshItem item;
                    item.mesh = thisNode;
                    DagHelper::getPlugValue ( thisNode, ATTR_INTERMEDIATE_OBJECT, item.isIntermediate );
                    DagHelper::getPlugValue ( thisNode, ATTR_VISIBILITY, item.isVisible );
                    DagHelper::setPlugValue ( thisNode, ATTR_INTERMEDIATE_OBJECT, false );
                    DagHelper::setPlugValue ( thisNode, ATTR_VISIBILITY, true );
                    meshStack.push_back ( item );
                }
            }
        }

        return true;
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
        const MFnMesh &fnMesh, const MFnGeometryFilter &clusterFn, MDagPath &outputShape )
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
    void ControllerExporter::exportJointSource( MayaController* targetController )
    {
        COLLADA::NameSource jointSource( mDocumentExporter->getStreamWriter() );
        String controllerId = targetController->controllerId;
        jointSource.setId ( controllerId + JOINTS_SOURCE_ID_SUFFIX );
        jointSource.setNodeName ( controllerId + JOINTS_SOURCE_ID_SUFFIX );
        jointSource.setArrayId ( controllerId + JOINTS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        jointSource.setAccessorStride ( 1 );

        // Retrieves the vertex positions.
        MDagPathArray influences = targetController->influences;
        uint numInfluences = influences.length();
        jointSource.setAccessorCount ( numInfluences );

        jointSource.getParameterNameList().push_back ( PARAM_TYPE_JOINT );
        jointSource.prepareToAppendValues();

        String boneBuffer = "bone";
        for (uint i=0; i<numInfluences; ++i)
        {
            std::ostringstream floatStream; 
            floatStream << i;
            String bone = boneBuffer + floatStream.str();
            jointSource.appendValues ( bone );
        }
        jointSource.finish();
    }

    //------------------------------------------------------
    void ControllerExporter::exportBindPosesSource( MayaController* targetController )
    {
        COLLADA::Float4x4Source bindPosesSource( mDocumentExporter->getStreamWriter() );
        String controllerId = targetController->controllerId;
        bindPosesSource.setId ( controllerId + BIND_POSES_SOURCE_ID_SUFFIX );
        bindPosesSource.setNodeName ( controllerId + BIND_POSES_SOURCE_ID_SUFFIX );
        bindPosesSource.setArrayId ( controllerId + BIND_POSES_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        bindPosesSource.setAccessorStride ( 16 );

        // Retrieves the vertex positions.
        MDagPathArray& influences = targetController->influences;
        uint numInfluences = influences.length();
        bindPosesSource.setAccessorCount ( numInfluences );

        bindPosesSource.getParameterNameList().push_back ( PARAM_TYPE_TRANSFORM );
        bindPosesSource.prepareToAppendValues();

        std::vector<MMatrix> bindPosesVec = targetController->bindPoses;
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
        String controllerId, 
        ColladaSkinController &colladaSkinController )
    {
        COLLADA::FloatSourceF weightSource( mDocumentExporter->getStreamWriter() );
        weightSource.setId ( controllerId + WEIGHTS_SOURCE_ID_SUFFIX );
        weightSource.setNodeName ( controllerId + WEIGHTS_SOURCE_ID_SUFFIX );
        weightSource.setArrayId ( controllerId + WEIGHTS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        weightSource.setAccessorStride ( 1 );

        // Create the vertex list
        std::vector<float> vertexVec;
        vertexVec.push_back(1.0f);
        uint numVertexPoints = 1;

        std::vector<SkinControllerVertex> vertexes = colladaSkinController.colladaVertexInfluences;
        for (uint i=0; i<vertexes.size(); ++i)
        {
            SkinControllerVertex vertex = vertexes[i];
            for (uint j=0; j<vertex.size(); ++j)
            {
                float value = vertex[j];
                if (vertex[j] != 0.0f) 
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
    void ControllerExporter::exportBindShapeTransform( ColladaSkinController &colladaSkinController )
    {
        // Write the bind shape transform matrix in the collada document.
        MMatrix mayaBindShapeMatrix = colladaSkinController.bindShapeTransform;
        double bindShapeMatrix[4][4] ;
        MConvert::convertMMatrixToDouble4x4 ( bindShapeMatrix, mayaBindShapeMatrix );
        addBindShapeTransform( bindShapeMatrix );
    }

    //------------------------------------------------------
    void ControllerExporter::exportController( 
        String skinTarget, 
        ColladaSkinController colladaSkinController, 
        MayaController* targetController )
    {
        // Get the unique id and the name of the current controller.
        String controllerId = targetController->controllerId;
        String controllerName = targetController->controllerName;

        // Opens the skin tag in the collada document.
        openSkin ( controllerId , controllerName, skinTarget );

        // Export the bind shape transform matrix
        exportBindShapeTransform( colladaSkinController );

        // Export the joint source
        exportJointSource( targetController );

        // Export the bind poses source
        exportBindPosesSource( targetController );

        // Export the weight source
        exportWeightSource( controllerId, colladaSkinController );

        {
            String jointSourceId;
            String jointBindSourceId;

            COLLADA::JointsElement jointsElement( mDocumentExporter->getStreamWriter() );
            COLLADA::InputList &jointsInputList = jointsElement.getInputList();
            jointsInputList.push_back ( COLLADA::Input ( COLLADA::JOINT, "#" + jointSourceId ) );
            jointsInputList.push_back ( COLLADA::Input ( COLLADA::BINDMATRIX, "#" + jointBindSourceId ) );
            jointsElement.add();
        }

        {
            String jointSourceId;
            String weightSourceId;

            uint offset = 0;
            COLLADA::VertexWeightsElement vertexWeightsElement( mDocumentExporter->getStreamWriter() );
            COLLADA::InputList &inputList = vertexWeightsElement.getInputList();
            inputList.push_back ( COLLADA::Input ( COLLADA::JOINT, "#" + jointSourceId, ++offset ) );
            inputList.push_back ( COLLADA::Input ( COLLADA::WEIGHT, "#" + weightSourceId, ++offset ) );

            // Generate the vertex count and match value strings and export the <v> and <vcount> elements

            // The list for the vertex values.
            std::vector<unsigned long> vertexMatches;

            // The input data 
            const std::vector<SkinControllerVertex> vertexes = colladaSkinController.colladaVertexInfluences;

            // Counter for the influence counts
            uint influenceCount = vertexes.size();

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
                        vertexMatches.push_back ( 0 );
                }
            }
            if (!vertexMatches.empty()) vertexMatches.pop_back();

            vertexWeightsElement.prepareToAppendValues();

            vertexWeightsElement.appendValues( vertexMatches );

            vertexWeightsElement.finish();
        }


        // Close the opened skin tag.
        closeSkin();

        // Close the opened controller tag.
        closeController();
    }

}

