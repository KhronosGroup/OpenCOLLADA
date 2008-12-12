/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLUIDTEXTURE2D_H__
#define __MayaDM_FLUIDTEXTURE2D_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFluidShape.h"
namespace MayaDM
{
/*
<p><pre>
 Manage a fluid texture

</pre></p>
*/
class FluidTexture2D : public FluidShape
{
public:
public:
	FluidTexture2D(FILE* file,const std::string& name,const std::string& parent=""):FluidShape(file, name, parent, "fluidTexture2D"){}
	virtual ~FluidTexture2D(){}
	/*The UV coords of the current sample point*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setUCoord(const FloatID& uvu){fprintf_s(mFile,"connectAttr \"");uvu.write(mFile);fprintf_s(mFile,"\" \"%s.uv.uvu\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setVCoord(const FloatID& uvv){fprintf_s(mFile,"connectAttr \"");uvv.write(mFile);fprintf_s(mFile,"\" \"%s.uv.uvv\";\n",mName.c_str());}
	/*
	<b>uvFilterSize</b> is the approximate size of a circular
	screenspace filter kernel projected into the [0,1] square
	uv-space of the texture. These values give you an idea of
	how much filtering is required so that your texture will
	not alias in your final image.
	<p/>
	So if you get values of (1,1.5) coming through the
	uvFilterSize attribute during shading, it means that the
	original circular screenspace filter has been projected to
	a roughly elliptical shape in your texture space, with
	major/minor axes of lengths 1 and 1.5, respectively.
	(currently unused by TfluidTexture2D, but provided for texture hookups)
	*/
	void setUvFilterSize(const Float2ID& uvfs){fprintf_s(mFile,"connectAttr \"");uvfs.write(mFile);fprintf_s(mFile,"\" \"%s.uvfs\";\n",mName.c_str());}
	/*The X size of the filter (sample)*/
	void setUvFilterSizeX(const FloatID& uvfsx){fprintf_s(mFile,"connectAttr \"");uvfsx.write(mFile);fprintf_s(mFile,"\" \"%s.uvfs.uvfsx\";\n",mName.c_str());}
	/*The Y size of the filter (sample)*/
	void setUvFilterSizeY(const FloatID& uvfsy){fprintf_s(mFile,"connectAttr \"");uvfsy.write(mFile);fprintf_s(mFile,"\" \"%s.uvfs.uvfsy\";\n",mName.c_str());}
	/*The standard output value for bump and displacement mapping*/
	void setOutAlpha(const FloatID& oa){fprintf_s(mFile,"connectAttr \"");oa.write(mFile);fprintf_s(mFile,"\" \"%s.oa\";\n",mName.c_str());}
	/*
	<b>Out UV</b>:  This attribute should be connected
	to the UV Coord attribute of the 2d texture being placed.
	*/
	void setOutUV(const Float2ID& ouv){fprintf_s(mFile,"connectAttr \"");ouv.write(mFile);fprintf_s(mFile,"\" \"%s.ouv\";\n",mName.c_str());}
	/*The U component of OutUV*/
	void setOutU(const FloatID& ou){fprintf_s(mFile,"connectAttr \"");ou.write(mFile);fprintf_s(mFile,"\" \"%s.ouv.ou\";\n",mName.c_str());}
	/*The V component of OutUV*/
	void setOutV(const FloatID& ov){fprintf_s(mFile,"connectAttr \"");ov.write(mFile);fprintf_s(mFile,"\" \"%s.ouv.ov\";\n",mName.c_str());}
	/*
	<b>Alpha Gain</b> is a multiplier that affects the
	alpha (mask) channel.  If this texture is being used
	as a bump map or a displacement map, you can adjust
	Alpha Gain to scale the amount of bumping.
	*/
	void setAlphaGain(float ag){if(ag == 1.0) return; fprintf_s(mFile, "setAttr \".ag\" %f;\n", ag);}
	/*
	<b>Alpha Gain</b> is a multiplier that affects the
	alpha (mask) channel.  If this texture is being used
	as a bump map or a displacement map, you can adjust
	Alpha Gain to scale the amount of bumping.
	*/
	void setAlphaGain(const FloatID& ag){fprintf_s(mFile,"connectAttr \"");ag.write(mFile);fprintf_s(mFile,"\" \"%s.ag\";\n",mName.c_str());}
	/*
	<b>Alpha Offset</b> is a value that is added to the
	alpha (mask) channel.  This can be used to uniformly
	increase the effect of the texture.
	*/
	void setAlphaOffset(float ao){if(ao == 0.0) return; fprintf_s(mFile, "setAttr \".ao\" %f;\n", ao);}
	/*
	<b>Alpha Offset</b> is a value that is added to the
	alpha (mask) channel.  This can be used to uniformly
	increase the effect of the texture.
	*/
	void setAlphaOffset(const FloatID& ao){fprintf_s(mFile,"connectAttr \"");ao.write(mFile);fprintf_s(mFile,"\" \"%s.ao\";\n",mName.c_str());}
	/*
	<b>Default Color</b> is the color of the texture in the
	areas that are not mapped.  If the placement of this
	texture is not covering an entire surface, then Default
	Color will be used in the areas not covered.
	*/
	void setDefaultColor(const float3& dcl){if(dcl == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".dcl\" -type \"float3\" ");dcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Default Color</b> is the color of the texture in the
	areas that are not mapped.  If the placement of this
	texture is not covering an entire surface, then Default
	Color will be used in the areas not covered.
	*/
	void setDefaultColor(const Float3ID& dcl){fprintf_s(mFile,"connectAttr \"");dcl.write(mFile);fprintf_s(mFile,"\" \"%s.dcl\";\n",mName.c_str());}
	/*Default Color red value.*/
	void setDefaultColorR(float dcr){if(dcr == 0.0) return; fprintf_s(mFile, "setAttr \".dcl.dcr\" %f;\n", dcr);}
	/*Default Color red value.*/
	void setDefaultColorR(const FloatID& dcr){fprintf_s(mFile,"connectAttr \"");dcr.write(mFile);fprintf_s(mFile,"\" \"%s.dcl.dcr\";\n",mName.c_str());}
	/*Default Color green value.*/
	void setDefaultColorG(float dcg){if(dcg == 0.0) return; fprintf_s(mFile, "setAttr \".dcl.dcg\" %f;\n", dcg);}
	/*Default Color green value.*/
	void setDefaultColorG(const FloatID& dcg){fprintf_s(mFile,"connectAttr \"");dcg.write(mFile);fprintf_s(mFile,"\" \"%s.dcl.dcg\";\n",mName.c_str());}
	/*Default Color blue value.*/
	void setDefaultColorB(float dcb){if(dcb == 0.0) return; fprintf_s(mFile, "setAttr \".dcl.dcb\" %f;\n", dcb);}
	/*Default Color blue value.*/
	void setDefaultColorB(const FloatID& dcb){fprintf_s(mFile,"connectAttr \"");dcb.write(mFile);fprintf_s(mFile,"\" \"%s.dcl.dcb\";\n",mName.c_str());}
	/*The UV coords of the current sample point*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.uvu",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.uvv",mName.c_str());return (const char*)buffer;}
	/*
	<b>uvFilterSize</b> is the approximate size of a circular
	screenspace filter kernel projected into the [0,1] square
	uv-space of the texture. These values give you an idea of
	how much filtering is required so that your texture will
	not alias in your final image.
	<p/>
	So if you get values of (1,1.5) coming through the
	uvFilterSize attribute during shading, it means that the
	original circular screenspace filter has been projected to
	a roughly elliptical shape in your texture space, with
	major/minor axes of lengths 1 and 1.5, respectively.
	(currently unused by TfluidTexture2D, but provided for texture hookups)
	*/
	Float2ID getUvFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.uvfs",mName.c_str());return (const char*)buffer;}
	/*The X size of the filter (sample)*/
	FloatID getUvFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.uvfs.uvfsx",mName.c_str());return (const char*)buffer;}
	/*The Y size of the filter (sample)*/
	FloatID getUvFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.uvfs.uvfsy",mName.c_str());return (const char*)buffer;}
	/*The standard output value for bump and displacement mapping*/
	FloatID getOutAlpha(){char buffer[4096];sprintf_s (buffer, "%s.oa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out UV</b>:  This attribute should be connected
	to the UV Coord attribute of the 2d texture being placed.
	*/
	Float2ID getOutUV(){char buffer[4096];sprintf_s (buffer, "%s.ouv",mName.c_str());return (const char*)buffer;}
	/*The U component of OutUV*/
	FloatID getOutU(){char buffer[4096];sprintf_s (buffer, "%s.ouv.ou",mName.c_str());return (const char*)buffer;}
	/*The V component of OutUV*/
	FloatID getOutV(){char buffer[4096];sprintf_s (buffer, "%s.ouv.ov",mName.c_str());return (const char*)buffer;}
	/*
	<b>Alpha Gain</b> is a multiplier that affects the
	alpha (mask) channel.  If this texture is being used
	as a bump map or a displacement map, you can adjust
	Alpha Gain to scale the amount of bumping.
	*/
	FloatID getAlphaGain(){char buffer[4096];sprintf_s (buffer, "%s.ag",mName.c_str());return (const char*)buffer;}
	/*
	<b>Alpha Offset</b> is a value that is added to the
	alpha (mask) channel.  This can be used to uniformly
	increase the effect of the texture.
	*/
	FloatID getAlphaOffset(){char buffer[4096];sprintf_s (buffer, "%s.ao",mName.c_str());return (const char*)buffer;}
	/*
	<b>Default Color</b> is the color of the texture in the
	areas that are not mapped.  If the placement of this
	texture is not covering an entire surface, then Default
	Color will be used in the areas not covered.
	*/
	Float3ID getDefaultColor(){char buffer[4096];sprintf_s (buffer, "%s.dcl",mName.c_str());return (const char*)buffer;}
	/*Default Color red value.*/
	FloatID getDefaultColorR(){char buffer[4096];sprintf_s (buffer, "%s.dcl.dcr",mName.c_str());return (const char*)buffer;}
	/*Default Color green value.*/
	FloatID getDefaultColorG(){char buffer[4096];sprintf_s (buffer, "%s.dcl.dcg",mName.c_str());return (const char*)buffer;}
	/*Default Color blue value.*/
	FloatID getDefaultColorB(){char buffer[4096];sprintf_s (buffer, "%s.dcl.dcb",mName.c_str());return (const char*)buffer;}
protected:
	FluidTexture2D(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):FluidShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FLUIDTEXTURE2D_H__
