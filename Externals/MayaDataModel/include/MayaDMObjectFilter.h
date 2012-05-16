/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTFILTER_H__
#define __MayaDM_OBJECTFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ObjectFilter : public DependNode
{
public:
public:

	ObjectFilter():DependNode(){}
	ObjectFilter(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "objectFilter", shared, create){}
	virtual ~ObjectFilter(){}

	void setChild(bool ch)
	{
		if(ch == 0) return;
		fprintf(mFile,"\tsetAttr \".ch\" %i;\n", ch);
	}
	void setInvert(bool inv)
	{
		if(inv == 0) return;
		fprintf(mFile,"\tsetAttr \".inv\" %i;\n", inv);
	}
	void setAnnotation(const string& an)
	{
		if(an == "NULL") return;
		fprintf(mFile,"\tsetAttr \".an\" -type \"string\" ");
		an.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCategory(const stringArray& cat)
	{
		fprintf(mFile,"\tsetAttr \".cat\" -type \"stringArray\" ");
		cat.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDisable(bool dis)
	{
		if(dis == 0) return;
		fprintf(mFile,"\tsetAttr \".dis\" %i;\n", dis);
	}
	void setFilterClass(unsigned int fcls)
	{
		if(fcls == 0) return;
		fprintf(mFile,"\tsetAttr \".fcls\" %i;\n", fcls);
	}
	void getChild()const
	{
		fprintf(mFile,"\"%s.ch\"",mName.c_str());
	}
	void getInvert()const
	{
		fprintf(mFile,"\"%s.inv\"",mName.c_str());
	}
	void getInputList()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getOutputList()const
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());
	}
	void getAnnotation()const
	{
		fprintf(mFile,"\"%s.an\"",mName.c_str());
	}
	void getCategory()const
	{
		fprintf(mFile,"\"%s.cat\"",mName.c_str());
	}
	void getDisable()const
	{
		fprintf(mFile,"\"%s.dis\"",mName.c_str());
	}
	void getFilterClass()const
	{
		fprintf(mFile,"\"%s.fcls\"",mName.c_str());
	}
protected:
	ObjectFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTFILTER_H__
