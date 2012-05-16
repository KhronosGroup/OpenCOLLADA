/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_CONVERSION_H__
#define __DAE2MA_CONVERSION_H__

#include "DAE2MAPrerequisites.h"

#include "Math/COLLADABUMathMatrix4.h"
#include "Math/COLLADABUMathUtils.h"


namespace DAE2MA
{

    /*
    * Transform the input matrix and convert it in a double[4][4] matrix.
    */
    static void convertMatrix4ToTransposedDouble4x4 ( 
        double outputMatrix[][4], 
        const COLLADABU::Math::Matrix4& inputMatrix, 
        const double tolerance )
    {
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][0],tolerance)) outputMatrix[0][0] = 0.0;
        else outputMatrix[0][0] = inputMatrix[0][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][1],tolerance)) outputMatrix[1][0] = 0.0;
        else outputMatrix[1][0] = inputMatrix[0][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][2],tolerance)) outputMatrix[2][0] = 0.0;
        else outputMatrix[2][0] = inputMatrix[0][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[0][3],tolerance)) outputMatrix[3][0] = 0.0;
        else outputMatrix[3][0] = inputMatrix[0][3];

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][0],tolerance)) outputMatrix[0][1] = 0.0;
        else outputMatrix[0][1] = inputMatrix[1][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][1],tolerance)) outputMatrix[1][1] = 0.0;
        else outputMatrix[1][1] = inputMatrix[1][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][2],tolerance)) outputMatrix[2][1] = 0.0;
        else outputMatrix[2][1] = inputMatrix[1][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[1][3],tolerance)) outputMatrix[3][1] = 0.0;
        else outputMatrix[3][1] = inputMatrix[1][3];

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][0],tolerance)) outputMatrix[0][2] = 0.0;
        else outputMatrix[0][2] = inputMatrix[2][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][1],tolerance)) outputMatrix[1][2] = 0.0;
        else outputMatrix[1][2] = inputMatrix[2][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][2],tolerance)) outputMatrix[2][2] = 0.0;
        else outputMatrix[2][2] = inputMatrix[2][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[2][3],tolerance)) outputMatrix[3][2] = 0.0;
        else outputMatrix[3][2] = inputMatrix[2][3];

        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][0],tolerance)) outputMatrix[0][3] = 0.0;
        else outputMatrix[0][3] = inputMatrix[3][0];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][1],tolerance)) outputMatrix[1][3] = 0.0;
        else outputMatrix[1][3] = inputMatrix[3][1];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][2],tolerance)) outputMatrix[2][3] = 0.0;
        else outputMatrix[2][3] = inputMatrix[3][2];
        if (COLLADABU::Math::Utils::equalsZero(inputMatrix[3][3],tolerance)) outputMatrix[3][3] = 0.0;
        else outputMatrix[3][3] = inputMatrix[3][3];
    }

}

#endif // __DAE2MA_CONVERSION_H__

