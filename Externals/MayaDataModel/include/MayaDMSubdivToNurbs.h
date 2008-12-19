/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	SubdivToNurbs(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "subdivToNurbs"){}
	virtual ~SubdivToNurbs(){}
	void setOutputType(unsigned int ot)
	{
		if(ot == 0) return;
		fprintf(mFile,"setAttr \".ot\" %i;\n", ot);

	}
	void setApplyMatrixToResult(bool amr)
	{
		if(amr == true) return;
		fprintf(mFile,"setAttr \".amr\" %i;\n", amr);

	}
	void getOutputSurfaces(size_t os_i)
	{
		fprintf(mFile,"\"%s.os[%i]\"",mName.c_str(),os_i);

	}
	void getOutputType()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getApplyMatrixToResult()
	{
		fprintf(mFile,"\"%s.amr\"",mName.c_str());

	}
protected:
	SubdivToNurbs(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVTONURBS_H__
