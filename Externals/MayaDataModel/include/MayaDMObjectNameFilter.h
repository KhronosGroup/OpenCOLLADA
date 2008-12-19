/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTNAMEFILTER_H__
#define __MayaDM_OBJECTNAMEFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
class ObjectNameFilter : public ObjectFilter
{
public:
public:
	ObjectNameFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectNameFilter"){}
	virtual ~ObjectNameFilter(){}
	void setRegExp(const string& rex)
	{
		if(rex == "NULL") return;
		fprintf(mFile,"setAttr \".rex\" -type \"string\" ");
		rex.write(mFile);
		fprintf(mFile,";\n");

	}
	void setNameStrings(const stringArray& nstr)
	{
		if(nstr.size == 0) return;
		fprintf(mFile,"setAttr \".nstr\" -type \"stringArray\" ");
		nstr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAttrName(bool attr)
	{
		if(attr == false) return;
		fprintf(mFile,"setAttr \".attr\" %i;\n", attr);

	}
	void getRegExp()
	{
		fprintf(mFile,"\"%s.rex\"",mName.c_str());

	}
	void getNameStrings()
	{
		fprintf(mFile,"\"%s.nstr\"",mName.c_str());

	}
	void getAttrName()
	{
		fprintf(mFile,"\"%s.attr\"",mName.c_str());

	}
protected:
	ObjectNameFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTNAMEFILTER_H__
