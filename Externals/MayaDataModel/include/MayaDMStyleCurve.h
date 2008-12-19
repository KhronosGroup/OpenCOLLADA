/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	StyleCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "styleCurve"){}
	virtual ~StyleCurve(){}
	void setStyle(unsigned int s)
	{
		if(s == 0) return;
		fprintf(mFile,"setAttr \".s\" %i;\n", s);

	}
	void getStyle()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getOutCurve()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
protected:
	StyleCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_STYLECURVE_H__
