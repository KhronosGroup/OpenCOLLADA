/*
    Copyright (c) 2015 Starbreeze

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryPhysicsModels.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
	LibraryPhysicsModels::LibraryPhysicsModels(COLLADASW::StreamWriter * streamWriter)
            : Library( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_PHYSICS_MODELS )
    {}


	void LibraryPhysicsModels::openRigidBody(const String & rbSId, const String & rbName)
	{
		mCurrentRigidBodyCloser = mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY);

		if (!rbSId.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, rbSId);

		if (!rbName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, rbName);
	}

	void LibraryPhysicsModels::openTechniqueCommon()
	{
		mCurrentTechniqueCommonCloser = mSW->openElement(CSWC::CSW_ELEMENT_TECHNIQUE_COMMON);
	}


	void LibraryPhysicsModels::addDynamic(bool dynamic)
	{
		//Dynamic
		mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_DYNAMIC);
		mSW->appendValues(dynamic);
		mSW->closeElement();
	}

	void LibraryPhysicsModels::addMass(float mass)
	{
		//Mass
		mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_MASS);
		mSW->appendValues(mass);
		mSW->closeElement();
	}

	void LibraryPhysicsModels::addInertia(float x, float y, float z)
	{
		//Inertia
		mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_INERTIA);
		mSW->appendValues(x, y, z);
		mSW->closeElement();
	}
	
	void LibraryPhysicsModels::openShape()
	{
		mCurrentShapeCloser =  mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE);
	}

	void LibraryPhysicsModels::closeShape()
	{
		mCurrentShapeCloser.close();
	}

	void LibraryPhysicsModels::AddBoxShape(float x, float y, float z)
	{
		mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_BOX);
		mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_BOX_EXTENTS);
		mSW->appendValues(x, y, z);
		mSW->closeElement();
		mSW->closeElement();
	}

	void LibraryPhysicsModels::AddCapsuleShape(float radiusX, float radiusY, float radiusZ, float height)
	{
		mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_CAPSULE);
		
		mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_CAPSULE_HEIGHT);
		mSW->appendValues(height);
		mSW->closeElement();
		
		mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_CAPSULE_RADIUS);
		mSW->appendValues(radiusX, radiusY, radiusZ);
		mSW->closeElement();
		
		mSW->closeElement();
	}

	void LibraryPhysicsModels::AddConvexMeshShape(const String &convexHullOf)
	{
        // This is not correct
		//mSW->openElement(CSWC::CSW_ELEMENT_RIGID_BODY_SHAPE_CONVEX_MESH);
		//if (!convexHullOf.empty())
		//	mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_CONVEX_HULL_OF, String("#") + convexHullOf);
		//mSW->closeElement();
	}

	void LibraryPhysicsModels::addTranslate(const String &sid, float x, float y, float z) const 
	{
		mSW->openElement(CSWC::CSW_ELEMENT_TRANSLATE);

		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);

		mSW->appendValues(x, y, z);
		mSW->closeElement();
	}


	void LibraryPhysicsModels::addRotate(const String &sid, double x, double y, double z, double angle) const
	{
		mSW->openElement(CSWC::CSW_ELEMENT_ROTATE);

		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);

		mSW->appendValues(x, y, z, angle);

		mSW->closeElement();
	}

	void LibraryPhysicsModels::closeTechniqueCommon()
	{
		mCurrentTechniqueCommonCloser.close();
	}

	void LibraryPhysicsModels::closeRigidBody()
	{
		mCurrentRigidBodyCloser.close();
	}

    //---------------------------------------------------------------
	void LibraryPhysicsModels::openPhysicsModel(const String & id, const String & name)
    {
        openLibrary();
		mCurrentPhysicsModelCloser = mSW->openElement(CSWC::CSW_ELEMENT_PHYSICS_MODEL);

        if( !id.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_ID, id );

        if( !name.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_NAME, name );
    }

    //---------------------------------------------------------------
	void LibraryPhysicsModels::closePhysicsModel()
    {
		mCurrentPhysicsModelCloser.close();
    }


} //namespace COLLADASW
