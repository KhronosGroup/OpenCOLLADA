/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBCURVE_H__
#define __MayaDM_SUBCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveRange.h"
namespace MayaDM
{
/*
The 'subCurve' node is used to selectively cut a portion of
 a NURBS curve. The portion of the curve is specified by giving a
 a min and max value in the parameter space domain of the NURBS curve.
 <p/>
 The input attribute 'inputCurve' specifies the NURBS curve on
 which the cut should be performed.
 <p/>
 The attributes 'min' and 'max' specify the desired range in the
 parameter space domain of the NURBS curve. The 'min' value must
 be less than the 'max' value.
 <p/>
 The attribute 'relative' may be used if the specified min, max
 values need to be remapped based on the start and end parameter
 values of the input NURBS curve. The specified values are modified
 using a linear transformation.
 <p/>
 The output attribute '.oc' provides the NURBS curve after the cut.
 <p/>
*/
class SubCurve : public CurveRange
{
public:
public:
	SubCurve(FILE* file,const std::string& name,const std::string& parent=""):CurveRange(file, name, parent, "subCurve"){}
	virtual ~SubCurve(){}
	/*The input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*Minimal parameter value for the curve segment*/
	void setMinValue(double min){if(min == 0.0) return; fprintf_s(mFile, "setAttr \".min\" %f;\n", min);}
	/*Minimal parameter value for the curve segment*/
	void setMinValue(const DoubleID& min){fprintf_s(mFile,"connectAttr \"");min.write(mFile);fprintf_s(mFile,"\" \"%s.min\";\n",mName.c_str());}
	/*Maximal parameter value for the curve segment*/
	void setMaxValue(double max){if(max == -1.0) return; fprintf_s(mFile, "setAttr \".max\" %f;\n", max);}
	/*Maximal parameter value for the curve segment*/
	void setMaxValue(const DoubleID& max){fprintf_s(mFile,"connectAttr \"");max.write(mFile);fprintf_s(mFile,"\" \"%s.max\";\n",mName.c_str());}
	/*Use relative (0 - 1) parameter range instead*/
	void setRelative(bool r){if(r == false) return; fprintf_s(mFile, "setAttr \".r\" %i;\n", r);}
	/*Use relative (0 - 1) parameter range instead*/
	void setRelative(const BoolID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Output curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*Minimal parameter value for the curve segment*/
	DoubleID getMinValue(){char buffer[4096];sprintf_s (buffer, "%s.min",mName.c_str());return (const char*)buffer;}
	/*Maximal parameter value for the curve segment*/
	DoubleID getMaxValue(){char buffer[4096];sprintf_s (buffer, "%s.max",mName.c_str());return (const char*)buffer;}
	/*Use relative (0 - 1) parameter range instead*/
	BoolID getRelative(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Output curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	SubCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveRange(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBCURVE_H__
