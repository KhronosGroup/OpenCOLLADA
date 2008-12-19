/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SIMPLEVOLUMESHADER_H__
#define __MayaDM_SIMPLEVOLUMESHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SimpleVolumeShader : public DependNode
{
public:
public:
	SimpleVolumeShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "simpleVolumeShader"){}
	virtual ~SimpleVolumeShader(){}
	void setParameter1(float p1)
	{
		if(p1 == 0.45) return;
		fprintf(mFile,"setAttr \".p1\" %f;\n", p1);

	}
	void setColor(const float3& c)
	{
		fprintf(mFile,"setAttr \".c\" -type \"float3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"setAttr \".c.cr\" %f;\n", cr);

	}
	void setColorG(float cg)
	{
		if(cg == 0.58824) return;
		fprintf(mFile,"setAttr \".c.cg\" %f;\n", cg);

	}
	void setColorB(float cb)
	{
		if(cb == 0.644) return;
		fprintf(mFile,"setAttr \".c.cb\" %f;\n", cb);

	}
	void setPointWorld(const float3& p)
	{
		if(p == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".p\" -type \"float3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPointWorldX(float px)
	{
		if(px == 0.0) return;
		fprintf(mFile,"setAttr \".p.px\" %f;\n", px);

	}
	void setPointWorldY(float py)
	{
		if(py == 0.0) return;
		fprintf(mFile,"setAttr \".p.py\" %f;\n", py);

	}
	void setPointWorldZ(float pz)
	{
		if(pz == 0.0) return;
		fprintf(mFile,"setAttr \".p.pz\" %f;\n", pz);

	}
	void setFarPointWorld(const float3& fp)
	{
		if(fp == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".fp\" -type \"float3\" ");
		fp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFarPointWorldX(float fpx)
	{
		if(fpx == 0.0) return;
		fprintf(mFile,"setAttr \".fp.fpx\" %f;\n", fpx);

	}
	void setFarPointWorldY(float fpy)
	{
		if(fpy == 0.0) return;
		fprintf(mFile,"setAttr \".fp.fpy\" %f;\n", fpy);

	}
	void setFarPointWorldZ(float fpz)
	{
		if(fpz == 0.0) return;
		fprintf(mFile,"setAttr \".fp.fpz\" %f;\n", fpz);

	}
	void getParameter1()
	{
		fprintf(mFile,"\"%s.p1\"",mName.c_str());

	}
	void getColor()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getColorR()
	{
		fprintf(mFile,"\"%s.c.cr\"",mName.c_str());

	}
	void getColorG()
	{
		fprintf(mFile,"\"%s.c.cg\"",mName.c_str());

	}
	void getColorB()
	{
		fprintf(mFile,"\"%s.c.cb\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());

	}
	void getOutTransparency()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getOutTransparencyR()
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());

	}
	void getOutTransparencyG()
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());

	}
	void getOutTransparencyB()
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());

	}
protected:
	SimpleVolumeShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SIMPLEVOLUMESHADER_H__
