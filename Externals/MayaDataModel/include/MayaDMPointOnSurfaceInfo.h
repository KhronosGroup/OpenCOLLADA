/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PointOnSurfaceInfo(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "pointOnSurfaceInfo"){}
	virtual ~PointOnSurfaceInfo(){}
	void setParameterU(double u)
	{
		if(u == 0.0) return;
		fprintf(mFile,"setAttr \".u\" %f;\n", u);

	}
	void setParameterV(double v)
	{
		if(v == 0.0) return;
		fprintf(mFile,"setAttr \".v\" %f;\n", v);

	}
	void setTurnOnPercentage(bool top)
	{
		if(top == false) return;
		fprintf(mFile,"setAttr \".top\" %i;\n", top);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getParameterU()
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());

	}
	void getParameterV()
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());

	}
	void getTurnOnPercentage()
	{
		fprintf(mFile,"\"%s.top\"",mName.c_str());

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
	void getNormalizedNormal()
	{
		fprintf(mFile,"\"%s.r.nn\"",mName.c_str());

	}
	void getNormalizedNormalX()
	{
		fprintf(mFile,"\"%s.r.nn.nnx\"",mName.c_str());

	}
	void getNormalizedNormalY()
	{
		fprintf(mFile,"\"%s.r.nn.nny\"",mName.c_str());

	}
	void getNormalizedNormalZ()
	{
		fprintf(mFile,"\"%s.r.nn.nnz\"",mName.c_str());

	}
	void getTangentU()
	{
		fprintf(mFile,"\"%s.r.tu\"",mName.c_str());

	}
	void getTangentUx()
	{
		fprintf(mFile,"\"%s.r.tu.tux\"",mName.c_str());

	}
	void getTangentUy()
	{
		fprintf(mFile,"\"%s.r.tu.tuy\"",mName.c_str());

	}
	void getTangentUz()
	{
		fprintf(mFile,"\"%s.r.tu.tuz\"",mName.c_str());

	}
	void getNormalizedTangentU()
	{
		fprintf(mFile,"\"%s.r.ntu\"",mName.c_str());

	}
	void getNormalizedTangentUX()
	{
		fprintf(mFile,"\"%s.r.ntu.nux\"",mName.c_str());

	}
	void getNormalizedTangentUY()
	{
		fprintf(mFile,"\"%s.r.ntu.nuy\"",mName.c_str());

	}
	void getNormalizedTangentUZ()
	{
		fprintf(mFile,"\"%s.r.ntu.nuz\"",mName.c_str());

	}
	void getTangentV()
	{
		fprintf(mFile,"\"%s.r.tv\"",mName.c_str());

	}
	void getTangentVx()
	{
		fprintf(mFile,"\"%s.r.tv.tvx\"",mName.c_str());

	}
	void getTangentVy()
	{
		fprintf(mFile,"\"%s.r.tv.tvy\"",mName.c_str());

	}
	void getTangentVz()
	{
		fprintf(mFile,"\"%s.r.tv.tvz\"",mName.c_str());

	}
	void getNormalizedTangentV()
	{
		fprintf(mFile,"\"%s.r.ntv\"",mName.c_str());

	}
	void getNormalizedTangentVX()
	{
		fprintf(mFile,"\"%s.r.ntv.nvx\"",mName.c_str());

	}
	void getNormalizedTangentVY()
	{
		fprintf(mFile,"\"%s.r.ntv.nvy\"",mName.c_str());

	}
	void getNormalizedTangentVZ()
	{
		fprintf(mFile,"\"%s.r.ntv.nvz\"",mName.c_str());

	}
protected:
	PointOnSurfaceInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POINTONSURFACEINFO_H__
