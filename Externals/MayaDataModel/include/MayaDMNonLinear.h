/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NONLINEAR_H__
#define __MayaDM_NONLINEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class NonLinear : public GeometryFilter
{
public:
public:

	NonLinear():GeometryFilter(){}
	NonLinear(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, "nonLinear", shared, create){}
	virtual ~NonLinear(){}

	void setMatrix(const matrix& ma)
	{
		if(ma == identity) return;
		fprintf(mFile,"\tsetAttr \".ma\" -type \"matrix\" ");
		ma.write(mFile);
		fprintf(mFile,";\n");
	}
	void getDeformerData()const
	{
		fprintf(mFile,"\"%s.dd\"",mName.c_str());
	}
	void getMatrix()const
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());
	}
protected:
	NonLinear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NONLINEAR_H__
