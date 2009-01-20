/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLVisualSceneLoader.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWIWriter.h"
#include "COLLADAFWTranslate.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWMatrix.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWGeometry.h"


namespace COLLADASaxFWL
{

	VisualSceneLoader::VisualSceneLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader),
		mCurrentTransformation(0),
		mTransformationNumbersReceived(0)
	{
		mVisualScene = new COLLADAFW::VisualScene();
	}

    //------------------------------
	VisualSceneLoader::~VisualSceneLoader()
	{
	}

	//------------------------------
	bool VisualSceneLoader::beginNode( const node__node__AttributeData& attributeData )
	{
		COLLADAFW::Node* newNode;
		if ( attributeData.id )
		{
			newNode = new COLLADAFW::Node(getUniqueId(String("#") + (const char*)attributeData.id, COLLADAFW::Node::ID()).getObjectId());
		}
		else
		{
			newNode = new COLLADAFW::Node(getUniqueId(COLLADAFW::Node::ID()).getObjectId());
		}

		if ( attributeData.name )
			newNode->setName((const char*)attributeData.name);

		if ( mNodeStack.empty() )
		{
			// we are a direct child of the visual scene
			mVisualScene->getRootNodes().append(newNode);
		}
		else
		{
			//we are a child of another node
			COLLADAFW::Node* parentNode = mNodeStack.top();
			parentNode->getChildNodes().append(newNode);
		}
		mNodeStack.push(newNode);
		return true;
	}

	//------------------------------
	bool VisualSceneLoader::endNode()
	{
		mNodeStack.pop();
		return true;
	}

	//------------------------------
	template<class Transformationtype>
	bool VisualSceneLoader::beginTransformation()
	{
		mCurrentTransformation = new Transformationtype();
		assert(mCurrentTransformation);
		return true;
	}


	//------------------------------
	bool VisualSceneLoader::endTransformation()
	{
		assert(!mNodeStack.empty());
		mNodeStack.top()->getTransformations().append(mCurrentTransformation);
		mTransformationNumbersReceived = 0;
		mCurrentTransformation = 0;
		return true;
	}


	//------------------------------
	bool VisualSceneLoader::begin__node__node( const node__node__AttributeData& attributeData )
	{
		return beginNode(attributeData);
	}

	//------------------------------
	bool VisualSceneLoader::end__node__node()
	{
		return endNode();
	}


	//------------------------------
	bool VisualSceneLoader::begin__visual_scene__node( const visual_scene__node__AttributeData& attributeData )
	{
		return beginNode(*(const node__node__AttributeData *)(&attributeData));
	}

	//------------------------------
	bool VisualSceneLoader::end__visual_scene__node()
	{
		return endNode();
	}

	bool VisualSceneLoader::end__visual_scene()
	{
		bool success = writer()->writeVisualScene(mVisualScene);
		delete mVisualScene;
		finish();
		return success;
	}

	//------------------------------
	bool VisualSceneLoader::begin__node__translate( const node__translate__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Translate>();
	}

	//------------------------------
	bool VisualSceneLoader::end__node__translate()
	{
		return endTransformation();
	}

	//------------------------------
	bool VisualSceneLoader::data__node__translate( const double* data, size_t length )
	{
		COLLADAFW::Translate* translate = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::TRANSLATE)
			translate = (COLLADAFW::Translate*)(mCurrentTransformation);

		assert(translate);
		COLLADABU::Math::Vector3& translationVector = translate->getTranslation();
		for ( size_t i = 0; i < length; ++i )
			translationVector[mTransformationNumbersReceived++] = data[i];
		return true;
	}

	//------------------------------
	bool VisualSceneLoader::begin__node__rotate( const node__rotate__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Rotate>();
	}

	//------------------------------
	bool VisualSceneLoader::end__node__rotate()
	{
		return endTransformation();
	}

	//------------------------------
	bool VisualSceneLoader::data__node__rotate( const double* data, size_t length )
	{
		COLLADAFW::Rotate* rotate = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::ROTATE)
			rotate = (COLLADAFW::Rotate*)(mCurrentTransformation);

		assert(rotate);
		COLLADABU::Math::Vector3& axisVector = rotate->getRotationAxis();
		for ( size_t i = 0; i < length; ++i )
		{
			if ( mTransformationNumbersReceived < 3)
				axisVector[mTransformationNumbersReceived++] = data[i];
			else
				rotate->setRotationAngle(data[i]);
		}
		return true;
	}

	//------------------------------
	bool VisualSceneLoader::begin__matrix( const matrix__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Matrix>();
	}

	//------------------------------
	bool VisualSceneLoader::end__matrix()
	{
		return endTransformation();
	}

	//------------------------------
	bool VisualSceneLoader::data__matrix( const double* data, size_t length )
	{
		COLLADAFW::Matrix* matrix = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::MATRIX)
			matrix = (COLLADAFW::Matrix*)(mCurrentTransformation);

		assert(matrix);
		COLLADABU::Math::Matrix4& transformationMatrix = matrix->getMatrix();
		for ( size_t i = 0; i < length; ++i )
		{
			size_t row = mTransformationNumbersReceived / 4;
			size_t column = mTransformationNumbersReceived % 4;
			transformationMatrix.setElement(row, column, data[i]);
			mTransformationNumbersReceived++;
		}
		return true;
	}

	//------------------------------
	bool VisualSceneLoader::begin__scale( const scale__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Scale>();
	}

	//------------------------------
	bool VisualSceneLoader::end__scale()
	{
		return endTransformation();
	}

	//------------------------------
	bool VisualSceneLoader::data__scale( const double* data, size_t length )
	{
		COLLADAFW::Scale* scale = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::SCALE)
			scale = (COLLADAFW::Scale*)(mCurrentTransformation);

		assert(scale);
		COLLADABU::Math::Vector3& scaleVector = scale->getScale();
		for ( size_t i = 0; i < length; ++i )
			scaleVector[mTransformationNumbersReceived++] = data[i];
		return true;
	}

	//------------------------------
	bool VisualSceneLoader::begin__node__instance_geometry( const node__instance_geometry__AttributeData& attributeData )
	{
		COLLADAFW::Node* currentNode = mNodeStack.top();

		COLLADAFW::UniqueId instantiatedGeometryUniqueId = getUniqueId((const char*)attributeData.url, COLLADAFW::Geometry::ID());

		COLLADAFW::InstanceGeometry* instanceGeometry = new COLLADAFW::InstanceGeometry(instantiatedGeometryUniqueId);

		currentNode->getInstanceGeometries().append(instanceGeometry);

		return true;
	}

	//------------------------------
	bool VisualSceneLoader::end__node__instance_geometry()
	{
		return true;
	}

	//------------------------------
	bool VisualSceneLoader::begin__instance_node( const instance_node__AttributeData& attributeData )
	{
		COLLADAFW::Node* currentNode = mNodeStack.top();

		COLLADAFW::UniqueId instantiatedNodeUniqueId = getUniqueId((const char*)attributeData.url, COLLADAFW::Node::ID());

		COLLADAFW::InstanceNode* instanceNode = new COLLADAFW::InstanceNode(instantiatedNodeUniqueId);

		currentNode->getInstanceNodes().append(instanceNode);

		return true;
	}

	//------------------------------
	bool VisualSceneLoader::end__instance_node()
	{
		return true;
	}

} // namespace COLLADASaxFWL
