/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOSESTPOINTONSURFACE_H__
#define __MayaDM_CLOSESTPOINTONSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class ClosestPointOnSurface : public AbstractBaseCreate
{
public:
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:
	ClosestPointOnSurface():AbstractBaseCreate(){}
	ClosestPointOnSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "closestPointOnSurface"){}
	virtual ~ClosestPointOnSurface(){}
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
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

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
protected:
	ClosestPointOnSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLOSESTPOINTONSURFACE_H__
