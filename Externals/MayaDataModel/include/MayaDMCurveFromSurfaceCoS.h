/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSURFACECOS_H__
#define __MayaDM_CURVEFROMSURFACECOS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSurface.h"
namespace MayaDM
{
/*
This node defines a NURBS curve that is derived from a curve
 on a NURBS surface.  This curve must be a 2-dimensional curve in the
 underworld of the surface.
 The curve is specified by the input attribute, "curveOnSurface".
 <p/> You can query the minValue and maxValue attributes of the
 input curve-on-surface to determine the minimum and
 maximum parameter values of the curve-on-surface.
*/
class CurveFromSurfaceCoS : public CurveFromSurface
{
public:
public:
	CurveFromSurfaceCoS(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSurface(file, name, parent, "curveFromSurfaceCoS"){}
	virtual ~CurveFromSurfaceCoS(){}
	/*The input curve-on-surface.  This curve is a 2D curve.*/
	void setCurveOnSurface(const NurbsCurveID& cos){fprintf_s(mFile,"connectAttr \"");cos.write(mFile);fprintf_s(mFile,"\" \"%s.cos\";\n",mName.c_str());}
	/*The input curve-on-surface.  This curve is a 2D curve.*/
	NurbsCurveID getCurveOnSurface(){char buffer[4096];sprintf_s (buffer, "%s.cos",mName.c_str());return (const char*)buffer;}
protected:
	CurveFromSurfaceCoS(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromSurface(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSURFACECOS_H__
