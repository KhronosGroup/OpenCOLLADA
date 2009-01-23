/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HARDENPOINT_H__
#define __MayaDM_HARDENPOINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class HardenPoint : public AbstractBaseCreate
{
public:
public:
	HardenPoint(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "hardenPoint"){}
	virtual ~HardenPoint(){}
	void setIndex(size_t i_i,int i)
	{
		if(i == 0) return;
		fprintf(mFile,"setAttr \".i[%i]\" %i;\n", i_i,i);

	}
	void setIndex(size_t i_start,size_t i_end,int* i)
	{
		fprintf(mFile,"setAttr \".i[%i:%i]\" ", i_start,i_end);
		size_t size = (i_end-i_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",i[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startIndex(size_t i_start,size_t i_end)
	{
		fprintf(mFile,"setAttr \".i[%i:%i]\"",i_start,i_end);

	}
	void appendIndex(int i)
	{
		fprintf(mFile," %i",i);

	}
	void endIndex()
	{
		fprintf(mFile,";\n");

	}
	void setMultiplicity(int m)
	{
		if(m == -1) return;
		fprintf(mFile,"setAttr \".m\" %i;\n", m);

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getIndex(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);

	}
	void getMultiplicity()
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());

	}
	void getOutputCurve()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
protected:
	HardenPoint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HARDENPOINT_H__
