/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	//------------------------------
	void ExtraData::appendExtraData( const ExtraDataArray& extraData )
	{
		mExtraDataArray.appendValues(extraData);
	}

	//------------------------------
	void ExtraData::appendExtraData( const ExtraData& extraData )
	{
		appendExtraData(extraData.getExtraDataArray());
	}

} // namespace COLLADAFW
