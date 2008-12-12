/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSURFACEISO_H__
#define __MayaDM_CURVEFROMSURFACEISO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSurface.h"
namespace MayaDM
{
/*
This node defines a NURBS curve that is derived from a NURBS surface
 isoparm.  The isoparm is defined by the "isoparmValue" and
 "isoparmDirection" attributes.  If the direction is "U", then the
 isoparm is along the U direction, ie. V = isoParmValue.
 If the direction is "V", then the isoparm is along the V direction,
 ie. U = isoparmValue.
 <p/> You can query the minValueU, minValueV, maxValueU, maxValueV
 attributes of the input surface to determine the minimum and
 maximum parameter values of the surface.
*/
class CurveFromSurfaceIso : public CurveFromSurface
{
public:
public:
	CurveFromSurfaceIso(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSurface(file, name, parent, "curveFromSurfaceIso"){}
	virtual ~CurveFromSurfaceIso(){}
	/*Parameter value for the isoparm*/
	void setIsoparmValue(double iv){if(iv == 0.0) return; fprintf_s(mFile, "setAttr \".iv\" %f;\n", iv);}
	/*Parameter value for the isoparm*/
	void setIsoparmValue(const DoubleID& iv){fprintf_s(mFile,"connectAttr \"");iv.write(mFile);fprintf_s(mFile,"\" \"%s.iv\";\n",mName.c_str());}
	/*Isoparm direction: 0 for U, 1 for V*/
	void setIsoparmDirection(unsigned int idr){if(idr == 0) return; fprintf_s(mFile, "setAttr \".idr\" %i;\n", idr);}
	/*Isoparm direction: 0 for U, 1 for V*/
	void setIsoparmDirection(const UnsignedintID& idr){fprintf_s(mFile,"connectAttr \"");idr.write(mFile);fprintf_s(mFile,"\" \"%s.idr\";\n",mName.c_str());}
	/*
	True means use a relative parameter range for values, from 0.0 to 1.0.
	Otherwise, the parameter values are absolute values.
	*/
	void setRelativeValue(bool rv){if(rv == false) return; fprintf_s(mFile, "setAttr \".rv\" %i;\n", rv);}
	/*
	True means use a relative parameter range for values, from 0.0 to 1.0.
	Otherwise, the parameter values are absolute values.
	*/
	void setRelativeValue(const BoolID& rv){fprintf_s(mFile,"connectAttr \"");rv.write(mFile);fprintf_s(mFile,"\" \"%s.rv\";\n",mName.c_str());}
	/*Parameter value for the isoparm*/
	DoubleID getIsoparmValue(){char buffer[4096];sprintf_s (buffer, "%s.iv",mName.c_str());return (const char*)buffer;}
	/*Isoparm direction: 0 for U, 1 for V*/
	UnsignedintID getIsoparmDirection(){char buffer[4096];sprintf_s (buffer, "%s.idr",mName.c_str());return (const char*)buffer;}
	/*
	True means use a relative parameter range for values, from 0.0 to 1.0.
	Otherwise, the parameter values are absolute values.
	*/
	BoolID getRelativeValue(){char buffer[4096];sprintf_s (buffer, "%s.rv",mName.c_str());return (const char*)buffer;}
protected:
	CurveFromSurfaceIso(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromSurface(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSURFACEISO_H__
