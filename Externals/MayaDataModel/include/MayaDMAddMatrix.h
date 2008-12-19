/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ADDMATRIX_H__
#define __MayaDM_ADDMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class AddMatrix : public DependNode
{
public:
public:
	AddMatrix(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "addMatrix"){}
	virtual ~AddMatrix(){}
	void setMatrixIn(size_t i_i,const matrix& i)
	{
		if(i == identity) return;
		fprintf(mFile,"setAttr \".i[%i]\" -type \"matrix\" ",i_i);
		i.write(mFile);
		fprintf(mFile,";\n");

	}
	void getMatrixIn(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);

	}
	void getMatrixSum()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	AddMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ADDMATRIX_H__
