/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSURFACE_H__
#define __MayaDM_CURVEFROMSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveRange.h"
namespace MayaDM
{
class CurveFromSurface : public CurveRange
{
public:
public:
	CurveFromSurface():CurveRange(){}
	CurveFromSurface(FILE* file,const std::string& name,const std::string& parent=""):CurveRange(file, name, parent, "curveFromSurface"){}
	virtual ~CurveFromSurface(){}
	void setMinValue(double min)
	{
		if(min == 1.0) return;
		fprintf(mFile,"\tsetAttr \".min\" %f;\n", min);

	}
	void setMaxValue(double max)
	{
		if(max == -1.0) return;
		fprintf(mFile,"\tsetAttr \".max\" %f;\n", max);

	}
	void setRelative(bool r)
	{
		if(r == false) return;
		fprintf(mFile,"\tsetAttr \".r\" %i;\n", r);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getMinValue()
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());

	}
	void getMaxValue()
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());

	}
	void getRelative()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getOutputCurve()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
protected:
	CurveFromSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:CurveRange(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSURFACE_H__
