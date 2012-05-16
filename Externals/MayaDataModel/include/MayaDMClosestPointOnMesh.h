/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	ClosestPointOnMesh():DependNode(){}
	ClosestPointOnMesh(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "closestPointOnMesh", shared, create){}
	virtual ~ClosestPointOnMesh(){}

	void setInPosition(const double3& ip)
	{
		if(ip == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".ip\" -type \"double3\" ");
		ip.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInPositionX(double ipx)
	{
		if(ipx == 0) return;
		fprintf(mFile,"\tsetAttr \".ip.ipx\" %f;\n", ipx);
	}
	void setInPositionY(double ipy)
	{
		if(ipy == 0) return;
		fprintf(mFile,"\tsetAttr \".ip.ipy\" %f;\n", ipy);
	}
	void setInPositionZ(double ipz)
	{
		if(ipz == 0) return;
		fprintf(mFile,"\tsetAttr \".ip.ipz\" %f;\n", ipz);
	}
	void getInMesh()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getInPosition()const
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());
	}
	void getInPositionX()const
	{
		fprintf(mFile,"\"%s.ip.ipx\"",mName.c_str());
	}
	void getInPositionY()const
	{
		fprintf(mFile,"\"%s.ip.ipy\"",mName.c_str());
	}
	void getInPositionZ()const
	{
		fprintf(mFile,"\"%s.ip.ipz\"",mName.c_str());
	}
	void getResult()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getPosition()const
	{
		fprintf(mFile,"\"%s.r.p\"",mName.c_str());
	}
	void getPositionX()const
	{
		fprintf(mFile,"\"%s.r.p.px\"",mName.c_str());
	}
	void getPositionY()const
	{
		fprintf(mFile,"\"%s.r.p.py\"",mName.c_str());
	}
	void getPositionZ()const
	{
		fprintf(mFile,"\"%s.r.p.pz\"",mName.c_str());
	}
	void getParameterU()const
	{
		fprintf(mFile,"\"%s.r.u\"",mName.c_str());
	}
	void getParameterV()const
	{
		fprintf(mFile,"\"%s.r.v\"",mName.c_str());
	}
	void getNormal()const
	{
		fprintf(mFile,"\"%s.r.n\"",mName.c_str());
	}
	void getNormalX()const
	{
		fprintf(mFile,"\"%s.r.n.nx\"",mName.c_str());
	}
	void getNormalY()const
	{
		fprintf(mFile,"\"%s.r.n.ny\"",mName.c_str());
	}
	void getNormalZ()const
	{
		fprintf(mFile,"\"%s.r.n.nz\"",mName.c_str());
	}
	void getClosestFaceIndex()const
	{
		fprintf(mFile,"\"%s.r.f\"",mName.c_str());
	}
	void getClosestVertexIndex()const
	{
		fprintf(mFile,"\"%s.r.vt\"",mName.c_str());
	}
protected:
	ClosestPointOnMesh(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLOSESTPOINTONMESH_H__
