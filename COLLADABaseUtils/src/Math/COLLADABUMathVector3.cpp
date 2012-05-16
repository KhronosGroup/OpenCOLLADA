/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADABaseUtils.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABUStableHeaders.h"
#include "Math/COLLADABUMathVector3.h"


namespace COLLADABU
{

    namespace Math
    {
        const Vector3 Vector3::ZERO( 0, 0, 0 );

        const Vector3 Vector3::UNIT_X( 1, 0, 0 );
        const Vector3 Vector3::UNIT_Y( 0, 1, 0 );
        const Vector3 Vector3::UNIT_Z( 0, 0, 1 );
        const Vector3 Vector3::NEGATIVE_UNIT_X( -1, 0, 0 );
        const Vector3 Vector3::NEGATIVE_UNIT_Y( 0, -1, 0 );
        const Vector3 Vector3::NEGATIVE_UNIT_Z( 0, 0, -1 );
        const Vector3 Vector3::UNIT_SCALE( 1, 1, 1 );
    }
}
