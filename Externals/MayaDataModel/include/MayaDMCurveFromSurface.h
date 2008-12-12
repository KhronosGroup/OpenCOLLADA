/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSURFACE_H__
#define __MayaDM_CURVEFROMSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveRange.h"
namespace MayaDM
{
/*
A curveFromSurface node is the basis node for
 curveFromSurfaceIso, curveFromSurfaceBnd, and curveFromSurfaceCos.
 This node describes a NURBS curve derived from a NURBS surface isoparm,
 boundary or curve-on-surface.  The resulting NURBS curve is the
 attribute "outputCurve" and its extent can be controlled by the
 minValue and maxValue parameters.  If the "relative" attribute
 is true, then the minValue and maxValue parameters are expressed
 as percent, ie. ranging from 0.0 to 1.0.
*/
class CurveFromSurface : public CurveRange
{
public:
public:
	CurveFromSurface(FILE* file,const std::string& name,const std::string& parent=""):CurveRange(file, name, parent, "curveFromSurface"){}
	virtual ~CurveFromSurface(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*
	Minimum parameter value for the curve segment
	If relative is true, then this attribute has minimum value of 0.0.
	*/
	void setMinValue(double min){if(min == 1.0) return; fprintf_s(mFile, "setAttr \".min\" %f;\n", min);}
	/*
	Minimum parameter value for the curve segment
	If relative is true, then this attribute has minimum value of 0.0.
	*/
	void setMinValue(const DoubleID& min){fprintf_s(mFile,"connectAttr \"");min.write(mFile);fprintf_s(mFile,"\" \"%s.min\";\n",mName.c_str());}
	/*
	Maximum parameter value for the curve segment.  Must be greater
	than or equal to the minValue attribute.
	If relative is true, then this attribute has maximum value of 1.0.
	*/
	void setMaxValue(double max){if(max == -1.0) return; fprintf_s(mFile, "setAttr \".max\" %f;\n", max);}
	/*
	Maximum parameter value for the curve segment.  Must be greater
	than or equal to the minValue attribute.
	If relative is true, then this attribute has maximum value of 1.0.
	*/
	void setMaxValue(const DoubleID& max){fprintf_s(mFile,"connectAttr \"");max.write(mFile);fprintf_s(mFile,"\" \"%s.max\";\n",mName.c_str());}
	/*
	True means use a relative parameter range, from 0.0 to 1.0.
	Otherwise, the parameter values are absolute values.
	*/
	void setRelative(bool r){if(r == false) return; fprintf_s(mFile, "setAttr \".r\" %i;\n", r);}
	/*
	True means use a relative parameter range, from 0.0 to 1.0.
	Otherwise, the parameter values are absolute values.
	*/
	void setRelative(const BoolID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The output curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*
	Minimum parameter value for the curve segment
	If relative is true, then this attribute has minimum value of 0.0.
	*/
	DoubleID getMinValue(){char buffer[4096];sprintf_s (buffer, "%s.min",mName.c_str());return (const char*)buffer;}
	/*
	Maximum parameter value for the curve segment.  Must be greater
	than or equal to the minValue attribute.
	If relative is true, then this attribute has maximum value of 1.0.
	*/
	DoubleID getMaxValue(){char buffer[4096];sprintf_s (buffer, "%s.max",mName.c_str());return (const char*)buffer;}
	/*
	True means use a relative parameter range, from 0.0 to 1.0.
	Otherwise, the parameter values are absolute values.
	*/
	BoolID getRelative(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The output curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	CurveFromSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveRange(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSURFACE_H__
