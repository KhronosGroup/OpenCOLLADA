/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OCEANSHADER_H__
#define __MayaDM_OCEANSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Use a <b>OceanShader</b> for extra control over the way color changes
  with light and view angle. One can simulate a variety of exotic materials
  as well as tweeking more standard shading in subtle ways.
        <p/>
        In the table below, important attributes have their names indicated
  in <b>bold</b> in the description column.
*/
class OceanShader : public DependNode
{
public:
	/*
	<b>Environment</b> defines a simple sky to ground environmental
	reflection using a ramp. The left of the ramp is the top of the
	sky and the right is the bottom.
	*/
	struct Environment{
		float environment_Position;
		float3 environment_Color;
		unsigned int environment_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", environment_Position);
			environment_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", environment_Interp);
		}
	};
	/*
	<b>WaveHeight</b> controls the size of waves relative
	to their wave length. If the value is 1.0, then the waves are half as
	tall as they are long. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	If the graph is a horizontal line, then all waves will
	exactly the same height proportional to their length.
	*/
	struct WaveHeight{
		float waveHeight_Position;
		float waveHeight_FloatValue;
		unsigned int waveHeight_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", waveHeight_Position);
			fprintf_s(file,"%f ", waveHeight_FloatValue);
			fprintf_s(file,"%i", waveHeight_Interp);
		}
	};
	/*
	<b>WaveTurbulence</b> controls the amount of turbulence at different
	wave frequencies. For values of 1.0 the wave motion will be
	completely turbulent at the defined frequency. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	For each wave frequency, the turbulence wave component
	consists of multiple sine waves at that frequency.
	This is the most computationaly expensive attribute. Making it zero
	will speed up renders significantly, although it is important for
	simulations of stormy or windy water. The peaking parameter only
	affects the turbulent wave layer, so there will be no affect from
	the peaking parameter wherever this value is zero.
	*/
	struct WaveTurbulence{
		float waveTurbulence_Position;
		float waveTurbulence_FloatValue;
		unsigned int waveTurbulence_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", waveTurbulence_Position);
			fprintf_s(file,"%f ", waveTurbulence_FloatValue);
			fprintf_s(file,"%i", waveTurbulence_Interp);
		}
	};
	/*
	<b>WavePeaking</b> controls the amount of crest formation for waves
	across the range of wave frequencies.
	This simulates a side to side sloshing of waves, as opposed to
	up-down motion. When this parameter is non-zero many more
	evaluations of the noise function are performed, and thus the
	computation speed will be affected. Also the waveTurbulence
	function must be non-zero for this parameter to have an effects,
	as it is only applied to the turbulent waves.
	*/
	struct WavePeaking{
		float wavePeaking_Position;
		float wavePeaking_FloatValue;
		unsigned int wavePeaking_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", wavePeaking_Position);
			fprintf_s(file,"%f ", wavePeaking_FloatValue);
			fprintf_s(file,"%i", wavePeaking_Interp);
		}
	};
