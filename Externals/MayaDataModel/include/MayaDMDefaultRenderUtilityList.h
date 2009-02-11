/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFAULTRENDERUTILITYLIST_H__
#define __MayaDM_DEFAULTRENDERUTILITYLIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DefaultRenderUtilityList : public DependNode
{
public:
public:
	DefaultRenderUtilityList():DependNode(){}
	DefaultRenderUtilityList(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "defaultRenderUtilityList"){}
	virtual ~DefaultRenderUtilityList(){}
	void getUtilities(size_t u_i)
	{
		fprintf(mFile,"\"%s.u[%i]\"",mName.c_str(),u_i);

	}
protected:
	DefaultRenderUtilityList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFAULTRENDERUTILITYLIST_H__
