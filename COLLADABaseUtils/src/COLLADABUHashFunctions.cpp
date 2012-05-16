/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "COLLADABUHashFunctions.h"
#include "COLLADABUURI.h"
#include "COLLADABUStringUtils.h"

namespace COLLADABU
{
	size_t calculateHash( const String& str )
	{
		return calculateHash(str.c_str());
	}

	size_t calculateHashUpper( const String& str )
	{
		return calculateHashUpper(str.c_str());
	}

	size_t calculateHash( const char* str )
	{
		unsigned long h = 0;
		unsigned long g;
		const char* pos = str;

		while (*pos != 0) {
			h = (h << 4) + *pos++;
			if ((g = (h & 0xf0000000)) != 0)
				h ^= g >> 24;
			h &= ~g;
		}
		return h;
	}

	size_t calculateHashUpper( const char* str )
	{
		unsigned long h = 0;
		unsigned long g;
		const char* pos = str;

		while (*pos != 0) {
			h = (h << 4) + StringUtils::toUpperASCIIChar(*pos++);
			if ((g = (h & 0xf0000000)) != 0)
				h ^= g >> 24;
			h &= ~g;
		}
		return h;
	}

	size_t calculateHash( const URI& uri )
	{
		return calculateHash(uri.getURIString());
	}



} // namespace COLLADABU
