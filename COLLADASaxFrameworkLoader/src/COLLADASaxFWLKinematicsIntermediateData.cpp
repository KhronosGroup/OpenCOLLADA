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
	KinematicsModel::KinematicsModel( const COLLADABU::URI& url, const char* name )
		: mUrl(url)
		, mName(name)
		, mSidTreeNode(0)
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
		deleteMap(mKinematicsModels);

		// delete kinematic controllers
		deleteMap(mKinematicsControllers);

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
	void KinematicsSidrefOrParam::setParamValue( const String& paramValue )
	{
		deleteAll(); 
		mValue._param = new String(paramValue); 
		mValueType = VALUETYPE_PARAM;
	}

	//------------------------------
	void KinematicsSidrefOrParam::setSidrefValue( const SidAddress& sidrefValue )
	{
		deleteAll(); 
		mValue._sidref = new SidAddress(sidrefValue); 
		mValueType = VALUETYPE_SIDREF;
	}

	//------------------------------
	void KinematicsSidrefOrParam::deleteSidRef()
	{
		if ( mValueType == VALUETYPE_SIDREF)
		{
			delete mValue._sidref;
			mValue._sidref = 0;
		}
	}

	//------------------------------
	void KinematicsSidrefOrParam::deleteParam()
	{
		if ( mValueType == VALUETYPE_PARAM)
		{
			delete mValue._param;
			mValue._param = 0;
		}
	}

	//------------------------------
	void KinematicsSidrefOrParam::deleteAll()
	{
		deleteSidRef();
		deleteParam();
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

	//------------------------------
	void KinematicsInstanceKinematicsModel::addKinematicsNewParam( KinematicsNewParam* newParam )
	{
		const String& name = newParam->getName();
		mKinematicsNewParams.insert(std::make_pair(name, newParam));
	}

	//------------------------------
	KinematicsNewParam* KinematicsInstanceKinematicsModel::getNewParamBySid( const String& sid ) const
	{
		KinematicsNewParams::const_iterator it =  mKinematicsNewParams.find(sid);
		if ( it != mKinematicsNewParams.end() )
		{
			return it->second;
		}
		else
		{
			return 0;
		}
	}

} // namespace COLLADASaxFWL
