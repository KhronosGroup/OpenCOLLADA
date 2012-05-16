/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BIRAILSRF_H__
#define __MayaDM_BIRAILSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class BirailSrf : public AbstractBaseCreate
{
public:
public:

	BirailSrf():AbstractBaseCreate(){}
	BirailSrf(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "birailSrf", shared, create){}
	virtual ~BirailSrf(){}

	void setTransformMode(unsigned int tm)
	{
		if(tm == 0) return;
		fprintf(mFile,"\tsetAttr \".tm\" %i;\n", tm);
	}
	void getInputRail1()const
	{
		fprintf(mFile,"\"%s.ir1\"",mName.c_str());
	}
	void getInputRail2()const
	{
		fprintf(mFile,"\"%s.ir2\"",mName.c_str());
	}
	void getSweepStyle()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getTransformMode()const
	{
		fprintf(mFile,"\"%s.tm\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
protected:
	BirailSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BIRAILSRF_H__
