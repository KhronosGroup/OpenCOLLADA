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

#ifndef __COLLADA_MAYA_ANIMATION_KEYS_H__
#define __COLLADA_MAYA_ANIMATION_KEYS_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaTangentPoint.h"
#include "COLLADASWLibraryAnimations.h"


namespace COLLADAMaya
{
    /**
    * This file contains the AnimationKey, AnimationKeyBezier and AnimationKeyTCB classes.
    */

    // ----------------------------------------------------------
    /**
    This class is the base for every animation key.
    */

	enum StepTransform
	{
		NO_Transformation = 0,
		TransX = 1,
		TransY = 2,
		TransZ = 4,
		RotX = 8,
		RotY = 16,
		RotZ = 32,
		ScaleX = 64,
		ScaleY = 128,
		ScaleZ = 256
	};

	enum StepType
	{
		NO_STEP,
		STEPPED,
		STEPPED_NEXT
	};

	struct Step
	{
		StepType		_type[9];
		StepTransform	_transform;
		MEulerRotation::RotationOrder _order;

		Step() : _transform(NO_Transformation), _order(MEulerRotation::kXYZ)
		{
			std::fill(_type, _type+9, NO_STEP);
		}
	};


	class BaseAnimationKey
    {

    public:
		BaseAnimationKey();

        /** The key input. Typically, this will be a time value, in seconds.
        For driven curves, the dimension of this value will depend on the driver. */
        float input;

        /** The key interpolation type. */
        COLLADASW::LibraryAnimations::InterpolationType interpolation;
		Step transformTypeStep;
    };

    // ----------------------------------------------------------
    /**
    A simple animation key.
    This class is the base for the more complex one-dimensional keys
    and it is used directly for linear and step keys.

    Do not create directly.
    Instead call AnimationCurve::AddKey(LINEAR)
    or AnimationCurve::AddKey(STEP).
    */

    class AnimationKey : public BaseAnimationKey
    {

    public:
        AnimationKey() : BaseAnimationKey (), output (-1) {}

        /** The key output. */
        float output;
    };

    /** Animation key list */
    typedef std::vector<AnimationKey*> AnimationKeyList;

    // ----------------------------------------------------------
    /**
    An animation key with tangents values.
    This class is used for bezier keys and soon: for hermite keys as well.

    Do not create directly.
    Instead call AnimationCurve::AddKey(BEZIER).
    */

    class AnimationKeyBezier : public AnimationKey
    {

    public:

        AnimationKeyBezier() : AnimationKey () {}

        TangentPoint inTangent;  /**< The incoming tangent value. */
        TangentPoint outTangent; /**< The outcoming tangent value. */
    };

    // ----------------------------------------------------------
    /**
    An animation key with tension, continuity and bias values.
    This class is used for 3dsMax TCB keys.

    Do not create directly.
    Instead call AnimationCurve::AddKey(TCB).
    */

    class AnimationKeyTCB : public AnimationKey
    {

    public:

        AnimationKeyTCB() 
            : AnimationKey (), tension(-1), continuity(-1), bias(-1), easeIn(-1), easeOut(-1)
        {}

        float tension;  /**< The tension. */
        float continuity; /**< The continuity. */
        float bias;   /**< The bias. */

        float easeIn;  /**< The ease-in factor. */
        float easeOut;  /**< The ease-out factor. */
    };

    // ----------------------------------------------------------
    /**
    A simple multi-dimensional animation key.
    This class is the base for the more complex multi-dimensional keys
    and it is used directly for linear and step multi-dimensional keys.
    */

    class AnimationMKey : public BaseAnimationKey
    {

    private:
        uint dimension;

    public:
        /** Constructor. Do not use directly.
        Instead call AnimationMultiCurve::AddKey(FUDaeInterpolation::LINEAR)
        or AnimationMultiCurve::AddKey(FUDaeInterpolation::STEP).
        @param dimension The number of dimension to the key output. */
        AnimationMKey ( uint dimension );

        /** Destructor. */
        virtual ~AnimationMKey();

        /** Retrieves the number of dimensions for this key.
        @return The number of dimensions. */
        uint getDimension() const
        {
            return dimension;
        };

        /** The multi-dimensional key output. */
        float* output;
    };

    /** A array of multi-dimensional animation keys. */
    typedef std::vector<AnimationMKey*> AnimationMKeyList;

    // ----------------------------------------------------------
    /**
    A multi-dimensional animation key with tangents values.
    This class is used for bezier keys and soon: for hermite keys as well.
    */

    class AnimationMKeyBezier : public AnimationMKey
    {

    public:
        /** Constructor: do not use directly.
        Instead call AnimationCurve::AddKey(FUDaeInterpolation::BEZIER).
        @param dimension The number of dimension to the key output. */
        AnimationMKeyBezier ( uint dimension );

        /** Destructor. */
        virtual ~AnimationMKeyBezier();

        TangentPoint* inTangent; /**< The incoming tangent value. */
        TangentPoint* outTangent; /**< The outcoming tangent value. */
    };

    // ----------------------------------------------------------
    /**
    An animation key with tension, continuity and bias values.
    This class is used for 3dsMax TCB keys.
    */

    class AnimationMKeyTCB : public AnimationMKey
    {

    public:
        /** Constructor: do not use directly.
        Instead call AnimationMultiCurve::AddKey(FUDaeInterpolation::TCB).
        @param dimension The number of dimension to the key output. */
        AnimationMKeyTCB ( uint dimension );

        /** Destructor. */
        virtual ~AnimationMKeyTCB();

        float* tension; /**< The multi-dimensional tensions. */
        float* continuity; /**< The multi-dimensional continuities. */
        float* bias; /**< The multi-dimensional biases. */

        float* easeIn; /**< The multi-dimensional ease-in factors. */
        float* easeOut; /**< The multi-dimensional ease-out factors. */
    };

}

#endif // __COLLADA_MAYA_ANIMATION_KEYS_H__

