/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RBFSRF_H__
#define __MayaDM_RBFSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class RbfSrf : public AbstractBaseCreate
{
public:
public:
	RbfSrf():AbstractBaseCreate(){}
	RbfSrf(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:AbstractBaseCreate(file, name, parent, "rbfSrf", create){}
	virtual ~RbfSrf(){}
	void setPrimaryRadius(double pr)
	{
		if(pr == 1) return;
		fprintf(mFile,"\tsetAttr \".pr\" %f;\n", pr);

	}
	void setSecondaryRadius(double sr)
	{
		if(sr == 1) return;
		fprintf(mFile,"\tsetAttr \".sr\" %f;\n", sr);

	}
	void setPositionTolerance(double pt)
	{
		if(pt == 0.01) return;
		fprintf(mFile,"\tsetAttr \".pt\" %f;\n", pt);

	}
	void setTangentTolerance(double tt)
	{
		if(tt == 0.01) return;
		fprintf(mFile,"\tsetAttr \".tt\" %f;\n", tt);

	}
	void getPrimarySurface()const
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getSecondarySurface()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getPrimaryRadius()const
	{
		fprintf(mFile,"\"%s.pr\"",mName.c_str());

	}
	void getSecondaryRadius()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getPositionTolerance()const
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());

	}
	void getTangentTolerance()const
	{
		fprintf(mFile,"\"%s.tt\"",mName.c_str());

	}
	void getOutputSurface(size_t os_i)const
	{
		fprintf(mFile,"\"%s.os[%i]\"",mName.c_str(),os_i);

	}
	void getTrimCurveOnPrimary(size_t tcp_i)const
	{
		fprintf(mFile,"\"%s.tcp[%i]\"",mName.c_str(),tcp_i);

	}
	void getTrimCurveOnSecondary(size_t tcs_i)const
	{
		fprintf(mFile,"\"%s.tcs[%i]\"",mName.c_str(),tcs_i);

	}
protected:
	RbfSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RBFSRF_H__
