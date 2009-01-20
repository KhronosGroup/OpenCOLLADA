/*
Copyright (c) 2008 NetAllied Systems GmbH

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
#include "COLLADAMaxVisualSceneImporter.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWInstanceGeometry.h"

#include "Math/COLLADABUMathMatrix4.h"

#include <max.h>


namespace COLLADAMax
{


	VisualSceneImporter::VisualSceneImporter( DocumentImporter* documentImporter, const COLLADAFW::VisualScene* visualScene )
		:	ImporterBase(documentImporter),
			mVisualScene(visualScene)
	{}

    //------------------------------
	VisualSceneImporter::~VisualSceneImporter()
	{
	}


	//---------------------------------------------------------------
	void VisualSceneImporter::Matrix4ToMaxMatrix3 ( Matrix3 & copy,  const COLLADABU::Math::Matrix4& original )
	{
		Point4 column;
		column[ 0 ] = (float)original.getElement(0,0);
		column[ 1 ] = (float)original.getElement(0,1);
		column[ 2 ] = (float)original.getElement(0,2);
		column[ 3 ] = (float)original.getElement(0,3);
		copy.SetColumn(0, column);

		column[ 0 ] = (float)original.getElement(1,0);
		column[ 1 ] = (float)original.getElement(1,1);
		column[ 2 ] = (float)original.getElement(1,2);
		column[ 3 ] = (float)original.getElement(1,3);
		copy.SetColumn(1, column);

		column[ 0 ] = (float)original.getElement(2,0);
		column[ 1 ] = (float)original.getElement(2,1);
		column[ 2 ] = (float)original.getElement(2,2);
		column[ 3 ] = (float)original.getElement(2,3);
		copy.SetColumn(2, column);
	}

	//------------------------------
	bool VisualSceneImporter::import()
	{
		if ( !mVisualScene )
			return false;


		mDummyObject = (DummyObject*) getMaxImportInterface()->Create(HELPER_CLASS_ID, Class_ID(DUMMY_CLASS_ID, 0));



		// make a new node for each visual scene (it might happen, that we receive more than one)
		// we remove unused visual scenes at the end of the import
		ImpNode* visualSceneRootNode = getMaxImportInterface()->CreateNode();
		getMaxImportInterface()->AddNodeToScene(visualSceneRootNode);
		RefResult res = visualSceneRootNode->Reference(mDummyObject);
		
		String visualScenenName = mVisualScene->getName();
		if ( !visualScenenName.empty() )
			visualSceneRootNode->SetName(visualScenenName.c_str());

		importNodes(mVisualScene->getRootNodes(), visualSceneRootNode);

		return true;
	}

	//------------------------------
	void VisualSceneImporter::setNodeProperties( const COLLADAFW::Node* node, ImpNode* importNode)
	{
		String newNodeName = node->getName();
		if ( !newNodeName.empty() )
			importNode->SetName(newNodeName.c_str());

		// set transform
		COLLADABU::Math::Matrix4 transformationMatrix;
		node->getTransformationMatrix(transformationMatrix);
		Matrix3 maxTransformationMatrix;
		Matrix4ToMaxMatrix3(maxTransformationMatrix, transformationMatrix);
		importNode->SetTransform(0, maxTransformationMatrix);

	}

	//------------------------------
	ImpNode* VisualSceneImporter::importNode( COLLADAFW::Node* node, ImpNode* parentImportNode )
	{
		bool singleGeometryInstance = node->getInstanceGeometries().getCount() == 1;
		ImpNode* newImportNode = 0;

		if ( !singleGeometryInstance )
		{
			newImportNode = getMaxImportInterface()->CreateNode();

			setNodeProperties(node, newImportNode);
			getMaxImportInterface()->AddNodeToScene(newImportNode);

			RefResult res = newImportNode->Reference(mDummyObject);

			importInstanceGeometries(node->getInstanceGeometries(), newImportNode);
			importNodes(node->getChildNodes(), newImportNode);
		}
		else
		{
			newImportNode = importInstanceGeometrie( node, parentImportNode );
			importNodes(node->getChildNodes(), parentImportNode);
		}

		importInstanceNodes(node->getInstanceNodes(), newImportNode);

		addUniqueIdINodePair(node->getUniqueId(), newImportNode->GetINode());

		INode* childNode = newImportNode->GetINode();
		INode* parentNode = parentImportNode->GetINode();
		parentNode->AttachChild(childNode, FALSE);

		return newImportNode;
	}

	//------------------------------
	bool VisualSceneImporter::importNodes( const COLLADAFW::NodeArray& nodeArray, ImpNode* parentImportNode )
	{
		for ( size_t i = 0, count = nodeArray.getCount(); i < count; ++i)
		{
			ImpNode* newNode = importNode(nodeArray[i], parentImportNode);
		}

		return true;
	}

	//------------------------------
	bool VisualSceneImporter::importInstanceGeometries( const COLLADAFW::InstanceGeometryArray& instanceGeometryArray, ImpNode* parentImportNode )
	{
		for ( size_t i = 0, count = instanceGeometryArray.getCount(); i < count; ++i)
		{
			COLLADAFW::InstanceGeometry* instanceGeometry = instanceGeometryArray[i];

			ImpNode* newImportNode = getMaxImportInterface()->CreateNode();
			INode* newNode = newImportNode->GetINode();
			const COLLADAFW::UniqueId& uniqueId = instanceGeometry->getInstanciatedObjectId();

			Object* object = getObjectByUniqueId(uniqueId);
			if ( object )
			{
				newImportNode->Reference(object);
			}
			else
			{
				newImportNode->Reference(mDummyObject);
			}
			const COLLADAFW::UniqueId& instanceGeometryUniqueId = instanceGeometry->getInstanciatedObjectId();
			addObjectINodeUniqueIdPair(newNode, instanceGeometryUniqueId);
			addUniqueIdObjectINodePair(instanceGeometryUniqueId, newNode);

			INode* parentNode = parentImportNode->GetINode();
			parentNode->AttachChild(newNode, FALSE);
		}

		return true;
	}

	//------------------------------
	ImpNode* VisualSceneImporter::importInstanceGeometrie( const COLLADAFW::Node* node, ImpNode* parentImportNode )
	{
		ImpNode* newImportNode = getMaxImportInterface()->CreateNode();
		setNodeProperties(node, newImportNode);
		INode* newNode = newImportNode->GetINode();

		COLLADAFW::InstanceGeometry* instanceGeometry = node->getInstanceGeometries()[0];
		const COLLADAFW::UniqueId& uniqueId = instanceGeometry->getInstanciatedObjectId();

		Object* object = getObjectByUniqueId(uniqueId);
		if ( object )
		{
			newImportNode->Reference(object);
		}
		else
		{
			newImportNode->Reference(mDummyObject);
		}

		const COLLADAFW::UniqueId& instanceGeometryUniqueId = instanceGeometry->getInstanciatedObjectId();
		addObjectINodeUniqueIdPair(newNode, instanceGeometryUniqueId);
		addUniqueIdObjectINodePair(instanceGeometryUniqueId, newNode);
		INode* parentNode = parentImportNode->GetINode();
		parentNode->AttachChild(newNode, FALSE);
		return newImportNode;
	}


	//------------------------------
	bool VisualSceneImporter::importInstanceNodes( const COLLADAFW::InstanceNodeArray& instanceNodeArray, ImpNode* parentImportNode )
	{
		for ( size_t i = 0, count = instanceNodeArray.getCount(); i < count; ++i)
		{
			COLLADAFW::InstanceNode* instanceNode = instanceNodeArray[i];

			const COLLADAFW::UniqueId& uniqueId = instanceNode->getInstanciatedObjectId();

			INode* instanciatedINode = getINodeByUniqueId(uniqueId);
			if ( instanciatedINode )
			{
				if ( !recursivlyCloneINode(parentImportNode, instanciatedINode) )
					return false;;
			}

	//		addUniqueIdObjectINodePair(instanceNode->getInstanciatedObjectId(), newNode);
	//		INode* parentNode = parentImportNode->GetINode();
	//		parentNode->AttachChild(newNode, FALSE);
		}

		return true;
	}

	//------------------------------
	bool VisualSceneImporter::recursivlyCloneINode( ImpNode* parentImportNode, INode* nodeToClone )
	{
		ImpNode* newImportNode = getMaxImportInterface()->CreateNode();
		getMaxImportInterface()->AddNodeToScene(newImportNode);

		INode* newNode = newImportNode->GetINode();
		INode* parentNode = parentImportNode->GetINode();

		Object* object = nodeToClone->GetObjectRef();
		newImportNode->Reference(object);
//		newImportNode->SetTransform(0, nodeToClone->GetObjectTM(0));
//		newImportNode->SetTransform(0, nodeToClone->GetParentTM(0));
		newNode->SetTMController(nodeToClone->GetTMController());
		newImportNode->SetName(nodeToClone->GetName());

		parentNode->AttachChild(newNode, TRUE);


		COLLADAFW::UniqueId id = getUniqueIdByObjectINode(nodeToClone);
		if ( id.isValid() )
			addUniqueIdObjectINodePair(id, newNode);

		for ( int i = 0, count = nodeToClone->NumberOfChildren(); i < count; ++i)
			recursivlyCloneINode(newImportNode, nodeToClone->GetChildNode(i));

		return true;
	}



} // namespace COLLADAMax
