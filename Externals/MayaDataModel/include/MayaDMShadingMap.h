/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SHADINGMAP_H__
#define __MayaDM_SHADINGMAP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The <b>Shading Map</b> shader allows you to create
 various non-photorealistic shading effects.
 For example, you can use it to create cartoon-style
 materials.  Use a Shading map shader
 in conjunction with a regular shader (such as a Phong or Blinn shader)
 and a texture (such as a Ramp or File texture).  It works like a
 post process --- first, the regular shader computes a color for
 each point on the surface.  Then, the shading maps shader <i>replaces</i>
 this color with another color.  This mapping is based on two things;
 the <i>brightness</i> of the original color, and the <i>hue</i> of the
 original color.
 <p/>
 For example, you can create a material that renders the bright areas
 of an object (the areas facing light) as red, and the dark areas
 of an object (facing away from light) as blue.  To do this, use
 a Shading Map shader, a Lambert shader, and a Ramp texture.
 The Ramp texture is red on the top, and blue on the bottom.
 Connect the Lambert shader's Out Color attribute to the Shading
 Map shader's Color attribute.  Connect the Ramp texture's Out Color
 attribute to the Shading Map shader's Shading Map Color attribute.
 <p/>
 When you render, the Lambert shader calculates the color for each point on
 the material.  Then the Shading Map shader replaces the color at each point
 by 'looking up' a color at on the Ramp texture.  The hue of the original
 color gives the horizontal position on the ramp, and the brightness of the
 original color gives the vertical position.  The original color is
 replaced with the color at that position on the Ramp.  So in this example,
 the bright areas become red, and the dark areas become blue.
 <p/>
 For a different example, let's say you used the same Ramp texture turned
 sideways.  Then no matter how bright the pixel was, it would be mapped
 to the same color intensity.  Colors of different hues would be mapped
 to different shades of red or blue.
 <p/>
 Using similar techniques, Shading Map shaders can be used to do
 cartoon-style rendering.
 <p/>
 In the table below, important attribute have their names indicated
 in <b>bold</b> in the description column.
