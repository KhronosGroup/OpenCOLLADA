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

#if defined(COLLADABU_OS_LINUX) || defined(COLLADABU_OS_MAC)
#	include <ext/hash_map>
#else
#	include <hash_map>
#endif

// file to include the hah map platform independent

namespace COLLADABU
{

#if defined(COLLADABU_OS_LINUX) || defined(COLLADABU_OS_MAC)
	using namespace __gnu_cxx;
#else
	using namespace stdext;
#endif



} // namespace COLLADABU

#endif // __COLLADABU_HASH_MAP_H__
