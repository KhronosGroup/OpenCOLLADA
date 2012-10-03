/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_LIBRARYEFFECTSSLOADER_H__
#define __COLLADASAXFWL_LIBRARYEFFECTSSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLXmlTypes.h"

#include "COLLADAFWEffectCommon.h"
#include "COLLADAFWTypes.h"
#include "COLLADAFWColorOrTexture.h"


namespace COLLADAFW
{
	class Effect;
	class Sampler;
}


namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class LibraryEffectsLoader : public FilePartLoader
	{
    public:
		enum ShaderParameterTypes
		{
			SHADER_PARAMETER_EMISSION,
			SHADER_PARAMETER_AMBIENT,
			SHADER_PARAMETER_DIFFUSE,
			SHADER_PARAMETER_SPECULAR,
			SHADER_PARAMETER_SHININESS,
			SHADER_PARAMETER_REFLECTIVE,
			SHADER_PARAMETER_REFLECTIVITY,
			SHADER_PARAMETER_TRANSPARENT,
			SHADER_PARAMETER_TRANSPARENCY,
			SHADER_PARAMETER_INDEX_OF_REFRACTION,
			UNKNOWN_SHADER_TYPE
		};

    private:
        enum Profile
        {
            PROFILE_BRIDGE,
            PROFILE_CG,
            PROFILE_GLES,
            PROFILE_GLES2,
            PROFILE_GLSL,
            PROFILE_COMMON,
            PROFILE_NONE
        };

		struct Surface
		{
			ENUM__fx_surface_type surfaceType;

			/** The unique id of the image used by the surface.*/
			COLLADAFW::UniqueId imageUniqueId;
		};

		typedef std::map<String, Surface> SidSurfaceMap;

		typedef std::map<String, size_t> StringIndexMap;

		struct SamplerInfo
		{
			/** The sampler.*/
			COLLADAFW::Sampler* sampler;

			/** The index of the sampler.*/
			COLLADAFW::SamplerID id;

			/** The source of the sampler.*/
			String surfaceSid;
		};

		typedef std::map<String, SamplerInfo> SidSamplerInfoMap;

        /**
        * There is a transparent color and a transparency value with an opaque mode in collada.
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

		/** The effect currently being imported.*/
		COLLADAFW::Effect* mCurrentEffect;

        /**
         * There is a transparent color and a transparency value with an opaque mode in collada.
         * We have to calculate with this the opaque color for the framework.
         */
		COLLADAFW::ColorOrTexture mTransparent;

        /**
        * There is a transparent color and a transparency value with an opaque mode in collada.
        * We have to calculate with this the opaque color for the framework.
        */
		COLLADAFW::FloatOrParam mTransparency;

        /**
        * There is a transparent color and a transparency value with an opaque mode in collada.
        * We have to calculate with this the opaque color for the framework.
        */
        OpaqueMode mOpaqueMode;

		/** The current profile.*/
		Profile mCurrentProfile;

		/** The type of the current shader parameter.*/
		ShaderParameterTypes mCurrentShaderParameterType;

		/** The index of the next color component to read.*/
		size_t mCurrentColorValueIndex;

		/** The sid of the current new param.*/
		String mCurrentNewParamSid;

		/** The current surface.*/
		Surface mCurrentSurface;

		/** The init from string of the current surface.*/
		String mCurrentSurfaceInitFrom;

		/** Maps sids of surfaces directly defined under an effect to the surface.*/
		SidSurfaceMap mEffectSidSurfaceMap;

        /** Maps sids of surfaces defined under an effect profile to the surface.*/
        SidSurfaceMap mEffectProfileSidSurfaceMap;

        /** The source of the current sampler.*/
		String mCurrentSamplerSource;

        /** The wrapS mode of the current sampler.*/
		COLLADAFW::Sampler::WrapMode mCurrentSamplerWrapS;

        /** The wrapT mode of the current sampler.*/
		COLLADAFW::Sampler::WrapMode mCurrentSamplerWrapT;

		/** The current sampler.*/
		COLLADAFW::Sampler* mCurrentSampler;

        /** Maps sids of samplers directly defined under an effect to the samplers info.*/
        SidSamplerInfoMap mEffectSidSamplerInfoMap;

		/** Maps sids of samplers defined under an effect profile to the samplers info.*/
		SidSamplerInfoMap mEffectProfileSidSamplerInfoMap;

        /**List of used texture sids in the current effect profile. */
        StringIndexMap mEffectProfileSamplersMap;

		/** The index of the next sampler to add to mEffectProfileSamplersMap.*/
		size_t mNextSamplerIndex;

        /** True, if the parser is in the technique element under profile_COMMON. */
        bool mInProfileCommonTechnique;

        /** True, if the parser is a texture element. */
        bool mInTexture;

        /** True, if the parser is a surface element. */
        bool mInSurface;
        unsigned int mSurfaceIndex;

        /** True, if the parser is a sampler 2d element. */
        bool mInSampler2D;

        /** The variable to store the name of the second extra key. */
        String mSecondKey;

	public:

        /** Constructor. */
		LibraryEffectsLoader( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~LibraryEffectsLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

		/** Creates a new current effect.*/
		virtual bool begin__effect( const effect__AttributeData& attributeData );

		/** Sends current material to the writer an deletes it afterwards.*/
		virtual bool end__effect();


        /** Store the sid of the new param.*/
        virtual bool begin__newparam____fx_newparam_common( const newparam____fx_newparam_common__AttributeData& attributeData );

        /** Clear the sid of the new param.*/
        virtual bool end__newparam____fx_newparam_common();

        /** Store the sid of the new param.*/
        virtual bool begin__newparam____cg_newparam( const newparam____cg_newparam__AttributeData& attributeData );

		/** Set the current profile to PROFILE_COMMON. Create and append common effect to current 
		effect.*/
		virtual bool begin__profile_COMMON( const profile_COMMON__AttributeData& attributeData );

		/** Set the current profile to unknown.*/
		virtual bool end__profile_COMMON();


		/** Store the sid of the new param.*/
		virtual bool begin__newparam____common_newparam_type( const newparam____common_newparam_type__AttributeData& attributeData );

		/** Clear the sid of the new param.*/
		virtual bool end__newparam____common_newparam_type();


		/** Set the surface type.*/
		virtual bool begin__surface____fx_surface_common( const surface____fx_surface_common__AttributeData& attributeData );

		/** Adds the surface to the map of surfaces.*/
		virtual bool end__surface____fx_surface_common();


		/** We don't need to do anything here.*/
		virtual bool begin__init_from____fx_surface_init_from_common( const init_from____fx_surface_init_from_common__AttributeData& attributeData ){return true;}

		/** Assign the unique id of the surface image.*/
		virtual bool end__init_from____fx_surface_init_from_common();

		/** Store data in mCurrentSurfaceInitFrom.*/
		virtual bool data__init_from____fx_surface_init_from_common( const ParserChar* data, size_t length );


		/** Creates a new sampler2D.*/
		virtual bool begin__sampler2D____fx_sampler2D_common();

		/** Adds the sampler to the map of samplers.*/
		virtual bool end__sampler2D____fx_sampler2D_common();


		/** We don't need to do anything here.*/
		virtual bool begin__source____NCName(){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__source____NCName(){return true;}

		/** Store data in mCurrentSamplerSource.*/
		virtual bool data__source____NCName( const ParserChar* data, size_t length );

		/** We don't need to do anything here.*/
		virtual bool begin__wrap_s____fx_sampler_wrap_common(){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__wrap_s____fx_sampler_wrap_common(){return true;}

		/** Store data in mCurrentSamplerWrapS.*/
		virtual bool data__wrap_s____fx_sampler_wrap_common( const ENUM__fx_sampler_wrap_common value );

		/** We don't need to do anything here.*/
		virtual bool begin__wrap_t____fx_sampler_wrap_common(){return true;}

		/** We don't need to do anything here.*/
		virtual bool end__wrap_t____fx_sampler_wrap_common(){return true;}

		/** Store data in mCurrentSamplerWrapS.*/
		virtual bool data__wrap_t____fx_sampler_wrap_common( const ENUM__fx_sampler_wrap_common value );

		/** Resolve all the samplers and copy them to the current effect.*/
		virtual bool begin__profile_COMMON__technique( const profile_COMMON__technique__AttributeData& attributeData );

        /** Iterate over the list of used samplers in the current effect profile and push them 
            in the sampler array. */
        bool fillSamplerArray();

        /** Delete all temporary samplers.*/
		virtual bool end__profile_COMMON__technique();


		/** Set the shader type of the current profile.*/
		virtual bool begin__profile_COMMON__technique__constant();

		/** We don't need to do anything here.*/
		virtual bool end__profile_COMMON__technique__constant(){return true;}


		/** Set the shader type of the current profile.*/
		virtual bool begin__lambert();

		/** We don't need to do anything here.*/
		virtual bool end__lambert(){return true;}


		/** Set the shader type of the current profile.*/
		virtual bool begin__phong();

		/** We don't need to do anything here.*/
		virtual bool end__phong(){return true;}

		/** Set the color or texture kind.*/
		virtual bool begin__emission();
		virtual bool end__emission();
		virtual bool begin__ambient____common_color_or_texture_type();
		virtual bool end__ambient____common_color_or_texture_type();
		virtual bool begin__diffuse();
		virtual bool end__diffuse();
		virtual bool begin__specular();
		virtual bool end__specular();
		virtual bool begin__shininess();
		virtual bool end__shininess();
		virtual bool begin__reflective();
		virtual bool end__reflective();
		virtual bool begin__reflectivity();
		virtual bool end__reflectivity();
		/** Stores the opaque mode attribute. */
		virtual bool begin__transparent( const transparent__AttributeData& attributeData );
		virtual bool end__transparent();
		virtual bool begin__transparency();
		virtual bool end__transparency();
		virtual bool begin__index_of_refraction();
		virtual bool end__index_of_refraction();


		/** Set the shader type of the current profile.*/
		virtual bool begin__blinn();

		/** We don't need to do anything here.*/
		virtual bool end__blinn(){return true;}


		/** Sets the shader parameter type.*/
		virtual bool begin__common_color_or_texture_type____color( const common_color_or_texture_type____color__AttributeData& attributeData );
		/** Resets the shader parameter type.*/
		virtual bool end__common_color_or_texture_type____color();
		/** Stores color data into the correct color object.*/
		virtual bool data__common_color_or_texture_type____color( const float* data, size_t length );

        /** Sets the shader parameter type.*/
        virtual bool begin__common_float_or_param_type____float( const common_float_or_param_type____float__AttributeData& attributeData );
        /** Resets the shader parameter type.*/
        virtual bool end__common_float_or_param_type____float();
        /** Stores float data into the correct float object.*/
        virtual bool data__common_float_or_param_type____float( float value );


		/** Stores texture data into the correct texture object.*/
		virtual bool begin__texture( const texture__AttributeData& attributeData );
		/** We don't need to do anything here.*/
		virtual bool end__texture();

        /** Handles COLLADA 1.5 specific textures. */
        virtual bool begin__instance_image( const instance_image__AttributeData& attributeData );
        virtual bool end__instance_image(){return true;}

        /** Finishes loading a library effects.*/
		virtual bool end__library_effects();

	private:
		/** Set the shader type of the current profile.*/
		bool setCommonEffectShaderType( COLLADAFW::EffectCommon::ShaderType shaderType); 

		/** Stores color data into the correct color object.*/
		bool handleColorData( const float* value, size_t length );

		/** Stores color data into the  @a color object.*/
		bool handleColorData( const float* value, size_t length, COLLADAFW::Color& color );

		/** Stores texture data into the @a shaderParameterType texture object.*/
		bool handleTexture( const texture__AttributeData& attributeData);

        /**
         * Luminance is the function, based on the ISO/CIE color standards (see ITU-R 
         * Recommendation BT.709-4), that averages the color channels into one value.
         */
        double calculateLuminance ( const COLLADAFW::Color& color );

        /** Calculates the framework opacity value from the collada transparent and transparency values. */
        void calculateOpacity ();

        /** Disable default copy ctor. */
		LibraryEffectsLoader( const LibraryEffectsLoader& pre );

        /** Disable default assignment operator. */
		const LibraryEffectsLoader& operator= ( const LibraryEffectsLoader& pre );

        /** Returns the current color or texture element. */
		COLLADAFW::ColorOrTexture* getCurrentColorOrTexture ( const bool forTexture = false );
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYEFFECTSSLOADER_H__
