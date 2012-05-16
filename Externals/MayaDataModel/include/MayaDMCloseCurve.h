/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOSECURVE_H__
#define __MayaDM_CLOSECURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class CloseCurve : public AbstractBaseCreate
{
public:
public:

	CloseCurve():AbstractBaseCreate(){}
	CloseCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "closeCurve", shared, create){}
	virtual ~CloseCurve(){}

	void setPreserveShape(unsigned int ps)
	{
		if(ps == 1) return;
		fprintf(mFile,"\tsetAttr \".ps\" %i;\n", ps);
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
	void getInputCurve()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getPreserveShape()const
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());
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
	void getOutputCurve()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
protected:
	CloseCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLOSECURVE_H__
