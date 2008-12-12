/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCOLORMOD_H__
#define __MayaDM_POLYCOLORMOD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
<p><pre> Color modification node
</pre></p>
*/
class PolyColorMod : public PolyModifier
{
public:
	/*<b>Red Scale</b> affects scaling of the red color channel.*/
	struct RedScale{
		float redScale_Position;
		float redScale_FloatValue;
		unsigned int redScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", redScale_Position);
			fprintf_s(file,"%f ", redScale_FloatValue);
			fprintf_s(file,"%i", redScale_Interp);
		}
	};
	/*<b>Green Scale</b> affects scaling of the green color channel.*/
	struct GreenScale{
		float greenScale_Position;
		float greenScale_FloatValue;
		unsigned int greenScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", greenScale_Position);
			fprintf_s(file,"%f ", greenScale_FloatValue);
			fprintf_s(file,"%i", greenScale_Interp);
		}
	};
	/*<b>Blue Scale</b> affects scaling of the blue color channel.*/
	struct BlueScale{
		float blueScale_Position;
		float blueScale_FloatValue;
		unsigned int blueScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", blueScale_Position);
			fprintf_s(file,"%f ", blueScale_FloatValue);
			fprintf_s(file,"%i", blueScale_Interp);
		}
	};
	/*<b>Alpha Scale</b> affects scaling of the alpah channel.*/
	struct AlphaScale{
		float alphaScale_Position;
		float alphaScale_FloatValue;
		unsigned int alphaScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", alphaScale_Position);
			fprintf_s(file,"%f ", alphaScale_FloatValue);
			fprintf_s(file,"%i", alphaScale_Interp);
		}
	};
	/*<b>Intensity Scale</b>  affects scaling of the total color intensity.*/
	struct IntensityScale{
		float intensityScale_Position;
		float intensityScale_FloatValue;
		unsigned int intensityScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", intensityScale_Position);
			fprintf_s(file,"%f ", intensityScale_FloatValue);
			fprintf_s(file,"%i", intensityScale_Interp);
		}
	};
