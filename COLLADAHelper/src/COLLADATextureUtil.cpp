#include "HelperStableHeaders.h"
#include "COLLADATextureUtil.h"

namespace COLLADA
{

	//-----------------------------------------------------------------------
	domImage* TextureUtil::findTextureImage( domCommon_color_or_texture_type::domTexture* texture )
	{
		std::string textureParam = texture->getTexture();
		// texture->color->phong->technique->profile_common
		domProfile_COMMON* profile = daeSafeCast<domProfile_COMMON>(texture->getParent()->getParent()->getParent()->getParent());
		if(profile == 0)
			return 0;

		std::string sid;
		const domCommon_newparam_type_Array& params = profile->getNewparam_array();
		for(size_t p=0,pcount=params.getCount(); p<pcount; ++p)
		{
			domCommon_newparam_typeRef param = params.get(p);
			if(param->getSid() == textureParam)
			{
				domFx_sampler2D_commonRef sampler = param->getSampler2D();
				
				//-- COLLADA 1.4 --
				domFx_sampler2D_common_complexType::domSourceRef source = sampler->getSource();
				sid = source->getValue();
				//-----------------
								
				break;
			}
		}

		if(sid == "")
			return 0;

		std::string imgId;
		for(size_t p=0,pcount=params.getCount(); p<pcount; ++p)
		{
			domCommon_newparam_typeRef param = params.get(p);
			if(param->getSid() == sid)
			{
				//-- COLLADA 1.4 --
				domFx_surface_commonRef surface = param->getSurface();
				daeElement* init_from = surface->getChild("init_from");
				init_from->getCharData(imgId);
				//------------------
				break;				
			}
		}
		
		if(imgId == "")
			return 0;

		std::vector<daeElement*> elements = texture->getDAE()->getDatabase()->idLookup(imgId);
		if(elements.size() == 0)
			return 0;

		return daeSafeCast<domImage>(elements[0]);
	}
	//-----------------------------------------------------------------------
	std::string TextureUtil::findTexureImageFile( domCommon_color_or_texture_type::domTexture* texture )
	{
		domImage* img = COLLADA::TextureUtil::findTextureImage(texture);
		return getImagePath(img);


	}
	//-----------------------------------------------------------------------
	std::string TextureUtil::getImagePath( domImage* img )
	{
		domImage::domInit_fromRef init_from = img->getInit_from();
		xsAnyURI uri = init_from->getValue();
		return cdom::uriToFilePath(uri.getURI());		
	}
}