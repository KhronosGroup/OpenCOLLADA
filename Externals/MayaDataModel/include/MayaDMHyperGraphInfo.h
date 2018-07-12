/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HYPERGRAPHINFO_H__
#define __MayaDM_HYPERGRAPHINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class HyperGraphInfo : public DependNode
{
public:
public:

	HyperGraphInfo():DependNode(){}
	HyperGraphInfo(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "hyperGraphInfo", shared, create){}
	virtual ~HyperGraphInfo(){}

	void getBookmarks(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i]\"",mName.c_str(),b_i);
	}
	void getBookmarks()const
	{

		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
protected:
	HyperGraphInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HYPERGRAPHINFO_H__
