/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_JOINT_H__
#define __COLLADAFW_JOINT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWJointPrimitive.h"
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

    /** Represents a joint in the the kinematics model, consisting of one ore more joint primitives. */
	class Joint : public ObjectTemplate < COLLADA_TYPE::JOINT >
	{
	private:

		/** The original id, if present. */
		String mOriginalId;

		/** The name of the joint*/
		String mName;

		/** The joint primitives of the joint.*/
		JointPrimitivePointerArray mJointPrimitives;

	public:

        /** Constructor. */
		Joint( const UniqueId& uniqueId ) 
			: ObjectTemplate< COLLADA_TYPE::JOINT >(uniqueId){}

        /** Destructor. */
		virtual ~Joint(){}

		/** The original id, if present. */
		const String& getOriginalId () const { return mOriginalId; }

		/** The original id, if present. */
		void setOriginalId ( const String& originalId ) { mOriginalId = originalId; }

		/** Returns the name of the camera.*/
		const String& getName() const { return mName; }

		/** Sets the name of the camera.*/
		void setName(const String& name) { mName = name; }

		/** Returns the joint primitives of the joint.*/
		const JointPrimitivePointerArray& getJointPrimitives() const { return mJointPrimitives; }

		/** Returns the joint primitives of the joint.*/
		JointPrimitivePointerArray& getJointPrimitives() { return mJointPrimitives; }

		Joint* clone() { return FW_NEW Joint(*this); }

		/** Clones the joint, but uses the unique id given.*/
		Joint* clone( const UniqueId& uniqueId) 
		{ 
			Joint* joint = FW_NEW Joint(*this);
			joint->setUniqueId(uniqueId);
			return joint; 
		}

	};

	typedef PointerArray<Joint> JointPointerArray;



} // namespace COLLADAFW

#endif // __COLLADAFW_JOINT_H__
