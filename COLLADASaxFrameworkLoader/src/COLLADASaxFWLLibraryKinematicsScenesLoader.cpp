/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryKinematicsScenesLoader.h"
#include "COLLADASaxFWLFileLoader.h"


namespace COLLADASaxFWL
{

	//------------------------------
	LibraryKinematicsScenesLoader::LibraryKinematicsScenesLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentKinematicsScene(0)
		, mInstanceArticulatedSystemLoader()
	{}


    //------------------------------
	LibraryKinematicsScenesLoader::~LibraryKinematicsScenesLoader()
	{
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::end__library_kinematics_scenes()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::begin__kinematics_scene( const kinematics_scene__AttributeData& attributeData )
	{
		COLLADABU::URI uri(getFileUri());
		if ( attributeData.id )
		{
			uri.setFragment( attributeData.id );
		}

		const char* name = 0;
		if ( attributeData.name )
		{
			name = attributeData.name;
		}
		else if ( attributeData.id )
		{
			name = attributeData.id;
		}

		mCurrentKinematicsScene = new KinematicsScene(uri, name);
		addToSidTree(attributeData.id, 0);
		return true;
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::end__kinematics_scene()
	{
		getFileLoader()->addKinematicsScene( mCurrentKinematicsScene );
		mCurrentKinematicsScene = 0;
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::begin__instance_articulated_system( const instance_articulated_system__AttributeData& attributeData )
	{
		COLLADABU::URI absoluteUrl(getFileUri(), attributeData.url.getURIString());

		KinematicsInstanceArticulatedSystem* instanceArticulatedSystem = new KinematicsInstanceArticulatedSystem(absoluteUrl);
		mInstanceArticulatedSystemLoader.setInstanceArticulatedSystem(instanceArticulatedSystem);
		return true;
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::end__instance_articulated_system()
	{
		mCurrentKinematicsScene->addInstanceArticulatedSystem(mInstanceArticulatedSystemLoader.getInstanceArticulatedSystem());
		return true;
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::begin__bind____kinematics_bind_type( const bind____kinematics_bind_type__AttributeData& attributeData )
	{
		return mInstanceArticulatedSystemLoader.begin__bind____kinematics_bind_type(attributeData);
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::end__bind____kinematics_bind_type()
	{
		return mInstanceArticulatedSystemLoader.end__bind____kinematics_bind_type();
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::begin__param____kinematics_param_type( const param____kinematics_param_type__AttributeData& attributeData )
	{
		return mInstanceArticulatedSystemLoader.begin__param____kinematics_param_type( attributeData );
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::end__param____kinematics_param_type()
	{
		return mInstanceArticulatedSystemLoader.end__param____kinematics_param_type();
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::begin__instance_kinematics_model( const instance_kinematics_model__AttributeData& attributeData )
	{
		KinematicsInstanceKinematicsModels& instanceKinematicsModels = mCurrentKinematicsScene->getKinematicsInstanceKinematicsModels();
		COLLADABU::URI absoluteUrl(getFileUri(), attributeData.url.getURIString());
		instanceKinematicsModels.push_back(KinematicsInstanceKinematicsModel(absoluteUrl)); 
		KinematicsInstanceKinematicsModel * instanceKinematicsModel = &instanceKinematicsModels.back();
		addToSidTree( 0, attributeData.sid, instanceKinematicsModel);
		mInstanceKinematicsModelLoader.setCurrentInstanceKinematicsModel(instanceKinematicsModel);
		return true;
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::end__instance_kinematics_model()
	{
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::begin__newparam____kinematics_newparam_type( const newparam____kinematics_newparam_type__AttributeData& attributeData )
	{
		mValueElementParentType = VALUE_ELEMENT_NEWPARAM;
		return mInstanceKinematicsModelLoader.begin__newparam____kinematics_newparam_type(attributeData);
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::end__newparam____kinematics_newparam_type()
	{
		mValueElementParentType = VALUE_ELEMENT_NONE;
		return mInstanceKinematicsModelLoader.end__newparam____kinematics_newparam_type();
	}

	//-----------------------------------------------------------------
	bool LibraryKinematicsScenesLoader::begin__float()
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
	bool LibraryKinematicsScenesLoader::end__float()
	{
		return mInstanceKinematicsModelLoader.end__float();
	}

	//-----------------------------------------------------------------
	bool LibraryKinematicsScenesLoader::data__float( float value )
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
	bool LibraryKinematicsScenesLoader::begin__int()
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
	bool LibraryKinematicsScenesLoader::end__int()
	{
		mInstanceKinematicsModelLoader.end__int();
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryKinematicsScenesLoader::data__int( int value )
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mInstanceKinematicsModelLoader.data__int(value);
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryKinematicsScenesLoader::begin__bool()
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
	bool LibraryKinematicsScenesLoader::end__bool()
	{
		mInstanceKinematicsModelLoader.end__bool();
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryKinematicsScenesLoader::data__bool( bool value )
	{
		switch ( mValueElementParentType )
		{
		case VALUE_ELEMENT_NEWPARAM:
			{
				mInstanceKinematicsModelLoader.data__bool(value);
				break;
			}
		}
		return true;
	}

	//-----------------------------------------------------------------
	bool LibraryKinematicsScenesLoader::begin__SIDREF()
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
	bool LibraryKinematicsScenesLoader::end__SIDREF()
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
	bool LibraryKinematicsScenesLoader::data__SIDREF( const ParserChar* value, size_t length )
	{
		mInstanceKinematicsModelLoader.data__SIDREF(value, length);
		return true;
	}


} // namespace COLLADASaxFWL
