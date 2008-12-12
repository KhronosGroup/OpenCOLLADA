/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURPOINTONMESHINFO_H__
#define __MayaDM_FURPOINTONMESHINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*"furPointOnMeshInfo" node is used to calculate a point on the mesh surface.*/
class FurPointOnMeshInfo : public DependNode
{
public:
	/*Face index of the mesh surface.*/
	struct FaceIndex{
	};
public:
	FurPointOnMeshInfo(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "furPointOnMeshInfo"){}
	virtual ~FurPointOnMeshInfo(){}
	/*The input surface which is used to calculate a point on the polygon.*/
	void setInMesh(const mesh& im){fprintf_s(mFile, "setAttr \".im\" -type \"mesh\" ");im.write(mFile);fprintf_s(mFile,";\n");}
	/*Face index of the mesh surface.*/
	void setFaceIndex(const FaceIndexID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Defines whether the evaluation of position and normal of a point should be relative or not.*/
	void setRelative(bool r){if(r == true) return; fprintf_s(mFile, "setAttr \".r\" %i;\n", r);}
	/*Defines whether the evaluation of position and normal of a point should be relative or not.*/
	void setRelative(const BoolID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Defines the U paramenter of a face.*/
	void setParameterU(double u){if(u == 0.0) return; fprintf_s(mFile, "setAttr \".u\" %f;\n", u);}
	/*Defines the U paramenter of a face.*/
	void setParameterU(const DoubleID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*Defines the U paramenter of a face.*/
	void setParameterV(double v){if(v == 0.0) return; fprintf_s(mFile, "setAttr \".v\" %f;\n", v);}
	/*Defines the U paramenter of a face.*/
	void setParameterV(const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*Position of a point on the mesh surface.*/
	void setPosition(const double3& p){if(p == 0.0) return; fprintf_s(mFile, "setAttr \".p\" -type \"double3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*Position of a point on the mesh surface.*/
	void setPosition(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*X coordinate of a point on the mesh surface.*/
	void setPositionX(double px){if(px == 0.0) return; fprintf_s(mFile, "setAttr \".px\" %f;\n", px);}
	/*X coordinate of a point on the mesh surface.*/
	void setPositionX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.px\";\n",mName.c_str());}
	/*Y coordinate of a point on the mesh surface.*/
	void setPositionY(double py){if(py == 0.0) return; fprintf_s(mFile, "setAttr \".py\" %f;\n", py);}
	/*Y coordinate of a point on the mesh surface.*/
	void setPositionY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.py\";\n",mName.c_str());}
	/*Z coordinate of a point on the mesh surface.*/
	void setPositionZ(double pz){if(pz == 0.0) return; fprintf_s(mFile, "setAttr \".pz\" %f;\n", pz);}
	/*Z coordinate of a point on the mesh surface.*/
	void setPositionZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.pz\";\n",mName.c_str());}
	/*Normal of a point on the mesh surface.*/
	void setNormal(const double3& n){if(n == 0.0) return; fprintf_s(mFile, "setAttr \".n\" -type \"double3\" ");n.write(mFile);fprintf_s(mFile,";\n");}
	/*Normal of a point on the mesh surface.*/
	void setNormal(const Double3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*X coordinate of the normal of a point on the mesh surface.*/
	void setNormalX(double nx){if(nx == 0.0) return; fprintf_s(mFile, "setAttr \".nx\" %f;\n", nx);}
	/*X coordinate of the normal of a point on the mesh surface.*/
	void setNormalX(const DoubleID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.nx\";\n",mName.c_str());}
	/*Y coordinate of the normal of a point on the mesh surface.*/
	void setNormalY(double ny){if(ny == 0.0) return; fprintf_s(mFile, "setAttr \".ny\" %f;\n", ny);}
	/*Y coordinate of the normal of a point on the mesh surface.*/
	void setNormalY(const DoubleID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.ny\";\n",mName.c_str());}
	/*Z coordinate of the normal of a point on the mesh surface.*/
	void setNormalZ(double nz){if(nz == 0.0) return; fprintf_s(mFile, "setAttr \".nz\" %f;\n", nz);}
	/*Z coordinate of the normal of a point on the mesh surface.*/
	void setNormalZ(const DoubleID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.nz\";\n",mName.c_str());}
	/*Face index of the mesh surface.*/
	FaceIndexID getFaceIndex(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*Defines whether the evaluation of position and normal of a point should be relative or not.*/
	BoolID getRelative(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Defines the U paramenter of a face.*/
	DoubleID getParameterU(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*Defines the U paramenter of a face.*/
	DoubleID getParameterV(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*Position of a point on the mesh surface.*/
	Double3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*X coordinate of a point on the mesh surface.*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.px",mName.c_str());return (const char*)buffer;}
	/*Y coordinate of a point on the mesh surface.*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.py",mName.c_str());return (const char*)buffer;}
	/*Z coordinate of a point on the mesh surface.*/
	DoubleID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.pz",mName.c_str());return (const char*)buffer;}
	/*Normal of a point on the mesh surface.*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*X coordinate of the normal of a point on the mesh surface.*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.nx",mName.c_str());return (const char*)buffer;}
	/*Y coordinate of the normal of a point on the mesh surface.*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.ny",mName.c_str());return (const char*)buffer;}
	/*Z coordinate of the normal of a point on the mesh surface.*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.nz",mName.c_str());return (const char*)buffer;}
protected:
	FurPointOnMeshInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FURPOINTONMESHINFO_H__
