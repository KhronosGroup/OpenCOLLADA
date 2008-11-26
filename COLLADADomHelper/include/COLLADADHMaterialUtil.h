/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MATERIAL_UTIL_H__
#define __COLLADA_MATERIAL_UTIL_H__

#include "COLLADADHStableHeaders.h"
#include "COLLADADHEffectUtil.h"

namespace COLLADADH 
{

    class MaterialUtil
    {
    public:
        static domEffectRef getEffect(const domMaterialRef& material);		
        		
		static const domFx_color_common& getAmbientColor(const domMaterialRef& material);
        static const domFx_color_common& getDiffuseColor(const domMaterialRef& material);		
		static const domFx_color_common& getSpecularColor(const domMaterialRef& material);
		static const domFx_color_common& getEmissiveColor(const domMaterialRef& material);
		
		static float getShininess(const domMaterialRef& material);
		static float getTransparency(const domMaterialRef& material);
		
		static void getTextureImages(const domMaterialRef& material, TextureImageList& list);
    };
}

#endif // __COLLADA_MATERIAL_UTIL_H__
