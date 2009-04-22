/*
Copyright (c) 2008 NetAllied Systems GmbH

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
#include "COLLADAMaxAnimationImporter.h"

#include "COLLADAFWAnimation.h"


namespace COLLADAMax
{

	//------------------------------
	inline int frameWorkInterpolationToMaxInterpolation(COLLADAFW::AnimationCurve::InterpolationType interpolationType)
	{
		switch (interpolationType)
		{
		case COLLADAFW::AnimationCurve::INTERPOLATION_STEP: 
			return BEZKEY_STEP;
		case COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR: 
			return BEZKEY_LINEAR;
		default: 
			return BEZKEY_USER;
		}
	}

    //------------------------------
	AnimationImporter::AnimationImporter( DocumentImporter* documentImporter, const COLLADAFW::Animation* animation )
		: AnimationCreator(documentImporter)
		, mAnimation(animation)
		, mUnitConversionFunctors(getUnitConversionFunctors())
	{
	}
	
    //------------------------------
	AnimationImporter::~AnimationImporter()
	{
	}

	ConversionFunctor* AnimationImporter::getConversionFunctorByPhysicalDimension( COLLADAFW::PhysicalDimension physicalDimension )
	{
		switch ( physicalDimension )
		{
		case COLLADAFW::PHYSICAL_DIMENSION_LENGTH:
			return mUnitConversionFunctors.lengthConversion;
		case COLLADAFW::PHYSICAL_DIMENSION_ANGLE:
			return mUnitConversionFunctors.angleConversion;
		case COLLADAFW::PHYSICAL_DIMENSION_TIME:
			return mUnitConversionFunctors.timeConversion;
		}
		return 0;
	}

	//------------------------------
	bool AnimationImporter::import()
	{
		// We only support curves
		if ( mAnimation->getAnimationType() != COLLADAFW::Animation::ANIMATION_CURVE )
			return true;

		const COLLADAFW::UniqueId& animationUniqueId = mAnimation->getUniqueId();

		COLLADAFW::AnimationCurve* animationCurve = (COLLADAFW::AnimationCurve*)mAnimation;
		
		size_t dimensions = animationCurve->getOutDimension();

		for ( size_t i = 0; i < dimensions; ++i)
		{
			Control* maxController = createAndFillMaxFloatController( animationCurve, i);
			addMaxControllerToAnimationUniqueId( animationUniqueId, maxController);
		}
		return true;
	}

	//------------------------------
	Control* AnimationImporter::createAndFillMaxFloatController( COLLADAFW::AnimationCurve* animationCurve, size_t dimension )
	{
		COLLADAFW::AnimationCurve::InterpolationType interpolationType = animationCurve->getInterpolationType();
		bool isLinear = (interpolationType ==  COLLADAFW::AnimationCurve::INTERPOLATION_LINEAR);

		Control* maxController = createMaxFloatController( animationCurve, isLinear );
		if ( !maxController )
			return 0;

		IKeyControl* maxKeyController = GetKeyControlInterface( maxController );

		fillMaxFloatController( maxKeyController, animationCurve, dimension, isLinear);

		return maxController;
	}

	//------------------------------
	bool AnimationImporter::fillMaxFloatController( IKeyControl* maxKeyController, COLLADAFW::AnimationCurve* animationCurve, size_t dimension, bool isLinear )
	{
		// Fill in the controller with the animation data from the curve
		size_t keyCount = animationCurve->getKeyCount();
		size_t dimensions = animationCurve->getOutDimension();

		assert( dimension <= dimensions);

		maxKeyController->SetNumKeys((int) keyCount);

		const COLLADAFW::FloatOrDoubleArray& inputValues = animationCurve->getInputValues();
		COLLADAFW::FloatOrDoubleArray::DataType inputValuesDataType = inputValues.getType();

		const COLLADAFW::FloatOrDoubleArray& outputValues = animationCurve->getOutputValues();
		COLLADAFW::FloatOrDoubleArray::DataType outputValuesDataType = outputValues.getType();

		ConversionFunctor* inputConversionFunctor = getConversionFunctorByPhysicalDimension( animationCurve->getInPhysicalDimension() );
		ConversionFunctor* outputConversionFunctor = getConversionFunctorByPhysicalDimension( animationCurve->getOutPhysicalDimensions()[dimension]);

		if ( isLinear )
		{
			if ( inputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
			{
				if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
				{
					fillLinearMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getDoubleValues(), inputConversionFunctor, outputConversionFunctor);
				}
				else if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
				{
					fillLinearMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getFloatValues(), inputConversionFunctor, outputConversionFunctor);
				}
			}
			else if ( inputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT )
			{
				if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
				{
					fillLinearMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getDoubleValues(), inputConversionFunctor, outputConversionFunctor);
				}
				else if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
				{
					fillLinearMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getFloatValues(), inputConversionFunctor, outputConversionFunctor);
				}
			}
		}
		else
		{
			const COLLADAFW::AnimationCurve::InterpolationTypeArray& interpolationTypes = animationCurve->getInterpolationTypes();
			COLLADAFW::AnimationCurve::InterpolationType interpolationType = animationCurve->getInterpolationType();

			const COLLADAFW::FloatOrDoubleArray& inTangentValues = animationCurve->getInTangentValues();
			COLLADAFW::FloatOrDoubleArray::DataType inTangentValuesDataType = inTangentValues.getType();

			const COLLADAFW::FloatOrDoubleArray& outTangentValues = animationCurve->getOutTangentValues();
			COLLADAFW::FloatOrDoubleArray::DataType outTangentValuesDataType = outTangentValues.getType();


			if ( inputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
			{
				if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
				{
					if ( inTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
					{
						if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getDoubleValues(), *inTangentValues.getDoubleValues(), *outTangentValues.getDoubleValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
						else if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getDoubleValues(), *inTangentValues.getDoubleValues(), *outTangentValues.getFloatValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
					}
					else if ( inTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
					{
						if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getDoubleValues(), *inTangentValues.getFloatValues(), *outTangentValues.getDoubleValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
						else if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getDoubleValues(), *inTangentValues.getFloatValues(), *outTangentValues.getFloatValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
					}
				}
				else if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
				{
					if ( inTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
					{
						if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getFloatValues(), *inTangentValues.getDoubleValues(), *outTangentValues.getDoubleValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
						else if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getFloatValues(), *inTangentValues.getDoubleValues(), *outTangentValues.getFloatValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
					}
					else if ( inTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
					{
						if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getFloatValues(), *inTangentValues.getFloatValues(), *outTangentValues.getDoubleValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
						else if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getFloatValues(), *inTangentValues.getFloatValues(), *outTangentValues.getFloatValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
					}
				}
			}
			else if ( inputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT )
			{
				if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
				{
					if ( inTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
					{
						if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getDoubleValues(), *inTangentValues.getDoubleValues(), *outTangentValues.getDoubleValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
						else if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getDoubleValues(), *inTangentValues.getDoubleValues(), *outTangentValues.getFloatValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
					}
					else if ( inTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
					{
						if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getDoubleValues(), *inTangentValues.getFloatValues(), *outTangentValues.getDoubleValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
						else if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getDoubleValues(), *inTangentValues.getFloatValues(), *outTangentValues.getFloatValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
					}
				}
				else if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
				{
					if ( inTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
					{
						if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getFloatValues(), *inTangentValues.getDoubleValues(), *outTangentValues.getDoubleValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
						else if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getFloatValues(), *inTangentValues.getDoubleValues(), *outTangentValues.getFloatValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
					}
					else if ( inTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
					{
						if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getFloatValues(), *inTangentValues.getFloatValues(), *outTangentValues.getDoubleValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
						else if ( outTangentValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
						{
							fillBezierMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getFloatValues(), *inTangentValues.getFloatValues(), *outTangentValues.getFloatValues(), interpolationType, interpolationTypes, inputConversionFunctor, outputConversionFunctor);
						}
					}
				}
			}
		}
		
		maxKeyController->SortKeys();
		return true;
	}

	//------------------------------
	template<class InputArrayType, class OutputArrayType> 
	bool AnimationImporter::fillLinearMaxFloatController( IKeyControl* maxKeyController, 
                                                       	  size_t keyCount, 
		                                                  size_t dimensions, 
		                                                  size_t dimension, 
		                                                  const InputArrayType& inputValues, 
		                                                  const OutputArrayType& outputValues,
														  ConversionFunctorType inputConversionFunctor,
														  ConversionFunctorType outputConversionFunctor)
	{
		for ( size_t i = 0; i < keyCount; ++i)
		{
			// Create the linear keys
			ILinFloatKey key;
			if ( inputConversionFunctor )
			{
				key.time = (TimeValue)((*inputConversionFunctor)((float)(inputValues[i])));
			}
			else
			{
				key.time = (TimeValue)(inputValues[i]);
			}
			
			if ( outputConversionFunctor )
			{
				key.val = (*outputConversionFunctor)((float)(outputValues[ i*dimensions + dimension ]));
			}
			else
			{
				key.val = (float)(outputValues[ i*dimensions + dimension ]);
			}

			maxKeyController->SetKey((int) i, &key);
		}
		return true;
	}


	//------------------------------
	template<class InputArrayType, class OutputArrayType, class InTangentArrayType, class OutTangentArrayType> 
	bool AnimationImporter::fillBezierMaxFloatController( IKeyControl* maxKeyController, 
														  size_t keyCount, 
														  size_t dimensions, 
														  size_t dimension, 
														  const InputArrayType& inputValues, 
														  const OutputArrayType& outputValues,
														  const InTangentArrayType& inTangentValues,
														  const OutTangentArrayType& outTangentValues,
														  const COLLADAFW::AnimationCurve::InterpolationType interpolationType,
														  const COLLADAFW::AnimationCurve::InterpolationTypeArray& interpolationTypes,
														  ConversionFunctorType inputConversionFunctor,
														  ConversionFunctorType outputConversionFunctor)
	{
		COLLADAFW::AnimationCurve::InterpolationType previousKeyInterpolationType;
		COLLADAFW::AnimationCurve::InterpolationType currentKeyInterpolationType;
		if ( interpolationType != COLLADAFW::AnimationCurve::INTERPOLATION_MIXED )
		{
			previousKeyInterpolationType = interpolationType;
			currentKeyInterpolationType = interpolationType;
		}

		for ( size_t i = 0; i < keyCount; ++i)
		{

			if ( interpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_MIXED )
			{
				previousKeyInterpolationType = interpolationTypes[i > 0 ? i-1 : i];
				currentKeyInterpolationType = interpolationTypes[i];
			}


			float currentKeyInput = (float)(inputValues[i]);
			// Create the linear keys
			IBezFloatKey key;

			key.time = (TimeValue)convert( inputConversionFunctor, currentKeyInput );

			key.val = convert( outputConversionFunctor, (float)(outputValues[ i*dimensions + dimension ]));
		
			SetInTanType(key.flags, frameWorkInterpolationToMaxInterpolation( previousKeyInterpolationType ) );
			SetOutTanType(key.flags, frameWorkInterpolationToMaxInterpolation( currentKeyInterpolationType ) );
 
			size_t tangentIndex = 2*(dimensions * i + dimension);

			// in tangent
			if ( previousKeyInterpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER )
			{
				float previousSpan = (i > 0 ? currentKeyInput - (float)(inputValues[i-1]) : TOLERANCE);

				// Calculate the in-tangent
				float absoluteInTangentLength = currentKeyInput - (float)inTangentValues[tangentIndex];
				key.inLength = absoluteInTangentLength / previousSpan;
				if ( COLLADABU::Math::Utils::equalsZero( key.inLength ) ) 
				{
					key.inLength = COLLADABU::Math::Utils::sign(key.inLength) * TOLERANCE;
				}
				key.intan = ( convert( outputConversionFunctor, (float)inTangentValues[tangentIndex + 1]) - key.val) / ( convert(inputConversionFunctor, absoluteInTangentLength));
			}
			else
			{
				key.intan  = 0.0f;
				key.inLength = 0.333f;
			}


			// out tangent
			if ( currentKeyInterpolationType == COLLADAFW::AnimationCurve::INTERPOLATION_BEZIER )
			{
				float nextSpan = (i < keyCount - 1 ? (float)(inputValues[i+1]) - currentKeyInput : TOLERANCE );

				// Calculate the out-tangent
				float absoluteOutTangentLength =  (float)outTangentValues[tangentIndex] - currentKeyInput;
				key.outLength = absoluteOutTangentLength / nextSpan;
				if ( COLLADABU::Math::Utils::equalsZero(key.outLength) )
				{
					key.outLength = COLLADABU::Math::Utils::sign(key.outLength) * TOLERANCE;
				}
				key.outtan = (convert( outputConversionFunctor, (float)outTangentValues[tangentIndex + 1]) - key.val) / ( convert(inputConversionFunctor, absoluteOutTangentLength) );
			}
			else
			{
				key.outtan = 0.0f;
				key.outLength = 0.333f;
			}

			// In some rare cases, only half the key is set by the first call, so call the SetKey function twice.
			maxKeyController->SetKey((int) i, &key);
			maxKeyController->SetKey((int) i, &key);
		}

		return true;
	}


} // namespace COLLADAMax
