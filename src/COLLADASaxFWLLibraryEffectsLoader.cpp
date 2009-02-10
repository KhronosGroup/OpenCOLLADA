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

namespace COLLADASaxFWL
{

    //------------------------------
	LibraryEffectsLoader::LibraryEffectsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentEffect(0)
		, mCurrentProfile(PROFILE_UNKNOWN)
		, mCurrentShaderParameterType(UNKNOWN_SHADER_TYPE)
		, mCurrentColorValueIndex(0)

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
				case SHADER_PARAMETER_TRANSPARANT:
					{
						colorOrTexture = &mCurrentEffect->getCommonEffects().back()->getTransparent();
						break;
					}
				}
				colorOrTexture->setType(COLLADAFW::ColorOrTexture::COLOR);
				handleColorData(data, length, colorOrTexture->getColor());
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
	bool LibraryEffectsLoader::begin__transparent__color( const transparent__color__AttributeData& attributeData )
	{
		mCurrentShaderParameterType = SHADER_PARAMETER_TRANSPARANT;
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
		mCurrentEffect->getCommonEffects().back()->setTransparency(value);
		return true;
	}

	//------------------------------
	bool LibraryEffectsLoader::data__index_of_refraction__float( double value )
	{
		mCurrentEffect->getCommonEffects().back()->setIndexOfRefraction(value);
		return true;
	}

} // namespace COLLADASaxFWL
