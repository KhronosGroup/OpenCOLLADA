/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWKinematicsController.h"


namespace COLLADAFW
{

    //------------------------------
	KinematicsController::KinematicsController(const UniqueId& uniqueId)
		: ObjectTemplate<COLLADA_TYPE::KINEMATICS_CONTROLLER>(uniqueId)
		, mKinematicsModelUniqueIds(UniqueIdArray::OWNER)
		, mAxisInfos(AxisInfoArray::OWNER)
	{
	}

	//------------------------------
	KinematicsController::KinematicsController( const KinematicsController& pre )
		: ObjectTemplate<COLLADA_TYPE::KINEMATICS_CONTROLLER>(pre)
		, mKinematicsModelUniqueIds(UniqueIdArray::OWNER)
		, mAxisInfos(AxisInfoArray::OWNER)
		, mLinearMotionProfile(pre.mLinearMotionProfile)
		, mAngularMotionProfile(pre.mAngularMotionProfile)
	{

	}


    //------------------------------
	KinematicsController::~KinematicsController()
	{
	}

	//------------------------------
	const KinematicsController& KinematicsController::operator=( const KinematicsController& pre )
	{
		ObjectTemplate<COLLADA_TYPE::KINEMATICS_CONTROLLER>::operator=(pre);
		pre.mKinematicsModelUniqueIds.cloneArray(mKinematicsModelUniqueIds);
		pre.mAxisInfos.cloneArray(mAxisInfos);
		mLinearMotionProfile = pre.mLinearMotionProfile;
		mAngularMotionProfile = pre.mAngularMotionProfile;
		return *this;
	}

} // namespace COLLADAFW
