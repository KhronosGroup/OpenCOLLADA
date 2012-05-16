/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class PointOnSurfaceInfo : public AbstractBaseCreate
{
public:
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:

	PointOnSurfaceInfo():AbstractBaseCreate(){}
	PointOnSurfaceInfo(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "pointOnSurfaceInfo", shared, create){}
	virtual ~PointOnSurfaceInfo(){}

	void setParameterU(double u)
	{
		if(u == 0.0) return;
		fprintf(mFile,"\tsetAttr \".u\" %f;\n", u);
	}
	void setParameterV(double v)
	{
		if(v == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v\" %f;\n", v);
	}
	void setTurnOnPercentage(bool top)
	{
		if(top == false) return;
		fprintf(mFile,"\tsetAttr \".top\" %i;\n", top);
	}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getParameterU()const
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());
	}
	void getParameterV()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getTurnOnPercentage()const
	{
		fprintf(mFile,"\"%s.top\"",mName.c_str());
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
	void getNormalizedNormal()const
	{
		fprintf(mFile,"\"%s.r.nn\"",mName.c_str());
	}
	void getNormalizedNormalX()const
	{
		fprintf(mFile,"\"%s.r.nn.nnx\"",mName.c_str());
	}
	void getNormalizedNormalY()const
	{
		fprintf(mFile,"\"%s.r.nn.nny\"",mName.c_str());
	}
	void getNormalizedNormalZ()const
	{
		fprintf(mFile,"\"%s.r.nn.nnz\"",mName.c_str());
	}
	void getTangentU()const
	{
		fprintf(mFile,"\"%s.r.tu\"",mName.c_str());
	}
	void getTangentUx()const
	{
		fprintf(mFile,"\"%s.r.tu.tux\"",mName.c_str());
	}
	void getTangentUy()const
	{
		fprintf(mFile,"\"%s.r.tu.tuy\"",mName.c_str());
	}
	void getTangentUz()const
	{
		fprintf(mFile,"\"%s.r.tu.tuz\"",mName.c_str());
	}
	void getNormalizedTangentU()const
	{
		fprintf(mFile,"\"%s.r.ntu\"",mName.c_str());
	}
	void getNormalizedTangentUX()const
	{
		fprintf(mFile,"\"%s.r.ntu.nux\"",mName.c_str());
	}
	void getNormalizedTangentUY()const
	{
		fprintf(mFile,"\"%s.r.ntu.nuy\"",mName.c_str());
	}
	void getNormalizedTangentUZ()const
	{
		fprintf(mFile,"\"%s.r.ntu.nuz\"",mName.c_str());
	}
	void getTangentV()const
	{
		fprintf(mFile,"\"%s.r.tv\"",mName.c_str());
	}
	void getTangentVx()const
	{
		fprintf(mFile,"\"%s.r.tv.tvx\"",mName.c_str());
	}
	void getTangentVy()const
	{
		fprintf(mFile,"\"%s.r.tv.tvy\"",mName.c_str());
	}
	void getTangentVz()const
	{
		fprintf(mFile,"\"%s.r.tv.tvz\"",mName.c_str());
	}
	void getNormalizedTangentV()const
	{
		fprintf(mFile,"\"%s.r.ntv\"",mName.c_str());
	}
	void getNormalizedTangentVX()const
	{
		fprintf(mFile,"\"%s.r.ntv.nvx\"",mName.c_str());
	}
	void getNormalizedTangentVY()const
	{
		fprintf(mFile,"\"%s.r.ntv.nvy\"",mName.c_str());
	}
	void getNormalizedTangentVZ()const
	{
		fprintf(mFile,"\"%s.r.ntv.nvz\"",mName.c_str());
	}
protected:
	PointOnSurfaceInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POINTONSURFACEINFO_H__
