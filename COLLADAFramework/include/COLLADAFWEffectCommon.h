/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_EFFECTCOMMON_H__
#define __COLLADAFW_EFFECTCOMMON_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWColorOrTexture.h"
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWSampler.h"
#include "COLLADAFWFloatOrParam.h"


namespace COLLADAFW
{
	/** Once we implement referencing of floats, this might become a class.*/
//	typedef double FloatOrParam;


    /** An effect defined as in the COLLADA common profile.  */
	class EffectCommon 	
	{
	public:

		/** Possible shaders that can be represented by EffectCommon.*/
		enum ShaderType
		{
			SHADER_UNKNOWN,
			SHADER_BLINN,
			SHADER_CONSTANT,
			SHADER_PHONG,
			SHADER_LAMBERT
		};
        
        /**
         * There is a transparent color and a transparency value with an opaque mode in COLLADA.
         * We have to calculate with this the opaque color for the framework.
         */
        enum OpaqueMode
        {
            UNSPECIFIED_OPAQUE,
            A_ONE,
            RGB_ZERO,
            A_ZERO,
            RGB_ONE
        };

	private:

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

		/** The shader used by the effect.*/
		ShaderType mShaderType;

		/** Declares the amount of light emitted from the surface of this object.
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		ColorOrTexture mEmission;

		/** Declares the amount of ambient light emitted from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		Lambert
		*/
		ColorOrTexture mAmbient;

		/** Declares the amount of light diffusely reflected from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		Lambert
		*/
		ColorOrTexture mDiffuse;

		/** Declares the color of light specularly reflected from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		*/
		ColorOrTexture mSpecular;

		/** Declares the specularity or roughness of the specular reflection lobe. 
		Used by the following shaders:
		Blinn
		Phong
		*/
		FloatOrParam mShininess;


		/** Declares the color of a perfect mirror reflection. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		ColorOrTexture mReflective;

		/** Declares the amount of perfect mirror reflection to be added to the reflected light 
		as a value between 0.0 and 1.0. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		FloatOrParam mReflectivity;

        /** Declares the opaque color. 
        Used by the following shaders:
        Blinn
        Constant
        Phong
        Lambert
        */
        ColorOrTexture mOpacity;

        /** Declares transparent color.
         Note: this property should only be used if one wants to know the value that were used to compute the final opacity color
        */
        
 		ColorOrTexture mTransparent;
        
        /** Declares the transparency value.
         Note: this property should only be used if one wants to know the value that were used to compute the final opacity color
         */
		FloatOrParam mTransparency;

		/** Declares the index of refraction for perfectly refracted light as a single scalar index. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		FloatOrParam mIndexOfRefraction;

		/** All the samplers used as texture in the CommonEffect.*/
		SamplerPointerArray mSamplers;

        /** Declares the opaque mode */
        OpaqueMode mOpaqueMode;
        
	public:

        /** Constructor. */
		EffectCommon();

        /** Destructor. */
		virtual ~EffectCommon();

        /**
        * The original object id, if it in the original file format exist. 
        */
        const String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const String& val ) { mOriginalId = val; }


		/** Returns the type of the shader used by the effect.*/
		ShaderType getShaderType() const { return mShaderType; }

		/** Sets the type of the shader used by the effect.*/
		void setShaderType(ShaderType val) { mShaderType = val; }


		/** Declares the amount of light emitted from the surface of this object. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		const ColorOrTexture& getEmission() const { return mEmission; }

		/** Declares the amount of light emitted from the surface of this object. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		ColorOrTexture& getEmission() { return mEmission; }

		/** Declares the amount of light emitted from the surface of this object. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		void setEmission( const ColorOrTexture& Emission ) { mEmission = Emission; }


		/** Declares the amount of ambient light emitted from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		Lambert
		*/
		const ColorOrTexture& getAmbient () const { return mAmbient; }

		/** Declares the amount of ambient light emitted from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		Lambert
		*/
		ColorOrTexture& getAmbient () { return mAmbient; }

		/** Declares the amount of ambient light emitted from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		Lambert
		*/
		void setAmbient ( const ColorOrTexture& Ambient ) { mAmbient = Ambient; }


		/** Declares the amount of light diffusely reflected from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		Lambert
		*/
		const ColorOrTexture& getDiffuse () const { return mDiffuse; }

		/** Declares the amount of light diffusely reflected from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		Lambert
		*/
		ColorOrTexture& getDiffuse () { return mDiffuse; }

		/** Declares the amount of light diffusely reflected from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		Lambert
		*/
		void setDiffuse ( const ColorOrTexture& Diffuse ) { mDiffuse = Diffuse; }

        /** Declares the transparent color
         */
        const ColorOrTexture& getTransparent () const { return mTransparent; }
        
        /** Declares the transparent color
         */
        ColorOrTexture& getTransparent () { return mTransparent; }
        
