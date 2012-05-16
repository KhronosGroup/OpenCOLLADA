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

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxSceneGraphCreator.h"

#include "COLLADAFWVisualScene.h"

#include "dummy.h"

namespace COLLADAMax
{

	SceneGraphCreator::SceneGraphCreator( DocumentImporter* documentImporter, const COLLADAFW::VisualScene* visualScene )
		: ImporterBase(documentImporter)
		, mVisualScene( visualScene )
	{}

	//------------------------------
	SceneGraphCreator::~SceneGraphCreator()
	{
	}

	//------------------------------
	void SceneGraphCreator::setNodeProperties( const COLLADAFW::Node* node, ImpNode* importNode)
	{
		const String& newNodeName = node->getName();
		if ( !newNodeName.empty() )
			importNode->SetName(newNodeName.c_str());

		// set transform. we always do this. If there is an animation, the controller will be changed
		COLLADABU::Math::Matrix4 transformationMatrix;
		node->getTransformationMatrix(transformationMatrix);
		Matrix3 maxTransformationMatrix;
		Matrix4ToMaxMatrix3(maxTransformationMatrix, transformationMatrix);
		importNode->SetTransform(0, maxTransformationMatrix);
	}

	//------------------------------
	bool SceneGraphCreator::create()
	{
		if ( !mVisualScene )
			return false;

		INode* rootNode = getMaxInterface()->GetRootNode();
		importNodes(mVisualScene->getRootNodes(), rootNode);

		return true;
	}

	//------------------------------
	ImpNode* SceneGraphCreator::importNode( const COLLADAFW::Node* node, INode* parentINode )
	{
		bool singleInstance = (node->getInstanceGeometries().getCount() +
							   node->getInstanceControllers().getCount() +
			                   node->getInstanceCameras().getCount() +
							   node->getInstanceLights().getCount() ) == 1;
		ImpNode* newImportNode = 0;
		const COLLADAFW::UniqueId& nodeUniqueId = node->getUniqueId();

		if ( !singleInstance )
		{
			newImportNode = getMaxImportInterface()->CreateNode();

			setNodeProperties(node, newImportNode);
			getMaxImportInterface()->AddNodeToScene(newImportNode);

			RefResult res = newImportNode->Reference(getDummyObject());
			if ( node->getType() == COLLADAFW::Node::JOINT )
			{
				newImportNode->GetINode()->ShowBone(1);
			}

			importInstanceGeometries(node->getInstanceGeometries(), newImportNode);
			importInstanceControllers(node->getInstanceControllers(), newImportNode);
			importInstanceCameras(node->getInstanceCameras(), newImportNode);
			importInstanceLights(node->getInstanceLights(), newImportNode);
		}
		else
		{
			newImportNode = importInstanceGeometry( node, parentINode );

			if ( !newImportNode )
				newImportNode = importInstanceController( node, parentINode );

			if ( !newImportNode )
				newImportNode = importInstanceCamera( node, parentINode );

			if ( !newImportNode )
				newImportNode = importInstanceLight( node, parentINode );

			assert(newImportNode);
		}

		INode* childNode = newImportNode->GetINode();
		importNodes(node->getChildNodes(), childNode);

		// Append all nodes that are referenced by this node.
		importInstanceNodes(node->getInstanceNodes(), newImportNode);

		/** Store the unique id of the created node, to resolve references, when ever necessary.*/ 
		addUniqueIdINodePair( nodeUniqueId, newImportNode->GetINode());

		parentINode->AttachChild(childNode, FALSE);

#if 0
		/* if there are nodes that reference the just created node, clone this node
		and append it to the referencing node.*/
		ImpNode* referencingImpNode = 0;
		while ( referencingImpNode = getReferencingImpNodesByUniqueId(nodeUniqueId) )
		{
			removeUniqueIdReferencingImpNodePair( nodeUniqueId, referencingImpNode);
			recursivelyCloneINode( referencingImpNode, newImportNode->GetINode() );
		}
#endif
		return newImportNode;
	}

	//------------------------------
	bool SceneGraphCreator::importNodes( const COLLADAFW::NodePointerArray& nodeArray, INode* parentINode )
	{
		for ( size_t i = 0, count = nodeArray.getCount(); i < count; ++i)
		{
			ImpNode* newNode = importNode(nodeArray[i], parentINode);
		}

		return true;
	}

