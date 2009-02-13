/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXPLODENURBSSHELL_H__
#define __MayaDM_EXPLODENURBSSHELL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class ExplodeNurbsShell : public AbstractBaseCreate
{
public:
public:
	ExplodeNurbsShell():AbstractBaseCreate(){}
	ExplodeNurbsShell(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:AbstractBaseCreate(file, name, parent, "explodeNurbsShell", create){}
	virtual ~ExplodeNurbsShell(){}
	void getInputShell()const
	{
		fprintf(mFile,"\"%s.ish\"",mName.c_str());

	}
	void getOutputSurface(size_t os_i)const
	{
		fprintf(mFile,"\"%s.os[%i]\"",mName.c_str(),os_i);

	}
protected:
	ExplodeNurbsShell(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_EXPLODENURBSSHELL_H__
