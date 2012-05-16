/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMODIFIER_H__
#define __MayaDM_POLYMODIFIER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyBase.h"
namespace MayaDM
{
class PolyModifier : public PolyBase
{
public:
public:

	PolyModifier():PolyBase(){}
	PolyModifier(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyBase(file, name, parent, "polyModifier", shared, create){}
	virtual ~PolyModifier(){}

	void setUseOldPolyArchitecture(bool uopa)
	{
		if(uopa == false) return;
		fprintf(mFile,"\tsetAttr \".uopa\" %i;\n", uopa);
	}
	void setInputComponents(const componentList& ics)
	{
		fprintf(mFile,"\tsetAttr \".ics\" -type \"componentList\" ");
		ics.write(mFile);
		fprintf(mFile,";\n");
	}
	void getInputPolymesh()const
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());
	}
	void getInputComponents()const
	{
		fprintf(mFile,"\"%s.ics\"",mName.c_str());
	}
protected:
	PolyModifier(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyBase(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMODIFIER_H__
