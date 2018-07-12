/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ATTACHCURVE_H__
#define __MayaDM_ATTACHCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class AttachCurve : public AbstractBaseCreate
{
public:
public:

	AttachCurve():AbstractBaseCreate(){}
	AttachCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "attachCurve", shared, create){}
	virtual ~AttachCurve(){}

	void setReverse1(bool rv1)
	{
		if(rv1 == false) return;
		fprintf(mFile,"\tsetAttr \".rv1\" %i;\n", rv1);
	}
	void setReverse2(bool rv2)
	{
		if(rv2 == false) return;
		fprintf(mFile,"\tsetAttr \".rv2\" %i;\n", rv2);
	}
	void setMethod(unsigned int m)
	{
		if(m == 0) return;
		fprintf(mFile,"\tsetAttr \".m\" %i;\n", m);
	}
	void setKeepMultipleKnots(bool kmk)
	{
		if(kmk == true) return;
		fprintf(mFile,"\tsetAttr \".kmk\" %i;\n", kmk);
	}
	void setBlendBias(double bb)
	{
		if(bb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".bb\" %f;\n", bb);
	}
	void setBlendKnotInsertion(bool bki)
	{
		if(bki == false) return;
		fprintf(mFile,"\tsetAttr \".bki\" %i;\n", bki);
	}
	void setParameter(double p)
	{
		if(p == 0.1) return;
		fprintf(mFile,"\tsetAttr \".p\" %f;\n", p);
	}
	void getInputCurve1()const
	{
		fprintf(mFile,"\"%s.ic1\"",mName.c_str());
	}
	void getInputCurve2()const
	{
		fprintf(mFile,"\"%s.ic2\"",mName.c_str());
	}
	void getInputCurves(size_t ics_i)const
	{
		fprintf(mFile,"\"%s.ics[%i]\"",mName.c_str(),ics_i);
	}
	void getInputCurves()const
	{

		fprintf(mFile,"\"%s.ics\"",mName.c_str());
	}
	void getOutputCurve()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getReverse1()const
	{
		fprintf(mFile,"\"%s.rv1\"",mName.c_str());
	}
	void getReverse2()const
	{
		fprintf(mFile,"\"%s.rv2\"",mName.c_str());
	}
	void getMethod()const
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getKeepMultipleKnots()const
	{
		fprintf(mFile,"\"%s.kmk\"",mName.c_str());
	}
	void getBlendBias()const
	{
		fprintf(mFile,"\"%s.bb\"",mName.c_str());
	}
	void getBlendKnotInsertion()const
	{
		fprintf(mFile,"\"%s.bki\"",mName.c_str());
	}
	void getParameter()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
protected:
	AttachCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ATTACHCURVE_H__
