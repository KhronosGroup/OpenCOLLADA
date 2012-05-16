/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWLoaderUtils.h"

namespace COLLADAFW
{
	//--------------------------------------------------------------------
	LoaderUtils::LoaderUtils()
	{
	}
	
	//--------------------------------------------------------------------
	LoaderUtils::~LoaderUtils()
	{
	}

	ObjectId LoaderUtils::getLowestObjectIdFor( ClassId classId )
	{
		ClassIdObjectIdMap::iterator it = mLowestObjectIdMap.find(classId);
		
		if ( it == mLowestObjectIdMap.end() )
		{
			mLowestObjectIdMap[classId] = 1;
			return 0;
		}
		else
		{
			return it->second++;
		}
	}

} // namespace COLLADAFW
