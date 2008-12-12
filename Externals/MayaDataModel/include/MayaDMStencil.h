/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STENCIL_H__
#define __MayaDM_STENCIL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
The <b>Stencil</b> texture lets you take any image input (from
 a shading network, or a file texture node, say) and map it
 onto an object.  It also lets you mask the input image to control
 how it covers a surface.  Use the Stencil texture to overlay
 different textures (and control what parts of the texture are
 visible), or for label mapping.
 <p/>
 Normally, Stencil nodes are created automatically by the system
 when you put a 2d texture map on a node, and specify that it
 should be a 2d Stencil.  The Out Color attribute of the Stencil
 is connected to the attribute being mapped.  The Stencil itself
 is driven by the new texture map and its placement node.
 Specifically, the texture's Out Color is connected to the Stencil's
 Image attribute, and the Placement node drives the Stencil's
 UV Coord and uv Filter Size attributes.  This is all done for you.
 <p/>
 <b>Note:</b> The region being stenciled-out will take on the
 default color of the stencil, not the shader's color.
 <p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class Stencil : public Texture2d
{
public:
public:
	Stencil(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "stencil"){}
	virtual ~Stencil(){}
	/*
	<b>Image</b> is the texture that will be
	used as a stencil.
	*/
	void setImage(const float3& im){if(im == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".im\" -type \"float3\" ");im.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Image</b> is the texture that will be
	used as a stencil.
	*/
	void setImage(const Float3ID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im\";\n",mName.c_str());}
	/*Image Red channel*/
	void setImageR(float imr){if(imr == 0.0) return; fprintf_s(mFile, "setAttr \".im.imr\" %f;\n", imr);}
	/*Image Red channel*/
	void setImageR(const FloatID& imr){fprintf_s(mFile,"connectAttr \"");imr.write(mFile);fprintf_s(mFile,"\" \"%s.im.imr\";\n",mName.c_str());}
	/*Image Green channel*/
	void setImageG(float img){if(img == 0.0) return; fprintf_s(mFile, "setAttr \".im.img\" %f;\n", img);}
	/*Image Green channel*/
	void setImageG(const FloatID& img){fprintf_s(mFile,"connectAttr \"");img.write(mFile);fprintf_s(mFile,"\" \"%s.im.img\";\n",mName.c_str());}
	/*Image Blue channel*/
	void setImageB(float imb){if(imb == 0.0) return; fprintf_s(mFile, "setAttr \".im.imb\" %f;\n", imb);}
	/*Image Blue channel*/
	void setImageB(const FloatID& imb){fprintf_s(mFile,"connectAttr \"");imb.write(mFile);fprintf_s(mFile,"\" \"%s.im.imb\";\n",mName.c_str());}
	/*
	<b>Mask</b> is the transparency of the Stencil texture.
	You can use the Mask attribute either to control the
	overall transparency of the entire texture, or to control
	the transparency of select regions of the texture (by
	mapping another texture to Mask).
	<p/>
	For example, if the Stencil texture is mapped to a shader's
	color, and the Mask value is 0.5, the resulting surface will
	be an even mix of the shader color and the Stencil
	texture color. If Mask is mapped with an image of a
	black circle on white, the Stencil texture color will
	appear inside the circle, and the shader color will
	appear outside the circle.
	*/
	void setMask(float m){if(m == 0.0) return; fprintf_s(mFile, "setAttr \".m\" %f;\n", m);}
	/*
	<b>Mask</b> is the transparency of the Stencil texture.
	You can use the Mask attribute either to control the
	overall transparency of the entire texture, or to control
	the transparency of select regions of the texture (by
	mapping another texture to Mask).
	<p/>
	For example, if the Stencil texture is mapped to a shader's
	color, and the Mask value is 0.5, the resulting surface will
	be an even mix of the shader color and the Stencil
	texture color. If Mask is mapped with an image of a
	black circle on white, the Stencil texture color will
	appear inside the circle, and the shader color will
	appear outside the circle.
	*/
	void setMask(const FloatID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*
	<b>Edge Blend</b> controls the sharpness of the edges
	of the texture.  Increase this value to make the edges
	blend more softly.
	*/
	void setEdgeBlend(float eb){if(eb == 0.0) return; fprintf_s(mFile, "setAttr \".eb\" %f;\n", eb);}
	/*
	<b>Edge Blend</b> controls the sharpness of the edges
	of the texture.  Increase this value to make the edges
	blend more softly.
	*/
	void setEdgeBlend(const FloatID& eb){fprintf_s(mFile,"connectAttr \"");eb.write(mFile);fprintf_s(mFile,"\" \"%s.eb\";\n",mName.c_str());}
	/*
	<b>Key Masking</b> is a switch to enable or disable
	Chroma Key masking.  When this is turned OFF, all other
	key attributes have no effect.
	*/
	void setKeyMasking(bool km){if(km == false) return; fprintf_s(mFile, "setAttr \".km\" %i;\n", km);}
	/*
	<b>Key Masking</b> is a switch to enable or disable
	Chroma Key masking.  When this is turned OFF, all other
	key attributes have no effect.
	*/
	void setKeyMasking(const BoolID& km){fprintf_s(mFile,"connectAttr \"");km.write(mFile);fprintf_s(mFile,"\" \"%s.km\";\n",mName.c_str());}
	/*
	<b>Positive Key</b> inverts the chroma key mask
	(only the colors specified in the Color Key and HSV
	Range are displayed). The default setting is OFF (the
	colors specified in the Color Key
	and HSV Range are masked).
	*/
	void setPositiveKey(bool pk){if(pk == false) return; fprintf_s(mFile, "setAttr \".pk\" %i;\n", pk);}
	/*
	<b>Positive Key</b> inverts the chroma key mask
	(only the colors specified in the Color Key and HSV
	Range are displayed). The default setting is OFF (the
	colors specified in the Color Key
	and HSV Range are masked).
	*/
	void setPositiveKey(const BoolID& pk){fprintf_s(mFile,"connectAttr \"");pk.write(mFile);fprintf_s(mFile,"\" \"%s.pk\";\n",mName.c_str());}
	/*
	<b>Color Key</b> is The color to be masked in the
	texture. The default setting is black. To mask a range
	of colors, you must also set the Hue/Sat/Val Range parameters.
	*/
	void setColorKey(const float3& ck){if(ck == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ck\" -type \"float3\" ");ck.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color Key</b> is The color to be masked in the
	texture. The default setting is black. To mask a range
	of colors, you must also set the Hue/Sat/Val Range parameters.
	*/
	void setColorKey(const Float3ID& ck){fprintf_s(mFile,"connectAttr \"");ck.write(mFile);fprintf_s(mFile,"\" \"%s.ck\";\n",mName.c_str());}
	/*The red component of Color Key*/
	void setColorKeyR(float ckr){if(ckr == 0.0) return; fprintf_s(mFile, "setAttr \".ck.ckr\" %f;\n", ckr);}
	/*The red component of Color Key*/
	void setColorKeyR(const FloatID& ckr){fprintf_s(mFile,"connectAttr \"");ckr.write(mFile);fprintf_s(mFile,"\" \"%s.ck.ckr\";\n",mName.c_str());}
	/*The green component of Color Key*/
	void setColorKeyG(float ckg){if(ckg == 0.0) return; fprintf_s(mFile, "setAttr \".ck.ckg\" %f;\n", ckg);}
	/*The green component of Color Key*/
	void setColorKeyG(const FloatID& ckg){fprintf_s(mFile,"connectAttr \"");ckg.write(mFile);fprintf_s(mFile,"\" \"%s.ck.ckg\";\n",mName.c_str());}
	/*The blue component of Color Key*/
	void setColorKeyB(float ckb){if(ckb == 0.0) return; fprintf_s(mFile, "setAttr \".ck.ckb\" %f;\n", ckb);}
	/*The blue component of Color Key*/
	void setColorKeyB(const FloatID& ckb){fprintf_s(mFile,"connectAttr \"");ckb.write(mFile);fprintf_s(mFile,"\" \"%s.ck.ckb\";\n",mName.c_str());}
	/*
	<b>Hue Range</b> controls The range of hues
	(H) centered on the Color Key color which will
	also be masked. The valid range is 0 to 1. The
	default value is 0.5.
	*/
	void setHueRange(float hr){if(hr == 0.5) return; fprintf_s(mFile, "setAttr \".hr\" %f;\n", hr);}
	/*
	<b>Hue Range</b> controls The range of hues
	(H) centered on the Color Key color which will
	also be masked. The valid range is 0 to 1. The
	default value is 0.5.
	*/
	void setHueRange(const FloatID& hr){fprintf_s(mFile,"connectAttr \"");hr.write(mFile);fprintf_s(mFile,"\" \"%s.hr\";\n",mName.c_str());}
	/*
	<b>Saturation Range</b> controls The range of saturations
	(S) centered on the Color Key color which will
	also be masked. The valid range is 0 to 1. The
	default value is 0.5.
	*/
	void setSaturationRange(float sr){if(sr == 0.5) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*
	<b>Saturation Range</b> controls The range of saturations
	(S) centered on the Color Key color which will
	also be masked. The valid range is 0 to 1. The
	default value is 0.5.
	*/
	void setSaturationRange(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	<b>Value Range</b> controls The range of values
	(V) centered on the Color Key color which will
	also be masked. The valid range is 0 to 1. The
	default value is 0.5.
	*/
	void setValueRange(float vr){if(vr == 0.5) return; fprintf_s(mFile, "setAttr \".vr\" %f;\n", vr);}
	/*
	<b>Value Range</b> controls The range of values
	(V) centered on the Color Key color which will
	also be masked. The valid range is 0 to 1. The
	default value is 0.5.
	*/
	void setValueRange(const FloatID& vr){fprintf_s(mFile,"connectAttr \"");vr.write(mFile);fprintf_s(mFile,"\" \"%s.vr\";\n",mName.c_str());}
	/*
	<b>Threshold</b> controls the point at which the
	color state changes.
	*/
	void setThreshold(float th){if(th == 0.5) return; fprintf_s(mFile, "setAttr \".th\" %f;\n", th);}
	/*
	<b>Threshold</b> controls the point at which the
	color state changes.
	*/
	void setThreshold(const FloatID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th\";\n",mName.c_str());}
	/*
	<b>Image</b> is the texture that will be
	used as a stencil.
	*/
	Float3ID getImage(){char buffer[4096];sprintf_s (buffer, "%s.im",mName.c_str());return (const char*)buffer;}
	/*Image Red channel*/
	FloatID getImageR(){char buffer[4096];sprintf_s (buffer, "%s.im.imr",mName.c_str());return (const char*)buffer;}
	/*Image Green channel*/
	FloatID getImageG(){char buffer[4096];sprintf_s (buffer, "%s.im.img",mName.c_str());return (const char*)buffer;}
	/*Image Blue channel*/
	FloatID getImageB(){char buffer[4096];sprintf_s (buffer, "%s.im.imb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Mask</b> is the transparency of the Stencil texture.
	You can use the Mask attribute either to control the
	overall transparency of the entire texture, or to control
	the transparency of select regions of the texture (by
	mapping another texture to Mask).
	<p/>
	For example, if the Stencil texture is mapped to a shader's
	color, and the Mask value is 0.5, the resulting surface will
	be an even mix of the shader color and the Stencil
	texture color. If Mask is mapped with an image of a
	black circle on white, the Stencil texture color will
	appear inside the circle, and the shader color will
	appear outside the circle.
	*/
	FloatID getMask(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*
	<b>Edge Blend</b> controls the sharpness of the edges
	of the texture.  Increase this value to make the edges
	blend more softly.
	*/
	FloatID getEdgeBlend(){char buffer[4096];sprintf_s (buffer, "%s.eb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Key Masking</b> is a switch to enable or disable
	Chroma Key masking.  When this is turned OFF, all other
	key attributes have no effect.
	*/
	BoolID getKeyMasking(){char buffer[4096];sprintf_s (buffer, "%s.km",mName.c_str());return (const char*)buffer;}
	/*
	<b>Positive Key</b> inverts the chroma key mask
	(only the colors specified in the Color Key and HSV
	Range are displayed). The default setting is OFF (the
	colors specified in the Color Key
	and HSV Range are masked).
	*/
	BoolID getPositiveKey(){char buffer[4096];sprintf_s (buffer, "%s.pk",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color Key</b> is The color to be masked in the
	texture. The default setting is black. To mask a range
	of colors, you must also set the Hue/Sat/Val Range parameters.
	*/
	Float3ID getColorKey(){char buffer[4096];sprintf_s (buffer, "%s.ck",mName.c_str());return (const char*)buffer;}
	/*The red component of Color Key*/
	FloatID getColorKeyR(){char buffer[4096];sprintf_s (buffer, "%s.ck.ckr",mName.c_str());return (const char*)buffer;}
	/*The green component of Color Key*/
	FloatID getColorKeyG(){char buffer[4096];sprintf_s (buffer, "%s.ck.ckg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Color Key*/
	FloatID getColorKeyB(){char buffer[4096];sprintf_s (buffer, "%s.ck.ckb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Hue Range</b> controls The range of hues
	(H) centered on the Color Key color which will
	also be masked. The valid range is 0 to 1. The
	default value is 0.5.
	*/
	FloatID getHueRange(){char buffer[4096];sprintf_s (buffer, "%s.hr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Saturation Range</b> controls The range of saturations
	(S) centered on the Color Key color which will
	also be masked. The valid range is 0 to 1. The
	default value is 0.5.
	*/
	FloatID getSaturationRange(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Value Range</b> controls The range of values
	(V) centered on the Color Key color which will
	also be masked. The valid range is 0 to 1. The
	default value is 0.5.
	*/
	FloatID getValueRange(){char buffer[4096];sprintf_s (buffer, "%s.vr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Threshold</b> controls the point at which the
	color state changes.
	*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.th",mName.c_str());return (const char*)buffer;}
protected:
	Stencil(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_STENCIL_H__
