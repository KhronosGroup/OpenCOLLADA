/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RESULTCURVE_H__
#define __MayaDM_RESULTCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAnimCurve.h"
namespace MayaDM
{
class ResultCurve : public AnimCurve
{
public:
public:
	ResultCurve(FILE* file,const std::string& name,const std::string& parent=""):AnimCurve(file, name, parent, "resultCurve"){}
	virtual ~ResultCurve(){}
	void getStart()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getEnd()
	{
		fprintf(mFile,"\"%s.et\"",mName.c_str());

	}
	void getSampleBy()
	{
		fprintf(mFile,"\"%s.sby\"",mName.c_str());

	}
protected:
	ResultCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AnimCurve(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RESULTCURVE_H__
