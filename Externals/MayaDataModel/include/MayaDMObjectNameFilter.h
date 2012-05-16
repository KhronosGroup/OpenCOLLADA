/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	ObjectNameFilter():ObjectFilter(){}
	ObjectNameFilter(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ObjectFilter(file, name, parent, "objectNameFilter", shared, create){}
	virtual ~ObjectNameFilter(){}

	void setRegExp(const string& rex)
	{
		if(rex == "NULL") return;
		fprintf(mFile,"\tsetAttr \".rex\" -type \"string\" ");
		rex.write(mFile);
		fprintf(mFile,";\n");
	}
	void setNameStrings(const stringArray& nstr)
	{
		if(nstr.size == 0) return;
		fprintf(mFile,"\tsetAttr \".nstr\" -type \"stringArray\" ");
		nstr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAttrName(bool attr)
	{
		if(attr == false) return;
		fprintf(mFile,"\tsetAttr \".attr\" %i;\n", attr);
	}
	void getRegExp()const
	{
		fprintf(mFile,"\"%s.rex\"",mName.c_str());
	}
	void getNameStrings()const
	{
		fprintf(mFile,"\"%s.nstr\"",mName.c_str());
	}
	void getAttrName()const
	{
		fprintf(mFile,"\"%s.attr\"",mName.c_str());
	}
protected:
	ObjectNameFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ObjectFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTNAMEFILTER_H__
