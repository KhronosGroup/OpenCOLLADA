/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaRotateHelper.h"
#include "COLLADAMayaSyntax.h"

#include "Math/COLLADABUMathUtils.h"


namespace COLLADAMaya
{

    // --------------------------------------------
    RotateHelper::RotateHelper( MEulerRotation rotation )
    :	rotation ( rotation )
    {
        createRotation ();
    }

    // --------------------------------------------
    void RotateHelper::createRotation ( )
    {
        switch (rotation.order)
        {
        case MEulerRotation::kXYZ: 
            createZ(0); createY(1); createX(2); 
            break;
        case MEulerRotation::kXZY: 
            createY(0); createZ(1); createX(2); 
            break;
        case MEulerRotation::kYXZ: 
            createZ(0); createX(1); createY(2); 
            break;
        case MEulerRotation::kYZX: 
            createX(0); createZ(1); createY(2); 
            break;
        case MEulerRotation::kZXY: 
            createY(0); createX(1); createZ(2); 
            break;
        case MEulerRotation::kZYX: 
            createX(0); createY(1); createZ(2); 
            break;
        default: 
            // Export XYZ euler rotation in Z Y X order in the file.
            // The rotation order is set to XYZ, Collada reads the parameter from behind.
            createZ(0); createY(1); createX(2); 
            break;
        }
    }

    // --------------------------------------------
    void RotateHelper::createX ( uint pos ) 
    {
        double axis[] = { 1, 0, 0, COLLADABU::Math::Utils::radToDeg ( rotation.x ) }; 
        std::vector<double> axisVec (axis, axis + sizeof(axis) / sizeof(double) );
        rotationMatrix.push_back ( axisVec );
        rotationParameters.push_back ( *X_PARAMETER );
//        rotationMatrix[pos] = { 0, 0, 1, COLLADABU::Math::Utils::radToDeg ( rotation.x ) }; 
    }

    // --------------------------------------------
    void RotateHelper::createY ( uint pos ) 
    {
        double axis[] = { 0, 1, 0, COLLADABU::Math::Utils::radToDeg ( rotation.y ) }; 
        std::vector<double> axisVec (axis, axis + sizeof(axis) / sizeof(double) );
        rotationMatrix.push_back ( axisVec );
        rotationParameters.push_back ( *Y_PARAMETER );
//        rotationMatrix[pos] = { 0, 0, 1, COLLADABU::Math::Utils::radToDeg ( rotation.y ) }; 
    }

    // --------------------------------------------
    void RotateHelper::createZ ( uint pos ) 
    { 
        double axis[] = { 0, 0, 1, COLLADABU::Math::Utils::radToDeg ( rotation.z ) }; 
        std::vector<double> axisVec (axis, axis + sizeof(axis) / sizeof(double) );
        rotationMatrix.push_back ( axisVec );
        rotationParameters.push_back ( *Z_PARAMETER );
//        rotationMatrix[pos] = { 0, 0, 1, COLLADABU::Math::Utils::radToDeg ( rotation.z ) }; 
    }

}