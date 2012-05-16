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
#include "COLLADASWNode.h"
#include "COLLADASWInstanceGeometry.h"
#include "COLLADASWBindMaterial.h"

#include <maya/MSelectionList.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MItDependencyGraph.h>
#include <maya/MItDag.h>
#include <maya/MFnSkinCluster.h>
#include <maya/MFnTransform.h>

#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaVisualSceneExporter.h"
#include "COLLADAMayaAnimationSampleCache.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaSetHelper.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaPlatform.h"
#include "assert.h"


namespace COLLADAMaya
{


    // ------------------------------------------------------------
    SceneGraph::SceneGraph ( DocumentExporter* documentExporter )
            : mDocumentExporter ( documentExporter ),
            mExportNodesTree ( NULL )
    {}

    // ------------------------------------------------------------
    SceneGraph::~SceneGraph()
    {
        {
            // Release the nodes tree
            SceneElementsList::iterator it = mExportNodesTree.begin();
            for ( ; it!= mExportNodesTree.end(); ++it )
            {
                SceneElement* sceneElement = *it;
                delete sceneElement;
            }
            mExportNodesTree.clear();
        }

        {
            // The elements are all in the mExportNodesTree, where they will deleted.
            mExportedNodes.clear();
        }

    }

    // ------------------------------------------------------------
    bool SceneGraph::retrieveExportNodes()
    {
        // Create a selection list containing only the root nodes (implies export all!)
        MSelectionList allTargets;
        for (   MItDag it ( MItDag::kBreadthFirst ); 
                it.depth()<=1 && it.item()!=MObject::kNullObj; 
                it.next() )
        {
            MDagPath path;
            MStatus status = it.getPath ( path );
            String pathName = path.fullPathName().asChar();

            // Attach a function set
            MFnDependencyNode fn ( path.node() );
            String theNodeName = fn.name().asChar();

            // Check if it's the world node
            if ( it.depth() == 0 ) continue;

            if ( status == MStatus::kSuccess )
            {
                if ( mExportSelectedOnly )
                    allTargets.add ( path );
                else
                    mTargets.add ( path );
            }
        }

        // now fill in the targets, either the same as allTargets, or it is export selection only
        if ( mExportSelectedOnly )
        {
            // Export the selection:
            // Grab the selected DAG components
            if ( MStatus::kFailure == MGlobal::getActiveSelectionList ( mTargets ) )
            {
                std::cerr << "MGlobal::getActiveSelectionList" << std::endl;
                return false;
            }

            // For all the non-transforms selected, make sure to extend to the transforms underneath.
            MDagPathArray additions;
            MIntArray removals;

            for ( uint32 i = 0; i < mTargets.length(); ++i )
            {
                MDagPath itemPath;
                mTargets.getDagPath ( i, itemPath );
                if ( !itemPath.node().hasFn ( MFn::kTransform ) )
                {
                    MDagPath transformPath = itemPath;
                    while ( transformPath.length() > 0 )
                    {
                        transformPath.pop();

                        if ( !mTargets.hasItem ( transformPath ) )
                        {
                            additions.append ( transformPath );
                            break;
                        }
                    }
                    removals.append ( i );
                }
            }

            for ( uint32 i = 0; i < removals.length(); ++i ) mTargets.remove ( removals[i] - i );
            for ( uint32 i = 0; i < additions.length(); ++i ) mTargets.add ( additions[i] );

            // Add all the forced nodes to the list.
            uint32 forceNodeCount = mForcedNodes.length();
            for ( uint32 i = 0; i < forceNodeCount; ++i )
            {
                MDagPath p = mForcedNodes[i];
                if ( mTargets.hasItem ( p ) ) continue;

                mTargets.add ( p );
            }

            // Add additional selection paths for any objects in our
            // selection which have been instanced (either directly, or
            // via instancing of an ancestor) - as otherwise, the selection
            // will only include ONE of the DAG paths
            //
            addInstancedDagPaths ( mTargets );

            // remove any selected nodes CONTAINED within other selected
            // hierarchies (to ensure we don't export subtrees multiple times)
            //
            removeMultiplyIncludedDagPaths ( mTargets );
        }

        return true;
    }

