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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaConvert.h"

namespace COLLADAMaya
{

    namespace MConvert
    {
        //---------------------------------------------------------------
        void convertMMatrixToDouble4x4 ( double copy[][4], const MMatrix& original )
        {
            copy[0][0] = original[0][0];
            copy[1][0] = original[0][1];
            copy[2][0] = original[0][2];
            copy[3][0] = 0;
            copy[0][1] = original[1][0];
            copy[1][1] = original[1][1];
            copy[2][1] = original[1][2];
            copy[3][1] = 0;
            copy[0][2] = original[2][0];
            copy[1][2] = original[2][1];
            copy[2][2] = original[2][2];
            copy[3][2] = 0;
            copy[0][3] = original[3][0];
            copy[1][3] = original[3][1];
            copy[2][3] = original[3][2];
            copy[3][3] = 1;
        }

        //---------------------------------------------------------------
        const char* toChar ( const MString& m )
        {
#if MAYA_API_VERSION >= 850
            return ( char* ) m.asWChar();
#else // MAYA_API_VERSION >= 850
            return m.asChar();
#endif // MAYA_API_VERSION >= 850
        }
    }

}