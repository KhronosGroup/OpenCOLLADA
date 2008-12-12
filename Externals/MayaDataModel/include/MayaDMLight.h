/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHT_H__
#define __MayaDM_LIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
<p><pre>
        This class contains the "shape" information for all lights.

</pre></p>
*/
class Light : public Shape
{
public:
public:
	Light(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "light"){}
	virtual ~Light(){}
	/*The input color.*/
	void setColor(const float3& cl){if(cl == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".cl\" -type \"float3\" ");cl.write(mFile);fprintf_s(mFile,";\n");}
	/*The input color.*/
	void setColor(const Float3ID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl\";\n",mName.c_str());}
	/*The red component of the input color.*/
	void setColorR(float cr){if(cr == 0.0) return; fprintf_s(mFile, "setAttr \".cl.cr\" %f;\n", cr);}
	/*The red component of the input color.*/
	void setColorR(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cr\";\n",mName.c_str());}
	/*The green component of the input color.*/
	void setColorG(float cg){if(cg == 0.0) return; fprintf_s(mFile, "setAttr \".cl.cg\" %f;\n", cg);}
	/*The green component of the input color.*/
	void setColorG(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cg\";\n",mName.c_str());}
	/*The blue component of the input color.*/
	void setColorB(float cb){if(cb == 0.0) return; fprintf_s(mFile, "setAttr \".cl.cb\" %f;\n", cb);}
	/*The blue component of the input color.*/
	void setColorB(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cb\";\n",mName.c_str());}
	/*The intensity fo the light.*/
	void setIntensity(float in){if(in == 1.0) return; fprintf_s(mFile, "setAttr \".in\" %f;\n", in);}
	/*The intensity fo the light.*/
	void setIntensity(const FloatID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in\";\n",mName.c_str());}
	/*Do I ray trace my shadows?*/
	void setUseRayTraceShadows(bool urs){if(urs == false) return; fprintf_s(mFile, "setAttr \".urs\" %i;\n", urs);}
	/*Do I ray trace my shadows?*/
	void setUseRayTraceShadows(const BoolID& urs){fprintf_s(mFile,"connectAttr \"");urs.write(mFile);fprintf_s(mFile,"\" \"%s.urs\";\n",mName.c_str());}
	/*The input shadow color.*/
	void setShadowColor(const float3& sc){if(sc == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".sc\" -type \"float3\" ");sc.write(mFile);fprintf_s(mFile,";\n");}
	/*The input shadow color.*/
	void setShadowColor(const Float3ID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*The red component of the input shadow color.*/
	void setShadColorR(float scr){if(scr == 0.0) return; fprintf_s(mFile, "setAttr \".sc.scr\" %f;\n", scr);}
	/*The red component of the input shadow color.*/
	void setShadColorR(const FloatID& scr){fprintf_s(mFile,"connectAttr \"");scr.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scr\";\n",mName.c_str());}
	/*The green component of the input shadow color.*/
	void setShadColorG(float scg){if(scg == 0.0) return; fprintf_s(mFile, "setAttr \".sc.scg\" %f;\n", scg);}
	/*The green component of the input shadow color.*/
	void setShadColorG(const FloatID& scg){fprintf_s(mFile,"connectAttr \"");scg.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scg\";\n",mName.c_str());}
	/*The blue component of the input shadow color.*/
	void setShadColorB(float scb){if(scb == 0.0) return; fprintf_s(mFile, "setAttr \".sc.scb\" %f;\n", scb);}
	/*The blue component of the input shadow color.*/
	void setShadColorB(const FloatID& scb){fprintf_s(mFile,"connectAttr \"");scb.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scb\";\n",mName.c_str());}
	/*The number of rays used for soft shadow sampling.*/
	void setShadowRays(short shr){if(shr == 1) return; fprintf_s(mFile, "setAttr \".shr\" %i;\n", shr);}
	/*The number of rays used for soft shadow sampling.*/
	void setShadowRays(const ShortID& shr){fprintf_s(mFile,"connectAttr \"");shr.write(mFile);fprintf_s(mFile,"\" \"%s.shr\";\n",mName.c_str());}
	/*max ray depth allowed*/
	void setRayDepthLimit(short rdl){if(rdl == 1) return; fprintf_s(mFile, "setAttr \".rdl\" %i;\n", rdl);}
	/*max ray depth allowed*/
	void setRayDepthLimit(const ShortID& rdl){fprintf_s(mFile,"connectAttr \"");rdl.write(mFile);fprintf_s(mFile,"\" \"%s.rdl\";\n",mName.c_str());}
	/*Distance to the center of illumination*/
	void setCenterOfIllumination(double col){if(col == 5.0) return; fprintf_s(mFile, "setAttr \".col\" %f;\n", col);}
	/*Distance to the center of illumination*/
	void setCenterOfIllumination(const DoubleID& col){fprintf_s(mFile,"connectAttr \"");col.write(mFile);fprintf_s(mFile,"\" \"%s.col\";\n",mName.c_str());}
	/*The surface point.*/
	void setPointCamera(const float3& p){if(p == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".p\" -type \"float3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*The x-component of the position.*/
	void setPointCameraX(float px){if(px == 0.0) return; fprintf_s(mFile, "setAttr \".p.px\" %f;\n", px);}
	/*The y-component of the position.*/
	void setPointCameraY(float py){if(py == 0.0) return; fprintf_s(mFile, "setAttr \".p.py\" %f;\n", py);}
	/*The z-component of the position.*/
	void setPointCameraZ(float pz){if(pz == 0.0) return; fprintf_s(mFile, "setAttr \".p.pz\" %f;\n", pz);}
	/*
	the render state, i.e. depthMap computation, pre-illuimnation,
	regular rendering, post processing, raytracing, etc.
	*/
	void setRenderState(int rdst){if(rdst == 0) return; fprintf_s(mFile, "setAttr \".rdst\" %i;\n", rdst);}
	/*Scale factor for the light locator.*/
	void setLocatorScale(double lls){if(lls == 1.0) return; fprintf_s(mFile, "setAttr \".lls\" %f;\n", lls);}
	/*Scale factor for the light locator.*/
	void setLocatorScale(const DoubleID& lls){fprintf_s(mFile,"connectAttr \"");lls.write(mFile);fprintf_s(mFile,"\" \"%s.lls\";\n",mName.c_str());}
	/*The UV coords of the current sample point*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setUCoord(const FloatID& uu){fprintf_s(mFile,"connectAttr \"");uu.write(mFile);fprintf_s(mFile,"\" \"%s.uv.uu\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setVCoord(const FloatID& vv){fprintf_s(mFile,"connectAttr \"");vv.write(mFile);fprintf_s(mFile,"\" \"%s.uv.vv\";\n",mName.c_str());}
	/*The sample (filter) size*/
	void setUvFilterSize(const Float2ID& fq){fprintf_s(mFile,"connectAttr \"");fq.write(mFile);fprintf_s(mFile,"\" \"%s.fq\";\n",mName.c_str());}
	/*The X size of the filter (sample)*/
	void setUvFilterSizeX(const FloatID& fsx){fprintf_s(mFile,"connectAttr \"");fsx.write(mFile);fprintf_s(mFile,"\" \"%s.fq.fsx\";\n",mName.c_str());}
	/*The Y size of the filter (sample)*/
	void setUvFilterSizeY(const FloatID& fsy){fprintf_s(mFile,"connectAttr \"");fsy.write(mFile);fprintf_s(mFile,"\" \"%s.fq.fsy\";\n",mName.c_str());}
	/*Information bits passing along information about type of shading*/
	void setInfoBits(const IntID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
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
	/*The pre shadow light intensity.*/
	void setPreShadowIntensity(const FloatID& psi){fprintf_s(mFile,"connectAttr \"");psi.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.psi\";\n",mName.c_str());}
	/*The light's blind data.*/
	void setLightBlindData(const AddrID& lbl){fprintf_s(mFile,"connectAttr \"");lbl.write(mFile);fprintf_s(mFile,"\" \"%s.ltd.lbl\";\n",mName.c_str());}
	/*The visibility of the light (for optical FX)*/
	void setOpticalFXvisibility(const Float3ID& ov){fprintf_s(mFile,"connectAttr \"");ov.write(mFile);fprintf_s(mFile,"\" \"%s.ov\";\n",mName.c_str());}
	/*The red component of the visibility of the light (for optical FX)*/
	void setOpticalFXvisibilityR(const FloatID& ovr){fprintf_s(mFile,"connectAttr \"");ovr.write(mFile);fprintf_s(mFile,"\" \"%s.ov.ovr\";\n",mName.c_str());}
	/*The green component of the visibility of the light (for optical FX)*/
	void setOpticalFXvisibilityG(const FloatID& ovg){fprintf_s(mFile,"connectAttr \"");ovg.write(mFile);fprintf_s(mFile,"\" \"%s.ov.ovg\";\n",mName.c_str());}
	/*The blue component of the visibility of the light (for optical FX)*/
	void setOpticalFXvisibilityB(const FloatID& ovb){fprintf_s(mFile,"connectAttr \"");ovb.write(mFile);fprintf_s(mFile,"\" \"%s.ov.ovb\";\n",mName.c_str());}
	/*The input color.*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.cl",mName.c_str());return (const char*)buffer;}
	/*The red component of the input color.*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.cl.cr",mName.c_str());return (const char*)buffer;}
	/*The green component of the input color.*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.cl.cg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the input color.*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.cl.cb",mName.c_str());return (const char*)buffer;}
	/*The intensity fo the light.*/
	FloatID getIntensity(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*Do I ray trace my shadows?*/
	BoolID getUseRayTraceShadows(){char buffer[4096];sprintf_s (buffer, "%s.urs",mName.c_str());return (const char*)buffer;}
	/*The input shadow color.*/
	Float3ID getShadowColor(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*The red component of the input shadow color.*/
	FloatID getShadColorR(){char buffer[4096];sprintf_s (buffer, "%s.sc.scr",mName.c_str());return (const char*)buffer;}
	/*The green component of the input shadow color.*/
	FloatID getShadColorG(){char buffer[4096];sprintf_s (buffer, "%s.sc.scg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the input shadow color.*/
	FloatID getShadColorB(){char buffer[4096];sprintf_s (buffer, "%s.sc.scb",mName.c_str());return (const char*)buffer;}
	/*The number of rays used for soft shadow sampling.*/
	ShortID getShadowRays(){char buffer[4096];sprintf_s (buffer, "%s.shr",mName.c_str());return (const char*)buffer;}
	/*max ray depth allowed*/
	ShortID getRayDepthLimit(){char buffer[4096];sprintf_s (buffer, "%s.rdl",mName.c_str());return (const char*)buffer;}
	/*Distance to the center of illumination*/
	DoubleID getCenterOfIllumination(){char buffer[4096];sprintf_s (buffer, "%s.col",mName.c_str());return (const char*)buffer;}
	/*Scale factor for the light locator.*/
	DoubleID getLocatorScale(){char buffer[4096];sprintf_s (buffer, "%s.lls",mName.c_str());return (const char*)buffer;}
	/*The UV coords of the current sample point*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.uu",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.vv",mName.c_str());return (const char*)buffer;}
	/*The sample (filter) size*/
	Float2ID getUvFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.fq",mName.c_str());return (const char*)buffer;}
	/*The X size of the filter (sample)*/
	FloatID getUvFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.fq.fsx",mName.c_str());return (const char*)buffer;}
	/*The Y size of the filter (sample)*/
	FloatID getUvFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.fq.fsy",mName.c_str());return (const char*)buffer;}
	/*Information bits passing along information about type of shading*/
	IntID getInfoBits(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
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
	/*The pre shadow light intensity.*/
	FloatID getPreShadowIntensity(){char buffer[4096];sprintf_s (buffer, "%s.ltd.psi",mName.c_str());return (const char*)buffer;}
	/*The light's blind data.*/
	AddrID getLightBlindData(){char buffer[4096];sprintf_s (buffer, "%s.ltd.lbl",mName.c_str());return (const char*)buffer;}
	/*The visibility of the light (for optical FX)*/
	Float3ID getOpticalFXvisibility(){char buffer[4096];sprintf_s (buffer, "%s.ov",mName.c_str());return (const char*)buffer;}
	/*The red component of the visibility of the light (for optical FX)*/
	FloatID getOpticalFXvisibilityR(){char buffer[4096];sprintf_s (buffer, "%s.ov.ovr",mName.c_str());return (const char*)buffer;}
	/*The green component of the visibility of the light (for optical FX)*/
	FloatID getOpticalFXvisibilityG(){char buffer[4096];sprintf_s (buffer, "%s.ov.ovg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the visibility of the light (for optical FX)*/
	FloatID getOpticalFXvisibilityB(){char buffer[4096];sprintf_s (buffer, "%s.ov.ovb",mName.c_str());return (const char*)buffer;}
protected:
	Light(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LIGHT_H__
