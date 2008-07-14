/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
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