public:
	OceanShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "oceanShader"){}
	virtual ~OceanShader(){}
	/*ray depth limit*/
	void setRefractionLimit(short rdl){if(rdl == 6) return; fprintf_s(mFile, "setAttr \".rdl\" %i;\n", rdl);}
	/*ray depth limit*/
	void setRefractionLimit(const ShortID& rdl){fprintf_s(mFile,"connectAttr \"");rdl.write(mFile);fprintf_s(mFile,"\" \"%s.rdl\";\n",mName.c_str());}
	/*
	<b>Refractive Index</b> determines how much a ray of light will bend
	when it passes through an object.  This attribute only works
	if your material is partially or completely transparent (see the
	<i>Transparency</i> attribute), refractions are turned on
	(see the <i>Refractions</i> attribute) and you
	are rendering using Ray Tracing.  (See <i>Render Settings</i>)
	<p/>
	If the Refractive Index is set to 1.0, then light does not bend
	when it passes through the object.  Here are some other useful values
	for Refractive Index:
	<p/><ul>
	Air: 1.0<br/>
	Water: 1.33<br/>
	Gasoline: 1.45<br/>
	Crystal: 2.00<br/>
	Glass: 1.5<br/>
	Ice: 1.309<br/>
	Quartz: 1.6<br/>
	Ruby: 1.77<br/>
	Sapphire: 1.77<br/>
	Salt: 1.54<br/>
	Alcohol: 1.329<br/>
	Emerald: 1.57<br/>
	Polystyrene: 1.55<br/>
	</ul>
	<p/><i>Note:</i>If you make an object transparent, objects that
	are seen through it will be refracted only if their Visible
	In Refractions attribute is turned on.
	*/
	void setRefractiveIndex(float rfi){if(rfi == 1.3) return; fprintf_s(mFile, "setAttr \".rfi\" %f;\n", rfi);}
	/*
	<b>Refractive Index</b> determines how much a ray of light will bend
	when it passes through an object.  This attribute only works
	if your material is partially or completely transparent (see the
	<i>Transparency</i> attribute), refractions are turned on
	(see the <i>Refractions</i> attribute) and you
	are rendering using Ray Tracing.  (See <i>Render Settings</i>)
	<p/>
	If the Refractive Index is set to 1.0, then light does not bend
	when it passes through the object.  Here are some other useful values
	for Refractive Index:
	<p/><ul>
	Air: 1.0<br/>
	Water: 1.33<br/>
	Gasoline: 1.45<br/>
	Crystal: 2.00<br/>
	Glass: 1.5<br/>
	Ice: 1.309<br/>
	Quartz: 1.6<br/>
	Ruby: 1.77<br/>
	Sapphire: 1.77<br/>
	Salt: 1.54<br/>
	Alcohol: 1.329<br/>
	Emerald: 1.57<br/>
	Polystyrene: 1.55<br/>
	</ul>
	<p/><i>Note:</i>If you make an object transparent, objects that
	are seen through it will be refracted only if their Visible
	In Refractions attribute is turned on.
	*/
	void setRefractiveIndex(const FloatID& rfi){fprintf_s(mFile,"connectAttr \"");rfi.write(mFile);fprintf_s(mFile,"\" \"%s.rfi\";\n",mName.c_str());}
	/*
	Turn on <b>Refractions</b> to make your material refract light
	when you are rendering with Ray Tracing.  You will not see
	a difference unless Refractive Index is set to a value other
	than 1.0. (See the <i>Refractive Index</i>
	attribute above for more details.)  Refractions are turned off by default.
	*/
	void setRefractions(bool rfc){if(rfc == false) return; fprintf_s(mFile, "setAttr \".rfc\" %i;\n", rfc);}
	/*
	Turn on <b>Refractions</b> to make your material refract light
	when you are rendering with Ray Tracing.  You will not see
	a difference unless Refractive Index is set to a value other
	than 1.0. (See the <i>Refractive Index</i>
	attribute above for more details.)  Refractions are turned off by default.
	*/
	void setRefractions(const BoolID& rfc){fprintf_s(mFile,"connectAttr \"");rfc.write(mFile);fprintf_s(mFile,"\" \"%s.rfc\";\n",mName.c_str());}
	/*
	<b>Diffuse</b> controls how much of the light in the scene
	is scattered from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.
	*/
	void setDiffuse(float dc){if(dc == 0.3) return; fprintf_s(mFile, "setAttr \".dc\" %f;\n", dc);}
	/*
	<b>Diffuse</b> controls how much of the light in the scene
	is scattered from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.
	*/
	void setDiffuse(const FloatID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*<b>Color</b> is the basic color of the surface.*/
	void setWaterColor(const float3& wc){fprintf_s(mFile, "setAttr \".wc\" -type \"float3\" ");wc.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Color</b> is the basic color of the surface.*/
	void setWaterColor(const Float3ID& wc){fprintf_s(mFile,"connectAttr \"");wc.write(mFile);fprintf_s(mFile,"\" \"%s.wc\";\n",mName.c_str());}
	/*color red value*/
	void setWaterColorR(float wcr){if(wcr == 0.0) return; fprintf_s(mFile, "setAttr \".wc.wcr\" %f;\n", wcr);}
	/*color red value*/
	void setWaterColorR(const FloatID& wcr){fprintf_s(mFile,"connectAttr \"");wcr.write(mFile);fprintf_s(mFile,"\" \"%s.wc.wcr\";\n",mName.c_str());}
	/*color green value*/
	void setWaterColorG(float wcg){if(wcg == 0.36) return; fprintf_s(mFile, "setAttr \".wc.wcg\" %f;\n", wcg);}
	/*color green value*/
	void setWaterColorG(const FloatID& wcg){fprintf_s(mFile,"connectAttr \"");wcg.write(mFile);fprintf_s(mFile,"\" \"%s.wc.wcg\";\n",mName.c_str());}
	/*color blue value*/
	void setWaterColorB(float wcb){if(wcb == 0.4) return; fprintf_s(mFile, "setAttr \".wc.wcb\" %f;\n", wcb);}
	/*color blue value*/
	void setWaterColorB(const FloatID& wcb){fprintf_s(mFile,"connectAttr \"");wcb.write(mFile);fprintf_s(mFile,"\" \"%s.wc.wcb\";\n",mName.c_str());}
	/*
	<b>Transparency</b> controls how transparent or opaque the material is.
	Black means completely opaque (the default), and white means completely
	transparent.  You can set it to any level in between.  You can
	also control transparency on a per-channel basis;  for example, if
	you set this to red, then only the red channel will be transparent.
	<p/><i>Note:</i> If this material has specular highlights (<i>i.e.</i>, if
	this is a Phong or Blinn shader), the transparency
	setting will <i>not</i> affect the highlights.  So if you are
	trying to make an object disappear by animating the transparency
	attribute, you may also have to animate the specular highlight
	attributes.
	*/
	void setTransparency(const float3& it){fprintf_s(mFile, "setAttr \".it\" -type \"float3\" ");it.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Transparency</b> controls how transparent or opaque the material is.
	Black means completely opaque (the default), and white means completely
	transparent.  You can set it to any level in between.  You can
	also control transparency on a per-channel basis;  for example, if
	you set this to red, then only the red channel will be transparent.
	<p/><i>Note:</i> If this material has specular highlights (<i>i.e.</i>, if
	this is a Phong or Blinn shader), the transparency
	setting will <i>not</i> affect the highlights.  So if you are
	trying to make an object disappear by animating the transparency
	attribute, you may also have to animate the specular highlight
	attributes.
	*/
	void setTransparency(const Float3ID& it){fprintf_s(mFile,"connectAttr \"");it.write(mFile);fprintf_s(mFile,"\" \"%s.it\";\n",mName.c_str());}
	/*transparency red value*/
	void setTransparencyR(float itr){if(itr == 0.0) return; fprintf_s(mFile, "setAttr \".it.itr\" %f;\n", itr);}
	/*transparency red value*/
	void setTransparencyR(const FloatID& itr){fprintf_s(mFile,"connectAttr \"");itr.write(mFile);fprintf_s(mFile,"\" \"%s.it.itr\";\n",mName.c_str());}
	/*transparency green value*/
	void setTransparencyG(float itg){if(itg == 0.0) return; fprintf_s(mFile, "setAttr \".it.itg\" %f;\n", itg);}
	/*transparency green value*/
	void setTransparencyG(const FloatID& itg){fprintf_s(mFile,"connectAttr \"");itg.write(mFile);fprintf_s(mFile,"\" \"%s.it.itg\";\n",mName.c_str());}
	/*transparency blue value*/
	void setTransparencyB(float itb){if(itb == 0.0) return; fprintf_s(mFile, "setAttr \".it.itb\" %f;\n", itb);}
	/*transparency blue value*/
	void setTransparencyB(const FloatID& itb){fprintf_s(mFile,"connectAttr \"");itb.write(mFile);fprintf_s(mFile,"\" \"%s.it.itb\";\n",mName.c_str());}
	/*
	<b>Ambient Color</b> is black by default, which means it does not affect
	the material's over-all color.  As the ambient color becomes brighter,
	it affects the material's color by lightening it and blending
	the two colors.
	<p/>
	If there are ambient lights in the scene, then the color and
	brightness of those lights is used to control how much the
	ambient color contributes to the final color of the material.
	*/
	void setAmbientColor(const float3& ambc){fprintf_s(mFile, "setAttr \".ambc\" -type \"float3\" ");ambc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Ambient Color</b> is black by default, which means it does not affect
	the material's over-all color.  As the ambient color becomes brighter,
	it affects the material's color by lightening it and blending
	the two colors.
	<p/>
	If there are ambient lights in the scene, then the color and
	brightness of those lights is used to control how much the
	ambient color contributes to the final color of the material.
	*/
	void setAmbientColor(const Float3ID& ambc){fprintf_s(mFile,"connectAttr \"");ambc.write(mFile);fprintf_s(mFile,"\" \"%s.ambc\";\n",mName.c_str());}
	/*ambient color red value*/
	void setAmbientColorR(float acr){if(acr == 0.0) return; fprintf_s(mFile, "setAttr \".ambc.acr\" %f;\n", acr);}
	/*ambient color red value*/
	void setAmbientColorR(const FloatID& acr){fprintf_s(mFile,"connectAttr \"");acr.write(mFile);fprintf_s(mFile,"\" \"%s.ambc.acr\";\n",mName.c_str());}
	/*ambient color green value*/
	void setAmbientColorG(float acg){if(acg == 0.0) return; fprintf_s(mFile, "setAttr \".ambc.acg\" %f;\n", acg);}
	/*ambient color green value*/
	void setAmbientColorG(const FloatID& acg){fprintf_s(mFile,"connectAttr \"");acg.write(mFile);fprintf_s(mFile,"\" \"%s.ambc.acg\";\n",mName.c_str());}
	/*ambient color blue value*/
	void setAmbientColorB(float acb){if(acb == 0.0) return; fprintf_s(mFile, "setAttr \".ambc.acb\" %f;\n", acb);}
	/*ambient color blue value*/
	void setAmbientColorB(const FloatID& acb){fprintf_s(mFile,"connectAttr \"");acb.write(mFile);fprintf_s(mFile,"\" \"%s.ambc.acb\";\n",mName.c_str());}
	/*
	<b>Incandescence</b> makes a material appear opalescent, as if it were
	emmitting light itself, such as lava or a phosphorescent moss.  A
	slight touch of incandescence on vegetable matter, for example,
	can make the vegetation look alive.<p/>
	By default, the color is black, which has no effect on the surface.
	<p/><i>Note:</i> although incandescence makes a surface appear to
	glow, it does not actually act as a source of light in the scene.
	<p/>See also Glow Intensity.
	*/
	void setIncandescence(const float3& ic){fprintf_s(mFile, "setAttr \".ic\" -type \"float3\" ");ic.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Incandescence</b> makes a material appear opalescent, as if it were
	emmitting light itself, such as lava or a phosphorescent moss.  A
	slight touch of incandescence on vegetable matter, for example,
	can make the vegetation look alive.<p/>
	By default, the color is black, which has no effect on the surface.
	<p/><i>Note:</i> although incandescence makes a surface appear to
	glow, it does not actually act as a source of light in the scene.
	<p/>See also Glow Intensity.
	*/
	void setIncandescence(const Float3ID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*incandescence red value*/
	void setIncandescenceR(float ir){if(ir == 0.0) return; fprintf_s(mFile, "setAttr \".ic.ir\" %f;\n", ir);}
	/*incandescence red value*/
	void setIncandescenceR(const FloatID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.ic.ir\";\n",mName.c_str());}
	/*incandescence green value*/
	void setIncandescenceG(float ig){if(ig == 0.0) return; fprintf_s(mFile, "setAttr \".ic.ig\" %f;\n", ig);}
	/*incandescence green value*/
	void setIncandescenceG(const FloatID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ic.ig\";\n",mName.c_str());}
	/*incandescence blue value*/
	void setIncandescenceB(float ib){if(ib == 0.0) return; fprintf_s(mFile, "setAttr \".ic.ib\" %f;\n", ib);}
	/*incandescence blue value*/
	void setIncandescenceB(const FloatID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ic.ib\";\n",mName.c_str());}
	/*
	<b>Translucence</b> simulates the way light diffusely penetrates
	through translucent objects.  This means that when light shines
	on one side of the object, the other side is partially illuminated.
	This can be used for effects such as clouds, fur, hair, marble,
	jade, wax, paper, leaves, etc.
	<p/>If this is set to 0 (the default) then no light shows through
	the object.  If this is set to 1, all the light shows through.
	*/
	void setTranslucence(float tc){if(tc == 0.3) return; fprintf_s(mFile, "setAttr \".tc\" %f;\n", tc);}
	/*
	<b>Translucence</b> simulates the way light diffusely penetrates
	through translucent objects.  This means that when light shines
	on one side of the object, the other side is partially illuminated.
	This can be used for effects such as clouds, fur, hair, marble,
	jade, wax, paper, leaves, etc.
	<p/>If this is set to 0 (the default) then no light shows through
	the object.  If this is set to 1, all the light shows through.
	*/
	void setTranslucence(const FloatID& tc){fprintf_s(mFile,"connectAttr \"");tc.write(mFile);fprintf_s(mFile,"\" \"%s.tc\";\n",mName.c_str());}
	/*
	<b>TranslucenceFocus</b> simulates the way light scatters more
	in a forward direction through translucent objects.
	Thin objects like a leaf, or low density objects like a cloud
	tend to scatter more in a forward direction. When the focus is 0.0
	translucent light is scattered in all directions. As the focus
	value is raised the translucent light is scatter more in the
	light direction. This makes the backlit side of a leaf glow more
	than the frontlit side. At high focus values one will see a halo
	or glow around the lightsource when seen through a translucent
	object.
	*/
	void setTranslucenceFocus(float tcf){if(tcf == 0.0) return; fprintf_s(mFile, "setAttr \".tcf\" %f;\n", tcf);}
	/*
	<b>TranslucenceFocus</b> simulates the way light scatters more
	in a forward direction through translucent objects.
	Thin objects like a leaf, or low density objects like a cloud
	tend to scatter more in a forward direction. When the focus is 0.0
	translucent light is scattered in all directions. As the focus
	value is raised the translucent light is scatter more in the
	light direction. This makes the backlit side of a leaf glow more
	than the frontlit side. At high focus values one will see a halo
	or glow around the lightsource when seen through a translucent
	object.
	*/
	void setTranslucenceFocus(const FloatID& tcf){fprintf_s(mFile,"connectAttr \"");tcf.write(mFile);fprintf_s(mFile,"\" \"%s.tcf\";\n",mName.c_str());}
	/*
	<b>Translucence Depth</b><p/>
	The depth of penetration into an object at which translucence decays
	to nothing.  When the parameter is 0, translucence does not decay
	with respect to the distance light travels through the object.
	*/
	void setTranslucenceDepth(float trsd){if(trsd == 10.0) return; fprintf_s(mFile, "setAttr \".trsd\" %f;\n", trsd);}
	/*
	<b>Translucence Depth</b><p/>
	The depth of penetration into an object at which translucence decays
	to nothing.  When the parameter is 0, translucence does not decay
	with respect to the distance light travels through the object.
	*/
	void setTranslucenceDepth(const FloatID& trsd){fprintf_s(mFile,"connectAttr \"");trsd.write(mFile);fprintf_s(mFile,"\" \"%s.trsd\";\n",mName.c_str());}
	/*
	<b>Opacity Depth</b> (Studio special effect)<p/>
	Causes the transparency of an object to diminish with its thickness.
	An object is opaque if its thickness is greater than its Opacity Depth.
	When the Opacity Depth value is 0, it has no effect (as opposed to
	making an object entirely opaque).  The shader must have some
	Transparency to show the effect of Opacity Depth. When Opacity Depth
	is non-zero, transparency controls specularity, reflectivity, and
	incandescence, which are normally independent of transparency.
	This makes it easier to create soft, fuzzy objects. Also, if you
	use a transparency map to create holes in a surface that has specular
	highlights, set Opacity Depth to a high value instead of creating a
	matching specular map. Transparent objects cast shadows in the
	raycaster even if the Opacity Depth value is non-zero.
	<p/>Tip: Use Opacity Depth to simulate hair, fur, and clouds.
	*/
	void setOpacityDepth(float opad){if(opad == 0.0) return; fprintf_s(mFile, "setAttr \".opad\" %f;\n", opad);}
	/*
	<b>Opacity Depth</b> (Studio special effect)<p/>
	Causes the transparency of an object to diminish with its thickness.
	An object is opaque if its thickness is greater than its Opacity Depth.
	When the Opacity Depth value is 0, it has no effect (as opposed to
	making an object entirely opaque).  The shader must have some
	Transparency to show the effect of Opacity Depth. When Opacity Depth
	is non-zero, transparency controls specularity, reflectivity, and
	incandescence, which are normally independent of transparency.
	This makes it easier to create soft, fuzzy objects. Also, if you
	use a transparency map to create holes in a surface that has specular
	highlights, set Opacity Depth to a high value instead of creating a
	matching specular map. Transparent objects cast shadows in the
	raycaster even if the Opacity Depth value is non-zero.
	<p/>Tip: Use Opacity Depth to simulate hair, fur, and clouds.
	*/
	void setOpacityDepth(const FloatID& opad){fprintf_s(mFile,"connectAttr \"");opad.write(mFile);fprintf_s(mFile,"\" \"%s.opad\";\n",mName.c_str());}
	/*
	<b>Glow Intensity</b> is 0 by default, meaning that no glow is added to the
	material.  As this is turned up, the material seems to 'glow'
	with a faint halo of light around it.
	<p/>Note that this is different from the Incandescence attribute
	in a few important ways.  First, glow is added as a post-process
	at the end of rendering.  (Incandescence just makes the surface
	appear brighter.)  Second, glow adds a halo, which incandescence
	does not.
	*/
	void setGlowIntensity(float gi){if(gi == 0.0) return; fprintf_s(mFile, "setAttr \".gi\" %f;\n", gi);}
	/*
	<b>Glow Intensity</b> is 0 by default, meaning that no glow is added to the
	material.  As this is turned up, the material seems to 'glow'
	with a faint halo of light around it.
	<p/>Note that this is different from the Incandescence attribute
	in a few important ways.  First, glow is added as a post-process
	at the end of rendering.  (Incandescence just makes the surface
	appear brighter.)  Second, glow adds a halo, which incandescence
	does not.
	*/
	void setGlowIntensity(const FloatID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.gi\";\n",mName.c_str());}
	/*
	<b>Specular Glow</b> works the same way as glow intensity, only
	it makes specular highlights glow. It is useful for things like
	twinkling highlights on water.
	*/
	void setSpecularGlow(float spg){if(spg == 0.0) return; fprintf_s(mFile, "setAttr \".spg\" %f;\n", spg);}
	/*
	<b>Specular Glow</b> works the same way as glow intensity, only
	it makes specular highlights glow. It is useful for things like
	twinkling highlights on water.
	*/
	void setSpecularGlow(const FloatID& spg){fprintf_s(mFile,"connectAttr \"");spg.write(mFile);fprintf_s(mFile,"\" \"%s.spg\";\n",mName.c_str());}
	/*
	<b>Shadow Attenuation (Fake Refraction Caustics)</b>>p>
	(aka Studio special effect "Transparency Shade" - raytracing only)<p/>
	Causes shadows of transparent objects to be brighter in the
	center, simulating the focusing of light.  0 gives constant
	intensity shadows, 1 gives shadows focused in the center.
	*/
	void setShadowAttenuation(float fakc){if(fakc == 0.5) return; fprintf_s(mFile, "setAttr \".fakc\" %f;\n", fakc);}
	/*
	<b>Shadow Attenuation (Fake Refraction Caustics)</b>>p>
	(aka Studio special effect "Transparency Shade" - raytracing only)<p/>
	Causes shadows of transparent objects to be brighter in the
	center, simulating the focusing of light.  0 gives constant
	intensity shadows, 1 gives shadows focused in the center.
	*/
	void setShadowAttenuation(const FloatID& fakc){fprintf_s(mFile,"connectAttr \"");fakc.write(mFile);fprintf_s(mFile,"\" \"%s.fakc\";\n",mName.c_str());}
	/*
	<b>Eccentricity</b> controls how big your specular highlights
	(also called 'hot spots') will be.
	*/
	void setEccentricity(float ec){if(ec == 0.03) return; fprintf_s(mFile, "setAttr \".ec\" %f;\n", ec);}
	/*
	<b>Eccentricity</b> controls how big your specular highlights
	(also called 'hot spots') will be.
	*/
	void setEccentricity(const FloatID& ec){fprintf_s(mFile,"connectAttr \"");ec.write(mFile);fprintf_s(mFile,"\" \"%s.ec\";\n",mName.c_str());}
	/*
	<b>Specularity</b> controls how bright your specular highlights
	will be.  It is a simple multiplier of the specular color.
	*/
	void setSpecularity(float spl){if(spl == 0.7) return; fprintf_s(mFile, "setAttr \".spl\" %f;\n", spl);}
	/*
	<b>Specularity</b> controls how bright your specular highlights
	will be.  It is a simple multiplier of the specular color.
	*/
	void setSpecularity(const FloatID& spl){fprintf_s(mFile,"connectAttr \"");spl.write(mFile);fprintf_s(mFile,"\" \"%s.spl\";\n",mName.c_str());}
	/*reflected ray depth limit*/
	void setReflectionLimit(short fll){if(fll == 1) return; fprintf_s(mFile, "setAttr \".fll\" %i;\n", fll);}
	/*reflected ray depth limit*/
	void setReflectionLimit(const ShortID& fll){fprintf_s(mFile,"connectAttr \"");fll.write(mFile);fprintf_s(mFile,"\" \"%s.fll\";\n",mName.c_str());}
	/*
	<b>Specular Color</b> is the color of the specular reflections
	(also called 'hot spots') on the material.  The final color
	of a specular reflection is a combination of the Specular Color
	and the color of the light.
	<p/>By making the Specular Color brighter or dimmer, you can control
	the brightness of the specular reflections on an object.
	<p/>
	<i>Tip:</i> To make a material look more plastic, use white for the specular
	color.  To make a material look more metallic, make the specular
	color similar to the surface color.
	*/
	void setSpecularColor(const float3& sc){fprintf_s(mFile, "setAttr \".sc\" -type \"float3\" ");sc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Specular Color</b> is the color of the specular reflections
	(also called 'hot spots') on the material.  The final color
	of a specular reflection is a combination of the Specular Color
	and the color of the light.
	<p/>By making the Specular Color brighter or dimmer, you can control
	the brightness of the specular reflections on an object.
	<p/>
	<i>Tip:</i> To make a material look more plastic, use white for the specular
	color.  To make a material look more metallic, make the specular
	color similar to the surface color.
	*/
	void setSpecularColor(const Float3ID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*specular color red value*/
	void setSpecularColorR(float sr){if(sr == 1.0) return; fprintf_s(mFile, "setAttr \".sc.sr\" %f;\n", sr);}
	/*specular color red value*/
	void setSpecularColorR(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sc.sr\";\n",mName.c_str());}
	/*specular color green value*/
	void setSpecularColorG(float sg){if(sg == 1.0) return; fprintf_s(mFile, "setAttr \".sc.sg\" %f;\n", sg);}
	/*specular color green value*/
	void setSpecularColorG(const FloatID& sg){fprintf_s(mFile,"connectAttr \"");sg.write(mFile);fprintf_s(mFile,"\" \"%s.sc.sg\";\n",mName.c_str());}
	/*specular color blue value*/
	void setSpecularColorB(float sb){if(sb == 1.0) return; fprintf_s(mFile, "setAttr \".sc.sb\" %f;\n", sb);}
	/*specular color blue value*/
	void setSpecularColorB(const FloatID& sb){fprintf_s(mFile,"connectAttr \"");sb.write(mFile);fprintf_s(mFile,"\" \"%s.sc.sb\";\n",mName.c_str());}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
	<p/>
	The default ocean reflectivity  currently matches that of water.
	It is nearly totally reflective from glancing angles but not so reflective
	from others( the Fresnel effect ). This effect is a feature of the
	refractive index of a material, which for water is 1.33. Increasing
	the refractive index will make the water more reflective to direct rays,
	but also more like chrome than water.
	<p/>
	This attribute is only meaningful if there is a reflection map, or
	if you are doing Ray Tracing.
	<p/>
	Here are some useful values for Reflectivity:
	<ul>
	Car Paint: 0.4<br/>
	Glass: 0.7<br/>
	Mirror: 1.0<br/>
	Chrome: 1.0
	</ul>
	<p/>
	<i>Note:</i> If you are doing Ray Tracing, and you want
	other objects in the scene to be seen in reflections, then
	you must turn on the Visible In Reflections attribute of
	those objects.
	*/
	void setReflectivity(float rfl){if(rfl == 0.7) return; fprintf_s(mFile, "setAttr \".rfl\" %f;\n", rfl);}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
	<p/>
	The default ocean reflectivity  currently matches that of water.
	It is nearly totally reflective from glancing angles but not so reflective
	from others( the Fresnel effect ). This effect is a feature of the
	refractive index of a material, which for water is 1.33. Increasing
	the refractive index will make the water more reflective to direct rays,
	but also more like chrome than water.
	<p/>
	This attribute is only meaningful if there is a reflection map, or
	if you are doing Ray Tracing.
	<p/>
	Here are some useful values for Reflectivity:
	<ul>
	Car Paint: 0.4<br/>
	Glass: 0.7<br/>
	Mirror: 1.0<br/>
	Chrome: 1.0
	</ul>
	<p/>
	<i>Note:</i> If you are doing Ray Tracing, and you want
	other objects in the scene to be seen in reflections, then
	you must turn on the Visible In Reflections attribute of
	those objects.
	*/
	void setReflectivity(const FloatID& rfl){fprintf_s(mFile,"connectAttr \"");rfl.write(mFile);fprintf_s(mFile,"\" \"%s.rfl\";\n",mName.c_str());}
	/*
	<b>Environment</b> defines a simple sky to ground environmental
	reflection using a ramp. The left of the ramp is the top of the
	sky and the right is the bottom.
	*/
	void setEnvironment(size_t env_i,const Environment& env){fprintf_s(mFile, "setAttr \".env[%i]\" ",env_i);env.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Environment</b> defines a simple sky to ground environmental
	reflection using a ramp. The left of the ramp is the top of the
	sky and the right is the bottom.
	*/
	void setEnvironment(size_t env_i,const EnvironmentID& env){fprintf_s(mFile,"connectAttr \"");env.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i]\";\n",mName.c_str(),env_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setEnvironment_Position(size_t env_i,float envp){if(envp == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envp\" %f;\n", env_i,envp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setEnvironment_Position(size_t env_i,const FloatID& envp){fprintf_s(mFile,"connectAttr \"");envp.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envp\";\n",mName.c_str(),env_i);}
	/*Ramp color at the sibling position*/
	void setEnvironment_Color(size_t env_i,const float3& envc){fprintf_s(mFile, "setAttr \".env[%i].envc\" -type \"float3\" ",env_i);envc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setEnvironment_Color(size_t env_i,const Float3ID& envc){fprintf_s(mFile,"connectAttr \"");envc.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc\";\n",mName.c_str(),env_i);}
	/*Ramp red channel value at the sibling position*/
	void setEnvironment_ColorR(size_t env_i,float envcr){if(envcr == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envc.envcr\" %f;\n", env_i,envcr);}
	/*Ramp red channel value at the sibling position*/
	void setEnvironment_ColorR(size_t env_i,const FloatID& envcr){fprintf_s(mFile,"connectAttr \"");envcr.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc.envcr\";\n",mName.c_str(),env_i);}
	/*Ramp green channel value at the sibling position*/
	void setEnvironment_ColorG(size_t env_i,float envcg){if(envcg == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envc.envcg\" %f;\n", env_i,envcg);}
	/*Ramp green channel value at the sibling position*/
	void setEnvironment_ColorG(size_t env_i,const FloatID& envcg){fprintf_s(mFile,"connectAttr \"");envcg.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc.envcg\";\n",mName.c_str(),env_i);}
	/*Ramp blue channel value at the sibling position*/
	void setEnvironment_ColorB(size_t env_i,float envcb){if(envcb == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envc.envcb\" %f;\n", env_i,envcb);}
	/*Ramp blue channel value at the sibling position*/
	void setEnvironment_ColorB(size_t env_i,const FloatID& envcb){fprintf_s(mFile,"connectAttr \"");envcb.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc.envcb\";\n",mName.c_str(),env_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setEnvironment_Interp(size_t env_i,unsigned int envi){if(envi == 0) return; fprintf_s(mFile, "setAttr \".env[%i].envi\" %i;\n", env_i,envi);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setEnvironment_Interp(size_t env_i,const UnsignedintID& envi){fprintf_s(mFile,"connectAttr \"");envi.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envi\";\n",mName.c_str(),env_i);}
	/*
	<b>Reflected Color</b> affects the color of light reflected from
	the material.
	<p/>You can map an image or texture  or environment map to this
	attribute in order to make 'fake reflections', which are less
	expensive than ray-tracing.  This is called Reflection Mapping.
	<p/>Reflection Mapping and raytracing may be used together, in
	which case the reflection map is used as 'background', and
	raytraced reflections appear in the 'foreground'.
	*/
	void setReflectedColor(const float3& rc){fprintf_s(mFile, "setAttr \".rc\" -type \"float3\" ");rc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Reflected Color</b> affects the color of light reflected from
	the material.
	<p/>You can map an image or texture  or environment map to this
	attribute in order to make 'fake reflections', which are less
	expensive than ray-tracing.  This is called Reflection Mapping.
	<p/>Reflection Mapping and raytracing may be used together, in
	which case the reflection map is used as 'background', and
	raytraced reflections appear in the 'foreground'.
	*/
	void setReflectedColor(const Float3ID& rc){fprintf_s(mFile,"connectAttr \"");rc.write(mFile);fprintf_s(mFile,"\" \"%s.rc\";\n",mName.c_str());}
	/*reflected color red value*/
	void setReflectedColorR(float rr){if(rr == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rr\" %f;\n", rr);}
	/*reflected color red value*/
	void setReflectedColorR(const FloatID& rr){fprintf_s(mFile,"connectAttr \"");rr.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rr\";\n",mName.c_str());}
	/*reflected color green value*/
	void setReflectedColorG(float rg){if(rg == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rg\" %f;\n", rg);}
	/*reflected color green value*/
	void setReflectedColorG(const FloatID& rg){fprintf_s(mFile,"connectAttr \"");rg.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rg\";\n",mName.c_str());}
	/*reflected color blue value*/
	void setReflectedColorB(float rb){if(rb == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rb\" %f;\n", rb);}
	/*reflected color blue value*/
	void setReflectedColorB(const FloatID& rb){fprintf_s(mFile,"connectAttr \"");rb.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rb\";\n",mName.c_str());}
	/*
	<b>Triangle Normal In Camera Space</b> This is the normal of the visible triangle
	in the camera space.
	<p/>This normal is used to check the reflection direction is not
	in the opposite direction of the normal of the visible triangle.
	*/
	void setTriangleNormalCamera(const Float3ID& tnc){fprintf_s(mFile,"connectAttr \"");tnc.write(mFile);fprintf_s(mFile,"\" \"%s.tnc\";\n",mName.c_str());}
	/*triangle normal x value*/
	void setTriangleNormalCameraX(const FloatID& tnx){fprintf_s(mFile,"connectAttr \"");tnx.write(mFile);fprintf_s(mFile,"\" \"%s.tnc.tnx\";\n",mName.c_str());}
	/*triangle normal y value*/
	void setTriangleNormalCameraY(const FloatID& tny){fprintf_s(mFile,"connectAttr \"");tny.write(mFile);fprintf_s(mFile,"\" \"%s.tnc.tny\";\n",mName.c_str());}
	/*triangle normal z value*/
	void setTriangleNormalCameraZ(const FloatID& tnz){fprintf_s(mFile,"connectAttr \"");tnz.write(mFile);fprintf_s(mFile,"\" \"%s.tnc.tnz\";\n",mName.c_str());}
	/*
	<b>Reflection Specular </b> controls the contribution of the
	specular component when dealing with reflection rays for ray
	tracing.  I.e., the specular contribution when seen as a
	mirror reflection.
	*/
	void setReflectionSpecularity(float rsp){if(rsp == 1.0) return; fprintf_s(mFile, "setAttr \".rsp\" %f;\n", rsp);}
	/*
	<b>Reflection Specular </b> controls the contribution of the
	specular component when dealing with reflection rays for ray
	tracing.  I.e., the specular contribution when seen as a
	mirror reflection.
	*/
	void setReflectionSpecularity(const FloatID& rsp){fprintf_s(mFile,"connectAttr \"");rsp.write(mFile);fprintf_s(mFile,"\" \"%s.rsp\";\n",mName.c_str());}
	/*
	<b>Out Color</b> is the final output color generated by this node.
	If you are using this node as one of the layers in a Layered Shader,
	then you will need to connect this attribute to the Color input of
	the Layered Shader.
	*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*out color red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*out color green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*out color blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*
	<b>Out Transparency</b> is the final output transparency generated by this node.
	If you are using this node as one of the layers in a Layered Shader,
	then you will need to connect this attribute to the Transparency input
	of the Layered Shader.
	*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*out transparency red value*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*out transparency green value*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*out transparency blue value*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*
	Out Glow Color is the final output glow color from this node
	(if this node is glowing)
	*/
	void setOutGlowColor(const Float3ID& ogc){fprintf_s(mFile,"connectAttr \"");ogc.write(mFile);fprintf_s(mFile,"\" \"%s.ogc\";\n",mName.c_str());}
	/*out glow color red value*/
	void setOutGlowColorR(const FloatID& ogr){fprintf_s(mFile,"connectAttr \"");ogr.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogr\";\n",mName.c_str());}
	/*out glow color green value*/
	void setOutGlowColorG(const FloatID& ogg){fprintf_s(mFile,"connectAttr \"");ogg.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogg\";\n",mName.c_str());}
	/*out glow color blue value*/
	void setOutGlowColorB(const FloatID& ogb){fprintf_s(mFile,"connectAttr \"");ogb.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogb\";\n",mName.c_str());}
	/*surface intersection point in camera space*/
	void setPointCamera(const Float3ID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*point camera x component*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.pc.px\";\n",mName.c_str());}
	/*point camera y component*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.pc.py\";\n",mName.c_str());}
	/*point camera z component*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pz\";\n",mName.c_str());}
	/*
	<b>Normal Camera</b> represents the surface normals in the
	camera's space. (These are
	used to calculate shading.)<p/>To do Bump Mapping, connect the output of a bump
	node to this attribute.
	*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*normal camera x value*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*normal camera Y value*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*normal camera Z value*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*The sample (filter) size*/
	void setFilterSize(const Float3ID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs\";\n",mName.c_str());}
	/*The X size of the filter (sample)*/
	void setFilterSizeX(const FloatID& fsx){fprintf_s(mFile,"connectAttr \"");fsx.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsx\";\n",mName.c_str());}
	/*The Y size of the filter (sample)*/
	void setFilterSizeY(const FloatID& fsy){fprintf_s(mFile,"connectAttr \"");fsy.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsy\";\n",mName.c_str());}
	/*The Z size of the filter (sample)*/
	void setFilterSizeZ(const FloatID& fsz){fprintf_s(mFile,"connectAttr \"");fsz.write(mFile);fprintf_s(mFile,"\" \"%s.fs.fsz\";\n",mName.c_str());}
	/*The matrix that takes world space to eye space*/
	void setMatrixWorldToEye(const FltMatrixID& wte){fprintf_s(mFile,"connectAttr \"");wte.write(mFile);fprintf_s(mFile,"\" \"%s.wte\";\n",mName.c_str());}
	/*The transform to go from eye to world space*/
	void setMatrixEyeToWorld(const FltMatrixID& e2w){fprintf_s(mFile,"connectAttr \"");e2w.write(mFile);fprintf_s(mFile,"\" \"%s.e2w\";\n",mName.c_str());}
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
	parts, when you do not want the background to show through them.
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
	parts, when you do not want the background to show through them.
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
	<b>Time</b> is used to animate the Ocean texture.
	Typically this is connected to the node time1, which
	provides the normal scene time for most nodes.
	*/
	void setTime(const TimeID& ti){fprintf_s(mFile,"connectAttr \"");ti.write(mFile);fprintf_s(mFile,"\" \"%s.ti\";\n",mName.c_str());}
	/*
	<b>Scale</b> controls the defined size in meters that corresponds
	to the texture space 0-1 in UV( for default texture placement settings ).
	*/
	void setScale(float scl){if(scl == 1.0) return; fprintf_s(mFile, "setAttr \".scl\" %f;\n", scl);}
	/*
	<b>Scale</b> controls the defined size in meters that corresponds
	to the texture space 0-1 in UV( for default texture placement settings ).
	*/
	void setScale(const FloatID& scl){fprintf_s(mFile,"connectAttr \"");scl.write(mFile);fprintf_s(mFile,"\" \"%s.scl\";\n",mName.c_str());}
	/*
	<b>Wind UV</b> controls the (average) direction that
	the waves will travel, simulating the effect
	of wind.  This is expressed as U and V values, in the
	UV texture space. Note: animating this parameter will
	cause unnatural motion, and should be avoided.
	*/
	void setWindUV(const float2& wi){if(wi == float2(1.0, 0.0)) return; fprintf_s(mFile, "setAttr \".wi\" -type \"float2\" ");wi.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Wind UV</b> controls the (average) direction that
	the waves will travel, simulating the effect
	of wind.  This is expressed as U and V values, in the
	UV texture space. Note: animating this parameter will
	cause unnatural motion, and should be avoided.
	*/
	void setWindUV(const Float2ID& wi){fprintf_s(mFile,"connectAttr \"");wi.write(mFile);fprintf_s(mFile,"\" \"%s.wi\";\n",mName.c_str());}
	/*The U component of the wind direction*/
	void setWindU(float wiu){if(wiu == 0.0) return; fprintf_s(mFile, "setAttr \".wi.wiu\" %f;\n", wiu);}
	/*The U component of the wind direction*/
	void setWindU(const FloatID& wiu){fprintf_s(mFile,"connectAttr \"");wiu.write(mFile);fprintf_s(mFile,"\" \"%s.wi.wiu\";\n",mName.c_str());}
	/*The V component of the wind direction*/
	void setWindV(float wiv){if(wiv == 0.0) return; fprintf_s(mFile, "setAttr \".wi.wiv\" %f;\n", wiv);}
	/*The V component of the wind direction*/
	void setWindV(const FloatID& wiv){fprintf_s(mFile,"connectAttr \"");wiv.write(mFile);fprintf_s(mFile,"\" \"%s.wi.wiv\";\n",mName.c_str());}
	/*
	<b>Observer Speed</b> is useful when you do not want the waves
	to move transversely. It cancels out transverse wave motion by
	moving a simulated observer. This is similar to animating the
	uvOffset of the texture relative to the wind direction.
	When <b>Observer Speed</b> is 1.0 the primary waves will not
	appear to travel because the viewer is moving at the same speed as
	the waves. The secondary waves will still move relative to the
	primary ones.
	*/
	void setObserverSpeed(float os){if(os == 0.0) return; fprintf_s(mFile, "setAttr \".os\" %f;\n", os);}
	/*
	<b>Observer Speed</b> is useful when you do not want the waves
	to move transversely. It cancels out transverse wave motion by
	moving a simulated observer. This is similar to animating the
	uvOffset of the texture relative to the wind direction.
	When <b>Observer Speed</b> is 1.0 the primary waves will not
	appear to travel because the viewer is moving at the same speed as
	the waves. The secondary waves will still move relative to the
	primary ones.
	*/
	void setObserverSpeed(const FloatID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*
	<b>WaveDirSpread</b> determines the variance in wave direction with
	respect to the wind direction. If it is zero, then all waves
	travel in the same direction. If it is one, then waves will travel
	in random directions. Inconsistency of the wind
	direction along with other effects like wave refraction tend
	to cause a natural variation in wave direction.
	*/
	void setWaveDirSpread(float wd){if(wd == 0.2) return; fprintf_s(mFile, "setAttr \".wd\" %f;\n", wd);}
	/*
	<b>WaveDirSpread</b> determines the variance in wave direction with
	respect to the wind direction. If it is zero, then all waves
	travel in the same direction. If it is one, then waves will travel
	in random directions. Inconsistency of the wind
	direction along with other effects like wave refraction tend
	to cause a natural variation in wave direction.
	*/
	void setWaveDirSpread(const FloatID& wd){fprintf_s(mFile,"connectAttr \"");wd.write(mFile);fprintf_s(mFile,"\" \"%s.wd\";\n",mName.c_str());}
	/*
	<b>NumFrequencies</b> controls the number of interpolated frequencies
	between <b>waveLengthMin</b> and <b>WaveLengthMax</b>
	Note: the higher this value, the longer this texture takes to compute.
	If this value is not an integer, then the number of created frequencies
	will be the rounded up value, but the amplitude for the extra
	frequency will be proportional to the remainder( ie .25 for 8.25 )
	This allows this parameter to be smoothly animated.
	*/
	void setNumFrequencies(float nf){if(nf == 3.0) return; fprintf_s(mFile, "setAttr \".nf\" %f;\n", nf);}
	/*
	<b>NumFrequencies</b> controls the number of interpolated frequencies
	between <b>waveLengthMin</b> and <b>WaveLengthMax</b>
	Note: the higher this value, the longer this texture takes to compute.
	If this value is not an integer, then the number of created frequencies
	will be the rounded up value, but the amplitude for the extra
	frequency will be proportional to the remainder( ie .25 for 8.25 )
	This allows this parameter to be smoothly animated.
	*/
	void setNumFrequencies(const FloatID& nf){fprintf_s(mFile,"connectAttr \"");nf.write(mFile);fprintf_s(mFile,"\" \"%s.nf\";\n",mName.c_str());}
	/*
	<b>WaveLengthMin</b> controls the minimum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	void setWaveLengthMin(float wlm){if(wlm == 0.3) return; fprintf_s(mFile, "setAttr \".wlm\" %f;\n", wlm);}
	/*
	<b>WaveLengthMin</b> controls the minimum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	void setWaveLengthMin(const FloatID& wlm){fprintf_s(mFile,"connectAttr \"");wlm.write(mFile);fprintf_s(mFile,"\" \"%s.wlm\";\n",mName.c_str());}
	/*
	<b>WaveLengthMax</b> controls the maximum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	void setWaveLengthMax(float wlx){if(wlx == 4.0) return; fprintf_s(mFile, "setAttr \".wlx\" %f;\n", wlx);}
	/*
	<b>WaveLengthMax</b> controls the maximum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	void setWaveLengthMax(const FloatID& wlx){fprintf_s(mFile,"connectAttr \"");wlx.write(mFile);fprintf_s(mFile,"\" \"%s.wlx\";\n",mName.c_str());}
	/*
	<b>WaveHeight</b> controls the size of waves relative
	to their wave length. If the value is 1.0, then the waves are half as
	tall as they are long. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	If the graph is a horizontal line, then all waves will
	exactly the same height proportional to their length.
	*/
	void setWaveHeight(size_t wh_i,const WaveHeight& wh){fprintf_s(mFile, "setAttr \".wh[%i]\" ",wh_i);wh.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>WaveHeight</b> controls the size of waves relative
	to their wave length. If the value is 1.0, then the waves are half as
	tall as they are long. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	If the graph is a horizontal line, then all waves will
	exactly the same height proportional to their length.
	*/
	void setWaveHeight(size_t wh_i,const WaveHeightID& wh){fprintf_s(mFile,"connectAttr \"");wh.write(mFile);fprintf_s(mFile,"\" \"%s.wh[%i]\";\n",mName.c_str(),wh_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWaveHeight_Position(size_t wh_i,float whp){if(whp == 0.0) return; fprintf_s(mFile, "setAttr \".wh[%i].whp\" %f;\n", wh_i,whp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWaveHeight_Position(size_t wh_i,const FloatID& whp){fprintf_s(mFile,"connectAttr \"");whp.write(mFile);fprintf_s(mFile,"\" \"%s.wh[%i].whp\";\n",mName.c_str(),wh_i);}
	/*Ramp value at the sibling position*/
	void setWaveHeight_FloatValue(size_t wh_i,float whfv){if(whfv == 0.0) return; fprintf_s(mFile, "setAttr \".wh[%i].whfv\" %f;\n", wh_i,whfv);}
	/*Ramp value at the sibling position*/
	void setWaveHeight_FloatValue(size_t wh_i,const FloatID& whfv){fprintf_s(mFile,"connectAttr \"");whfv.write(mFile);fprintf_s(mFile,"\" \"%s.wh[%i].whfv\";\n",mName.c_str(),wh_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setWaveHeight_Interp(size_t wh_i,unsigned int whi){if(whi == 0) return; fprintf_s(mFile, "setAttr \".wh[%i].whi\" %i;\n", wh_i,whi);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setWaveHeight_Interp(size_t wh_i,const UnsignedintID& whi){fprintf_s(mFile,"connectAttr \"");whi.write(mFile);fprintf_s(mFile,"\" \"%s.wh[%i].whi\";\n",mName.c_str(),wh_i);}
	/*
	<b>WaveTurbulence</b> controls the amount of turbulence at different
	wave frequencies. For values of 1.0 the wave motion will be
	completely turbulent at the defined frequency. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	For each wave frequency, the turbulence wave component
	consists of multiple sine waves at that frequency.
	This is the most computationaly expensive attribute. Making it zero
	will speed up renders significantly, although it is important for
	simulations of stormy or windy water. The peaking parameter only
	affects the turbulent wave layer, so there will be no affect from
	the peaking parameter wherever this value is zero.
	*/
	void setWaveTurbulence(size_t wtb_i,const WaveTurbulence& wtb){fprintf_s(mFile, "setAttr \".wtb[%i]\" ",wtb_i);wtb.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>WaveTurbulence</b> controls the amount of turbulence at different
	wave frequencies. For values of 1.0 the wave motion will be
	completely turbulent at the defined frequency. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	For each wave frequency, the turbulence wave component
	consists of multiple sine waves at that frequency.
	This is the most computationaly expensive attribute. Making it zero
	will speed up renders significantly, although it is important for
	simulations of stormy or windy water. The peaking parameter only
	affects the turbulent wave layer, so there will be no affect from
	the peaking parameter wherever this value is zero.
	*/
	void setWaveTurbulence(size_t wtb_i,const WaveTurbulenceID& wtb){fprintf_s(mFile,"connectAttr \"");wtb.write(mFile);fprintf_s(mFile,"\" \"%s.wtb[%i]\";\n",mName.c_str(),wtb_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWaveTurbulence_Position(size_t wtb_i,float wtbp){if(wtbp == 0.0) return; fprintf_s(mFile, "setAttr \".wtb[%i].wtbp\" %f;\n", wtb_i,wtbp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWaveTurbulence_Position(size_t wtb_i,const FloatID& wtbp){fprintf_s(mFile,"connectAttr \"");wtbp.write(mFile);fprintf_s(mFile,"\" \"%s.wtb[%i].wtbp\";\n",mName.c_str(),wtb_i);}
	/*Ramp value at the sibling position*/
	void setWaveTurbulence_FloatValue(size_t wtb_i,float wtbfv){if(wtbfv == 0.0) return; fprintf_s(mFile, "setAttr \".wtb[%i].wtbfv\" %f;\n", wtb_i,wtbfv);}
	/*Ramp value at the sibling position*/
	void setWaveTurbulence_FloatValue(size_t wtb_i,const FloatID& wtbfv){fprintf_s(mFile,"connectAttr \"");wtbfv.write(mFile);fprintf_s(mFile,"\" \"%s.wtb[%i].wtbfv\";\n",mName.c_str(),wtb_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setWaveTurbulence_Interp(size_t wtb_i,unsigned int wtbi){if(wtbi == 0) return; fprintf_s(mFile, "setAttr \".wtb[%i].wtbi\" %i;\n", wtb_i,wtbi);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setWaveTurbulence_Interp(size_t wtb_i,const UnsignedintID& wtbi){fprintf_s(mFile,"connectAttr \"");wtbi.write(mFile);fprintf_s(mFile,"\" \"%s.wtb[%i].wtbi\";\n",mName.c_str(),wtb_i);}
	/*
	<b>WavePeaking</b> controls the amount of crest formation for waves
	across the range of wave frequencies.
	This simulates a side to side sloshing of waves, as opposed to
	up-down motion. When this parameter is non-zero many more
	evaluations of the noise function are performed, and thus the
	computation speed will be affected. Also the waveTurbulence
	function must be non-zero for this parameter to have an effects,
	as it is only applied to the turbulent waves.
	*/
	void setWavePeaking(size_t wp_i,const WavePeaking& wp){fprintf_s(mFile, "setAttr \".wp[%i]\" ",wp_i);wp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>WavePeaking</b> controls the amount of crest formation for waves
	across the range of wave frequencies.
	This simulates a side to side sloshing of waves, as opposed to
	up-down motion. When this parameter is non-zero many more
	evaluations of the noise function are performed, and thus the
	computation speed will be affected. Also the waveTurbulence
	function must be non-zero for this parameter to have an effects,
	as it is only applied to the turbulent waves.
	*/
	void setWavePeaking(size_t wp_i,const WavePeakingID& wp){fprintf_s(mFile,"connectAttr \"");wp.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i]\";\n",mName.c_str(),wp_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWavePeaking_Position(size_t wp_i,float wpp){if(wpp == 0.0) return; fprintf_s(mFile, "setAttr \".wp[%i].wpp\" %f;\n", wp_i,wpp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWavePeaking_Position(size_t wp_i,const FloatID& wpp){fprintf_s(mFile,"connectAttr \"");wpp.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i].wpp\";\n",mName.c_str(),wp_i);}
	/*Ramp value at the sibling position*/
	void setWavePeaking_FloatValue(size_t wp_i,float wpfv){if(wpfv == 0.0) return; fprintf_s(mFile, "setAttr \".wp[%i].wpfv\" %f;\n", wp_i,wpfv);}
	/*Ramp value at the sibling position*/
	void setWavePeaking_FloatValue(size_t wp_i,const FloatID& wpfv){fprintf_s(mFile,"connectAttr \"");wpfv.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i].wpfv\";\n",mName.c_str(),wp_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setWavePeaking_Interp(size_t wp_i,unsigned int wpi){if(wpi == 0) return; fprintf_s(mFile, "setAttr \".wp[%i].wpi\" %i;\n", wp_i,wpi);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setWavePeaking_Interp(size_t wp_i,const UnsignedintID& wpi){fprintf_s(mFile,"connectAttr \"");wpi.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i].wpi\";\n",mName.c_str(),wp_i);}
	/*
	<b>WaveHeightOffset</b> is a simple offset on the overall
	displacement of the ocean. When textured this is useful for adding
	custom waves and boat wakes.
	*/
	void setWaveHeightOffset(float who){if(who == 0.0) return; fprintf_s(mFile, "setAttr \".who\" %f;\n", who);}
	/*
	<b>WaveHeightOffset</b> is a simple offset on the overall
	displacement of the ocean. When textured this is useful for adding
	custom waves and boat wakes.
	*/
	void setWaveHeightOffset(const FloatID& who){fprintf_s(mFile,"connectAttr \"");who.write(mFile);fprintf_s(mFile,"\" \"%s.who\";\n",mName.c_str());}
	/*
	<b>TroughShadowing</b> darkens the diffuse color in the wave troughs.
	This can simulate certain lighting conditions where wave peaks are
	brighter, scattering light. This works well when the wave color is
	in a blue-green range.
	*/
	void setTroughShadowing(float tsh){if(tsh == 0.5) return; fprintf_s(mFile, "setAttr \".tsh\" %f;\n", tsh);}
	/*
	<b>TroughShadowing</b> darkens the diffuse color in the wave troughs.
	This can simulate certain lighting conditions where wave peaks are
	brighter, scattering light. This works well when the wave color is
	in a blue-green range.
	*/
	void setTroughShadowing(const FloatID& tsh){fprintf_s(mFile,"connectAttr \"");tsh.write(mFile);fprintf_s(mFile,"\" \"%s.tsh\";\n",mName.c_str());}
	/*
	<b>Foam Color</b> determines the color of the foam layer.
	Part of the simulated foam may be considered submerged, in
	which case the color is blended with the material color.
	*/
	void setFoamColor(const float3& fc){fprintf_s(mFile, "setAttr \".fc\" -type \"float3\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Foam Color</b> determines the color of the foam layer.
	Part of the simulated foam may be considered submerged, in
	which case the color is blended with the material color.
	*/
	void setFoamColor(const Float3ID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc\";\n",mName.c_str());}
	/*foamColor red value*/
	void setFoamColorR(float fcr){if(fcr == 1.0) return; fprintf_s(mFile, "setAttr \".fc.fcr\" %f;\n", fcr);}
	/*foamColor red value*/
	void setFoamColorR(const FloatID& fcr){fprintf_s(mFile,"connectAttr \"");fcr.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcr\";\n",mName.c_str());}
	/*foamColor green value*/
	void setFoamColorG(float fcg){if(fcg == 1.0) return; fprintf_s(mFile, "setAttr \".fc.fcg\" %f;\n", fcg);}
	/*foamColor green value*/
	void setFoamColorG(const FloatID& fcg){fprintf_s(mFile,"connectAttr \"");fcg.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcg\";\n",mName.c_str());}
	/*foamColor blue value*/
	void setFoamColorB(float fcb){if(fcb == 1.0) return; fprintf_s(mFile, "setAttr \".fc.fcb\" %f;\n", fcb);}
	/*foamColor blue value*/
	void setFoamColorB(const FloatID& fcb){fprintf_s(mFile,"connectAttr \"");fcb.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcb\";\n",mName.c_str());}
	/*
	<b>FoamEmission</b> Controls density of foam generated above
	the foam threshold. The foam value is output to the outFoam
	attribute, which can be used to define opacity of a layered
	foam shader.
	*/
	void setFoamEmission(float fme){if(fme == 0.0) return; fprintf_s(mFile, "setAttr \".fme\" %f;\n", fme);}
	/*
	<b>FoamEmission</b> Controls density of foam generated above
	the foam threshold. The foam value is output to the outFoam
	attribute, which can be used to define opacity of a layered
	foam shader.
	*/
	void setFoamEmission(const FloatID& fme){fprintf_s(mFile,"connectAttr \"");fme.write(mFile);fprintf_s(mFile,"\" \"%s.fme\";\n",mName.c_str());}
	/*
	<b>FoamThreshold</b> Controls the wave amplitude required
	to generate foam as well as how long the foam lasts.
	*/
	void setFoamThreshold(float fmt){if(fmt == 0.51) return; fprintf_s(mFile, "setAttr \".fmt\" %f;\n", fmt);}
	/*
	<b>FoamThreshold</b> Controls the wave amplitude required
	to generate foam as well as how long the foam lasts.
	*/
	void setFoamThreshold(const FloatID& fmt){fprintf_s(mFile,"connectAttr \"");fmt.write(mFile);fprintf_s(mFile,"\" \"%s.fmt\";\n",mName.c_str());}
	/*
	<b>FoamOffset</b> simply adds a uniform foam everywhere.
	It is useful when one needs to add a custom foam texture.
	*/
	void setFoamOffset(float fmo){if(fmo == 0.0) return; fprintf_s(mFile, "setAttr \".fmo\" %f;\n", fmo);}
	/*
	<b>FoamOffset</b> simply adds a uniform foam everywhere.
	It is useful when one needs to add a custom foam texture.
	*/
	void setFoamOffset(const FloatID& fmo){fprintf_s(mFile,"connectAttr \"");fmo.write(mFile);fprintf_s(mFile,"\" \"%s.fmo\";\n",mName.c_str());}
	/*
	<b>Out Foam</b> is the output foam density value
	computed by the texture.  Use this value to control
	the density of a layered foam shader. If applied
	to transparency, the value should be first inverted.
	*/
	void setOutFoam(const FloatID& ofm){fprintf_s(mFile,"connectAttr \"");ofm.write(mFile);fprintf_s(mFile,"\" \"%s.ofm\";\n",mName.c_str());}
	/*
	<b>Out Displacement</b> is the relative output height of the
	waves computed by the shader. The value of zero represents sealevel.
	It should typically be plugged into
	the displacement shader.
	*/
	void setDisplacement(float d){if(d == 0.0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	<b>Out Displacement</b> is the relative output height of the
	waves computed by the shader. The value of zero represents sealevel.
	It should typically be plugged into
	the displacement shader.
	*/
	void setDisplacement(const FloatID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	<b>Bump Blur</b> determines the separation of samples(relative to
	the smallest wavelength) used in
	computing the bumped normal for shading. Larger values have the
	effect of making small waves and peaks smoother.
	*/
	void setBumpBlur(float bbl){if(bbl == 0.1) return; fprintf_s(mFile, "setAttr \".bbl\" %f;\n", bbl);}
	/*
	<b>Bump Blur</b> determines the separation of samples(relative to
	the smallest wavelength) used in
	computing the bumped normal for shading. Larger values have the
	effect of making small waves and peaks smoother.
	*/
	void setBumpBlur(const FloatID& bbl){fprintf_s(mFile,"connectAttr \"");bbl.write(mFile);fprintf_s(mFile,"\" \"%s.bbl\";\n",mName.c_str());}
	/*
	<b>Horizon Filter</b> smooths the ocean near the horizon so that lower
	antialiasing levels may be used. This help avoids chatter along the horizon.
	The bump blur is increased for oblique distant samples.
	*/
	void setHorizonFilter(float hft){if(hft == 1.0) return; fprintf_s(mFile, "setAttr \".hft\" %f;\n", hft);}
	/*
	<b>Horizon Filter</b> smooths the ocean near the horizon so that lower
	antialiasing levels may be used. This help avoids chatter along the horizon.
	The bump blur is increased for oblique distant samples.
	*/
	void setHorizonFilter(const FloatID& hft){fprintf_s(mFile,"connectAttr \"");hft.write(mFile);fprintf_s(mFile,"\" \"%s.hft\";\n",mName.c_str());}
	/*
	<b>Wave Speed</b> determines how fast waves move.
	It scales the input time used to determine
	wave movement. At the default value of 1.0 it creates
	the correct speeds for open ocean waves at the scale
	determined by the Maya units and the oceanShader scale parameter.
	Thus if the scale is 10 and the wave speed 1, 1 unit will
	represent 10 meters and the waves should move at the correct speed.
	To freeze the waves make the speed zero. If you wish the speed
	to change over time this parameter will not work. One needs to
	change the animation on the time attribute instead.
	*/
	void setWaveSpeed(float wvs){if(wvs == 1.0) return; fprintf_s(mFile, "setAttr \".wvs\" %f;\n", wvs);}
	/*
	<b>Wave Speed</b> determines how fast waves move.
	It scales the input time used to determine
	wave movement. At the default value of 1.0 it creates
	the correct speeds for open ocean waves at the scale
	determined by the Maya units and the oceanShader scale parameter.
	Thus if the scale is 10 and the wave speed 1, 1 unit will
	represent 10 meters and the waves should move at the correct speed.
	To freeze the waves make the speed zero. If you wish the speed
	to change over time this parameter will not work. One needs to
	change the animation on the time attribute instead.
	*/
	void setWaveSpeed(const FloatID& wvs){fprintf_s(mFile,"connectAttr \"");wvs.write(mFile);fprintf_s(mFile,"\" \"%s.wvs\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointCamera(const Float3ID& rpc){fprintf_s(mFile,"connectAttr \"");rpc.write(mFile);fprintf_s(mFile,"\" \"%s.rpc\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setRefPointCameraX(const FloatID& rcx){fprintf_s(mFile,"connectAttr \"");rcx.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setRefPointCameraY(const FloatID& rcy){fprintf_s(mFile,"connectAttr \"");rcy.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setRefPointCameraZ(const FloatID& rcz){fprintf_s(mFile,"connectAttr \"");rcz.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcz\";\n",mName.c_str());}
	/*
	Enable refraction blur by shooting more refraction rays.
	Blurry refractions require supersampling
	because a ray's direction is not exactly determined anymore.
	It may deviate (randomly) from the perfect specular direction,
	within the bounds specified by <b>miRefractionBlur</b> (in angle).
	A value of zero implies a perfectly specular interaction,
	a value of 90 a perfectly diffuse reflection or refraction.
	Values of 10 to 30 are a good starting point
	*/
	void setMiRefractionBlur(float mirfb){if(mirfb == 0) return; fprintf_s(mFile, "setAttr \".mirfb\" %f;\n", mirfb);}
	/*
	Enable refraction blur by shooting more refraction rays.
	Blurry refractions require supersampling
	because a ray's direction is not exactly determined anymore.
	It may deviate (randomly) from the perfect specular direction,
	within the bounds specified by <b>miRefractionBlur</b> (in angle).
	A value of zero implies a perfectly specular interaction,
	a value of 90 a perfectly diffuse reflection or refraction.
	Values of 10 to 30 are a good starting point
	*/
	void setMiRefractionBlur(const FloatID& mirfb){fprintf_s(mFile,"connectAttr \"");mirfb.write(mFile);fprintf_s(mFile,"\" \"%s.mirfb\";\n",mName.c_str());}
	/*
	Number of refraction rays to use for blurring.
	<b>miRefractionRays</b> specifies number of rays to use
	to sample the random deviation. In general more rays are required
	for more blurry reflections or refractions.
	Other sampling parameters also affect this setting:
	per-object samples and the Render Settings sample setting supersample in image space.
	If you increase any of these two settings,
	you may be able to reduce the number of rays without loss of quality,
	but significant performance gain.
	*/
	void setMiRefractionRays(short mirfr){if(mirfr == 1) return; fprintf_s(mFile, "setAttr \".mirfr\" %i;\n", mirfr);}
	/*
	Number of refraction rays to use for blurring.
	<b>miRefractionRays</b> specifies number of rays to use
	to sample the random deviation. In general more rays are required
	for more blurry reflections or refractions.
	Other sampling parameters also affect this setting:
	per-object samples and the Render Settings sample setting supersample in image space.
	If you increase any of these two settings,
	you may be able to reduce the number of rays without loss of quality,
	but significant performance gain.
	*/
	void setMiRefractionRays(const ShortID& mirfr){fprintf_s(mFile,"connectAttr \"");mirfr.write(mFile);fprintf_s(mFile,"\" \"%s.mirfr\";\n",mName.c_str());}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a ray's direction is not exactly determined anymore.
	It may deviate (randomly) from the perfect specular direction,
	within the bounds specified by <b>miReflectionBlur</b> (in angle).
	A value of zero implies a perfectly specular interaction,
	a value of 90 a perfectly diffuse reflection or refraction.
	Values of 10 to 30 are a good starting point
	*/
	void setMiReflectionBlur(float mircb){if(mircb == 0) return; fprintf_s(mFile, "setAttr \".mircb\" %f;\n", mircb);}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a ray's direction is not exactly determined anymore.
	It may deviate (randomly) from the perfect specular direction,
	within the bounds specified by <b>miReflectionBlur</b> (in angle).
	A value of zero implies a perfectly specular interaction,
	a value of 90 a perfectly diffuse reflection or refraction.
	Values of 10 to 30 are a good starting point
	*/
	void setMiReflectionBlur(const FloatID& mircb){fprintf_s(mFile,"connectAttr \"");mircb.write(mFile);fprintf_s(mFile,"\" \"%s.mircb\";\n",mName.c_str());}
	/*
	Number of reflection rays to use for blurring.
	<b>miReflectionRays</b> specifies number of rays to use
	to sample the random deviation. In general more rays are required
	for more blurry reflections or refractions.
	Other sampling parameters also affect this setting:
	per-object samples and the Render Settings sample setting supersample in image space.
	If you increase any of these two settings,
	you may be able to reduce the number of rays without loss of quality,
	but significant performance gain.
	*/
	void setMiReflectionRays(short mircr){if(mircr == 1) return; fprintf_s(mFile, "setAttr \".mircr\" %i;\n", mircr);}
	/*
	Number of reflection rays to use for blurring.
	<b>miReflectionRays</b> specifies number of rays to use
	to sample the random deviation. In general more rays are required
	for more blurry reflections or refractions.
	Other sampling parameters also affect this setting:
	per-object samples and the Render Settings sample setting supersample in image space.
	If you increase any of these two settings,
	you may be able to reduce the number of rays without loss of quality,
	but significant performance gain.
	*/
	void setMiReflectionRays(const ShortID& mircr){fprintf_s(mFile,"connectAttr \"");mircr.write(mFile);fprintf_s(mFile,"\" \"%s.mircr\";\n",mName.c_str());}
	/*Port to map indirect illumination from a texture instead of computing it.*/
	void setMiIrradiance(const float3& mii){fprintf_s(mFile, "setAttr \".mii\" -type \"float3\" ");mii.write(mFile);fprintf_s(mFile,";\n");}
	/*Port to map indirect illumination from a texture instead of computing it.*/
	void setMiIrradiance(const Float3ID& mii){fprintf_s(mFile,"connectAttr \"");mii.write(mFile);fprintf_s(mFile,"\" \"%s.mii\";\n",mName.c_str());}
	/*Red component.*/
	void setMiIrradianceR(float miir){if(miir == 0) return; fprintf_s(mFile, "setAttr \".mii.miir\" %f;\n", miir);}
	/*Red component.*/
	void setMiIrradianceR(const FloatID& miir){fprintf_s(mFile,"connectAttr \"");miir.write(mFile);fprintf_s(mFile,"\" \"%s.mii.miir\";\n",mName.c_str());}
	/*Green component.*/
	void setMiIrradianceG(float miig){if(miig == 0) return; fprintf_s(mFile, "setAttr \".mii.miig\" %f;\n", miig);}
	/*Green component.*/
	void setMiIrradianceG(const FloatID& miig){fprintf_s(mFile,"connectAttr \"");miig.write(mFile);fprintf_s(mFile,"\" \"%s.mii.miig\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiIrradianceB(float miib){if(miib == 0) return; fprintf_s(mFile, "setAttr \".mii.miib\" %f;\n", miib);}
	/*Blue component.*/
	void setMiIrradianceB(const FloatID& miib){fprintf_s(mFile,"connectAttr \"");miib.write(mFile);fprintf_s(mFile,"\" \"%s.mii.miib\";\n",mName.c_str());}
	/*Scale the indirect illumination by this color before applying.*/
	void setMiIrradianceColor(const float3& miic){fprintf_s(mFile, "setAttr \".miic\" -type \"float3\" ");miic.write(mFile);fprintf_s(mFile,";\n");}
	/*Scale the indirect illumination by this color before applying.*/
	void setMiIrradianceColor(const Float3ID& miic){fprintf_s(mFile,"connectAttr \"");miic.write(mFile);fprintf_s(mFile,"\" \"%s.miic\";\n",mName.c_str());}
	/*Red component.*/
	void setMiIrradianceColorR(float miicr){if(miicr == 1) return; fprintf_s(mFile, "setAttr \".miic.miicr\" %f;\n", miicr);}
	/*Red component.*/
	void setMiIrradianceColorR(const FloatID& miicr){fprintf_s(mFile,"connectAttr \"");miicr.write(mFile);fprintf_s(mFile,"\" \"%s.miic.miicr\";\n",mName.c_str());}
	/*Green component.*/
	void setMiIrradianceColorG(float miicg){if(miicg == 1) return; fprintf_s(mFile, "setAttr \".miic.miicg\" %f;\n", miicg);}
	/*Green component.*/
	void setMiIrradianceColorG(const FloatID& miicg){fprintf_s(mFile,"connectAttr \"");miicg.write(mFile);fprintf_s(mFile,"\" \"%s.miic.miicg\";\n",mName.c_str());}
	/*Blue component.*/
	void setMiIrradianceColorB(float miicb){if(miicb == 1) return; fprintf_s(mFile, "setAttr \".miic.miicb\" %f;\n", miicb);}
	/*Blue component.*/
	void setMiIrradianceColorB(const FloatID& miicb){fprintf_s(mFile,"connectAttr \"");miicb.write(mFile);fprintf_s(mFile,"\" \"%s.miic.miicb\";\n",mName.c_str());}
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
	/*ray depth limit*/
	ShortID getRefractionLimit(){char buffer[4096];sprintf_s (buffer, "%s.rdl",mName.c_str());return (const char*)buffer;}
	/*
	<b>Refractive Index</b> determines how much a ray of light will bend
	when it passes through an object.  This attribute only works
	if your material is partially or completely transparent (see the
	<i>Transparency</i> attribute), refractions are turned on
	(see the <i>Refractions</i> attribute) and you
	are rendering using Ray Tracing.  (See <i>Render Settings</i>)
	<p/>
	If the Refractive Index is set to 1.0, then light does not bend
	when it passes through the object.  Here are some other useful values
	for Refractive Index:
	<p/><ul>
	Air: 1.0<br/>
	Water: 1.33<br/>
	Gasoline: 1.45<br/>
	Crystal: 2.00<br/>
	Glass: 1.5<br/>
	Ice: 1.309<br/>
	Quartz: 1.6<br/>
	Ruby: 1.77<br/>
	Sapphire: 1.77<br/>
	Salt: 1.54<br/>
	Alcohol: 1.329<br/>
	Emerald: 1.57<br/>
	Polystyrene: 1.55<br/>
	</ul>
	<p/><i>Note:</i>If you make an object transparent, objects that
	are seen through it will be refracted only if their Visible
	In Refractions attribute is turned on.
	*/
	FloatID getRefractiveIndex(){char buffer[4096];sprintf_s (buffer, "%s.rfi",mName.c_str());return (const char*)buffer;}
	/*
	Turn on <b>Refractions</b> to make your material refract light
	when you are rendering with Ray Tracing.  You will not see
	a difference unless Refractive Index is set to a value other
	than 1.0. (See the <i>Refractive Index</i>
	attribute above for more details.)  Refractions are turned off by default.
	*/
	BoolID getRefractions(){char buffer[4096];sprintf_s (buffer, "%s.rfc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Diffuse</b> controls how much of the light in the scene
	is scattered from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.
	*/
	FloatID getDiffuse(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*<b>Color</b> is the basic color of the surface.*/
	Float3ID getWaterColor(){char buffer[4096];sprintf_s (buffer, "%s.wc",mName.c_str());return (const char*)buffer;}
	/*color red value*/
	FloatID getWaterColorR(){char buffer[4096];sprintf_s (buffer, "%s.wc.wcr",mName.c_str());return (const char*)buffer;}
	/*color green value*/
	FloatID getWaterColorG(){char buffer[4096];sprintf_s (buffer, "%s.wc.wcg",mName.c_str());return (const char*)buffer;}
	/*color blue value*/
	FloatID getWaterColorB(){char buffer[4096];sprintf_s (buffer, "%s.wc.wcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Transparency</b> controls how transparent or opaque the material is.
	Black means completely opaque (the default), and white means completely
	transparent.  You can set it to any level in between.  You can
	also control transparency on a per-channel basis;  for example, if
	you set this to red, then only the red channel will be transparent.
	<p/><i>Note:</i> If this material has specular highlights (<i>i.e.</i>, if
	this is a Phong or Blinn shader), the transparency
	setting will <i>not</i> affect the highlights.  So if you are
	trying to make an object disappear by animating the transparency
	attribute, you may also have to animate the specular highlight
	attributes.
	*/
	Float3ID getTransparency(){char buffer[4096];sprintf_s (buffer, "%s.it",mName.c_str());return (const char*)buffer;}
	/*transparency red value*/
	FloatID getTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.it.itr",mName.c_str());return (const char*)buffer;}
	/*transparency green value*/
	FloatID getTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.it.itg",mName.c_str());return (const char*)buffer;}
	/*transparency blue value*/
	FloatID getTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.it.itb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ambient Color</b> is black by default, which means it does not affect
	the material's over-all color.  As the ambient color becomes brighter,
	it affects the material's color by lightening it and blending
	the two colors.
	<p/>
	If there are ambient lights in the scene, then the color and
	brightness of those lights is used to control how much the
	ambient color contributes to the final color of the material.
	*/
	Float3ID getAmbientColor(){char buffer[4096];sprintf_s (buffer, "%s.ambc",mName.c_str());return (const char*)buffer;}
	/*ambient color red value*/
	FloatID getAmbientColorR(){char buffer[4096];sprintf_s (buffer, "%s.ambc.acr",mName.c_str());return (const char*)buffer;}
	/*ambient color green value*/
	FloatID getAmbientColorG(){char buffer[4096];sprintf_s (buffer, "%s.ambc.acg",mName.c_str());return (const char*)buffer;}
	/*ambient color blue value*/
	FloatID getAmbientColorB(){char buffer[4096];sprintf_s (buffer, "%s.ambc.acb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Incandescence</b> makes a material appear opalescent, as if it were
	emmitting light itself, such as lava or a phosphorescent moss.  A
	slight touch of incandescence on vegetable matter, for example,
	can make the vegetation look alive.<p/>
	By default, the color is black, which has no effect on the surface.
	<p/><i>Note:</i> although incandescence makes a surface appear to
	glow, it does not actually act as a source of light in the scene.
	<p/>See also Glow Intensity.
	*/
	Float3ID getIncandescence(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*incandescence red value*/
	FloatID getIncandescenceR(){char buffer[4096];sprintf_s (buffer, "%s.ic.ir",mName.c_str());return (const char*)buffer;}
	/*incandescence green value*/
	FloatID getIncandescenceG(){char buffer[4096];sprintf_s (buffer, "%s.ic.ig",mName.c_str());return (const char*)buffer;}
	/*incandescence blue value*/
	FloatID getIncandescenceB(){char buffer[4096];sprintf_s (buffer, "%s.ic.ib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Translucence</b> simulates the way light diffusely penetrates
	through translucent objects.  This means that when light shines
	on one side of the object, the other side is partially illuminated.
	This can be used for effects such as clouds, fur, hair, marble,
	jade, wax, paper, leaves, etc.
	<p/>If this is set to 0 (the default) then no light shows through
	the object.  If this is set to 1, all the light shows through.
	*/
	FloatID getTranslucence(){char buffer[4096];sprintf_s (buffer, "%s.tc",mName.c_str());return (const char*)buffer;}
	/*
	<b>TranslucenceFocus</b> simulates the way light scatters more
	in a forward direction through translucent objects.
	Thin objects like a leaf, or low density objects like a cloud
	tend to scatter more in a forward direction. When the focus is 0.0
	translucent light is scattered in all directions. As the focus
	value is raised the translucent light is scatter more in the
	light direction. This makes the backlit side of a leaf glow more
	than the frontlit side. At high focus values one will see a halo
	or glow around the lightsource when seen through a translucent
	object.
	*/
	FloatID getTranslucenceFocus(){char buffer[4096];sprintf_s (buffer, "%s.tcf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Translucence Depth</b><p/>
	The depth of penetration into an object at which translucence decays
	to nothing.  When the parameter is 0, translucence does not decay
	with respect to the distance light travels through the object.
	*/
	FloatID getTranslucenceDepth(){char buffer[4096];sprintf_s (buffer, "%s.trsd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Opacity Depth</b> (Studio special effect)<p/>
	Causes the transparency of an object to diminish with its thickness.
	An object is opaque if its thickness is greater than its Opacity Depth.
	When the Opacity Depth value is 0, it has no effect (as opposed to
	making an object entirely opaque).  The shader must have some
	Transparency to show the effect of Opacity Depth. When Opacity Depth
	is non-zero, transparency controls specularity, reflectivity, and
	incandescence, which are normally independent of transparency.
	This makes it easier to create soft, fuzzy objects. Also, if you
	use a transparency map to create holes in a surface that has specular
	highlights, set Opacity Depth to a high value instead of creating a
	matching specular map. Transparent objects cast shadows in the
	raycaster even if the Opacity Depth value is non-zero.
	<p/>Tip: Use Opacity Depth to simulate hair, fur, and clouds.
	*/
	FloatID getOpacityDepth(){char buffer[4096];sprintf_s (buffer, "%s.opad",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Intensity</b> is 0 by default, meaning that no glow is added to the
	material.  As this is turned up, the material seems to 'glow'
	with a faint halo of light around it.
	<p/>Note that this is different from the Incandescence attribute
	in a few important ways.  First, glow is added as a post-process
	at the end of rendering.  (Incandescence just makes the surface
	appear brighter.)  Second, glow adds a halo, which incandescence
	does not.
	*/
	FloatID getGlowIntensity(){char buffer[4096];sprintf_s (buffer, "%s.gi",mName.c_str());return (const char*)buffer;}
	/*
	<b>Specular Glow</b> works the same way as glow intensity, only
	it makes specular highlights glow. It is useful for things like
	twinkling highlights on water.
	*/
	FloatID getSpecularGlow(){char buffer[4096];sprintf_s (buffer, "%s.spg",mName.c_str());return (const char*)buffer;}
	/*
	<b>Shadow Attenuation (Fake Refraction Caustics)</b>>p>
	(aka Studio special effect "Transparency Shade" - raytracing only)<p/>
	Causes shadows of transparent objects to be brighter in the
	center, simulating the focusing of light.  0 gives constant
	intensity shadows, 1 gives shadows focused in the center.
	*/
	FloatID getShadowAttenuation(){char buffer[4096];sprintf_s (buffer, "%s.fakc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Eccentricity</b> controls how big your specular highlights
	(also called 'hot spots') will be.
	*/
	FloatID getEccentricity(){char buffer[4096];sprintf_s (buffer, "%s.ec",mName.c_str());return (const char*)buffer;}
	/*
	<b>Specularity</b> controls how bright your specular highlights
	will be.  It is a simple multiplier of the specular color.
	*/
	FloatID getSpecularity(){char buffer[4096];sprintf_s (buffer, "%s.spl",mName.c_str());return (const char*)buffer;}
	/*reflected ray depth limit*/
	ShortID getReflectionLimit(){char buffer[4096];sprintf_s (buffer, "%s.fll",mName.c_str());return (const char*)buffer;}
	/*
	<b>Specular Color</b> is the color of the specular reflections
	(also called 'hot spots') on the material.  The final color
	of a specular reflection is a combination of the Specular Color
	and the color of the light.
	<p/>By making the Specular Color brighter or dimmer, you can control
	the brightness of the specular reflections on an object.
	<p/>
	<i>Tip:</i> To make a material look more plastic, use white for the specular
	color.  To make a material look more metallic, make the specular
	color similar to the surface color.
	*/
	Float3ID getSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*specular color red value*/
	FloatID getSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.sc.sr",mName.c_str());return (const char*)buffer;}
	/*specular color green value*/
	FloatID getSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.sc.sg",mName.c_str());return (const char*)buffer;}
	/*specular color blue value*/
	FloatID getSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.sc.sb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
	<p/>
	The default ocean reflectivity  currently matches that of water.
	It is nearly totally reflective from glancing angles but not so reflective
	from others( the Fresnel effect ). This effect is a feature of the
	refractive index of a material, which for water is 1.33. Increasing
	the refractive index will make the water more reflective to direct rays,
	but also more like chrome than water.
	<p/>
	This attribute is only meaningful if there is a reflection map, or
	if you are doing Ray Tracing.
	<p/>
	Here are some useful values for Reflectivity:
	<ul>
	Car Paint: 0.4<br/>
	Glass: 0.7<br/>
	Mirror: 1.0<br/>
	Chrome: 1.0
	</ul>
	<p/>
	<i>Note:</i> If you are doing Ray Tracing, and you want
	other objects in the scene to be seen in reflections, then
	you must turn on the Visible In Reflections attribute of
	those objects.
	*/
	FloatID getReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.rfl",mName.c_str());return (const char*)buffer;}
	/*
	<b>Environment</b> defines a simple sky to ground environmental
	reflection using a ramp. The left of the ramp is the top of the
	sky and the right is the bottom.
	*/
	const EnvironmentID& getEnvironment(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i]",mName.c_str(),env_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getEnvironment_Position(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envp",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getEnvironment_Color(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getEnvironment_ColorR(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc.envcr",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getEnvironment_ColorG(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc.envcg",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getEnvironment_ColorB(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc.envcb",mName.c_str(),env_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getEnvironment_Interp(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envi",mName.c_str(),env_i);return (const char*)buffer;}
	/*
	<b>Reflected Color</b> affects the color of light reflected from
	the material.
	<p/>You can map an image or texture  or environment map to this
	attribute in order to make 'fake reflections', which are less
	expensive than ray-tracing.  This is called Reflection Mapping.
	<p/>Reflection Mapping and raytracing may be used together, in
	which case the reflection map is used as 'background', and
	raytraced reflections appear in the 'foreground'.
	*/
	Float3ID getReflectedColor(){char buffer[4096];sprintf_s (buffer, "%s.rc",mName.c_str());return (const char*)buffer;}
	/*reflected color red value*/
	FloatID getReflectedColorR(){char buffer[4096];sprintf_s (buffer, "%s.rc.rr",mName.c_str());return (const char*)buffer;}
	/*reflected color green value*/
	FloatID getReflectedColorG(){char buffer[4096];sprintf_s (buffer, "%s.rc.rg",mName.c_str());return (const char*)buffer;}
	/*reflected color blue value*/
	FloatID getReflectedColorB(){char buffer[4096];sprintf_s (buffer, "%s.rc.rb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Triangle Normal In Camera Space</b> This is the normal of the visible triangle
	in the camera space.
	<p/>This normal is used to check the reflection direction is not
	in the opposite direction of the normal of the visible triangle.
	*/
	Float3ID getTriangleNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.tnc",mName.c_str());return (const char*)buffer;}
	/*triangle normal x value*/
	FloatID getTriangleNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.tnc.tnx",mName.c_str());return (const char*)buffer;}
	/*triangle normal y value*/
	FloatID getTriangleNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.tnc.tny",mName.c_str());return (const char*)buffer;}
	/*triangle normal z value*/
	FloatID getTriangleNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.tnc.tnz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Reflection Specular </b> controls the contribution of the
	specular component when dealing with reflection rays for ray
	tracing.  I.e., the specular contribution when seen as a
	mirror reflection.
	*/
	FloatID getReflectionSpecularity(){char buffer[4096];sprintf_s (buffer, "%s.rsp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Color</b> is the final output color generated by this node.
	If you are using this node as one of the layers in a Layered Shader,
	then you will need to connect this attribute to the Color input of
	the Layered Shader.
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*out color red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*out color green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*out color blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Transparency</b> is the final output transparency generated by this node.
	If you are using this node as one of the layers in a Layered Shader,
	then you will need to connect this attribute to the Transparency input
	of the Layered Shader.
	*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*out transparency red value*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*out transparency green value*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*out transparency blue value*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*
	Out Glow Color is the final output glow color from this node
	(if this node is glowing)
	*/
	Float3ID getOutGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.ogc",mName.c_str());return (const char*)buffer;}
	/*out glow color red value*/
	FloatID getOutGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogr",mName.c_str());return (const char*)buffer;}
	/*out glow color green value*/
	FloatID getOutGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogg",mName.c_str());return (const char*)buffer;}
	/*out glow color blue value*/
	FloatID getOutGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogb",mName.c_str());return (const char*)buffer;}
	/*surface intersection point in camera space*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*point camera x component*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.pc.px",mName.c_str());return (const char*)buffer;}
	/*point camera y component*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.pc.py",mName.c_str());return (const char*)buffer;}
	/*point camera z component*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.pc.pz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Normal Camera</b> represents the surface normals in the
	camera's space. (These are
	used to calculate shading.)<p/>To do Bump Mapping, connect the output of a bump
	node to this attribute.
	*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*normal camera x value*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*normal camera Y value*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*normal camera Z value*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*The sample (filter) size*/
	Float3ID getFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.fs",mName.c_str());return (const char*)buffer;}
	/*The X size of the filter (sample)*/
	FloatID getFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsx",mName.c_str());return (const char*)buffer;}
	/*The Y size of the filter (sample)*/
	FloatID getFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsy",mName.c_str());return (const char*)buffer;}
	/*The Z size of the filter (sample)*/
	FloatID getFilterSizeZ(){char buffer[4096];sprintf_s (buffer, "%s.fs.fsz",mName.c_str());return (const char*)buffer;}
	/*The matrix that takes world space to eye space*/
	FltMatrixID getMatrixWorldToEye(){char buffer[4096];sprintf_s (buffer, "%s.wte",mName.c_str());return (const char*)buffer;}
	/*The transform to go from eye to world space*/
	FltMatrixID getMatrixEyeToWorld(){char buffer[4096];sprintf_s (buffer, "%s.e2w",mName.c_str());return (const char*)buffer;}
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
	parts, when you do not want the background to show through them.
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
	<b>Time</b> is used to animate the Ocean texture.
	Typically this is connected to the node time1, which
	provides the normal scene time for most nodes.
	*/
	TimeID getTime(){char buffer[4096];sprintf_s (buffer, "%s.ti",mName.c_str());return (const char*)buffer;}
	/*
	<b>Scale</b> controls the defined size in meters that corresponds
	to the texture space 0-1 in UV( for default texture placement settings ).
	*/
	FloatID getScale(){char buffer[4096];sprintf_s (buffer, "%s.scl",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wind UV</b> controls the (average) direction that
	the waves will travel, simulating the effect
	of wind.  This is expressed as U and V values, in the
	UV texture space. Note: animating this parameter will
	cause unnatural motion, and should be avoided.
	*/
	Float2ID getWindUV(){char buffer[4096];sprintf_s (buffer, "%s.wi",mName.c_str());return (const char*)buffer;}
	/*The U component of the wind direction*/
	FloatID getWindU(){char buffer[4096];sprintf_s (buffer, "%s.wi.wiu",mName.c_str());return (const char*)buffer;}
	/*The V component of the wind direction*/
	FloatID getWindV(){char buffer[4096];sprintf_s (buffer, "%s.wi.wiv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Observer Speed</b> is useful when you do not want the waves
	to move transversely. It cancels out transverse wave motion by
	moving a simulated observer. This is similar to animating the
	uvOffset of the texture relative to the wind direction.
	When <b>Observer Speed</b> is 1.0 the primary waves will not
	appear to travel because the viewer is moving at the same speed as
	the waves. The secondary waves will still move relative to the
	primary ones.
	*/
	FloatID getObserverSpeed(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*
	<b>WaveDirSpread</b> determines the variance in wave direction with
	respect to the wind direction. If it is zero, then all waves
	travel in the same direction. If it is one, then waves will travel
	in random directions. Inconsistency of the wind
	direction along with other effects like wave refraction tend
	to cause a natural variation in wave direction.
	*/
	FloatID getWaveDirSpread(){char buffer[4096];sprintf_s (buffer, "%s.wd",mName.c_str());return (const char*)buffer;}
	/*
	<b>NumFrequencies</b> controls the number of interpolated frequencies
	between <b>waveLengthMin</b> and <b>WaveLengthMax</b>
	Note: the higher this value, the longer this texture takes to compute.
	If this value is not an integer, then the number of created frequencies
	will be the rounded up value, but the amplitude for the extra
	frequency will be proportional to the remainder( ie .25 for 8.25 )
	This allows this parameter to be smoothly animated.
	*/
	FloatID getNumFrequencies(){char buffer[4096];sprintf_s (buffer, "%s.nf",mName.c_str());return (const char*)buffer;}
	/*
	<b>WaveLengthMin</b> controls the minimum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	FloatID getWaveLengthMin(){char buffer[4096];sprintf_s (buffer, "%s.wlm",mName.c_str());return (const char*)buffer;}
	/*
	<b>WaveLengthMax</b> controls the maximum length of waves in meters.
	This is either the upper or the lower wavelength bound.
	*/
	FloatID getWaveLengthMax(){char buffer[4096];sprintf_s (buffer, "%s.wlx",mName.c_str());return (const char*)buffer;}
	/*
	<b>WaveHeight</b> controls the size of waves relative
	to their wave length. If the value is 1.0, then the waves are half as
	tall as they are long. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	If the graph is a horizontal line, then all waves will
	exactly the same height proportional to their length.
	*/
	const WaveHeightID& getWaveHeight(size_t wh_i){char buffer[4096];sprintf_s (buffer, "%s.wh[%i]",mName.c_str(),wh_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getWaveHeight_Position(size_t wh_i){char buffer[4096];sprintf_s (buffer, "%s.wh[%i].whp",mName.c_str(),wh_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getWaveHeight_FloatValue(size_t wh_i){char buffer[4096];sprintf_s (buffer, "%s.wh[%i].whfv",mName.c_str(),wh_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getWaveHeight_Interp(size_t wh_i){char buffer[4096];sprintf_s (buffer, "%s.wh[%i].whi",mName.c_str(),wh_i);return (const char*)buffer;}
	/*
	<b>WaveTurbulence</b> controls the amount of turbulence at different
	wave frequencies. For values of 1.0 the wave motion will be
	completely turbulent at the defined frequency. The left edge of the graph represents waves
	with the shortest wavelengths and the right edge represents waves with
	the longest wavelengths( as determined by <b>WaveLengthMin</b> and <b>waveLengthMax</b>)
	For each wave frequency, the turbulence wave component
	consists of multiple sine waves at that frequency.
	This is the most computationaly expensive attribute. Making it zero
	will speed up renders significantly, although it is important for
	simulations of stormy or windy water. The peaking parameter only
	affects the turbulent wave layer, so there will be no affect from
	the peaking parameter wherever this value is zero.
	*/
	const WaveTurbulenceID& getWaveTurbulence(size_t wtb_i){char buffer[4096];sprintf_s (buffer, "%s.wtb[%i]",mName.c_str(),wtb_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getWaveTurbulence_Position(size_t wtb_i){char buffer[4096];sprintf_s (buffer, "%s.wtb[%i].wtbp",mName.c_str(),wtb_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getWaveTurbulence_FloatValue(size_t wtb_i){char buffer[4096];sprintf_s (buffer, "%s.wtb[%i].wtbfv",mName.c_str(),wtb_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getWaveTurbulence_Interp(size_t wtb_i){char buffer[4096];sprintf_s (buffer, "%s.wtb[%i].wtbi",mName.c_str(),wtb_i);return (const char*)buffer;}
	/*
	<b>WavePeaking</b> controls the amount of crest formation for waves
	across the range of wave frequencies.
	This simulates a side to side sloshing of waves, as opposed to
	up-down motion. When this parameter is non-zero many more
	evaluations of the noise function are performed, and thus the
	computation speed will be affected. Also the waveTurbulence
	function must be non-zero for this parameter to have an effects,
	as it is only applied to the turbulent waves.
	*/
	const WavePeakingID& getWavePeaking(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i]",mName.c_str(),wp_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getWavePeaking_Position(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i].wpp",mName.c_str(),wp_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getWavePeaking_FloatValue(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i].wpfv",mName.c_str(),wp_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getWavePeaking_Interp(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i].wpi",mName.c_str(),wp_i);return (const char*)buffer;}
	/*
	<b>WaveHeightOffset</b> is a simple offset on the overall
	displacement of the ocean. When textured this is useful for adding
	custom waves and boat wakes.
	*/
	FloatID getWaveHeightOffset(){char buffer[4096];sprintf_s (buffer, "%s.who",mName.c_str());return (const char*)buffer;}
	/*
	<b>TroughShadowing</b> darkens the diffuse color in the wave troughs.
	This can simulate certain lighting conditions where wave peaks are
	brighter, scattering light. This works well when the wave color is
	in a blue-green range.
	*/
	FloatID getTroughShadowing(){char buffer[4096];sprintf_s (buffer, "%s.tsh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Foam Color</b> determines the color of the foam layer.
	Part of the simulated foam may be considered submerged, in
	which case the color is blended with the material color.
	*/
	Float3ID getFoamColor(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*foamColor red value*/
	FloatID getFoamColorR(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcr",mName.c_str());return (const char*)buffer;}
	/*foamColor green value*/
	FloatID getFoamColorG(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcg",mName.c_str());return (const char*)buffer;}
	/*foamColor blue value*/
	FloatID getFoamColorB(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>FoamEmission</b> Controls density of foam generated above
	the foam threshold. The foam value is output to the outFoam
	attribute, which can be used to define opacity of a layered
	foam shader.
	*/
	FloatID getFoamEmission(){char buffer[4096];sprintf_s (buffer, "%s.fme",mName.c_str());return (const char*)buffer;}
	/*
	<b>FoamThreshold</b> Controls the wave amplitude required
	to generate foam as well as how long the foam lasts.
	*/
	FloatID getFoamThreshold(){char buffer[4096];sprintf_s (buffer, "%s.fmt",mName.c_str());return (const char*)buffer;}
	/*
	<b>FoamOffset</b> simply adds a uniform foam everywhere.
	It is useful when one needs to add a custom foam texture.
	*/
	FloatID getFoamOffset(){char buffer[4096];sprintf_s (buffer, "%s.fmo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Foam</b> is the output foam density value
	computed by the texture.  Use this value to control
	the density of a layered foam shader. If applied
	to transparency, the value should be first inverted.
	*/
	FloatID getOutFoam(){char buffer[4096];sprintf_s (buffer, "%s.ofm",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Displacement</b> is the relative output height of the
	waves computed by the shader. The value of zero represents sealevel.
	It should typically be plugged into
	the displacement shader.
	*/
	FloatID getDisplacement(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bump Blur</b> determines the separation of samples(relative to
	the smallest wavelength) used in
	computing the bumped normal for shading. Larger values have the
	effect of making small waves and peaks smoother.
	*/
	FloatID getBumpBlur(){char buffer[4096];sprintf_s (buffer, "%s.bbl",mName.c_str());return (const char*)buffer;}
	/*
	<b>Horizon Filter</b> smooths the ocean near the horizon so that lower
	antialiasing levels may be used. This help avoids chatter along the horizon.
	The bump blur is increased for oblique distant samples.
	*/
	FloatID getHorizonFilter(){char buffer[4096];sprintf_s (buffer, "%s.hft",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wave Speed</b> determines how fast waves move.
	It scales the input time used to determine
	wave movement. At the default value of 1.0 it creates
	the correct speeds for open ocean waves at the scale
	determined by the Maya units and the oceanShader scale parameter.
	Thus if the scale is 10 and the wave speed 1, 1 unit will
	represent 10 meters and the waves should move at the correct speed.
	To freeze the waves make the speed zero. If you wish the speed
	to change over time this parameter will not work. One needs to
	change the animation on the time attribute instead.
	*/
	FloatID getWaveSpeed(){char buffer[4096];sprintf_s (buffer, "%s.wvs",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.rpc",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getRefPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getRefPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getRefPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcz",mName.c_str());return (const char*)buffer;}
	/*
	Enable refraction blur by shooting more refraction rays.
	Blurry refractions require supersampling
	because a ray's direction is not exactly determined anymore.
	It may deviate (randomly) from the perfect specular direction,
	within the bounds specified by <b>miRefractionBlur</b> (in angle).
	A value of zero implies a perfectly specular interaction,
	a value of 90 a perfectly diffuse reflection or refraction.
	Values of 10 to 30 are a good starting point
	*/
	FloatID getMiRefractionBlur(){char buffer[4096];sprintf_s (buffer, "%s.mirfb",mName.c_str());return (const char*)buffer;}
	/*
	Number of refraction rays to use for blurring.
	<b>miRefractionRays</b> specifies number of rays to use
	to sample the random deviation. In general more rays are required
	for more blurry reflections or refractions.
	Other sampling parameters also affect this setting:
	per-object samples and the Render Settings sample setting supersample in image space.
	If you increase any of these two settings,
	you may be able to reduce the number of rays without loss of quality,
	but significant performance gain.
	*/
	ShortID getMiRefractionRays(){char buffer[4096];sprintf_s (buffer, "%s.mirfr",mName.c_str());return (const char*)buffer;}
	/*
	Enable reflection blur by shooting more reflection rays.
	Blurry reflections require supersampling
	because a ray's direction is not exactly determined anymore.
	It may deviate (randomly) from the perfect specular direction,
	within the bounds specified by <b>miReflectionBlur</b> (in angle).
	A value of zero implies a perfectly specular interaction,
	a value of 90 a perfectly diffuse reflection or refraction.
	Values of 10 to 30 are a good starting point
	*/
	FloatID getMiReflectionBlur(){char buffer[4096];sprintf_s (buffer, "%s.mircb",mName.c_str());return (const char*)buffer;}
	/*
	Number of reflection rays to use for blurring.
	<b>miReflectionRays</b> specifies number of rays to use
	to sample the random deviation. In general more rays are required
	for more blurry reflections or refractions.
	Other sampling parameters also affect this setting:
	per-object samples and the Render Settings sample setting supersample in image space.
	If you increase any of these two settings,
	you may be able to reduce the number of rays without loss of quality,
	but significant performance gain.
	*/
	ShortID getMiReflectionRays(){char buffer[4096];sprintf_s (buffer, "%s.mircr",mName.c_str());return (const char*)buffer;}
	/*Port to map indirect illumination from a texture instead of computing it.*/
	Float3ID getMiIrradiance(){char buffer[4096];sprintf_s (buffer, "%s.mii",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiIrradianceR(){char buffer[4096];sprintf_s (buffer, "%s.mii.miir",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiIrradianceG(){char buffer[4096];sprintf_s (buffer, "%s.mii.miig",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiIrradianceB(){char buffer[4096];sprintf_s (buffer, "%s.mii.miib",mName.c_str());return (const char*)buffer;}
	/*Scale the indirect illumination by this color before applying.*/
	Float3ID getMiIrradianceColor(){char buffer[4096];sprintf_s (buffer, "%s.miic",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getMiIrradianceColorR(){char buffer[4096];sprintf_s (buffer, "%s.miic.miicr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getMiIrradianceColorG(){char buffer[4096];sprintf_s (buffer, "%s.miic.miicg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getMiIrradianceColorB(){char buffer[4096];sprintf_s (buffer, "%s.miic.miicb",mName.c_str());return (const char*)buffer;}
	/*
	Derive photon shader parameters from the shading node if enabled,
	otherwise use explicit mental ray attributes.
	*/
	BoolID getMiDeriveFromMaya(){char buffer[4096];sprintf_s (buffer, "%s.mifm",mName.c_str());return (const char*)buffer;}
	/*Photon shader shinyness parameter to control glossy reflection and refraction.*/
	FloatID getMiShinyness(){char buffer[4096];sprintf_s (buffer, "%s.mis",mName.c_str());return (const char*)buffer;}
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
	OceanShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OCEANSHADER_H__
