/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYBASE_H__
#define __MayaDM_POLYBASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class PolyBase : public DependNode
{
public:
public:
	PolyBase(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "polyBase"){}
	virtual ~PolyBase(){}
	void getOutput()
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());

	}
protected:
	PolyBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYBASE_H__
