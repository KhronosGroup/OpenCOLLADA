/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RAMPSHADER_H__
#define __MayaDM_RAMPSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Use a <b>RampShader</b> for extra control over the way color changes
  with light and view angle. One can simulate a variety of exotic materials
  as well as tweeking more standard shading in subtle ways.
        <p/>
        In the table below, important attributes have their names indicated
  in <b>bold</b> in the description column.
*/
class RampShader : public DependNode
{
public:
	/*The basic color of the surface.*/
	struct Color{
		float color_Position;
		float3 color_Color;
		unsigned int color_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", color_Position);
			color_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", color_Interp);
		}
	};
	/*
	<b>Transparency</b> controls how transparent or opaque the material is.
	Black means completely opaque (the default), and white means completely
	transparent.  You can set it to any level in between.  You can
	also control transparency on a per-channel basis;  for example, if
	you set this to red, then only the red channel will be transparent.
	<p/><i>Note:</i> If this material has specular highlights the transparency
	setting will <i>not</i> affect the highlights.  So if you are
	trying to make an object disappear by animating the transparency
	attribute, you may also have to animate the specular highlight
	attributes.
	If there is more than one index in the ramp then the transparency
	value will vary with the facing angle.
	*/
	struct Transparency{
		float transparency_Position;
		float3 transparency_Color;
		unsigned int transparency_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", transparency_Position);
			transparency_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", transparency_Interp);
		}
	};
	/*
	<b>Incandescence</b> makes a material appear opalescent, as if it were
	emmitting light itself, such as lava or a phosphorescent moss.  A
	slight touch of incandescence on vegetable matter, for example,
	can make the vegetation look alive.<p/>
	By default, the color is black, which has no effect on the surface.
	<p/><i>Note:</i> although incandescence makes a surface appear to
	glow, it does not actually act as a source of light in the scene.
	If there is more than one index in the ramp then the incandescence
	value will vary with the facing angle.
	<p/>See also Glow Intensity.
	*/
	struct Incandescence{
		float incandescence_Position;
		float3 incandescence_Color;
		unsigned int incandescence_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", incandescence_Position);
			incandescence_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", incandescence_Interp);
		}
	};
	/*
	<b>Specular Rolloff</b> controls the ability of a surface to
	reflect its surroundings (the environment, other objects, or
	the Reflection Map, if any), when viewed at oblique angles.
	The horizontal dimension of the graph represents the brightness
	of specular reflections and the horizontal represents the facing
	angle with the view.
	<p/>
	Specular Rolloff does not affect the reflections produced
	when you render using Ray Tracing.
	<p/>
	<i>Tip:</i> to get a "wet" look (such as wet paint), make the
	edges more reflective.
	*/
	struct SpecularRollOff{
		float specularRollOff_Position;
		float specularRollOff_FloatValue;
		unsigned int specularRollOff_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", specularRollOff_Position);
			fprintf_s(file,"%f ", specularRollOff_FloatValue);
			fprintf_s(file,"%i", specularRollOff_Interp);
		}
	};
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
	If there is more than one ramp index the specular color will vary
	based on the brightness of the highlight.
	*/
	struct SpecularColor{
		float specularColor_Position;
		float3 specularColor_Color;
		unsigned int specularColor_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", specularColor_Position);
			specularColor_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", specularColor_Interp);
		}
	};
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
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
	struct Reflectivity{
		float reflectivity_Position;
		float reflectivity_FloatValue;
		unsigned int reflectivity_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", reflectivity_Position);
			fprintf_s(file,"%f ", reflectivity_FloatValue);
			fprintf_s(file,"%i", reflectivity_Interp);
		}
	};
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
public:
	RampShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "rampShader"){}
	virtual ~RampShader(){}
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
	void setRefractiveIndex(float rfi){if(rfi == 1.0) return; fprintf_s(mFile, "setAttr \".rfi\" %f;\n", rfi);}
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
	void setDiffuse(float dc){if(dc == 0.8) return; fprintf_s(mFile, "setAttr \".dc\" %f;\n", dc);}
	/*
	<b>Diffuse</b> controls how much of the light in the scene
	is scattered from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.
	*/
	void setDiffuse(const FloatID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*
	<b>Forward Scatter</b> controls how much of the light is diffusely scattered
	along the light direction. At a value of 0 the light is scattered
	uniformly in a lambertian fashion, which is good for most surfaces.
	Some materials, such as skin, scatter the light in a more
	along the forward direction so values larger than zero may help.
	in simulating these materials.
	*/
	void setForwardScatter(float fsc){if(fsc == 0.0) return; fprintf_s(mFile, "setAttr \".fsc\" %f;\n", fsc);}
	/*
	<b>Forward Scatter</b> controls how much of the light is diffusely scattered
	along the light direction. At a value of 0 the light is scattered
	uniformly in a lambertian fashion, which is good for most surfaces.
	Some materials, such as skin, scatter the light in a more
	along the forward direction so values larger than zero may help.
	in simulating these materials.
	*/
	void setForwardScatter(const FloatID& fsc){fprintf_s(mFile,"connectAttr \"");fsc.write(mFile);fprintf_s(mFile,"\" \"%s.fsc\";\n",mName.c_str());}
	/*The basic color of the surface.*/
	void setColor(size_t clr_i,const Color& clr){fprintf_s(mFile, "setAttr \".clr[%i]\" ",clr_i);clr.write(mFile);fprintf_s(mFile,";\n");}
	/*The basic color of the surface.*/
	void setColor(size_t clr_i,const ColorID& clr){fprintf_s(mFile,"connectAttr \"");clr.write(mFile);fprintf_s(mFile,"\" \"%s.clr[%i]\";\n",mName.c_str(),clr_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColor_Position(size_t clr_i,float clrp){if(clrp == 0.0) return; fprintf_s(mFile, "setAttr \".clr[%i].clrp\" %f;\n", clr_i,clrp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColor_Position(size_t clr_i,const FloatID& clrp){fprintf_s(mFile,"connectAttr \"");clrp.write(mFile);fprintf_s(mFile,"\" \"%s.clr[%i].clrp\";\n",mName.c_str(),clr_i);}
	/*Ramp color at the sibling position*/
	void setColor_Color(size_t clr_i,const float3& clrc){fprintf_s(mFile, "setAttr \".clr[%i].clrc\" -type \"float3\" ",clr_i);clrc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setColor_Color(size_t clr_i,const Float3ID& clrc){fprintf_s(mFile,"connectAttr \"");clrc.write(mFile);fprintf_s(mFile,"\" \"%s.clr[%i].clrc\";\n",mName.c_str(),clr_i);}
	/*Ramp red channel value at the sibling position*/
	void setColor_ColorR(size_t clr_i,float clrcr){if(clrcr == 0.0) return; fprintf_s(mFile, "setAttr \".clr[%i].clrc.clrcr\" %f;\n", clr_i,clrcr);}
	/*Ramp red channel value at the sibling position*/
	void setColor_ColorR(size_t clr_i,const FloatID& clrcr){fprintf_s(mFile,"connectAttr \"");clrcr.write(mFile);fprintf_s(mFile,"\" \"%s.clr[%i].clrc.clrcr\";\n",mName.c_str(),clr_i);}
	/*Ramp green channel value at the sibling position*/
	void setColor_ColorG(size_t clr_i,float clrcg){if(clrcg == 0.0) return; fprintf_s(mFile, "setAttr \".clr[%i].clrc.clrcg\" %f;\n", clr_i,clrcg);}
	/*Ramp green channel value at the sibling position*/
	void setColor_ColorG(size_t clr_i,const FloatID& clrcg){fprintf_s(mFile,"connectAttr \"");clrcg.write(mFile);fprintf_s(mFile,"\" \"%s.clr[%i].clrc.clrcg\";\n",mName.c_str(),clr_i);}
	/*Ramp blue channel value at the sibling position*/
	void setColor_ColorB(size_t clr_i,float clrcb){if(clrcb == 0.0) return; fprintf_s(mFile, "setAttr \".clr[%i].clrc.clrcb\" %f;\n", clr_i,clrcb);}
	/*Ramp blue channel value at the sibling position*/
	void setColor_ColorB(size_t clr_i,const FloatID& clrcb){fprintf_s(mFile,"connectAttr \"");clrcb.write(mFile);fprintf_s(mFile,"\" \"%s.clr[%i].clrc.clrcb\";\n",mName.c_str(),clr_i);}
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
	void setColor_Interp(size_t clr_i,unsigned int clri){if(clri == 0) return; fprintf_s(mFile, "setAttr \".clr[%i].clri\" %i;\n", clr_i,clri);}
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
	void setColor_Interp(size_t clr_i,const UnsignedintID& clri){fprintf_s(mFile,"connectAttr \"");clri.write(mFile);fprintf_s(mFile,"\" \"%s.clr[%i].clri\";\n",mName.c_str(),clr_i);}
	/*
	This determines the input to the color ramp.
	<b>Constant:</b> only the start value of the ramp is used.
	<b>Light Angle:</b> the position along the ramp is determined by the
	angle of the light with the surface normal.
	<b>Facing Angle:</b> the position along the ramp is determined by the
	angle of the surface with the view direction.
	<b>Brightness:</b> the total light brightness is used to index the
	ramp. This can be used to create cartoon style shading by using a
	ramp with stepped values.
	<b>Normalized Brightness:</b> this is similar to brightness, but the
	total light is normalized so that changing the overall light intensity
	will not affect the shading. However changing the intensity of one light
	relative to another light will shift the shaded position.
	This may be convenient when dealing with toon shading where one
	may want the color band spacing to be relatively fixed even though
	the lighting setup may be complex.
	*/
	void setColorInput(unsigned int cin){if(cin == 0) return; fprintf_s(mFile, "setAttr \".cin\" %i;\n", cin);}
	/*
	This determines the input to the color ramp.
	<b>Constant:</b> only the start value of the ramp is used.
	<b>Light Angle:</b> the position along the ramp is determined by the
	angle of the light with the surface normal.
	<b>Facing Angle:</b> the position along the ramp is determined by the
	angle of the surface with the view direction.
	<b>Brightness:</b> the total light brightness is used to index the
	ramp. This can be used to create cartoon style shading by using a
	ramp with stepped values.
	<b>Normalized Brightness:</b> this is similar to brightness, but the
	total light is normalized so that changing the overall light intensity
	will not affect the shading. However changing the intensity of one light
	relative to another light will shift the shaded position.
	This may be convenient when dealing with toon shading where one
	may want the color band spacing to be relatively fixed even though
	the lighting setup may be complex.
	*/
	void setColorInput(const UnsignedintID& cin){fprintf_s(mFile,"connectAttr \"");cin.write(mFile);fprintf_s(mFile,"\" \"%s.cin\";\n",mName.c_str());}
	/*
	This determines how color is computed in shadow regions.
	It is primarily useful for a toon style shading.
	<b>Normal:</b> The shadow is computed as for a standard shader.
	If the color input is brightness, then the brightness value used
	to index the color ramp includes the effect of shadowing.
	<b>Shaded Color:</b> the color in shadow regions
	uses the shadow color values. One will see the effects of soft shadows
	as well as the effects of partial shadow occlusion when illuminated by
	multiple lights.
	<b>Constant Color:</b> the color in shadow regions
	uses the shadow color values. The shadow will be a fixed color. Shadows will
	appear hard edged, and this color will be constant across regions of both partial
	and full shadowing.
	*/
	void setShadowMode(unsigned int smd){if(smd == 0) return; fprintf_s(mFile, "setAttr \".smd\" %i;\n", smd);}
	/*
	This determines how color is computed in shadow regions.
	It is primarily useful for a toon style shading.
	<b>Normal:</b> The shadow is computed as for a standard shader.
	If the color input is brightness, then the brightness value used
	to index the color ramp includes the effect of shadowing.
	<b>Shaded Color:</b> the color in shadow regions
	uses the shadow color values. One will see the effects of soft shadows
	as well as the effects of partial shadow occlusion when illuminated by
	multiple lights.
	<b>Constant Color:</b> the color in shadow regions
	uses the shadow color values. The shadow will be a fixed color. Shadows will
	appear hard edged, and this color will be constant across regions of both partial
	and full shadowing.
	*/
	void setShadowMode(const UnsignedintID& smd){fprintf_s(mFile,"connectAttr \"");smd.write(mFile);fprintf_s(mFile,"\" \"%s.smd\";\n",mName.c_str());}
	/*
	<b>Shadow Color</b> is only used when shadow mode is not set to normal.
	How it is applied is dependant on the shadow mode used. Normally shadow
	color arises from the interaction of the surface color and the remaining
	light when some lights are blocked from illuminating a region. For purposes
	of toon shading it can be useful to directly specify the color in these
	regions.
	*/
	void setShadowColor(const float3& shc){fprintf_s(mFile, "setAttr \".shc\" -type \"float3\" ");shc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Shadow Color</b> is only used when shadow mode is not set to normal.
	How it is applied is dependant on the shadow mode used. Normally shadow
	color arises from the interaction of the surface color and the remaining
	light when some lights are blocked from illuminating a region. For purposes
	of toon shading it can be useful to directly specify the color in these
	regions.
	*/
	void setShadowColor(const Float3ID& shc){fprintf_s(mFile,"connectAttr \"");shc.write(mFile);fprintf_s(mFile,"\" \"%s.shc\";\n",mName.c_str());}
	/*shadow color red value*/
	void setShadowColorR(float shr){if(shr == 0.0) return; fprintf_s(mFile, "setAttr \".shc.shr\" %f;\n", shr);}
	/*shadow color red value*/
	void setShadowColorR(const FloatID& shr){fprintf_s(mFile,"connectAttr \"");shr.write(mFile);fprintf_s(mFile,"\" \"%s.shc.shr\";\n",mName.c_str());}
	/*shadow color green value*/
	void setShadowColorG(float shg){if(shg == 0.0) return; fprintf_s(mFile, "setAttr \".shc.shg\" %f;\n", shg);}
	/*shadow color green value*/
	void setShadowColorG(const FloatID& shg){fprintf_s(mFile,"connectAttr \"");shg.write(mFile);fprintf_s(mFile,"\" \"%s.shc.shg\";\n",mName.c_str());}
	/*shadow color blue value*/
	void setShadowColorB(float shb){if(shb == 0.0) return; fprintf_s(mFile, "setAttr \".shc.shb\" %f;\n", shb);}
	/*shadow color blue value*/
	void setShadowColorB(const FloatID& shb){fprintf_s(mFile,"connectAttr \"");shb.write(mFile);fprintf_s(mFile,"\" \"%s.shc.shb\";\n",mName.c_str());}
	/*
	<b>Shadow Threshold</b><p/>
	This determines how great a proportion of the incoming light must
	be blocked for a shadow to appear. It requires that the shadow mode
	be set to shaded color or constant color. This is primarily of use
	for toon style shading.
	*/
	void setShadowThreshold(float sht){if(sht == 0.0) return; fprintf_s(mFile, "setAttr \".sht\" %f;\n", sht);}
	/*
	<b>Shadow Threshold</b><p/>
	This determines how great a proportion of the incoming light must
	be blocked for a shadow to appear. It requires that the shadow mode
	be set to shaded color or constant color. This is primarily of use
	for toon style shading.
	*/
	void setShadowThreshold(const FloatID& sht){fprintf_s(mFile,"connectAttr \"");sht.write(mFile);fprintf_s(mFile,"\" \"%s.sht\";\n",mName.c_str());}
	/*
	<b>Transparency</b> controls how transparent or opaque the material is.
	Black means completely opaque (the default), and white means completely
	transparent.  You can set it to any level in between.  You can
	also control transparency on a per-channel basis;  for example, if
	you set this to red, then only the red channel will be transparent.
	<p/><i>Note:</i> If this material has specular highlights the transparency
	setting will <i>not</i> affect the highlights.  So if you are
	trying to make an object disappear by animating the transparency
	attribute, you may also have to animate the specular highlight
	attributes.
	If there is more than one index in the ramp then the transparency
	value will vary with the facing angle.
	*/
	void setTransparency(size_t it_i,const Transparency& it){fprintf_s(mFile, "setAttr \".it[%i]\" ",it_i);it.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Transparency</b> controls how transparent or opaque the material is.
	Black means completely opaque (the default), and white means completely
	transparent.  You can set it to any level in between.  You can
	also control transparency on a per-channel basis;  for example, if
	you set this to red, then only the red channel will be transparent.
	<p/><i>Note:</i> If this material has specular highlights the transparency
	setting will <i>not</i> affect the highlights.  So if you are
	trying to make an object disappear by animating the transparency
	attribute, you may also have to animate the specular highlight
	attributes.
	If there is more than one index in the ramp then the transparency
	value will vary with the facing angle.
	*/
	void setTransparency(size_t it_i,const TransparencyID& it){fprintf_s(mFile,"connectAttr \"");it.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i]\";\n",mName.c_str(),it_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setTransparency_Position(size_t it_i,float itp){if(itp == 0.0) return; fprintf_s(mFile, "setAttr \".it[%i].itp\" %f;\n", it_i,itp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setTransparency_Position(size_t it_i,const FloatID& itp){fprintf_s(mFile,"connectAttr \"");itp.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itp\";\n",mName.c_str(),it_i);}
	/*Ramp color at the sibling position*/
	void setTransparency_Color(size_t it_i,const float3& itc){fprintf_s(mFile, "setAttr \".it[%i].itc\" -type \"float3\" ",it_i);itc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setTransparency_Color(size_t it_i,const Float3ID& itc){fprintf_s(mFile,"connectAttr \"");itc.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itc\";\n",mName.c_str(),it_i);}
	/*Ramp red channel value at the sibling position*/
	void setTransparency_ColorR(size_t it_i,float itcr){if(itcr == 0.0) return; fprintf_s(mFile, "setAttr \".it[%i].itc.itcr\" %f;\n", it_i,itcr);}
	/*Ramp red channel value at the sibling position*/
	void setTransparency_ColorR(size_t it_i,const FloatID& itcr){fprintf_s(mFile,"connectAttr \"");itcr.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itc.itcr\";\n",mName.c_str(),it_i);}
	/*Ramp green channel value at the sibling position*/
	void setTransparency_ColorG(size_t it_i,float itcg){if(itcg == 0.0) return; fprintf_s(mFile, "setAttr \".it[%i].itc.itcg\" %f;\n", it_i,itcg);}
	/*Ramp green channel value at the sibling position*/
	void setTransparency_ColorG(size_t it_i,const FloatID& itcg){fprintf_s(mFile,"connectAttr \"");itcg.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itc.itcg\";\n",mName.c_str(),it_i);}
	/*Ramp blue channel value at the sibling position*/
	void setTransparency_ColorB(size_t it_i,float itcb){if(itcb == 0.0) return; fprintf_s(mFile, "setAttr \".it[%i].itc.itcb\" %f;\n", it_i,itcb);}
	/*Ramp blue channel value at the sibling position*/
	void setTransparency_ColorB(size_t it_i,const FloatID& itcb){fprintf_s(mFile,"connectAttr \"");itcb.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].itc.itcb\";\n",mName.c_str(),it_i);}
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
	void setTransparency_Interp(size_t it_i,unsigned int iti){if(iti == 0) return; fprintf_s(mFile, "setAttr \".it[%i].iti\" %i;\n", it_i,iti);}
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
	void setTransparency_Interp(size_t it_i,const UnsignedintID& iti){fprintf_s(mFile,"connectAttr \"");iti.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i].iti\";\n",mName.c_str(),it_i);}
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
	If there is more than one index in the ramp then the incandescence
	value will vary with the facing angle.
	<p/>See also Glow Intensity.
	*/
	void setIncandescence(size_t ic_i,const Incandescence& ic){fprintf_s(mFile, "setAttr \".ic[%i]\" ",ic_i);ic.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Incandescence</b> makes a material appear opalescent, as if it were
	emmitting light itself, such as lava or a phosphorescent moss.  A
	slight touch of incandescence on vegetable matter, for example,
	can make the vegetation look alive.<p/>
	By default, the color is black, which has no effect on the surface.
	<p/><i>Note:</i> although incandescence makes a surface appear to
	glow, it does not actually act as a source of light in the scene.
	If there is more than one index in the ramp then the incandescence
	value will vary with the facing angle.
	<p/>See also Glow Intensity.
	*/
	void setIncandescence(size_t ic_i,const IncandescenceID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i]\";\n",mName.c_str(),ic_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setIncandescence_Position(size_t ic_i,float icp){if(icp == 0.0) return; fprintf_s(mFile, "setAttr \".ic[%i].icp\" %f;\n", ic_i,icp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setIncandescence_Position(size_t ic_i,const FloatID& icp){fprintf_s(mFile,"connectAttr \"");icp.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i].icp\";\n",mName.c_str(),ic_i);}
	/*Ramp color at the sibling position*/
	void setIncandescence_Color(size_t ic_i,const float3& icc){fprintf_s(mFile, "setAttr \".ic[%i].icc\" -type \"float3\" ",ic_i);icc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setIncandescence_Color(size_t ic_i,const Float3ID& icc){fprintf_s(mFile,"connectAttr \"");icc.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i].icc\";\n",mName.c_str(),ic_i);}
	/*Ramp red channel value at the sibling position*/
	void setIncandescence_ColorR(size_t ic_i,float iccr){if(iccr == 0.0) return; fprintf_s(mFile, "setAttr \".ic[%i].icc.iccr\" %f;\n", ic_i,iccr);}
	/*Ramp red channel value at the sibling position*/
	void setIncandescence_ColorR(size_t ic_i,const FloatID& iccr){fprintf_s(mFile,"connectAttr \"");iccr.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i].icc.iccr\";\n",mName.c_str(),ic_i);}
	/*Ramp green channel value at the sibling position*/
	void setIncandescence_ColorG(size_t ic_i,float iccg){if(iccg == 0.0) return; fprintf_s(mFile, "setAttr \".ic[%i].icc.iccg\" %f;\n", ic_i,iccg);}
	/*Ramp green channel value at the sibling position*/
	void setIncandescence_ColorG(size_t ic_i,const FloatID& iccg){fprintf_s(mFile,"connectAttr \"");iccg.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i].icc.iccg\";\n",mName.c_str(),ic_i);}
	/*Ramp blue channel value at the sibling position*/
	void setIncandescence_ColorB(size_t ic_i,float iccb){if(iccb == 0.0) return; fprintf_s(mFile, "setAttr \".ic[%i].icc.iccb\" %f;\n", ic_i,iccb);}
	/*Ramp blue channel value at the sibling position*/
	void setIncandescence_ColorB(size_t ic_i,const FloatID& iccb){fprintf_s(mFile,"connectAttr \"");iccb.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i].icc.iccb\";\n",mName.c_str(),ic_i);}
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
	void setIncandescence_Interp(size_t ic_i,unsigned int ici){if(ici == 0) return; fprintf_s(mFile, "setAttr \".ic[%i].ici\" %i;\n", ic_i,ici);}
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
	void setIncandescence_Interp(size_t ic_i,const UnsignedintID& ici){fprintf_s(mFile,"connectAttr \"");ici.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i].ici\";\n",mName.c_str(),ic_i);}
	/*
	<b>Translucence</b> simulates the way light diffusely penetrates
	through translucent objects.  This means that when light shines
	on one side of the object, the other side is partially illuminated.
	This can be used for effects such as clouds, fur, hair, marble,
	jade, wax, paper, leaves, etc.
	<p/>If this is set to 0 (the default) then no light shows through
	the object.  If this is set to 1, all the light shows through.
	*/
	void setTranslucence(float tc){if(tc == 0.0) return; fprintf_s(mFile, "setAttr \".tc\" %f;\n", tc);}
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
	void setTranslucenceDepth(float trsd){if(trsd == 0.05) return; fprintf_s(mFile, "setAttr \".trsd\" %f;\n", trsd);}
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
	If <b>Hide Source</b> is turned on (and Glow Intensity is not zero), then the
	glowing object will be hidden, but its glowing halo will
	still be rendered in the scene (during post-processing).  Use this
	attribute to produce gas effects, or interesting ghosts.
	*/
	void setHideSource(bool hs){if(hs == false) return; fprintf_s(mFile, "setAttr \".hs\" %i;\n", hs);}
	/*
	If <b>Hide Source</b> is turned on (and Glow Intensity is not zero), then the
	glowing object will be hidden, but its glowing halo will
	still be rendered in the scene (during post-processing).  Use this
	attribute to produce gas effects, or interesting ghosts.
	*/
	void setHideSource(const BoolID& hs){fprintf_s(mFile,"connectAttr \"");hs.write(mFile);fprintf_s(mFile,"\" \"%s.hs\";\n",mName.c_str());}
	/*
	<b>Surface Thickness</b><p/>
	(aka Studio special effect "Surface Width" - raytracing only)<p/>
	The simulated thickness (in world space units) of transparent
	objects that are made from single surfaces (for example, a plane
	or face). Using Surface Width does not produce the same results
	as building a surface with actual thickness. However, the effect
	works well when the edges of the surface are not visible (for example,
	closed surfaces, or bounded shapes like a car windshield).
	*/
	void setSurfaceThickness(float thik){if(thik == 0.0) return; fprintf_s(mFile, "setAttr \".thik\" %f;\n", thik);}
	/*
	<b>Surface Thickness</b><p/>
	(aka Studio special effect "Surface Width" - raytracing only)<p/>
	The simulated thickness (in world space units) of transparent
	objects that are made from single surfaces (for example, a plane
	or face). Using Surface Width does not produce the same results
	as building a surface with actual thickness. However, the effect
	works well when the edges of the surface are not visible (for example,
	closed surfaces, or bounded shapes like a car windshield).
	*/
	void setSurfaceThickness(const FloatID& thik){fprintf_s(mFile,"connectAttr \"");thik.write(mFile);fprintf_s(mFile,"\" \"%s.thik\";\n",mName.c_str());}
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
	<b>Transparency Depth</b> (Studio special effect - raytracing only)<p/>
	This should be used for backwards compatability when rendering
	data from Studio - Maya users should use Absorbance instead.<p/>
	The distance (in world units) camera rays can travel after
	passing through a transparent surface. Useful for effects
	like under water.  If the Transp. Depth value is 0, camera
	rays can travel an infinite distance, and all objects
	behind the transparent surface are visible no matter how far
	away they are. For non-zero values, as a camera ray
	reaches the distance of the Transp. Depth value, its color
	becomes the surface color. Only objects near the transparent
	surface (less than the Transp. Depth value) are visible
	through the surface. Objects close to the surface are more
	visible (the surface is more transparent in those areas)
	and objects further away are less visible (the surface is
	less transparent in those areas). Objects beyond this depth
	are not visible at all (the surface is opaque in those areas).
	*/
	void setTransparencyDepth(float trdp){if(trdp == 0.0) return; fprintf_s(mFile, "setAttr \".trdp\" %f;\n", trdp);}
	/*
	<b>Transparency Depth</b> (Studio special effect - raytracing only)<p/>
	This should be used for backwards compatability when rendering
	data from Studio - Maya users should use Absorbance instead.<p/>
	The distance (in world units) camera rays can travel after
	passing through a transparent surface. Useful for effects
	like under water.  If the Transp. Depth value is 0, camera
	rays can travel an infinite distance, and all objects
	behind the transparent surface are visible no matter how far
	away they are. For non-zero values, as a camera ray
	reaches the distance of the Transp. Depth value, its color
	becomes the surface color. Only objects near the transparent
	surface (less than the Transp. Depth value) are visible
	through the surface. Objects close to the surface are more
	visible (the surface is more transparent in those areas)
	and objects further away are less visible (the surface is
	less transparent in those areas). Objects beyond this depth
	are not visible at all (the surface is opaque in those areas).
	*/
	void setTransparencyDepth(const FloatID& trdp){fprintf_s(mFile,"connectAttr \"");trdp.write(mFile);fprintf_s(mFile,"\" \"%s.trdp\";\n",mName.c_str());}
	/*
	<b>Light Absorbance</b> Transparent materials generally absorb some
	amount of the light which passes through them (Beer's Law).
	The more of the material the light shines through, the less of
	the light gets through.  This attribute describes how light
	absorbing the material is (raytracing only). A material with
	an absorbance of 0.0 will transmitt completely.  The higher
	the absorbance, the less light will pass through.
	*/
	void setLightAbsorbance(float absb){if(absb == 0.0) return; fprintf_s(mFile, "setAttr \".absb\" %f;\n", absb);}
	/*
	<b>Light Absorbance</b> Transparent materials generally absorb some
	amount of the light which passes through them (Beer's Law).
	The more of the material the light shines through, the less of
	the light gets through.  This attribute describes how light
	absorbing the material is (raytracing only). A material with
	an absorbance of 0.0 will transmitt completely.  The higher
	the absorbance, the less light will pass through.
	*/
	void setLightAbsorbance(const FloatID& absb){fprintf_s(mFile,"connectAttr \"");absb.write(mFile);fprintf_s(mFile,"\" \"%s.absb\";\n",mName.c_str());}
	/*
	<b>Chromatic Aberration</b> Causes different wavelengths of light
	to refract at different angles when passing through a transparent
	surface during raytracing.  Chromatic aberration only affects light
	rays as they pass through the second surface of a transparent object
	(that is, the first exit ray). For best results, make sure there are
	suitable objects in the background to be refracted.
	*/
	void setChromaticAberration(bool crab){if(crab == false) return; fprintf_s(mFile, "setAttr \".crab\" %i;\n", crab);}
	/*
	<b>Chromatic Aberration</b> Causes different wavelengths of light
	to refract at different angles when passing through a transparent
	surface during raytracing.  Chromatic aberration only affects light
	rays as they pass through the second surface of a transparent object
	(that is, the first exit ray). For best results, make sure there are
	suitable objects in the background to be refracted.
	*/
	void setChromaticAberration(const BoolID& crab){fprintf_s(mFile,"connectAttr \"");crab.write(mFile);fprintf_s(mFile,"\" \"%s.crab\";\n",mName.c_str());}
	/*
	<b>Eccentricity</b> controls how big your specular highlights
	(also called 'hot spots') will be.
	*/
	void setEccentricity(float ec){if(ec == 0.3) return; fprintf_s(mFile, "setAttr \".ec\" %f;\n", ec);}
	/*
	<b>Eccentricity</b> controls how big your specular highlights
	(also called 'hot spots') will be.
	*/
	void setEccentricity(const FloatID& ec){fprintf_s(mFile,"connectAttr \"");ec.write(mFile);fprintf_s(mFile,"\" \"%s.ec\";\n",mName.c_str());}
	/*
	<b>Specularity</b> controls how bright your specular highlights
	will be.  It is a simple multiplier of the specular color.
	*/
	void setSpecularity(float spl){if(spl == 0.3) return; fprintf_s(mFile, "setAttr \".spl\" %f;\n", spl);}
	/*
	<b>Specularity</b> controls how bright your specular highlights
	will be.  It is a simple multiplier of the specular color.
	*/
	void setSpecularity(const FloatID& spl){fprintf_s(mFile,"connectAttr \"");spl.write(mFile);fprintf_s(mFile,"\" \"%s.spl\";\n",mName.c_str());}
	/*
	<b>Specular Rolloff</b> controls the ability of a surface to
	reflect its surroundings (the environment, other objects, or
	the Reflection Map, if any), when viewed at oblique angles.
	The horizontal dimension of the graph represents the brightness
	of specular reflections and the horizontal represents the facing
	angle with the view.
	<p/>
	Specular Rolloff does not affect the reflections produced
	when you render using Ray Tracing.
	<p/>
	<i>Tip:</i> to get a "wet" look (such as wet paint), make the
	edges more reflective.
	*/
	void setSpecularRollOff(size_t sro_i,const SpecularRollOff& sro){fprintf_s(mFile, "setAttr \".sro[%i]\" ",sro_i);sro.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Specular Rolloff</b> controls the ability of a surface to
	reflect its surroundings (the environment, other objects, or
	the Reflection Map, if any), when viewed at oblique angles.
	The horizontal dimension of the graph represents the brightness
	of specular reflections and the horizontal represents the facing
	angle with the view.
	<p/>
	Specular Rolloff does not affect the reflections produced
	when you render using Ray Tracing.
	<p/>
	<i>Tip:</i> to get a "wet" look (such as wet paint), make the
	edges more reflective.
	*/
	void setSpecularRollOff(size_t sro_i,const SpecularRollOffID& sro){fprintf_s(mFile,"connectAttr \"");sro.write(mFile);fprintf_s(mFile,"\" \"%s.sro[%i]\";\n",mName.c_str(),sro_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setSpecularRollOff_Position(size_t sro_i,float srop){if(srop == 0.0) return; fprintf_s(mFile, "setAttr \".sro[%i].srop\" %f;\n", sro_i,srop);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setSpecularRollOff_Position(size_t sro_i,const FloatID& srop){fprintf_s(mFile,"connectAttr \"");srop.write(mFile);fprintf_s(mFile,"\" \"%s.sro[%i].srop\";\n",mName.c_str(),sro_i);}
	/*Ramp value at the sibling position*/
	void setSpecularRollOff_FloatValue(size_t sro_i,float srofv){if(srofv == 0.0) return; fprintf_s(mFile, "setAttr \".sro[%i].srofv\" %f;\n", sro_i,srofv);}
	/*Ramp value at the sibling position*/
	void setSpecularRollOff_FloatValue(size_t sro_i,const FloatID& srofv){fprintf_s(mFile,"connectAttr \"");srofv.write(mFile);fprintf_s(mFile,"\" \"%s.sro[%i].srofv\";\n",mName.c_str(),sro_i);}
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
	void setSpecularRollOff_Interp(size_t sro_i,unsigned int sroi){if(sroi == 0) return; fprintf_s(mFile, "setAttr \".sro[%i].sroi\" %i;\n", sro_i,sroi);}
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
	void setSpecularRollOff_Interp(size_t sro_i,const UnsignedintID& sroi){fprintf_s(mFile,"connectAttr \"");sroi.write(mFile);fprintf_s(mFile,"\" \"%s.sro[%i].sroi\";\n",mName.c_str(),sro_i);}
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
	If there is more than one ramp index the specular color will vary
	based on the brightness of the highlight.
	*/
	void setSpecularColor(size_t sc_i,const SpecularColor& sc){fprintf_s(mFile, "setAttr \".sc[%i]\" ",sc_i);sc.write(mFile);fprintf_s(mFile,";\n");}
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
	If there is more than one ramp index the specular color will vary
	based on the brightness of the highlight.
	*/
	void setSpecularColor(size_t sc_i,const SpecularColorID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i]\";\n",mName.c_str(),sc_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setSpecularColor_Position(size_t sc_i,float scp){if(scp == 0.0) return; fprintf_s(mFile, "setAttr \".sc[%i].scp\" %f;\n", sc_i,scp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setSpecularColor_Position(size_t sc_i,const FloatID& scp){fprintf_s(mFile,"connectAttr \"");scp.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i].scp\";\n",mName.c_str(),sc_i);}
	/*Ramp color at the sibling position*/
	void setSpecularColor_Color(size_t sc_i,const float3& scc){fprintf_s(mFile, "setAttr \".sc[%i].scc\" -type \"float3\" ",sc_i);scc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setSpecularColor_Color(size_t sc_i,const Float3ID& scc){fprintf_s(mFile,"connectAttr \"");scc.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i].scc\";\n",mName.c_str(),sc_i);}
	/*Ramp red channel value at the sibling position*/
	void setSpecularColor_ColorR(size_t sc_i,float sccr){if(sccr == 0.0) return; fprintf_s(mFile, "setAttr \".sc[%i].scc.sccr\" %f;\n", sc_i,sccr);}
	/*Ramp red channel value at the sibling position*/
	void setSpecularColor_ColorR(size_t sc_i,const FloatID& sccr){fprintf_s(mFile,"connectAttr \"");sccr.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i].scc.sccr\";\n",mName.c_str(),sc_i);}
	/*Ramp green channel value at the sibling position*/
	void setSpecularColor_ColorG(size_t sc_i,float sccg){if(sccg == 0.0) return; fprintf_s(mFile, "setAttr \".sc[%i].scc.sccg\" %f;\n", sc_i,sccg);}
	/*Ramp green channel value at the sibling position*/
	void setSpecularColor_ColorG(size_t sc_i,const FloatID& sccg){fprintf_s(mFile,"connectAttr \"");sccg.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i].scc.sccg\";\n",mName.c_str(),sc_i);}
	/*Ramp blue channel value at the sibling position*/
	void setSpecularColor_ColorB(size_t sc_i,float sccb){if(sccb == 0.0) return; fprintf_s(mFile, "setAttr \".sc[%i].scc.sccb\" %f;\n", sc_i,sccb);}
	/*Ramp blue channel value at the sibling position*/
	void setSpecularColor_ColorB(size_t sc_i,const FloatID& sccb){fprintf_s(mFile,"connectAttr \"");sccb.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i].scc.sccb\";\n",mName.c_str(),sc_i);}
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
	void setSpecularColor_Interp(size_t sc_i,unsigned int sci){if(sci == 0) return; fprintf_s(mFile, "setAttr \".sc[%i].sci\" %i;\n", sc_i,sci);}
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
	void setSpecularColor_Interp(size_t sc_i,const UnsignedintID& sci){fprintf_s(mFile,"connectAttr \"");sci.write(mFile);fprintf_s(mFile,"\" \"%s.sc[%i].sci\";\n",mName.c_str(),sc_i);}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
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
	void setReflectivity(size_t rfl_i,const Reflectivity& rfl){fprintf_s(mFile, "setAttr \".rfl[%i]\" ",rfl_i);rfl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
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
	void setReflectivity(size_t rfl_i,const ReflectivityID& rfl){fprintf_s(mFile,"connectAttr \"");rfl.write(mFile);fprintf_s(mFile,"\" \"%s.rfl[%i]\";\n",mName.c_str(),rfl_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setReflectivity_Position(size_t rfl_i,float rflp){if(rflp == 0.0) return; fprintf_s(mFile, "setAttr \".rfl[%i].rflp\" %f;\n", rfl_i,rflp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setReflectivity_Position(size_t rfl_i,const FloatID& rflp){fprintf_s(mFile,"connectAttr \"");rflp.write(mFile);fprintf_s(mFile,"\" \"%s.rfl[%i].rflp\";\n",mName.c_str(),rfl_i);}
	/*Ramp value at the sibling position*/
	void setReflectivity_FloatValue(size_t rfl_i,float rflfv){if(rflfv == 0.0) return; fprintf_s(mFile, "setAttr \".rfl[%i].rflfv\" %f;\n", rfl_i,rflfv);}
	/*Ramp value at the sibling position*/
	void setReflectivity_FloatValue(size_t rfl_i,const FloatID& rflfv){fprintf_s(mFile,"connectAttr \"");rflfv.write(mFile);fprintf_s(mFile,"\" \"%s.rfl[%i].rflfv\";\n",mName.c_str(),rfl_i);}
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
	void setReflectivity_Interp(size_t rfl_i,unsigned int rfli){if(rfli == 0) return; fprintf_s(mFile, "setAttr \".rfl[%i].rfli\" %i;\n", rfl_i,rfli);}
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
	void setReflectivity_Interp(size_t rfl_i,const UnsignedintID& rfli){fprintf_s(mFile,"connectAttr \"");rfli.write(mFile);fprintf_s(mFile,"\" \"%s.rfl[%i].rfli\";\n",mName.c_str(),rfl_i);}
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
	/*
	<b>Forward Scatter</b> controls how much of the light is diffusely scattered
	along the light direction. At a value of 0 the light is scattered
	uniformly in a lambertian fashion, which is good for most surfaces.
	Some materials, such as skin, scatter the light in a more
	along the forward direction so values larger than zero may help.
	in simulating these materials.
	*/
	FloatID getForwardScatter(){char buffer[4096];sprintf_s (buffer, "%s.fsc",mName.c_str());return (const char*)buffer;}
	/*The basic color of the surface.*/
	const ColorID& getColor(size_t clr_i){char buffer[4096];sprintf_s (buffer, "%s.clr[%i]",mName.c_str(),clr_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getColor_Position(size_t clr_i){char buffer[4096];sprintf_s (buffer, "%s.clr[%i].clrp",mName.c_str(),clr_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getColor_Color(size_t clr_i){char buffer[4096];sprintf_s (buffer, "%s.clr[%i].clrc",mName.c_str(),clr_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getColor_ColorR(size_t clr_i){char buffer[4096];sprintf_s (buffer, "%s.clr[%i].clrc.clrcr",mName.c_str(),clr_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getColor_ColorG(size_t clr_i){char buffer[4096];sprintf_s (buffer, "%s.clr[%i].clrc.clrcg",mName.c_str(),clr_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getColor_ColorB(size_t clr_i){char buffer[4096];sprintf_s (buffer, "%s.clr[%i].clrc.clrcb",mName.c_str(),clr_i);return (const char*)buffer;}
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
	const UnsignedintID& getColor_Interp(size_t clr_i){char buffer[4096];sprintf_s (buffer, "%s.clr[%i].clri",mName.c_str(),clr_i);return (const char*)buffer;}
	/*
	This determines the input to the color ramp.
	<b>Constant:</b> only the start value of the ramp is used.
	<b>Light Angle:</b> the position along the ramp is determined by the
	angle of the light with the surface normal.
	<b>Facing Angle:</b> the position along the ramp is determined by the
	angle of the surface with the view direction.
	<b>Brightness:</b> the total light brightness is used to index the
	ramp. This can be used to create cartoon style shading by using a
	ramp with stepped values.
	<b>Normalized Brightness:</b> this is similar to brightness, but the
	total light is normalized so that changing the overall light intensity
	will not affect the shading. However changing the intensity of one light
	relative to another light will shift the shaded position.
	This may be convenient when dealing with toon shading where one
	may want the color band spacing to be relatively fixed even though
	the lighting setup may be complex.
	*/
	UnsignedintID getColorInput(){char buffer[4096];sprintf_s (buffer, "%s.cin",mName.c_str());return (const char*)buffer;}
	/*
	This determines how color is computed in shadow regions.
	It is primarily useful for a toon style shading.
	<b>Normal:</b> The shadow is computed as for a standard shader.
	If the color input is brightness, then the brightness value used
	to index the color ramp includes the effect of shadowing.
	<b>Shaded Color:</b> the color in shadow regions
	uses the shadow color values. One will see the effects of soft shadows
	as well as the effects of partial shadow occlusion when illuminated by
	multiple lights.
	<b>Constant Color:</b> the color in shadow regions
	uses the shadow color values. The shadow will be a fixed color. Shadows will
	appear hard edged, and this color will be constant across regions of both partial
	and full shadowing.
	*/
	UnsignedintID getShadowMode(){char buffer[4096];sprintf_s (buffer, "%s.smd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Shadow Color</b> is only used when shadow mode is not set to normal.
	How it is applied is dependant on the shadow mode used. Normally shadow
	color arises from the interaction of the surface color and the remaining
	light when some lights are blocked from illuminating a region. For purposes
	of toon shading it can be useful to directly specify the color in these
	regions.
	*/
	Float3ID getShadowColor(){char buffer[4096];sprintf_s (buffer, "%s.shc",mName.c_str());return (const char*)buffer;}
	/*shadow color red value*/
	FloatID getShadowColorR(){char buffer[4096];sprintf_s (buffer, "%s.shc.shr",mName.c_str());return (const char*)buffer;}
	/*shadow color green value*/
	FloatID getShadowColorG(){char buffer[4096];sprintf_s (buffer, "%s.shc.shg",mName.c_str());return (const char*)buffer;}
	/*shadow color blue value*/
	FloatID getShadowColorB(){char buffer[4096];sprintf_s (buffer, "%s.shc.shb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Shadow Threshold</b><p/>
	This determines how great a proportion of the incoming light must
	be blocked for a shadow to appear. It requires that the shadow mode
	be set to shaded color or constant color. This is primarily of use
	for toon style shading.
	*/
	FloatID getShadowThreshold(){char buffer[4096];sprintf_s (buffer, "%s.sht",mName.c_str());return (const char*)buffer;}
	/*
	<b>Transparency</b> controls how transparent or opaque the material is.
	Black means completely opaque (the default), and white means completely
	transparent.  You can set it to any level in between.  You can
	also control transparency on a per-channel basis;  for example, if
	you set this to red, then only the red channel will be transparent.
	<p/><i>Note:</i> If this material has specular highlights the transparency
	setting will <i>not</i> affect the highlights.  So if you are
	trying to make an object disappear by animating the transparency
	attribute, you may also have to animate the specular highlight
	attributes.
	If there is more than one index in the ramp then the transparency
	value will vary with the facing angle.
	*/
	const TransparencyID& getTransparency(size_t it_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i]",mName.c_str(),it_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getTransparency_Position(size_t it_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itp",mName.c_str(),it_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getTransparency_Color(size_t it_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itc",mName.c_str(),it_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getTransparency_ColorR(size_t it_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itc.itcr",mName.c_str(),it_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getTransparency_ColorG(size_t it_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itc.itcg",mName.c_str(),it_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getTransparency_ColorB(size_t it_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].itc.itcb",mName.c_str(),it_i);return (const char*)buffer;}
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
	const UnsignedintID& getTransparency_Interp(size_t it_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i].iti",mName.c_str(),it_i);return (const char*)buffer;}
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
	If there is more than one index in the ramp then the incandescence
	value will vary with the facing angle.
	<p/>See also Glow Intensity.
	*/
	const IncandescenceID& getIncandescence(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i]",mName.c_str(),ic_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getIncandescence_Position(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i].icp",mName.c_str(),ic_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getIncandescence_Color(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i].icc",mName.c_str(),ic_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getIncandescence_ColorR(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i].icc.iccr",mName.c_str(),ic_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getIncandescence_ColorG(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i].icc.iccg",mName.c_str(),ic_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getIncandescence_ColorB(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i].icc.iccb",mName.c_str(),ic_i);return (const char*)buffer;}
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
	const UnsignedintID& getIncandescence_Interp(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i].ici",mName.c_str(),ic_i);return (const char*)buffer;}
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
	If <b>Hide Source</b> is turned on (and Glow Intensity is not zero), then the
	glowing object will be hidden, but its glowing halo will
	still be rendered in the scene (during post-processing).  Use this
	attribute to produce gas effects, or interesting ghosts.
	*/
	BoolID getHideSource(){char buffer[4096];sprintf_s (buffer, "%s.hs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Surface Thickness</b><p/>
	(aka Studio special effect "Surface Width" - raytracing only)<p/>
	The simulated thickness (in world space units) of transparent
	objects that are made from single surfaces (for example, a plane
	or face). Using Surface Width does not produce the same results
	as building a surface with actual thickness. However, the effect
	works well when the edges of the surface are not visible (for example,
	closed surfaces, or bounded shapes like a car windshield).
	*/
	FloatID getSurfaceThickness(){char buffer[4096];sprintf_s (buffer, "%s.thik",mName.c_str());return (const char*)buffer;}
	/*
	<b>Shadow Attenuation (Fake Refraction Caustics)</b>>p>
	(aka Studio special effect "Transparency Shade" - raytracing only)<p/>
	Causes shadows of transparent objects to be brighter in the
	center, simulating the focusing of light.  0 gives constant
	intensity shadows, 1 gives shadows focused in the center.
	*/
	FloatID getShadowAttenuation(){char buffer[4096];sprintf_s (buffer, "%s.fakc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Transparency Depth</b> (Studio special effect - raytracing only)<p/>
	This should be used for backwards compatability when rendering
	data from Studio - Maya users should use Absorbance instead.<p/>
	The distance (in world units) camera rays can travel after
	passing through a transparent surface. Useful for effects
	like under water.  If the Transp. Depth value is 0, camera
	rays can travel an infinite distance, and all objects
	behind the transparent surface are visible no matter how far
	away they are. For non-zero values, as a camera ray
	reaches the distance of the Transp. Depth value, its color
	becomes the surface color. Only objects near the transparent
	surface (less than the Transp. Depth value) are visible
	through the surface. Objects close to the surface are more
	visible (the surface is more transparent in those areas)
	and objects further away are less visible (the surface is
	less transparent in those areas). Objects beyond this depth
	are not visible at all (the surface is opaque in those areas).
	*/
	FloatID getTransparencyDepth(){char buffer[4096];sprintf_s (buffer, "%s.trdp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Absorbance</b> Transparent materials generally absorb some
	amount of the light which passes through them (Beer's Law).
	The more of the material the light shines through, the less of
	the light gets through.  This attribute describes how light
	absorbing the material is (raytracing only). A material with
	an absorbance of 0.0 will transmitt completely.  The higher
	the absorbance, the less light will pass through.
	*/
	FloatID getLightAbsorbance(){char buffer[4096];sprintf_s (buffer, "%s.absb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Chromatic Aberration</b> Causes different wavelengths of light
	to refract at different angles when passing through a transparent
	surface during raytracing.  Chromatic aberration only affects light
	rays as they pass through the second surface of a transparent object
	(that is, the first exit ray). For best results, make sure there are
	suitable objects in the background to be refracted.
	*/
	BoolID getChromaticAberration(){char buffer[4096];sprintf_s (buffer, "%s.crab",mName.c_str());return (const char*)buffer;}
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
	/*
	<b>Specular Rolloff</b> controls the ability of a surface to
	reflect its surroundings (the environment, other objects, or
	the Reflection Map, if any), when viewed at oblique angles.
	The horizontal dimension of the graph represents the brightness
	of specular reflections and the horizontal represents the facing
	angle with the view.
	<p/>
	Specular Rolloff does not affect the reflections produced
	when you render using Ray Tracing.
	<p/>
	<i>Tip:</i> to get a "wet" look (such as wet paint), make the
	edges more reflective.
	*/
	const SpecularRollOffID& getSpecularRollOff(size_t sro_i){char buffer[4096];sprintf_s (buffer, "%s.sro[%i]",mName.c_str(),sro_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getSpecularRollOff_Position(size_t sro_i){char buffer[4096];sprintf_s (buffer, "%s.sro[%i].srop",mName.c_str(),sro_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getSpecularRollOff_FloatValue(size_t sro_i){char buffer[4096];sprintf_s (buffer, "%s.sro[%i].srofv",mName.c_str(),sro_i);return (const char*)buffer;}
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
	const UnsignedintID& getSpecularRollOff_Interp(size_t sro_i){char buffer[4096];sprintf_s (buffer, "%s.sro[%i].sroi",mName.c_str(),sro_i);return (const char*)buffer;}
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
	If there is more than one ramp index the specular color will vary
	based on the brightness of the highlight.
	*/
	const SpecularColorID& getSpecularColor(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i]",mName.c_str(),sc_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getSpecularColor_Position(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i].scp",mName.c_str(),sc_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getSpecularColor_Color(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i].scc",mName.c_str(),sc_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getSpecularColor_ColorR(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i].scc.sccr",mName.c_str(),sc_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getSpecularColor_ColorG(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i].scc.sccg",mName.c_str(),sc_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getSpecularColor_ColorB(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i].scc.sccb",mName.c_str(),sc_i);return (const char*)buffer;}
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
	const UnsignedintID& getSpecularColor_Interp(size_t sc_i){char buffer[4096];sprintf_s (buffer, "%s.sc[%i].sci",mName.c_str(),sc_i);return (const char*)buffer;}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you don't want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
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
	const ReflectivityID& getReflectivity(size_t rfl_i){char buffer[4096];sprintf_s (buffer, "%s.rfl[%i]",mName.c_str(),rfl_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getReflectivity_Position(size_t rfl_i){char buffer[4096];sprintf_s (buffer, "%s.rfl[%i].rflp",mName.c_str(),rfl_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getReflectivity_FloatValue(size_t rfl_i){char buffer[4096];sprintf_s (buffer, "%s.rfl[%i].rflfv",mName.c_str(),rfl_i);return (const char*)buffer;}
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
	const UnsignedintID& getReflectivity_Interp(size_t rfl_i){char buffer[4096];sprintf_s (buffer, "%s.rfl[%i].rfli",mName.c_str(),rfl_i);return (const char*)buffer;}
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
	RampShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RAMPSHADER_H__
