/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MATERIALFACADE_H__
#define __MayaDM_MATERIALFACADE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFacade.h"
namespace MayaDM
{
class MaterialFacade : public Facade
{
public:
public:
	MaterialFacade(FILE* file,const std::string& name,const std::string& parent=""):Facade(file, name, parent, "materialFacade"){}
	virtual ~MaterialFacade(){}
	void setProxyInitProc(const string& pip)
	{
		if(pip == "NULL") return;
		fprintf(mFile,"setAttr \".pip\" -type \"string\" ");
		pip.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutColor(const float3& oc)
	{
		if(oc == float3(1.0f,0.6f,0.4f)) return;
		fprintf(mFile,"setAttr \".oc\" -type \"float3\" ");
		oc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutColorR(float ocr)
	{
		if(ocr == 0.0) return;
		fprintf(mFile,"setAttr \".oc.ocr\" %f;\n", ocr);

	}
	void setOutColorG(float ocg)
	{
		if(ocg == 0.0) return;
		fprintf(mFile,"setAttr \".oc.ocg\" %f;\n", ocg);

	}
	void setOutColorB(float ocb)
	{
		if(ocb == 0.0) return;
		fprintf(mFile,"setAttr \".oc.ocb\" %f;\n", ocb);

	}
	void getHardwareProxy()
	{
		fprintf(mFile,"\"%s.hp\"",mName.c_str());

	}
	void getProxyInitProc()
	{
		fprintf(mFile,"\"%s.pip\"",mName.c_str());

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
protected:
	MaterialFacade(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Facade(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MATERIALFACADE_H__
