/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FFFILLETSRF_H__
#define __MayaDM_FFFILLETSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class FfFilletSrf : public AbstractBaseCreate
{
public:
public:

	FfFilletSrf():AbstractBaseCreate(){}
	FfFilletSrf(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "ffFilletSrf", shared, create){}
	virtual ~FfFilletSrf(){}

	void setPositionTolerance(double pt)
	{
		if(pt == 0.1) return;
		fprintf(mFile,"\tsetAttr \".pt\" %f;\n", pt);
	}
	void setTangentTolerance(double tt)
	{
		if(tt == 0.1) return;
		fprintf(mFile,"\tsetAttr \".tt\" %f;\n", tt);
	}
	void setDepth(double d)
	{
		if(d == 0.5) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setBias(double b)
	{
		if(b == 0.5) return;
		fprintf(mFile,"\tsetAttr \".b\" %f;\n", b);
	}
	void getLeftCurve()const
	{
		fprintf(mFile,"\"%s.lc\"",mName.c_str());
	}
	void getRightCurve()const
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());
	}
	void getPositionTolerance()const
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());
	}
	void getTangentTolerance()const
	{
		fprintf(mFile,"\"%s.tt\"",mName.c_str());
	}
	void getDepth()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getBias()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
protected:
	FfFilletSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FFFILLETSRF_H__
