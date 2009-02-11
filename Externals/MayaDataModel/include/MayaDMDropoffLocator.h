/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DROPOFFLOCATOR_H__
#define __MayaDM_DROPOFFLOCATOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLocator.h"
namespace MayaDM
{
class DropoffLocator : public Locator
{
public:
public:
	DropoffLocator():Locator(){}
	DropoffLocator(FILE* file,const std::string& name,const std::string& parent=""):Locator(file, name, parent, "dropoffLocator"){}
	virtual ~DropoffLocator(){}
	void setPercent(float pc)
	{
		if(pc == 1) return;
		fprintf(mFile,"\tsetAttr \".pc\" %f;\n", pc);

	}
	void setParam(float pr)
	{
		if(pr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pr\" %f;\n", pr);

	}
	void getPercent()
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());

	}
	void getParam()
	{
		fprintf(mFile,"\"%s.pr\"",mName.c_str());

	}
protected:
	DropoffLocator(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Locator(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DROPOFFLOCATOR_H__
