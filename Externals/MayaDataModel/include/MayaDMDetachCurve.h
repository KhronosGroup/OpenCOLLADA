/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DETACHCURVE_H__
#define __MayaDM_DETACHCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class DetachCurve : public AbstractBaseCreate
{
public:
public:

	DetachCurve():AbstractBaseCreate(){}
	DetachCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "detachCurve", shared, create){}
	virtual ~DetachCurve(){}

	void setParameter(size_t p_i,double p)
	{
		if(p == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p[%i]\" %f;\n", p_i,p);
	}
	void setParameter(size_t p_start,size_t p_end,double* p)
	{
		fprintf(mFile,"\tsetAttr \".p[%i:%i]\" ", p_start,p_end);
		size_t size = (p_end-p_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",p[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startParameter(size_t p_start,size_t p_end)const
	{
		fprintf(mFile,"\tsetAttr \".p[%i:%i]\"",p_start,p_end);
	}
	void appendParameter(double p)const
	{
		fprintf(mFile," %f",p);
	}
	void endParameter()const
	{
		fprintf(mFile,";\n");
	}
	void setKeep(size_t k_i,bool k)
	{
		if(k == true) return;
		fprintf(mFile,"\tsetAttr \".k[%i]\" %i;\n", k_i,k);
	}
	void setKeep(size_t k_start,size_t k_end,bool* k)
	{
		fprintf(mFile,"\tsetAttr \".k[%i:%i]\" ", k_start,k_end);
		size_t size = (k_end-k_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",k[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startKeep(size_t k_start,size_t k_end)const
	{
		fprintf(mFile,"\tsetAttr \".k[%i:%i]\"",k_start,k_end);
	}
	void appendKeep(bool k)const
	{
		fprintf(mFile," %i",k);
	}
	void endKeep()const
	{
		fprintf(mFile,";\n");
	}
	void getInputCurve()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getOutputCurve(size_t oc_i)const
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);
	}
	void getOutputCurve()const
	{

		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getParameter(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);
	}
	void getParameter()const
	{

		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getKeep(size_t k_i)const
	{
		fprintf(mFile,"\"%s.k[%i]\"",mName.c_str(),k_i);
	}
	void getKeep()const
	{

		fprintf(mFile,"\"%s.k\"",mName.c_str());
	}
protected:
	DetachCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DETACHCURVE_H__
