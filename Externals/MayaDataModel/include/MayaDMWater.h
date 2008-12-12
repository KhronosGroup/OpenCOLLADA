/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WATER_H__
#define __MayaDM_WATER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
The <b>Water</b> texture is a parametric texture used to produce
 water effects.  If used as a bump or displacement map, the result
 resembles water waves or ripples.  Water waves consist of linear
 sine waves , whereas water ripples consist of concentric rings
 originating from a drop.  You can control the number, size, and
 speed of both the linear waves and the concentric ripples.
<p/>
  Aside from the attributes listed here, Water inherits many other
  attributes from its parent node, <a href="texture2d.html">Texture2d</a>.
  <p/>
  In the table below, important attributes have their names listed
  in <b>bold</b> in the description column.
/
*/
class Water : public Texture2d
{
public:
public:
	Water(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "water"){}
	virtual ~Water(){}
	/*
	<b>Number of Waves</b> controls how many linear waves are
	generated, when this texture is animated.  (See
	the Wave Time attribute below).
	<p/>
	If you want this texture to show only concentric ripples,
	set Number of Waves to 0.  If you want to combine linear waves
	and ripples, try values between 1 and 3.
	*/
	void setNumberOfWaves(short nw){if(nw == 8) return; fprintf_s(mFile, "setAttr \".nw\" %i;\n", nw);}
	/*
	<b>Number of Waves</b> controls how many linear waves are
	generated, when this texture is animated.  (See
	the Wave Time attribute below).
	<p/>
	If you want this texture to show only concentric ripples,
	set Number of Waves to 0.  If you want to combine linear waves
	and ripples, try values between 1 and 3.
	*/
	void setNumberOfWaves(const ShortID& nw){fprintf_s(mFile,"connectAttr \"");nw.write(mFile);fprintf_s(mFile,"\" \"%s.nw\";\n",mName.c_str());}
	/*
	<b>Wave Time</b> controls the motion of the waves.  Set
	keyframes on this attribute in order to animate the motion
	of the linear waves.  The faster this changes, the faster
	the waves will go.
	*/
	void setWaveTime(float wt){if(wt == 0.0) return; fprintf_s(mFile, "setAttr \".wt\" %f;\n", wt);}
	/*
	<b>Wave Time</b> controls the motion of the waves.  Set
	keyframes on this attribute in order to animate the motion
	of the linear waves.  The faster this changes, the faster
	the waves will go.
	*/
	void setWaveTime(const FloatID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.wt\";\n",mName.c_str());}
	/*
	<b>Wave Velocity</b> controls the speed of the linear waves,
	if you have animated them using the Wave Time attribute above.
	<p/>
	This attribute is effectively just a multiplier on Wave Time.
	*/
	void setWaveVelocity(float wv){if(wv == 1.0) return; fprintf_s(mFile, "setAttr \".wv\" %f;\n", wv);}
	/*
	<b>Wave Velocity</b> controls the speed of the linear waves,
	if you have animated them using the Wave Time attribute above.
	<p/>
	This attribute is effectively just a multiplier on Wave Time.
	*/
	void setWaveVelocity(const FloatID& wv){fprintf_s(mFile,"connectAttr \"");wv.write(mFile);fprintf_s(mFile,"\" \"%s.wv\";\n",mName.c_str());}
	/*
	<b>Wave Amplitude</b> controls the height of the waves.
	Increase this to make the waves higher.
	*/
	void setWaveAmplitude(float wa){if(wa == 0.05) return; fprintf_s(mFile, "setAttr \".wa\" %f;\n", wa);}
	/*
	<b>Wave Amplitude</b> controls the height of the waves.
	Increase this to make the waves higher.
	*/
	void setWaveAmplitude(const FloatID& wa){fprintf_s(mFile,"connectAttr \"");wa.write(mFile);fprintf_s(mFile,"\" \"%s.wa\";\n",mName.c_str());}
	/*
	<b>Wave Frequency</b> controls the frequency of the waves,
	and therefore their width.  As you increase Wave Frequency,
	the waves get narrower and closer together.  Their height does
	not change.
	*/
	void setWaveFrequency(float wf){if(wf == 4.0) return; fprintf_s(mFile, "setAttr \".wf\" %f;\n", wf);}
	/*
	<b>Wave Frequency</b> controls the frequency of the waves,
	and therefore their width.  As you increase Wave Frequency,
	the waves get narrower and closer together.  Their height does
	not change.
	*/
	void setWaveFrequency(const FloatID& wf){fprintf_s(mFile,"connectAttr \"");wf.write(mFile);fprintf_s(mFile,"\" \"%s.wf\";\n",mName.c_str());}
	/*
	<b>Sub Wave Frequency</b> controls the frequency (and therefore
	the width) of any secondary waves that ride on top of the
	primary waves (white caps, for example).
	*/
	void setSubWaveFrequency(float swf){if(swf == 0.125) return; fprintf_s(mFile, "setAttr \".swf\" %f;\n", swf);}
	/*
	<b>Sub Wave Frequency</b> controls the frequency (and therefore
	the width) of any secondary waves that ride on top of the
	primary waves (white caps, for example).
	*/
	void setSubWaveFrequency(const FloatID& swf){fprintf_s(mFile,"connectAttr \"");swf.write(mFile);fprintf_s(mFile,"\" \"%s.swf\";\n",mName.c_str());}
	/*
	<b>Smoothness</b> controls the intensity of any
	secondary waves present.  Increase smoothness to make
	the secondary waves less pronounced.
	*/
	void setSmoothness(float s){if(s == 2.0) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*
	<b>Smoothness</b> controls the intensity of any
	secondary waves present.  Increase smoothness to make
	the secondary waves less pronounced.
	*/
	void setSmoothness(const FloatID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	<b>Wind UV</b> controls the (average) direction that
	the linear waves will travel, simulating the effect
	of wind.  This is expressed as U and V values, in the
	UV texture space.
	*/
	void setWindUV(const float2& wi){if(wi == float2(1.0, 0.0)) return; fprintf_s(mFile, "setAttr \".wi\" -type \"float2\" ");wi.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Wind UV</b> controls the (average) direction that
	the linear waves will travel, simulating the effect
	of wind.  This is expressed as U and V values, in the
	UV texture space.
	*/
	void setWindUV(const Float2ID& wi){fprintf_s(mFile,"connectAttr \"");wi.write(mFile);fprintf_s(mFile,"\" \"%s.wi\";\n",mName.c_str());}
	/*The U component of the wind direction*/
	void setWindU(float wiu){if(wiu == 0.0) return; fprintf_s(mFile, "setAttr \".wi.wiu\" %f;\n", wiu);}
	/*The U component of the wind direction*/
	void setWindU(const FloatID& wiu){fprintf_s(mFile,"connectAttr \"");wiu.write(mFile);fprintf_s(mFile,"\" \"%s.wi.wiu\";\n",mName.c_str());}
	/*The V component of the wind direction*/
	void setWindV(float wiv){if(wiv == 0.0) return; fprintf_s(mFile, "setAttr \".wi.wiv\" %f;\n", wiv);}
	/*The V component of the wind direction*/
	void setWindV(const FloatID& wiv){fprintf_s(mFile,"connectAttr \"");wiv.write(mFile);fprintf_s(mFile,"\" \"%s.wi.wiv\";\n",mName.c_str());}
	/*
	<b>Ripple Time</b> controls the motion of the ripples. Set
	keyframes on this attribute in order to animate the motion
	of the ripples.  The faster this changes, the faster
	the waves will go.
	<p/>If you do not want to see any ripples, set Ripple Time
	to 0 and do not animate it.
	<p/>When Ripple Time is 0, there are no ripples; the
	droplet has not yet touched the surface of the water.
	As Ripple Time increases, the ripples begin at a point and
	spread outwards.
	*/
	void setRippleTime(float rt){if(rt == 0.0) return; fprintf_s(mFile, "setAttr \".rt\" %f;\n", rt);}
	/*
	<b>Ripple Time</b> controls the motion of the ripples. Set
	keyframes on this attribute in order to animate the motion
	of the ripples.  The faster this changes, the faster
	the waves will go.
	<p/>If you do not want to see any ripples, set Ripple Time
	to 0 and do not animate it.
	<p/>When Ripple Time is 0, there are no ripples; the
	droplet has not yet touched the surface of the water.
	As Ripple Time increases, the ripples begin at a point and
	spread outwards.
	*/
	void setRippleTime(const FloatID& rt){fprintf_s(mFile,"connectAttr \"");rt.write(mFile);fprintf_s(mFile,"\" \"%s.rt\";\n",mName.c_str());}
	/*
	<b>Ripple Frequency</b> controls the frequency at which
	ripples are created, and therefore their width.  As
	the frequency increases, the ripples become narrower and
	closer together.  Their height is not affected
	*/
	void setRippleFrequency(float rf){if(rf == 25.0) return; fprintf_s(mFile, "setAttr \".rf\" %f;\n", rf);}
	/*
	<b>Ripple Frequency</b> controls the frequency at which
	ripples are created, and therefore their width.  As
	the frequency increases, the ripples become narrower and
	closer together.  Their height is not affected
	*/
	void setRippleFrequency(const FloatID& rf){fprintf_s(mFile,"connectAttr \"");rf.write(mFile);fprintf_s(mFile,"\" \"%s.rf\";\n",mName.c_str());}
	/*
	<b>Ripple Amplitude</b> controls the height of the ripples.
	Increase this to make the ripples bigger, as though a
	heavier object had created them.
	*/
	void setRippleAmplitude(float ra){if(ra == 0.05) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	<b>Ripple Amplitude</b> controls the height of the ripples.
	Increase this to make the ripples bigger, as though a
	heavier object had created them.
	*/
	void setRippleAmplitude(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*
	<b>Drop Size</b> controls the size of the drop that
	starts the ripple wave effect
	*/
	void setDropSize(float ds){if(ds == 0.3) return; fprintf_s(mFile, "setAttr \".ds\" %f;\n", ds);}
	/*
	<b>Drop Size</b> controls the size of the drop that
	starts the ripple wave effect
	*/
	void setDropSize(const FloatID& ds){fprintf_s(mFile,"connectAttr \"");ds.write(mFile);fprintf_s(mFile,"\" \"%s.ds\";\n",mName.c_str());}
	/*
	<b>Ripple Origin</b> controls the location where the
	the ripples start.  This is in UV Texture space.
	*/
	void setRippleOrigin(const float2& rc){if(rc == float2(0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".rc\" -type \"float2\" ");rc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Ripple Origin</b> controls the location where the
	the ripples start.  This is in UV Texture space.
	*/
	void setRippleOrigin(const Float2ID& rc){fprintf_s(mFile,"connectAttr \"");rc.write(mFile);fprintf_s(mFile,"\" \"%s.rc\";\n",mName.c_str());}
	/*The U component of the ripple origin position*/
	void setRippleOriginU(float rcu){if(rcu == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rcu\" %f;\n", rcu);}
	/*The U component of the ripple origin position*/
	void setRippleOriginU(const FloatID& rcu){fprintf_s(mFile,"connectAttr \"");rcu.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rcu\";\n",mName.c_str());}
	/*The V component of the ripple origin position*/
	void setRippleOriginV(float rcv){if(rcv == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rcv\" %f;\n", rcv);}
	/*The V component of the ripple origin position*/
	void setRippleOriginV(const FloatID& rcv){fprintf_s(mFile,"connectAttr \"");rcv.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rcv\";\n",mName.c_str());}
	/*
	<b>Group Velocity</b> controls the size and speed of the
	primary ripple.  Increase this to make the ripple move
	faster.
	*/
	void setGroupVelocity(float gv){if(gv == 1.0) return; fprintf_s(mFile, "setAttr \".gv\" %f;\n", gv);}
	/*
	<b>Group Velocity</b> controls the size and speed of the
	primary ripple.  Increase this to make the ripple move
	faster.
	*/
	void setGroupVelocity(const FloatID& gv){fprintf_s(mFile,"connectAttr \"");gv.write(mFile);fprintf_s(mFile,"\" \"%s.gv\";\n",mName.c_str());}
	/*
	<b>Phase Velocity</b> controls the size and speed of
	the sub-wavelets.  Increase this to make them move
	faster.
	*/
	void setPhaseVelocity(float pv){if(pv == 2.5) return; fprintf_s(mFile, "setAttr \".pv\" %f;\n", pv);}
	/*
	<b>Phase Velocity</b> controls the size and speed of
	the sub-wavelets.  Increase this to make them move
	faster.
	*/
	void setPhaseVelocity(const FloatID& pv){fprintf_s(mFile,"connectAttr \"");pv.write(mFile);fprintf_s(mFile,"\" \"%s.pv\";\n",mName.c_str());}
	/*
	<b>Spread Start</b> controls the size of the initial
	impact of the drop at time zero.  Increase Spread Start
	to make the size of the initial disturbance increase.
	*/
	void setSpreadStart(float ss){if(ss == 0.005) return; fprintf_s(mFile, "setAttr \".ss\" %f;\n", ss);}
	/*
	<b>Spread Start</b> controls the size of the initial
	impact of the drop at time zero.  Increase Spread Start
	to make the size of the initial disturbance increase.
	*/
	void setSpreadStart(const FloatID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*
	<b>Spread Rate</b> controls the speed at which an
	outward-expanding ripple breaks up into sub-wavelets.
	Increase this to make the ripples break up more quickly.
	*/
	void setSpreadRate(float sr){if(sr == 0.3) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*
	<b>Spread Rate</b> controls the speed at which an
	outward-expanding ripple breaks up into sub-wavelets.
	Increase this to make the ripples break up more quickly.
	*/
	void setSpreadRate(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	<b>Reflection Box</b>.  Turn on this attribute to create
	the effect of ripples hitting the edges of a box and being
	reflected back.  This can create some wonderful natural-looking
	interference patterns in the ripples.  The box is defined
	as upper and lower limits in
	UV texture space.
	<p/>
	Note: When Reflection Box is turned on, calculating the
	water shader slows down significantly.
	*/
	void setReflectionBox(bool rb){if(rb == false) return; fprintf_s(mFile, "setAttr \".rb\" %i;\n", rb);}
	/*
	<b>Reflection Box</b>.  Turn on this attribute to create
	the effect of ripples hitting the edges of a box and being
	reflected back.  This can create some wonderful natural-looking
	interference patterns in the ripples.  The box is defined
	as upper and lower limits in
	UV texture space.
	<p/>
	Note: When Reflection Box is turned on, calculating the
	water shader slows down significantly.
	*/
	void setReflectionBox(const BoolID& rb){fprintf_s(mFile,"connectAttr \"");rb.write(mFile);fprintf_s(mFile,"\" \"%s.rb\";\n",mName.c_str());}
	/*
	<b>Box Min</b> is UV position of the lower left corner
	of the reflection bounding box.
	<p/>This attribute is only used if Reflection Box is turned on.
	*/
	void setBoxMin(const float2& bmn){if(bmn == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".bmn\" -type \"float2\" ");bmn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Box Min</b> is UV position of the lower left corner
	of the reflection bounding box.
	<p/>This attribute is only used if Reflection Box is turned on.
	*/
	void setBoxMin(const Float2ID& bmn){fprintf_s(mFile,"connectAttr \"");bmn.write(mFile);fprintf_s(mFile,"\" \"%s.bmn\";\n",mName.c_str());}
	/*The lower U value*/
	void setBoxMinU(float bu1){if(bu1 == 0.0) return; fprintf_s(mFile, "setAttr \".bmn.bu1\" %f;\n", bu1);}
	/*The lower U value*/
	void setBoxMinU(const FloatID& bu1){fprintf_s(mFile,"connectAttr \"");bu1.write(mFile);fprintf_s(mFile,"\" \"%s.bmn.bu1\";\n",mName.c_str());}
	/*The lower V value*/
	void setBoxMinV(float bv1){if(bv1 == 0.0) return; fprintf_s(mFile, "setAttr \".bmn.bv1\" %f;\n", bv1);}
	/*The lower V value*/
	void setBoxMinV(const FloatID& bv1){fprintf_s(mFile,"connectAttr \"");bv1.write(mFile);fprintf_s(mFile,"\" \"%s.bmn.bv1\";\n",mName.c_str());}
	/*
	<b>Box Max</b> is the UV position of the upper right corner
	of the reflection bounding box.
	<p/>This attribute is only used if Reflection Box is turned on.
	*/
	void setBoxMax(const float2& bmx){if(bmx == float2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".bmx\" -type \"float2\" ");bmx.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Box Max</b> is the UV position of the upper right corner
	of the reflection bounding box.
	<p/>This attribute is only used if Reflection Box is turned on.
	*/
	void setBoxMax(const Float2ID& bmx){fprintf_s(mFile,"connectAttr \"");bmx.write(mFile);fprintf_s(mFile,"\" \"%s.bmx\";\n",mName.c_str());}
	/*The upper U value*/
	void setBoxMaxU(float bu2){if(bu2 == 0.0) return; fprintf_s(mFile, "setAttr \".bmx.bu2\" %f;\n", bu2);}
	/*The upper U value*/
	void setBoxMaxU(const FloatID& bu2){fprintf_s(mFile,"connectAttr \"");bu2.write(mFile);fprintf_s(mFile,"\" \"%s.bmx.bu2\";\n",mName.c_str());}
	/*The upper V value*/
	void setBoxMaxV(float bv2){if(bv2 == 0.0) return; fprintf_s(mFile, "setAttr \".bmx.bv2\" %f;\n", bv2);}
	/*The upper V value*/
	void setBoxMaxV(const FloatID& bv2){fprintf_s(mFile,"connectAttr \"");bv2.write(mFile);fprintf_s(mFile,"\" \"%s.bmx.bv2\";\n",mName.c_str());}
	/*
	<b>Fast</b> is an optimization in the Water texture.  When it
	is turned on, the color tables are computed once
	per frame.  When it is off, the color tables are computed
	for every sample.
	<p/>
	The only time you might turn this off is if the water
	will be seen very close up in the final scene.
	*/
	void setFast(bool fa){if(fa == true) return; fprintf_s(mFile, "setAttr \".fa\" %i;\n", fa);}
	/*
	<b>Fast</b> is an optimization in the Water texture.  When it
	is turned on, the color tables are computed once
	per frame.  When it is off, the color tables are computed
	for every sample.
	<p/>
	The only time you might turn this off is if the water
	will be seen very close up in the final scene.
	*/
	void setFast(const BoolID& fa){fprintf_s(mFile,"connectAttr \"");fa.write(mFile);fprintf_s(mFile,"\" \"%s.fa\";\n",mName.c_str());}
	/*
	<b>Number of Waves</b> controls how many linear waves are
	generated, when this texture is animated.  (See
	the Wave Time attribute below).
	<p/>
	If you want this texture to show only concentric ripples,
	set Number of Waves to 0.  If you want to combine linear waves
	and ripples, try values between 1 and 3.
	*/
	ShortID getNumberOfWaves(){char buffer[4096];sprintf_s (buffer, "%s.nw",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wave Time</b> controls the motion of the waves.  Set
	keyframes on this attribute in order to animate the motion
	of the linear waves.  The faster this changes, the faster
	the waves will go.
	*/
	FloatID getWaveTime(){char buffer[4096];sprintf_s (buffer, "%s.wt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wave Velocity</b> controls the speed of the linear waves,
	if you have animated them using the Wave Time attribute above.
	<p/>
	This attribute is effectively just a multiplier on Wave Time.
	*/
	FloatID getWaveVelocity(){char buffer[4096];sprintf_s (buffer, "%s.wv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wave Amplitude</b> controls the height of the waves.
	Increase this to make the waves higher.
	*/
	FloatID getWaveAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.wa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wave Frequency</b> controls the frequency of the waves,
	and therefore their width.  As you increase Wave Frequency,
	the waves get narrower and closer together.  Their height does
	not change.
	*/
	FloatID getWaveFrequency(){char buffer[4096];sprintf_s (buffer, "%s.wf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sub Wave Frequency</b> controls the frequency (and therefore
	the width) of any secondary waves that ride on top of the
	primary waves (white caps, for example).
	*/
	FloatID getSubWaveFrequency(){char buffer[4096];sprintf_s (buffer, "%s.swf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Smoothness</b> controls the intensity of any
	secondary waves present.  Increase smoothness to make
	the secondary waves less pronounced.
	*/
	FloatID getSmoothness(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	<b>Wind UV</b> controls the (average) direction that
	the linear waves will travel, simulating the effect
	of wind.  This is expressed as U and V values, in the
	UV texture space.
	*/
	Float2ID getWindUV(){char buffer[4096];sprintf_s (buffer, "%s.wi",mName.c_str());return (const char*)buffer;}
	/*The U component of the wind direction*/
	FloatID getWindU(){char buffer[4096];sprintf_s (buffer, "%s.wi.wiu",mName.c_str());return (const char*)buffer;}
	/*The V component of the wind direction*/
	FloatID getWindV(){char buffer[4096];sprintf_s (buffer, "%s.wi.wiv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ripple Time</b> controls the motion of the ripples. Set
	keyframes on this attribute in order to animate the motion
	of the ripples.  The faster this changes, the faster
	the waves will go.
	<p/>If you do not want to see any ripples, set Ripple Time
	to 0 and do not animate it.
	<p/>When Ripple Time is 0, there are no ripples; the
	droplet has not yet touched the surface of the water.
	As Ripple Time increases, the ripples begin at a point and
	spread outwards.
	*/
	FloatID getRippleTime(){char buffer[4096];sprintf_s (buffer, "%s.rt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ripple Frequency</b> controls the frequency at which
	ripples are created, and therefore their width.  As
	the frequency increases, the ripples become narrower and
	closer together.  Their height is not affected
	*/
	FloatID getRippleFrequency(){char buffer[4096];sprintf_s (buffer, "%s.rf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ripple Amplitude</b> controls the height of the ripples.
	Increase this to make the ripples bigger, as though a
	heavier object had created them.
	*/
	FloatID getRippleAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*
	<b>Drop Size</b> controls the size of the drop that
	starts the ripple wave effect
	*/
	FloatID getDropSize(){char buffer[4096];sprintf_s (buffer, "%s.ds",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ripple Origin</b> controls the location where the
	the ripples start.  This is in UV Texture space.
	*/
	Float2ID getRippleOrigin(){char buffer[4096];sprintf_s (buffer, "%s.rc",mName.c_str());return (const char*)buffer;}
	/*The U component of the ripple origin position*/
	FloatID getRippleOriginU(){char buffer[4096];sprintf_s (buffer, "%s.rc.rcu",mName.c_str());return (const char*)buffer;}
	/*The V component of the ripple origin position*/
	FloatID getRippleOriginV(){char buffer[4096];sprintf_s (buffer, "%s.rc.rcv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Group Velocity</b> controls the size and speed of the
	primary ripple.  Increase this to make the ripple move
	faster.
	*/
	FloatID getGroupVelocity(){char buffer[4096];sprintf_s (buffer, "%s.gv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Phase Velocity</b> controls the size and speed of
	the sub-wavelets.  Increase this to make them move
	faster.
	*/
	FloatID getPhaseVelocity(){char buffer[4096];sprintf_s (buffer, "%s.pv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Spread Start</b> controls the size of the initial
	impact of the drop at time zero.  Increase Spread Start
	to make the size of the initial disturbance increase.
	*/
	FloatID getSpreadStart(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*
	<b>Spread Rate</b> controls the speed at which an
	outward-expanding ripple breaks up into sub-wavelets.
	Increase this to make the ripples break up more quickly.
	*/
	FloatID getSpreadRate(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Reflection Box</b>.  Turn on this attribute to create
	the effect of ripples hitting the edges of a box and being
	reflected back.  This can create some wonderful natural-looking
	interference patterns in the ripples.  The box is defined
	as upper and lower limits in
	UV texture space.
	<p/>
	Note: When Reflection Box is turned on, calculating the
	water shader slows down significantly.
	*/
	BoolID getReflectionBox(){char buffer[4096];sprintf_s (buffer, "%s.rb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Box Min</b> is UV position of the lower left corner
	of the reflection bounding box.
	<p/>This attribute is only used if Reflection Box is turned on.
	*/
	Float2ID getBoxMin(){char buffer[4096];sprintf_s (buffer, "%s.bmn",mName.c_str());return (const char*)buffer;}
	/*The lower U value*/
	FloatID getBoxMinU(){char buffer[4096];sprintf_s (buffer, "%s.bmn.bu1",mName.c_str());return (const char*)buffer;}
	/*The lower V value*/
	FloatID getBoxMinV(){char buffer[4096];sprintf_s (buffer, "%s.bmn.bv1",mName.c_str());return (const char*)buffer;}
	/*
	<b>Box Max</b> is the UV position of the upper right corner
	of the reflection bounding box.
	<p/>This attribute is only used if Reflection Box is turned on.
	*/
	Float2ID getBoxMax(){char buffer[4096];sprintf_s (buffer, "%s.bmx",mName.c_str());return (const char*)buffer;}
	/*The upper U value*/
	FloatID getBoxMaxU(){char buffer[4096];sprintf_s (buffer, "%s.bmx.bu2",mName.c_str());return (const char*)buffer;}
	/*The upper V value*/
	FloatID getBoxMaxV(){char buffer[4096];sprintf_s (buffer, "%s.bmx.bv2",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fast</b> is an optimization in the Water texture.  When it
	is turned on, the color tables are computed once
	per frame.  When it is off, the color tables are computed
	for every sample.
	<p/>
	The only time you might turn this off is if the water
	will be seen very close up in the final scene.
	*/
	BoolID getFast(){char buffer[4096];sprintf_s (buffer, "%s.fa",mName.c_str());return (const char*)buffer;}
protected:
	Water(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_WATER_H__
