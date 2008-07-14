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

#ifndef __COLLADA_MAYA_SCENE_GRAPH_H__
#define __COLLADA_MAYA_SCENE_GRAPH_H__

#include "COLLADAMayaVisualSceneExporter.h"

#include <maya/MSelectionList.h>

class MFnPlugin;

class DaeDoc;

class SceneElement;

class DocumentExporter;

class VisualSceneExporter;

namespace COLLADAMaya
{

    /**
     * Creates the scene graph of the current scene.
     */

    class SceneGraph
    {

    public:

        /** The ID of the current scene. It always exist just one scene! */
        static const String SCENE_ID;

    private:

        /** false if all data should be exported, true if export just the selected elements */
        bool mExportSelectedOnly;

        /** A list with all nodes which are already exported */
        SceneElementsList mExportedNodes;

        /** A list with all mesh nodes of type kJointCluster or kSkinClusterFilter, which have to be exported */
        MDagPathArray mForcedNodes;

        /** A list with all dag paths which have to be exported */
        MSelectionList mTargets;

        /** The tree of all node elements in the scene */
        SceneElementsList mExportNodesTree;

        /** A pointer to the document exporter. It coordinates the export. */
        DocumentExporter* mDocumentExporter;

    public:
        /**
         * SceneGraph Constructor
         * @param documentExporter Pointer to the main document exporter.
         */
        SceneGraph ( DocumentExporter* documentExporter );

        /**
         * ~SceneGraph Destructor
         */
        virtual ~SceneGraph();

        /**
         * Returns list with the root nodes to export, which represents the scene graph.
         * @return SceneElementsList* The list with the root nodes
         */
        SceneElementsList* getExportNodesTree()
        {
            return &mExportNodesTree;
        }

        /**
         * Returns the list with all dag paths which have to be exported.
         * @return MSelectionList* Maya selection list with the selected elements.
         */
        MSelectionList* getTargets()
        {
            return &mTargets;
        }

        /**
         * Create the scene graph and list the forced nodes. Done during the AnimCache pass.
         * @param selectionOnly Flag, if just the selected elements should be exported.
         * @return bool True, if the creation was sucessfull.
         */
        bool create ( bool selectionOnly );

        /**
         * Push all nodes from root down to all meshes which have to be exported in a list.
         */
        void findForcedNodes();

        /**
         * Appends the node of the current path to a list.
         * @param dagPath Path to the forced node.
         */
        void appendForcedNodeToList ( const MDagPath& dagPath );

        /**
         * Add all the nodes which affect the mesh and have to be exported in a special way.
         * This nodes are meshes from type MFn::kSkinClusterFilter or MFn::kJointCluster.
         * @param dagPath The Path to the affected mesh.
         */
        void addForcedNodes ( const MDagPath& dagPath );
        bool isForcedNode ( const MDagPath& dagPath );

        // Look-ups
        SceneElement* findElement ( const MDagPath& dagPath );

        /** Adds this element to the list of exported elements */
        void addElement ( SceneElement* entity );

        /** Checks if the node should be exported */
        bool isExportNode ( const MDagPath& dagPath,
                            bool& isForced,
                            bool& isVisible );

    private:

        /** Iterate recursive though the DAG nodes and build the scene graph tree. */
        bool createChildSceneElements ( SceneElement* sceneElement, bool isTransform = false );

        /** Fills the list with all targets to export. */
        bool retrieveExportNodes();

        /** Creates a new scene element and sets the required flags */
        SceneElement* createSceneElement ( const MDagPath &dagPath, SceneElement* parentSceneElement=NULL );

        /** Clears the forced nodes. */
        void endExport();

        /**
         * Remove any DAG nodes which are multiply included in the selection list.
         * (e.g. |transform1|shape1 is already included in |transform1)
         * @param selectionList The list with the selected elements.
         * @return MStatus Status, if the operation was successful.
         */
        MStatus removeMultiplyIncludedDagPaths ( MSelectionList& selectionList );

        /**
         * Add additional dag paths for any instanced objects within our selection set
         * as by default, the selection list only includes one of the dag paths.
         * @param selectionList The list with the selected elements.
         * @return MStatus Status, if the operation was successful.
         */
        MStatus addInstancedDagPaths ( MSelectionList& selectionList );

    };
}

#endif // __COLLADA_MAYA_SCENE_GRAPH_H__
