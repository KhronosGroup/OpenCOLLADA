/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FRACTAL_H__
#define __MayaDM_FRACTAL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
<b>Fractal</b> textures are very useful for simulating
 many natural phenomena.  Some examples:

 <ul>
   <li>Used as a bump map, Fractals can create surface textures like
   sand or dirt.</li>
   <li>A stretched-out fractal bump map can make a metal surface
   look brushed.</li>
   <li>Used as a color (and bump), Fractals can
   create patterns of rust.</li>
   <li>Attached to the Cloud Texture imput of an Env Sky node,
   Fractals create natural-looking clouds.</li>
   <li>Attached to the V Offset attribute of a 2d Texture Placement
   node, Fractals produce a smearing effect, like a smear map.</li>
   <li>Attached to the Intensity attribute of a light, Fractals
   produce a irregular lighting effect, useful for things such as
   moonlight, or light passing through clouds.</li>
 </ul>

 You can create even more interesting effects by having one fractal
 node attached to the Amplitude attribute of another.
 <p/>
  Aside from the attributes listed here, Fractal inherits many other
  attributes from its parent node, <a href="texture2d.html">Texture2d</a>.
 <p/>
 In the table below, important attributes are shown in <b>bold</b>
 in the description column.
*/
class Fractal : public Texture2d
{
public:
public:
	Fractal(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "fractal"){}
	virtual ~Fractal(){}
	/*
	<b>Amplitude</b> controls the amount of fractal effect.
	When you increase it, the bright areas become brighter
	and the dark areas darker.  If you are using the fractal
	as a bump or displacement map, it will make the bumps
	more pronounced.
	*/
	void setAmplitude(float a){if(a == 1.0) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*
	<b>Amplitude</b> controls the amount of fractal effect.
	When you increase it, the bright areas become brighter
	and the dark areas darker.  If you are using the fractal
	as a bump or displacement map, it will make the bumps
	more pronounced.
	*/
	void setAmplitude(const FloatID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	<b>Ratio</b> controls the blending between the bright
	and dark areas of the fractal.  As you increase Ratio,
	the edges between light and dark are more blurred.  If the
	fractal is used as bump map, this would make the bumps appear
	more like rolling hills and less like craggy mountains.
	If you decrease Ratio, the edges in the fractal become
	sharper.
	*/
	void setRatio(float ra){if(ra == 0.707) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	<b>Ratio</b> controls the blending between the bright
	and dark areas of the fractal.  As you increase Ratio,
	the edges between light and dark are more blurred.  If the
	fractal is used as bump map, this would make the bumps appear
	more like rolling hills and less like craggy mountains.
	If you decrease Ratio, the edges in the fractal become
	sharper.
	*/
	void setRatio(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*
	<b>Threshold</b> controls how much of the Fractal is
	white.  As you increase this value, more of the Fractal
	is white.  At high values, the fractal looks like a white
	area with irregular darker dots.  As you decrease this
	attribute, more and more detail becomes visible.
	*/
	void setThreshold(float th){if(th == 0.0) return; fprintf_s(mFile, "setAttr \".th\" %f;\n", th);}
	/*
	<b>Threshold</b> controls how much of the Fractal is
	white.  As you increase this value, more of the Fractal
	is white.  At high values, the fractal looks like a white
	area with irregular darker dots.  As you decrease this
	attribute, more and more detail becomes visible.
	*/
	void setThreshold(const FloatID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th\";\n",mName.c_str());}
	/*
	<b>Level Min</b> and <b>Level Max</b> are used
	to control how much calculation is done by the
	Fractal texture.  Fractals are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	surface being rendered.  You can use Level Min and
	Level Max to control the minimum and maximum amount
	of calculation the node will do.
	*/
	void setLevelMin(float lmn){if(lmn == 0.0) return; fprintf_s(mFile, "setAttr \".lmn\" %f;\n", lmn);}
	/*
	<b>Level Min</b> and <b>Level Max</b> are used
	to control how much calculation is done by the
	Fractal texture.  Fractals are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	surface being rendered.  You can use Level Min and
	Level Max to control the minimum and maximum amount
	of calculation the node will do.
	*/
	void setLevelMin(const FloatID& lmn){fprintf_s(mFile,"connectAttr \"");lmn.write(mFile);fprintf_s(mFile,"\" \"%s.lmn\";\n",mName.c_str());}
	/*<b>Level Max</b>.  See the description for Level Min (above).*/
	void setLevelMax(float lmx){if(lmx == 9.0) return; fprintf_s(mFile, "setAttr \".lmx\" %f;\n", lmx);}
	/*<b>Level Max</b>.  See the description for Level Min (above).*/
	void setLevelMax(const FloatID& lmx){fprintf_s(mFile,"connectAttr \"");lmx.write(mFile);fprintf_s(mFile,"\" \"%s.lmx\";\n",mName.c_str());}
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
	/*
	<b>Amplitude</b> controls the amount of fractal effect.
	When you increase it, the bright areas become brighter
	and the dark areas darker.  If you are using the fractal
	as a bump or displacement map, it will make the bumps
	more pronounced.
	*/
	FloatID getAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ratio</b> controls the blending between the bright
	and dark areas of the fractal.  As you increase Ratio,
	the edges between light and dark are more blurred.  If the
	fractal is used as bump map, this would make the bumps appear
	more like rolling hills and less like craggy mountains.
	If you decrease Ratio, the edges in the fractal become
	sharper.
	*/
	FloatID getRatio(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*
	<b>Threshold</b> controls how much of the Fractal is
	white.  As you increase this value, more of the Fractal
	is white.  At high values, the fractal looks like a white
	area with irregular darker dots.  As you decrease this
	attribute, more and more detail becomes visible.
	*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.th",mName.c_str());return (const char*)buffer;}
	/*
	<b>Level Min</b> and <b>Level Max</b> are used
	to control how much calculation is done by the
	Fractal texture.  Fractals are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	surface being rendered.  You can use Level Min and
	Level Max to control the minimum and maximum amount
	of calculation the node will do.
	*/
	FloatID getLevelMin(){char buffer[4096];sprintf_s (buffer, "%s.lmn",mName.c_str());return (const char*)buffer;}
	/*<b>Level Max</b>.  See the description for Level Min (above).*/
	FloatID getLevelMax(){char buffer[4096];sprintf_s (buffer, "%s.lmx",mName.c_str());return (const char*)buffer;}
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
	Fractal(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FRACTAL_H__
