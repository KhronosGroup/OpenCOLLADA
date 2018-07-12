/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSEPARATE_H__
#define __MayaDM_POLYSEPARATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class PolySeparate : public DependNode
{
public:
public:

	PolySeparate():DependNode(){}
	PolySeparate(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "polySeparate", shared, create){}
	virtual ~PolySeparate(){}

	void setUseOldPolyArchitecture(bool uopa)
	{
		if(uopa == false) return;
		fprintf(mFile,"\tsetAttr \".uopa\" %i;\n", uopa);
	}
	void setIcount(int ic)
	{
		if(ic == -1) return;
		fprintf(mFile,"\tsetAttr \".ic\" %i;\n", ic);
	}
	void setRemShells(const intArray& rs)
	{
		if(rs.size == 0) return;
		fprintf(mFile,"\tsetAttr \".rs\" -type \"intArray\" ");
		rs.write(mFile);
		fprintf(mFile,";\n");
	}
	void getInputPoly()const
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());
	}
	void getIcount()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getRemShells()const
	{
		fprintf(mFile,"\"%s.rs\"",mName.c_str());
	}
	void getOutput(size_t out_i)const
	{
		fprintf(mFile,"\"%s.out[%i]\"",mName.c_str(),out_i);
	}
	void getOutput()const
	{

		fprintf(mFile,"\"%s.out\"",mName.c_str());
	}
protected:
	PolySeparate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSEPARATE_H__
