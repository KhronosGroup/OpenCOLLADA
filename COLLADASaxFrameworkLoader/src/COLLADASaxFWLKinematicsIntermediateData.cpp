/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLKinematicsIntermediateData.h"
#include "COLLADASaxFWLUtils.h"

#include "COLLADAFWJoint.h"


namespace COLLADASaxFWL
{

	//------------------------------
	KinematicsModel::KinematicsModel( const COLLADABU::URI& uri, const char* name )
		: mUri(uri)
		, mName(name)
	{
	}

	//------------------------------
	KinematicsModel::~KinematicsModel()
	{
		// delete base links
		deleteVector(mBaseLinks);
	}

	//------------------------------
	KinematicsIntermediateData::KinematicsIntermediateData()
	{
	}
	

	//------------------------------
	KinematicsBind::KinematicsBind( ValueType valueType ) : mValueType(valueType)
	{
		switch ( mValueType )
		{
		case VALUETYPE_BOOL: 
			mValue._bool = true;
			break;
		case VALUETYPE_FLOAT: 
			mValue._double = 0;
			break;
		case VALUETYPE_INT: 
			mValue._int = 0;
			break;
		case VALUETYPE_SIDREF: 
			mValue._sidref = 0;
			break;
		case VALUETYPE_PARAM: 
			mValue._param = 0;
			break;
		}
	}

	//------------------------------
	KinematicsBind::KinematicsBind( ) : mValueType(VALUETYPE_UNKNOWN)
	{}

	//------------------------------
	KinematicsInstanceArticulatedSystem::~KinematicsInstanceArticulatedSystem()
	{
		// delete kinematic binds
		deleteVector(mKinematicsBinds);
	}

    //------------------------------
	KinematicsIntermediateData::~KinematicsIntermediateData()
	{
		// delete joints
		deleteVectorFW(mJoints);

		// delete joint instances
		deleteVectorFW(mInstanceJoints);

		// delete kinematic models
		deleteVector(mKinematicsModels);

		// delete kinematic controllers
		deleteVector(mKinematicsControllers);

		// delete  instance kinematics scenes
		deleteVector(mInstanceKinematicsScenes);
	}

	//------------------------------
	KinematicsScene::~KinematicsScene()
	{
		// delete kinematics instance articulated systems
		deleteVector(mKinematicsInstanceArticulatedSystems);
	}

	//------------------------------
	void KinematicsScene::addInstanceArticulatedSystem( KinematicsInstanceArticulatedSystem* kinematicsInstanceArticulatedSystem )
	{
		mKinematicsInstanceArticulatedSystems.push_back( kinematicsInstanceArticulatedSystem );
	}

	//------------------------------
	KinematicsSidrefOrParam::KinematicsSidrefOrParam( ValueType axisType )
	{
		switch ( mValueType )
		{
		case VALUETYPE_SIDREF: 
			mValue._sidref = 0;
			break;
		case VALUETYPE_PARAM: 
			mValue._param = 0;
			break;
		}
	}

	//------------------------------
	KinematicsFloatOrParam::KinematicsFloatOrParam( ValueType axisType )
	{
		switch ( mValueType )
		{
		case VALUETYPE_FLOAT: 
			mValue._float = std::numeric_limits<float>::quiet_NaN();
			break;
		case VALUETYPE_PARAM: 
			mValue._param = 0;
			break;
		}
	}

	//------------------------------
	KinematicsInstanceKinematicsScene::~KinematicsInstanceKinematicsScene()
	{
		// delete BindJointAxes
		deleteVector(mBindJointAxes);
	}

} // namespace COLLADASaxFWL
