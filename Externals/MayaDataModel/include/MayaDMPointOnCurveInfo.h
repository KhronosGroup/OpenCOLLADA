/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POINTONCURVEINFO_H__
#define __MayaDM_POINTONCURVEINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute information associated with a point on a nurbs curve.  The point
 is specified with the input curve (inputCurve) and the parameter value
 (parameter), either in the curve domain or in the 0-1 domain (if
 turnOnPercentage is set to true.)  The information available is: position,
 curve normal (normalized to length 1 in normalizedNormal), curve tangent
 normalized to length 1 in normalizedTangent), curvature radius
 (curvatureRadius) and the center of curvature (curvatureCenter.)
*/
class PointOnCurveInfo : public AbstractBaseCreate
{
public:
	/*All results - container holding position, tangent, normal, etc.*/
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:
	PointOnCurveInfo(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "pointOnCurveInfo"){}
	virtual ~PointOnCurveInfo(){}
	/*Input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*The parameter value on curve to investigate*/
	void setParameter(double pr){if(pr == 0.0) return; fprintf_s(mFile, "setAttr \".pr\" %f;\n", pr);}
	/*The parameter value on curve to investigate*/
	void setParameter(const DoubleID& pr){fprintf_s(mFile,"connectAttr \"");pr.write(mFile);fprintf_s(mFile,"\" \"%s.pr\";\n",mName.c_str());}
	/*If set, the parameter value should be specified in 0,1 range*/
	void setTurnOnPercentage(bool top){if(top == false) return; fprintf_s(mFile, "setAttr \".top\" %i;\n", top);}
	/*If set, the parameter value should be specified in 0,1 range*/
	void setTurnOnPercentage(const BoolID& top){fprintf_s(mFile,"connectAttr \"");top.write(mFile);fprintf_s(mFile,"\" \"%s.top\";\n",mName.c_str());}
	/*All results - container holding position, tangent, normal, etc.*/
	void setResult(const ResultID& rs){fprintf_s(mFile,"connectAttr \"");rs.write(mFile);fprintf_s(mFile,"\" \"%s.rs\";\n",mName.c_str());}
	/*Position (in result compound)*/
	void setPosition(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.rs.p\";\n",mName.c_str());}
	/*X value of position*/
	void setPositionX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.rs.p.px\";\n",mName.c_str());}
	/*Y value of position*/
	void setPositionY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.rs.p.py\";\n",mName.c_str());}
	/*Z value of position*/
	void setPositionZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.rs.p.pz\";\n",mName.c_str());}
	/*Normal (in result compound)*/
	void setNormal(const Double3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.rs.n\";\n",mName.c_str());}
	/*X value of normal*/
	void setNormalX(const DoubleID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.rs.n.nx\";\n",mName.c_str());}
	/*Y value of normal*/
	void setNormalY(const DoubleID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.rs.n.ny\";\n",mName.c_str());}
	/*Z value of normal*/
	void setNormalZ(const DoubleID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.rs.n.nz\";\n",mName.c_str());}
	/*Normalized (length 1) normal (in result compound)*/
	void setNormalizedNormal(const Double3ID& nn){fprintf_s(mFile,"connectAttr \"");nn.write(mFile);fprintf_s(mFile,"\" \"%s.rs.nn\";\n",mName.c_str());}
	/*X value of normalized normal*/
	void setNormalizedNormalX(const DoubleID& nnx){fprintf_s(mFile,"connectAttr \"");nnx.write(mFile);fprintf_s(mFile,"\" \"%s.rs.nn.nnx\";\n",mName.c_str());}
	/*Y value of normalized normal*/
	void setNormalizedNormalY(const DoubleID& nny){fprintf_s(mFile,"connectAttr \"");nny.write(mFile);fprintf_s(mFile,"\" \"%s.rs.nn.nny\";\n",mName.c_str());}
	/*Z value of normalized normal*/
	void setNormalizedNormalZ(const DoubleID& nnz){fprintf_s(mFile,"connectAttr \"");nnz.write(mFile);fprintf_s(mFile,"\" \"%s.rs.nn.nnz\";\n",mName.c_str());}
	/*Tangent (in result compound)*/
	void setTangent(const Double3ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.rs.t\";\n",mName.c_str());}
	/*X value of tangent*/
	void setTangentX(const DoubleID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.rs.t.tx\";\n",mName.c_str());}
	/*Y value of tangent*/
	void setTangentY(const DoubleID& ty){fprintf_s(mFile,"connectAttr \"");ty.write(mFile);fprintf_s(mFile,"\" \"%s.rs.t.ty\";\n",mName.c_str());}
	/*Z value of tangent*/
	void setTangentZ(const DoubleID& tz){fprintf_s(mFile,"connectAttr \"");tz.write(mFile);fprintf_s(mFile,"\" \"%s.rs.t.tz\";\n",mName.c_str());}
	/*Normalized (length 1) tangent (in result compound)*/
	void setNormalizedTangent(const Double3ID& nt){fprintf_s(mFile,"connectAttr \"");nt.write(mFile);fprintf_s(mFile,"\" \"%s.rs.nt\";\n",mName.c_str());}
	/*X value of normalized tangent*/
	void setNormalizedTangentX(const DoubleID& ntx){fprintf_s(mFile,"connectAttr \"");ntx.write(mFile);fprintf_s(mFile,"\" \"%s.rs.nt.ntx\";\n",mName.c_str());}
	/*Y value of normalized tangent*/
	void setNormalizedTangentY(const DoubleID& nty){fprintf_s(mFile,"connectAttr \"");nty.write(mFile);fprintf_s(mFile,"\" \"%s.rs.nt.nty\";\n",mName.c_str());}
	/*Z value of normalized tangent*/
	void setNormalizedTangentZ(const DoubleID& ntz){fprintf_s(mFile,"connectAttr \"");ntz.write(mFile);fprintf_s(mFile,"\" \"%s.rs.nt.ntz\";\n",mName.c_str());}
	/*Center of curvature (in result compound)*/
	void setCurvatureCenter(const Double3ID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.rs.cc\";\n",mName.c_str());}
	/*X value of center of curvature*/
	void setCurvatureCenterX(const DoubleID& ccx){fprintf_s(mFile,"connectAttr \"");ccx.write(mFile);fprintf_s(mFile,"\" \"%s.rs.cc.ccx\";\n",mName.c_str());}
	/*Y value of center of curvature*/
	void setCurvatureCenterY(const DoubleID& ccy){fprintf_s(mFile,"connectAttr \"");ccy.write(mFile);fprintf_s(mFile,"\" \"%s.rs.cc.ccy\";\n",mName.c_str());}
	/*Z value of center of curvature*/
	void setCurvatureCenterZ(const DoubleID& ccz){fprintf_s(mFile,"connectAttr \"");ccz.write(mFile);fprintf_s(mFile,"\" \"%s.rs.cc.ccz\";\n",mName.c_str());}
	/*Radius of curvature (in result compound)*/
	void setCurvatureRadius(const DoubleID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.rs.cr\";\n",mName.c_str());}
	/*Input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*The parameter value on curve to investigate*/
	DoubleID getParameter(){char buffer[4096];sprintf_s (buffer, "%s.pr",mName.c_str());return (const char*)buffer;}
	/*If set, the parameter value should be specified in 0,1 range*/
	BoolID getTurnOnPercentage(){char buffer[4096];sprintf_s (buffer, "%s.top",mName.c_str());return (const char*)buffer;}
	/*All results - container holding position, tangent, normal, etc.*/
	ResultID getResult(){char buffer[4096];sprintf_s (buffer, "%s.rs",mName.c_str());return (const char*)buffer;}
	/*Position (in result compound)*/
	Double3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.rs.p",mName.c_str());return (const char*)buffer;}
	/*X value of position*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.rs.p.px",mName.c_str());return (const char*)buffer;}
	/*Y value of position*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.rs.p.py",mName.c_str());return (const char*)buffer;}
	/*Z value of position*/
	DoubleID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.rs.p.pz",mName.c_str());return (const char*)buffer;}
	/*Normal (in result compound)*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.rs.n",mName.c_str());return (const char*)buffer;}
	/*X value of normal*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.rs.n.nx",mName.c_str());return (const char*)buffer;}
	/*Y value of normal*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.rs.n.ny",mName.c_str());return (const char*)buffer;}
	/*Z value of normal*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.rs.n.nz",mName.c_str());return (const char*)buffer;}
	/*Normalized (length 1) normal (in result compound)*/
	Double3ID getNormalizedNormal(){char buffer[4096];sprintf_s (buffer, "%s.rs.nn",mName.c_str());return (const char*)buffer;}
	/*X value of normalized normal*/
	DoubleID getNormalizedNormalX(){char buffer[4096];sprintf_s (buffer, "%s.rs.nn.nnx",mName.c_str());return (const char*)buffer;}
	/*Y value of normalized normal*/
	DoubleID getNormalizedNormalY(){char buffer[4096];sprintf_s (buffer, "%s.rs.nn.nny",mName.c_str());return (const char*)buffer;}
	/*Z value of normalized normal*/
	DoubleID getNormalizedNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.rs.nn.nnz",mName.c_str());return (const char*)buffer;}
	/*Tangent (in result compound)*/
	Double3ID getTangent(){char buffer[4096];sprintf_s (buffer, "%s.rs.t",mName.c_str());return (const char*)buffer;}
	/*X value of tangent*/
	DoubleID getTangentX(){char buffer[4096];sprintf_s (buffer, "%s.rs.t.tx",mName.c_str());return (const char*)buffer;}
	/*Y value of tangent*/
	DoubleID getTangentY(){char buffer[4096];sprintf_s (buffer, "%s.rs.t.ty",mName.c_str());return (const char*)buffer;}
	/*Z value of tangent*/
	DoubleID getTangentZ(){char buffer[4096];sprintf_s (buffer, "%s.rs.t.tz",mName.c_str());return (const char*)buffer;}
	/*Normalized (length 1) tangent (in result compound)*/
	Double3ID getNormalizedTangent(){char buffer[4096];sprintf_s (buffer, "%s.rs.nt",mName.c_str());return (const char*)buffer;}
	/*X value of normalized tangent*/
	DoubleID getNormalizedTangentX(){char buffer[4096];sprintf_s (buffer, "%s.rs.nt.ntx",mName.c_str());return (const char*)buffer;}
	/*Y value of normalized tangent*/
	DoubleID getNormalizedTangentY(){char buffer[4096];sprintf_s (buffer, "%s.rs.nt.nty",mName.c_str());return (const char*)buffer;}
	/*Z value of normalized tangent*/
	DoubleID getNormalizedTangentZ(){char buffer[4096];sprintf_s (buffer, "%s.rs.nt.ntz",mName.c_str());return (const char*)buffer;}
	/*Center of curvature (in result compound)*/
	Double3ID getCurvatureCenter(){char buffer[4096];sprintf_s (buffer, "%s.rs.cc",mName.c_str());return (const char*)buffer;}
	/*X value of center of curvature*/
	DoubleID getCurvatureCenterX(){char buffer[4096];sprintf_s (buffer, "%s.rs.cc.ccx",mName.c_str());return (const char*)buffer;}
	/*Y value of center of curvature*/
	DoubleID getCurvatureCenterY(){char buffer[4096];sprintf_s (buffer, "%s.rs.cc.ccy",mName.c_str());return (const char*)buffer;}
	/*Z value of center of curvature*/
	DoubleID getCurvatureCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.rs.cc.ccz",mName.c_str());return (const char*)buffer;}
	/*Radius of curvature (in result compound)*/
	DoubleID getCurvatureRadius(){char buffer[4096];sprintf_s (buffer, "%s.rs.cr",mName.c_str());return (const char*)buffer;}
protected:
	PointOnCurveInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POINTONCURVEINFO_H__
