/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_COPYUVSET_H__
#define __MayaDM_COPYUVSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class CopyUVSet : public DependNode
{
public:
public:
	CopyUVSet():DependNode(){}
	CopyUVSet(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "copyUVSet"){}
	virtual ~CopyUVSet(){}
	void setUvSetName(const string& uvs)
	{
		if(uvs == "NULL") return;
		fprintf(mFile,"\tsetAttr \".uvs\" -type \"string\" ");
		uvs.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvSetName2(const string& uv2)
	{
		if(uv2 == "NULL") return;
		fprintf(mFile,"\tsetAttr \".uv2\" -type \"string\" ");
		uv2.write(mFile);
		fprintf(mFile,";\n");

	}
	void getInputGeometry()
	{
		fprintf(mFile,"\"%s.ig\"",mName.c_str());

	}
	void getOutputGeometry()
	{
		fprintf(mFile,"\"%s.og\"",mName.c_str());

	}
	void getUvSetName()
	{
		fprintf(mFile,"\"%s.uvs\"",mName.c_str());

	}
	void getUvSetName2()
	{
		fprintf(mFile,"\"%s.uv2\"",mName.c_str());

	}
protected:
	CopyUVSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_COPYUVSET_H__
