/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NETWORK_H__
#define __MayaDM_NETWORK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Network : public DependNode
{
public:
public:

	Network():DependNode(){}
	Network(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "network", shared, create){}
	virtual ~Network(){}

	void getAffects(size_t a_i)const
	{
		fprintf(mFile,"\"%s.a[%i]\"",mName.c_str(),a_i);
	}
	void getAffects()const
	{

		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getAffectedBy(size_t ab_i)const
	{
		fprintf(mFile,"\"%s.ab[%i]\"",mName.c_str(),ab_i);
	}
	void getAffectedBy()const
	{

		fprintf(mFile,"\"%s.ab\"",mName.c_str());
	}
protected:
	Network(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NETWORK_H__
