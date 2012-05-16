/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTMULTIFILTER_H__
#define __MayaDM_OBJECTMULTIFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
class ObjectMultiFilter : public ObjectFilter
{
public:
public:

	ObjectMultiFilter():ObjectFilter(){}
	ObjectMultiFilter(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ObjectFilter(file, name, parent, "objectMultiFilter", shared, create){}
	virtual ~ObjectMultiFilter(){}

	void setFilterType(unsigned int ftyp)
	{
		if(ftyp == 0) return;
		fprintf(mFile,"\tsetAttr \".ftyp\" %i;\n", ftyp);
	}
	void getResultList()const
	{
		fprintf(mFile,"\"%s.res\"",mName.c_str());
	}
	void getFilterType()const
	{
		fprintf(mFile,"\"%s.ftyp\"",mName.c_str());
	}
protected:
	ObjectMultiFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ObjectFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTMULTIFILTER_H__
