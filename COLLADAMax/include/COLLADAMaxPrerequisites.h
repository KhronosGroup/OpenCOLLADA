/*
    Copyright (c) 2008 NetAllied Systems GmbH

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


// Max 2009 requires RTTI to be enabled
#ifdef MAX_2009_OR_NEWER
#ifndef _CPPRTTI
#error "Max 2009 or newer requires RTTI to be enabled. Please enable and try again..."
#endif
#endif


#define TIME_INITIAL_POSE  0
//#define TIME_EXPORT_START  0//OPTS->AnimStart()


#include "COLLADASWPrerequisites.h"
#include "COLLADASWNativeString.h"

namespace COLLADAMax
{
	typedef COLLADASW::String String;
	typedef COLLADASW::WideString WideString;
	typedef COLLADASW::NativeString NativeString;

}



#endif //__COLLADAMAX_PREREQUISITES_H__
