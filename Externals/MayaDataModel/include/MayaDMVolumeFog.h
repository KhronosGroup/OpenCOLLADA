/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VOLUMEFOG_H__
#define __MayaDM_VOLUMEFOG_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*Use <b>volume fog</b> to shade the density of a volume shape.*/
class VolumeFog : public DependNode
{
public:
	/*
	This defines the color ramp used by the colorRampInput, which
	defines a mapping of this ramp to the volume.
	*/
	struct ColorRamp{
		float colorRamp_Position;
		float3 colorRamp_Color;
		unsigned int colorRamp_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", colorRamp_Position);
			colorRamp_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", colorRamp_Interp);
		}
	};
public:
	VolumeFog(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "volumeFog"){}
	virtual ~VolumeFog(){}
	/*The ray direction.*/
	void setRayDirection(const Float3ID& rad){fprintf_s(mFile,"connectAttr \"");rad.write(mFile);fprintf_s(mFile,"\" \"%s.rad\";\n",mName.c_str());}
	/*The x component of the direction.*/
	void setRayDirectionX(const FloatID& rdx){fprintf_s(mFile,"connectAttr \"");rdx.write(mFile);fprintf_s(mFile,"\" \"%s.rad.rdx\";\n",mName.c_str());}
	/*The y component of the direction.*/
	void setRayDirectionY(const FloatID& rdy){fprintf_s(mFile,"connectAttr \"");rdy.write(mFile);fprintf_s(mFile,"\" \"%s.rad.rdy\";\n",mName.c_str());}
	/*The z component of the direction.*/
	void setRayDirectionZ(const FloatID& rdz){fprintf_s(mFile,"connectAttr \"");rdz.write(mFile);fprintf_s(mFile,"\" \"%s.rad.rdz\";\n",mName.c_str());}
	/*The current start point of the volume interval*/
	void setPointWorld(const Float3ID& pw){fprintf_s(mFile,"connectAttr \"");pw.write(mFile);fprintf_s(mFile,"\" \"%s.pw\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointWorldX(const FloatID& pwx){fprintf_s(mFile,"connectAttr \"");pwx.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointWorldY(const FloatID& pwy){fprintf_s(mFile,"connectAttr \"");pwy.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointWorldZ(const FloatID& pwz){fprintf_s(mFile,"connectAttr \"");pwz.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwz\";\n",mName.c_str());}
	/*The end of the volume interval in world space.*/
	void setFarPointWorld(const Float3ID& fw){fprintf_s(mFile,"connectAttr \"");fw.write(mFile);fprintf_s(mFile,"\" \"%s.fw\";\n",mName.c_str());}
	/*The x-component of the world far-position.*/
	void setFarPointWorldX(const FloatID& fwx){fprintf_s(mFile,"connectAttr \"");fwx.write(mFile);fprintf_s(mFile,"\" \"%s.fw.fwx\";\n",mName.c_str());}
	/*The y-component of the world far-position.*/
	void setFarPointWorldY(const FloatID& fwy){fprintf_s(mFile,"connectAttr \"");fwy.write(mFile);fprintf_s(mFile,"\" \"%s.fw.fwy\";\n",mName.c_str());}
	/*The z-component of the world far-position.*/
	void setFarPointWorldZ(const FloatID& fwz){fprintf_s(mFile,"connectAttr \"");fwz.write(mFile);fprintf_s(mFile,"\" \"%s.fw.fwz\";\n",mName.c_str());}
	/*The current start point of the volume interval in object space*/
	void setPointObj(const Float3ID& po){fprintf_s(mFile,"connectAttr \"");po.write(mFile);fprintf_s(mFile,"\" \"%s.po\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointObjX(const FloatID& pox){fprintf_s(mFile,"connectAttr \"");pox.write(mFile);fprintf_s(mFile,"\" \"%s.po.pox\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointObjY(const FloatID& poy){fprintf_s(mFile,"connectAttr \"");poy.write(mFile);fprintf_s(mFile,"\" \"%s.po.poy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointObjZ(const FloatID& poz){fprintf_s(mFile,"connectAttr \"");poz.write(mFile);fprintf_s(mFile,"\" \"%s.po.poz\";\n",mName.c_str());}
	/*The end of the volume interval in world space.*/
	void setFarPointObj(const Float3ID& fo){fprintf_s(mFile,"connectAttr \"");fo.write(mFile);fprintf_s(mFile,"\" \"%s.fo\";\n",mName.c_str());}
	/*The x-component of the object space far-position.*/
	void setFarPointObjectX(const FloatID& fox){fprintf_s(mFile,"connectAttr \"");fox.write(mFile);fprintf_s(mFile,"\" \"%s.fo.fox\";\n",mName.c_str());}
	/*The y-component of the object space far-position.*/
	void setFarPointObjectY(const FloatID& foy){fprintf_s(mFile,"connectAttr \"");foy.write(mFile);fprintf_s(mFile,"\" \"%s.fo.foy\";\n",mName.c_str());}
	/*The z-component of the object space far-position.*/
	void setFarPointObjectZ(const FloatID& foz){fprintf_s(mFile,"connectAttr \"");foz.write(mFile);fprintf_s(mFile,"\" \"%s.fo.foz\";\n",mName.c_str());}
	/*<b>Color</b> is the basic color of the volume(when not otherwise defined).*/
	void setColor(const float3& cl){fprintf_s(mFile, "setAttr \".cl\" -type \"float3\" ");cl.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Color</b> is the basic color of the volume(when not otherwise defined).*/
	void setColor(const Float3ID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl\";\n",mName.c_str());}
	/*color red value*/
	void setColorR(float cr){if(cr == 0.9) return; fprintf_s(mFile, "setAttr \".cl.cr\" %f;\n", cr);}
	/*color red value*/
	void setColorR(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cr\";\n",mName.c_str());}
	/*color green value*/
	void setColorG(float cg){if(cg == 0.9) return; fprintf_s(mFile, "setAttr \".cl.cg\" %f;\n", cg);}
	/*color green value*/
	void setColorG(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cg\";\n",mName.c_str());}
	/*color blue value*/
	void setColorB(float cb){if(cb == 0.9) return; fprintf_s(mFile, "setAttr \".cl.cb\" %f;\n", cb);}
	/*color blue value*/
	void setColorB(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cb\";\n",mName.c_str());}
	/*
	This determines the input to the color ramp. If transparency
	is used, then the value used from the colorRamp is relative
	to the current transparency within the volume. More transparent
	regions will use the color at the left of the ramp and totally
	opaque regions will have the color at the right.
	For concentric mapping the distance to the volume center
	determines color from the ramp.  Y Gradient selects the color
	based on the position along the y axis. If Ignore is set then
	the color parameter is used instead of the color ramp.
	*/
	void setColorRampInput(unsigned int cri){if(cri == 0) return; fprintf_s(mFile, "setAttr \".cri\" %i;\n", cri);}
	/*
	This determines the input to the color ramp. If transparency
	is used, then the value used from the colorRamp is relative
	to the current transparency within the volume. More transparent
	regions will use the color at the left of the ramp and totally
	opaque regions will have the color at the right.
	For concentric mapping the distance to the volume center
	determines color from the ramp.  Y Gradient selects the color
	based on the position along the y axis. If Ignore is set then
	the color parameter is used instead of the color ramp.
	*/
	void setColorRampInput(const UnsignedintID& cri){fprintf_s(mFile,"connectAttr \"");cri.write(mFile);fprintf_s(mFile,"\" \"%s.cri\";\n",mName.c_str());}
	/*
	This defines the color ramp used by the colorRampInput, which
	defines a mapping of this ramp to the volume.
	*/
	void setColorRamp(size_t crm_i,const ColorRamp& crm){fprintf_s(mFile, "setAttr \".crm[%i]\" ",crm_i);crm.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This defines the color ramp used by the colorRampInput, which
	defines a mapping of this ramp to the volume.
	*/
	void setColorRamp(size_t crm_i,const ColorRampID& crm){fprintf_s(mFile,"connectAttr \"");crm.write(mFile);fprintf_s(mFile,"\" \"%s.crm[%i]\";\n",mName.c_str(),crm_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColorRamp_Position(size_t crm_i,float crmp){if(crmp == 0.0) return; fprintf_s(mFile, "setAttr \".crm[%i].crmp\" %f;\n", crm_i,crmp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColorRamp_Position(size_t crm_i,const FloatID& crmp){fprintf_s(mFile,"connectAttr \"");crmp.write(mFile);fprintf_s(mFile,"\" \"%s.crm[%i].crmp\";\n",mName.c_str(),crm_i);}
	/*Ramp color at the sibling position*/
	void setColorRamp_Color(size_t crm_i,const float3& crmc){fprintf_s(mFile, "setAttr \".crm[%i].crmc\" -type \"float3\" ",crm_i);crmc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setColorRamp_Color(size_t crm_i,const Float3ID& crmc){fprintf_s(mFile,"connectAttr \"");crmc.write(mFile);fprintf_s(mFile,"\" \"%s.crm[%i].crmc\";\n",mName.c_str(),crm_i);}
	/*Ramp red channel value at the sibling position*/
	void setColorRamp_ColorR(size_t crm_i,float crmcr){if(crmcr == 0.0) return; fprintf_s(mFile, "setAttr \".crm[%i].crmc.crmcr\" %f;\n", crm_i,crmcr);}
	/*Ramp red channel value at the sibling position*/
	void setColorRamp_ColorR(size_t crm_i,const FloatID& crmcr){fprintf_s(mFile,"connectAttr \"");crmcr.write(mFile);fprintf_s(mFile,"\" \"%s.crm[%i].crmc.crmcr\";\n",mName.c_str(),crm_i);}
	/*Ramp green channel value at the sibling position*/
	void setColorRamp_ColorG(size_t crm_i,float crmcg){if(crmcg == 0.0) return; fprintf_s(mFile, "setAttr \".crm[%i].crmc.crmcg\" %f;\n", crm_i,crmcg);}
	/*Ramp green channel value at the sibling position*/
	void setColorRamp_ColorG(size_t crm_i,const FloatID& crmcg){fprintf_s(mFile,"connectAttr \"");crmcg.write(mFile);fprintf_s(mFile,"\" \"%s.crm[%i].crmc.crmcg\";\n",mName.c_str(),crm_i);}
	/*Ramp blue channel value at the sibling position*/
	void setColorRamp_ColorB(size_t crm_i,float crmcb){if(crmcb == 0.0) return; fprintf_s(mFile, "setAttr \".crm[%i].crmc.crmcb\" %f;\n", crm_i,crmcb);}
	/*Ramp blue channel value at the sibling position*/
	void setColorRamp_ColorB(size_t crm_i,const FloatID& crmcb){fprintf_s(mFile,"connectAttr \"");crmcb.write(mFile);fprintf_s(mFile,"\" \"%s.crm[%i].crmc.crmcb\";\n",mName.c_str(),crm_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setColorRamp_Interp(size_t crm_i,unsigned int crmi){if(crmi == 0) return; fprintf_s(mFile, "setAttr \".crm[%i].crmi\" %i;\n", crm_i,crmi);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setColorRamp_Interp(size_t crm_i,const UnsignedintID& crmi){fprintf_s(mFile,"connectAttr \"");crmi.write(mFile);fprintf_s(mFile,"\" \"%s.crm[%i].crmi\";\n",mName.c_str(),crm_i);}
	/*<b>Transparency</b> is the color transparency of the volume*/
	void setTransparency(const float3& t){fprintf_s(mFile, "setAttr \".t\" -type \"float3\" ");t.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Transparency</b> is the color transparency of the volume*/
	void setTransparency(const Float3ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*transparency red value*/
	void setTransparencyR(float tr){if(tr == 0.5) return; fprintf_s(mFile, "setAttr \".t.tr\" %f;\n", tr);}
	/*transparency red value*/
	void setTransparencyR(const FloatID& tr){fprintf_s(mFile,"connectAttr \"");tr.write(mFile);fprintf_s(mFile,"\" \"%s.t.tr\";\n",mName.c_str());}
	/*transparency green value*/
	void setTransparencyG(float tg){if(tg == 0.5) return; fprintf_s(mFile, "setAttr \".t.tg\" %f;\n", tg);}
	/*transparency green value*/
	void setTransparencyG(const FloatID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.t.tg\";\n",mName.c_str());}
	/*transparency blue value*/
	void setTransparencyB(float tb){if(tb == 0.5) return; fprintf_s(mFile, "setAttr \".t.tb\" %f;\n", tb);}
	/*transparency blue value*/
	void setTransparencyB(const FloatID& tb){fprintf_s(mFile,"connectAttr \"");tb.write(mFile);fprintf_s(mFile,"\" \"%s.t.tb\";\n",mName.c_str());}
	/*
	<b>Incandescence</b> makes a material appear opalescent, as if it were
	emmitting light itself, such as lava or a phosphorescent moss.  A
	slight touch of incandescence on vegetable matter, for example,
	can make the vegetation look alive.<p/>
	By default, the color is black, which has no effect on the surface.
	<p/><i>Note:</i> although incandescence makes a surface appear to
	glow, it does not actually act as a source of light in the scene.
	<p/>See also Glow Intensity.
	*/
	void setIncandescence(const float3& ic){fprintf_s(mFile, "setAttr \".ic\" -type \"float3\" ");ic.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Incandescence</b> makes a material appear opalescent, as if it were
	emmitting light itself, such as lava or a phosphorescent moss.  A
	slight touch of incandescence on vegetable matter, for example,
	can make the vegetation look alive.<p/>
	By default, the color is black, which has no effect on the surface.
	<p/><i>Note:</i> although incandescence makes a surface appear to
	glow, it does not actually act as a source of light in the scene.
	<p/>See also Glow Intensity.
	*/
	void setIncandescence(const Float3ID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*incandescence red value*/
	void setIncandescenceR(float ir){if(ir == 0.0) return; fprintf_s(mFile, "setAttr \".ic.ir\" %f;\n", ir);}
	/*incandescence red value*/
	void setIncandescenceR(const FloatID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.ic.ir\";\n",mName.c_str());}
	/*incandescence green value*/
	void setIncandescenceG(float ig){if(ig == 0.0) return; fprintf_s(mFile, "setAttr \".ic.ig\" %f;\n", ig);}
	/*incandescence green value*/
	void setIncandescenceG(const FloatID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ic.ig\";\n",mName.c_str());}
	/*incandescence blue value*/
	void setIncandescenceB(float ib){if(ib == 0.0) return; fprintf_s(mFile, "setAttr \".ic.ib\" %f;\n", ib);}
	/*incandescence blue value*/
	void setIncandescenceB(const FloatID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ic.ib\";\n",mName.c_str());}
	/*
	<b>Glow Intensity</b> is 0 by default, meaning that no glow is added to the
	material.  As this is turned up, the material seems to 'glow'
	with a faint halo of light around it.
	<p/>Note that this is different from the Incandescence attribute
	in a few important ways.  First, glow is added as a post-process
	at the end of rendering.  (Incandescence just makes the surface
	appear brighter.)  Second, glow adds a halo, which incandescence
	does not.
	*/
	void setGlowIntensity(float gi){if(gi == 0.0) return; fprintf_s(mFile, "setAttr \".gi\" %f;\n", gi);}
	/*
	<b>Glow Intensity</b> is 0 by default, meaning that no glow is added to the
	material.  As this is turned up, the material seems to 'glow'
	with a faint halo of light around it.
	<p/>Note that this is different from the Incandescence attribute
	in a few important ways.  First, glow is added as a post-process
	at the end of rendering.  (Incandescence just makes the surface
	appear brighter.)  Second, glow adds a halo, which incandescence
	does not.
	*/
	void setGlowIntensity(const FloatID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.gi\";\n",mName.c_str());}
	/*
	Out Glow Color is the final output glow color from this node
	(if this node is glowing)
	*/
	void setOutGlowColor(const Float3ID& ogc){fprintf_s(mFile,"connectAttr \"");ogc.write(mFile);fprintf_s(mFile,"\" \"%s.ogc\";\n",mName.c_str());}
	/*out glow color red value*/
	void setOutGlowColorR(const FloatID& ogr){fprintf_s(mFile,"connectAttr \"");ogr.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogr\";\n",mName.c_str());}
	/*out glow color green value*/
	void setOutGlowColorG(const FloatID& ogg){fprintf_s(mFile,"connectAttr \"");ogg.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogg\";\n",mName.c_str());}
	/*out glow color blue value*/
	void setOutGlowColorB(const FloatID& ogb){fprintf_s(mFile,"connectAttr \"");ogb.write(mFile);fprintf_s(mFile,"\" \"%s.ogc.ogb\";\n",mName.c_str());}
	/*the density or opacity of the fog*/
	void setDensity(float dns){if(dns == 1) return; fprintf_s(mFile, "setAttr \".dns\" %f;\n", dns);}
	/*the density or opacity of the fog*/
	void setDensity(const FloatID& dns){fprintf_s(mFile,"connectAttr \"");dns.write(mFile);fprintf_s(mFile,"\" \"%s.dns\";\n",mName.c_str());}
	/*
	Determines if the density is defined in worldspace or objectspace.
	Objectspace density preserves the look when an object is scaled.
	*/
	void setDensityMode(unsigned int dmd){if(dmd == 1) return; fprintf_s(mFile, "setAttr \".dmd\" %i;\n", dmd);}
	/*
	Determines if the density is defined in worldspace or objectspace.
	Objectspace density preserves the look when an object is scaled.
	*/
	void setDensityMode(const UnsignedintID& dmd){fprintf_s(mFile,"connectAttr \"");dmd.write(mFile);fprintf_s(mFile,"\" \"%s.dmd\";\n",mName.c_str());}
	/*
	Defines a shape to use to define an outer boundary for
	creating a soft edged volume. If one
	is rendering a box volume then Cube should match the
	edges of the volume. Likewise for Sphere and Cone volumes.
	LightCone is different from Cone in that the fade does not
	occur near the point of the cone.
	*/
	void setDropoffShape(unsigned int dos){if(dos == 0) return; fprintf_s(mFile, "setAttr \".dos\" %i;\n", dos);}
	/*
	Defines a shape to use to define an outer boundary for
	creating a soft edged volume. If one
	is rendering a box volume then Cube should match the
	edges of the volume. Likewise for Sphere and Cone volumes.
	LightCone is different from Cone in that the fade does not
	occur near the point of the cone.
	*/
	void setDropoffShape(const UnsignedintID& dos){fprintf_s(mFile,"connectAttr \"");dos.write(mFile);fprintf_s(mFile,"\" \"%s.dos\";\n",mName.c_str());}
	/*
	Defines the rate at which the density drops off towards the edge
	defined by the <b>Dropoff Shape</b>.
	*/
	void setEdgeDropoff(float edr){if(edr == .5) return; fprintf_s(mFile, "setAttr \".edr\" %f;\n", edr);}
	/*
	Defines the rate at which the density drops off towards the edge
	defined by the <b>Dropoff Shape</b>.
	*/
	void setEdgeDropoff(const FloatID& edr){fprintf_s(mFile,"connectAttr \"");edr.write(mFile);fprintf_s(mFile,"\" \"%s.edr\";\n",mName.c_str());}
	/*Defines how quickly the density drops off down the axis of a cone.*/
	void setAxialDropoff(float axd){if(axd == 0.3) return; fprintf_s(mFile, "setAttr \".axd\" %f;\n", axd);}
	/*Defines how quickly the density drops off down the axis of a cone.*/
	void setAxialDropoff(const FloatID& axd){fprintf_s(mFile,"connectAttr \"");axd.write(mFile);fprintf_s(mFile,"\" \"%s.axd\";\n",mName.c_str());}
	/*
	Defines the the way the edge dropoff is performed
	<b>Scale Opacity</b> multiplies the overall density by the
	dropoff value, causing a uniform change in transparency.
	<b>Subtract Density</b> subtracts the dropoff value multiplied by
	the <b>Dropoff Subtract</b> value from the density. This is primarily useful
	when the density or transparency is textured. Low density regions
	will become completely transparent, while high density regions will
	not be affected much. This can help preserve the character of a pluffy
	cloud, for example.
	*/
	void setDropoffMethod(unsigned int drm){if(drm == 0) return; fprintf_s(mFile, "setAttr \".drm\" %i;\n", drm);}
	/*
	Defines the the way the edge dropoff is performed
	<b>Scale Opacity</b> multiplies the overall density by the
	dropoff value, causing a uniform change in transparency.
	<b>Subtract Density</b> subtracts the dropoff value multiplied by
	the <b>Dropoff Subtract</b> value from the density. This is primarily useful
	when the density or transparency is textured. Low density regions
	will become completely transparent, while high density regions will
	not be affected much. This can help preserve the character of a pluffy
	cloud, for example.
	*/
	void setDropoffMethod(const UnsignedintID& drm){fprintf_s(mFile,"connectAttr \"");drm.write(mFile);fprintf_s(mFile,"\" \"%s.drm\";\n",mName.c_str());}
	/*
	This is the maximum amount of density subtracted from
	the volume when <b>Dropoff Method = Subtract Density</b>.
	If the volume density is 1.0 and <b>Dropoff Subtract</b> is 1.0
	then the edge of the volume will be completely transparent.
	*/
	void setDropoffSubtract(float drs){if(drs == 1.0) return; fprintf_s(mFile, "setAttr \".drs\" %f;\n", drs);}
	/*
	This is the maximum amount of density subtracted from
	the volume when <b>Dropoff Method = Subtract Density</b>.
	If the volume density is 1.0 and <b>Dropoff Subtract</b> is 1.0
	then the edge of the volume will be completely transparent.
	*/
	void setDropoffSubtract(const FloatID& drs){fprintf_s(mFile,"connectAttr \"");drs.write(mFile);fprintf_s(mFile,"\" \"%s.drs\";\n",mName.c_str());}
	/*
	If <b>Illuminated</b> is turned on then lights will be computed
	for the fog. The lighting happens for each volume span as determined
	by the volume samples parameter on the geometry.
	*/
	void setIlluminated(bool il){if(il == false) return; fprintf_s(mFile, "setAttr \".il\" %i;\n", il);}
	/*
	If <b>Illuminated</b> is turned on then lights will be computed
	for the fog. The lighting happens for each volume span as determined
	by the volume samples parameter on the geometry.
	*/
	void setIlluminated(const BoolID& il){fprintf_s(mFile,"connectAttr \"");il.write(mFile);fprintf_s(mFile,"\" \"%s.il\";\n",mName.c_str());}
	/*
	This is the amount that the fog scatters light in all directions.
	As it approaches zero the fog tends to scatter light more and more
	in a directional fashion, resulting in halos around light sources.
	*/
	void setLightScatter(float lsc){if(lsc == 1.0) return; fprintf_s(mFile, "setAttr \".lsc\" %f;\n", lsc);}
	/*
	This is the amount that the fog scatters light in all directions.
	As it approaches zero the fog tends to scatter light more and more
	in a directional fashion, resulting in halos around light sources.
	*/
	void setLightScatter(const FloatID& lsc){fprintf_s(mFile,"connectAttr \"");lsc.write(mFile);fprintf_s(mFile,"\" \"%s.lsc\";\n",mName.c_str());}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you do not want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	void setMatteOpacityMode(unsigned int mom){if(mom == 2) return; fprintf_s(mFile, "setAttr \".mom\" %i;\n", mom);}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you do not want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	void setMatteOpacityMode(const UnsignedintID& mom){fprintf_s(mFile,"connectAttr \"");mom.write(mFile);fprintf_s(mFile,"\" \"%s.mom\";\n",mName.c_str());}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(float mog){if(mog == 1.0) return; fprintf_s(mFile, "setAttr \".mog\" %f;\n", mog);}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(const FloatID& mog){fprintf_s(mFile,"connectAttr \"");mog.write(mFile);fprintf_s(mFile,"\" \"%s.mog\";\n",mName.c_str());}
	/*
	<b>Out Color</b>.  Connect another attribute to this to
	control the color of the volume shader.
	*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Out Color red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*Out Color green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*Out Color blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*
	<b>Out Transparency</b>. Connect another attribute to this to
	control the Shader's transparency.  Higher values (that is,
	brighter colors) make the object more transparent;  darker
	colors make it more opaque.
	*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*Out Transparency red value*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*Out Transparency green value*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*Out Transparency blue value*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*
	<b>Out Matte Opacity</b>.  Connect another attribute to this
	to control the opacity of the material's matte (alpha) channel.
	*/
	void setOutMatteOpacity(const Float3ID& omo){fprintf_s(mFile,"connectAttr \"");omo.write(mFile);fprintf_s(mFile,"\" \"%s.omo\";\n",mName.c_str());}
	/*Out Matte Opacity red value*/
	void setOutMatteOpacityR(const FloatID& omor){fprintf_s(mFile,"connectAttr \"");omor.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omor\";\n",mName.c_str());}
	/*Out Matte Opacity green value*/
	void setOutMatteOpacityG(const FloatID& omog){fprintf_s(mFile,"connectAttr \"");omog.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omog\";\n",mName.c_str());}
	/*Out Matte Opacity blue value*/
	void setOutMatteOpacityB(const FloatID& omob){fprintf_s(mFile,"connectAttr \"");omob.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omob\";\n",mName.c_str());}
	/*The ray direction.*/
	Float3ID getRayDirection(){char buffer[4096];sprintf_s (buffer, "%s.rad",mName.c_str());return (const char*)buffer;}
	/*The x component of the direction.*/
	FloatID getRayDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.rad.rdx",mName.c_str());return (const char*)buffer;}
	/*The y component of the direction.*/
	FloatID getRayDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.rad.rdy",mName.c_str());return (const char*)buffer;}
	/*The z component of the direction.*/
	FloatID getRayDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.rad.rdz",mName.c_str());return (const char*)buffer;}
	/*The current start point of the volume interval*/
	Float3ID getPointWorld(){char buffer[4096];sprintf_s (buffer, "%s.pw",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointWorldX(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointWorldY(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointWorldZ(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwz",mName.c_str());return (const char*)buffer;}
	/*The end of the volume interval in world space.*/
	Float3ID getFarPointWorld(){char buffer[4096];sprintf_s (buffer, "%s.fw",mName.c_str());return (const char*)buffer;}
	/*The x-component of the world far-position.*/
	FloatID getFarPointWorldX(){char buffer[4096];sprintf_s (buffer, "%s.fw.fwx",mName.c_str());return (const char*)buffer;}
	/*The y-component of the world far-position.*/
	FloatID getFarPointWorldY(){char buffer[4096];sprintf_s (buffer, "%s.fw.fwy",mName.c_str());return (const char*)buffer;}
	/*The z-component of the world far-position.*/
	FloatID getFarPointWorldZ(){char buffer[4096];sprintf_s (buffer, "%s.fw.fwz",mName.c_str());return (const char*)buffer;}
	/*The current start point of the volume interval in object space*/
	Float3ID getPointObj(){char buffer[4096];sprintf_s (buffer, "%s.po",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.po.pox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.po.poy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.po.poz",mName.c_str());return (const char*)buffer;}
	/*The end of the volume interval in world space.*/
	Float3ID getFarPointObj(){char buffer[4096];sprintf_s (buffer, "%s.fo",mName.c_str());return (const char*)buffer;}
	/*The x-component of the object space far-position.*/
	FloatID getFarPointObjectX(){char buffer[4096];sprintf_s (buffer, "%s.fo.fox",mName.c_str());return (const char*)buffer;}
	/*The y-component of the object space far-position.*/
	FloatID getFarPointObjectY(){char buffer[4096];sprintf_s (buffer, "%s.fo.foy",mName.c_str());return (const char*)buffer;}
	/*The z-component of the object space far-position.*/
	FloatID getFarPointObjectZ(){char buffer[4096];sprintf_s (buffer, "%s.fo.foz",mName.c_str());return (const char*)buffer;}
	/*<b>Color</b> is the basic color of the volume(when not otherwise defined).*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.cl",mName.c_str());return (const char*)buffer;}
	/*color red value*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.cl.cr",mName.c_str());return (const char*)buffer;}
	/*color green value*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.cl.cg",mName.c_str());return (const char*)buffer;}
	/*color blue value*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.cl.cb",mName.c_str());return (const char*)buffer;}
	/*
	This determines the input to the color ramp. If transparency
	is used, then the value used from the colorRamp is relative
	to the current transparency within the volume. More transparent
	regions will use the color at the left of the ramp and totally
	opaque regions will have the color at the right.
	For concentric mapping the distance to the volume center
	determines color from the ramp.  Y Gradient selects the color
	based on the position along the y axis. If Ignore is set then
	the color parameter is used instead of the color ramp.
	*/
	UnsignedintID getColorRampInput(){char buffer[4096];sprintf_s (buffer, "%s.cri",mName.c_str());return (const char*)buffer;}
	/*
	This defines the color ramp used by the colorRampInput, which
	defines a mapping of this ramp to the volume.
	*/
	const ColorRampID& getColorRamp(size_t crm_i){char buffer[4096];sprintf_s (buffer, "%s.crm[%i]",mName.c_str(),crm_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getColorRamp_Position(size_t crm_i){char buffer[4096];sprintf_s (buffer, "%s.crm[%i].crmp",mName.c_str(),crm_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getColorRamp_Color(size_t crm_i){char buffer[4096];sprintf_s (buffer, "%s.crm[%i].crmc",mName.c_str(),crm_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getColorRamp_ColorR(size_t crm_i){char buffer[4096];sprintf_s (buffer, "%s.crm[%i].crmc.crmcr",mName.c_str(),crm_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getColorRamp_ColorG(size_t crm_i){char buffer[4096];sprintf_s (buffer, "%s.crm[%i].crmc.crmcg",mName.c_str(),crm_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getColorRamp_ColorB(size_t crm_i){char buffer[4096];sprintf_s (buffer, "%s.crm[%i].crmc.crmcb",mName.c_str(),crm_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getColorRamp_Interp(size_t crm_i){char buffer[4096];sprintf_s (buffer, "%s.crm[%i].crmi",mName.c_str(),crm_i);return (const char*)buffer;}
	/*<b>Transparency</b> is the color transparency of the volume*/
	Float3ID getTransparency(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*transparency red value*/
	FloatID getTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.t.tr",mName.c_str());return (const char*)buffer;}
	/*transparency green value*/
	FloatID getTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.t.tg",mName.c_str());return (const char*)buffer;}
	/*transparency blue value*/
	FloatID getTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.t.tb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Incandescence</b> makes a material appear opalescent, as if it were
	emmitting light itself, such as lava or a phosphorescent moss.  A
	slight touch of incandescence on vegetable matter, for example,
	can make the vegetation look alive.<p/>
	By default, the color is black, which has no effect on the surface.
	<p/><i>Note:</i> although incandescence makes a surface appear to
	glow, it does not actually act as a source of light in the scene.
	<p/>See also Glow Intensity.
	*/
	Float3ID getIncandescence(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*incandescence red value*/
	FloatID getIncandescenceR(){char buffer[4096];sprintf_s (buffer, "%s.ic.ir",mName.c_str());return (const char*)buffer;}
	/*incandescence green value*/
	FloatID getIncandescenceG(){char buffer[4096];sprintf_s (buffer, "%s.ic.ig",mName.c_str());return (const char*)buffer;}
	/*incandescence blue value*/
	FloatID getIncandescenceB(){char buffer[4096];sprintf_s (buffer, "%s.ic.ib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Glow Intensity</b> is 0 by default, meaning that no glow is added to the
	material.  As this is turned up, the material seems to 'glow'
	with a faint halo of light around it.
	<p/>Note that this is different from the Incandescence attribute
	in a few important ways.  First, glow is added as a post-process
	at the end of rendering.  (Incandescence just makes the surface
	appear brighter.)  Second, glow adds a halo, which incandescence
	does not.
	*/
	FloatID getGlowIntensity(){char buffer[4096];sprintf_s (buffer, "%s.gi",mName.c_str());return (const char*)buffer;}
	/*
	Out Glow Color is the final output glow color from this node
	(if this node is glowing)
	*/
	Float3ID getOutGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.ogc",mName.c_str());return (const char*)buffer;}
	/*out glow color red value*/
	FloatID getOutGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogr",mName.c_str());return (const char*)buffer;}
	/*out glow color green value*/
	FloatID getOutGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogg",mName.c_str());return (const char*)buffer;}
	/*out glow color blue value*/
	FloatID getOutGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.ogc.ogb",mName.c_str());return (const char*)buffer;}
	/*the density or opacity of the fog*/
	FloatID getDensity(){char buffer[4096];sprintf_s (buffer, "%s.dns",mName.c_str());return (const char*)buffer;}
	/*
	Determines if the density is defined in worldspace or objectspace.
	Objectspace density preserves the look when an object is scaled.
	*/
	UnsignedintID getDensityMode(){char buffer[4096];sprintf_s (buffer, "%s.dmd",mName.c_str());return (const char*)buffer;}
	/*
	Defines a shape to use to define an outer boundary for
	creating a soft edged volume. If one
	is rendering a box volume then Cube should match the
	edges of the volume. Likewise for Sphere and Cone volumes.
	LightCone is different from Cone in that the fade does not
	occur near the point of the cone.
	*/
	UnsignedintID getDropoffShape(){char buffer[4096];sprintf_s (buffer, "%s.dos",mName.c_str());return (const char*)buffer;}
	/*
	Defines the rate at which the density drops off towards the edge
	defined by the <b>Dropoff Shape</b>.
	*/
	FloatID getEdgeDropoff(){char buffer[4096];sprintf_s (buffer, "%s.edr",mName.c_str());return (const char*)buffer;}
	/*Defines how quickly the density drops off down the axis of a cone.*/
	FloatID getAxialDropoff(){char buffer[4096];sprintf_s (buffer, "%s.axd",mName.c_str());return (const char*)buffer;}
	/*
	Defines the the way the edge dropoff is performed
	<b>Scale Opacity</b> multiplies the overall density by the
	dropoff value, causing a uniform change in transparency.
	<b>Subtract Density</b> subtracts the dropoff value multiplied by
	the <b>Dropoff Subtract</b> value from the density. This is primarily useful
	when the density or transparency is textured. Low density regions
	will become completely transparent, while high density regions will
	not be affected much. This can help preserve the character of a pluffy
	cloud, for example.
	*/
	UnsignedintID getDropoffMethod(){char buffer[4096];sprintf_s (buffer, "%s.drm",mName.c_str());return (const char*)buffer;}
	/*
	This is the maximum amount of density subtracted from
	the volume when <b>Dropoff Method = Subtract Density</b>.
	If the volume density is 1.0 and <b>Dropoff Subtract</b> is 1.0
	then the edge of the volume will be completely transparent.
	*/
	FloatID getDropoffSubtract(){char buffer[4096];sprintf_s (buffer, "%s.drs",mName.c_str());return (const char*)buffer;}
	/*
	If <b>Illuminated</b> is turned on then lights will be computed
	for the fog. The lighting happens for each volume span as determined
	by the volume samples parameter on the geometry.
	*/
	BoolID getIlluminated(){char buffer[4096];sprintf_s (buffer, "%s.il",mName.c_str());return (const char*)buffer;}
	/*
	This is the amount that the fog scatters light in all directions.
	As it approaches zero the fog tends to scatter light more and more
	in a directional fashion, resulting in halos around light sources.
	*/
	FloatID getLightScatter(){char buffer[4096];sprintf_s (buffer, "%s.lsc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you do not want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	UnsignedintID getMatteOpacityMode(){char buffer[4096];sprintf_s (buffer, "%s.mom",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	FloatID getMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.mog",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Color</b>.  Connect another attribute to this to
	control the color of the volume shader.
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*Out Color red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*Out Color green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*Out Color blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Transparency</b>. Connect another attribute to this to
	control the Shader's transparency.  Higher values (that is,
	brighter colors) make the object more transparent;  darker
	colors make it more opaque.
	*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*Out Transparency red value*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*Out Transparency green value*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*Out Transparency blue value*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Matte Opacity</b>.  Connect another attribute to this
	to control the opacity of the material's matte (alpha) channel.
	*/
	Float3ID getOutMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.omo",mName.c_str());return (const char*)buffer;}
	/*Out Matte Opacity red value*/
	FloatID getOutMatteOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.omo.omor",mName.c_str());return (const char*)buffer;}
	/*Out Matte Opacity green value*/
	FloatID getOutMatteOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.omo.omog",mName.c_str());return (const char*)buffer;}
	/*Out Matte Opacity blue value*/
	FloatID getOutMatteOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.omo.omob",mName.c_str());return (const char*)buffer;}
protected:
	VolumeFog(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMEFOG_H__
