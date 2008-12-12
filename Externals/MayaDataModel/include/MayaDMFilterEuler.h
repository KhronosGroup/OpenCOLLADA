/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTEREULER_H__
#define __MayaDM_FILTEREULER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFilter.h"
namespace MayaDM
{
/*
This node implements an Euler angle "demangler" filter
 used by the applyTake command to process recorded motion capture data.
 The attributes of the node are settings which affect the
 operation of the filter as it is invoked by applyTake.  These settings
 are preserved when the scene file is saved.

 <p/>The overall operation of the filter is controlled by two
 enumerated attributes -- smooth and nearestTo.

 <p/>Enumerated values for attribute smooth, specifying how the
        "best" Euler solution is chosen:

        <table border="1">
                <tr><td>0</td>
                        <td> No smoothing</td></tr>
                <tr><td>1</td>
                        <td> Bound to +/-pi (+/-180 deg)</td></tr>
                <tr><td>2</td>
                        <td> Nearest cut to (within pi or 180 deg of) nearestTo</td></tr>
                <tr><td>3</td>
                        <td> Nearest Euler angle solution to nearestTo</td></tr>
        </table>

 <p/>Enumerated values for attribute nearestTo,
        only used if smooth is 2 or 3,
        specifies that the filter selects the cut or
        solution which is nearest to:

        <table border="1">
                <tr><td>0</td><td> Zero</td></tr>
                <tr><td>1</td><td> Initial Value</td></tr>
                <tr><td>2</td><td> Previous Value</td></tr>
        </table>

        <h3>Notes</h3>
  Since the base class inputs (comprising the input and output
  data and timestamp values) to this node are unconnectable, this node
        cannot be used in a traditional dependency graph sense.
*/
class FilterEuler : public Filter
{
public:
public:
	FilterEuler(FILE* file,const std::string& name,const std::string& parent=""):Filter(file, name, parent, "filterEuler"){}
	virtual ~FilterEuler(){}
	/*
	The smoothing/demangling operation to use.
	See the table above for the enumeration of
	the values and their effects.
	*/
	void setSmooth(unsigned int s){if(s == 3) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*
	The smoothing/demangling operation to use.
	See the table above for the enumeration of
	the values and their effects.
	*/
	void setSmooth(const UnsignedintID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	The value to which the cut or solution should be nearest.
	See the table above for the enumeration of
	the values and their effects.
	*/
	void setNearestTo(unsigned int nt){if(nt == 2) return; fprintf_s(mFile, "setAttr \".nt\" %i;\n", nt);}
	/*
	The value to which the cut or solution should be nearest.
	See the table above for the enumeration of
	the values and their effects.
	*/
	void setNearestTo(const UnsignedintID& nt){fprintf_s(mFile,"connectAttr \"");nt.write(mFile);fprintf_s(mFile,"\" \"%s.nt\";\n",mName.c_str());}
	/*
	weight for closest cut and closest solution comparisons.
	Specifies the weight vector for evaluating
	"closeness". Axes with smaller weights are considered less
	important than those with higher weights.
	*/
	void setWeight(const double3& w){if(w == double3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".w\" -type \"double3\" ");w.write(mFile);fprintf_s(mFile,";\n");}
	/*
	weight for closest cut and closest solution comparisons.
	Specifies the weight vector for evaluating
	"closeness". Axes with smaller weights are considered less
	important than those with higher weights.
	*/
	void setWeight(const Double3ID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*X weight for closest cut and closest solution comparisons*/
	void setWeightX(double wx){if(wx == 1.0) return; fprintf_s(mFile, "setAttr \".w.wx\" %f;\n", wx);}
	/*X weight for closest cut and closest solution comparisons*/
	void setWeightX(const DoubleID& wx){fprintf_s(mFile,"connectAttr \"");wx.write(mFile);fprintf_s(mFile,"\" \"%s.w.wx\";\n",mName.c_str());}
	/*Y weight for closest cut and closest solution comparisons*/
	void setWeightY(double wy){if(wy == 1.0) return; fprintf_s(mFile, "setAttr \".w.wy\" %f;\n", wy);}
	/*Y weight for closest cut and closest solution comparisons*/
	void setWeightY(const DoubleID& wy){fprintf_s(mFile,"connectAttr \"");wy.write(mFile);fprintf_s(mFile,"\" \"%s.w.wy\";\n",mName.c_str());}
	/*Z weight for closest cut and closest solution comparisons*/
	void setWeightZ(double wz){if(wz == 1.0) return; fprintf_s(mFile, "setAttr \".w.wz\" %f;\n", wz);}
	/*Z weight for closest cut and closest solution comparisons*/
	void setWeightZ(const DoubleID& wz){fprintf_s(mFile,"connectAttr \"");wz.write(mFile);fprintf_s(mFile,"\" \"%s.w.wz\";\n",mName.c_str());}
	/*
	enable use of initial Euler rotation attribute for
	closest cut and closest solution comparisons. If false, the value
	of the first sample is used as the initial value.
	*/
	void setEnableInitialRotation(bool eir){if(eir == false) return; fprintf_s(mFile, "setAttr \".eir\" %i;\n", eir);}
	/*
	enable use of initial Euler rotation attribute for
	closest cut and closest solution comparisons. If false, the value
	of the first sample is used as the initial value.
	*/
	void setEnableInitialRotation(const BoolID& eir){fprintf_s(mFile,"connectAttr \"");eir.write(mFile);fprintf_s(mFile,"\" \"%s.eir\";\n",mName.c_str());}
	/*
	the initial Euler rotation value for closest cut and closest
	solution comparisons, used in place of first sample for if
	enableInitialRotation is true.
	*/
	void setInitialRotation(const double3& ir){if(ir == double3(0., 0., 0.)) return; fprintf_s(mFile, "setAttr \".ir\" -type \"double3\" ");ir.write(mFile);fprintf_s(mFile,";\n");}
	/*
	the initial Euler rotation value for closest cut and closest
	solution comparisons, used in place of first sample for if
	enableInitialRotation is true.
	*/
	void setInitialRotation(const Double3ID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.ir\";\n",mName.c_str());}
	/*initial X Euler rotation component*/
	void setInitialRotationX(double irx){if(irx == 0) return; fprintf_s(mFile, "setAttr \".ir.irx\" %f;\n", irx);}
	/*initial X Euler rotation component*/
	void setInitialRotationX(const DoubleID& irx){fprintf_s(mFile,"connectAttr \"");irx.write(mFile);fprintf_s(mFile,"\" \"%s.ir.irx\";\n",mName.c_str());}
	/*initial Y Euler rotationcomponent*/
	void setInitialRotationY(double iry){if(iry == 0) return; fprintf_s(mFile, "setAttr \".ir.iry\" %f;\n", iry);}
	/*initial Y Euler rotationcomponent*/
	void setInitialRotationY(const DoubleID& iry){fprintf_s(mFile,"connectAttr \"");iry.write(mFile);fprintf_s(mFile,"\" \"%s.ir.iry\";\n",mName.c_str());}
	/*initial Z Euler rotationcomponent*/
	void setInitialRotationZ(double irz){if(irz == 0) return; fprintf_s(mFile, "setAttr \".ir.irz\" %f;\n", irz);}
	/*initial Z Euler rotationcomponent*/
	void setInitialRotationZ(const DoubleID& irz){fprintf_s(mFile,"connectAttr \"");irz.write(mFile);fprintf_s(mFile,"\" \"%s.ir.irz\";\n",mName.c_str());}
	/*Controls output rotation order.  Internal use only.  Do not set.*/
	void setOutputUsageOpt(unsigned int use){if(use == 0) return; fprintf_s(mFile, "setAttr \".use\" %i;\n", use);}
	/*Controls output rotation order.  Internal use only.  Do not set.*/
	void setOutputUsageOpt(const UnsignedintID& use){fprintf_s(mFile,"connectAttr \"");use.write(mFile);fprintf_s(mFile,"\" \"%s.use\";\n",mName.c_str());}
	/*
	The smoothing/demangling operation to use.
	See the table above for the enumeration of
	the values and their effects.
	*/
	UnsignedintID getSmooth(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	The value to which the cut or solution should be nearest.
	See the table above for the enumeration of
	the values and their effects.
	*/
	UnsignedintID getNearestTo(){char buffer[4096];sprintf_s (buffer, "%s.nt",mName.c_str());return (const char*)buffer;}
	/*
	weight for closest cut and closest solution comparisons.
	Specifies the weight vector for evaluating
	"closeness". Axes with smaller weights are considered less
	important than those with higher weights.
	*/
	Double3ID getWeight(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*X weight for closest cut and closest solution comparisons*/
	DoubleID getWeightX(){char buffer[4096];sprintf_s (buffer, "%s.w.wx",mName.c_str());return (const char*)buffer;}
	/*Y weight for closest cut and closest solution comparisons*/
	DoubleID getWeightY(){char buffer[4096];sprintf_s (buffer, "%s.w.wy",mName.c_str());return (const char*)buffer;}
	/*Z weight for closest cut and closest solution comparisons*/
	DoubleID getWeightZ(){char buffer[4096];sprintf_s (buffer, "%s.w.wz",mName.c_str());return (const char*)buffer;}
	/*
	enable use of initial Euler rotation attribute for
	closest cut and closest solution comparisons. If false, the value
	of the first sample is used as the initial value.
	*/
	BoolID getEnableInitialRotation(){char buffer[4096];sprintf_s (buffer, "%s.eir",mName.c_str());return (const char*)buffer;}
	/*
	the initial Euler rotation value for closest cut and closest
	solution comparisons, used in place of first sample for if
	enableInitialRotation is true.
	*/
	Double3ID getInitialRotation(){char buffer[4096];sprintf_s (buffer, "%s.ir",mName.c_str());return (const char*)buffer;}
	/*initial X Euler rotation component*/
	DoubleID getInitialRotationX(){char buffer[4096];sprintf_s (buffer, "%s.ir.irx",mName.c_str());return (const char*)buffer;}
	/*initial Y Euler rotationcomponent*/
	DoubleID getInitialRotationY(){char buffer[4096];sprintf_s (buffer, "%s.ir.iry",mName.c_str());return (const char*)buffer;}
	/*initial Z Euler rotationcomponent*/
	DoubleID getInitialRotationZ(){char buffer[4096];sprintf_s (buffer, "%s.ir.irz",mName.c_str());return (const char*)buffer;}
	/*Controls output rotation order.  Internal use only.  Do not set.*/
	UnsignedintID getOutputUsageOpt(){char buffer[4096];sprintf_s (buffer, "%s.use",mName.c_str());return (const char*)buffer;}
protected:
	FilterEuler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Filter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FILTEREULER_H__
