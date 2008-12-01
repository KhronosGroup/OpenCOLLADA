/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_VISUALSCENELOADER_H__
#define __COLLADA_VISUALSCENELOADER_H__

#include "COLLADADHStableHeaders.h"
#include "COLLADADHNodeTraverser.h"
#include "COLLADADHBaseLoader.h"

#include <stack>


class domVisual_scene;

namespace COLLADAFW
{
	class VisualScene;
	class Node;
}

namespace COLLADADH
{
	class Loader;

	/** This class takes a COLALDA dom visual scene and builds a frame work visual scene out of it.*/
	class VisualSceneLoader : BaseLoader, COLLADADH::NodeTraverser::TraverserListener
	{
	private:
		/** Stack of nodes.*/
		typedef std::stack<COLLADAFW::Node*> NodeStack;

	private:
		/** The collada loader */
		Loader* mColladaLoader;

		/** Pointer to the visual scene this loader creates.*/
		COLLADAFW::VisualScene* mVisualScene;

		/** Stack of nodes to traverse back in node hierarchy. Array and contents will be delete in destructor.*/
		NodeStack mNodeStack;
	
	public:
		VisualSceneLoader(Loader* colladaLoader, domCOLLADA* colladaRoot);
		virtual ~VisualSceneLoader();

		/** Loads the collada dom visual scene and creates a frame work visual scene.
		@return A pointer to the created visual scene.*/
		COLLADAFW::VisualScene* load();


		/** Callback method when an instance_camera is found.
		@param instance. The found camera.
		@param level. The depth in the tree.
		@return true if traversing is to be continued, otherwise false.
		*/
		virtual bool detectedInstanceCamera(domInstance_camera& instance, int level) { return true; }

		/** Callback method when an instance_controller is found.
		@param instance. The found controller.
		@param level. The depth in the tree.
		@return true if traversing is to be continued, otherwise false.
		*/
		virtual bool detectedInstanceController(domInstance_controller& instance, int level) {return true;}

		/** Callback method when an instance_geometry is found.
		@param instance. The found geometry.
		@param level. The depth in the tree.
		@return true if traversing is to be continued, otherwise false.
		*/
		virtual bool detectedInstanceGeometry(domInstance_geometry& instance, int level);

		/** Callback method when an instance_light is found.
		@param instance. The found light.
		@param level. The depth in the tree.
		@return true if traversing is to be continued, otherwise false.
		*/
		virtual bool detectedInstanceLight(domInstance_light& instance, int level){return true;}

		/** Callback method when an instance_node is found.
		@param instance. The found node.
		@param level. The depth in the tree.
		@return true if traversing is to be continued, otherwise false.
		*/
		virtual bool detectedInstanceNode(domInstance_node& instance, int level) {return true;}

		/** Callback method when a node is found.
		@param node. The found node.
		@param level. The depth in the tree.
		@return true if traversing is to be continued, otherwise false.
		*/
		virtual bool preDetectedNode(domNode& node, int level);

		/** Callback method when a node is found and all its sub elements
		were detected.
		@param node. The found node.
		@param level. The depth in the tree.
		@return true if traversing is to be continued, otherwise false.
		*/
		virtual bool postDetectedNode(domNode& node, int level);

		/** Callback method when an extra within a node is found.
		@param extra. The found extra.
		@param level. The depth in the tree.
		@return true if traversing is to be continued, otherwise false.
		*/
		virtual bool detectedNodeExtra(domExtra& extra, int level){return true;}


	private:
        /** Disable default copy ctor. */
		VisualSceneLoader( const VisualSceneLoader& pre );
        /** Disable default assignment operator. */
		const VisualSceneLoader& operator= ( const VisualSceneLoader& pre );

	};
	
} // namespace COLLADA

#endif // __COLLADA_VISUALSCENELOADER_H__
