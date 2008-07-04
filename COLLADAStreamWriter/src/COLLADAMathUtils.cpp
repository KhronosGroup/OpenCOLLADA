/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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