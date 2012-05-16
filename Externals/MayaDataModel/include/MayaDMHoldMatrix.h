/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HOLDMATRIX_H__
#define __MayaDM_HOLDMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class HoldMatrix : public DependNode
{
public:
public:

	HoldMatrix():DependNode(){}
	HoldMatrix(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "holdMatrix", shared, create){}
	virtual ~HoldMatrix(){}

	void setInMatrix(const matrix& i_)
	{
		if(i_ == identity) return;
		fprintf(mFile,"\tsetAttr \".i\" -type \"matrix\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOutMatrix(const matrix& o)
	{
		if(o == identity) return;
		fprintf(mFile,"\tsetAttr \".o\" -type \"matrix\" ");
		o.write(mFile);
		fprintf(mFile,";\n");
	}
	void getInMatrix()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutMatrix()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	HoldMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HOLDMATRIX_H__
