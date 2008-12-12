/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OPTICALFX_H__
#define __MayaDM_OPTICALFX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Optical FX</b> nodes are used to add glowing effects to
 a light source in the scene.  These effects simulate the
 sorts of light effects that happen on camera lenses;  radial
 "star" arms, light halos, and lens flares.  Since the effect
 is happening on the camera lens, the size of the effect does
 not change based on the distance of the light from the camera.
 <p/>
 These Optical FX are added during post-processing, that is,
 after the main rendering is completed.
 <p/>
 Normally, an Optical FX node is created automatically by the
 system when you click on the Light Glow mapping button, which
 is found under the Light Effects tab in the Attribute Editor
 of any light shape.  We recommend this method of creation, since
 all the connections are made for you.  The system also creates
 a sphere, attached to the Optical FX.  The optical FX determines
 its Glow Visibility based on how much of the sphere is visible.
 (The sphere itself is not rendered).
 <p/>
 If you create an Optical FX node yourself, you will have to
 connect it to a light to make it work properly.  Here are the
 connections you need to make:
<pre>
   Optical FX              LightShape
   ----------              ----------
   Light Connection ------> Light Glow
   Light Color      <------ Color
   Light World Mat  <------ World Matrix
</pre>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class OpticalFX : public DependNode
{
public:
public:
	OpticalFX(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "opticalFX"){}
	virtual ~OpticalFX(){}
	/*
	<b>Active</b> controls whether the light glow is
	on or not.  Turn off Active to make the effect disappear.
	*/
	void setActive(bool act){if(act == true) return; fprintf_s(mFile, "setAttr \".act\" %i;\n", act);}
	/*
	<b>Active</b> controls whether the light glow is
	on or not.  Turn off Active to make the effect disappear.
	*/
	void setActive(const BoolID& act){fprintf_s(mFile,"connectAttr \"");act.write(mFile);fprintf_s(mFile,"\" \"%s.act\";\n",mName.c_str());}
	/*
	<b>Glow Type</b> controls the appearance of the light
	glow.  Possible settings are:
	<ul>
	<b>None:</b> No glow.<p/>
	<b>Linear:</b> Glow slowly diminishes from the center of the light<p/>
	<b>Exponential:</b> Glow quickly diminishes from the center of the light<p/>
	<b>Ball:</b> Glow diminishes faster towards a distance (from the light
	center) specified by the Glow Spread attribute.<p/>
	<b>Lens Flare:</b> Lower frequencies (red) refract (or spread)
	more than the higher frequencies (blue).<p/>
	<b>Rim Halo:</b> This is like Lens Flare, but the Glow starts
	at a certain distance from the
	light, controlled by the Glow Spread attribute.
	</ul>
	*/
	void setGlowType(unsigned int gt){if(gt == 1) return; fprintf_s(mFile, "setAttr \".gt\" %i;\n", gt);}
	/*
	<b>Glow Type</b> controls the appearance of the light
	glow.  Possible settings are:
	<ul>
	<b>None:</b> No glow.<p/>
	<b>Linear:</b> Glow slowly diminishes from the center of the light<p/>
	<b>Exponential:</b> Glow quickly diminishes from the center of the light<p/>
	<b>Ball:</b> Glow diminishes faster towards a distance (from the light
	center) specified by the Glow Spread attribute.<p/>
	<b>Lens Flare:</b> Lower frequencies (red) refract (or spread)
	more than the higher frequencies (blue).<p/>
	<b>Rim Halo:</b> This is like Lens Flare, but the Glow starts
	at a certain distance from the
	light, controlled by the Glow Spread attribute.
	</ul>
	*/
	void setGlowType(const UnsignedintID& gt){fprintf_s(mFile,"connectAttr \"");gt.write(mFile);fprintf_s(mFile,"\" \"%s.gt\";\n",mName.c_str());}
	/*
	<b>Halo Type</b> controls the type of halo the
	light produces when viewed directly. Halo is similar
	to Glow, except that the falloff is more gradual.
	The available types are:
	<ul>
	<b>None:</b> No halo.<p/>
	<b>Linear:</b> Halo slowly diminishes from the center of the light<p/>
	<b>Exponential:</b> Halo quickly diminishes from the center of the light<p/>
	<b>Ball:</b> Halo diminishes faster towards a distance (from the light
	center) specified by the Halo Spread attribute.<p/>
	<b>Lens Flare:</b> Simulates a bright light source illuminating
	the surfaces of several camera lenses. The intensity of the
	flare is determined by the Halo Intensity attribute. The size
	of the flare circles is relative to the field of
	view of the camera.<p/>
	<b>Rim Halo:</b> Forms a circular ring with a soft central
	glow.  The size of the ring is controlled by the Halo Spread
	attribute.
	</ul>
	*/
	void setHaloType(unsigned int ht){if(ht == 0) return; fprintf_s(mFile, "setAttr \".ht\" %i;\n", ht);}
	/*
	<b>Halo Type</b> controls the type of halo the
	light produces when viewed directly. Halo is similar
	to Glow, except that the falloff is more gradual.
	The available types are:
	<ul>
	<b>None:</b> No halo.<p/>
	<b>Linear:</b> Halo slowly diminishes from the center of the light<p/>
	<b>Exponential:</b> Halo quickly diminishes from the center of the light<p/>
	<b>Ball:</b> Halo diminishes faster towards a distance (from the light
	center) specified by the Halo Spread attribute.<p/>
	<b>Lens Flare:</b> Simulates a bright light source illuminating
	the surfaces of several camera lenses. The intensity of the
	flare is determined by the Halo Intensity attribute. The size
	of the flare circles is relative to the field of
	view of the camera.<p/>
	<b>Rim Halo:</b> Forms a circular ring with a soft central
	glow.  The size of the ring is controlled by the Halo Spread
	attribute.
	</ul>
	*/
	void setHaloType(const UnsignedintID& ht){fprintf_s(mFile,"connectAttr \"");ht.write(mFile);fprintf_s(mFile,"\" \"%s.ht\";\n",mName.c_str());}
	/*What type of fog (this feature is not implemented).*/
	void setFogType(short ft){if(ft == 0) return; fprintf_s(mFile, "setAttr \".ft\" %i;\n", ft);}
	/*What type of fog (this feature is not implemented).*/
	void setFogType(const ShortID& ft){fprintf_s(mFile,"connectAttr \"");ft.write(mFile);fprintf_s(mFile,"\" \"%s.ft\";\n",mName.c_str());}
	/*
	<b>Lens Flare</b> Simulates a bright light source
	illuminating the surfaces of several camera lenses.
	The intensity of the flare is determined by the
	Flare Intensity attribute. The size of the flare circles
	created is relative to the field of view of the camera.
	The Lens Flare attribute is not available for ambient lights.
	*/
	void setLensFlare(bool lf){if(lf == false) return; fprintf_s(mFile, "setAttr \".lf\" %i;\n", lf);}
	/*
	<b>Lens Flare</b> Simulates a bright light source
	illuminating the surfaces of several camera lenses.
	The intensity of the flare is determined by the
	Flare Intensity attribute. The size of the flare circles
	created is relative to the field of view of the camera.
	The Lens Flare attribute is not available for ambient lights.
	*/
	void setLensFlare(const BoolID& lf){fprintf_s(mFile,"connectAttr \"");lf.write(mFile);fprintf_s(mFile,"\" \"%s.lf\";\n",mName.c_str());}
	/*<b>Glow Color</b> controls the basic color of the light glow..*/
	void setGlowColor(const float3& gc){if(gc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".gc\" -type \"float3\" ");gc.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Glow Color</b> controls the basic color of the light glow..*/
	void setGlowColor(const Float3ID& gc){fprintf_s(mFile,"connectAttr \"");gc.write(mFile);fprintf_s(mFile,"\" \"%s.gc\";\n",mName.c_str());}
	/*The red component of Glow Color.*/
	void setGlowColorR(float gr){if(gr == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gr\" %f;\n", gr);}
	/*The red component of Glow Color.*/
	void setGlowColorR(const FloatID& gr){fprintf_s(mFile,"connectAttr \"");gr.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gr\";\n",mName.c_str());}
	/*The green component of Glow Color.*/
	void setGlowColorG(float gg){if(gg == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gg\" %f;\n", gg);}
	/*The green component of Glow Color.*/
	void setGlowColorG(const FloatID& gg){fprintf_s(mFile,"connectAttr \"");gg.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gg\";\n",mName.c_str());}
	/*The blue component of Glow Color.*/
	void setGlowColorB(float gb){if(gb == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gb\" %f;\n", gb);}
	/*The blue component of Glow Color.*/
	void setGlowColorB(const FloatID& gb){fprintf_s(mFile,"connectAttr \"");gb.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gb\";\n",mName.c_str());}
	/*<b>Halo Color</b> controsl the basic color of the Halo.*/
	void setHaloColor(const float3& hc){if(hc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".hc\" -type \"float3\" ");hc.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Halo Color</b> controsl the basic color of the Halo.*/
	void setHaloColor(const Float3ID& hc){fprintf_s(mFile,"connectAttr \"");hc.write(mFile);fprintf_s(mFile,"\" \"%s.hc\";\n",mName.c_str());}
	/*The red component of Halo Color.*/
	void setHaloColorR(float hr){if(hr == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hr\" %f;\n", hr);}
	/*The red component of Halo Color.*/
	void setHaloColorR(const FloatID& hr){fprintf_s(mFile,"connectAttr \"");hr.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hr\";\n",mName.c_str());}
	/*The red component of Halo Color.*/
	void setHaloColorG(float hg){if(hg == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hg\" %f;\n", hg);}
	/*The red component of Halo Color.*/
	void setHaloColorG(const FloatID& hg){fprintf_s(mFile,"connectAttr \"");hg.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hg\";\n",mName.c_str());}
	/*The red component of Halo Color.*/
	void setHaloColorB(float hb){if(hb == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hb\" %f;\n", hb);}
	/*The red component of Halo Color.*/
	void setHaloColorB(const FloatID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hb\";\n",mName.c_str());}
	/*The fog color (not implemented).*/
	void setFogColor(const float3& fc){if(fc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".fc\" -type \"float3\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*The fog color (not implemented).*/
	void setFogColor(const Float3ID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc\";\n",mName.c_str());}
	/*The red component of the fog color (not implemented).*/
	void setFogColorR(float fr){if(fr == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fr\" %f;\n", fr);}
	/*The red component of the fog color (not implemented).*/
	void setFogColorR(const FloatID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fr\";\n",mName.c_str());}
	/*The red component of the fog color (not implemented).*/
	void setFogColorG(float fg){if(fg == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fg\" %f;\n", fg);}
	/*The red component of the fog color (not implemented).*/
	void setFogColorG(const FloatID& fg){fprintf_s(mFile,"connectAttr \"");fg.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fg\";\n",mName.c_str());}
	/*The red component of the fog color (not implemented).*/
	void setFogColorB(float fb){if(fb == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fb\" %f;\n", fb);}
	/*The red component of the fog color (not implemented).*/
	void setFogColorB(const FloatID& fb){fprintf_s(mFile,"connectAttr \"");fb.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fb\";\n",mName.c_str());}
	/*<b>Flare Color</b> controls the basic color of Lens Flare.*/
	void setFlareColor(const float3& rc){if(rc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".rc\" -type \"float3\" ");rc.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Flare Color</b> controls the basic color of Lens Flare.*/
	void setFlareColor(const Float3ID& rc){fprintf_s(mFile,"connectAttr \"");rc.write(mFile);fprintf_s(mFile,"\" \"%s.rc\";\n",mName.c_str());}
	/*The red component of Flare Color.*/
	void setFlareColorR(float rr){if(rr == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rr\" %f;\n", rr);}
	/*The red component of Flare Color.*/
	void setFlareColorR(const FloatID& rr){fprintf_s(mFile,"connectAttr \"");rr.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rr\";\n",mName.c_str());}
	/*The red component of Flare Color.*/
	void setFlareColorG(float rg){if(rg == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rg\" %f;\n", rg);}
	/*The red component of Flare Color.*/
	void setFlareColorG(const FloatID& rg){fprintf_s(mFile,"connectAttr \"");rg.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rg\";\n",mName.c_str());}
	/*The red component of Flare Color.*/
	void setFlareColorB(float rb){if(rb == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rb\" %f;\n", rb);}
	/*The red component of Flare Color.*/
	void setFlareColorB(const FloatID& rb){fprintf_s(mFile,"connectAttr \"");rb.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rb\";\n",mName.c_str());}
	/*
	<b>Flare Intensity</b> controls the brightness of
	the flare effect.
	*/
	void setFlareIntensity(float fi){if(fi == 1.0) return; fprintf_s(mFile, "setAttr \".fi\" %f;\n", fi);}
	/*
	<b>Flare Intensity</b> controls the brightness of
	the flare effect.
	*/
	void setFlareIntensity(const FloatID& fi){fprintf_s(mFile,"connectAttr \"");fi.write(mFile);fprintf_s(mFile,"\" \"%s.fi\";\n",mName.c_str());}
	/*
	<b>Flare Num Circles</b> controls the number of circles
	in the flare effect.
	<p/>
	If Num Circles is very large, rendering times may be
	Tint32, especially if Flare Min Size and Flare Max Size
	are large, and Flare Color is textured.
	*/
	void setFlareNumCircles(float fn){if(fn == 20.0) return; fprintf_s(mFile, "setAttr \".fn\" %f;\n", fn);}
	/*
	<b>Flare Num Circles</b> controls the number of circles
	in the flare effect.
	<p/>
	If Num Circles is very large, rendering times may be
	Tint32, especially if Flare Min Size and Flare Max Size
	are large, and Flare Color is textured.
	*/
	void setFlareNumCircles(const FloatID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn\";\n",mName.c_str());}
	/*
	<b>Flare Min Size:</b> The size of the lens flare
	circles is randomized between the Flare Min Size and
	Flare Max Size.  These sizes are relative to the view of the camera.
	*/
	void setFlareMinSize(float fm){if(fm == 0.1) return; fprintf_s(mFile, "setAttr \".fm\" %f;\n", fm);}
	/*
	<b>Flare Min Size:</b> The size of the lens flare
	circles is randomized between the Flare Min Size and
	Flare Max Size.  These sizes are relative to the view of the camera.
	*/
	void setFlareMinSize(const FloatID& fm){fprintf_s(mFile,"connectAttr \"");fm.write(mFile);fprintf_s(mFile,"\" \"%s.fm\";\n",mName.c_str());}
	/*<b>Flare Max Size</b>.  See Flare Min Size.*/
	void setFlareMaxSize(float fa){if(fa == 1.0) return; fprintf_s(mFile, "setAttr \".fa\" %f;\n", fa);}
	/*<b>Flare Max Size</b>.  See Flare Min Size.*/
	void setFlareMaxSize(const FloatID& fa){fprintf_s(mFile,"connectAttr \"");fa.write(mFile);fprintf_s(mFile,"\" \"%s.fa\";\n",mName.c_str());}
	/*
	<b>Flare Col Spread:</b>  The hue of flare color
	is randomized, centered on the Flare Color value.
	Increase Flare Col Spread to allow more variation
	in the colors.
	<p/>Note that this will have seem to have no effect if the base
	color of the flare is white or a shade of grey.
	*/
	void setFlareColSpread(float lc){if(lc == 0.5) return; fprintf_s(mFile, "setAttr \".lc\" %f;\n", lc);}
	/*
	<b>Flare Col Spread:</b>  The hue of flare color
	is randomized, centered on the Flare Color value.
	Increase Flare Col Spread to allow more variation
	in the colors.
	<p/>Note that this will have seem to have no effect if the base
	color of the flare is white or a shade of grey.
	*/
	void setFlareColSpread(const FloatID& lc){fprintf_s(mFile,"connectAttr \"");lc.write(mFile);fprintf_s(mFile,"\" \"%s.lc\";\n",mName.c_str());}
	/*
	<b>Flare Focus</b> controls the sharpness of the circle
	edges.  Increase this value to make the circles sharper.
	*/
	void setFlareFocus(float ff){if(ff == 0.6) return; fprintf_s(mFile, "setAttr \".ff\" %f;\n", ff);}
	/*
	<b>Flare Focus</b> controls the sharpness of the circle
	edges.  Increase this value to make the circles sharper.
	*/
	void setFlareFocus(const FloatID& ff){fprintf_s(mFile,"connectAttr \"");ff.write(mFile);fprintf_s(mFile,"\" \"%s.ff\";\n",mName.c_str());}
	/*
	<b>Flare Vertical</b> and Flare Horizontal control
	the axis of the flare relative to the center of the
	image.  If the light source moves, the flare will appear
	to rotate through this point.
	*/
	void setFlareVertical(float fv){if(fv == 1.0) return; fprintf_s(mFile, "setAttr \".fv\" %f;\n", fv);}
	/*
	<b>Flare Vertical</b> and Flare Horizontal control
	the axis of the flare relative to the center of the
	image.  If the light source moves, the flare will appear
	to rotate through this point.
	*/
	void setFlareVertical(const FloatID& fv){fprintf_s(mFile,"connectAttr \"");fv.write(mFile);fprintf_s(mFile,"\" \"%s.fv\";\n",mName.c_str());}
	/*<b>Flare Horizontal:</b> See Flare Vertical (above)*/
	void setFlareHorizontal(float fh){if(fh == 1.0) return; fprintf_s(mFile, "setAttr \".fh\" %f;\n", fh);}
	/*<b>Flare Horizontal:</b> See Flare Vertical (above)*/
	void setFlareHorizontal(const FloatID& fh){fprintf_s(mFile,"connectAttr \"");fh.write(mFile);fprintf_s(mFile,"\" \"%s.fh\";\n",mName.c_str());}
	/*
	<b>Flare Length</b> controls the length of the flare
	effect relative to the light location.  If Flare Length
	is small, all circles will overlap the light.  If
	Flare Length is large, the circles will spread out
	across the image.
	<p/>The Flare Length value has no
	effect if the Flare Vertical and Flare Horizontal
	attributes are both 0.
	*/
	void setFlareLength(float fl){if(fl == 1.0) return; fprintf_s(mFile, "setAttr \".fl\" %f;\n", fl);}
	/*
	<b>Flare Length</b> controls the length of the flare
	effect relative to the light location.  If Flare Length
	is small, all circles will overlap the light.  If
	Flare Length is large, the circles will spread out
	across the image.
	<p/>The Flare Length value has no
	effect if the Flare Vertical and Flare Horizontal
	attributes are both 0.
	*/
	void setFlareLength(const FloatID& fl){fprintf_s(mFile,"connectAttr \"");fl.write(mFile);fprintf_s(mFile,"\" \"%s.fl\";\n",mName.c_str());}
	/*
	<b>Hexagon Flare</b> makes the flare elements shaped
	like hexagons rather than circles.
	*/
	void setHexagonFlare(bool hf){if(hf == false) return; fprintf_s(mFile, "setAttr \".hf\" %i;\n", hf);}
	/*
	<b>Hexagon Flare</b> makes the flare elements shaped
	like hexagons rather than circles.
	*/
	void setHexagonFlare(const BoolID& hf){fprintf_s(mFile,"connectAttr \"");hf.write(mFile);fprintf_s(mFile,"\" \"%s.hf\";\n",mName.c_str());}
	/*
	<b>Glow Intensity</b> controls the brightness of
	the glow. As the Intensity value increases, so does
	the apparent size of the glow effect. A negative
	Glow Intensity value subtracts from other glows.
	*/
	void setGlowIntensity(float gi){if(gi == 1.0) return; fprintf_s(mFile, "setAttr \".gi\" %f;\n", gi);}
	/*
	<b>Glow Intensity</b> controls the brightness of
	the glow. As the Intensity value increases, so does
	the apparent size of the glow effect. A negative
	Glow Intensity value subtracts from other glows.
	*/
	void setGlowIntensity(const FloatID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.gi\";\n",mName.c_str());}
	/*
	<b>Halo Intensity</b> controls the brightness of the
	halo. As the Intensity value increases, so does the
	apparent size of the halo effect.
	*/
	void setHaloIntensity(float hi){if(hi == 1.0) return; fprintf_s(mFile, "setAttr \".hi\" %f;\n", hi);}
	/*
	<b>Halo Intensity</b> controls the brightness of the
	halo. As the Intensity value increases, so does the
	apparent size of the halo effect.
	*/
	void setHaloIntensity(const FloatID& hi){fprintf_s(mFile,"connectAttr \"");hi.write(mFile);fprintf_s(mFile,"\" \"%s.hi\";\n",mName.c_str());}
	/*Fog intensity (not implemented).*/
	void setFogIntensity(float oi){if(oi == 1.0) return; fprintf_s(mFile, "setAttr \".oi\" %f;\n", oi);}
	/*Fog intensity (not implemented).*/
	void setFogIntensity(const FloatID& oi){fprintf_s(mFile,"connectAttr \"");oi.write(mFile);fprintf_s(mFile,"\" \"%s.oi\";\n",mName.c_str());}
	/*<b>Glow Spread</b> controls the size of the glow effect.*/
	void setGlowSpread(float gs){if(gs == 1.0) return; fprintf_s(mFile, "setAttr \".gs\" %f;\n", gs);}
	/*<b>Glow Spread</b> controls the size of the glow effect.*/
	void setGlowSpread(const FloatID& gs){fprintf_s(mFile,"connectAttr \"");gs.write(mFile);fprintf_s(mFile,"\" \"%s.gs\";\n",mName.c_str());}
	/*
	<b>Halo Spread</b> controls the size of the halo effect.
	Halo Spread also controls the size of the glow if Glow Type
	is set to Rim Halo.  Halo size is gererally larger than
	glow size when their spreads are the same.
	*/
	void setHaloSpread(float hs){if(hs == 1.0) return; fprintf_s(mFile, "setAttr \".hs\" %f;\n", hs);}
	/*
	<b>Halo Spread</b> controls the size of the halo effect.
	Halo Spread also controls the size of the glow if Glow Type
	is set to Rim Halo.  Halo size is gererally larger than
	glow size when their spreads are the same.
	*/
	void setHaloSpread(const FloatID& hs){fprintf_s(mFile,"connectAttr \"");hs.write(mFile);fprintf_s(mFile,"\" \"%s.hs\";\n",mName.c_str());}
	/*Fog spread (not implemented).*/
	void setFogSpread(float fs){if(fs == 1.0) return; fprintf_s(mFile, "setAttr \".fs\" %f;\n", fs);}
	/*Fog spread (not implemented).*/
	void setFogSpread(const FloatID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs\";\n",mName.c_str());}
	/*
	<b>Glow Noise</b> controls the appearance of
	of noise (random fluctuations) in the glow.
	*/
	void setGlowNoise(float gd){if(gd == 0.0) return; fprintf_s(mFile, "setAttr \".gd\" %f;\n", gd);}
	/*
	<b>Glow Noise</b> controls the appearance of
	of noise (random fluctuations) in the glow.
	*/
	void setGlowNoise(const FloatID& gd){fprintf_s(mFile,"connectAttr \"");gd.write(mFile);fprintf_s(mFile,"\" \"%s.gd\";\n",mName.c_str());}
	/*Fog 2Dnoise (not implemented)*/
	void setFogNoise(float fd){if(fd == 0.0) return; fprintf_s(mFile, "setAttr \".fd\" %f;\n", fd);}
	/*Fog 2Dnoise (not implemented)*/
	void setFogNoise(const FloatID& fd){fprintf_s(mFile,"connectAttr \"");fd.write(mFile);fprintf_s(mFile,"\" \"%s.fd\";\n",mName.c_str());}
	/*
	<b>Glow Radial Noise</b> randomizes the spread of
	the glow to simulate starburst effects and eyelashes
	refracting light. Negative values of Glow Radial Noise
	produce thicker noise
	*/
	void setGlowRadialNoise(float gn){if(gn == 0.0) return; fprintf_s(mFile, "setAttr \".gn\" %f;\n", gn);}
	/*
	<b>Glow Radial Noise</b> randomizes the spread of
	the glow to simulate starburst effects and eyelashes
	refracting light. Negative values of Glow Radial Noise
	produce thicker noise
	*/
	void setGlowRadialNoise(const FloatID& gn){fprintf_s(mFile,"connectAttr \"");gn.write(mFile);fprintf_s(mFile,"\" \"%s.gn\";\n",mName.c_str());}
	/*Fog radial noise (not implemented)*/
	void setFogRadialNoise(float fz){if(fz == 0.0) return; fprintf_s(mFile, "setAttr \".fz\" %f;\n", fz);}
	/*Fog radial noise (not implemented)*/
	void setFogRadialNoise(const FloatID& fz){fprintf_s(mFile,"connectAttr \"");fz.write(mFile);fprintf_s(mFile,"\" \"%s.fz\";\n",mName.c_str());}
	/*
	<b>Glow Star Level</b> simulates camera star filter
	effects.
	*/
	void setGlowStarLevel(float gv){if(gv == 3.0) return; fprintf_s(mFile, "setAttr \".gv\" %f;\n", gv);}
	/*
	<b>Glow Star Level</b> simulates camera star filter
	effects.
	*/
	void setGlowStarLevel(const FloatID& gv){fprintf_s(mFile,"connectAttr \"");gv.write(mFile);fprintf_s(mFile,"\" \"%s.gv\";\n",mName.c_str());}
	/*Fog star level (not implemented)*/
	void setFogStarlevel(float fe){if(fe == 0.0) return; fprintf_s(mFile, "setAttr \".fe\" %f;\n", fe);}
	/*Fog star level (not implemented)*/
	void setFogStarlevel(const FloatID& fe){fprintf_s(mFile,"connectAttr \"");fe.write(mFile);fprintf_s(mFile,"\" \"%s.fe\";\n",mName.c_str());}
	/*
	<b>Glow Opacity</b> controls the amount that the
	light's glow obscures objects behind it. Increase
	Glow Opacity to make it obscure objects more.
	*/
	void setGlowOpacity(float go){if(go == 0.0) return; fprintf_s(mFile, "setAttr \".go\" %f;\n", go);}
	/*
	<b>Glow Opacity</b> controls the amount that the
	light's glow obscures objects behind it. Increase
	Glow Opacity to make it obscure objects more.
	*/
	void setGlowOpacity(const FloatID& go){fprintf_s(mFile,"connectAttr \"");go.write(mFile);fprintf_s(mFile,"\" \"%s.go\";\n",mName.c_str());}
	/*Fog opacity (not implemented)*/
	void setFogOpacity(float fo){if(fo == 0.0) return; fprintf_s(mFile, "setAttr \".fo\" %f;\n", fo);}
	/*Fog opacity (not implemented)*/
	void setFogOpacity(const FloatID& fo){fprintf_s(mFile,"connectAttr \"");fo.write(mFile);fprintf_s(mFile,"\" \"%s.fo\";\n",mName.c_str());}
	/*
	<b>Radial Frequency</b> controls the frequency of
	the Radial Noise.  Increase this to make the noise
	more fine-grained.
	*/
	void setRadialFrequency(float rf){if(rf == 0.5) return; fprintf_s(mFile, "setAttr \".rf\" %f;\n", rf);}
	/*
	<b>Radial Frequency</b> controls the frequency of
	the Radial Noise.  Increase this to make the noise
	more fine-grained.
	*/
	void setRadialFrequency(const FloatID& rf){fprintf_s(mFile,"connectAttr \"");rf.write(mFile);fprintf_s(mFile,"\" \"%s.rf\";\n",mName.c_str());}
	/*
	<b>Star Points</b> controls the number of points
	on glow star filter effects.  Set Star Points to
	1 to produce a comet-like effect, or more points
	to make a more regular, star-like glow effect.
	*/
	void setStarPoints(float sp){if(sp == 4.0) return; fprintf_s(mFile, "setAttr \".sp\" %f;\n", sp);}
	/*
	<b>Star Points</b> controls the number of points
	on glow star filter effects.  Set Star Points to
	1 to produce a comet-like effect, or more points
	to make a more regular, star-like glow effect.
	*/
	void setStarPoints(const FloatID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*
	<b>Rotation</b> controls the rotated position of
	the star points.  You can animate this to make the
	light glows seem to "roll".
	*/
	void setRotation(float ra){if(ra == 0.0) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	<b>Rotation</b> controls the rotated position of
	the star points.  You can animate this to make the
	light glows seem to "roll".
	*/
	void setRotation(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*
	<b>Noise U Scale</b> is used to scale the
	noise (random fluctuations) in the glow.  Increasing
	Noise U Scale will seem to compress the noise vertically.
	*/
	void setNoiseUscale(float nu){if(nu == 1.0) return; fprintf_s(mFile, "setAttr \".nu\" %f;\n", nu);}
	/*
	<b>Noise U Scale</b> is used to scale the
	noise (random fluctuations) in the glow.  Increasing
	Noise U Scale will seem to compress the noise vertically.
	*/
	void setNoiseUscale(const FloatID& nu){fprintf_s(mFile,"connectAttr \"");nu.write(mFile);fprintf_s(mFile,"\" \"%s.nu\";\n",mName.c_str());}
	/*
	<b>Noise V Scale</b> is used to scale the
	noise (random fluctuations) in the glow.  Increasing
	Noise V Scale will seem to compress the noise horizontally.
	*/
	void setNoiseVscale(float nv){if(nv == 1.0) return; fprintf_s(mFile, "setAttr \".nv\" %f;\n", nv);}
	/*
	<b>Noise V Scale</b> is used to scale the
	noise (random fluctuations) in the glow.  Increasing
	Noise V Scale will seem to compress the noise horizontally.
	*/
	void setNoiseVscale(const FloatID& nv){fprintf_s(mFile,"connectAttr \"");nv.write(mFile);fprintf_s(mFile,"\" \"%s.nv\";\n",mName.c_str());}
	/*
	<b>Noise U Offset</b> can be used to move the
	noise vertically.
	*/
	void setNoiseUoffset(float ni){if(ni == 1.0) return; fprintf_s(mFile, "setAttr \".ni\" %f;\n", ni);}
	/*
	<b>Noise U Offset</b> can be used to move the
	noise vertically.
	*/
	void setNoiseUoffset(const FloatID& ni){fprintf_s(mFile,"connectAttr \"");ni.write(mFile);fprintf_s(mFile,"\" \"%s.ni\";\n",mName.c_str());}
	/*
	<b>Noise V Offset</b> can be used to move the
	noise horizontally.
	*/
	void setNoiseVoffset(float nf){if(nf == 0.5) return; fprintf_s(mFile, "setAttr \".nf\" %f;\n", nf);}
	/*
	<b>Noise V Offset</b> can be used to move the
	noise horizontally.
	*/
	void setNoiseVoffset(const FloatID& nf){fprintf_s(mFile,"connectAttr \"");nf.write(mFile);fprintf_s(mFile,"\" \"%s.nf\";\n",mName.c_str());}
	/*
	<b>Noise Threshold</b> is the cutoff value for
	the 2d noise.  As Threshold approaches 0, the
	noise breaks up into smaller patches.
	*/
	void setNoiseThreshold(float nt){if(nt == 0.5) return; fprintf_s(mFile, "setAttr \".nt\" %f;\n", nt);}
	/*
	<b>Noise Threshold</b> is the cutoff value for
	the 2d noise.  As Threshold approaches 0, the
	noise breaks up into smaller patches.
	*/
	void setNoiseThreshold(const FloatID& nt){fprintf_s(mFile,"connectAttr \"");nt.write(mFile);fprintf_s(mFile,"\" \"%s.nt\";\n",mName.c_str());}
	/*
	<b>Ignore Light</b>: Ignores missing connection to a light.
	<p/>As a default, an optical effect needs to be
	connected to a light, or it will be ignored at render time. When
	this attribute is turned on, the effect will be rendered even if
	no light is connected.
	<br/>For example,
	you could create a Locator object in the scene, and
	attach its World Matrix attribute to the Light World Mat
	of this node. If you then turn on Ignore Light, you
	have a glow effect that you can position by moving the
	locator.
	*/
	void setIgnoreLight(bool il){if(il == false) return; fprintf_s(mFile, "setAttr \".il\" %i;\n", il);}
	/*
	<b>Ignore Light</b>: Ignores missing connection to a light.
	<p/>As a default, an optical effect needs to be
	connected to a light, or it will be ignored at render time. When
	this attribute is turned on, the effect will be rendered even if
	no light is connected.
	<br/>For example,
	you could create a Locator object in the scene, and
	attach its World Matrix attribute to the Light World Mat
	of this node. If you then turn on Ignore Light, you
	have a glow effect that you can position by moving the
	locator.
	*/
	void setIgnoreLight(const BoolID& il){fprintf_s(mFile,"connectAttr \"");il.write(mFile);fprintf_s(mFile,"\" \"%s.il\";\n",mName.c_str());}
	/*
	<b>Light World Mat</b>:  This is used to keep the
	light glow effect centered on the light.  The World
	Matrix attribute of a light shape should be connected
	to this attribute.
	*/
	void setLightWorldMat(const matrix& lw){if(lw == identity) return; fprintf_s(mFile, "setAttr \".lw\" -type \"matrix\" ");lw.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Light Connection</b>.  This attribute should be
	connected to the Light Glow attribute of the light
	shape.
	*/
	void setLightConnection(const MessageID& ln){fprintf_s(mFile,"connectAttr \"");ln.write(mFile);fprintf_s(mFile,"\" \"%s.ln\";\n",mName.c_str());}
	/*
	<b>Glow Visibility</b> controls the fractional
	visibility of the glow effect.  Normally, this
	attribute is controlled by a piece of geometry
	automatically created by the system.
	<p/>For example, when you add glow to a Point Light,
	a sphere is created. The sphere's Visible Fraction
	attribute drives Glow Visibility, so that as the sphere
	is occluded, the glow stops.
	<p/>For Spotlights, a 'directed disc' is created.  The
	glow is only visible when the disc (and therefore
	the spotlight) is facing the camera.
	*/
	void setGlowVisibility(float gvb){if(gvb == 1.0) return; fprintf_s(mFile, "setAttr \".gvb\" %f;\n", gvb);}
	/*
	<b>Light Color</b> is the color of the light that
	this glow effect is attached to.  The Color attribute
	of the light shape should be connected to this node.
	*/
	void setLightColor(const float3& lr){if(lr == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".lr\" -type \"float3\" ");lr.write(mFile);fprintf_s(mFile,";\n");}
	/*The red component of Light Color*/
	void setLightColorR(float lcr){if(lcr == 0.0) return; fprintf_s(mFile, "setAttr \".lr.lcr\" %f;\n", lcr);}
	/*The green component of Light Color*/
	void setLightColorG(float lcg){if(lcg == 0.0) return; fprintf_s(mFile, "setAttr \".lr.lcg\" %f;\n", lcg);}
	/*The blue component of Light Color*/
	void setLightColorB(float lgb){if(lgb == 0.0) return; fprintf_s(mFile, "setAttr \".lr.lgb\" %f;\n", lgb);}
	/*The visibility of the light. (not implemented)*/
	void setVisibility(const float3& vb){if(vb == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".vb\" -type \"float3\" ");vb.write(mFile);fprintf_s(mFile,";\n");}
	/*The red-component of the visibility of the light.*/
	void setVisibilityR(float vbr){if(vbr == 0.0) return; fprintf_s(mFile, "setAttr \".vb.vbr\" %f;\n", vbr);}
	/*The green-component of the visibility of the light.*/
	void setVisibilityG(float vbg){if(vbg == 0.0) return; fprintf_s(mFile, "setAttr \".vb.vbg\" %f;\n", vbg);}
	/*The blue-component of the visibility of the light.*/
	void setVisibilityB(float vbb){if(vbb == 0.0) return; fprintf_s(mFile, "setAttr \".vb.vbb\" %f;\n", vbb);}
	/*
	<b>Active</b> controls whether the light glow is
	on or not.  Turn off Active to make the effect disappear.
	*/
	BoolID getActive(){char buffer[4096];sprintf_s (buffer, "%s.act",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Type</b> controls the appearance of the light
	glow.  Possible settings are:
	<ul>
	<b>None:</b> No glow.<p/>
	<b>Linear:</b> Glow slowly diminishes from the center of the light<p/>
	<b>Exponential:</b> Glow quickly diminishes from the center of the light<p/>
	<b>Ball:</b> Glow diminishes faster towards a distance (from the light
	center) specified by the Glow Spread attribute.<p/>
	<b>Lens Flare:</b> Lower frequencies (red) refract (or spread)
	more than the higher frequencies (blue).<p/>
	<b>Rim Halo:</b> This is like Lens Flare, but the Glow starts
	at a certain distance from the
	light, controlled by the Glow Spread attribute.
	</ul>
	*/
	UnsignedintID getGlowType(){char buffer[4096];sprintf_s (buffer, "%s.gt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Halo Type</b> controls the type of halo the
	light produces when viewed directly. Halo is similar
	to Glow, except that the falloff is more gradual.
	The available types are:
	<ul>
	<b>None:</b> No halo.<p/>
	<b>Linear:</b> Halo slowly diminishes from the center of the light<p/>
	<b>Exponential:</b> Halo quickly diminishes from the center of the light<p/>
	<b>Ball:</b> Halo diminishes faster towards a distance (from the light
	center) specified by the Halo Spread attribute.<p/>
	<b>Lens Flare:</b> Simulates a bright light source illuminating
	the surfaces of several camera lenses. The intensity of the
	flare is determined by the Halo Intensity attribute. The size
	of the flare circles is relative to the field of
	view of the camera.<p/>
	<b>Rim Halo:</b> Forms a circular ring with a soft central
	glow.  The size of the ring is controlled by the Halo Spread
	attribute.
	</ul>
	*/
	UnsignedintID getHaloType(){char buffer[4096];sprintf_s (buffer, "%s.ht",mName.c_str());return (const char*)buffer;}
	/*What type of fog (this feature is not implemented).*/
	ShortID getFogType(){char buffer[4096];sprintf_s (buffer, "%s.ft",mName.c_str());return (const char*)buffer;}
	/*
	<b>Lens Flare</b> Simulates a bright light source
	illuminating the surfaces of several camera lenses.
	The intensity of the flare is determined by the
	Flare Intensity attribute. The size of the flare circles
	created is relative to the field of view of the camera.
	The Lens Flare attribute is not available for ambient lights.
	*/
	BoolID getLensFlare(){char buffer[4096];sprintf_s (buffer, "%s.lf",mName.c_str());return (const char*)buffer;}
	/*<b>Glow Color</b> controls the basic color of the light glow..*/
	Float3ID getGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.gc",mName.c_str());return (const char*)buffer;}
	/*The red component of Glow Color.*/
	FloatID getGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.gc.gr",mName.c_str());return (const char*)buffer;}
	/*The green component of Glow Color.*/
	FloatID getGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.gc.gg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Glow Color.*/
	FloatID getGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.gc.gb",mName.c_str());return (const char*)buffer;}
	/*<b>Halo Color</b> controsl the basic color of the Halo.*/
	Float3ID getHaloColor(){char buffer[4096];sprintf_s (buffer, "%s.hc",mName.c_str());return (const char*)buffer;}
	/*The red component of Halo Color.*/
	FloatID getHaloColorR(){char buffer[4096];sprintf_s (buffer, "%s.hc.hr",mName.c_str());return (const char*)buffer;}
	/*The red component of Halo Color.*/
	FloatID getHaloColorG(){char buffer[4096];sprintf_s (buffer, "%s.hc.hg",mName.c_str());return (const char*)buffer;}
	/*The red component of Halo Color.*/
	FloatID getHaloColorB(){char buffer[4096];sprintf_s (buffer, "%s.hc.hb",mName.c_str());return (const char*)buffer;}
	/*The fog color (not implemented).*/
	Float3ID getFogColor(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*The red component of the fog color (not implemented).*/
	FloatID getFogColorR(){char buffer[4096];sprintf_s (buffer, "%s.fc.fr",mName.c_str());return (const char*)buffer;}
	/*The red component of the fog color (not implemented).*/
	FloatID getFogColorG(){char buffer[4096];sprintf_s (buffer, "%s.fc.fg",mName.c_str());return (const char*)buffer;}
	/*The red component of the fog color (not implemented).*/
	FloatID getFogColorB(){char buffer[4096];sprintf_s (buffer, "%s.fc.fb",mName.c_str());return (const char*)buffer;}
	/*<b>Flare Color</b> controls the basic color of Lens Flare.*/
	Float3ID getFlareColor(){char buffer[4096];sprintf_s (buffer, "%s.rc",mName.c_str());return (const char*)buffer;}
	/*The red component of Flare Color.*/
	FloatID getFlareColorR(){char buffer[4096];sprintf_s (buffer, "%s.rc.rr",mName.c_str());return (const char*)buffer;}
	/*The red component of Flare Color.*/
	FloatID getFlareColorG(){char buffer[4096];sprintf_s (buffer, "%s.rc.rg",mName.c_str());return (const char*)buffer;}
	/*The red component of Flare Color.*/
	FloatID getFlareColorB(){char buffer[4096];sprintf_s (buffer, "%s.rc.rb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Flare Intensity</b> controls the brightness of
	the flare effect.
	*/
	FloatID getFlareIntensity(){char buffer[4096];sprintf_s (buffer, "%s.fi",mName.c_str());return (const char*)buffer;}
	/*
	<b>Flare Num Circles</b> controls the number of circles
	in the flare effect.
	<p/>
	If Num Circles is very large, rendering times may be
	Tint32, especially if Flare Min Size and Flare Max Size
	are large, and Flare Color is textured.
	*/
	FloatID getFlareNumCircles(){char buffer[4096];sprintf_s (buffer, "%s.fn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Flare Min Size:</b> The size of the lens flare
	circles is randomized between the Flare Min Size and
	Flare Max Size.  These sizes are relative to the view of the camera.
	*/
	FloatID getFlareMinSize(){char buffer[4096];sprintf_s (buffer, "%s.fm",mName.c_str());return (const char*)buffer;}
	/*<b>Flare Max Size</b>.  See Flare Min Size.*/
	FloatID getFlareMaxSize(){char buffer[4096];sprintf_s (buffer, "%s.fa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Flare Col Spread:</b>  The hue of flare color
	is randomized, centered on the Flare Color value.
	Increase Flare Col Spread to allow more variation
	in the colors.
	<p/>Note that this will have seem to have no effect if the base
	color of the flare is white or a shade of grey.
	*/
	FloatID getFlareColSpread(){char buffer[4096];sprintf_s (buffer, "%s.lc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Flare Focus</b> controls the sharpness of the circle
	edges.  Increase this value to make the circles sharper.
	*/
	FloatID getFlareFocus(){char buffer[4096];sprintf_s (buffer, "%s.ff",mName.c_str());return (const char*)buffer;}
	/*
	<b>Flare Vertical</b> and Flare Horizontal control
	the axis of the flare relative to the center of the
	image.  If the light source moves, the flare will appear
	to rotate through this point.
	*/
	FloatID getFlareVertical(){char buffer[4096];sprintf_s (buffer, "%s.fv",mName.c_str());return (const char*)buffer;}
	/*<b>Flare Horizontal:</b> See Flare Vertical (above)*/
	FloatID getFlareHorizontal(){char buffer[4096];sprintf_s (buffer, "%s.fh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Flare Length</b> controls the length of the flare
	effect relative to the light location.  If Flare Length
	is small, all circles will overlap the light.  If
	Flare Length is large, the circles will spread out
	across the image.
	<p/>The Flare Length value has no
	effect if the Flare Vertical and Flare Horizontal
	attributes are both 0.
	*/
	FloatID getFlareLength(){char buffer[4096];sprintf_s (buffer, "%s.fl",mName.c_str());return (const char*)buffer;}
	/*
	<b>Hexagon Flare</b> makes the flare elements shaped
	like hexagons rather than circles.
	*/
	BoolID getHexagonFlare(){char buffer[4096];sprintf_s (buffer, "%s.hf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Intensity</b> controls the brightness of
	the glow. As the Intensity value increases, so does
	the apparent size of the glow effect. A negative
	Glow Intensity value subtracts from other glows.
	*/
	FloatID getGlowIntensity(){char buffer[4096];sprintf_s (buffer, "%s.gi",mName.c_str());return (const char*)buffer;}
	/*
	<b>Halo Intensity</b> controls the brightness of the
	halo. As the Intensity value increases, so does the
	apparent size of the halo effect.
	*/
	FloatID getHaloIntensity(){char buffer[4096];sprintf_s (buffer, "%s.hi",mName.c_str());return (const char*)buffer;}
	/*Fog intensity (not implemented).*/
	FloatID getFogIntensity(){char buffer[4096];sprintf_s (buffer, "%s.oi",mName.c_str());return (const char*)buffer;}
	/*<b>Glow Spread</b> controls the size of the glow effect.*/
	FloatID getGlowSpread(){char buffer[4096];sprintf_s (buffer, "%s.gs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Halo Spread</b> controls the size of the halo effect.
	Halo Spread also controls the size of the glow if Glow Type
	is set to Rim Halo.  Halo size is gererally larger than
	glow size when their spreads are the same.
	*/
	FloatID getHaloSpread(){char buffer[4096];sprintf_s (buffer, "%s.hs",mName.c_str());return (const char*)buffer;}
	/*Fog spread (not implemented).*/
	FloatID getFogSpread(){char buffer[4096];sprintf_s (buffer, "%s.fs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Noise</b> controls the appearance of
	of noise (random fluctuations) in the glow.
	*/
	FloatID getGlowNoise(){char buffer[4096];sprintf_s (buffer, "%s.gd",mName.c_str());return (const char*)buffer;}
	/*Fog 2Dnoise (not implemented)*/
	FloatID getFogNoise(){char buffer[4096];sprintf_s (buffer, "%s.fd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Radial Noise</b> randomizes the spread of
	the glow to simulate starburst effects and eyelashes
	refracting light. Negative values of Glow Radial Noise
	produce thicker noise
	*/
	FloatID getGlowRadialNoise(){char buffer[4096];sprintf_s (buffer, "%s.gn",mName.c_str());return (const char*)buffer;}
	/*Fog radial noise (not implemented)*/
	FloatID getFogRadialNoise(){char buffer[4096];sprintf_s (buffer, "%s.fz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Star Level</b> simulates camera star filter
	effects.
	*/
	FloatID getGlowStarLevel(){char buffer[4096];sprintf_s (buffer, "%s.gv",mName.c_str());return (const char*)buffer;}
	/*Fog star level (not implemented)*/
	FloatID getFogStarlevel(){char buffer[4096];sprintf_s (buffer, "%s.fe",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Opacity</b> controls the amount that the
	light's glow obscures objects behind it. Increase
	Glow Opacity to make it obscure objects more.
	*/
	FloatID getGlowOpacity(){char buffer[4096];sprintf_s (buffer, "%s.go",mName.c_str());return (const char*)buffer;}
	/*Fog opacity (not implemented)*/
	FloatID getFogOpacity(){char buffer[4096];sprintf_s (buffer, "%s.fo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Radial Frequency</b> controls the frequency of
	the Radial Noise.  Increase this to make the noise
	more fine-grained.
	*/
	FloatID getRadialFrequency(){char buffer[4096];sprintf_s (buffer, "%s.rf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Star Points</b> controls the number of points
	on glow star filter effects.  Set Star Points to
	1 to produce a comet-like effect, or more points
	to make a more regular, star-like glow effect.
	*/
	FloatID getStarPoints(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Rotation</b> controls the rotated position of
	the star points.  You can animate this to make the
	light glows seem to "roll".
	*/
	FloatID getRotation(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise U Scale</b> is used to scale the
	noise (random fluctuations) in the glow.  Increasing
	Noise U Scale will seem to compress the noise vertically.
	*/
	FloatID getNoiseUscale(){char buffer[4096];sprintf_s (buffer, "%s.nu",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise V Scale</b> is used to scale the
	noise (random fluctuations) in the glow.  Increasing
	Noise V Scale will seem to compress the noise horizontally.
	*/
	FloatID getNoiseVscale(){char buffer[4096];sprintf_s (buffer, "%s.nv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise U Offset</b> can be used to move the
	noise vertically.
	*/
	FloatID getNoiseUoffset(){char buffer[4096];sprintf_s (buffer, "%s.ni",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise V Offset</b> can be used to move the
	noise horizontally.
	*/
	FloatID getNoiseVoffset(){char buffer[4096];sprintf_s (buffer, "%s.nf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Noise Threshold</b> is the cutoff value for
	the 2d noise.  As Threshold approaches 0, the
	noise breaks up into smaller patches.
	*/
	FloatID getNoiseThreshold(){char buffer[4096];sprintf_s (buffer, "%s.nt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ignore Light</b>: Ignores missing connection to a light.
	<p/>As a default, an optical effect needs to be
	connected to a light, or it will be ignored at render time. When
	this attribute is turned on, the effect will be rendered even if
	no light is connected.
	<br/>For example,
	you could create a Locator object in the scene, and
	attach its World Matrix attribute to the Light World Mat
	of this node. If you then turn on Ignore Light, you
	have a glow effect that you can position by moving the
	locator.
	*/
	BoolID getIgnoreLight(){char buffer[4096];sprintf_s (buffer, "%s.il",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Connection</b>.  This attribute should be
	connected to the Light Glow attribute of the light
	shape.
	*/
	MessageID getLightConnection(){char buffer[4096];sprintf_s (buffer, "%s.ln",mName.c_str());return (const char*)buffer;}
protected:
	OpticalFX(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OPTICALFX_H__
