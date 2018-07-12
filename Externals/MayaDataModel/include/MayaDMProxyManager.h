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
	ProxyManager(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "proxyManager", shared, create){}
	virtual ~ProxyManager(){}

	void getProxyList(size_t plst_i)const
	{
		fprintf(mFile,"\"%s.plst[%i]\"",mName.c_str(),plst_i);
	}
	void getProxyList()const
	{

		fprintf(mFile,"\"%s.plst\"",mName.c_str());
	}
	void getActiveProxy()const
	{
		fprintf(mFile,"\"%s.aprx\"",mName.c_str());
	}
	void getSharedEditsOwner()const
	{
		fprintf(mFile,"\"%s.psed\"",mName.c_str());
	}
protected:
	ProxyManager(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PROXYMANAGER_H__
