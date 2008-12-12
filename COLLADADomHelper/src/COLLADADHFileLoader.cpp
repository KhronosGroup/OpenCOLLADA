/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADADHStableHeaders.h"
#include "COLLADADHFileLoader.h"
#include "COLLADADHLoader.h"

#include "COLLADAFWObject.h"

namespace COLLADADH
{

    //-----------------------------
	FileLoader::FileLoader ( Loader* colladaLoader, const COLLADABU::URI& fileURI)
         : mColladaLoader(colladaLoader),
		 mFileURI(fileURI)
	{
	}
	
    //-----------------------------
	FileLoader::~FileLoader()
	{
	}


	const COLLADAFW::UniqueId& FileLoader::getUniqueId( const COLLADABU::URI& uri, COLLADAFW::ClassId classId )
	{
		if ( !getColladaLoader() )
			return COLLADAFW::UniqueId::INVALID;
		
		return getColladaLoader()->getUniqueId(uri, classId);
	}

	COLLADAFW::IWriter* FileLoader::writer()
	{
		COLLADAFW::Object<0>* d;
		COLLADAFW::Object<1>* d1;
		d = d1;
		return getColladaLoader()->writer();
	}

} // namespace COLLADADH
