/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADAMaterialUtil.h"
#include "COLLADAEffectUtil.h"

namespace COLLADADH 
{

    static const domFx_color_common EMTPY;
    
    //-----------------------------------------------------------------------
    domEffectRef MaterialUtil::getEffect( const domMaterialRef& material )
    {
        domInstance_effectRef effectInstance = material->getInstance_effect();
        return daeSafeCast<domEffect>(effectInstance->getUrl().getElement());
    }
	//-----------------------------------------------------------------------
	const domFx_color_common& MaterialUtil::getAmbientColor( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return COLLADADH::EffectUtil::getFallbackColor();

		return COLLADADH::EffectUtil::getAmbientColor(effect);
	}
	//-----------------------------------------------------------------------
	const domFx_color_common& MaterialUtil::getDiffuseColor( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return COLLADADH::EffectUtil::getFallbackColor();

		return COLLADADH::EffectUtil::getDiffuseColor(effect);
	}
	//-----------------------------------------------------------------------
	const domFx_color_common& MaterialUtil::getSpecularColor( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return COLLADADH::EffectUtil::getFallbackColor();

		return COLLADADH::EffectUtil::getSpecularColor(effect);
	}
	//-----------------------------------------------------------------------
	const domFx_color_common& MaterialUtil::getEmissiveColor( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return COLLADADH::EffectUtil::getFallbackColor();

		return COLLADADH::EffectUtil::getEmissiveColor(effect);

	}
	//-----------------------------------------------------------------------
	float MaterialUtil::getShininess( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return 0;

		return COLLADADH::EffectUtil::getShininess(effect);
	}	
	//-----------------------------------------------------------------------
	float MaterialUtil::getTransparency( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return 0;

		return COLLADADH::EffectUtil::getTransparency(effect);

	}
	//-----------------------------------------------------------------------
	void MaterialUtil::getTextureImages( const domMaterialRef& material, TextureImageList& list )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return;

		return EffectUtil::getTextureImages(effect, list);
	}
}
