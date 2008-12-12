/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LAYEREDSHADER_H__
#define __MayaDM_LAYEREDSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Use a <b>Layered Shader</b> to combine two or more shaders
  into a single shader, or to combine two or more textures into
  a single texture.
  <p/>
  To do this, connect the Out Color attribute of two or more
  shaders (or textures) to the Color attribute of this node.
  Then use the Transparency
  attribute for each input color to control its contribution to the
  output color of this node.
  <p/>
  You can also connect the Out Transparency attribute of
  the other shaders to the Transparency attribute of this shader.  These
  transparency values will then determine the contribution
  of each input shader to this Layered Shader.
  <p/>
  Similarly, the Out Glow attributes of other shaders can be
  connected to the Glow attribute of this shader.  These glow
  value will be combined, just like the colors.
  <p/>
  In the table below, important attribute have their names indicated
  in <b>bold</b> in the description column.
*/
class LayeredShader : public DependNode
{
public:
	/*
	This is the list of input colors, transparencies, and glows
	that will be combined in this Layered Shader.
	*/
	struct Inputs{
		float3 color;
		float3 transparency;
		float3 glowColor;
		void write(FILE* file) const
		{
			color.write(file);
			fprintf_s(file, " ");
			transparency.write(file);
			fprintf_s(file, " ");
			glowColor.write(file);
		}
	};
public:
	LayeredShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "layeredShader"){}
	virtual ~LayeredShader(){}
	/*
	Use the <b>Compositing Flag</b> to control how the different
	input shaders or textures are combined together.  It has two modes:
	<ul>
	<li><b>Layer Shaders</b>:  Use this setting if you are combining
	multiple shaders into a single new shader.</li>
	<li><b>Layer Texture</b>:  Use this setting if you are combining
	multiple textures into a single new texture.</li>
	</ul>
	*/
	void setCompositingFlag(unsigned int cf){if(cf == 0) return; fprintf_s(mFile, "setAttr \".cf\" %i;\n", cf);}
	/*
	Use the <b>Compositing Flag</b> to control how the different
	input shaders or textures are combined together.  It has two modes:
	<ul>
	<li><b>Layer Shaders</b>:  Use this setting if you are combining
	multiple shaders into a single new shader.</li>
	<li><b>Layer Texture</b>:  Use this setting if you are combining
	multiple textures into a single new texture.</li>
	</ul>
	*/
	void setCompositingFlag(const UnsignedintID& cf){fprintf_s(mFile,"connectAttr \"");cf.write(mFile);fprintf_s(mFile,"\" \"%s.cf\";\n",mName.c_str());}
	/*
	This is the list of input colors, transparencies, and glows
	that will be combined in this Layered Shader.
	*/
	void setInputs(size_t cs_i,const Inputs& cs){fprintf_s(mFile, "setAttr \".cs[%i]\" ",cs_i);cs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is the list of input colors, transparencies, and glows
	that will be combined in this Layered Shader.
	*/
	void setInputs(size_t cs_i,const InputsID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i]\";\n",mName.c_str(),cs_i);}
	/*
	<b>Color</b> affects the final color of the layered
	shader.  Connect the output color attributes of other
	shaders to this attribute to combine them into a single
	shader.
	*/
	void setColor(size_t cs_i,const float3& c){fprintf_s(mFile, "setAttr \".cs[%i].c\" -type \"float3\" ",cs_i);c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color</b> affects the final color of the layered
	shader.  Connect the output color attributes of other
	shaders to this attribute to combine them into a single
	shader.
	*/
	void setColor(size_t cs_i,const Float3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].c\";\n",mName.c_str(),cs_i);}
	/*color red value*/
	void setColorR(size_t cs_i,float cr){if(cr == 0.0) return; fprintf_s(mFile, "setAttr \".cs[%i].c.cr\" %f;\n", cs_i,cr);}
	/*color red value*/
	void setColorR(size_t cs_i,const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].c.cr\";\n",mName.c_str(),cs_i);}
	/*color green value*/
	void setColorG(size_t cs_i,float cg){if(cg == 0.0) return; fprintf_s(mFile, "setAttr \".cs[%i].c.cg\" %f;\n", cs_i,cg);}
	/*color green value*/
	void setColorG(size_t cs_i,const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].c.cg\";\n",mName.c_str(),cs_i);}
	/*color blue value*/
	void setColorB(size_t cs_i,float cb){if(cb == 0.0) return; fprintf_s(mFile, "setAttr \".cs[%i].c.cb\" %f;\n", cs_i,cb);}
	/*color blue value*/
	void setColorB(size_t cs_i,const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].c.cb\";\n",mName.c_str(),cs_i);}
	/*
	<b>Transparency</b> controls the amount each color input
	contributes to the final color of this shader.  This attribute
	has a different value for each input color.  Set this darker
	to make the layer more opaque (that is, to make the layer
	contributes more).
	Set this brighter to make the layer more transparent.
	*/
	void setTransparency(size_t cs_i,const float3& t){fprintf_s(mFile, "setAttr \".cs[%i].t\" -type \"float3\" ",cs_i);t.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Transparency</b> controls the amount each color input
	contributes to the final color of this shader.  This attribute
	has a different value for each input color.  Set this darker
	to make the layer more opaque (that is, to make the layer
	contributes more).
	Set this brighter to make the layer more transparent.
	*/
	void setTransparency(size_t cs_i,const Float3ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].t\";\n",mName.c_str(),cs_i);}
	/*Transparency red value*/
	void setTransparencyR(size_t cs_i,float tr){if(tr == 1.0) return; fprintf_s(mFile, "setAttr \".cs[%i].t.tr\" %f;\n", cs_i,tr);}
	/*Transparency red value*/
	void setTransparencyR(size_t cs_i,const FloatID& tr){fprintf_s(mFile,"connectAttr \"");tr.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].t.tr\";\n",mName.c_str(),cs_i);}
	/*Transparency green value*/
	void setTransparencyG(size_t cs_i,float tg){if(tg == 1.0) return; fprintf_s(mFile, "setAttr \".cs[%i].t.tg\" %f;\n", cs_i,tg);}
	/*Transparency green value*/
	void setTransparencyG(size_t cs_i,const FloatID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].t.tg\";\n",mName.c_str(),cs_i);}
	/*Transparency blue value*/
	void setTransparencyB(size_t cs_i,float tb){if(tb == 1.0) return; fprintf_s(mFile, "setAttr \".cs[%i].t.tb\" %f;\n", cs_i,tb);}
	/*Transparency blue value*/
	void setTransparencyB(size_t cs_i,const FloatID& tb){fprintf_s(mFile,"connectAttr \"");tb.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].t.tb\";\n",mName.c_str(),cs_i);}
	/*
	<b>Glow Color</b> allows you to combine the glow attributes of
	the input shaders into a single glow, just as you combine the
	colors.  Connect the Output Glow Color of the other shaders to
	this attribute.  The Transparency values above will be applied
	when combining the glow values.
	*/
	void setGlowColor(size_t cs_i,const float3& g){fprintf_s(mFile, "setAttr \".cs[%i].g\" -type \"float3\" ",cs_i);g.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Glow Color</b> allows you to combine the glow attributes of
	the input shaders into a single glow, just as you combine the
	colors.  Connect the Output Glow Color of the other shaders to
	this attribute.  The Transparency values above will be applied
	when combining the glow values.
	*/
	void setGlowColor(size_t cs_i,const Float3ID& g){fprintf_s(mFile,"connectAttr \"");g.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].g\";\n",mName.c_str(),cs_i);}
	/*glow color red value*/
	void setGlowColorR(size_t cs_i,float gr){if(gr == 0.0) return; fprintf_s(mFile, "setAttr \".cs[%i].g.gr\" %f;\n", cs_i,gr);}
	/*glow color red value*/
	void setGlowColorR(size_t cs_i,const FloatID& gr){fprintf_s(mFile,"connectAttr \"");gr.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].g.gr\";\n",mName.c_str(),cs_i);}
	/*glow color green value*/
	void setGlowColorG(size_t cs_i,float gg){if(gg == 0.0) return; fprintf_s(mFile, "setAttr \".cs[%i].g.gg\" %f;\n", cs_i,gg);}
	/*glow color green value*/
	void setGlowColorG(size_t cs_i,const FloatID& gg){fprintf_s(mFile,"connectAttr \"");gg.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].g.gg\";\n",mName.c_str(),cs_i);}
	/*glow color blue value*/
	void setGlowColorB(size_t cs_i,float gb){if(gb == 0.0) return; fprintf_s(mFile, "setAttr \".cs[%i].g.gb\" %f;\n", cs_i,gb);}
	/*glow color blue value*/
	void setGlowColorB(size_t cs_i,const FloatID& gb){fprintf_s(mFile,"connectAttr \"");gb.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].g.gb\";\n",mName.c_str(),cs_i);}
	/*
	<b>Hardware Color</b> tells Maya what color to make the
	material appear when you are looking at the view in shaded mode.
	This is not used when rendering, only for faster display.
	When the final image is rendered, you will see the layers
	in the layered shader.
	*/
	void setHardwareColor(const float3& hc){fprintf_s(mFile, "setAttr \".hc\" -type \"float3\" ");hc.write(mFile);fprintf_s(mFile,";\n");}
	/*hardware color R value*/
	void setHardwareColorR(float hcr){if(hcr == 0.5) return; fprintf_s(mFile, "setAttr \".hc.hcr\" %f;\n", hcr);}
	/*hardware color G value*/
	void setHardwareColorG(float hcg){if(hcg == 0.5) return; fprintf_s(mFile, "setAttr \".hc.hcg\" %f;\n", hcg);}
	/*hardware color B value*/
	void setHardwareColorB(float hcb){if(hcb == 0.5) return; fprintf_s(mFile, "setAttr \".hc.hcb\" %f;\n", hcb);}
	/*
	Attribute to be connected to a hardware shader in order to
	override drawing in the 3d view.
	*/
	void setHardwareShader(const Float3ID& hws){fprintf_s(mFile,"connectAttr \"");hws.write(mFile);fprintf_s(mFile,"\" \"%s.hws\";\n",mName.c_str());}
	/*Red component.*/
	void setHardwareShaderR(const FloatID& hwr){fprintf_s(mFile,"connectAttr \"");hwr.write(mFile);fprintf_s(mFile,"\" \"%s.hws.hwr\";\n",mName.c_str());}
	/*Green component.*/
	void setHardwareShaderG(const FloatID& hwg){fprintf_s(mFile,"connectAttr \"");hwg.write(mFile);fprintf_s(mFile,"\" \"%s.hws.hwg\";\n",mName.c_str());}
	/*Blue component.*/
	void setHardwareShaderB(const FloatID& hwb){fprintf_s(mFile,"connectAttr \"");hwb.write(mFile);fprintf_s(mFile,"\" \"%s.hws.hwb\";\n",mName.c_str());}
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
	/*outGlowColor red value*/
	void setOutGlowColorR(const FloatID& ogr){fprintf_s(mFile,"connectAttr \"");ogr.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogr\";\n",mName.c_str());}
	/*outGlowColor green value*/
	void setOutGlowColorG(const FloatID& ogg){fprintf_s(mFile,"connectAttr \"");ogg.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogg\";\n",mName.c_str());}
	/*outGlowColor blue value*/
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
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
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
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
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
	/*
	Use the <b>Compositing Flag</b> to control how the different
	input shaders or textures are combined together.  It has two modes:
	<ul>
	<li><b>Layer Shaders</b>:  Use this setting if you are combining
	multiple shaders into a single new shader.</li>
	<li><b>Layer Texture</b>:  Use this setting if you are combining
	multiple textures into a single new texture.</li>
	</ul>
	*/
	UnsignedintID getCompositingFlag(){char buffer[4096];sprintf_s (buffer, "%s.cf",mName.c_str());return (const char*)buffer;}
	/*
	This is the list of input colors, transparencies, and glows
	that will be combined in this Layered Shader.
	*/
	const InputsID& getInputs(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i]",mName.c_str(),cs_i);return (const char*)buffer;}
	/*
	<b>Color</b> affects the final color of the layered
	shader.  Connect the output color attributes of other
	shaders to this attribute to combine them into a single
	shader.
	*/
	const Float3ID& getColor(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].c",mName.c_str(),cs_i);return (const char*)buffer;}
	/*color red value*/
	const FloatID& getColorR(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].c.cr",mName.c_str(),cs_i);return (const char*)buffer;}
	/*color green value*/
	const FloatID& getColorG(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].c.cg",mName.c_str(),cs_i);return (const char*)buffer;}
	/*color blue value*/
	const FloatID& getColorB(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].c.cb",mName.c_str(),cs_i);return (const char*)buffer;}
	/*
	<b>Transparency</b> controls the amount each color input
	contributes to the final color of this shader.  This attribute
	has a different value for each input color.  Set this darker
	to make the layer more opaque (that is, to make the layer
	contributes more).
	Set this brighter to make the layer more transparent.
	*/
	const Float3ID& getTransparency(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].t",mName.c_str(),cs_i);return (const char*)buffer;}
	/*Transparency red value*/
	const FloatID& getTransparencyR(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].t.tr",mName.c_str(),cs_i);return (const char*)buffer;}
	/*Transparency green value*/
	const FloatID& getTransparencyG(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].t.tg",mName.c_str(),cs_i);return (const char*)buffer;}
	/*Transparency blue value*/
	const FloatID& getTransparencyB(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].t.tb",mName.c_str(),cs_i);return (const char*)buffer;}
	/*
	<b>Glow Color</b> allows you to combine the glow attributes of
	the input shaders into a single glow, just as you combine the
	colors.  Connect the Output Glow Color of the other shaders to
	this attribute.  The Transparency values above will be applied
	when combining the glow values.
	*/
	const Float3ID& getGlowColor(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].g",mName.c_str(),cs_i);return (const char*)buffer;}
	/*glow color red value*/
	const FloatID& getGlowColorR(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].g.gr",mName.c_str(),cs_i);return (const char*)buffer;}
	/*glow color green value*/
	const FloatID& getGlowColorG(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].g.gg",mName.c_str(),cs_i);return (const char*)buffer;}
	/*glow color blue value*/
	const FloatID& getGlowColorB(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].g.gb",mName.c_str(),cs_i);return (const char*)buffer;}
	/*
	Attribute to be connected to a hardware shader in order to
	override drawing in the 3d view.
	*/
	Float3ID getHardwareShader(){char buffer[4096];sprintf_s (buffer, "%s.hws",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getHardwareShaderR(){char buffer[4096];sprintf_s (buffer, "%s.hws.hwr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getHardwareShaderG(){char buffer[4096];sprintf_s (buffer, "%s.hws.hwg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getHardwareShaderB(){char buffer[4096];sprintf_s (buffer, "%s.hws.hwb",mName.c_str());return (const char*)buffer;}
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
	/*outGlowColor red value*/
	FloatID getOutGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogr",mName.c_str());return (const char*)buffer;}
	/*outGlowColor green value*/
	FloatID getOutGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogg",mName.c_str());return (const char*)buffer;}
	/*outGlowColor blue value*/
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
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
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
	LayeredShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LAYEREDSHADER_H__
