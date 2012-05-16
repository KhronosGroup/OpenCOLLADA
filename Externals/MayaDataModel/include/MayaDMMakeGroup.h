/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKEGROUP_H__
#define __MayaDM_MAKEGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class MakeGroup : public DependNode
{
public:
public:

	MakeGroup():DependNode(){}
	MakeGroup(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "makeGroup", shared, create){}
	virtual ~MakeGroup(){}

	void setGroupType(unsigned int gt)
	{
		if(gt == 0) return;
		fprintf(mFile,"\tsetAttr \".gt\" %i;\n", gt);
	}
	void setGroupName(int gn)
	{
		if(gn == -1) return;
		fprintf(mFile,"\tsetAttr \".gn\" %i;\n", gn);
	}
	void setElemList(const intArray& el)
	{
		if(el.size == 0) return;
		fprintf(mFile,"\tsetAttr \".el\" -type \"intArray\" ");
		el.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputComponents(const componentList& ic)
	{
		fprintf(mFile,"\tsetAttr \".ic\" -type \"componentList\" ");
		ic.write(mFile);
		fprintf(mFile,";\n");
	}
	void getInputGeometry()const
	{
		fprintf(mFile,"\"%s.ig\"",mName.c_str());
	}
	void getOutputGeometry()const
	{
		fprintf(mFile,"\"%s.og\"",mName.c_str());
	}
	void getGroupType()const
	{
		fprintf(mFile,"\"%s.gt\"",mName.c_str());
	}
	void getGroupName()const
	{
		fprintf(mFile,"\"%s.gn\"",mName.c_str());
	}
	void getElemList()const
	{
		fprintf(mFile,"\"%s.el\"",mName.c_str());
	}
	void getInputComponents()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
protected:
	MakeGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKEGROUP_H__
