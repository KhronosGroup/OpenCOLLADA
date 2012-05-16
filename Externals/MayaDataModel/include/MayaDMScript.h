/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SCRIPT_H__
#define __MayaDM_SCRIPT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Script : public DependNode
{
public:
public:

	Script():DependNode(){}
	Script(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "script", shared, create){}
	virtual ~Script(){}

	void setBefore(const string& b)
	{
		if(b == "NULL") return;
		fprintf(mFile,"\tsetAttr \".b\" -type \"string\" ");
		b.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAfter(const string& a)
	{
		if(a == "NULL") return;
		fprintf(mFile,"\tsetAttr \".a\" -type \"string\" ");
		a.write(mFile);
		fprintf(mFile,";\n");
	}
	void setScriptType(unsigned int st)
	{
		if(st == 0) return;
		fprintf(mFile,"\tsetAttr \".st\" %i;\n", st);
	}
	void getBefore()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getAfter()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getScriptType()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
protected:
	Script(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SCRIPT_H__
