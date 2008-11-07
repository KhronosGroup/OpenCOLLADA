/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADAEffectUtil.h"
#include "COLLADATextureUtil.h"

namespace COLLADADomHelper
{
	static domFx_color_common FALLBACK_COLOR;
	static domFx_color_common DEFAULT_SPECULAR_COLOR;
	static domFx_color_common DEFAULT_EMISSIVE_COLOR;
	static domFx_color_common DEFAULT_REFLECTIVE_COLOR;
	static domFx_color_common DEFAULT_AMBIENT_COLOR;
    static domCommon_transparent_typeRef DEFAULT_TRANSPARENT_TYPE;
	static const float DEFAULT_TRANSPARENCY = 1;
	static const float DEFAULT_SHININESS = 0;

	const domFx_color_common& EffectUtil::getFallbackColor()
	{
		if(FALLBACK_COLOR.getCount() == 0)
		{
			FALLBACK_COLOR.append4(1,1,1,1);
		}
		return FALLBACK_COLOR;
	}

	const domFx_color_common& EffectUtil::getDefaultSpecularColor()
	{
		if(DEFAULT_SPECULAR_COLOR.getCount() == 0)
		{
			DEFAULT_SPECULAR_COLOR.append4(0,0,0,1);
		}
		return DEFAULT_SPECULAR_COLOR;
	}

	const domFx_color_common& EffectUtil::getDefaultEmissiveColor()
	{
		if(DEFAULT_EMISSIVE_COLOR.getCount() == 0)
		{
			DEFAULT_EMISSIVE_COLOR.append4(0,0,0,1);
		}
		return DEFAULT_EMISSIVE_COLOR;
	}

	const domFx_color_common& EffectUtil::getDefaultAmbientColor()
	{
		if(DEFAULT_AMBIENT_COLOR.getCount() == 0)
		{
			DEFAULT_AMBIENT_COLOR.append4(0,0,0,1);
		}
		return DEFAULT_AMBIENT_COLOR;
	}

	const domFx_color_common& EffectUtil::getDefaultReflectiveColor()
	{
		if(DEFAULT_REFLECTIVE_COLOR.getCount() == 0)
		{
			DEFAULT_REFLECTIVE_COLOR.append4(0,0,0,1);
		}
		return DEFAULT_REFLECTIVE_COLOR;
	}

	//-----------------------------------------------------------------------
	domProfile_COMMONRef EffectUtil::getCommonProfile( const domEffectRef& effect )
	{
		domFx_profile_abstract_Array& profiles = effect->getFx_profile_abstract_array();
		for(size_t i=0, icount=profiles.getCount(); i<icount; ++i)
		{
			domFx_profile_abstractRef profile = profiles.get(i);
			if(profile->getElementType() == COLLADA_TYPE::PROFILE_COMMON)
			{
				return daeSafeCast<domProfile_COMMON>(profile);
			}
		}
		return 0;
	}
	//-----------------------------------------------------------------------
	domProfile_COMMON::domTechnique::domPhongRef EffectUtil::getPhong(  const domEffectRef& effect )
	{
		domProfile_COMMONRef commonProfile = getCommonProfile(effect);
		if(commonProfile == 0)
			return 0;

		domProfile_COMMON::domTechniqueRef technique = commonProfile->getTechnique();
		if(technique == 0)
			return 0;

		return technique->getPhong();
	}

