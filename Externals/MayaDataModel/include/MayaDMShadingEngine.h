/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SHADINGENGINE_H__
#define __MayaDM_SHADINGENGINE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectSet.h"
namespace MayaDM
{
class ShadingEngine : public ObjectSet
{
public:
public:

	ShadingEngine():ObjectSet(){}
	ShadingEngine(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ObjectSet(file, name, parent, "shadingEngine", shared, create){}
	virtual ~ShadingEngine(){}

	void setMiExportMrMaterial(bool mimt)
	{
		if(mimt == false) return;
		fprintf(mFile,"\tsetAttr \".mimt\" %i;\n", mimt);
	}
	void setMiOpaque(bool miop)
	{
		if(miop == false) return;
		fprintf(mFile,"\tsetAttr \".miop\" %i;\n", miop);
	}
	void setMiCutAwayOpacity(float mico)
	{
		if(mico == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mico\" %f;\n", mico);
	}
	void setMiExportShadingEngine(bool mise)
	{
		if(mise == false) return;
		fprintf(mFile,"\tsetAttr \".mise\" %i;\n", mise);
	}
	void setMiExportVolumeSampler(bool mism)
	{
		if(mism == false) return;
		fprintf(mFile,"\tsetAttr \".mism\" %i;\n", mism);
	}
	void setMiContourEnable(bool mice)
	{
		if(mice == false) return;
		fprintf(mFile,"\tsetAttr \".mice\" %i;\n", mice);
	}
	void setMiContourColor(const float3& micc)
	{
		fprintf(mFile,"\tsetAttr \".micc\" -type \"float3\" ");
		micc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiContourColorR(float micr)
	{
		if(micr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".micc.micr\" %f;\n", micr);
	}
	void setMiContourColorG(float micg)
	{
		if(micg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".micc.micg\" %f;\n", micg);
	}
	void setMiContourColorB(float micb)
	{
		if(micb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".micc.micb\" %f;\n", micb);
	}
	void setMiContourAlpha(float mica)
	{
		if(mica == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mica\" %f;\n", mica);
	}
	void setMiContourWidth(float micw)
	{
		if(micw == 1.25) return;
		fprintf(mFile,"\tsetAttr \".micw\" %f;\n", micw);
	}
	void setMiContourRelativeWidth(bool mirw)
	{
		if(mirw == false) return;
		fprintf(mFile,"\tsetAttr \".mirw\" %i;\n", mirw);
	}
	void getSurfaceShader()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getDisplacementShader()const
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());
	}
	void getVolumeShader()const
	{
		fprintf(mFile,"\"%s.vs\"",mName.c_str());
	}
	void getImageShader()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getMiExportMrMaterial()const
	{
		fprintf(mFile,"\"%s.mimt\"",mName.c_str());
	}
	void getMiOpaque()const
	{
		fprintf(mFile,"\"%s.miop\"",mName.c_str());
	}
	void getMiCutAwayOpacity()const
	{
		fprintf(mFile,"\"%s.mico\"",mName.c_str());
	}
	void getMiExportShadingEngine()const
	{
		fprintf(mFile,"\"%s.mise\"",mName.c_str());
	}
	void getMiMaterialShader()const
	{
		fprintf(mFile,"\"%s.mims\"",mName.c_str());
	}
	void getMiShadowShader()const
	{
		fprintf(mFile,"\"%s.miss\"",mName.c_str());
	}
	void getMiExportVolumeSampler()const
	{
		fprintf(mFile,"\"%s.mism\"",mName.c_str());
	}
	void getMiVolumeShader()const
	{
		fprintf(mFile,"\"%s.mivs\"",mName.c_str());
	}
	void getMiPhotonShader()const
	{
		fprintf(mFile,"\"%s.mips\"",mName.c_str());
	}
	void getMiPhotonVolumeShader()const
	{
		fprintf(mFile,"\"%s.mipv\"",mName.c_str());
	}
	void getMiDisplacementShader()const
	{
		fprintf(mFile,"\"%s.mids\"",mName.c_str());
	}
	void getMiEnvironmentShader()const
	{
		fprintf(mFile,"\"%s.mies\"",mName.c_str());
	}
	void getMiLightMapShader()const
	{
		fprintf(mFile,"\"%s.milm\"",mName.c_str());
	}
	void getMiContourShader()const
	{
		fprintf(mFile,"\"%s.mics\"",mName.c_str());
	}
	void getMiContourEnable()const
	{
		fprintf(mFile,"\"%s.mice\"",mName.c_str());
	}
	void getMiContourColor()const
	{
		fprintf(mFile,"\"%s.micc\"",mName.c_str());
	}
	void getMiContourColorR()const
	{
		fprintf(mFile,"\"%s.micc.micr\"",mName.c_str());
	}
	void getMiContourColorG()const
	{
		fprintf(mFile,"\"%s.micc.micg\"",mName.c_str());
	}
	void getMiContourColorB()const
	{
		fprintf(mFile,"\"%s.micc.micb\"",mName.c_str());
	}
	void getMiContourAlpha()const
	{
		fprintf(mFile,"\"%s.mica\"",mName.c_str());
	}
	void getMiContourWidth()const
	{
		fprintf(mFile,"\"%s.micw\"",mName.c_str());
	}
	void getMiContourRelativeWidth()const
	{
		fprintf(mFile,"\"%s.mirw\"",mName.c_str());
	}
protected:
	ShadingEngine(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ObjectSet(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SHADINGENGINE_H__
