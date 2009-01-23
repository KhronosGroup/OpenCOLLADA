/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Expression(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "expression"){}
	virtual ~Expression(){}
	void setInput(size_t in_i,double in)
	{
		if(in == 0.0) return;
		fprintf(mFile,"setAttr \".in[%i]\" %f;\n", in_i,in);

	}
	void setInput(size_t in_start,size_t in_end,double* in)
	{
		fprintf(mFile,"setAttr \".in[%i:%i]\" ", in_start,in_end);
		size_t size = (in_end-in_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",in[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startInput(size_t in_start,size_t in_end)
	{
		fprintf(mFile,"setAttr \".in[%i:%i]\"",in_start,in_end);

	}
	void appendInput(double in)
	{
		fprintf(mFile," %f",in);

	}
	void endInput()
	{
		fprintf(mFile,";\n");

	}
	void setInternalExpression(const string& ixp)
	{
		if(ixp == "NULL") return;
		fprintf(mFile,"setAttr \".ixp\" -type \"string\" ");
		ixp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAnimated(unsigned int ani)
	{
		if(ani == 1) return;
		fprintf(mFile,"setAttr \".ani\" %i;\n", ani);

	}
	void setUnitOption(unsigned int uno)
	{
		if(uno == 0) return;
		fprintf(mFile,"setAttr \".uno\" %i;\n", uno);

	}
	void getInput(size_t in_i)
	{
		fprintf(mFile,"\"%s.in[%i]\"",mName.c_str(),in_i);

	}
	void getOutput(size_t out_i)
	{
		fprintf(mFile,"\"%s.out[%i]\"",mName.c_str(),out_i);

	}
	void getObject()
	{
		fprintf(mFile,"\"%s.ob\"",mName.c_str());

	}
	void getAttribute()
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());

	}
	void getExpression()
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());

	}
	void getExprConnCount()
	{
		fprintf(mFile,"\"%s.xcc\"",mName.c_str());

	}
	void getInternalExpression()
	{
		fprintf(mFile,"\"%s.ixp\"",mName.c_str());

	}
	void getTime()
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());

	}
	void getFrame()
	{
		fprintf(mFile,"\"%s.frm\"",mName.c_str());

	}
	void getLastTimeEvaluated()
	{
		fprintf(mFile,"\"%s.lte\"",mName.c_str());

	}
	void getEvaluateNow()
	{
		fprintf(mFile,"\"%s.xen\"",mName.c_str());

	}
	void getAnimated()
	{
		fprintf(mFile,"\"%s.ani\"",mName.c_str());

	}
	void getNewFileFormat()
	{
		fprintf(mFile,"\"%s.nff\"",mName.c_str());

	}
	void getObjectMsg()
	{
		fprintf(mFile,"\"%s.obm\"",mName.c_str());

	}
	void getUnitOption()
	{
		fprintf(mFile,"\"%s.uno\"",mName.c_str());

	}
protected:
	Expression(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_EXPRESSION_H__
