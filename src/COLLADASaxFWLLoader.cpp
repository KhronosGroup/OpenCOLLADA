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

#include <sys/types.h>
#include <sys/timeb.h>
#include <fstream>

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
		_timeb startTimeBuffer;
		_ftime( &startTimeBuffer );
		double startTime = (double)startTimeBuffer.time + (double)startTimeBuffer.millitm / 1000;


		FileLoader fileLoader(this, COLLADABU::URI::URI(COLLADABU::URI::nativePathToUri(fileName)));
		fileLoader.load();

		_timeb endTimeBuffer;
		_ftime(&endTimeBuffer);

		std::ofstream s;
		s.open("c:\\temp\\out");
		double endTime = (double)endTimeBuffer.time + (double)endTimeBuffer.millitm / 1000;

		s << endTime - startTime;

		return true;
	}

} // namespace COLLADA
