/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWKinematicsModel.h"


namespace COLLADAFW
{

    //------------------------------
	KinematicsModel::KinematicsModel(const UniqueId& uniqueId)
		: ObjectTemplate<COLLADA_TYPE::KINEMATICS_MODEL>(uniqueId)
		, mBaseLinks(SizeTValuesArray::OWNER)
	{
	}

	//------------------------------
	KinematicsModel::KinematicsModel( const KinematicsModel& pre )
		: ObjectTemplate<COLLADA_TYPE::KINEMATICS_MODEL>(pre)
		, mJoints(pre.mJoints)
		, mLinkJointConnections(pre.mLinkJointConnections)
		, mBaseLinks(SizeTValuesArray::OWNER)
	{

	}


    //------------------------------
	KinematicsModel::~KinematicsModel()
	{
	}

	//------------------------------
	const KinematicsModel& KinematicsModel::operator=( const KinematicsModel& pre )
	{
		ObjectTemplate<COLLADA_TYPE::KINEMATICS_MODEL>::operator=(pre);
		mJoints = pre.mJoints;
		mLinkJointConnections = pre.mLinkJointConnections;
		pre.mBaseLinks.cloneArray(mBaseLinks);
		return *this;
	}

} // namespace COLLADAFW
