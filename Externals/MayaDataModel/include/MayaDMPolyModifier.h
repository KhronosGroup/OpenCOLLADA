/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolyModifier(FILE* file,const std::string& name,const std::string& parent=""):PolyBase(file, name, parent, "polyModifier"){}
	virtual ~PolyModifier(){}
	void setUseOldPolyArchitecture(bool uopa)
	{
		if(uopa == false) return;
		fprintf(mFile,"setAttr \".uopa\" %i;\n", uopa);

	}
	void setInputComponents(const componentList& ics)
	{
		fprintf(mFile,"setAttr \".ics\" -type \"componentList\" ");
		ics.write(mFile);
		fprintf(mFile,";\n");

	}
	void getInputPolymesh()
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());

	}
	void getInputComponents()
	{
		fprintf(mFile,"\"%s.ics\"",mName.c_str());

	}
protected:
	PolyModifier(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyBase(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMODIFIER_H__
