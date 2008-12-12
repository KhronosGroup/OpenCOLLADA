/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SOLIDFRACTAL_H__
#define __MayaDM_SOLIDFRACTAL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
The <b>Solid Fractal</b> texture represents a three-dimensional random
 function with a particular frequency distribution (a fractal) and can
 be used to create many different types of effects.  In fact, many of
 the other procedural textures are based on fractal mathematics.
<p/>
 Aside from the attributes listed here, Solid Fractal inherits
 many other attributes from its parent, <a href="texture3d.html">
 Texture3d</a>.
<p/>
 In the table below, important attributes have their names shown
 in <b>bold</b> in the Description column.
*/
class SolidFractal : public Texture3d
{
public:
public:
	SolidFractal(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "solidFractal"){}
	virtual ~SolidFractal(){}
	/*The pixel angle*/
	void setXPixelAngle(float xpa){if(xpa == 0.002053) return; fprintf_s(mFile, "setAttr \".xpa\" %f;\n", xpa);}
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
	<b>Amplitude</b> is a scaling factor applied to all the
	values in the texture, centered around the texture's
	average value.  This means that when you increase Amplitude,
	the light areas get lighter and the dark areas get darker.
	<p/>
	If the Solid Fractal is being used as a bump map, then
	increasing Amplitude will make the bumps higher and the
	valleys deeper.
	<p/>If you set Amplitude to a value greater than 1.0, then
	those parts of the texture that scale out of range will be
	clipped.  On a bump map, this will show up as plateau regions.
	*/
	void setAmplitude(float a){if(a == 1.0) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*
	<b>Amplitude</b> is a scaling factor applied to all the
	values in the texture, centered around the texture's
	average value.  This means that when you increase Amplitude,
	the light areas get lighter and the dark areas get darker.
	<p/>
	If the Solid Fractal is being used as a bump map, then
	increasing Amplitude will make the bumps higher and the
	valleys deeper.
	<p/>If you set Amplitude to a value greater than 1.0, then
	those parts of the texture that scale out of range will be
	clipped.  On a bump map, this will show up as plateau regions.
	*/
	void setAmplitude(const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	<b>Ratio</b> controls the frequency of the fractal
	noise.  Increase this value to increase the fineness of
	detail in the fractal,
	*/
	void setRatio(float ra){if(ra == 0.707) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	<b>Ratio</b> controls the frequency of the fractal
	noise.  Increase this value to increase the fineness of
	detail in the fractal,
	*/
	void setRatio(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*
	<b>Threshold</b> is a number that is added to the whole
	fractal, making it uniformly brighter.  If some parts of
	the fractal are pushed up out of range (greater than 1.0),
	then they will be clipped to 1.0.  If the Solid Fractal is being
	used as a bump map, this will show up as plateau regions.
	*/
	void setThreshold(float th){if(th == 0.0) return; fprintf_s(mFile, "setAttr \".th\" %f;\n", th);}
	/*
	<b>Threshold</b> is a number that is added to the whole
	fractal, making it uniformly brighter.  If some parts of
	the fractal are pushed up out of range (greater than 1.0),
	then they will be clipped to 1.0.  If the Solid Fractal is being
	used as a bump map, this will show up as plateau regions.
	*/
	void setThreshold(const FloatID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th\";\n",mName.c_str());}
	/*
	<b>Ripples</b> determines how wavy the image will be when
	projected, but controlling the scale of the fundamental
	frequency of any fractal used in the texture.
	<p/>
	If you increase Ripples in any particular direction, the
	fractal detail will seem to smear out in that direction.
	*/
	void setRipples(const float3& r){if(r == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".r\" -type \"float3\" ");r.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Ripples</b> determines how wavy the image will be when
	projected, but controlling the scale of the fundamental
	frequency of any fractal used in the texture.
	<p/>
	If you increase Ripples in any particular direction, the
	fractal detail will seem to smear out in that direction.
	*/
	void setRipples(const Float3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Ripples X value*/
	void setRipplesX(float rx){if(rx == 0.0) return; fprintf_s(mFile, "setAttr \".r.rx\" %f;\n", rx);}
	/*Ripples X value*/
	void setRipplesX(const FloatID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*Ripples Y value*/
	void setRipplesY(float ry){if(ry == 0.0) return; fprintf_s(mFile, "setAttr \".r.ry\" %f;\n", ry);}
	/*Ripples Y value*/
	void setRipplesY(const FloatID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*Ripples Z value*/
	void setRipplesZ(float rz){if(rz == 0.0) return; fprintf_s(mFile, "setAttr \".r.rz\" %f;\n", rz);}
	/*Ripples Z value*/
	void setRipplesZ(const FloatID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*
	<b>Depth</b> controls
	how much calculation is done by the
	Solid Fractal texture.  Fractal textures
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	void setDepth(const float2& d){if(d == float2(0.0, 8.0)) return; fprintf_s(mFile, "setAttr \".d\" -type \"float2\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Depth</b> controls
	how much calculation is done by the
	Solid Fractal texture.  Fractal textures
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
	<b>Frequency Ratio</b> This determines the relative spacial
	scale of the noise frequencies. If this ratio is not a whole integer then
	the fractal will not repeat  at the integer uv boundaries. A
	cylinder with default placement would then display a seam.
	*/
	void setFrequencyRatio(float fr){if(fr == 2.0) return; fprintf_s(mFile, "setAttr \".fr\" %f;\n", fr);}
	/*
	<b>Frequency Ratio</b> This determines the relative spacial
	scale of the noise frequencies. If this ratio is not a whole integer then
	the fractal will not repeat  at the integer uv boundaries. A
	cylinder with default placement would then display a seam.
	*/
	void setFrequencyRatio(const FloatID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*
	<b>Bias</b> This biases the -1 to 1 noise towards either 1 or 0.
	Values greater than 0  make the fractal more contrasting
	while values less than zero make it more flat with spikes.
	*/
	void setBias(float bs){if(bs == 0.0) return; fprintf_s(mFile, "setAttr \".bs\" %f;\n", bs);}
	/*
	<b>Bias</b> This biases the -1 to 1 noise towards either 1 or 0.
	Values greater than 0  make the fractal more contrasting
	while values less than zero make it more flat with spikes.
	*/
	void setBias(const FloatID& bs){fprintf_s(mFile,"connectAttr \"");bs.write(mFile);fprintf_s(mFile,"\" \"%s.bs\";\n",mName.c_str());}
	/*
	<b>Inflection</b> This applies a kink in the noise function
	This is useful for creating puffy or bumpy effects.
	It is equivalent to abs(noise) * 2 - 1.
	*/
	void setInflection(bool in){if(in == false) return; fprintf_s(mFile, "setAttr \".in\" %i;\n", in);}
	/*
	<b>Inflection</b> This applies a kink in the noise function
	This is useful for creating puffy or bumpy effects.
	It is equivalent to abs(noise) * 2 - 1.
	*/
	void setInflection(const BoolID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in\";\n",mName.c_str());}
	/*
	<b>Animated</b>.  Turn this attribute on if you want
	your fractal texture to be animatable;  that is, to shift
	and change over different frames of your animation.  This
	is useful for creating effects such as static on a tv screen,
	or irregular bubbling on a liquid surface.
	<p/>
	After you turn on this attribute, you must also keyframe
	the Time attribute of the Fractal node at different frames
	to get the effect of motion.
	*/
	void setAnimated(bool an){if(an == false) return; fprintf_s(mFile, "setAttr \".an\" %i;\n", an);}
	/*
	<b>Animated</b>.  Turn this attribute on if you want
	your fractal texture to be animatable;  that is, to shift
	and change over different frames of your animation.  This
	is useful for creating effects such as static on a tv screen,
	or irregular bubbling on a liquid surface.
	<p/>
	After you turn on this attribute, you must also keyframe
	the Time attribute of the Fractal node at different frames
	to get the effect of motion.
	*/
	void setAnimated(const BoolID& an){fprintf_s(mFile,"connectAttr \"");an.write(mFile);fprintf_s(mFile,"\" \"%s.an\";\n",mName.c_str());}
	/*
	<b>Time Ratio</b> This determines the relative time
	scale of the noise frequencies. If this ratio is not a
	whole integer then the animation will not repeat when time = 1.
	The default is equal to the frequency ratio, which means that
	higher frequency noises move faster in direct proportion
	to the frequency. Many natural effects, such as water waves,
	move instead relative to the sqrt of the frequency, thus it
	may create better motion to make the timeRatio = sqrt( frequencyRatio ).
	Thus if the frequencyRatio is 2, make the timeRatio = 1.4.
	*/
	void setTimeRatio(float tr){if(tr == 2.0) return; fprintf_s(mFile, "setAttr \".tr\" %f;\n", tr);}
	/*
	<b>Time Ratio</b> This determines the relative time
	scale of the noise frequencies. If this ratio is not a
	whole integer then the animation will not repeat when time = 1.
	The default is equal to the frequency ratio, which means that
	higher frequency noises move faster in direct proportion
	to the frequency. Many natural effects, such as water waves,
	move instead relative to the sqrt of the frequency, thus it
	may create better motion to make the timeRatio = sqrt( frequencyRatio ).
	Thus if the frequencyRatio is 2, make the timeRatio = 1.4.
	*/
	void setTimeRatio(const FloatID& tr){fprintf_s(mFile,"connectAttr \"");tr.write(mFile);fprintf_s(mFile,"\" \"%s.tr\";\n",mName.c_str());}
	/*
	<b>Time</b> is used to animate a Fractal texture.  (See
	the Animated attribute, above.)  Once you have turned on
	Animated, you can keyframe the Time attribute to control
	the rate and amount of change of the fractal texture
	in your scene.  Set keyframes on this value to make the
	texture start or stop moving, or speed up, etc.
	*/
	void setTime(float ti){if(ti == 0.0) return; fprintf_s(mFile, "setAttr \".ti\" %f;\n", ti);}
	/*
	<b>Time</b> is used to animate a Fractal texture.  (See
	the Animated attribute, above.)  Once you have turned on
	Animated, you can keyframe the Time attribute to control
	the rate and amount of change of the fractal texture
	in your scene.  Set keyframes on this value to make the
	texture start or stop moving, or speed up, etc.
	*/
	void setTime(const FloatID& ti){fprintf_s(mFile,"connectAttr \"");ti.write(mFile);fprintf_s(mFile,"\" \"%s.ti\";\n",mName.c_str());}
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
	<b>Amplitude</b> is a scaling factor applied to all the
	values in the texture, centered around the texture's
	average value.  This means that when you increase Amplitude,
	the light areas get lighter and the dark areas get darker.
	<p/>
	If the Solid Fractal is being used as a bump map, then
	increasing Amplitude will make the bumps higher and the
	valleys deeper.
	<p/>If you set Amplitude to a value greater than 1.0, then
	those parts of the texture that scale out of range will be
	clipped.  On a bump map, this will show up as plateau regions.
	*/
	FloatID getAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ratio</b> controls the frequency of the fractal
	noise.  Increase this value to increase the fineness of
	detail in the fractal,
	*/
	FloatID getRatio(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*
	<b>Threshold</b> is a number that is added to the whole
	fractal, making it uniformly brighter.  If some parts of
	the fractal are pushed up out of range (greater than 1.0),
	then they will be clipped to 1.0.  If the Solid Fractal is being
	used as a bump map, this will show up as plateau regions.
	*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.th",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ripples</b> determines how wavy the image will be when
	projected, but controlling the scale of the fundamental
	frequency of any fractal used in the texture.
	<p/>
	If you increase Ripples in any particular direction, the
	fractal detail will seem to smear out in that direction.
	*/
	Float3ID getRipples(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Ripples X value*/
	FloatID getRipplesX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*Ripples Y value*/
	FloatID getRipplesY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*Ripples Z value*/
	FloatID getRipplesZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Depth</b> controls
	how much calculation is done by the
	Solid Fractal texture.  Fractal textures
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
	<b>Frequency Ratio</b> This determines the relative spacial
	scale of the noise frequencies. If this ratio is not a whole integer then
	the fractal will not repeat  at the integer uv boundaries. A
	cylinder with default placement would then display a seam.
	*/
	FloatID getFrequencyRatio(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bias</b> This biases the -1 to 1 noise towards either 1 or 0.
	Values greater than 0  make the fractal more contrasting
	while values less than zero make it more flat with spikes.
	*/
	FloatID getBias(){char buffer[4096];sprintf_s (buffer, "%s.bs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Inflection</b> This applies a kink in the noise function
	This is useful for creating puffy or bumpy effects.
	It is equivalent to abs(noise) * 2 - 1.
	*/
	BoolID getInflection(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*
	<b>Animated</b>.  Turn this attribute on if you want
	your fractal texture to be animatable;  that is, to shift
	and change over different frames of your animation.  This
	is useful for creating effects such as static on a tv screen,
	or irregular bubbling on a liquid surface.
	<p/>
	After you turn on this attribute, you must also keyframe
	the Time attribute of the Fractal node at different frames
	to get the effect of motion.
	*/
	BoolID getAnimated(){char buffer[4096];sprintf_s (buffer, "%s.an",mName.c_str());return (const char*)buffer;}
	/*
	<b>Time Ratio</b> This determines the relative time
	scale of the noise frequencies. If this ratio is not a
	whole integer then the animation will not repeat when time = 1.
	The default is equal to the frequency ratio, which means that
	higher frequency noises move faster in direct proportion
	to the frequency. Many natural effects, such as water waves,
	move instead relative to the sqrt of the frequency, thus it
	may create better motion to make the timeRatio = sqrt( frequencyRatio ).
	Thus if the frequencyRatio is 2, make the timeRatio = 1.4.
	*/
	FloatID getTimeRatio(){char buffer[4096];sprintf_s (buffer, "%s.tr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Time</b> is used to animate a Fractal texture.  (See
	the Animated attribute, above.)  Once you have turned on
	Animated, you can keyframe the Time attribute to control
	the rate and amount of change of the fractal texture
	in your scene.  Set keyframes on this value to make the
	texture start or stop moving, or speed up, etc.
	*/
	FloatID getTime(){char buffer[4096];sprintf_s (buffer, "%s.ti",mName.c_str());return (const char*)buffer;}
protected:
	SolidFractal(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SOLIDFRACTAL_H__
