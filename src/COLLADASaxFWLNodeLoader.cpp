/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLNodeLoader.h"
#include "COLLADASaxFWLGeometryMaterialIdInfo.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWTranslate.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWSkew.h"
#include "COLLADAFWLookat.h"
#include "COLLADAFWMatrix.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWMaterial.h"
#include "COLLADAFWCamera.h"
#include "COLLADAFWLight.h"
#include "COLLADAFWSkinControllerData.h"


namespace COLLADASaxFWL
{

	NodeLoader::NodeLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader),
		mCurrentTransformation(0),
		mTransformationNumbersReceived(0),
		mCurrentInstanceWithMaterial(0),
		mCurrentMaterialInfo(0),
		mCurrentMaterialBinding(0),
		mCurrentInstanceControllerData(0)
	{
	}

	//------------------------------
	NodeLoader::~NodeLoader()
	{
	}

	//------------------------------
	bool NodeLoader::beginNode( const node__AttributeData& attributeData )
	{
		COLLADAFW::Node* newNode = new COLLADAFW::Node(getUniqueIdFromId(attributeData.id, COLLADAFW::Node::ID()).getObjectId());

		if ( attributeData.name )
			newNode->setName ( (const char*)attributeData.name );
		else if ( attributeData.id )
			newNode->setName ( (const char*)attributeData.id );

        if ( attributeData.id )
            newNode->setOriginalId ( (const char*)attributeData.id );

        if ( attributeData.type == ENUM__NodeType__JOINT )
            newNode->setType ( COLLADAFW::Node::JOINT );

		addToSidTree(attributeData.id, attributeData.sid, newNode);

		if ( mNodeStack.empty() )
		{
			// we are a direct child of a container
			handleRootNode(newNode);
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
	bool NodeLoader::endNode()
	{
		mNodeStack.pop();
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	template<class Transformationtype> 
	bool NodeLoader::beginTransformation( const char* sid )
	{
		mCurrentTransformation = new Transformationtype();
		addToSidTree( 0, sid, mCurrentTransformation);
		assert(mCurrentTransformation);
		return true;
	}


	//------------------------------
	bool NodeLoader::endTransformation()
	{
		assert(!mNodeStack.empty());
		mNodeStack.top()->getTransformations().append(mCurrentTransformation);
		moveUpInSidTree();
		mTransformationNumbersReceived = 0;
		mCurrentTransformation = 0;
		return true;
	}


	//------------------------------
	bool NodeLoader::endInstanceWithMaterial()
	{
		copyStlContainerToArray( mCurrentMaterialBindings, mCurrentInstanceWithMaterial->getMaterialBindings());

		mCurrentInstanceWithMaterial = 0;
		mCurrentMaterialInfo = 0;
		mCurrentMaterialBindings.clear();
		return true;
	}

	//------------------------------
	bool NodeLoader::begin__node( const node__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__node(attributeData));
		return beginNode(attributeData);
	}

	//------------------------------
	bool NodeLoader::end__node()
	{
		SaxVirtualFunctionTest(end__node());
		return endNode();
	}


	//------------------------------
	bool NodeLoader::begin__translate( const translate__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__translate(attributeData));
		return beginTransformation<COLLADAFW::Translate>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__translate()
	{
		SaxVirtualFunctionTest(end__translate());
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__translate( const float* data, size_t length )
	{
		SaxVirtualFunctionTest(data__translate(data, length));
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
	bool NodeLoader::begin__rotate( const rotate__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__rotate(attributeData));
		return beginTransformation<COLLADAFW::Rotate>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__rotate()
	{
		SaxVirtualFunctionTest(end__rotate());
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__rotate( const float* data, size_t length )
	{
		SaxVirtualFunctionTest(data__rotate(data, length));
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
	bool NodeLoader::begin__matrix( const matrix__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__matrix(attributeData));
		return beginTransformation<COLLADAFW::Matrix>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__matrix()
	{
		SaxVirtualFunctionTest(end__matrix());
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__matrix( const float* data, size_t length )
	{
		SaxVirtualFunctionTest(data__matrix(data, length));
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
	bool NodeLoader::begin__scale( const scale__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__scale(attributeData));
		return beginTransformation<COLLADAFW::Scale>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__scale()
	{
		SaxVirtualFunctionTest(end__scale());
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__scale( const float* data, size_t length )
	{
		SaxVirtualFunctionTest(data__scale(data, length));
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
    bool NodeLoader::begin__skew ( const skew__AttributeData& attributeData )
    {
		SaxVirtualFunctionTest(begin__skew(attributeData));
        return beginTransformation<COLLADAFW::Skew>( attributeData.sid );
    }

    //------------------------------
    bool NodeLoader::end__skew ()
    {
		SaxVirtualFunctionTest(end__skew());
        return endTransformation();
    }

    //------------------------------
	bool NodeLoader::data__skew( const float* data, size_t length )
	{
		SaxVirtualFunctionTest(data__skew(data, length));
        COLLADAFW::Skew* skew = 0;

        if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::SKEW)
            skew = (COLLADAFW::Skew*)(mCurrentTransformation);

        assert(skew);

        double angle = skew->getAngle ();
        COLLADABU::Math::Vector3& rotateAxis = skew->getRotateAxis ();
        COLLADABU::Math::Vector3& aroundAxis = skew->getTranslateAxis ();

        size_t i = 0;
        if ( i < length && mTransformationNumbersReceived == 0 )
        {
            angle = data [mTransformationNumbersReceived++];
            ++i;
        }
        if ( i < length && mTransformationNumbersReceived > 0 && mTransformationNumbersReceived < 4 )
        {
            for ( size_t j=0; j<3 && i<length; ++j, ++i )
            {
                rotateAxis[j] = data[i];
                mTransformationNumbersReceived++;
            }
        }
        if (  i < length && mTransformationNumbersReceived >= 4 )
        {
            for ( size_t j=0; j<3 && i<length; ++j, ++i )
            {
                aroundAxis[j] = data[i];
                mTransformationNumbersReceived++;
            }
        }
        return true;
    }

	//------------------------------
	bool NodeLoader::begin__lookat ( const lookat__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__lookat(attributeData));
		return beginTransformation<COLLADAFW::Lookat>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__lookat ()
	{
		SaxVirtualFunctionTest(end__lookat());
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__lookat( const float* data, size_t length )
	{
		SaxVirtualFunctionTest(data__lookat(data, length));
		COLLADAFW::Lookat* lookat = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::LOOKAT)
			lookat = (COLLADAFW::Lookat*)(mCurrentTransformation);

		assert(lookat);

		COLLADABU::Math::Vector3& eyePosition = lookat->getEyePosition ();
		COLLADABU::Math::Vector3& interestPointPosition = lookat->getInterestPointPosition ();
		COLLADABU::Math::Vector3& upAxisDirection = lookat->getUpAxisDirection ();

		size_t i = 0;
		if ( i < length && mTransformationNumbersReceived < 3 )
		{
			for ( size_t j=mTransformationNumbersReceived; j<3 && i<length; ++j, ++i )
			{
				eyePosition[j] = data[i];
				mTransformationNumbersReceived++;
			}
		}
		if ( i < length && mTransformationNumbersReceived >= 3 && mTransformationNumbersReceived < 6 )
		{
			for ( size_t j=mTransformationNumbersReceived-3; j<3 && i<length; ++j, ++i )
			{
				interestPointPosition[j] = data[i];
				mTransformationNumbersReceived++;
			}
		}
		if (  i < length && mTransformationNumbersReceived >= 6 )
		{
			for ( size_t j=mTransformationNumbersReceived-6; j<3 && i<length; ++j, ++i )
			{
				upAxisDirection[j] = data[i];
				mTransformationNumbersReceived++;
			}
		}
		return true;
	}	

    //------------------------------
	bool NodeLoader::begin__instance_geometry( const instance_geometry__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__instance_geometry(attributeData));
		COLLADAFW::Node* currentNode = mNodeStack.top();

		COLLADAFW::UniqueId instantiatedGeometryUniqueId = getUniqueIdFromUrl( attributeData.url, COLLADAFW::Geometry::ID());
		mCurrentMaterialInfo = &getMeshMaterialIdInfo(instantiatedGeometryUniqueId);

		COLLADAFW::InstanceGeometry* instanceGeometry = new COLLADAFW::InstanceGeometry(instantiatedGeometryUniqueId);
		mCurrentInstanceWithMaterial = instanceGeometry;
		currentNode->getInstanceGeometries().append(instanceGeometry);

		return true;
	}


	//------------------------------
	bool NodeLoader::end__instance_geometry()
	{
		SaxVirtualFunctionTest(end__instance_geometry());
		endInstanceWithMaterial();
		return true;
	}


	//------------------------------
	bool NodeLoader::begin__instance_material( const instance_material__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__instance_material(attributeData));
		// remove this, as soon as we support controllers
		if ( !mCurrentInstanceWithMaterial )
			return true;

		COLLADAFW::MaterialId materialId = attributeData.symbol ? mCurrentMaterialInfo->getMaterialId((const char*)attributeData.symbol) : 0;
		mCurrentMaterialBinding = new COLLADAFW::InstanceGeometry::MaterialBinding(materialId, getUniqueIdFromUrl(attributeData.target, COLLADAFW::Material::ID()));

        if ( attributeData.symbol )
            mCurrentMaterialBinding->setName((const char*)attributeData.symbol);

		return true;
	}

	//------------------------------
	bool NodeLoader::end__instance_material()
	{
		SaxVirtualFunctionTest(end__instance_material());
		// remove this, as soon as we support controllers
		if ( !mCurrentInstanceWithMaterial )
			return true;

		copyStlContainerToArray( mCurrentTextureCoordinateBindings, mCurrentMaterialBinding->getTextureCoordinateBindingArray());
		mCurrentMaterialBindings.insert(*mCurrentMaterialBinding);
		delete mCurrentMaterialBinding;
		mCurrentMaterialBinding = 0;
		mCurrentTextureCoordinateBindings.clear();
		return true;
	}

	//------------------------------
	bool NodeLoader::begin__bind_vertex_input( const bind_vertex_input__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__bind_vertex_input(attributeData));
		// remove this, as soon as we support controllers
		if ( !mCurrentInstanceWithMaterial )
			return true;

		COLLADAFW::InstanceGeometry::TextureCoordinateBinding texCoordinateBinding;
		texCoordinateBinding.setIndex = (size_t)attributeData.input_set;
		texCoordinateBinding.textureMapId = getTextureMapIdBySematic( attributeData.semantic );
		mCurrentTextureCoordinateBindings.insert(texCoordinateBinding);
		return true;
	}

	//------------------------------
	bool NodeLoader::begin__instance_node( const instance_node__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__instance_node(attributeData));
		COLLADAFW::Node* currentNode = mNodeStack.top();
		COLLADAFW::UniqueId instantiatedNodeUniqueId = getUniqueIdFromUrl( attributeData.url, COLLADAFW::Node::ID() );

		COLLADAFW::InstanceNode* instanceNode = FW_NEW COLLADAFW::InstanceNode(instantiatedNodeUniqueId);
		currentNode->getInstanceNodes().append(instanceNode);

		return true;
	}

	//------------------------------
	bool NodeLoader::begin__instance_camera( const instance_camera__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__instance_camera(attributeData));
		COLLADAFW::Node* currentNode = mNodeStack.top();
		COLLADAFW::UniqueId instantiatedCameraUniqueId = getUniqueIdFromUrl( attributeData.url, COLLADAFW::Camera::ID() );

		COLLADAFW::InstanceCamera* instanceCamera = FW_NEW COLLADAFW::InstanceCamera(instantiatedCameraUniqueId);
		currentNode->getInstanceCameras().append(instanceCamera);

		return true;
	}

	//------------------------------
	bool NodeLoader::begin__instance_light( const instance_light__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__instance_light(attributeData));
		COLLADAFW::Node* currentNode = mNodeStack.top();
		COLLADAFW::UniqueId instantiatedLightUniqueId = getUniqueIdFromUrl( attributeData.url, COLLADAFW::Light::ID() );

		COLLADAFW::InstanceLight* instanceLight = FW_NEW COLLADAFW::InstanceLight(instantiatedLightUniqueId);
		currentNode->getInstanceLights().append(instanceLight);

		return true;
	}

	//------------------------------
	bool NodeLoader::begin__instance_controller( const instance_controller__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__instance_controller(attributeData));
		COLLADAFW::Node* currentNode = mNodeStack.top();
		COLLADAFW::UniqueId instantiatedControllerUniqueId = getUniqueIdFromUrl( attributeData.url, COLLADAFW::SkinControllerData::ID() );
		mCurrentMaterialInfo = &getMeshMaterialIdInfo(instantiatedControllerUniqueId);

		COLLADAFW::InstanceController* instanceController = FW_NEW COLLADAFW::InstanceController(instantiatedControllerUniqueId);
		mCurrentInstanceWithMaterial = instanceController;
		currentNode->getInstanceControllers().append(instanceController);

		InstanceControllerData instanceControllerData;
		instanceControllerData.instanceController = instanceController;
		InstanceControllerDataList& instanceControllerDataList = getInstanceControllerDataListByControllerUniqueId(instantiatedControllerUniqueId);
		instanceControllerDataList.push_back(instanceControllerData);
		mCurrentInstanceControllerData = &instanceControllerDataList.back();

		return true;
	}

	//------------------------------
	bool NodeLoader::end__instance_controller()
	{
		SaxVirtualFunctionTest(end__instance_controller());
		endInstanceWithMaterial();
		mCurrentInstanceControllerData = 0;
		return true;
	}

	//------------------------------
	bool NodeLoader::data__skeleton( COLLADABU::URI value )
	{
		if (mCurrentInstanceControllerData)
		{
			mCurrentInstanceControllerData->skeletonRoots.push_back( value );
		}

		return true;
	}

} // namespace COLLADASaxFWL
