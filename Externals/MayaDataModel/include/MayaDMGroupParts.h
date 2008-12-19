/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	GroupParts(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "groupParts"){}
	virtual ~GroupParts(){}
	void setInputComponents(const componentList& ic)
	{
		fprintf(mFile,"setAttr \".ic\" -type \"componentList\" ");
		ic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputRemoveComponent(const componentList& irc)
	{
		fprintf(mFile,"setAttr \".irc\" -type \"componentList\" ");
		irc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGroupId(int gi)
	{
		if(gi == -1) return;
		fprintf(mFile,"setAttr \".gi\" %i;\n", gi);

	}
	void getInputGeometry()
	{
		fprintf(mFile,"\"%s.ig\"",mName.c_str());

	}
	void getInputComponents()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getInputRemoveComponent()
	{
		fprintf(mFile,"\"%s.irc\"",mName.c_str());

	}
	void getOutputGeometry()
	{
		fprintf(mFile,"\"%s.og\"",mName.c_str());

	}
	void getGroupId()
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());

	}
protected:
	GroupParts(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_GROUPPARTS_H__
