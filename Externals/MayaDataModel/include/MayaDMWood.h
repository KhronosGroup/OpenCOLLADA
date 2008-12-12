/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WOOD_H__
#define __MayaDM_WOOD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
The <b>Wood</b> texture simulates wood by projecting a two-dimensional
 pattern. This pattern consists of layers of concentric rings defined
 by <i>veins</i> and <i>filler</i>.  When you map the Wood texture to
 a surface, the surface will appear to be carved out of wood.  If you
 map the same Wood texture to several surfaces, they will appear to
 be carved from a single block of wood.
<p/>
 Aside from the attributes listed here, Wood inherits many attributes
 from <a href="texture3d.html">Texture3d</a>.
<p/>
 In the table below, important attributes have their names shown
 in <b>bold</b> in the Description column.
*/
class Wood : public Texture3d
{
public:
public:
	Wood(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "wood"){}
	virtual ~Wood(){}
	/*The pixel angle*/
	void setXPixelAngle(float xpa){if(xpa == 0.002053) return; fprintf_s(mFile, "setAttr \".xpa\" %f;\n", xpa);}
	/*The input normal*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The X component of the input normal*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The Y component of the input normal*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The Z component of the input normal*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointObj(const Float3ID& rpo){fprintf_s(mFile,"connectAttr \"");rpo.write(mFile);fprintf_s(mFile,"\" \"%s.rpo\";\n",mName.c_str());}
	/*The x component of the current reference sample position*/
	void setRefPointObjX(const FloatID& rox){fprintf_s(mFile,"connectAttr \"");rox.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.rox\";\n",mName.c_str());}
	/*The y component of the current reference sample position*/
	void setRefPointObjY(const FloatID& roy){fprintf_s(mFile,"connectAttr \"");roy.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.roy\";\n",mName.c_str());}
	/*The z component of the current reference sample position*/
	void setRefPointObjZ(const FloatID& roz){fprintf_s(mFile,"connectAttr \"");roz.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.roz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointCamera(const Float3ID& rpc){fprintf_s(mFile,"connectAttr \"");rpc.write(mFile);fprintf_s(mFile,"\" \"%s.rpc\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setRefPointCameraX(const FloatID& rcx){fprintf_s(mFile,"connectAttr \"");rcx.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setRefPointCameraY(const FloatID& rcy){fprintf_s(mFile,"connectAttr \"");rcy.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setRefPointCameraZ(const FloatID& rcz){fprintf_s(mFile,"connectAttr \"");rcz.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcz\";\n",mName.c_str());}
	/*
	<b>Filler Color</b> controls the color of the space between
	the veins.  The vein color diffuses into the filler color.
	*/
	void setFillerColor(const float3& fc){if(fc == float3(0.824, 0.627, 0.471)) return; fprintf_s(mFile, "setAttr \".fc\" -type \"float3\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Filler Color</b> controls the color of the space between
	the veins.  The vein color diffuses into the filler color.
	*/
	void setFillerColor(const Float3ID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc\";\n",mName.c_str());}
	/*Filler Color red value*/
	void setFillerColorR(float fcr){if(fcr == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fcr\" %f;\n", fcr);}
	/*Filler Color red value*/
	void setFillerColorR(const FloatID& fcr){fprintf_s(mFile,"connectAttr \"");fcr.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcr\";\n",mName.c_str());}
	/*Filler Color green value*/
	void setFillerColorG(float fcg){if(fcg == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fcg\" %f;\n", fcg);}
	/*Filler Color green value*/
	void setFillerColorG(const FloatID& fcg){fprintf_s(mFile,"connectAttr \"");fcg.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcg\";\n",mName.c_str());}
	/*Filler Color blue value*/
	void setFillerColorB(float fcb){if(fcb == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fcb\" %f;\n", fcb);}
	/*Filler Color blue value*/
	void setFillerColorB(const FloatID& fcb){fprintf_s(mFile,"connectAttr \"");fcb.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcb\";\n",mName.c_str());}
	/*
	<b>Vein Color</b> controls the color of the veins (rings) in
	the wood.  The vein color diffuses into the filler color.
	*/
	void setVeinColor(const float3& vc){if(vc == float3(0.157, 0.078, 0.039)) return; fprintf_s(mFile, "setAttr \".vc\" -type \"float3\" ");vc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Vein Color</b> controls the color of the veins (rings) in
	the wood.  The vein color diffuses into the filler color.
	*/
	void setVeinColor(const Float3ID& vc){fprintf_s(mFile,"connectAttr \"");vc.write(mFile);fprintf_s(mFile,"\" \"%s.vc\";\n",mName.c_str());}
	/*Vein Color red value*/
	void setVeinColorR(float vcr){if(vcr == 0.0) return; fprintf_s(mFile, "setAttr \".vc.vcr\" %f;\n", vcr);}
	/*Vein Color red value*/
	void setVeinColorR(const FloatID& vcr){fprintf_s(mFile,"connectAttr \"");vcr.write(mFile);fprintf_s(mFile,"\" \"%s.vc.vcr\";\n",mName.c_str());}
	/*Vein Color green value*/
	void setVeinColorG(float vcg){if(vcg == 0.0) return; fprintf_s(mFile, "setAttr \".vc.vcg\" %f;\n", vcg);}
	/*Vein Color green value*/
	void setVeinColorG(const FloatID& vcg){fprintf_s(mFile,"connectAttr \"");vcg.write(mFile);fprintf_s(mFile,"\" \"%s.vc.vcg\";\n",mName.c_str());}
	/*Vein Color blue value*/
	void setVeinColorB(float vcb){if(vcb == 0.0) return; fprintf_s(mFile, "setAttr \".vc.vcb\" %f;\n", vcb);}
	/*Vein Color blue value*/
	void setVeinColorB(const FloatID& vcb){fprintf_s(mFile,"connectAttr \"");vcb.write(mFile);fprintf_s(mFile,"\" \"%s.vc.vcb\";\n",mName.c_str());}
	/*
	<b>Vein Spread</b> controls the amount that the vein color
	diffuses into the Filler Color.  Increase this to make the
	vein color diffuse more into the filler.
	*/
	void setVeinSpread(float v){if(v == 0.25) return; fprintf_s(mFile, "setAttr \".v\" %f;\n", v);}
	/*
	<b>Vein Spread</b> controls the amount that the vein color
	diffuses into the Filler Color.  Increase this to make the
	vein color diffuse more into the filler.
	*/
	void setVeinSpread(const FloatID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*
	<b>Layer Size</b> controls the average thickness of each
	layer or ring.  (The thickness of individual layers or rings
	is also infludenced by the Randomness and Age attributes.)
	*/
	void setLayerSize(float ls){if(ls == 0.05) return; fprintf_s(mFile, "setAttr \".ls\" %f;\n", ls);}
	/*
	<b>Layer Size</b> controls the average thickness of each
	layer or ring.  (The thickness of individual layers or rings
	is also infludenced by the Randomness and Age attributes.)
	*/
	void setLayerSize(const FloatID& ls){fprintf_s(mFile,"connectAttr \"");ls.write(mFile);fprintf_s(mFile,"\" \"%s.ls\";\n",mName.c_str());}
	/*
	<b>Randomness</b> randomizes the thickness of individual layers
	or rings.  Increase Randomness to make a greater variety of sizes.
	Decrease Randomness to make all the rings exactly the same
	width.
	*/
	void setRandomness(float rd){if(rd == 0.5) return; fprintf_s(mFile, "setAttr \".rd\" %f;\n", rd);}
	/*
	<b>Randomness</b> randomizes the thickness of individual layers
	or rings.  Increase Randomness to make a greater variety of sizes.
	Decrease Randomness to make all the rings exactly the same
	width.
	*/
	void setRandomness(const FloatID& rd){fprintf_s(mFile,"connectAttr \"");rd.write(mFile);fprintf_s(mFile,"\" \"%s.rd\";\n",mName.c_str());}
	/*
	<b>Age</b> controls the age (in years, or number of rings)
	of the tree from which the wood came.  The Age value determines
	the total number of layers or rings in the texture, and influences
	the relative thickness of the central and outer layers.  The
	central rings of wood are thinner than the outer rings because
	a tree's growth is slower when it is young.
	*/
	void setAge(float a){if(a == 20.0) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*
	<b>Age</b> controls the age (in years, or number of rings)
	of the tree from which the wood came.  The Age value determines
	the total number of layers or rings in the texture, and influences
	the relative thickness of the central and outer layers.  The
	central rings of wood are thinner than the outer rings because
	a tree's growth is slower when it is young.
	*/
	void setAge(const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	<b>Grain Color</b> controls the color of the random
	grain in the wood.  (This shows up as spots in the
	texture's cross-section.)
	*/
	void setGrainColor(const float3& gc){if(gc == float3(0.118, 0.039, 0.0)) return; fprintf_s(mFile, "setAttr \".gc\" -type \"float3\" ");gc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Grain Color</b> controls the color of the random
	grain in the wood.  (This shows up as spots in the
	texture's cross-section.)
	*/
	void setGrainColor(const Float3ID& gc){fprintf_s(mFile,"connectAttr \"");gc.write(mFile);fprintf_s(mFile,"\" \"%s.gc\";\n",mName.c_str());}
	/*Grain Color red value*/
	void setGrainColorR(float gcr){if(gcr == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gcr\" %f;\n", gcr);}
	/*Grain Color red value*/
	void setGrainColorR(const FloatID& gcr){fprintf_s(mFile,"connectAttr \"");gcr.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gcr\";\n",mName.c_str());}
	/*Grain Color green value*/
	void setGrainColorG(float gcg){if(gcg == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gcg\" %f;\n", gcg);}
	/*Grain Color green value*/
	void setGrainColorG(const FloatID& gcg){fprintf_s(mFile,"connectAttr \"");gcg.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gcg\";\n",mName.c_str());}
	/*Grain Color blue value*/
	void setGrainColorB(float gcb){if(gcb == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gcb\" %f;\n", gcb);}
	/*Grain Color blue value*/
	void setGrainColorB(const FloatID& gcb){fprintf_s(mFile,"connectAttr \"");gcb.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gcb\";\n",mName.c_str());}
	/*
	<b>Grain Contrast</b> controls the amount that the
	Grain Color diffuses into the surrounding wood color.
	Increase Grain Contrast to make the grain stand out more.
	*/
	void setGrainContrast(float gx){if(gx == 0.5) return; fprintf_s(mFile, "setAttr \".gx\" %f;\n", gx);}
	/*
	<b>Grain Contrast</b> controls the amount that the
	Grain Color diffuses into the surrounding wood color.
	Increase Grain Contrast to make the grain stand out more.
	*/
	void setGrainContrast(const FloatID& gx){fprintf_s(mFile,"connectAttr \"");gx.write(mFile);fprintf_s(mFile,"\" \"%s.gx\";\n",mName.c_str());}
	/*
	<b>Grain Spacing</b> controls the average distance between
	spots.  Increase this to push the spots farther apart.
	*/
	void setGrainSpacing(float gs){if(gs == 0.01) return; fprintf_s(mFile, "setAttr \".gs\" %f;\n", gs);}
	/*
	<b>Grain Spacing</b> controls the average distance between
	spots.  Increase this to push the spots farther apart.
	*/
	void setGrainSpacing(const FloatID& gs){fprintf_s(mFile,"connectAttr \"");gs.write(mFile);fprintf_s(mFile,"\" \"%s.gs\";\n",mName.c_str());}
	/*
	<b>Center</b> controls the location of the center of the
	concentric rings of texture in U and V space.
	*/
	void setCenter(const float2& c){if(c == float2(0.5, -0.5)) return; fprintf_s(mFile, "setAttr \".c\" -type \"float2\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Center</b> controls the location of the center of the
	concentric rings of texture in U and V space.
	*/
	void setCenter(const Float2ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*The U coordinate of the ring center*/
	void setCenterU(float cu){if(cu == 0.0) return; fprintf_s(mFile, "setAttr \".c.cu\" %f;\n", cu);}
	/*The U coordinate of the ring center*/
	void setCenterU(const FloatID& cu){fprintf_s(mFile,"connectAttr \"");cu.write(mFile);fprintf_s(mFile,"\" \"%s.c.cu\";\n",mName.c_str());}
	/*The V coordinate of the ring center*/
	void setCenterV(float cv){if(cv == 0.0) return; fprintf_s(mFile, "setAttr \".c.cv\" %f;\n", cv);}
	/*The V coordinate of the ring center*/
	void setCenterV(const FloatID& cv){fprintf_s(mFile,"connectAttr \"");cv.write(mFile);fprintf_s(mFile,"\" \"%s.c.cv\";\n",mName.c_str());}
	/*The X amplitude for 3D noise*/
	void setAmplitudeX(float ax){if(ax == 0.0) return; fprintf_s(mFile, "setAttr \".ax\" %f;\n", ax);}
	/*The X amplitude for 3D noise*/
	void setAmplitudeX(const FloatID& ax){fprintf_s(mFile,"connectAttr \"");ax.write(mFile);fprintf_s(mFile,"\" \"%s.ax\";\n",mName.c_str());}
	/*The Y amplitude for 3D noise*/
	void setAmplitudeY(float ay){if(ay == 0.0) return; fprintf_s(mFile, "setAttr \".ay\" %f;\n", ay);}
	/*The Y amplitude for 3D noise*/
	void setAmplitudeY(const FloatID& ay){fprintf_s(mFile,"connectAttr \"");ay.write(mFile);fprintf_s(mFile,"\" \"%s.ay\";\n",mName.c_str());}
	/*The ratio control for the fractal noise*/
	void setRatio(float ra){if(ra == 0.35) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*The ratio control for the fractal noise*/
	void setRatio(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*The noise frequencies (ripples)*/
	void setRipples(const float3& r){if(r == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".r\" -type \"float3\" ");r.write(mFile);fprintf_s(mFile,";\n");}
	/*The noise frequencies (ripples)*/
	void setRipples(const Float3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The noise along X*/
	void setRipplesX(float rx){if(rx == 0.0) return; fprintf_s(mFile, "setAttr \".r.rx\" %f;\n", rx);}
	/*The noise along X*/
	void setRipplesX(const FloatID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*The noise along Y*/
	void setRipplesY(float ry){if(ry == 0.0) return; fprintf_s(mFile, "setAttr \".r.ry\" %f;\n", ry);}
	/*The noise along Y*/
	void setRipplesY(const FloatID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*The noise along Z*/
	void setRipplesZ(float rz){if(rz == 0.0) return; fprintf_s(mFile, "setAttr \".r.rz\" %f;\n", rz);}
	/*The noise along Z*/
	void setRipplesZ(const FloatID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*The range for the iteration of the algorithm.*/
	void setDepth(const float2& d){if(d == float2(0.0, 8.0)) return; fprintf_s(mFile, "setAttr \".d\" -type \"float2\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*The range for the iteration of the algorithm.*/
	void setDepth(const Float2ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The minimum value for recursion depth*/
	void setDepthMin(float dmn){if(dmn == 0.0) return; fprintf_s(mFile, "setAttr \".d.dmn\" %f;\n", dmn);}
	/*The minimum value for recursion depth*/
	void setDepthMin(const FloatID& dmn){fprintf_s(mFile,"connectAttr \"");dmn.write(mFile);fprintf_s(mFile,"\" \"%s.d.dmn\";\n",mName.c_str());}
	/*The maximum value for recursion depth*/
	void setDepthMax(float dmx){if(dmx == 0.0) return; fprintf_s(mFile, "setAttr \".d.dmx\" %f;\n", dmx);}
	/*The maximum value for recursion depth*/
	void setDepthMax(const FloatID& dmx){fprintf_s(mFile,"connectAttr \"");dmx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dmx\";\n",mName.c_str());}
	/*The input normal*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The X component of the input normal*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the input normal*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The Z component of the input normal*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointObj(){char buffer[4096];sprintf_s (buffer, "%s.rpo",mName.c_str());return (const char*)buffer;}
	/*The x component of the current reference sample position*/
	FloatID getRefPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.rpo.rox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current reference sample position*/
	FloatID getRefPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.rpo.roy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current reference sample position*/
	FloatID getRefPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.rpo.roz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.rpc",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getRefPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getRefPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getRefPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Filler Color</b> controls the color of the space between
	the veins.  The vein color diffuses into the filler color.
	*/
	Float3ID getFillerColor(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*Filler Color red value*/
	FloatID getFillerColorR(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcr",mName.c_str());return (const char*)buffer;}
	/*Filler Color green value*/
	FloatID getFillerColorG(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcg",mName.c_str());return (const char*)buffer;}
	/*Filler Color blue value*/
	FloatID getFillerColorB(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Vein Color</b> controls the color of the veins (rings) in
	the wood.  The vein color diffuses into the filler color.
	*/
	Float3ID getVeinColor(){char buffer[4096];sprintf_s (buffer, "%s.vc",mName.c_str());return (const char*)buffer;}
	/*Vein Color red value*/
	FloatID getVeinColorR(){char buffer[4096];sprintf_s (buffer, "%s.vc.vcr",mName.c_str());return (const char*)buffer;}
	/*Vein Color green value*/
	FloatID getVeinColorG(){char buffer[4096];sprintf_s (buffer, "%s.vc.vcg",mName.c_str());return (const char*)buffer;}
	/*Vein Color blue value*/
	FloatID getVeinColorB(){char buffer[4096];sprintf_s (buffer, "%s.vc.vcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Vein Spread</b> controls the amount that the vein color
	diffuses into the Filler Color.  Increase this to make the
	vein color diffuse more into the filler.
	*/
	FloatID getVeinSpread(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*
	<b>Layer Size</b> controls the average thickness of each
	layer or ring.  (The thickness of individual layers or rings
	is also infludenced by the Randomness and Age attributes.)
	*/
	FloatID getLayerSize(){char buffer[4096];sprintf_s (buffer, "%s.ls",mName.c_str());return (const char*)buffer;}
	/*
	<b>Randomness</b> randomizes the thickness of individual layers
	or rings.  Increase Randomness to make a greater variety of sizes.
	Decrease Randomness to make all the rings exactly the same
	width.
	*/
	FloatID getRandomness(){char buffer[4096];sprintf_s (buffer, "%s.rd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Age</b> controls the age (in years, or number of rings)
	of the tree from which the wood came.  The Age value determines
	the total number of layers or rings in the texture, and influences
	the relative thickness of the central and outer layers.  The
	central rings of wood are thinner than the outer rings because
	a tree's growth is slower when it is young.
	*/
	FloatID getAge(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grain Color</b> controls the color of the random
	grain in the wood.  (This shows up as spots in the
	texture's cross-section.)
	*/
	Float3ID getGrainColor(){char buffer[4096];sprintf_s (buffer, "%s.gc",mName.c_str());return (const char*)buffer;}
	/*Grain Color red value*/
	FloatID getGrainColorR(){char buffer[4096];sprintf_s (buffer, "%s.gc.gcr",mName.c_str());return (const char*)buffer;}
	/*Grain Color green value*/
	FloatID getGrainColorG(){char buffer[4096];sprintf_s (buffer, "%s.gc.gcg",mName.c_str());return (const char*)buffer;}
	/*Grain Color blue value*/
	FloatID getGrainColorB(){char buffer[4096];sprintf_s (buffer, "%s.gc.gcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grain Contrast</b> controls the amount that the
	Grain Color diffuses into the surrounding wood color.
	Increase Grain Contrast to make the grain stand out more.
	*/
	FloatID getGrainContrast(){char buffer[4096];sprintf_s (buffer, "%s.gx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Grain Spacing</b> controls the average distance between
	spots.  Increase this to push the spots farther apart.
	*/
	FloatID getGrainSpacing(){char buffer[4096];sprintf_s (buffer, "%s.gs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Center</b> controls the location of the center of the
	concentric rings of texture in U and V space.
	*/
	Float2ID getCenter(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*The U coordinate of the ring center*/
	FloatID getCenterU(){char buffer[4096];sprintf_s (buffer, "%s.c.cu",mName.c_str());return (const char*)buffer;}
	/*The V coordinate of the ring center*/
	FloatID getCenterV(){char buffer[4096];sprintf_s (buffer, "%s.c.cv",mName.c_str());return (const char*)buffer;}
	/*The X amplitude for 3D noise*/
	FloatID getAmplitudeX(){char buffer[4096];sprintf_s (buffer, "%s.ax",mName.c_str());return (const char*)buffer;}
	/*The Y amplitude for 3D noise*/
	FloatID getAmplitudeY(){char buffer[4096];sprintf_s (buffer, "%s.ay",mName.c_str());return (const char*)buffer;}
	/*The ratio control for the fractal noise*/
	FloatID getRatio(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*The noise frequencies (ripples)*/
	Float3ID getRipples(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The noise along X*/
	FloatID getRipplesX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*The noise along Y*/
	FloatID getRipplesY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*The noise along Z*/
	FloatID getRipplesZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*The range for the iteration of the algorithm.*/
	Float2ID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The minimum value for recursion depth*/
	FloatID getDepthMin(){char buffer[4096];sprintf_s (buffer, "%s.d.dmn",mName.c_str());return (const char*)buffer;}
	/*The maximum value for recursion depth*/
	FloatID getDepthMax(){char buffer[4096];sprintf_s (buffer, "%s.d.dmx",mName.c_str());return (const char*)buffer;}
protected:
	Wood(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_WOOD_H__
