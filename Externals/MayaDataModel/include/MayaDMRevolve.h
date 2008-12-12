/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REVOLVE_H__
#define __MayaDM_REVOLVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Given an input curve (inputCurve) this node creates a revolved
 surface about a specified axis of revolution (defined by the
 attributes "axis" and "pivot").  The sweep is defined by
 "startSweep" and "endSweep".  The degree of the resulting surface
 is defined by the attribute "degree".  The end sweep cannot be more
 than 360 degrees.  You can control the number of spans or "sections" in
 the surface either explicitly, using the "sections" attribute,
 or indirectly, using the "useTolerance" and "tolerance" attributes.
 If tolerance is used, then the result surface has as many spans as
 needed to stay within the specified tolerance.
*/
class Revolve : public AbstractBaseCreate
{
public:
public:
	Revolve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "revolve"){}
	virtual ~Revolve(){}
	/*The input curve.*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*The value for the start sweep angle, in the current units.  This must be no more than the maximum, 360 degrees, or 2 Pi radians.*/
	void setStartSweep(double ssw){if(ssw == 0) return; fprintf_s(mFile, "setAttr \".ssw\" %f;\n", ssw);}
	/*The value for the start sweep angle, in the current units.  This must be no more than the maximum, 360 degrees, or 2 Pi radians.*/
	void setStartSweep(const DoubleID& ssw){fprintf_s(mFile,"connectAttr \"");ssw.write(mFile);fprintf_s(mFile,"\" \"%s.ssw\";\n",mName.c_str());}
	/*The value for the end sweep angle, in the current units.  This must be no more than the maximum, 360 degrees, or 2 Pi radians.*/
	void setEndSweep(double esw){if(esw == 6.2831853) return; fprintf_s(mFile, "setAttr \".esw\" %f;\n", esw);}
	/*The value for the end sweep angle, in the current units.  This must be no more than the maximum, 360 degrees, or 2 Pi radians.*/
	void setEndSweep(const DoubleID& esw){fprintf_s(mFile,"connectAttr \"");esw.write(mFile);fprintf_s(mFile,"\" \"%s.esw\";\n",mName.c_str());}
	/*Use the tolerance, or the number of sections to control the sections.*/
	void setUseTolerance(bool ut){if(ut == false) return; fprintf_s(mFile, "setAttr \".ut\" %i;\n", ut);}
	/*Use the tolerance, or the number of sections to control the sections.*/
	void setUseTolerance(const BoolID& ut){fprintf_s(mFile,"connectAttr \"");ut.write(mFile);fprintf_s(mFile,"\" \"%s.ut\";\n",mName.c_str());}
	/*The degree of the resulting surface.*/
	void setDegree(unsigned int d){if(d == 3) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*The degree of the resulting surface.*/
	void setDegree(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Number of sections of the resulting surface (if tolerance is not used).*/
	void setSections(int s){if(s == 8) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*Number of sections of the resulting surface (if tolerance is not used).*/
	void setSections(const IntID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Tolerance to build to (if useTolerance attribute is set)*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*Tolerance to build to (if useTolerance attribute is set)*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*Revolve axis*/
	void setAxis(const double3& ax){fprintf_s(mFile, "setAttr \".ax\" -type \"double3\" ");ax.write(mFile);fprintf_s(mFile,";\n");}
	/*Revolve axis*/
	void setAxis(const Double3ID& ax){fprintf_s(mFile,"connectAttr \"");ax.write(mFile);fprintf_s(mFile,"\" \"%s.ax\";\n",mName.c_str());}
	/*X of the axis*/
	void setAxisX(double axx){if(axx == 1) return; fprintf_s(mFile, "setAttr \".ax.axx\" %f;\n", axx);}
	/*X of the axis*/
	void setAxisX(const DoubleID& axx){fprintf_s(mFile,"connectAttr \"");axx.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axx\";\n",mName.c_str());}
	/*Y of the axis*/
	void setAxisY(double axy){if(axy == 0) return; fprintf_s(mFile, "setAttr \".ax.axy\" %f;\n", axy);}
	/*Y of the axis*/
	void setAxisY(const DoubleID& axy){fprintf_s(mFile,"connectAttr \"");axy.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axy\";\n",mName.c_str());}
	/*Z of the axis*/
	void setAxisZ(double axz){if(axz == 0) return; fprintf_s(mFile, "setAttr \".ax.axz\" %f;\n", axz);}
	/*Z of the axis*/
	void setAxisZ(const DoubleID& axz){fprintf_s(mFile,"connectAttr \"");axz.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axz\";\n",mName.c_str());}
	/*Revolve pivot point*/
	void setPivot(const double3& p){fprintf_s(mFile, "setAttr \".p\" -type \"double3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*Revolve pivot point*/
	void setPivot(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*X of the pivot*/
	void setPivotX(double px){if(px == 0) return; fprintf_s(mFile, "setAttr \".p.px\" %f;\n", px);}
	/*X of the pivot*/
	void setPivotX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*Y of the pivot*/
	void setPivotY(double py){if(py == 0) return; fprintf_s(mFile, "setAttr \".p.py\" %f;\n", py);}
	/*Y of the pivot*/
	void setPivotY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*Z of the pivot*/
	void setPivotZ(double pz){if(pz == 0) return; fprintf_s(mFile, "setAttr \".p.pz\" %f;\n", pz);}
	/*Z of the pivot*/
	void setPivotZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*If this is set to true we will attempt to reverse the direction of the axis in case it is necessary to do so for the surface normals to end up pointing to the outside of the object.*/
	void setAutoCorrectNormal(bool acn){if(acn == false) return; fprintf_s(mFile, "setAttr \".acn\" %i;\n", acn);}
	/*If this is set to true we will attempt to reverse the direction of the axis in case it is necessary to do so for the surface normals to end up pointing to the outside of the object.*/
	void setAutoCorrectNormal(const BoolID& acn){fprintf_s(mFile,"connectAttr \"");acn.write(mFile);fprintf_s(mFile,"\" \"%s.acn\";\n",mName.c_str());}
	/*If this is set to 2, we will compute the axis, use the curve position and radius to compute the pivot for the revolve internally.  The value of the pivot and axis attributes are ignored.  If this is set to 1, we will take the supplied axis, but compute the pivot.  If this is set to 0, we will take both the supplied axis and pivot.*/
	void setComputePivotAndAxis(unsigned int cpa){if(cpa == 0) return; fprintf_s(mFile, "setAttr \".cpa\" %i;\n", cpa);}
	/*If this is set to 2, we will compute the axis, use the curve position and radius to compute the pivot for the revolve internally.  The value of the pivot and axis attributes are ignored.  If this is set to 1, we will take the supplied axis, but compute the pivot.  If this is set to 0, we will take both the supplied axis and pivot.*/
	void setComputePivotAndAxis(const UnsignedintID& cpa){fprintf_s(mFile,"connectAttr \"");cpa.write(mFile);fprintf_s(mFile,"\" \"%s.cpa\";\n",mName.c_str());}
	/*The pivot point will be this distance away from the bounding box of the curve, if computedPivot is set to true.  The value of the pivot attribute is ignored.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*The pivot point will be this distance away from the bounding box of the curve, if computedPivot is set to true.  The value of the pivot attribute is ignored.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The position on the curve for the anchor point so that we can compute the pivot using the radius value.  If in 0 - 1 range, its on the curve, normalized parameter range.  If < 0 or > 1, its computed based on the bounding box.*/
	void setRadiusAnchor(double ra){if(ra == -1) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*The position on the curve for the anchor point so that we can compute the pivot using the radius value.  If in 0 - 1 range, its on the curve, normalized parameter range.  If < 0 or > 1, its computed based on the bounding box.*/
	void setRadiusAnchor(const DoubleID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*Only used for computed axis/pivot case.  As we are computing the axis for a planar curve, we have two choices for the major axis based axis.  We will choose the axis corresponding to the longer dimension of the object (0), or explicitly choose one or the other (choices 1 and 2).*/
	void setAxisChoice(unsigned int aco){if(aco == 0) return; fprintf_s(mFile, "setAttr \".aco\" %i;\n", aco);}
	/*Only used for computed axis/pivot case.  As we are computing the axis for a planar curve, we have two choices for the major axis based axis.  We will choose the axis corresponding to the longer dimension of the object (0), or explicitly choose one or the other (choices 1 and 2).*/
	void setAxisChoice(const UnsignedintID& aco){fprintf_s(mFile,"connectAttr \"");aco.write(mFile);fprintf_s(mFile,"\" \"%s.aco\";\n",mName.c_str());}
	/*If true, we will close a partial revolve to get a pie shaped surface.  The surface will be closed, but not periodic the way it is in the full revolve case.*/
	void setBridge(bool br){if(br == false) return; fprintf_s(mFile, "setAttr \".br\" %i;\n", br);}
	/*If true, we will close a partial revolve to get a pie shaped surface.  The surface will be closed, but not periodic the way it is in the full revolve case.*/
	void setBridge(const BoolID& br){fprintf_s(mFile,"connectAttr \"");br.write(mFile);fprintf_s(mFile,"\" \"%s.br\";\n",mName.c_str());}
	/*Output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*If we have a partial revolve, this curve can be used to bridge the surface into a pie shaped one.*/
	void setBridgeCurve(const NurbsCurveID& bc){fprintf_s(mFile,"connectAttr \"");bc.write(mFile);fprintf_s(mFile,"\" \"%s.bc\";\n",mName.c_str());}
	/*Computed axis if computePivotAndAxis attribute was set to non-zero.*/
	void setCompAxis(const Double3ID& ca){fprintf_s(mFile,"connectAttr \"");ca.write(mFile);fprintf_s(mFile,"\" \"%s.ca\";\n",mName.c_str());}
	/*X of the computed axis if computePivotAndAxis attribute was set.*/
	void setCompAxisX(const DoubleID& cax){fprintf_s(mFile,"connectAttr \"");cax.write(mFile);fprintf_s(mFile,"\" \"%s.ca.cax\";\n",mName.c_str());}
	/*Y of the computed axis if computePivotAndAxis attribute was set.*/
	void setCompAxisY(const DoubleID& cay){fprintf_s(mFile,"connectAttr \"");cay.write(mFile);fprintf_s(mFile,"\" \"%s.ca.cay\";\n",mName.c_str());}
	/*Z of the computed axis if computePivotAndAxis attribute was set.*/
	void setCompAxisZ(const DoubleID& caz){fprintf_s(mFile,"connectAttr \"");caz.write(mFile);fprintf_s(mFile,"\" \"%s.ca.caz\";\n",mName.c_str());}
	/*Computed pivot if computePivotAndAxis attribute was set to non-zero.*/
	void setCompPivot(const Double3ID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp\";\n",mName.c_str());}
	/*X of the computed pivot.*/
	void setCompPivotX(const DoubleID& cpx){fprintf_s(mFile,"connectAttr \"");cpx.write(mFile);fprintf_s(mFile,"\" \"%s.cp.cpx\";\n",mName.c_str());}
	/*Y of the computed pivot.*/
	void setCompPivotY(const DoubleID& cpy){fprintf_s(mFile,"connectAttr \"");cpy.write(mFile);fprintf_s(mFile,"\" \"%s.cp.cpy\";\n",mName.c_str());}
	/*Z of the computed pivot.*/
	void setCompPivotZ(const DoubleID& cpz){fprintf_s(mFile,"connectAttr \"");cpz.write(mFile);fprintf_s(mFile,"\" \"%s.cp.cpz\";\n",mName.c_str());}
	/*Computed axis choice, either matching non-zero axis choice or computed from the curve.*/
	void setCompAxisChoice(const UnsignedintID& cac){fprintf_s(mFile,"connectAttr \"");cac.write(mFile);fprintf_s(mFile,"\" \"%s.cac\";\n",mName.c_str());}
	/*Computed anchor if computePivotAndAxis attribute was set to non-zero.  This is the point from which the computed pivot is radius distance away.*/
	void setCompAnchor(const Double3ID& cn){fprintf_s(mFile,"connectAttr \"");cn.write(mFile);fprintf_s(mFile,"\" \"%s.cn\";\n",mName.c_str());}
	/*X of the computed anchor.*/
	void setCompAnchorX(const DoubleID& cnx){fprintf_s(mFile,"connectAttr \"");cnx.write(mFile);fprintf_s(mFile,"\" \"%s.cn.cnx\";\n",mName.c_str());}
	/*Y of the computed anchor.*/
	void setCompAnchorY(const DoubleID& cny){fprintf_s(mFile,"connectAttr \"");cny.write(mFile);fprintf_s(mFile,"\" \"%s.cn.cny\";\n",mName.c_str());}
	/*Z of the computed anchor.*/
	void setCompAnchorZ(const DoubleID& cnz){fprintf_s(mFile,"connectAttr \"");cnz.write(mFile);fprintf_s(mFile,"\" \"%s.cn.cnz\";\n",mName.c_str());}
	/*The input curve.*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*The value for the start sweep angle, in the current units.  This must be no more than the maximum, 360 degrees, or 2 Pi radians.*/
	DoubleID getStartSweep(){char buffer[4096];sprintf_s (buffer, "%s.ssw",mName.c_str());return (const char*)buffer;}
	/*The value for the end sweep angle, in the current units.  This must be no more than the maximum, 360 degrees, or 2 Pi radians.*/
	DoubleID getEndSweep(){char buffer[4096];sprintf_s (buffer, "%s.esw",mName.c_str());return (const char*)buffer;}
	/*Use the tolerance, or the number of sections to control the sections.*/
	BoolID getUseTolerance(){char buffer[4096];sprintf_s (buffer, "%s.ut",mName.c_str());return (const char*)buffer;}
	/*The degree of the resulting surface.*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Number of sections of the resulting surface (if tolerance is not used).*/
	IntID getSections(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*Tolerance to build to (if useTolerance attribute is set)*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*Revolve axis*/
	Double3ID getAxis(){char buffer[4096];sprintf_s (buffer, "%s.ax",mName.c_str());return (const char*)buffer;}
	/*X of the axis*/
	DoubleID getAxisX(){char buffer[4096];sprintf_s (buffer, "%s.ax.axx",mName.c_str());return (const char*)buffer;}
	/*Y of the axis*/
	DoubleID getAxisY(){char buffer[4096];sprintf_s (buffer, "%s.ax.axy",mName.c_str());return (const char*)buffer;}
	/*Z of the axis*/
	DoubleID getAxisZ(){char buffer[4096];sprintf_s (buffer, "%s.ax.axz",mName.c_str());return (const char*)buffer;}
	/*Revolve pivot point*/
	Double3ID getPivot(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*X of the pivot*/
	DoubleID getPivotX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*Y of the pivot*/
	DoubleID getPivotY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*Z of the pivot*/
	DoubleID getPivotZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*If this is set to true we will attempt to reverse the direction of the axis in case it is necessary to do so for the surface normals to end up pointing to the outside of the object.*/
	BoolID getAutoCorrectNormal(){char buffer[4096];sprintf_s (buffer, "%s.acn",mName.c_str());return (const char*)buffer;}
	/*If this is set to 2, we will compute the axis, use the curve position and radius to compute the pivot for the revolve internally.  The value of the pivot and axis attributes are ignored.  If this is set to 1, we will take the supplied axis, but compute the pivot.  If this is set to 0, we will take both the supplied axis and pivot.*/
	UnsignedintID getComputePivotAndAxis(){char buffer[4096];sprintf_s (buffer, "%s.cpa",mName.c_str());return (const char*)buffer;}
	/*The pivot point will be this distance away from the bounding box of the curve, if computedPivot is set to true.  The value of the pivot attribute is ignored.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The position on the curve for the anchor point so that we can compute the pivot using the radius value.  If in 0 - 1 range, its on the curve, normalized parameter range.  If < 0 or > 1, its computed based on the bounding box.*/
	DoubleID getRadiusAnchor(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*Only used for computed axis/pivot case.  As we are computing the axis for a planar curve, we have two choices for the major axis based axis.  We will choose the axis corresponding to the longer dimension of the object (0), or explicitly choose one or the other (choices 1 and 2).*/
	UnsignedintID getAxisChoice(){char buffer[4096];sprintf_s (buffer, "%s.aco",mName.c_str());return (const char*)buffer;}
	/*If true, we will close a partial revolve to get a pie shaped surface.  The surface will be closed, but not periodic the way it is in the full revolve case.*/
	BoolID getBridge(){char buffer[4096];sprintf_s (buffer, "%s.br",mName.c_str());return (const char*)buffer;}
	/*Output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*If we have a partial revolve, this curve can be used to bridge the surface into a pie shaped one.*/
	NurbsCurveID getBridgeCurve(){char buffer[4096];sprintf_s (buffer, "%s.bc",mName.c_str());return (const char*)buffer;}
	/*Computed axis if computePivotAndAxis attribute was set to non-zero.*/
	Double3ID getCompAxis(){char buffer[4096];sprintf_s (buffer, "%s.ca",mName.c_str());return (const char*)buffer;}
	/*X of the computed axis if computePivotAndAxis attribute was set.*/
	DoubleID getCompAxisX(){char buffer[4096];sprintf_s (buffer, "%s.ca.cax",mName.c_str());return (const char*)buffer;}
	/*Y of the computed axis if computePivotAndAxis attribute was set.*/
	DoubleID getCompAxisY(){char buffer[4096];sprintf_s (buffer, "%s.ca.cay",mName.c_str());return (const char*)buffer;}
	/*Z of the computed axis if computePivotAndAxis attribute was set.*/
	DoubleID getCompAxisZ(){char buffer[4096];sprintf_s (buffer, "%s.ca.caz",mName.c_str());return (const char*)buffer;}
	/*Computed pivot if computePivotAndAxis attribute was set to non-zero.*/
	Double3ID getCompPivot(){char buffer[4096];sprintf_s (buffer, "%s.cp",mName.c_str());return (const char*)buffer;}
	/*X of the computed pivot.*/
	DoubleID getCompPivotX(){char buffer[4096];sprintf_s (buffer, "%s.cp.cpx",mName.c_str());return (const char*)buffer;}
	/*Y of the computed pivot.*/
	DoubleID getCompPivotY(){char buffer[4096];sprintf_s (buffer, "%s.cp.cpy",mName.c_str());return (const char*)buffer;}
	/*Z of the computed pivot.*/
	DoubleID getCompPivotZ(){char buffer[4096];sprintf_s (buffer, "%s.cp.cpz",mName.c_str());return (const char*)buffer;}
	/*Computed axis choice, either matching non-zero axis choice or computed from the curve.*/
	UnsignedintID getCompAxisChoice(){char buffer[4096];sprintf_s (buffer, "%s.cac",mName.c_str());return (const char*)buffer;}
	/*Computed anchor if computePivotAndAxis attribute was set to non-zero.  This is the point from which the computed pivot is radius distance away.*/
	Double3ID getCompAnchor(){char buffer[4096];sprintf_s (buffer, "%s.cn",mName.c_str());return (const char*)buffer;}
	/*X of the computed anchor.*/
	DoubleID getCompAnchorX(){char buffer[4096];sprintf_s (buffer, "%s.cn.cnx",mName.c_str());return (const char*)buffer;}
	/*Y of the computed anchor.*/
	DoubleID getCompAnchorY(){char buffer[4096];sprintf_s (buffer, "%s.cn.cny",mName.c_str());return (const char*)buffer;}
	/*Z of the computed anchor.*/
	DoubleID getCompAnchorZ(){char buffer[4096];sprintf_s (buffer, "%s.cn.cnz",mName.c_str());return (const char*)buffer;}
protected:
	Revolve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REVOLVE_H__