	//------------------------------
	template<class Instance, 
		void (SceneGraphCreator::*postProcess)( INode*, Instance* )>
		bool SceneGraphCreator::importInstances( const COLLADAFW::PointerArray<Instance>& instanceArray, ImpNode* parentImportNode )
	{
		for ( size_t i = 0, count = instanceArray.getCount(); i < count; ++i)
		{
			Instance* instance = instanceArray[i];

			ImpNode* newImportNode = getMaxImportInterface()->CreateNode();
			INode* newNode = newImportNode->GetINode();
			const COLLADAFW::UniqueId& uniqueId = instance->getInstanciatedObjectId();

			Object* object = getObjectByUniqueId(uniqueId);
			if ( object )
			{
				newImportNode->Reference(object);
			}
			else
			{
				newImportNode->Reference( getDummyObject() );
			}
			const COLLADAFW::UniqueId& instanceUniqueId = instance->getInstanciatedObjectId();
			// Store mapping between unique ids and nodes referencing the corresponding object.
			// Used to clone nodes
			addObjectINodeUniqueIdPair(newNode, instanceUniqueId);
			// Used to resolve instancing of objects
			addUniqueIdObjectINodePair(instanceUniqueId, newNode);

			INode* parentNode = parentImportNode->GetINode();
			parentNode->AttachChild(newNode, FALSE);

			// post process the creation
			if ( postProcess )
				(this->*postProcess)(newNode, instance);
		}

		return true;
	}


	//------------------------------
	bool SceneGraphCreator::importInstanceGeometries( const COLLADAFW::InstanceGeometryPointerArray& instanceGeometryArray, ImpNode* parentImportNode )
	{
		return importInstances<COLLADAFW::InstanceGeometry, &SceneGraphCreator::storeMaterialBindings<COLLADAFW::COLLADA_TYPE::INSTANCE_GEOMETRY> >(instanceGeometryArray, parentImportNode);
	}

	//------------------------------
	bool SceneGraphCreator::importInstanceControllers( const COLLADAFW::InstanceControllerPointerArray& instanceControllerArray, ImpNode* parentImportNode )
	{
		return importInstances<COLLADAFW::InstanceController, &SceneGraphCreator::postProcessInstanceController>(instanceControllerArray, parentImportNode);
	}

	//------------------------------
	bool SceneGraphCreator::importInstanceCameras( const COLLADAFW::InstanceCameraPointerArray& instanceCameraArray, ImpNode* parentImportNode )
	{
		return importInstances<COLLADAFW::InstanceCamera, 0>(instanceCameraArray, parentImportNode);
	}

	//------------------------------
	bool SceneGraphCreator::importInstanceLights( const COLLADAFW::InstanceLightPointerArray& instanceLightArray, ImpNode* parentImportNode )
	{
		return importInstances<COLLADAFW::InstanceLight, 0>(instanceLightArray, parentImportNode);
	}

	//------------------------------
	template<class Instance, 
		     const COLLADAFW::PointerArray<Instance>& (COLLADAFW::Node::*getInstances)()const, 
			 void (SceneGraphCreator::*postProcess)( INode*, Instance* )> 
	ImpNode* SceneGraphCreator::importInstance( const COLLADAFW::Node* node, INode* parentINode )
	{
		const COLLADAFW::PointerArray<Instance>& instances = (node->*getInstances)();
		if ( instances.getCount() != 1 )
			return 0;

		ImpNode* newImportNode = getMaxImportInterface()->CreateNode();
		setNodeProperties(node, newImportNode);
		INode* newNode = newImportNode->GetINode();

		Instance* instance = instances[0];
		const COLLADAFW::UniqueId& uniqueId = instance->getInstanciatedObjectId();

		Object* object = getObjectByUniqueId(uniqueId);
		if ( object )
		{
			newImportNode->Reference(object);
			const String& objectName = getObjectNameByObject(object);

			if ( node->getName().empty() && !objectName.empty() )
				newImportNode->SetName( objectName.c_str() );
		}
		else
		{
			newImportNode->Reference( getDummyObject() );
		}

		const COLLADAFW::UniqueId& instanceGeometryUniqueId = instance->getInstanciatedObjectId();
		// Store mapping between unique ids and nodes referencing the corresponding object.
		// Used to clone nodes
		addObjectINodeUniqueIdPair(newNode, instanceGeometryUniqueId);
		// Used to resolve instancing of objects
		addUniqueIdObjectINodePair(instanceGeometryUniqueId, newNode);
		parentINode->AttachChild(newNode, FALSE);

		// post process the creation
		if ( postProcess )
			(this->*postProcess)(newNode, instance);

		return newImportNode;
	}

	//------------------------------
	ImpNode* SceneGraphCreator::importInstanceGeometry( const COLLADAFW::Node* node, INode* parentINode )
	{
		return importInstance<COLLADAFW::InstanceGeometry, &COLLADAFW::Node::getInstanceGeometries, &SceneGraphCreator::storeMaterialBindings<COLLADAFW::COLLADA_TYPE::INSTANCE_GEOMETRY> >(node, parentINode);
	}