	//-----------------------------------------------------------------------
	const domFx_color_common& EffectUtil::getAmbientColor( const domEffectRef& effect, const ShaderType shaderType /*= ALL*/ )
	{
		domProfile_COMMON::domTechnique::domPhongRef phong = 0;
		domProfile_COMMON::domTechnique::domBlinnRef blinn = 0;
		domProfile_COMMON::domTechnique::domLambertRef lambert = 0;

		switch (shaderType)
		{
		case PHONG:
			phong = getPhong(effect);
			break;

		case BLINN:
			blinn = getBlinn(effect);
			break;

		case LAMBERT:
			lambert = getLambert(effect);
			break;

		default:
			phong = getPhong(effect);
			blinn = getBlinn(effect);
			lambert = getLambert(effect);
			break;
		}

		if(phong == 0 && shaderType == PHONG)
			return getDefaultAmbientColor();

		if(lambert == 0 && shaderType == LAMBERT)
			return getDefaultAmbientColor();

		if(blinn == 0 && shaderType == BLINN)
			return getDefaultAmbientColor();

		domCommon_color_or_texture_typeRef color_or_texture = NULL;
		
		if (phong)
			color_or_texture = phong->getAmbient();
		if (blinn)
			color_or_texture = blinn->getAmbient();
		if (lambert)
			color_or_texture = lambert->getAmbient();

		if(color_or_texture == 0)
			return getDefaultAmbientColor();

		domCommon_color_or_texture_type_complexType::domColorRef color = color_or_texture->getColor();
		if(color == 0)
			return getDefaultAmbientColor();

		domFx_color_common& value = color->getValue();
		if(value.getCount() == 0)
			return getDefaultAmbientColor();

		return value;
	}
	//-----------------------------------------------------------------------
	const domFx_color_common& EffectUtil::getDiffuseColor(const domEffectRef& effect, const ShaderType shaderType /*= ALL*/ )
	{
		domProfile_COMMON::domTechnique::domPhongRef phong = 0;
		domProfile_COMMON::domTechnique::domBlinnRef blinn = 0;
		domProfile_COMMON::domTechnique::domLambertRef lambert = 0;

		switch (shaderType)
		{
		case PHONG:
			phong = getPhong(effect);
			break;

		case BLINN:
			blinn = getBlinn(effect);
			break;

		case LAMBERT:
			lambert = getLambert(effect);
			break;

		default:
			phong = getPhong(effect);
			blinn = getBlinn(effect);
			lambert = getLambert(effect);
			break;
		}

		if(phong == 0 && shaderType == PHONG)
			return getFallbackColor();

		if(lambert == 0 && shaderType == LAMBERT)
			return getFallbackColor();

		if(blinn == 0 && shaderType == BLINN)
			return getFallbackColor();

		domCommon_color_or_texture_typeRef color_or_texture = NULL;

		if (phong)
			color_or_texture = phong->getDiffuse();
		if (blinn)
			color_or_texture = blinn->getDiffuse();
		if (lambert)
			color_or_texture = lambert->getDiffuse();
		
		if(color_or_texture == 0)
			return getFallbackColor();

		domCommon_color_or_texture_type_complexType::domColorRef color = color_or_texture->getColor();
		if(color == 0)
			return getFallbackColor();

		domFx_color_common& value = color->getValue();
		if(value.getCount() == 0)
			return getFallbackColor();

		return value;
	}
	//-----------------------------------------------------------------------
	const domFx_color_common& EffectUtil::getSpecularColor( const domEffectRef& effect, const ShaderType shaderType /*= ALL*/ )
	{
		domProfile_COMMON::domTechnique::domPhongRef phong = 0;
		domProfile_COMMON::domTechnique::domBlinnRef blinn = 0;

		switch (shaderType)
		{
		case PHONG:
			phong = getPhong(effect);
			break;

		case BLINN:
			blinn = getBlinn(effect);
			break;


		default:
			phong = getPhong(effect);
			blinn = getBlinn(effect);
			break;
		}

		if(phong == 0 && shaderType == PHONG)
			return getDefaultSpecularColor();

		if(blinn == 0 && shaderType == BLINN)
			return getDefaultSpecularColor();

		domCommon_color_or_texture_typeRef color_or_texture = NULL;

		if (phong)
			color_or_texture = phong->getSpecular();
		if (blinn)
			color_or_texture = blinn->getSpecular();
	
		if(color_or_texture == 0)
			return getDefaultSpecularColor();

		domCommon_color_or_texture_type_complexType::domColorRef color = color_or_texture->getColor();
		if(color == 0)
			return getDefaultSpecularColor();

		domFx_color_common& value = color->getValue();
		if(value.getCount() == 0)
			return getDefaultSpecularColor();

		return value;
	}
	//-----------------------------------------------------------------------
	const domFx_color_common& EffectUtil::getEmissiveColor( const domEffectRef& effect, const ShaderType shaderType /*= ALL*/ )
	{
		domProfile_COMMON::domTechnique::domPhongRef phong = 0;
		domProfile_COMMON::domTechnique::domConstantRef constant = 0;
		domProfile_COMMON::domTechnique::domBlinnRef blinn = 0;
		domProfile_COMMON::domTechnique::domLambertRef lambert = 0;

		switch (shaderType)
		{
		case PHONG:
			phong = getPhong(effect);
			break;

		case CONSTANT:
			constant = getConstant(effect);
			break;

		case BLINN:
			blinn = getBlinn(effect);
			break;

		case LAMBERT:
			lambert = getLambert(effect);
			break;

		default:
			phong = getPhong(effect);
			constant = getConstant(effect);
			blinn = getBlinn(effect);
			lambert = getLambert(effect);
			break;
		}

		if(phong == 0 && shaderType == PHONG)
			return getDefaultEmissiveColor();

		if(lambert == 0 && shaderType == LAMBERT)
			return getDefaultEmissiveColor();

		if(blinn == 0 && shaderType == BLINN)
			return getDefaultEmissiveColor();

		if(constant == 0 && shaderType == CONSTANT)
			return getDefaultEmissiveColor();

		domCommon_color_or_texture_typeRef color_or_texture = NULL;

		if (phong)
			color_or_texture = phong->getEmission();
		if (blinn)
			color_or_texture = blinn->getEmission();
		if (lambert)
			color_or_texture = lambert->getEmission();
		if (constant)
			color_or_texture = constant->getEmission();

		if(color_or_texture == 0)
			return getDefaultEmissiveColor();

		domCommon_color_or_texture_type_complexType::domColorRef color = color_or_texture->getColor();
		if(color == 0)
			return getDefaultEmissiveColor();

		domFx_color_common& value = color->getValue();
		if(value.getCount() == 0)
			return getDefaultEmissiveColor();

		return value;
	}

