/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SMOOTHCURVE_H__
#define __MayaDM_SMOOTHCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class SmoothCurve : public AbstractBaseCreate
{
public:
public:

	SmoothCurve():AbstractBaseCreate(){}
	SmoothCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "smoothCurve", shared, create){}
	virtual ~SmoothCurve(){}

	void setSmoothness(double s)
	{
		if(s == 10.0) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void setIndex(size_t i_i,int i_)
	{
		if(i_ == 0) return;
		fprintf(mFile,"\tsetAttr \".i[%i]\" %i;\n", i_i,i_);
	}
	void setIndex(size_t i_start,size_t i_end,int* i_)
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\" ", i_start,i_end);
		size_t size = (i_end-i_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",i_[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startIndex(size_t i_start,size_t i_end)const
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\"",i_start,i_end);
	}
	void appendIndex(int i)const
	{
		fprintf(mFile," %i",i);
	}
	void endIndex()const
	{
		fprintf(mFile,";\n");
	}
	void getInputCurve()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getSmoothness()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getIndex(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);
	}
	void getIndex()const
	{

		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutputCurve()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
protected:
	SmoothCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SMOOTHCURVE_H__
