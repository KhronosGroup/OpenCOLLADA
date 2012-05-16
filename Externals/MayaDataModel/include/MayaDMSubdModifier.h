/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDMODIFIER_H__
#define __MayaDM_SUBDMODIFIER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdBase.h"
namespace MayaDM
{
class SubdModifier : public SubdBase
{
public:
public:

	SubdModifier():SubdBase(){}
	SubdModifier(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SubdBase(file, name, parent, "subdModifier", shared, create){}
	virtual ~SubdModifier(){}

	void setInputComponents(const componentList& ics)
	{
		fprintf(mFile,"\tsetAttr \".ics\" -type \"componentList\" ");
		ics.write(mFile);
		fprintf(mFile,";\n");
	}
	void getInSubdiv()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getCachedSubdiv()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getInputComponents()const
	{
		fprintf(mFile,"\"%s.ics\"",mName.c_str());
	}
protected:
	SubdModifier(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SubdBase(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDMODIFIER_H__
