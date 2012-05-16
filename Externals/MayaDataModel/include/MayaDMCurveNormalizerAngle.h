/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVENORMALIZERANGLE_H__
#define __MayaDM_CURVENORMALIZERANGLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveNormalizer.h"
namespace MayaDM
{
class CurveNormalizerAngle : public CurveNormalizer
{
public:
public:

	CurveNormalizerAngle():CurveNormalizer(){}
	CurveNormalizerAngle(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:CurveNormalizer(file, name, parent, "curveNormalizerAngle", shared, create){}
	virtual ~CurveNormalizerAngle(){}

	void setAnimInput(double ai)
	{
		if(ai == 0) return;
		fprintf(mFile,"\tsetAttr \".ai\" %f;\n", ai);
	}
	void getAnimInput()const
	{
		fprintf(mFile,"\"%s.ai\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	CurveNormalizerAngle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:CurveNormalizer(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVENORMALIZERANGLE_H__
