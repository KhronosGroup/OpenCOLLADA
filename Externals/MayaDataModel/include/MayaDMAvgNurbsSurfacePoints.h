/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AVGNURBSSURFACEPOINTS_H__
#define __MayaDM_AVGNURBSSURFACEPOINTS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The avgNurbsSurfacePoints node computes the weighted average in
 position and normal of one or more NURBS surface points.
 The points could be specified as surface parameter (u,v) points
 or surface control vertex(CV) indices (i,j).
 <p/>
 The i-th surface point in XYZ space is computed by evaluating
 the input NURBS surface connected to `sp[i].is` at
 (sp[i].u, sp[i].v). The computed position and normal is weighted by
 a factor of `sp[i].wt`. If the i-th surface point is given as CV indices,
 the normal at the CV is computed as the normal at the greville point
 corresponding to the CV.
 <p/>
 The output attribute 'result' gives both the position and normal.
 <p/>
 The output attribute 'position' gives the position. To get
 only the weighted average position connect to attribute `r.p` on the node.
 <p/>
 The output attribute 'normal' gives the normal. To get
 only the weighted average normal connect to attribute `r.n` on the node.
 <p/>
 Use this node to compute the center of mass one or more NURBS surface points.
*/
class AvgNurbsSurfacePoints : public AbstractBaseCreate
{
public:
	/*Place Holder housing a surface point information.*/
	struct SurfacePoint{
		nurbsSurface inputSurface;
		double weight;
		double parameterU;
		double parameterV;
		int cvIthIndex;
		int cvJthIndex;
		void write(FILE* file) const
		{
			inputSurface.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f ", weight);
			fprintf_s(file,"%f ", parameterU);
			fprintf_s(file,"%f ", parameterV);
			fprintf_s(file,"%i ", cvIthIndex);
			fprintf_s(file,"%i", cvJthIndex);
		}
	};
	/*All results - container holding weighted position, normal*/
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:
	AvgNurbsSurfacePoints(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "avgNurbsSurfacePoints"){}
	virtual ~AvgNurbsSurfacePoints(){}
	/*Place Holder housing a surface point information.*/
	void setSurfacePoint(size_t sp_i,const SurfacePoint& sp){fprintf_s(mFile, "setAttr \".sp[%i]\" ",sp_i);sp.write(mFile);fprintf_s(mFile,";\n");}
	/*The input surface*/
	void setInputSurface(size_t sp_i,const nurbsSurface& is){fprintf_s(mFile, "setAttr \".sp[%i].is\" -type \"nurbsSurface\" ",sp_i);is.write(mFile);fprintf_s(mFile,";\n");}
	/*The input surface*/
	void setInputSurface(size_t sp_i,const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.sp[%i].is\";\n",mName.c_str(),sp_i);}
	/*The weighting factor for point.*/
	void setWeight(size_t sp_i,double wt){if(wt == 0.5) return; fprintf_s(mFile, "setAttr \".sp[%i].wt\" %f;\n", sp_i,wt);}
	/*The weighting factor for point.*/
	void setWeight(size_t sp_i,const DoubleID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.sp[%i].wt\";\n",mName.c_str(),sp_i);}
	/*The U parameter value on surface*/
	void setParameterU(size_t sp_i,double u){if(u == -1000.0) return; fprintf_s(mFile, "setAttr \".sp[%i].u\" %f;\n", sp_i,u);}
	/*The U parameter value on surface*/
	void setParameterU(size_t sp_i,const DoubleID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.sp[%i].u\";\n",mName.c_str(),sp_i);}
	/*The V parameter value on surface*/
	void setParameterV(size_t sp_i,double v){if(v == -1000.0) return; fprintf_s(mFile, "setAttr \".sp[%i].v\" %f;\n", sp_i,v);}
	/*The V parameter value on surface*/
	void setParameterV(size_t sp_i,const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.sp[%i].v\";\n",mName.c_str(),sp_i);}
	/*The index for the ith cv index*/
	void setCvIthIndex(size_t sp_i,int ci){if(ci == -1) return; fprintf_s(mFile, "setAttr \".sp[%i].ci\" %i;\n", sp_i,ci);}
	/*The index for the ith cv index*/
	void setCvIthIndex(size_t sp_i,const IntID& ci){fprintf_s(mFile,"connectAttr \"");ci.write(mFile);fprintf_s(mFile,"\" \"%s.sp[%i].ci\";\n",mName.c_str(),sp_i);}
	/*The index for the jth cv index*/
	void setCvJthIndex(size_t sp_i,int cj){if(cj == -1) return; fprintf_s(mFile, "setAttr \".sp[%i].cj\" %i;\n", sp_i,cj);}
	/*The index for the jth cv index*/
	void setCvJthIndex(size_t sp_i,const IntID& cj){fprintf_s(mFile,"connectAttr \"");cj.write(mFile);fprintf_s(mFile,"\" \"%s.sp[%i].cj\";\n",mName.c_str(),sp_i);}
	/*All results - container holding weighted position, normal*/
	void setResult(const ResultID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Computed weighted position (in result compound)*/
	void setPosition(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.r.p\";\n",mName.c_str());}
	/*Computed X value of position*/
	void setPositionX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.px\";\n",mName.c_str());}
	/*Computed Y value of position*/
	void setPositionY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.py\";\n",mName.c_str());}
	/*Computed Z value of position*/
	void setPositionZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.pz\";\n",mName.c_str());}
	/*Computed weighted normal (in result compound)*/
	void setNormal(const Double3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.r.n\";\n",mName.c_str());}
	/*Computed X value of normal*/
	void setNormalX(const DoubleID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.nx\";\n",mName.c_str());}
	/*Computed Y value of normal*/
	void setNormalY(const DoubleID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.ny\";\n",mName.c_str());}
	/*Computed Z value of normal*/
	void setNormalZ(const DoubleID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.nz\";\n",mName.c_str());}
	/*The input surface*/
	const NurbsSurfaceID& getInputSurface(size_t sp_i){char buffer[4096];sprintf_s (buffer, "%s.sp[%i].is",mName.c_str(),sp_i);return (const char*)buffer;}
	/*The weighting factor for point.*/
	const DoubleID& getWeight(size_t sp_i){char buffer[4096];sprintf_s (buffer, "%s.sp[%i].wt",mName.c_str(),sp_i);return (const char*)buffer;}
	/*The U parameter value on surface*/
	const DoubleID& getParameterU(size_t sp_i){char buffer[4096];sprintf_s (buffer, "%s.sp[%i].u",mName.c_str(),sp_i);return (const char*)buffer;}
	/*The V parameter value on surface*/
	const DoubleID& getParameterV(size_t sp_i){char buffer[4096];sprintf_s (buffer, "%s.sp[%i].v",mName.c_str(),sp_i);return (const char*)buffer;}
	/*The index for the ith cv index*/
	const IntID& getCvIthIndex(size_t sp_i){char buffer[4096];sprintf_s (buffer, "%s.sp[%i].ci",mName.c_str(),sp_i);return (const char*)buffer;}
	/*The index for the jth cv index*/
	const IntID& getCvJthIndex(size_t sp_i){char buffer[4096];sprintf_s (buffer, "%s.sp[%i].cj",mName.c_str(),sp_i);return (const char*)buffer;}
	/*All results - container holding weighted position, normal*/
	ResultID getResult(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Computed weighted position (in result compound)*/
	Double3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.r.p",mName.c_str());return (const char*)buffer;}
	/*Computed X value of position*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.r.p.px",mName.c_str());return (const char*)buffer;}
	/*Computed Y value of position*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.r.p.py",mName.c_str());return (const char*)buffer;}
	/*Computed Z value of position*/
	DoubleID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.r.p.pz",mName.c_str());return (const char*)buffer;}
	/*Computed weighted normal (in result compound)*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.r.n",mName.c_str());return (const char*)buffer;}
	/*Computed X value of normal*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.r.n.nx",mName.c_str());return (const char*)buffer;}
	/*Computed Y value of normal*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.r.n.ny",mName.c_str());return (const char*)buffer;}
	/*Computed Z value of normal*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.r.n.nz",mName.c_str());return (const char*)buffer;}
protected:
	AvgNurbsSurfacePoints(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_AVGNURBSSURFACEPOINTS_H__
