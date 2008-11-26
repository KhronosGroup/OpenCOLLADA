/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_TEXTURE_UTIL_H__
#define __COLLADA_TEXTURE_UTIL_H__

namespace COLLADADH
{

	class TextureUtil
	{
	public:
		static domImage* findTextureImage(domCommon_color_or_texture_type::domTexture* texture);
		static std::string findTexureImageFile(domCommon_color_or_texture_type::domTexture* texture);
		static std::string getImagePath( domImage* img);
	private:
		TextureUtil();
	};
}

#endif // __COLLADA_TEXTURE_UTIL_H__