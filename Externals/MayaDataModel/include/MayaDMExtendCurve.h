/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXTENDCURVE_H__
#define __MayaDM_EXTENDCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Extend the start or end of the input curve. There are two methods used
 to specify where to extend to (extendMethod). The curve can be extended
 given a distance or given a point to extend to. In addition, the extension
 can be a linear, circular, or cubic segment (extendType).
 The extension can be joined to the original curve (join) and any unnecessary
 multiple knots at that join can be removed (removeMultKnots).
 <p/>
*/
class ExtendCurve : public AbstractBaseCreate
{
public:
public:
	ExtendCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "extendCurve"){}
	virtual ~ExtendCurve(){}
	/*The curve to extend.*/
	void setInputCurve1(const NurbsCurveID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.ic1\";\n",mName.c_str());}
	/*The curve to extend to (optional).  Currently not used.*/
	void setInputCurve2(const NurbsCurveID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.ic2\";\n",mName.c_str());}
	/*The surface to extend to (optional).  Currently not used.*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*The point to extend to (optional)*/
	void setInputPoint(const double3& ip){fprintf_s(mFile, "setAttr \".ip\" -type \"double3\" ");ip.write(mFile);fprintf_s(mFile,";\n");}
	/*The point to extend to (optional)*/
	void setInputPoint(const Double3ID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip\";\n",mName.c_str());}
	/*X of the point to extend to*/
	void setPointX(double px){if(px == 0) return; fprintf_s(mFile, "setAttr \".ip.px\" %f;\n", px);}
	/*X of the point to extend to*/
	void setPointX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.ip.px\";\n",mName.c_str());}
	/*Y of the point to extend to*/
	void setPointY(double py){if(py == 0) return; fprintf_s(mFile, "setAttr \".ip.py\" %f;\n", py);}
	/*Y of the point to extend to*/
	void setPointY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.ip.py\";\n",mName.c_str());}
	/*Z of the point to extend to*/
	void setPointZ(double pz){if(pz == 0) return; fprintf_s(mFile, "setAttr \".ip.pz\" %f;\n", pz);}
	/*Z of the point to extend to*/
	void setPointZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.ip.pz\";\n",mName.c_str());}
	/*
	The type of extension:
	0 - linear,
	1 - circular,
	2 - extrapolate
	*/
	void setExtensionType(unsigned int et){if(et == 0) return; fprintf_s(mFile, "setAttr \".et\" %i;\n", et);}
	/*
	The type of extension:
	0 - linear,
	1 - circular,
	2 - extrapolate
	*/
	void setExtensionType(const UnsignedintID& et){fprintf_s(mFile,"connectAttr \"");et.write(mFile);fprintf_s(mFile,"\" \"%s.et\";\n",mName.c_str());}
	/*
	The method with which to extend:
	0 - based on distance,
	2 - to a 3D point
	*/
	void setExtendMethod(unsigned int em){if(em == 0) return; fprintf_s(mFile, "setAttr \".em\" %i;\n", em);}
	/*
	The method with which to extend:
	0 - based on distance,
	2 - to a 3D point
	*/
	void setExtendMethod(const UnsignedintID& em){fprintf_s(mFile,"connectAttr \"");em.write(mFile);fprintf_s(mFile,"\" \"%s.em\";\n",mName.c_str());}
	/*
	Which end of the curve to extend.
	0 - end,
	1 - start,
	2 - both
	*/
	void setStart(unsigned int s){if(s == 1) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*
	Which end of the curve to extend.
	0 - end,
	1 - start,
	2 - both
	*/
	void setStart(const UnsignedintID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*If true, join the extension to original curve*/
	void setJoin(bool jn){if(jn == true) return; fprintf_s(mFile, "setAttr \".jn\" %i;\n", jn);}
	/*If true, join the extension to original curve*/
	void setJoin(const BoolID& jn){fprintf_s(mFile,"connectAttr \"");jn.write(mFile);fprintf_s(mFile,"\" \"%s.jn\";\n",mName.c_str());}
	/*
	The distance to extend
	Used only for extendMethod is byDistance.
	*/
	void setDistance(double d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	The distance to extend
	Used only for extendMethod is byDistance.
	*/
	void setDistance(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	If true remove multiple knots at join
	Used only if join is true.
	*/
	void setRemoveMultipleKnots(bool rmk){if(rmk == false) return; fprintf_s(mFile, "setAttr \".rmk\" %i;\n", rmk);}
	/*
	If true remove multiple knots at join
	Used only if join is true.
	*/
	void setRemoveMultipleKnots(const BoolID& rmk){fprintf_s(mFile,"connectAttr \"");rmk.write(mFile);fprintf_s(mFile,"\" \"%s.rmk\";\n",mName.c_str());}
	/*The extended curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The curve to extend.*/
	NurbsCurveID getInputCurve1(){char buffer[4096];sprintf_s (buffer, "%s.ic1",mName.c_str());return (const char*)buffer;}
	/*The curve to extend to (optional).  Currently not used.*/
	NurbsCurveID getInputCurve2(){char buffer[4096];sprintf_s (buffer, "%s.ic2",mName.c_str());return (const char*)buffer;}
	/*The surface to extend to (optional).  Currently not used.*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*The point to extend to (optional)*/
	Double3ID getInputPoint(){char buffer[4096];sprintf_s (buffer, "%s.ip",mName.c_str());return (const char*)buffer;}
	/*X of the point to extend to*/
	DoubleID getPointX(){char buffer[4096];sprintf_s (buffer, "%s.ip.px",mName.c_str());return (const char*)buffer;}
	/*Y of the point to extend to*/
	DoubleID getPointY(){char buffer[4096];sprintf_s (buffer, "%s.ip.py",mName.c_str());return (const char*)buffer;}
	/*Z of the point to extend to*/
	DoubleID getPointZ(){char buffer[4096];sprintf_s (buffer, "%s.ip.pz",mName.c_str());return (const char*)buffer;}
	/*
	The type of extension:
	0 - linear,
	1 - circular,
	2 - extrapolate
	*/
	UnsignedintID getExtensionType(){char buffer[4096];sprintf_s (buffer, "%s.et",mName.c_str());return (const char*)buffer;}
	/*
	The method with which to extend:
	0 - based on distance,
	2 - to a 3D point
	*/
	UnsignedintID getExtendMethod(){char buffer[4096];sprintf_s (buffer, "%s.em",mName.c_str());return (const char*)buffer;}
	/*
	Which end of the curve to extend.
	0 - end,
	1 - start,
	2 - both
	*/
	UnsignedintID getStart(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*If true, join the extension to original curve*/
	BoolID getJoin(){char buffer[4096];sprintf_s (buffer, "%s.jn",mName.c_str());return (const char*)buffer;}
	/*
	The distance to extend
	Used only for extendMethod is byDistance.
	*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	If true remove multiple knots at join
	Used only if join is true.
	*/
	BoolID getRemoveMultipleKnots(){char buffer[4096];sprintf_s (buffer, "%s.rmk",mName.c_str());return (const char*)buffer;}
	/*The extended curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	ExtendCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_EXTENDCURVE_H__
