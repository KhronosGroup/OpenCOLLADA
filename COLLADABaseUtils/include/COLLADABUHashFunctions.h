/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_HASHFUNCTIONS_H__
#define __COLLADABU_HASHFUNCTIONS_H__

#include "COLLADABUPrerequisites.h"
#include "COLLADABUPlatform.h"
#include "COLLADABUURI.h"
  

namespace COLLADABU
{
	size_t calculateHash(const String& str);

	/** Converts all lower case ASCII caracters to the corresponding upper case character befor calculating the hash.*/
	size_t calculateHashUpper(const String& str);

	size_t calculateHash(const char* str);

	/** Converts all lower case ASCII caracters to the corresponding upper case character befor calculating the hash.*/
	size_t calculateHashUpper(const char* str);

	size_t calculateHash(const URI& uri);
	inline size_t calculateHashU(const URI& uri){
		return calculateHash(uri);
	}

} // namespace COLLADABU

#if defined(COLLADABU_HAVE_TR1_UNORDERED_MAP) || defined(COLLADABU_OS_LINUX) || defined(COLLADABU_OS_MAC)
#if defined(COLLADABU_HAVE_TR1_UNORDERED_MAP)
namespace std { namespace tr1
#else
namespace __gnu_cxx
#endif
{
	template<>
	struct hash<COLLADABU::URI>
	{
		size_t
			operator()(const COLLADABU::URI& uri) const
		{ return COLLADABU::calculateHash(uri); }
	};
#if defined(COLLADABU_HAVE_TR1_UNORDERED_MAP)
}
#endif
} // namespace __gnu_cxx
#endif


#endif // __COLLADABU_HASHFUNCTIONS_H__
