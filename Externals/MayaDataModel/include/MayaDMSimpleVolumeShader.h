/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	SimpleVolumeShader():DependNode(){}
	SimpleVolumeShader(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "simpleVolumeShader", shared, create){}
	virtual ~SimpleVolumeShader(){}

	void setParameter1(float p1)
	{
		if(p1 == 0.45) return;
		fprintf(mFile,"\tsetAttr \".p1\" %f;\n", p1);
	}
	void setColor(const float3& c)
	{
		fprintf(mFile,"\tsetAttr \".c\" -type \"float3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cr\" %f;\n", cr);
	}
	void setColorG(float cg)
	{
		if(cg == 0.58824) return;
		fprintf(mFile,"\tsetAttr \".c.cg\" %f;\n", cg);
	}
	void setColorB(float cb)
	{
		if(cb == 0.644) return;
		fprintf(mFile,"\tsetAttr \".c.cb\" %f;\n", cb);
	}
	void setPointWorld(const float3& p)
	{
		if(p == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".p\" -type \"float3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointWorldX(float px)
	{
		if(px == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.px\" %f;\n", px);
	}
	void setPointWorldY(float py)
	{
		if(py == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.py\" %f;\n", py);
	}
	void setPointWorldZ(float pz)
	{
		if(pz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.pz\" %f;\n", pz);
	}
	void setFarPointWorld(const float3& fp)
	{
		if(fp == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".fp\" -type \"float3\" ");
		fp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFarPointWorldX(float fpx)
	{
		if(fpx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fp.fpx\" %f;\n", fpx);
	}
	void setFarPointWorldY(float fpy)
	{
		if(fpy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fp.fpy\" %f;\n", fpy);
	}
	void setFarPointWorldZ(float fpz)
	{
		if(fpz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fp.fpz\" %f;\n", fpz);
	}
	void getParameter1()const
	{
		fprintf(mFile,"\"%s.p1\"",mName.c_str());
	}
	void getColor()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getColorR()const
	{
		fprintf(mFile,"\"%s.c.cr\"",mName.c_str());
	}
	void getColorG()const
	{
		fprintf(mFile,"\"%s.c.cg\"",mName.c_str());
	}
	void getColorB()const
	{
		fprintf(mFile,"\"%s.c.cb\"",mName.c_str());
	}
	void getPointWorld()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPointWorldX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPointWorldY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPointWorldZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getFarPointWorld()const
	{
		fprintf(mFile,"\"%s.fp\"",mName.c_str());
	}
	void getFarPointWorldX()const
	{
		fprintf(mFile,"\"%s.fp.fpx\"",mName.c_str());
	}
	void getFarPointWorldY()const
	{
		fprintf(mFile,"\"%s.fp.fpy\"",mName.c_str());
	}
	void getFarPointWorldZ()const
	{
		fprintf(mFile,"\"%s.fp.fpz\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());
	}
	void getOutTransparency()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getOutTransparencyR()const
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());
	}
	void getOutTransparencyG()const
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());
	}
	void getOutTransparencyB()const
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());
	}
protected:
	SimpleVolumeShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SIMPLEVOLUMESHADER_H__
