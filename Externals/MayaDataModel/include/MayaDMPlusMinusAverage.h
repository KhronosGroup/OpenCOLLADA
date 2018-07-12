/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PLUSMINUSAVERAGE_H__
#define __MayaDM_PLUSMINUSAVERAGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class PlusMinusAverage : public DependNode
{
public:
public:

	PlusMinusAverage():DependNode(){}
	PlusMinusAverage(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "plusMinusAverage", shared, create){}
	virtual ~PlusMinusAverage(){}

	void setOperation(unsigned int op)
	{
		if(op == 1) return;
		fprintf(mFile,"\tsetAttr \".op\" %i;\n", op);
	}
	void setInput1D(size_t i1_i,float i1)
	{
		if(i1 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i1[%i]\" %f;\n", i1_i,i1);
	}
	void setInput1D(size_t i1_start,size_t i1_end,float* i1)
	{
		fprintf(mFile,"\tsetAttr \".i1[%i:%i]\" ", i1_start,i1_end);
		size_t size = (i1_end-i1_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",i1[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInput1D(size_t i1_start,size_t i1_end)const
	{
		fprintf(mFile,"\tsetAttr \".i1[%i:%i]\"",i1_start,i1_end);
	}
	void appendInput1D(float i1)const
	{
		fprintf(mFile," %f",i1);
	}
	void endInput1D()const
	{
		fprintf(mFile,";\n");
	}
	void setInput2D(size_t i2_i,const float2& i2)
	{
		if(i2 == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".i2[%i]\" -type \"float2\" ",i2_i);
		i2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInput2D(size_t i2_start,size_t i2_end,float* i2)
	{
		fprintf(mFile,"\tsetAttr \".i2[%i:%i]\" ", i2_start,i2_end);
		size_t size = (i2_end-i2_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",i2[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInput2D(size_t i2_start,size_t i2_end)const
	{
		fprintf(mFile,"\tsetAttr \".i2[%i:%i]\"",i2_start,i2_end);
	}
	void appendInput2D(float i2)const
	{
		fprintf(mFile," %f",i2);
	}
	void endInput2D()const
	{
		fprintf(mFile,";\n");
	}
	void setInput2Dx(size_t i2_i,float i2x)
	{
		if(i2x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i2[%i].i2x\" %f;\n", i2_i,i2x);
	}
	void setInput2Dy(size_t i2_i,float i2y)
	{
		if(i2y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i2[%i].i2y\" %f;\n", i2_i,i2y);
	}
	void setInput3D(size_t i3_i,const float3& i3)
	{
		if(i3 == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".i3[%i]\" -type \"float3\" ",i3_i);
		i3.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInput3D(size_t i3_start,size_t i3_end,float* i3)
	{
		fprintf(mFile,"\tsetAttr \".i3[%i:%i]\" ", i3_start,i3_end);
		size_t size = (i3_end-i3_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",i3[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInput3D(size_t i3_start,size_t i3_end)const
	{
		fprintf(mFile,"\tsetAttr \".i3[%i:%i]\"",i3_start,i3_end);
	}
	void appendInput3D(float i3)const
	{
		fprintf(mFile," %f",i3);
	}
	void endInput3D()const
	{
		fprintf(mFile,";\n");
	}
	void setInput3Dx(size_t i3_i,float i3x)
	{
		if(i3x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i3[%i].i3x\" %f;\n", i3_i,i3x);
	}
	void setInput3Dy(size_t i3_i,float i3y)
	{
		if(i3y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i3[%i].i3y\" %f;\n", i3_i,i3y);
	}
	void setInput3Dz(size_t i3_i,float i3z)
	{
		if(i3z == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i3[%i].i3z\" %f;\n", i3_i,i3z);
	}
	void getOperation()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getInput1D(size_t i1_i)const
	{
		fprintf(mFile,"\"%s.i1[%i]\"",mName.c_str(),i1_i);
	}
	void getInput1D()const
	{

		fprintf(mFile,"\"%s.i1\"",mName.c_str());
	}
	void getInput2D(size_t i2_i)const
	{
		fprintf(mFile,"\"%s.i2[%i]\"",mName.c_str(),i2_i);
	}
	void getInput2D()const
	{

		fprintf(mFile,"\"%s.i2\"",mName.c_str());
	}
	void getInput2Dx(size_t i2_i)const
	{
		fprintf(mFile,"\"%s.i2[%i].i2x\"",mName.c_str(),i2_i);
	}
	void getInput2Dx()const
	{

		fprintf(mFile,"\"%s.i2.i2x\"",mName.c_str());
	}
	void getInput2Dy(size_t i2_i)const
	{
		fprintf(mFile,"\"%s.i2[%i].i2y\"",mName.c_str(),i2_i);
	}
	void getInput2Dy()const
	{

		fprintf(mFile,"\"%s.i2.i2y\"",mName.c_str());
	}
	void getInput3D(size_t i3_i)const
	{
		fprintf(mFile,"\"%s.i3[%i]\"",mName.c_str(),i3_i);
	}
	void getInput3D()const
	{

		fprintf(mFile,"\"%s.i3\"",mName.c_str());
	}
	void getInput3Dx(size_t i3_i)const
	{
		fprintf(mFile,"\"%s.i3[%i].i3x\"",mName.c_str(),i3_i);
	}
	void getInput3Dx()const
	{

		fprintf(mFile,"\"%s.i3.i3x\"",mName.c_str());
	}
	void getInput3Dy(size_t i3_i)const
	{
		fprintf(mFile,"\"%s.i3[%i].i3y\"",mName.c_str(),i3_i);
	}
	void getInput3Dy()const
	{

		fprintf(mFile,"\"%s.i3.i3y\"",mName.c_str());
	}
	void getInput3Dz(size_t i3_i)const
	{
		fprintf(mFile,"\"%s.i3[%i].i3z\"",mName.c_str(),i3_i);
	}
	void getInput3Dz()const
	{

		fprintf(mFile,"\"%s.i3.i3z\"",mName.c_str());
	}
	void getOutput1D()const
	{
		fprintf(mFile,"\"%s.o1\"",mName.c_str());
	}
	void getOutput2D()const
	{
		fprintf(mFile,"\"%s.o2\"",mName.c_str());
	}
	void getOutput2Dx()const
	{
		fprintf(mFile,"\"%s.o2.o2x\"",mName.c_str());
	}
	void getOutput2Dy()const
	{
		fprintf(mFile,"\"%s.o2.o2y\"",mName.c_str());
	}
	void getOutput3D()const
	{
		fprintf(mFile,"\"%s.o3\"",mName.c_str());
	}
	void getOutput3Dx()const
	{
		fprintf(mFile,"\"%s.o3.o3x\"",mName.c_str());
	}
	void getOutput3Dy()const
	{
		fprintf(mFile,"\"%s.o3.o3y\"",mName.c_str());
	}
	void getOutput3Dz()const
	{
		fprintf(mFile,"\"%s.o3.o3z\"",mName.c_str());
	}
protected:
	PlusMinusAverage(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PLUSMINUSAVERAGE_H__
