/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTRENDERFILTER_H__
#define __MayaDM_OBJECTRENDERFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
/*Dependency node that filters selection lists by name.*/
class ObjectRenderFilter : public ObjectFilter
{
public:
public:
	ObjectRenderFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectRenderFilter"){}
	virtual ~ObjectRenderFilter(){}
	/*Filter for shaders*/
	void setShaders(bool shad){if(shad == 0) return; fprintf_s(mFile, "setAttr \".shad\" %i;\n", shad);}
	/*Filter for shaders*/
	void setShaders(const BoolID& shad){fprintf_s(mFile,"connectAttr \"");shad.write(mFile);fprintf_s(mFile,"\" \"%s.shad\";\n",mName.c_str());}
	/*Filter for textures*/
	void setTextures(bool txtr){if(txtr == 0) return; fprintf_s(mFile, "setAttr \".txtr\" %i;\n", txtr);}
	/*Filter for textures*/
	void setTextures(const BoolID& txtr){fprintf_s(mFile,"connectAttr \"");txtr.write(mFile);fprintf_s(mFile,"\" \"%s.txtr\";\n",mName.c_str());}
	/*Filter for 2D textures*/
	void setTextures2D(bool tx2d){if(tx2d == 0) return; fprintf_s(mFile, "setAttr \".tx2d\" %i;\n", tx2d);}
	/*Filter for 2D textures*/
	void setTextures2D(const BoolID& tx2d){fprintf_s(mFile,"connectAttr \"");tx2d.write(mFile);fprintf_s(mFile,"\" \"%s.tx2d\";\n",mName.c_str());}
	/*Filter for 3D textures*/
	void setTextures3D(bool tx3d){if(tx3d == 0) return; fprintf_s(mFile, "setAttr \".tx3d\" %i;\n", tx3d);}
	/*Filter for 3D textures*/
	void setTextures3D(const BoolID& tx3d){fprintf_s(mFile,"connectAttr \"");tx3d.write(mFile);fprintf_s(mFile,"\" \"%s.tx3d\";\n",mName.c_str());}
	/*Filter for lights*/
	void setLights(bool lght){if(lght == 0) return; fprintf_s(mFile, "setAttr \".lght\" %i;\n", lght);}
	/*Filter for lights*/
	void setLights(const BoolID& lght){fprintf_s(mFile,"connectAttr \"");lght.write(mFile);fprintf_s(mFile,"\" \"%s.lght\";\n",mName.c_str());}
	/*Filter for exclusive lights*/
	void setExclusiveLights(bool exlt){if(exlt == 0) return; fprintf_s(mFile, "setAttr \".exlt\" %i;\n", exlt);}
	/*Filter for exclusive lights*/
	void setExclusiveLights(const BoolID& exlt){fprintf_s(mFile,"connectAttr \"");exlt.write(mFile);fprintf_s(mFile,"\" \"%s.exlt\";\n",mName.c_str());}
	/*Filter for lights*/
	void setNonExclusiveLights(bool nxlt){if(nxlt == 0) return; fprintf_s(mFile, "setAttr \".nxlt\" %i;\n", nxlt);}
	/*Filter for lights*/
	void setNonExclusiveLights(const BoolID& nxlt){fprintf_s(mFile,"connectAttr \"");nxlt.write(mFile);fprintf_s(mFile,"\" \"%s.nxlt\";\n",mName.c_str());}
	/*Filter for post process nodes*/
	void setPostProcess(bool post){if(post == 0) return; fprintf_s(mFile, "setAttr \".post\" %i;\n", post);}
	/*Filter for post process nodes*/
	void setPostProcess(const BoolID& post){fprintf_s(mFile,"connectAttr \"");post.write(mFile);fprintf_s(mFile,"\" \"%s.post\";\n",mName.c_str());}
	/*Filter for utility nodes*/
	void setUtility(bool util){if(util == 0) return; fprintf_s(mFile, "setAttr \".util\" %i;\n", util);}
	/*Filter for utility nodes*/
	void setUtility(const BoolID& util){fprintf_s(mFile,"connectAttr \"");util.write(mFile);fprintf_s(mFile,"\" \"%s.util\";\n",mName.c_str());}
	/*Filter for sets containing renderable objects*/
	void setRenderableObjectSets(bool ros){if(ros == 0) return; fprintf_s(mFile, "setAttr \".ros\" %i;\n", ros);}
	/*Filter for sets containing renderable objects*/
	void setRenderableObjectSets(const BoolID& ros){fprintf_s(mFile,"connectAttr \"");ros.write(mFile);fprintf_s(mFile,"\" \"%s.ros\";\n",mName.c_str());}
	/*Filter for sets containing lights*/
	void setLightSets(bool ls){if(ls == 0) return; fprintf_s(mFile, "setAttr \".ls\" %i;\n", ls);}
	/*Filter for sets containing lights*/
	void setLightSets(const BoolID& ls){fprintf_s(mFile,"connectAttr \"");ls.write(mFile);fprintf_s(mFile,"\" \"%s.ls\";\n",mName.c_str());}
	/*Filter for shaders*/
	BoolID getShaders(){char buffer[4096];sprintf_s (buffer, "%s.shad",mName.c_str());return (const char*)buffer;}
	/*Filter for textures*/
	BoolID getTextures(){char buffer[4096];sprintf_s (buffer, "%s.txtr",mName.c_str());return (const char*)buffer;}
	/*Filter for 2D textures*/
	BoolID getTextures2D(){char buffer[4096];sprintf_s (buffer, "%s.tx2d",mName.c_str());return (const char*)buffer;}
	/*Filter for 3D textures*/
	BoolID getTextures3D(){char buffer[4096];sprintf_s (buffer, "%s.tx3d",mName.c_str());return (const char*)buffer;}
	/*Filter for lights*/
	BoolID getLights(){char buffer[4096];sprintf_s (buffer, "%s.lght",mName.c_str());return (const char*)buffer;}
	/*Filter for exclusive lights*/
	BoolID getExclusiveLights(){char buffer[4096];sprintf_s (buffer, "%s.exlt",mName.c_str());return (const char*)buffer;}
	/*Filter for lights*/
	BoolID getNonExclusiveLights(){char buffer[4096];sprintf_s (buffer, "%s.nxlt",mName.c_str());return (const char*)buffer;}
	/*Filter for post process nodes*/
	BoolID getPostProcess(){char buffer[4096];sprintf_s (buffer, "%s.post",mName.c_str());return (const char*)buffer;}
	/*Filter for utility nodes*/
	BoolID getUtility(){char buffer[4096];sprintf_s (buffer, "%s.util",mName.c_str());return (const char*)buffer;}
	/*Filter for sets containing renderable objects*/
	BoolID getRenderableObjectSets(){char buffer[4096];sprintf_s (buffer, "%s.ros",mName.c_str());return (const char*)buffer;}
	/*Filter for sets containing lights*/
	BoolID getLightSets(){char buffer[4096];sprintf_s (buffer, "%s.ls",mName.c_str());return (const char*)buffer;}
protected:
	ObjectRenderFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTRENDERFILTER_H__
