/*
     Copyright (c) 2008-2009 NetAllied Systems GmbH
 
     This file is part of COLLADABaseUtils.
 
     Licensed under the MIT Open Source License, 
     for details please see LICENSE file or the website
     http://www.opensource.org/licenses/mit-license.php
 */


#ifndef __COLLADABU_HASH_MAP_H__
#define __COLLADABU_HASH_MAP_H__

#include "COLLADABUPrerequisites.h"
#include "COLLADABUPlatform.h"
// file to include the hash map platform independently

#ifdef COLLADABU_OS_WIN
    #if defined(_MSC_VER) && !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION) && !defined(_RWSTD_VER_STR) && !defined(_RWSTD_VER)
        #if _MSC_VER <= 1400
            #include <hash_map>
            #include <hash_set>

            #define COLLADABU_HASH_MAP stdext::hash_map
			#define COLLADABU_HASH_MULTIMAP stdext::hash_multimap
            #define COLLADABU_HASH_SET stdext::hash_set
            #define COLLADABU_HASH_NAMESPACE_OPEN stdext
            #define COLLADABU_HASH_NAMESPACE_CLOSE
            #define COLLADABU_HASH_FUN hash_compare     // Unfortunately stdext::hash_compare is not the same as std::hash...
        #elif _MSC_VER == 1500
            #include <unordered_map>
            #include <unordered_set>

            #define COLLADABU_HASH_MAP std::tr1::unordered_map
			#define COLLADABU_HASH_MULTIMAP std::tr1::unordered_multimap
            #define COLLADABU_HASH_SET std::tr1::unordered_set
            #define COLLADABU_HASH_NAMESPACE_OPEN std { namespace tr1
            #define COLLADABU_HASH_NAMESPACE_CLOSE }
            #define COLLADABU_HASH_FUN hash
        #else   // _MSC_VER >= 1600
            #include <unordered_map>
            #include <unordered_set>

			#define COLLADABU_HASH_MAP std::unordered_map
			#define COLLADABU_HASH_MULTIMAP std::unordered_multimap
            #define COLLADABU_HASH_SET std::unordered_set
            #define COLLADABU_HASH_NAMESPACE_OPEN std
            #define COLLADABU_HASH_NAMESPACE_CLOSE
            #define COLLADABU_HASH_FUN hash
        #endif
    #elif defined(__MINGW32__) || defined(__MINGW64__)
        #include <tr1/unordered_map>
        #include <tr1/unordered_set>

        #define COLLADABU_HASH_MAP std::tr1::unordered_map
        #define COLLADABU_HASH_MULTIMAP std::tr1::unordered_multimap
        #define COLLADABU_HASH_SET std::tr1::unordered_set
        #define COLLADABU_HASH_NAMESPACE_OPEN std { namespace tr1
        #define COLLADABU_HASH_NAMESPACE_CLOSE }
        #define COLLADABU_HASH_FUN hash
    #endif
#else   // Linux or Mac
    #if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 3)
        #include <ext/hash_map>
        #include <ext/hash_set>
        #include <ext/hash_fun.h>

        namespace __gnu_cxx     // Do we need these specializations under Windows (with _MSC_VER==1400 (VS2005) and namespace "stdext") as well?
        {
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

		#define COLLADABU_HASH_MAP __gnu_cxx::hash_map
		#define COLLADABU_HASH_MULTIMAP __gnu_cxx::hash_multimap
        #define COLLADABU_HASH_SET __gnu_cxx::hash_set
        #define COLLADABU_HASH_NAMESPACE_OPEN __gnu_cxx
        #define COLLADABU_HASH_NAMESPACE_CLOSE
        #define COLLADABU_HASH_FUN hash
    #else
        #include <tr1/unordered_map>
        #include <tr1/unordered_set>

		#define COLLADABU_HASH_MAP std::tr1::unordered_map
		#define COLLADABU_HASH_MULTIMAP std::tr1::unordered_multimap
        #define COLLADABU_HASH_SET std::tr1::unordered_set
        #define COLLADABU_HASH_NAMESPACE_OPEN std { namespace tr1
        #define COLLADABU_HASH_NAMESPACE_CLOSE }
        #define COLLADABU_HASH_FUN hash
    #endif
#endif

namespace COLLADABU
{
    // typedef COLLADABU_HASH_MAP<X, Y> hash_map<X, Y>;   // Unfortunately, this is not possible...
	template<class X, class Y>
	class hash_map : public COLLADABU_HASH_MAP<X,Y>
	{
	public:

		hash_map() {}
		hash_map(const hash_map& a) : COLLADABU_HASH_MAP<X,Y>(a) {}
		hash_map& operator = (const hash_map& a) { COLLADABU_HASH_MAP<X,Y>::operator = (*this, a); return this; }
	};

	template<class X, class Y>
	class hash_multimap : public COLLADABU_HASH_MULTIMAP<X,Y>
	{
	public:

		hash_multimap() {}
		hash_multimap(const hash_multimap& a) : COLLADABU_HASH_MULTIMAP<X,Y>(a) {}
		hash_multimap& operator = (const hash_multimap& a) { COLLADABU_HASH_MULTIMAP<X,Y>::operator = (*this, a); return this; }
	};

    template<class X>
    class hash_set : public COLLADABU_HASH_SET<X>
    {
        public:

        hash_set() {}
        hash_set(const hash_set& a) : COLLADABU_HASH_SET<X>(a) {}
        hash_set& operator = (const hash_set& a) { COLLADABU_HASH_SET<X>::operator = (*this, a); return this; }
    };
}

#endif // __COLLADABU_HASH_MAP_H__