    // ------------------------------------------------------------
    bool SceneGraph::create ( bool selectionOnly )
    {
        // The flag, if just the selected elements should be exported.
        mExportSelectedOnly = selectionOnly;

        // Add all the animation expressions
        MItDependencyNodes depIter ( MFn::kExpression );
        for ( ; !depIter.isDone(); depIter.next() )
        {
            MObject item = depIter.item();
            if ( item.hasFn ( MFn::kExpression ) )
            {
                mAnimationExpressions.append ( item );
            }
        }

        // Push all nodes from root down to all meshes which have to be exported in a list.
        findForcedNodes ();

        // Fills the list with all root targets to export.
        bool success = retrieveExportNodes ();
        
        // Create a selection list containing only the root nodes (implies export all!)
        uint length = mTargets.length();
        for ( uint i=0; i<mTargets.length(); ++i )
        {
            MDagPath dagPath;
            MStatus status = mTargets.getDagPath ( i, dagPath );
            if ( status != MStatus::kSuccess ) return false;

            // This node has no transform - i.e., it's the world node
            MObject transformNode = dagPath.transform ( &status );
            if ( !status && status.statusCode () == MStatus::kInvalidParameter ) continue;

            // Check if it is a valid transform node
            MFnDagNode transform ( transformNode, &status );
            if ( !status )
            {
                status.perror ( "MFnDagNode constructor" );
                return false;
            }

            // Create a new scene element
            SceneElement* sceneElement = createSceneElement ( dagPath );

            // Push the root nodes into the tree.
            // If the root node is instanced, push it at the beginning (no instance on root!).
            if ( dagPath.isInstanced () )
                mExportNodesTree.insert ( mExportNodesTree.begin (), sceneElement );
            else
                mExportNodesTree.push_back ( sceneElement );
            
            // Create the child elements
            //if ( sceneElement->getIsExportNode() )
            {
                createChildSceneElements ( sceneElement );
            }
        }

        return true;
    }

    // ------------------------------------------------------------
    void SceneGraph::sampleAnimationExpressions ()
    {
        // Start by caching the expressions that will be sampled
        uint expressionCount = mAnimationExpressions.length();
        for ( uint i=0; i<expressionCount; ++i )
        {
            // expressions only for sampling
            mDocumentExporter->getAnimationCache()->sampleExpression ( mAnimationExpressions[i] );
        }
    }

    // ------------------------------------------------------------
    SceneElement* SceneGraph::createSceneElement ( 
        const MDagPath &dagPath,
        SceneElement* parentSceneElement )
    {
        // Create a new scene element
        SceneElement* sceneElement = new SceneElement ( dagPath );

        // Attach a function set
        MFnDependencyNode fn ( dagPath.node() );

        // Check for multiple instances.
        bool isInstanced = dagPath.isInstanced ();
        if ( parentSceneElement == 0 )
        {
//             dagPath.getAllPathsTo ( ) ()
        }

        // Get the node name
        String nodeName = DocumentExporter::mayaNameToColladaName ( fn.name() );
        sceneElement->setNodeName ( nodeName );

        // Check if it's a node to export and
        // tell the scene node to be transformed or not.
        bool isForced = false;
        bool isVisible = false;
        bool isExportNode = getIsExportNode ( dagPath, isForced, isVisible );
        sceneElement->setIsForced ( isForced );
        sceneElement->setIsVisible ( isVisible );

        // Check for a file reference
        MFnDagNode dagFn ( dagPath );
        bool isLocal = !dagFn.isFromReferencedFile();
        if ( ExportOptions::exportXRefs() && ExportOptions::dereferenceXRefs()) isLocal = true;
        if ( !isLocal && !ExportOptions::exportXRefs() ) isExportNode = false;
        sceneElement->setIsExportNode ( isExportNode );
        sceneElement->setIsLocal ( isLocal );

        if ( parentSceneElement != NULL )
        {
            if ( !sceneElement->containsParentElement ( parentSceneElement ) )
                sceneElement->addParentElement ( parentSceneElement );

            if ( !parentSceneElement->containsChildElement ( sceneElement ) )
                parentSceneElement->addChildElement ( sceneElement );
        }

        return sceneElement;
    }

