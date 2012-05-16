/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	FurPointOnSubd():DependNode(){}
	FurPointOnSubd(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "furPointOnSubd", shared, create){}
	virtual ~FurPointOnSubd(){}

	void setRelative(bool rel)
	{
		if(rel == true) return;
		fprintf(mFile,"\tsetAttr \".rel\" %i;\n", rel);
	}
	void setUValue(double u)
	{
		if(u == 0.0) return;
		fprintf(mFile,"\tsetAttr \".u\" %f;\n", u);
	}
	void setVValue(double v)
	{
		if(v == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v\" %f;\n", v);
	}
	void setPosition(const double3& p)
	{
		if(p == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p\" -type \"double3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPositionX(double px)
	{
		if(px == 0.0) return;
		fprintf(mFile,"\tsetAttr \".px\" %f;\n", px);
	}
	void setPositionY(double py)
	{
		if(py == 0.0) return;
		fprintf(mFile,"\tsetAttr \".py\" %f;\n", py);
	}
	void setPositionZ(double pz)
	{
		if(pz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pz\" %f;\n", pz);
	}
	void setNormal(const double3& n)
	{
		if(n == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n\" -type \"double3\" ");
		n.write(mFile);
		fprintf(mFile,";\n");
	}
	void setNormalX(double nx)
	{
		if(nx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".nx\" %f;\n", nx);
	}
	void setNormalY(double ny)
	{
		if(ny == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ny\" %f;\n", ny);
	}
	void setNormalZ(double nz)
	{
		if(nz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".nz\" %f;\n", nz);
	}
	void getSubd()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getFaceFirst()const
	{
		fprintf(mFile,"\"%s.ff\"",mName.c_str());
	}
	void getFaceSecond()const
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getRelative()const
	{
		fprintf(mFile,"\"%s.rel\"",mName.c_str());
	}
	void getUValue()const
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());
	}
	void getVValue()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getPosition()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPositionX()const
	{
		fprintf(mFile,"\"%s.px\"",mName.c_str());
	}
	void getPositionY()const
	{
		fprintf(mFile,"\"%s.py\"",mName.c_str());
	}
	void getPositionZ()const
	{
		fprintf(mFile,"\"%s.pz\"",mName.c_str());
	}
	void getNormal()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNormalX()const
	{
		fprintf(mFile,"\"%s.nx\"",mName.c_str());
	}
	void getNormalY()const
	{
		fprintf(mFile,"\"%s.ny\"",mName.c_str());
	}
	void getNormalZ()const
	{
		fprintf(mFile,"\"%s.nz\"",mName.c_str());
	}
protected:
	FurPointOnSubd(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURPOINTONSUBD_H__
