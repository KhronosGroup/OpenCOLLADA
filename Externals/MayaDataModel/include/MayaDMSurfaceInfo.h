/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACEINFO_H__
#define __MayaDM_SURFACEINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
<p><pre>This surface information node is the best way to query the control
points (also known as control vertices, or CVs) and knots of a surface.
</pre></p>
*/
class SurfaceInfo : public AbstractBaseCreate
{
public:
public:
	SurfaceInfo(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "surfaceInfo"){}
	virtual ~SurfaceInfo(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Control points (or control vertices, CVs) of a surface, in U-dominant order.*/
	void setControlPoints(size_t cp_i,const Double3ID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i]\";\n",mName.c_str(),cp_i);}
	/*X value of a control point*/
	void setXValue(size_t cp_i,const DoubleID& xv){fprintf_s(mFile,"connectAttr \"");xv.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i].xv\";\n",mName.c_str(),cp_i);}
	/*Y value of a control point*/
	void setYValue(size_t cp_i,const DoubleID& yv){fprintf_s(mFile,"connectAttr \"");yv.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i].yv\";\n",mName.c_str(),cp_i);}
	/*Z value of a control point*/
	void setZValue(size_t cp_i,const DoubleID& zv){fprintf_s(mFile,"connectAttr \"");zv.write(mFile);fprintf_s(mFile,"\" \"%s.cp[%i].zv\";\n",mName.c_str(),cp_i);}
	/*CV weights values for NURBS, else unused*/
	void setWeights(size_t wt_i,const DoubleID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.wt[%i]\";\n",mName.c_str(),wt_i);}
	/*U knots for the surface*/
	void setKnotsU(size_t ku_i,const DoubleID& ku){fprintf_s(mFile,"connectAttr \"");ku.write(mFile);fprintf_s(mFile,"\" \"%s.ku[%i]\";\n",mName.c_str(),ku_i);}
	/*V knots for the surface*/
	void setKnotsV(size_t kv_i,const DoubleID& kv){fprintf_s(mFile,"connectAttr \"");kv.write(mFile);fprintf_s(mFile,"\" \"%s.kv[%i]\";\n",mName.c_str(),kv_i);}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Control points (or control vertices, CVs) of a surface, in U-dominant order.*/
	const Double3ID& getControlPoints(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i]",mName.c_str(),cp_i);return (const char*)buffer;}
	/*X value of a control point*/
	const DoubleID& getXValue(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i].xv",mName.c_str(),cp_i);return (const char*)buffer;}
	/*Y value of a control point*/
	const DoubleID& getYValue(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i].yv",mName.c_str(),cp_i);return (const char*)buffer;}
	/*Z value of a control point*/
	const DoubleID& getZValue(size_t cp_i){char buffer[4096];sprintf_s (buffer, "%s.cp[%i].zv",mName.c_str(),cp_i);return (const char*)buffer;}
	/*CV weights values for NURBS, else unused*/
	const DoubleID& getWeights(size_t wt_i){char buffer[4096];sprintf_s (buffer, "%s.wt[%i]",mName.c_str(),wt_i);return (const char*)buffer;}
	/*U knots for the surface*/
	const DoubleID& getKnotsU(size_t ku_i){char buffer[4096];sprintf_s (buffer, "%s.ku[%i]",mName.c_str(),ku_i);return (const char*)buffer;}
	/*V knots for the surface*/
	const DoubleID& getKnotsV(size_t kv_i){char buffer[4096];sprintf_s (buffer, "%s.kv[%i]",mName.c_str(),kv_i);return (const char*)buffer;}
protected:
	SurfaceInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SURFACEINFO_H__
