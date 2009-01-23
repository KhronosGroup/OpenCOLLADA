/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	DetachCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "detachCurve"){}
	virtual ~DetachCurve(){}
	void setParameter(size_t p_i,double p)
	{
		if(p == 0.0) return;
		fprintf(mFile,"setAttr \".p[%i]\" %f;\n", p_i,p);

	}
	void setParameter(size_t p_start,size_t p_end,double* p)
	{
		fprintf(mFile,"setAttr \".p[%i:%i]\" ", p_start,p_end);
		size_t size = (p_end-p_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",p[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startParameter(size_t p_start,size_t p_end)
	{
		fprintf(mFile,"setAttr \".p[%i:%i]\"",p_start,p_end);

	}
	void appendParameter(double p)
	{
		fprintf(mFile," %f",p);

	}
	void endParameter()
	{
		fprintf(mFile,";\n");

	}
	void setKeep(size_t k_i,bool k)
	{
		if(k == true) return;
		fprintf(mFile,"setAttr \".k[%i]\" %i;\n", k_i,k);

	}
	void setKeep(size_t k_start,size_t k_end,bool* k)
	{
		fprintf(mFile,"setAttr \".k[%i:%i]\" ", k_start,k_end);
		size_t size = (k_end-k_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",k[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startKeep(size_t k_start,size_t k_end)
	{
		fprintf(mFile,"setAttr \".k[%i:%i]\"",k_start,k_end);

	}
	void appendKeep(bool k)
	{
		fprintf(mFile," %i",k);

	}
	void endKeep()
	{
		fprintf(mFile,";\n");

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getOutputCurve(size_t oc_i)
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);

	}
	void getParameter(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);

	}
	void getKeep(size_t k_i)
	{
		fprintf(mFile,"\"%s.k[%i]\"",mName.c_str(),k_i);

	}
protected:
	DetachCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DETACHCURVE_H__
