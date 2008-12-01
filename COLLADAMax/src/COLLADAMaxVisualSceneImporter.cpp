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
#include "COLLADAFWMathMatrix4.h"
#include "COLLADAFWInstanceGeometry.h"

#include <max.h>


namespace COLLADAMax
{


	VisualSceneImporter::VisualSceneImporter( DocumentImporter* documentImporter, const COLLADAFW::VisualScene* visualScene )
		:	ImporterBase(documentImporter),
			mVisualScene(visualScene)
	{

	}

    //------------------------------
	VisualSceneImporter::~VisualSceneImporter()
	{
	}


	//---------------------------------------------------------------
	void VisualSceneImporter::Matrix4ToMaxMatrix3 ( Matrix3 & copy,  const COLLADAFW::Math::Matrix4& original )
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

		mDummyGeoObject = (Object* ) getMaxImportInterface()->Create(GEOMOBJECT_CLASS_ID, Class_ID ( SPHERE_CLASS_ID, 0 ));

		((GenSphere*)mDummyGeoObject)->SetParams(10,32);

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
	ImpNode* VisualSceneImporter::importNode( COLLADAFW::Node* node  )
	{
		ImpNode* newImportNode = getMaxImportInterface()->CreateNode();

		String newNodeName = node->getName();
		if ( !newNodeName.empty() )
			newImportNode->SetName(newNodeName.c_str());

		// set transform
		COLLADAFW::Math::Matrix4 transformationMatrix;
		node->getTransformationMatrix(transformationMatrix);
		Matrix3 maxTransformationMatrix;
		Matrix4ToMaxMatrix3(maxTransformationMatrix, transformationMatrix);
		newImportNode->SetTransform(0, maxTransformationMatrix);

		getMaxImportInterface()->AddNodeToScene(newImportNode);

		RefResult res = newImportNode->Reference(mDummyObject);

		importInstanceGeometries(node->getInstanceGeometries(), newImportNode);
		importNodes(node->getChildNodes(), newImportNode);

		return newImportNode;
	}

	//------------------------------
	bool VisualSceneImporter::importNodes( const COLLADAFW::NodeArray& nodeArray, ImpNode* parentImportNode )
	{
		for ( size_t i = 0, count = nodeArray.getCount(); i < count; ++i)
		{
			ImpNode* newNode = importNode(nodeArray[i]);
			INode* childNode = newNode->GetINode();
			INode* parentNode = parentImportNode->GetINode();
			parentNode->AttachChild(childNode, FALSE);
		}

		return true;
	}

	//------------------------------
	bool VisualSceneImporter::importInstanceGeometries( const COLLADAFW::InstanceGeometryArray& instanceGeometryArray, ImpNode* parentImportNode )
	{
		for ( size_t i = 0, count = instanceGeometryArray.getCount(); i < count; ++i)
		{
			COLLADAFW::InstanceGeometry* instanceGeoemtry = instanceGeometryArray[i];

			ImpNode* newImportNode = getMaxImportInterface()->CreateNode();
			INode* newNode = newImportNode->GetINode();

			// TODO remove this if we
			newImportNode->Reference(mDummyGeoObject);

			addUniqueIdINodePair(instanceGeoemtry->getInstanciatedGeometryId(), newNode);
			INode* parentNode = parentImportNode->GetINode();
			parentNode->AttachChild(newNode, FALSE);
		}

		return true;
	}


} // namespace COLLADAMax
