/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTSCRIPTFILTER_H__
#define __MayaDM_OBJECTSCRIPTFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
class ObjectScriptFilter : public ObjectFilter
{
public:
public:
	ObjectScriptFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectScriptFilter"){}
	virtual ~ObjectScriptFilter(){}
	void setArrayArg(bool aarg)
	{
		if(aarg == 1) return;
		fprintf(mFile,"setAttr \".aarg\" %i;\n", aarg);

	}
	void setProcName(const string& pnam)
	{
		if(pnam == "NULL") return;
		fprintf(mFile,"setAttr \".pnam\" -type \"string\" ");
		pnam.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAttrName(bool attr)
	{
		if(attr == false) return;
		fprintf(mFile,"setAttr \".attr\" %i;\n", attr);

	}
	void setUniqueNodeNames(bool unn)
	{
		if(unn == 0) return;
		fprintf(mFile,"setAttr \".unn\" %i;\n", unn);

	}
	void getArrayArg()
	{
		fprintf(mFile,"\"%s.aarg\"",mName.c_str());

	}
	void getProcName()
	{
		fprintf(mFile,"\"%s.pnam\"",mName.c_str());

	}
	void getAttrName()
	{
		fprintf(mFile,"\"%s.attr\"",mName.c_str());

	}
	void getUniqueNodeNames()
	{
		fprintf(mFile,"\"%s.unn\"",mName.c_str());

	}
protected:
	ObjectScriptFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTSCRIPTFILTER_H__
