/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_STABLE_HEADERS_H__
#define __DAE2MA_STABLE_HEADERS_H__

//
// Precompiled Header
//

#define _CRT_SECURE_NO_DEPRECATE 1


#include "DAE2MASyntax.h"

//STL
#include <vector>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>
#include <map>
//#include <hash_map>

#include "COLLADASaxFWLColladaParserAutoGen15Attributes.h"

// base utils
#include <COLLADABU.h>

// Framework
#include <COLLADAFW.h>


#ifdef WIN32
#elif WIN64
#elif (defined(MAC_PLUGIN) || defined (OSMac_))
#elif defined(LINUX)

#else
#error "Unsupported platform"
#endif //all platforms..

#ifndef UINT_MAX
#define UINT_MAX 0xFFFFFFFF
#endif

#ifndef INT_MAX
#define INT_MAX 0x7FFFFFFF
#endif

#endif // __DAE2MA_STABLE_HEADERS_H__
