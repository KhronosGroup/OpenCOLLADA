/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryArticulatedSystemsLoader.h"
#include "COLLADASaxFWLKinematicsIntermediateData.h"
#include "COLLADASaxFWLFileLoader.h"


namespace COLLADASaxFWL
{

    //------------------------------
	LibraryArticulatedSystemsLoader::LibraryArticulatedSystemsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentKinematicsController(0)
		, mCurrentKinematicsInstanceKinematicsModel(0)
		, mValueElementParentType(VALUE_ELEMENT_NONE)
		, mCurrentAxisInfo(0)
	{

	}

    //------------------------------
	LibraryArticulatedSystemsLoader::~LibraryArticulatedSystemsLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& LibraryArticulatedSystemsLoader::getUniqueId ()
    {
        // TODO No uniqueId!
        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	bool LibraryArticulatedSystemsLoader::end__library_articulated_systems()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::begin__articulated_system( const articulated_system__AttributeData& attributeData )
	{
		if ( attributeData.id ) 
		{
			mCurrentArticulatedId = attributeData.id;
		}
		if ( attributeData.name )
		{
			mCurrentArticulatedName = attributeData.name;
		}
		else if ( attributeData.id )
		{
			mCurrentArticulatedName = attributeData.id;
		}

		addToSidTree( attributeData.id, 0);
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::end__articulated_system()
	{
		mCurrentArticulatedId.clear();
		mCurrentArticulatedName.clear();
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::begin__kinematics()
	{
		mCurrentKinematicsController = new KinematicsController( mCurrentArticulatedId, mCurrentArticulatedName );
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::end__kinematics()
	{
		getFileLoader()->addKinematicsController(mCurrentKinematicsController);
		mCurrentKinematicsController = 0;
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::begin__instance_kinematics_model( const instance_kinematics_model__AttributeData& attributeData )
	{
		KinematicsInstanceKinematicsModels& instanceKinematicsModels = mCurrentKinematicsController->getKinematicsInstanceKinematicsModels();
		instanceKinematicsModels.push_back(KinematicsInstanceKinematicsModel(attributeData.url)); 
		mCurrentKinematicsInstanceKinematicsModel = &instanceKinematicsModels.back();
		addToSidTree( 0, attributeData.sid, mCurrentKinematicsInstanceKinematicsModel);
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::end__instance_kinematics_model()
	{
		moveUpInSidTree();
		mCurrentKinematicsInstanceKinematicsModel = 0;
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::begin__newparam____kinematics_newparam_type( const newparam____kinematics_newparam_type__AttributeData& attributeData )
	{
		mValueElementParentType = VALUE_ELEMENT_NEWPARAM;
		if ( attributeData.sid )
		{
			mCurrentKinematicsNewParamSid = attributeData.sid;
		}
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::end__newparam____kinematics_newparam_type()
	{
		mCurrentKinematicsInstanceKinematicsModel->getKinematicsNewParams().push_back(mCurrentKinematicsNewParam);
		mValueElementParentType = VALUE_ELEMENT_NONE;
		mCurrentKinematicsNewParamSid.clear();
		mCurrentKinematicsNewParam = 0;
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::begin__float()
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mCurrentKinematicsNewParam = new KinematicsNewParam(KinematicsNewParam::VALUETYPE_FLOAT);
				mCurrentKinematicsNewParam->setName(mCurrentKinematicsNewParamSid);
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__float()
	{
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::data__float( float value )
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mCurrentKinematicsNewParam->setDoubleValue( value );
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::begin__int()
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mCurrentKinematicsNewParam = new KinematicsNewParam(KinematicsNewParam::VALUETYPE_INT);
				mCurrentKinematicsNewParam->setName(mCurrentKinematicsNewParamSid);
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__int()
	{
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::data__int( int value )
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mCurrentKinematicsNewParam->setIntValue( value );
				break;
			}
		case VALUE_ELEMENT_INDEX:
			{
				mCurrentAxisInfo->setIndex(value);
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::begin__bool()
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mCurrentKinematicsNewParam = new KinematicsNewParam(KinematicsNewParam::VALUETYPE_BOOL);
				mCurrentKinematicsNewParam->setName(mCurrentKinematicsNewParamSid);
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__bool()
	{
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::data__bool( bool value )
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mCurrentKinematicsNewParam->setBoolValue( value );
				break;
			}
		case VALUE_ELEMENT_AKTIVE:
			{
				mCurrentAxisInfo->setIsActive(value);
				break;
			}
		case VALUE_ELEMENT_LOCKED:
			{
				mCurrentAxisInfo->setIsLocked(value);
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::begin__SIDREF()
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mCurrentKinematicsNewParam = new KinematicsNewParam(KinematicsNewParam::VALUETYPE_SIDREF);
				mCurrentKinematicsNewParam->setName(mCurrentKinematicsNewParamSid);
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__SIDREF()
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mCurrentKinematicsNewParam->setSidrefValue( mSidRefString );
				mSidRefString.clear();
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::data__SIDREF( const ParserChar* value, size_t length )
	{
		mSidRefString.append( value, length );
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::begin__axis_info____kinematics_axis_info_type( const axis_info____kinematics_axis_info_type__AttributeData& attributeData )
	{
		if ( attributeData.axis )
		{
			mCurrentKinematicsController->getAxisInfos().push_back(AxisInfo(SidAddress(String(attributeData.axis))));
			mCurrentAxisInfo = &mCurrentKinematicsController->getAxisInfos().back();
			addToSidTree( 0, attributeData.sid );
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__axis_info____kinematics_axis_info_type()
	{
		if ( mCurrentAxisInfo )
		{
			moveUpInSidTree();
		}
		mCurrentAxisInfo = 0;
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::begin__active()
	{
		if ( mCurrentAxisInfo )
		{
			mValueElementParentType = VALUE_ELEMENT_AKTIVE;
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__active()
	{
		mValueElementParentType = VALUE_ELEMENT_NONE;
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::begin__locked()
	{
		if ( mCurrentAxisInfo )
		{
			mValueElementParentType = VALUE_ELEMENT_LOCKED;
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__locked()
	{
		mValueElementParentType = VALUE_ELEMENT_NONE;
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::begin__index( const index__AttributeData& attributeData )
	{
		if ( mCurrentAxisInfo )
		{
			mValueElementParentType = VALUE_ELEMENT_INDEX;
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__index()
	{
		mValueElementParentType = VALUE_ELEMENT_NONE;
		return true;
	}


} // namespace COLLADASaxFWL
