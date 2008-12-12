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
	const COLLADAFW::UniqueId& IFilePartLoader::getUniqueId( const COLLADABU::URI& uri, COLLADAFW::ClassId classId )
	{
		if ( !getColladaLoader() )
			return COLLADAFW::UniqueId::INVALID;

		return getColladaLoader()->getUniqueId(uri, classId);
	}



} // namespace COLLADASaxFWL
