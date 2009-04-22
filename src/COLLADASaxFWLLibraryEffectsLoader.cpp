/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	COLLADAFW::ColorOrTexture* LibraryEffectsLoader::getCurrentColorOrTexture()
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

	//------------------------------
	bool LibraryEffectsLoader::begin__effect( const effect__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__effect(attributeData)); 
		mCurrentEffect = FW_NEW COLLADAFW::Effect(getUniqueIdFromId(attributeData.id, COLLADAFW::Effect::ID()).getObjectId());
		
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
		SaxVirtualFunctionTest(end__effect()); 
		getFileLoader()->addEffect(mCurrentEffect);
		mCurrentEffect = 0;
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__profile_COMMON( const profile_COMMON__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__profile_COMMON(attributeData)); 
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
		SaxVirtualFunctionTest(end__profile_COMMON()); 
		// Calculate the opacity value.
		calculateOpacity ();

		mTransparent.getColor ().set ( -1, -1, -1, -1 );

		mCurrentProfile = PROFILE_UNKNOWN;
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__surface____fx_surface_common( const surface____fx_surface_common__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__surface____fx_surface_common(attributeData)); 
		mCurrentSurface.surfaceType = attributeData.type;
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__surface____fx_surface_common()
	{
		SaxVirtualFunctionTest(end__surface____fx_surface_common()); 
		mSidSurfaceMap.insert(std::make_pair(mCurrentNewParamSid, mCurrentSurface));
		mCurrentSurfaceInitFrom.clear();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__init_from____fx_surface_init_from_common()
	{
		SaxVirtualFunctionTest(end__init_from____fx_surface_init_from_common()); 
		mCurrentSurface.imageUniqueId = getUniqueIdFromId((const ParserChar*)mCurrentSurfaceInitFrom.c_str(), COLLADAFW::Image::ID());
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__init_from____fx_surface_init_from_common( const ParserChar* data, size_t length )
	{
		SaxVirtualFunctionTest(data__init_from____fx_surface_init_from_common(data, length)); 
		mCurrentSurfaceInitFrom.append((const char* )data, length);
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__newparam____common_newparam_type( const newparam____common_newparam_type__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__newparam____common_newparam_type(attributeData)); 
		if ( attributeData.sid )
			mCurrentNewParamSid = (const char *)attributeData.sid;	
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__newparam____common_newparam_type()
	{
		SaxVirtualFunctionTest(end__newparam____common_newparam_type()); 
		mCurrentNewParamSid.clear();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__sampler2D____fx_sampler2D_common()
	{
		SaxVirtualFunctionTest(begin__sampler2D____fx_sampler2D_common()); 
		mCurrentSampler = new COLLADAFW::Sampler();
		mCurrentSampler->setSamplerType( COLLADAFW::Sampler::SAMPLER_TYPE_2D );
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__sampler2D____fx_sampler2D_common()
	{
		SaxVirtualFunctionTest(end__sampler2D____fx_sampler2D_common()); 
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
	bool LibraryEffectsLoader::data__source____NCName( const ParserChar* data, size_t length )
	{
		SaxVirtualFunctionTest(data__source____NCName(data, length)); 
		mCurrentSamplerSource.append((const char* )data, length);
		return true;
	}


	//------------------------------
	bool LibraryEffectsLoader::begin__profile_COMMON__technique( const profile_COMMON__technique__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__profile_COMMON__technique(attributeData)); 
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
		SaxVirtualFunctionTest(end__profile_COMMON__technique()); 
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
	bool LibraryEffectsLoader::begin__profile_COMMON__technique__constant()
	{
		SaxVirtualFunctionTest(begin__profile_COMMON__technique__constant()); 
		return setCommonEffectShaderType(COLLADAFW::EffectCommon::SHADER_CONSTANT);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__lambert()
	{
		SaxVirtualFunctionTest(begin__lambert()); 
		return setCommonEffectShaderType(COLLADAFW::EffectCommon::SHADER_LAMBERT);
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__blinn()
	{
		SaxVirtualFunctionTest(begin__blinn()); 
		return setCommonEffectShaderType(COLLADAFW::EffectCommon::SHADER_BLINN);
	}


	//------------------------------
	bool LibraryEffectsLoader::begin__phong()
	{
		SaxVirtualFunctionTest(begin__phong()); 
		return setCommonEffectShaderType(COLLADAFW::EffectCommon::SHADER_PHONG);
	}

	//------------------------------
	bool LibraryEffectsLoader::end__library_effects()
	{
		SaxVirtualFunctionTest(end__library_effects()); 
		finish();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__common_color_or_texture_type____color( const common_color_or_texture_type____color__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__common_color_or_texture_type____color(attributeData)); 
		COLLADAFW::ColorOrTexture* colorOrTexture = getCurrentColorOrTexture();
		addToSidTree( 0, attributeData.sid, &colorOrTexture->getColor() );
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__common_color_or_texture_type____color()
	{
		SaxVirtualFunctionTest(end__common_color_or_texture_type____color()); 
		mCurrentColorValueIndex = 0;
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__common_color_or_texture_type____color( const float* data, size_t length )
	{
		SaxVirtualFunctionTest(data__common_color_or_texture_type____color(data, length)); 
		return handleColorData(data, length);
	}

	bool LibraryEffectsLoader::begin__texture( const texture__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__texture(attributeData)); 
		return handleTexture( attributeData);
	}



	//------------------------------
	bool LibraryEffectsLoader::data__common_float_or_param_type____float( float value )
	{
		SaxVirtualFunctionTest(data__common_float_or_param_type____float(value)); 
		switch ( mCurrentShaderParameterType)
		{
		case SHADER_PARAMETER_SHININESS:
			mCurrentEffect->getCommonEffects().back()->setShininess(value);
			break;
		case SHADER_PARAMETER_REFLECTIVITY:
			mCurrentEffect->getCommonEffects().back()->setReflectivity(value);
			break;
		case SHADER_PARAMETER_INDEX_OF_REFRECTION:
			mCurrentEffect->getCommonEffects().back()->setIndexOfRefraction(value);
			break;
		case SHADER_PARAMETER_TRANSPARANCY:
			mTransparency = value;
			break;
		}
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__emission()
	{
		SaxVirtualFunctionTest(begin__emission()); 
		mCurrentShaderParameterType = SHADER_PARAMETER_EMISSION; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__emission()
	{
		SaxVirtualFunctionTest(end__emission()); 
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__ambient____common_color_or_texture_type()
	{
		SaxVirtualFunctionTest(begin__ambient____common_color_or_texture_type());  
		mCurrentShaderParameterType = SHADER_PARAMETER_AMBIENT; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__ambient____common_color_or_texture_type()
	{
		SaxVirtualFunctionTest(end__ambient____common_color_or_texture_type());  
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__diffuse()
	{
		SaxVirtualFunctionTest(begin__diffuse());  
		mCurrentShaderParameterType = SHADER_PARAMETER_DIFFUSE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__diffuse()
	{
		SaxVirtualFunctionTest(end__diffuse());  
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__specular()
	{
		SaxVirtualFunctionTest(begin__specular());  
		mCurrentShaderParameterType = SHADER_PARAMETER_SPECULAR; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__specular()
	{
		SaxVirtualFunctionTest(end__specular());  
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__shininess()
	{
		SaxVirtualFunctionTest(begin__shininess()); 
		mCurrentShaderParameterType = SHADER_PARAMETER_SHININESS; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__shininess()
	{
		SaxVirtualFunctionTest(end__shininess());  
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__reflective()
	{
		SaxVirtualFunctionTest(begin__reflective());  
		mCurrentShaderParameterType = SHADER_PARAMETER_REFLECTIVE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__reflective()
	{
		SaxVirtualFunctionTest(end__reflective());  
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__reflectivity()
	{
		SaxVirtualFunctionTest(begin__reflectivity());  
		mCurrentShaderParameterType = SHADER_PARAMETER_REFLECTIVITY; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__reflectivity()
	{
		SaxVirtualFunctionTest(end__reflectivity());  
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__transparent ( const transparent__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__transparent(attributeData));  
		ENUM__fx_opaque_enum opaque = attributeData.opaque;
		switch ( opaque )
		{
		case ENUM__fx_opaque_enum__A_ONE:
			mOpaqueMode = A_ONE;
			break;
		case ENUM__fx_opaque_enum__RGB_ZERO:
			mOpaqueMode = RGB_ZERO;
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
		SaxVirtualFunctionTest(end__transparent());  
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__transparency()
	{
		SaxVirtualFunctionTest(begin__transparency());  
		mCurrentShaderParameterType = SHADER_PARAMETER_TRANSPARANCY; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__transparency()
	{
		SaxVirtualFunctionTest(end__transparency()); 
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::begin__index_of_refraction()
	{
		SaxVirtualFunctionTest(begin__index_of_refraction());  
		mCurrentShaderParameterType = SHADER_PARAMETER_INDEX_OF_REFRECTION; 
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::end__index_of_refraction()
	{
		SaxVirtualFunctionTest(end__index_of_refraction());  
		mCurrentShaderParameterType = UNKNOWN_SHADER_TYPE; 
		return true;
	}
} // namespace COLLADASaxFWL
