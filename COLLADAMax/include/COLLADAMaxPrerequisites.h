/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_PREREQUISITES_H__
#define __COLLADAMAX_PREREQUISITES_H__

#define UNUSED(a) /**< Removes a piece of code during the pre-process. This macro is useful for these pesky unused variable warnings. */

#include "maxversion.h"


#if ( MAX_VERSION_MAJOR >= 7 )
#  define MAX_7_OR_NEWER
#endif
#if ( MAX_VERSION_MAJOR == 7 )
#  define MAX_7
#endif

#if ( MAX_VERSION_MAJOR >= 8 )
#  define MAX_8_OR_NEWER
#endif
#if ( MAX_VERSION_MAJOR == 8 )
#  define MAX_8
#endif

#if ( MAX_VERSION_MAJOR >= 9 )
#  define MAX_9_OR_NEWER
#endif
#if ( MAX_VERSION_MAJOR == 9 )
#  define MAX_9
#endif

#if ( MAX_VERSION_MAJOR >= 10 )
#  define MAX_2008_OR_NEWER
#endif
#if ( MAX_VERSION_MAJOR == 10 )
#  define MAX_2008
#endif

#if ( MAX_VERSION_MAJOR >= 11 )
#  define MAX_2009_OR_NEWER
#endif
#if ( MAX_VERSION_MAJOR == 11 )
#  define MAX_2009
#endif

#if ( MAX_VERSION_MAJOR >= 12 )
#  define MAX_2010_OR_NEWER
#endif
#if ( MAX_VERSION_MAJOR == 12 )
#  define MAX_2010
#endif

#if ( MAX_VERSION_MAJOR >= 13 )
#  define MAX_2011_OR_NEWER
#endif
#if ( MAX_VERSION_MAJOR == 13 )
#  define MAX_2011
#endif

#if ( MAX_VERSION_MAJOR >= 14 )
#  define MAX_2012_OR_NEWER
#endif
#if ( MAX_VERSION_MAJOR == 14 )
#  define MAX_2012
#endif

// Max 2009 requires RTTI to be enabled
#ifdef MAX_2009_OR_NEWER
#ifndef _CPPRTTI
#error "Max 2009 or newer requires RTTI to be enabled. Please enable and try again..."
#endif
#endif


#define TIME_INITIAL_POSE  0
//#define TIME_EXPORT_START  0//OPTS->AnimStart()


#include <string>
#include "COLLADABUURI.h"
#include "COLLADABUStringUtils.h"
#include "COLLADABUNativeString.h"
#include "Math/COLLADABUMathUtils.h"


namespace COLLADAMax
{
    typedef COLLADABU::URI URI;
    typedef COLLADABU::Utils Utils;
    typedef COLLADABU::StringUtils StringUtils;
    typedef COLLADABU::NativeString NativeString;
    typedef COLLADABU::Math::Utils MathUtils;

    typedef std::string String;
    typedef std::wstring WideString;
}



#endif //__COLLADAMAX_PREREQUISITES_H__
