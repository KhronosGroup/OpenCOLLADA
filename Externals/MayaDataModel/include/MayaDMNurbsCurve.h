/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSCURVE_H__
#define __MayaDM_NURBSCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveShape.h"
namespace MayaDM
{
/*
*/
class NurbsCurve : public CurveShape
{
public:
public:
	NurbsCurve(FILE* file,const std::string& name,const std::string& parent=""):CurveShape(file, name, parent, "nurbsCurve"){}
	virtual ~NurbsCurve(){}
	/*
	Create in local space.  Construction history operations put the result
	in this attribute.
	*/
	void setCreate(const NurbsCurveID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*Curve in local space to be used in subsequent operations*/
	void setLocal(const NurbsCurveID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*
	Curve in world space (indexed by the instance number)to be used
	in subsequent operations
	*/
	void setWorldSpace(size_t ws_i,const NurbsCurveID& ws){fprintf_s(mFile,"connectAttr \"");ws.write(mFile);fprintf_s(mFile,"\" \"%s.ws[%i]\";\n",mName.c_str(),ws_i);}
	/*Curve fitting plane normal in world space (indexed by the instance number).*/
	void setWorldNormal(size_t wn_i,const Double3ID& wn){fprintf_s(mFile,"connectAttr \"");wn.write(mFile);fprintf_s(mFile,"\" \"%s.wn[%i]\";\n",mName.c_str(),wn_i);}
	/*X value of world plane normal*/
	void setWorldNormalX(size_t wn_i,const DoubleID& wnx){fprintf_s(mFile,"connectAttr \"");wnx.write(mFile);fprintf_s(mFile,"\" \"%s.wn[%i].wnx\";\n",mName.c_str(),wn_i);}
	/*Y value of world plane normal*/
	void setWorldNormalY(size_t wn_i,const DoubleID& wny){fprintf_s(mFile,"connectAttr \"");wny.write(mFile);fprintf_s(mFile,"\" \"%s.wn[%i].wny\";\n",mName.c_str(),wn_i);}
	/*Z value of world plane normal*/
	void setWorldNormalZ(size_t wn_i,const DoubleID& wnz){fprintf_s(mFile,"connectAttr \"");wnz.write(mFile);fprintf_s(mFile,"\" \"%s.wn[%i].wnz\";\n",mName.c_str(),wn_i);}
	/*Form (open = 0, closed = 1, periodic = 2)*/
	void setForm(const UnsignedintID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Curve degree*/
	void setDegree(const ShortID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Number of spans*/
	void setSpans(const IntID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*edit points*/
	void setEditPoints(size_t eps_i,const Double3ID& eps){fprintf_s(mFile,"connectAttr \"");eps.write(mFile);fprintf_s(mFile,"\" \"%s.eps[%i]\";\n",mName.c_str(),eps_i);}
	/*X value of a edit point*/
	void setXValueEp(size_t eps_i,const DoubleID& xve){fprintf_s(mFile,"connectAttr \"");xve.write(mFile);fprintf_s(mFile,"\" \"%s.eps[%i].xve\";\n",mName.c_str(),eps_i);}
	/*Y value of a edit point*/
	void setYValueEp(size_t eps_i,const DoubleID& yve){fprintf_s(mFile,"connectAttr \"");yve.write(mFile);fprintf_s(mFile,"\" \"%s.eps[%i].yve\";\n",mName.c_str(),eps_i);}
	/*Z value of a edit point*/
	void setZValueEp(size_t eps_i,const DoubleID& zve){fprintf_s(mFile,"connectAttr \"");zve.write(mFile);fprintf_s(mFile,"\" \"%s.eps[%i].zve\";\n",mName.c_str(),eps_i);}
	/*
	Cached curve
	Defines geometry of the curve. The properties are defined in this order:
	First line: degree, number of spans, form (0=open, 1=closed, 2=periodic), rational (yes/no), dimension
	Second line: number of knots, list of knot values
	Third line: number of CVs
	Fourth and later lines: CV positions in x,y,z (and w if rational)
	*/
	void setCached(const nurbsCurve& cc){fprintf_s(mFile, "setAttr \".cc\" -type \"nurbsCurve\" ");cc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Cached curve
	Defines geometry of the curve. The properties are defined in this order:
	First line: degree, number of spans, form (0=open, 1=closed, 2=periodic), rational (yes/no), dimension
	Second line: number of knots, list of knot values
	Third line: number of CVs
	Fourth and later lines: CV positions in x,y,z (and w if rational)
	*/
	void setCached(const NurbsCurveID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.cc\";\n",mName.c_str());}
	/*In place with history*/
	void setInPlace(bool ipo){if(ipo == false) return; fprintf_s(mFile, "setAttr \".ipo\" %i;\n", ipo);}
	/*In place with history*/
	void setInPlace(const BoolID& ipo){fprintf_s(mFile,"connectAttr \"");ipo.write(mFile);fprintf_s(mFile,"\" \"%s.ipo\";\n",mName.c_str());}
	/*Controls explicit CV display*/
	void setDispCV(bool dcv){if(dcv == false) return; fprintf_s(mFile, "setAttr \".dcv\" %i;\n", dcv);}
	/*Controls explicit CV display*/
	void setDispCV(const BoolID& dcv){fprintf_s(mFile,"connectAttr \"");dcv.write(mFile);fprintf_s(mFile,"\" \"%s.dcv\";\n",mName.c_str());}
	/*Controls explicit edit point display*/
	void setDispEP(bool dep){if(dep == false) return; fprintf_s(mFile, "setAttr \".dep\" %i;\n", dep);}
	/*Controls explicit edit point display*/
	void setDispEP(const BoolID& dep){fprintf_s(mFile,"connectAttr \"");dep.write(mFile);fprintf_s(mFile,"\" \"%s.dep\";\n",mName.c_str());}
	/*Controls explicit hull display*/
	void setDispHull(bool dh){if(dh == false) return; fprintf_s(mFile, "setAttr \".dh\" %i;\n", dh);}
	/*Controls explicit hull display*/
	void setDispHull(const BoolID& dh){fprintf_s(mFile,"connectAttr \"");dh.write(mFile);fprintf_s(mFile,"\" \"%s.dh\";\n",mName.c_str());}
	/*Controls explicit display of curve start and end points during curve draw.*/
	void setDispCurveEndPoints(const BoolID& dce){fprintf_s(mFile,"connectAttr \"");dce.write(mFile);fprintf_s(mFile,"\" \"%s.dce\";\n",mName.c_str());}
	/*Controls explicit geometry display*/
	void setDispGeometry(bool dg){if(dg == true) return; fprintf_s(mFile, "setAttr \".dg\" %i;\n", dg);}
	/*Controls explicit geometry display*/
	void setDispGeometry(const BoolID& dg){fprintf_s(mFile,"connectAttr \"");dg.write(mFile);fprintf_s(mFile,"\" \"%s.dg\";\n",mName.c_str());}
	/*What was the topology when we tweaked*/
	void setTweakSize(const IntID& ts){fprintf_s(mFile,"connectAttr \"");ts.write(mFile);fprintf_s(mFile,"\" \"%s.ts\";\n",mName.c_str());}
	/*
	Compound attribute holding the minValue and maxValue.  See the
	children attributes for explanation.
	*/
	void setMinMaxValue(const Double2ID& mmv){fprintf_s(mFile,"connectAttr \"");mmv.write(mFile);fprintf_s(mFile,"\" \"%s.mmv\";\n",mName.c_str());}
	/*Parameter range min*/
	void setMinValue(const DoubleID& min){fprintf_s(mFile,"connectAttr \"");min.write(mFile);fprintf_s(mFile,"\" \"%s.mmv.min\";\n",mName.c_str());}
	/*Parameter range max*/
	void setMaxValue(const DoubleID& max){fprintf_s(mFile,"connectAttr \"");max.write(mFile);fprintf_s(mFile,"\" \"%s.mmv.max\";\n",mName.c_str());}
	/*
	Create in local space.  Construction history operations put the result
	in this attribute.
	*/
	NurbsCurveID getCreate(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*Curve in local space to be used in subsequent operations*/
	NurbsCurveID getLocal(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*
	Curve in world space (indexed by the instance number)to be used
	in subsequent operations
	*/
	const NurbsCurveID& getWorldSpace(size_t ws_i){char buffer[4096];sprintf_s (buffer, "%s.ws[%i]",mName.c_str(),ws_i);return (const char*)buffer;}
	/*Curve fitting plane normal in world space (indexed by the instance number).*/
	const Double3ID& getWorldNormal(size_t wn_i){char buffer[4096];sprintf_s (buffer, "%s.wn[%i]",mName.c_str(),wn_i);return (const char*)buffer;}
	/*X value of world plane normal*/
	const DoubleID& getWorldNormalX(size_t wn_i){char buffer[4096];sprintf_s (buffer, "%s.wn[%i].wnx",mName.c_str(),wn_i);return (const char*)buffer;}
	/*Y value of world plane normal*/
	const DoubleID& getWorldNormalY(size_t wn_i){char buffer[4096];sprintf_s (buffer, "%s.wn[%i].wny",mName.c_str(),wn_i);return (const char*)buffer;}
	/*Z value of world plane normal*/
	const DoubleID& getWorldNormalZ(size_t wn_i){char buffer[4096];sprintf_s (buffer, "%s.wn[%i].wnz",mName.c_str(),wn_i);return (const char*)buffer;}
	/*Form (open = 0, closed = 1, periodic = 2)*/
	UnsignedintID getForm(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*Curve degree*/
	ShortID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Number of spans*/
	IntID getSpans(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*edit points*/
	const Double3ID& getEditPoints(size_t eps_i){char buffer[4096];sprintf_s (buffer, "%s.eps[%i]",mName.c_str(),eps_i);return (const char*)buffer;}
	/*X value of a edit point*/
	const DoubleID& getXValueEp(size_t eps_i){char buffer[4096];sprintf_s (buffer, "%s.eps[%i].xve",mName.c_str(),eps_i);return (const char*)buffer;}
	/*Y value of a edit point*/
	const DoubleID& getYValueEp(size_t eps_i){char buffer[4096];sprintf_s (buffer, "%s.eps[%i].yve",mName.c_str(),eps_i);return (const char*)buffer;}
	/*Z value of a edit point*/
	const DoubleID& getZValueEp(size_t eps_i){char buffer[4096];sprintf_s (buffer, "%s.eps[%i].zve",mName.c_str(),eps_i);return (const char*)buffer;}
	/*
	Cached curve
	Defines geometry of the curve. The properties are defined in this order:
	First line: degree, number of spans, form (0=open, 1=closed, 2=periodic), rational (yes/no), dimension
	Second line: number of knots, list of knot values
	Third line: number of CVs
	Fourth and later lines: CV positions in x,y,z (and w if rational)
	*/
	NurbsCurveID getCached(){char buffer[4096];sprintf_s (buffer, "%s.cc",mName.c_str());return (const char*)buffer;}
	/*In place with history*/
	BoolID getInPlace(){char buffer[4096];sprintf_s (buffer, "%s.ipo",mName.c_str());return (const char*)buffer;}
	/*Controls explicit CV display*/
	BoolID getDispCV(){char buffer[4096];sprintf_s (buffer, "%s.dcv",mName.c_str());return (const char*)buffer;}
	/*Controls explicit edit point display*/
	BoolID getDispEP(){char buffer[4096];sprintf_s (buffer, "%s.dep",mName.c_str());return (const char*)buffer;}
	/*Controls explicit hull display*/
	BoolID getDispHull(){char buffer[4096];sprintf_s (buffer, "%s.dh",mName.c_str());return (const char*)buffer;}
	/*Controls explicit display of curve start and end points during curve draw.*/
	BoolID getDispCurveEndPoints(){char buffer[4096];sprintf_s (buffer, "%s.dce",mName.c_str());return (const char*)buffer;}
	/*Controls explicit geometry display*/
	BoolID getDispGeometry(){char buffer[4096];sprintf_s (buffer, "%s.dg",mName.c_str());return (const char*)buffer;}
	/*What was the topology when we tweaked*/
	IntID getTweakSize(){char buffer[4096];sprintf_s (buffer, "%s.ts",mName.c_str());return (const char*)buffer;}
	/*
	Compound attribute holding the minValue and maxValue.  See the
	children attributes for explanation.
	*/
	Double2ID getMinMaxValue(){char buffer[4096];sprintf_s (buffer, "%s.mmv",mName.c_str());return (const char*)buffer;}
	/*Parameter range min*/
	DoubleID getMinValue(){char buffer[4096];sprintf_s (buffer, "%s.mmv.min",mName.c_str());return (const char*)buffer;}
	/*Parameter range max*/
	DoubleID getMaxValue(){char buffer[4096];sprintf_s (buffer, "%s.mmv.max",mName.c_str());return (const char*)buffer;}
protected:
	NurbsCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NURBSCURVE_H__
