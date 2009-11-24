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

#if defined(COLLADABU_OS_LINUX) || defined(COLLADABU_OS_MAC)
#   include <backward/hash_fun.h>
#   include "COLLADABUURI.h"
#endif



namespace COLLADABU
{
	class URI;


	size_t calculateHash(const String& str);

	size_t calculateHash(const char* str);

	size_t calculateHash(const URI& uri);

} // namespace COLLADABU

#if defined(COLLADABU_OS_LINUX) || defined(COLLADABU_OS_MAC)

_GLIBCXX_BEGIN_NAMESPACE(__gnu_cxx)

 template<>
    struct hash<COLLADABU::URI>
    {
      size_t
      operator()(const COLLADABU::URI& uri) const
      { return COLLADABU::calculateHash(uri); }
    };

_GLIBCXX_END_NAMESPACE

#endif


#endif // __COLLADABU_HASHFUNCTIONS_H__
