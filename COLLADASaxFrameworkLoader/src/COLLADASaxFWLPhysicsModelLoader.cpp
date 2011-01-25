/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPhysicsModelLoader.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLFilePartLoader.h"

#include "COLLADAFWPhysicsModel.h"
#include "COLLADAFWRigidBody.h"
#include "COLLADAFWIWriter.h"


namespace COLLADASaxFWL
{

	PhysicsModelLoader::PhysicsModelLoader( )
		: mPhysicsModel(0)
	{ }

    //------------------------------
	PhysicsModelLoader::~PhysicsModelLoader()
	{ }

    //------------------------------
    const COLLADAFW::UniqueId& PhysicsModelLoader::getUniqueId()
    {
        if ( mPhysicsModel )
		{
			return mPhysicsModel->getUniqueId();
		}

        return COLLADAFW::UniqueId::INVALID;
    }
	
	//------------------------------
	void PhysicsModelLoader::handleParentBody( COLLADAFW::RigidBody* parentBody )
	{
		mPhysicsModel->getBodies().append(parentBody);
	}

	//------------------------------
	bool PhysicsModelLoader::beginPhysicsModel( const physics_model__AttributeData& attributeData)
	{	std::cout << "in begin phys models in PML::begin phys model \n";
		mPhysicsModel = new COLLADAFW::PhysicsModel( getHandlingFilePartLoader()->createUniqueIdFromId(attributeData.id, COLLADAFW::PhysicsModel::ID()));

		if ( attributeData.name )
			mPhysicsModel->setName ( (const char*)attributeData.name );
		else if ( attributeData.id )
			mPhysicsModel->setName ( (const char*)attributeData.id );

        if ( attributeData.id )
            mPhysicsModel->setOriginalId ( (const char*)attributeData.id );

        getHandlingFilePartLoader()->addToSidTree(attributeData.id, 0, mPhysicsModel );

		return true;
	}
	
	//------------------------------
	bool PhysicsModelLoader::endPhysicsModel()
	{   std::cout << "in end phys models in PML::end phys model \n";
		getHandlingFilePartLoader()->moveUpInSidTree();
		getHandlingFilePartLoader()->getFileLoader()->addPhysicsModels(mPhysicsModel);
		return true;
	}

	//------------------------------
	bool PhysicsModelLoader::begin__physics_model( const physics_model__AttributeData& attributeData )
	{
		return beginPhysicsModel(attributeData);
	}

	//------------------------------
	bool PhysicsModelLoader::end__physics_model()
	{
		return endPhysicsModel();
	}

	/*bool PhysicsModelLoader::begin__instance_physics_model( const instance_physics_model__AttributeData& attributeData )
	{
		PhysicsInstancePhysicsModels& instancePhysicsModels = mCurrentPhysicsModel->getPhysicsInstancePhysicsModels();
		COLLADABU::URI absoluteUrl(getFileUri(), attributeData.url.getURIString());
		instancePhysicsModels.push_back(PhysicsInstancePhysicsModel(absoluteUrl)); 
		PhysicsInstancePhysicsModel * instancePhysicsModel = &instancePhysicsModels.back();
		addToSidTree( 0, attributeData.sid, instancePhysicsModel);
		mInstancePhysicsModelLoader.setCurrentInstancePhysicsModel(instancePhysicsModel);
		return true;
	}*/

	//------------------------------
	/*bool PhysicsModelLoader::end__instance_physics_model()
	{
		moveUpInSidTree();
		return true;
	}*/

	//------------------------------
	bool PhysicsModelLoader::begin__rigid_body( const rigid_body__AttributeData& attributeData )
	{
		
		COLLADAFW::RigidBody* newBody = new COLLADAFW::RigidBody( getHandlingFilePartLoader()->createUniqueIdFromId(attributeData.id, COLLADAFW::RigidBody::ID()));

		if ( attributeData.name )
			newBody->setName ( (const char*)attributeData.name );
		else if ( attributeData.id )
			newBody->setName ( (const char*)attributeData.id );

        if ( attributeData.id )
            newBody->setOriginalId ( (const char*)attributeData.id );

        getHandlingFilePartLoader()->addToSidTree(attributeData.id, attributeData.sid, newBody);

		if ( mRigidbodyStack.empty() )
		{
			// we are a direct child of a container
			handleParentBody(newBody);
		}
		else
		{
			//we are a child of another Body
			COLLADAFW::RigidBody* parentBody = mRigidbodyStack.top();
			parentBody->getChildBodies().append(newBody);
		}

		mRigidbodyStack.push(newBody);
		return true;
	}

	//------------------------------
	bool PhysicsModelLoader::end__rigid_body()
	{
		mRigidbodyStack.pop();
		getHandlingFilePartLoader()->moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool PhysicsModelLoader::begin__rigid_body__technique_common__dynamic( const rigid_body__technique_common__dynamic__AttributeData& attributeData )
	{
		getHandlingFilePartLoader()->addToSidTree( 0, attributeData.sid, &mRigidbodyStack.top()->isDynamic());
		return true;
	}

	//------------------------------
	bool PhysicsModelLoader::end__rigid_body__technique_common__dynamic()
	{
		getHandlingFilePartLoader()->moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool PhysicsModelLoader::data__rigid_body__technique_common__dynamic( const bool value )
	{
		mRigidbodyStack.top()->setDynamicity(value);
		//mHasTimeStep = true;
		return true;
	}

	//------------------------------
	bool PhysicsModelLoader::begin__mass( const mass__AttributeData & attributeData )
	{
		getHandlingFilePartLoader()->addToSidTree( 0, attributeData.sid, &mRigidbodyStack.top()->isDynamic());
		return true;
	}

	//------------------------------
	bool PhysicsModelLoader::end__mass()
	{
		getHandlingFilePartLoader()->moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool PhysicsModelLoader::data__mass( const float value )
	{
		mRigidbodyStack.top()->setMass(value);
		//mHasTimeStep = true;
		return true;
	}
} // namespace COLLADASaxFWL
