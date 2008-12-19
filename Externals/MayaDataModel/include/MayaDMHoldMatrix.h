/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	HoldMatrix(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "holdMatrix"){}
	virtual ~HoldMatrix(){}
	void setInMatrix(const matrix& i)
	{
		if(i == identity) return;
		fprintf(mFile,"setAttr \".i\" -type \"matrix\" ");
		i.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutMatrix(const matrix& o)
	{
		if(o == identity) return;
		fprintf(mFile,"setAttr \".o\" -type \"matrix\" ");
		o.write(mFile);
		fprintf(mFile,";\n");

	}
	void getInMatrix()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getOutMatrix()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	HoldMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HOLDMATRIX_H__
