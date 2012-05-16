/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	ResultCurve():AnimCurve(){}
	ResultCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AnimCurve(file, name, parent, "resultCurve", shared, create){}
	virtual ~ResultCurve(){}

	void setStart(double st)
	{
		if(st == 0) return;
		fprintf(mFile,"\tsetAttr \".st\" %f;\n", st);
	}
	void setEnd(double et)
	{
		if(et == 3) return;
		fprintf(mFile,"\tsetAttr \".et\" %f;\n", et);
	}
	void setSampleBy(double sby)
	{
		if(sby == 1) return;
		fprintf(mFile,"\tsetAttr \".sby\" %f;\n", sby);
	}
	void getStart()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getEnd()const
	{
		fprintf(mFile,"\"%s.et\"",mName.c_str());
	}
	void getSampleBy()const
	{
		fprintf(mFile,"\"%s.sby\"",mName.c_str());
	}
protected:
	ResultCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AnimCurve(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RESULTCURVE_H__
