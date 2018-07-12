/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVTONURBS_H__
#define __MayaDM_SUBDIVTONURBS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class SubdivToNurbs : public AbstractBaseCreate
{
public:
public:

	SubdivToNurbs():AbstractBaseCreate(){}
	SubdivToNurbs(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "subdivToNurbs", shared, create){}
	virtual ~SubdivToNurbs(){}

	void setOutputType(unsigned int ot)
	{
		if(ot == 0) return;
		fprintf(mFile,"\tsetAttr \".ot\" %i;\n", ot);
	}
	void setApplyMatrixToResult(bool amr)
	{
		if(amr == true) return;
		fprintf(mFile,"\tsetAttr \".amr\" %i;\n", amr);
	}
	void getInSubdiv()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutputSurfaces(size_t os_i)const
	{
		fprintf(mFile,"\"%s.os[%i]\"",mName.c_str(),os_i);
	}
	void getOutputSurfaces()const
	{

		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getOutputType()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getApplyMatrixToResult()const
	{
		fprintf(mFile,"\"%s.amr\"",mName.c_str());
	}
protected:
	SubdivToNurbs(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVTONURBS_H__
