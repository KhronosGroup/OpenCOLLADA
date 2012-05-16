/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MULTILISTERLIGHT_H__
#define __MayaDM_MULTILISTERLIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class MultilisterLight : public DependNode
{
public:
public:

	MultilisterLight():DependNode(){}
	MultilisterLight(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "multilisterLight", shared, create){}
	virtual ~MultilisterLight(){}

	void setPointCamera(const float3& p)
	{
		if(p == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".p\" -type \"float3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointCameraX(float px)
	{
		if(px == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.px\" %f;\n", px);
	}
	void setPointCameraY(float py)
	{
		if(py == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.py\" %f;\n", py);
	}
	void setPointCameraZ(float pz)
	{
		if(pz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.pz\" %f;\n", pz);
	}
	void getPointCamera()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPointCameraX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPointCameraY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPointCameraZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getLightData()const
	{
		fprintf(mFile,"\"%s.ltd\"",mName.c_str());
	}
	void getLightDirection()const
	{
		fprintf(mFile,"\"%s.ltd.ld\"",mName.c_str());
	}
	void getLightDirectionX()const
	{
		fprintf(mFile,"\"%s.ltd.ld.ldx\"",mName.c_str());
	}
	void getLightDirectionY()const
	{
		fprintf(mFile,"\"%s.ltd.ld.ldy\"",mName.c_str());
	}
	void getLightDirectionZ()const
	{
		fprintf(mFile,"\"%s.ltd.ld.ldz\"",mName.c_str());
	}
	void getLightIntensity()const
	{
		fprintf(mFile,"\"%s.ltd.li\"",mName.c_str());
	}
	void getLightIntensityR()const
	{
		fprintf(mFile,"\"%s.ltd.li.lir\"",mName.c_str());
	}
	void getLightIntensityG()const
	{
		fprintf(mFile,"\"%s.ltd.li.lig\"",mName.c_str());
	}
	void getLightIntensityB()const
	{
		fprintf(mFile,"\"%s.ltd.li.lib\"",mName.c_str());
	}
	void getLightAmbient()const
	{
		fprintf(mFile,"\"%s.ltd.la\"",mName.c_str());
	}
	void getLightDiffuse()const
	{
		fprintf(mFile,"\"%s.ltd.ldf\"",mName.c_str());
	}
	void getLightSpecular()const
	{
		fprintf(mFile,"\"%s.ltd.ls\"",mName.c_str());
	}
	void getLightShadowFraction()const
	{
		fprintf(mFile,"\"%s.ltd.lsf\"",mName.c_str());
	}
	void getPreShadowIntensity()const
	{
		fprintf(mFile,"\"%s.ltd.psi\"",mName.c_str());
	}
	void getLightBlindData()const
	{
		fprintf(mFile,"\"%s.ltd.lbd\"",mName.c_str());
	}
protected:
	MultilisterLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MULTILISTERLIGHT_H__
