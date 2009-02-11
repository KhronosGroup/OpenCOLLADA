/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTATTRFILTER_H__
#define __MayaDM_OBJECTATTRFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
class ObjectAttrFilter : public ObjectFilter
{
public:
public:
	ObjectAttrFilter():ObjectFilter(){}
	ObjectAttrFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectAttrFilter"){}
	virtual ~ObjectAttrFilter(){}
	void setAttrType(unsigned int atyp)
	{
		if(atyp == 1) return;
		fprintf(mFile,"\tsetAttr \".atyp\" %i;\n", atyp);

	}
	void getAttrType()
	{
		fprintf(mFile,"\"%s.atyp\"",mName.c_str());

	}
protected:
	ObjectAttrFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:ObjectFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTATTRFILTER_H__
