/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTERCLOSESTSAMPLE_H__
#define __MayaDM_FILTERCLOSESTSAMPLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFilter.h"
namespace MayaDM
{
class FilterClosestSample : public Filter
{
public:
public:

	FilterClosestSample():Filter(){}
	FilterClosestSample(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Filter(file, name, parent, "filterClosestSample", shared, create){}
	virtual ~FilterClosestSample(){}

	void setFrequency(double f)
	{
		if(f == 30.) return;
		fprintf(mFile,"\tsetAttr \".f\" %f;\n", f);
	}
	void getFrequency()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
protected:
	FilterClosestSample(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Filter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FILTERCLOSESTSAMPLE_H__
