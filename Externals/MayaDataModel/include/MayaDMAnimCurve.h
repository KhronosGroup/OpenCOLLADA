/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMCURVE_H__
#define __MayaDM_ANIMCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node represents an animation curve that can be used
        as input to any simple numeric attribute.  Animation
        curves consist of keyframes and the interpolated spans
        between them; the "setKeyframe" command can be used to
        add new keyframes to a curve.<p/>

        Information stored in this node includes:
        <ul>
        <li> keyframe in- and out-tangent types</li>
        <li> in- and out-tangent positions</li>
        <li> tangent angle- and weight-lock status</li>
        <li> curve pre- and post-infinity types</li>
        </ul>

        To avoid implicit unit conversions, the keyframe times and values
        are attributes of the specific animation curve node required.  The
        types available are based on the input and output attributes of the
        curve node.<p/>

        <center>
        <table border="2">

        <tr>
        <td><b>Name</b></td>
        <td><b>Input Type</b></td>
        <td><b>Output Type</b></td>
        </tr>

        <tr>
        <td>animCurveTL</td>
        <td>time</td>
        <td>distance</td>
        </tr>

        <tr>
        <td>animCurveTA</td>
        <td>time</td>
        <td>angle</td>
        </tr>

        <tr>
        <td>animCurveTT</td>
        <td>time</td>
        <td>time</td>
        </tr>

        <tr>
        <td>animCurveTU</td>
        <td>time</td>
        <td>double</td>
        </tr>

        <tr>
        <td>animCurveUL</td>
        <td>double</td>
        <td>distance</td>
        </tr>

        <tr>
        <td>animCurveUA</td>
        <td>double</td>
        <td>angle</td>
        </tr>

        <tr>
        <td>animCurveUT</td>
        <td>double</td>
        <td>time</td>
        </tr>

        <tr>
        <td>animCurveUU</td>
        <td>double</td>
        <td>double</td>
        </tr>

        </table>
        </center>
