/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REVERSE_H__
#define __MayaDM_REVERSE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Reverse : public DependNode
{
public:
public:

	Reverse():DependNode(){}
	Reverse(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "reverse", shared, create){}
	virtual ~Reverse(){}

	void setInput(const float3& i_)
	{
		if(i_ == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".i\" -type \"float3\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputX(float ix)
	{
		if(ix == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ix\" %f;\n", ix);
	}
	void setInputY(float iy)
	{
		if(iy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.iy\" %f;\n", iy);
	}
	void setInputZ(float iz)
	{
		if(iz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.iz\" %f;\n", iz);
	}
	void getInput()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getInputX()const
	{
		fprintf(mFile,"\"%s.i.ix\"",mName.c_str());
	}
	void getInputY()const
	{
		fprintf(mFile,"\"%s.i.iy\"",mName.c_str());
	}
	void getInputZ()const
	{
		fprintf(mFile,"\"%s.i.iz\"",mName.c_str());
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
	Reverse(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_REVERSE_H__