public:
	PolyColorMod(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyColorMod"){}
	virtual ~PolyColorMod(){}
	/*Name of the color set to copy from*/
	void setBaseColorName(const string& bcn){if(bcn == "NULL") return; fprintf_s(mFile, "setAttr \".bcn\" -type \"string\" ");bcn.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the color set to copy from*/
	void setBaseColorName(const StringID& bcn){fprintf_s(mFile,"connectAttr \"");bcn.write(mFile);fprintf_s(mFile,"\" \"%s.bcn\";\n",mName.c_str());}
	/*<b>Red Scale</b> affects scaling of the red color channel.*/
	void setRedScale(size_t r_i,const RedScale& r){fprintf_s(mFile, "setAttr \".r[%i]\" ",r_i);r.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Red Scale</b> affects scaling of the red color channel.*/
	void setRedScale(size_t r_i,const RedScaleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i]\";\n",mName.c_str(),r_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setRedScale_Position(size_t r_i,float rp){if(rp == 0.0) return; fprintf_s(mFile, "setAttr \".r[%i].rp\" %f;\n", r_i,rp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setRedScale_Position(size_t r_i,const FloatID& rp){fprintf_s(mFile,"connectAttr \"");rp.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i].rp\";\n",mName.c_str(),r_i);}
	/*Ramp value at the sibling position*/
	void setRedScale_FloatValue(size_t r_i,float rfv){if(rfv == 0.0) return; fprintf_s(mFile, "setAttr \".r[%i].rfv\" %f;\n", r_i,rfv);}
	/*Ramp value at the sibling position*/
	void setRedScale_FloatValue(size_t r_i,const FloatID& rfv){fprintf_s(mFile,"connectAttr \"");rfv.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i].rfv\";\n",mName.c_str(),r_i);}
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
	void setRedScale_Interp(size_t r_i,unsigned int ri){if(ri == 0) return; fprintf_s(mFile, "setAttr \".r[%i].ri\" %i;\n", r_i,ri);}
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
	void setRedScale_Interp(size_t r_i,const UnsignedintID& ri){fprintf_s(mFile,"connectAttr \"");ri.write(mFile);fprintf_s(mFile,"\" \"%s.r[%i].ri\";\n",mName.c_str(),r_i);}
	/*<b>Green Scale</b> affects scaling of the green color channel.*/
	void setGreenScale(size_t g_i,const GreenScale& g){fprintf_s(mFile, "setAttr \".g[%i]\" ",g_i);g.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Green Scale</b> affects scaling of the green color channel.*/
	void setGreenScale(size_t g_i,const GreenScaleID& g){fprintf_s(mFile,"connectAttr \"");g.write(mFile);fprintf_s(mFile,"\" \"%s.g[%i]\";\n",mName.c_str(),g_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setGreenScale_Position(size_t g_i,float gp){if(gp == 0.0) return; fprintf_s(mFile, "setAttr \".g[%i].gp\" %f;\n", g_i,gp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setGreenScale_Position(size_t g_i,const FloatID& gp){fprintf_s(mFile,"connectAttr \"");gp.write(mFile);fprintf_s(mFile,"\" \"%s.g[%i].gp\";\n",mName.c_str(),g_i);}
	/*Ramp value at the sibling position*/
	void setGreenScale_FloatValue(size_t g_i,float gfv){if(gfv == 0.0) return; fprintf_s(mFile, "setAttr \".g[%i].gfv\" %f;\n", g_i,gfv);}
	/*Ramp value at the sibling position*/
	void setGreenScale_FloatValue(size_t g_i,const FloatID& gfv){fprintf_s(mFile,"connectAttr \"");gfv.write(mFile);fprintf_s(mFile,"\" \"%s.g[%i].gfv\";\n",mName.c_str(),g_i);}
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
	void setGreenScale_Interp(size_t g_i,unsigned int gi){if(gi == 0) return; fprintf_s(mFile, "setAttr \".g[%i].gi\" %i;\n", g_i,gi);}
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
	void setGreenScale_Interp(size_t g_i,const UnsignedintID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.g[%i].gi\";\n",mName.c_str(),g_i);}
	/*<b>Blue Scale</b> affects scaling of the blue color channel.*/
	void setBlueScale(size_t b_i,const BlueScale& b){fprintf_s(mFile, "setAttr \".b[%i]\" ",b_i);b.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Blue Scale</b> affects scaling of the blue color channel.*/
	void setBlueScale(size_t b_i,const BlueScaleID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b[%i]\";\n",mName.c_str(),b_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setBlueScale_Position(size_t b_i,float bp){if(bp == 0.0) return; fprintf_s(mFile, "setAttr \".b[%i].bp\" %f;\n", b_i,bp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setBlueScale_Position(size_t b_i,const FloatID& bp){fprintf_s(mFile,"connectAttr \"");bp.write(mFile);fprintf_s(mFile,"\" \"%s.b[%i].bp\";\n",mName.c_str(),b_i);}
	/*Ramp value at the sibling position*/
	void setBlueScale_FloatValue(size_t b_i,float bfv){if(bfv == 0.0) return; fprintf_s(mFile, "setAttr \".b[%i].bfv\" %f;\n", b_i,bfv);}
	/*Ramp value at the sibling position*/
	void setBlueScale_FloatValue(size_t b_i,const FloatID& bfv){fprintf_s(mFile,"connectAttr \"");bfv.write(mFile);fprintf_s(mFile,"\" \"%s.b[%i].bfv\";\n",mName.c_str(),b_i);}
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
	void setBlueScale_Interp(size_t b_i,unsigned int bi){if(bi == 0) return; fprintf_s(mFile, "setAttr \".b[%i].bi\" %i;\n", b_i,bi);}
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
	void setBlueScale_Interp(size_t b_i,const UnsignedintID& bi){fprintf_s(mFile,"connectAttr \"");bi.write(mFile);fprintf_s(mFile,"\" \"%s.b[%i].bi\";\n",mName.c_str(),b_i);}
	/*<b>Alpha Scale</b> affects scaling of the alpah channel.*/
	void setAlphaScale(size_t a_i,const AlphaScale& a){fprintf_s(mFile, "setAttr \".a[%i]\" ",a_i);a.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Alpha Scale</b> affects scaling of the alpah channel.*/
	void setAlphaScale(size_t a_i,const AlphaScaleID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a[%i]\";\n",mName.c_str(),a_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setAlphaScale_Position(size_t a_i,float ap){if(ap == 0.0) return; fprintf_s(mFile, "setAttr \".a[%i].ap\" %f;\n", a_i,ap);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setAlphaScale_Position(size_t a_i,const FloatID& ap){fprintf_s(mFile,"connectAttr \"");ap.write(mFile);fprintf_s(mFile,"\" \"%s.a[%i].ap\";\n",mName.c_str(),a_i);}
	/*Ramp value at the sibling position*/
	void setAlphaScale_FloatValue(size_t a_i,float afv){if(afv == 0.0) return; fprintf_s(mFile, "setAttr \".a[%i].afv\" %f;\n", a_i,afv);}
	/*Ramp value at the sibling position*/
	void setAlphaScale_FloatValue(size_t a_i,const FloatID& afv){fprintf_s(mFile,"connectAttr \"");afv.write(mFile);fprintf_s(mFile,"\" \"%s.a[%i].afv\";\n",mName.c_str(),a_i);}
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
	void setAlphaScale_Interp(size_t a_i,unsigned int ai){if(ai == 0) return; fprintf_s(mFile, "setAttr \".a[%i].ai\" %i;\n", a_i,ai);}
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
	void setAlphaScale_Interp(size_t a_i,const UnsignedintID& ai){fprintf_s(mFile,"connectAttr \"");ai.write(mFile);fprintf_s(mFile,"\" \"%s.a[%i].ai\";\n",mName.c_str(),a_i);}
	/*<b>Intensity Scale</b>  affects scaling of the total color intensity.*/
	void setIntensityScale(size_t n_i,const IntensityScale& n){fprintf_s(mFile, "setAttr \".n[%i]\" ",n_i);n.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Intensity Scale</b>  affects scaling of the total color intensity.*/
	void setIntensityScale(size_t n_i,const IntensityScaleID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n[%i]\";\n",mName.c_str(),n_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setIntensityScale_Position(size_t n_i,float np){if(np == 0.0) return; fprintf_s(mFile, "setAttr \".n[%i].np\" %f;\n", n_i,np);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setIntensityScale_Position(size_t n_i,const FloatID& np){fprintf_s(mFile,"connectAttr \"");np.write(mFile);fprintf_s(mFile,"\" \"%s.n[%i].np\";\n",mName.c_str(),n_i);}
	/*Ramp value at the sibling position*/
	void setIntensityScale_FloatValue(size_t n_i,float nfv){if(nfv == 0.0) return; fprintf_s(mFile, "setAttr \".n[%i].nfv\" %f;\n", n_i,nfv);}
	/*Ramp value at the sibling position*/
	void setIntensityScale_FloatValue(size_t n_i,const FloatID& nfv){fprintf_s(mFile,"connectAttr \"");nfv.write(mFile);fprintf_s(mFile,"\" \"%s.n[%i].nfv\";\n",mName.c_str(),n_i);}
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
	void setIntensityScale_Interp(size_t n_i,unsigned int ni){if(ni == 0) return; fprintf_s(mFile, "setAttr \".n[%i].ni\" %i;\n", n_i,ni);}
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
	void setIntensityScale_Interp(size_t n_i,const UnsignedintID& ni){fprintf_s(mFile,"connectAttr \"");ni.write(mFile);fprintf_s(mFile,"\" \"%s.n[%i].ni\";\n",mName.c_str(),n_i);}
	/*<b>Hue</b>  rotates hue value of the final color.*/
	void setHuev(float h){if(h == 0.0) return; fprintf_s(mFile, "setAttr \".h\" %f;\n", h);}
	/*<b>Hue</b>  rotates hue value of the final color.*/
	void setHuev(const FloatID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*<b>Sat</b> scales the staturation of the final color.*/
	void setSatv(float s){if(s == 1.0) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*<b>Sat</b> scales the staturation of the final color.*/
	void setSatv(const FloatID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*<b>Value</b> scales the final color value.*/
	void setValue(float v){if(v == 1.0) return; fprintf_s(mFile, "setAttr \".v\" %f;\n", v);}
	/*<b>Value</b> scales the final color value.*/
	void setValue(const FloatID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*Name of the color set to copy from*/
	StringID getBaseColorName(){char buffer[4096];sprintf_s (buffer, "%s.bcn",mName.c_str());return (const char*)buffer;}
	/*<b>Red Scale</b> affects scaling of the red color channel.*/
	const RedScaleID& getRedScale(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i]",mName.c_str(),r_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getRedScale_Position(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i].rp",mName.c_str(),r_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getRedScale_FloatValue(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i].rfv",mName.c_str(),r_i);return (const char*)buffer;}
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
	const UnsignedintID& getRedScale_Interp(size_t r_i){char buffer[4096];sprintf_s (buffer, "%s.r[%i].ri",mName.c_str(),r_i);return (const char*)buffer;}
	/*<b>Green Scale</b> affects scaling of the green color channel.*/
	const GreenScaleID& getGreenScale(size_t g_i){char buffer[4096];sprintf_s (buffer, "%s.g[%i]",mName.c_str(),g_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getGreenScale_Position(size_t g_i){char buffer[4096];sprintf_s (buffer, "%s.g[%i].gp",mName.c_str(),g_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getGreenScale_FloatValue(size_t g_i){char buffer[4096];sprintf_s (buffer, "%s.g[%i].gfv",mName.c_str(),g_i);return (const char*)buffer;}
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
	const UnsignedintID& getGreenScale_Interp(size_t g_i){char buffer[4096];sprintf_s (buffer, "%s.g[%i].gi",mName.c_str(),g_i);return (const char*)buffer;}
	/*<b>Blue Scale</b> affects scaling of the blue color channel.*/
	const BlueScaleID& getBlueScale(size_t b_i){char buffer[4096];sprintf_s (buffer, "%s.b[%i]",mName.c_str(),b_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getBlueScale_Position(size_t b_i){char buffer[4096];sprintf_s (buffer, "%s.b[%i].bp",mName.c_str(),b_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getBlueScale_FloatValue(size_t b_i){char buffer[4096];sprintf_s (buffer, "%s.b[%i].bfv",mName.c_str(),b_i);return (const char*)buffer;}
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
	const UnsignedintID& getBlueScale_Interp(size_t b_i){char buffer[4096];sprintf_s (buffer, "%s.b[%i].bi",mName.c_str(),b_i);return (const char*)buffer;}
	/*<b>Alpha Scale</b> affects scaling of the alpah channel.*/
	const AlphaScaleID& getAlphaScale(size_t a_i){char buffer[4096];sprintf_s (buffer, "%s.a[%i]",mName.c_str(),a_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getAlphaScale_Position(size_t a_i){char buffer[4096];sprintf_s (buffer, "%s.a[%i].ap",mName.c_str(),a_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getAlphaScale_FloatValue(size_t a_i){char buffer[4096];sprintf_s (buffer, "%s.a[%i].afv",mName.c_str(),a_i);return (const char*)buffer;}
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
	const UnsignedintID& getAlphaScale_Interp(size_t a_i){char buffer[4096];sprintf_s (buffer, "%s.a[%i].ai",mName.c_str(),a_i);return (const char*)buffer;}
	/*<b>Intensity Scale</b>  affects scaling of the total color intensity.*/
	const IntensityScaleID& getIntensityScale(size_t n_i){char buffer[4096];sprintf_s (buffer, "%s.n[%i]",mName.c_str(),n_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getIntensityScale_Position(size_t n_i){char buffer[4096];sprintf_s (buffer, "%s.n[%i].np",mName.c_str(),n_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getIntensityScale_FloatValue(size_t n_i){char buffer[4096];sprintf_s (buffer, "%s.n[%i].nfv",mName.c_str(),n_i);return (const char*)buffer;}
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
	const UnsignedintID& getIntensityScale_Interp(size_t n_i){char buffer[4096];sprintf_s (buffer, "%s.n[%i].ni",mName.c_str(),n_i);return (const char*)buffer;}
	/*<b>Hue</b>  rotates hue value of the final color.*/
	FloatID getHuev(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*<b>Sat</b> scales the staturation of the final color.*/
	FloatID getSatv(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*<b>Value</b> scales the final color value.*/
	FloatID getValue(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
protected:
	PolyColorMod(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOLORMOD_H__
