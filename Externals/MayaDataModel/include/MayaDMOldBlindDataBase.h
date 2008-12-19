/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	OldBlindDataBase(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "oldBlindDataBase"){}
	virtual ~OldBlindDataBase(){}
	void setTypeId(int tid)
	{
		if(tid == 0) return;
		fprintf(mFile,"setAttr \".tid\" %i;\n", tid);

	}
	void getTypeId()
	{
		fprintf(mFile,"\"%s.tid\"",mName.c_str());

	}
protected:
	OldBlindDataBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OLDBLINDDATABASE_H__
