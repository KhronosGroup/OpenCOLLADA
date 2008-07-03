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
/*
* Interfaces between the collada classes and the Maya compatible structures
*/

#ifndef __COLLADA_MAYA_CONVERT_H__
#define __COLLADA_MAYA_CONVERT_H__

#ifndef _MFnAnimCurve
#include <maya/MFnAnimCurve.h>
#endif // _MFnAnimCurve

#include "ColladaMayaPrerequisites.h"
#include <COLLADAMayaPlatform.h>

namespace COLLADAMaya
{

    namespace MConvert
    {
        // Fills the two dimensional array @a copy with the values contained in @a original
        void convertMMatrixToDouble4x4 ( double copy[][4], const MMatrix& original );

        const char* toChar ( const MString& m );
    }
}

#endif // __COLLADA_MAYA_CONVERT_H__