        /** Declares the transparent color
         */
        void setTransparent ( const ColorOrTexture& transparent ) { mTransparent = transparent; }

		/** Declares the color of light specularly reflected from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		*/
		const ColorOrTexture& getSpecular () const { return mSpecular; }

		/** Declares the color of light specularly reflected from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		*/
		ColorOrTexture& getSpecular () { return mSpecular; }

		/** Declares the color of light specularly reflected from the surface of this object. 
		Used by the following shaders:
		Blinn
		Phong
		*/
		void setSpecular ( const ColorOrTexture& Specular ) { mSpecular = Specular; }


		/** Declares the specularity or roughness of the specular reflection lobe. 
		Used by the following shaders:
		Blinn
		Phong
		*/
		const FloatOrParam& getShininess () const { return mShininess; }

		/** Declares the specularity or roughness of the specular reflection lobe. 
		Used by the following shaders:
		Blinn
		Phong
		*/
		FloatOrParam& getShininess () { return mShininess; }

		/** Declares the specularity or roughness of the specular reflection lobe. 
		Used by the following shaders:
		Blinn
		Phong
		*/
		void setShininess ( const FloatOrParam& Shininess ) { mShininess = Shininess; }

		/** Declares the color of a perfect mirror reflection. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		const ColorOrTexture& getReflective() const { return mReflective; }

		/** Declares the color of a perfect mirror reflection. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		ColorOrTexture& getReflective() { return mReflective; }

		/** Declares the color of a perfect mirror reflection. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		void setReflective( const ColorOrTexture& Reflective ) { mReflective = Reflective; }


		/** Declares the amount of perfect mirror reflection to be added to the reflected light 
		as a value between 0.0 and 1.0. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		const FloatOrParam& getReflectivity() const { return mReflectivity; }

		/** Declares the amount of perfect mirror reflection to be added to the reflected light 
		as a value between 0.0 and 1.0. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		FloatOrParam& getReflectivity() { return mReflectivity; }

		/** Declares the amount of perfect mirror reflection to be added to the reflected light 
		as a value between 0.0 and 1.0. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		void setReflectivity( const FloatOrParam& Reflectivity ) { mReflectivity = Reflectivity; }

        /** Declares the transparency value
         */
        FloatOrParam& getTransparency() { return mTransparency; }

        /** Declares the transparency value
         */
        const FloatOrParam& getTransparency() const { return mTransparency; }
        
        /** Declares the transparency value
         */
        void setTransparency( const FloatOrParam& transparency ) { mTransparency = transparency; }
        
        /** Declares the opaque mode
         */
        OpaqueMode getOpaqueMode() const { return mOpaqueMode; }

        /** Declares the transparency value
         */
        void setOpaqueMode(OpaqueMode opaqueMode ) { mOpaqueMode = opaqueMode; }
        
        /** Declares the opaque color. 
        Used by the following shaders:
        Blinn
        Constant
        Phong
        Lambert
        */
        ColorOrTexture& getOpacity () { return mOpacity; }

        /** Declares the opaque color. 
        Used by the following shaders:
        Blinn
        Constant
        Phong
        Lambert
        */
        const ColorOrTexture& getOpacity () const { return mOpacity; }

        /** Declares the opaque color. 
        Used by the following shaders:
        Blinn
        Constant
        Phong
        Lambert
        */
        void setOpacity ( const ColorOrTexture& val ) { mOpacity = val; }

		/** Declares the index of refraction for perfectly refracted light as a single scalar index. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		const FloatOrParam& getIndexOfRefraction() const { return mIndexOfRefraction; }

		/** Declares the index of refraction for perfectly refracted light as a single scalar index. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		FloatOrParam& getIndexOfRefraction() { return mIndexOfRefraction; }

		/** Declares the index of refraction for perfectly refracted light as a single scalar index. 
		Used by the following shaders:
		Blinn
		Constant
		Phong
		Lambert
		*/
		void setIndexOfRefraction( const FloatOrParam& IndexOfRefraction ) { mIndexOfRefraction = IndexOfRefraction; }

		/** Returns the samplers used by the common effect.*/
		SamplerPointerArray& getSamplerPointerArray() { return mSamplers; }

		/** Returns the samplers used by the common effect.*/
		const SamplerPointerArray& getSamplerPointerArray() const { return mSamplers; }


		/** clones the effect*/
		EffectCommon* clone( ) { return FW_NEW EffectCommon(*this); }

	private:

        /** Disable default copy ctor. */
//		EffectCommon( const EffectCommon& pre );

        /** Disable default assignment operator. */
//		const EffectCommon& operator=( const EffectCommon& pre );

	};

	typedef PointerArray<EffectCommon> CommonEffectPointerArray;


} // namespace COLLADAFW

#endif // __COLLADAFW_EFFECTCOMMON_H__
