#include "HelperStableHeaders.h"
#include "COLLADAMaterialUtil.h"
#include "COLLADAEffectUtil.h"

namespace COLLADA {

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
			return COLLADA::EffectUtil::getFallbackColor();

		return COLLADA::EffectUtil::getAmbientColor(effect);
	}
	//-----------------------------------------------------------------------
	const domFx_color_common& MaterialUtil::getDiffuseColor( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return COLLADA::EffectUtil::getFallbackColor();

		return COLLADA::EffectUtil::getDiffuseColor(effect);
	}
	//-----------------------------------------------------------------------
	const domFx_color_common& MaterialUtil::getSpecularColor( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return COLLADA::EffectUtil::getFallbackColor();

		return COLLADA::EffectUtil::getSpecularColor(effect);
	}
	//-----------------------------------------------------------------------
	const domFx_color_common& MaterialUtil::getEmissiveColor( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return COLLADA::EffectUtil::getFallbackColor();

		return COLLADA::EffectUtil::getEmissiveColor(effect);

	}
	//-----------------------------------------------------------------------
	float MaterialUtil::getShininess( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return 0;

		return COLLADA::EffectUtil::getShininess(effect);
	}	
	//-----------------------------------------------------------------------
	float MaterialUtil::getTransparency( const domMaterialRef& material )
	{
		domEffectRef effect = getEffect(material);
		if(effect == 0)
			return 0;

		return COLLADA::EffectUtil::getTransparency(effect);

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
