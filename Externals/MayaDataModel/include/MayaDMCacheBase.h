/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	CacheBase(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "cacheBase"){}
	virtual ~CacheBase(){}
	void getOutCacheData(size_t ocd_i)
	{
		fprintf(mFile,"\"%s.ocd[%i]\"",mName.c_str(),ocd_i);

	}
	void getInRange()
	{
		fprintf(mFile,"\"%s.ir\"",mName.c_str());

	}
protected:
	CacheBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CACHEBASE_H__
