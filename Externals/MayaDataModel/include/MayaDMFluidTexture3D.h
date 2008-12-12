/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLUIDTEXTURE3D_H__
#define __MayaDM_FLUIDTEXTURE3D_H__
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
class FluidTexture3D : public FluidShape
{
public:
public:
	FluidTexture3D(FILE* file,const std::string& name,const std::string& parent=""):FluidShape(file, name, parent, "fluidTexture3D"){}
	virtual ~FluidTexture3D(){}
	/*surface intersection point in camera space*/
	void setRefPointCamera(const Float3ID& rpc){fprintf_s(mFile,"connectAttr \"");rpc.write(mFile);fprintf_s(mFile,"\" \"%s.rpc\";\n",mName.c_str());}
	/*point camera x component*/
	void setRefPointCameraX(const FloatID& rcx){fprintf_s(mFile,"connectAttr \"");rcx.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcx\";\n",mName.c_str());}
	/*point camera y component*/
	void setRefPointCameraY(const FloatID& rcy){fprintf_s(mFile,"connectAttr \"");rcy.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcy\";\n",mName.c_str());}
	/*point camera z component*/
	void setRefPointCameraZ(const FloatID& rcz){fprintf_s(mFile,"connectAttr \"");rcz.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcz\";\n",mName.c_str());}
	/*The standard output value for bump and displacement mapping*/
	void setOutAlpha(const FloatID& oa){fprintf_s(mFile,"connectAttr \"");oa.write(mFile);fprintf_s(mFile,"\" \"%s.oa\";\n",mName.c_str());}
	/*
	<b>Out Coord</b>:  This attribute contains the output
	texture coordinate grid values. It can be mapped to the
	inputs of a solid texture to push the texture along with
	the fluid when a texture coordinate grid is used.
	*/
	void setOutCoord(const Float3ID& ouc){fprintf_s(mFile,"connectAttr \"");ouc.write(mFile);fprintf_s(mFile,"\" \"%s.ouc\";\n",mName.c_str());}
	/*The X component of OutCoord*/
	void setOucx(const FloatID& ocx){fprintf_s(mFile,"connectAttr \"");ocx.write(mFile);fprintf_s(mFile,"\" \"%s.ouc.ocx\";\n",mName.c_str());}
	/*The Y component of OutCoord*/
	void setOucy(const FloatID& ocy){fprintf_s(mFile,"connectAttr \"");ocy.write(mFile);fprintf_s(mFile,"\" \"%s.ouc.ocy\";\n",mName.c_str());}
	/*The Z component of OutCoord*/
	void setOucz(const FloatID& ocz){fprintf_s(mFile,"connectAttr \"");ocz.write(mFile);fprintf_s(mFile,"\" \"%s.ouc.ocz\";\n",mName.c_str());}
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
	/*surface intersection point in camera space*/
	Float3ID getRefPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.rpc",mName.c_str());return (const char*)buffer;}
	/*point camera x component*/
	FloatID getRefPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcx",mName.c_str());return (const char*)buffer;}
	/*point camera y component*/
	FloatID getRefPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcy",mName.c_str());return (const char*)buffer;}
	/*point camera z component*/
	FloatID getRefPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcz",mName.c_str());return (const char*)buffer;}
	/*The standard output value for bump and displacement mapping*/
	FloatID getOutAlpha(){char buffer[4096];sprintf_s (buffer, "%s.oa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Coord</b>:  This attribute contains the output
	texture coordinate grid values. It can be mapped to the
	inputs of a solid texture to push the texture along with
	the fluid when a texture coordinate grid is used.
	*/
	Float3ID getOutCoord(){char buffer[4096];sprintf_s (buffer, "%s.ouc",mName.c_str());return (const char*)buffer;}
	/*The X component of OutCoord*/
	FloatID getOucx(){char buffer[4096];sprintf_s (buffer, "%s.ouc.ocx",mName.c_str());return (const char*)buffer;}
	/*The Y component of OutCoord*/
	FloatID getOucy(){char buffer[4096];sprintf_s (buffer, "%s.ouc.ocy",mName.c_str());return (const char*)buffer;}
	/*The Z component of OutCoord*/
	FloatID getOucz(){char buffer[4096];sprintf_s (buffer, "%s.ouc.ocz",mName.c_str());return (const char*)buffer;}
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
	FluidTexture3D(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):FluidShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FLUIDTEXTURE3D_H__
