/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	RbfSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "rbfSrf"){}
	virtual ~RbfSrf(){}
	void setPrimaryRadius(double pr)
	{
		if(pr == 1) return;
		fprintf(mFile,"setAttr \".pr\" %f;\n", pr);

	}
	void setSecondaryRadius(double sr)
	{
		if(sr == 1) return;
		fprintf(mFile,"setAttr \".sr\" %f;\n", sr);

	}
	void setPositionTolerance(double pt)
	{
		if(pt == 0.01) return;
		fprintf(mFile,"setAttr \".pt\" %f;\n", pt);

	}
	void setTangentTolerance(double tt)
	{
		if(tt == 0.01) return;
		fprintf(mFile,"setAttr \".tt\" %f;\n", tt);

	}
	void getPrimarySurface()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getSecondarySurface()
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getPrimaryRadius()
	{
		fprintf(mFile,"\"%s.pr\"",mName.c_str());

	}
	void getSecondaryRadius()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getPositionTolerance()
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());

	}
	void getTangentTolerance()
	{
		fprintf(mFile,"\"%s.tt\"",mName.c_str());

	}
	void getOutputSurface(size_t os_i)
	{
		fprintf(mFile,"\"%s.os[%i]\"",mName.c_str(),os_i);

	}
	void getTrimCurveOnPrimary(size_t tcp_i)
	{
		fprintf(mFile,"\"%s.tcp[%i]\"",mName.c_str(),tcp_i);

	}
	void getTrimCurveOnSecondary(size_t tcs_i)
	{
		fprintf(mFile,"\"%s.tcs[%i]\"",mName.c_str(),tcs_i);

	}
protected:
	RbfSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RBFSRF_H__
