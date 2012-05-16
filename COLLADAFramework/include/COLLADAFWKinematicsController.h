/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_KINEMATICSCONTROLLER_H__
#define __COLLADAFW_KINEMATICSCONTROLLER_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWMotionProfile.h"
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWAxisInfo.h"
#include "COLLADAFWTypes.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class KinematicsController 	: public ObjectTemplate<COLLADA_TYPE::KINEMATICS_CONTROLLER>
	{
	private:

		/** List of the unique ids of the kinematics models used in this controller.*/ 
		UniqueIdArray mKinematicsModelUniqueIds;

		/** The axis infos of the joints contained in the kinematics models controlled by this controller.
		Not all joints need to to have an axis info. If none is present for a specific joint, the default values
		apply.*/
		AxisInfoArray mAxisInfos;
		
		/** The motion profile of linear motion.*/
		MotionProfile mLinearMotionProfile;

		/** The motion profile of angular motion.*/
		MotionProfile mAngularMotionProfile;
	
	public:

        /** Constructor. */
		KinematicsController(const UniqueId& uniqueId);

        /** Destructor. */
		virtual ~KinematicsController();

		/** List of the unique ids of the kinematics models used in this controller.*/ 
		const UniqueIdArray& getKinematicsModelUniqueIds() const { return mKinematicsModelUniqueIds; }

		/** List of the unique ids of the kinematics models used in this controller.*/ 
		UniqueIdArray& getKinematicsModelUniqueIds() { return mKinematicsModelUniqueIds; }

		/** The axis infos of the joints contained in the kinematics models controlled by this controller.
		Not all joints need to to have an axis info. If none is present for a specific joint, the default values
		apply.*/
		const AxisInfoArray& getAxisInfos() const { return mAxisInfos; }

		/** The axis infos of the joints contained in the kinematics models controlled by this controller.
		Not all joints need to to have an axis info. If none is present for a specific joint, the default values
		apply.*/
		AxisInfoArray& getAxisInfos() { return mAxisInfos; }

		/** The motion profile of linear motion.*/
		const MotionProfile& getLinearMotionProfile() const { return mLinearMotionProfile; }

		/** The motion profile of linear motion.*/
		void setLinearMotionProfile(const MotionProfile& linearMotionProfile) { mLinearMotionProfile = linearMotionProfile; }

		/** The motion profile of angular motion.*/
		const MotionProfile& getAngularMotionProfile() const { return mAngularMotionProfile; }

		/** The motion profile of angular motion.*/
		void setAngularMotionProfile( const MotionProfile& angularMotionProfile) { mAngularMotionProfile = angularMotionProfile; }

		/** Creates a clone of the KinematicsController and returns a pointer to it.*/
		KinematicsController* clone() const { return FW_NEW KinematicsController(*this); }

	private:

        /** Disable default copy ctor. */
		KinematicsController( const KinematicsController& pre );

        /** Disable default assignment operator. */
		const KinematicsController& operator= ( const KinematicsController& pre );

	};

	typedef PointerArray<KinematicsController> KinematicsControllerArray;


} // namespace COLLADAFW

#endif // __COLLADAFW_KINEMATICSCONTROLLER_H__
