/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_PREREQUISITES_H__
#define __COLLADABU_PREREQUISITES_H__

#include "COLLADABUPlatform.h"

#include <string>
#include <string.h>

#include "COLLADABUPlatform.h"

namespace COLLADABU
{
    typedef std::string String;
    typedef std::wstring WideString;
}

#define COLLADABU_HAVE_TR1_UNORDERED_MAP
#ifndef COLLADABU_OS_WIN
#if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 3)
#undef COLLADABU_HAVE_TR1_UNORDERED_MAP
#else
  #include <tr1/unordered_map>
  #include <tr1/unordered_set>
#endif
#else
#  undef COLLADABU_HAVE_TR1_UNORDERED_MAP
#  if defined(_MSC_VER) && (_MSC_VER >= 1500) \
   && defined(_MSC_FULL_VER) && \
   !defined(__SGI_STL_PORT) && \
   !defined(_STLPORT_VERSION) && \
   !defined(_RWSTD_VER_STR) && \
   !defined(_RWSTD_VER)
#    define COLLADABU_HAVE_TR1_UNORDERED_MAP
#    include <unordered_map>
#    include <unordered_set>
#else
#    define COLLADABU_HAVE_TR1_UNORDERED_MAP
#	 include <xhash>
#  endif
#endif
#ifndef COLLADABU_HAVE_TR1_UNORDERED_MAP
#  if defined(COLLADABU_OS_LINUX) || defined(COLLADABU_OS_MAC)
#   include <ext/hash_map>
#   include <ext/hash_set>
#  else
#   include <hash_map>
#   include <hash_set>
#  endif
#endif

#ifdef COLLADABU_HAVE_TR1_UNORDERED_MAP
//#  include 
#else
#  ifdef COLLADABU_OS_LINUX
#if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 3)
#   include <ext/hash_fun.h>
#else
#   include <backward/hash_fun.h>
#endif
#   include "COLLADABUURI.h"
#  elif (defined COLLADABU_OS_MAC)
#   include <ext/hash_fun.h>
#   include "COLLADABUURI.h"
#  endif
#endif

#ifndef COLLADABU_HAVE_TR1_UNORDERED_MAP
    namespace __gnu_cxx {

		template <>
        struct hash<std::string> 
        {
            size_t operator() (const std::string& x) const 
            {
                return hash<const char*>()(x.c_str());
            }
        };

        template < class _TYPE_ >
        struct hash< _TYPE_ *> 
        {
            typedef _TYPE_* TYPE_PTR;
            
            size_t operator() ( TYPE_PTR x) const 
            {
                return hash<intptr_t>()((intptr_t)x);
            }
        };
    }
#endif

#endif //__COLLADABU_PREREQUISITES_H__
