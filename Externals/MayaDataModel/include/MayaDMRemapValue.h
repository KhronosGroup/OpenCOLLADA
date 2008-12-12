/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REMAPVALUE_H__
#define __MayaDM_REMAPVALUE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Remap Value</b> is a utility node that allows you to take an input
 scalar value and remap its value using a gradient. One can remap this to a new output
 scalar value and/or color.
<p/>
 The input value is used to select a point along the gradient to use for the output value.
 The value specified by the Min attribute determines the input value that indexes the far left of
 the ramp while the Max attribute determines the value at far right.
<p/>
 The outColor is determined by the color gradient and the outValue by the value gradient. If one only uses
 the outValue, for example, then the color gradient is ignored.
*/
class RemapValue : public DependNode
{
public:
	/*
	<b>Value</b> defines a range of values used to remap the input value to the outValue.
	The <b>Input Value</b> parameter, along with the min and max attributes determine where to
	index into this gradient.
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
	/*
	<b>Color</b> defines a range of color values used to remap the input value to the outColor.
	The <b>Input Value</b> parameter, along with the min and max attributes determine where to
	index into this ramp.
	*/
	struct Color{
		float color_Position;
		float3 color_Color;
		unsigned int color_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", color_Position);
			color_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", color_Interp);
		}
	};
