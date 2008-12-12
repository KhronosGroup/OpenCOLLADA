/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURPOINTONSUBD_H__
#define __MayaDM_FURPOINTONSUBD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*"furPointOnSubd" node is used to calculate a point on the subd surface.*/
class FurPointOnSubd : public DependNode
{
public:
	/*First face index of the subd surface.*/
	struct FaceFirst{
	};
	/*Second face index of the subd surface.*/
	struct FaceSecond{
	};
public:
	FurPointOnSubd(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "furPointOnSubd"){}
	virtual ~FurPointOnSubd(){}
	/*First face index of the subd surface.*/
	void setFaceFirst(const FaceFirstID& ff){fprintf_s(mFile,"connectAttr \"");ff.write(mFile);fprintf_s(mFile,"\" \"%s.ff\";\n",mName.c_str());}
	/*Second face index of the subd surface.*/
	void setFaceSecond(const FaceSecondID& fs){fprintf_s(mFile,"connectAttr \"");fs.write(mFile);fprintf_s(mFile,"\" \"%s.fs\";\n",mName.c_str());}
	/*Defines whether the evaluation of position and normal of a point should be relative or not.*/
	void setRelative(bool rel){if(rel == true) return; fprintf_s(mFile, "setAttr \".rel\" %i;\n", rel);}
	/*Defines whether the evaluation of position and normal of a point should be relative or not.*/
	void setRelative(const BoolID& rel){fprintf_s(mFile,"connectAttr \"");rel.write(mFile);fprintf_s(mFile,"\" \"%s.rel\";\n",mName.c_str());}
	/*Defines the U paramenter of a subd face.*/
	void setUValue(double u){if(u == 0.0) return; fprintf_s(mFile, "setAttr \".u\" %f;\n", u);}
	/*Defines the U paramenter of a subd face.*/
	void setUValue(const DoubleID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*Defines the U paramenter of a subd face.*/
	void setVValue(double v){if(v == 0.0) return; fprintf_s(mFile, "setAttr \".v\" %f;\n", v);}
	/*Defines the U paramenter of a subd face.*/
	void setVValue(const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*Position of a point on the subd surface.*/
	void setPosition(const double3& p){if(p == 0.0) return; fprintf_s(mFile, "setAttr \".p\" -type \"double3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*Position of a point on the subd surface.*/
	void setPosition(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*X coordinate of a point on the subd surface.*/
	void setPositionX(double px){if(px == 0.0) return; fprintf_s(mFile, "setAttr \".px\" %f;\n", px);}
	/*X coordinate of a point on the subd surface.*/
	void setPositionX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.px\";\n",mName.c_str());}
	/*Y coordinate of a point on the subd surface.*/
	void setPositionY(double py){if(py == 0.0) return; fprintf_s(mFile, "setAttr \".py\" %f;\n", py);}
	/*Y coordinate of a point on the subd surface.*/
	void setPositionY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.py\";\n",mName.c_str());}
	/*Z coordinate of a point on the subd surface.*/
	void setPositionZ(double pz){if(pz == 0.0) return; fprintf_s(mFile, "setAttr \".pz\" %f;\n", pz);}
	/*Z coordinate of a point on the subd surface.*/
	void setPositionZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.pz\";\n",mName.c_str());}
	/*Normal of a point on the subd surface.*/
	void setNormal(const double3& n){if(n == 0.0) return; fprintf_s(mFile, "setAttr \".n\" -type \"double3\" ");n.write(mFile);fprintf_s(mFile,";\n");}
	/*Normal of a point on the subd surface.*/
	void setNormal(const Double3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*X coordinate of the normal of a point on the subd surface.*/
	void setNormalX(double nx){if(nx == 0.0) return; fprintf_s(mFile, "setAttr \".nx\" %f;\n", nx);}
	/*X coordinate of the normal of a point on the subd surface.*/
	void setNormalX(const DoubleID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.nx\";\n",mName.c_str());}
	/*Y coordinate of the normal of a point on the subd surface.*/
	void setNormalY(double ny){if(ny == 0.0) return; fprintf_s(mFile, "setAttr \".ny\" %f;\n", ny);}
	/*Y coordinate of the normal of a point on the subd surface.*/
	void setNormalY(const DoubleID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.ny\";\n",mName.c_str());}
	/*Z coordinate of the normal of a point on the subd surface.*/
	void setNormalZ(double nz){if(nz == 0.0) return; fprintf_s(mFile, "setAttr \".nz\" %f;\n", nz);}
	/*Z coordinate of the normal of a point on the subd surface.*/
	void setNormalZ(const DoubleID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.nz\";\n",mName.c_str());}
	/*First face index of the subd surface.*/
	FaceFirstID getFaceFirst(){char buffer[4096];sprintf_s (buffer, "%s.ff",mName.c_str());return (const char*)buffer;}
	/*Second face index of the subd surface.*/
	FaceSecondID getFaceSecond(){char buffer[4096];sprintf_s (buffer, "%s.fs",mName.c_str());return (const char*)buffer;}
	/*Defines whether the evaluation of position and normal of a point should be relative or not.*/
	BoolID getRelative(){char buffer[4096];sprintf_s (buffer, "%s.rel",mName.c_str());return (const char*)buffer;}
	/*Defines the U paramenter of a subd face.*/
	DoubleID getUValue(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*Defines the U paramenter of a subd face.*/
	DoubleID getVValue(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*Position of a point on the subd surface.*/
	Double3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*X coordinate of a point on the subd surface.*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.px",mName.c_str());return (const char*)buffer;}
	/*Y coordinate of a point on the subd surface.*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.py",mName.c_str());return (const char*)buffer;}
	/*Z coordinate of a point on the subd surface.*/
	DoubleID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.pz",mName.c_str());return (const char*)buffer;}
	/*Normal of a point on the subd surface.*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*X coordinate of the normal of a point on the subd surface.*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.nx",mName.c_str());return (const char*)buffer;}
	/*Y coordinate of the normal of a point on the subd surface.*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.ny",mName.c_str());return (const char*)buffer;}
	/*Z coordinate of the normal of a point on the subd surface.*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.nz",mName.c_str());return (const char*)buffer;}
protected:
	FurPointOnSubd(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FURPOINTONSUBD_H__
