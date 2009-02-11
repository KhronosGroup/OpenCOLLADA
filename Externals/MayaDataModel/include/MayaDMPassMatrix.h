/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PASSMATRIX_H__
#define __MayaDM_PASSMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class PassMatrix : public DependNode
{
public:
public:
	PassMatrix():DependNode(){}
	PassMatrix(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "passMatrix"){}
	virtual ~PassMatrix(){}
	void setInMatrix(const matrix& i_)
	{
		if(i_ == identity) return;
		fprintf(mFile,"\tsetAttr \".i\" -type \"matrix\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInScale(double s)
	{
		if(s == 2.0) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);

	}
	void getInMatrix()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getInScale()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getOutMatrix()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	PassMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PASSMATRIX_H__
