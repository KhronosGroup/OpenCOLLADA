/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Blend(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "blend"){}
	virtual ~Blend(){}
	void setInput(size_t i_i,double i)
	{
		if(i == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i]\" %f;\n", i_i,i);

	}
	void setCurrent(int c)
	{
		if(c == 0) return;
		fprintf(mFile,"setAttr \".c\" %i;\n", c);

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
	Blend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLEND_H__
