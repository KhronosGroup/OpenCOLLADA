/*
Copyright (c) 2008 Intel Corporation
Copyright (c) 2005-2008 Sony Computer Entertainment America
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAMaya.

COLLADAMaya is free software; you can redistribute it and/or modify
it under the terms of the MIT License as published by the
Massachusetts Institute of Technology.

COLLADAMaya is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
MIT License for more details.

You should have received a copy of the MIT License along with
COLLADAMaya; see the file COPYING. If not have a look here:
http://www.opensource.org/licenses/mit-license.php
*/
#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaControllerLibrary.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaGeometryExporter.h"

#include <assert.h>

#include <maya/MItDependencyGraph.h>
#include <maya/MFnDagNode.h>
#include <maya/MFnTransform.h>


namespace COLLADAMaya
{

    //------------------------------------------------------
    ControllerLibrary::ControllerLibrary ( COLLADA::StreamWriter* streamWriter,
                                           DocumentExporter* documentExporter )
            : mDocumentExporter ( documentExporter )
    {}

    //------------------------------------------------------
    ControllerLibrary::~ControllerLibrary()
    {
        importedMorphControllers.clear();
        skinControllers.clear();
    }

    //------------------------------------------------------
    bool ControllerLibrary::hasController ( const MObject& node )
    {
        return hasSkinController ( node ) || hasMorphController ( node );
    }

    //------------------------------------------------------
    bool ControllerLibrary::hasSkinController ( const MObject& node )
    {
        MStatus status;
        MPlug plug = MFnDependencyNode ( node ).findPlug ( "inMesh", &status );

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
    bool ControllerLibrary::hasMorphController ( const MObject& node )
    {
        MPlug plug = MFnDependencyNode ( node ).findPlug ( "inMesh" );

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
    void ControllerLibrary::exportController ( SceneElement* sceneNode,
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

                if ( parentNode == NULL ) assert ( "Parent node can't be null!" ); // shouldn't happen.

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
    bool ControllerLibrary::exportController ( SceneElement* sceneNode, const MObject& node )
    {
        // The stacks of the controllers.
        ControllerStack stack;
        ControllerMeshStack meshStack;

        // Iterate upstream finding all the nodes which affect the mesh.
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

            if ( MS::kSuccess != stat ) return NULL;

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

        // At the end, export the base mesh
        mDocumentExporter->getGeometryExporter()->exportGeometry ( node );

//  DaeEntity* target = doc->GetGeometryLibrary()->exportMesh(node);

        // Export the controller stack
        bool alreadyHasSkin = false; // We cannot express more than one skin per geometry instance...

        for ( intptr_t i = stack.size() - 1; i >= 0; --i )
        {
            ControllerStackItem* item = stack[i];

            if ( item->isSkin )
            {
                if ( ExportOptions::exportJointsAndSkin() &&
                        !alreadyHasSkin )
                {
                    // Correctly avoid chained joint-clusters: only export the first joint cluster
                    // which exports the subsequent joint-clusters with it.
                    if ( !item->skinControllerNode.hasFn ( MFn::kJointCluster ) ||
                            i == 0 || !stack[i-1]->isSkin ||
                            !stack[i-1]->skinControllerNode.hasFn ( MFn::kJointCluster ) )
                    {
                        // TODO
//       target = exportSkinController(item->skinControllerNode, MDagPath::getAPathTo(node), target);
//       doc->GetEntityManager()->ExportEntity(item->skinControllerNode, target->entity);
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
}

