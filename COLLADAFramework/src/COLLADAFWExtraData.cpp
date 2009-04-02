/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWExtraData.h"


namespace COLLADAFW
{


	//------------------------------
	ExtraDataPair::ExtraDataPair( const String& key, const String& value )
		: mKey(key)
		, mValue(value)
	{
	}

	//------------------------------
	ExtraData::ExtraData()
	{
	}
	
    //------------------------------
	ExtraData::~ExtraData()
	{
	}


} // namespace COLLADAFW
