/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTERRESAMPLE_H__
#define __MayaDM_FILTERRESAMPLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFilter.h"
namespace MayaDM
{
class FilterResample : public Filter
{
public:
public:
	FilterResample(FILE* file,const std::string& name,const std::string& parent=""):Filter(file, name, parent, "filterResample"){}
	virtual ~FilterResample(){}
	void setKernel(unsigned int kr)
	{
		if(kr == 600) return;
		fprintf(mFile,"setAttr \".kr\" %i;\n", kr);

	}
	void getTimeStep()
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());

	}
	void getKernel()
	{
		fprintf(mFile,"\"%s.kr\"",mName.c_str());

	}
protected:
	FilterResample(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Filter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FILTERRESAMPLE_H__
