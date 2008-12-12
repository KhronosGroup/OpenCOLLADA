/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AVGSURFACEPOINTS_H__
#define __MayaDM_AVGSURFACEPOINTS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The 'avgSurfacePoints' node is used to compute a weighted
 average in both position and normal of a given set of NURBS
 surface points.
 <p/>
 The i-th point to be used in the averaging process is given
 by specifying the NURBS surface at the attribute 'is[i]',
 the parameter space location on the surface 'is[i]' at
 attributes ('u[i]', 'v[i]') and any associated weight with
 the point at 'w[i]'.
 <p/>
 The attribute 'top' can be used to indicate that the specified
 (u,v) coordinates of the points are normalized. This may be
 used if the parameter space domain of the NURBS surfaces are
 not known in advance.
 <p/>
 The computed postion and normal can be obtained using the
 output attributes 'r.p' and 'r.n' respectively.
 <p/>
*/
class AvgSurfacePoints : public AbstractBaseCreate
{
public:
	/*All results - container holding position, normal*/
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:
	AvgSurfacePoints(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "avgSurfacePoints"){}
	virtual ~AvgSurfacePoints(){}
	/*The input surfaces*/
	void setInputSurfaces(size_t is_i,const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is[%i]\";\n",mName.c_str(),is_i);}
	/*The weighting factor for each point*/
	void setWeight(size_t wt_i,double wt){if(wt == 0.5) return; fprintf_s(mFile, "setAttr \".wt[%i]\" %f;\n", wt_i,wt);}
	/*The weighting factor for each point*/
	void setWeight(size_t wt_i,const DoubleID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.wt[%i]\";\n",mName.c_str(),wt_i);}
	/*The U parameter value on surface*/
	void setParameterU(size_t u_i,double u){if(u == 0.0) return; fprintf_s(mFile, "setAttr \".u[%i]\" %f;\n", u_i,u);}
	/*The U parameter value on surface*/
	void setParameterU(size_t u_i,const DoubleID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u[%i]\";\n",mName.c_str(),u_i);}
	/*The V parameter value on surface*/
	void setParameterV(size_t v_i,double v){if(v == 0.0) return; fprintf_s(mFile, "setAttr \".v[%i]\" %f;\n", v_i,v);}
	/*The V parameter value on surface*/
	void setParameterV(size_t v_i,const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i]\";\n",mName.c_str(),v_i);}
	/*Whether the parameter is normalized (0,1) or not*/
	void setTurnOnPercentage(bool top){if(top == false) return; fprintf_s(mFile, "setAttr \".top\" %i;\n", top);}
	/*Whether the parameter is normalized (0,1) or not*/
	void setTurnOnPercentage(const BoolID& top){fprintf_s(mFile,"connectAttr \"");top.write(mFile);fprintf_s(mFile,"\" \"%s.top\";\n",mName.c_str());}
	/*All results - container holding position, normal*/
	void setResult(const ResultID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Computed position (in result compound)*/
	void setPosition(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.r.p\";\n",mName.c_str());}
	/*Computed X value of position*/
	void setPositionX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.px\";\n",mName.c_str());}
	/*Computed Y value of position*/
	void setPositionY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.py\";\n",mName.c_str());}
	/*Computed Z value of position*/
	void setPositionZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.pz\";\n",mName.c_str());}
	/*Computed normal (in result compound)*/
	void setNormal(const Double3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.r.n\";\n",mName.c_str());}
	/*Computed X value of normal*/
	void setNormalX(const DoubleID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.nx\";\n",mName.c_str());}
	/*Computed Y value of normal*/
	void setNormalY(const DoubleID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.ny\";\n",mName.c_str());}
	/*Computed Z value of normal*/
	void setNormalZ(const DoubleID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.nz\";\n",mName.c_str());}
	/*The input surfaces*/
	const NurbsSurfaceID& getInputSurfaces(size_t is_i){char buffer[4096];sprintf_s (buffer, "%s.is[%i]",mName.c_str(),is_i);return (const char*)buffer;}
	/*The weighting factor for each point*/
	const DoubleID& getWeight(size_t wt_i){char buffer[4096];sprintf_s (buffer, "%s.wt[%i]",mName.c_str(),wt_i);return (const char*)buffer;}
	/*The U parameter value on surface*/
	const DoubleID& getParameterU(size_t u_i){char buffer[4096];sprintf_s (buffer, "%s.u[%i]",mName.c_str(),u_i);return (const char*)buffer;}
	/*The V parameter value on surface*/
	const DoubleID& getParameterV(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i]",mName.c_str(),v_i);return (const char*)buffer;}
	/*Whether the parameter is normalized (0,1) or not*/
	BoolID getTurnOnPercentage(){char buffer[4096];sprintf_s (buffer, "%s.top",mName.c_str());return (const char*)buffer;}
	/*All results - container holding position, normal*/
	ResultID getResult(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Computed position (in result compound)*/
	Double3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.r.p",mName.c_str());return (const char*)buffer;}
	/*Computed X value of position*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.r.p.px",mName.c_str());return (const char*)buffer;}
	/*Computed Y value of position*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.r.p.py",mName.c_str());return (const char*)buffer;}
	/*Computed Z value of position*/
	DoubleID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.r.p.pz",mName.c_str());return (const char*)buffer;}
	/*Computed normal (in result compound)*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.r.n",mName.c_str());return (const char*)buffer;}
	/*Computed X value of normal*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.r.n.nx",mName.c_str());return (const char*)buffer;}
	/*Computed Y value of normal*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.r.n.ny",mName.c_str());return (const char*)buffer;}
	/*Computed Z value of normal*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.r.n.nz",mName.c_str());return (const char*)buffer;}
protected:
	AvgSurfacePoints(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_AVGSURFACEPOINTS_H__
