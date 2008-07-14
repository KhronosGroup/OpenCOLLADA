/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAMathUtils.h"


namespace COLLADA
{

    const double MathUtils::COLLADA_PI = 3.1415926535;
    const float MathUtils::COLLADA_PI_f = 3.1415926535f;

    /*
    const double MathUtils::TWOPI = 2 * PI;
    const double MathUtils::HALFPI = 0.5 * PI;
    */
    const double MathUtils::COLLADA_DEG_TO_RAD = COLLADA_PI/180.0;
    const double MathUtils::COLLADA_RAD_TO_DEG = 180.0/COLLADA_PI;

    const float MathUtils::DEG_TO_RAD_f = COLLADA_PI_f/180.0f;
    const float MathUtils::RAD_TO_DEG_f = 180.0f/COLLADA_PI_f;

}