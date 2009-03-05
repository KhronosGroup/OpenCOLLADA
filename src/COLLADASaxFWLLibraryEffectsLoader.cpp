/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryEffectsLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWImage.h"

namespace COLLADASaxFWL
{

    //------------------------------
	LibraryEffectsLoader::LibraryEffectsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentEffect(0)
		, mCurrentProfile(PROFILE_UNKNOWN)
		, mCurrentShaderParameterType(UNKNOWN_SHADER_TYPE)
		, mCurrentColorValueIndex(0)
		, mCurrentSampler(0)
        , mTransparency (1)
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
	bool LibraryEffectsLoader::handleColorData( const double* data, size_t length )
	{
		switch ( mCurrentProfile )
		{
		case PROFILE_COMMON:
			{
				COLLADAFW::ColorOrTexture* colorOrTexture = 0;
				switch ( mCurrentShaderParameterType )
				{
				case SHADER_PARAMETER_EMISSION:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getEmission();
						break;
					}
				case SHADER_PARAMETER_AMBIENT:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getAmbient();
						break;
					}
				case SHADER_PARAMETER_DIFFUSE:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getDiffuse();
						break;
					}
				case SHADER_PARAMETER_SPECULAR:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getSpecular();
						break;
					}
				case SHADER_PARAMETER_REFLECTIVE:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getReflective();
						break;
					}
				case SHADER_PARAMETER_TRANSPARENT:
					{
						colorOrTexture = &mTransparent;
						break;
					}
				}
				colorOrTexture->setType(COLLADAFW::ColorOrTexture::COLOR);
				handleColorData(data, length, colorOrTexture->getColor());

                if ( mCurrentShaderParameterType == SHADER_PARAMETER_TRANSPARENT )
                {
                    mTransparent.getColor ().set ( -1, -1, -1, -1 );
                }

				break;
			}

		}
		return true;

	}

	//------------------------------
	bool LibraryEffectsLoader::handleColorData( const double* data, size_t length, COLLADAFW::Color& color )
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
	bool LibraryEffectsLoader::handleTexture( const texture__AttributeData& attributeData, ShaderParameterTypes shaderParameterType )
	{
		switch ( mCurrentProfile )
		{
		case PROFILE_COMMON:
			{
				COLLADAFW::ColorOrTexture* colorOrTexture = 0;
				switch ( shaderParameterType )
				{
				case SHADER_PARAMETER_EMISSION:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getEmission();
						break;
					}
				case SHADER_PARAMETER_AMBIENT:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getAmbient();
						break;
					}
				case SHADER_PARAMETER_DIFFUSE:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getDiffuse();
						break;
					}
				case SHADER_PARAMETER_SPECULAR:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getSpecular();
						break;
					}
				case SHADER_PARAMETER_REFLECTIVE:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getReflective();
						break;
					}
				case SHADER_PARAMETER_TRANSPARENT:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getOpacity();
						break;
					}
				}

				SidSamplerInfoMap::const_iterator it = mSidSamplerInfoMap.find((const char*)attributeData.texture);
				if ( it == mSidSamplerInfoMap.end() )
					break;

				const SamplerInfo& samplerInfo = it->second;

				colorOrTexture->setType(COLLADAFW::ColorOrTexture::TEXTURE);
				COLLADAFW::Texture& texture = colorOrTexture->getTexture();
				texture.setSamplerId( samplerInfo.id );
				texture.setTextureMapId( getTextureMapIdBySematic( attributeData.texcoord) );
				break;
			}
		}
		return true;

	}

	//------------------------------
	bool LibraryEffectsLoader::begin__effect( const effect__AttributeData& attributeData )
	{
		mCurrentEffect = FW_NEW COLLADAFW::Effect(getUniqueIdFromId(attributeData.id, COLLADAFW::Effect::ID()).getObjectId());
		if ( attributeData.name )
		{
			mCurrentEffect->setName((const char*)attributeData.name);
		}
		else if ( attributeData.id)
		{
			mCurrentEffect->setName((const char*)attributeData.id);
		} 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__effect()
	{
        // Calculate the opacity value.
        calculateOpacity ();

		bool success = writer()->writeEffect(mCurrentEffect);
		FW_DELETE mCurrentEffect;
		mCurrentEffect = 0;
		return success;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__profile_COMMON( const profile_COMMON__AttributeData& attributeData )
	{
		mCurrentProfile = PROFILE_COMMON;
		mCurrentEffect->getCommonEffects().append(FW_NEW COLLADAFW::EffectCommon() );
		return true;
	}
	
	//------------------------------
	bool LibraryEffectsLoader::end__profile_COMMON()
	{
		mCurrentProfile = PROFILE_UNKNOWN;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__newparam__surface( const newparam__surface__AttributeData& attributeData )
	{
		mCurrentSurface.surfaceType = attributeData.type;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__newparam__surface()
	{
		mSidSurfaceMap.insert(std::make_pair(mCurrentNewParamSid, mCurrentSurface));
		mCurrentSurfaceInitFrom.clear();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__surface__init_from()
	{
		mCurrentSurface.imageUniqueId = getUniqueIdFromId((const ParserChar*)mCurrentSurfaceInitFrom.c_str(), COLLADAFW::Image::ID());
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__surface__init_from( const ParserChar* data, size_t length )
	{
		mCurrentSurfaceInitFrom.append((const char* )data, length);
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__profile_COMMON__newparam( const profile_COMMON__newparam__AttributeData& attributeData )
	{
		if ( attributeData.sid )
			mCurrentNewParamSid = (const char *)attributeData.sid;	
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__profile_COMMON__newparam()
	{
		mCurrentNewParamSid.clear();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__newparam__sampler2D()
	{
		mCurrentSampler = new COLLADAFW::Sampler();
		mCurrentSampler->setSamplerType( COLLADAFW::Sampler::SAMPLER_TYPE_2D );
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__newparam__sampler2D()
	{
		SamplerInfo samplerInfo;
		samplerInfo.sampler = mCurrentSampler;
		samplerInfo.id = 0;
		samplerInfo.surfaceSid = mCurrentSamplerSource;
		mSidSamplerInfoMap.insert(std::make_pair(mCurrentNewParamSid, samplerInfo));
		mCurrentSampler = 0;
		mCurrentSamplerSource.clear();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__sampler2D__source( const ParserChar* data, size_t length )
	{
		mCurrentSamplerSource.append((const char* )data, length);
		return true;
	}


	//------------------------------
	bool LibraryEffectsLoader::begin__profile_COMMON__technique( const profile_COMMON__technique__AttributeData& attributeData )
	{
		COLLADAFW::EffectCommon& commonEffect =  *mCurrentEffect->getCommonEffects().back();
		COLLADAFW::SamplerPointerArray& samplerArray = commonEffect.getSamplerPointerArray();
		SidSamplerInfoMap::iterator samplerIt = mSidSamplerInfoMap.begin();
		for ( ; samplerIt != mSidSamplerInfoMap.end(); ++samplerIt)
		{
			SamplerInfo& samplerInfo = samplerIt->second;
			samplerInfo.id = samplerArray.getCount();
			COLLADAFW::Sampler* sampler = samplerInfo.sampler;
			SidSurfaceMap::const_iterator surfaceIt = mSidSurfaceMap.find( samplerInfo.surfaceSid );
			if ( surfaceIt != mSidSurfaceMap.end() )
			{
				const Surface& surface = surfaceIt->second;
				sampler->setSource(surface.imageUniqueId);

				// copy sampler into common effect
				samplerArray.append( sampler->clone() );
			}
		}
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__profile_COMMON__technique()
	{
		SidSamplerInfoMap::iterator samplerIt = mSidSamplerInfoMap.begin();
		for ( ; samplerIt != mSidSamplerInfoMap.end(); ++samplerIt)
		{
			SamplerInfo& samplerInfo = samplerIt->second;
			delete samplerInfo.sampler;
		}
		mSidSamplerInfoMap.clear();
		mSidSurfaceMap.clear();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__technique__constant()
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
		finish();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__emission__color( const emission__color__AttributeData& attributeData )
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_EMISSION;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__emission__color()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		mCurrentColorValueIndex = 0;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__emission__color( const double* data, size_t length )
	{
		return handleColorData(data, length);
	}

	bool LibraryEffectsLoader::begin__emission__texture( const texture__AttributeData& attributeData )
	{
		return handleTexture( attributeData, SHADER_PARAMETER_EMISSION);
	}


	//------------------------------
	bool LibraryEffectsLoader::begin__ambient__color( const ambient__color__AttributeData& attributeData )
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_AMBIENT;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__ambient__color()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		mCurrentColorValueIndex = 0;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__ambient__color( const double* data, size_t length )
	{
		return handleColorData(data, length);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__ambient__texture( const texture__AttributeData& attributeData )
	{
		return handleTexture( attributeData, SHADER_PARAMETER_AMBIENT);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__diffuse__color( const diffuse__color__AttributeData& attributeData )
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_DIFFUSE;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__diffuse__color()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		mCurrentColorValueIndex = 0;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__diffuse__color( const double* data, size_t length )
	{
		return handleColorData(data, length);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__diffuse__texture( const texture__AttributeData& attributeData )
	{
		return handleTexture( attributeData, SHADER_PARAMETER_DIFFUSE);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__specular__color( const specular__color__AttributeData& attributeData )
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_SPECULAR;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__specular__color()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		mCurrentColorValueIndex = 0;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__specular__color( const double* data, size_t length )
	{
		return handleColorData(data, length);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__specular__texture( const texture__AttributeData& attributeData )
	{
		return handleTexture( attributeData, SHADER_PARAMETER_SPECULAR);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__reflective__color( const reflective__color__AttributeData& attributeData )
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_REFLECTIVE;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__reflective__color()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		mCurrentColorValueIndex = 0;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__reflective__color( const double* data, size_t length )
	{
		return handleColorData(data, length);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__reflective__texture( const texture__AttributeData& attributeData )
	{
		return handleTexture( attributeData, SHADER_PARAMETER_REFLECTIVE);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__transparent__color( const transparent__color__AttributeData& attributeData )
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_TRANSPARENT;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__transparent__color()
	{
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		mCurrentColorValueIndex = 0;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__transparent__color( const double* data, size_t length )
	{
		return handleColorData(data, length);
	}

	bool LibraryEffectsLoader::begin__transparent__texture( const texture__AttributeData& attributeData )
	{
		return handleTexture( attributeData, SHADER_PARAMETER_TRANSPARENT);
	}

	//------------------------------
	bool LibraryEffectsLoader::data__shininess__float( double value )
	{
		mCurrentEffect->getCommonEffects().back()->setShininess(value);
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__reflectivity__float( double value )
	{
		mCurrentEffect->getCommonEffects().back()->setReflectivity(value);
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__transparency__float( double value )
	{
        // Set the current transparency value.
        mTransparency = value;

		return true;
	}

    //------------------------------
    double LibraryEffectsLoader::calculateLuminance ( const COLLADAFW::Color& color )
    {
        return ( (color.getRed () * 0.212671) + (color.getGreen () * 0.715160) + (color.getBlue () * 0.072169) );
    }

    //------------------------------
	bool LibraryEffectsLoader::data__index_of_refraction__float( double value )
	{
		mCurrentEffect->getCommonEffects().back()->setIndexOfRefraction(value);
		return true;
	}

    //------------------------------
    bool LibraryEffectsLoader::begin__constant__transparent ( const transparent__AttributeData& attributeData )
    {
        fx_opaque_enum opaque = attributeData.opaque;
        switch ( opaque )
        {
        case fx_opaque_enum__A_ONE:
            mOpaqueMode = A_ONE;
            break;
        case fx_opaque_enum__RGB_ZERO:
            mOpaqueMode = RGB_ZERO;
            break;
        default:
            mOpaqueMode = UNSPECIFIED_OPAQUE;
            break;
        }

        return true;
    }

    //------------------------------
    bool LibraryEffectsLoader::begin__lambert__transparent ( const transparent__AttributeData& attributeData )
    {
        fx_opaque_enum opaque = attributeData.opaque;
        switch ( opaque )
        {
        case fx_opaque_enum__A_ONE:
            mOpaqueMode = A_ONE;
            break;
        case fx_opaque_enum__RGB_ZERO:
            mOpaqueMode = RGB_ZERO;
            break;
        default:
            mOpaqueMode = UNSPECIFIED_OPAQUE;
            break;
        }

        return true;
    }

    //------------------------------
    bool LibraryEffectsLoader::begin__phong__transparent ( const transparent__AttributeData& attributeData )
    {
        fx_opaque_enum opaque = attributeData.opaque;
        switch ( opaque )
        {
        case fx_opaque_enum__A_ONE:
            mOpaqueMode = A_ONE;
            break;
        case fx_opaque_enum__RGB_ZERO:
            mOpaqueMode = RGB_ZERO;
            break;
        default:
            mOpaqueMode = UNSPECIFIED_OPAQUE;
            break;
        }

        return true;
    }

    //------------------------------
    bool LibraryEffectsLoader::begin__blinn__transparent ( const transparent__AttributeData& attributeData )
    {
        fx_opaque_enum opaque = attributeData.opaque;
        switch ( opaque )
        {
        case fx_opaque_enum__A_ONE:
            mOpaqueMode = A_ONE;
            break;
        case fx_opaque_enum__RGB_ZERO:
            mOpaqueMode = RGB_ZERO;
            break;
        default:
            mOpaqueMode = UNSPECIFIED_OPAQUE;
            break;
        }

        return true;
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
                    opaqueColor.setRed ( transparentColor.getAlpha () * mTransparency );
                    opaqueColor.setGreen ( transparentColor.getAlpha () * mTransparency );
                    opaqueColor.setBlue ( transparentColor.getAlpha () * mTransparency );
                    opaqueColor.setAlpha ( transparentColor.getAlpha () * mTransparency );
                    break;
                }
            case LibraryEffectsLoader::A_ZERO:
                {
                    opaqueColor.setRed ( 1 - transparentColor.getAlpha () * mTransparency );
                    opaqueColor.setGreen ( 1 - transparentColor.getAlpha () * mTransparency );
                    opaqueColor.setBlue ( 1 - transparentColor.getAlpha () * mTransparency );
                    opaqueColor.setAlpha ( 1 - transparentColor.getAlpha () * mTransparency );
                    break;
                }
            case LibraryEffectsLoader::RGB_ONE:
                {
                    opaqueColor.setRed ( transparentColor.getRed () * mTransparency );
                    opaqueColor.setGreen ( transparentColor.getGreen () * mTransparency );
                    opaqueColor.setBlue ( transparentColor.getBlue () * mTransparency );
                    opaqueColor.setAlpha ( calculateLuminance ( transparentColor ) * mTransparency );
                    break;
                }
            case LibraryEffectsLoader::RGB_ZERO:
                {
                    opaqueColor.setRed ( 1 - transparentColor.getRed () * mTransparency );
                    opaqueColor.setGreen ( 1 - transparentColor.getGreen () * mTransparency );
                    opaqueColor.setBlue ( 1 - transparentColor.getBlue () * mTransparency );
                    opaqueColor.setAlpha ( 1 - calculateLuminance ( transparentColor ) * mTransparency );
                    break;
                }
            case LibraryEffectsLoader::UNSPECIFIED_OPAQUE:
            default:
                {
                    // A_ONE is the default:
                    opaqueColor.setRed ( transparentColor.getAlpha () * mTransparency );
                    opaqueColor.setGreen ( transparentColor.getAlpha () * mTransparency );
                    opaqueColor.setBlue ( transparentColor.getAlpha () * mTransparency );
                    opaqueColor.setAlpha ( transparentColor.getAlpha () * mTransparency );
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
                    opaqueColor.set ( mTransparency, mTransparency, mTransparency, mTransparency );
                    break;
                }
            case LibraryEffectsLoader::A_ZERO:
            case LibraryEffectsLoader::RGB_ZERO:
                {
                    opaqueColor.set ( 1-mTransparency, 1-mTransparency, 1-mTransparency, 1-mTransparency );
                    break;
                }
            case LibraryEffectsLoader::UNSPECIFIED_OPAQUE:
            default:
                {
                    // A_ONE is the default:
                    opaqueColor.set ( mTransparency, mTransparency, mTransparency, mTransparency );
                    break;
                }
            }
        }

        // Reset the transparent, transparency and opaque values.
        mTransparency = 1;
        mTransparent.setType ( COLLADAFW::ColorOrTexture::UNSPECIFIED );
        mOpaqueMode = LibraryEffectsLoader::UNSPECIFIED_OPAQUE;
    }

} // namespace COLLADASaxFWL
