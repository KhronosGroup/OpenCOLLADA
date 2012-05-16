/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DELETECOLORSET_H__
#define __MayaDM_DELETECOLORSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DeleteColorSet : public DependNode
{
public:
public:

	DeleteColorSet():DependNode(){}
	DeleteColorSet(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "deleteColorSet", shared, create){}
	virtual ~DeleteColorSet(){}

	void setColorSetName(const string& cols)
	{
		if(cols == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cols\" -type \"string\" ");
		cols.write(mFile);
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
	void getColorSetName()const
	{
		fprintf(mFile,"\"%s.cols\"",mName.c_str());
	}
protected:
	DeleteColorSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DELETECOLORSET_H__
