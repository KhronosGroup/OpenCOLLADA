/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLNodeLoader.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLGeometryMaterialIdInfo.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWMaterial.h"
#include "COLLADAFWCamera.h"
#include "COLLADAFWLight.h"
#include "COLLADAFWSkinControllerData.h"
#include "COLLADAFWTranslate.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWSkew.h"
#include "COLLADAFWLookat.h"
#include "COLLADAFWMatrix.h"



namespace COLLADASaxFWL
{

    //------------------------------
	NodeLoader::NodeLoader(  )
        : mCurrentInstanceGeometry (0)
        , mCurrentInstanceController (0)
        , mCurrentMaterialInfo(0)
        , mCurrentMaterialBinding(0)
        , mCurrentInstanceControllerData(0)
	{
	}

	//------------------------------
	NodeLoader::~NodeLoader()
	{
	}

	//------------------------------
	bool NodeLoader::beginNode( const node__AttributeData& attributeData )
	{
		COLLADAFW::Node* newNode = new COLLADAFW::Node( getHandlingFilePartLoader()->createUniqueIdFromId(attributeData.id, COLLADAFW::Node::ID()));

		if ( attributeData.name )
			newNode->setName ( (const char*)attributeData.name );
		else if ( attributeData.id )
			newNode->setName ( (const char*)attributeData.id );

        if ( attributeData.id )
            newNode->setOriginalId ( (const char*)attributeData.id );

        if ( attributeData.type == ENUM__NodeType__JOINT )
            newNode->setType ( COLLADAFW::Node::JOINT );

		getHandlingFilePartLoader()->addToSidTree(attributeData.id, attributeData.sid, newNode);

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
		getHandlingFilePartLoader()->moveUpInSidTree();
		return true;
	}

	//------------------------------
	template<class Transformationtype> 
	bool NodeLoader::beginTransformation( const char* sid )
	{
		mTransformationLoader.beginTransformation<Transformationtype>();
		getHandlingFilePartLoader()->addToSidTree( 0, sid, mTransformationLoader.getCurrentTransformation());
		return true;
	}


	//------------------------------
	bool NodeLoader::endTransformation()
	{
		COLLADABU_ASSERT(!mNodeStack.empty());
		mNodeStack.top()->getTransformations().append( mTransformationLoader.getCurrentTransformation());
		getHandlingFilePartLoader()->moveUpInSidTree();
		mTransformationLoader.endTransformation();
		return true;
	}


	//------------------------------
	bool NodeLoader::endInstanceWithMaterial()
	{
		mCurrentMaterialInfo = 0;
		mCurrentMaterialBindings.clear();
		return true;
	}

	//------------------------------
	bool NodeLoader::begin__node( const node__AttributeData& attributeData )
	{
		return beginNode(attributeData);
	}

	//------------------------------
	bool NodeLoader::end__node()
	{
		return endNode();
	}


