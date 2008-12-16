/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADASaxFrameworkLoader.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADABUURI.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWIWriter.h"

namespace COLLADASaxFWL
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
		mWriter = writer;
		FileLoader fileLoader(this, COLLADABU::URI::URI(COLLADABU::URI::nativePathToUri(fileName)));
		fileLoader.load();

		return true;
	}

} // namespace COLLADA
