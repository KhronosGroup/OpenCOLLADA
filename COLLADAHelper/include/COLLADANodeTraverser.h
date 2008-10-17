#ifndef __COLLADA_NODETRAVERSER_H__
#define __COLLADA_NODETRAVERSER_H__

#include <dom/domNode.h>
#include <dom/domInstance_node.h>
#include <dom/domInstance_geometry.h>
#include <dom/domInstance_light.h>
#include <dom/domInstance_camera.h>
#include <dom/domExtra.h>
#include <dom/domCOLLADA.h>

namespace COLLADA
{
	/** This class traverses over a node hierarchy of the given Element. 
	The detection of a node element is signaled through a listener interface.
	*/
	class NodeTraverser
	{
	public:
		class TraverserListenerData
		{
		};

		/** Interface for a listener. 
		*/
		class TraverserListener
		{
		public:
        
            /** virtual destructor to avoid warnings*/
            virtual ~TraverserListener(){};
            
			/** Callback method when an instance_camera is found.
			@param instance. The found camera.
			@param level. The depth in the tree.
			@return true if traversing is to be continued, otherwise false.
			*/
			virtual bool detectedInstanceCamera(domInstance_camera& instance, int level) = 0;

			/** Callback method when an instance_controller is found.
			@param instance. The found controller.
			@param level. The depth in the tree.
			@return true if traversing is to be continued, otherwise false.
			*/
			virtual bool detectedInstanceController(domInstance_controller& instance, int level) {return true;};

			/** Callback method when an instance_geometry is found.
			@param instance. The found geometry.
			@param level. The depth in the tree.
			@return true if traversing is to be continued, otherwise false.
			*/
			virtual bool detectedInstanceGeometry(domInstance_geometry& instance, int level) = 0;

			/** Callback method when an instance_light is found.
			@param instance. The found light.
			@param level. The depth in the tree.
			@return true if traversing is to be continued, otherwise false.
			*/
			virtual bool detectedInstanceLight(domInstance_light& instance, int level) = 0;

			/** Callback method when an instance_node is found.
			@param instance. The found node.
			@param level. The depth in the tree.
			@return true if traversing is to be continued, otherwise false.
			*/
			virtual bool detectedInstanceNode(domInstance_node& instance, int level) = 0;

			/** Callback method when a node is found.
			 @param node. The found node.
			 @param level. The depth in the tree.
			 @return true if traversing is to be continued, otherwise false.
			*/
			virtual bool preDetectedNode(domNode& node, int level) = 0;

			/** Callback method when a node is found and all its sub elements
			were detected.
			 @param node. The found node.
			 @param level. The depth in the tree.
			 @return true if traversing is to be continued, otherwise false.
			*/
			virtual bool postDetectedNode(domNode& node, int level) = 0;

			/** Callback method when an extra within a node is found.
			@param extra. The found extra.
			@param level. The depth in the tree.
			@return true if traversing is to be continued, otherwise false.
			*/
			virtual bool detectedNodeExtra(domExtra& extra, int level) = 0;
		};

	public:
		/** Constructor.
		 @param nodeContainer. A element which contains nodes.
		*/
		NodeTraverser(daeElement &nodeContainer);

		/// Destructor.
		virtual ~NodeTraverser();

		/** Starts the traversing.
		 @param listener.
		 @param level. Start level.
		 @return true if traversing was successful, otherwise false.
		*/
		virtual bool traverse(TraverserListener &listener, int level = -1);

        virtual daeElement* getNodeContainer()const {return &mNodeContainer;}

		void setOnlyThisLevel(bool onlyThisLevel);

	protected:
        /** Traverses a scene.
        @param scene. Scene element.
        @param level. Depth of the tree.
        @param listener. The listener with callback methods.
        @return true if all sub elements are detected, otherwise false.
        */
        virtual bool traverseScene(domCOLLADA::domScene &scene, int level, TraverserListener &listener);

		/** Traverses all nodes under a viusal scene.
		 @param vs. Visual scene element.
		 @param level. Depth of the tree.
		 @param listener. The listener with callback methods.
		 @return true if all sub elements are detected, otherwise false.
		*/
		virtual bool traverseVisualScene(domVisual_scene &vs, int level, TraverserListener &listener);
		
		/** Traverses all nodes under a node.
		 @param node. Node element.
		 @param level. Depth of the tree.
		 @param listener. The listener with callback methods.
		 @return true if all sub elements are detected, otherwise false.
		*/
		virtual bool traverseNode(domNode &node, int level, TraverserListener &listener);

		/** Traverses all nodes under a Library node.
		 @param libNodes. Librarynodes element.
		 @param level. Depth of the tree.
		 @param listener. The listener with callback methods.
		 @return true if all sub elements are detected, otherwise false.
		*/
		virtual bool traverseLibraryNodes(domLibrary_nodes &libNodes, int level, TraverserListener &listener);

	private:
		daeElement &mNodeContainer;

		bool mOnlyThisLevel;
	
	};
};

#endif// __COLLADA_NODETRAVERSER_H__
