/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SMOOTHCURVE_H__
#define __MayaDM_SMOOTHCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class SmoothCurve : public AbstractBaseCreate
{
public:
public:
	SmoothCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "smoothCurve"){}
	virtual ~SmoothCurve(){}
	void setSmoothness(double s)
	{
		if(s == 10.0) return;
		fprintf(mFile,"setAttr \".s\" %f;\n", s);

	}
	void setIndex(size_t i_i,int i)
	{
		if(i == 0) return;
		fprintf(mFile,"setAttr \".i[%i]\" %i;\n", i_i,i);

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getSmoothness()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getIndex(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);

	}
	void getOutputCurve()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
protected:
	SmoothCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SMOOTHCURVE_H__
