/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADABU_MATH_PREREQUISITES_H__
#define __COLLADABU_MATH_PREREQUISITES_H__

#include <math.h>

#undef PI
#undef HALF_PI

namespace COLLADABU
{
    namespace Math
    {
        typedef double Real;
		const double PI = Real( 4.0 * atan( 1.0 ) );
		const double HALF_PI = PI / 2;

    }
}


#endif //__COLLADABU_MATH_PREREQUISITES_H__