*/
class AnimCurve : public DependNode
{
public:
public:
	AnimCurve(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "animCurve"){}
	virtual ~AnimCurve(){}
	/*Function attribute to get the value of the param curve at a point*/
	void setApply(const FunctionID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	Most common tangent type of keyframes in this curve.  Used as
	a performance optimization during file store/retrieve.
	The following are legal values: 1=Fixed, 2=Linear, 3=Flat,
	5=Step, 6=Slow, 7=Fast, 9=Spline, 10=Clamped, 16 = Plateau,
	17 = StepNext
	*/
	void setTangentType(unsigned int tan){if(tan == 4) return; fprintf_s(mFile, "setAttr \".tan\" %i;\n", tan);}
	/*Specifies whether or not the tangents on the animCurve are weighted*/
	void setWeightedTangents(bool wgt){if(wgt == true) return; fprintf_s(mFile, "setAttr \".wgt\" %i;\n", wgt);}
	/*
	True makes the in- and out-tangents move together.
	False makes them move separately.
	*/
	void setKeyTanLocked(size_t ktl_i,bool ktl){if(ktl == true) return; fprintf_s(mFile, "setAttr \".ktl[%i]\" %i;\n", ktl_i,ktl);}
	/*True prevents changes to the tangent weight.  False allows changes.*/
	void setKeyWeightLocked(size_t kwl_i,bool kwl){if(kwl == true) return; fprintf_s(mFile, "setAttr \".kwl[%i]\" %i;\n", kwl_i,kwl);}
	/*The horizontal component of the keyframe in-tangent*/
	void setKeyTanInX(size_t kix_i,double kix){if(kix == 0.0) return; fprintf_s(mFile, "setAttr \".kix[%i]\" %f;\n", kix_i,kix);}
	/*The vertical component of the keyframe in-tangent*/
	void setKeyTanInY(size_t kiy_i,double kiy){if(kiy == 0.0) return; fprintf_s(mFile, "setAttr \".kiy[%i]\" %f;\n", kiy_i,kiy);}
	/*The horizontal component of the keyframe out-tangent*/
	void setKeyTanOutX(size_t kox_i,double kox){if(kox == 0.0) return; fprintf_s(mFile, "setAttr \".kox[%i]\" %f;\n", kox_i,kox);}
	/*The vertical component of the keyframe out-tangent*/
	void setKeyTanOutY(size_t koy_i,double koy){if(koy == 0.0) return; fprintf_s(mFile, "setAttr \".koy[%i]\" %f;\n", koy_i,koy);}
	/*
	The tangent type of the keyframe's in tangent.
	The following are legal values: 1=Fixed, 2=Linear, 3=Flat,
	5=Step, 6=Slow, 7=Fast, 9=Spline, 10=Clamped, 16 = Plateau
	*/
	void setKeyTanInType(size_t kit_i,unsigned int kit){if(kit == 4) return; fprintf_s(mFile, "setAttr \".kit[%i]\" %i;\n", kit_i,kit);}
	/*
	The tangent type of the keyframe's out tangent.
	The following are legal values: 1=Fixed, 2=Linear, 3=Flat,
	5=Step, 6=Slow, 7=Fast, 9=Spline, 10=Clamped, 16 = Plateau,
	17 = StepNext
	*/
	void setKeyTanOutType(size_t kot_i,unsigned int kot){if(kot == 4) return; fprintf_s(mFile, "setAttr \".kot[%i]\" %i;\n", kot_i,kot);}
	/*
	True makes this key act as a breakdown.
	False makes this key a key.
	*/
	void setKeyBreakdown(size_t kbd_i,bool kbd){if(kbd == false) return; fprintf_s(mFile, "setAttr \".kbd[%i]\" %i;\n", kbd_i,kbd);}
	/*
	True causes the tick mark representing a given key to be drawn
	specially in the time-slider using the user-definable
	special tick color.
	False causes the tick mark representing a given key to be drawn
	normally.
	*/
	void setKeyTickDrawSpecial(size_t kyts_i,bool kyts){if(kyts == false) return; fprintf_s(mFile, "setAttr \".kyts[%i]\" %i;\n", kyts_i,kyts);}
	/*
	This attribute specifies how the curve data is interpolated if
	the curve is being utilised for rotation.
	The following are legal values: 1="None" for Unsynchronized Euler angled
	curves, where keyframes on sibling curves are independent. For
	non-rotational curves, this is the only possible setting.
	2="Euler" for synchronized Euler-angled curves where sibling
	curve keyframes are coincident in time sibling curve,
	3="Quaternion" for synchronized quaternion interpolation where
	sibling curve keyframes are coincident and quaternion interpolation
	is performed between keyframes. "None" (1) for non-rotational curves
	as well as for pre-4.0 rotational behaviour.
	*/
	void setRotationInterpolation(unsigned int roti){if(roti == 1) return; fprintf_s(mFile, "setAttr \".roti\" %i;\n", roti);}
	/*
	Controls how the curve is evaluated before the first keyframe.
	The following are legal values: 0=Constant, 1=Linear, 3=Cycle,
	4=Cycle with Offset, 5=Oscillate
	*/
	void setPreInfinity(unsigned int pre){if(pre == 0) return; fprintf_s(mFile, "setAttr \".pre\" %i;\n", pre);}
	/*
	Controls how the curve is evaluated after the last keyframe.
	The following are legal values: 0=Constant, 1=Linear, 3=Cycle,
	4=Cycle with Offset, 5=Oscillate
	*/
	void setPostInfinity(unsigned int pst){if(pst == 0) return; fprintf_s(mFile, "setAttr \".pst\" %i;\n", pst);}
	/*
	An Enum to set the stipple pattern for the sections of the
	anim curve that are specified by the stippleRegion attribute.
	The default is long dotted (--- --- --- ---).
	*/
	void setStipplePattern(unsigned int sp){if(sp == 6) return; fprintf_s(mFile, "setAttr \".sp\" %i;\n", sp);}
	/*
	An Enum to set the stipple pattern for the sections of the
	anim curve that are specified by the stippleRegion attribute.
	The default is long dotted (--- --- --- ---).
	*/
	void setStipplePattern(const UnsignedintID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*
	If the anim curve gets at or below this value, the outStippleRange
	will treat it as a region to stipple.
	*/
	void setOutStippleThreshold(double ot){if(ot == 0.0) return; fprintf_s(mFile, "setAttr \".ot\" %f;\n", ot);}
	/*
	If the anim curve gets at or below this value, the outStippleRange
	will treat it as a region to stipple.
	*/
	void setOutStippleThreshold(const DoubleID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*
	A double array containing pairs of ranges (if time, in seconds)
	of regions when the anim curve is below the stippleThreshold.
	*/
	void setOutStippleRange(const doubleArray& osr){if(osr.size == 0) return; fprintf_s(mFile, "setAttr \".osr\" -type \"doubleArray\" ");osr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	A double array containing pairs of ranges (if time, in seconds)
	of regions when the anim curve is below the stippleThreshold.
	*/
	void setOutStippleRange(const DoubleArrayID& osr){fprintf_s(mFile,"connectAttr \"");osr.write(mFile);fprintf_s(mFile,"\" \"%s.osr\";\n",mName.c_str());}
	/*A double array that contains pairs of ranges to stipple.*/
	void setInStippleRange(const doubleArray& isr){if(isr.size == 0) return; fprintf_s(mFile, "setAttr \".isr\" -type \"doubleArray\" ");isr.write(mFile);fprintf_s(mFile,";\n");}
	/*A double array that contains pairs of ranges to stipple.*/
	void setInStippleRange(const DoubleArrayID& isr){fprintf_s(mFile,"connectAttr \"");isr.write(mFile);fprintf_s(mFile,"\" \"%s.isr\";\n",mName.c_str());}
	/*
	When true, the stippled regions will become unstippled, and the solid
	regions will become stippled. This attribute will only have an effect
	if the inStippleRange attribute is connected.
	*/
	void setStippleReverse(bool sr){if(sr == false) return; fprintf_s(mFile, "setAttr \".sr\" %i;\n", sr);}
	/*
	When true, the stippled regions will become unstippled, and the solid
	regions will become stippled. This attribute will only have an effect
	if the inStippleRange attribute is connected.
	*/
	void setStippleReverse(const BoolID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	Specifies the display style for this curve. If false, Maya's default
	color scheme is used for drawing the curve. If true, the value of the
	curveColor attribute is used for drawing.
	*/
	void setUseCurveColor(bool ucc){if(ucc == false) return; fprintf_s(mFile, "setAttr \".ucc\" %i;\n", ucc);}
	/*
	Specifies the display style for this curve. If false, Maya's default
	color scheme is used for drawing the curve. If true, the value of the
	curveColor attribute is used for drawing.
	*/
	void setUseCurveColor(const BoolID& ucc){fprintf_s(mFile,"connectAttr \"");ucc.write(mFile);fprintf_s(mFile,"\" \"%s.ucc\";\n",mName.c_str());}
	/*
	If the useCurveColor attribute is true, then the curveColor
	attribute provides the color used to draw curve segments when
	the curve is inactive (i.e. not selected). This setting is
	only visible in the graph editor.
	*/
	void setCurveColor(const float3& cc){fprintf_s(mFile, "setAttr \".cc\" -type \"float3\" ");cc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	If the useCurveColor attribute is true, then the curveColor
	attribute provides the color used to draw curve segments when
	the curve is inactive (i.e. not selected). This setting is
	only visible in the graph editor.
	*/
	void setCurveColor(const Float3ID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.cc\";\n",mName.c_str());}
	/*Curve color red value (used for curve segments of a non-active curve).*/
	void setCurveColorR(float ccr){if(ccr == 0.0) return; fprintf_s(mFile, "setAttr \".cc.ccr\" %f;\n", ccr);}
	/*Curve color red value (used for curve segments of a non-active curve).*/
	void setCurveColorR(const FloatID& ccr){fprintf_s(mFile,"connectAttr \"");ccr.write(mFile);fprintf_s(mFile,"\" \"%s.cc.ccr\";\n",mName.c_str());}
	/*Curve color green value (used for curve segments of a non-active curve).*/
	void setCurveColorG(float ccg){if(ccg == 0.0) return; fprintf_s(mFile, "setAttr \".cc.ccg\" %f;\n", ccg);}
	/*Curve color green value (used for curve segments of a non-active curve).*/
	void setCurveColorG(const FloatID& ccg){fprintf_s(mFile,"connectAttr \"");ccg.write(mFile);fprintf_s(mFile,"\" \"%s.cc.ccg\";\n",mName.c_str());}
	/*Curve color blue value (used for curve segments of a non-active curve).*/
	void setCurveColorB(float ccb){if(ccb == 0.0) return; fprintf_s(mFile, "setAttr \".cc.ccb\" %f;\n", ccb);}
	/*Curve color blue value (used for curve segments of a non-active curve).*/
	void setCurveColorB(const FloatID& ccb){fprintf_s(mFile,"connectAttr \"");ccb.write(mFile);fprintf_s(mFile,"\" \"%s.cc.ccb\";\n",mName.c_str());}
	/*Function attribute to get the value of the param curve at a point*/
	FunctionID getApply(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	An Enum to set the stipple pattern for the sections of the
	anim curve that are specified by the stippleRegion attribute.
	The default is long dotted (--- --- --- ---).
	*/
	UnsignedintID getStipplePattern(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*
	If the anim curve gets at or below this value, the outStippleRange
	will treat it as a region to stipple.
	*/
	DoubleID getOutStippleThreshold(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*
	A double array containing pairs of ranges (if time, in seconds)
	of regions when the anim curve is below the stippleThreshold.
	*/
	DoubleArrayID getOutStippleRange(){char buffer[4096];sprintf_s (buffer, "%s.osr",mName.c_str());return (const char*)buffer;}
	/*A double array that contains pairs of ranges to stipple.*/
	DoubleArrayID getInStippleRange(){char buffer[4096];sprintf_s (buffer, "%s.isr",mName.c_str());return (const char*)buffer;}
	/*
	When true, the stippled regions will become unstippled, and the solid
	regions will become stippled. This attribute will only have an effect
	if the inStippleRange attribute is connected.
	*/
	BoolID getStippleReverse(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the display style for this curve. If false, Maya's default
	color scheme is used for drawing the curve. If true, the value of the
	curveColor attribute is used for drawing.
	*/
	BoolID getUseCurveColor(){char buffer[4096];sprintf_s (buffer, "%s.ucc",mName.c_str());return (const char*)buffer;}
	/*
	If the useCurveColor attribute is true, then the curveColor
	attribute provides the color used to draw curve segments when
	the curve is inactive (i.e. not selected). This setting is
	only visible in the graph editor.
	*/
	Float3ID getCurveColor(){char buffer[4096];sprintf_s (buffer, "%s.cc",mName.c_str());return (const char*)buffer;}
	/*Curve color red value (used for curve segments of a non-active curve).*/
	FloatID getCurveColorR(){char buffer[4096];sprintf_s (buffer, "%s.cc.ccr",mName.c_str());return (const char*)buffer;}
	/*Curve color green value (used for curve segments of a non-active curve).*/
	FloatID getCurveColorG(){char buffer[4096];sprintf_s (buffer, "%s.cc.ccg",mName.c_str());return (const char*)buffer;}
	/*Curve color blue value (used for curve segments of a non-active curve).*/
	FloatID getCurveColorB(){char buffer[4096];sprintf_s (buffer, "%s.cc.ccb",mName.c_str());return (const char*)buffer;}
protected:
	AnimCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCURVE_H__
