/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_INSERTKNOTCURVE_H__
#define __MayaDM_INSERTKNOTCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class InsertKnotCurve : public AbstractBaseCreate
{
public:
public:
	InsertKnotCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "insertKnotCurve"){}
	virtual ~InsertKnotCurve(){}
	void setParameter(size_t p_i,double p)
	{
		if(p == 0.0) return;
		fprintf(mFile,"setAttr \".p[%i]\" %f;\n", p_i,p);

	}
	void setNumberOfKnots(size_t nk_i,int nk)
	{
		if(nk == 1) return;
		fprintf(mFile,"setAttr \".nk[%i]\" %i;\n", nk_i,nk);

	}
	void setAddKnots(bool add)
	{
		if(add == true) return;
		fprintf(mFile,"setAttr \".add\" %i;\n", add);

	}
	void setInsertBetween(bool ib)
	{
		if(ib == false) return;
		fprintf(mFile,"setAttr \".ib\" %i;\n", ib);

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getParameter(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);

	}
	void getNumberOfKnots(size_t nk_i)
	{
		fprintf(mFile,"\"%s.nk[%i]\"",mName.c_str(),nk_i);

	}
	void getAddKnots()
	{
		fprintf(mFile,"\"%s.add\"",mName.c_str());

	}
	void getInsertBetween()
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());

	}
	void getOutputCurve()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
protected:
	InsertKnotCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_INSERTKNOTCURVE_H__
