/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MOUNTAIN_H__
#define __MayaDM_MOUNTAIN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
<b>Mountain</b> textures are used to render terrain. For best
 results, use the same Mountain texture as both a color map and a
 bump or displacement map in your shader.
<p/>
 A Mountain texture gives the appearance of rough, craggy
 rock partially covered in snow.  Snow only sticks to the
 elevated areas of the texture, and areas where it is not
 too steep.  The Mountain texture
 is based on a 2d fractal.
<p/>
 Note:  Changing the color attributes will have no effect on the
 bump or displacement effect of this texture.
<p/>
 Aside from the attributes listed here, Mountain inherits many other
 attributes from its parent node, <a href="texture2d.html">Texture2d</a>.
<p/>
 In the table below, important attributes are shown in <b>bold</b>
 in the description column.
*/
class Mountain : public Texture2d
{
public:
public:
	Mountain(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "mountain"){}
	virtual ~Mountain(){}
	/*
	<b>Snow Color</b> controls the color of the snow in the
	texture.  This is normally left white.
	*/
	void setSnowColor(const float3& sc){if(sc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".sc\" -type \"float3\" ");sc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Snow Color</b> controls the color of the snow in the
	texture.  This is normally left white.
	*/
	void setSnowColor(const Float3ID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*Snow Color red value*/
	void setSnowColorR(float scr){if(scr == 0.0) return; fprintf_s(mFile, "setAttr \".sc.scr\" %f;\n", scr);}
	/*Snow Color red value*/
	void setSnowColorR(const FloatID& scr){fprintf_s(mFile,"connectAttr \"");scr.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scr\";\n",mName.c_str());}
	/*Snow Color green value*/
	void setSnowColorG(float scg){if(scg == 0.0) return; fprintf_s(mFile, "setAttr \".sc.scg\" %f;\n", scg);}
	/*Snow Color green value*/
	void setSnowColorG(const FloatID& scg){fprintf_s(mFile,"connectAttr \"");scg.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scg\";\n",mName.c_str());}
	/*Snow Color blue value*/
	void setSnowColorB(float scb){if(scb == 0.0) return; fprintf_s(mFile, "setAttr \".sc.scb\" %f;\n", scb);}
	/*Snow Color blue value*/
	void setSnowColorB(const FloatID& scb){fprintf_s(mFile,"connectAttr \"");scb.write(mFile);fprintf_s(mFile,"\" \"%s.sc.scb\";\n",mName.c_str());}
	/*
	<b>Rock Color</b> controls the color of the rock seen
	through the snowy parts of the texture.
	*/
	void setRockColor(const float3& rc){if(rc == float3(0.262, 0.102, 0.0)) return; fprintf_s(mFile, "setAttr \".rc\" -type \"float3\" ");rc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Rock Color</b> controls the color of the rock seen
	through the snowy parts of the texture.
	*/
	void setRockColor(const Float3ID& rc){fprintf_s(mFile,"connectAttr \"");rc.write(mFile);fprintf_s(mFile,"\" \"%s.rc\";\n",mName.c_str());}
	/*Rock Color red value*/
	void setRockColorR(float rcr){if(rcr == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rcr\" %f;\n", rcr);}
	/*Rock Color red value*/
	void setRockColorR(const FloatID& rcr){fprintf_s(mFile,"connectAttr \"");rcr.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rcr\";\n",mName.c_str());}
	/*Rock Color green value*/
	void setRockColorG(float rcg){if(rcg == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rcg\" %f;\n", rcg);}
	/*Rock Color green value*/
	void setRockColorG(const FloatID& rcg){fprintf_s(mFile,"connectAttr \"");rcg.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rcg\";\n",mName.c_str());}
	/*Rock Color blue value*/
	void setRockColorB(float rcb){if(rcb == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rcb\" %f;\n", rcb);}
	/*Rock Color blue value*/
	void setRockColorB(const FloatID& rcb){fprintf_s(mFile,"connectAttr \"");rcb.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rcb\";\n",mName.c_str());}
	/*
	<b>Amplitude</b> controls how 'craggy' the Mountain texture
	is. As Amplitude increases, the bumps seem more jagged, and
	more rock is visible through the snowy layer.  As it descreases,
	the surface seens smoother, and less rock shows through
	the snow.
	*/
	void setAmplitude(float a){if(a == 1.0) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*
	<b>Amplitude</b> controls how 'craggy' the Mountain texture
	is. As Amplitude increases, the bumps seem more jagged, and
	more rock is visible through the snowy layer.  As it descreases,
	the surface seens smoother, and less rock shows through
	the snow.
	*/
	void setAmplitude(const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	<b>Snow Roughness</b> controls how bumpy the snowy areas
	of the Mountain texture are.  Increase this value to make
	the snow more detailed and bumpy;  decrease this value
	to make the snow more smooth and rolling.
	*/
	void setSnowRoughness(float sr){if(sr == 0.4) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*
	<b>Snow Roughness</b> controls how bumpy the snowy areas
	of the Mountain texture are.  Increase this value to make
	the snow more detailed and bumpy;  decrease this value
	to make the snow more smooth and rolling.
	*/
	void setSnowRoughness(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	<b>Rock Roughness</b> controls how bumpy the rocky areas
	of the Mountain texture are.  Increase this value to make
	the rock more detailed and craggy;  decrease this value
	to make the rock smoother and more weather-worn.
	*/
	void setRockRoughness(float rr){if(rr == 0.707) return; fprintf_s(mFile, "setAttr \".rr\" %f;\n", rr);}
	/*
	<b>Rock Roughness</b> controls how bumpy the rocky areas
	of the Mountain texture are.  Increase this value to make
	the rock more detailed and craggy;  decrease this value
	to make the rock smoother and more weather-worn.
	*/
	void setRockRoughness(const FloatID& rr){fprintf_s(mFile,"connectAttr \"");rr.write(mFile);fprintf_s(mFile,"\" \"%s.rr\";\n",mName.c_str());}
	/*
	<b>Boundary</b> controls the smoothness of the boundary
	between the snowy and the rocky areas.  Increase
	this value to make the boundaries more finely detailed;
	decrease it to make the boundaries smoother.
	*/
	void setBoundary(float bo){if(bo == 1.0) return; fprintf_s(mFile, "setAttr \".bo\" %f;\n", bo);}
	/*
	<b>Boundary</b> controls the smoothness of the boundary
	between the snowy and the rocky areas.  Increase
	this value to make the boundaries more finely detailed;
	decrease it to make the boundaries smoother.
	*/
	void setBoundary(const FloatID& bo){fprintf_s(mFile,"connectAttr \"");bo.write(mFile);fprintf_s(mFile,"\" \"%s.bo\";\n",mName.c_str());}
	/*
	<b>Snow Altitude</b> controls how far down into the
	mountain crags the snow will reach.  As you increase this
	value, snow covers more and more of the mountain texture.
	As you decrease this value, the snow 'retreats' up to just
	the peaks.
	<p/>
	Note that the 'crags' and 'peaks' referred to here are
	the ones generated by the bump map.  The texture is not
	affected by any crags and peaks that may be in the
	geometry being textured.
	*/
	void setSnowAltitude(float sa){if(sa == 0.5) return; fprintf_s(mFile, "setAttr \".sa\" %f;\n", sa);}
	/*
	<b>Snow Altitude</b> controls how far down into the
	mountain crags the snow will reach.  As you increase this
	value, snow covers more and more of the mountain texture.
	As you decrease this value, the snow 'retreats' up to just
	the peaks.
	<p/>
	Note that the 'crags' and 'peaks' referred to here are
	the ones generated by the bump map.  The texture is not
	affected by any crags and peaks that may be in the
	geometry being textured.
	*/
	void setSnowAltitude(const FloatID& sa){fprintf_s(mFile,"connectAttr \"");sa.write(mFile);fprintf_s(mFile,"\" \"%s.sa\";\n",mName.c_str());}
	/*
	<b>Snow Dropoff</b> controls how the snow tapers off as
	we move from the snowy to the rocky areas of the texture.
	Increase this value to have the snow drop off more abruptly.
	*/
	void setSnowDropoff(float sd){if(sd == 2.0) return; fprintf_s(mFile, "setAttr \".sd\" %f;\n", sd);}
	/*
	<b>Snow Dropoff</b> controls how the snow tapers off as
	we move from the snowy to the rocky areas of the texture.
	Increase this value to have the snow drop off more abruptly.
	*/
	void setSnowDropoff(const FloatID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd\";\n",mName.c_str());}
	/*
	<b>Snow Slope</b> controls how well the snow can stick to
	sloped areas of the texture.  In areas where the texture
	is steep, the snow 'falls off' so that you can see rock.
	If you increase Snow Slope, then the snow can stick to
	steeper slopes, so you see more of it.  If you decrease
	Snow Slope, you see less snow.
	<p/>
	Note that the 'slopes' referred to here are
	the ones generated by the bump map.  The texture is not
	affected by any crags and peaks that may be in the
	geometry being textured.
	*/
	void setSnowSlope(float ss){if(ss == 0.8) return; fprintf_s(mFile, "setAttr \".ss\" %f;\n", ss);}
	/*
	<b>Snow Slope</b> controls how well the snow can stick to
	sloped areas of the texture.  In areas where the texture
	is steep, the snow 'falls off' so that you can see rock.
	If you increase Snow Slope, then the snow can stick to
	steeper slopes, so you see more of it.  If you decrease
	Snow Slope, you see less snow.
	<p/>
	Note that the 'slopes' referred to here are
	the ones generated by the bump map.  The texture is not
	affected by any crags and peaks that may be in the
	geometry being textured.
	*/
	void setSnowSlope(const FloatID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*
	<b>Depth Max</b> is used to limit the amount of calculation
	done by this node.  Fractal textures, such as this one,
	are calculated by an iteratice mathematical process.  The
	more times it iterates, the more detailed the fractal can
	be, but the longer it takes to calculate.  The Maya renderer
	will try to choose the right amount of calculation for
	the geometry you are rendering, but you can use this
	attribute to limit how much calculation it does.
	*/
	void setDepthMax(float dmx){if(dmx == 20.0) return; fprintf_s(mFile, "setAttr \".dmx\" %f;\n", dmx);}
	/*
	<b>Depth Max</b> is used to limit the amount of calculation
	done by this node.  Fractal textures, such as this one,
	are calculated by an iteratice mathematical process.  The
	more times it iterates, the more detailed the fractal can
	be, but the longer it takes to calculate.  The Maya renderer
	will try to choose the right amount of calculation for
	the geometry you are rendering, but you can use this
	attribute to limit how much calculation it does.
	*/
	void setDepthMax(const FloatID& dmx){fprintf_s(mFile,"connectAttr \"");dmx.write(mFile);fprintf_s(mFile,"\" \"%s.dmx\";\n",mName.c_str());}
	/*
	<b>Snow Color</b> controls the color of the snow in the
	texture.  This is normally left white.
	*/
	Float3ID getSnowColor(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*Snow Color red value*/
	FloatID getSnowColorR(){char buffer[4096];sprintf_s (buffer, "%s.sc.scr",mName.c_str());return (const char*)buffer;}
	/*Snow Color green value*/
	FloatID getSnowColorG(){char buffer[4096];sprintf_s (buffer, "%s.sc.scg",mName.c_str());return (const char*)buffer;}
	/*Snow Color blue value*/
	FloatID getSnowColorB(){char buffer[4096];sprintf_s (buffer, "%s.sc.scb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Rock Color</b> controls the color of the rock seen
	through the snowy parts of the texture.
	*/
	Float3ID getRockColor(){char buffer[4096];sprintf_s (buffer, "%s.rc",mName.c_str());return (const char*)buffer;}
	/*Rock Color red value*/
	FloatID getRockColorR(){char buffer[4096];sprintf_s (buffer, "%s.rc.rcr",mName.c_str());return (const char*)buffer;}
	/*Rock Color green value*/
	FloatID getRockColorG(){char buffer[4096];sprintf_s (buffer, "%s.rc.rcg",mName.c_str());return (const char*)buffer;}
	/*Rock Color blue value*/
	FloatID getRockColorB(){char buffer[4096];sprintf_s (buffer, "%s.rc.rcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Amplitude</b> controls how 'craggy' the Mountain texture
	is. As Amplitude increases, the bumps seem more jagged, and
	more rock is visible through the snowy layer.  As it descreases,
	the surface seens smoother, and less rock shows through
	the snow.
	*/
	FloatID getAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	<b>Snow Roughness</b> controls how bumpy the snowy areas
	of the Mountain texture are.  Increase this value to make
	the snow more detailed and bumpy;  decrease this value
	to make the snow more smooth and rolling.
	*/
	FloatID getSnowRoughness(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Rock Roughness</b> controls how bumpy the rocky areas
	of the Mountain texture are.  Increase this value to make
	the rock more detailed and craggy;  decrease this value
	to make the rock smoother and more weather-worn.
	*/
	FloatID getRockRoughness(){char buffer[4096];sprintf_s (buffer, "%s.rr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Boundary</b> controls the smoothness of the boundary
	between the snowy and the rocky areas.  Increase
	this value to make the boundaries more finely detailed;
	decrease it to make the boundaries smoother.
	*/
	FloatID getBoundary(){char buffer[4096];sprintf_s (buffer, "%s.bo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Snow Altitude</b> controls how far down into the
	mountain crags the snow will reach.  As you increase this
	value, snow covers more and more of the mountain texture.
	As you decrease this value, the snow 'retreats' up to just
	the peaks.
	<p/>
	Note that the 'crags' and 'peaks' referred to here are
	the ones generated by the bump map.  The texture is not
	affected by any crags and peaks that may be in the
	geometry being textured.
	*/
	FloatID getSnowAltitude(){char buffer[4096];sprintf_s (buffer, "%s.sa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Snow Dropoff</b> controls how the snow tapers off as
	we move from the snowy to the rocky areas of the texture.
	Increase this value to have the snow drop off more abruptly.
	*/
	FloatID getSnowDropoff(){char buffer[4096];sprintf_s (buffer, "%s.sd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Snow Slope</b> controls how well the snow can stick to
	sloped areas of the texture.  In areas where the texture
	is steep, the snow 'falls off' so that you can see rock.
	If you increase Snow Slope, then the snow can stick to
	steeper slopes, so you see more of it.  If you decrease
	Snow Slope, you see less snow.
	<p/>
	Note that the 'slopes' referred to here are
	the ones generated by the bump map.  The texture is not
	affected by any crags and peaks that may be in the
	geometry being textured.
	*/
	FloatID getSnowSlope(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*
	<b>Depth Max</b> is used to limit the amount of calculation
	done by this node.  Fractal textures, such as this one,
	are calculated by an iteratice mathematical process.  The
	more times it iterates, the more detailed the fractal can
	be, but the longer it takes to calculate.  The Maya renderer
	will try to choose the right amount of calculation for
	the geometry you are rendering, but you can use this
	attribute to limit how much calculation it does.
	*/
	FloatID getDepthMax(){char buffer[4096];sprintf_s (buffer, "%s.dmx",mName.c_str());return (const char*)buffer;}
protected:
	Mountain(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MOUNTAIN_H__
