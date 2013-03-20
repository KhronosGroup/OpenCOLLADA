/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_EFFECT_H__
#define __COLLADAFW_EFFECT_H__

#include "COLLADAFWPrerequisites.h"

#include "COLLADAFWObject.h"
#include "COLLADAFWColor.h"

#include "COLLADAFWEffectCommon.h"

namespace COLLADAFW
{

    /** 
    Provides a self-contained description of a COLLADA effect.

    Programmable pipelines allow stages of the 3-D pipeline to be programmed using high-level languages.
    These shaders often require very specific data to be passed to them and require the rest of the 3-D pipeline
    to be set up in a particular way in order to function. Shader Effects is a way of describing not only shaders,
    but also the environment in which they will execute. The environment requires description of images,
    samplers, shaders, input and output parameters, uniform parameters, and render-state settings.
    Additionally, some algorithms require several passes to render the effect. This is supported by breaking
    pipeline descriptions into an ordered collection of <pass> objects. These are grouped into
    <technique>s that describe one of several ways of generating an effect.
    Elements inside the <effect> declaration assume the use of an underlying library of code that handles
    the creation, use, and management of shaders, source code, parameters, etc. We shall refer to this
    underlying library as the “FX Runtime”.
    Parameters declared inside the <effect> element but outside of any <profile_*> element are said to
    be in “<effect> scope”. Parameters inside <effect> scope can be drawn only from a constrained list
    of basic data types and, after declaration, are available to <shader>s and declarations across all profiles.
    <effect> scope provides a handy way to parameterize many profiles and techniques with a single
    parameter.
    */
	class Effect : public ObjectTemplate<COLLADA_TYPE::EFFECT>
    {
	private:
	
        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

        /** 
         * Pretty-print name for this effect. Optional. 
         */
        String mName; 

        /** 
        At least one profile must appear, but any number of any of
        the following profiles can be included:
        • <profile_CG>
        • <profile_GLES>
        • <profile_GLSL>
        • <profile_COMMON> 
        */
        // TODO Fix members!!!
//        Profile* mProfile;

		/** 
         * All the COLLADA common effects.
         */
		CommonEffectPointerArray mCommonEffects;
	
		/** 
         * The standard color, i.e. the color to by used by systems that support only
		 * one color, like most of the CAD-systems.
         */
        Color mStandardColor;

		PointerArray<TextureAttributes> mExtraTextures;

    public:

        /** Constructor. */
		Effect( const UniqueId& uniqueId );

        /** Destructor. */
		virtual ~Effect();

        /**
        * The original object id, if it in the original file format exist. 
        */
        const String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const String& val ) { mOriginalId = val; }

        /** Pretty-print name for this effect. Optional. */
        const String getName () const { return mName; }

        /** Pretty-print name for this effect. Optional. */
        void setName ( const String Name ) { mName = Name; }

		/** Returns the standard color, i.e. the color to by used by systems that support only
		one color, like most of the CAD-systems.*/
		const Color& getStandardColor() const { return mStandardColor; }

		/** Sets the standard color, i.e. the color to by used by systems that support only
		one color, like most of the CAD-systems.*/
		void setStandardColor(Color val) { mStandardColor = val; }

		/** Returns the common effects.*/
		CommonEffectPointerArray& getCommonEffects() { return mCommonEffects; }

		/** Returns the common effects.*/
		const CommonEffectPointerArray& getCommonEffects()const { return mCommonEffects; }

		TextureAttributes* createExtraTextureAttributes();
		const PointerArray<TextureAttributes>& getExtraTextures();

	private:
		void addExtraTextureAttributes( COLLADAFW::TextureAttributes* textureAttributes );

	private:

        /** TODO Implement copy constructor if necessary. */
//		Effect( const Effect& pre );

        /** TODO Implement assignment operator if necessary */
//		const Effect& operator= ( const Effect& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_EFFECT_H__
