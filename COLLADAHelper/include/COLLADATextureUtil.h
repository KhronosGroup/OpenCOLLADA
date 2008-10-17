#ifndef __COLLADA_TEXTURE_UTIL_H__
#define __COLLADA_TEXTURE_UTIL_H__

namespace COLLADA
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