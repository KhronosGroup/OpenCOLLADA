/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SHADERCONSTANTFX_H__
#define __COLLADAFW_SHADERCONSTANTFX_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWColorOrTexture.h"
#include "COLLADAFWFloatOrParam.h"


namespace COLLADAFW
{

    /** 
    Produces a constantly shaded surface that is independent of lighting.

    Used inside a <profile_COMMON> effect, declares a fixed-function pipeline that produces a 
    constantly shaded surface that is independent of lighting.
    The reflected color is calculated as:
    color = <emission> + <ambient> * al
    where:
    • al — A constant amount of ambient light contribution coming from the scene. In the COMMON
    profile, this is the sum of all the <light><technique_common><ambient><color> values in
    the <visual_scene>.
    */
    class ShaderConstantFX : public ShaderElement
	{
	private:
	
        /** Declares the amount of light emitted from the surface of this object. */
        ColorOrTexture mEmission;

        /** Declares the color of a perfect mirror reflection. */
        ColorOrTexture mReflective;

        /** Declares the amount of perfect mirror reflection to be added to the reflected light 
        as a value between 0.0 and 1.0. */
        FloatOrParam mReflectivity;

        /** Declares the color of perfectly refracted light. */
        ColorOrTexture mTransparent;

        /** Declares the amount of perfectly refracted light added to the reflected color as a 
        scalar value between 0.0 and 1.0. */
        FloatOrParam mTransparency;

        /** Declares the index of refraction for perfectly refracted light as a single scalar index. */
        FloatOrParam mIndexOfRefraction;

	public:

        /** Constructor. */
        ShaderConstantFX() {};

        /** Destructor. */
        virtual ~ShaderConstantFX() {};

        /** Declares the amount of light emitted from the surface of this object. */
        const ColorOrTexture getEmission () const { return mEmission; }

        /** Declares the amount of light emitted from the surface of this object. */
        void setEmission ( const ColorOrTexture Emission ) { mEmission = Emission; }

        /** Declares the color of a perfect mirror reflection. */
        const ColorOrTexture getReflective () const { return mReflective; }

        /** Declares the color of a perfect mirror reflection. */
        void setReflective ( const ColorOrTexture Reflective ) { mReflective = Reflective; }

        /** Declares the amount of perfect mirror reflection to be added to the reflected light 
        as a value between 0.0 and 1.0. */
        const FloatOrParam getReflectivity () const { return mReflectivity; }

        /** Declares the amount of perfect mirror reflection to be added to the reflected light 
        as a value between 0.0 and 1.0. */
        void setReflectivity ( const FloatOrParam Reflectivity ) { mReflectivity = Reflectivity; }

        /** Declares the color of perfectly refracted light. */
        const ColorOrTexture getTransparent () const { return mTransparent; }

        /** Declares the color of perfectly refracted light. */
        void setTransparent ( const ColorOrTexture Transparent ) { mTransparent = Transparent; }

        /** Declares the amount of perfectly refracted light added to the reflected color as a 
        scalar value between 0.0 and 1.0. */
        const FloatOrParam getTransparency () const { return mTransparency; }

        /** Declares the amount of perfectly refracted light added to the reflected color as a 
        scalar value between 0.0 and 1.0. */
        void setTransparency ( const FloatOrParam Transparency ) { mTransparency = Transparency; }

        /** Declares the index of refraction for perfectly refracted light as a single scalar index. */
        const FloatOrParam getIndexOfRefraction () const { return mIndexOfRefraction; }

        /** Declares the index of refraction for perfectly refracted light as a single scalar index. */
        void setIndexOfRefraction ( const FloatOrParam IndexOfRefraction ) { mIndexOfRefraction = IndexOfRefraction; }

	private:

        /** Disable default copy ctor. */
		ShaderConstantFX( const ShaderConstantFX& pre );

        /** Disable default assignment operator. */
		const ShaderConstantFX& operator= ( const ShaderConstantFX& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SHADERCONSTANTFX_H__