    // ------------------------------------------------------------
    bool SceneGraph::createChildSceneElements ( SceneElement* sceneElement )
    {
        // Get the current path
        MDagPath dagPath = sceneElement->getPath();

        // Now, whip through this node's DAG children
        MFnDagNode dagFn ( dagPath );

        uint childCount = dagFn.childCount();
        for ( uint i = 0; i < childCount; ++i )
        {
            MObject child = dagFn.child ( i );
            MDagPath childDagPath = dagPath;
            childDagPath.push ( child );

            SceneElement* childSceneElement = createSceneElement ( childDagPath, sceneElement );

            // Recursive call to take the children
            createChildSceneElements ( childSceneElement );
        }

        return true;
    }

    // ---------------------------------------------------------------
    void SceneGraph::endExport()
    {
        MStatus status;

        /*
        // TODO
        // Write out the scene parameters
        CDOC->SetStartTime((float) AnimationHelper::AnimationStartTime().as(MTime::kSeconds));
        CDOC->SetEndTime((float) AnimationHelper::AnimationEndTime().as(MTime::kSeconds));
        */

        mForcedNodes.clear();
    }

    // --------------------------------------------------------------------
    bool SceneGraph::getIsExportNode ( 
        const MDagPath& dagPath, 
        bool& isForced,
        bool& isVisible )
    {
        // Does this dagPath already exist? If so, only recurse if FollowInstancedChildren() is set.
        MFnDagNode dagFn ( dagPath );
        String dagNodeName = dagFn.name().asChar();

        bool isSceneRoot = dagPath.length() == 0;

        // Ignore default and intermediate nodes (history items)
        bool isIntermediateObject = dagFn.isIntermediateObject();
        if ( ( dagFn.isDefaultNode() && !isSceneRoot ) || isIntermediateObject )
        {
            return false;
        }

        MString nodeName = dagPath.partialPathName();
        if ( nodeName == MString ( NIMA_INTERNAL_PHYSIKS ) )
        {
            // Skip this node, which is only used
            // by Nima as a work-around for a Maya bug.
            return false;
        }

        // If we are not already forcing this node, its children
        // check whether we should be forcing it (skinning of hidden joints).
        isForced = isForcedNode ( dagPath );
        DagHelper::getPlugValue ( dagPath.node(), ATTR_VISIBILITY, isVisible );
        bool isInstanced = dagPath.isInstanced();
        uint instanceNumber = dagPath.instanceNumber();

        if ( !isForced )
        {
            // Check for visibility
            if ( !ExportOptions::exportInvisibleNodes() && !isVisible )
            {
                // Check if the visibility of the element is animated.
                AnimationSampleCache* animationCache = mDocumentExporter->getAnimationCache();
                if ( !AnimationHelper::isAnimated ( animationCache, dagPath.node(), ATTR_VISIBILITY ) )
                {
                    return false;
                }
            }
            else if ( !isVisible && !ExportOptions::exportDefaultCameras() )
            {
                // Check for the default camera transform names.
                if ( nodeName == CAMERA_PERSP || nodeName == CAMERA_TOP || nodeName == CAMERA_SIDE || nodeName == CAMERA_FRONT ||
                     nodeName == CAMERA_PERSP_SHAPE || nodeName == CAMERA_TOP_SHAPE || nodeName == CAMERA_SIDE_SHAPE || nodeName == CAMERA_FRONT_SHAPE )
                    return false;
            }
        }

        isForced &= !isVisible;
        if ( !isForced )
        {
            // We don't want to process manipulators
            if ( dagPath.hasFn ( MFn::kManipulator ) || dagPath.hasFn ( MFn::kViewManip ) ) return false;

            // Check for constraints which are not exported
            //if ( !ExportOptions::exportConstraints() && dagPath.hasFn ( MFn::kConstraint ) ) return false;
            if ( dagPath.hasFn ( MFn::kConstraint ) ) return false;

            // Check set membership exclusion/inclusion
            if ( SetHelper::isExcluded ( dagPath ) ) return false;
        }

        return true;
    }

    // --------------------------------------------------------------------
    MStatus SceneGraph::removeMultiplyIncludedDagPaths ( MSelectionList& selectionList )
    {
        // As we're potentially deleting elements out of the selection list
        // it's easiest to avoid array bound check issues by walking the
        // list backwards.
        MStatus status;
        int length=selectionList.length ( &status );

        if ( status != MStatus::kSuccess )
            return MStatus::kFailure;

        for ( int i = length - 1; i >= 0; --i )
        {
            MDagPath dagIPath;

            if ( selectionList.getDagPath ( i, dagIPath ) != MStatus::kSuccess )
                return MStatus::kFailure;

            uint dagIdepth = dagIPath.length();
            for ( int j = i - 1; j >= 0; --j )
            {
                MDagPath dagJPath;
                if ( selectionList.getDagPath ( j, dagJPath ) != MStatus::kSuccess )
                    return MStatus::kFailure;

                // Test if the longer of these two dag paths contains the shorter ...
                uint dagJdepth = dagJPath.length();
                if ( dagJdepth >= dagIdepth )
                {
                    bool isParent = false;
                    for ( int depth = dagIdepth - 1; depth > 0 && !isParent; --depth )
                    {
                        dagJPath.pop();
                        isParent = dagJPath.node() == dagIPath.node();
                    }

                    if ( isParent )
                    {
                        selectionList.remove ( j );
                        i--;
                    }
                }
                else
                {
                    bool isParent = false;
                    MDagPath dagIt = dagIPath;
                    for ( int depth = dagIdepth - 1; depth > 0 && !isParent; --depth )
                    {
                        dagIt.pop();
                        isParent = dagJPath.node() == dagIt.node();
                    }

                    if ( isParent )
                    {
                        selectionList.remove ( i );
                        break;
                    }
                }
            }
        }

        return MStatus::kSuccess;
    }

    // --------------------------------------------------------------------
    MStatus SceneGraph::addInstancedDagPaths ( MSelectionList& selectionList )
    {
        MStatus status;
        int length = selectionList.length ( &status );
        if ( status != MStatus::kSuccess ) return MStatus::kFailure;

        for ( int i=0; i<length; i++ )
        {
            MDagPath dagPath;
            if ( selectionList.getDagPath ( i, dagPath ) != MStatus::kSuccess ) return MStatus::kFailure;

            if ( dagPath.isInstanced() )
            {
                int includedInstance=dagPath.instanceNumber ( &status );
                if ( status != MStatus::kSuccess ) return MStatus::kFailure;

                MObject object=dagPath.node ( &status );
                if ( status != MStatus::kSuccess ) return MStatus::kFailure;

                MDagPathArray paths;
                if ( MDagPath::getAllPathsTo ( object, paths ) != MStatus::kSuccess ) return MStatus::kFailure;

                int numPaths=paths.length();
                for ( int p=0; p<numPaths; p++ )
                    if ( p!=includedInstance )
                        selectionList.add ( paths[p] );
            }
        }

        return MStatus::kSuccess;
    }

    // --------------------------------------------------------------------
    SceneElement* SceneGraph::findElement ( const MDagPath& dagPath )
    {
        static bool output = false;
        for ( SceneElementsList::iterator it = mExportNodesTree.begin(); it != mExportNodesTree.end(); ++it )
        {
            SceneElement* sceneElement = *it;
            if ( sceneElement->getPath() == dagPath ) return ( sceneElement );

            // Recursive call for all the child elements
            for ( uint i=0; i<sceneElement->getChildCount(); ++i )
            {
                SceneElement* childElement = sceneElement->getChild ( i );
                if ( ( childElement = findElement ( dagPath, childElement ) ) != NULL) return childElement;
            }
        }

        return NULL;
    }

    // --------------------------------------------------------------------
    SceneElement* SceneGraph::findElement ( 
        const MDagPath& dagPath, 
        SceneElement* sceneElement )
    {
        if ( sceneElement->getPath() == dagPath ) return ( sceneElement );

        // Recursive call for all the child elements
        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            if ( ( childElement = findElement ( dagPath, childElement ) ) != NULL) return childElement;
        }

