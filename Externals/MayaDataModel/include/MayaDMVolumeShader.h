/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VOLUMESHADER_H__
#define __MayaDM_VOLUMESHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class VolumeShader : public DependNode
{
public:
public:

	VolumeShader():DependNode(){}
	VolumeShader(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "volumeShader", shared, create){}
	virtual ~VolumeShader(){}

	void setOutColor(const float3& oc)
	{
		if(oc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".oc\" -type \"float3\" ");
		oc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOutColorR(float ocr)
	{
		if(ocr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".oc.ocr\" %f;\n", ocr);
	}
	void setOutColorG(float ocg)
	{
		if(ocg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".oc.ocg\" %f;\n", ocg);
	}
	void setOutColorB(float ocb)
	{
		if(ocb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".oc.ocb\" %f;\n", ocb);
	}
	void setOutTransparency(const float3& ot)
	{
		if(ot == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".ot\" -type \"float3\" ");
		ot.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOutTransparencyR(float otr)
	{
		if(otr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ot.otr\" %f;\n", otr);
	}
	void setOutTransparencyG(float otg)
	{
		if(otg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ot.otg\" %f;\n", otg);
	}
	void setOutTransparencyB(float otb)
	{
		if(otb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ot.otb\" %f;\n", otb);
	}
	void setOutMatteOpacity(const float3& omo)
	{
		if(omo == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".omo\" -type \"float3\" ");
		omo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOutMatteOpacityR(float omor)
	{
		if(omor == 0.0) return;
		fprintf(mFile,"\tsetAttr \".omo.omor\" %f;\n", omor);
	}
	void setOutMatteOpacityG(float omog)
	{
		if(omog == 0.0) return;
		fprintf(mFile,"\tsetAttr \".omo.omog\" %f;\n", omog);
	}
	void setOutMatteOpacityB(float omob)
	{
		if(omob == 0.0) return;
		fprintf(mFile,"\tsetAttr \".omo.omob\" %f;\n", omob);
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
protected:
	VolumeShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMESHADER_H__
