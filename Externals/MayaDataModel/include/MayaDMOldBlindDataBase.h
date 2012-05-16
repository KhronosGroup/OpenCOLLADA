/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OLDBLINDDATABASE_H__
#define __MayaDM_OLDBLINDDATABASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class OldBlindDataBase : public DependNode
{
public:
public:

	OldBlindDataBase():DependNode(){}
	OldBlindDataBase(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "oldBlindDataBase", shared, create){}
	virtual ~OldBlindDataBase(){}

	void setTypeId(int tid)
	{
		if(tid == 0) return;
		fprintf(mFile,"\tsetAttr \".tid\" %i;\n", tid);
	}
	void getTypeId()const
	{
		fprintf(mFile,"\"%s.tid\"",mName.c_str());
	}
protected:
	OldBlindDataBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OLDBLINDDATABASE_H__
