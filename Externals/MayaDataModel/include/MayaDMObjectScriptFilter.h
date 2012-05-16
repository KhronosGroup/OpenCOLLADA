/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	ObjectScriptFilter():ObjectFilter(){}
	ObjectScriptFilter(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ObjectFilter(file, name, parent, "objectScriptFilter", shared, create){}
	virtual ~ObjectScriptFilter(){}

	void setArrayArg(bool aarg)
	{
		if(aarg == 1) return;
		fprintf(mFile,"\tsetAttr \".aarg\" %i;\n", aarg);
	}
	void setProcName(const string& pnam)
	{
		if(pnam == "NULL") return;
		fprintf(mFile,"\tsetAttr \".pnam\" -type \"string\" ");
		pnam.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAttrName(bool attr)
	{
		if(attr == false) return;
		fprintf(mFile,"\tsetAttr \".attr\" %i;\n", attr);
	}
	void setUniqueNodeNames(bool unn)
	{
		if(unn == 0) return;
		fprintf(mFile,"\tsetAttr \".unn\" %i;\n", unn);
	}
	void getArrayArg()const
	{
		fprintf(mFile,"\"%s.aarg\"",mName.c_str());
	}
	void getProcName()const
	{
		fprintf(mFile,"\"%s.pnam\"",mName.c_str());
	}
	void getAttrName()const
	{
		fprintf(mFile,"\"%s.attr\"",mName.c_str());
	}
	void getUniqueNodeNames()const
	{
		fprintf(mFile,"\"%s.unn\"",mName.c_str());
	}
protected:
	ObjectScriptFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ObjectFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTSCRIPTFILTER_H__
