/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFAULTSHADERLIST_H__
#define __MayaDM_DEFAULTSHADERLIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DefaultShaderList : public DependNode
{
public:
public:
	DefaultShaderList():DependNode(){}
	DefaultShaderList(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:DependNode(file, name, parent, "defaultShaderList", create){}
	virtual ~DefaultShaderList(){}
	void getShaders(size_t s_i)const
	{
		fprintf(mFile,"\"%s.s[%i]\"",mName.c_str(),s_i);

	}
protected:
	DefaultShaderList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:DependNode(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFAULTSHADERLIST_H__
