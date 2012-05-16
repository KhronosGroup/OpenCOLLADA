/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAMaxStableHeaders.h"

#include "COLLADAMaxConversionFunctor.h"



namespace COLLADAMax
{

	// We cannot use COLLADASW::MathUtils::RAD_TO_DEG_f because it might not be initialized at this point
	ScaleConversionFunctor ConversionFunctors::radToDeg = ScaleConversionFunctor(180.0f/3.1415926535f);
	ScaleConversionFunctor ConversionFunctors::degToRad = ScaleConversionFunctor(3.1415926535f/180.0f);
	ScaleConversionFunctor ConversionFunctors::fromPercent = ScaleConversionFunctor( 0.01f );
	ScaleConversionFunctor ConversionFunctors::toPercent = ScaleConversionFunctor( 100.0f );


	float convert( ConversionFunctorType conversionFunctor, float inValue )
	{
		if ( conversionFunctor )
		{
			return (*conversionFunctor)(inValue);
		}
		else
		{
			return inValue;
		}
	}


}
