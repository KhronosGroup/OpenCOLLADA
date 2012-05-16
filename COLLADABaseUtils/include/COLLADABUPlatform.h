/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADABaseUtils.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADABU_PLATTFORM_H__
#define __COLLADABU_PLATTFORM_H__


#if (defined(__APPLE__) || defined(OSMac_)) && (defined(__GNUC__) || defined(__xlC__) || defined(__xlc__)) || defined(__APPLE_CC__) 
#  define COLLADABU_OS_MAC
#  ifdef __LP64__
#    define COLLADABU_OS_MAC64
#  else
#    define COLLADABU_OS_MAC32
#  endif
#elif (defined(WIN64) || defined(_WIN64) || defined(__WIN64__))
#  define COLLADABU_OS_WIN64
#elif (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
#  define COLLADABU_OS_WIN32
#elif defined(__linux__) || defined(__linux)
#  define COLLADABU_OS_LINUX
#endif

#if defined(COLLADABU_OS_WIN32) || defined(COLLADABU_OS_WIN64)
#  define COLLADABU_OS_WIN
#endif

// from ogre OgrePlatform.h
// Win32 compilers use _DEBUG for specifying debug builds.
// Unlike the Win32 compilers, Linux compilers seem to use DEBUG for when
// specifying a debug build.
// (??? this is wrong, on Linux debug builds aren't marked in any way unless
// you mark it yourself any way you like it -- zap ???)
#if defined(_DEBUG) || defined(DEBUG)
#     define COLLADABU_DEBUG 
#endif

#include <cassert>

#if defined(COLLADABU_DEBUG)
#	define COLLADABU_ASSERT(cond) assert(cond);
#else
#	define COLLADABU_ASSERT(cond) 
#endif


#endif //__COLLADABU_PLATTFORM_H__
