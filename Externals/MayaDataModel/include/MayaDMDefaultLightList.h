/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFAULTLIGHTLIST_H__
#define __MayaDM_DEFAULTLIGHTLIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
        This node contains a list of lights that shine on all surfaces.
        Exclusive lights do not show up on this list.

</pre></p>
*/
class DefaultLightList : public DependNode
{
public:
public:
	DefaultLightList(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "defaultLightList"){}
	virtual ~DefaultLightList(){}
	/*The lighting information this node computes.*/
	void setLightData(const LightDataID& ltd){fprintf_s(mFile,"connectAttr \"");ltd.write(mFile);fprintf_s(mFile,"\" \"%s.ltd\";\n",mName.c_str());}
	/*The light direction.*/
	void setLightDirectionOut(const Float3ID& ldo){fprintf_s(mFile,"connectAttr \"");ldo.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ldo\";\n",mName.c_str());}
	/*The x component of the direction.*/
	void setLightDirectionOutX(const FloatID& lqx){fprintf_s(mFile,"connectAttr \"");lqx.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ldo.lqx\";\n",mName.c_str());}
	/*The y component of the direction.*/
	void setLightDirectionOutY(const FloatID& lqy){fprintf_s(mFile,"connectAttr \"");lqy.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ldo.lqy\";\n",mName.c_str());}
	/*The z component of the direction.*/
	void setLightDirectionOutZ(const FloatID& lqz){fprintf_s(mFile,"connectAttr \"");lqz.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ldo.lqz\";\n",mName.c_str());}
	/*The light intensity (its a colour).*/
	void setLightIntensityOut(const Float3ID& lw){fprintf_s(mFile,"connectAttr \"");lw.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lw\";\n",mName.c_str());}
	/*The red component of the intensity.*/
	void setLightIntensityOutR(const FloatID& lwr){fprintf_s(mFile,"connectAttr \"");lwr.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lw.lwr\";\n",mName.c_str());}
	/*The green component of the intensity.*/
	void setLightIntensityOutG(const FloatID& lwg){fprintf_s(mFile,"connectAttr \"");lwg.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lw.lwg\";\n",mName.c_str());}
	/*The blue component of the intensity.*/
	void setLightIntensityOutB(const FloatID& lwb){fprintf_s(mFile,"connectAttr \"");lwb.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lw.lwb\";\n",mName.c_str());}
	/*The boolean that indicates if the light has an ambient component.*/
	void setLightAmbientOut(const BoolID& lya){fprintf_s(mFile,"connectAttr \"");lya.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lya\";\n",mName.c_str());}
	/*The boolean that indicates if the light has a diffuse component.*/
	void setLightDiffuseOut(const BoolID& lyf){fprintf_s(mFile,"connectAttr \"");lyf.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lyf\";\n",mName.c_str());}
	/*The boolean that indicates if the light has a specular component.*/
	void setLightSpecularOut(const BoolID& lys){fprintf_s(mFile,"connectAttr \"");lys.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lys\";\n",mName.c_str());}
	/*The visibility fraction to the light.  value is in [0,1]*/
	void setLightShadowFractionOut(const FloatID& sfo){fprintf_s(mFile,"connectAttr \"");sfo.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.sfo\";\n",mName.c_str());}
	/*pre shadow light intensity.*/
	void setPreShadowIntensityOut(const FloatID& psio){fprintf_s(mFile,"connectAttr \"");psio.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.psio\";\n",mName.c_str());}
	/*The light's blind data pointer.*/
	void setLightBlindDataOut(const AddrID& lbdo){fprintf_s(mFile,"connectAttr \"");lbdo.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lbdo\";\n",mName.c_str());}
	/*The lighting information this node computes.*/
	LightDataID getLightData(){char buffer[4096];sprintf_s (buffer, "%s.ltd",mName.c_str());return (const char*)buffer;}
	/*The light direction.*/
	Float3ID getLightDirectionOut(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ldo",mName.c_str());return (const char*)buffer;}
	/*The x component of the direction.*/
	FloatID getLightDirectionOutX(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ldo.lqx",mName.c_str());return (const char*)buffer;}
	/*The y component of the direction.*/
	FloatID getLightDirectionOutY(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ldo.lqy",mName.c_str());return (const char*)buffer;}
	/*The z component of the direction.*/
	FloatID getLightDirectionOutZ(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ldo.lqz",mName.c_str());return (const char*)buffer;}
	/*The light intensity (its a colour).*/
	Float3ID getLightIntensityOut(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lw",mName.c_str());return (const char*)buffer;}
	/*The red component of the intensity.*/
	FloatID getLightIntensityOutR(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lw.lwr",mName.c_str());return (const char*)buffer;}
	/*The green component of the intensity.*/
	FloatID getLightIntensityOutG(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lw.lwg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the intensity.*/
	FloatID getLightIntensityOutB(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lw.lwb",mName.c_str());return (const char*)buffer;}
	/*The boolean that indicates if the light has an ambient component.*/
	BoolID getLightAmbientOut(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lya",mName.c_str());return (const char*)buffer;}
	/*The boolean that indicates if the light has a diffuse component.*/
	BoolID getLightDiffuseOut(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lyf",mName.c_str());return (const char*)buffer;}
	/*The boolean that indicates if the light has a specular component.*/
	BoolID getLightSpecularOut(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lys",mName.c_str());return (const char*)buffer;}
	/*The visibility fraction to the light.  value is in [0,1]*/
	FloatID getLightShadowFractionOut(){char buffer[4096];sprintf_s (buffer, "%s.ltd.sfo",mName.c_str());return (const char*)buffer;}
	/*pre shadow light intensity.*/
	FloatID getPreShadowIntensityOut(){char buffer[4096];sprintf_s (buffer, "%s.ltd.psio",mName.c_str());return (const char*)buffer;}
	/*The light's blind data pointer.*/
	AddrID getLightBlindDataOut(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lbdo",mName.c_str());return (const char*)buffer;}
protected:
	DefaultLightList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFAULTLIGHTLIST_H__
