/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CACHEBASE_H__
#define __MayaDM_CACHEBASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class CacheBase : public DependNode
{
public:
public:

	CacheBase():DependNode(){}
	CacheBase(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "cacheBase", shared, create){}
	virtual ~CacheBase(){}

	void getOutCacheData(size_t ocd_i)const
	{
		fprintf(mFile,"\"%s.ocd[%i]\"",mName.c_str(),ocd_i);
	}
	void getOutCacheData()const
	{

		fprintf(mFile,"\"%s.ocd\"",mName.c_str());
	}
	void getInRange()const
	{
		fprintf(mFile,"\"%s.ir\"",mName.c_str());
	}
protected:
	CacheBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CACHEBASE_H__
