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
	MultilisterLight(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "multilisterLight"){}
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
	void getPointCamera()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getPointCameraX()
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());

	}
	void getPointCameraY()
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());

	}
	void getPointCameraZ()
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());

	}
	void getLightData()
	{
		fprintf(mFile,"\"%s.ltd\"",mName.c_str());

	}
	void getLightDirection()
	{
		fprintf(mFile,"\"%s.ltd.ld\"",mName.c_str());

	}
	void getLightDirectionX()
	{
		fprintf(mFile,"\"%s.ltd.ld.ldx\"",mName.c_str());

	}
	void getLightDirectionY()
	{
		fprintf(mFile,"\"%s.ltd.ld.ldy\"",mName.c_str());

	}
	void getLightDirectionZ()
	{
		fprintf(mFile,"\"%s.ltd.ld.ldz\"",mName.c_str());

	}
	void getLightIntensity()
	{
		fprintf(mFile,"\"%s.ltd.li\"",mName.c_str());

	}
	void getLightIntensityR()
	{
		fprintf(mFile,"\"%s.ltd.li.lir\"",mName.c_str());

	}
	void getLightIntensityG()
	{
		fprintf(mFile,"\"%s.ltd.li.lig\"",mName.c_str());

	}
	void getLightIntensityB()
	{
		fprintf(mFile,"\"%s.ltd.li.lib\"",mName.c_str());

	}
	void getLightAmbient()
	{
		fprintf(mFile,"\"%s.ltd.la\"",mName.c_str());

	}
	void getLightDiffuse()
	{
		fprintf(mFile,"\"%s.ltd.ldf\"",mName.c_str());

	}
	void getLightSpecular()
	{
		fprintf(mFile,"\"%s.ltd.ls\"",mName.c_str());

	}
	void getLightShadowFraction()
	{
		fprintf(mFile,"\"%s.ltd.lsf\"",mName.c_str());

	}
	void getPreShadowIntensity()
	{
		fprintf(mFile,"\"%s.ltd.psi\"",mName.c_str());

	}
	void getLightBlindData()
	{
		fprintf(mFile,"\"%s.ltd.lbd\"",mName.c_str());

	}
protected:
	MultilisterLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MULTILISTERLIGHT_H__
