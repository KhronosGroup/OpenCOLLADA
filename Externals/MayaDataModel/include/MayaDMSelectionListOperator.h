/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SELECTIONLISTOPERATOR_H__
#define __MayaDM_SELECTIONLISTOPERATOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SelectionListOperator : public DependNode
{
public:
public:

	SelectionListOperator():DependNode(){}
	SelectionListOperator(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "selectionListOperator", shared, create){}
	virtual ~SelectionListOperator(){}

	void setOperation(unsigned int op)
	{
		if(op == 0) return;
		fprintf(mFile,"\tsetAttr \".op\" %i;\n", op);
	}
	void setOperatorClass(unsigned int ocls)
	{
		if(ocls == 0) return;
		fprintf(mFile,"\tsetAttr \".ocls\" %i;\n", ocls);
	}
	void getOperation()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getInputListA()const
	{
		fprintf(mFile,"\"%s.ina\"",mName.c_str());
	}
	void getInputListB()const
	{
		fprintf(mFile,"\"%s.inb\"",mName.c_str());
	}
	void getOutputList()const
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());
	}
	void getOperatorClass()const
	{
		fprintf(mFile,"\"%s.ocls\"",mName.c_str());
	}
protected:
	SelectionListOperator(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SELECTIONLISTOPERATOR_H__
