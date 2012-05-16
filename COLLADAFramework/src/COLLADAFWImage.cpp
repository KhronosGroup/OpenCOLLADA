/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWImage.h"


namespace COLLADAFW
{

	//------------------------------
	Image::Image( const UniqueId& uniqueId)
		: ObjectTemplate< COLLADA_TYPE::IMAGE >(uniqueId)
		, mSourceType(SOURCE_TYPE_UNKNOWN)
		, mHeight(0)
		, mWidth(0)
		, mDepth(0)
	{
	}

	//------------------------------
	Image::~Image()
	{
	}

} // namespace COLLADAFW
