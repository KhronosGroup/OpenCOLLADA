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
	int validate( const AnimationCurve* animationCurve, bool verbose )
	{
		int failure_count = 0;
		if ( !animationCurve )
			return 1;

		size_t keyCount = animationCurve->getKeyCount();
		size_t dimension = animationCurve->getOutDimension();

		// We do not allow animations without keys
		if ( keyCount == 0 ){
			if (verbose)
				printf("ERROR: [%s] Animation curve has no keys.\n",
				animationCurve->getName().c_str());
			failure_count +=1;
		}

		// We do not allow animations with no out dimensions
		if ( dimension == 0 ) {
			if (verbose)
				printf("ERROR: [%s] Animation curve has no dimension.\n",
				animationCurve->getName().c_str());
			failure_count +=1;
		}

		// Subsequent checks only make sense when above checks passed.
		// Hence return now, if errors occured until here.
		if (failure_count > 0)
			return failure_count;

		// for each key we need an input value
		if ( animationCurve->getInputValues().getValuesCount() != keyCount ) {
			if (verbose)
				printf("ERROR: [%s] Found %d input values for %d keys\n",
				animationCurve->getName().c_str(),
				(int)animationCurve->getInputValues().getValuesCount(),
				(int)keyCount);
			failure_count +=1;
		}

		size_t outValuesCount = dimension * keyCount;

		// Check output values count
		if ( animationCurve->getOutputValues().getValuesCount() != outValuesCount )
			failure_count +=1;

		bool needsTangents = ( animationCurve->getInterpolationType() == AnimationCurve::INTERPOLATION_BEZIER ) ||
							 ( animationCurve->getInterpolationType() == AnimationCurve::INTERPOLATION_HERMITE );

		if ( animationCurve->getInterpolationType() == AnimationCurve::INTERPOLATION_MIXED )
		{
			// Check interpolations count
			if ( animationCurve->getInterpolationTypes().getCount() != keyCount ) {
				if (verbose)
					printf("ERROR: [%s] Found %d interpolation types for %d keys\n",
					animationCurve->getName().c_str(),
					(int)animationCurve->getInterpolationTypes().getCount(),
					(int)keyCount);
				failure_count +=1;
			}

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
			if ( animationCurve->getInterpolationTypes().getCount() != 0 ) {
				if (verbose)
					printf("ERROR: [%s] Found %d mixed interpolation types (expected only one type).\n",
                        animationCurve->getName().c_str(),
                        (int)animationCurve->getInterpolationTypes().getCount());
				failure_count +=1;
			}
		}

		size_t tangentCount = 0;
		if ( needsTangents )
		{
			tangentCount = 2 * outValuesCount;
		}

		// Check in tangents count
		if ( animationCurve->getInTangentValues().getValuesCount() != tangentCount ) {
				if (verbose)
					printf("ERROR: [%s] Found %d IN tangent values for %d tangents\n",
					animationCurve->getName().c_str(),
					(int)animationCurve->getInTangentValues().getValuesCount(),
					(int)tangentCount);
			failure_count +=1;
		}

		// Check out tangents count
		if ( animationCurve->getOutTangentValues().getValuesCount() != tangentCount ) {
				if (verbose)
					printf("ERROR: [%s] Found %d OUT tangent values for %d tangents\n",
					animationCurve->getName().c_str(),
					(int)animationCurve->getOutTangentValues().getValuesCount(),
					(int)tangentCount);
			failure_count +=1;
		}

		return failure_count;
	}


	//------------------------------
	int validate( const SkinControllerData* skinControllerData, bool verbose)
	{
		int failure_count = 0;
		if ( !skinControllerData ) {
			return 1;
		}

		size_t jointsCount = skinControllerData->getJointsCount();
		size_t weightsCount = skinControllerData->getWeights().getValuesCount();

		if ( skinControllerData->getInverseBindMatrices().getCount() != jointsCount ) {
			if (verbose)
				printf("ERROR: [%s] found %d bind matrices and %d joints\n",
				skinControllerData->getName().c_str(),
				(int)skinControllerData->getInverseBindMatrices().getCount(),
				(int)jointsCount);
			failure_count +=1;
		}
	
		const UIntValuesArray& jointsPerVertex = skinControllerData->getJointsPerVertex();

		unsigned int jointsVertexPairCount = 0;
		for ( size_t i = 0, count = jointsPerVertex.getCount(); i < count; ++i)
		{
			jointsVertexPairCount += jointsPerVertex[i];
		}

		// test weight indices
		const UIntValuesArray& weightIndices = skinControllerData->getWeightIndices();

		if ( jointsVertexPairCount != weightIndices.getCount() ) {
			if (verbose)
				printf("ERROR: [%s] found %d joint-Vertex Pairs and %d weights\n",
				skinControllerData->getName().c_str(),
				jointsVertexPairCount,
				(int)weightIndices.getCount());
			failure_count +=1;
		}

		for ( size_t i = 0, count = weightIndices.getCount(); i < count; ++i)
		{
			if ( weightIndices[i] >= weightsCount) {
				if (verbose)
					printf("ERROR: [%s] weight index %d=%d points outside of weight array of length %d\n",
					skinControllerData->getName().c_str(),
					(int)i,
					weightIndices[i],
					(int)weightsCount);
				failure_count +=1;
			}
		}

		// test joint indices
		const IntValuesArray& jointIndices = skinControllerData->getJointIndices();

		if ( jointsVertexPairCount != jointIndices.getCount() ) {
			if (verbose)
				printf("ERROR: [%s] found %d joint-Vertex Pairs and %d joint indices\n",
				skinControllerData->getName().c_str(),
				jointsVertexPairCount,
				(int)jointIndices.getCount());
			failure_count +=1;
		}

		for ( size_t i = 0, count = jointIndices.getCount(); i < count; ++i)
		{
			if ( (unsigned int)abs(jointIndices[i]) >= jointsCount) {
				if (verbose)
					printf("ERROR: [%s] joint index %d=%d points outside of weight array of length %d\n",
					skinControllerData->getName().c_str(),
					(int)i,
					(unsigned int)abs(jointIndices[i]),
					(int)jointsCount);
				failure_count +=1;
			}
		}
		return failure_count;
	}

} // namespace COLLADAFW
