/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FACADE_H__
#define __MayaDM_FACADE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Facade : public DependNode
{
public:
public:
	Facade(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "facade"){}
	virtual ~Facade(){}
	void setSharedLibName(const string& sln)
	{
		if(sln == "NULL") return;
		fprintf(mFile,"setAttr \".sln\" -type \"string\" ");
		sln.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUiName(const string& uin)
	{
		if(uin == "NULL") return;
		fprintf(mFile,"setAttr \".uin\" -type \"string\" ");
		uin.write(mFile);
		fprintf(mFile,";\n");

	}
	void setKeyWords(const string& kwds)
	{
		if(kwds == "NULL") return;
		fprintf(mFile,"setAttr \".kwds\" -type \"string\" ");
		kwds.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUiScript(const string& uis)
	{
		if(uis == "NULL") return;
		fprintf(mFile,"setAttr \".uis\" -type \"string\" ");
		uis.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUniqueID(const string& uid)
	{
		if(uid == "NULL") return;
		fprintf(mFile,"setAttr \".uid\" -type \"string\" ");
		uid.write(mFile);
		fprintf(mFile,";\n");

	}
	void getSharedLibName()
	{
		fprintf(mFile,"\"%s.sln\"",mName.c_str());

	}
	void getConnection()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getUiName()
	{
		fprintf(mFile,"\"%s.uin\"",mName.c_str());

	}
	void getKeyWords()
	{
		fprintf(mFile,"\"%s.kwds\"",mName.c_str());

	}
	void getUiScript()
	{
		fprintf(mFile,"\"%s.uis\"",mName.c_str());

	}
	void getUniqueID()
	{
		fprintf(mFile,"\"%s.uid\"",mName.c_str());

	}
protected:
	Facade(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FACADE_H__
