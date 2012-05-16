/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MOTIONPROFILE_H__
#define __COLLADAFW_MOTIONPROFILE_H__

#include "COLLADAFWPrerequisites.h"

#include <limits>


namespace COLLADAFW
{

    /** A profile that restricts the motion ( velocity and its derivatives). */
	class MotionProfile 	
	{
	private:

		/** The maximal allowed speed. Always positive. Set to NaN if not restricted.*/
		float mReferenceSpeed;

		/** The maximal allowed acceleration. Always positive. Set to NaN if not restricted.*/
		float mReferenceAcceleration;

		/** The maximal allowed deceleration. Always positive. Set to NaN if not restricted.*/
		float mReferenceDeceleration; 

		/** The maximal allowed jerk. Always positive. Set to NaN if not restricted.*/
		float mReferenceJerk;

	public:

        /** Constructor. */
		MotionProfile()
			: mReferenceSpeed(std::numeric_limits<float>::quiet_NaN())
			, mReferenceAcceleration(std::numeric_limits<float>::quiet_NaN())
			, mReferenceDeceleration(std::numeric_limits<float>::quiet_NaN())
			, mReferenceJerk(std::numeric_limits<float>::quiet_NaN())
		{}

        /** Destructor. */
		virtual ~MotionProfile(){}


		/** Returns the maximal allowed speed. Always positive. Set to NaN if not restricted.*/
		float getReferenceSpeed() const { return mReferenceSpeed; }

		/** Sets the maximal allowed speed. Always positive. Set to NaN if not restricted.*/
		void setReferenceSpeed(float referenceSpeed) { mReferenceSpeed = referenceSpeed; }

		/** Returns the maximal allowed acceleration. Always positive. Set to NaN if not restricted.*/
		float getReferenceAcceleration() const { return mReferenceAcceleration; }

		/** Sets the maximal allowed acceleration. Always positive. Set to NaN if not restricted.*/
		void setReferenceAcceleration(float referenceAcceleration) { mReferenceAcceleration = referenceAcceleration; }

		/** Returns the maximal allowed deceleration. Always positive. Set to NaN if not restricted.*/
		float getReferenceDeceleration() const { return mReferenceDeceleration; }

		/** Sets the maximal allowed deceleration. Always positive. Set to NaN if not restricted.*/
		void setReferenceDeceleration(float referenceDeceleration) { mReferenceDeceleration = referenceDeceleration; }

		/** Returns the maximal allowed jerk. Always positive. Set to NaN if not restricted.*/
		float getReferenceJerk() const { return mReferenceJerk; }

		/** Sets the maximal allowed jerk. Always positive. Set to NaN if not restricted.*/
		void setReferenceJerk(float val) { mReferenceJerk = val; }
	};

} // namespace COLLADAFW

#endif // __COLLADAFW_MOTIONPROFILE_H__
