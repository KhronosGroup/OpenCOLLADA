/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSUBDIV_H__
#define __MayaDM_CURVEFROMSUBDIV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveRange.h"
namespace MayaDM
{
class CurveFromSubdiv : public CurveRange
{
public:
public:
	CurveFromSubdiv(FILE* file,const std::string& name,const std::string& parent=""):CurveRange(file, name, parent, "curveFromSubdiv"){}
	virtual ~CurveFromSubdiv(){}
	void setMinValue(double min)
	{
		if(min == 1.0) return;
		fprintf(mFile,"setAttr \".min\" %f;\n", min);

	}
	void setMaxValue(double max)
	{
		if(max == -1.0) return;
		fprintf(mFile,"setAttr \".max\" %f;\n", max);

	}
	void setRelative(bool r)
	{
		if(r == false) return;
		fprintf(mFile,"setAttr \".r\" %i;\n", r);

	}
	void getInputSubdiv()
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
	CurveFromSubdiv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveRange(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSUBDIV_H__
