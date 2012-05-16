/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_PREREQUISITES_H__
#define __COLLADASTREAMWRITER_PREREQUISITES_H__

#include <string>
#include "COLLADABUURI.h"
#include "COLLADABUNativeString.h"
#include "Math/COLLADABUMathUtils.h"


namespace COLLADASW
{
    typedef COLLADABU::URI URI;
    typedef COLLADABU::Utils Utils;
    typedef COLLADABU::NativeString NativeString;
    typedef COLLADABU::Math::Utils MathUtils;

    typedef std::string String;
	typedef std::wstring WideString;
}

#endif //__COLLADASTREAMWRITER_PREREQUISITES_H__
