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
