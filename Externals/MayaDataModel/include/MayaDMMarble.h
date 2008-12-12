/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MARBLE_H__
#define __MayaDM_MARBLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
The <b>Marble</b> texture consists of horizontal layers of one
 material (the Vein), sandwiched between layers of Filler material.
 The Vein is assumed to contain a strong pigmenting agent that
 crosses the boundary and diffuses into the Filler material.
<p/>
 Aside from the attributes listed here, Marble inherits
 many other attributes from <a href="texture3d.html">Texture3d</a>.
<p/>
 In the table below, important attributes have their names
 shown in <b>bold</b> in the description column.
*/
class Marble : public Texture3d
{
public:
public:
	Marble(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "marble"){}
	virtual ~Marble(){}
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
	<b>Filler Color</b> controls the color of the Filler
	material (the material between the veins) of the Marble
	texture.
	*/
	void setFillerColor(const float3& fc){if(fc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".fc\" -type \"float3\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Filler Color</b> controls the color of the Filler
	material (the material between the veins) of the Marble
	texture.
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
	<b>Vein Color</b>. controls the color of the Vwins that
	are sandwiched within the marble.
	*/
	void setVeinColor(const float3& vc){if(vc == float3(0.298, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".vc\" -type \"float3\" ");vc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Vein Color</b>. controls the color of the Vwins that
	are sandwiched within the marble.
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
	/*<b>Vein Width</b> controls the thickness of the veins.*/
	void setVeinWidth(float vw){if(vw == 0.1) return; fprintf_s(mFile, "setAttr \".vw\" %f;\n", vw);}
	/*<b>Vein Width</b> controls the thickness of the veins.*/
	void setVeinWidth(const FloatID& vw){fprintf_s(mFile,"connectAttr \"");vw.write(mFile);fprintf_s(mFile,"\" \"%s.vw\";\n",mName.c_str());}
	/*
	<b>Diffusion</b> controls how much of the Vein Color
	bleeds into the filler surrounding the vein.  Low
	values of Diffusion cause the colors to be completely
	separated.  High values cause the vein color to spread
	right out through the filler material, staining it.
	(see also Contrast).
	*/
	void setDiffusion(float di){if(di == 0.5) return; fprintf_s(mFile, "setAttr \".di\" %f;\n", di);}
	/*
	<b>Diffusion</b> controls how much of the Vein Color
	bleeds into the filler surrounding the vein.  Low
	values of Diffusion cause the colors to be completely
	separated.  High values cause the vein color to spread
	right out through the filler material, staining it.
	(see also Contrast).
	*/
	void setDiffusion(const FloatID& di){fprintf_s(mFile,"connectAttr \"");di.write(mFile);fprintf_s(mFile,"\" \"%s.di\";\n",mName.c_str());}
	/*
	<b>Contrast</b> controls how much the two colors
	blend into one another in the areas where the vein color
	is diffusing into the filler color.  Increase Contrast
	to reduce the amount of mixing.  Setting Contrast to
	its maximum value (1.0) will produce the same result
	as setting Diffusion to 0.  (See also Diffusion)
	*/
	void setContrast(float c){if(c == 0.5) return; fprintf_s(mFile, "setAttr \".c\" %f;\n", c);}
	/*
	<b>Contrast</b> controls how much the two colors
	blend into one another in the areas where the vein color
	is diffusing into the filler color.  Increase Contrast
	to reduce the amount of mixing.  Setting Contrast to
	its maximum value (1.0) will produce the same result
	as setting Diffusion to 0.  (See also Diffusion)
	*/
	void setContrast(const FloatID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*
	<b>Ripples</b> can be used to smear the material in
	a direction or make it wavy.  (It controls the scale
	of the fundamental frequency of the fractal noise used in
	the texture).
	*/
	void setRipples(const float3& r){if(r == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".r\" -type \"float3\" ");r.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Ripples</b> can be used to smear the material in
	a direction or make it wavy.  (It controls the scale
	of the fundamental frequency of the fractal noise used in
	the texture).
	*/
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
	/*
	<b>Depth</b> controls
	how much calculation is done by the
	Marble texture.  Fractal textures (such as Marble)
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	void setDepth(const float2& d){if(d == float2(0.0, 20.0)) return; fprintf_s(mFile, "setAttr \".d\" -type \"float2\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Depth</b> controls
	how much calculation is done by the
	Marble texture.  Fractal textures (such as Marble)
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	void setDepth(const Float2ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The minimum value for recursion depth*/
	void setDepthMin(float dmn){if(dmn == 0.0) return; fprintf_s(mFile, "setAttr \".d.dmn\" %f;\n", dmn);}
	/*The minimum value for recursion depth*/
	void setDepthMin(const FloatID& dmn){fprintf_s(mFile,"connectAttr \"");dmn.write(mFile);fprintf_s(mFile,"\" \"%s.d.dmn\";\n",mName.c_str());}
	/*The maximum value for recursion depth*/
	void setDepthMax(float dmx){if(dmx == 0.0) return; fprintf_s(mFile, "setAttr \".d.dmx\" %f;\n", dmx);}
	/*The maximum value for recursion depth*/
	void setDepthMax(const FloatID& dmx){fprintf_s(mFile,"connectAttr \"");dmx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dmx\";\n",mName.c_str());}
	/*
	<b>Amplitude</b> controls the amount of perturbation
	in the veins.  If you set Amplitude to 0.0, the veins
	in the marble become perfectly flat planes.  As you increase
	Amplitude, the veins become more irregular in shape.
	*/
	void setAmplitude(float a){if(a == 1.5) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*
	<b>Amplitude</b> controls the amount of perturbation
	in the veins.  If you set Amplitude to 0.0, the veins
	in the marble become perfectly flat planes.  As you increase
	Amplitude, the veins become more irregular in shape.
	*/
	void setAmplitude(const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	<b>Ratio</b> controls the Ratio of the fractal noise
	used to generate this texture.  For best results, keep
	this value around the middle of the range.
	*/
	void setRatio(float ra){if(ra == 0.707) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	<b>Ratio</b> controls the Ratio of the fractal noise
	used to generate this texture.  For best results, keep
	this value around the middle of the range.
	*/
	void setRatio(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
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
	<b>Filler Color</b> controls the color of the Filler
	material (the material between the veins) of the Marble
	texture.
	*/
	Float3ID getFillerColor(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*Filler Color red value*/
	FloatID getFillerColorR(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcr",mName.c_str());return (const char*)buffer;}
	/*Filler Color green value*/
	FloatID getFillerColorG(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcg",mName.c_str());return (const char*)buffer;}
	/*Filler Color blue value*/
	FloatID getFillerColorB(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Vein Color</b>. controls the color of the Vwins that
	are sandwiched within the marble.
	*/
	Float3ID getVeinColor(){char buffer[4096];sprintf_s (buffer, "%s.vc",mName.c_str());return (const char*)buffer;}
	/*Vein Color red value*/
	FloatID getVeinColorR(){char buffer[4096];sprintf_s (buffer, "%s.vc.vcr",mName.c_str());return (const char*)buffer;}
	/*Vein Color green value*/
	FloatID getVeinColorG(){char buffer[4096];sprintf_s (buffer, "%s.vc.vcg",mName.c_str());return (const char*)buffer;}
	/*Vein Color blue value*/
	FloatID getVeinColorB(){char buffer[4096];sprintf_s (buffer, "%s.vc.vcb",mName.c_str());return (const char*)buffer;}
	/*<b>Vein Width</b> controls the thickness of the veins.*/
	FloatID getVeinWidth(){char buffer[4096];sprintf_s (buffer, "%s.vw",mName.c_str());return (const char*)buffer;}
	/*
	<b>Diffusion</b> controls how much of the Vein Color
	bleeds into the filler surrounding the vein.  Low
	values of Diffusion cause the colors to be completely
	separated.  High values cause the vein color to spread
	right out through the filler material, staining it.
	(see also Contrast).
	*/
	FloatID getDiffusion(){char buffer[4096];sprintf_s (buffer, "%s.di",mName.c_str());return (const char*)buffer;}
	/*
	<b>Contrast</b> controls how much the two colors
	blend into one another in the areas where the vein color
	is diffusing into the filler color.  Increase Contrast
	to reduce the amount of mixing.  Setting Contrast to
	its maximum value (1.0) will produce the same result
	as setting Diffusion to 0.  (See also Diffusion)
	*/
	FloatID getContrast(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ripples</b> can be used to smear the material in
	a direction or make it wavy.  (It controls the scale
	of the fundamental frequency of the fractal noise used in
	the texture).
	*/
	Float3ID getRipples(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The noise along X*/
	FloatID getRipplesX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*The noise along Y*/
	FloatID getRipplesY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*The noise along Z*/
	FloatID getRipplesZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Depth</b> controls
	how much calculation is done by the
	Marble texture.  Fractal textures (such as Marble)
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	Float2ID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The minimum value for recursion depth*/
	FloatID getDepthMin(){char buffer[4096];sprintf_s (buffer, "%s.d.dmn",mName.c_str());return (const char*)buffer;}
	/*The maximum value for recursion depth*/
	FloatID getDepthMax(){char buffer[4096];sprintf_s (buffer, "%s.d.dmx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Amplitude</b> controls the amount of perturbation
	in the veins.  If you set Amplitude to 0.0, the veins
	in the marble become perfectly flat planes.  As you increase
	Amplitude, the veins become more irregular in shape.
	*/
	FloatID getAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ratio</b> controls the Ratio of the fractal noise
	used to generate this texture.  For best results, keep
	this value around the middle of the range.
	*/
	FloatID getRatio(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
protected:
	Marble(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MARBLE_H__
