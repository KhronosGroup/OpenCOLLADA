/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REMAPCOLOR_H__
#define __MayaDM_REMAPCOLOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Remap Color</b> is a utility node that allows you to take an input
 color value and remap the red green and blue balance using three gradients.
<p/>
 The input value is used to select a point along the gradient to use for the output value.
*/
class RemapColor : public DependNode
{
public:
	/*
	<b>Red</b> defines a range of values used to remap the input
	red component to the outColor red value. The red component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	struct Red{
		float red_Position;
		float red_FloatValue;
		unsigned int red_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", red_Position);
			fprintf_s(file,"%f ", red_FloatValue);
			fprintf_s(file,"%i", red_Interp);
		}
	};
	/*
	<b>Green</b> defines a range of values used to remap the input
	green component to the outColor green value. The green component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	struct Green{
		float green_Position;
		float green_FloatValue;
		unsigned int green_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", green_Position);
			fprintf_s(file,"%f ", green_FloatValue);
			fprintf_s(file,"%i", green_Interp);
		}
	};
	/*
	<b>Blue</b> defines a range of values used to remap the input
	blue component to the outColor blue value. The blue component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	struct Blue{
		float blue_Position;
		float blue_FloatValue;
		unsigned int blue_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", blue_Position);
			fprintf_s(file,"%f ", blue_FloatValue);
			fprintf_s(file,"%i", blue_Interp);
		}
	};
public:
	RemapColor(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "remapColor"){}
	virtual ~RemapColor(){}
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
	<b>Red</b> defines a range of values used to remap the input
	red component to the outColor red value. The red component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setRed(size_t r_i,const Red& r){fprintf_s(mFile, "setAttr \".r[%i]\" ",r_i);r.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Red</b> defines a range of values used to remap the input
	red component to the outColor red value. The red component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setRed(size_t r_i,const RedID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i]\";\n",mName.c_str(),r_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setRed_Position(size_t r_i,float rp){if(rp == 0.0) return; fprintf_s(mFile, "setAttr \".r[%i].rp\" %f;\n", r_i,rp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setRed_Position(size_t r_i,const FloatID& rp){fprintf_s(mFile,"connectAttr \"");rp.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i].rp\";\n",mName.c_str(),r_i);}
	/*Ramp value at the sibling position*/
	void setRed_FloatValue(size_t r_i,float rfv){if(rfv == 0.0) return; fprintf_s(mFile, "setAttr \".r[%i].rfv\" %f;\n", r_i,rfv);}
	/*Ramp value at the sibling position*/
	void setRed_FloatValue(size_t r_i,const FloatID& rfv){fprintf_s(mFile,"connectAttr \"");rfv.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i].rfv\";\n",mName.c_str(),r_i);}
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
	void setRed_Interp(size_t r_i,unsigned int ri){if(ri == 0) return; fprintf_s(mFile, "setAttr \".r[%i].ri\" %i;\n", r_i,ri);}
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
	void setRed_Interp(size_t r_i,const UnsignedintID& ri){fprintf_s(mFile,"connectAttr \"");ri.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i].ri\";\n",mName.c_str(),r_i);}
	/*
	<b>Green</b> defines a range of values used to remap the input
	green component to the outColor green value. The green component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setGreen(size_t g_i,const Green& g){fprintf_s(mFile, "setAttr \".g[%i]\" ",g_i);g.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Green</b> defines a range of values used to remap the input
	green component to the outColor green value. The green component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setGreen(size_t g_i,const GreenID& g){fprintf_s(mFile,"connectAttr \"");g.write(mFile);fprintf_s(mFile,"\" \"%s.g[%i]\";\n",mName.c_str(),g_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setGreen_Position(size_t g_i,float gp){if(gp == 0.0) return; fprintf_s(mFile, "setAttr \".g[%i].gp\" %f;\n", g_i,gp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setGreen_Position(size_t g_i,const FloatID& gp){fprintf_s(mFile,"connectAttr \"");gp.write(mFile);fprintf_s(mFile,"\" \"%s.g[%i].gp\";\n",mName.c_str(),g_i);}
	/*Ramp value at the sibling position*/
	void setGreen_FloatValue(size_t g_i,float gfv){if(gfv == 0.0) return; fprintf_s(mFile, "setAttr \".g[%i].gfv\" %f;\n", g_i,gfv);}
	/*Ramp value at the sibling position*/
	void setGreen_FloatValue(size_t g_i,const FloatID& gfv){fprintf_s(mFile,"connectAttr \"");gfv.write(mFile);fprintf_s(mFile,"\" \"%s.g[%i].gfv\";\n",mName.c_str(),g_i);}
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
	void setGreen_Interp(size_t g_i,unsigned int gi){if(gi == 0) return; fprintf_s(mFile, "setAttr \".g[%i].gi\" %i;\n", g_i,gi);}
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
	void setGreen_Interp(size_t g_i,const UnsignedintID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.g[%i].gi\";\n",mName.c_str(),g_i);}
	/*
	<b>Blue</b> defines a range of values used to remap the input
	blue component to the outColor blue value. The blue component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setBlue(size_t b_i,const Blue& b){fprintf_s(mFile, "setAttr \".b[%i]\" ",b_i);b.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Blue</b> defines a range of values used to remap the input
	blue component to the outColor blue value. The blue component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	void setBlue(size_t b_i,const BlueID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b[%i]\";\n",mName.c_str(),b_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setBlue_Position(size_t b_i,float bp){if(bp == 0.0) return; fprintf_s(mFile, "setAttr \".b[%i].bp\" %f;\n", b_i,bp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setBlue_Position(size_t b_i,const FloatID& bp){fprintf_s(mFile,"connectAttr \"");bp.write(mFile);fprintf_s(mFile,"\" \"%s.b[%i].bp\";\n",mName.c_str(),b_i);}
	/*Ramp value at the sibling position*/
	void setBlue_FloatValue(size_t b_i,float bfv){if(bfv == 0.0) return; fprintf_s(mFile, "setAttr \".b[%i].bfv\" %f;\n", b_i,bfv);}
	/*Ramp value at the sibling position*/
	void setBlue_FloatValue(size_t b_i,const FloatID& bfv){fprintf_s(mFile,"connectAttr \"");bfv.write(mFile);fprintf_s(mFile,"\" \"%s.b[%i].bfv\";\n",mName.c_str(),b_i);}
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
	void setBlue_Interp(size_t b_i,unsigned int bi){if(bi == 0) return; fprintf_s(mFile, "setAttr \".b[%i].bi\" %i;\n", b_i,bi);}
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
	void setBlue_Interp(size_t b_i,const UnsignedintID& bi){fprintf_s(mFile,"connectAttr \"");bi.write(mFile);fprintf_s(mFile,"\" \"%s.b[%i].bi\";\n",mName.c_str(),b_i);}
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
	<b>Red</b> defines a range of values used to remap the input
	red component to the outColor red value. The red component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	const RedID& getRed(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i]",mName.c_str(),r_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getRed_Position(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i].rp",mName.c_str(),r_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getRed_FloatValue(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i].rfv",mName.c_str(),r_i);return (const char*)buffer;}
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
	const UnsignedintID& getRed_Interp(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i].ri",mName.c_str(),r_i);return (const char*)buffer;}
	/*
	<b>Green</b> defines a range of values used to remap the input
	green component to the outColor green value. The green component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	const GreenID& getGreen(size_t g_i){char buffer[4096];sprintf_s (buffer, "%s.g[%i]",mName.c_str(),g_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getGreen_Position(size_t g_i){char buffer[4096];sprintf_s (buffer, "%s.g[%i].gp",mName.c_str(),g_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getGreen_FloatValue(size_t g_i){char buffer[4096];sprintf_s (buffer, "%s.g[%i].gfv",mName.c_str(),g_i);return (const char*)buffer;}
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
	const UnsignedintID& getGreen_Interp(size_t g_i){char buffer[4096];sprintf_s (buffer, "%s.g[%i].gi",mName.c_str(),g_i);return (const char*)buffer;}
	/*
	<b>Blue</b> defines a range of values used to remap the input
	blue component to the outColor blue value. The blue component
	from the input color is used as the index in this ramp
	where a value of 0.0 will map to the left while
	1.0 will map to the right.
	*/
	const BlueID& getBlue(size_t b_i){char buffer[4096];sprintf_s (buffer, "%s.b[%i]",mName.c_str(),b_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getBlue_Position(size_t b_i){char buffer[4096];sprintf_s (buffer, "%s.b[%i].bp",mName.c_str(),b_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getBlue_FloatValue(size_t b_i){char buffer[4096];sprintf_s (buffer, "%s.b[%i].bfv",mName.c_str(),b_i);return (const char*)buffer;}
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
	const UnsignedintID& getBlue_Interp(size_t b_i){char buffer[4096];sprintf_s (buffer, "%s.b[%i].bi",mName.c_str(),b_i);return (const char*)buffer;}
	/*<b>OutColor</b> is the final remapped color.*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*The X component of Output*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*The Y component of Output*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*The Z component of Output*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
protected:
	RemapColor(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REMAPCOLOR_H__
