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
#include "COLLADAMayaControllerExporter.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaConversion.h"
#include "COLLADAMayaAnimationTools.h"
#include "COLLADAMayaAnimationExporter.h"

#include <assert.h>

#include "Math/COLLADABUMathUtils.h"

#include "COLLADASWBaseInputElement.h"

#include <maya/MItDependencyGraph.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>
#include <maya/MFnSkinCluster.h>
#include <maya/MItGeometry.h>
#include <maya/MFnWeightGeometryFilter.h>
#include <maya/MFnPointArrayData.h>
#include <maya/MFnBlendShapeDeformer.h>
#include <maya/MFnComponentListData.h>


namespace COLLADAMaya
{

    const String ControllerExporter::PARAM_TYPE_TRANSFORM    = "TRANSFORM";
    const String ControllerExporter::PARAM_TYPE_JOINT        = "JOINT";
    const String ControllerExporter::PARAM_TYPE_MORPH_TARGET = "MORPH_TARGET";
    const String ControllerExporter::PARAM_TYPE_MORPH_WEIGHT = "MORPH_WEIGHT";
    const String ControllerExporter::PARAM_TYPE_WEIGHT       = "WEIGHT";

    //------------------------------------------------------
    ControllerExporter::ControllerExporter ( COLLADASW::StreamWriter* streamWriter,
                                           DocumentExporter* documentExporter )
    : COLLADASW::LibraryControllers ( streamWriter )
    , mDocumentExporter ( documentExporter )
    , mExportedControllers ( NULL )
    {}

    //------------------------------------------------------
    ControllerExporter::~ControllerExporter()
    {
    }

    //------------------------------------------------------
    void ControllerExporter::exportControllers()
    {
        // Get the list with the transform nodes.
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* exportNodesTree = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        size_t length = exportNodesTree->size();
        for ( size_t i=0; i<length; ++i )
        {
            SceneElement* sceneElement = ( *exportNodesTree ) [i];
            exportControllers ( sceneElement );
        }

        closeLibrary();
    }

