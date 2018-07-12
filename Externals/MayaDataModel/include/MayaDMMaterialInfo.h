/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	MaterialInfo():DependNode(){}
	MaterialInfo(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "materialInfo", shared, create){}
	virtual ~MaterialInfo(){}

	void setTextureFilter(unsigned int tmip)
	{
		if(tmip == 0) return;
		fprintf(mFile,"\tsetAttr \".tmip\" %i;\n", tmip);
	}
	void getShadingGroup()const
	{
		fprintf(mFile,"\"%s.sg\"",mName.c_str());
	}
	void getMaterial()const
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getTexture(size_t t_i)const
	{
		fprintf(mFile,"\"%s.t[%i]\"",mName.c_str(),t_i);
	}
	void getTexture()const
	{

		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getTextureChannel()const
	{
		fprintf(mFile,"\"%s.tc\"",mName.c_str());
	}
	void getTexturePlug()const
	{
		fprintf(mFile,"\"%s.tp\"",mName.c_str());
	}
	void getTextureFilter()const
	{
		fprintf(mFile,"\"%s.tmip\"",mName.c_str());
	}
protected:
	MaterialInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MATERIALINFO_H__
