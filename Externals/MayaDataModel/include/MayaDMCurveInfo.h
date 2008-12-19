/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEINFO_H__
#define __MayaDM_CURVEINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class CurveInfo : public AbstractBaseCreate
{
public:
public:
	CurveInfo(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "curveInfo"){}
	virtual ~CurveInfo(){}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getArcLength()
	{
		fprintf(mFile,"\"%s.al\"",mName.c_str());

	}
	void getControlPoints(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i]\"",mName.c_str(),cp_i);

	}
	void getXValue(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i].xv\"",mName.c_str(),cp_i);

	}
	void getYValue(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i].yv\"",mName.c_str(),cp_i);

	}
	void getZValue(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i].zv\"",mName.c_str(),cp_i);

	}
	void getWeights(size_t wt_i)
	{
		fprintf(mFile,"\"%s.wt[%i]\"",mName.c_str(),wt_i);

	}
	void getKnots(size_t kn_i)
	{
		fprintf(mFile,"\"%s.kn[%i]\"",mName.c_str(),kn_i);

	}
protected:
	CurveInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEINFO_H__
