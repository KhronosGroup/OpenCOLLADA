/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SMOOTHTANGENTSRF_H__
#define __MayaDM_SMOOTHTANGENTSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class SmoothTangentSrf : public AbstractBaseCreate
{
public:
public:

	SmoothTangentSrf():AbstractBaseCreate(){}
	SmoothTangentSrf(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "smoothTangentSrf", shared, create){}
	virtual ~SmoothTangentSrf(){}

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
	void setDirection(unsigned int d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setSmoothness(unsigned int s)
	{
		if(s == 1) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);
	}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getParameter(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);
	}
	void getParameter()const
	{

		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getDirection()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSmoothness()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
protected:
	SmoothTangentSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SMOOTHTANGENTSRF_H__
