/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MULTDOUBLELINEAR_H__
#define __MayaDM_MULTDOUBLELINEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class MultDoubleLinear : public DependNode
{
public:
public:
	MultDoubleLinear(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "multDoubleLinear"){}
	virtual ~MultDoubleLinear(){}
	void setInput1(double i1)
	{
		if(i1 == 0) return;
		fprintf(mFile,"setAttr \".i1\" %f;\n", i1);

	}
	void setInput2(double i2)
	{
		if(i2 == 0) return;
		fprintf(mFile,"setAttr \".i2\" %f;\n", i2);

	}
	void getInput1()
	{
		fprintf(mFile,"\"%s.i1\"",mName.c_str());

	}
	void getInput2()
	{
		fprintf(mFile,"\"%s.i2\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	MultDoubleLinear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MULTDOUBLELINEAR_H__
