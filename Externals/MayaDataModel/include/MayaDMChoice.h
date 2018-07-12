/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHOICE_H__
#define __MayaDM_CHOICE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Choice : public DependNode
{
public:
public:

	Choice():DependNode(){}
	Choice(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "choice", shared, create){}
	virtual ~Choice(){}

	void setSelector(int s)
	{
		if(s == 0) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);
	}
	void getSelector()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getInput(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);
	}
	void getInput()const
	{

		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	Choice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CHOICE_H__
