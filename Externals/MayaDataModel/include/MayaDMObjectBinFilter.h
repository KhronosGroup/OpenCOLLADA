/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTBINFILTER_H__
#define __MayaDM_OBJECTBINFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
class ObjectBinFilter : public ObjectFilter
{
public:
public:
	ObjectBinFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectBinFilter"){}
	virtual ~ObjectBinFilter(){}
	void setBinName(const string& bnam)
	{
		if(bnam == "NULL") return;
		fprintf(mFile,"setAttr \".bnam\" -type \"string\" ");
		bnam.write(mFile);
		fprintf(mFile,";\n");

	}
	void getBinName()
	{
		fprintf(mFile,"\"%s.bnam\"",mName.c_str());

	}
protected:
	ObjectBinFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTBINFILTER_H__
