/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEINFO_H__
#define __MayaDM_CURVEINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
<p><pre> Compute an arclength of the curve and produce some valuable information
 about it: control vertex positions and weights or the knot values.
</pre></p>
*/
class CurveInfo : public AbstractBaseCreate
{
public:
public:
	CurveInfo(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "curveInfo"){}
	virtual ~CurveInfo(){}
	/*The input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*The arclength of the curve*/
	void setArcLength(const DoubleID& al){fprintf_s(mFile,"connectAttr \"");al.write(mFile);fprintf_s(mFile,"\" \"%s.al\";\n",mName.c_str());}
	/*control points*/
	void setControlPoints(size_t cp_i,const Double3ID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i]\";\n",mName.c_str(),cp_i);}
	/*X value of a control point*/
	void setXValue(size_t cp_i,const DoubleID& xv){fprintf_s(mFile,"connectAttr \"");xv.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i].xv\";\n",mName.c_str(),cp_i);}
	/*Y value of a control point*/
	void setYValue(size_t cp_i,const DoubleID& yv){fprintf_s(mFile,"connectAttr \"");yv.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i].yv\";\n",mName.c_str(),cp_i);}
	/*Z value of a control point*/
	void setZValue(size_t cp_i,const DoubleID& zv){fprintf_s(mFile,"connectAttr \"");zv.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i].zv\";\n",mName.c_str(),cp_i);}
	/*CV weights values for nurbs, else unused*/
	void setWeights(size_t wt_i,const DoubleID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.wt[%i]\";\n",mName.c_str(),wt_i);}
	/*knots for the curve*/
	void setKnots(size_t kn_i,const DoubleID& kn){fprintf_s(mFile,"connectAttr \"");kn.write(mFile);fprintf_s(mFile,"\" \"%s.kn[%i]\";\n",mName.c_str(),kn_i);}
	/*The input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*The arclength of the curve*/
	DoubleID getArcLength(){char buffer[4096];sprintf_s (buffer, "%s.al",mName.c_str());return (const char*)buffer;}
	/*control points*/
	const Double3ID& getControlPoints(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i]",mName.c_str(),cp_i);return (const char*)buffer;}
	/*X value of a control point*/
	const DoubleID& getXValue(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i].xv",mName.c_str(),cp_i);return (const char*)buffer;}
	/*Y value of a control point*/
	const DoubleID& getYValue(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i].yv",mName.c_str(),cp_i);return (const char*)buffer;}
	/*Z value of a control point*/
	const DoubleID& getZValue(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i].zv",mName.c_str(),cp_i);return (const char*)buffer;}
	/*CV weights values for nurbs, else unused*/
	const DoubleID& getWeights(size_t wt_i){char buffer[4096];sprintf_s (buffer, "%s.wt[%i]",mName.c_str(),wt_i);return (const char*)buffer;}
	/*knots for the curve*/
	const DoubleID& getKnots(size_t kn_i){char buffer[4096];sprintf_s (buffer, "%s.kn[%i]",mName.c_str(),kn_i);return (const char*)buffer;}
protected:
	CurveInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEINFO_H__
