/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADASWStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASWMathUtils.h"


namespace COLLADASW
{

    const double MathUtils::COLLADASW_PI = 3.1415926535;
    const float MathUtils::COLLADASW_PI_f = 3.1415926535f;

    /*
    const double MathUtils::TWOPI = 2 * PI;
    const double MathUtils::HALFPI = 0.5 * PI;
    */
    const double MathUtils::COLLADASW_DEG_TO_RAD = COLLADASW_PI/180.0;
    const double MathUtils::COLLADASW_RAD_TO_DEG = 180.0/COLLADASW_PI;

    const float MathUtils::DEG_TO_RAD_f = COLLADASW_PI_f/180.0f;
    const float MathUtils::RAD_TO_DEG_f = 180.0f/COLLADASW_PI_f;

}