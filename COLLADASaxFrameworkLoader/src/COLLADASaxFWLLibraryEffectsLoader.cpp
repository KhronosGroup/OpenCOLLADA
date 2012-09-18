/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryEffectsLoader.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWImage.h"


namespace COLLADASaxFWL
{

    //------------------------------
	LibraryEffectsLoader::LibraryEffectsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentEffect(0)
		, mCurrentProfile(PROFILE_NONE)
		, mCurrentShaderParameterType(UNKNOWN_SHADER_TYPE)
		, mCurrentColorValueIndex(0)
		, mCurrentSampler(0)
		, mCurrentSamplerWrapS(COLLADAFW::Sampler::WRAP_MODE_WRAP)
		, mCurrentSamplerWrapT(COLLADAFW::Sampler::WRAP_MODE_WRAP)
        , mTransparency(1)
		, mOpaqueMode(UNSPECIFIED_OPAQUE)
		, mNextSamplerIndex(0)
        , mInProfileCommonTechnique (false)
        , mInTexture (false)
        , mInSurface (false)
        , mInSampler2D (false)
        , mSurfaceIndex (0)
	{
	}
	
    //------------------------------
	LibraryEffectsLoader::~LibraryEffectsLoader()
	{
	}

	//------------------------------
	bool LibraryEffectsLoader::setCommonEffectShaderType( COLLADAFW::EffectCommon::ShaderType shaderType )
	{
		switch ( mCurrentProfile )
		{
		case PROFILE_COMMON:
			mCurrentEffect->getCommonEffects().back()->setShaderType( shaderType );
			break;
		}
		return true;
	}

	//------------------------------
	COLLADAFW::ColorOrTexture* LibraryEffectsLoader::getCurrentColorOrTexture ( const bool forTexture /*= false*/)
	{
		switch ( mCurrentShaderParameterType )
		{
		case SHADER_PARAMETER_EMISSION:
			{
				return &mCurrentEffect->getCommonEffects().back()->getEmission();
			}
		case SHADER_PARAMETER_AMBIENT:
			{
				return &mCurrentEffect->getCommonEffects().back()->getAmbient();
			}
		case SHADER_PARAMETER_DIFFUSE:
			{
				return &mCurrentEffect->getCommonEffects().back()->getDiffuse();
			}
		case SHADER_PARAMETER_SPECULAR:
			{
				return &mCurrentEffect->getCommonEffects().back()->getSpecular();
			}
		case SHADER_PARAMETER_REFLECTIVE:
			{
				return &mCurrentEffect->getCommonEffects().back()->getReflective();
			}
		case SHADER_PARAMETER_TRANSPARENT:
			{
                if ( forTexture )
                    return &mCurrentEffect->getCommonEffects().back()->getOpacity();
                else
    				return &mTransparent;
			}
		default:
			return 0;
		}
	}

	//------------------------------
	bool LibraryEffectsLoader::handleColorData( const float* data, size_t length )
	{
		switch ( mCurrentProfile )
		{
		case PROFILE_COMMON:
			{
				COLLADAFW::ColorOrTexture* colorOrTexture = getCurrentColorOrTexture();
				colorOrTexture->setType(COLLADAFW::ColorOrTexture::COLOR);
				handleColorData(data, length, colorOrTexture->getColor());

				break;
			}
		}
		return true;

	}

	//------------------------------
	bool LibraryEffectsLoader::handleColorData( const float* data, size_t length, COLLADAFW::Color& color )
	{
		for ( size_t i = 0; i < length; ++i)
		{
			switch ( mCurrentColorValueIndex )
			{
			case 0:
				color.setRed(data[i]);
				break;
			case 1:
				color.setGreen(data[i]);
				break;
			case 2:
				color.setBlue(data[i]);
				break;
			case 3:
				color.setAlpha(data[i]);
				break;
			}
			mCurrentColorValueIndex++;
		}
		return true;
	}


