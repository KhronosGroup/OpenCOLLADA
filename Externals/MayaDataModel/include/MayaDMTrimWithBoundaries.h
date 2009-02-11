/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRIMWITHBOUNDARIES_H__
#define __MayaDM_TRIMWITHBOUNDARIES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class TrimWithBoundaries : public AbstractBaseCreate
{
public:
public:
	TrimWithBoundaries():AbstractBaseCreate(){}
	TrimWithBoundaries(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "trimWithBoundaries"){}
	virtual ~TrimWithBoundaries(){}
	void setFlipNormal(bool fn)
	{
		if(fn == false) return;
		fprintf(mFile,"\tsetAttr \".fn\" %i;\n", fn);

	}
	void setTolerancePE(double tpe)
	{
		if(tpe == 0) return;
		fprintf(mFile,"\tsetAttr \".tpe\" %f;\n", tpe);

	}
	void setToleranceE(double te)
	{
		if(te == 0) return;
		fprintf(mFile,"\tsetAttr \".te\" %f;\n", te);

	}
	void getInputBoundaries(size_t ib_i)
	{
		fprintf(mFile,"\"%s.ib[%i]\"",mName.c_str(),ib_i);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getFlipNormal()
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());

	}
	void getTolerancePE()
	{
		fprintf(mFile,"\"%s.tpe\"",mName.c_str());

	}
	void getToleranceE()
	{
		fprintf(mFile,"\"%s.te\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	TrimWithBoundaries(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TRIMWITHBOUNDARIES_H__