	//------------------------------
	ImpNode* SceneGraphCreator::importInstanceController( const COLLADAFW::Node* node, INode* parentINode )
	{
		return importInstance<COLLADAFW::InstanceController, &COLLADAFW::Node::getInstanceControllers, &SceneGraphCreator::postProcessInstanceController>(node, parentINode);
	}

	//------------------------------
	ImpNode* SceneGraphCreator::importInstanceCamera( const COLLADAFW::Node* node, INode* parentINode )
	{
		return importInstance<COLLADAFW::InstanceCamera, &COLLADAFW::Node::getInstanceCameras, 0>(node, parentINode);
	}

	//------------------------------
	ImpNode* SceneGraphCreator::importInstanceLight( const COLLADAFW::Node* node, INode* parentINode )
	{
		return importInstance<COLLADAFW::InstanceLight, &COLLADAFW::Node::getInstanceLights, 0>(node, parentINode);
	}

	//------------------------------
	bool SceneGraphCreator::importInstanceNodes( const COLLADAFW::InstanceNodePointerArray& instanceNodeArray, ImpNode* parentImportNode )
	{
		for ( size_t i = 0, count = instanceNodeArray.getCount(); i < count; ++i)
		{
			COLLADAFW::InstanceNode* instanceNode = instanceNodeArray[i];

			const COLLADAFW::UniqueId& uniqueId = instanceNode->getInstanciatedObjectId();

			INode* instanciatedINode = getINodeByUniqueId(uniqueId);
			// check if the referenced node is already in the max scene graph
			if ( instanciatedINode )
			{
				if ( !recursivelyCloneINode(parentImportNode, instanciatedINode) )
					return false;;
			}
			else
			{
				const COLLADAFW::Node* instanciatedFWNode = getFWNodeByUniqueId( uniqueId );
				// check if the referenced node is in one of the already received library nodes
				if ( instanciatedFWNode )
				{
					importNode( instanciatedFWNode, parentImportNode->GetINode() );
				}
#if 0
				else
				{
					// If the referenced node has not been imported, store which node is referenced
					// to clone the nodes as the referenced nodes gets imported
					addUniqueIdReferencingImpNodePair(instanceNode->getInstanciatedObjectId(), parentImportNode );
				}
#endif
			}
		}

		return true;
	}

	//------------------------------
	bool SceneGraphCreator::recursivelyCloneINode( ImpNode* parentImportNode, INode* nodeToClone )
	{
		ImpNode* newImportNode = getMaxImportInterface()->CreateNode();
		getMaxImportInterface()->AddNodeToScene(newImportNode);

		INode* newNode = newImportNode->GetINode();

		Object* object = nodeToClone->GetObjectRef();
		newImportNode->Reference(object);
		newNode->SetTMController(nodeToClone->GetTMController());
		newImportNode->SetName(nodeToClone->GetName());
		//used to assign material
		addClonedINodeOriginalINodePair(newNode, nodeToClone);

		INode* parentNode = parentImportNode->GetINode();
		parentNode->AttachChild(newNode, TRUE);

		/* If the node to clone references an object, the cloned one must references the same object.*/
		COLLADAFW::UniqueId id = getUniqueIdByObjectINode(nodeToClone);
		if ( id.isValid() )
		{
			addUniqueIdObjectINodePair(id, newNode);
			addObjectINodeUniqueIdPair(newNode, id);
		}

		// Clone the children 
		for ( int i = 0, count = nodeToClone->NumberOfChildren(); i < count; ++i)
			recursivelyCloneINode(newImportNode, nodeToClone->GetChildNode(i));

		return true;
	}

	//------------------------------
	void SceneGraphCreator::postProcessInstanceController( INode* node, COLLADAFW::InstanceController* instanceController )
	{
		storeMaterialBindings<COLLADAFW::COLLADA_TYPE::INSTANCE_CONTROLLER>( node, instanceController );

		const COLLADAFW::UniqueId& controllerUniqueId = instanceController->getInstanciatedObjectId();

		const COLLADAFW::SkinController* skinController = getSkinControllerByUniqueId( controllerUniqueId );

		if ( skinController )
		{
			const COLLADAFW::UniqueId& skinSource = skinController->getSource();
			if ( skinSource.getClassId() == COLLADAFW::MorphController::ID() )
			{
				addMorphControllerINodePair( skinSource, node);
			}
		}

	}


} // namespace COLLADAMax
