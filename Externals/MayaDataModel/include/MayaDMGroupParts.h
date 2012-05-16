/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GROUPPARTS_H__
#define __MayaDM_GROUPPARTS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class GroupParts : public DependNode
{
public:
public:

	GroupParts():DependNode(){}
	GroupParts(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "groupParts", shared, create){}
	virtual ~GroupParts(){}

	void setInputComponents(const componentList& ic)
	{
		fprintf(mFile,"\tsetAttr \".ic\" -type \"componentList\" ");
		ic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputRemoveComponent(const componentList& irc)
	{
		fprintf(mFile,"\tsetAttr \".irc\" -type \"componentList\" ");
		irc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGroupId(int gi)
	{
		if(gi == -1) return;
		fprintf(mFile,"\tsetAttr \".gi\" %i;\n", gi);
	}
	void getInputGeometry()const
	{
		fprintf(mFile,"\"%s.ig\"",mName.c_str());
	}
	void getInputComponents()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getInputRemoveComponent()const
	{
		fprintf(mFile,"\"%s.irc\"",mName.c_str());
	}
	void getOutputGeometry()const
	{
		fprintf(mFile,"\"%s.og\"",mName.c_str());
	}
	void getGroupId()const
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());
	}
protected:
	GroupParts(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_GROUPPARTS_H__
