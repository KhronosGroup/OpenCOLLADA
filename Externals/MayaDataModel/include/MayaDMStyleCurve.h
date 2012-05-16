/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STYLECURVE_H__
#define __MayaDM_STYLECURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class StyleCurve : public AbstractBaseCreate
{
public:
public:

	StyleCurve():AbstractBaseCreate(){}
	StyleCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "styleCurve", shared, create){}
	virtual ~StyleCurve(){}

	void setStyle(unsigned int s)
	{
		if(s == 0) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);
	}
	void getStyle()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getOutCurve()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
protected:
	StyleCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_STYLECURVE_H__
