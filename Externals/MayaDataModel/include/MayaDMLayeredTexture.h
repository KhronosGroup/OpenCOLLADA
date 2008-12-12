/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LAYEREDTEXTURE_H__
#define __MayaDM_LAYEREDTEXTURE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The Layered Texture node can be used to layer multiple textures one on top
 of another to produce a single result texture. <p/>

 There are also a number of different blend modes which you can use to
 specify exactly how each layer is to be composited with the layers beneath
 it. <p/>

 To use the layered texture node, connect the outColor and/or outAlpha
 attributes of the various layers to the inputs[x].color and inputs[x].alpha
 attributes of the layered texture node respectively.
*/
class LayeredTexture : public DependNode
{
public:
	/*
	This is the list of input colors and alphas
	that will be combined in this Layered Texture.
	*/
	struct Inputs{
		float3 color;
		float alpha;
		unsigned int blendMode;
		bool isVisible;
		void write(FILE* file) const
		{
			color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f ", alpha);
			fprintf_s(file,"%i ", blendMode);
			fprintf_s(file,"%i", isVisible);
		}
	};
public:
	LayeredTexture(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "layeredTexture"){}
	virtual ~LayeredTexture(){}
	/*
	This is the list of input colors and alphas
	that will be combined in this Layered Texture.
	*/
	void setInputs(size_t cs_i,const Inputs& cs){fprintf_s(mFile, "setAttr \".cs[%i]\" ",cs_i);cs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is the list of input colors and alphas
	that will be combined in this Layered Texture.
	*/
	void setInputs(size_t cs_i,const InputsID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i]\";\n",mName.c_str(),cs_i);}
	/*
	<b>Color</b> affects the final color of the layered
	texture.  Connect the output color attributes of other
	textures to this attribute to combine them into a single
	texture.
	*/
	void setColor(size_t cs_i,const float3& c){fprintf_s(mFile, "setAttr \".cs[%i].c\" -type \"float3\" ",cs_i);c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color</b> affects the final color of the layered
	texture.  Connect the output color attributes of other
	textures to this attribute to combine them into a single
	texture.
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
	/*<b>Alpha</b>*/
	void setAlpha(size_t cs_i,float a){if(a == 1.0) return; fprintf_s(mFile, "setAttr \".cs[%i].a\" %f;\n", cs_i,a);}
	/*<b>Alpha</b>*/
	void setAlpha(size_t cs_i,const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].a\";\n",mName.c_str(),cs_i);}
	/*
	Use the <b>Blend Mode</b> to control how successive layers
	of textures are combined together. There are a number of blend
	modes which can specify exactly how to blend a texture with
	the textures beneath it. <p/>
	Here we present two descriptions of the different blend modes. The
	first description is a non-technical definition of each blend mode
	for the benefit of someone who wants to know what each one does.
	The second is a technical definition of each blend mode for the
	benefit of someone who is attempting to imitate their function in
	hardware. In both cases we will refer to the texture whose blend
	mode is being specified as the "foreground" texture, and the result
	of all of the underlying textures blended together (according to
	their particular blend modes) as the "background" texture. <p/>
	The non-technical definitions are as follows: <p/>
	<ul>
	<li><b>None</b>: The foreground texture covers up the background
	texture entirely.</li>
	<li><b>Over</b>: The foreground texture is applied like a decal to
	the background.
	The shape of the decal is determined by the foreground alpha.</li>
	<li><b>In</b>: The result is the background texture cut in the
	shape of the foreground alpha.</li>
	<li><b>Out</b>: The result is the opposite of In. It is as if the
	shape of the foreground alpha has been cut out of the background.</li>
	<li><b>Add</b>: The result color is the foreground color added to
	the background color as if being projected on the background
	through a slide projector.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	<li><b>Subtract</b>: The result color is the foreground color
	subtracted from the background color.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	<li><b>Multiply</b>: The result color is the foreground color
	multiplied by the background color.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	<li><b>Difference</b>: The result color is the difference between
	the foreground color and the background color.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.
	Difference is not supported by hardware texturing.</li>
	<li><b>Lighten</b>: The result color of each pixel is the
	background color or foreground color, whichever is lighter.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.
	Lighten is not supported by hardware texturing.</li>
	<li><b>Darken</b>: The result color of each pixel is the background
	color or foreground color, whichever is darker.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.
	Darken is not supported by hardware texturing.</li>
	<li><b>Saturate</b>: The result color is the background color with
	saturation increased in proportion to the foreground color scaled
	by foreground alpha. If the foreground color is red, for example,
	the result color will be the background color with more saturated
	reds.</li>
	<li><b>Desaturate</b>: The result color is the background color
	with saturation decreased in proportion to the foreground color
	scaled by foreground alpha. If the foreground color is red, for
	example, the result color will be the background color with
	desaturated reds.</li>
	<li><b>Illuminate</b>: The result color is the background color
	mixed with the foreground color, brighter where the foreground is
	bright and darker where the foreground is dark. It is as if the
	foreground texture represents the light falling on the background.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	</ul><p/>
	The following descriptions describe the blend modes in a
	technical fashion.
	<p/>
	Let "fc" be the foreground color <br/>
	Let "fa" be the foreground alpha <br/>
	Let "bc" be the background color <br/>
	Let "ba" be the background alpha <br/>
	Let "color" be the result color <p/>
	Let "alpha" be the result alpha <p/>
	<p/><ul>
	<li><b>None</b>:<br/>
	color = fc<br/>
	alpha = fa<br/></li>
	<li><b>Over</b>:<br/>
	color = fc * fa + (bc * (1 - fa))<br/>
	alpha = 1 - ((1 - ba) * (1 - fa))<br/></li>
	<li><b>In</b>:<br/>
	color = bc * fa<br/>
	alpha = ba * fa<br/></li>
	<li><b>Out</b>:<br/>
	color = bc * (1 - fa)<br/>
	alpha = ba * (1 - fa)<br/></li>
	<li><b>Add</b>:<br/>
	color = bc + (fc * fa)<br/>
	alpha = ba<br/></li>
	<li><b>Subtract</b>:<br/>
	color = bc - (fc * fa)<br/>
	alpha = ba<br/></li>
	<li><b>Multiply</b>:<br/>
	color = bc * (fc * fa + 1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Difference</b>:<br/>
	color = (abs((fc * fa) - bc)) * fa + bc * (1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Lighten</b>:<br/>
	color = (max((fc * fa), bc)) * fa + bc * (1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Darken</b>:<br/>
	color = (min((fc * fa), bc)) * fa + bc * (1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Saturate</b>:<br/>
	color = bc * (1 + (fc * fa))<br/>
	alpha = ba<br/></li>
	<li><b>Desaturate</b>:<br/>
	color = bc * (1 - (fc * fa))<br/>
	alpha = ba<br/></li>
	<li><b>Illuminate</b>:<br/>
	color = bc * (2 * fc * fa + 1 - fa)<br/>
	alpha = ba<br/></li>
	</ul>
	*/
	void setBlendMode(size_t cs_i,unsigned int bm){if(bm == 1) return; fprintf_s(mFile, "setAttr \".cs[%i].bm\" %i;\n", cs_i,bm);}
	/*
	Use the <b>Blend Mode</b> to control how successive layers
	of textures are combined together. There are a number of blend
	modes which can specify exactly how to blend a texture with
	the textures beneath it. <p/>
	Here we present two descriptions of the different blend modes. The
	first description is a non-technical definition of each blend mode
	for the benefit of someone who wants to know what each one does.
	The second is a technical definition of each blend mode for the
	benefit of someone who is attempting to imitate their function in
	hardware. In both cases we will refer to the texture whose blend
	mode is being specified as the "foreground" texture, and the result
	of all of the underlying textures blended together (according to
	their particular blend modes) as the "background" texture. <p/>
	The non-technical definitions are as follows: <p/>
	<ul>
	<li><b>None</b>: The foreground texture covers up the background
	texture entirely.</li>
	<li><b>Over</b>: The foreground texture is applied like a decal to
	the background.
	The shape of the decal is determined by the foreground alpha.</li>
	<li><b>In</b>: The result is the background texture cut in the
	shape of the foreground alpha.</li>
	<li><b>Out</b>: The result is the opposite of In. It is as if the
	shape of the foreground alpha has been cut out of the background.</li>
	<li><b>Add</b>: The result color is the foreground color added to
	the background color as if being projected on the background
	through a slide projector.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	<li><b>Subtract</b>: The result color is the foreground color
	subtracted from the background color.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	<li><b>Multiply</b>: The result color is the foreground color
	multiplied by the background color.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	<li><b>Difference</b>: The result color is the difference between
	the foreground color and the background color.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.
	Difference is not supported by hardware texturing.</li>
	<li><b>Lighten</b>: The result color of each pixel is the
	background color or foreground color, whichever is lighter.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.
	Lighten is not supported by hardware texturing.</li>
	<li><b>Darken</b>: The result color of each pixel is the background
	color or foreground color, whichever is darker.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.
	Darken is not supported by hardware texturing.</li>
	<li><b>Saturate</b>: The result color is the background color with
	saturation increased in proportion to the foreground color scaled
	by foreground alpha. If the foreground color is red, for example,
	the result color will be the background color with more saturated
	reds.</li>
	<li><b>Desaturate</b>: The result color is the background color
	with saturation decreased in proportion to the foreground color
	scaled by foreground alpha. If the foreground color is red, for
	example, the result color will be the background color with
	desaturated reds.</li>
	<li><b>Illuminate</b>: The result color is the background color
	mixed with the foreground color, brighter where the foreground is
	bright and darker where the foreground is dark. It is as if the
	foreground texture represents the light falling on the background.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	</ul><p/>
	The following descriptions describe the blend modes in a
	technical fashion.
	<p/>
	Let "fc" be the foreground color <br/>
	Let "fa" be the foreground alpha <br/>
	Let "bc" be the background color <br/>
	Let "ba" be the background alpha <br/>
	Let "color" be the result color <p/>
	Let "alpha" be the result alpha <p/>
	<p/><ul>
	<li><b>None</b>:<br/>
	color = fc<br/>
	alpha = fa<br/></li>
	<li><b>Over</b>:<br/>
	color = fc * fa + (bc * (1 - fa))<br/>
	alpha = 1 - ((1 - ba) * (1 - fa))<br/></li>
	<li><b>In</b>:<br/>
	color = bc * fa<br/>
	alpha = ba * fa<br/></li>
	<li><b>Out</b>:<br/>
	color = bc * (1 - fa)<br/>
	alpha = ba * (1 - fa)<br/></li>
	<li><b>Add</b>:<br/>
	color = bc + (fc * fa)<br/>
	alpha = ba<br/></li>
	<li><b>Subtract</b>:<br/>
	color = bc - (fc * fa)<br/>
	alpha = ba<br/></li>
	<li><b>Multiply</b>:<br/>
	color = bc * (fc * fa + 1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Difference</b>:<br/>
	color = (abs((fc * fa) - bc)) * fa + bc * (1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Lighten</b>:<br/>
	color = (max((fc * fa), bc)) * fa + bc * (1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Darken</b>:<br/>
	color = (min((fc * fa), bc)) * fa + bc * (1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Saturate</b>:<br/>
	color = bc * (1 + (fc * fa))<br/>
	alpha = ba<br/></li>
	<li><b>Desaturate</b>:<br/>
	color = bc * (1 - (fc * fa))<br/>
	alpha = ba<br/></li>
	<li><b>Illuminate</b>:<br/>
	color = bc * (2 * fc * fa + 1 - fa)<br/>
	alpha = ba<br/></li>
	</ul>
	*/
	void setBlendMode(size_t cs_i,const UnsignedintID& bm){fprintf_s(mFile,"connectAttr \"");bm.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].bm\";\n",mName.c_str(),cs_i);}
	/*Specifies whether the layer is visible*/
	void setIsVisible(size_t cs_i,bool iv){if(iv == true) return; fprintf_s(mFile, "setAttr \".cs[%i].iv\" %i;\n", cs_i,iv);}
	/*Specifies whether the layer is visible*/
	void setIsVisible(size_t cs_i,const BoolID& iv){fprintf_s(mFile,"connectAttr \"");iv.write(mFile);fprintf_s(mFile,"\" \"%s.cs[%i].iv\";\n",mName.c_str(),cs_i);}
	/*output color*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*outColor red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*outColor green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*outColor blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*output alpha*/
	void setOutAlpha(const FloatID& oa){fprintf_s(mFile,"connectAttr \"");oa.write(mFile);fprintf_s(mFile,"\" \"%s.oa\";\n",mName.c_str());}
	/*
	<b>Hardware Color</b> defines the color to be used in shading
	objects using this layered texture when in hardware shaded but not
	hardware textured mode.
	*/
	void setHardwareColor(const float3& hc){fprintf_s(mFile, "setAttr \".hc\" -type \"float3\" ");hc.write(mFile);fprintf_s(mFile,";\n");}
	/*hardware color R value*/
	void setHardwareColorR(float hcr){if(hcr == 0.5) return; fprintf_s(mFile, "setAttr \".hc.hcr\" %f;\n", hcr);}
	/*hardware color G value*/
	void setHardwareColorG(float hcg){if(hcg == 0.5) return; fprintf_s(mFile, "setAttr \".hc.hcg\" %f;\n", hcg);}
	/*hardware color B value*/
	void setHardwareColorB(float hcb){if(hcb == 0.5) return; fprintf_s(mFile, "setAttr \".hc.hcb\" %f;\n", hcb);}
	/*
	If true, the outAlpha of the layered texture will be the luminance
	of the outColor. Useful for bump mapping or displacement mapping.
	*/
	void setAlphaIsLuminance(bool ail){if(ail == false) return; fprintf_s(mFile, "setAttr \".ail\" %i;\n", ail);}
	/*
	If true, the outAlpha of the layered texture will be the luminance
	of the outColor. Useful for bump mapping or displacement mapping.
	*/
	void setAlphaIsLuminance(const BoolID& ail){fprintf_s(mFile,"connectAttr \"");ail.write(mFile);fprintf_s(mFile,"\" \"%s.ail\";\n",mName.c_str());}
	/*
	<b>Out Transparency</b> is the transparency computed by this
	texture. Each channel of Out Transparency (R, G, B) is
	1 - outAlpha.
	Connect this value to a transparency
	attribute of a shader to texture map that color.
	*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*Out Transparency red value.*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*Out Transparency green value.*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*Out Transparency blue value.*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*
	This is the list of input colors and alphas
	that will be combined in this Layered Texture.
	*/
	const InputsID& getInputs(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i]",mName.c_str(),cs_i);return (const char*)buffer;}
	/*
	<b>Color</b> affects the final color of the layered
	texture.  Connect the output color attributes of other
	textures to this attribute to combine them into a single
	texture.
	*/
	const Float3ID& getColor(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].c",mName.c_str(),cs_i);return (const char*)buffer;}
	/*color red value*/
	const FloatID& getColorR(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].c.cr",mName.c_str(),cs_i);return (const char*)buffer;}
	/*color green value*/
	const FloatID& getColorG(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].c.cg",mName.c_str(),cs_i);return (const char*)buffer;}
	/*color blue value*/
	const FloatID& getColorB(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].c.cb",mName.c_str(),cs_i);return (const char*)buffer;}
	/*<b>Alpha</b>*/
	const FloatID& getAlpha(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].a",mName.c_str(),cs_i);return (const char*)buffer;}
	/*
	Use the <b>Blend Mode</b> to control how successive layers
	of textures are combined together. There are a number of blend
	modes which can specify exactly how to blend a texture with
	the textures beneath it. <p/>
	Here we present two descriptions of the different blend modes. The
	first description is a non-technical definition of each blend mode
	for the benefit of someone who wants to know what each one does.
	The second is a technical definition of each blend mode for the
	benefit of someone who is attempting to imitate their function in
	hardware. In both cases we will refer to the texture whose blend
	mode is being specified as the "foreground" texture, and the result
	of all of the underlying textures blended together (according to
	their particular blend modes) as the "background" texture. <p/>
	The non-technical definitions are as follows: <p/>
	<ul>
	<li><b>None</b>: The foreground texture covers up the background
	texture entirely.</li>
	<li><b>Over</b>: The foreground texture is applied like a decal to
	the background.
	The shape of the decal is determined by the foreground alpha.</li>
	<li><b>In</b>: The result is the background texture cut in the
	shape of the foreground alpha.</li>
	<li><b>Out</b>: The result is the opposite of In. It is as if the
	shape of the foreground alpha has been cut out of the background.</li>
	<li><b>Add</b>: The result color is the foreground color added to
	the background color as if being projected on the background
	through a slide projector.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	<li><b>Subtract</b>: The result color is the foreground color
	subtracted from the background color.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	<li><b>Multiply</b>: The result color is the foreground color
	multiplied by the background color.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	<li><b>Difference</b>: The result color is the difference between
	the foreground color and the background color.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.
	Difference is not supported by hardware texturing.</li>
	<li><b>Lighten</b>: The result color of each pixel is the
	background color or foreground color, whichever is lighter.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.
	Lighten is not supported by hardware texturing.</li>
	<li><b>Darken</b>: The result color of each pixel is the background
	color or foreground color, whichever is darker.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.
	Darken is not supported by hardware texturing.</li>
	<li><b>Saturate</b>: The result color is the background color with
	saturation increased in proportion to the foreground color scaled
	by foreground alpha. If the foreground color is red, for example,
	the result color will be the background color with more saturated
	reds.</li>
	<li><b>Desaturate</b>: The result color is the background color
	with saturation decreased in proportion to the foreground color
	scaled by foreground alpha. If the foreground color is red, for
	example, the result color will be the background color with
	desaturated reds.</li>
	<li><b>Illuminate</b>: The result color is the background color
	mixed with the foreground color, brighter where the foreground is
	bright and darker where the foreground is dark. It is as if the
	foreground texture represents the light falling on the background.
	The result color is then applied over the background color using the
	foreground alpha to define the opacity of the result.</li>
	</ul><p/>
	The following descriptions describe the blend modes in a
	technical fashion.
	<p/>
	Let "fc" be the foreground color <br/>
	Let "fa" be the foreground alpha <br/>
	Let "bc" be the background color <br/>
	Let "ba" be the background alpha <br/>
	Let "color" be the result color <p/>
	Let "alpha" be the result alpha <p/>
	<p/><ul>
	<li><b>None</b>:<br/>
	color = fc<br/>
	alpha = fa<br/></li>
	<li><b>Over</b>:<br/>
	color = fc * fa + (bc * (1 - fa))<br/>
	alpha = 1 - ((1 - ba) * (1 - fa))<br/></li>
	<li><b>In</b>:<br/>
	color = bc * fa<br/>
	alpha = ba * fa<br/></li>
	<li><b>Out</b>:<br/>
	color = bc * (1 - fa)<br/>
	alpha = ba * (1 - fa)<br/></li>
	<li><b>Add</b>:<br/>
	color = bc + (fc * fa)<br/>
	alpha = ba<br/></li>
	<li><b>Subtract</b>:<br/>
	color = bc - (fc * fa)<br/>
	alpha = ba<br/></li>
	<li><b>Multiply</b>:<br/>
	color = bc * (fc * fa + 1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Difference</b>:<br/>
	color = (abs((fc * fa) - bc)) * fa + bc * (1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Lighten</b>:<br/>
	color = (max((fc * fa), bc)) * fa + bc * (1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Darken</b>:<br/>
	color = (min((fc * fa), bc)) * fa + bc * (1 - fa)<br/>
	alpha = ba<br/></li>
	<li><b>Saturate</b>:<br/>
	color = bc * (1 + (fc * fa))<br/>
	alpha = ba<br/></li>
	<li><b>Desaturate</b>:<br/>
	color = bc * (1 - (fc * fa))<br/>
	alpha = ba<br/></li>
	<li><b>Illuminate</b>:<br/>
	color = bc * (2 * fc * fa + 1 - fa)<br/>
	alpha = ba<br/></li>
	</ul>
	*/
	const UnsignedintID& getBlendMode(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].bm",mName.c_str(),cs_i);return (const char*)buffer;}
	/*Specifies whether the layer is visible*/
	const BoolID& getIsVisible(size_t cs_i){char buffer[4096];sprintf_s (buffer, "%s.cs[%i].iv",mName.c_str(),cs_i);return (const char*)buffer;}
	/*output color*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*outColor red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*outColor green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*outColor blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*output alpha*/
	FloatID getOutAlpha(){char buffer[4096];sprintf_s (buffer, "%s.oa",mName.c_str());return (const char*)buffer;}
	/*
	If true, the outAlpha of the layered texture will be the luminance
	of the outColor. Useful for bump mapping or displacement mapping.
	*/
	BoolID getAlphaIsLuminance(){char buffer[4096];sprintf_s (buffer, "%s.ail",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Transparency</b> is the transparency computed by this
	texture. Each channel of Out Transparency (R, G, B) is
	1 - outAlpha.
	Connect this value to a transparency
	attribute of a shader to texture map that color.
	*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*Out Transparency red value.*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*Out Transparency green value.*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*Out Transparency blue value.*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
protected:
	LayeredTexture(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LAYEREDTEXTURE_H__
