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

#ifndef __COLLADA_MAYA_NODE_TRAVERSER_H__
#define __COLLADA_MAYA_NODE_TRAVERSER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaSceneNodeTraverser.h"

#include "COLLADANodeTraverser.h"

namespace COLLADAMaya
{

    /** Declares the listener implementation of the TraverserListener */
    class SceneTraverserListener : public COLLADA::NodeTraverser::TraverserListener
    {

    private:

        /** Pointer to the node traverser. */
        SceneNodeTraverser* mTraverser;

    public:

        /** Constructor. */
        SceneTraverserListener ( SceneNodeTraverser* traverser ) : mTraverser ( traverser ) {}

        /** Destructor. */
        virtual ~SceneTraverserListener () {}

        /** Callback method when a node is found.
        @par see COLLADA::NodeTraverseListener::preDetectedNode(domNode&, int&);
        @param node. The found node.
        @param level. The depth in the tree.
        @return true if traversing is to be continued, otherwise false.
        @todo: transformations!!!
        */
        virtual bool preDetectedNode( domNode& node, int level );

        /** Callback method when a node is found and all its sub elements
        were detected.
        @par see COLLADA::NodeTraverseListener::postDetectedNode(domNode&, int&);
        @param node. The found node.
        @param level. The depth in the tree.
        @return true if traversing is to be continued, otherwise false.
        */
        virtual bool postDetectedNode( domNode& node, int level );

        /** Callback method when an instance_node is found.
        @param instance. The found node.
        @param level. The depth in the tree.
        @return true if traversing is to be continued, otherwise false.
        */
        virtual bool detectedInstanceNode(domInstance_node& instance, int level);

        /** Callback method when an instance_node is found.
        @par see COLLADA::NodeTraverseListener::domInstance_geometry(domNode&, int&);
        @param node. The found node.
        @param level. The depth in the tree.
        @return true if traversing is to be continued, otherwise false.
        @todo: for uniqueEntityId: getScopeId for parent hierarchy of node(s)
        */
        virtual bool detectedInstanceGeometry( domInstance_geometry& instance, int level );

        /** Callback method when an instance_light is found.
        empty implementation.
        */
        virtual bool detectedInstanceLight( domInstance_light& instance, int level );

        /** Callback method when an instance_camera is found.
        empty implementation.
        */
        virtual bool detectedInstanceCamera( domInstance_camera& instance, int level );

        /** Callback method when an extra within a node is found.
        @param extra. The found extra.
        @param level. The depth in the tree.
        @return true if traversing is to be continued, otherwise false.
        */
        virtual bool detectedNodeExtra(domExtra& extra, int level);
    };
}

#endif // __COLLADA_MAYA_NODE_TRAVERSER_H__