	//-----------------------------------------------------------------------
	float EffectUtil::getShininess( const domEffectRef& effect, const ShaderType shaderType /*= ALL*/ )
	{
		domProfile_COMMON::domTechnique::domPhongRef phong = 0;
		domProfile_COMMON::domTechnique::domBlinnRef blinn = 0;

		switch (shaderType)
		{
		case PHONG:
			phong = getPhong(effect);
			break;

		case BLINN:
			blinn = getBlinn(effect);
			break;

		default:
			phong = getPhong(effect);
			blinn = getBlinn(effect);
			break;
		}

		if(phong == 0 && shaderType == PHONG)
			return DEFAULT_SHININESS;
	
		if(blinn == 0 && shaderType == BLINN)
			return DEFAULT_SHININESS;

		domCommon_float_or_param_typeRef shininess = NULL;

		if (phong)
			shininess = phong->getShininess();
		if (blinn)
			shininess = blinn->getShininess();
	
		if(shininess == 0)
			return DEFAULT_SHININESS;

		if(shininess->getFloat() == 0)
			return DEFAULT_SHININESS;

		return (float) shininess->getFloat()->getValue();
	}

    //-----------------------------------------------------------------------
	float EffectUtil::getTransparency( const domEffectRef& effect, const ShaderType shaderType /*= ALL*/ )
	{
		domProfile_COMMON::domTechnique::domPhongRef phong = 0;
		domProfile_COMMON::domTechnique::domConstantRef constant = 0;
		domProfile_COMMON::domTechnique::domBlinnRef blinn = 0;
		domProfile_COMMON::domTechnique::domLambertRef lambert = 0;

		switch (shaderType)
		{
		case PHONG:
			phong = getPhong(effect);
			break;

		case CONSTANT:
			constant = getConstant(effect);
			break;

		case BLINN:
			blinn = getBlinn(effect);
			break;

		case LAMBERT:
			lambert = getLambert(effect);
			break;

		default:
			phong = getPhong(effect);
			constant = getConstant(effect);
			blinn = getBlinn(effect);
			lambert = getLambert(effect);
			break;
		}

		if(phong == 0 && shaderType == PHONG)
			return DEFAULT_TRANSPARENCY;

		if(lambert == 0 && shaderType == LAMBERT)
			return DEFAULT_TRANSPARENCY;

		if(blinn == 0 && shaderType == BLINN)
			return DEFAULT_TRANSPARENCY;

		if(constant == 0 && shaderType == CONSTANT)
			return DEFAULT_TRANSPARENCY;

		domCommon_float_or_param_typeRef transparency = NULL;

		if (phong)
			transparency = phong->getTransparency();
		if (blinn)
			transparency = blinn->getTransparency();
		if (lambert)
			transparency = lambert->getTransparency();
		if (constant)
			transparency = constant->getTransparency();

		if(transparency == 0)
			return DEFAULT_TRANSPARENCY;

		if(transparency->getFloat() == 0)
			return DEFAULT_TRANSPARENCY;

		return (float)transparency->getFloat()->getValue();
	}
	
