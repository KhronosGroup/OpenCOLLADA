/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPhysicsSceneLoader.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLFilePartLoader.h"

#include "COLLADAFWPhysicsScene.h"
#include "COLLADAFWIWriter.h"


namespace COLLADASaxFWL
{

	PhysicsSceneLoader::PhysicsSceneLoader()
		: mPhysicsScene(0)
		, mCurrentSceneHasGravity(false)
		, mCurrentSceneHasTimeStep(false)
   		{ }

    //------------------------------
	PhysicsSceneLoader::~PhysicsSceneLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& PhysicsSceneLoader::getUniqueId()
    {
        if ( mPhysicsScene )
		{
			return mPhysicsScene->getUniqueId();
		}

        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	bool PhysicsSceneLoader::beginPhysicsScene( const physics_scene__AttributeData& attributeData)
	{	std::cout << "begin phys scene \n";
		mPhysicsScene = new COLLADAFW::PhysicsScene( getHandlingFilePartLoader()->createUniqueIdFromId(attributeData.id, COLLADAFW::PhysicsScene::ID()));

		if ( attributeData.name )
			mPhysicsScene->setName ( (const char*)attributeData.name );
		else if ( attributeData.id )
			mPhysicsScene->setName ( (const char*)attributeData.id );

        if ( attributeData.id )
            mPhysicsScene->setOriginalId ( (const char*)attributeData.id );

        getHandlingFilePartLoader()->addToSidTree(attributeData.id, 0, mPhysicsScene );

		return true;
	}
	
	//------------------------------
	bool PhysicsSceneLoader::endPhysicsScene()
	{   std::cout << "end phys scene \n";
		getHandlingFilePartLoader()->moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool PhysicsSceneLoader::begin__physics_scene( const physics_scene__AttributeData& attributeData )
	{
		return beginPhysicsScene(attributeData);
	}

	//------------------------------
	bool PhysicsSceneLoader::end__physics_scene()
	{
		return endPhysicsScene();
	}

	/*bool PhysicsSceneLoader::begin__instance_physics_model( const instance_physics_model__AttributeData& attributeData )
	{
		PhysicsInstancePhysicsModels& instancePhysicsModels = mCurrentPhysicsScene->getPhysicsInstancePhysicsModels();
		COLLADABU::URI absoluteUrl(getFileUri(), attributeData.url.getURIString());
		instancePhysicsModels.push_back(PhysicsInstancePhysicsModel(absoluteUrl)); 
		PhysicsInstancePhysicsModel * instancePhysicsModel = &instancePhysicsModels.back();
		addToSidTree( 0, attributeData.sid, instancePhysicsModel);
		mInstancePhysicsModelLoader.setCurrentInstancePhysicsModel(instancePhysicsModel);
		return true;
	}*/

	//------------------------------
	/*bool PhysicsSceneLoader::end__instance_physics_model()
	{
		moveUpInSidTree();
		return true;
	}*/

	bool PhysicsSceneLoader::begin__gravity( const gravity__AttributeData& attributeData )
	{
		getHandlingFilePartLoader()->addToSidTree( 0, attributeData.sid, &mPhysicsScene->getGravity());
		return true;
	}

	//------------------------------
	bool PhysicsSceneLoader::data__gravity( const float* data, size_t length )
   	{
		COLLADAFW::Gravity& gravity = mPhysicsScene->getGravity();
		for ( size_t i = 0; i < length; ++i)
		{
			switch ( i )
			{
			case 0:
				gravity.setX(data[i]);
				break;
			case 1:
				gravity.setY(data[i]);
				break;
			case 2:
				gravity.setZ(data[i]);
				break;
			}
		}	
		return true;
    }

	//------------------------------
	bool PhysicsSceneLoader::end__gravity()
	{
		getHandlingFilePartLoader()->moveUpInSidTree();
		return true;
	}

	bool PhysicsSceneLoader::begin__time_step( const time_step__AttributeData& attributeData )
	{
		getHandlingFilePartLoader()->addToSidTree( 0, attributeData.sid, &mPhysicsScene->getTimestep());
		return true;
	}

	//------------------------------
	bool PhysicsSceneLoader::data__time_step( float value )
	{
		mPhysicsScene->setTimeStep(value);
		mCurrentSceneHasTimeStep = true;
		return true;
	}

	//------------------------------
	bool PhysicsSceneLoader::end__time_step()
	{
		getHandlingFilePartLoader()->moveUpInSidTree();
		return true;
	}


} // namespace COLLADASaxFWL
