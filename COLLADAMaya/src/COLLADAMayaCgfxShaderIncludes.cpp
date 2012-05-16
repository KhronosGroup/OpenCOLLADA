/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"

#ifdef _WIN32
# pragma warning(disable: 4312)
#endif

// make this compileable under linux
#ifdef LINUX
#   define RedHat8_
#endif

#include "cgfxAttrDef.cpp"
#if MAYA_API_VERSION > 800
#include "cgfxEffectDef.cpp"
/* We undef the macros defined "cgfxEffectDef.cpp" to avoid compiler warning in "cgfxShaderNode.cpp"*/
#ifdef _WIN32
#else
#   undef stricmp
#   undef strnicmp 
#endif

#endif // MAYA_API_VERSION > 800
#include "cgfxFindImage.cpp"
#include "cgfxShaderCmd.cpp"
#include "cgfxShaderNode.cpp"
#include "cgfxVector.cpp"
#include "nv_dds.cpp"

#if MAYA_API_VERSION >= 201200
#include "cgfxProfile.cpp"
#include "cgfxPassStateSetter.cpp"
#endif

#ifdef _WIN32
# pragma warning(default: 4312)
#endif