	//------------------------------
	bool NodeLoader::begin__translate( const translate__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Translate>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__translate()
	{
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__translate( const float* data, size_t length )
	{
		return mTransformationLoader.dataTranslate( data, length);
	}

	//------------------------------
	bool NodeLoader::begin__rotate( const rotate__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Rotate>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__rotate()
	{
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__rotate( const float* data, size_t length )
	{
		return mTransformationLoader.dataRotate( data, length);
	}

	//------------------------------
	bool NodeLoader::begin__matrix( const matrix__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Matrix>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__matrix()
	{
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__matrix( const float* data, size_t length )
	{
		return mTransformationLoader.dataMatrix( data, length);
	}

	//------------------------------
	bool NodeLoader::begin__scale( const scale__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Scale>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__scale()
	{
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__scale( const float* data, size_t length )
	{
		return mTransformationLoader.dataScale( data, length);
	}

    //------------------------------
    bool NodeLoader::begin__skew ( const skew__AttributeData& attributeData )
    {
        return beginTransformation<COLLADAFW::Skew>( attributeData.sid );
    }

    //------------------------------
    bool NodeLoader::end__skew ()
    {
        return endTransformation();
    }

    //------------------------------
	bool NodeLoader::data__skew( const float* data, size_t length )
	{
		return mTransformationLoader.dataSkew( data, length);
    }

	//------------------------------
	bool NodeLoader::begin__lookat ( const lookat__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Lookat>( attributeData.sid );
	}

	//------------------------------
	bool NodeLoader::end__lookat ()
	{
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__lookat( const float* data, size_t length )
	{
		return mTransformationLoader.dataLookat( data, length);
	}	

    //------------------------------
	bool NodeLoader::begin__instance_geometry( const instance_geometry__AttributeData& attributeData )
	{
		COLLADAFW::Node* currentNode = mNodeStack.top();

		COLLADAFW::UniqueId instantiatedGeometryUniqueId = getHandlingFilePartLoader()->createUniqueIdFromUrl( attributeData.url, COLLADAFW::Geometry::ID());
		mCurrentMaterialInfo = &getHandlingFilePartLoader()->getMeshMaterialIdInfo();

        COLLADAFW::UniqueId uniqueId = getHandlingFilePartLoader()->createUniqueId ( COLLADAFW::InstanceGeometry::ID() );
		COLLADAFW::InstanceGeometry* instanceGeometry = FW_NEW COLLADAFW::InstanceGeometry ( uniqueId, instantiatedGeometryUniqueId );
		mCurrentInstanceGeometry = instanceGeometry;
		instanceGeometry->setName(currentNode->getName());
		currentNode->getInstanceGeometries().append(instanceGeometry);

		return true;
	}


	//------------------------------
	bool NodeLoader::end__instance_geometry()
	{
        FilePartLoader::copyStlContainerToArray( mCurrentMaterialBindings, mCurrentInstanceGeometry->getMaterialBindings());
        mCurrentInstanceGeometry = 0;
        endInstanceWithMaterial();

        return true;
	}

    //------------------------------
    bool NodeLoader::begin__bind_material ()
    {
        return true;
    }

    //------------------------------
    bool NodeLoader::end__bind_material ()
    {
        return true;
    }

	//------------------------------
	bool NodeLoader::begin__instance_material( const instance_material__AttributeData& attributeData )
	{
        if ( mCurrentInstanceGeometry || mCurrentInstanceController )
        {
            COLLADAFW::MaterialId materialId = attributeData.symbol ? mCurrentMaterialInfo->getMaterialId((const char*)attributeData.symbol) : 0;
            mCurrentMaterialBinding = new COLLADAFW::MaterialBinding(materialId, getHandlingFilePartLoader()->createUniqueIdFromUrl(attributeData.target, COLLADAFW::Material::ID()));

            if ( attributeData.symbol )
                mCurrentMaterialBinding->setName((const char*)attributeData.symbol);
        }

		return true;
	}

	//------------------------------
	bool NodeLoader::end__instance_material()
	{
        if ( mCurrentInstanceGeometry || mCurrentInstanceController )
        {
            FilePartLoader::copyStlContainerToArray( mCurrentTextureCoordinateBindings, mCurrentMaterialBinding->getTextureCoordinateBindingArray());
            mCurrentMaterialBindings.insert(*mCurrentMaterialBinding);
            delete mCurrentMaterialBinding;
            mCurrentMaterialBinding = 0;
            mCurrentTextureCoordinateBindings.clear();
        }

        return true;
	}

	//------------------------------
	bool NodeLoader::begin__bind_vertex_input( const bind_vertex_input__AttributeData& attributeData )
	{
        if ( mCurrentInstanceGeometry || mCurrentInstanceController )
        {
            COLLADAFW::TextureCoordinateBinding texCoordinateBinding;
            texCoordinateBinding.setSetIndex ( (size_t)attributeData.input_set );
            texCoordinateBinding.setSemantic( attributeData.semantic );
            texCoordinateBinding.setTextureMapId ( getHandlingFilePartLoader()->getTextureMapIdBySematic( attributeData.semantic ) );
            mCurrentTextureCoordinateBindings.insert(texCoordinateBinding);
        }
		return true;
	}

	//------------------------------
	bool NodeLoader::begin__instance_node( const instance_node__AttributeData& attributeData )
	{
		COLLADAFW::Node* currentNode = mNodeStack.top();
		COLLADAFW::UniqueId instantiatedNodeUniqueId = getHandlingFilePartLoader()->createUniqueIdFromUrl( attributeData.url, COLLADAFW::Node::ID() );

        COLLADAFW::UniqueId instanceNodeUniqueId = getHandlingFilePartLoader()->createUniqueId( COLLADAFW::InstanceNode::ID() );
		COLLADAFW::InstanceNode* instanceNode = FW_NEW COLLADAFW::InstanceNode(instanceNodeUniqueId,instantiatedNodeUniqueId);
		currentNode->getInstanceNodes().append(instanceNode);

		return true;
	}

    //------------------------------
    bool NodeLoader::end__instance_node ()
    {
        return true;
    }
    
    //------------------------------
	bool NodeLoader::begin__instance_camera( const instance_camera__AttributeData& attributeData )
	{
        COLLADAFW::Node* currentNode = mNodeStack.top();
		COLLADAFW::UniqueId instantiatedCameraUniqueId = getHandlingFilePartLoader()->createUniqueIdFromUrl( attributeData.url, COLLADAFW::Camera::ID() );

        COLLADAFW::UniqueId instanceCameraUniqueId = getHandlingFilePartLoader()->createUniqueId( COLLADAFW::InstanceCamera::ID() );
		COLLADAFW::InstanceCamera* instanceCamera = FW_NEW COLLADAFW::InstanceCamera(instanceCameraUniqueId, instantiatedCameraUniqueId);
		currentNode->getInstanceCameras().append(instanceCamera);

		return true;
	}

    //------------------------------
    bool NodeLoader::end__instance_camera ()
    {
        return true;
    }
    
    //------------------------------
	bool NodeLoader::begin__instance_light( const instance_light__AttributeData& attributeData )
	{
		COLLADAFW::Node* currentNode = mNodeStack.top();
		COLLADAFW::UniqueId instantiatedLightUniqueId = getHandlingFilePartLoader()->createUniqueIdFromUrl( attributeData.url, COLLADAFW::Light::ID() );

        COLLADAFW::UniqueId instanceLightUniqueId = getHandlingFilePartLoader()->createUniqueId( COLLADAFW::InstanceLight::ID() );
		COLLADAFW::InstanceLight* instanceLight = FW_NEW COLLADAFW::InstanceLight(instanceLightUniqueId, instantiatedLightUniqueId);
		currentNode->getInstanceLights().append(instanceLight);

		return true;
	}

    //------------------------------
    bool NodeLoader::end__instance_light ()
    {
        return true;
    }

	//------------------------------
	bool NodeLoader::begin__instance_controller( const instance_controller__AttributeData& attributeData )
	{
		COLLADAFW::Node* currentNode = mNodeStack.top();
		COLLADAFW::UniqueId instantiatedControllerUniqueId = getHandlingFilePartLoader()->createUniqueIdFromUrl( attributeData.url, COLLADAFW::SkinControllerData::ID() );
		mCurrentMaterialInfo = &getHandlingFilePartLoader()->getMeshMaterialIdInfo();

        COLLADAFW::UniqueId uniqueId = getHandlingFilePartLoader()->createUniqueId ( COLLADAFW::InstanceController::ID() );
		COLLADAFW::InstanceController* instanceController = FW_NEW COLLADAFW::InstanceController( uniqueId, instantiatedControllerUniqueId);
		mCurrentInstanceController = instanceController;
		currentNode->getInstanceControllers().append(instanceController);

		Loader::InstanceControllerData instanceControllerData;
		instanceControllerData.instanceController = instanceController;
		Loader::InstanceControllerDataList& instanceControllerDataList = getHandlingFilePartLoader()->getInstanceControllerDataListByControllerUniqueId(instantiatedControllerUniqueId);
		instanceControllerDataList.push_back(instanceControllerData);
		mCurrentInstanceControllerData = &instanceControllerDataList.back();

		return true;
	}

	//------------------------------
	bool NodeLoader::end__instance_controller()
	{
        FilePartLoader::copyStlContainerToArray( mCurrentMaterialBindings, mCurrentInstanceController->getMaterialBindings());
        mCurrentInstanceController = 0;
		mCurrentInstanceControllerData = 0;
        endInstanceWithMaterial();

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
