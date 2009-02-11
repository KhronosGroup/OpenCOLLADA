/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLEND_H__
#define __MayaDM_BLEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Blend : public DependNode
{
public:
public:
	Blend():DependNode(){}
	Blend(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "blend"){}
	virtual ~Blend(){}
	void setInput(size_t i_i,double i_)
	{
		if(i_ == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i]\" %f;\n", i_i,i_);

	}
	void setInput(size_t i_start,size_t i_end,double* i_)
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\" ", i_start,i_end);
		size_t size = (i_end-i_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",i_[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startInput(size_t i_start,size_t i_end)
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\"",i_start,i_end);

	}
	void appendInput(double i)
	{
		fprintf(mFile," %f",i);

	}
	void endInput()
	{
		fprintf(mFile,";\n");

	}
	void setCurrent(int c)
	{
		if(c == 0) return;
		fprintf(mFile,"\tsetAttr \".c\" %i;\n", c);

	}
	void getInput(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	Blend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLEND_H__
