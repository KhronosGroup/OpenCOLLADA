/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PROXYMANAGER_H__
#define __MayaDM_PROXYMANAGER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ProxyManager : public DependNode
{
public:
public:
	ProxyManager():DependNode(){}
	ProxyManager(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "proxyManager"){}
	virtual ~ProxyManager(){}
	void getProxyList(size_t plst_i)
	{
		fprintf(mFile,"\"%s.plst[%i]\"",mName.c_str(),plst_i);

	}
	void getActiveProxy()
	{
		fprintf(mFile,"\"%s.aprx\"",mName.c_str());

	}
	void getSharedEditsOwner()
	{
		fprintf(mFile,"\"%s.psed\"",mName.c_str());

	}
protected:
	ProxyManager(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PROXYMANAGER_H__