        return NULL;
    }

    // --------------------------------------------------------------------
    SceneElement* SceneGraph::findExportedElement ( const MDagPath& dagPath )
    {
        static bool output = false;
        for ( SceneElementsList::iterator it = mExportedNodes.begin(); it != mExportedNodes.end(); ++it )
        {
            if ( ( *it )->getNode() == dagPath.node() ) return ( *it );
        }

        return NULL;
    }

    // --------------------------------------------------------------------
    void SceneGraph::addExportedElement ( SceneElement* exportedElement )
    {
        mExportedNodes.push_back ( exportedElement );
    }

    // ------------------------------------------------------------
    void SceneGraph::appendForcedNodeToList ( const MDagPath& dagPath )
    {
        // Attach a function set
        MFnDependencyNode fn ( dagPath.node() );
        String theNodeName = fn.name().asChar();

        MDagPath dagPathCopy = dagPath;
        while ( dagPathCopy.length() > 0 && !isForcedNode ( dagPathCopy ) )
        {
            // Attach a function set
            MFnDependencyNode fn ( dagPathCopy.node() );
            String theNodeName = fn.name().asChar();

            mForcedNodes.append ( dagPathCopy );
            dagPathCopy.pop();
        }
    }

    // ------------------------------------------------------------
    void SceneGraph::findForcedNodes()
    {
        MStatus status;

        if ( mExportSelectedOnly )
        {
            MSelectionList selectedItems;
            MGlobal::getActiveSelectionList ( selectedItems );
            uint selectedCount = selectedItems.length();
            MDagPathArray queue;

            for ( uint i = 0; i < selectedCount; ++i )
            {
                MDagPath selectedPath;
                status = selectedItems.getDagPath ( i, selectedPath );
                if ( status == MStatus::kSuccess ) queue.append ( selectedPath );
            }

            while ( queue.length() > 0 )
            {
                MDagPath selectedPath = queue[queue.length() - 1];
                queue.remove ( queue.length() - 1 );

                // Queue up the children.
                uint childCount = selectedPath.childCount();
                for ( uint i = 0; i < childCount; ++i )
                {
                    MObject node = selectedPath.child ( i );
                    MDagPath childPath = selectedPath;
                    childPath.push ( node );
                    queue.append ( childPath );
                }

                // Look for a mesh
                if ( selectedPath.node().hasFn ( MFn::kMesh ) )
                {
                    // export forced nodes in path
                    addForcedNodes ( selectedPath );
                }
            }
        }
        else
        {
            for ( MItDag dagIt ( MItDag::kBreadthFirst ); !dagIt.isDone(); dagIt.next() )
            {
                MDagPath currentPath;
                status = dagIt.getPath ( currentPath );
                if ( status == MStatus::kSuccess )
                {
                    MFnDagNode node ( currentPath );
                    String nodeName = node.name().asChar();
                    if ( currentPath.node().hasFn ( MFn::kMesh ) )
                    {
                        // export forced nodes in path
                        addForcedNodes ( currentPath );
                    }
                }
            }
        }
    }

    // ------------------------------------------------------------
    void SceneGraph::addForcedNodes ( const MDagPath& dagPath )
    {
        MFnMesh meshFn ( dagPath );

        // Iterate upstream finding all the nodes which affect the mesh.
        MStatus stat;
        MPlug plug = meshFn.findPlug ( ATTR_IN_MESH );
        if ( plug.isConnected() )
        {
            MItDependencyGraph dependGraphIter ( plug,
                                                 MFn::kInvalid,
                                                 MItDependencyGraph::kUpstream,
                                                 MItDependencyGraph::kDepthFirst,
                                                 MItDependencyGraph::kPlugLevel,
                                                 &stat );

            if ( stat == MS::kSuccess )
            {
                dependGraphIter.disablePruningOnFilter();
                for ( ; ! dependGraphIter.isDone(); dependGraphIter.next() )
                {
                    MObject thisNode = dependGraphIter.thisNode();
                    MFn::Type type = thisNode.apiType();

                    if ( thisNode.apiType() == MFn::kSkinClusterFilter )
                    {
                        MFnSkinCluster clusterFn ( thisNode );
                        MDagPathArray jointPaths;
                        clusterFn.influenceObjects ( jointPaths, &stat );
                        if ( stat == MS::kSuccess )
                        {
                            uint count = jointPaths.length();
                            for ( uint i = 0; i < count; ++i ) appendForcedNodeToList ( jointPaths[i] );
                        }
                    }
                    else if ( thisNode.apiType() == MFn::kJointCluster )
                    {
                        MObject joint = DagHelper::getNodeConnectedTo ( thisNode, ATTR_MATRIX );
                        MDagPath jointPath = MDagPath::getAPathTo ( joint );
                        appendForcedNodeToList ( jointPath );
                    }
                }
            }
        }
    }

    // ------------------------------------------------------------
    bool SceneGraph::isForcedNode ( const MDagPath& dagPath )
    {
        uint count = mForcedNodes.length();
        for ( uint i = 0; i < count; ++i )
        {
            if ( dagPath == mForcedNodes[i] ) return true;
        }

        return false;
    }

}