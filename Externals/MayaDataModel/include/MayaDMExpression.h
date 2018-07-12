/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXPRESSION_H__
#define __MayaDM_EXPRESSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Expression : public DependNode
{
public:
public:

	Expression():DependNode(){}
	Expression(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "expression", shared, create){}
	virtual ~Expression(){}

	void setInput(size_t in_i,double in)
	{
		if(in == 0.0) return;
		fprintf(mFile,"\tsetAttr \".in[%i]\" %f;\n", in_i,in);
	}
	void setInput(size_t in_start,size_t in_end,double* in)
	{
		fprintf(mFile,"\tsetAttr \".in[%i:%i]\" ", in_start,in_end);
		size_t size = (in_end-in_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",in[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInput(size_t in_start,size_t in_end)const
	{
		fprintf(mFile,"\tsetAttr \".in[%i:%i]\"",in_start,in_end);
	}
	void appendInput(double in)const
	{
		fprintf(mFile," %f",in);
	}
	void endInput()const
	{
		fprintf(mFile,";\n");
	}
	void setInternalExpression(const string& ixp)
	{
		if(ixp == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ixp\" -type \"string\" ");
		ixp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAnimated(unsigned int ani)
	{
		if(ani == 1) return;
		fprintf(mFile,"\tsetAttr \".ani\" %i;\n", ani);
	}
	void setUnitOption(unsigned int uno)
	{
		if(uno == 0) return;
		fprintf(mFile,"\tsetAttr \".uno\" %i;\n", uno);
	}
	void getInput(size_t in_i)const
	{
		fprintf(mFile,"\"%s.in[%i]\"",mName.c_str(),in_i);
	}
	void getInput()const
	{

		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getOutput(size_t out_i)const
	{
		fprintf(mFile,"\"%s.out[%i]\"",mName.c_str(),out_i);
	}
	void getOutput()const
	{

		fprintf(mFile,"\"%s.out\"",mName.c_str());
	}
	void getObject()const
	{
		fprintf(mFile,"\"%s.ob\"",mName.c_str());
	}
	void getAttribute()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getExpression()const
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());
	}
	void getExprConnCount()const
	{
		fprintf(mFile,"\"%s.xcc\"",mName.c_str());
	}
	void getInternalExpression()const
	{
		fprintf(mFile,"\"%s.ixp\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());
	}
	void getFrame()const
	{
		fprintf(mFile,"\"%s.frm\"",mName.c_str());
	}
	void getLastTimeEvaluated()const
	{
		fprintf(mFile,"\"%s.lte\"",mName.c_str());
	}
	void getEvaluateNow()const
	{
		fprintf(mFile,"\"%s.xen\"",mName.c_str());
	}
	void getAnimated()const
	{
		fprintf(mFile,"\"%s.ani\"",mName.c_str());
	}
	void getNewFileFormat()const
	{
		fprintf(mFile,"\"%s.nff\"",mName.c_str());
	}
	void getObjectMsg()const
	{
		fprintf(mFile,"\"%s.obm\"",mName.c_str());
	}
	void getUnitOption()const
	{
		fprintf(mFile,"\"%s.uno\"",mName.c_str());
	}
protected:
	Expression(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_EXPRESSION_H__
