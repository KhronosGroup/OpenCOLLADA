/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADANode.h"
#include "COLLADAInstanceGeometry.h"
#include "COLLADABindMaterial.h"

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
#include "ColladaMayaPlatform.h"
#include "assert.h"


namespace COLLADAMaya
{

    const String SceneGraph::SCENE_ID = "MayaScene";


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
        // Add all the expressions
        MObjectArray expressions;
        MItDependencyNodes depIter ( MFn::kExpression );

        for ( ; !depIter.isDone(); depIter.next() )
        {
            MObject item = depIter.item();

            if ( item.hasFn ( MFn::kExpression ) )
            {
                expressions.append ( item );
            }
        }

        // Create a selection list containing only the root nodes (implies export all!)
        MSelectionList allTargets;

        for ( MItDag it ( MItDag::kBreadthFirst ); it.depth() <= 1 && it.item() != MObject::kNullObj; it.next() )
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
                MGlobal::displayError ( "MGlobal::getActiveSelectionList" );
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
        MObjectArray expressions;
        MItDependencyNodes depIter ( MFn::kExpression );

        for ( ; !depIter.isDone(); depIter.next() )
        {
            MObject item = depIter.item();

            if ( item.hasFn ( MFn::kExpression ) )
            {
                expressions.append ( item );
            }
        }

        // Start by caching the expressions that will be sampled
        uint expressionCount = expressions.length();

        for ( uint i = 0; i < expressionCount; ++i )
        {
            // expressions only for sampling
            mDocumentExporter->getAnimationCache()->sampleExpression ( expressions[i] );
        }

        // Push all nodes from root down to all meshes which have to be exported in a list.
        findForcedNodes();

        // Fills the list with all root targets to export.
        bool success = retrieveExportNodes();

        // Create a selection list containing only the root nodes (implies export all!)
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

            // Create the child elemements.
            createChildSceneElements ( sceneElement, true );
        }

        return true;
    }

    // ------------------------------------------------------------
    SceneElement* SceneGraph::createSceneElement ( const MDagPath &dagPath,
            SceneElement* parentSceneElement )
    {
        // Create a new scene element
        SceneElement* sceneElement = new SceneElement ( dagPath );

        // Attach a function set
        MFnDependencyNode fn ( dagPath.node() );

        // Get the node name
        String nodeName = fn.name().asChar();
        sceneElement->setNodeName ( fn.name().asChar() );

        // Check if it's a node to export and
        // tell the scene node to be transformed or not.
        bool isForced = false;
        bool isVisible = false;
        bool exportNode = isExportNode ( dagPath, isForced, isVisible );
        sceneElement->setIsExportNode ( exportNode );
        sceneElement->setIsForced ( isForced );
        sceneElement->setIsVisible ( isVisible );

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
    bool SceneGraph::createChildSceneElements ( SceneElement* sceneElement, bool isRootTransformNode )
    {
        // Check if it is a root node. If so, push it in the tree.
        if ( isRootTransformNode ) mExportNodesTree.push_back ( sceneElement );

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
    bool SceneGraph::isExportNode ( const MDagPath& dagPath,
                                    bool& isForced,
                                    bool& isVisible )
    {
        // Does this dagPath already exist? If so, only recurse if FollowInstancedChildren() is set.
        MFnDagNode dagFn ( dagPath );
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

        if ( !isForced )
        {
            // Check for visibility
            if ( !ExportOptions::exportInvisibleNodes() && !isVisible )
            {
                AnimationSampleCache* animationCache = mDocumentExporter->getAnimationCache();

                if ( !AnimationHelper::isAnimated ( animationCache, dagPath.node(), ATTR_VISIBILITY ) )
                {
                    return false;
                }
            }

            else if ( !isVisible && !ExportOptions::exportDefaultCameras() )
            {
                // Check for the default camera transform names.
                if ( nodeName == CAMERA_PERSP ||
                        nodeName == CAMERA_TOP ||
                        nodeName == CAMERA_SIDE ||
                        nodeName == CAMERA_FRONT )
                    return false;
            }
        }

        isForced &= !isVisible;

        if ( !isForced )
        {
            // We don't want to process manipulators
            if ( dagPath.hasFn ( MFn::kManipulator ) || dagPath.hasFn ( MFn::kViewManip ) ) return false;

            // Check for constraints which are not exported
            if ( !ExportOptions::ExportConstraints() && dagPath.hasFn ( MFn::kConstraint ) ) return false;

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

                uint dagJdepth = dagJPath.length();

                // Test if the longer of these two dag paths contains the shorter ...
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

        if ( output ) MGlobal::displayInfo ( MString ( "Comparing against: " ) + dagPath.fullPathName() );

        for ( SceneElementsList::iterator it = mExportedNodes.begin(); it != mExportedNodes.end(); ++it )
        {
            if ( output ) MGlobal::displayInfo ( MString ( "Local value: " ) + MFnDependencyNode ( ( *it )->getNode() ).name() );

            if ( ( *it )->getNode() == dagPath.node() ) return ( *it );
        }

        return NULL;
    }

    // --------------------------------------------------------------------
    void SceneGraph::addElement ( SceneElement* exportedElement )
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