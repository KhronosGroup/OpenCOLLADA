/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLIFilePartLoader.h"
#include "COLLADASaxFWLLoader.h"


namespace COLLADASaxFWL
{

    //------------------------------
	IFilePartLoader::IFilePartLoader()
		: mPartLoader(0)
	{
	}
	
    //------------------------------
	IFilePartLoader::~IFilePartLoader()
	{
	}


	//-----------------------------
	COLLADAFW::IWriter* IFilePartLoader::writer()
	{
		return getColladaLoader()->writer();
	}

	//-----------------------------
	const COLLADAFW::UniqueId& IFilePartLoader::getUniqueId( const String& uriString, COLLADAFW::ClassId classId )
	{
		if ( !getColladaLoader() )
			return COLLADAFW::UniqueId::INVALID;
		
		COLLADABU::URI uri(getFileUri(), uriString);

		return getColladaLoader()->getUniqueId(uri, classId);
	}

	//-----------------------------
	COLLADAFW::UniqueId IFilePartLoader::getUniqueId( COLLADAFW::ClassId classId )
	{
		if ( !getColladaLoader() )
			return COLLADAFW::UniqueId::INVALID;

		return getColladaLoader()->getUniqueId(classId);
	}

	//-----------------------------
	void IFilePartLoader::deleteFilePartLoader()
	{
		if ( mPartLoader )
		{
			delete mPartLoader;
			mPartLoader = 0;
		}
	}

	//------------------------------
	void IFilePartLoader::setMeAsParser()
	{
		setParser(this);
	}

	GeometryMaterialIdInfo& IFilePartLoader::getMeshMaterialIdInfo( const COLLADAFW::UniqueId& uniqueId )
	{
		assert(getColladaLoader());
		return getColladaLoader()->getMeshMaterialIdInfo(uniqueId);
	}


} // namespace COLLADASaxFWL
