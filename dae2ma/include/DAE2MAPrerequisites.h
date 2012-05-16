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

#ifndef __DAE2MA_PREREQUISITES_H__
#define __DAE2MA_PREREQUISITES_H__


#include <string>

#include "COLLADABUURI.h"
#include "COLLADABUNativeString.h"

#include "GeneratedSaxParser.h"


namespace DAE2MA
{
    typedef std::string String;
    typedef COLLADABU::URI URI;
	typedef COLLADABU::NativeString NativeString;

    typedef GeneratedSaxParser::StringHash StringHash;

    /** The default tolerance for double-sized floating-point comparison functions. */
#define DOUBLE_TOLERANCE 0.0e-12

    /** The default tolerance for single-sized floating-point comparison functions. */
#define FLOAT_TOLERANCE 0.0001f


#ifndef uint
    typedef unsigned int uint;
#endif

#ifndef NULL
    typedef 0 NULL
#endif

}

#endif // __DAE2MA_PREREQUISITES_H__
