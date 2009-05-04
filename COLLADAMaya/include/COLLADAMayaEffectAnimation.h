/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_EFFECTANIMATION_H__
#define __COLLADAMAYA_EFFECTANIMATION_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWEffectCommon.h"


namespace COLLADAMaya
{

    /** Stores the material id, the animation id and the animated value with it's type. */
	class EffectAnimation 	
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

        COLLADAFW::UniqueId mAnimationListId;
        COLLADAFW::UniqueId mEffectId;
        AnimatedValueType mAnimatedValueType;

	public:

        /** Constructor. */
		EffectAnimation();

        /** Destructor. */
		virtual ~EffectAnimation();

        const COLLADAFW::UniqueId& getAnimationListId () const { return mAnimationListId; }
        void setAnimationListId ( const COLLADAFW::UniqueId& val ) { mAnimationListId = val; }

        const COLLADAFW::UniqueId& getEffectId () const { return mEffectId; }
        void setEffectId ( const COLLADAFW::UniqueId& val ) { mEffectId = val; }

        const COLLADAMaya::EffectAnimation::AnimatedValueType& getAnimatedValueType () const { return mAnimatedValueType; }
        void setAnimatedValueType ( const COLLADAMaya::EffectAnimation::AnimatedValueType& val ) { mAnimatedValueType = val; }

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_EFFECTANIMATION_H__