    //-----------------------------------------------------------------------
    domCommon_transparent_typeRef EffectUtil::getTransparent( const domEffectRef& effect, const ShaderType shaderType /*= ALL*/ )
    {
        domProfile_COMMON::domTechnique::domPhongRef phong = 0;
        domProfile_COMMON::domTechnique::domConstantRef constant = 0;
        domProfile_COMMON::domTechnique::domBlinnRef blinn = 0;
        domProfile_COMMON::domTechnique::domLambertRef lambert = 0;

        switch (shaderType)
        {
        case PHONG:
            phong = getPhong(effect);
            break;

        case CONSTANT:
            constant = getConstant(effect);
            break;

        case BLINN:
            blinn = getBlinn(effect);
            break;

        case LAMBERT:
            lambert = getLambert(effect);
            break;

        default:
            phong = getPhong(effect);
            constant = getConstant(effect);
            blinn = getBlinn(effect);
            lambert = getLambert(effect);
            break;
        }

        if(phong == 0 && shaderType == PHONG)
            return DEFAULT_TRANSPARENT_TYPE;

        if(lambert == 0 && shaderType == LAMBERT)
            return DEFAULT_TRANSPARENT_TYPE;

        if(blinn == 0 && shaderType == BLINN)
            return DEFAULT_TRANSPARENT_TYPE;

        if(constant == 0 && shaderType == CONSTANT)
            return DEFAULT_TRANSPARENT_TYPE;

        domCommon_transparent_typeRef transparent = NULL;

        if (phong)
            transparent = phong->getTransparent();
        if (blinn)
            transparent = blinn->getTransparent();
        if (lambert)
            transparent = lambert->getTransparent();
        if (constant)
            transparent = constant->getTransparent();

        if (transparent == 0)
            return DEFAULT_TRANSPARENT_TYPE;

        return transparent;
    }

	//-----------------------------------------------------------------------
	void EffectUtil::getTextureImages( const domEffectRef& effect, TextureImageList& list, const ColorType colorType /*= ALL*/, const ShaderType shaderType /*= ALL*/ )
	{
		daeElementRef element = 0;

		switch (shaderType)
		{
		case PHONG:
			element = getPhong(effect);
			break;

		case CONSTANT:
			element = getConstant(effect);
			break;

		case BLINN:
			element = getBlinn(effect);
			break;

		case LAMBERT:
			element = getLambert(effect);
			break;

		default:
			element = getPhong(effect);
			if (element == 0)
				element = getConstant(effect);
			if (element == 0)
				element = getBlinn(effect);
			if (element == 0)
				element = getLambert(effect);
			break;
		}

		if(element == 0 && shaderType == PHONG)
			return;

		if(element == 0 && shaderType == LAMBERT)
			return;

		if(element == 0 && shaderType == BLINN)
			return;

		if(element == 0 && shaderType == CONSTANT)
			return;

		if(element != 0)
		{
			domCommon_color_or_texture_type_Array colorsOrTextures;
			element->getChildrenByType(colorsOrTextures);
			for(size_t c=0,ccount=colorsOrTextures.getCount(); c<ccount; ++c)
			{
				domCommon_color_or_texture_typeRef colorOrTexture = colorsOrTextures.get(c);
				if(colorOrTexture)
				{
					if (colorType != ALL_COLORS && 
						(
							(strcmp(colorOrTexture->getElementName(), COLLADA_ELEMENT_DIFFUSE) == 0 && colorType != DIFFUSE)
						||	(strcmp(colorOrTexture->getElementName(), COLLADA_ELEMENT_SPECULAR) == 0 && colorType != SPECULAR)
						||	(strcmp(colorOrTexture->getElementName(), COLLADA_ELEMENT_AMBIENT) == 0 && colorType != AMBIENT)
						||	(strcmp(colorOrTexture->getElementName(), COLLADA_ELEMENT_REFLECTIVE) == 0 && colorType != REFLECTIVE)
						||	(strcmp(colorOrTexture->getElementName(), COLLADA_ELEMENT_EMISSION) == 0 && colorType != EMISSIVE))
						)
						continue;
					domCommon_color_or_texture_type_complexType::domTextureRef texture = colorOrTexture->getTexture();
					if(texture != 0)
					{
						domImage* img = TextureUtil::findTextureImage(texture);
						if(img != 0)
						{
							list.push_back(img);
						}
					}
				}		
			}
		}
	}

