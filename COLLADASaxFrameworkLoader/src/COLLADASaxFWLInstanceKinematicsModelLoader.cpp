/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLInstanceKinematicsModelLoader.h"
#include "COLLADASaxFWLKinematicsIntermediateData.h"


namespace COLLADASaxFWL
{

    //------------------------------
	InstanceKinematicsModelLoader::InstanceKinematicsModelLoader()
		:  mCurrentKinematicsInstanceKinematicsModel(0)
		, mCurrentKinematicsNewParam(0)
	{
	}
	
    //------------------------------
	InstanceKinematicsModelLoader::~InstanceKinematicsModelLoader()
	{
	}

	//------------------------------
	bool InstanceKinematicsModelLoader::begin__newparam____kinematics_newparam_type( const newparam____kinematics_newparam_type__AttributeData& attributeData )
	{
		if ( attributeData.sid )
		{
			mCurrentKinematicsNewParamSid = attributeData.sid;
		}
		return true;
	}

	//------------------------------
	bool InstanceKinematicsModelLoader::end__newparam____kinematics_newparam_type()
	{
		if ( mCurrentKinematicsInstanceKinematicsModel )
		{
			mCurrentKinematicsInstanceKinematicsModel->addKinematicsNewParam(mCurrentKinematicsNewParam);
		}
		mCurrentKinematicsNewParamSid.clear();
		mCurrentKinematicsNewParam = 0;
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::begin__float()
	{
		mCurrentKinematicsNewParam = new KinematicsNewParam(KinematicsNewParam::VALUETYPE_FLOAT);
		mCurrentKinematicsNewParam->setName(mCurrentKinematicsNewParamSid);
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::end__float()
	{
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::data__float( float value )
	{
		mCurrentKinematicsNewParam->setDoubleValue( value );
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::begin__int()
	{
		mCurrentKinematicsNewParam = new KinematicsNewParam(KinematicsNewParam::VALUETYPE_INT);
		mCurrentKinematicsNewParam->setName(mCurrentKinematicsNewParamSid);
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::end__int()
	{
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::data__int( int value )
	{
		mCurrentKinematicsNewParam->setIntValue( value );
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::begin__bool()
	{
		mCurrentKinematicsNewParam = new KinematicsNewParam(KinematicsNewParam::VALUETYPE_BOOL);
		mCurrentKinematicsNewParam->setName(mCurrentKinematicsNewParamSid);
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::end__bool()
	{
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::data__bool( bool value )
	{
		mCurrentKinematicsNewParam->setBoolValue( value );
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::begin__SIDREF()
	{
		mCurrentKinematicsNewParam = new KinematicsNewParam(KinematicsNewParam::VALUETYPE_SIDREF);
		mCurrentKinematicsNewParam->setName(mCurrentKinematicsNewParamSid);
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::end__SIDREF()
	{
		mCurrentKinematicsNewParam->setSidrefValue( mSidRefString );
		mSidRefString.clear();
		return true;
	}

	//-----------------------------------------------------------------
	bool InstanceKinematicsModelLoader::data__SIDREF( const ParserChar* value, size_t length )
	{
		mSidRefString.append( value, length );
		return true;
	}



} // namespace COLLADASaxFWL
