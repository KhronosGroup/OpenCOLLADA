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
#include "COLLADAFWAnimationCurve.h"


namespace COLLADAMax
{

    //------------------------------
	AnimationImporter::AnimationImporter( DocumentImporter* documentImporter, const COLLADAFW::Animation* animation )
		: ImporterBase(documentImporter)
		, mAnimation(animation)
	{
	}
	
    //------------------------------
	AnimationImporter::~AnimationImporter()
	{
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
	Control* AnimationImporter::createMaxFloatController( COLLADAFW::AnimationCurve* animationCurve, bool isLinear )
	{
		Class_ID controllerClassID(isLinear ? LININTERP_FLOAT_CLASS_ID : HYBRIDINTERP_FLOAT_CLASS_ID, 0);
		Control* maxController = (Control*)createMaxObject( CTRL_FLOAT_CLASS_ID, controllerClassID);

		// TODO
		// Set the out-of-range types.
		//maxController->SetORT(ToORT(curve->GetPreInfinity()), ORT_BEFORE);
		//maxController->SetORT(ToORT(curve->GetPostInfinity()), ORT_AFTER);

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


		if ( isLinear )
		{
			if ( inputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
			{
				if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
				{
					fillLinearMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getDoubleValues());
				}
				else if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
				{
					fillLinearMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getDoubleValues(), *outputValues.getFloatValues());
				}
			}
			else if ( inputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT )
			{
				if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE )
				{
					fillLinearMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getDoubleValues());
				}
				else if ( outputValuesDataType == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT)
				{
					fillLinearMaxFloatController( maxKeyController, keyCount, dimensions, dimension, *inputValues.getFloatValues(), *outputValues.getFloatValues());
				}
			}
		}
		else
		{
#if 0
			for (size_t i = 0; i < keyCount; ++i)
			{
				// Create each bezier key independently.
				IBezFloatKey key;
				key.time = keys[i]->input * timeFactor;
				key.val = keys[i]->output;
				SetInTanType(key.flags, ConvertInterpolation(keys[i > 0 ? i-1 : i]->interpolation));
				SetOutTanType(key.flags, ConvertInterpolation(keys[i]->interpolation));

				if (keys[i]->interpolation == FUDaeInterpolation::BEZIER)
				{
					FCDAnimationKeyBezier* bkey = (FCDAnimationKeyBezier*) keys[i];
					float previousSpan = keys[i]->input - (i > 0 ? keys[i-1]->input : (keys[i]->input - FLT_TOLERANCE));
					float nextSpan = (i < keyCount - 1 ? keys[i+1]->input : (keys[i]->input + FLT_TOLERANCE)) - keys[i]->input;

					// Calculate the in-tangent
					key.inLength = (bkey->input - bkey->inTangent.x) / previousSpan;
					if (key.inLength < FLT_TOLERANCE && key.inLength > -FLT_TOLERANCE) key.inLength = FMath::Sign(key.inLength) * FLT_TOLERANCE;
					key.intan = (bkey->inTangent.y - key.val) / (key.inLength * previousSpan * timeFactor);

					// Calculate the out-tangent
					key.outLength = (bkey->outTangent.x - bkey->input) / nextSpan;
					if (key.outLength < FLT_TOLERANCE && key.outLength > -FLT_TOLERANCE) key.outLength = FMath::Sign(key.outLength) * FLT_TOLERANCE;
					key.outtan = (bkey->outTangent.y - key.val) / (key.outLength * nextSpan * timeFactor);
				}
				else
				{
					key.intan = key.outtan = 0.0f;
					key.outLength = key.inLength = 0.333f;
				}

				// In some rare cases, only half the key is set by the first call, so call the SetKey function twice.
				controller->SetKey((int) i, &key);
				controller->SetKey((int) i, &key);
			}
#endif
		}
		
		maxKeyController->SortKeys();
		return true;
	}

	//------------------------------
	template<class InputArrayType, class OutputArrayType> 
	bool COLLADAMax::AnimationImporter::fillLinearMaxFloatController( IKeyControl* maxKeyController, 
                                                                	  size_t keyCount, 
		                                                              size_t dimensions, 
		                                                              size_t dimension, 
		                                                              const InputArrayType& inputValues, 
		                                                              const OutputArrayType& outputValues )
	{
		int timeFactor = getTimeFactor();

		for ( size_t i = 0; i < keyCount; ++i)
		{
			// Create the linear keys
			ILinFloatKey key;
			key.time = (TimeValue)(inputValues[i] * timeFactor);
			key.val = (float)(outputValues[ i*dimensions + dimension ]);

			maxKeyController->SetKey((int) i, &key);
		}
		return true;
	}

} // namespace COLLADAMax
