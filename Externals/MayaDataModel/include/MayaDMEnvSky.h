/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVSKY_H__
#define __MayaDM_ENVSKY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTextureEnv.h"
namespace MayaDM
{
/*
The <b>Env Sky</b> texture is an environment map that generates images of a
 planetary atmosphere as seen from the surface of a planet.
 <p/>
 Sky attributes let you control the composition of the atmosphere and the
 cloud layer.  If no floor is specified, the environment below the horizon
 is a vertical mirror reflection of the environment above the horizon.
 If you specify a floor, you can set it to a color or use a texture map.
 <p/>
 If a floor is specified and the camera point-of-view drops below that
 floor, then the sky will turn red as a warning.
 <p/>
 You can use the Env Sky texture as a reflection map, by connecting
 its Out Color attribute to the Reflected Color attribute of an specular
 shader, such as Blinn or PhongE.  You can also use the Env Sky texture
 as a background, by connecting it to an image plane.  For best results,
 scale the sky so it is in proportion to the half-height of the image plane.
 <p/>
 Aside from the attributes listed here, Env Sky inherits additional
 attributes from <a href="textureEnv.html">TextureEnv</a>.
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class EnvSky : public TextureEnv
{
public:
public:
	EnvSky(FILE* file,const std::string& name,const std::string& parent=""):TextureEnv(file, name, parent, "envSky"){}
	virtual ~EnvSky(){}
	/*The current sample point that has to be shaded*/
	void setPointCamera(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointCamera(const Float3ID& rpc){fprintf_s(mFile,"connectAttr \"");rpc.write(mFile);fprintf_s(mFile,"\" \"%s.rpc\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setRefPointCameraX(const FloatID& rcx){fprintf_s(mFile,"connectAttr \"");rcx.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setRefPointCameraY(const FloatID& rcy){fprintf_s(mFile,"connectAttr \"");rcy.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setRefPointCameraZ(const FloatID& rcz){fprintf_s(mFile,"connectAttr \"");rcz.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcz\";\n",mName.c_str());}
	/*
	<b>Total Brightness</b> controls the overall brightness
	level of the environment.
	*/
	void setTotalBrightness(float tb){if(tb == 1.0) return; fprintf_s(mFile, "setAttr \".tb\" %f;\n", tb);}
	/*
	<b>Total Brightness</b> controls the overall brightness
	level of the environment.
	*/
	void setTotalBrightness(const FloatID& tb){fprintf_s(mFile,"connectAttr \"");tb.write(mFile);fprintf_s(mFile,"\" \"%s.tb\";\n",mName.c_str());}
	/*
	<b>Sun Brightness</b> controls how bright the sun is
	in the environment.  Note: this attribute only affects the brightness
	of the sun, and not its color.
	*/
	void setSunBrightness(const float3& su){if(su == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".su\" -type \"float3\" ");su.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Sun Brightness</b> controls how bright the sun is
	in the environment.  Note: this attribute only affects the brightness
	of the sun, and not its color.
	*/
	void setSunBrightness(const Float3ID& su){fprintf_s(mFile,"connectAttr \"");su.write(mFile);fprintf_s(mFile,"\" \"%s.su\";\n",mName.c_str());}
	/*The red component of Sun Brightness*/
	void setSunBrightnessR(float sur){if(sur == 0.0) return; fprintf_s(mFile, "setAttr \".su.sur\" %f;\n", sur);}
	/*The red component of Sun Brightness*/
	void setSunBrightnessR(const FloatID& sur){fprintf_s(mFile,"connectAttr \"");sur.write(mFile);fprintf_s(mFile,"\" \"%s.su.sur\";\n",mName.c_str());}
	/*The green component of Sun Brightness*/
	void setSunBrightnessG(float sug){if(sug == 0.0) return; fprintf_s(mFile, "setAttr \".su.sug\" %f;\n", sug);}
	/*The green component of Sun Brightness*/
	void setSunBrightnessG(const FloatID& sug){fprintf_s(mFile,"connectAttr \"");sug.write(mFile);fprintf_s(mFile,"\" \"%s.su.sug\";\n",mName.c_str());}
	/*The blue component of Sun Brightness*/
	void setSunBrightnessB(float sub){if(sub == 0.0) return; fprintf_s(mFile, "setAttr \".su.sub\" %f;\n", sub);}
	/*The blue component of Sun Brightness*/
	void setSunBrightnessB(const FloatID& sub){fprintf_s(mFile,"connectAttr \"");sub.write(mFile);fprintf_s(mFile,"\" \"%s.su.sub\";\n",mName.c_str());}
	/*
	<b>Halo Brightness</b> controls how bright the halo around
	the sun is.  Note: this attribute only affects the brightness
	of the halo, and not its color.
	*/
	void setHaloBrightness(const float3& hb){if(hb == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".hb\" -type \"float3\" ");hb.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Halo Brightness</b> controls how bright the halo around
	the sun is.  Note: this attribute only affects the brightness
	of the halo, and not its color.
	*/
	void setHaloBrightness(const Float3ID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.hb\";\n",mName.c_str());}
	/*The red component of Halo Brightness*/
	void setHaloBrightnessR(float hbr){if(hbr == 0.0) return; fprintf_s(mFile, "setAttr \".hb.hbr\" %f;\n", hbr);}
	/*The red component of Halo Brightness*/
	void setHaloBrightnessR(const FloatID& hbr){fprintf_s(mFile,"connectAttr \"");hbr.write(mFile);fprintf_s(mFile,"\" \"%s.hb.hbr\";\n",mName.c_str());}
	/*The green component of Halo Brightness*/
	void setHaloBrightnessG(float hbg){if(hbg == 0.0) return; fprintf_s(mFile, "setAttr \".hb.hbg\" %f;\n", hbg);}
	/*The green component of Halo Brightness*/
	void setHaloBrightnessG(const FloatID& hbg){fprintf_s(mFile,"connectAttr \"");hbg.write(mFile);fprintf_s(mFile,"\" \"%s.hb.hbg\";\n",mName.c_str());}
	/*The blue component of Halo Brightness*/
	void setHaloBrightnessB(float hbb){if(hbb == 0.0) return; fprintf_s(mFile, "setAttr \".hb.hbb\" %f;\n", hbb);}
	/*The blue component of Halo Brightness*/
	void setHaloBrightnessB(const FloatID& hbb){fprintf_s(mFile,"connectAttr \"");hbb.write(mFile);fprintf_s(mFile,"\" \"%s.hb.hbb\";\n",mName.c_str());}
	/*
	<b>Elevation</b> controls how high the sun is in the sky.
	An elevation of 0 degrees would put the sun at the horizon, and an
	elevation of 90 degrees would put it directly overhead.
	*/
	void setElevation(double e){if(e == 4) return; fprintf_s(mFile, "setAttr \".e\" %f;\n", e);}
	/*
	<b>Elevation</b> controls how high the sun is in the sky.
	An elevation of 0 degrees would put the sun at the horizon, and an
	elevation of 90 degrees would put it directly overhead.
	*/
	void setElevation(const DoubleID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e\";\n",mName.c_str());}
	/*
	<b>Azimuth</b> controls the position of the sun around a vertical
	axis.  Adjust this to move the sun around horizontally without
	changing its elevation.
	*/
	void setAzimuth(double az){if(az == 1) return; fprintf_s(mFile, "setAttr \".az\" %f;\n", az);}
	/*
	<b>Azimuth</b> controls the position of the sun around a vertical
	axis.  Adjust this to move the sun around horizontally without
	changing its elevation.
	*/
	void setAzimuth(const DoubleID& az){fprintf_s(mFile,"connectAttr \"");az.write(mFile);fprintf_s(mFile,"\" \"%s.az\";\n",mName.c_str());}
	/*<b>Size</b> controls the size (radius) of the disk of the sun.*/
	void setSize(float sz){if(sz == 0.531) return; fprintf_s(mFile, "setAttr \".sz\" %f;\n", sz);}
	/*<b>Size</b> controls the size (radius) of the disk of the sun.*/
	void setSize(const FloatID& sz){fprintf_s(mFile,"connectAttr \"");sz.write(mFile);fprintf_s(mFile,"\" \"%s.sz\";\n",mName.c_str());}
	/*
	<b>Blur</b> controls the size (radius) of the halo around
	the sun.
	*/
	void setBlur(float b){if(b == 1.0) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*
	<b>Blur</b> controls the size (radius) of the halo around
	the sun.
	*/
	void setBlur(const FloatID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*
	<b>Sky Brightness</b> is a color value that is multiplied
	by the basic sky color.  You can use this to brighten or
	darken or tint the sky.
	*/
	void setSkyBrightness(const float3& sk){if(sk == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".sk\" -type \"float3\" ");sk.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Sky Brightness</b> is a color value that is multiplied
	by the basic sky color.  You can use this to brighten or
	darken or tint the sky.
	*/
	void setSkyBrightness(const Float3ID& sk){fprintf_s(mFile,"connectAttr \"");sk.write(mFile);fprintf_s(mFile,"\" \"%s.sk\";\n",mName.c_str());}
	/*The red component of Sky Brightness*/
	void setSkyBrightnessR(float skr){if(skr == 0.0) return; fprintf_s(mFile, "setAttr \".sk.skr\" %f;\n", skr);}
	/*The red component of Sky Brightness*/
	void setSkyBrightnessR(const FloatID& skr){fprintf_s(mFile,"connectAttr \"");skr.write(mFile);fprintf_s(mFile,"\" \"%s.sk.skr\";\n",mName.c_str());}
	/*The green component of Sky Brightness*/
	void setSkyBrightnessG(float skg){if(skg == 0.0) return; fprintf_s(mFile, "setAttr \".sk.skg\" %f;\n", skg);}
	/*The green component of Sky Brightness*/
	void setSkyBrightnessG(const FloatID& skg){fprintf_s(mFile,"connectAttr \"");skg.write(mFile);fprintf_s(mFile,"\" \"%s.sk.skg\";\n",mName.c_str());}
	/*The blue component of Sky Brightness*/
	void setSkyBrightnessB(float skb){if(skb == 0.0) return; fprintf_s(mFile, "setAttr \".sk.skb\" %f;\n", skb);}
	/*The blue component of Sky Brightness*/
	void setSkyBrightnessB(const FloatID& skb){fprintf_s(mFile,"connectAttr \"");skb.write(mFile);fprintf_s(mFile,"\" \"%s.sk.skb\";\n",mName.c_str());}
	/*
	<b>Air Density</b> controls how light is scattered by
	the atmosphere, and therefore the "blueness" of the sky.
	To simulate high-altitude skies (which are black at the zenith,
	and blue near the horizon), set Air Density to values less
	than 1.0.  To simulate low-altitude skies (which are blue at
	the zenith, and white near the horizon), set Air Density to
	values greater than 1.0.
	*/
	void setAirDensity(float ad){if(ad == 1.0) return; fprintf_s(mFile, "setAttr \".ad\" %f;\n", ad);}
	/*
	<b>Air Density</b> controls how light is scattered by
	the atmosphere, and therefore the "blueness" of the sky.
	To simulate high-altitude skies (which are black at the zenith,
	and blue near the horizon), set Air Density to values less
	than 1.0.  To simulate low-altitude skies (which are blue at
	the zenith, and white near the horizon), set Air Density to
	values greater than 1.0.
	*/
	void setAirDensity(const FloatID& ad){fprintf_s(mFile,"connectAttr \"");ad.write(mFile);fprintf_s(mFile,"\" \"%s.ad\";\n",mName.c_str());}
	/*<b>Dust Density</b> density of the dust in the atmosphere.*/
	void setDustDensity(float dd){if(dd == 0.0) return; fprintf_s(mFile, "setAttr \".dd\" %f;\n", dd);}
	/*<b>Dust Density</b> density of the dust in the atmosphere.*/
	void setDustDensity(const FloatID& dd){fprintf_s(mFile,"connectAttr \"");dd.write(mFile);fprintf_s(mFile,"\" \"%s.dd\";\n",mName.c_str());}
	/*
	<b>Sky Thickness</b> controls the thickness of the atmosphere.
	When this is increased, light has to pass through more air,
	and is therefore scattered more, showing more color.
	*/
	void setSkyThickness(float st){if(st == 1000.0) return; fprintf_s(mFile, "setAttr \".st\" %f;\n", st);}
	/*
	<b>Sky Thickness</b> controls the thickness of the atmosphere.
	When this is increased, light has to pass through more air,
	and is therefore scattered more, showing more color.
	*/
	void setSkyThickness(const FloatID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*
	<b>Sky Radius</b> can be thought of as the size
	of the planet, epressed as a multiple of Sky Thickness.
	When you increase this, it affects the relative difference
	in light scattering between light coming from above and
	light coming from the horizon.  The bigger the planet,
	the more sunlight has to go through as the sun sets.
	<p/>
	Effectively, increasing this value will result in redder
	but dimmer sunsets.  (You can compensate for dimness by
	increasing the Sky Brightness)
	*/
	void setSkyRadius(float sr){if(sr == 50.0) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*
	<b>Sky Radius</b> can be thought of as the size
	of the planet, epressed as a multiple of Sky Thickness.
	When you increase this, it affects the relative difference
	in light scattering between light coming from above and
	light coming from the horizon.  The bigger the planet,
	the more sunlight has to go through as the sun sets.
	<p/>
	Effectively, increasing this value will result in redder
	but dimmer sunsets.  (You can compensate for dimness by
	increasing the Sky Brightness)
	*/
	void setSkyRadius(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	<b>Has Floor</b> controls whether there is a floor
	in the environment.  If you turn this off, the environment
	below the horizon is a mirror reflection of the environment
	above the horizon.
	*/
	void setHasFloor(bool hf){if(hf == true) return; fprintf_s(mFile, "setAttr \".hf\" %i;\n", hf);}
	/*
	<b>Has Floor</b> controls whether there is a floor
	in the environment.  If you turn this off, the environment
	below the horizon is a mirror reflection of the environment
	above the horizon.
	*/
	void setHasFloor(const BoolID& hf){fprintf_s(mFile,"connectAttr \"");hf.write(mFile);fprintf_s(mFile,"\" \"%s.hf\";\n",mName.c_str());}
	/*
	<b>Floor Color</b> controls the color of the floor, when
	Has Floor is turned on.  You can, of course, texture map this
	attribute to get interesting ground effects.
	*/
	void setFloorColor(const float3& fc){if(fc == float3(0.4, 0.4, 0.4)) return; fprintf_s(mFile, "setAttr \".fc\" -type \"float3\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Floor Color</b> controls the color of the floor, when
	Has Floor is turned on.  You can, of course, texture map this
	attribute to get interesting ground effects.
	*/
	void setFloorColor(const Float3ID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc\";\n",mName.c_str());}
	/*The red component of Floor Color*/
	void setFloorColorR(float fcr){if(fcr == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fcr\" %f;\n", fcr);}
	/*The red component of Floor Color*/
	void setFloorColorR(const FloatID& fcr){fprintf_s(mFile,"connectAttr \"");fcr.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcr\";\n",mName.c_str());}
	/*The green component of Floor Color*/
	void setFloorColorG(float fcg){if(fcg == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fcg\" %f;\n", fcg);}
	/*The green component of Floor Color*/
	void setFloorColorG(const FloatID& fcg){fprintf_s(mFile,"connectAttr \"");fcg.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcg\";\n",mName.c_str());}
	/*The blue component of Floor Color*/
	void setFloorColorB(float fcb){if(fcb == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fcb\" %f;\n", fcb);}
	/*The blue component of Floor Color*/
	void setFloorColorB(const FloatID& fcb){fprintf_s(mFile,"connectAttr \"");fcb.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcb\";\n",mName.c_str());}
	/*
	<b>Floor Altitude</b> controls the position of the floor
	plane relative to the vertical axis.  Increase this to
	move the floor up, decrease it to move the floor down.
	Remember to always keep your camera above the floor
	altitude.
	*/
	void setFloorAltitude(float fa){if(fa == -10.0) return; fprintf_s(mFile, "setAttr \".fa\" %f;\n", fa);}
	/*
	<b>Floor Altitude</b> controls the position of the floor
	plane relative to the vertical axis.  Increase this to
	move the floor up, decrease it to move the floor down.
	Remember to always keep your camera above the floor
	altitude.
	*/
	void setFloorAltitude(const FloatID& fa){fprintf_s(mFile,"connectAttr \"");fa.write(mFile);fprintf_s(mFile,"\" \"%s.fa\";\n",mName.c_str());}
	/*
	<b>Use Texture</b> controls whether or not Env Sky pays
	attention to the Cloud Texture attribute.  If you attach
	a Cloud or other fractal texture node to the Cloud Texture
	attribute, then you must turn on Use Texture to see the
	results.
	*/
	void setUseTexture(bool ut){if(ut == false) return; fprintf_s(mFile, "setAttr \".ut\" %i;\n", ut);}
	/*
	<b>Use Texture</b> controls whether or not Env Sky pays
	attention to the Cloud Texture attribute.  If you attach
	a Cloud or other fractal texture node to the Cloud Texture
	attribute, then you must turn on Use Texture to see the
	results.
	*/
	void setUseTexture(const BoolID& ut){fprintf_s(mFile,"connectAttr \"");ut.write(mFile);fprintf_s(mFile,"\" \"%s.ut\";\n",mName.c_str());}
	/*
	<b>Cloud Texture</b> lets you assign a layer of clouds
	to the sky.  Map a Cloud texture  or other fractal texture to this
	attribute.
	<p/><b>Note</b>: if you use this attribute, you must turn
	on the Use Texture attribute, or you will not see your clouds.
	*/
	void setCloudTexture(float ct){if(ct == 1.0) return; fprintf_s(mFile, "setAttr \".ct\" %f;\n", ct);}
	/*
	<b>Cloud Texture</b> lets you assign a layer of clouds
	to the sky.  Map a Cloud texture  or other fractal texture to this
	attribute.
	<p/><b>Note</b>: if you use this attribute, you must turn
	on the Use Texture attribute, or you will not see your clouds.
	*/
	void setCloudTexture(const FloatID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*
	<b>Cloud Brightness</b> sets the brightness of the ambient
	scattered light from the atmosphere.  This also depends on the
	current Elevation of the sun.
	*/
	void setCloudBrightness(const float3& cb){if(cb == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".cb\" -type \"float3\" ");cb.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Cloud Brightness</b> sets the brightness of the ambient
	scattered light from the atmosphere.  This also depends on the
	current Elevation of the sun.
	*/
	void setCloudBrightness(const Float3ID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cb\";\n",mName.c_str());}
	/*The red component of Cloud Brightness*/
	void setCloudBrightnessR(float cbr){if(cbr == 0.0) return; fprintf_s(mFile, "setAttr \".cb.cbr\" %f;\n", cbr);}
	/*The red component of Cloud Brightness*/
	void setCloudBrightnessR(const FloatID& cbr){fprintf_s(mFile,"connectAttr \"");cbr.write(mFile);fprintf_s(mFile,"\" \"%s.cb.cbr\";\n",mName.c_str());}
	/*The green component of Cloud Brightness*/
	void setCloudBrightnessG(float cbg){if(cbg == 0.0) return; fprintf_s(mFile, "setAttr \".cb.cbg\" %f;\n", cbg);}
	/*The green component of Cloud Brightness*/
	void setCloudBrightnessG(const FloatID& cbg){fprintf_s(mFile,"connectAttr \"");cbg.write(mFile);fprintf_s(mFile,"\" \"%s.cb.cbg\";\n",mName.c_str());}
	/*The blue component of Cloud Brightness*/
	void setCloudBrightnessB(float cbb){if(cbb == 0.0) return; fprintf_s(mFile, "setAttr \".cb.cbb\" %f;\n", cbb);}
	/*The blue component of Cloud Brightness*/
	void setCloudBrightnessB(const FloatID& cbb){fprintf_s(mFile,"connectAttr \"");cbb.write(mFile);fprintf_s(mFile,"\" \"%s.cb.cbb\";\n",mName.c_str());}
	/*
	<b>Sunset Brightness</b> controls the illumination of the
	clouds when the sun is below the horizon and the clouds
	are front-lit.  This is a very subtle effect and only
	occurs briefly after sunset.
	*/
	void setSunsetBrightness(const float3& ss){if(ss == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".ss\" -type \"float3\" ");ss.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Sunset Brightness</b> controls the illumination of the
	clouds when the sun is below the horizon and the clouds
	are front-lit.  This is a very subtle effect and only
	occurs briefly after sunset.
	*/
	void setSunsetBrightness(const Float3ID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*The red component of Sunset Brightness*/
	void setSunsetBrightnessR(float ssr){if(ssr == 0.0) return; fprintf_s(mFile, "setAttr \".ss.ssr\" %f;\n", ssr);}
	/*The red component of Sunset Brightness*/
	void setSunsetBrightnessR(const FloatID& ssr){fprintf_s(mFile,"connectAttr \"");ssr.write(mFile);fprintf_s(mFile,"\" \"%s.ss.ssr\";\n",mName.c_str());}
	/*The green component of Sunset Brightness*/
	void setSunsetBrightnessG(float ssg){if(ssg == 0.0) return; fprintf_s(mFile, "setAttr \".ss.ssg\" %f;\n", ssg);}
	/*The green component of Sunset Brightness*/
	void setSunsetBrightnessG(const FloatID& ssg){fprintf_s(mFile,"connectAttr \"");ssg.write(mFile);fprintf_s(mFile,"\" \"%s.ss.ssg\";\n",mName.c_str());}
	/*The blue component of Sunset Brightness*/
	void setSunsetBrightnessB(float ssb){if(ssb == 0.0) return; fprintf_s(mFile, "setAttr \".ss.ssb\" %f;\n", ssb);}
	/*The blue component of Sunset Brightness*/
	void setSunsetBrightnessB(const FloatID& ssb){fprintf_s(mFile,"connectAttr \"");ssb.write(mFile);fprintf_s(mFile,"\" \"%s.ss.ssb\";\n",mName.c_str());}
	/*
	<b>Density</b> controls how dense the clouds are.
	At 0.0, the clouds are non-existent.  Increase the
	value to make the clouds denser.  At 5.0, they are
	heavy rain clouds.
	*/
	void setDensity(float d){if(d == 1.0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	<b>Density</b> controls how dense the clouds are.
	At 0.0, the clouds are non-existent.  Increase the
	value to make the clouds denser.  At 5.0, they are
	heavy rain clouds.
	*/
	void setDensity(const FloatID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	<b>Threshold</b> controls how much of the sky is covered
	with cloud.  At 0.0, the entire sky will be cloudy.  As this
	value increases, you will see more and more of the sky through
	the cloud layer.
	*/
	void setThreshold(float t){if(t == 0.5) return; fprintf_s(mFile, "setAttr \".t\" %f;\n", t);}
	/*
	<b>Threshold</b> controls how much of the sky is covered
	with cloud.  At 0.0, the entire sky will be cloudy.  As this
	value increases, you will see more and more of the sky through
	the cloud layer.
	*/
	void setThreshold(const FloatID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*
	<b>Power</b> scales and positions the clouds.
	If you set Power to 0, you will get clouds that have
	little or no variation in density within each cloud.
	As you increase Power, you will see more variation.
	(Basically, Power acts to modulate the Density attribute.)
	*/
	void setPower(float po){if(po == 1.0) return; fprintf_s(mFile, "setAttr \".po\" %f;\n", po);}
	/*
	<b>Power</b> scales and positions the clouds.
	If you set Power to 0, you will get clouds that have
	little or no variation in density within each cloud.
	As you increase Power, you will see more variation.
	(Basically, Power acts to modulate the Density attribute.)
	*/
	void setPower(const FloatID& po){fprintf_s(mFile,"connectAttr \"");po.write(mFile);fprintf_s(mFile,"\" \"%s.po\";\n",mName.c_str());}
	/*
	<b>Altitude</b> controls the apparent altitude of the
	cloud layer.  This does not affect the position of the clouds
	on the screen.  Rather, it affects the fraction of the atmosphere
	that obscures the clouds near the horizon.  Low-altitude clouds
	disappear into haze much more slowly than high-altitude clouds.
	*/
	void setAltitude(float a){if(a == 0.2) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*
	<b>Altitude</b> controls the apparent altitude of the
	cloud layer.  This does not affect the position of the clouds
	on the screen.  Rather, it affects the fraction of the atmosphere
	that obscures the clouds near the horizon.  Low-altitude clouds
	disappear into haze much more slowly than high-altitude clouds.
	*/
	void setAltitude(const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	<b>Halo Size</b> controls the radius over which direct
	back-lighting from the sun occurs.  This is most noticeable
	near the edges of thick clouds or anywhere on thin clouds.
	*/
	void setHaloSize(float hs){if(hs == 20.0) return; fprintf_s(mFile, "setAttr \".hs\" %f;\n", hs);}
	/*
	<b>Halo Size</b> controls the radius over which direct
	back-lighting from the sun occurs.  This is most noticeable
	near the edges of thick clouds or anywhere on thin clouds.
	*/
	void setHaloSize(const FloatID& hs){fprintf_s(mFile,"connectAttr \"");hs.write(mFile);fprintf_s(mFile,"\" \"%s.hs\";\n",mName.c_str());}
	/*
	<b>Sky Samples</b> controls the number of "samples" that
	the renderer uses in its calculations above the cloud layer.
	You can decrease this value to as low as one to speed up
	the environment calculation.  However, decreasing it too much
	may result in undesirable "flatness" in the image, and
	loss of detail.
	*/
	void setSkySamples(float ssa){if(ssa == 5.0) return; fprintf_s(mFile, "setAttr \".ssa\" %f;\n", ssa);}
	/*
	<b>Sky Samples</b> controls the number of "samples" that
	the renderer uses in its calculations above the cloud layer.
	You can decrease this value to as low as one to speed up
	the environment calculation.  However, decreasing it too much
	may result in undesirable "flatness" in the image, and
	loss of detail.
	*/
	void setSkySamples(const FloatID& ssa){fprintf_s(mFile,"connectAttr \"");ssa.write(mFile);fprintf_s(mFile,"\" \"%s.ssa\";\n",mName.c_str());}
	/*
	<b>Floor Samples</b> controls the number of "samples" that
	the renderer uses in its calculations of the floor.  You
	can decrease this value to speed up the environment calculation,
	but if you do so, you will lose some of the atmospheric effect
	along the floor (<i>i.e.</i> fading towards the horizon).
	*/
	void setFloorSamples(float fsa){if(fsa == 1.0) return; fprintf_s(mFile, "setAttr \".fsa\" %f;\n", fsa);}
	/*
	<b>Floor Samples</b> controls the number of "samples" that
	the renderer uses in its calculations of the floor.  You
	can decrease this value to speed up the environment calculation,
	but if you do so, you will lose some of the atmospheric effect
	along the floor (<i>i.e.</i> fading towards the horizon).
	*/
	void setFloorSamples(const FloatID& fsa){fprintf_s(mFile,"connectAttr \"");fsa.write(mFile);fprintf_s(mFile,"\" \"%s.fsa\";\n",mName.c_str());}
	/*
	<b>Cloud Samples</b> controls the number of "samples" that
	the renderer uses in its calculations of the clouds.  You
	can decrease this value to speed up the environment calculation,
	but if you do so, you will lose some of the atmospheric effects ---
	clouds will not fade to mist at the horizon.
	*/
	void setCloudSamples(float csa){if(csa == 5.0) return; fprintf_s(mFile, "setAttr \".csa\" %f;\n", csa);}
	/*
	<b>Cloud Samples</b> controls the number of "samples" that
	the renderer uses in its calculations of the clouds.  You
	can decrease this value to speed up the environment calculation,
	but if you do so, you will lose some of the atmospheric effects ---
	clouds will not fade to mist at the horizon.
	*/
	void setCloudSamples(const FloatID& csa){fprintf_s(mFile,"connectAttr \"");csa.write(mFile);fprintf_s(mFile,"\" \"%s.csa\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.rpc",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getRefPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getRefPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getRefPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Total Brightness</b> controls the overall brightness
	level of the environment.
	*/
	FloatID getTotalBrightness(){char buffer[4096];sprintf_s (buffer, "%s.tb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sun Brightness</b> controls how bright the sun is
	in the environment.  Note: this attribute only affects the brightness
	of the sun, and not its color.
	*/
	Float3ID getSunBrightness(){char buffer[4096];sprintf_s (buffer, "%s.su",mName.c_str());return (const char*)buffer;}
	/*The red component of Sun Brightness*/
	FloatID getSunBrightnessR(){char buffer[4096];sprintf_s (buffer, "%s.su.sur",mName.c_str());return (const char*)buffer;}
	/*The green component of Sun Brightness*/
	FloatID getSunBrightnessG(){char buffer[4096];sprintf_s (buffer, "%s.su.sug",mName.c_str());return (const char*)buffer;}
	/*The blue component of Sun Brightness*/
	FloatID getSunBrightnessB(){char buffer[4096];sprintf_s (buffer, "%s.su.sub",mName.c_str());return (const char*)buffer;}
	/*
	<b>Halo Brightness</b> controls how bright the halo around
	the sun is.  Note: this attribute only affects the brightness
	of the halo, and not its color.
	*/
	Float3ID getHaloBrightness(){char buffer[4096];sprintf_s (buffer, "%s.hb",mName.c_str());return (const char*)buffer;}
	/*The red component of Halo Brightness*/
	FloatID getHaloBrightnessR(){char buffer[4096];sprintf_s (buffer, "%s.hb.hbr",mName.c_str());return (const char*)buffer;}
	/*The green component of Halo Brightness*/
	FloatID getHaloBrightnessG(){char buffer[4096];sprintf_s (buffer, "%s.hb.hbg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Halo Brightness*/
	FloatID getHaloBrightnessB(){char buffer[4096];sprintf_s (buffer, "%s.hb.hbb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Elevation</b> controls how high the sun is in the sky.
	An elevation of 0 degrees would put the sun at the horizon, and an
	elevation of 90 degrees would put it directly overhead.
	*/
	DoubleID getElevation(){char buffer[4096];sprintf_s (buffer, "%s.e",mName.c_str());return (const char*)buffer;}
	/*
	<b>Azimuth</b> controls the position of the sun around a vertical
	axis.  Adjust this to move the sun around horizontally without
	changing its elevation.
	*/
	DoubleID getAzimuth(){char buffer[4096];sprintf_s (buffer, "%s.az",mName.c_str());return (const char*)buffer;}
	/*<b>Size</b> controls the size (radius) of the disk of the sun.*/
	FloatID getSize(){char buffer[4096];sprintf_s (buffer, "%s.sz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Blur</b> controls the size (radius) of the halo around
	the sun.
	*/
	FloatID getBlur(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sky Brightness</b> is a color value that is multiplied
	by the basic sky color.  You can use this to brighten or
	darken or tint the sky.
	*/
	Float3ID getSkyBrightness(){char buffer[4096];sprintf_s (buffer, "%s.sk",mName.c_str());return (const char*)buffer;}
	/*The red component of Sky Brightness*/
	FloatID getSkyBrightnessR(){char buffer[4096];sprintf_s (buffer, "%s.sk.skr",mName.c_str());return (const char*)buffer;}
	/*The green component of Sky Brightness*/
	FloatID getSkyBrightnessG(){char buffer[4096];sprintf_s (buffer, "%s.sk.skg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Sky Brightness*/
	FloatID getSkyBrightnessB(){char buffer[4096];sprintf_s (buffer, "%s.sk.skb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Air Density</b> controls how light is scattered by
	the atmosphere, and therefore the "blueness" of the sky.
	To simulate high-altitude skies (which are black at the zenith,
	and blue near the horizon), set Air Density to values less
	than 1.0.  To simulate low-altitude skies (which are blue at
	the zenith, and white near the horizon), set Air Density to
	values greater than 1.0.
	*/
	FloatID getAirDensity(){char buffer[4096];sprintf_s (buffer, "%s.ad",mName.c_str());return (const char*)buffer;}
	/*<b>Dust Density</b> density of the dust in the atmosphere.*/
	FloatID getDustDensity(){char buffer[4096];sprintf_s (buffer, "%s.dd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sky Thickness</b> controls the thickness of the atmosphere.
	When this is increased, light has to pass through more air,
	and is therefore scattered more, showing more color.
	*/
	FloatID getSkyThickness(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sky Radius</b> can be thought of as the size
	of the planet, epressed as a multiple of Sky Thickness.
	When you increase this, it affects the relative difference
	in light scattering between light coming from above and
	light coming from the horizon.  The bigger the planet,
	the more sunlight has to go through as the sun sets.
	<p/>
	Effectively, increasing this value will result in redder
	but dimmer sunsets.  (You can compensate for dimness by
	increasing the Sky Brightness)
	*/
	FloatID getSkyRadius(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Has Floor</b> controls whether there is a floor
	in the environment.  If you turn this off, the environment
	below the horizon is a mirror reflection of the environment
	above the horizon.
	*/
	BoolID getHasFloor(){char buffer[4096];sprintf_s (buffer, "%s.hf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Floor Color</b> controls the color of the floor, when
	Has Floor is turned on.  You can, of course, texture map this
	attribute to get interesting ground effects.
	*/
	Float3ID getFloorColor(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*The red component of Floor Color*/
	FloatID getFloorColorR(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcr",mName.c_str());return (const char*)buffer;}
	/*The green component of Floor Color*/
	FloatID getFloorColorG(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Floor Color*/
	FloatID getFloorColorB(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Floor Altitude</b> controls the position of the floor
	plane relative to the vertical axis.  Increase this to
	move the floor up, decrease it to move the floor down.
	Remember to always keep your camera above the floor
	altitude.
	*/
	FloatID getFloorAltitude(){char buffer[4096];sprintf_s (buffer, "%s.fa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Use Texture</b> controls whether or not Env Sky pays
	attention to the Cloud Texture attribute.  If you attach
	a Cloud or other fractal texture node to the Cloud Texture
	attribute, then you must turn on Use Texture to see the
	results.
	*/
	BoolID getUseTexture(){char buffer[4096];sprintf_s (buffer, "%s.ut",mName.c_str());return (const char*)buffer;}
	/*
	<b>Cloud Texture</b> lets you assign a layer of clouds
	to the sky.  Map a Cloud texture  or other fractal texture to this
	attribute.
	<p/><b>Note</b>: if you use this attribute, you must turn
	on the Use Texture attribute, or you will not see your clouds.
	*/
	FloatID getCloudTexture(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*
	<b>Cloud Brightness</b> sets the brightness of the ambient
	scattered light from the atmosphere.  This also depends on the
	current Elevation of the sun.
	*/
	Float3ID getCloudBrightness(){char buffer[4096];sprintf_s (buffer, "%s.cb",mName.c_str());return (const char*)buffer;}
	/*The red component of Cloud Brightness*/
	FloatID getCloudBrightnessR(){char buffer[4096];sprintf_s (buffer, "%s.cb.cbr",mName.c_str());return (const char*)buffer;}
	/*The green component of Cloud Brightness*/
	FloatID getCloudBrightnessG(){char buffer[4096];sprintf_s (buffer, "%s.cb.cbg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Cloud Brightness*/
	FloatID getCloudBrightnessB(){char buffer[4096];sprintf_s (buffer, "%s.cb.cbb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sunset Brightness</b> controls the illumination of the
	clouds when the sun is below the horizon and the clouds
	are front-lit.  This is a very subtle effect and only
	occurs briefly after sunset.
	*/
	Float3ID getSunsetBrightness(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*The red component of Sunset Brightness*/
	FloatID getSunsetBrightnessR(){char buffer[4096];sprintf_s (buffer, "%s.ss.ssr",mName.c_str());return (const char*)buffer;}
	/*The green component of Sunset Brightness*/
	FloatID getSunsetBrightnessG(){char buffer[4096];sprintf_s (buffer, "%s.ss.ssg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Sunset Brightness*/
	FloatID getSunsetBrightnessB(){char buffer[4096];sprintf_s (buffer, "%s.ss.ssb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Density</b> controls how dense the clouds are.
	At 0.0, the clouds are non-existent.  Increase the
	value to make the clouds denser.  At 5.0, they are
	heavy rain clouds.
	*/
	FloatID getDensity(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	<b>Threshold</b> controls how much of the sky is covered
	with cloud.  At 0.0, the entire sky will be cloudy.  As this
	value increases, you will see more and more of the sky through
	the cloud layer.
	*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*
	<b>Power</b> scales and positions the clouds.
	If you set Power to 0, you will get clouds that have
	little or no variation in density within each cloud.
	As you increase Power, you will see more variation.
	(Basically, Power acts to modulate the Density attribute.)
	*/
	FloatID getPower(){char buffer[4096];sprintf_s (buffer, "%s.po",mName.c_str());return (const char*)buffer;}
	/*
	<b>Altitude</b> controls the apparent altitude of the
	cloud layer.  This does not affect the position of the clouds
	on the screen.  Rather, it affects the fraction of the atmosphere
	that obscures the clouds near the horizon.  Low-altitude clouds
	disappear into haze much more slowly than high-altitude clouds.
	*/
	FloatID getAltitude(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	<b>Halo Size</b> controls the radius over which direct
	back-lighting from the sun occurs.  This is most noticeable
	near the edges of thick clouds or anywhere on thin clouds.
	*/
	FloatID getHaloSize(){char buffer[4096];sprintf_s (buffer, "%s.hs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sky Samples</b> controls the number of "samples" that
	the renderer uses in its calculations above the cloud layer.
	You can decrease this value to as low as one to speed up
	the environment calculation.  However, decreasing it too much
	may result in undesirable "flatness" in the image, and
	loss of detail.
	*/
	FloatID getSkySamples(){char buffer[4096];sprintf_s (buffer, "%s.ssa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Floor Samples</b> controls the number of "samples" that
	the renderer uses in its calculations of the floor.  You
	can decrease this value to speed up the environment calculation,
	but if you do so, you will lose some of the atmospheric effect
	along the floor (<i>i.e.</i> fading towards the horizon).
	*/
	FloatID getFloorSamples(){char buffer[4096];sprintf_s (buffer, "%s.fsa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Cloud Samples</b> controls the number of "samples" that
	the renderer uses in its calculations of the clouds.  You
	can decrease this value to speed up the environment calculation,
	but if you do so, you will lose some of the atmospheric effects ---
	clouds will not fade to mist at the horizon.
	*/
	FloatID getCloudSamples(){char buffer[4096];sprintf_s (buffer, "%s.csa",mName.c_str());return (const char*)buffer;}
protected:
	EnvSky(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):TextureEnv(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ENVSKY_H__
