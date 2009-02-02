/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TIMEFUNCTION_H__
#define __MayaDM_TIMEFUNCTION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class TimeFunction : public DependNode
{
public:
public:
	TimeFunction(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "timeFunction"){}
	virtual ~TimeFunction(){}
	void setInput(double i_)
	{
		if(i_ == 0.0) return;
		fprintf(mFile,"setAttr \".i\" %f;\n", i_);

	}
	void getInput()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	TimeFunction(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TIMEFUNCTION_H__
