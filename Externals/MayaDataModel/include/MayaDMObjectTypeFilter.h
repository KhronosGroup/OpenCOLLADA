/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTTYPEFILTER_H__
#define __MayaDM_OBJECTTYPEFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
class ObjectTypeFilter : public ObjectFilter
{
public:
public:
	ObjectTypeFilter():ObjectFilter(){}
	ObjectTypeFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectTypeFilter"){}
	virtual ~ObjectTypeFilter(){}
	void setTypeName(const string& tnam)
	{
		if(tnam == "NULL") return;
		fprintf(mFile,"\tsetAttr \".tnam\" -type \"string\" ");
		tnam.write(mFile);
		fprintf(mFile,";\n");

	}
	void getTypeName()
	{
		fprintf(mFile,"\"%s.tnam\"",mName.c_str());

	}
	void getType()
	{
		fprintf(mFile,"\"%s.typ\"",mName.c_str());

	}
protected:
	ObjectTypeFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:ObjectFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTTYPEFILTER_H__
