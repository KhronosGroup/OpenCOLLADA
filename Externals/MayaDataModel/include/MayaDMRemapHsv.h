/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REMAPHSV_H__
#define __MayaDM_REMAPHSV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Remap Hsv</b> is a utility node that allows you to take an input
 color value and remap the Hue Saturation and Value balance using three gradients.
<p/>
 The input value is used to select a point along the gradient to use for the output value.
*/
class RemapHsv : public DependNode
{
public:
	/*
	<b>Hue</b> defines a range of values used to remap the input
	hue component to the outColor. The hue component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	struct Hue{
		float hue_Position;
		float hue_FloatValue;
		unsigned int hue_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", hue_Position);
			fprintf_s(file,"%f ", hue_FloatValue);
			fprintf_s(file,"%i", hue_Interp);
		}
	};
	/*
	<b>Saturation</b> defines a range of values used to remap the input
	saturation component to the outColor. The saturation
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	struct Saturation{
		float saturation_Position;
		float saturation_FloatValue;
		unsigned int saturation_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", saturation_Position);
			fprintf_s(file,"%f ", saturation_FloatValue);
			fprintf_s(file,"%i", saturation_Interp);
		}
	};
	/*
	<b>Value</b> defines a range of values used to remap the input
	value, or intensity, component to the outColor. The value
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	struct Value{
		float value_Position;
		float value_FloatValue;
		unsigned int value_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", value_Position);
			fprintf_s(file,"%f ", value_FloatValue);
			fprintf_s(file,"%i", value_Interp);
		}
	};
public:
	RemapHsv(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "remapHsv"){}
	virtual ~RemapHsv(){}
	/*<b>Color</b> is the input color to remap.*/
	void setColor(const float3& cl){fprintf_s(mFile, "setAttr \".cl\" -type \"float3\" ");cl.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Color</b> is the input color to remap.*/
	void setColor(const Float3ID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl\";\n",mName.c_str());}
	/*color red value*/
	void setColorR(float cr){if(cr == 0.5) return; fprintf_s(mFile, "setAttr \".cl.cr\" %f;\n", cr);}
	/*color red value*/
	void setColorR(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cr\";\n",mName.c_str());}
	/*color green value*/
	void setColorG(float cg){if(cg == 0.5) return; fprintf_s(mFile, "setAttr \".cl.cg\" %f;\n", cg);}
	/*color green value*/
	void setColorG(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cg\";\n",mName.c_str());}
	/*color blue value*/
	void setColorB(float cb){if(cb == 0.5) return; fprintf_s(mFile, "setAttr \".cl.cb\" %f;\n", cb);}
	/*color blue value*/
	void setColorB(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cb\";\n",mName.c_str());}
	/*This determines the input value which maps to the left of the gradients.*/
	void setInputMin(float imn){if(imn == 0) return; fprintf_s(mFile, "setAttr \".imn\" %f;\n", imn);}
	/*This determines the input value which maps to the left of the gradients.*/
	void setInputMin(const FloatID& imn){fprintf_s(mFile,"connectAttr \"");imn.write(mFile);fprintf_s(mFile,"\" \"%s.imn\";\n",mName.c_str());}
	/*This determines the input value which maps to the right of the gradients.*/
	void setInputMax(float imx){if(imx == 1) return; fprintf_s(mFile, "setAttr \".imx\" %f;\n", imx);}
	/*This determines the input value which maps to the right of the gradients.*/
	void setInputMax(const FloatID& imx){fprintf_s(mFile,"connectAttr \"");imx.write(mFile);fprintf_s(mFile,"\" \"%s.imx\";\n",mName.c_str());}
	/*This determines the output value which maps to the bottom of the graph or the color black.*/
	void setOutputMin(float omn){if(omn == 0) return; fprintf_s(mFile, "setAttr \".omn\" %f;\n", omn);}
	/*This determines the output value which maps to the bottom of the graph or the color black.*/
	void setOutputMin(const FloatID& omn){fprintf_s(mFile,"connectAttr \"");omn.write(mFile);fprintf_s(mFile,"\" \"%s.omn\";\n",mName.c_str());}
	/*This determines the output value at the graph top or white value.*/
	void setOutputMax(float omx){if(omx == 1) return; fprintf_s(mFile, "setAttr \".omx\" %f;\n", omx);}
	/*This determines the output value at the graph top or white value.*/
	void setOutputMax(const FloatID& omx){fprintf_s(mFile,"connectAttr \"");omx.write(mFile);fprintf_s(mFile,"\" \"%s.omx\";\n",mName.c_str());}
	/*
	<b>Hue</b> defines a range of values used to remap the input
	hue component to the outColor. The hue component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setHue(size_t h_i,const Hue& h){fprintf_s(mFile, "setAttr \".h[%i]\" ",h_i);h.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Hue</b> defines a range of values used to remap the input
	hue component to the outColor. The hue component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setHue(size_t h_i,const HueID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h[%i]\";\n",mName.c_str(),h_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setHue_Position(size_t h_i,float hp){if(hp == 0.0) return; fprintf_s(mFile, "setAttr \".h[%i].hp\" %f;\n", h_i,hp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setHue_Position(size_t h_i,const FloatID& hp){fprintf_s(mFile,"connectAttr \"");hp.write(mFile);fprintf_s(mFile,"\" \"%s.h[%i].hp\";\n",mName.c_str(),h_i);}
	/*Ramp value at the sibling position*/
	void setHue_FloatValue(size_t h_i,float hfv){if(hfv == 0.0) return; fprintf_s(mFile, "setAttr \".h[%i].hfv\" %f;\n", h_i,hfv);}
	/*Ramp value at the sibling position*/
	void setHue_FloatValue(size_t h_i,const FloatID& hfv){fprintf_s(mFile,"connectAttr \"");hfv.write(mFile);fprintf_s(mFile,"\" \"%s.h[%i].hfv\";\n",mName.c_str(),h_i);}
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
	void setHue_Interp(size_t h_i,unsigned int hi){if(hi == 0) return; fprintf_s(mFile, "setAttr \".h[%i].hi\" %i;\n", h_i,hi);}
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
	void setHue_Interp(size_t h_i,const UnsignedintID& hi){fprintf_s(mFile,"connectAttr \"");hi.write(mFile);fprintf_s(mFile,"\" \"%s.h[%i].hi\";\n",mName.c_str(),h_i);}
	/*
	<b>Saturation</b> defines a range of values used to remap the input
	saturation component to the outColor. The saturation
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setSaturation(size_t s_i,const Saturation& s){fprintf_s(mFile, "setAttr \".s[%i]\" ",s_i);s.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Saturation</b> defines a range of values used to remap the input
	saturation component to the outColor. The saturation
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setSaturation(size_t s_i,const SaturationID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s[%i]\";\n",mName.c_str(),s_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setSaturation_Position(size_t s_i,float sp){if(sp == 0.0) return; fprintf_s(mFile, "setAttr \".s[%i].sp\" %f;\n", s_i,sp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setSaturation_Position(size_t s_i,const FloatID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.s[%i].sp\";\n",mName.c_str(),s_i);}
	/*Ramp value at the sibling position*/
	void setSaturation_FloatValue(size_t s_i,float sfv){if(sfv == 0.0) return; fprintf_s(mFile, "setAttr \".s[%i].sfv\" %f;\n", s_i,sfv);}
	/*Ramp value at the sibling position*/
	void setSaturation_FloatValue(size_t s_i,const FloatID& sfv){fprintf_s(mFile,"connectAttr \"");sfv.write(mFile);fprintf_s(mFile,"\" \"%s.s[%i].sfv\";\n",mName.c_str(),s_i);}
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
	void setSaturation_Interp(size_t s_i,unsigned int si){if(si == 0) return; fprintf_s(mFile, "setAttr \".s[%i].si\" %i;\n", s_i,si);}
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
	void setSaturation_Interp(size_t s_i,const UnsignedintID& si){fprintf_s(mFile,"connectAttr \"");si.write(mFile);fprintf_s(mFile,"\" \"%s.s[%i].si\";\n",mName.c_str(),s_i);}
	/*
	<b>Value</b> defines a range of values used to remap the input
	value, or intensity, component to the outColor. The value
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setValue(size_t v_i,const Value& v){fprintf_s(mFile, "setAttr \".v[%i]\" ",v_i);v.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Value</b> defines a range of values used to remap the input
	value, or intensity, component to the outColor. The value
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setValue(size_t v_i,const ValueID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i]\";\n",mName.c_str(),v_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setValue_Position(size_t v_i,float vp){if(vp == 0.0) return; fprintf_s(mFile, "setAttr \".v[%i].vp\" %f;\n", v_i,vp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setValue_Position(size_t v_i,const FloatID& vp){fprintf_s(mFile,"connectAttr \"");vp.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i].vp\";\n",mName.c_str(),v_i);}
	/*Ramp value at the sibling position*/
	void setValue_FloatValue(size_t v_i,float vfv){if(vfv == 0.0) return; fprintf_s(mFile, "setAttr \".v[%i].vfv\" %f;\n", v_i,vfv);}
	/*Ramp value at the sibling position*/
	void setValue_FloatValue(size_t v_i,const FloatID& vfv){fprintf_s(mFile,"connectAttr \"");vfv.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i].vfv\";\n",mName.c_str(),v_i);}
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
	void setValue_Interp(size_t v_i,unsigned int vi){if(vi == 0) return; fprintf_s(mFile, "setAttr \".v[%i].vi\" %i;\n", v_i,vi);}
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
	void setValue_Interp(size_t v_i,const UnsignedintID& vi){fprintf_s(mFile,"connectAttr \"");vi.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i].vi\";\n",mName.c_str(),v_i);}
	/*<b>OutColor</b> is the final remapped color.*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The X component of Output*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*The Y component of Output*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*The Z component of Output*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*<b>Color</b> is the input color to remap.*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.cl",mName.c_str());return (const char*)buffer;}
	/*color red value*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.cl.cr",mName.c_str());return (const char*)buffer;}
	/*color green value*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.cl.cg",mName.c_str());return (const char*)buffer;}
	/*color blue value*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.cl.cb",mName.c_str());return (const char*)buffer;}
	/*This determines the input value which maps to the left of the gradients.*/
	FloatID getInputMin(){char buffer[4096];sprintf_s (buffer, "%s.imn",mName.c_str());return (const char*)buffer;}
	/*This determines the input value which maps to the right of the gradients.*/
	FloatID getInputMax(){char buffer[4096];sprintf_s (buffer, "%s.imx",mName.c_str());return (const char*)buffer;}
	/*This determines the output value which maps to the bottom of the graph or the color black.*/
	FloatID getOutputMin(){char buffer[4096];sprintf_s (buffer, "%s.omn",mName.c_str());return (const char*)buffer;}
	/*This determines the output value at the graph top or white value.*/
	FloatID getOutputMax(){char buffer[4096];sprintf_s (buffer, "%s.omx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Hue</b> defines a range of values used to remap the input
	hue component to the outColor. The hue component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	const HueID& getHue(size_t h_i){char buffer[4096];sprintf_s (buffer, "%s.h[%i]",mName.c_str(),h_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getHue_Position(size_t h_i){char buffer[4096];sprintf_s (buffer, "%s.h[%i].hp",mName.c_str(),h_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getHue_FloatValue(size_t h_i){char buffer[4096];sprintf_s (buffer, "%s.h[%i].hfv",mName.c_str(),h_i);return (const char*)buffer;}
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
	const UnsignedintID& getHue_Interp(size_t h_i){char buffer[4096];sprintf_s (buffer, "%s.h[%i].hi",mName.c_str(),h_i);return (const char*)buffer;}
	/*
	<b>Saturation</b> defines a range of values used to remap the input
	saturation component to the outColor. The saturation
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	const SaturationID& getSaturation(size_t s_i){char buffer[4096];sprintf_s (buffer, "%s.s[%i]",mName.c_str(),s_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getSaturation_Position(size_t s_i){char buffer[4096];sprintf_s (buffer, "%s.s[%i].sp",mName.c_str(),s_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getSaturation_FloatValue(size_t s_i){char buffer[4096];sprintf_s (buffer, "%s.s[%i].sfv",mName.c_str(),s_i);return (const char*)buffer;}
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
	const UnsignedintID& getSaturation_Interp(size_t s_i){char buffer[4096];sprintf_s (buffer, "%s.s[%i].si",mName.c_str(),s_i);return (const char*)buffer;}
	/*
	<b>Value</b> defines a range of values used to remap the input
	value, or intensity, component to the outColor. The value
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	const ValueID& getValue(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i]",mName.c_str(),v_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getValue_Position(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vp",mName.c_str(),v_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getValue_FloatValue(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vfv",mName.c_str(),v_i);return (const char*)buffer;}
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
	const UnsignedintID& getValue_Interp(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vi",mName.c_str(),v_i);return (const char*)buffer;}
	/*<b>OutColor</b> is the final remapped color.*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*The X component of Output*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*The Y component of Output*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*The Z component of Output*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
protected:
	RemapHsv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REMAPHSV_H__