	//------------------------------
	bool LibraryEffectsLoader::handleTexture( const texture__AttributeData& attributeData )
	{
		bool success = true;
		switch ( mCurrentProfile )
		{
		case PROFILE_COMMON:
			{
                // Get the current color or texture element.
				COLLADAFW::ColorOrTexture* colorOrTexture = getCurrentColorOrTexture ( true );

                // Check if the texture is referenced.
                String textureSid = (const char *)attributeData.texture;
				SidSamplerInfoMap::const_iterator it = mEffectProfileSidSamplerInfoMap.find(textureSid);
				if ( it == mEffectProfileSidSamplerInfoMap.end() )
                {
                    it = mEffectSidSamplerInfoMap.find((const char*)attributeData.texture);
                    if ( it == mEffectSidSamplerInfoMap.end() )
                    {
						String msg("Texture with sid \"" + textureSid + "\" not found");
						if ( mCurrentEffect )
						{
							msg += " in effect with id \"" + mCurrentEffect->getOriginalId() + "\"";
						}
						msg += ".";
                        success = handleFWLError ( SaxFWLError::ERROR_UNRESOLVED_REFERENCE, msg );
                        break;
                    }
                }

				// Push the texture sid of the current sampler in the list of used samplers
				// of the current effect profile. 
				size_t samplerIndex = 0;
				StringIndexMap::const_iterator samplerIt = mEffectProfileSamplersMap.find(textureSid);
				if ( samplerIt == mEffectProfileSamplersMap.end() )
				{
					// This sid has not been used before. Add to map with next index
					samplerIndex = mNextSamplerIndex;
					mEffectProfileSamplersMap.insert(std::make_pair(textureSid, mNextSamplerIndex++));
				}
				else
				{
					// This sid is already in the map. Use its index
					samplerIndex = samplerIt->second;
				}

				// Initialize the texture element.
				/* const SamplerInfo& samplerInfo = it->second; */ /* UNUSED */
				colorOrTexture->setType(COLLADAFW::ColorOrTexture::TEXTURE);
				COLLADAFW::Texture& texture = colorOrTexture->getTexture();
                texture.setUniqueId ( createUniqueId(COLLADAFW::Texture::ID()) );
				texture.setSamplerId( samplerIndex );
				if ( attributeData.texcoord )
				{
					texture.setTextureMapId( getTextureMapIdBySematic( attributeData.texcoord) );
				}

				break;
			}
		}
		return success;

	}

	//------------------------------
	double LibraryEffectsLoader::calculateLuminance ( const COLLADAFW::Color& color )
	{
		return ( (color.getRed () * 0.212671) + (color.getGreen () * 0.715160) + (color.getBlue () * 0.072169) );
	}

