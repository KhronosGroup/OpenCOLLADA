/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_SCENEGRAPHCREATOR_H__
#define __COLLADAMAX_SCENEGRAPHCREATOR_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"

#include "COLLADAFWNode.h"

#include "Math/COLLADABUMathMatrix4.h"



namespace COLLADAMax
{

	/** Creates the entire scene graph */
	class SceneGraphCreator : public ImporterBase 
	{
	private:
		/** The visual scene that should be imported.*/
		const COLLADAFW::VisualScene* mVisualScene;

	public:
		/** Constructor. */
		SceneGraphCreator(DocumentImporter* documentImporter, const COLLADAFW::VisualScene* visualScene);

		/** Destructor. */
		virtual ~SceneGraphCreator();

		/** Creates the scene graph.*/
		bool create();

	private:
		void setNodeProperties( const COLLADAFW::Node* node, ImpNode* importNode);

		/** Recursively imports @a node.*/
		ImpNode* importNode( const COLLADAFW::Node* node, INode* parentINode );

		/** Imports all nodes in  @a nodeArray and attaches them to @a parentImportNode.*/
		bool importNodes(const COLLADAFW::NodePointerArray& nodeArray, INode* parentINode);

		/** Imports all the instances in  @a instanceArray and attaches them to @a parentImportNode.*/
		template<class Instance, 
			void (SceneGraphCreator::*postProcess)( INode*, Instance* )>
			bool importInstances( const COLLADAFW::PointerArray<Instance>& instanceArray, ImpNode* parentImportNode );

		/** Imports all the instance geometries in  @a instanceGeometryArray and attaches them to @a parentImportNode.*/
		bool importInstanceGeometries( const COLLADAFW::InstanceGeometryPointerArray& instanceGeometryArray, ImpNode* parentImportNode );

		/** Imports all the instance controllers in  @a instanceControllerArray and attaches them to @a parentImportNode.*/
		bool importInstanceControllers( const COLLADAFW::InstanceControllerPointerArray& instanceControllerArray, ImpNode* parentImportNode );

		/** Imports all the instance cameras in  @a instanceGeometryArray and attaches them to @a parentImportNode.*/
		bool importInstanceCameras( const COLLADAFW::InstanceCameraPointerArray& instanceCameraArray, ImpNode* parentImportNode );

		/** Imports all the instance lights in  @a instanceGeometryArray and attaches them to @a parentImportNode.*/
		bool importInstanceLights( const COLLADAFW::InstanceLightPointerArray& instanceLightArray, ImpNode* parentImportNode );

		/** Imports the first instance of type Instance in @a node. A new INode is created, that references 
		the instantiated geometry and has the	properties of @a node (name, transformation). The new INode 
		is attached to @a parentImportNode. Use this member, if a node has exactly one instance.*/
		template<class Instance, 
			     const COLLADAFW::PointerArray<Instance>& (COLLADAFW::Node::*getInstances)()const, 
				 void (SceneGraphCreator::*postProcess)( INode*, Instance* )> 
		ImpNode* importInstance( const COLLADAFW::Node* node, INode* parentINode );

		/** Imports the first instance geometry in @a node. It is assumed that @a node has at least one
		instance geometry. A new INode is created, that references the instantiated geometry and has the
		properties of @a node (name, transformation). The new INode is attached to @a parentImportNode. 
		Use this member, if a node has exactly one instance geometry.*/
		ImpNode* importInstanceGeometry( const COLLADAFW::Node* node, INode* parentINode );

		/** Imports the first instance controller in @a node. It is assumed that @a node has at least one
		instance controller. A new INode is created, that references the instantiated controller and has the
		properties of @a node (name, transformation). The new INode is attached to @a parentImportNode. 
		Use this member, if a node has exactly one instance controller.*/
		ImpNode* importInstanceController( const COLLADAFW::Node* node, INode* parentINode );

		/** Imports the first instance camera in @a node. It is assumed that @a node has at least one
		instance camera. A new INode is created, that references the instantiated camera and has the
		properties of @a node (name, transformation). The new INode is attached to @a parentImportNode. 
		Use this member, if a node has exactly one instance camera.*/
		ImpNode* importInstanceCamera( const COLLADAFW::Node* node, INode* parentINode );

		/** Imports the first instance light in @a node. It is assumed that @a node has at least one
		instance light. A new INode is created, that references the instantiated light and has the
		properties of @a node (name, transformation). The new INode is attached to @a parentImportNode. 
		Use this member, if a node has exactly one instance light.*/
		ImpNode* importInstanceLight( const COLLADAFW::Node* node, INode* parentINode );

		/** Imports all the instance nodes in  @a instanceNodeArray and attaches them to @a parentImportNode.*/
		bool importInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodeArray, ImpNode* parentImportNode );

		/** Recursively clones @a nodeToClone and attaches the cloned graph to @a parentImportNode. The cloned
		nodes with reference the same object and transformation controller.*/
		bool recursivelyCloneINode( ImpNode* parentImportNode, INode* nodeToClone );

		/** Store the information about material bindings of @a instanceGeometry attached to max node @a node.*/
        template<COLLADAFW::ClassId classId>
		void storeMaterialBindings( INode* node, COLLADAFW::InstanceBindingBase<classId>* instanceGeometry)
        {
            COLLADAFW::MaterialBindingArray& materialBindings = instanceGeometry->getMaterialBindings();
            if ( !materialBindings.empty() )
            {
                DocumentImporter::NodeMaterialBindingsPair& materialBindingsPair = createAndAddNodeMaterialBindingsPair(node);
                size_t bindingsCount = materialBindings.getCount();
                materialBindingsPair.materialBindings.reserve(bindingsCount);
                for ( size_t i = 0; i < bindingsCount; ++i)
                    materialBindingsPair.materialBindings.push_back(materialBindings[i]);
            }
        }

		/** Store the information about material bindings of @a instanceController attached to max node @a node. */
		void postProcessInstanceController( INode* node, COLLADAFW::InstanceController* instanceController );


	private:

		/** Disable default copy ctor. */
		SceneGraphCreator( const SceneGraphCreator& pre );

		/** Disable default assignment operator. */
		const SceneGraphCreator& operator= ( const SceneGraphCreator& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_SCENEGRAPHCREATOR_H__
