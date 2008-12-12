/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADADomHelper.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADADHStableHeaders.h"
#include "COLLADADHLoader.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWIWriter.h"

namespace COLLADADH
{
	//---------------------------------
	Loader::Loader()
	{
	}

    //---------------------------------
	Loader::~Loader()
	{
	}


   
    //---------------------------------
	const COLLADAFW::UniqueId& Loader::getUniqueId( const COLLADABU::URI& uri, COLLADAFW::ClassId classId )
	{
		URIUniqueIdMap::iterator it = mURIUniqueIdMap.find(uri);
		if ( it == mURIUniqueIdMap.end() )
		{
			return mURIUniqueIdMap[uri] = COLLADAFW::UniqueId(classId, mLoaderUtil.getLowestObjectIdFor(classId));
		}
		else
		{
			return it.second();
		}
	}

	//---------------------------------
	bool Loader::loadDocument( const String& fileName, COLLADAFW::IWriter* writer )
	{
		if ( !writer )
			return false;

		return true;
	}

} // namespace COLLADA
