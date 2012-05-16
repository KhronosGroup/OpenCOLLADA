/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWValidate.h"

#include "COLLADAFWAnimationCurve.h"
#include "COLLADAFWSkinControllerData.h"


namespace COLLADAFW
{



	//------------------------------
	bool validate( const AnimationCurve* animationCurve )
	{
		if ( !animationCurve )
			return false;

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
			tangentCount = 2 * outValuesCount;
		}

		// Check in tangents count
		if ( animationCurve->getInTangentValues().getValuesCount() != tangentCount )
			return false;

		// Check out tangents count
		if ( animationCurve->getOutTangentValues().getValuesCount() != tangentCount )
			return false;

		return true;
	}


	//------------------------------
	bool validate( const SkinControllerData* skinControllerData )
	{
		if ( !skinControllerData )
			return false;

		size_t jointsCount = skinControllerData->getJointsCount();
		size_t weightsCount = skinControllerData->getWeights().getValuesCount();

		if ( skinControllerData->getInverseBindMatrices().getCount() != jointsCount )
			return false;
	
		const UIntValuesArray& jointsPerVertex = skinControllerData->getJointsPerVertex();

		unsigned int jointsVertexPairCount = 0;
		for ( size_t i = 0, count = jointsPerVertex.getCount(); i < count; ++i)
		{
			jointsVertexPairCount += jointsPerVertex[i];
		}

		// test weight indices
		const UIntValuesArray& weightIndices = skinControllerData->getWeightIndices();

		if ( jointsVertexPairCount != weightIndices.getCount() )
			return false;

		for ( size_t i = 0, count = weightIndices.getCount(); i < count; ++i)
		{
			if ( weightIndices[i] >= weightsCount)
				return false;
		}

		// test joint indices
		const IntValuesArray& jointIndices = skinControllerData->getJointIndices();

		if ( jointsVertexPairCount != jointIndices.getCount() )
			return false;

		for ( size_t i = 0, count = jointIndices.getCount(); i < count; ++i)
		{
			if ( (unsigned int)abs(jointIndices[i]) >= jointsCount)
				return false;
		}
		return true;
	}

} // namespace COLLADAFW