*/
class ShadingMap : public DependNode
{
public:
public:
	ShadingMap(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "shadingMap"){}
	virtual ~ShadingMap(){}
	/*The UV coords of the current sample point*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setUCoord(const FloatID& uu){fprintf_s(mFile,"connectAttr \"");uu.write(mFile);fprintf_s(mFile,"\" \"%s.uv.uu\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setVCoord(const FloatID& vv){fprintf_s(mFile,"connectAttr \"");vv.write(mFile);fprintf_s(mFile,"\" \"%s.uv.vv\";\n",mName.c_str());}
	/*
	Specifies how the input <b>color</b> will be used when looking
	up in the U direction of <b>shadingMapColor</b>. For example,
	if set to "value"; the input RGB will be converted to the HSV
	color space, and brightness will be used as the uCoord when
	sampling the shading map. A black input color will result
	in a color lookup from the left side of the shading map, and
	a white input color will correspond to a lookup from the right
	side of the shading map.
	*/
	void setMapFunctionU(unsigned int mfu){if(mfu == 0) return; fprintf_s(mFile, "setAttr \".mfu\" %i;\n", mfu);}
	/*
	Specifies how the input <b>color</b> will be used when looking
	up in the U direction of <b>shadingMapColor</b>. For example,
	if set to "value"; the input RGB will be converted to the HSV
	color space, and brightness will be used as the uCoord when
	sampling the shading map. A black input color will result
	in a color lookup from the left side of the shading map, and
	a white input color will correspond to a lookup from the right
	side of the shading map.
	*/
	void setMapFunctionU(const UnsignedintID& mfu){fprintf_s(mFile,"connectAttr \"");mfu.write(mFile);fprintf_s(mFile,"\" \"%s.mfu\";\n",mName.c_str());}
	/*
	Specifies how the input <b>color</b> will be used when looking
	up in the V direction of <b>shadingMapColor</b>. For example,
	if set to "value"; the input RGB will be converted to the HSV
	color space, and brightness will be used as the uCoord when
	sampling the shading map. A black input color will result
	in a color lookup from the bottom side of the shading map, and
	a white input color will correspond to a lookup from the top
	side of the shading map.
	*/
	void setMapFunctionV(unsigned int mfv){if(mfv == 2) return; fprintf_s(mFile, "setAttr \".mfv\" %i;\n", mfv);}
	/*
	Specifies how the input <b>color</b> will be used when looking
	up in the V direction of <b>shadingMapColor</b>. For example,
	if set to "value"; the input RGB will be converted to the HSV
	color space, and brightness will be used as the uCoord when
	sampling the shading map. A black input color will result
	in a color lookup from the bottom side of the shading map, and
	a white input color will correspond to a lookup from the top
	side of the shading map.
	*/
	void setMapFunctionV(const UnsignedintID& mfv){fprintf_s(mFile,"connectAttr \"");mfv.write(mFile);fprintf_s(mFile,"\" \"%s.mfv\";\n",mName.c_str());}
	/*
	<b>Color</b> gives you the base color of the surface.
	Connect the Out Color attribute of another shader
	(such as Phong or Blinn) to this attribute.  This will
	give you the initial color, to which the shading
	map will be applied.
	<p/>In the Attribute Editor, this is combined with Glow
	Color and Transparency into a single attribute called <b>Shader</b>
	*/
	void setColor(const float3& c){fprintf_s(mFile, "setAttr \".c\" -type \"float3\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color</b> gives you the base color of the surface.
	Connect the Out Color attribute of another shader
	(such as Phong or Blinn) to this attribute.  This will
	give you the initial color, to which the shading
	map will be applied.
	<p/>In the Attribute Editor, this is combined with Glow
	Color and Transparency into a single attribute called <b>Shader</b>
	*/
	void setColor(const Float3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*color red value*/
	void setColorR(float cr){if(cr == 0.5) return; fprintf_s(mFile, "setAttr \".c.cr\" %f;\n", cr);}
	/*color red value*/
	void setColorR(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.c.cr\";\n",mName.c_str());}
	/*color green value*/
	void setColorG(float cg){if(cg == 0.5) return; fprintf_s(mFile, "setAttr \".c.cg\" %f;\n", cg);}
	/*color green value*/
	void setColorG(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.c.cg\";\n",mName.c_str());}
	/*color blue value*/
	void setColorB(float cb){if(cb == 0.5) return; fprintf_s(mFile, "setAttr \".c.cb\" %f;\n", cb);}
	/*color blue value*/
	void setColorB(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.c.cb\";\n",mName.c_str());}
	/*
	<b>Shading Map Color</b>.  Connect the Out Color attribute
	of a texture to this attribute.
	This can be a ramp, file, or any other kind of texture.
	<p/><i>Note:</i> If you do no map this attribute, then the
	entire surface will appear to be exactly this color, with
	no shading.
	*/
	void setShadingMapColor(const float3& sc){fprintf_s(mFile, "setAttr \".sc\" -type \"float3\" ");sc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Shading Map Color</b>.  Connect the Out Color attribute
	of a texture to this attribute.
	This can be a ramp, file, or any other kind of texture.
	<p/><i>Note:</i> If you do no map this attribute, then the
	entire surface will appear to be exactly this color, with
	no shading.
	*/
	void setShadingMapColor(const Float3ID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*shading map color red value*/
	void setShadingMapColorR(float scr){if(scr == 0.5) return; fprintf_s(mFile, "setAttr \".sc.scr\" %f;\n", scr);}
	/*shading map color red value*/
	void setShadingMapColorR(const FloatID& scr){fprintf_s(mFile,"connectAttr \"");scr.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scr\";\n",mName.c_str());}
	/*shading map color green value*/
	void setShadingMapColorG(float scg){if(scg == 0.5) return; fprintf_s(mFile, "setAttr \".sc.scg\" %f;\n", scg);}
	/*shading map color green value*/
	void setShadingMapColorG(const FloatID& scg){fprintf_s(mFile,"connectAttr \"");scg.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scg\";\n",mName.c_str());}
	/*shading map color blue value*/
	void setShadingMapColorB(float scb){if(scb == 0.5) return; fprintf_s(mFile, "setAttr \".sc.scb\" %f;\n", scb);}
	/*shading map color blue value*/
	void setShadingMapColorB(const FloatID& scb){fprintf_s(mFile,"connectAttr \"");scb.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scb\";\n",mName.c_str());}
	/*
	<b>Glow Color</b>.  Connect the Out Glow Color attribute of
	the input shader to this attribute.
	<p/>In the Attribute Editor, this is combined with
	Color and Transparency into a single attribute called <b>Shader</b>
	*/
	void setGlowColor(const float3& g){fprintf_s(mFile, "setAttr \".g\" -type \"float3\" ");g.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Glow Color</b>.  Connect the Out Glow Color attribute of
	the input shader to this attribute.
	<p/>In the Attribute Editor, this is combined with
	Color and Transparency into a single attribute called <b>Shader</b>
	*/
	void setGlowColor(const Float3ID& g){fprintf_s(mFile,"connectAttr \"");g.write(mFile);fprintf_s(mFile,"\" \"%s.g\";\n",mName.c_str());}
	/*glow color red value*/
	void setGlowColorR(float gr){if(gr == 0.0) return; fprintf_s(mFile, "setAttr \".g.gr\" %f;\n", gr);}
	/*glow color red value*/
	void setGlowColorR(const FloatID& gr){fprintf_s(mFile,"connectAttr \"");gr.write(mFile);fprintf_s(mFile,"\" \"%s.g.gr\";\n",mName.c_str());}
	/*glow color green value*/
	void setGlowColorG(float gg){if(gg == 0.0) return; fprintf_s(mFile, "setAttr \".g.gg\" %f;\n", gg);}
	/*glow color green value*/
	void setGlowColorG(const FloatID& gg){fprintf_s(mFile,"connectAttr \"");gg.write(mFile);fprintf_s(mFile,"\" \"%s.g.gg\";\n",mName.c_str());}
	/*glow color blue value*/
	void setGlowColorB(float gb){if(gb == 0.0) return; fprintf_s(mFile, "setAttr \".g.gb\" %f;\n", gb);}
	/*glow color blue value*/
	void setGlowColorB(const FloatID& gb){fprintf_s(mFile,"connectAttr \"");gb.write(mFile);fprintf_s(mFile,"\" \"%s.g.gb\";\n",mName.c_str());}
	/*
	<b>Transparency</b>.  Connect the Out Transparency attribute of
	the input shader to this attribute.
	<p/>In the Attribute Editor, this is combined with
	Color and Glow Color into a single attribute called <b>Shader</b>
	*/
	void setTransparency(const float3& it){fprintf_s(mFile, "setAttr \".it\" -type \"float3\" ");it.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Transparency</b>.  Connect the Out Transparency attribute of
	the input shader to this attribute.
	<p/>In the Attribute Editor, this is combined with
	Color and Glow Color into a single attribute called <b>Shader</b>
	*/
	void setTransparency(const Float3ID& it){fprintf_s(mFile,"connectAttr \"");it.write(mFile);fprintf_s(mFile,"\" \"%s.it\";\n",mName.c_str());}
	/*Transparency red value*/
	void setTransparencyR(float itr){if(itr == 0.0) return; fprintf_s(mFile, "setAttr \".it.itr\" %f;\n", itr);}
	/*Transparency red value*/
	void setTransparencyR(const FloatID& itr){fprintf_s(mFile,"connectAttr \"");itr.write(mFile);fprintf_s(mFile,"\" \"%s.it.itr\";\n",mName.c_str());}
	/*Transparency green value*/
	void setTransparencyG(float itg){if(itg == 0.0) return; fprintf_s(mFile, "setAttr \".it.itg\" %f;\n", itg);}
	/*Transparency green value*/
	void setTransparencyG(const FloatID& itg){fprintf_s(mFile,"connectAttr \"");itg.write(mFile);fprintf_s(mFile,"\" \"%s.it.itg\";\n",mName.c_str());}
	/*Transparency blue value*/
	void setTransparencyB(float itb){if(itb == 0.0) return; fprintf_s(mFile, "setAttr \".it.itb\" %f;\n", itb);}
	/*Transparency blue value*/
	void setTransparencyB(const FloatID& itb){fprintf_s(mFile,"connectAttr \"");itb.write(mFile);fprintf_s(mFile,"\" \"%s.it.itb\";\n",mName.c_str());}
	/*output color*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*outColor red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*outColor green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*outColor blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*output Transparency*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*outTransparency red value*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*outTransparency green value*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*outTransparency blue value*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*output color*/
	void setOutGlowColor(const Float3ID& ogc){fprintf_s(mFile,"connectAttr \"");ogc.write(mFile);fprintf_s(mFile,"\" \"%s.ogc\";\n",mName.c_str());}
	/*outColor red value*/
	void setOutGlowColorR(const FloatID& ogr){fprintf_s(mFile,"connectAttr \"");ogr.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogr\";\n",mName.c_str());}
	/*outColor green value*/
	void setOutGlowColorG(const FloatID& ogg){fprintf_s(mFile,"connectAttr \"");ogg.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogg\";\n",mName.c_str());}
	/*outColor blue value*/
	void setOutGlowColorB(const FloatID& ogb){fprintf_s(mFile,"connectAttr \"");ogb.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogb\";\n",mName.c_str());}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this
	when you are creating substitute geometry in a scene, which is
	standing in for objects in a background image that you will be
	compositing with later.  Your stand-in objects will 'punch a hole'
	in the matte.  This allows other computer-generated geometry
	to pass behind your stand-in objects. Later, when foreground
	and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	void setMatteOpacityMode(unsigned int mom){if(mom == 2) return; fprintf_s(mFile, "setAttr \".mom\" %i;\n", mom);}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this
	when you are creating substitute geometry in a scene, which is
	standing in for objects in a background image that you will be
	compositing with later.  Your stand-in objects will 'punch a hole'
	in the matte.  This allows other computer-generated geometry
	to pass behind your stand-in objects. Later, when foreground
	and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	void setMatteOpacityMode(const UnsignedintID& mom){fprintf_s(mFile,"connectAttr \"");mom.write(mFile);fprintf_s(mFile,"\" \"%s.mom\";\n",mName.c_str());}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(float mog){if(mog == 1.0) return; fprintf_s(mFile, "setAttr \".mog\" %f;\n", mog);}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(const FloatID& mog){fprintf_s(mFile,"connectAttr \"");mog.write(mFile);fprintf_s(mFile,"\" \"%s.mog\";\n",mName.c_str());}
	/*output Matte Opacity*/
	void setOutMatteOpacity(const Float3ID& omo){fprintf_s(mFile,"connectAttr \"");omo.write(mFile);fprintf_s(mFile,"\" \"%s.omo\";\n",mName.c_str());}
	/*output Matte Opacity red value*/
	void setOutMatteOpacityR(const FloatID& omor){fprintf_s(mFile,"connectAttr \"");omor.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omor\";\n",mName.c_str());}
	/*output Matte Opacity green value*/
	void setOutMatteOpacityG(const FloatID& omog){fprintf_s(mFile,"connectAttr \"");omog.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omog\";\n",mName.c_str());}
	/*output Matte Opacity blue value*/
	void setOutMatteOpacityB(const FloatID& omob){fprintf_s(mFile,"connectAttr \"");omob.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omob\";\n",mName.c_str());}
	/*
	Derive photon shader parameters from the shading node if enabled,
	otherwise use explicit mental ray attributes.
	*/
	void setMiDeriveFromMaya(bool mifm){if(mifm == true) return; fprintf_s(mFile, "setAttr \".mifm\" %i;\n", mifm);}
	/*
	Derive photon shader parameters from the shading node if enabled,
	otherwise use explicit mental ray attributes.
	*/
	void setMiDeriveFromMaya(const BoolID& mifm){fprintf_s(mFile,"connectAttr \"");mifm.write(mFile);fprintf_s(mFile,"\" \"%s.mifm\";\n",mName.c_str());}
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	void setMiShinyness(float mis){if(mis == 10) return; fprintf_s(mFile, "setAttr \".mis\" %f;\n", mis);}
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	void setMiShinyness(const FloatID& mis){fprintf_s(mFile,"connectAttr \"");mis.write(mFile);fprintf_s(mFile,"\" \"%s.mis\";\n",mName.c_str());}
	/*Photon shader angle parameter to control direction of anisotropic feature.*/
	void setMiAngle(float mia){if(mia == 0) return; fprintf_s(mFile, "setAttr \".mia\" %f;\n", mia);}
	/*Photon shader angle parameter to control direction of anisotropic feature.*/
	void setMiAngle(const FloatID& mia){fprintf_s(mFile,"connectAttr \"");mia.write(mFile);fprintf_s(mFile,"\" \"%s.mia\";\n",mName.c_str());}
	/*Photon shader x spread parameter to control size of anisotropic feature in x direction.*/
	void setMiSpreadX(float misx){if(misx == 10) return; fprintf_s(mFile, "setAttr \".misx\" %f;\n", misx);}
	/*Photon shader x spread parameter to control size of anisotropic feature in x direction.*/
	void setMiSpreadX(const FloatID& misx){fprintf_s(mFile,"connectAttr \"");misx.write(mFile);fprintf_s(mFile,"\" \"%s.misx\";\n",mName.c_str());}
	/*Photon shader spread parameter to control size of anisotropic feature in y direction.*/
	void setMiSpreadY(float misy){if(misy == 5) return; fprintf_s(mFile, "setAttr \".misy\" %f;\n", misy);}
	/*Photon shader spread parameter to control size of anisotropic feature in y direction.*/
	void setMiSpreadY(const FloatID& misy){fprintf_s(mFile,"connectAttr \"");misy.write(mFile);fprintf_s(mFile,"\" \"%s.misy\";\n",mName.c_str());}
	/*Photon shader whiteness parameter.*/
	void setMiWhiteness(const float3& miwn){fprintf_s(mFile, "setAttr \".miwn\" -type \"float3\" ");miwn.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader whiteness parameter.*/
	void setMiWhiteness(const Float3ID& miwn){fprintf_s(mFile,"connectAttr \"");miwn.write(mFile);fprintf_s(mFile,"\" \"%s.miwn\";\n",mName.c_str());}
	/*Red component.*/
	void setMiWhitenessR(float miwnr){if(miwnr == 0.5) return; fprintf_s(mFile, "setAttr \".miwn.miwnr\" %f;\n", miwnr);}
	/*Red component.*/
	void setMiWhitenessR(const FloatID& miwnr){fprintf_s(mFile,"connectAttr \"");miwnr.write(mFile);fprintf_s(mFile,"\" \"%s.miwn.miwnr\";\n",mName.c_str());}
	/*Green component.*/
	void setMiWhitenessG(float miwng){if(miwng == 0.5) return; fprintf_s(mFile, "setAttr \".miwn.miwng\" %f;\n", miwng);}
	/*Green component.*/
	void setMiWhitenessG(const FloatID& miwng){fprintf_s(mFile,"connectAttr \"");miwng.write(mFile);fprintf_s(mFile,"\" \"%s.miwn.miwng\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiWhitenessB(float miwnb){if(miwnb == 0.5) return; fprintf_s(mFile, "setAttr \".miwn.miwnb\" %f;\n", miwnb);}
	/*Blue component.*/
	void setMiWhitenessB(const FloatID& miwnb){fprintf_s(mFile,"connectAttr \"");miwnb.write(mFile);fprintf_s(mFile,"\" \"%s.miwn.miwnb\";\n",mName.c_str());}
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const float3& misc){fprintf_s(mFile, "setAttr \".misc\" -type \"float3\" ");misc.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader specular color parameter.*/
	void setMiSpecularColor(const Float3ID& misc){fprintf_s(mFile,"connectAttr \"");misc.write(mFile);fprintf_s(mFile,"\" \"%s.misc\";\n",mName.c_str());}
	/*Red component.*/
	void setMiSpecularColorR(float miscr){if(miscr == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscr\" %f;\n", miscr);}
	/*Red component.*/
	void setMiSpecularColorR(const FloatID& miscr){fprintf_s(mFile,"connectAttr \"");miscr.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscr\";\n",mName.c_str());}
	/*Green component.*/
	void setMiSpecularColorG(float miscg){if(miscg == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscg\" %f;\n", miscg);}
	/*Green component.*/
	void setMiSpecularColorG(const FloatID& miscg){fprintf_s(mFile,"connectAttr \"");miscg.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscg\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiSpecularColorB(float miscb){if(miscb == 0.5) return; fprintf_s(mFile, "setAttr \".misc.miscb\" %f;\n", miscb);}
	/*Blue component.*/
	void setMiSpecularColorB(const FloatID& miscb){fprintf_s(mFile,"connectAttr \"");miscb.write(mFile);fprintf_s(mFile,"\" \"%s.misc.miscb\";\n",mName.c_str());}
	/*Photon shader reflectivity parameter.*/
	void setMiReflectivity(float mirf){if(mirf == 0.5) return; fprintf_s(mFile, "setAttr \".mirf\" %f;\n", mirf);}
	/*Photon shader reflectivity parameter.*/
	void setMiReflectivity(const FloatID& mirf){fprintf_s(mFile,"connectAttr \"");mirf.write(mFile);fprintf_s(mFile,"\" \"%s.mirf\";\n",mName.c_str());}
	/*Photon shader index-of-refraction parameter.*/
	void setMiRefractiveIndex(float miri){if(miri == 1) return; fprintf_s(mFile, "setAttr \".miri\" %f;\n", miri);}
	/*Photon shader index-of-refraction parameter.*/
	void setMiRefractiveIndex(const FloatID& miri){fprintf_s(mFile,"connectAttr \"");miri.write(mFile);fprintf_s(mFile,"\" \"%s.miri\";\n",mName.c_str());}
	/*Photon shader refractions parameter.*/
	void setMiRefractions(bool mirc){if(mirc == true) return; fprintf_s(mFile, "setAttr \".mirc\" %i;\n", mirc);}
	/*Photon shader refractions parameter.*/
	void setMiRefractions(const BoolID& mirc){fprintf_s(mFile,"connectAttr \"");mirc.write(mFile);fprintf_s(mFile,"\" \"%s.mirc\";\n",mName.c_str());}
	/*Photon shader absorption parameter.*/
	void setMiAbsorbs(bool miab){if(miab == true) return; fprintf_s(mFile, "setAttr \".miab\" %i;\n", miab);}
	/*Photon shader absorption parameter.*/
	void setMiAbsorbs(const BoolID& miab){fprintf_s(mFile,"connectAttr \"");miab.write(mFile);fprintf_s(mFile,"\" \"%s.miab\";\n",mName.c_str());}
	/*Photon shader diffuse parameter.*/
	void setMiDiffuse(float midc){if(midc == 0.8) return; fprintf_s(mFile, "setAttr \".midc\" %f;\n", midc);}
	/*Photon shader diffuse parameter.*/
	void setMiDiffuse(const FloatID& midc){fprintf_s(mFile,"connectAttr \"");midc.write(mFile);fprintf_s(mFile,"\" \"%s.midc\";\n",mName.c_str());}
	/*Photon shader base color parameter.*/
	void setMiColor(const float3& mic){fprintf_s(mFile, "setAttr \".mic\" -type \"float3\" ");mic.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader base color parameter.*/
	void setMiColor(const Float3ID& mic){fprintf_s(mFile,"connectAttr \"");mic.write(mFile);fprintf_s(mFile,"\" \"%s.mic\";\n",mName.c_str());}
	/*Red component.*/
	void setMiColorR(float micr){if(micr == 0.5) return; fprintf_s(mFile, "setAttr \".mic.micr\" %f;\n", micr);}
	/*Red component.*/
	void setMiColorR(const FloatID& micr){fprintf_s(mFile,"connectAttr \"");micr.write(mFile);fprintf_s(mFile,"\" \"%s.mic.micr\";\n",mName.c_str());}
	/*Green component.*/
	void setMiColorG(float micg){if(micg == 0.5) return; fprintf_s(mFile, "setAttr \".mic.micg\" %f;\n", micg);}
	/*Green component.*/
	void setMiColorG(const FloatID& micg){fprintf_s(mFile,"connectAttr \"");micg.write(mFile);fprintf_s(mFile,"\" \"%s.mic.micg\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiColorB(float micb){if(micb == 0.5) return; fprintf_s(mFile, "setAttr \".mic.micb\" %f;\n", micb);}
	/*Blue component.*/
	void setMiColorB(const FloatID& micb){fprintf_s(mFile,"connectAttr \"");micb.write(mFile);fprintf_s(mFile,"\" \"%s.mic.micb\";\n",mName.c_str());}
	/*Photon shader transparency parameter.*/
	void setMiTransparency(const float3& mit){fprintf_s(mFile, "setAttr \".mit\" -type \"float3\" ");mit.write(mFile);fprintf_s(mFile,";\n");}
	/*Photon shader transparency parameter.*/
	void setMiTransparency(const Float3ID& mit){fprintf_s(mFile,"connectAttr \"");mit.write(mFile);fprintf_s(mFile,"\" \"%s.mit\";\n",mName.c_str());}
	/*Red component.*/
	void setMiTransparencyR(float mitr){if(mitr == 0) return; fprintf_s(mFile, "setAttr \".mit.mitr\" %f;\n", mitr);}
	/*Red component.*/
	void setMiTransparencyR(const FloatID& mitr){fprintf_s(mFile,"connectAttr \"");mitr.write(mFile);fprintf_s(mFile,"\" \"%s.mit.mitr\";\n",mName.c_str());}
	/*Green component.*/
	void setMiTransparencyG(float mitg){if(mitg == 0) return; fprintf_s(mFile, "setAttr \".mit.mitg\" %f;\n", mitg);}
	/*Green component.*/
	void setMiTransparencyG(const FloatID& mitg){fprintf_s(mFile,"connectAttr \"");mitg.write(mFile);fprintf_s(mFile,"\" \"%s.mit.mitg\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiTransparencyB(float mitb){if(mitb == 0) return; fprintf_s(mFile, "setAttr \".mit.mitb\" %f;\n", mitb);}
	/*Blue component.*/
	void setMiTransparencyB(const FloatID& mitb){fprintf_s(mFile,"connectAttr \"");mitb.write(mFile);fprintf_s(mFile,"\" \"%s.mit.mitb\";\n",mName.c_str());}
	/*Photon shader translucency parameter.*/
	void setMiTranslucence(float mitc){if(mitc == 0) return; fprintf_s(mFile, "setAttr \".mitc\" %f;\n", mitc);}
	/*Photon shader translucency parameter.*/
	void setMiTranslucence(const FloatID& mitc){fprintf_s(mFile,"connectAttr \"");mitc.write(mFile);fprintf_s(mFile,"\" \"%s.mitc\";\n",mName.c_str());}
	/*Photon shader translucence focus parameter.*/
	void setMiTranslucenceFocus(float mitf){if(mitf == 0.5) return; fprintf_s(mFile, "setAttr \".mitf\" %f;\n", mitf);}
	/*Photon shader translucence focus parameter.*/
	void setMiTranslucenceFocus(const FloatID& mitf){fprintf_s(mFile,"connectAttr \"");mitf.write(mFile);fprintf_s(mFile,"\" \"%s.mitf\";\n",mName.c_str());}
	/*Port to connect bump node for photon shader.*/
	void setMiNormalCamera(const float3& minc){fprintf_s(mFile, "setAttr \".minc\" -type \"float3\" ");minc.write(mFile);fprintf_s(mFile,";\n");}
	/*Port to connect bump node for photon shader.*/
	void setMiNormalCamera(const Float3ID& minc){fprintf_s(mFile,"connectAttr \"");minc.write(mFile);fprintf_s(mFile,"\" \"%s.minc\";\n",mName.c_str());}
	/*X component.*/
	void setMiNormalCameraX(float mincx){if(mincx == 0) return; fprintf_s(mFile, "setAttr \".minc.mincx\" %f;\n", mincx);}
	/*X component.*/
	void setMiNormalCameraX(const FloatID& mincx){fprintf_s(mFile,"connectAttr \"");mincx.write(mFile);fprintf_s(mFile,"\" \"%s.minc.mincx\";\n",mName.c_str());}
	/*Y component.*/
	void setMiNormalCameraY(float mincy){if(mincy == 0) return; fprintf_s(mFile, "setAttr \".minc.mincy\" %f;\n", mincy);}
	/*Y component.*/
	void setMiNormalCameraY(const FloatID& mincy){fprintf_s(mFile,"connectAttr \"");mincy.write(mFile);fprintf_s(mFile,"\" \"%s.minc.mincy\";\n",mName.c_str());}
	/*Z component.*/
	void setMiNormalCameraZ(float mincz){if(mincz == 0) return; fprintf_s(mFile, "setAttr \".minc.mincz\" %f;\n", mincz);}
	/*Z component.*/
	void setMiNormalCameraZ(const FloatID& mincz){fprintf_s(mFile,"connectAttr \"");mincz.write(mFile);fprintf_s(mFile,"\" \"%s.minc.mincz\";\n",mName.c_str());}
	/*The UV coords of the current sample point*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.uu",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.vv",mName.c_str());return (const char*)buffer;}
	/*
	Specifies how the input <b>color</b> will be used when looking
	up in the U direction of <b>shadingMapColor</b>. For example,
	if set to "value"; the input RGB will be converted to the HSV
	color space, and brightness will be used as the uCoord when
	sampling the shading map. A black input color will result
	in a color lookup from the left side of the shading map, and
	a white input color will correspond to a lookup from the right
	side of the shading map.
	*/
	UnsignedintID getMapFunctionU(){char buffer[4096];sprintf_s (buffer, "%s.mfu",mName.c_str());return (const char*)buffer;}
	/*
	Specifies how the input <b>color</b> will be used when looking
	up in the V direction of <b>shadingMapColor</b>. For example,
	if set to "value"; the input RGB will be converted to the HSV
	color space, and brightness will be used as the uCoord when
	sampling the shading map. A black input color will result
	in a color lookup from the bottom side of the shading map, and
	a white input color will correspond to a lookup from the top
	side of the shading map.
	*/
	UnsignedintID getMapFunctionV(){char buffer[4096];sprintf_s (buffer, "%s.mfv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color</b> gives you the base color of the surface.
	Connect the Out Color attribute of another shader
	(such as Phong or Blinn) to this attribute.  This will
	give you the initial color, to which the shading
	map will be applied.
	<p/>In the Attribute Editor, this is combined with Glow
	Color and Transparency into a single attribute called <b>Shader</b>
	*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*color red value*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.c.cr",mName.c_str());return (const char*)buffer;}
	/*color green value*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.c.cg",mName.c_str());return (const char*)buffer;}
	/*color blue value*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.c.cb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Shading Map Color</b>.  Connect the Out Color attribute
	of a texture to this attribute.
	This can be a ramp, file, or any other kind of texture.
	<p/><i>Note:</i> If you do no map this attribute, then the
	entire surface will appear to be exactly this color, with
	no shading.
	*/
	Float3ID getShadingMapColor(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*shading map color red value*/
	FloatID getShadingMapColorR(){char buffer[4096];sprintf_s (buffer, "%s.sc.scr",mName.c_str());return (const char*)buffer;}
	/*shading map color green value*/
	FloatID getShadingMapColorG(){char buffer[4096];sprintf_s (buffer, "%s.sc.scg",mName.c_str());return (const char*)buffer;}
	/*shading map color blue value*/
	FloatID getShadingMapColorB(){char buffer[4096];sprintf_s (buffer, "%s.sc.scb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Color</b>.  Connect the Out Glow Color attribute of
	the input shader to this attribute.
	<p/>In the Attribute Editor, this is combined with
	Color and Transparency into a single attribute called <b>Shader</b>
	*/
	Float3ID getGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.g",mName.c_str());return (const char*)buffer;}
	/*glow color red value*/
	FloatID getGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.g.gr",mName.c_str());return (const char*)buffer;}
	/*glow color green value*/
	FloatID getGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.g.gg",mName.c_str());return (const char*)buffer;}
	/*glow color blue value*/
	FloatID getGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.g.gb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Transparency</b>.  Connect the Out Transparency attribute of
	the input shader to this attribute.
	<p/>In the Attribute Editor, this is combined with
	Color and Glow Color into a single attribute called <b>Shader</b>
	*/
	Float3ID getTransparency(){char buffer[4096];sprintf_s (buffer, "%s.it",mName.c_str());return (const char*)buffer;}
	/*Transparency red value*/
	FloatID getTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.it.itr",mName.c_str());return (const char*)buffer;}
	/*Transparency green value*/
	FloatID getTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.it.itg",mName.c_str());return (const char*)buffer;}
	/*Transparency blue value*/
	FloatID getTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.it.itb",mName.c_str());return (const char*)buffer;}
	/*output color*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*outColor red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*outColor green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*outColor blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*output Transparency*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*outTransparency red value*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*outTransparency green value*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*outTransparency blue value*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*output color*/
	Float3ID getOutGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.ogc",mName.c_str());return (const char*)buffer;}
	/*outColor red value*/
	FloatID getOutGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogr",mName.c_str());return (const char*)buffer;}
	/*outColor green value*/
	FloatID getOutGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogg",mName.c_str());return (const char*)buffer;}
	/*outColor blue value*/
	FloatID getOutGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this
	when you are creating substitute geometry in a scene, which is
	standing in for objects in a background image that you will be
	compositing with later.  Your stand-in objects will 'punch a hole'
	in the matte.  This allows other computer-generated geometry
	to pass behind your stand-in objects. Later, when foreground
	and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	UnsignedintID getMatteOpacityMode(){char buffer[4096];sprintf_s (buffer, "%s.mom",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	FloatID getMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.mog",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity*/
	Float3ID getOutMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.omo",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity red value*/
	FloatID getOutMatteOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.omo.omor",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity green value*/
	FloatID getOutMatteOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.omo.omog",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity blue value*/
	FloatID getOutMatteOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.omo.omob",mName.c_str());return (const char*)buffer;}
	/*
	Derive photon shader parameters from the shading node if enabled,
	otherwise use explicit mental ray attributes.
	*/
	BoolID getMiDeriveFromMaya(){char buffer[4096];sprintf_s (buffer, "%s.mifm",mName.c_str());return (const char*)buffer;}
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	FloatID getMiShinyness(){char buffer[4096];sprintf_s (buffer, "%s.mis",mName.c_str());return (const char*)buffer;}
	/*Photon shader angle parameter to control direction of anisotropic feature.*/
	FloatID getMiAngle(){char buffer[4096];sprintf_s (buffer, "%s.mia",mName.c_str());return (const char*)buffer;}
	/*Photon shader x spread parameter to control size of anisotropic feature in x direction.*/
	FloatID getMiSpreadX(){char buffer[4096];sprintf_s (buffer, "%s.misx",mName.c_str());return (const char*)buffer;}
	/*Photon shader spread parameter to control size of anisotropic feature in y direction.*/
	FloatID getMiSpreadY(){char buffer[4096];sprintf_s (buffer, "%s.misy",mName.c_str());return (const char*)buffer;}
	/*Photon shader whiteness parameter.*/
	Float3ID getMiWhiteness(){char buffer[4096];sprintf_s (buffer, "%s.miwn",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiWhitenessR(){char buffer[4096];sprintf_s (buffer, "%s.miwn.miwnr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiWhitenessG(){char buffer[4096];sprintf_s (buffer, "%s.miwn.miwng",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiWhitenessB(){char buffer[4096];sprintf_s (buffer, "%s.miwn.miwnb",mName.c_str());return (const char*)buffer;}
	/*Photon shader specular color parameter.*/
	Float3ID getMiSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.misc",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.misc.miscb",mName.c_str());return (const char*)buffer;}
	/*Photon shader reflectivity parameter.*/
	FloatID getMiReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.mirf",mName.c_str());return (const char*)buffer;}
	/*Photon shader index-of-refraction parameter.*/
	FloatID getMiRefractiveIndex(){char buffer[4096];sprintf_s (buffer, "%s.miri",mName.c_str());return (const char*)buffer;}
	/*Photon shader refractions parameter.*/
	BoolID getMiRefractions(){char buffer[4096];sprintf_s (buffer, "%s.mirc",mName.c_str());return (const char*)buffer;}
	/*Photon shader absorption parameter.*/
	BoolID getMiAbsorbs(){char buffer[4096];sprintf_s (buffer, "%s.miab",mName.c_str());return (const char*)buffer;}
	/*Photon shader diffuse parameter.*/
	FloatID getMiDiffuse(){char buffer[4096];sprintf_s (buffer, "%s.midc",mName.c_str());return (const char*)buffer;}
	/*Photon shader base color parameter.*/
	Float3ID getMiColor(){char buffer[4096];sprintf_s (buffer, "%s.mic",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiColorR(){char buffer[4096];sprintf_s (buffer, "%s.mic.micr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiColorG(){char buffer[4096];sprintf_s (buffer, "%s.mic.micg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiColorB(){char buffer[4096];sprintf_s (buffer, "%s.mic.micb",mName.c_str());return (const char*)buffer;}
	/*Photon shader transparency parameter.*/
	Float3ID getMiTransparency(){char buffer[4096];sprintf_s (buffer, "%s.mit",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.mit.mitr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.mit.mitg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.mit.mitb",mName.c_str());return (const char*)buffer;}
	/*Photon shader translucency parameter.*/
	FloatID getMiTranslucence(){char buffer[4096];sprintf_s (buffer, "%s.mitc",mName.c_str());return (const char*)buffer;}
	/*Photon shader translucence focus parameter.*/
	FloatID getMiTranslucenceFocus(){char buffer[4096];sprintf_s (buffer, "%s.mitf",mName.c_str());return (const char*)buffer;}
	/*Port to connect bump node for photon shader.*/
	Float3ID getMiNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.minc",mName.c_str());return (const char*)buffer;}
	/*X component.*/
	FloatID getMiNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.minc.mincx",mName.c_str());return (const char*)buffer;}
	/*Y component.*/
	FloatID getMiNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.minc.mincy",mName.c_str());return (const char*)buffer;}
	/*Z component.*/
	FloatID getMiNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.minc.mincz",mName.c_str());return (const char*)buffer;}
protected:
	ShadingMap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SHADINGMAP_H__
