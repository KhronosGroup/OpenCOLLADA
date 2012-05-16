/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_JOINTPRIMITIVE_H__
#define __COLLADAFW_JOINTPRIMITIVE_H__

#include "COLLADAFWPrerequisites.h"
#include "Math/COLLADABUMathVector3.h"
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWMotionProfile.h"
#include "COLLADAFWObject.h"

#include <limits>

namespace COLLADAFW
{

    /** Represents a joint primitive ( prismatic or revolute ) in the kinematics model.*/
	class JointPrimitive : public ObjectTemplate < COLLADA_TYPE::JOINTPRIMITIVE >
	{
	public:
		/** The types of a joint primitive.*/
		enum Type { PRISMATIC, REVOLUTE };

	private:

		/** Type of the joint primitive.*/
		Type mType;

		/** Axis of the joint primitive.*/
		COLLADABU::Math::Vector3 mAxis;

		/** The hard minimal limit of the joint primitive. Not set if set to NaN. Might be -infinity. */
		float mHardLimitMin;

		/** The hard maximal limit of the joint primitive. Not set if set to NaN. Might be +infinity. */
		float mHardLimitMax;

		/** The soft minimal limit of the joint primitive. Not set if set to NaN. Might be -infinity. */
		float mSoftLimitMin;

		/** The soft maximal limit of the joint primitive. Not set if set to NaN. Might be +infinity. */
		float mSoftLimitMax;

		/** The MotionProfile that restricts the motion of the joint.*/
		MotionProfile mMotionProfile;
	
	public:

        /** Constructor. */
		JointPrimitive( const UniqueId& uniqueId, Type type )
			: ObjectTemplate < COLLADA_TYPE::JOINTPRIMITIVE >( uniqueId )
			, mType(type)
			, mHardLimitMin(std::numeric_limits<float>::quiet_NaN())
			, mHardLimitMax(std::numeric_limits<float>::quiet_NaN())
			, mSoftLimitMin(std::numeric_limits<float>::quiet_NaN())
			, mSoftLimitMax(std::numeric_limits<float>::quiet_NaN())
		{}

        /** Destructor. */
		virtual ~JointPrimitive(){}

		/** Returns the type of the joint primitive.*/
		Type getType() const { return mType; }

		/** Returns the axis of the joint primitive.*/
		const COLLADABU::Math::Vector3& getAxis() const { return mAxis; }

		/** Returns the axis of the joint primitive.*/
		COLLADABU::Math::Vector3& getAxis() { return mAxis; }

		/** Sets the axis of the joint primitive.*/
		void setAxis(const COLLADABU::Math::Vector3& axis) { mAxis = axis; }

		/** Returns the hard minimal limit of the joint primitive. Not set if set to NaN. Might be -infinity. */
		float getHardLimitMin() const { return mHardLimitMin; }

		/** Sets the hard minimal limit of the joint primitive. Not set if set to NaN. Might be -infinity. */
		void setHardLimitMin(float hardLimitMin) { mHardLimitMin = hardLimitMin; }
		
		/** Returns the hard maximal limit of the joint primitive. Not set if set to NaN. Might be +infinity. */
		float getHardLimitMax() const { return mHardLimitMax; }

		/** Sets the hard maximal limit of the joint primitive. Not set if set to NaN. Might be +infinity. */
		void setHardLimitMax(float hardLimitMax) { mHardLimitMax = hardLimitMax; }

		/** Returns the soft minimal limit of the joint primitive. Not set if set to NaN. Might be -infinity. */
		float getSoftLimitMin() const { return mSoftLimitMin; }

		/** Returns the soft minimal limit of the joint primitive. Not set if set to NaN. Might be -infinity. */
		void setSoftLimitMin(float softLimitMin) { mSoftLimitMin = softLimitMin; }

		/** Returns the soft maximal limit of the joint primitive. Not set if set to NaN. Might be +infinity. */
		float getSoftLimitMax() const { return mSoftLimitMax; }

		/** Set the soft maximal limit of the joint primitive. Not set if set to NaN. Might be +infinity. */
		void setSoftLimitMax(float softLimitMax) { mSoftLimitMax = softLimitMax; }

		/** Returns the MotionProfile that restricts the motion of the joint.*/
		const MotionProfile& getMotionProfile() const { return mMotionProfile; }

		/** Sets the MotionProfile that restricts the motion of the joint.*/
		void setMotionProfile(MotionProfile motionProfile) { mMotionProfile = motionProfile; }

		JointPrimitive* clone() { return FW_NEW JointPrimitive(*this); }

	};

	typedef PointerArray<JointPrimitive> JointPrimitivePointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_JOINTPRIMITIVE_H__
