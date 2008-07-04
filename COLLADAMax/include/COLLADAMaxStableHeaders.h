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


#ifndef __COLLADAMAX_STABLE_HEADERS_H__
#define __COLLADAMAX_STABLE_HEADERS_H__


#ifdef MAX_9
#pragma message ("Compling for Max9")
#elif MAX_2008
#pragma message ("Compling for Max2008")
#elif MAX_2009
#pragma message ("Compling for Max2009")
#endif

#include <Max.h>
#include <istdplug.h>
#include <iparamb2.h>
#include <iparamm2.h>
#include <bitmap.h>    //for bitmap info
#include <triobj.h>
#include <MeshNormalSpec.h>
#include <modstack.h>   // for IDerivedObject
#include <cs/bipexp.h>   // for BipIface
#include <matrix3.h>
#include <stdmat.h>       // for standard material
#include <shaders.h>   // for shaders
#include <decomp.h>    // for decomposition of transformations
#include <simpobj.h>   //for SimpleObject2


#include <IDxMaterial.h>  // for IDxMaterial

//STL
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>


#endif //__COLLADAMAX_STABLE_HEADERS_H__
