/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Reverse(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "reverse"){}
	virtual ~Reverse(){}
	void setInput(const float3& i_)
	{
		if(i_ == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".i\" -type \"float3\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputX(float ix)
	{
		if(ix == 0.0) return;
		fprintf(mFile,"setAttr \".i.ix\" %f;\n", ix);

	}
	void setInputY(float iy)
	{
		if(iy == 0.0) return;
		fprintf(mFile,"setAttr \".i.iy\" %f;\n", iy);

	}
	void setInputZ(float iz)
	{
		if(iz == 0.0) return;
		fprintf(mFile,"setAttr \".i.iz\" %f;\n", iz);

	}
	void getInput()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getInputX()
	{
		fprintf(mFile,"\"%s.i.ix\"",mName.c_str());

	}
	void getInputY()
	{
		fprintf(mFile,"\"%s.i.iy\"",mName.c_str());

	}
	void getInputZ()
	{
		fprintf(mFile,"\"%s.i.iz\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOutputX()
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());

	}
	void getOutputY()
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());

	}
	void getOutputZ()
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());

	}
protected:
	Reverse(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_REVERSE_H__