	//-----------------------------------------------------------------------
	domProfile_COMMON::domTechnique::domLambertRef EffectUtil::getLambert( const domEffectRef& effect )
	{
		domProfile_COMMONRef commonProfile = getCommonProfile(effect);
		if(commonProfile == 0)
			return 0;

		domProfile_COMMON::domTechniqueRef technique = commonProfile->getTechnique();
		if(technique == 0)
			return 0;

		return technique->getLambert();
	}

	//-----------------------------------------------------------------------
	domProfile_COMMON::domTechnique::domBlinnRef EffectUtil::getBlinn( const domEffectRef& effect )
	{
		domProfile_COMMONRef commonProfile = getCommonProfile(effect);
		if(commonProfile == 0)
			return 0;

		domProfile_COMMON::domTechniqueRef technique = commonProfile->getTechnique();
		if(technique == 0)
			return 0;

		return technique->getBlinn();
	}

	//-----------------------------------------------------------------------
	domProfile_COMMON::domTechnique::domConstantRef EffectUtil::getConstant( const domEffectRef& effect )
	{
		domProfile_COMMONRef commonProfile = getCommonProfile(effect);
		if(commonProfile == 0)
			return 0;

		domProfile_COMMON::domTechniqueRef technique = commonProfile->getTechnique();
		if(technique == 0)
			return 0;

		return technique->getConstant();
	}

	//-----------------------------------------------------------------------
	const EffectUtil::ShaderType EffectUtil::getShaderType( const domEffectRef& effect )
	{
		domProfile_COMMONRef commonProfile = getCommonProfile(effect);
		if(commonProfile == 0)
			return UNKNOWN;

		domProfile_COMMON::domTechniqueRef technique = commonProfile->getTechnique();
		if(technique == 0)
			return UNKNOWN;

		if (technique->getPhong() != 0)
			return PHONG;
		if (technique->getBlinn() != 0)
			return BLINN;
		if (technique->getLambert() != 0)
			return LAMBERT;
		if (technique->getConstant() != 0)
			return CONSTANT;

		return UNKNOWN;
	}

	//-----------------------------------------------------------------------
	const domFx_color_common& EffectUtil::getReflectiveColor( const domEffectRef& effect, const ShaderType shaderType /*= ALL*/ )
	{
		domProfile_COMMON::domTechnique::domPhongRef phong = 0;
		domProfile_COMMON::domTechnique::domConstantRef constant = 0;
		domProfile_COMMON::domTechnique::domBlinnRef blinn = 0;
		domProfile_COMMON::domTechnique::domLambertRef lambert = 0;

		switch (shaderType)
		{
		case PHONG:
			phong = getPhong(effect);
			break;

		case CONSTANT:
			constant = getConstant(effect);
			break;

		case BLINN:
			blinn = getBlinn(effect);
			break;

		case LAMBERT:
			lambert = getLambert(effect);
			break;

		default:
			phong = getPhong(effect);
			constant = getConstant(effect);
			blinn = getBlinn(effect);
			lambert = getLambert(effect);
			break;
		}

		if(phong == 0 && shaderType == PHONG)
			return getDefaultReflectiveColor();

		if(lambert == 0 && shaderType == LAMBERT)
			return getDefaultReflectiveColor();

		if(blinn == 0 && shaderType == BLINN)
			return getDefaultReflectiveColor();

		if(constant == 0 && shaderType == CONSTANT)
			return getDefaultReflectiveColor();

		domCommon_color_or_texture_typeRef color_or_texture = NULL;

		if (phong)
			color_or_texture = phong->getReflective();
		if (blinn)
			color_or_texture = blinn->getReflective();
		if (lambert)
			color_or_texture = lambert->getReflective();
		if (constant)
			color_or_texture = constant->getReflective();

		if(color_or_texture == 0)
			return getDefaultReflectiveColor();

		domCommon_color_or_texture_type_complexType::domColorRef color = color_or_texture->getColor();
		if(color == 0)
			return getDefaultReflectiveColor();

		domFx_color_common& value = color->getValue();
		if(value.getCount() == 0)
			return getDefaultReflectiveColor();

		return value;
	}


}