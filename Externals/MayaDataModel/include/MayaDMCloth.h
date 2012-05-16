/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOTH_H__
#define __MayaDM_CLOTH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Cloth : public Texture2d
{
public:
public:

	Cloth():Texture2d(){}
	Cloth(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture2d(file, name, parent, "cloth", shared, create){}
	virtual ~Cloth(){}

	void setGapColor(const float3& gc)
	{
		if(gc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".gc\" -type \"float3\" ");
		gc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGapColorR(float gcr)
	{
		if(gcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gcr\" %f;\n", gcr);
	}
	void setGapColorG(float gcg)
	{
		if(gcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gcg\" %f;\n", gcg);
	}
	void setGapColorB(float gcb)
	{
		if(gcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gcb\" %f;\n", gcb);
	}
	void setUColor(const float3& uc)
	{
		if(uc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".uc\" -type \"float3\" ");
		uc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUColorR(float ucr)
	{
		if(ucr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uc.ucr\" %f;\n", ucr);
	}
	void setUColorG(float ucg)
	{
		if(ucg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uc.ucg\" %f;\n", ucg);
	}
	void setUColorB(float ucb)
	{
		if(ucb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uc.ucb\" %f;\n", ucb);
	}
	void setVColor(const float3& vc)
	{
		if(vc == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".vc\" -type \"float3\" ");
		vc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVColorR(float vcr)
	{
		if(vcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc.vcr\" %f;\n", vcr);
	}
	void setVColorG(float vcg)
	{
		if(vcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc.vcg\" %f;\n", vcg);
	}
	void setVColorB(float vcb)
	{
		if(vcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc.vcb\" %f;\n", vcb);
	}
	void setUWidth(float uwi)
	{
		if(uwi == 0.75) return;
		fprintf(mFile,"\tsetAttr \".uwi\" %f;\n", uwi);
	}
	void setVWidth(float vwi)
	{
		if(vwi == 0.75) return;
		fprintf(mFile,"\tsetAttr \".vwi\" %f;\n", vwi);
	}
	void setUWave(float uwa)
	{
		if(uwa == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uwa\" %f;\n", uwa);
	}
	void setVWave(float vwa)
	{
		if(vwa == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vwa\" %f;\n", vwa);
	}
	void setRandomness(float r)
	{
		if(r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r\" %f;\n", r);
	}
	void setWidthSpread(float ws)
	{
		if(ws == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ws\" %f;\n", ws);
	}
	void setBrightSpread(float bs)
	{
		if(bs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bs\" %f;\n", bs);
	}
	void getGapColor()const
	{
		fprintf(mFile,"\"%s.gc\"",mName.c_str());
	}
	void getGapColorR()const
	{
		fprintf(mFile,"\"%s.gc.gcr\"",mName.c_str());
	}
	void getGapColorG()const
	{
		fprintf(mFile,"\"%s.gc.gcg\"",mName.c_str());
	}
	void getGapColorB()const
	{
		fprintf(mFile,"\"%s.gc.gcb\"",mName.c_str());
	}
	void getUColor()const
	{
		fprintf(mFile,"\"%s.uc\"",mName.c_str());
	}
	void getUColorR()const
	{
		fprintf(mFile,"\"%s.uc.ucr\"",mName.c_str());
	}
	void getUColorG()const
	{
		fprintf(mFile,"\"%s.uc.ucg\"",mName.c_str());
	}
	void getUColorB()const
	{
		fprintf(mFile,"\"%s.uc.ucb\"",mName.c_str());
	}
	void getVColor()const
	{
		fprintf(mFile,"\"%s.vc\"",mName.c_str());
	}
	void getVColorR()const
	{
		fprintf(mFile,"\"%s.vc.vcr\"",mName.c_str());
	}
	void getVColorG()const
	{
		fprintf(mFile,"\"%s.vc.vcg\"",mName.c_str());
	}
	void getVColorB()const
	{
		fprintf(mFile,"\"%s.vc.vcb\"",mName.c_str());
	}
	void getUWidth()const
	{
		fprintf(mFile,"\"%s.uwi\"",mName.c_str());
	}
	void getVWidth()const
	{
		fprintf(mFile,"\"%s.vwi\"",mName.c_str());
	}
	void getUWave()const
	{
		fprintf(mFile,"\"%s.uwa\"",mName.c_str());
	}
	void getVWave()const
	{
		fprintf(mFile,"\"%s.vwa\"",mName.c_str());
	}
	void getRandomness()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getWidthSpread()const
	{
		fprintf(mFile,"\"%s.ws\"",mName.c_str());
	}
	void getBrightSpread()const
	{
		fprintf(mFile,"\"%s.bs\"",mName.c_str());
	}
protected:
	Cloth(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture2d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLOTH_H__
