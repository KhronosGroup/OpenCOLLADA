/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_AXISINFO_H__
#define __COLLADAFW_AXISINFO_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWUniqueId.h"

namespace COLLADAFW
{
	class JointPrimitive;

    /** TODO Documentation */
	class AxisInfo 	
	{
	private:
		/** The joint primitive which axes is referenced by the AxisInfo.*/
		JointPrimitive* mJointPrimitive;

		/** True if the joint is active, false otherwise. Defaults to true.*/
		bool mIsActive;
	
		/** True if the joint is locked, false otherwise. Defaults to false.*/
		bool mIsLocked;

		/** The index of the axis in the roboter. 1-base, 0 meas unset.*/
		int mIndex;

	public:
		static const AxisInfo DEFAULT;

	public:

        /** Constructor. */
		AxisInfo();

		/** Constructor. */
//		AxisInfo(Target jointPrimitiveRef);

        /** Destructor. */
		virtual ~AxisInfo(){}

		/** The joint primitive which axes is referenced by the AxisInfo.*/
		JointPrimitive* getJointPrimitive() const { return mJointPrimitive; }

		/** The joint primitive which axes is referenced by the AxisInfo.*/
		void setJointPrimitive( JointPrimitive* jointPrimitive) { mJointPrimitive = jointPrimitive; }

		/** True if the joint is active, false otherwise .*/
		bool getIsActive() const { return mIsActive; }

		/** True if the joint is active, false otherwise .*/
		void setIsActive(bool isActive) { mIsActive = isActive; }

		/** True if the joint is locked, false otherwise .*/
		bool getIsLocked() const { return mIsLocked; }

		/** True if the joint is locked, false otherwise .*/
		void setIsLocked(bool isLocked) { mIsLocked = isLocked; }

		/** The index of the axis in the roboter. 1-base, 0 meas unset.*/
		int getIndex() const { return mIndex; }

		/** The index of the axis in the roboter. 1-base, 0 meas unset.*/
		void setIndex(int index) { mIndex = index; }

	};

	typedef ArrayPrimitiveType<AxisInfo> AxisInfoArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_AXISINFO_H__