public:
	RemapValue(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "remapValue"){}
	virtual ~RemapValue(){}
	/*<b>InputValue</b> is the raw input connection to remap.*/
	void setInputValue(float i){if(i == 0.0) return; fprintf_s(mFile, "setAttr \".i\" %f;\n", i);}
	/*<b>InputValue</b> is the raw input connection to remap.*/
	void setInputValue(const FloatID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
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
	<b>Value</b> defines a range of values used to remap the input value to the outValue.
	The <b>Input Value</b> parameter, along with the min and max attributes determine where to
	index into this gradient.
	*/
	void setValue(size_t vl_i,const Value& vl){fprintf_s(mFile, "setAttr \".vl[%i]\" ",vl_i);vl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Value</b> defines a range of values used to remap the input value to the outValue.
	The <b>Input Value</b> parameter, along with the min and max attributes determine where to
	index into this gradient.
	*/
	void setValue(size_t vl_i,const ValueID& vl){fprintf_s(mFile,"connectAttr \"");vl.write(mFile);fprintf_s(mFile,"\" \"%s.vl[%i]\";\n",mName.c_str(),vl_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setValue_Position(size_t vl_i,float vlp){if(vlp == 0.0) return; fprintf_s(mFile, "setAttr \".vl[%i].vlp\" %f;\n", vl_i,vlp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setValue_Position(size_t vl_i,const FloatID& vlp){fprintf_s(mFile,"connectAttr \"");vlp.write(mFile);fprintf_s(mFile,"\" \"%s.vl[%i].vlp\";\n",mName.c_str(),vl_i);}
	/*Ramp value at the sibling position*/
	void setValue_FloatValue(size_t vl_i,float vlfv){if(vlfv == 0.0) return; fprintf_s(mFile, "setAttr \".vl[%i].vlfv\" %f;\n", vl_i,vlfv);}
	/*Ramp value at the sibling position*/
	void setValue_FloatValue(size_t vl_i,const FloatID& vlfv){fprintf_s(mFile,"connectAttr \"");vlfv.write(mFile);fprintf_s(mFile,"\" \"%s.vl[%i].vlfv\";\n",mName.c_str(),vl_i);}
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
	void setValue_Interp(size_t vl_i,unsigned int vli){if(vli == 0) return; fprintf_s(mFile, "setAttr \".vl[%i].vli\" %i;\n", vl_i,vli);}
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
	void setValue_Interp(size_t vl_i,const UnsignedintID& vli){fprintf_s(mFile,"connectAttr \"");vli.write(mFile);fprintf_s(mFile,"\" \"%s.vl[%i].vli\";\n",mName.c_str(),vl_i);}
	/*
	<b>Color</b> defines a range of color values used to remap the input value to the outColor.
	The <b>Input Value</b> parameter, along with the min and max attributes determine where to
	index into this ramp.
	*/
	void setColor(size_t cl_i,const Color& cl){fprintf_s(mFile, "setAttr \".cl[%i]\" ",cl_i);cl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color</b> defines a range of color values used to remap the input value to the outColor.
	The <b>Input Value</b> parameter, along with the min and max attributes determine where to
	index into this ramp.
	*/
	void setColor(size_t cl_i,const ColorID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i]\";\n",mName.c_str(),cl_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColor_Position(size_t cl_i,float clp){if(clp == 0.0) return; fprintf_s(mFile, "setAttr \".cl[%i].clp\" %f;\n", cl_i,clp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setColor_Position(size_t cl_i,const FloatID& clp){fprintf_s(mFile,"connectAttr \"");clp.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clp\";\n",mName.c_str(),cl_i);}
	/*Ramp color at the sibling position*/
	void setColor_Color(size_t cl_i,const float3& clc){fprintf_s(mFile, "setAttr \".cl[%i].clc\" -type \"float3\" ",cl_i);clc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setColor_Color(size_t cl_i,const Float3ID& clc){fprintf_s(mFile,"connectAttr \"");clc.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clc\";\n",mName.c_str(),cl_i);}
	/*Ramp red channel value at the sibling position*/
	void setColor_ColorR(size_t cl_i,float clcr){if(clcr == 0.0) return; fprintf_s(mFile, "setAttr \".cl[%i].clc.clcr\" %f;\n", cl_i,clcr);}
	/*Ramp red channel value at the sibling position*/
	void setColor_ColorR(size_t cl_i,const FloatID& clcr){fprintf_s(mFile,"connectAttr \"");clcr.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clc.clcr\";\n",mName.c_str(),cl_i);}
	/*Ramp green channel value at the sibling position*/
	void setColor_ColorG(size_t cl_i,float clcg){if(clcg == 0.0) return; fprintf_s(mFile, "setAttr \".cl[%i].clc.clcg\" %f;\n", cl_i,clcg);}
	/*Ramp green channel value at the sibling position*/
	void setColor_ColorG(size_t cl_i,const FloatID& clcg){fprintf_s(mFile,"connectAttr \"");clcg.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clc.clcg\";\n",mName.c_str(),cl_i);}
	/*Ramp blue channel value at the sibling position*/
	void setColor_ColorB(size_t cl_i,float clcb){if(clcb == 0.0) return; fprintf_s(mFile, "setAttr \".cl[%i].clc.clcb\" %f;\n", cl_i,clcb);}
	/*Ramp blue channel value at the sibling position*/
	void setColor_ColorB(size_t cl_i,const FloatID& clcb){fprintf_s(mFile,"connectAttr \"");clcb.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].clc.clcb\";\n",mName.c_str(),cl_i);}
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
	void setColor_Interp(size_t cl_i,unsigned int cli){if(cli == 0) return; fprintf_s(mFile, "setAttr \".cl[%i].cli\" %i;\n", cl_i,cli);}
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
	void setColor_Interp(size_t cl_i,const UnsignedintID& cli){fprintf_s(mFile,"connectAttr \"");cli.write(mFile);fprintf_s(mFile,"\" \"%s.cl[%i].cli\";\n",mName.c_str(),cl_i);}
	/*<b>OutValue</b> is the final remapped value.*/
	void setOutValue(const FloatID& ov){fprintf_s(mFile,"connectAttr \"");ov.write(mFile);fprintf_s(mFile,"\" \"%s.ov\";\n",mName.c_str());}
	/*<b>OutColor</b> is the final remapped color.*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The X component of Output*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*The Y component of Output*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*The Z component of Output*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*<b>InputValue</b> is the raw input connection to remap.*/
	FloatID getInputValue(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*This determines the input value which maps to the left of the gradients.*/
	FloatID getInputMin(){char buffer[4096];sprintf_s (buffer, "%s.imn",mName.c_str());return (const char*)buffer;}
	/*This determines the input value which maps to the right of the gradients.*/
	FloatID getInputMax(){char buffer[4096];sprintf_s (buffer, "%s.imx",mName.c_str());return (const char*)buffer;}
	/*This determines the output value which maps to the bottom of the graph or the color black.*/
	FloatID getOutputMin(){char buffer[4096];sprintf_s (buffer, "%s.omn",mName.c_str());return (const char*)buffer;}
	/*This determines the output value at the graph top or white value.*/
	FloatID getOutputMax(){char buffer[4096];sprintf_s (buffer, "%s.omx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Value</b> defines a range of values used to remap the input value to the outValue.
	The <b>Input Value</b> parameter, along with the min and max attributes determine where to
	index into this gradient.
	*/
	const ValueID& getValue(size_t vl_i){char buffer[4096];sprintf_s (buffer, "%s.vl[%i]",mName.c_str(),vl_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getValue_Position(size_t vl_i){char buffer[4096];sprintf_s (buffer, "%s.vl[%i].vlp",mName.c_str(),vl_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getValue_FloatValue(size_t vl_i){char buffer[4096];sprintf_s (buffer, "%s.vl[%i].vlfv",mName.c_str(),vl_i);return (const char*)buffer;}
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
	const UnsignedintID& getValue_Interp(size_t vl_i){char buffer[4096];sprintf_s (buffer, "%s.vl[%i].vli",mName.c_str(),vl_i);return (const char*)buffer;}
	/*
	<b>Color</b> defines a range of color values used to remap the input value to the outColor.
	The <b>Input Value</b> parameter, along with the min and max attributes determine where to
	index into this ramp.
	*/
	const ColorID& getColor(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i]",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getColor_Position(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clp",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getColor_Color(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clc",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getColor_ColorR(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clc.clcr",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getColor_ColorG(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clc.clcg",mName.c_str(),cl_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getColor_ColorB(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].clc.clcb",mName.c_str(),cl_i);return (const char*)buffer;}
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
	const UnsignedintID& getColor_Interp(size_t cl_i){char buffer[4096];sprintf_s (buffer, "%s.cl[%i].cli",mName.c_str(),cl_i);return (const char*)buffer;}
	/*<b>OutValue</b> is the final remapped value.*/
	FloatID getOutValue(){char buffer[4096];sprintf_s (buffer, "%s.ov",mName.c_str());return (const char*)buffer;}
	/*<b>OutColor</b> is the final remapped color.*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*The X component of Output*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*The Y component of Output*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*The Z component of Output*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
protected:
	RemapValue(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REMAPVALUE_H__
