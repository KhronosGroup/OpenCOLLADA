/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POINTONSURFACEINFO_H__
#define __MayaDM_POINTONSURFACEINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute information associated with a point on a nurbs surface.  The point
 is specified with the input surface (inputSurface) and the parameter value
 (parameterU and parameterV),
 either in the surface domain or in the 0-1 domain (if
 turnOnPercentage is set to true.)  The information available is: position,
 surface normal (normalized to length 1 in normalizedNormal), surface tangents
 and their normalized counterparts.
*/
class PointOnSurfaceInfo : public AbstractBaseCreate
{
public:
	/*All results - container holding position, tangents, normal etc.*/
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:
	PointOnSurfaceInfo(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "pointOnSurfaceInfo"){}
	virtual ~PointOnSurfaceInfo(){}
	/*Input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*U parameter value on surface*/
	void setParameterU(double u){if(u == 0.0) return; fprintf_s(mFile, "setAttr \".u\" %f;\n", u);}
	/*U parameter value on surface*/
	void setParameterU(const DoubleID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*V parameter value on surface*/
	void setParameterV(double v){if(v == 0.0) return; fprintf_s(mFile, "setAttr \".v\" %f;\n", v);}
	/*V parameter value on surface*/
	void setParameterV(const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*If set, the parameter values should be specified in 0,1 range*/
	void setTurnOnPercentage(bool top){if(top == false) return; fprintf_s(mFile, "setAttr \".top\" %i;\n", top);}
	/*If set, the parameter values should be specified in 0,1 range*/
	void setTurnOnPercentage(const BoolID& top){fprintf_s(mFile,"connectAttr \"");top.write(mFile);fprintf_s(mFile,"\" \"%s.top\";\n",mName.c_str());}
	/*All results - container holding position, tangents, normal etc.*/
	void setResult(const ResultID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Pposition (in result compound)*/
	void setPosition(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.r.p\";\n",mName.c_str());}
	/*X value of position*/
	void setPositionX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.px\";\n",mName.c_str());}
	/*Y value of position*/
	void setPositionY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.py\";\n",mName.c_str());}
	/*Z value of position*/
	void setPositionZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.pz\";\n",mName.c_str());}
	/*Nnormal (in result compound)*/
	void setNormal(const Double3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.r.n\";\n",mName.c_str());}
	/*X value of normal*/
	void setNormalX(const DoubleID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.nx\";\n",mName.c_str());}
	/*Y value of normal*/
	void setNormalY(const DoubleID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.ny\";\n",mName.c_str());}
	/*Z value of normal*/
	void setNormalZ(const DoubleID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.nz\";\n",mName.c_str());}
	/*Normalized normal (in result compound)*/
	void setNormalizedNormal(const Double3ID& nn){fprintf_s(mFile,"connectAttr \"");nn.write(mFile);fprintf_s(mFile,"\" \"%s.r.nn\";\n",mName.c_str());}
	/*X value of normalized normal*/
	void setNormalizedNormalX(const DoubleID& nnx){fprintf_s(mFile,"connectAttr \"");nnx.write(mFile);fprintf_s(mFile,"\" \"%s.r.nn.nnx\";\n",mName.c_str());}
	/*Y value of normalized normal*/
	void setNormalizedNormalY(const DoubleID& nny){fprintf_s(mFile,"connectAttr \"");nny.write(mFile);fprintf_s(mFile,"\" \"%s.r.nn.nny\";\n",mName.c_str());}
	/*Z value of normalized normal*/
	void setNormalizedNormalZ(const DoubleID& nnz){fprintf_s(mFile,"connectAttr \"");nnz.write(mFile);fprintf_s(mFile,"\" \"%s.r.nn.nnz\";\n",mName.c_str());}
	/*U tangent (in result compound)*/
	void setTangentU(const Double3ID& tu){fprintf_s(mFile,"connectAttr \"");tu.write(mFile);fprintf_s(mFile,"\" \"%s.r.tu\";\n",mName.c_str());}
	/*X value of U tangent*/
	void setTangentUx(const DoubleID& tux){fprintf_s(mFile,"connectAttr \"");tux.write(mFile);fprintf_s(mFile,"\" \"%s.r.tu.tux\";\n",mName.c_str());}
	/*Y value of U tangent*/
	void setTangentUy(const DoubleID& tuy){fprintf_s(mFile,"connectAttr \"");tuy.write(mFile);fprintf_s(mFile,"\" \"%s.r.tu.tuy\";\n",mName.c_str());}
	/*Z value of U tangent*/
	void setTangentUz(const DoubleID& tuz){fprintf_s(mFile,"connectAttr \"");tuz.write(mFile);fprintf_s(mFile,"\" \"%s.r.tu.tuz\";\n",mName.c_str());}
	/*Normalized U tangent (in result compound)*/
	void setNormalizedTangentU(const Double3ID& ntu){fprintf_s(mFile,"connectAttr \"");ntu.write(mFile);fprintf_s(mFile,"\" \"%s.r.ntu\";\n",mName.c_str());}
	/*X value of normalized U tangent*/
	void setNormalizedTangentUX(const DoubleID& nux){fprintf_s(mFile,"connectAttr \"");nux.write(mFile);fprintf_s(mFile,"\" \"%s.r.ntu.nux\";\n",mName.c_str());}
	/*Y value of normalized U tangent*/
	void setNormalizedTangentUY(const DoubleID& nuy){fprintf_s(mFile,"connectAttr \"");nuy.write(mFile);fprintf_s(mFile,"\" \"%s.r.ntu.nuy\";\n",mName.c_str());}
	/*Z value of normalized U tangent*/
	void setNormalizedTangentUZ(const DoubleID& nuz){fprintf_s(mFile,"connectAttr \"");nuz.write(mFile);fprintf_s(mFile,"\" \"%s.r.ntu.nuz\";\n",mName.c_str());}
	/*V tangent (in result compound)*/
	void setTangentV(const Double3ID& tv){fprintf_s(mFile,"connectAttr \"");tv.write(mFile);fprintf_s(mFile,"\" \"%s.r.tv\";\n",mName.c_str());}
	/*X value of V tangent*/
	void setTangentVx(const DoubleID& tvx){fprintf_s(mFile,"connectAttr \"");tvx.write(mFile);fprintf_s(mFile,"\" \"%s.r.tv.tvx\";\n",mName.c_str());}
	/*Y value of V tangent*/
	void setTangentVy(const DoubleID& tvy){fprintf_s(mFile,"connectAttr \"");tvy.write(mFile);fprintf_s(mFile,"\" \"%s.r.tv.tvy\";\n",mName.c_str());}
	/*Z value of V tangent*/
	void setTangentVz(const DoubleID& tvz){fprintf_s(mFile,"connectAttr \"");tvz.write(mFile);fprintf_s(mFile,"\" \"%s.r.tv.tvz\";\n",mName.c_str());}
	/*Normalized V tangent (in result compound)*/
	void setNormalizedTangentV(const Double3ID& ntv){fprintf_s(mFile,"connectAttr \"");ntv.write(mFile);fprintf_s(mFile,"\" \"%s.r.ntv\";\n",mName.c_str());}
	/*X value of normalized V tangent*/
	void setNormalizedTangentVX(const DoubleID& nvx){fprintf_s(mFile,"connectAttr \"");nvx.write(mFile);fprintf_s(mFile,"\" \"%s.r.ntv.nvx\";\n",mName.c_str());}
	/*Y value of normalized V tangent*/
	void setNormalizedTangentVY(const DoubleID& nvy){fprintf_s(mFile,"connectAttr \"");nvy.write(mFile);fprintf_s(mFile,"\" \"%s.r.ntv.nvy\";\n",mName.c_str());}
	/*Z value of normalized V tangent*/
	void setNormalizedTangentVZ(const DoubleID& nvz){fprintf_s(mFile,"connectAttr \"");nvz.write(mFile);fprintf_s(mFile,"\" \"%s.r.ntv.nvz\";\n",mName.c_str());}
	/*Input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*U parameter value on surface*/
	DoubleID getParameterU(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*V parameter value on surface*/
	DoubleID getParameterV(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*If set, the parameter values should be specified in 0,1 range*/
	BoolID getTurnOnPercentage(){char buffer[4096];sprintf_s (buffer, "%s.top",mName.c_str());return (const char*)buffer;}
	/*All results - container holding position, tangents, normal etc.*/
	ResultID getResult(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Pposition (in result compound)*/
	Double3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.r.p",mName.c_str());return (const char*)buffer;}
	/*X value of position*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.r.p.px",mName.c_str());return (const char*)buffer;}
	/*Y value of position*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.r.p.py",mName.c_str());return (const char*)buffer;}
	/*Z value of position*/
	DoubleID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.r.p.pz",mName.c_str());return (const char*)buffer;}
	/*Nnormal (in result compound)*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.r.n",mName.c_str());return (const char*)buffer;}
	/*X value of normal*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.r.n.nx",mName.c_str());return (const char*)buffer;}
	/*Y value of normal*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.r.n.ny",mName.c_str());return (const char*)buffer;}
	/*Z value of normal*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.r.n.nz",mName.c_str());return (const char*)buffer;}
	/*Normalized normal (in result compound)*/
	Double3ID getNormalizedNormal(){char buffer[4096];sprintf_s (buffer, "%s.r.nn",mName.c_str());return (const char*)buffer;}
	/*X value of normalized normal*/
	DoubleID getNormalizedNormalX(){char buffer[4096];sprintf_s (buffer, "%s.r.nn.nnx",mName.c_str());return (const char*)buffer;}
	/*Y value of normalized normal*/
	DoubleID getNormalizedNormalY(){char buffer[4096];sprintf_s (buffer, "%s.r.nn.nny",mName.c_str());return (const char*)buffer;}
	/*Z value of normalized normal*/
	DoubleID getNormalizedNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.r.nn.nnz",mName.c_str());return (const char*)buffer;}
	/*U tangent (in result compound)*/
	Double3ID getTangentU(){char buffer[4096];sprintf_s (buffer, "%s.r.tu",mName.c_str());return (const char*)buffer;}
	/*X value of U tangent*/
	DoubleID getTangentUx(){char buffer[4096];sprintf_s (buffer, "%s.r.tu.tux",mName.c_str());return (const char*)buffer;}
	/*Y value of U tangent*/
	DoubleID getTangentUy(){char buffer[4096];sprintf_s (buffer, "%s.r.tu.tuy",mName.c_str());return (const char*)buffer;}
	/*Z value of U tangent*/
	DoubleID getTangentUz(){char buffer[4096];sprintf_s (buffer, "%s.r.tu.tuz",mName.c_str());return (const char*)buffer;}
	/*Normalized U tangent (in result compound)*/
	Double3ID getNormalizedTangentU(){char buffer[4096];sprintf_s (buffer, "%s.r.ntu",mName.c_str());return (const char*)buffer;}
	/*X value of normalized U tangent*/
	DoubleID getNormalizedTangentUX(){char buffer[4096];sprintf_s (buffer, "%s.r.ntu.nux",mName.c_str());return (const char*)buffer;}
	/*Y value of normalized U tangent*/
	DoubleID getNormalizedTangentUY(){char buffer[4096];sprintf_s (buffer, "%s.r.ntu.nuy",mName.c_str());return (const char*)buffer;}
	/*Z value of normalized U tangent*/
	DoubleID getNormalizedTangentUZ(){char buffer[4096];sprintf_s (buffer, "%s.r.ntu.nuz",mName.c_str());return (const char*)buffer;}
	/*V tangent (in result compound)*/
	Double3ID getTangentV(){char buffer[4096];sprintf_s (buffer, "%s.r.tv",mName.c_str());return (const char*)buffer;}
	/*X value of V tangent*/
	DoubleID getTangentVx(){char buffer[4096];sprintf_s (buffer, "%s.r.tv.tvx",mName.c_str());return (const char*)buffer;}
	/*Y value of V tangent*/
	DoubleID getTangentVy(){char buffer[4096];sprintf_s (buffer, "%s.r.tv.tvy",mName.c_str());return (const char*)buffer;}
	/*Z value of V tangent*/
	DoubleID getTangentVz(){char buffer[4096];sprintf_s (buffer, "%s.r.tv.tvz",mName.c_str());return (const char*)buffer;}
	/*Normalized V tangent (in result compound)*/
	Double3ID getNormalizedTangentV(){char buffer[4096];sprintf_s (buffer, "%s.r.ntv",mName.c_str());return (const char*)buffer;}
	/*X value of normalized V tangent*/
	DoubleID getNormalizedTangentVX(){char buffer[4096];sprintf_s (buffer, "%s.r.ntv.nvx",mName.c_str());return (const char*)buffer;}
	/*Y value of normalized V tangent*/
	DoubleID getNormalizedTangentVY(){char buffer[4096];sprintf_s (buffer, "%s.r.ntv.nvy",mName.c_str());return (const char*)buffer;}
	/*Z value of normalized V tangent*/
	DoubleID getNormalizedTangentVZ(){char buffer[4096];sprintf_s (buffer, "%s.r.ntv.nvz",mName.c_str());return (const char*)buffer;}
protected:
	PointOnSurfaceInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POINTONSURFACEINFO_H__
