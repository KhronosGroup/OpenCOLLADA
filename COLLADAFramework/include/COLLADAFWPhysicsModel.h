/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_PHYSICSMODEL_H__
#define __COLLADAFW_PHYSICSMODEL_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTransformation.h"
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWRigidBody.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{
	typedef PointerArray<COLLADAFW::RigidBody> BodyPointerArray;
    /** A Physics model. It describes a Physics model, using the rigidBodies contained in mrigidBodies. The hierarchy 
	of the model is defines by a list of LinkBodyConnection that connect the bodies to a link. Since links do 
	not have any properties, they are simply described by numbers, starting from 0.  */
	class PhysicsModel : public ObjectTemplate<COLLADA_TYPE::PHYSICS_MODEL>
	{
	public:
		
		/** Returns the array containing all rigidbodies of the physics model.*/
		const BodyPointerArray& getBodies()	const { return mBodies; }

		/** Returns the array containing all rigidbodies of the physics model.*/
		BodyPointerArray& getBodies() { return mBodies; }
	
	private:

		/** The bodies used in the Physics model.*/
		BodyPointerArray mBodies;

		/**
		* The name attribute is the text string name of this element. 
		* Optional attribute.
		*/
		String mName;

		 /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;
		
		/**
        * The original object id, if it in the original file format exist. 
        */
        String mNodeName;
	
	public:

        /** Constructor. */
		PhysicsModel(const UniqueId& uniqueId):ObjectTemplate < COLLADA_TYPE::PHYSICS_MODEL > ( uniqueId )
		{}

        /** Destructor. */
		virtual ~PhysicsModel(){};

		/** Creates a clone of the PhysicsModel and returns a pointer to it.*/
		PhysicsModel* clone() const { return FW_NEW PhysicsModel(*this); }

		/** Sets the name of the model.*/
		void setName(const String& name) { mName = name; }

		const String& getName() const { return mName; }

		 /**
        * The original object id, if it in the original file format exist. 
        */
         void setOriginalId ( const String& val ) { mOriginalId = val; }

		 const String& getOriginalId ( ) const { return mOriginalId; }

	
    private:

        /** Disable default copy ctor. */
		PhysicsModel( const PhysicsModel& pre );

        /** Disable default assignment operator. */
		const PhysicsModel& operator= ( const PhysicsModel& pre );

	};

	typedef PointerArray<PhysicsModel> PhysicsModelArray;
	typedef PointerArray<COLLADAFW::RigidBody> BodyPointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_PHYSICSMODEL_H__
