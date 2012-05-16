/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ADDDOUBLELINEAR_H__
#define __MayaDM_ADDDOUBLELINEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class AddDoubleLinear : public DependNode
{
public:
public:

	AddDoubleLinear():DependNode(){}
	AddDoubleLinear(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "addDoubleLinear", shared, create){}
	virtual ~AddDoubleLinear(){}

	void setInput1(double i1)
	{
		if(i1 == 0) return;
		fprintf(mFile,"\tsetAttr \".i1\" %f;\n", i1);
	}
	void setInput2(double i2)
	{
		if(i2 == 0) return;
		fprintf(mFile,"\tsetAttr \".i2\" %f;\n", i2);
	}
	void getInput1()const
	{
		fprintf(mFile,"\"%s.i1\"",mName.c_str());
	}
	void getInput2()const
	{
		fprintf(mFile,"\"%s.i2\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	AddDoubleLinear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ADDDOUBLELINEAR_H__
