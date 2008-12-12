/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LAMBERT_H__
#define __MayaDM_LAMBERT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Use a <b>Lambert</b> shader to produce a surface that appears
  flat, with no reflections or highlights on it.  Lambert shaders
  are good for modeling things like chalk, matte paint, and other
  unpolished surfaces.
  <p/>
  Several other shaders are based on the Lambert shader, and share
  all of these attributes.  You can
  use them to produce different effects:
  <ul>
        For metallic surfaces, like brass or aluminum, use a <b>Blinn</b> shader.
  <p/>
  For glass and glossy plastic surfaces, or car and bathroom mouldings,
  use a <b>PhongE</b> shader.
  <p/>
  For microgrooved surfaces like CDs, brushed metal, or hair, use an
  <b>Anisotropic</b> shader.
  </ul>
        <p/>
        In the table below, important attributes have their names indicated
  in <b>bold</b> in the description column.
*/
class Lambert : public DependNode
{
public:
public:
	Lambert(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "lambert"){}
	virtual ~Lambert(){}
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
	is reflected from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.  The default
	value is 0.8;  a value of 1.0 (the maximum) would mean that all
	the light falling on the material is reflected;  a value of 0.0
	(the minimum) would mean
	that no light is reflected (the material would appear black,
	although it could still have highlights.)
	*/
	void setDiffuse(float dc){if(dc == 0.8) return; fprintf_s(mFile, "setAttr \".dc\" %f;\n", dc);}
	/*
	<b>Diffuse</b> controls how much of the light in the scene
	is reflected from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.  The default
	value is 0.8;  a value of 1.0 (the maximum) would mean that all
	the light falling on the material is reflected;  a value of 0.0
	(the minimum) would mean
	that no light is reflected (the material would appear black,
	although it could still have highlights.)
	*/
	void setDiffuse(const FloatID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*<b>Color</b> is the basic color of the surface.*/
	void setColor(const float3& c){fprintf_s(mFile, "setAttr \".c\" -type \"float3\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Color</b> is the basic color of the surface.*/
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
	void setTranslucenceFocus(float tcf){if(tcf == 0.5) return; fprintf_s(mFile, "setAttr \".tcf\" %f;\n", tcf);}
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
	void setTranslucenceDepth(float trsd){if(trsd == 0.5) return; fprintf_s(mFile, "setAttr \".trsd\" %f;\n", trsd);}
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
	/*Allows user to over-ride render globals and customize settings per material.*/
	void setVrOverwriteDefaults(bool vrod){if(vrod == 0) return; fprintf_s(mFile, "setAttr \".vrod\" %i;\n", vrod);}
	/*Allows user to over-ride render globals and customize settings per material.*/
	void setVrOverwriteDefaults(const BoolID& vrod){fprintf_s(mFile,"connectAttr \"");vrod.write(mFile);fprintf_s(mFile,"\" \"%s.vrod\";\n",mName.c_str());}
	/*The style of shading used to fill surfaces in the rendered image.*/
	void setVrFillObject(unsigned int vrfo){if(vrfo == 0) return; fprintf_s(mFile, "setAttr \".vrfo\" %i;\n", vrfo);}
	/*The style of shading used to fill surfaces in the rendered image.*/
	void setVrFillObject(const UnsignedintID& vrfo){fprintf_s(mFile,"connectAttr \"");vrfo.write(mFile);fprintf_s(mFile,"\" \"%s.vrfo\";\n",mName.c_str());}
	/*Surface edges and silhouettes are rendered as outlines. Controls the thickness of surface outlines (measured in points).*/
	void setVrEdgeWeight(double vrew){if(vrew == 0.0) return; fprintf_s(mFile, "setAttr \".vrew\" %f;\n", vrew);}
	/*Surface edges and silhouettes are rendered as outlines. Controls the thickness of surface outlines (measured in points).*/
	void setVrEdgeWeight(const DoubleID& vrew){fprintf_s(mFile,"connectAttr \"");vrew.write(mFile);fprintf_s(mFile,"\" \"%s.vrew\";\n",mName.c_str());}
	/*Surface edges and silhouettes are rendered as outlines. This controls the color of surface outlines.*/
	void setVrEdgeColor(const float3& vrec){fprintf_s(mFile, "setAttr \".vrec\" -type \"float3\" ");vrec.write(mFile);fprintf_s(mFile,";\n");}
	/*Surface edges and silhouettes are rendered as outlines. This controls the color of surface outlines.*/
	void setVrEdgeColor(const Float3ID& vrec){fprintf_s(mFile,"connectAttr \"");vrec.write(mFile);fprintf_s(mFile,"\" \"%s.vrec\";\n",mName.c_str());}
	/*Red component.*/
	void setVrEdgeColorR(float vecr){if(vecr == 0.5) return; fprintf_s(mFile, "setAttr \".vrec.vecr\" %f;\n", vecr);}
	/*Red component.*/
	void setVrEdgeColorR(const FloatID& vecr){fprintf_s(mFile,"connectAttr \"");vecr.write(mFile);fprintf_s(mFile,"\" \"%s.vrec.vecr\";\n",mName.c_str());}
	/*Green component.*/
	void setVrEdgeColorG(float vecg){if(vecg == 0.5) return; fprintf_s(mFile, "setAttr \".vrec.vecg\" %f;\n", vecg);}
	/*Green component.*/
	void setVrEdgeColorG(const FloatID& vecg){fprintf_s(mFile,"connectAttr \"");vecg.write(mFile);fprintf_s(mFile,"\" \"%s.vrec.vecg\";\n",mName.c_str());}
	/*Blue component.*/
	void setVrEdgeColorB(float vecb){if(vecb == 0.5) return; fprintf_s(mFile, "setAttr \".vrec.vecb\" %f;\n", vecb);}
	/*Blue component.*/
	void setVrEdgeColorB(const FloatID& vecb){fprintf_s(mFile,"connectAttr \"");vecb.write(mFile);fprintf_s(mFile,"\" \"%s.vrec.vecb\";\n",mName.c_str());}
	/*Surface edges and silhouettes are rendered as outlines. This controls the level of detail (i.e. number of outlines).*/
	void setVrEdgeStyle(unsigned int vres){if(vres == 0) return; fprintf_s(mFile, "setAttr \".vres\" %i;\n", vres);}
	/*Surface edges and silhouettes are rendered as outlines. This controls the level of detail (i.e. number of outlines).*/
	void setVrEdgeStyle(const UnsignedintID& vres){fprintf_s(mFile,"connectAttr \"");vres.write(mFile);fprintf_s(mFile,"\" \"%s.vres\";\n",mName.c_str());}
	/*
	A depth algorithm is used to determine which line style to use when
	two line styles collide.  If the line style cannot be resolved with
	the depth algorithm the edge priority attribute is used to determine
	which line style to use.
	*/
	void setVrEdgePriority(int vrep){if(vrep == 0) return; fprintf_s(mFile, "setAttr \".vrep\" %i;\n", vrep);}
	/*
	A depth algorithm is used to determine which line style to use when
	two line styles collide.  If the line style cannot be resolved with
	the depth algorithm the edge priority attribute is used to determine
	which line style to use.
	*/
	void setVrEdgePriority(const IntID& vrep){fprintf_s(mFile,"connectAttr \"");vrep.write(mFile);fprintf_s(mFile,"\" \"%s.vrep\";\n",mName.c_str());}
	/*
	Surface edges and silhouettes are rendered as outlines.
	This controls whether the outline behind a surface will be displayed.
	*/
	void setVrHiddenEdges(bool vrhe){if(vrhe == 0) return; fprintf_s(mFile, "setAttr \".vrhe\" %i;\n", vrhe);}
	/*
	Surface edges and silhouettes are rendered as outlines.
	This controls whether the outline behind a surface will be displayed.
	*/
	void setVrHiddenEdges(const BoolID& vrhe){fprintf_s(mFile,"connectAttr \"");vrhe.write(mFile);fprintf_s(mFile,"\" \"%s.vrhe\";\n",mName.c_str());}
	/*
	The attribute controls the rendering of hidden edges on transparent
	objects. Hidden edges on transparent objects are treated differently
	from ordinary hidden edges. Their edge color is masked by the
	transparency and their lines can be occluded by opaque objects.
	*/
	void setVrHiddenEdgesOnTransparent(bool vrht){if(vrht == 0) return; fprintf_s(mFile, "setAttr \".vrht\" %i;\n", vrht);}
	/*
	The attribute controls the rendering of hidden edges on transparent
	objects. Hidden edges on transparent objects are treated differently
	from ordinary hidden edges. Their edge color is masked by the
	transparency and their lines can be occluded by opaque objects.
	*/
	void setVrHiddenEdgesOnTransparent(const BoolID& vrht){fprintf_s(mFile,"connectAttr \"");vrht.write(mFile);fprintf_s(mFile,"\" \"%s.vrht\";\n",mName.c_str());}
	/*
	Specifies if edges should be drawn when two polygons intersect.
	By default this flag is enabled.
	*/
	void setVrOutlinesAtIntersections(bool vroi){if(vroi == 1) return; fprintf_s(mFile, "setAttr \".vroi\" %i;\n", vroi);}
	/*
	Specifies if edges should be drawn when two polygons intersect.
	By default this flag is enabled.
	*/
	void setVrOutlinesAtIntersections(const BoolID& vroi){fprintf_s(mFile,"connectAttr \"");vroi.write(mFile);fprintf_s(mFile,"\" \"%s.vroi\";\n",mName.c_str());}
	/*Material Alpha*/
	void setMaterialAlphaGain(float maga){if(maga == 1.0) return; fprintf_s(mFile, "setAttr \".maga\" %f;\n", maga);}
	/*Material Alpha*/
	void setMaterialAlphaGain(const FloatID& maga){fprintf_s(mFile,"connectAttr \"");maga.write(mFile);fprintf_s(mFile,"\" \"%s.maga\";\n",mName.c_str());}
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
	is reflected from the object.  Most materials absorb some of
	the light falling on them, and scatter the rest.  The default
	value is 0.8;  a value of 1.0 (the maximum) would mean that all
	the light falling on the material is reflected;  a value of 0.0
	(the minimum) would mean
	that no light is reflected (the material would appear black,
	although it could still have highlights.)
	*/
	FloatID getDiffuse(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*<b>Color</b> is the basic color of the surface.*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*color red value*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.c.cr",mName.c_str());return (const char*)buffer;}
	/*color green value*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.c.cg",mName.c_str());return (const char*)buffer;}
	/*color blue value*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.c.cb",mName.c_str());return (const char*)buffer;}
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
	/*Allows user to over-ride render globals and customize settings per material.*/
	BoolID getVrOverwriteDefaults(){char buffer[4096];sprintf_s (buffer, "%s.vrod",mName.c_str());return (const char*)buffer;}
	/*The style of shading used to fill surfaces in the rendered image.*/
	UnsignedintID getVrFillObject(){char buffer[4096];sprintf_s (buffer, "%s.vrfo",mName.c_str());return (const char*)buffer;}
	/*Surface edges and silhouettes are rendered as outlines. Controls the thickness of surface outlines (measured in points).*/
	DoubleID getVrEdgeWeight(){char buffer[4096];sprintf_s (buffer, "%s.vrew",mName.c_str());return (const char*)buffer;}
	/*Surface edges and silhouettes are rendered as outlines. This controls the color of surface outlines.*/
	Float3ID getVrEdgeColor(){char buffer[4096];sprintf_s (buffer, "%s.vrec",mName.c_str());return (const char*)buffer;}
	/*Red component.*/
	FloatID getVrEdgeColorR(){char buffer[4096];sprintf_s (buffer, "%s.vrec.vecr",mName.c_str());return (const char*)buffer;}
	/*Green component.*/
	FloatID getVrEdgeColorG(){char buffer[4096];sprintf_s (buffer, "%s.vrec.vecg",mName.c_str());return (const char*)buffer;}
	/*Blue component.*/
	FloatID getVrEdgeColorB(){char buffer[4096];sprintf_s (buffer, "%s.vrec.vecb",mName.c_str());return (const char*)buffer;}
	/*Surface edges and silhouettes are rendered as outlines. This controls the level of detail (i.e. number of outlines).*/
	UnsignedintID getVrEdgeStyle(){char buffer[4096];sprintf_s (buffer, "%s.vres",mName.c_str());return (const char*)buffer;}
	/*
	A depth algorithm is used to determine which line style to use when
	two line styles collide.  If the line style cannot be resolved with
	the depth algorithm the edge priority attribute is used to determine
	which line style to use.
	*/
	IntID getVrEdgePriority(){char buffer[4096];sprintf_s (buffer, "%s.vrep",mName.c_str());return (const char*)buffer;}
	/*
	Surface edges and silhouettes are rendered as outlines.
	This controls whether the outline behind a surface will be displayed.
	*/
	BoolID getVrHiddenEdges(){char buffer[4096];sprintf_s (buffer, "%s.vrhe",mName.c_str());return (const char*)buffer;}
	/*
	The attribute controls the rendering of hidden edges on transparent
	objects. Hidden edges on transparent objects are treated differently
	from ordinary hidden edges. Their edge color is masked by the
	transparency and their lines can be occluded by opaque objects.
	*/
	BoolID getVrHiddenEdgesOnTransparent(){char buffer[4096];sprintf_s (buffer, "%s.vrht",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if edges should be drawn when two polygons intersect.
	By default this flag is enabled.
	*/
	BoolID getVrOutlinesAtIntersections(){char buffer[4096];sprintf_s (buffer, "%s.vroi",mName.c_str());return (const char*)buffer;}
	/*Material Alpha*/
	FloatID getMaterialAlphaGain(){char buffer[4096];sprintf_s (buffer, "%s.maga",mName.c_str());return (const char*)buffer;}
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
	Lambert(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LAMBERT_H__
