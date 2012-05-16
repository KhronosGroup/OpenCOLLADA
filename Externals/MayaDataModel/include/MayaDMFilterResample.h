/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	FilterResample():Filter(){}
	FilterResample(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Filter(file, name, parent, "filterResample", shared, create){}
	virtual ~FilterResample(){}

	void setTimeStep(double ts)
	{
		if(ts == 0) return;
		fprintf(mFile,"\tsetAttr \".ts\" %f;\n", ts);
	}
	void setKernel(unsigned int kr)
	{
		if(kr == 600) return;
		fprintf(mFile,"\tsetAttr \".kr\" %i;\n", kr);
	}
	void getTimeStep()const
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());
	}
	void getKernel()const
	{
		fprintf(mFile,"\"%s.kr\"",mName.c_str());
	}
protected:
	FilterResample(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Filter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FILTERRESAMPLE_H__
