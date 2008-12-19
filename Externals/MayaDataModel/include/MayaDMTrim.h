/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRIM_H__
#define __MayaDM_TRIM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class Trim : public AbstractBaseCreate
{
public:
public:
	Trim(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "trim"){}
	virtual ~Trim(){}
	void setLocatorU(size_t lu_i,double lu)
	{
		if(lu == 0.5) return;
		fprintf(mFile,"setAttr \".lu[%i]\" %f;\n", lu_i,lu);

	}
	void setLocatorV(size_t lv_i,double lv)
	{
		if(lv == 0.5) return;
		fprintf(mFile,"setAttr \".lv[%i]\" %f;\n", lv_i,lv);

	}
	void setSelected(unsigned int sl)
	{
		if(sl == 0) return;
		fprintf(mFile,"setAttr \".sl\" %i;\n", sl);

	}
	void setShrink(bool sh)
	{
		if(sh == false) return;
		fprintf(mFile,"setAttr \".sh\" %i;\n", sh);

	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void getInputCurve(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i]\"",mName.c_str(),ic_i);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getLocatorU(size_t lu_i)
	{
		fprintf(mFile,"\"%s.lu[%i]\"",mName.c_str(),lu_i);

	}
	void getLocatorV(size_t lv_i)
	{
		fprintf(mFile,"\"%s.lv[%i]\"",mName.c_str(),lv_i);

	}
	void getSelected()
	{
		fprintf(mFile,"\"%s.sl\"",mName.c_str());

	}
	void getShrink()
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getUsedCurves(size_t uc_i)
	{
		fprintf(mFile,"\"%s.uc[%i]\"",mName.c_str(),uc_i);

	}
	void getSplitSurface()
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getShouldBeLast()
	{
		fprintf(mFile,"\"%s.sbl\"",mName.c_str());

	}
protected:
	Trim(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TRIM_H__
