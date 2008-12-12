/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MULTILISTERLIGHT_H__
#define __MayaDM_MULTILISTERLIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
        This class defines the multilister light.  It is a very
        simple light that has a constant direction and colour.

</pre></p>
*/
class MultilisterLight : public DependNode
{
public:
public:
	MultilisterLight(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "multilisterLight"){}
	virtual ~MultilisterLight(){}
	/*The surface point.*/
	void setPointCamera(const float3& p){if(p == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".p\" -type \"float3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*The x-component of the position.*/
	void setPointCameraX(float px){if(px == 0.0) return; fprintf_s(mFile, "setAttr \".p.px\" %f;\n", px);}
	/*The y-component of the position.*/
	void setPointCameraY(float py){if(py == 0.0) return; fprintf_s(mFile, "setAttr \".p.py\" %f;\n", py);}
	/*The z-component of the position.*/
	void setPointCameraZ(float pz){if(pz == 0.0) return; fprintf_s(mFile, "setAttr \".p.pz\" %f;\n", pz);}
	/*The lighting information this node computes.*/
	void setLightData(const LightDataID& ltd){fprintf_s(mFile,"connectAttr \"");ltd.write(mFile);fprintf_s(mFile,"\" \"%s.ltd\";\n",mName.c_str());}
	/*The light direction.*/
	void setLightDirection(const Float3ID& ld){fprintf_s(mFile,"connectAttr \"");ld.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ld\";\n",mName.c_str());}
	/*The x component of the direction.*/
	void setLightDirectionX(const FloatID& ldx){fprintf_s(mFile,"connectAttr \"");ldx.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ld.ldx\";\n",mName.c_str());}
	/*The y component of the direction.*/
	void setLightDirectionY(const FloatID& ldy){fprintf_s(mFile,"connectAttr \"");ldy.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ld.ldy\";\n",mName.c_str());}
	/*The z component of the direction.*/
	void setLightDirectionZ(const FloatID& ldz){fprintf_s(mFile,"connectAttr \"");ldz.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ld.ldz\";\n",mName.c_str());}
	/*The light intensity (its a colour).*/
	void setLightIntensity(const Float3ID& li){fprintf_s(mFile,"connectAttr \"");li.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.li\";\n",mName.c_str());}
	/*The red component of the intensity.*/
	void setLightIntensityR(const FloatID& lir){fprintf_s(mFile,"connectAttr \"");lir.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.li.lir\";\n",mName.c_str());}
	/*The green component of the intensity.*/
	void setLightIntensityG(const FloatID& lig){fprintf_s(mFile,"connectAttr \"");lig.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.li.lig\";\n",mName.c_str());}
	/*The blue component of the intensity.*/
	void setLightIntensityB(const FloatID& lib){fprintf_s(mFile,"connectAttr \"");lib.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.li.lib\";\n",mName.c_str());}
	/*The boolean that indicates if the light has an ambient component.*/
	void setLightAmbient(const BoolID& la){fprintf_s(mFile,"connectAttr \"");la.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.la\";\n",mName.c_str());}
	/*The boolean that indicates if the light has a diffuse component.*/
	void setLightDiffuse(const BoolID& ldf){fprintf_s(mFile,"connectAttr \"");ldf.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ldf\";\n",mName.c_str());}
	/*The boolean that indicates if the light has a specular component.*/
	void setLightSpecular(const BoolID& ls){fprintf_s(mFile,"connectAttr \"");ls.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.ls\";\n",mName.c_str());}
	/*The visibility fraction to the light.  value is in [0,1]*/
	void setLightShadowFraction(const FloatID& lsf){fprintf_s(mFile,"connectAttr \"");lsf.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lsf\";\n",mName.c_str());}
	/*The intensity before shadow compution*/
	void setPreShadowIntensity(const FloatID& psi){fprintf_s(mFile,"connectAttr \"");psi.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.psi\";\n",mName.c_str());}
	/*The pointer to the light's blind data.*/
	void setLightBlindData(const AddrID& lbd){fprintf_s(mFile,"connectAttr \"");lbd.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lbd\";\n",mName.c_str());}
	/*The lighting information this node computes.*/
	LightDataID getLightData(){char buffer[4096];sprintf_s (buffer, "%s.ltd",mName.c_str());return (const char*)buffer;}
	/*The light direction.*/
	Float3ID getLightDirection(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ld",mName.c_str());return (const char*)buffer;}
	/*The x component of the direction.*/
	FloatID getLightDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ld.ldx",mName.c_str());return (const char*)buffer;}
	/*The y component of the direction.*/
	FloatID getLightDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ld.ldy",mName.c_str());return (const char*)buffer;}
	/*The z component of the direction.*/
	FloatID getLightDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ld.ldz",mName.c_str());return (const char*)buffer;}
	/*The light intensity (its a colour).*/
	Float3ID getLightIntensity(){char buffer[4096];sprintf_s (buffer, "%s.ltd.li",mName.c_str());return (const char*)buffer;}
	/*The red component of the intensity.*/
	FloatID getLightIntensityR(){char buffer[4096];sprintf_s (buffer, "%s.ltd.li.lir",mName.c_str());return (const char*)buffer;}
	/*The green component of the intensity.*/
	FloatID getLightIntensityG(){char buffer[4096];sprintf_s (buffer, "%s.ltd.li.lig",mName.c_str());return (const char*)buffer;}
	/*The blue component of the intensity.*/
	FloatID getLightIntensityB(){char buffer[4096];sprintf_s (buffer, "%s.ltd.li.lib",mName.c_str());return (const char*)buffer;}
	/*The boolean that indicates if the light has an ambient component.*/
	BoolID getLightAmbient(){char buffer[4096];sprintf_s (buffer, "%s.ltd.la",mName.c_str());return (const char*)buffer;}
	/*The boolean that indicates if the light has a diffuse component.*/
	BoolID getLightDiffuse(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ldf",mName.c_str());return (const char*)buffer;}
	/*The boolean that indicates if the light has a specular component.*/
	BoolID getLightSpecular(){char buffer[4096];sprintf_s (buffer, "%s.ltd.ls",mName.c_str());return (const char*)buffer;}
	/*The visibility fraction to the light.  value is in [0,1]*/
	FloatID getLightShadowFraction(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lsf",mName.c_str());return (const char*)buffer;}
	/*The intensity before shadow compution*/
	FloatID getPreShadowIntensity(){char buffer[4096];sprintf_s (buffer, "%s.ltd.psi",mName.c_str());return (const char*)buffer;}
	/*The pointer to the light's blind data.*/
	AddrID getLightBlindData(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lbd",mName.c_str());return (const char*)buffer;}
protected:
	MultilisterLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MULTILISTERLIGHT_H__
