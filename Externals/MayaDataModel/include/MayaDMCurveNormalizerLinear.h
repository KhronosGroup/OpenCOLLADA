/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVENORMALIZERLINEAR_H__
#define __MayaDM_CURVENORMALIZERLINEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveNormalizer.h"
namespace MayaDM
{
class CurveNormalizerLinear : public CurveNormalizer
{
public:
public:
	CurveNormalizerLinear(FILE* file,const std::string& name,const std::string& parent=""):CurveNormalizer(file, name, parent, "curveNormalizerLinear"){}
	virtual ~CurveNormalizerLinear(){}
	void setAnimInput(double ai)
	{
		if(ai == 0) return;
		fprintf(mFile,"setAttr \".ai\" %f;\n", ai);

	}
	void getAnimInput()
	{
		fprintf(mFile,"\"%s.ai\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	CurveNormalizerLinear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveNormalizer(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVENORMALIZERLINEAR_H__
