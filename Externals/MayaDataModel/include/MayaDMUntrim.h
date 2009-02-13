/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNTRIM_H__
#define __MayaDM_UNTRIM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class Untrim : public AbstractBaseCreate
{
public:
public:
	Untrim():AbstractBaseCreate(){}
	Untrim(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:AbstractBaseCreate(file, name, parent, "untrim", create){}
	virtual ~Untrim(){}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getOutputCurve(size_t oc_i)const
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);

	}
protected:
	Untrim(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_UNTRIM_H__
