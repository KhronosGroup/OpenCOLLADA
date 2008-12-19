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
class FurPointOnSubd : public DependNode
{
public:
	struct FaceFirst{
	};
	struct FaceSecond{
	};
public:
	FurPointOnSubd(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "furPointOnSubd"){}
	virtual ~FurPointOnSubd(){}
	void setRelative(bool rel)
	{
		if(rel == true) return;
		fprintf(mFile,"setAttr \".rel\" %i;\n", rel);

	}
	void setUValue(double u)
	{
		if(u == 0.0) return;
		fprintf(mFile,"setAttr \".u\" %f;\n", u);

	}
	void setVValue(double v)
	{
		if(v == 0.0) return;
		fprintf(mFile,"setAttr \".v\" %f;\n", v);

	}
	void setPosition(const double3& p)
	{
		if(p == 0.0) return;
		fprintf(mFile,"setAttr \".p\" -type \"double3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPositionX(double px)
	{
		if(px == 0.0) return;
		fprintf(mFile,"setAttr \".px\" %f;\n", px);

	}
	void setPositionY(double py)
	{
		if(py == 0.0) return;
		fprintf(mFile,"setAttr \".py\" %f;\n", py);

	}
	void setPositionZ(double pz)
	{
		if(pz == 0.0) return;
		fprintf(mFile,"setAttr \".pz\" %f;\n", pz);

	}
	void setNormal(const double3& n)
	{
		if(n == 0.0) return;
		fprintf(mFile,"setAttr \".n\" -type \"double3\" ");
		n.write(mFile);
		fprintf(mFile,";\n");

	}
	void setNormalX(double nx)
	{
		if(nx == 0.0) return;
		fprintf(mFile,"setAttr \".nx\" %f;\n", nx);

	}
	void setNormalY(double ny)
	{
		if(ny == 0.0) return;
		fprintf(mFile,"setAttr \".ny\" %f;\n", ny);

	}
	void setNormalZ(double nz)
	{
		if(nz == 0.0) return;
		fprintf(mFile,"setAttr \".nz\" %f;\n", nz);

	}
	void getFaceFirst()
	{
		fprintf(mFile,"\"%s.ff\"",mName.c_str());

	}
	void getFaceSecond()
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());

	}
	void getRelative()
	{
		fprintf(mFile,"\"%s.rel\"",mName.c_str());

	}
	void getUValue()
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());

	}
	void getVValue()
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());

	}
	void getPosition()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getPositionX()
	{
		fprintf(mFile,"\"%s.px\"",mName.c_str());

	}
	void getPositionY()
	{
		fprintf(mFile,"\"%s.py\"",mName.c_str());

	}
	void getPositionZ()
	{
		fprintf(mFile,"\"%s.pz\"",mName.c_str());

	}
	void getNormal()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getNormalX()
	{
		fprintf(mFile,"\"%s.nx\"",mName.c_str());

	}
	void getNormalY()
	{
		fprintf(mFile,"\"%s.ny\"",mName.c_str());

	}
	void getNormalZ()
	{
		fprintf(mFile,"\"%s.nz\"",mName.c_str());

	}
protected:
	FurPointOnSubd(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURPOINTONSUBD_H__
