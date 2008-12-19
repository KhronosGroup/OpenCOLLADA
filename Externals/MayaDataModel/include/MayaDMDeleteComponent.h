/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DELETECOMPONENT_H__
#define __MayaDM_DELETECOMPONENT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DeleteComponent : public DependNode
{
public:
public:
	DeleteComponent(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "deleteComponent"){}
	virtual ~DeleteComponent(){}
	void setDeleteComponents(const componentList& dc)
	{
		fprintf(mFile,"setAttr \".dc\" -type \"componentList\" ");
		dc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUseOldPolyArchitecture(bool uopa)
	{
		if(uopa == false) return;
		fprintf(mFile,"setAttr \".uopa\" %i;\n", uopa);

	}
	void getInputGeometry()
	{
		fprintf(mFile,"\"%s.ig\"",mName.c_str());

	}
	void getDeleteComponents()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getOutputGeometry()
	{
		fprintf(mFile,"\"%s.og\"",mName.c_str());

	}
protected:
	DeleteComponent(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DELETECOMPONENT_H__
