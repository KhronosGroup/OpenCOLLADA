/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFAULTLIGHTLIST_H__
#define __MayaDM_DEFAULTLIGHTLIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DefaultLightList : public DependNode
{
public:
public:
	DefaultLightList(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "defaultLightList"){}
	virtual ~DefaultLightList(){}
	void getLightData()
	{
		fprintf(mFile,"\"%s.ltd\"",mName.c_str());

	}
	void getLightDirectionOut()
	{
		fprintf(mFile,"\"%s.ltd.ldo\"",mName.c_str());

	}
	void getLightDirectionOutX()
	{
		fprintf(mFile,"\"%s.ltd.ldo.lqx\"",mName.c_str());

	}
	void getLightDirectionOutY()
	{
		fprintf(mFile,"\"%s.ltd.ldo.lqy\"",mName.c_str());

	}
	void getLightDirectionOutZ()
	{
		fprintf(mFile,"\"%s.ltd.ldo.lqz\"",mName.c_str());

	}
	void getLightIntensityOut()
	{
		fprintf(mFile,"\"%s.ltd.lw\"",mName.c_str());

	}
	void getLightIntensityOutR()
	{
		fprintf(mFile,"\"%s.ltd.lw.lwr\"",mName.c_str());

	}
	void getLightIntensityOutG()
	{
		fprintf(mFile,"\"%s.ltd.lw.lwg\"",mName.c_str());

	}
	void getLightIntensityOutB()
	{
		fprintf(mFile,"\"%s.ltd.lw.lwb\"",mName.c_str());

	}
	void getLightAmbientOut()
	{
		fprintf(mFile,"\"%s.ltd.lya\"",mName.c_str());

	}
	void getLightDiffuseOut()
	{
		fprintf(mFile,"\"%s.ltd.lyf\"",mName.c_str());

	}
	void getLightSpecularOut()
	{
		fprintf(mFile,"\"%s.ltd.lys\"",mName.c_str());

	}
	void getLightShadowFractionOut()
	{
		fprintf(mFile,"\"%s.ltd.sfo\"",mName.c_str());

	}
	void getPreShadowIntensityOut()
	{
		fprintf(mFile,"\"%s.ltd.psio\"",mName.c_str());

	}
	void getLightBlindDataOut()
	{
		fprintf(mFile,"\"%s.ltd.lbdo\"",mName.c_str());

	}
protected:
	DefaultLightList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFAULTLIGHTLIST_H__
