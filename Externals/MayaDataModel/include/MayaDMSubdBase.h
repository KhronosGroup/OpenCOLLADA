/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDBASE_H__
#define __MayaDM_SUBDBASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SubdBase : public DependNode
{
public:
public:
	SubdBase():DependNode(){}
	SubdBase(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdBase"){}
	virtual ~SubdBase(){}
	void getOutSubdiv()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	SubdBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDBASE_H__
