/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STITCHASNURBSSHELL_H__
#define __MayaDM_STITCHASNURBSSHELL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class StitchAsNurbsShell : public AbstractBaseCreate
{
public:
public:

	StitchAsNurbsShell():AbstractBaseCreate(){}
	StitchAsNurbsShell(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "stitchAsNurbsShell", shared, create){}
	virtual ~StitchAsNurbsShell(){}

	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void getInputSurface(size_t is_i)const
	{
		fprintf(mFile,"\"%s.is[%i]\"",mName.c_str(),is_i);
	}
	void getInputSurface()const
	{

		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getOutputShell()const
	{
		fprintf(mFile,"\"%s.osh\"",mName.c_str());
	}
protected:
	StitchAsNurbsShell(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_STITCHASNURBSSHELL_H__
