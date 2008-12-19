/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MATERIALINFO_H__
#define __MayaDM_MATERIALINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class MaterialInfo : public DependNode
{
public:
public:
	MaterialInfo(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "materialInfo"){}
	virtual ~MaterialInfo(){}
	void setTextureFilter(unsigned int tmip)
	{
		if(tmip == 0) return;
		fprintf(mFile,"setAttr \".tmip\" %i;\n", tmip);

	}
	void getShadingGroup()
	{
		fprintf(mFile,"\"%s.sg\"",mName.c_str());

	}
	void getMaterial()
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());

	}
	void getTextureChannel()
	{
		fprintf(mFile,"\"%s.tc\"",mName.c_str());

	}
	void getTexturePlug()
	{
		fprintf(mFile,"\"%s.tp\"",mName.c_str());

	}
	void getTextureFilter()
	{
		fprintf(mFile,"\"%s.tmip\"",mName.c_str());

	}
protected:
	MaterialInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MATERIALINFO_H__
