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
class ClosestPointOnMesh : public DependNode
{
public:
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:
	ClosestPointOnMesh(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "closestPointOnMesh"){}
	virtual ~ClosestPointOnMesh(){}
	void setInPosition(const double3& ip)
	{
		if(ip == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"setAttr \".ip\" -type \"double3\" ");
		ip.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInPositionX(double ipx)
	{
		if(ipx == 0) return;
		fprintf(mFile,"setAttr \".ip.ipx\" %f;\n", ipx);

	}
	void setInPositionY(double ipy)
	{
		if(ipy == 0) return;
		fprintf(mFile,"setAttr \".ip.ipy\" %f;\n", ipy);

	}
	void setInPositionZ(double ipz)
	{
		if(ipz == 0) return;
		fprintf(mFile,"setAttr \".ip.ipz\" %f;\n", ipz);

	}
	void getInMesh()
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());

	}
	void getInPosition()
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());

	}
	void getInPositionX()
	{
		fprintf(mFile,"\"%s.ip.ipx\"",mName.c_str());

	}
	void getInPositionY()
	{
		fprintf(mFile,"\"%s.ip.ipy\"",mName.c_str());

	}
	void getInPositionZ()
	{
		fprintf(mFile,"\"%s.ip.ipz\"",mName.c_str());

	}
	void getResult()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getPosition()
	{
		fprintf(mFile,"\"%s.r.p\"",mName.c_str());

	}
	void getPositionX()
	{
		fprintf(mFile,"\"%s.r.p.px\"",mName.c_str());

	}
	void getPositionY()
	{
		fprintf(mFile,"\"%s.r.p.py\"",mName.c_str());

	}
	void getPositionZ()
	{
		fprintf(mFile,"\"%s.r.p.pz\"",mName.c_str());

	}
	void getParameterU()
	{
		fprintf(mFile,"\"%s.r.u\"",mName.c_str());

	}
	void getParameterV()
	{
		fprintf(mFile,"\"%s.r.v\"",mName.c_str());

	}
	void getNormal()
	{
		fprintf(mFile,"\"%s.r.n\"",mName.c_str());

	}
	void getNormalX()
	{
		fprintf(mFile,"\"%s.r.n.nx\"",mName.c_str());

	}
	void getNormalY()
	{
		fprintf(mFile,"\"%s.r.n.ny\"",mName.c_str());

	}
	void getNormalZ()
	{
		fprintf(mFile,"\"%s.r.n.nz\"",mName.c_str());

	}
	void getClosestFaceIndex()
	{
		fprintf(mFile,"\"%s.r.f\"",mName.c_str());

	}
	void getClosestVertexIndex()
	{
		fprintf(mFile,"\"%s.r.vt\"",mName.c_str());

	}
protected:
	ClosestPointOnMesh(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLOSESTPOINTONMESH_H__
