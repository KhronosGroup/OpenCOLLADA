/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VECTORPRODUCT_H__
#define __MayaDM_VECTORPRODUCT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class VectorProduct : public DependNode
{
public:
public:

	VectorProduct():DependNode(){}
	VectorProduct(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "vectorProduct", shared, create){}
	virtual ~VectorProduct(){}

	void setOperation(unsigned int op)
	{
		if(op == 1) return;
		fprintf(mFile,"\tsetAttr \".op\" %i;\n", op);
	}
	void setInput1(const float3& i1)
	{
		if(i1 == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".i1\" -type \"float3\" ");
		i1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInput1X(float i1x)
	{
		if(i1x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i1.i1x\" %f;\n", i1x);
	}
	void setInput1Y(float i1y)
	{
		if(i1y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i1.i1y\" %f;\n", i1y);
	}
	void setInput1Z(float i1z)
	{
		if(i1z == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i1.i1z\" %f;\n", i1z);
	}
	void setInput2(const float3& i2)
	{
		if(i2 == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".i2\" -type \"float3\" ");
		i2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInput2X(float i2x)
	{
		if(i2x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i2.i2x\" %f;\n", i2x);
	}
	void setInput2Y(float i2y)
	{
		if(i2y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i2.i2y\" %f;\n", i2y);
	}
	void setInput2Z(float i2z)
	{
		if(i2z == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i2.i2z\" %f;\n", i2z);
	}
	void setNormalizeOutput(bool no)
	{
		if(no == false) return;
		fprintf(mFile,"\tsetAttr \".no\" %i;\n", no);
	}
	void getOperation()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getInput1()const
	{
		fprintf(mFile,"\"%s.i1\"",mName.c_str());
	}
	void getInput1X()const
	{
		fprintf(mFile,"\"%s.i1.i1x\"",mName.c_str());
	}
	void getInput1Y()const
	{
		fprintf(mFile,"\"%s.i1.i1y\"",mName.c_str());
	}
	void getInput1Z()const
	{
		fprintf(mFile,"\"%s.i1.i1z\"",mName.c_str());
	}
	void getInput2()const
	{
		fprintf(mFile,"\"%s.i2\"",mName.c_str());
	}
	void getInput2X()const
	{
		fprintf(mFile,"\"%s.i2.i2x\"",mName.c_str());
	}
	void getInput2Y()const
	{
		fprintf(mFile,"\"%s.i2.i2y\"",mName.c_str());
	}
	void getInput2Z()const
	{
		fprintf(mFile,"\"%s.i2.i2z\"",mName.c_str());
	}
	void getMatrix()const
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getNormalizeOutput()const
	{
		fprintf(mFile,"\"%s.no\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getOutputX()const
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());
	}
	void getOutputY()const
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());
	}
	void getOutputZ()const
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());
	}
protected:
	VectorProduct(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_VECTORPRODUCT_H__
