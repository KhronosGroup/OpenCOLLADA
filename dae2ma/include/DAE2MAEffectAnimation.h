/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_EFFECTANIMATION_H__
#define __DAE2MA_EFFECTANIMATION_H__

#include "DAE2MAPrerequisites.h"
#include "DAE2MABaseAnimation.h"

#include "COLLADAFWEffectCommon.h"


namespace DAE2MA
{

    /** Stores the material id, the animation id and the animated value with it's type. */
	class EffectAnimation : public BaseAnimation
    {
	public:

        enum AnimatedValueType
        {
            COLOR_OR_TEXTURE_STANDARD,
            COLOR_OR_TEXTURE_AMBIENT,
            COLOR_OR_TEXTURE_DIFFUSE,
            COLOR_OR_TEXTURE_EMISSION,
            FLOAT_OR_PARAM_REFRACTIVE_INDEX,
            COLOR_OR_TEXTURE_TRANSPARENCY, // Opacity
            FLOAT_OR_PARAM_ECCENTRICITY, // shininess (blinn)
            FLOAT_OR_PARAM_COSINE_POWER, // shininess (phong)
            COLOR_OR_TEXTURE_REFLECTED, // Reflective (reflect shader)
            FLOAT_OR_PARAM_REFLECTIVITY, // (reflect shader)
            COLOR_OR_TEXTURE_SPECULAR, // specular (reflect shader)
        };

    private:

        AnimatedValueType mAnimatedValueType;

	public:

        /** Constructor. */
		EffectAnimation();

        /** Destructor. */
		virtual ~EffectAnimation();

        const EffectAnimation::AnimatedValueType& getAnimatedValueType () const { return mAnimatedValueType; }
        void setAnimatedValueType ( const EffectAnimation::AnimatedValueType& val ) { mAnimatedValueType = val; }

	};

} // namespace DAE2MA

#endif // __DAE2MA_EFFECTANIMATION_H__
