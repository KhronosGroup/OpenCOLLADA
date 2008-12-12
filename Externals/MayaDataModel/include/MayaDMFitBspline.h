/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FITBSPLINE_H__
#define __MayaDM_FITBSPLINE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
This node computes a NURBS curve that will fit through
 a list of given points.  The list of points is defined as the
 the control points of the input curve (attribute "inputCurve").
 <p/> You can control the number of spans in the resulting curve
 by changing the tolerance.
 <p/> If you just have a list of points to fit to,
 an easy way to use this node is to produce a linear (degree 1)
 NURBS curve that contains the points.
 Then this node can be connected to produce a fitted NURBS curve.
 <p/> If you need more control of the number of resulting spans,
 consider using the rebuildCurve node.
*/
class FitBspline : public AbstractBaseCreate
{
public:
public:
	FitBspline(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "fitBspline"){}
	virtual ~FitBspline(){}
	/*The input curve (whose CVs are fitted to)*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*
	Tolerance for the fit.  The resulting curve will be kept
	within tolerance of the given points.
	*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*
	Tolerance for the fit.  The resulting curve will be kept
	within tolerance of the given points.
	*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*Output curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The input curve (whose CVs are fitted to)*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*
	Tolerance for the fit.  The resulting curve will be kept
	within tolerance of the given points.
	*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*Output curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	FitBspline(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FITBSPLINE_H__
