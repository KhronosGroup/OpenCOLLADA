/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CONTAINER_H__
#define __MayaDM_CONTAINER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Container : public DependNode
{
public:
public:

	Container():DependNode(){}
	Container(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "container", shared, create){}
	virtual ~Container(){}

	void setIsCollapsed(bool isc)
	{
		if(isc == false) return;
		fprintf(mFile,"\tsetAttr \".isc\" %i;\n", isc);
	}
	void getHyperLayout()const
	{
		fprintf(mFile,"\"%s.hl\"",mName.c_str());
	}
	void getIsCollapsed()const
	{
		fprintf(mFile,"\"%s.isc\"",mName.c_str());
	}
protected:
	Container(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CONTAINER_H__