    //------------------------------------------------------
    void ControllerExporter::exportControllers( SceneElement* sceneElement )
    {
        // If we have a external reference, we don't need to export the data here.
        if ( !sceneElement->getIsLocal() ) return;
        if ( !sceneElement->getIsExportNode () ) return;

        // Check if it is a mesh and an export node
        SceneElement::Type sceneElementType = sceneElement->getType();
        if ( sceneElementType == SceneElement::MESH )
        {
            // Get the current dag path
            MDagPath dagPath = sceneElement->getPath();

            // Check if the current element is an instance. 
            // We don't need to export instances, because we export the original instanced element.
            bool isInstance = ( dagPath.isInstanced() && dagPath.instanceNumber() > 0 );

            // If the original instanced element isn't already exported, we have to export it now.
            if ( isInstance )
            {
                // Get the original instanced element.
                MDagPath instancedPath;
                dagPath.getPath ( instancedPath, 0 );
                SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
                SceneElement* instancedSceneElement = sceneGraph->findElement ( instancedPath );

                // Check if the geometry of original instanced element is already exported.
                SceneElement* exportedGeometryElement = sceneGraph->findExportedElement ( instancedPath );
                if ( exportedGeometryElement == 0 )
                {
                    // Export the original instanced element and push it in the exported list. 
                    GeometryExporter* geometryExporter = mDocumentExporter->getGeometryExporter ();
                    geometryExporter->exportControllerOrGeometry ( instancedSceneElement );
                }

                // Check if the controller of the original instanced element is already exported.
                std::vector<SceneElement*>::const_iterator controllerIter;
                controllerIter = find ( mExportedControllerSceneElements.begin (), mExportedControllerSceneElements.end (), instancedSceneElement );
                if ( controllerIter == mExportedControllerSceneElements.end () )
                {
                    // Create a skin/morph transform object and export the controller for the 
                    // the original instanced element.
                    if ( exportController ( instancedSceneElement ) )
                    {
                        // Push the scene element in the list of exported controller elements.
                        mExportedControllerSceneElements.push_back ( instancedSceneElement );
                    }
                }
            }
            else
            {
                // Create a skin/morph transform object and export the controller.
                if ( exportController ( sceneElement ) )
                {
                    // Push the scene element in the list of exported controller elements.
                    mExportedControllerSceneElements.push_back ( sceneElement );
                }
            }
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
        // Get the current dag path
        MDagPath dagPath = sceneElement->getPath();

        // Get the current mesh node.
        MObject meshNode = dagPath.node();

        // The stacks of the controllers for the affected nodes.
        ControllerStack stack;
        ControllerMeshStack meshStack;

        // Iterate upstream finding all the nodes which affect the mesh.
        if ( !findAffectedNodes ( meshNode, stack, meshStack ) )
        {
            return false;
        }

        // Disable any effects on the nodes.
        setControllerNodeStatesToNoEffect ( stack );
        // Set all meshes as visible and not intermediate.
        setValidMeshParameters ( meshStack );

        // Exports all the mesh affected nodes in the controller stack.
        exportControllerStack ( sceneElement, stack );

        // Reset the intermediate and visibility mesh parameters.
        resetMeshParameters ( meshStack );
        // Reset the controller node states.
        resetControllerNodeStates ( stack );
        // Delete the controller stack items and clear the stack.
        deleteControllerStackItems ( stack );

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
                        exportSkinController ( sceneElement, skinControllerNode, MDagPath::getAPathTo( meshNode ) );
                        alreadyHasSkin = true;
                    }
                }
            }
            else
            {
                exportMorphController( sceneElement, item->morphControllerNodes );
            }
        }
    }

    //------------------------------------------------------
    void ControllerExporter::exportMorphController(
        SceneElement* sceneElement,
        MObjectArray& controllerNodes )
    {
//         // Retrieve the target informations of the blend shape
//         uint controllerNodeCount2 = controllerNodes.length();
//         for (uint i = 0; i < controllerNodeCount2; ++i)
//         {
//             MFnBlendShapeDeformer deformerFn ( controllerNodes[i] );
//             String blendShapeName = deformerFn.name().asChar();
//             cout << endl << endl << "blendShapeName = " << blendShapeName << endl;
//
//             // get a list of objects that this blend shape deforms
//             MObjectArray base_objects;
//             deformerFn.getBaseObjects(base_objects);
//
//             // loop through each blend-shaped object
//             for ( uint i=0; i<base_objects.length(); ++i )
//             {
//                 // get the base shape
//                 MObject base = base_objects[i];
//                 // output info about the base shape
//                 MFnDependencyNode fnDep(base);
//                 String baseName = fnDep.name().asChar();
//                 cout << "baseName = " << baseName << endl;
//
//                 // get the weights
//                 unsigned int nWeights = deformerFn.numWeights();
//                 cout << "numWeights = " << nWeights << endl;
//
//                 // only want non-history items
//                 for (uint i=0; i<nWeights; ++i)
//                 {
//                     // get an array of target shapes
//                     MObjectArray targets;
//                     deformerFn.getTargets(base,i,targets);
//                     uint numTargets = targets.length();
//
//                     // output each target shape
//                     for (unsigned int j=0;j<targets.length();++j)
//                     {
//                         MObject target = targets[j];
//                         MFnDependencyNode fn ( target );
//                         String targetName = fn.name().asChar();
//                         cout << "targetName = " << targetName << endl;
//                     }
//                 }
//             }
//         }


        // =================================================

        uint controllerNodeCount = controllerNodes.length();
        if ( controllerNodeCount == 0 ) return;

        // TODO id preservation

        // Get the maya controller name
//        MString mayaControllerName = ( isSkinCluster ) ? clusterFn.name() : outputShape.partialPathName();
//        String controllerName = mayaControllerName.asChar();
        String mayaControllerId = MFnDependencyNode(controllerNodes[0]).name().asChar();

        // TODO
//         // Generate a COLLADA id for the new object
//         String colladaControllerId;
// 
//         // Check if there is an extra attribute "colladaId" and use this as export id.
//         MString attributeValue;
//         DagHelper::getPlugValue ( lightNode, BaseImporter::COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
//         if ( attributeValue != "" )
//         {
//             // Generate a valid collada name, if necessary.
//             colladaControllerId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
//         }
//         else
//         {
//             // Generate a COLLADA id for the new object
//             colladaControllerId = mDocumentExporter->dagPathToColladaId ( dagPath );
//         }
//         // Make the id unique and store it in a map.
//         colladaControllerId = mControllerIdList.addId ( colladaControllerId );
//         mMayaIdColladaIdMap [ mayaControllerId ] = colladaControllerId;


        String colladaControllerId;
        if ( !sceneElement->getNodeId().empty() )
        {
            colladaControllerId = sceneElement->getNodeId() +
                COLLADASW::LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX;
        }
        else
        {
            colladaControllerId = sceneElement->getNodeName() +
                COLLADASW::LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX;
        }

        // Check if the controller isn't already exported
        std::vector<String>::iterator controllerIter;
        controllerIter = find ( mExportedControllers.begin(), mExportedControllers.end(), colladaControllerId );
        if ( controllerIter != mExportedControllers.end() ) return;

        // Push the exported controller in the export list
        mExportedControllers.push_back ( colladaControllerId );

        // Create a morph controller to hold the data
        MorphController morphController( colladaControllerId, mayaControllerId );
        MorphControllerTargets& blendTargets = morphController.getMorphControllerTargets();
        std::vector<float>& blendWeights = morphController.getMorphControllerWeights();

        std::vector<MPlug> weightPlugs;

        // Retrieve the target informations of the blend shape
        for (uint i = 0; i < controllerNodeCount; ++i)
        {
            MFnDependencyNode controllerFn( controllerNodes[i] );
            MPlug inputTargetArrayPlug = controllerFn.findPlug( ATTR_INPUT_TARGET ); // "inputTarget"
            if ( inputTargetArrayPlug.attribute().isNull() ) continue;

            MPlug weightArrayPlug = controllerFn.findPlug( ATTR_WEIGHT ); // "weight"
            uint nextIndex = 0;

            uint inputTargetCount = inputTargetArrayPlug.numElements();
            for (uint j = 0; j < inputTargetCount; ++j)
            {
                MPlug inputTargetPlug = inputTargetArrayPlug.elementByPhysicalIndex(j);
                if ( inputTargetPlug.attribute().isNull() ) continue;

                MPlug inputTargetGroupArrayPlug =
                    DagHelper::getChildPlug( inputTargetPlug, ATTR_INPUT_TARGET_GROUP ); // "inputTargetGroup"
                if ( inputTargetGroupArrayPlug.attribute().isNull() ) continue;

                uint inputTargetGroupCount = inputTargetGroupArrayPlug.numElements();
                for (uint k = 0; k < inputTargetGroupCount; ++k)
                {
                    MPlug inputTargetGroupPlug = inputTargetGroupArrayPlug.elementByPhysicalIndex( k );
                    if (inputTargetGroupPlug.attribute().isNull()) continue;

                    MPlug inputTargetInputArrayPlug =
                        DagHelper::getChildPlug( inputTargetGroupPlug, ATTR_INPUT_TARGET_INPUT ); // "inputTargetInput"
                    if ( inputTargetInputArrayPlug.attribute().isNull() ) continue;

                    uint inputTargetInputCount = inputTargetInputArrayPlug.numElements();
                    for (uint m = 0; m < inputTargetInputCount; ++m)
                    {
                        MPlug inputTargetInput = inputTargetInputArrayPlug.elementByPhysicalIndex(m);
                        if (inputTargetInput.attribute().isNull()) continue;

                        MPlug inputTargetGeometryPlug =
                            DagHelper::getChildPlug( inputTargetInput, ATTR_INPUT_GEOM_TARGET ); // "inputGeomTarget"
                        if (inputTargetGeometryPlug.attribute().isNull()) continue;

                        // We now have a valid Maya blend shape target.
                        uint currentIndex = nextIndex++;
                        String blendShapeTargetId;
                        bool isInstanced = DagHelper::hasConnection( inputTargetGeometryPlug, false, true );
                        if (isInstanced)
                        {
                            // Find the first attached mesh DAG node.
                            MItDependencyGraph itDG(
                                inputTargetGeometryPlug,
                                MFn::kMesh,
                                MItDependencyGraph::kUpstream,
                                MItDependencyGraph::kDepthFirst,
                                MItDependencyGraph::kNodeLevel);
                            MObject targetObj = itDG.thisNode();
                            if (targetObj.isNull()) continue;

                            // This mesh is our morph target.
                            MDagPath targetPath = MDagPath::getAPathTo ( targetObj );
                            SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
                            if ( sceneGraph->findExportedElement( targetPath ) == NULL )
                            {
                                SceneElement* targetSceneElement = sceneGraph->findElement( targetPath );
                                if ( !targetSceneElement->getNodeId().empty() )
                                    blendShapeTargetId = targetSceneElement->getNodeId();
                                else blendShapeTargetId = targetSceneElement->getNodeName();
                            }
                        }
                        else
                        {
                            // TODO What the hell is this?
                            MPlug targetVertexListPlug =
                                DagHelper::getChildPlug( inputTargetInput, ATTR_INPUT_POINTS_TARGET ); // "inputPointsTarget"
                            if (inputTargetInput.attribute().isNull()) continue;

                            MPlug targetComponentListPlug =
                                DagHelper::getChildPlug( inputTargetInput, ATTR_INPUT_COMPONENT_TARGET ); // "inputComponentTarget"
                            if (inputTargetInput.attribute().isNull()) continue;

                            MGlobal::displayError ( "'exportMorphTarget' not implemented!" );
                            continue;
                            // We have a dangling geometry: create a FCDGeometry and fill it with the vertex positions.
//                            blendShapeTargetId = exportMorphTarget(targetVertexListPlug, targetComponentListPlug, currentIndex, baseMesh);
                        }

                        if ( !blendShapeTargetId.empty() )
                        {
                            MPlug weightPlug = weightArrayPlug.elementByLogicalIndex ( currentIndex );
                            if (weightPlug.attribute().isNull()) continue;

                            blendTargets.push_back( blendShapeTargetId );
                            weightPlugs.push_back( weightPlug );
                        }
                    }
                }
            }
        }

        size_t targetCount = blendTargets.size();
        if (targetCount == 0) return ;

        // Set the weights and export the morph target weight animations
        for ( size_t j=0; j<targetCount; ++j )
        {
            MPlug& weightPlug = weightPlugs[j];
            MPlug enveloppePlug = MFnDependencyNode( weightPlug.node() ).findPlug( ATTR_ENVELOPE );
            float envelope=1.0f, weight;
            if ( !enveloppePlug.attribute().isNull() )
                enveloppePlug.getValue ( envelope );
            weightPlug.getValue( weight );
            blendWeights.push_back( envelope * weight );

            String subId = colladaControllerId + MORPH_WEIGHTS_SOURCE_ID_SUFFIX;
            AnimationExporter* animExport = mDocumentExporter->getAnimationExporter();
            animExport->addPlugAnimation( weightPlug, subId, kSingle, XY_PARAMETERS, false, ( int ) j );
        }

        // Write the controller data into the COLLADA document
        writeMorphController ( sceneElement->getNodeName(), morphController );
    }

    //------------------------------------------------------
    void ControllerExporter::exportMorphTarget(
        MPlug& targetVertexListPlug,
        MPlug& targetComponentListPlug,
        uint currentIndex )
    {
        MStatus status;

        // Retrieve the data objects for the vertex list.
        MObject pointArrayData, componentListData;
        CHECK_STAT ( targetVertexListPlug.getValue ( pointArrayData ) );
        if ( pointArrayData.isNull() ) return ;

        CHECK_STAT ( targetComponentListPlug.getValue ( componentListData ) );
        if ( componentListData.isNull() ) return ;

        MFnPointArrayData vlistFn ( pointArrayData, &status ); CHECK_STAT ( status );
        uint relativePointCount = vlistFn.length(&status); CHECK_STAT ( status );
        if ( relativePointCount == 0 ) return ;

        MFnComponentListData componentListFn ( componentListData, &status ); CHECK_STAT ( status );
        uint componentCount = componentListFn.length ( &status ); CHECK_STAT ( status );
        if ( componentCount == 0 ) return ;


//         // Create the morph controller
//         COLLADASW::LibraryControllers
//
//         // Create a new FCollada geometry.
//         FUStringBuilder name(MConvert::ToFChar( MFnDependencyNode(targetVertexListPlug.node()).name() ) );
//         name.append(FC("-target")); name.append(currentIndex);
//         FCDGeometry* morphTarget = CDOC->GetGeometryLibrary()->AddEntity();
//         morphTarget->SetName(name.ToString());
//         fm::string id = TO_STRING(morphTarget->GetName());
//         morphTarget->SetDaeId(id);
//
//         // Create the mesh and fill in the position source with the source mesh's positions.
//         FCDGeometryMesh* targetMesh = morphTarget->CreateMesh();
//         FCDGeometrySource* positionSource = targetMesh->AddVertexSource(FUDaeGeometryInput::POSITION);
//         FUSStringBuilder sourceId(id); sourceId.append("-positions");
//         positionSource->SetDaeId(sourceId.ToString());
//         positionSource->SetStride(3);
//         FCDGeometrySource* baseSource = baseMesh->GetMesh()->GetPositionSource();
//         size_t valueCount = baseSource->GetValueCount();
//         positionSource->SetValueCount(valueCount);
//         float* data = positionSource->GetData();
//         memcpy(data, baseSource->GetData(), sizeof(float) * baseSource->GetDataCount());
//
//         uint offset = 0;
//         for (uint c = 0; c < componentCount; ++c)
//         {
//             MFnSingleIndexedComponent component(componentListFn[c]);
//             MIntArray elements;
//             CHECK_MSTATUS(component.getElements(elements));
//             uint elementCount = elements.length();
//             for (uint i = 0; i < elementCount; ++i)
//             {
//                 const MPoint& p = vlistFn[offset + i];
//                 uint pointIndex = elements[i];
//                 data[3 * pointIndex + 0] += (float) p.x;
//                 data[3 * pointIndex + 1] += (float) p.y;
//                 data[3 * pointIndex + 2] += (float) p.z;
//             }
//             offset += elementCount;
//         }
//
//         return morphTarget;
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
//      String controllerId = mDocumentExporter->dagPathToColladaId( targetDagPath ) +
//                                 LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;
        bool morphController =  hasMorphController( targetDagPath.node() );
        String controllerIdSuffix;
        if ( morphController )
            controllerIdSuffix = COLLADASW::LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX +
                COLLADASW::LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;
        else controllerIdSuffix = COLLADASW::LibraryControllers::SKIN_CONTROLLER_ID_SUFFIX;

        String controllerId;
        if ( !sceneElement->getNodeId().empty() )
            controllerId = sceneElement->getNodeId() + controllerIdSuffix;
        else controllerId = sceneElement->getNodeName() + controllerIdSuffix;
        
        // Check if the controller isn't already exported
        std::vector<String>::iterator controllerIter;
        controllerIter = find ( mExportedControllers.begin(), mExportedControllers.end(), controllerId );
        if ( controllerIter != mExportedControllers.end() ) return;

        // Push the exported controller in the export list
        mExportedControllers.push_back ( controllerId );

        // Figure out which type of skin controller we currently have: mesh-centric or joint-centric
        bool isJointCluster = controllerNode.hasFn(MFn::kJointCluster);
        bool isSkinCluster = controllerNode.hasFn(MFn::kSkinClusterFilter);
        if (!isJointCluster && !isSkinCluster) return;

        // Retrieve the instance information for this skinned character
        MFnGeometryFilter clusterFn(controllerNode);
        uint clusterIndex = retrieveInstanceInformation ( clusterFn, outputShape );

        // TODO id preservation

        // Create the controller name
        MString mayaControllerName = ( isSkinCluster ) ? clusterFn.name() : outputShape.partialPathName();
        String controllerName = mayaControllerName.asChar();

        // Get the skin target
        // If the output shape has a morph controller, the target
        // is not the shape's geometry, but the morph controller.
        MFnDependencyNode fn ( outputShape.node() );
        String skinTarget = DocumentExporter::mayaNameToColladaName ( fn.name() );
        if ( hasMorphController( outputShape.node() ) )
            skinTarget += COLLADASW::LibraryControllers::MORPH_CONTROLLER_ID_SUFFIX;

        // Create an skin controller to hold the data
        SkinController skinController( controllerId, controllerName );

        // Get the transform matrix for the shape.
        getBindShapeTransform( &skinController, clusterFn, isJointCluster, clusterIndex );

        // The weight filters to fill in.
        MObjectArray weightFilters;

        // Gather the list of joints
        gatherJoints( &skinController, controllerNode, weightFilters, clusterIndex );

        // Set the joint entry into the other scene element, which use this joints.
        MDagPathArray influences = skinController.getInfluences();
        unsigned int numInfluences = influences.length();
        for ( unsigned int i=0; i<numInfluences; ++i )
        {
            MDagPath skeletonPath = influences [i];
            String skeletonId = mDocumentExporter->dagPathToColladaId( skeletonPath );
            sceneElement->addSkeletonId ( skeletonId );

            // Set the id on the other instanced nodes.
            bool isInstanced = targetDagPath.isInstanced ();
            uint instanceNumber = targetDagPath.instanceNumber ();
            MDagPathArray pathes;
            MDagPath::getAllPathsTo( targetDagPath.node(), pathes );
            for (uint i=0; i<pathes.length(); ++i)
            {
                SceneElement* foundElement = mDocumentExporter->getSceneGraph()->findElement( pathes[i] );
                if ( foundElement != NULL )
                    foundElement->addSkeletonId ( skeletonId );
            }
        }

        gatherBindMatrices( &skinController, controllerNode );

        // Collect the vertex weights into the collada skin controller.
        collectVertexWeights(
            &skinController,
            controllerNode,
            outputShape,
            weightFilters,
            clusterIndex,
            numInfluences );

        // Create the joints
        createJoints ( &skinController );

        // Write the data into the collada document.
        writeSkinController( skinTarget, skinController );

    }

    //------------------------------------------------------
    void ControllerExporter::collectVertexWeights(
        SkinController* skinController,
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
        SkinControllerVertices& colladaInfluences = skinController->getVertexInfluences();
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

            WeightArray weights;
            MObject component = componentIt.component();
            if (skinClusterFn.getWeights(outputShape, component, weights, numInfluences) != MS::kSuccess)
            {
                weights.clear();
            }

            uint weightCount = weights.length();
            for (uint i = 0; i < weightCount; ++i)
            {
                if (!COLLADABU::Math::Utils::equals(weights[i], Weight(0)))
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
                if (COLLADABU::Math::Utils::equals(weight, 0.0f))
                {
                    SkinControllerVertex& vertex = colladaInfluences[componentIt.index()];
                    vertex[i] = weight;
                }
            }
        }
    }

    //------------------------------------------------------
    void ControllerExporter::gatherJoints(
        SkinController* skinController,
        const MObject &controllerNode,
        MObjectArray &weightFilters,
        const uint clusterIndex )
{
        // Gather the list of joints
        MDagPathArray& influences = skinController->getInfluences();
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
        SkinController* skinController,
        const MObject& controllerNode )
    {
        // The list of joints
        MDagPathArray& influences = skinController->getInfluences();

        // Request a change in capacity
        uint numInfluences = influences.length();
        std::vector<MMatrix>& bindPoses = skinController->getBindPoses();
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
        SkinController* skinController )
    {
        // Gather the list of joints
        const MDagPathArray& influences = skinController->getInfluences();

        // Create the joints with their ids.
        SkinControllerJoints& joints = skinController->getJoints();
        uint numInfluences = influences.length();
        joints.resize( numInfluences );

        for (uint i=0; i<numInfluences; ++i)
        {
            MDagPath dagPath = influences[i];

            SkinControllerJoint &joint = joints[i];
            joint.first = mDocumentExporter->dagPathToColladaId ( dagPath );
            joint.second = skinController->getBindPoses()[i];
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
        SkinController* skinController,
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
    void ControllerExporter::disableBlendShape ( ControllerStack &stack )
    {
        // Disable the blend shape
        for ( size_t i=0; i<stack.size(); ++i )
        {
            ControllerStackItem* item = stack[i];

            // Disable the blend shape node
            if ( item->skinControllerNode.hasFn ( MFn::kBlendShape ) )
            {
                // Attach the function set
                MFnBlendShapeDeformer fn ( item->skinControllerNode );

                // get the envelope attribute plug
                MPlug plug = fn.findPlug ( ATTR_ENVELOPE );

                // Get the old value
                float envelope;
                MStatus status = plug.getValue ( envelope );
                if ( status != MStatus::kSuccess ) return ;
                item->envelope = envelope;

                // set to 0 to disable FFD effect
                plug.setValue (0.0f) ;
            }
        }
    }

    //------------------------------------------------------
    void ControllerExporter::enableBlendShape ( ControllerStack &stack )
    {
        // Enable the blend shape
        for ( size_t i=0; i<stack.size(); ++i )
        {
            ControllerStackItem* item = stack[i];

            // Disable the blend shape node
            if ( item->skinControllerNode.hasFn ( MFn::kBlendShape ) )
            {
                // Attach the function set
                MFnBlendShapeDeformer fn ( item->skinControllerNode );

                // get the envelope attribute plug
                MPlug plug = fn.findPlug ( ATTR_ENVELOPE );

                // set to 0 to disable FFD effect
                plug.setValue ( item->envelope );
            }
        }
    }

    //------------------------------------------------------
    uint ControllerExporter::retrieveInstanceInformation(
        const MFnGeometryFilter &clusterFn,
        MDagPath &outputShape )
    {
        MStatus status;

        // Attach a function set to the controller node.
        MFnMesh fnMesh ( outputShape, &status );
        CHECK_STAT (status);

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
            CHECK_STATUS_AND_RETURN(status, NULL);
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
    void ControllerExporter::writeSkinJointSource( const SkinController &skinController )
    {
        COLLADASW::NameSource jointSource( mDocumentExporter->getStreamWriter() );
        String controllerId = skinController.getControllerId();
        jointSource.setId ( controllerId + JOINTS_SOURCE_ID_SUFFIX );
        jointSource.setNodeName ( controllerId + JOINTS_SOURCE_ID_SUFFIX );
        jointSource.setArrayId ( controllerId + JOINTS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        jointSource.setAccessorStride ( 1 );

        // Retrieves the vertex positions.
        const MDagPathArray& influences = skinController.getInfluences();
        uint numInfluences = influences.length();
        jointSource.setAccessorCount ( numInfluences );

        jointSource.getParameterNameList().push_back ( PARAM_TYPE_JOINT );
        jointSource.prepareToAppendValues();

        const SkinControllerJoints& joints = skinController.getJoints();
        SkinControllerJoints::const_iterator it = joints.begin();
        for (; it<joints.end(); ++it)
        {
            String boneId = (*it).first;
            jointSource.appendValues ( boneId );
        }
        jointSource.finish();
    }

    //------------------------------------------------------
    void ControllerExporter::writeMorphTargetSource( const MorphController &morphController )
    {
        COLLADASW::IdRefSource targetSource( mDocumentExporter->getStreamWriter() );
        String controllerId = morphController.getControllerId();
        targetSource.setId ( controllerId + TARGETS_SOURCE_ID_SUFFIX );
        targetSource.setNodeName ( controllerId + TARGETS_SOURCE_ID_SUFFIX );
        targetSource.setArrayId ( controllerId + TARGETS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        targetSource.setAccessorStride ( 1 );

        // Retrieve the morph controller targets.
        const MorphControllerTargets& morphControllerTargets = morphController.getMorphControllerTargets();
        size_t numTargets = morphControllerTargets.size();
        targetSource.setAccessorCount ( ( unsigned long ) numTargets );
        targetSource.getParameterNameList().push_back ( PARAM_TYPE_MORPH_TARGET );
        targetSource.prepareToAppendValues();
        targetSource.appendValues ( morphControllerTargets );
        targetSource.finish();
    }

    //------------------------------------------------------
    void ControllerExporter::writeSkinBindPosesSource( const SkinController &skinController )
    {
        COLLADASW::Float4x4Source bindPosesSource( mDocumentExporter->getStreamWriter() );
        String controllerId = skinController.getControllerId();
        bindPosesSource.setId ( controllerId + BIND_POSES_SOURCE_ID_SUFFIX );
        bindPosesSource.setNodeName ( controllerId + BIND_POSES_SOURCE_ID_SUFFIX );
        bindPosesSource.setArrayId ( controllerId + BIND_POSES_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        bindPosesSource.setAccessorStride ( 16 );

        // Retrieves the vertex positions.
        const MDagPathArray& influences = skinController.getInfluences();
        uint numInfluences = influences.length();
        bindPosesSource.setAccessorCount ( numInfluences );

        bindPosesSource.getParameterNameList().push_back ( PARAM_TYPE_TRANSFORM );
        bindPosesSource.prepareToAppendValues();

        const std::vector<MMatrix>& bindPosesVec = skinController.getBindPoses();
        size_t numBindPoses = bindPosesVec.size();
        for (size_t i=0; i<bindPosesVec.size(); ++i)
        {
            MMatrix mayaBindPoses = bindPosesVec[i];
            double bindPoses[4][4];
            convertMMatrixToDouble4x4(bindPoses, mayaBindPoses);

            // Convert the  maya internal unit type of the transform part of the
            // matrix from centimeters into the working units of the current scene!
            for ( uint i=0; i<3; ++i)
                bindPoses [i][3] = MDistance::internalToUI ( bindPoses [i][3] );

            bindPosesSource.appendValues ( bindPoses );
        }
        bindPosesSource.finish();
    }

    //------------------------------------------------------
    void ControllerExporter::writeSkinWeightSource( const SkinController &skinController )
    {
        String controllerId = skinController.getControllerId();
        COLLADASW::FloatSourceF weightSource( mDocumentExporter->getStreamWriter() );
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

        const SkinControllerVertices& vertexes = skinController.getVertexInfluences();
        for (uint i=0; i<vertexes.size(); ++i)
        {
            SkinControllerVertex vertex = vertexes[i];
            for (uint j=0; j<vertex.size(); ++j)
            {
                // We don't need to write the zero weight, cause then there is no
                // influence. We don't write the one weights, cause we have written
                // (see below) a one weight in front of the vertex_weights array and
                // always reference to it from the vertex_weights array.
                if ( !COLLADABU::Math::Utils::equalsZero( vertex[j] ) &&
                     !COLLADABU::Math::Utils::equals( vertex[j], 1.0f ) )
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
    void ControllerExporter::writeMorphWeightSource( const MorphController &morphController )
    {
        String controllerId = morphController.getControllerId();
        COLLADASW::FloatSourceF weightSource( mDocumentExporter->getStreamWriter() );
        weightSource.setId ( controllerId + MORPH_WEIGHTS_SOURCE_ID_SUFFIX );
        weightSource.setNodeName ( controllerId + MORPH_WEIGHTS_SOURCE_ID_SUFFIX );
        weightSource.setArrayId ( controllerId + MORPH_WEIGHTS_SOURCE_ID_SUFFIX + ARRAY_ID_SUFFIX );
        weightSource.setAccessorStride ( 1 );

        // Get the morph weights
        const std::vector<float> morphWeights = morphController.getMorphControllerWeights ();
        weightSource.setAccessorCount ( ( unsigned long ) morphWeights.size() );
        weightSource.getParameterNameList().push_back ( PARAM_TYPE_MORPH_WEIGHT );
        weightSource.prepareToAppendValues();
        weightSource.appendValues ( morphWeights );
        weightSource.finish();
    }

    //------------------------------------------------------
    void ControllerExporter::writeSkinBindShapeTransform ( const SkinController &skinController )
    {
        // Write the bind shape transform matrix in the collada document.
        const MMatrix& mayaBindShapeMatrix = skinController.getBindShapeTransform();
        double bindShapeMatrix[4][4] ;
        convertMMatrixToDouble4x4 ( bindShapeMatrix, mayaBindShapeMatrix );

        // Convert the  maya internal unit type of the transform part of the
        // matrix from centimeters into the working units of the current scene!
        for ( uint i=0; i<3; ++i)
            bindShapeMatrix [i][3] = MDistance::internalToUI ( bindShapeMatrix [i][3] );

        addBindShapeTransform ( bindShapeMatrix );
    }

    //------------------------------------------------------
    void ControllerExporter::writeSkinController(
        const String skinTarget,
        const SkinController &skinController )
    {
        // Get the unique id and the name of the current controller.
        String controllerId = skinController.getControllerId();
        String controllerName = skinController.getControllerName();

        // Opens the skin tag in the collada document.
        openSkin ( controllerId , controllerName, COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, skinTarget ) );

        writeSkinBindShapeTransform( skinController );
        writeSkinJointSource( skinController );
        writeSkinBindPosesSource( skinController );
        writeSkinWeightSource( skinController );
        writeSkinElementJoints( skinController );
        writeSkinElementVertexWeights( skinController );

        // Close the opened skin tag.
        closeSkin();

        // Close the opened controller tag.
        closeController();
    }

    //------------------------------------------------------
    void ControllerExporter::writeMorphController (
        const String morphTarget,
        const MorphController &morphController )
    {
        // Get the unique id and the name of the current controller.
        String controllerId = morphController.getControllerId();
        String controllerName = morphController.getControllerName();

        // Opens the skin tag in the collada document.
        openMorph ( controllerId , controllerName, COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, morphTarget ) );

        writeMorphTargetSource( morphController );
        writeMorphWeightSource ( morphController );
        writeMorphElementTargets ( morphController );

        // Close the opened skin tag.
        closeMorph();

        // Close the opened controller tag.
        closeController();

    }

    //------------------------------------------------------
    void ControllerExporter::writeSkinElementVertexWeights( const SkinController &skinController )
    {
        String controllerId = skinController.getControllerId();
        String jointSourceId = controllerId + JOINTS_SOURCE_ID_SUFFIX;
        String weightSourceId = controllerId + WEIGHTS_SOURCE_ID_SUFFIX;

        uint offset = 0;
        COLLADASW::VertexWeightsElement vertexWeightsElement( mDocumentExporter->getStreamWriter() );
        COLLADASW::InputList &inputList = vertexWeightsElement.getInputList();
        inputList.push_back ( COLLADASW::Input ( COLLADASW::JOINT, COLLADASW::URI (COLLADABU::Utils::EMPTY_STRING, jointSourceId ), offset++ ) );        inputList.push_back ( COLLADASW::Input ( COLLADASW::WEIGHT, COLLADASW::URI (COLLADABU::Utils::EMPTY_STRING, weightSourceId ), offset++ ) );
        // The list for the vertex values.
        std::vector<unsigned long> vertexMatches;

        // The input data
        const SkinControllerVertices& vertexes = skinController.getVertexInfluences();

        // Counter for the influence counts
        size_t influenceCount = vertexes.size();
        vertexWeightsElement.setCount( ( unsigned long ) influenceCount );

        // Generate the vertex count and match value strings and export the <v> and <vcount> elements
        uint weightOffset = 1;
        for (size_t j=0; j<influenceCount; ++j)
        {
            SkinControllerVertex vertex = vertexes[j];
            vertexWeightsElement.getVCountList().push_back( ( unsigned long ) vertex.size() );

            std::map<int, float>::const_iterator it = vertex.begin();
            for (; it!=vertex.end(); ++it)
            {
                vertexMatches.push_back( (*it).first );

                if ( !COLLADABU::Math::Utils::equals( (*it).second, 1.0f ) )
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
    void ControllerExporter::writeSkinElementJoints( const SkinController &skinController )
    {
        String controllerId = skinController.getControllerId();
        String jointSourceId = controllerId + JOINTS_SOURCE_ID_SUFFIX;
        String jointBindSourceId = controllerId + BIND_POSES_SOURCE_ID_SUFFIX;

        COLLADASW::JointsElement jointsElement( mDocumentExporter->getStreamWriter() );
        COLLADASW::InputList &jointsInputList = jointsElement.getInputList();
        jointsInputList.push_back ( COLLADASW::Input ( COLLADASW::JOINT, COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, jointSourceId ) ) );
        jointsInputList.push_back ( COLLADASW::Input ( COLLADASW::BINDMATRIX, COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, jointBindSourceId ) ) );
        jointsElement.add();
    }

    //------------------------------------------------------
    void ControllerExporter::writeMorphElementTargets( const MorphController &morphController )
    {
        String controllerId = morphController.getControllerId();
        String targetSourceId = controllerId + TARGETS_SOURCE_ID_SUFFIX;
        String morphWeightsSourceId = controllerId + MORPH_WEIGHTS_SOURCE_ID_SUFFIX;

        COLLADASW::TargetsElement targetsElement( mDocumentExporter->getStreamWriter() );
        COLLADASW::InputList &targetsInputList = targetsElement.getInputList();
        targetsInputList.push_back ( COLLADASW::Input ( COLLADASW::MORPH_TARGET, COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, targetSourceId ) ) );
        targetsInputList.push_back ( COLLADASW::Input ( COLLADASW::MORPH_WEIGHT, COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, morphWeightsSourceId ) ) );
        targetsElement.add();
    }

    //------------------------------------------------------
    bool ControllerExporter::findAffectedNodes(
        const MObject& node,
        ControllerStack &stack,
        ControllerMeshStack &meshStack )
    {
        MPlug plug = MFnDependencyNode ( node ).findPlug ( ATTR_IN_MESH );

        if ( plug.isConnected() )
        {
            MStatus status;
            MItDependencyGraph dgIt ( plug,
                MFn::kInvalid,
                MItDependencyGraph::kUpstream,
                MItDependencyGraph::kBreadthFirst,
                MItDependencyGraph::kNodeLevel,
                &status );
            if ( MS::kSuccess != status ) return false;

            dgIt.disablePruningOnFilter();
            for ( ; ! dgIt.isDone(); dgIt.next() )
            {
                MObject thisNode = dgIt.thisNode();

                MFnDependencyNode fn( thisNode );
                String nodeName = fn.name().asChar();

                if ( thisNode.hasFn ( MFn::kSkinClusterFilter ) || thisNode.hasFn ( MFn::kJointCluster ) )
                {
                    // Append the skin controller node.
                    ControllerStackItem* item = new ControllerStackItem();
                    item->isSkin = true;
                    item->skinControllerNode = thisNode;
                    stack.push_back ( item );
                }
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
                size_t nodeStateSize = item->nodeStates.size();
                assert ( nodeStateSize >= 1 );
                int nodeState = item->nodeStates.front();
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
                size_t nodeStateSize = item->nodeStates.size();
                for ( uint j=0; j<item->morphControllerNodes.length(); ++j )
                {
                    assert ( nodeStateSize >= j );
                    int nodeState = item->nodeStates[j];
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

