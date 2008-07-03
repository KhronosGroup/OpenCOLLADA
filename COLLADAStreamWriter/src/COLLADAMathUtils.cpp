/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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