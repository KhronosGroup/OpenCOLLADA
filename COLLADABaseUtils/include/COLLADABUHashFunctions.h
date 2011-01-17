/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_HASHFUNCTIONS_H__
#define __COLLADABU_HASHFUNCTIONS_H__

#include "COLLADABUhash_map.h"
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


namespace COLLADABU_HASH_NAMESPACE_OPEN
{
    template<>
    struct COLLADABU_HASH_FUN<COLLADABU::URI>
    {
        size_t operator() (const COLLADABU::URI& uri) const { return COLLADABU::calculateHash(uri); }

#if defined(_MSC_VER) && _MSC_VER==1400
        static const size_t bucket_size=4;
        static const size_t min_buckets=8;

        bool operator() (const COLLADABU::URI& uri1, const COLLADABU::URI& uri2) const { return uri1<uri2; }
#endif
    };
} COLLADABU_HASH_NAMESPACE_CLOSE

#endif // __COLLADABU_HASHFUNCTIONS_H__
