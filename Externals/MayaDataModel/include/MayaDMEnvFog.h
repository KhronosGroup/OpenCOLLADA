/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVFOG_H__
#define __MayaDM_ENVFOG_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLightFog.h"
namespace MayaDM
{
/*
<b>Env Fog</b> is a volume object that fills the whole scene,
 from the near to the far clipping planes.  Env Fog is normally
 semi-transparent, and tends to hide other objects.  You can adjust
 its attributes to change fog saturation, color, and how much of the
 scene it fills.
 <p/>
 There are two different fog simulations supported by this node.
 <b>Simple Fog</b> is the default, and uses a small number of
 attributes to make a simple representation of fog.
 <p/>
 If you turn on the <b>Physical Fog</b> attribute, then EnvFog
 switches to using a more sophisticated, physically-based model
 to simulate fog.  This model is more complex to use, but the results
 can be much better.  You can use Physical Fog to simulate complete
 atmospheric environments, and you can even use it for underwater scenes.
 <p/>
 Physical Fog works by simulating three things:  the air (which has
 its attributes for its light-scattering, density, transparency, etc),
 the water vapour (fog) in the air (which has its own attributes for
 the same things),
 and optionally, a body of water which has its own light scattering
 and other attributes.  The combination of these effects creates
 a realistic fog.
 <p/>
 Aside from the attributes described here, the Env Fog node inherits
 some of the attributes of its parent
 <a href="lightFog.html">Light Fog</a> node.
<p/>
 In the table below, important attribtues have their names indicated
 in <b>bold</b> in the description column.
*/
class EnvFog : public LightFog
{
public:
public:
	EnvFog(FILE* file,const std::string& name,const std::string& parent=""):LightFog(file, name, parent, "envFog"){}
	virtual ~EnvFog(){}
	/*The transform to go from eye to world space*/
	void setMatrixEyeToWorld(const FltMatrixID& e2w){fprintf_s(mFile,"connectAttr \"");e2w.write(mFile);fprintf_s(mFile,"\" \"%s.e2w\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	void setPointCamera(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	void setPointWorld(const Float3ID& pw){fprintf_s(mFile,"connectAttr \"");pw.write(mFile);fprintf_s(mFile,"\" \"%s.pw\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointWorldX(const FloatID& pwx){fprintf_s(mFile,"connectAttr \"");pwx.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointWorldY(const FloatID& pwy){fprintf_s(mFile,"connectAttr \"");pwy.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointWorldZ(const FloatID& pwz){fprintf_s(mFile,"connectAttr \"");pwz.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwz\";\n",mName.c_str());}
	/*The current incident ray*/
	void setRayDirection(const Float3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The x component of the ray*/
	void setRayDirectionX(const FloatID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*The y component of the ray*/
	void setRayDirectionY(const FloatID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*The z component of the ray*/
	void setRayDirectionZ(const FloatID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*
	<b>Distance Clip Planes</b> specifies which set of
	clipping planes define where there is fog.
	<b>envFog</b>  can either be limited by the camera near
	and far clipping plane, or by the <b>Fog Near and Far Distance</b>.
	*/
	void setDistanceClipPlanes(unsigned int dcp){if(dcp == 1) return; fprintf_s(mFile, "setAttr \".dcp\" %i;\n", dcp);}
	/*
	When <b>Use Layer</b> is turned on, the density of the
	fog will be multiplied by the value of the Layer parameter.
	Layer can be use to alter the degree of saturation of
	the fog. By connecting the output of a 3d Texture to the Layer
	parameter, you can create texture in the fog.  If Use Layer
	is turned off, the Layer parameter will be ignored.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	void setUseLayer(bool ul){if(ul == false) return; fprintf_s(mFile, "setAttr \".ul\" %i;\n", ul);}
	/*
	When <b>Use Layer</b> is turned on, the density of the
	fog will be multiplied by the value of the Layer parameter.
	Layer can be use to alter the degree of saturation of
	the fog. By connecting the output of a 3d Texture to the Layer
	parameter, you can create texture in the fog.  If Use Layer
	is turned off, the Layer parameter will be ignored.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	void setUseLayer(const BoolID& ul){fprintf_s(mFile,"connectAttr \"");ul.write(mFile);fprintf_s(mFile,"\" \"%s.ul\";\n",mName.c_str());}
	/*
	When <b>Use Height</b> is turned on, the fog will not
	fill the whole scene from top to bottom.  Instead, it
	will use the Min Height and Max Height attributes to
	determine where the fog begins and ends.  These heights
	are measured in world space.  When Use Height is turned
	off, the fog will fill the entire scene vertically.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	void setUseHeight(bool uh){if(uh == false) return; fprintf_s(mFile, "setAttr \".uh\" %i;\n", uh);}
	/*
	When <b>Use Height</b> is turned on, the fog will not
	fill the whole scene from top to bottom.  Instead, it
	will use the Min Height and Max Height attributes to
	determine where the fog begins and ends.  These heights
	are measured in world space.  When Use Height is turned
	off, the fog will fill the entire scene vertically.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	void setUseHeight(const BoolID& uh){fprintf_s(mFile,"connectAttr \"");uh.write(mFile);fprintf_s(mFile,"\" \"%s.uh\";\n",mName.c_str());}
	/*
	The distance/height at which blending starts
	<p/>This attribute only applies when Physical Fog is
	turned off.
	*/
	void setBlendRange(float br){if(br == 1.0) return; fprintf_s(mFile, "setAttr \".br\" %f;\n", br);}
	/*
	The distance/height at which blending starts
	<p/>This attribute only applies when Physical Fog is
	turned off.
	*/
	void setBlendRange(const FloatID& br){fprintf_s(mFile,"connectAttr \"");br.write(mFile);fprintf_s(mFile,"\" \"%s.br\";\n",mName.c_str());}
	/*
	<b>Saturation Distance</b> specifies the distance in
	camera space where the fog saturates (that is where the fog becames
	completely opaque).
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	void setSaturationDistance(float sdt){if(sdt == 100.0) return; fprintf_s(mFile, "setAttr \".sdt\" %f;\n", sdt);}
	/*
	<b>Saturation Distance</b> specifies the distance in
	camera space where the fog saturates (that is where the fog becames
	completely opaque).
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	void setSaturationDistance(const FloatID& sdt){fprintf_s(mFile,"connectAttr \"");sdt.write(mFile);fprintf_s(mFile,"\" \"%s.sdt\";\n",mName.c_str());}
	/*
	<b>Fog Near Distance</b> is the distance in front of the
	camera where the fog should begin. This distance is defined
	in camera space.
	<p/>This attribute only applies when <b>Distance Clip Planes</b> is
	set to Fog Near/Far.
	*/
	void setFogNearDistance(float fnd){if(fnd == 0.0) return; fprintf_s(mFile, "setAttr \".fnd\" %f;\n", fnd);}
	/*
	<b>Fog Near Distance</b> is the distance in front of the
	camera where the fog should begin. This distance is defined
	in camera space.
	<p/>This attribute only applies when <b>Distance Clip Planes</b> is
	set to Fog Near/Far.
	*/
	void setFogNearDistance(const FloatID& fnd){fprintf_s(mFile,"connectAttr \"");fnd.write(mFile);fprintf_s(mFile,"\" \"%s.fnd\";\n",mName.c_str());}
	/*
	<b>Fog Far Distance</b> is the distance in front of the camera
	where the fog should end.
	If you set this value to be less than Fog Near Distance,
	then the fog will start at Fog Near Distance, but extend
	out to the camera far clipping plane.
	This distance is defined in camera space.
	<p/>This attribute only applies when <b>Distance Clip Planes</b> is
	set to Fog Near/Far.
	*/
	void setFogFarDistance(float ffd){if(ffd == 200.0) return; fprintf_s(mFile, "setAttr \".ffd\" %f;\n", ffd);}
	/*
	<b>Fog Far Distance</b> is the distance in front of the camera
	where the fog should end.
	If you set this value to be less than Fog Near Distance,
	then the fog will start at Fog Near Distance, but extend
	out to the camera far clipping plane.
	This distance is defined in camera space.
	<p/>This attribute only applies when <b>Distance Clip Planes</b> is
	set to Fog Near/Far.
	*/
	void setFogFarDistance(const FloatID& ffd){fprintf_s(mFile,"connectAttr \"");ffd.write(mFile);fprintf_s(mFile,"\" \"%s.ffd\";\n",mName.c_str());}
	/*
	The <b>Layer</b> attribute is used as a multiplier to the
	fog's density.  This attribute is ignored unless Use Layer is turned on.
	<p/>Connect a 3d texture to this attribute to give some
	texture to your fog or use it to decrease the amount of fog saturation.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	void setLayer(float l){if(l == 1.0) return; fprintf_s(mFile, "setAttr \".l\" %f;\n", l);}
	/*
	The <b>Layer</b> attribute is used as a multiplier to the
	fog's density.  This attribute is ignored unless Use Layer is turned on.
	<p/>Connect a 3d texture to this attribute to give some
	texture to your fog or use it to decrease the amount of fog saturation.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	void setLayer(const FloatID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*
	<b>Min Height</b> is the height above which the fog starts.
	This attribute is ignored unless Use Height is turned on.
	Otherwise, fog fills the entire scene vertically.
	The height is defined in world space.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off and <b>Use Height</b> is turned on.
	*/
	void setMinHeight(float mnh){if(mnh == -1.0) return; fprintf_s(mFile, "setAttr \".mnh\" %f;\n", mnh);}
	/*
	<b>Min Height</b> is the height above which the fog starts.
	This attribute is ignored unless Use Height is turned on.
	Otherwise, fog fills the entire scene vertically.
	The height is defined in world space.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off and <b>Use Height</b> is turned on.
	*/
	void setMinHeight(const FloatID& mnh){fprintf_s(mFile,"connectAttr \"");mnh.write(mFile);fprintf_s(mFile,"\" \"%s.mnh\";\n",mName.c_str());}
	/*
	<b>Max Height</b> is the height where the fog ends;  above
	this height there is no fog..
	This attribute is ignored unless Use Height is turned on.
	Otherwise, fog fills the entire scene vertically.
	The height is defined in world space.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off and <b>Use Height</b> is turned on.
	*/
	void setMaxHeight(float mxh){if(mxh == 1.0) return; fprintf_s(mFile, "setAttr \".mxh\" %f;\n", mxh);}
	/*
	<b>Max Height</b> is the height where the fog ends;  above
	this height there is no fog..
	This attribute is ignored unless Use Height is turned on.
	Otherwise, fog fills the entire scene vertically.
	The height is defined in world space.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off and <b>Use Height</b> is turned on.
	*/
	void setMaxHeight(const FloatID& mxh){fprintf_s(mFile,"connectAttr \"");mxh.write(mFile);fprintf_s(mFile,"\" \"%s.mxh\";\n",mName.c_str());}
	/*Obsolete attribute.*/
	void setUseDistance(bool ud){if(ud == false) return; fprintf_s(mFile, "setAttr \".ud\" %i;\n", ud);}
	/*Obsolete attribute.*/
	void setUseDistance(const BoolID& ud){fprintf_s(mFile,"connectAttr \"");ud.write(mFile);fprintf_s(mFile,"\" \"%s.ud\";\n",mName.c_str());}
	/*Obsolete attribute.*/
	void setStartDistance(float sd){if(sd == 0.0) return; fprintf_s(mFile, "setAttr \".sd\" %f;\n", sd);}
	/*Obsolete attribute.*/
	void setStartDistance(const FloatID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd\";\n",mName.c_str());}
	/*Obsolete attribute.*/
	void setEndDistance(float ed){if(ed == -1.0) return; fprintf_s(mFile, "setAttr \".ed\" %f;\n", ed);}
	/*Obsolete attribute.*/
	void setEndDistance(const FloatID& ed){fprintf_s(mFile,"connectAttr \"");ed.write(mFile);fprintf_s(mFile,"\" \"%s.ed\";\n",mName.c_str());}
	/*
	<b>Physical Fog</b>.  If this is turned off, Env Fog
	uses a simple fog model with just a few attributes specified.
	When Physical Fog is turned on, a more sophisticated
	physically-based model is used to simulate fog.  A different
	set of attributes is used for this model.
	*/
	void setPhysicalFog(bool sff){if(sff == false) return; fprintf_s(mFile, "setAttr \".sff\" %i;\n", sff);}
	/*
	<b>Physical Fog</b>.  If this is turned off, Env Fog
	uses a simple fog model with just a few attributes specified.
	When Physical Fog is turned on, a more sophisticated
	physically-based model is used to simulate fog.  A different
	set of attributes is used for this model.
	*/
	void setPhysicalFog(const BoolID& sff){fprintf_s(mFile,"connectAttr \"");sff.write(mFile);fprintf_s(mFile,"\" \"%s.sff\";\n",mName.c_str());}
	/*
	<b>Fog Type</b> controls how the fog will be simulated in
	your scene.  It has a number of different settings, depending
	on what kind of fog effect you want.  This attribute is only
	available when <b>Physical Fog</b> is turned on.  The settings are:
	<ul><b>Uniform Fog</b>: The fog has uniform density in all directions.
	<p/><b>Atmospheric</b>: The fog is thickest near the ground, and
	thins out (decays) as you move upwards.
	<p/><b>Sky</b>: This simulates the effect of a whole sky, with fog
	blending properly at the horizon, etc.  Use this to provide a complete
	background to a foggy scene. It is especially useful for scenes where
	you can see a Tint32 distance, <i>e.g.</i> to the horizon.
	<p/><b>Water</b>: This simulates the effect of water, scattering light
	that is shining in from above it.  This is useful for underwater
	shots, or for shots where objects are visible in a pool of water
	from above.
	<p/><b>Water/Fog</b>: Allows you to have water in your scene, with
	Uniform Fog above the water.
	<p/><b>Water/Atmos</b>: Allows you to have water in your scene, with
	Atmospheric Fog above the water.
	<p/><b>Water/Sky</b>: Allows you to have water in your scene, with
	the full Sky Fog simulation above it.
	</ul>
	*/
	void setFogType(unsigned int ftp){if(ftp == 0) return; fprintf_s(mFile, "setAttr \".ftp\" %i;\n", ftp);}
	/*
	<b>Fog Type</b> controls how the fog will be simulated in
	your scene.  It has a number of different settings, depending
	on what kind of fog effect you want.  This attribute is only
	available when <b>Physical Fog</b> is turned on.  The settings are:
	<ul><b>Uniform Fog</b>: The fog has uniform density in all directions.
	<p/><b>Atmospheric</b>: The fog is thickest near the ground, and
	thins out (decays) as you move upwards.
	<p/><b>Sky</b>: This simulates the effect of a whole sky, with fog
	blending properly at the horizon, etc.  Use this to provide a complete
	background to a foggy scene. It is especially useful for scenes where
	you can see a Tint32 distance, <i>e.g.</i> to the horizon.
	<p/><b>Water</b>: This simulates the effect of water, scattering light
	that is shining in from above it.  This is useful for underwater
	shots, or for shots where objects are visible in a pool of water
	from above.
	<p/><b>Water/Fog</b>: Allows you to have water in your scene, with
	Uniform Fog above the water.
	<p/><b>Water/Atmos</b>: Allows you to have water in your scene, with
	Atmospheric Fog above the water.
	<p/><b>Water/Sky</b>: Allows you to have water in your scene, with
	the full Sky Fog simulation above it.
	</ul>
	*/
	void setFogType(const UnsignedintID& ftp){fprintf_s(mFile,"connectAttr \"");ftp.write(mFile);fprintf_s(mFile,"\" \"%s.ftp\";\n",mName.c_str());}
	/*
	<b>Fog Density</b> controls the optical density of
	vapour in the fog layer.  Increase this value to
	make the fog seem "thicker".
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setFogDensity(double fdn){if(fdn == 0.4) return; fprintf_s(mFile, "setAttr \".fdn\" %f;\n", fdn);}
	/*
	<b>Fog Density</b> controls the optical density of
	vapour in the fog layer.  Increase this value to
	make the fog seem "thicker".
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setFogDensity(const DoubleID& fdn){fprintf_s(mFile,"connectAttr \"");fdn.write(mFile);fprintf_s(mFile,"\" \"%s.fdn\";\n",mName.c_str());}
	/*
	<b>Fog Color</b> controls the color of light that
	is scattered by the fog.  When light passes through
	a medium such as air or fog, some frequencies (colors)
	pass directly through, while other frequencies are
	scattered.  The frequencies that are scattered
	give the fog its distinctive color.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setFogColor(const float3& fcl){fprintf_s(mFile, "setAttr \".fcl\" -type \"float3\" ");fcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Fog Color</b> controls the color of light that
	is scattered by the fog.  When light passes through
	a medium such as air or fog, some frequencies (colors)
	pass directly through, while other frequencies are
	scattered.  The frequencies that are scattered
	give the fog its distinctive color.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setFogColor(const Float3ID& fcl){fprintf_s(mFile,"connectAttr \"");fcl.write(mFile);fprintf_s(mFile,"\" \"%s.fcl\";\n",mName.c_str());}
	/*Fog Color Red value*/
	void setFogColorR(float fcr){if(fcr == 1.0) return; fprintf_s(mFile, "setAttr \".fcl.fcr\" %f;\n", fcr);}
	/*Fog Color Red value*/
	void setFogColorR(const FloatID& fcr){fprintf_s(mFile,"connectAttr \"");fcr.write(mFile);fprintf_s(mFile,"\" \"%s.fcl.fcr\";\n",mName.c_str());}
	/*Fog Color Green value*/
	void setFogColorG(float fcg){if(fcg == 1.0) return; fprintf_s(mFile, "setAttr \".fcl.fcg\" %f;\n", fcg);}
	/*Fog Color Green value*/
	void setFogColorG(const FloatID& fcg){fprintf_s(mFile,"connectAttr \"");fcg.write(mFile);fprintf_s(mFile,"\" \"%s.fcl.fcg\";\n",mName.c_str());}
	/*Fog Color Blue value*/
	void setFogColorB(float fcb){if(fcb == 1.0) return; fprintf_s(mFile, "setAttr \".fcl.fcb\" %f;\n", fcb);}
	/*Fog Color Blue value*/
	void setFogColorB(const FloatID& fcb){fprintf_s(mFile,"connectAttr \"");fcb.write(mFile);fprintf_s(mFile,"\" \"%s.fcl.fcb\";\n",mName.c_str());}
	/*
	<b>Fog Opacity</b> controls what frequencies
	(colors) of light are absorbed as they pass through
	the fog. This will affect the way that objects
	in the background appear to be "tinted" by the fog.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setFogOpacity(const float3& fop){fprintf_s(mFile, "setAttr \".fop\" -type \"float3\" ");fop.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Fog Opacity</b> controls what frequencies
	(colors) of light are absorbed as they pass through
	the fog. This will affect the way that objects
	in the background appear to be "tinted" by the fog.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setFogOpacity(const Float3ID& fop){fprintf_s(mFile,"connectAttr \"");fop.write(mFile);fprintf_s(mFile,"\" \"%s.fop\";\n",mName.c_str());}
	/*Fog Opacity Red value*/
	void setFogOpacityR(float for_){if(for_ == 0.5) return; fprintf_s(mFile, "setAttr \".fop.for\" %f;\n", for_);}
	/*Fog Opacity Red value*/
	void setFogOpacityR(const FloatID& for_){fprintf_s(mFile,"connectAttr \"");for_.write(mFile);fprintf_s(mFile,"\" \"%s.fop.for\";\n",mName.c_str());}
	/*Fog Opacity Green value*/
	void setFogOpacityG(float fog){if(fog == 0.5) return; fprintf_s(mFile, "setAttr \".fop.fog\" %f;\n", fog);}
	/*Fog Opacity Green value*/
	void setFogOpacityG(const FloatID& fog){fprintf_s(mFile,"connectAttr \"");fog.write(mFile);fprintf_s(mFile,"\" \"%s.fop.fog\";\n",mName.c_str());}
	/*Fog Opacity Blue value*/
	void setFogOpacityB(float fob){if(fob == 0.5) return; fprintf_s(mFile, "setAttr \".fop.fob\" %f;\n", fob);}
	/*Fog Opacity Blue value*/
	void setFogOpacityB(const FloatID& fob){fprintf_s(mFile,"connectAttr \"");fob.write(mFile);fprintf_s(mFile,"\" \"%s.fop.fob\";\n",mName.c_str());}
	/*
	<b>Fog Min Height</b> controls the height of
	the bottom of the fog layer.
	<p/>This attribute is only available when Physical
	Fog is turned on, and Fog Type is not Uniform.
	*/
	void setFogMinHeight(double fmh){if(fmh == 0.0) return; fprintf_s(mFile, "setAttr \".fmh\" %f;\n", fmh);}
	/*
	<b>Fog Min Height</b> controls the height of
	the bottom of the fog layer.
	<p/>This attribute is only available when Physical
	Fog is turned on, and Fog Type is not Uniform.
	*/
	void setFogMinHeight(const DoubleID& fmh){fprintf_s(mFile,"connectAttr \"");fmh.write(mFile);fprintf_s(mFile,"\" \"%s.fmh\";\n",mName.c_str());}
	/*
	<b>Fog Max Height</b> controls the height of
	the fog layer.
	<p/>If the Fog Type is Atmospheric (or Water/Atmos)
	then the density of the fog decreases exponentially
	from Fog Min Height upwards. In this case, Fog Max
	Height is the height at which density has decreased
	to half the value it has at the fog base.  (You might think
	of this as the half-life height)
	<p/>If the Fog Type is Sky (or Water/Sky) then Fog Max
	Height is the height of the top of the fog layer.
	<p/>This attribute is only available when Physical
	Fog is turned on, and Fog Type is not Uniform.
	*/
	void setFogMaxHeight(double fxh){if(fxh == 1.0) return; fprintf_s(mFile, "setAttr \".fxh\" %f;\n", fxh);}
	/*
	<b>Fog Max Height</b> controls the height of
	the fog layer.
	<p/>If the Fog Type is Atmospheric (or Water/Atmos)
	then the density of the fog decreases exponentially
	from Fog Min Height upwards. In this case, Fog Max
	Height is the height at which density has decreased
	to half the value it has at the fog base.  (You might think
	of this as the half-life height)
	<p/>If the Fog Type is Sky (or Water/Sky) then Fog Max
	Height is the height of the top of the fog layer.
	<p/>This attribute is only available when Physical
	Fog is turned on, and Fog Type is not Uniform.
	*/
	void setFogMaxHeight(const DoubleID& fxh){fprintf_s(mFile,"connectAttr \"");fxh.write(mFile);fprintf_s(mFile,"\" \"%s.fxh\";\n",mName.c_str());}
	/*
	<b>Fog Decay</b> controls the rate that the fog
	'thins out' at higher altitudes.  A value
	of 0.5 will make the fog decay linearly.
	Values between 0.5 and 1 will make the fog
	fairly even near the ground, then drop off
	suddenly at the top.  Values between 0 and 0.5
	will cause the fog to thin out very rapidly near its base.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is not Uniform.
	*/
	void setFogDecay(double fdc){if(fdc == 0.2) return; fprintf_s(mFile, "setAttr \".fdc\" %f;\n", fdc);}
	/*
	<b>Fog Decay</b> controls the rate that the fog
	'thins out' at higher altitudes.  A value
	of 0.5 will make the fog decay linearly.
	Values between 0.5 and 1 will make the fog
	fairly even near the ground, then drop off
	suddenly at the top.  Values between 0 and 0.5
	will cause the fog to thin out very rapidly near its base.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is not Uniform.
	*/
	void setFogDecay(const DoubleID& fdc){fprintf_s(mFile,"connectAttr \"");fdc.write(mFile);fprintf_s(mFile,"\" \"%s.fdc\";\n",mName.c_str());}
	/*
	<b>Fog Light Scatter</b>:  This controls how
	evenly the light is scattered in the fog.
	A value of 1 means that the light is uniformly
	scattered, and will appear to be spread throughout
	the fog.  Lower values will cause the fog to be
	brighter near the position of the sun.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setFogLightScatter(double flc){if(flc == 1.0) return; fprintf_s(mFile, "setAttr \".flc\" %f;\n", flc);}
	/*
	<b>Fog Light Scatter</b>:  This controls how
	evenly the light is scattered in the fog.
	A value of 1 means that the light is uniformly
	scattered, and will appear to be spread throughout
	the fog.  Lower values will cause the fog to be
	brighter near the position of the sun.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setFogLightScatter(const DoubleID& flc){fprintf_s(mFile,"connectAttr \"");flc.write(mFile);fprintf_s(mFile,"\" \"%s.flc\";\n",mName.c_str());}
	/*
	<b>Air Density</b> controls the optical density of
	air our in the fog simulation.  Increase this value to
	make the air seem more dense.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setAirDensity(double adn){if(adn == 0.0) return; fprintf_s(mFile, "setAttr \".adn\" %f;\n", adn);}
	/*
	<b>Air Density</b> controls the optical density of
	air our in the fog simulation.  Increase this value to
	make the air seem more dense.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setAirDensity(const DoubleID& adn){fprintf_s(mFile,"connectAttr \"");adn.write(mFile);fprintf_s(mFile,"\" \"%s.adn\";\n",mName.c_str());}
	/*
	<b>Air Color</b> controls the color of light that
	is scattered by the air.  When light passes through
	a medium such as air or fog, some frequencies (colors)
	pass directly through, while other frequencies are
	scattered.  The frequencies that are scattered are
	what give the sky, for example, its distinctive color.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setAirColor(const float3& acl){fprintf_s(mFile, "setAttr \".acl\" -type \"float3\" ");acl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Air Color</b> controls the color of light that
	is scattered by the air.  When light passes through
	a medium such as air or fog, some frequencies (colors)
	pass directly through, while other frequencies are
	scattered.  The frequencies that are scattered are
	what give the sky, for example, its distinctive color.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setAirColor(const Float3ID& acl){fprintf_s(mFile,"connectAttr \"");acl.write(mFile);fprintf_s(mFile,"\" \"%s.acl\";\n",mName.c_str());}
	/*Air Color Red value*/
	void setAirColorR(float acr){if(acr == 0.6) return; fprintf_s(mFile, "setAttr \".acl.acr\" %f;\n", acr);}
	/*Air Color Red value*/
	void setAirColorR(const FloatID& acr){fprintf_s(mFile,"connectAttr \"");acr.write(mFile);fprintf_s(mFile,"\" \"%s.acl.acr\";\n",mName.c_str());}
	/*Air Color Green value*/
	void setAirColorG(float acg){if(acg == 0.8) return; fprintf_s(mFile, "setAttr \".acl.acg\" %f;\n", acg);}
	/*Air Color Green value*/
	void setAirColorG(const FloatID& acg){fprintf_s(mFile,"connectAttr \"");acg.write(mFile);fprintf_s(mFile,"\" \"%s.acl.acg\";\n",mName.c_str());}
	/*Air Color Blue value*/
	void setAirColorB(float acb){if(acb == 1.0) return; fprintf_s(mFile, "setAttr \".acl.acb\" %f;\n", acb);}
	/*Air Color Blue value*/
	void setAirColorB(const FloatID& acb){fprintf_s(mFile,"connectAttr \"");acb.write(mFile);fprintf_s(mFile,"\" \"%s.acl.acb\";\n",mName.c_str());}
	/*
	<b>Air Opacity</b> controls what frequencies
	(colors) of light are absorbed as they pass through
	the air. This will affect the way that objects
	in the background appear to be "tinted" by the air.
	(for example, objects on the horizon often appear
	bluish in real life).
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setAirOpacity(const float3& aop){fprintf_s(mFile, "setAttr \".aop\" -type \"float3\" ");aop.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Air Opacity</b> controls what frequencies
	(colors) of light are absorbed as they pass through
	the air. This will affect the way that objects
	in the background appear to be "tinted" by the air.
	(for example, objects on the horizon often appear
	bluish in real life).
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setAirOpacity(const Float3ID& aop){fprintf_s(mFile,"connectAttr \"");aop.write(mFile);fprintf_s(mFile,"\" \"%s.aop\";\n",mName.c_str());}
	/*Air Opacity Red value*/
	void setAirOpacityR(float aor){if(aor == 0.37) return; fprintf_s(mFile, "setAttr \".aop.aor\" %f;\n", aor);}
	/*Air Opacity Red value*/
	void setAirOpacityR(const FloatID& aor){fprintf_s(mFile,"connectAttr \"");aor.write(mFile);fprintf_s(mFile,"\" \"%s.aop.aor\";\n",mName.c_str());}
	/*Air Opacity Green value*/
	void setAirOpacityG(float aog){if(aog == 0.47) return; fprintf_s(mFile, "setAttr \".aop.aog\" %f;\n", aog);}
	/*Air Opacity Green value*/
	void setAirOpacityG(const FloatID& aog){fprintf_s(mFile,"connectAttr \"");aog.write(mFile);fprintf_s(mFile,"\" \"%s.aop.aog\";\n",mName.c_str());}
	/*Air Opacity Blue value*/
	void setAirOpacityB(float aob){if(aob == 0.9) return; fprintf_s(mFile, "setAttr \".aop.aob\" %f;\n", aob);}
	/*Air Opacity Blue value*/
	void setAirOpacityB(const FloatID& aob){fprintf_s(mFile,"connectAttr \"");aob.write(mFile);fprintf_s(mFile,"\" \"%s.aop.aob\";\n",mName.c_str());}
	/*
	<b>Air Min Height</b> controls the height of the
	bottom of the air layer.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is not Uniform.
	*/
	void setAirMinHeight(double amh){if(amh == 0.0) return; fprintf_s(mFile, "setAttr \".amh\" %f;\n", amh);}
	/*
	<b>Air Min Height</b> controls the height of the
	bottom of the air layer.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is not Uniform.
	*/
	void setAirMinHeight(const DoubleID& amh){fprintf_s(mFile,"connectAttr \"");amh.write(mFile);fprintf_s(mFile,"\" \"%s.amh\";\n",mName.c_str());}
	/*
	<b>Air Max Height</b> controls the height of
	the air layer.
	<p/>If the Fog Type is Atmospheric (or Water/Atmos)
	then the density of the air decreases exponentially
	from Air Min Height upwards. In this case, Air Max
	Height is the height at which air density has decreased
	to half the value it has at Air Min Height.  (You might think
	of this as the half-life height)
	<p/>If the Fog Type is Sky (or Water/Sky) then Air Max
	Height is the height of the top of the air layer.
	<p/>This attribute is only available when Physical
	Fog is turned on, and Fog Type is not Uniform.
	*/
	void setAirMaxHeight(double axh){if(axh == 50.0) return; fprintf_s(mFile, "setAttr \".axh\" %f;\n", axh);}
	/*
	<b>Air Max Height</b> controls the height of
	the air layer.
	<p/>If the Fog Type is Atmospheric (or Water/Atmos)
	then the density of the air decreases exponentially
	from Air Min Height upwards. In this case, Air Max
	Height is the height at which air density has decreased
	to half the value it has at Air Min Height.  (You might think
	of this as the half-life height)
	<p/>If the Fog Type is Sky (or Water/Sky) then Air Max
	Height is the height of the top of the air layer.
	<p/>This attribute is only available when Physical
	Fog is turned on, and Fog Type is not Uniform.
	*/
	void setAirMaxHeight(const DoubleID& axh){fprintf_s(mFile,"connectAttr \"");axh.write(mFile);fprintf_s(mFile,"\" \"%s.axh\";\n",mName.c_str());}
	/*
	<b>Air Decay</b> controls the rate that the air
	'thins out' at higher altitudes.  A value
	of 0.5 will make the air decay linearly.
	Values between 0.5 and 1 will make the air
	fairly even near the ground, then drop off
	suddenly at the top.  Values between 0 and 0.5
	will cause the air to thin out very rapidly near the ground.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is not Uniform.
	*/
	void setAirDecay(double adc){if(adc == 0.1) return; fprintf_s(mFile, "setAttr \".adc\" %f;\n", adc);}
	/*
	<b>Air Decay</b> controls the rate that the air
	'thins out' at higher altitudes.  A value
	of 0.5 will make the air decay linearly.
	Values between 0.5 and 1 will make the air
	fairly even near the ground, then drop off
	suddenly at the top.  Values between 0 and 0.5
	will cause the air to thin out very rapidly near the ground.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is not Uniform.
	*/
	void setAirDecay(const DoubleID& adc){fprintf_s(mFile,"connectAttr \"");adc.write(mFile);fprintf_s(mFile,"\" \"%s.adc\";\n",mName.c_str());}
	/*
	<b>Air Light Scatter</b>:  This controls how
	evenly the light is scattered in the air.
	A value of 1 means that the light is uniformly
	scattered, and will appear to be spread throughout
	the air.  Lower values will cause the atmosphere
	to appear brighter around the sun
	position.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setAirLightScatter(double alc){if(alc == 1.0) return; fprintf_s(mFile, "setAttr \".alc\" %f;\n", alc);}
	/*
	<b>Air Light Scatter</b>:  This controls how
	evenly the light is scattered in the air.
	A value of 1 means that the light is uniformly
	scattered, and will appear to be spread throughout
	the air.  Lower values will cause the atmosphere
	to appear brighter around the sun
	position.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	void setAirLightScatter(const DoubleID& alc){fprintf_s(mFile,"connectAttr \"");alc.write(mFile);fprintf_s(mFile,"\" \"%s.alc\";\n",mName.c_str());}
	/*
	<b>Water Density</b> controls the optical density of
	water in the fog simulation.  Increase this value to
	make the 'underwater fog' seem more dense.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterDensity(double wdn){if(wdn == 0.0) return; fprintf_s(mFile, "setAttr \".wdn\" %f;\n", wdn);}
	/*
	<b>Water Density</b> controls the optical density of
	water in the fog simulation.  Increase this value to
	make the 'underwater fog' seem more dense.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterDensity(const DoubleID& wdn){fprintf_s(mFile,"connectAttr \"");wdn.write(mFile);fprintf_s(mFile,"\" \"%s.wdn\";\n",mName.c_str());}
	/*
	<b>Water Color</b> controls the color of light that
	is scattered by the water.  When light passes through
	a medium such as air or water, some frequencies (colors)
	pass directly through, while other frequencies are
	scattered.  The frequencies that are scattered are
	what give the water its distinctive color.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterColor(const float3& wcl){fprintf_s(mFile, "setAttr \".wcl\" -type \"float3\" ");wcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Water Color</b> controls the color of light that
	is scattered by the water.  When light passes through
	a medium such as air or water, some frequencies (colors)
	pass directly through, while other frequencies are
	scattered.  The frequencies that are scattered are
	what give the water its distinctive color.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterColor(const Float3ID& wcl){fprintf_s(mFile,"connectAttr \"");wcl.write(mFile);fprintf_s(mFile,"\" \"%s.wcl\";\n",mName.c_str());}
	/*Water Color Red value*/
	void setWaterColorR(float wcr){if(wcr == 0.6) return; fprintf_s(mFile, "setAttr \".wcl.wcr\" %f;\n", wcr);}
	/*Water Color Red value*/
	void setWaterColorR(const FloatID& wcr){fprintf_s(mFile,"connectAttr \"");wcr.write(mFile);fprintf_s(mFile,"\" \"%s.wcl.wcr\";\n",mName.c_str());}
	/*Water Color Green value*/
	void setWaterColorG(float wcg){if(wcg == 0.8) return; fprintf_s(mFile, "setAttr \".wcl.wcg\" %f;\n", wcg);}
	/*Water Color Green value*/
	void setWaterColorG(const FloatID& wcg){fprintf_s(mFile,"connectAttr \"");wcg.write(mFile);fprintf_s(mFile,"\" \"%s.wcl.wcg\";\n",mName.c_str());}
	/*Water Color Blue value*/
	void setWaterColorB(float wcb){if(wcb == 1.0) return; fprintf_s(mFile, "setAttr \".wcl.wcb\" %f;\n", wcb);}
	/*Water Color Blue value*/
	void setWaterColorB(const FloatID& wcb){fprintf_s(mFile,"connectAttr \"");wcb.write(mFile);fprintf_s(mFile,"\" \"%s.wcl.wcb\";\n",mName.c_str());}
	/*
	<b>Water Opacity</b> controls what frequencies
	(colors) of light are absorbed as they pass through
	the water. This will affect the way that objects
	in the background appear to be "tinted" by the water.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterOpacity(const float3& wop){fprintf_s(mFile, "setAttr \".wop\" -type \"float3\" ");wop.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Water Opacity</b> controls what frequencies
	(colors) of light are absorbed as they pass through
	the water. This will affect the way that objects
	in the background appear to be "tinted" by the water.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterOpacity(const Float3ID& wop){fprintf_s(mFile,"connectAttr \"");wop.write(mFile);fprintf_s(mFile,"\" \"%s.wop\";\n",mName.c_str());}
	/*Water Opacity Red value*/
	void setWaterOpacityR(float wor){if(wor == 0.37) return; fprintf_s(mFile, "setAttr \".wop.wor\" %f;\n", wor);}
	/*Water Opacity Red value*/
	void setWaterOpacityR(const FloatID& wor){fprintf_s(mFile,"connectAttr \"");wor.write(mFile);fprintf_s(mFile,"\" \"%s.wop.wor\";\n",mName.c_str());}
	/*Water Opacity Green value*/
	void setWaterOpacityG(float wog){if(wog == 0.47) return; fprintf_s(mFile, "setAttr \".wop.wog\" %f;\n", wog);}
	/*Water Opacity Green value*/
	void setWaterOpacityG(const FloatID& wog){fprintf_s(mFile,"connectAttr \"");wog.write(mFile);fprintf_s(mFile,"\" \"%s.wop.wog\";\n",mName.c_str());}
	/*Water Opacity Blue value*/
	void setWaterOpacityB(float wob){if(wob == 0.9) return; fprintf_s(mFile, "setAttr \".wop.wob\" %f;\n", wob);}
	/*Water Opacity Blue value*/
	void setWaterOpacityB(const FloatID& wob){fprintf_s(mFile,"connectAttr \"");wob.write(mFile);fprintf_s(mFile,"\" \"%s.wop.wob\";\n",mName.c_str());}
	/*
	<b>Water Level</b> is the height of the surface
	of the water.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterLevel(double wlv){if(wlv == 0.0) return; fprintf_s(mFile, "setAttr \".wlv\" %f;\n", wlv);}
	/*
	<b>Water Level</b> is the height of the surface
	of the water.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterLevel(const DoubleID& wlv){fprintf_s(mFile,"connectAttr \"");wlv.write(mFile);fprintf_s(mFile,"\" \"%s.wlv\";\n",mName.c_str());}
	/*
	<b>Water Depth</b> is the depth of the water
	in the scene. Increase this to make the water deeper.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterDepth(double wdp){if(wdp == 50.0) return; fprintf_s(mFile, "setAttr \".wdp\" %f;\n", wdp);}
	/*
	<b>Water Depth</b> is the depth of the water
	in the scene. Increase this to make the water deeper.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterDepth(const DoubleID& wdp){fprintf_s(mFile,"connectAttr \"");wdp.write(mFile);fprintf_s(mFile,"\" \"%s.wdp\";\n",mName.c_str());}
	/*
	<b>Water Light Decay</b> controls the rate that
	the illumination drops off with depth.
	<p/>Set this to 0 if you don't want the light to decay
	(that is, you don't want it to get darker as you go deeper).
	A setting of 1.0 will give a linear decay, and higher
	values will make it get darker faster.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterLightDecay(double wdc){if(wdc == 2.0) return; fprintf_s(mFile, "setAttr \".wdc\" %f;\n", wdc);}
	/*
	<b>Water Light Decay</b> controls the rate that
	the illumination drops off with depth.
	<p/>Set this to 0 if you don't want the light to decay
	(that is, you don't want it to get darker as you go deeper).
	A setting of 1.0 will give a linear decay, and higher
	values will make it get darker faster.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterLightDecay(const DoubleID& wdc){fprintf_s(mFile,"connectAttr \"");wdc.write(mFile);fprintf_s(mFile,"\" \"%s.wdc\";\n",mName.c_str());}
	/*
	<b>Water Light Scatter</b>:  This controls how
	evenly the light is scattered in the water.
	A value of 1 means that the light is uniformly
	scattered, and will appear to be spread throughout
	the water.  Lower values will cause the water
	to appear brighter near the surface, where the light is
	coming from.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterLightScatter(double wlc){if(wlc == 1.0) return; fprintf_s(mFile, "setAttr \".wlc\" %f;\n", wlc);}
	/*
	<b>Water Light Scatter</b>:  This controls how
	evenly the light is scattered in the water.
	A value of 1 means that the light is uniformly
	scattered, and will appear to be spread throughout
	the water.  Lower values will cause the water
	to appear brighter near the surface, where the light is
	coming from.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	void setWaterLightScatter(const DoubleID& wlc){fprintf_s(mFile,"connectAttr \"");wlc.write(mFile);fprintf_s(mFile,"\" \"%s.wlc\";\n",mName.c_str());}
	/*
	<b>Planet Radius</b> is a number used when calculating atmospheric
	effects that depend on the curvature of the atmosphere.
	Increasing this value makes the planet "larger", effectively
	making the atmosphere flatter, and pushing the horizon
	further away.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setPlanetRadius(double prd){if(prd == 1000.0) return; fprintf_s(mFile, "setAttr \".prd\" %f;\n", prd);}
	/*
	<b>Planet Radius</b> is a number used when calculating atmospheric
	effects that depend on the curvature of the atmosphere.
	Increasing this value makes the planet "larger", effectively
	making the atmosphere flatter, and pushing the horizon
	further away.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setPlanetRadius(const DoubleID& prd){fprintf_s(mFile,"connectAttr \"");prd.write(mFile);fprintf_s(mFile,"\" \"%s.prd\";\n",mName.c_str());}
	/*
	<b>Fog Axis</b> controls the direction that the fog
	simulation will use for "up".  You can choose any of the
	X, Y, or Z axes in the positive or negative direction.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setFogAxis(unsigned int fax){if(fax == 0) return; fprintf_s(mFile, "setAttr \".fax\" %i;\n", fax);}
	/*
	<b>Fog Axis</b> controls the direction that the fog
	simulation will use for "up".  You can choose any of the
	X, Y, or Z axes in the positive or negative direction.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setFogAxis(const UnsignedintID& fax){fprintf_s(mFile,"connectAttr \"");fax.write(mFile);fprintf_s(mFile,"\" \"%s.fax\";\n",mName.c_str());}
	/*
	<b>Sun Intensity</b> controls the overall
	brightness of the fog.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setSunIntensity(double sin){if(sin == 1.0) return; fprintf_s(mFile, "setAttr \".sin\" %f;\n", sin);}
	/*
	<b>Sun Intensity</b> controls the overall
	brightness of the fog.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setSunIntensity(const DoubleID& sin){fprintf_s(mFile,"connectAttr \"");sin.write(mFile);fprintf_s(mFile,"\" \"%s.sin\";\n",mName.c_str());}
	/*
	<b>Sun Azimuth</b> controls the position of the
	sun along an imaginary circle that goes around the
	Fog Axis.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setSunAzimuth(double saz){if(saz == 0.0) return; fprintf_s(mFile, "setAttr \".saz\" %f;\n", saz);}
	/*
	<b>Sun Azimuth</b> controls the position of the
	sun along an imaginary circle that goes around the
	Fog Axis.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setSunAzimuth(const DoubleID& saz){fprintf_s(mFile,"connectAttr \"");saz.write(mFile);fprintf_s(mFile,"\" \"%s.saz\";\n",mName.c_str());}
	/*
	<b>Sun Elevation</b> controls the position of the sun
	along a line from the horizon to directly overhead.
	A value of 90 puts the sun directly above (actually,
	directly in the position pointed to by the Fog Axis)
	and a value of 0 puts the sun at the horizon.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setSunElevation(double sel){if(sel == 45.0) return; fprintf_s(mFile, "setAttr \".sel\" %f;\n", sel);}
	/*
	<b>Sun Elevation</b> controls the position of the sun
	along a line from the horizon to directly overhead.
	A value of 90 puts the sun directly above (actually,
	directly in the position pointed to by the Fog Axis)
	and a value of 0 puts the sun at the horizon.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setSunElevation(const DoubleID& sel){fprintf_s(mFile,"connectAttr \"");sel.write(mFile);fprintf_s(mFile,"\" \"%s.sel\";\n",mName.c_str());}
	/*
	<b>Sun Color</b> controls the color of the sunlight
	illuminating the fog.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setSunColor(const float3& snc){fprintf_s(mFile, "setAttr \".snc\" -type \"float3\" ");snc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Sun Color</b> controls the color of the sunlight
	illuminating the fog.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	void setSunColor(const Float3ID& snc){fprintf_s(mFile,"connectAttr \"");snc.write(mFile);fprintf_s(mFile,"\" \"%s.snc\";\n",mName.c_str());}
	/*Sun Color Red value*/
	void setSunColorR(float snr){if(snr == 1.0) return; fprintf_s(mFile, "setAttr \".snc.snr\" %f;\n", snr);}
	/*Sun Color Red value*/
	void setSunColorR(const FloatID& snr){fprintf_s(mFile,"connectAttr \"");snr.write(mFile);fprintf_s(mFile,"\" \"%s.snc.snr\";\n",mName.c_str());}
	/*Sun Color Green value*/
	void setSunColorG(float sng){if(sng == 1.0) return; fprintf_s(mFile, "setAttr \".snc.sng\" %f;\n", sng);}
	/*Sun Color Green value*/
	void setSunColorG(const FloatID& sng){fprintf_s(mFile,"connectAttr \"");sng.write(mFile);fprintf_s(mFile,"\" \"%s.snc.sng\";\n",mName.c_str());}
	/*Sun Color Blue value*/
	void setSunColorB(float snb){if(snb == 1.0) return; fprintf_s(mFile, "setAttr \".snc.snb\" %f;\n", snb);}
	/*Sun Color Blue value*/
	void setSunColorB(const FloatID& snb){fprintf_s(mFile,"connectAttr \"");snb.write(mFile);fprintf_s(mFile,"\" \"%s.snc.snb\";\n",mName.c_str());}
	/*The transform to go from eye to world space*/
	FltMatrixID getMatrixEyeToWorld(){char buffer[4096];sprintf_s (buffer, "%s.e2w",mName.c_str());return (const char*)buffer;}
	/*The current sample point that has to be shaded*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*The current sample point that has to be shaded*/
	Float3ID getPointWorld(){char buffer[4096];sprintf_s (buffer, "%s.pw",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointWorldX(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointWorldY(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointWorldZ(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwz",mName.c_str());return (const char*)buffer;}
	/*The current incident ray*/
	Float3ID getRayDirection(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The x component of the ray*/
	FloatID getRayDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*The y component of the ray*/
	FloatID getRayDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*The z component of the ray*/
	FloatID getRayDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*
	When <b>Use Layer</b> is turned on, the density of the
	fog will be multiplied by the value of the Layer parameter.
	Layer can be use to alter the degree of saturation of
	the fog. By connecting the output of a 3d Texture to the Layer
	parameter, you can create texture in the fog.  If Use Layer
	is turned off, the Layer parameter will be ignored.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	BoolID getUseLayer(){char buffer[4096];sprintf_s (buffer, "%s.ul",mName.c_str());return (const char*)buffer;}
	/*
	When <b>Use Height</b> is turned on, the fog will not
	fill the whole scene from top to bottom.  Instead, it
	will use the Min Height and Max Height attributes to
	determine where the fog begins and ends.  These heights
	are measured in world space.  When Use Height is turned
	off, the fog will fill the entire scene vertically.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	BoolID getUseHeight(){char buffer[4096];sprintf_s (buffer, "%s.uh",mName.c_str());return (const char*)buffer;}
	/*
	The distance/height at which blending starts
	<p/>This attribute only applies when Physical Fog is
	turned off.
	*/
	FloatID getBlendRange(){char buffer[4096];sprintf_s (buffer, "%s.br",mName.c_str());return (const char*)buffer;}
	/*
	<b>Saturation Distance</b> specifies the distance in
	camera space where the fog saturates (that is where the fog becames
	completely opaque).
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	FloatID getSaturationDistance(){char buffer[4096];sprintf_s (buffer, "%s.sdt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Near Distance</b> is the distance in front of the
	camera where the fog should begin. This distance is defined
	in camera space.
	<p/>This attribute only applies when <b>Distance Clip Planes</b> is
	set to Fog Near/Far.
	*/
	FloatID getFogNearDistance(){char buffer[4096];sprintf_s (buffer, "%s.fnd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Far Distance</b> is the distance in front of the camera
	where the fog should end.
	If you set this value to be less than Fog Near Distance,
	then the fog will start at Fog Near Distance, but extend
	out to the camera far clipping plane.
	This distance is defined in camera space.
	<p/>This attribute only applies when <b>Distance Clip Planes</b> is
	set to Fog Near/Far.
	*/
	FloatID getFogFarDistance(){char buffer[4096];sprintf_s (buffer, "%s.ffd",mName.c_str());return (const char*)buffer;}
	/*
	The <b>Layer</b> attribute is used as a multiplier to the
	fog's density.  This attribute is ignored unless Use Layer is turned on.
	<p/>Connect a 3d texture to this attribute to give some
	texture to your fog or use it to decrease the amount of fog saturation.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off.
	*/
	FloatID getLayer(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*
	<b>Min Height</b> is the height above which the fog starts.
	This attribute is ignored unless Use Height is turned on.
	Otherwise, fog fills the entire scene vertically.
	The height is defined in world space.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off and <b>Use Height</b> is turned on.
	*/
	FloatID getMinHeight(){char buffer[4096];sprintf_s (buffer, "%s.mnh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Max Height</b> is the height where the fog ends;  above
	this height there is no fog..
	This attribute is ignored unless Use Height is turned on.
	Otherwise, fog fills the entire scene vertically.
	The height is defined in world space.
	<p/>This attribute only applies when <b>Physical Fog</b> is
	turned off and <b>Use Height</b> is turned on.
	*/
	FloatID getMaxHeight(){char buffer[4096];sprintf_s (buffer, "%s.mxh",mName.c_str());return (const char*)buffer;}
	/*Obsolete attribute.*/
	BoolID getUseDistance(){char buffer[4096];sprintf_s (buffer, "%s.ud",mName.c_str());return (const char*)buffer;}
	/*Obsolete attribute.*/
	FloatID getStartDistance(){char buffer[4096];sprintf_s (buffer, "%s.sd",mName.c_str());return (const char*)buffer;}
	/*Obsolete attribute.*/
	FloatID getEndDistance(){char buffer[4096];sprintf_s (buffer, "%s.ed",mName.c_str());return (const char*)buffer;}
	/*
	<b>Physical Fog</b>.  If this is turned off, Env Fog
	uses a simple fog model with just a few attributes specified.
	When Physical Fog is turned on, a more sophisticated
	physically-based model is used to simulate fog.  A different
	set of attributes is used for this model.
	*/
	BoolID getPhysicalFog(){char buffer[4096];sprintf_s (buffer, "%s.sff",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Type</b> controls how the fog will be simulated in
	your scene.  It has a number of different settings, depending
	on what kind of fog effect you want.  This attribute is only
	available when <b>Physical Fog</b> is turned on.  The settings are:
	<ul><b>Uniform Fog</b>: The fog has uniform density in all directions.
	<p/><b>Atmospheric</b>: The fog is thickest near the ground, and
	thins out (decays) as you move upwards.
	<p/><b>Sky</b>: This simulates the effect of a whole sky, with fog
	blending properly at the horizon, etc.  Use this to provide a complete
	background to a foggy scene. It is especially useful for scenes where
	you can see a Tint32 distance, <i>e.g.</i> to the horizon.
	<p/><b>Water</b>: This simulates the effect of water, scattering light
	that is shining in from above it.  This is useful for underwater
	shots, or for shots where objects are visible in a pool of water
	from above.
	<p/><b>Water/Fog</b>: Allows you to have water in your scene, with
	Uniform Fog above the water.
	<p/><b>Water/Atmos</b>: Allows you to have water in your scene, with
	Atmospheric Fog above the water.
	<p/><b>Water/Sky</b>: Allows you to have water in your scene, with
	the full Sky Fog simulation above it.
	</ul>
	*/
	UnsignedintID getFogType(){char buffer[4096];sprintf_s (buffer, "%s.ftp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Density</b> controls the optical density of
	vapour in the fog layer.  Increase this value to
	make the fog seem "thicker".
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	DoubleID getFogDensity(){char buffer[4096];sprintf_s (buffer, "%s.fdn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Color</b> controls the color of light that
	is scattered by the fog.  When light passes through
	a medium such as air or fog, some frequencies (colors)
	pass directly through, while other frequencies are
	scattered.  The frequencies that are scattered
	give the fog its distinctive color.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	Float3ID getFogColor(){char buffer[4096];sprintf_s (buffer, "%s.fcl",mName.c_str());return (const char*)buffer;}
	/*Fog Color Red value*/
	FloatID getFogColorR(){char buffer[4096];sprintf_s (buffer, "%s.fcl.fcr",mName.c_str());return (const char*)buffer;}
	/*Fog Color Green value*/
	FloatID getFogColorG(){char buffer[4096];sprintf_s (buffer, "%s.fcl.fcg",mName.c_str());return (const char*)buffer;}
	/*Fog Color Blue value*/
	FloatID getFogColorB(){char buffer[4096];sprintf_s (buffer, "%s.fcl.fcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Opacity</b> controls what frequencies
	(colors) of light are absorbed as they pass through
	the fog. This will affect the way that objects
	in the background appear to be "tinted" by the fog.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	Float3ID getFogOpacity(){char buffer[4096];sprintf_s (buffer, "%s.fop",mName.c_str());return (const char*)buffer;}
	/*Fog Opacity Red value*/
	FloatID getFogOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.fop.for",mName.c_str());return (const char*)buffer;}
	/*Fog Opacity Green value*/
	FloatID getFogOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.fop.fog",mName.c_str());return (const char*)buffer;}
	/*Fog Opacity Blue value*/
	FloatID getFogOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.fop.fob",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Min Height</b> controls the height of
	the bottom of the fog layer.
	<p/>This attribute is only available when Physical
	Fog is turned on, and Fog Type is not Uniform.
	*/
	DoubleID getFogMinHeight(){char buffer[4096];sprintf_s (buffer, "%s.fmh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Max Height</b> controls the height of
	the fog layer.
	<p/>If the Fog Type is Atmospheric (or Water/Atmos)
	then the density of the fog decreases exponentially
	from Fog Min Height upwards. In this case, Fog Max
	Height is the height at which density has decreased
	to half the value it has at the fog base.  (You might think
	of this as the half-life height)
	<p/>If the Fog Type is Sky (or Water/Sky) then Fog Max
	Height is the height of the top of the fog layer.
	<p/>This attribute is only available when Physical
	Fog is turned on, and Fog Type is not Uniform.
	*/
	DoubleID getFogMaxHeight(){char buffer[4096];sprintf_s (buffer, "%s.fxh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Decay</b> controls the rate that the fog
	'thins out' at higher altitudes.  A value
	of 0.5 will make the fog decay linearly.
	Values between 0.5 and 1 will make the fog
	fairly even near the ground, then drop off
	suddenly at the top.  Values between 0 and 0.5
	will cause the fog to thin out very rapidly near its base.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is not Uniform.
	*/
	DoubleID getFogDecay(){char buffer[4096];sprintf_s (buffer, "%s.fdc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Light Scatter</b>:  This controls how
	evenly the light is scattered in the fog.
	A value of 1 means that the light is uniformly
	scattered, and will appear to be spread throughout
	the fog.  Lower values will cause the fog to be
	brighter near the position of the sun.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	DoubleID getFogLightScatter(){char buffer[4096];sprintf_s (buffer, "%s.flc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Air Density</b> controls the optical density of
	air our in the fog simulation.  Increase this value to
	make the air seem more dense.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	DoubleID getAirDensity(){char buffer[4096];sprintf_s (buffer, "%s.adn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Air Color</b> controls the color of light that
	is scattered by the air.  When light passes through
	a medium such as air or fog, some frequencies (colors)
	pass directly through, while other frequencies are
	scattered.  The frequencies that are scattered are
	what give the sky, for example, its distinctive color.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	Float3ID getAirColor(){char buffer[4096];sprintf_s (buffer, "%s.acl",mName.c_str());return (const char*)buffer;}
	/*Air Color Red value*/
	FloatID getAirColorR(){char buffer[4096];sprintf_s (buffer, "%s.acl.acr",mName.c_str());return (const char*)buffer;}
	/*Air Color Green value*/
	FloatID getAirColorG(){char buffer[4096];sprintf_s (buffer, "%s.acl.acg",mName.c_str());return (const char*)buffer;}
	/*Air Color Blue value*/
	FloatID getAirColorB(){char buffer[4096];sprintf_s (buffer, "%s.acl.acb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Air Opacity</b> controls what frequencies
	(colors) of light are absorbed as they pass through
	the air. This will affect the way that objects
	in the background appear to be "tinted" by the air.
	(for example, objects on the horizon often appear
	bluish in real life).
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	Float3ID getAirOpacity(){char buffer[4096];sprintf_s (buffer, "%s.aop",mName.c_str());return (const char*)buffer;}
	/*Air Opacity Red value*/
	FloatID getAirOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.aop.aor",mName.c_str());return (const char*)buffer;}
	/*Air Opacity Green value*/
	FloatID getAirOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.aop.aog",mName.c_str());return (const char*)buffer;}
	/*Air Opacity Blue value*/
	FloatID getAirOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.aop.aob",mName.c_str());return (const char*)buffer;}
	/*
	<b>Air Min Height</b> controls the height of the
	bottom of the air layer.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is not Uniform.
	*/
	DoubleID getAirMinHeight(){char buffer[4096];sprintf_s (buffer, "%s.amh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Air Max Height</b> controls the height of
	the air layer.
	<p/>If the Fog Type is Atmospheric (or Water/Atmos)
	then the density of the air decreases exponentially
	from Air Min Height upwards. In this case, Air Max
	Height is the height at which air density has decreased
	to half the value it has at Air Min Height.  (You might think
	of this as the half-life height)
	<p/>If the Fog Type is Sky (or Water/Sky) then Air Max
	Height is the height of the top of the air layer.
	<p/>This attribute is only available when Physical
	Fog is turned on, and Fog Type is not Uniform.
	*/
	DoubleID getAirMaxHeight(){char buffer[4096];sprintf_s (buffer, "%s.axh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Air Decay</b> controls the rate that the air
	'thins out' at higher altitudes.  A value
	of 0.5 will make the air decay linearly.
	Values between 0.5 and 1 will make the air
	fairly even near the ground, then drop off
	suddenly at the top.  Values between 0 and 0.5
	will cause the air to thin out very rapidly near the ground.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is not Uniform.
	*/
	DoubleID getAirDecay(){char buffer[4096];sprintf_s (buffer, "%s.adc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Air Light Scatter</b>:  This controls how
	evenly the light is scattered in the air.
	A value of 1 means that the light is uniformly
	scattered, and will appear to be spread throughout
	the air.  Lower values will cause the atmosphere
	to appear brighter around the sun
	position.
	<p/>This attribute is only available when Physical
	Fog is turned on.
	*/
	DoubleID getAirLightScatter(){char buffer[4096];sprintf_s (buffer, "%s.alc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Water Density</b> controls the optical density of
	water in the fog simulation.  Increase this value to
	make the 'underwater fog' seem more dense.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	DoubleID getWaterDensity(){char buffer[4096];sprintf_s (buffer, "%s.wdn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Water Color</b> controls the color of light that
	is scattered by the water.  When light passes through
	a medium such as air or water, some frequencies (colors)
	pass directly through, while other frequencies are
	scattered.  The frequencies that are scattered are
	what give the water its distinctive color.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	Float3ID getWaterColor(){char buffer[4096];sprintf_s (buffer, "%s.wcl",mName.c_str());return (const char*)buffer;}
	/*Water Color Red value*/
	FloatID getWaterColorR(){char buffer[4096];sprintf_s (buffer, "%s.wcl.wcr",mName.c_str());return (const char*)buffer;}
	/*Water Color Green value*/
	FloatID getWaterColorG(){char buffer[4096];sprintf_s (buffer, "%s.wcl.wcg",mName.c_str());return (const char*)buffer;}
	/*Water Color Blue value*/
	FloatID getWaterColorB(){char buffer[4096];sprintf_s (buffer, "%s.wcl.wcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Water Opacity</b> controls what frequencies
	(colors) of light are absorbed as they pass through
	the water. This will affect the way that objects
	in the background appear to be "tinted" by the water.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	Float3ID getWaterOpacity(){char buffer[4096];sprintf_s (buffer, "%s.wop",mName.c_str());return (const char*)buffer;}
	/*Water Opacity Red value*/
	FloatID getWaterOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.wop.wor",mName.c_str());return (const char*)buffer;}
	/*Water Opacity Green value*/
	FloatID getWaterOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.wop.wog",mName.c_str());return (const char*)buffer;}
	/*Water Opacity Blue value*/
	FloatID getWaterOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.wop.wob",mName.c_str());return (const char*)buffer;}
	/*
	<b>Water Level</b> is the height of the surface
	of the water.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	DoubleID getWaterLevel(){char buffer[4096];sprintf_s (buffer, "%s.wlv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Water Depth</b> is the depth of the water
	in the scene. Increase this to make the water deeper.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	DoubleID getWaterDepth(){char buffer[4096];sprintf_s (buffer, "%s.wdp",mName.c_str());return (const char*)buffer;}
	/*
	<b>Water Light Decay</b> controls the rate that
	the illumination drops off with depth.
	<p/>Set this to 0 if you don't want the light to decay
	(that is, you don't want it to get darker as you go deeper).
	A setting of 1.0 will give a linear decay, and higher
	values will make it get darker faster.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	DoubleID getWaterLightDecay(){char buffer[4096];sprintf_s (buffer, "%s.wdc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Water Light Scatter</b>:  This controls how
	evenly the light is scattered in the water.
	A value of 1 means that the light is uniformly
	scattered, and will appear to be spread throughout
	the water.  Lower values will cause the water
	to appear brighter near the surface, where the light is
	coming from.
	<p/>This attribute is only available when Physical
	Fog is turned on and Fog Type is set to one of the Water types.
	*/
	DoubleID getWaterLightScatter(){char buffer[4096];sprintf_s (buffer, "%s.wlc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Planet Radius</b> is a number used when calculating atmospheric
	effects that depend on the curvature of the atmosphere.
	Increasing this value makes the planet "larger", effectively
	making the atmosphere flatter, and pushing the horizon
	further away.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	DoubleID getPlanetRadius(){char buffer[4096];sprintf_s (buffer, "%s.prd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fog Axis</b> controls the direction that the fog
	simulation will use for "up".  You can choose any of the
	X, Y, or Z axes in the positive or negative direction.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	UnsignedintID getFogAxis(){char buffer[4096];sprintf_s (buffer, "%s.fax",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sun Intensity</b> controls the overall
	brightness of the fog.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	DoubleID getSunIntensity(){char buffer[4096];sprintf_s (buffer, "%s.sin",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sun Azimuth</b> controls the position of the
	sun along an imaginary circle that goes around the
	Fog Axis.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	DoubleID getSunAzimuth(){char buffer[4096];sprintf_s (buffer, "%s.saz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sun Elevation</b> controls the position of the sun
	along a line from the horizon to directly overhead.
	A value of 90 puts the sun directly above (actually,
	directly in the position pointed to by the Fog Axis)
	and a value of 0 puts the sun at the horizon.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	DoubleID getSunElevation(){char buffer[4096];sprintf_s (buffer, "%s.sel",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sun Color</b> controls the color of the sunlight
	illuminating the fog.
	<p/>This attribute is only available when Physical
	Fog is turned on, and the Fog Type is not Uniform.
	*/
	Float3ID getSunColor(){char buffer[4096];sprintf_s (buffer, "%s.snc",mName.c_str());return (const char*)buffer;}
	/*Sun Color Red value*/
	FloatID getSunColorR(){char buffer[4096];sprintf_s (buffer, "%s.snc.snr",mName.c_str());return (const char*)buffer;}
	/*Sun Color Green value*/
	FloatID getSunColorG(){char buffer[4096];sprintf_s (buffer, "%s.snc.sng",mName.c_str());return (const char*)buffer;}
	/*Sun Color Blue value*/
	FloatID getSunColorB(){char buffer[4096];sprintf_s (buffer, "%s.snc.snb",mName.c_str());return (const char*)buffer;}
protected:
	EnvFog(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):LightFog(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ENVFOG_H__
