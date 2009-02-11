/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVCOLLAPSE_H__
#define __MayaDM_SUBDIVCOLLAPSE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SubdivCollapse : public DependNode
{
public:
public:
	SubdivCollapse():DependNode(){}
	SubdivCollapse(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdivCollapse"){}
	virtual ~SubdivCollapse(){}
	void setLevel(int l)
	{
		if(l == 0) return;
		fprintf(mFile,"\tsetAttr \".l\" %i;\n", l);

	}
	void getInSubdiv()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getOutSubdiv()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getLevel()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
protected:
	SubdivCollapse(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVCOLLAPSE_H__