	//------------------------------
	void LibraryEffectsLoader::calculateOpacity ()
	{
		// If we have already a texture as opacity, we don't need to calculate the opacity color.
		COLLADAFW::ColorOrTexture& opacity = mCurrentEffect->getCommonEffects ().back ()->getOpacity ();
		if ( opacity.isTexture () ) return;

		// Calculate the opacity.
		if ( mTransparent.isColor () )
		{
			opacity.setType ( COLLADAFW::ColorOrTexture::COLOR );
			COLLADAFW::Color& opaqueColor = opacity.getColor ();

			COLLADAFW::Color& transparentColor = mTransparent.getColor ();
			switch ( mOpaqueMode )
			{
			case LibraryEffectsLoader::A_ONE:
				{
					opaqueColor.setRed ( transparentColor.getAlpha () * mTransparency.getFloatValue () );
					opaqueColor.setGreen ( transparentColor.getAlpha () * mTransparency.getFloatValue () );
					opaqueColor.setBlue ( transparentColor.getAlpha () * mTransparency.getFloatValue () );
					opaqueColor.setAlpha ( transparentColor.getAlpha () * mTransparency.getFloatValue () );
					break;
				}
			case LibraryEffectsLoader::A_ZERO:
				{
					opaqueColor.setRed ( 1 - transparentColor.getAlpha () * mTransparency.getFloatValue () );
					opaqueColor.setGreen ( 1 - transparentColor.getAlpha () * mTransparency.getFloatValue () );
					opaqueColor.setBlue ( 1 - transparentColor.getAlpha () * mTransparency.getFloatValue () );
					opaqueColor.setAlpha ( 1 - transparentColor.getAlpha () * mTransparency.getFloatValue () );
					break;
				}
			case LibraryEffectsLoader::RGB_ONE:
				{
					opaqueColor.setRed ( transparentColor.getRed () * mTransparency.getFloatValue () );
					opaqueColor.setGreen ( transparentColor.getGreen () * mTransparency.getFloatValue () );
					opaqueColor.setBlue ( transparentColor.getBlue () * mTransparency.getFloatValue () );
					opaqueColor.setAlpha ( calculateLuminance ( transparentColor ) * mTransparency.getFloatValue () );
					break;
				}
			case LibraryEffectsLoader::RGB_ZERO:
				{
					opaqueColor.setRed ( 1 - transparentColor.getRed () * mTransparency.getFloatValue () );
					opaqueColor.setGreen ( 1 - transparentColor.getGreen () * mTransparency.getFloatValue () );
					opaqueColor.setBlue ( 1 - transparentColor.getBlue () * mTransparency.getFloatValue () );
					opaqueColor.setAlpha ( 1 - calculateLuminance ( transparentColor ) * mTransparency.getFloatValue () );
					break;
				}
			case LibraryEffectsLoader::UNSPECIFIED_OPAQUE:
			default:
				{
					// A_ONE is the default:
					opaqueColor.setRed ( transparentColor.getAlpha () * mTransparency.getFloatValue () );
					opaqueColor.setGreen ( transparentColor.getAlpha () * mTransparency.getFloatValue () );
					opaqueColor.setBlue ( transparentColor.getAlpha () * mTransparency.getFloatValue () );
					opaqueColor.setAlpha ( transparentColor.getAlpha () * mTransparency.getFloatValue () );
					break;
				}
			}

			// Reset the transparent color.
			transparentColor.set (-1,-1,-1,-1);
		}
		else 
		{
			opacity.setType ( COLLADAFW::ColorOrTexture::COLOR );
			COLLADAFW::Color& opaqueColor = opacity.getColor ();

			switch ( mOpaqueMode )
			{
			case LibraryEffectsLoader::A_ONE:
			case LibraryEffectsLoader::RGB_ONE:
				{
					opaqueColor.set ( mTransparency.getFloatValue (), mTransparency.getFloatValue (), mTransparency.getFloatValue (), mTransparency.getFloatValue () );
					break;
				}
			case LibraryEffectsLoader::A_ZERO:
			case LibraryEffectsLoader::RGB_ZERO:
				{
					opaqueColor.set ( 1-mTransparency.getFloatValue (), 1-mTransparency.getFloatValue (), 1-mTransparency.getFloatValue (), 1-mTransparency.getFloatValue () );
					break;
				}
			case LibraryEffectsLoader::UNSPECIFIED_OPAQUE:
			default:
				{
					// A_ONE is the default:
					opaqueColor.set ( mTransparency.getFloatValue (), mTransparency.getFloatValue (), mTransparency.getFloatValue (), mTransparency.getFloatValue () );
					break;
				}
			}
		}

		// Reset the transparent, transparency and opaque values.
		mTransparency = 1;
		mTransparent.setType ( COLLADAFW::ColorOrTexture::UNSPECIFIED );
		mOpaqueMode = LibraryEffectsLoader::UNSPECIFIED_OPAQUE;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__effect( const effect__AttributeData& attributeData )
	{
		mCurrentEffect = FW_NEW COLLADAFW::Effect(createUniqueIdFromId(attributeData.id, COLLADAFW::Effect::ID()));
		
        if ( attributeData.name )
            mCurrentEffect->setName ( (const char*)attributeData.name );
        else if ( attributeData.id )
            mCurrentEffect->setName ( (const char*)attributeData.id );

        if ( attributeData.id )
            mCurrentEffect->setOriginalId ( (const char*)attributeData.id );

        addToSidTree( attributeData.id, 0);
        
        return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__effect()
	{
		getFileLoader()->addEffect(mCurrentEffect);

        mCurrentEffect = 0;
        SidSamplerInfoMap::iterator samplerIt = mEffectSidSamplerInfoMap.begin();
        for ( ; samplerIt != mEffectSidSamplerInfoMap.end(); ++samplerIt)
        {
            SamplerInfo& samplerInfo = samplerIt->second;
            delete samplerInfo.sampler;
        }
        mEffectSidSamplerInfoMap.clear();
        mEffectSidSurfaceMap.clear();
        
        moveUpInSidTree();

		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__profile_COMMON( const profile_COMMON__AttributeData& attributeData )
	{
		mCurrentProfile = PROFILE_COMMON;
		mCurrentEffect->getCommonEffects().append(FW_NEW COLLADAFW::EffectCommon() );
		addToSidTree( attributeData.id, 0);

        if ( attributeData.id )
            mCurrentEffect->getCommonEffects ().back ()->setOriginalId ( (const char*)attributeData.id );

		return true;
	}
	
	//------------------------------
	bool LibraryEffectsLoader::end__profile_COMMON()
	{
		// Calculate the opacity value.
		calculateOpacity ();

        // Fill the array of samplers of the current profile.
        if ( !fillSamplerArray() )
			return false;

        SidSamplerInfoMap::iterator samplerIt = mEffectProfileSidSamplerInfoMap.begin();
        for ( ; samplerIt != mEffectProfileSidSamplerInfoMap.end(); ++samplerIt)
        {
            SamplerInfo& samplerInfo = samplerIt->second;
            delete samplerInfo.sampler;
        }
        mEffectProfileSidSamplerInfoMap.clear();
        mEffectProfileSidSurfaceMap.clear();
        mEffectProfileSamplersMap.clear ();
		mNextSamplerIndex = 0;

		mTransparent.getColor ().set ( -1, -1, -1, -1 );
		mCurrentProfile = PROFILE_NONE;

		moveUpInSidTree();

        return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__surface____fx_surface_common( const surface____fx_surface_common__AttributeData& attributeData )
	{
        mInSurface = true;
        ++mSurfaceIndex;

		mCurrentSurface.surfaceType = attributeData.type;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__surface____fx_surface_common()
	{
        // Check if we have a surface defined directly under an effect or under an effect profile.
        if ( mCurrentProfile == PROFILE_NONE )
            mEffectSidSurfaceMap.insert(std::make_pair(mCurrentNewParamSid, mCurrentSurface));
        else
            mEffectProfileSidSurfaceMap.insert(std::make_pair(mCurrentNewParamSid, mCurrentSurface));

		mCurrentSurfaceInitFrom.clear();

        mInSurface = false;

        return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__init_from____fx_surface_init_from_common()
	{
		mCurrentSurface.imageUniqueId = createUniqueIdFromId((const ParserChar*)mCurrentSurfaceInitFrom.c_str(), COLLADAFW::Image::ID());
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__init_from____fx_surface_init_from_common( const ParserChar* data, size_t length )
	{
		mCurrentSurfaceInitFrom.append((const char* )data, length);
		return true;
	}

    //------------------------------
    bool LibraryEffectsLoader::begin__instance_image( const instance_image__AttributeData& attributeData )
    {
        if ( (attributeData.present_attributes & instance_image__AttributeData::ATTRIBUTE_URL_PRESENT) == instance_image__AttributeData::ATTRIBUTE_URL_PRESENT )
        {
            mCurrentSampler->setSource(createUniqueIdFromUrl(attributeData.url, COLLADAFW::Image::ID()));
        }
        return true;
    }

    //------------------------------
    bool LibraryEffectsLoader::begin__newparam____fx_newparam_common( const newparam____fx_newparam_common__AttributeData& attributeData )
    {
        if ( attributeData.sid )
            mCurrentNewParamSid = (const char *)attributeData.sid;	
        return true;
    }

    //------------------------------
    bool LibraryEffectsLoader::end__newparam____fx_newparam_common()
    {
        mCurrentNewParamSid.clear();
        return true;
    }

    //------------------------------
    bool LibraryEffectsLoader::begin__newparam____cg_newparam( const newparam____cg_newparam__AttributeData& attributeData )
    {
        addToSidTree( 0, (const char *) attributeData.sid ); 
        return true;
    }

	//------------------------------
	bool LibraryEffectsLoader::begin__newparam____common_newparam_type( const newparam____common_newparam_type__AttributeData& attributeData )
	{
		if ( attributeData.sid )
			mCurrentNewParamSid = (const char *)attributeData.sid;	
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__newparam____common_newparam_type()
	{
		mCurrentNewParamSid.clear();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__sampler2D____fx_sampler2D_common()
	{
        mInSampler2D = true;
		mCurrentSampler = new COLLADAFW::Sampler( createUniqueId (COLLADAFW::Sampler::ID()));
		mCurrentSampler->setSamplerType( COLLADAFW::Sampler::SAMPLER_TYPE_2D );
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__sampler2D____fx_sampler2D_common()
	{
		SamplerInfo samplerInfo;
		samplerInfo.sampler = mCurrentSampler;
		samplerInfo.id = 0;
		samplerInfo.surfaceSid = mCurrentSamplerSource;
        
		samplerInfo.sampler->setWrapS(mCurrentSamplerWrapS);
		samplerInfo.sampler->setWrapT(mCurrentSamplerWrapT);

        // Check if we have a sampler defined directly under an effect or under an effect profile.
        if ( mCurrentProfile == PROFILE_NONE )
            mEffectSidSamplerInfoMap.insert(std::make_pair(mCurrentNewParamSid, samplerInfo));
        else
    		mEffectProfileSidSamplerInfoMap.insert(std::make_pair(mCurrentNewParamSid, samplerInfo));

		mCurrentSampler = 0;
		mCurrentSamplerSource.clear();

		mCurrentSamplerWrapS = COLLADAFW::Sampler::WRAP_MODE_WRAP;
		mCurrentSamplerWrapT = COLLADAFW::Sampler::WRAP_MODE_WRAP;

        mInSampler2D = false;

		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__source____NCName( const ParserChar* data, size_t length )
	{
		mCurrentSamplerSource.append((const char* )data, length);
		return true;
	}

	bool LibraryEffectsLoader::data__wrap_s____fx_sampler_wrap_common( const ENUM__fx_sampler_wrap_common value )
	{	
		switch (value)
		{
			case ENUM__fx_sampler_wrap_common__CLAMP: 
				mCurrentSamplerWrapS = COLLADAFW::Sampler::WRAP_MODE_CLAMP;
				break;
		
			case ENUM__fx_sampler_wrap_common__MIRROR: 
				mCurrentSamplerWrapS = COLLADAFW::Sampler::WRAP_MODE_MIRROR;
				break;

			case ENUM__fx_sampler_wrap_common__WRAP: 
				mCurrentSamplerWrapS = COLLADAFW::Sampler::WRAP_MODE_WRAP;
				break;

			case ENUM__fx_sampler_wrap_common__BORDER: 
				mCurrentSamplerWrapS = COLLADAFW::Sampler::WRAP_MODE_BORDER;
				break;

			case ENUM__fx_sampler_wrap_common__NONE: 
				mCurrentSamplerWrapS = COLLADAFW::Sampler::WRAP_MODE_NONE;
				break;

			case ENUM__fx_sampler_wrap_common__NOT_PRESENT: 
				mCurrentSamplerWrapS = COLLADAFW::Sampler::WRAP_MODE_UNSPECIFIED;
				break;
		}
		
		return true;
	}

	bool LibraryEffectsLoader::data__wrap_t____fx_sampler_wrap_common( const ENUM__fx_sampler_wrap_common value )
	{
		switch (value)
		{
			case ENUM__fx_sampler_wrap_common__CLAMP: 
				mCurrentSamplerWrapT = COLLADAFW::Sampler::WRAP_MODE_CLAMP;
				break;
		
			case ENUM__fx_sampler_wrap_common__MIRROR: 
				mCurrentSamplerWrapT = COLLADAFW::Sampler::WRAP_MODE_MIRROR;
				break;

			case ENUM__fx_sampler_wrap_common__WRAP: 
				mCurrentSamplerWrapT = COLLADAFW::Sampler::WRAP_MODE_WRAP;
				break;

			case ENUM__fx_sampler_wrap_common__BORDER: 
				mCurrentSamplerWrapT = COLLADAFW::Sampler::WRAP_MODE_BORDER;
				break;

			case ENUM__fx_sampler_wrap_common__NONE: 
				mCurrentSamplerWrapT = COLLADAFW::Sampler::WRAP_MODE_NONE;
				break;

			case ENUM__fx_sampler_wrap_common__NOT_PRESENT: 
				mCurrentSamplerWrapT = COLLADAFW::Sampler::WRAP_MODE_UNSPECIFIED;
				break;
		}
		
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__profile_COMMON__technique( const profile_COMMON__technique__AttributeData& attributeData )
	{
        mInProfileCommonTechnique = true;

		addToSidTree( attributeData.id, attributeData.sid );

		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__profile_COMMON__technique()
	{
		moveUpInSidTree();
		
        mInProfileCommonTechnique = false;

        return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__profile_COMMON__technique__constant()
	{
		return setCommonEffectShaderType(COLLADAFW::EffectCommon::SHADER_CONSTANT);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__lambert()
	{
		return setCommonEffectShaderType(COLLADAFW::EffectCommon::SHADER_LAMBERT);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__blinn()
	{
		return setCommonEffectShaderType(COLLADAFW::EffectCommon::SHADER_BLINN);
	}


	//------------------------------
	bool LibraryEffectsLoader::begin__phong()
	{
		return setCommonEffectShaderType(COLLADAFW::EffectCommon::SHADER_PHONG);
	}

	//------------------------------
	bool LibraryEffectsLoader::end__library_effects()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__common_color_or_texture_type____color( const common_color_or_texture_type____color__AttributeData& attributeData )
	{
		COLLADAFW::ColorOrTexture* colorOrTexture = getCurrentColorOrTexture();
		addToSidTree( 0, attributeData.sid, &colorOrTexture->getColor() );
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__common_color_or_texture_type____color()
	{
		mCurrentColorValueIndex = 0;
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__common_color_or_texture_type____color( const float* data, size_t length )
	{
		return handleColorData(data, length);
	}

    //------------------------------
	bool LibraryEffectsLoader::begin__texture( const texture__AttributeData& attributeData )
	{
        mInTexture = true;

		return handleTexture( attributeData);
	}

    //------------------------------
    bool LibraryEffectsLoader::end__texture ()
    {
        mInTexture = false;

        return true;
    }

    //------------------------------
    bool LibraryEffectsLoader::begin__common_float_or_param_type____float ( const common_float_or_param_type____float__AttributeData& attributeData )
    {
        switch ( mCurrentShaderParameterType)
        {
        case SHADER_PARAMETER_SHININESS:
            addToSidTree( 0, attributeData.sid, &mCurrentEffect->getCommonEffects().back()->getShininess() );
            break;
        case SHADER_PARAMETER_REFLECTIVITY:
            addToSidTree( 0, attributeData.sid, &mCurrentEffect->getCommonEffects().back()->getReflectivity() );
            break;
        case SHADER_PARAMETER_INDEX_OF_REFRACTION:
            addToSidTree( 0, attributeData.sid, &mCurrentEffect->getCommonEffects().back()->getIndexOfRefraction() );
            break;
        case SHADER_PARAMETER_TRANSPARENCY:
            addToSidTree( 0, attributeData.sid, &mTransparency );
            break;
        }      
        return true;
    }

    //------------------------------
    bool LibraryEffectsLoader::end__common_float_or_param_type____float ()
    {
        moveUpInSidTree();
        return true;
    }

	//------------------------------
	bool LibraryEffectsLoader::data__common_float_or_param_type____float( float value )
	{
		switch ( mCurrentShaderParameterType)
		{
		case SHADER_PARAMETER_SHININESS:
			mCurrentEffect->getCommonEffects().back()->setShininess(value);
			break;
		case SHADER_PARAMETER_REFLECTIVITY:
			mCurrentEffect->getCommonEffects().back()->setReflectivity(value);
			break;
		case SHADER_PARAMETER_INDEX_OF_REFRACTION:
			mCurrentEffect->getCommonEffects().back()->setIndexOfRefraction(value);
			break;
		case SHADER_PARAMETER_TRANSPARENCY:
			mTransparency.setFloatValue (value);
			break;
		}
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__emission()
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_EMISSION; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__emission()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__ambient____common_color_or_texture_type()
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_AMBIENT; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__ambient____common_color_or_texture_type()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__diffuse()
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_DIFFUSE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__diffuse()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__specular()
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_SPECULAR; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__specular()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__shininess()
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_SHININESS; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__shininess()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__reflective()
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_REFLECTIVE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__reflective()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__reflectivity()
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_REFLECTIVITY; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__reflectivity()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__transparent ( const transparent__AttributeData& attributeData )
	{
		ENUM__fx_opaque opaque = attributeData.opaque;
		switch ( opaque )
		{
        case ENUM__fx_opaque__A_ZERO:
            mOpaqueMode = A_ZERO;
            break;
		case ENUM__fx_opaque__A_ONE:
			mOpaqueMode = A_ONE;
			break;
		case ENUM__fx_opaque__RGB_ZERO:
			mOpaqueMode = RGB_ZERO;
			break;
        case ENUM__fx_opaque__RGB_ONE:
            mOpaqueMode = RGB_ONE;
            break;
		default:
			mOpaqueMode = UNSPECIFIED_OPAQUE;
			break;
		}
		mCurrentShaderParameterType = SHADER_PARAMETER_TRANSPARENT; 
		return true;
	}


	//------------------------------
	bool LibraryEffectsLoader::end__transparent()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__transparency()
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_TRANSPARENCY; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__transparency()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__index_of_refraction()
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_INDEX_OF_REFRACTION; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__index_of_refraction()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

    //------------------------------
    bool LibraryEffectsLoader::fillSamplerArray ()
    {
        COLLADAFW::EffectCommon& commonEffect =  *mCurrentEffect->getCommonEffects().back();
        COLLADAFW::SamplerPointerArray& samplerArray = commonEffect.getSamplerPointerArray();

        // Iterate over the list of used samplers in the current effect profile 
        // and push them in the sampler array.
		size_t samplerCount = mEffectProfileSamplersMap.size();
		samplerArray.reallocMemory(samplerCount);
		samplerArray.setCount(samplerCount);
        StringIndexMap::const_iterator it = mEffectProfileSamplersMap.begin ();
        while ( it != mEffectProfileSamplersMap.end () )
        {
            String samplerSid = it->first;
			size_t samplerIndex = it->second;

            bool validSampler =  false;
            SidSamplerInfoMap::iterator samplerIt = mEffectProfileSidSamplerInfoMap.find ( samplerSid );
            if ( samplerIt == mEffectProfileSidSamplerInfoMap.end () )
            {
                samplerIt = mEffectSidSamplerInfoMap.find ( samplerSid );
                if ( samplerIt != mEffectSidSamplerInfoMap.end () ) validSampler = true;
            }
            else validSampler = true;

            if ( validSampler )
            {
                SamplerInfo& samplerInfo = samplerIt->second;
                samplerInfo.id = samplerArray.getCount();
                COLLADAFW::Sampler* sampler = samplerInfo.sampler;
                if ( !sampler->getSourceImage().isValid() )
                {
                    bool validSurface = false;
                    SidSurfaceMap::const_iterator surfaceIt = mEffectProfileSidSurfaceMap.find( samplerInfo.surfaceSid );
                    if ( surfaceIt == mEffectProfileSidSurfaceMap.end() )
                    {
                        surfaceIt = mEffectSidSurfaceMap.find( samplerInfo.surfaceSid );
                        if ( surfaceIt != mEffectSidSurfaceMap.end() ) validSurface = true;
                    }
                    else validSurface = true;
                    if ( validSurface )
                    {
                        const Surface& surface = surfaceIt->second;
                        sampler->setSource(surface.imageUniqueId);

                        // copy sampler into common effect
                        samplerArray[samplerIndex] = sampler->clone();
                    }
                }
                else
                {
					samplerArray[samplerIndex] = sampler->clone();
                }
            }
            else
			{
				// we a null sampler here, to ensure the index of all of the following sampler remain correct
				samplerArray[samplerIndex] = 0;

				if ( !handleFWLError ( SaxFWLError::ERROR_UNRESOLVED_REFERENCE, "No sampler for texture \"" + samplerSid + "\" defined!" ))
					return false;
			}
            ++it;
        }

		return true;
    }

    //------------------------------
    const COLLADAFW::UniqueId& LibraryEffectsLoader::getUniqueId ()
    {
        if ( mCurrentSampler ) 
            return mCurrentSampler->getUniqueId ();
        else if ( mCurrentEffect ) 
            return mCurrentEffect->getUniqueId ();
        return COLLADAFW::UniqueId::INVALID;
    }

} // namespace COLLADASaxFWL
