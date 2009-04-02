/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWValidate.h"

#include "COLLADAFWAnimationCurve.h"


namespace COLLADAFW
{



	//------------------------------
	bool validate( const AnimationCurve* animationCurve )
	{
		size_t keyCount = animationCurve->getKeyCount();
		size_t dimension = animationCurve->getOutDimension();

		// We do not allow animations without keys
		if ( keyCount == 0 )
			return false;

		// We do not allow animations with no out dimensions
		if ( dimension == 0 )
			return false;

		// for each key we need an input value
		if ( animationCurve->getInputValues().getValuesCount() != keyCount )
			return false;

		size_t outValuesCount = dimension * keyCount;

		// Check output values count
		if ( animationCurve->getOutputValues().getValuesCount() != outValuesCount )
			return false;


		bool needsTangents = ( animationCurve->getInterpolationType() == AnimationCurve::INTERPOLATION_BEZIER ) ||
							 ( animationCurve->getInterpolationType() == AnimationCurve::INTERPOLATION_HERMITE );

		if ( animationCurve->getInterpolationType() == AnimationCurve::INTERPOLATION_MIXED )
		{
			// Check interpolations count
			if ( animationCurve->getInterpolationTypes().getCount() != keyCount )
				return false;

			// check if the animation must have tangent arrays
			if ( !needsTangents )
			{
				const AnimationCurve::InterpolationTypeArray& interpolations = animationCurve->getInterpolationTypes();
				for ( size_t i = 0, count = interpolations.getCount(); i < count; ++i )
				{
					const AnimationCurve::InterpolationType& interpolationType = interpolations[i];
					if ( (interpolationType == AnimationCurve::INTERPOLATION_BEZIER) || (interpolationType == AnimationCurve::INTERPOLATION_HERMITE) )
					{
						needsTangents = true;
						break;
					}
				}
			}
		}
		else
		{
			// Check interpolations count
			if ( animationCurve->getInterpolationTypes().getCount() != 0 )
				return false;
		}

		size_t tangentCount = 0;
		if ( needsTangents )
		{
			tangentCount = outValuesCount;
		}

		// Check in tangents count
		if ( animationCurve->getInTangentValues().getValuesCount() != tangentCount )
			return false;

		// Check out tangents count
		if ( animationCurve->getOutTangentValues().getValuesCount() != tangentCount )
			return false;

		return true;
	}


} // namespace COLLADAFW
