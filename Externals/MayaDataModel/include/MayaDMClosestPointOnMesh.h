/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOSESTPOINTONMESH_H__
#define __MayaDM_CLOSESTPOINTONMESH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> This node returns the closest point of an (x,y,z) point (attribute
 "inPosition") to a mesh (given by the attribute "inputMesh").
 You can query the closest
 (x,y,z) point (attribute "position") or you can query the closest
 mesh (u,v) point (given by attributes "parameterU" and "parameterV").
</pre></p>
*/
class ClosestPointOnMesh : public DependNode
{
public:
	/*All results - container holding closest point, its normal, u and v parameter values and closest face index.*/
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:
	ClosestPointOnMesh(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "closestPointOnMesh"){}
	virtual ~ClosestPointOnMesh(){}
	/*The input mesh for the info*/
	void setInMesh(const MeshID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im\";\n",mName.c_str());}
	/*Input reference point*/
	void setInPosition(const double3& ip){if(ip == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ip\" -type \"double3\" ");ip.write(mFile);fprintf_s(mFile,";\n");}
	/*Input reference point*/
	void setInPosition(const Double3ID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip\";\n",mName.c_str());}
	/*Input X value of reference position*/
	void setInPositionX(double ipx){if(ipx == 0) return; fprintf_s(mFile, "setAttr \".ip.ipx\" %f;\n", ipx);}
	/*Input X value of reference position*/
	void setInPositionX(const DoubleID& ipx){fprintf_s(mFile,"connectAttr \"");ipx.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipx\";\n",mName.c_str());}
	/*Input Y value of reference position*/
	void setInPositionY(double ipy){if(ipy == 0) return; fprintf_s(mFile, "setAttr \".ip.ipy\" %f;\n", ipy);}
	/*Input Y value of reference position*/
	void setInPositionY(const DoubleID& ipy){fprintf_s(mFile,"connectAttr \"");ipy.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipy\";\n",mName.c_str());}
	/*Input Z value of reference position*/
	void setInPositionZ(double ipz){if(ipz == 0) return; fprintf_s(mFile, "setAttr \".ip.ipz\" %f;\n", ipz);}
	/*Input Z value of reference position*/
	void setInPositionZ(const DoubleID& ipz){fprintf_s(mFile,"connectAttr \"");ipz.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipz\";\n",mName.c_str());}
	/*All results - container holding closest point, its normal, u and v parameter values and closest face index.*/
	void setResult(const ResultID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The closest (x,y,z) point (in result compound)*/
	void setPosition(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.r.p\";\n",mName.c_str());}
	/*Computed X value of closest point*/
	void setPositionX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.px\";\n",mName.c_str());}
	/*Computed Y value of closest point*/
	void setPositionY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.py\";\n",mName.c_str());}
	/*Computed Z value of closest point*/
	void setPositionZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.pz\";\n",mName.c_str());}
	/*The U parameter value on the mesh at the closest point*/
	void setParameterU(const DoubleID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.r.u\";\n",mName.c_str());}
	/*The V parameter value on the mesh at the closest point*/
	void setParameterV(const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.r.v\";\n",mName.c_str());}
	/*The normal of the point (in result compound)*/
	void setNormal(const Double3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.r.n\";\n",mName.c_str());}
	/*X normal of closest point*/
	void setNormalX(const DoubleID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.nx\";\n",mName.c_str());}
	/*Y normal of closest point*/
	void setNormalY(const DoubleID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.ny\";\n",mName.c_str());}
	/*Z normal of closest point*/
	void setNormalZ(const DoubleID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.r.n.nz\";\n",mName.c_str());}
	/*Index of the face on which the closest point lies.*/
	void setClosestFaceIndex(const IntID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.r.f\";\n",mName.c_str());}
	/*Index of the vertex closest to position on faceIndex.*/
	void setClosestVertexIndex(const IntID& vt){fprintf_s(mFile,"connectAttr \"");vt.write(mFile);fprintf_s(mFile,"\" \"%s.r.vt\";\n",mName.c_str());}
	/*The input mesh for the info*/
	MeshID getInMesh(){char buffer[4096];sprintf_s (buffer, "%s.im",mName.c_str());return (const char*)buffer;}
	/*Input reference point*/
	Double3ID getInPosition(){char buffer[4096];sprintf_s (buffer, "%s.ip",mName.c_str());return (const char*)buffer;}
	/*Input X value of reference position*/
	DoubleID getInPositionX(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipx",mName.c_str());return (const char*)buffer;}
	/*Input Y value of reference position*/
	DoubleID getInPositionY(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipy",mName.c_str());return (const char*)buffer;}
	/*Input Z value of reference position*/
	DoubleID getInPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipz",mName.c_str());return (const char*)buffer;}
	/*All results - container holding closest point, its normal, u and v parameter values and closest face index.*/
	ResultID getResult(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The closest (x,y,z) point (in result compound)*/
	Double3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.r.p",mName.c_str());return (const char*)buffer;}
	/*Computed X value of closest point*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.r.p.px",mName.c_str());return (const char*)buffer;}
	/*Computed Y value of closest point*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.r.p.py",mName.c_str());return (const char*)buffer;}
	/*Computed Z value of closest point*/
	DoubleID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.r.p.pz",mName.c_str());return (const char*)buffer;}
	/*The U parameter value on the mesh at the closest point*/
	DoubleID getParameterU(){char buffer[4096];sprintf_s (buffer, "%s.r.u",mName.c_str());return (const char*)buffer;}
	/*The V parameter value on the mesh at the closest point*/
	DoubleID getParameterV(){char buffer[4096];sprintf_s (buffer, "%s.r.v",mName.c_str());return (const char*)buffer;}
	/*The normal of the point (in result compound)*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.r.n",mName.c_str());return (const char*)buffer;}
	/*X normal of closest point*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.r.n.nx",mName.c_str());return (const char*)buffer;}
	/*Y normal of closest point*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.r.n.ny",mName.c_str());return (const char*)buffer;}
	/*Z normal of closest point*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.r.n.nz",mName.c_str());return (const char*)buffer;}
	/*Index of the face on which the closest point lies.*/
	IntID getClosestFaceIndex(){char buffer[4096];sprintf_s (buffer, "%s.r.f",mName.c_str());return (const char*)buffer;}
	/*Index of the vertex closest to position on faceIndex.*/
	IntID getClosestVertexIndex(){char buffer[4096];sprintf_s (buffer, "%s.r.vt",mName.c_str());return (const char*)buffer;}
protected:
	ClosestPointOnMesh(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLOSESTPOINTONMESH_H__
