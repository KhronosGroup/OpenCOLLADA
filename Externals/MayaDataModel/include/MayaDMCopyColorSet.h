/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_COPYCOLORSET_H__
#define __MayaDM_COPYCOLORSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class CopyColorSet : public DependNode
{
public:
public:
	CopyColorSet():DependNode(){}
	CopyColorSet(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "copyColorSet"){}
	virtual ~CopyColorSet(){}
	void setSrcColorSetName(const string& src)
	{
		if(src == "NULL") return;
		fprintf(mFile,"\tsetAttr \".src\" -type \"string\" ");
		src.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDstColorName(const string& dst)
	{
		if(dst == "NULL") return;
		fprintf(mFile,"\tsetAttr \".dst\" -type \"string\" ");
		dst.write(mFile);
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
	void getSrcColorSetName()
	{
		fprintf(mFile,"\"%s.src\"",mName.c_str());

	}
	void getDstColorName()
	{
		fprintf(mFile,"\"%s.dst\"",mName.c_str());

	}
protected:
	CopyColorSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_COPYCOLORSET_H__
