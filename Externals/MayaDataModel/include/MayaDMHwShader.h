/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HWSHADER_H__
#define __MayaDM_HWSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class HwShader : public DependNode
{
public:
public:

	HwShader():DependNode(){}
	HwShader(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "hwShader", shared, create){}
	virtual ~HwShader(){}

	void setEnableHwShading(int ehs)
	{
		if(ehs == 1) return;
		fprintf(mFile,"\tsetAttr \".ehs\" %i;\n", ehs);
	}
	void setVaryingParameters(const stringArray& vpar)
	{
		if(vpar.size == 0) return;
		fprintf(mFile,"\tsetAttr \".vpar\" -type \"stringArray\" ");
		vpar.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUniformParameters(const stringArray& upar)
	{
		if(upar.size == 0) return;
		fprintf(mFile,"\tsetAttr \".upar\" -type \"stringArray\" ");
		upar.write(mFile);
		fprintf(mFile,";\n");
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
	void getOutGlowColor()const
	{
		fprintf(mFile,"\"%s.ogc\"",mName.c_str());
	}
	void getOutGlowColorR()const
	{
		fprintf(mFile,"\"%s.ogc.ogr\"",mName.c_str());
	}
	void getOutGlowColorG()const
	{
		fprintf(mFile,"\"%s.ogc.ogg\"",mName.c_str());
	}
	void getOutGlowColorB()const
	{
		fprintf(mFile,"\"%s.ogc.ogb\"",mName.c_str());
	}
	void getOutMatteOpacity()const
	{
		fprintf(mFile,"\"%s.omo\"",mName.c_str());
	}
	void getOutMatteOpacityR()const
	{
		fprintf(mFile,"\"%s.omo.omor\"",mName.c_str());
	}
	void getOutMatteOpacityG()const
	{
		fprintf(mFile,"\"%s.omo.omog\"",mName.c_str());
	}
	void getOutMatteOpacityB()const
	{
		fprintf(mFile,"\"%s.omo.omob\"",mName.c_str());
	}
	void getEnableHwShading()const
	{
		fprintf(mFile,"\"%s.ehs\"",mName.c_str());
	}
	void getVaryingParameters()const
	{
		fprintf(mFile,"\"%s.vpar\"",mName.c_str());
	}
	void getUniformParameters()const
	{
		fprintf(mFile,"\"%s.upar\"",mName.c_str());
	}
protected:
	HwShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HWSHADER_H__
