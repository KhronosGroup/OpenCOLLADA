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
// file to include the hash map platform independent

namespace COLLADABU
{


#ifdef COLLADABU_HAVE_TR1_UNORDERED_MAP
    using namespace std::tr1;

	template<class X, class Y > 
	class hash_map : public std::tr1::unordered_map<X,Y>
	{ public:
	hash_map(){}
	hash_map(const hash_map&a):std::tr1::unordered_map<X,Y>(a){}
	hash_map&operator=(const hash_map&a){std::tr1::unordered_map<X,Y>::operator=(*this,a);return this;}
	};

	template<class X> 
	class hash_set : public std::tr1::unordered_set<X>
	{ public:
	hash_set(){}
	hash_set(const hash_set&a):std::tr1::unordered_set<X>(a){}
	hash_set&operator=(const hash_set&a){std::tr1::unordered_set<X>::operator=(*this,a);return this;}
	};
#else
#  if defined(COLLADABU_OS_LINUX) || defined(COLLADABU_OS_MAC)
	using namespace __gnu_cxx;
#  else
	using namespace stdext;
#  endif
#endif


} // namespace COLLADABU

#endif // __COLLADABU_HASH_MAP_H__
