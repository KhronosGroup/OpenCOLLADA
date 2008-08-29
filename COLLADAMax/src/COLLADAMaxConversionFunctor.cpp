/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxConversionFunctor.h"



namespace COLLADAMax
{

	ScaleConversionFunctor ConversionFunctors::radToDeg = ScaleConversionFunctor(COLLADA::MathUtils::RAD_TO_DEG_f);
	ScaleConversionFunctor ConversionFunctors::fromPercent = ScaleConversionFunctor( 0.01f );
	ScaleConversionFunctor ConversionFunctors::toPercent = ScaleConversionFunctor( 100 );

}
