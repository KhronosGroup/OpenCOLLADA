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
		return true;
	}

	//------------------------------
	bool LibraryKinematicsScenesLoader::end__kinematics_scene()
	{
		getFileLoader()->addKinematicsScene( mCurrentKinematicsScene );
		mCurrentKinematicsScene = 0;
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

} // namespace COLLADASaxFWL
