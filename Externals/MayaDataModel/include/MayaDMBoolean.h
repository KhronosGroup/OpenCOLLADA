/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BOOLEAN_H__
#define __MayaDM_BOOLEAN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class Boolean : public AbstractBaseCreate
{
public:
public:

	Boolean():AbstractBaseCreate(){}
	Boolean(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "boolean", shared, create){}
	virtual ~Boolean(){}

	void setOperation(unsigned int op)
	{
		if(op == 0) return;
		fprintf(mFile,"\tsetAttr \".op\" %i;\n", op);
	}
	void setTolerance(double tlb)
	{
		if(tlb == 0) return;
		fprintf(mFile,"\tsetAttr \".tlb\" %f;\n", tlb);
	}
	void getInputShellA()const
	{
		fprintf(mFile,"\"%s.isa\"",mName.c_str());
	}
	void getInputShellB()const
	{
		fprintf(mFile,"\"%s.isb\"",mName.c_str());
	}
	void getOperation()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tlb\"",mName.c_str());
	}
	void getOutputShell()const
	{
		fprintf(mFile,"\"%s.osh\"",mName.c_str());
	}
protected:
	Boolean(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BOOLEAN_H__
