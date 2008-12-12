/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVCHROME_H__
#define __MayaDM_ENVCHROME_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTextureEnv.h"
namespace MayaDM
{
/*
The <b>EnvChrome</b> texture creates a simple by effective environment
 to simulate the reflections off chrome surfaces.  The basic environment
 map consists of a ground plane and a sky with fluorescent-style light
 rectangles.
 <p/>
 These rectangular lights in the sky are there for visual effect only,
 and do not act as light sources in the scene.
 <p/>
 To use this texture as an environment map, connect the Out Color
 attribute to the Reflected Color attribute of any specular shader,
 such as Blinn or Phong.  (For chrome you will want to use a Blinn
 shader, with the Reflectivity attribute set to 1.0).
 <p/>
 Aside from the attributes listed here, EnvChrome inherits additional
 attributes from <a href="textureEnv.html">TextureEnv</a>.
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class EnvChrome : public TextureEnv
{
public:
public:
	EnvChrome(FILE* file,const std::string& name,const std::string& parent=""):TextureEnv(file, name, parent, "envChrome"){}
	virtual ~EnvChrome(){}
	/*The current sample point that has to be shaded*/
	void setPointCamera(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*
	<b>Sky Color</b> controls the color of the reflected sky
	at the horizon.  The overall color of the sky is linearly
	interpolated between Sky Color and Zenith Color.
	*/
	void setSkyColor(const float3& sc){if(sc == float3(0.784, 0.784, 1.0)) return; fprintf_s(mFile, "setAttr \".sc\" -type \"float3\" ");sc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Sky Color</b> controls the color of the reflected sky
	at the horizon.  The overall color of the sky is linearly
	interpolated between Sky Color and Zenith Color.
	*/
	void setSkyColor(const Float3ID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*The red component of Sky Color*/
	void setSkyColorR(float scr){if(scr == 0.0) return; fprintf_s(mFile, "setAttr \".sc.scr\" %f;\n", scr);}
	/*The red component of Sky Color*/
	void setSkyColorR(const FloatID& scr){fprintf_s(mFile,"connectAttr \"");scr.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scr\";\n",mName.c_str());}
	/*The green component of Sky Color*/
	void setSkyColorG(float scg){if(scg == 0.0) return; fprintf_s(mFile, "setAttr \".sc.scg\" %f;\n", scg);}
	/*The green component of Sky Color*/
	void setSkyColorG(const FloatID& scg){fprintf_s(mFile,"connectAttr \"");scg.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scg\";\n",mName.c_str());}
	/*The blue component of Sky Color*/
	void setSkyColorB(float scb){if(scb == 0.0) return; fprintf_s(mFile, "setAttr \".sc.scb\" %f;\n", scb);}
	/*The blue component of Sky Color*/
	void setSkyColorB(const FloatID& scb){fprintf_s(mFile,"connectAttr \"");scb.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scb\";\n",mName.c_str());}
	/*
	<b>Zenith Color</b> is the color of the sky at the
	zenith (looking straight up).
	The overall color of the sky is linearly
	interpolated between Sky Color and Zenith Color.
	*/
	void setZenithColor(const float3& zc){if(zc == float3(0.392, 0.392, 1.0)) return; fprintf_s(mFile, "setAttr \".zc\" -type \"float3\" ");zc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Zenith Color</b> is the color of the sky at the
	zenith (looking straight up).
	The overall color of the sky is linearly
	interpolated between Sky Color and Zenith Color.
	*/
	void setZenithColor(const Float3ID& zc){fprintf_s(mFile,"connectAttr \"");zc.write(mFile);fprintf_s(mFile,"\" \"%s.zc\";\n",mName.c_str());}
	/*The red component of Zenith Color*/
	void setZenithColorR(float zcr){if(zcr == 0.0) return; fprintf_s(mFile, "setAttr \".zc.zcr\" %f;\n", zcr);}
	/*The red component of Zenith Color*/
	void setZenithColorR(const FloatID& zcr){fprintf_s(mFile,"connectAttr \"");zcr.write(mFile);fprintf_s(mFile,"\" \"%s.zc.zcr\";\n",mName.c_str());}
	/*The green component of Zenith Color*/
	void setZenithColorG(float zcg){if(zcg == 0.0) return; fprintf_s(mFile, "setAttr \".zc.zcg\" %f;\n", zcg);}
	/*The green component of Zenith Color*/
	void setZenithColorG(const FloatID& zcg){fprintf_s(mFile,"connectAttr \"");zcg.write(mFile);fprintf_s(mFile,"\" \"%s.zc.zcg\";\n",mName.c_str());}
	/*The blue component of Zenith Color*/
	void setZenithColorB(float zcb){if(zcb == 0.0) return; fprintf_s(mFile, "setAttr \".zc.zcb\" %f;\n", zcb);}
	/*The blue component of Zenith Color*/
	void setZenithColorB(const FloatID& zcb){fprintf_s(mFile,"connectAttr \"");zcb.write(mFile);fprintf_s(mFile,"\" \"%s.zc.zcb\";\n",mName.c_str());}
	/*
	<b>Light Color</b> controls the color of the grid of
	rectangular "lights" seen in the reflected sky.  These lights
	are there for visual effect only;  they do not act as
	real light sources in the scene.
	*/
	void setLightColor(const float3& lc){if(lc == float3(0.784, 0.784, 1.0)) return; fprintf_s(mFile, "setAttr \".lc\" -type \"float3\" ");lc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Light Color</b> controls the color of the grid of
	rectangular "lights" seen in the reflected sky.  These lights
	are there for visual effect only;  they do not act as
	real light sources in the scene.
	*/
	void setLightColor(const Float3ID& lc){fprintf_s(mFile,"connectAttr \"");lc.write(mFile);fprintf_s(mFile,"\" \"%s.lc\";\n",mName.c_str());}
	/*The red component of Light Color*/
	void setLightColorR(float lcr){if(lcr == 0.0) return; fprintf_s(mFile, "setAttr \".lc.lcr\" %f;\n", lcr);}
	/*The red component of Light Color*/
	void setLightColorR(const FloatID& lcr){fprintf_s(mFile,"connectAttr \"");lcr.write(mFile);fprintf_s(mFile,"\" \"%s.lc.lcr\";\n",mName.c_str());}
	/*The green component of Light Color*/
	void setLightColorG(float lcg){if(lcg == 0.0) return; fprintf_s(mFile, "setAttr \".lc.lcg\" %f;\n", lcg);}
	/*The green component of Light Color*/
	void setLightColorG(const FloatID& lcg){fprintf_s(mFile,"connectAttr \"");lcg.write(mFile);fprintf_s(mFile,"\" \"%s.lc.lcg\";\n",mName.c_str());}
	/*The blue component of Light Color*/
	void setLightColorB(float lcb){if(lcb == 0.0) return; fprintf_s(mFile, "setAttr \".lc.lcb\" %f;\n", lcb);}
	/*The blue component of Light Color*/
	void setLightColorB(const FloatID& lcb){fprintf_s(mFile,"connectAttr \"");lcb.write(mFile);fprintf_s(mFile,"\" \"%s.lc.lcb\";\n",mName.c_str());}
	/*
	<b>Light Width</b> controls how wide each of the rectangular
	lights in the sky is, relative to the space between them in that direction.
	Set this to 0.5, and the lights will be exactly as wide
	as the space between them.  Set this to 0.9, and the lights
	will almost touch each other at the edges.
	*/
	void setLightWidth(float lw){if(lw == 0.5) return; fprintf_s(mFile, "setAttr \".lw\" %f;\n", lw);}
	/*
	<b>Light Width</b> controls how wide each of the rectangular
	lights in the sky is, relative to the space between them in that direction.
	Set this to 0.5, and the lights will be exactly as wide
	as the space between them.  Set this to 0.9, and the lights
	will almost touch each other at the edges.
	*/
	void setLightWidth(const FloatID& lw){fprintf_s(mFile,"connectAttr \"");lw.write(mFile);fprintf_s(mFile,"\" \"%s.lw\";\n",mName.c_str());}
	/*
	<b>Light Width Gain</b> controls how far apart the lights
	in the sky are (in the Width direction).  Increase Light Width Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the width of the lights is set relative to the
	space between them, increasing this will also make the lights
	wider.  (See Light Width).
	*/
	void setLightWidthGain(float lwg){if(lwg == 1.0) return; fprintf_s(mFile, "setAttr \".lwg\" %f;\n", lwg);}
	/*
	<b>Light Width Gain</b> controls how far apart the lights
	in the sky are (in the Width direction).  Increase Light Width Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the width of the lights is set relative to the
	space between them, increasing this will also make the lights
	wider.  (See Light Width).
	*/
	void setLightWidthGain(const FloatID& lwg){fprintf_s(mFile,"connectAttr \"");lwg.write(mFile);fprintf_s(mFile,"\" \"%s.lwg\";\n",mName.c_str());}
	/*
	<b>Light Width Offset</b> controls the positioning of the lights
	in the sky.  You can increase or decrease this value to make the
	lights move left or right without changing their size or spacing.
	*/
	void setLightWidthOffset(float lwo){if(lwo == 0.0) return; fprintf_s(mFile, "setAttr \".lwo\" %f;\n", lwo);}
	/*
	<b>Light Width Offset</b> controls the positioning of the lights
	in the sky.  You can increase or decrease this value to make the
	lights move left or right without changing their size or spacing.
	*/
	void setLightWidthOffset(const FloatID& lwo){fprintf_s(mFile,"connectAttr \"");lwo.write(mFile);fprintf_s(mFile,"\" \"%s.lwo\";\n",mName.c_str());}
	/*
	<b>Light Depth</b> controls how Tint32 each of the rectangular
	lights in the sky is, relative to the space between them in that
	direction.
	Set this to 0.5, and the lights will be exactly as Tint32
	as the space between them.  Set this to 0.9, and the lights
	will almost touch each other at the edges.
	*/
	void setLightDepth(float ld){if(ld == 0.1) return; fprintf_s(mFile, "setAttr \".ld\" %f;\n", ld);}
	/*
	<b>Light Depth</b> controls how Tint32 each of the rectangular
	lights in the sky is, relative to the space between them in that
	direction.
	Set this to 0.5, and the lights will be exactly as Tint32
	as the space between them.  Set this to 0.9, and the lights
	will almost touch each other at the edges.
	*/
	void setLightDepth(const FloatID& ld){fprintf_s(mFile,"connectAttr \"");ld.write(mFile);fprintf_s(mFile,"\" \"%s.ld\";\n",mName.c_str());}
	/*
	<b>Light Depth Gain</b> controls how far apart the lights
	in the sky are (in the Depth direction).  Increase Light Depth Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the length (depth) of the lights is set relative to the
	space between them, increasing this will also make the lights
	longer.  (See Light Depth).
	*/
	void setLightDepthGain(float ldg){if(ldg == 1.0) return; fprintf_s(mFile, "setAttr \".ldg\" %f;\n", ldg);}
	/*
	<b>Light Depth Gain</b> controls how far apart the lights
	in the sky are (in the Depth direction).  Increase Light Depth Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the length (depth) of the lights is set relative to the
	space between them, increasing this will also make the lights
	longer.  (See Light Depth).
	*/
	void setLightDepthGain(const FloatID& ldg){fprintf_s(mFile,"connectAttr \"");ldg.write(mFile);fprintf_s(mFile,"\" \"%s.ldg\";\n",mName.c_str());}
	/*
	<b>Light Depth Offset</b> controls the positioning of the lights
	in the sky.  You can increase or decrease this value to make the
	lights move closer or farther without changing their size or spacing.
	*/
	void setLightDepthOffset(float ldo){if(ldo == 0.0) return; fprintf_s(mFile, "setAttr \".ldo\" %f;\n", ldo);}
	/*
	<b>Light Depth Offset</b> controls the positioning of the lights
	in the sky.  You can increase or decrease this value to make the
	lights move closer or farther without changing their size or spacing.
	*/
	void setLightDepthOffset(const FloatID& ldo){fprintf_s(mFile,"connectAttr \"");ldo.write(mFile);fprintf_s(mFile,"\" \"%s.ldo\";\n",mName.c_str());}
	/*
	<b>Real Floor</b>.  If this is turned off, then the gridded
	floor in the environment acts as though it is infinitely
	far away (like the sky).  Turn this on to make the floor
	seem to be a real floor.
	<p/>
	Note:  when this is on, it is important that none of the
	surfaces (and the camera) in the scene project below the
	level of the floor.  If they do, the calculated shading will
	be incorrect.
	*/
	void setRealFloor(bool rf){if(rf == true) return; fprintf_s(mFile, "setAttr \".rf\" %i;\n", rf);}
	/*
	<b>Real Floor</b>.  If this is turned off, then the gridded
	floor in the environment acts as though it is infinitely
	far away (like the sky).  Turn this on to make the floor
	seem to be a real floor.
	<p/>
	Note:  when this is on, it is important that none of the
	surfaces (and the camera) in the scene project below the
	level of the floor.  If they do, the calculated shading will
	be incorrect.
	*/
	void setRealFloor(const BoolID& rf){fprintf_s(mFile,"connectAttr \"");rf.write(mFile);fprintf_s(mFile,"\" \"%s.rf\";\n",mName.c_str());}
	/*<b>Floor Color</b> controls the color of the floor.*/
	void setFloorColor(const float3& fc){if(fc == float3(0.588, 0.588, 0.784)) return; fprintf_s(mFile, "setAttr \".fc\" -type \"float3\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Floor Color</b> controls the color of the floor.*/
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
	along the vertical axis.  If Real Floor is turned on, make
	sure that none of the surfaces or the camera in the scene
	go below this level.
	*/
	void setFloorAltitude(float fa){if(fa == -1.0) return; fprintf_s(mFile, "setAttr \".fa\" %f;\n", fa);}
	/*
	<b>Floor Altitude</b> controls the position of the floor
	along the vertical axis.  If Real Floor is turned on, make
	sure that none of the surfaces or the camera in the scene
	go below this level.
	*/
	void setFloorAltitude(const FloatID& fa){fprintf_s(mFile,"connectAttr \"");fa.write(mFile);fprintf_s(mFile,"\" \"%s.fa\";\n",mName.c_str());}
	/*
	<b>Horizon Color</b> controls the color of the floor at the
	horizon.  The overall color of the floor is linearly interpolated
	between Floor Color and Horizon Color.
	*/
	void setHorizonColor(const float3& hc){if(hc == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".hc\" -type \"float3\" ");hc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Horizon Color</b> controls the color of the floor at the
	horizon.  The overall color of the floor is linearly interpolated
	between Floor Color and Horizon Color.
	*/
	void setHorizonColor(const Float3ID& hc){fprintf_s(mFile,"connectAttr \"");hc.write(mFile);fprintf_s(mFile,"\" \"%s.hc\";\n",mName.c_str());}
	/*The red component of Horizon Color*/
	void setHorizonColorR(float hcr){if(hcr == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hcr\" %f;\n", hcr);}
	/*The red component of Horizon Color*/
	void setHorizonColorR(const FloatID& hcr){fprintf_s(mFile,"connectAttr \"");hcr.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hcr\";\n",mName.c_str());}
	/*The green component of Horizon Color*/
	void setHorizonColorG(float hcg){if(hcg == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hcg\" %f;\n", hcg);}
	/*The green component of Horizon Color*/
	void setHorizonColorG(const FloatID& hcg){fprintf_s(mFile,"connectAttr \"");hcg.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hcg\";\n",mName.c_str());}
	/*The blue component of Horizon Color*/
	void setHorizonColorB(float hcb){if(hcb == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hcb\" %f;\n", hcb);}
	/*The blue component of Horizon Color*/
	void setHorizonColorB(const FloatID& hcb){fprintf_s(mFile,"connectAttr \"");hcb.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hcb\";\n",mName.c_str());}
	/*
	<b>Grid Color</b> controls the color of the grid lines
	on the floor.
	*/
	void setGridColor(const float3& gc){if(gc == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".gc\" -type \"float3\" ");gc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Grid Color</b> controls the color of the grid lines
	on the floor.
	*/
	void setGridColor(const Float3ID& gc){fprintf_s(mFile,"connectAttr \"");gc.write(mFile);fprintf_s(mFile,"\" \"%s.gc\";\n",mName.c_str());}
	/*The red component of Grid Color*/
	void setGridColorR(float gcr){if(gcr == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gcr\" %f;\n", gcr);}
	/*The red component of Grid Color*/
	void setGridColorR(const FloatID& gcr){fprintf_s(mFile,"connectAttr \"");gcr.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gcr\";\n",mName.c_str());}
	/*The green component of Grid Color*/
	void setGridColorG(float gcg){if(gcg == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gcg\" %f;\n", gcg);}
	/*The green component of Grid Color*/
	void setGridColorG(const FloatID& gcg){fprintf_s(mFile,"connectAttr \"");gcg.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gcg\";\n",mName.c_str());}
	/*The blue component of Grid Color*/
	void setGridColorB(float gcb){if(gcb == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gcb\" %f;\n", gcb);}
	/*The blue component of Grid Color*/
	void setGridColorB(const FloatID& gcb){fprintf_s(mFile,"connectAttr \"");gcb.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gcb\";\n",mName.c_str());}
	/*
	<b>Grid Width</b> controls the width of each of the grid lines
	running across the floor, relative to the space between them.
	Set this to 0.5, and the lines will be exactly as wide
	as the space between them.  Set this to 0.9, and the lines
	will almost touch each other at the edges.
	*/
	void setGridWidth(float gw){if(gw == 0.1) return; fprintf_s(mFile, "setAttr \".gw\" %f;\n", gw);}
	/*
	<b>Grid Width</b> controls the width of each of the grid lines
	running across the floor, relative to the space between them.
	Set this to 0.5, and the lines will be exactly as wide
	as the space between them.  Set this to 0.9, and the lines
	will almost touch each other at the edges.
	*/
	void setGridWidth(const FloatID& gw){fprintf_s(mFile,"connectAttr \"");gw.write(mFile);fprintf_s(mFile,"\" \"%s.gw\";\n",mName.c_str());}
	/*
	<b>Grid Width Gain</b> controls the distance between the grid
	lines that run across the floor. Increase Grid Width Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the width of the grid lines is set relative to the
	space between them, increasing this will also make the lines
	wider.  (See Grid Width).
	*/
	void setGridWidthGain(float gwg){if(gwg == 1.0) return; fprintf_s(mFile, "setAttr \".gwg\" %f;\n", gwg);}
	/*
	<b>Grid Width Gain</b> controls the distance between the grid
	lines that run across the floor. Increase Grid Width Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the width of the grid lines is set relative to the
	space between them, increasing this will also make the lines
	wider.  (See Grid Width).
	*/
	void setGridWidthGain(const FloatID& gwg){fprintf_s(mFile,"connectAttr \"");gwg.write(mFile);fprintf_s(mFile,"\" \"%s.gwg\";\n",mName.c_str());}
	/*
	<b>Grid Width Offset</b> controls the positioning of the grid lines
	across the floor.  You can increase or decrease this value to make the
	lines move back and forth without changing their width or spacing.
	*/
	void setGridWidthOffset(float gwo){if(gwo == 0.0) return; fprintf_s(mFile, "setAttr \".gwo\" %f;\n", gwo);}
	/*
	<b>Grid Width Offset</b> controls the positioning of the grid lines
	across the floor.  You can increase or decrease this value to make the
	lines move back and forth without changing their width or spacing.
	*/
	void setGridWidthOffset(const FloatID& gwo){fprintf_s(mFile,"connectAttr \"");gwo.write(mFile);fprintf_s(mFile,"\" \"%s.gwo\";\n",mName.c_str());}
	/*
	<b>Grid Depth</b> controls the width of each of the grid lines
	running along the floor, relative to the space between them.
	Set this to 0.5, and the lines will be exactly as wide
	as the space between them.  Set this to 0.9, and the lines
	will almost touch each other at the edges.
	*/
	void setGridDepth(float gd){if(gd == 0.1) return; fprintf_s(mFile, "setAttr \".gd\" %f;\n", gd);}
	/*
	<b>Grid Depth</b> controls the width of each of the grid lines
	running along the floor, relative to the space between them.
	Set this to 0.5, and the lines will be exactly as wide
	as the space between them.  Set this to 0.9, and the lines
	will almost touch each other at the edges.
	*/
	void setGridDepth(const FloatID& gd){fprintf_s(mFile,"connectAttr \"");gd.write(mFile);fprintf_s(mFile,"\" \"%s.gd\";\n",mName.c_str());}
	/*
	<b>Grid Depth Gain</b> controls the distance between the grid
	lines that run along the floor. Increase Grid Depth Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the width of the grid lines is set relative to the
	space between them, increasing this will also make the lines
	wider.  (See Grid Depth).
	*/
	void setGridDepthGain(float gdg){if(gdg == 1.0) return; fprintf_s(mFile, "setAttr \".gdg\" %f;\n", gdg);}
	/*
	<b>Grid Depth Gain</b> controls the distance between the grid
	lines that run along the floor. Increase Grid Depth Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the width of the grid lines is set relative to the
	space between them, increasing this will also make the lines
	wider.  (See Grid Depth).
	*/
	void setGridDepthGain(const FloatID& gdg){fprintf_s(mFile,"connectAttr \"");gdg.write(mFile);fprintf_s(mFile,"\" \"%s.gdg\";\n",mName.c_str());}
	/*
	<b>Grid Depth Offset</b> controls the positioning of the grid lines
	along the floor.  You can increase or decrease this value to make the
	lines move back and forth without changing their width or spacing.
	*/
	void setGridDepthOffset(float gdo){if(gdo == 0.0) return; fprintf_s(mFile, "setAttr \".gdo\" %f;\n", gdo);}
	/*
	<b>Grid Depth Offset</b> controls the positioning of the grid lines
	along the floor.  You can increase or decrease this value to make the
	lines move back and forth without changing their width or spacing.
	*/
	void setGridDepthOffset(const FloatID& gdo){fprintf_s(mFile,"connectAttr \"");gdo.write(mFile);fprintf_s(mFile,"\" \"%s.gdo\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sky Color</b> controls the color of the reflected sky
	at the horizon.  The overall color of the sky is linearly
	interpolated between Sky Color and Zenith Color.
	*/
	Float3ID getSkyColor(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*The red component of Sky Color*/
	FloatID getSkyColorR(){char buffer[4096];sprintf_s (buffer, "%s.sc.scr",mName.c_str());return (const char*)buffer;}
	/*The green component of Sky Color*/
	FloatID getSkyColorG(){char buffer[4096];sprintf_s (buffer, "%s.sc.scg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Sky Color*/
	FloatID getSkyColorB(){char buffer[4096];sprintf_s (buffer, "%s.sc.scb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Zenith Color</b> is the color of the sky at the
	zenith (looking straight up).
	The overall color of the sky is linearly
	interpolated between Sky Color and Zenith Color.
	*/
	Float3ID getZenithColor(){char buffer[4096];sprintf_s (buffer, "%s.zc",mName.c_str());return (const char*)buffer;}
	/*The red component of Zenith Color*/
	FloatID getZenithColorR(){char buffer[4096];sprintf_s (buffer, "%s.zc.zcr",mName.c_str());return (const char*)buffer;}
	/*The green component of Zenith Color*/
	FloatID getZenithColorG(){char buffer[4096];sprintf_s (buffer, "%s.zc.zcg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Zenith Color*/
	FloatID getZenithColorB(){char buffer[4096];sprintf_s (buffer, "%s.zc.zcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Color</b> controls the color of the grid of
	rectangular "lights" seen in the reflected sky.  These lights
	are there for visual effect only;  they do not act as
	real light sources in the scene.
	*/
	Float3ID getLightColor(){char buffer[4096];sprintf_s (buffer, "%s.lc",mName.c_str());return (const char*)buffer;}
	/*The red component of Light Color*/
	FloatID getLightColorR(){char buffer[4096];sprintf_s (buffer, "%s.lc.lcr",mName.c_str());return (const char*)buffer;}
	/*The green component of Light Color*/
	FloatID getLightColorG(){char buffer[4096];sprintf_s (buffer, "%s.lc.lcg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Light Color*/
	FloatID getLightColorB(){char buffer[4096];sprintf_s (buffer, "%s.lc.lcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Width</b> controls how wide each of the rectangular
	lights in the sky is, relative to the space between them in that direction.
	Set this to 0.5, and the lights will be exactly as wide
	as the space between them.  Set this to 0.9, and the lights
	will almost touch each other at the edges.
	*/
	FloatID getLightWidth(){char buffer[4096];sprintf_s (buffer, "%s.lw",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Width Gain</b> controls how far apart the lights
	in the sky are (in the Width direction).  Increase Light Width Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the width of the lights is set relative to the
	space between them, increasing this will also make the lights
	wider.  (See Light Width).
	*/
	FloatID getLightWidthGain(){char buffer[4096];sprintf_s (buffer, "%s.lwg",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Width Offset</b> controls the positioning of the lights
	in the sky.  You can increase or decrease this value to make the
	lights move left or right without changing their size or spacing.
	*/
	FloatID getLightWidthOffset(){char buffer[4096];sprintf_s (buffer, "%s.lwo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Depth</b> controls how Tint32 each of the rectangular
	lights in the sky is, relative to the space between them in that
	direction.
	Set this to 0.5, and the lights will be exactly as Tint32
	as the space between them.  Set this to 0.9, and the lights
	will almost touch each other at the edges.
	*/
	FloatID getLightDepth(){char buffer[4096];sprintf_s (buffer, "%s.ld",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Depth Gain</b> controls how far apart the lights
	in the sky are (in the Depth direction).  Increase Light Depth Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the length (depth) of the lights is set relative to the
	space between them, increasing this will also make the lights
	longer.  (See Light Depth).
	*/
	FloatID getLightDepthGain(){char buffer[4096];sprintf_s (buffer, "%s.ldg",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Depth Offset</b> controls the positioning of the lights
	in the sky.  You can increase or decrease this value to make the
	lights move closer or farther without changing their size or spacing.
	*/
	FloatID getLightDepthOffset(){char buffer[4096];sprintf_s (buffer, "%s.ldo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Real Floor</b>.  If this is turned off, then the gridded
	floor in the environment acts as though it is infinitely
	far away (like the sky).  Turn this on to make the floor
	seem to be a real floor.
	<p/>
	Note:  when this is on, it is important that none of the
	surfaces (and the camera) in the scene project below the
	level of the floor.  If they do, the calculated shading will
	be incorrect.
	*/
	BoolID getRealFloor(){char buffer[4096];sprintf_s (buffer, "%s.rf",mName.c_str());return (const char*)buffer;}
	/*<b>Floor Color</b> controls the color of the floor.*/
	Float3ID getFloorColor(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*The red component of Floor Color*/
	FloatID getFloorColorR(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcr",mName.c_str());return (const char*)buffer;}
	/*The green component of Floor Color*/
	FloatID getFloorColorG(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Floor Color*/
	FloatID getFloorColorB(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Floor Altitude</b> controls the position of the floor
	along the vertical axis.  If Real Floor is turned on, make
	sure that none of the surfaces or the camera in the scene
	go below this level.
	*/
	FloatID getFloorAltitude(){char buffer[4096];sprintf_s (buffer, "%s.fa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Horizon Color</b> controls the color of the floor at the
	horizon.  The overall color of the floor is linearly interpolated
	between Floor Color and Horizon Color.
	*/
	Float3ID getHorizonColor(){char buffer[4096];sprintf_s (buffer, "%s.hc",mName.c_str());return (const char*)buffer;}
	/*The red component of Horizon Color*/
	FloatID getHorizonColorR(){char buffer[4096];sprintf_s (buffer, "%s.hc.hcr",mName.c_str());return (const char*)buffer;}
	/*The green component of Horizon Color*/
	FloatID getHorizonColorG(){char buffer[4096];sprintf_s (buffer, "%s.hc.hcg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Horizon Color*/
	FloatID getHorizonColorB(){char buffer[4096];sprintf_s (buffer, "%s.hc.hcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grid Color</b> controls the color of the grid lines
	on the floor.
	*/
	Float3ID getGridColor(){char buffer[4096];sprintf_s (buffer, "%s.gc",mName.c_str());return (const char*)buffer;}
	/*The red component of Grid Color*/
	FloatID getGridColorR(){char buffer[4096];sprintf_s (buffer, "%s.gc.gcr",mName.c_str());return (const char*)buffer;}
	/*The green component of Grid Color*/
	FloatID getGridColorG(){char buffer[4096];sprintf_s (buffer, "%s.gc.gcg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Grid Color*/
	FloatID getGridColorB(){char buffer[4096];sprintf_s (buffer, "%s.gc.gcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grid Width</b> controls the width of each of the grid lines
	running across the floor, relative to the space between them.
	Set this to 0.5, and the lines will be exactly as wide
	as the space between them.  Set this to 0.9, and the lines
	will almost touch each other at the edges.
	*/
	FloatID getGridWidth(){char buffer[4096];sprintf_s (buffer, "%s.gw",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grid Width Gain</b> controls the distance between the grid
	lines that run across the floor. Increase Grid Width Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the width of the grid lines is set relative to the
	space between them, increasing this will also make the lines
	wider.  (See Grid Width).
	*/
	FloatID getGridWidthGain(){char buffer[4096];sprintf_s (buffer, "%s.gwg",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grid Width Offset</b> controls the positioning of the grid lines
	across the floor.  You can increase or decrease this value to make the
	lines move back and forth without changing their width or spacing.
	*/
	FloatID getGridWidthOffset(){char buffer[4096];sprintf_s (buffer, "%s.gwo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grid Depth</b> controls the width of each of the grid lines
	running along the floor, relative to the space between them.
	Set this to 0.5, and the lines will be exactly as wide
	as the space between them.  Set this to 0.9, and the lines
	will almost touch each other at the edges.
	*/
	FloatID getGridDepth(){char buffer[4096];sprintf_s (buffer, "%s.gd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grid Depth Gain</b> controls the distance between the grid
	lines that run along the floor. Increase Grid Depth Gain to spread them out,
	and decrease it to bring them closer together.
	<p/>
	Note:  Since the width of the grid lines is set relative to the
	space between them, increasing this will also make the lines
	wider.  (See Grid Depth).
	*/
	FloatID getGridDepthGain(){char buffer[4096];sprintf_s (buffer, "%s.gdg",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grid Depth Offset</b> controls the positioning of the grid lines
	along the floor.  You can increase or decrease this value to make the
	lines move back and forth without changing their width or spacing.
	*/
	FloatID getGridDepthOffset(){char buffer[4096];sprintf_s (buffer, "%s.gdo",mName.c_str());return (const char*)buffer;}
protected:
	EnvChrome(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):TextureEnv(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ENVCHROME_H__
