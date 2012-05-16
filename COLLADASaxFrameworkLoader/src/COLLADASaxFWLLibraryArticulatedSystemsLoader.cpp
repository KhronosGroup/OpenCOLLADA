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
		COLLADABU::URI uri(getFileUri());
		uri.setFragment( mCurrentArticulatedId );
		mCurrentKinematicsController = new KinematicsController( uri, mCurrentArticulatedName );
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
		COLLADABU::URI absoluteUrl(getFileUri(), attributeData.url.getURIString());
		instanceKinematicsModels.push_back(KinematicsInstanceKinematicsModel(absoluteUrl)); 
		KinematicsInstanceKinematicsModel * instanceKinematicsModel = &instanceKinematicsModels.back();
		addToSidTree( 0, attributeData.sid, instanceKinematicsModel);
		mInstanceKinematicsModelLoader.setCurrentInstanceKinematicsModel(instanceKinematicsModel);
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::end__instance_kinematics_model()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::begin__newparam____kinematics_newparam_type( const newparam____kinematics_newparam_type__AttributeData& attributeData )
	{
		mValueElementParentType = VALUE_ELEMENT_NEWPARAM;
		return mInstanceKinematicsModelLoader.begin__newparam____kinematics_newparam_type(attributeData);
	}

	//------------------------------
	bool LibraryArticulatedSystemsLoader::end__newparam____kinematics_newparam_type()
	{
		mValueElementParentType = VALUE_ELEMENT_NONE;
		return mInstanceKinematicsModelLoader.end__newparam____kinematics_newparam_type();
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::begin__float()
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				return mInstanceKinematicsModelLoader.begin__float();
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__float()
	{
		return mInstanceKinematicsModelLoader.end__float();
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::data__float( float value )
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mInstanceKinematicsModelLoader.data__float(value);
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
				mInstanceKinematicsModelLoader.begin__int();
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__int()
	{
		mInstanceKinematicsModelLoader.end__int();
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::data__int( int value )
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mInstanceKinematicsModelLoader.data__int(value);
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
				mInstanceKinematicsModelLoader.begin__bool();
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::end__bool()
	{
		mInstanceKinematicsModelLoader.end__bool();
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::data__bool( bool value )
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mInstanceKinematicsModelLoader.data__bool(value);
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
				mInstanceKinematicsModelLoader.begin__SIDREF();
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
				mInstanceKinematicsModelLoader.end__SIDREF();
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryArticulatedSystemsLoader::data__SIDREF( const ParserChar* value, size_t length )
	{
		mInstanceKinematicsModelLoader.data__SIDREF(value, length);
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
