/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SHADERLAMBERT_H__
#define __COLLADAFW_SHADERLAMBERT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWShaderConstantFX.h"


namespace COLLADAFW
{

    /** 
    Produces a diffuse shaded surface that is independent of lighting. 

    Used inside a <profile_COMMON> effect, declares a fixed-function pipeline that produces a diffuse
    shaded surface that is independent of lighting.
    The result is based on Lambert’s Law, which states that when light hits a rough surface, the light is
    reflected in all directions equally. The reflected color is calculated simply as:
    color = <emission> + <ambient> * al + <diffuse> * max ( N * L, 0 )
    where:
    • al — A constant amount of ambient light contribution coming from the scene. In the COMMON
    profile, this is the sum of all the <light><technique_common><ambient><color> values in
    the <visual_scene>.
    • N — Normal vector
    • L — Light vector
    */
	class ShaderLambert : public ShaderConstantFX 
	{
	private:
	
        /** Declares the amount of ambient light emitted from the surface of this object. */
        ColorOrTexture mAmbient;

        /** Declares the amount of light diffusely reflected from the surface of this object. */
        FloatOrParam mDiffuse;

	public:

        /** Constructor. */
		ShaderLambert() {};

        /** Destructor. */
		virtual ~ShaderLambert() {};

        /** Declares the amount of ambient light emitted from the surface of this object. */
        const ColorOrTexture getAmbient () const { return mAmbient; }

        /** Declares the amount of ambient light emitted from the surface of this object. */
        void setAmbient ( const ColorOrTexture Ambient ) { mAmbient = Ambient; }

        /** Declares the amount of light diffusely reflected from the surface of this object. */
        const FloatOrParam getDiffuse () const { return mDiffuse; }

        /** Declares the amount of light diffusely reflected from the surface of this object. */
        void setDiffuse ( const FloatOrParam Diffuse ) { mDiffuse = Diffuse; }

    private:

        /** Disable default copy ctor. */
		ShaderLambert( const ShaderLambert& pre );

        /** Disable default assignment operator. */
		const ShaderLambert& operator= ( const ShaderLambert& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SHADERLAMBERT_H__
