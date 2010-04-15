/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_HASHFUNCTIONS_H__
#define __COLLADAFW_HASHFUNCTIONS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADABUPlatform.h"

#ifdef COLLADABU_OS_LINUX
#	include <backward/hash_fun.h>
#   include "COLLADAFWUniqueId.h"
#elif (defined COLLADABU_OS_MAC)
#	include <ext/hash_fun.h>
#   include "COLLADAFWUniqueId.h"
#endif

#if defined(COLLADABU_HAVE_TR1_UNORDERED_MAP) || defined(COLLADABU_OS_LINUX) || defined(COLLADABU_OS_MAC)
#if defined(COLLADABU_HAVE_TR1_UNORDERED_MAP)
namespace std { namespace tr1
#else
namespace __gnu_cxx
#endif
{
    template<>
    struct hash<COLLADAFW::UniqueId>
    {
        size_t
            operator()(const COLLADAFW::UniqueId& uniqueId) const { return uniqueId; }
    };
#if defined(COLLADABU_HAVE_TR1_UNORDERED_MAP)
}
#endif
} // namespace __gnu_cxx
#endif

#endif // __COLLADAFW_HASHFUNCTIONS_H__
