/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	SelectionListOperator(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "selectionListOperator"){}
	virtual ~SelectionListOperator(){}
	void setOperation(unsigned int op)
	{
		if(op == 0) return;
		fprintf(mFile,"setAttr \".op\" %i;\n", op);

	}
	void setOperatorClass(unsigned int ocls)
	{
		if(ocls == 0) return;
		fprintf(mFile,"setAttr \".ocls\" %i;\n", ocls);

	}
	void getOperation()
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());

	}
	void getInputListA()
	{
		fprintf(mFile,"\"%s.ina\"",mName.c_str());

	}
	void getInputListB()
	{
		fprintf(mFile,"\"%s.inb\"",mName.c_str());

	}
	void getOutputList()
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());

	}
	void getOperatorClass()
	{
		fprintf(mFile,"\"%s.ocls\"",mName.c_str());

	}
protected:
	SelectionListOperator(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SELECTIONLISTOPERATOR_H__
