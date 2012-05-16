/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLInstanceArticulatedSystemLoader.h"


namespace COLLADASaxFWL
{

    //------------------------------
	InstanceArticulatedSystemLoader::InstanceArticulatedSystemLoader()
		: mInstanceArticulatedSystem(0)
		, mCurrentBind(0)
	{
	}

    //------------------------------
	InstanceArticulatedSystemLoader::~InstanceArticulatedSystemLoader()
	{
	}

	//------------------------------
	bool InstanceArticulatedSystemLoader::begin__bind____kinematics_bind_type( const bind____kinematics_bind_type__AttributeData& attributeData )
	{
		if ( !mInstanceArticulatedSystem )
		{
			return true;
		}
		mCurrentBind = new KinematicsBind();
		return true;
	}

	//------------------------------
	bool InstanceArticulatedSystemLoader::end__bind____kinematics_bind_type()
	{
		if ( !mInstanceArticulatedSystem )
		{
			return true;
		}
		mInstanceArticulatedSystem->addBind(mCurrentBind);
		mCurrentBind = 0;
		return true;
	}

	//------------------------------
	bool InstanceArticulatedSystemLoader::begin__param____kinematics_param_type( const param____kinematics_param_type__AttributeData& attributeData )
	{
		if ( !mInstanceArticulatedSystem || !mCurrentBind || !attributeData.ref)
		{
			return true;
		}
		mCurrentBind->setParamValue(attributeData.ref);
		return true;
	}

	//------------------------------
	void InstanceArticulatedSystemLoader::setInstanceArticulatedSystem( KinematicsInstanceArticulatedSystem* instanceArticulatedSystem )
	{
		mInstanceArticulatedSystem = instanceArticulatedSystem;
	}

	//------------------------------
	KinematicsInstanceArticulatedSystem* InstanceArticulatedSystemLoader::getInstanceArticulatedSystem()
	{
		return mInstanceArticulatedSystem;
	}

} // namespace COLLADASaxFWL
