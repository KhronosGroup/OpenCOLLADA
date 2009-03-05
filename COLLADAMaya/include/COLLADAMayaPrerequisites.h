/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_PREREQUISITES_H__
#define __COLLADA_MAYA_PREREQUISITES_H__

/**< Removes a piece of code during the pre-process.
This macro is useful for these pesky unused variable warnings. */
#define UNUSED(a)

#include <string>

#include "COLLADABUURI.h"
#include "COLLADABUNativeString.h"

namespace COLLADAMaya
{
    typedef std::string String;
    typedef COLLADABU::URI URI;
	typedef COLLADABU::NativeString NativeString;

#ifndef uint
    typedef unsigned int uint;
#endif

#ifndef NULL
    typedef 0 NULL
#endif

//
// Helper Macro
//
#define CHECK_STAT(X) \
    if ( (X) != MS::kSuccess) { \
    MGlobal::displayError ( status.errorString() ); \
    }

//
// Helper Macro
//
#define CHECK_STATUS(rc, errorString) \
    if ((rc) != MStatus::kSuccess)\
    {\
    MGlobal::displayError(MString(errorString));\
    return MObject::kNullObj;\
    }\


//#ifndef max
//#define max(a,b)            (((a) > (b)) ? (a) : (b))
//#endif

//#ifndef min
//#define min(a,b)            (((a) < (b)) ? (a) : (b))
//#endif
}

#endif // __COLLADA_MAYA_PREREQUISITES_H__
