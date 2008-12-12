/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NOISE_H__
#define __MayaDM_NOISE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
The <b>Noise</b> texture represents a three-dimensional random
 function with a particular frequency distribution (a fractal) and can
 be used to create many different types of effects.  In fact, many of
 the other procedural textures are based on fractal mathematics.
<p/>
 Aside from the attributes listed here, Noise inherits
 many other attributes from its parent, <a href="texture3d.html">
 Texture3d</a>.
<p/>
 In the table below, important attributes have their names shown
 in <b>bold</b> in the Description column.
*/
class Noise : public Texture2d
{
public:
public:
	Noise(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "noise"){}
	virtual ~Noise(){}
	/*
	<b>Amplitude</b> is a scaling factor applied to all the
	values in the texture, centered around the texture's
	average value.  This means that when you increase Amplitude,
	the light areas get lighter and the dark areas get darker.
	<p/>
	If the Noise is being used as a bump map, then
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
	If the Noise is being used as a bump map, then
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
	then they will be clipped to 1.0.  If the Noise is being
	used as a bump map, this will show up as plateau regions.
	*/
	void setThreshold(float th){if(th == 0.0) return; fprintf_s(mFile, "setAttr \".th\" %f;\n", th);}
	/*
	<b>Threshold</b> is a number that is added to the whole
	fractal, making it uniformly brighter.  If some parts of
	the fractal are pushed up out of range (greater than 1.0),
	then they will be clipped to 1.0.  If the Noise is being
	used as a bump map, this will show up as plateau regions.
	*/
	void setThreshold(const FloatID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th\";\n",mName.c_str());}
	/*
	<b>DepthMax</b> controls
	how much calculation is done by the
	Noise texture.  Fractal textures
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use
	Depth Max to control the maximum amount
	of calculation that the texure will do.
	*/
	void setDepthMax(short dm){if(dm == 3) return; fprintf_s(mFile, "setAttr \".dm\" %i;\n", dm);}
	/*
	<b>DepthMax</b> controls
	how much calculation is done by the
	Noise texture.  Fractal textures
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use
	Depth Max to control the maximum amount
	of calculation that the texure will do.
	*/
	void setDepthMax(const ShortID& dm){fprintf_s(mFile,"connectAttr \"");dm.write(mFile);fprintf_s(mFile,"\" \"%s.dm\";\n",mName.c_str());}
	/*
	<b>Frequency</b> This determines the fundamental frequency
	for the noise. As this value increases the noise becomes more
	detailed. It has the inverse effect of the scale parameter.
	*/
	void setFrequency(float fq){if(fq == 8.0) return; fprintf_s(mFile, "setAttr \".fq\" %f;\n", fq);}
	/*
	<b>Frequency</b> This determines the fundamental frequency
	for the noise. As this value increases the noise becomes more
	detailed. It has the inverse effect of the scale parameter.
	*/
	void setFrequency(const FloatID& fq){fprintf_s(mFile,"connectAttr \"");fq.write(mFile);fprintf_s(mFile,"\" \"%s.fq\";\n",mName.c_str());}
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
	<b>Time</b> is used to animate the Noise texture.
	You can keyframe the Time attribute to control
	the rate and amount of change of the texture.
	Typing the expression "= time" into the edit cell will cause
	the texture to billow when rendered in an animation.
	Typing "= time * 2" will make it billow twice as fast.
	*/
	void setTime(float ti){if(ti == 0.0) return; fprintf_s(mFile, "setAttr \".ti\" %f;\n", ti);}
	/*
	<b>Time</b> is used to animate the Noise texture.
	You can keyframe the Time attribute to control
	the rate and amount of change of the texture.
	Typing the expression "= time" into the edit cell will cause
	the texture to billow when rendered in an animation.
	Typing "= time * 2" will make it billow twice as fast.
	*/
	void setTime(const FloatID& ti){fprintf_s(mFile,"connectAttr \"");ti.write(mFile);fprintf_s(mFile,"\" \"%s.ti\";\n",mName.c_str());}
	/*
	Determines which noise to use during the fractal iteration.
	<b>Perlin</b> is the standard 2D noise used in the fFractal texture.
	<b>Billow</b> has a pluffy, cloudlike effect.
	<b>Wave</b> is a sum of 2D waves in space.
	<b>Wispy</b> is a perlin noise that uses a second noise as a smear
	map. This makes the noise stretch out in places, looking wispy. When the time
	attribute is animated the smear noise is moved causing an undulating effect.
	<b>SpaceTime</b> is a 3 dimensional version of the 2D perlin noise, where
	time is the 3th dimension.
	*/
	void setNoiseType(unsigned int nty){if(nty == 1) return; fprintf_s(mFile, "setAttr \".nty\" %i;\n", nty);}
	/*
	Determines which noise to use during the fractal iteration.
	<b>Perlin</b> is the standard 2D noise used in the fFractal texture.
	<b>Billow</b> has a pluffy, cloudlike effect.
	<b>Wave</b> is a sum of 2D waves in space.
	<b>Wispy</b> is a perlin noise that uses a second noise as a smear
	map. This makes the noise stretch out in places, looking wispy. When the time
	attribute is animated the smear noise is moved causing an undulating effect.
	<b>SpaceTime</b> is a 3 dimensional version of the 2D perlin noise, where
	time is the 3th dimension.
	*/
	void setNoiseType(const UnsignedintID& nty){fprintf_s(mFile,"connectAttr \"");nty.write(mFile);fprintf_s(mFile,"\" \"%s.nty\";\n",mName.c_str());}
	/*
	<b>Density</b> controls how many cells there are imbedded
	in the medium used by the <b>Billow</b> noise type.
	At 1.0, the medium is completely packed
	with cells.  Reduce this value to make the cells more sparse.
	<p/>If the texture is being used as a bump map, then
	low values for Density will make it look like a smooth surface
	with occasional bumps on it.
	*/
	void setDensity(float d){if(d == 1.0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	<b>Density</b> controls how many cells there are imbedded
	in the medium used by the <b>Billow</b> noise type.
	At 1.0, the medium is completely packed
	with cells.  Reduce this value to make the cells more sparse.
	<p/>If the texture is being used as a bump map, then
	low values for Density will make it look like a smooth surface
	with occasional bumps on it.
	*/
	void setDensity(const FloatID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	<b>Spottyness</b> controls the randomization of the density
	of the individual cells used by the <b>Billow</b> noise type.
	When Spottyness is close to 0,
	all the cells will be the same density.  As you increase
	Spottyness, some cells will be denser or thinner than others,
	in a random fashion.
	*/
	void setSpottyness(float sp){if(sp == 0.1) return; fprintf_s(mFile, "setAttr \".sp\" %f;\n", sp);}
	/*
	<b>Spottyness</b> controls the randomization of the density
	of the individual cells used by the <b>Billow</b> noise type.
	When Spottyness is close to 0,
	all the cells will be the same density.  As you increase
	Spottyness, some cells will be denser or thinner than others,
	in a random fashion.
	*/
	void setSpottyness(const FloatID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*
	<b>Size Rand</b> controls the randomization of the size
	of the individual blobs used by the <b>Billow</b> noise type.
	When it is close to 0,
	all the cells will be the same size.  As you increase
	<b>Size Rand</b>, some cells will be smaller than others,
	in a random fashion.
	*/
	void setSizeRand(float sr){if(sr == 0.0) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*
	<b>Size Rand</b> controls the randomization of the size
	of the individual blobs used by the <b>Billow</b> noise type.
	When it is close to 0,
	all the cells will be the same size.  As you increase
	<b>Size Rand</b>, some cells will be smaller than others,
	in a random fashion.
	*/
	void setSizeRand(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	<b>Randomness</b> controls how the cells for the <b>Billow</b>
	noise type are arranged relative to one another.
	Set randomness to 1.0 to get a realistic
	random distribution of cells, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	void setRandomness(float rn){if(rn == 1.0) return; fprintf_s(mFile, "setAttr \".rn\" %f;\n", rn);}
	/*
	<b>Randomness</b> controls how the cells for the <b>Billow</b>
	noise type are arranged relative to one another.
	Set randomness to 1.0 to get a realistic
	random distribution of cells, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	void setRandomness(const FloatID& rn){fprintf_s(mFile,"connectAttr \"");rn.write(mFile);fprintf_s(mFile,"\" \"%s.rn\";\n",mName.c_str());}
	/*
	This controls the way intensity falls off for individual blobs for
	the <b>Billow</b> noise type. <b>Linear</b> is a uniform falloff from the
	center to a value of zero at the edges of the blobs.<b>Smooth</b> is
	more natural looking, using a gaussian falloff. <b>Fast</b> focuses the
	intensity more towards the center of the blobs. <b>Bubble</b> uses a
	reverse falloff, fading to zero at the blob center.
	*/
	void setFalloff(unsigned int fof){if(fof == 2) return; fprintf_s(mFile, "setAttr \".fof\" %i;\n", fof);}
	/*
	This controls the way intensity falls off for individual blobs for
	the <b>Billow</b> noise type. <b>Linear</b> is a uniform falloff from the
	center to a value of zero at the edges of the blobs.<b>Smooth</b> is
	more natural looking, using a gaussian falloff. <b>Fast</b> focuses the
	intensity more towards the center of the blobs. <b>Bubble</b> uses a
	reverse falloff, fading to zero at the blob center.
	*/
	void setFalloff(const UnsignedintID& fof){fprintf_s(mFile,"connectAttr \"");fof.write(mFile);fprintf_s(mFile,"\" \"%s.fof\";\n",mName.c_str());}
	/*
	<b>NumWaves</b> determines how many waves to generate for the <b>Wave</b>
	noise type. The larger this number the more random looking and slower the texture.
	*/
	void setNumWaves(short nw){if(nw == 5) return; fprintf_s(mFile, "setAttr \".nw\" %i;\n", nw);}
	/*
	<b>NumWaves</b> determines how many waves to generate for the <b>Wave</b>
	noise type. The larger this number the more random looking and slower the texture.
	*/
	void setNumWaves(const ShortID& nw){fprintf_s(mFile,"connectAttr \"");nw.write(mFile);fprintf_s(mFile,"\" \"%s.nw\";\n",mName.c_str());}
	/*
	<b>Implode</b> warps the noise function in a concentric fashion
	about a point defined by the <b>Implode Center</b>.
	At a value of zero there is no effect, while at a value of
	1.0 it is a spherical projection of the noise function, creating
	a starburst effect. Negative values can be used to skew the noise
	outward instead of inward.
	*/
	void setImplode(float imp){if(imp == 0.0) return; fprintf_s(mFile, "setAttr \".imp\" %f;\n", imp);}
	/*
	<b>Implode</b> warps the noise function in a concentric fashion
	about a point defined by the <b>Implode Center</b>.
	At a value of zero there is no effect, while at a value of
	1.0 it is a spherical projection of the noise function, creating
	a starburst effect. Negative values can be used to skew the noise
	outward instead of inward.
	*/
	void setImplode(const FloatID& imp){fprintf_s(mFile,"connectAttr \"");imp.write(mFile);fprintf_s(mFile,"\" \"%s.imp\";\n",mName.c_str());}
	/*
	<b>Implode Center</b> defines the center uv point about which the
	implode effect is defined.
	*/
	void setImplodeCenter(const float2& imc){if(imc == float2(0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".imc\" -type \"float2\" ");imc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Implode Center</b> defines the center uv point about which the
	implode effect is defined.
	*/
	void setImplodeCenter(const Float2ID& imc){fprintf_s(mFile,"connectAttr \"");imc.write(mFile);fprintf_s(mFile,"\" \"%s.imc\";\n",mName.c_str());}
	/*<b>Implode Center U</b> u position for implode effect*/
	void setImplodeCenterU(float imu){if(imu == 0.0) return; fprintf_s(mFile, "setAttr \".imc.imu\" %f;\n", imu);}
	/*<b>Implode Center U</b> u position for implode effect*/
	void setImplodeCenterU(const FloatID& imu){fprintf_s(mFile,"connectAttr \"");imu.write(mFile);fprintf_s(mFile,"\" \"%s.imc.imu\";\n",mName.c_str());}
	/*<b>Implode Center V</b> v position for implode effect*/
	void setImplodeCenterV(float imv){if(imv == 0.0) return; fprintf_s(mFile, "setAttr \".imc.imv\" %f;\n", imv);}
	/*<b>Implode Center V</b> v position for implode effect*/
	void setImplodeCenterV(const FloatID& imv){fprintf_s(mFile,"connectAttr \"");imv.write(mFile);fprintf_s(mFile,"\" \"%s.imc.imv\";\n",mName.c_str());}
	/*
	<b>Amplitude</b> is a scaling factor applied to all the
	values in the texture, centered around the texture's
	average value.  This means that when you increase Amplitude,
	the light areas get lighter and the dark areas get darker.
	<p/>
	If the Noise is being used as a bump map, then
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
	then they will be clipped to 1.0.  If the Noise is being
	used as a bump map, this will show up as plateau regions.
	*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.th",mName.c_str());return (const char*)buffer;}
	/*
	<b>DepthMax</b> controls
	how much calculation is done by the
	Noise texture.  Fractal textures
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use
	Depth Max to control the maximum amount
	of calculation that the texure will do.
	*/
	ShortID getDepthMax(){char buffer[4096];sprintf_s (buffer, "%s.dm",mName.c_str());return (const char*)buffer;}
	/*
	<b>Frequency</b> This determines the fundamental frequency
	for the noise. As this value increases the noise becomes more
	detailed. It has the inverse effect of the scale parameter.
	*/
	FloatID getFrequency(){char buffer[4096];sprintf_s (buffer, "%s.fq",mName.c_str());return (const char*)buffer;}
	/*
	<b>Frequency Ratio</b> This determines the relative spacial
	scale of the noise frequencies. If this ratio is not a whole integer then
	the fractal will not repeat  at the integer uv boundaries. A
	cylinder with default placement would then display a seam.
	*/
	FloatID getFrequencyRatio(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Inflection</b> This applies a kink in the noise function
	This is useful for creating puffy or bumpy effects.
	It is equivalent to abs(noise) * 2 - 1.
	*/
	BoolID getInflection(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*
	<b>Time</b> is used to animate the Noise texture.
	You can keyframe the Time attribute to control
	the rate and amount of change of the texture.
	Typing the expression "= time" into the edit cell will cause
	the texture to billow when rendered in an animation.
	Typing "= time * 2" will make it billow twice as fast.
	*/
	FloatID getTime(){char buffer[4096];sprintf_s (buffer, "%s.ti",mName.c_str());return (const char*)buffer;}
	/*
	Determines which noise to use during the fractal iteration.
	<b>Perlin</b> is the standard 2D noise used in the fFractal texture.
	<b>Billow</b> has a pluffy, cloudlike effect.
	<b>Wave</b> is a sum of 2D waves in space.
	<b>Wispy</b> is a perlin noise that uses a second noise as a smear
	map. This makes the noise stretch out in places, looking wispy. When the time
	attribute is animated the smear noise is moved causing an undulating effect.
	<b>SpaceTime</b> is a 3 dimensional version of the 2D perlin noise, where
	time is the 3th dimension.
	*/
	UnsignedintID getNoiseType(){char buffer[4096];sprintf_s (buffer, "%s.nty",mName.c_str());return (const char*)buffer;}
	/*
	<b>Density</b> controls how many cells there are imbedded
	in the medium used by the <b>Billow</b> noise type.
	At 1.0, the medium is completely packed
	with cells.  Reduce this value to make the cells more sparse.
	<p/>If the texture is being used as a bump map, then
	low values for Density will make it look like a smooth surface
	with occasional bumps on it.
	*/
	FloatID getDensity(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	<b>Spottyness</b> controls the randomization of the density
	of the individual cells used by the <b>Billow</b> noise type.
	When Spottyness is close to 0,
	all the cells will be the same density.  As you increase
	Spottyness, some cells will be denser or thinner than others,
	in a random fashion.
	*/
	FloatID getSpottyness(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Size Rand</b> controls the randomization of the size
	of the individual blobs used by the <b>Billow</b> noise type.
	When it is close to 0,
	all the cells will be the same size.  As you increase
	<b>Size Rand</b>, some cells will be smaller than others,
	in a random fashion.
	*/
	FloatID getSizeRand(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Randomness</b> controls how the cells for the <b>Billow</b>
	noise type are arranged relative to one another.
	Set randomness to 1.0 to get a realistic
	random distribution of cells, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	FloatID getRandomness(){char buffer[4096];sprintf_s (buffer, "%s.rn",mName.c_str());return (const char*)buffer;}
	/*
	This controls the way intensity falls off for individual blobs for
	the <b>Billow</b> noise type. <b>Linear</b> is a uniform falloff from the
	center to a value of zero at the edges of the blobs.<b>Smooth</b> is
	more natural looking, using a gaussian falloff. <b>Fast</b> focuses the
	intensity more towards the center of the blobs. <b>Bubble</b> uses a
	reverse falloff, fading to zero at the blob center.
	*/
	UnsignedintID getFalloff(){char buffer[4096];sprintf_s (buffer, "%s.fof",mName.c_str());return (const char*)buffer;}
	/*
	<b>NumWaves</b> determines how many waves to generate for the <b>Wave</b>
	noise type. The larger this number the more random looking and slower the texture.
	*/
	ShortID getNumWaves(){char buffer[4096];sprintf_s (buffer, "%s.nw",mName.c_str());return (const char*)buffer;}
	/*
	<b>Implode</b> warps the noise function in a concentric fashion
	about a point defined by the <b>Implode Center</b>.
	At a value of zero there is no effect, while at a value of
	1.0 it is a spherical projection of the noise function, creating
	a starburst effect. Negative values can be used to skew the noise
	outward instead of inward.
	*/
	FloatID getImplode(){char buffer[4096];sprintf_s (buffer, "%s.imp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Implode Center</b> defines the center uv point about which the
	implode effect is defined.
	*/
	Float2ID getImplodeCenter(){char buffer[4096];sprintf_s (buffer, "%s.imc",mName.c_str());return (const char*)buffer;}
	/*<b>Implode Center U</b> u position for implode effect*/
	FloatID getImplodeCenterU(){char buffer[4096];sprintf_s (buffer, "%s.imc.imu",mName.c_str());return (const char*)buffer;}
	/*<b>Implode Center V</b> v position for implode effect*/
	FloatID getImplodeCenterV(){char buffer[4096];sprintf_s (buffer, "%s.imc.imv",mName.c_str());return (const char*)buffer;}
protected:
	Noise(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NOISE_H__
