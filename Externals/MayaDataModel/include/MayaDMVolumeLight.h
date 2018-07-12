/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VOLUMELIGHT_H__
#define __MayaDM_VOLUMELIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPointLight.h"
namespace MayaDM
{
class VolumeLight : public PointLight
{
public:
	struct ColorRange{
		float colorRange_Position;
		float3 colorRange_Color;
		unsigned int colorRange_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", colorRange_Position);
			colorRange_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", colorRange_Interp);
		}
	};
	struct Penumbra{
		float penumbra_Position;
		float penumbra_FloatValue;
		unsigned int penumbra_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", penumbra_Position);
			fprintf(file,"%f ", penumbra_FloatValue);
			fprintf(file,"%i", penumbra_Interp);
		}
	};
public:

	VolumeLight():PointLight(){}
	VolumeLight(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PointLight(file, name, parent, "volumeLight", shared, create){}
	virtual ~VolumeLight(){}

	void setLightShape(unsigned int lis)
	{
		if(lis == 1) return;
		fprintf(mFile,"\tsetAttr \".lis\" %i;\n", lis);
	}
	void setVolumeLightDir(unsigned int vld)
	{
		if(vld == 0) return;
		fprintf(mFile,"\tsetAttr \".vld\" %i;\n", vld);
	}
	void setArc(float ac)
	{
		if(ac == 360.0) return;
		fprintf(mFile,"\tsetAttr \".ac\" %f;\n", ac);
	}
	void setConeEndRadius(float cer)
	{
		if(cer == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cer\" %f;\n", cer);
	}
	void setColorRange(size_t crg_i,const ColorRange& crg)
	{
		fprintf(mFile,"\tsetAttr \".crg[%i]\" ",crg_i);
		crg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorRange(size_t crg_start,size_t crg_end,ColorRange* crg)
	{
		fprintf(mFile,"\tsetAttr \".crg[%i:%i]\" ", crg_start,crg_end);
		size_t size = (crg_end-crg_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			crg[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startColorRange(size_t crg_start,size_t crg_end)const
	{
		fprintf(mFile,"\tsetAttr \".crg[%i:%i]\"",crg_start,crg_end);
		fprintf(mFile," -type \"ColorRange\" ");
	}
	void appendColorRange(const ColorRange& crg)const
	{
		fprintf(mFile," ");
		crg.write(mFile);
	}
	void endColorRange()const
	{
		fprintf(mFile,";\n");
	}
	void setColorRange_Position(size_t crg_i,float crgp)
	{
		if(crgp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crg[%i].crgp\" %f;\n", crg_i,crgp);
	}
	void setColorRange_Color(size_t crg_i,const float3& crgc)
	{
		fprintf(mFile,"\tsetAttr \".crg[%i].crgc\" -type \"float3\" ",crg_i);
		crgc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorRange_ColorR(size_t crg_i,float crgcr)
	{
		if(crgcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crg[%i].crgc.crgcr\" %f;\n", crg_i,crgcr);
	}
	void setColorRange_ColorG(size_t crg_i,float crgcg)
	{
		if(crgcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crg[%i].crgc.crgcg\" %f;\n", crg_i,crgcg);
	}
	void setColorRange_ColorB(size_t crg_i,float crgcb)
	{
		if(crgcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crg[%i].crgc.crgcb\" %f;\n", crg_i,crgcb);
	}
	void setColorRange_Interp(size_t crg_i,unsigned int crgi)
	{
		if(crgi == 0) return;
		fprintf(mFile,"\tsetAttr \".crg[%i].crgi\" %i;\n", crg_i,crgi);
	}
	void setPenumbra(size_t pen_i,const Penumbra& pen)
	{
		fprintf(mFile,"\tsetAttr \".pen[%i]\" ",pen_i);
		pen.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPenumbra(size_t pen_start,size_t pen_end,Penumbra* pen)
	{
		fprintf(mFile,"\tsetAttr \".pen[%i:%i]\" ", pen_start,pen_end);
		size_t size = (pen_end-pen_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			pen[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startPenumbra(size_t pen_start,size_t pen_end)const
	{
		fprintf(mFile,"\tsetAttr \".pen[%i:%i]\"",pen_start,pen_end);
		fprintf(mFile," -type \"Penumbra\" ");
	}
	void appendPenumbra(const Penumbra& pen)const
	{
		fprintf(mFile," ");
		pen.write(mFile);
	}
	void endPenumbra()const
	{
		fprintf(mFile,";\n");
	}
	void setPenumbra_Position(size_t pen_i,float penp)
	{
		if(penp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pen[%i].penp\" %f;\n", pen_i,penp);
	}
	void setPenumbra_FloatValue(size_t pen_i,float penfv)
	{
		if(penfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pen[%i].penfv\" %f;\n", pen_i,penfv);
	}
	void setPenumbra_Interp(size_t pen_i,unsigned int peni)
	{
		if(peni == 0) return;
		fprintf(mFile,"\tsetAttr \".pen[%i].peni\" %i;\n", pen_i,peni);
	}
	void setEmitAmbient(bool ema)
	{
		if(ema == false) return;
		fprintf(mFile,"\tsetAttr \".ema\" %i;\n", ema);
	}
	void getLightShape()const
	{
		fprintf(mFile,"\"%s.lis\"",mName.c_str());
	}
	void getVolumeLightDir()const
	{
		fprintf(mFile,"\"%s.vld\"",mName.c_str());
	}
	void getArc()const
	{
		fprintf(mFile,"\"%s.ac\"",mName.c_str());
	}
	void getConeEndRadius()const
	{
		fprintf(mFile,"\"%s.cer\"",mName.c_str());
	}
	void getColorRange(size_t crg_i)const
	{
		fprintf(mFile,"\"%s.crg[%i]\"",mName.c_str(),crg_i);
	}
	void getColorRange()const
	{

		fprintf(mFile,"\"%s.crg\"",mName.c_str());
	}
	void getColorRange_Position(size_t crg_i)const
	{
		fprintf(mFile,"\"%s.crg[%i].crgp\"",mName.c_str(),crg_i);
	}
	void getColorRange_Position()const
	{

		fprintf(mFile,"\"%s.crg.crgp\"",mName.c_str());
	}
	void getColorRange_Color(size_t crg_i)const
	{
		fprintf(mFile,"\"%s.crg[%i].crgc\"",mName.c_str(),crg_i);
	}
	void getColorRange_Color()const
	{

		fprintf(mFile,"\"%s.crg.crgc\"",mName.c_str());
	}
	void getColorRange_ColorR(size_t crg_i)const
	{
		fprintf(mFile,"\"%s.crg[%i].crgc.crgcr\"",mName.c_str(),crg_i);
	}
	void getColorRange_ColorR()const
	{

		fprintf(mFile,"\"%s.crg.crgc.crgcr\"",mName.c_str());
	}
	void getColorRange_ColorG(size_t crg_i)const
	{
		fprintf(mFile,"\"%s.crg[%i].crgc.crgcg\"",mName.c_str(),crg_i);
	}
	void getColorRange_ColorG()const
	{

		fprintf(mFile,"\"%s.crg.crgc.crgcg\"",mName.c_str());
	}
	void getColorRange_ColorB(size_t crg_i)const
	{
		fprintf(mFile,"\"%s.crg[%i].crgc.crgcb\"",mName.c_str(),crg_i);
	}
	void getColorRange_ColorB()const
	{

		fprintf(mFile,"\"%s.crg.crgc.crgcb\"",mName.c_str());
	}
	void getColorRange_Interp(size_t crg_i)const
	{
		fprintf(mFile,"\"%s.crg[%i].crgi\"",mName.c_str(),crg_i);
	}
	void getColorRange_Interp()const
	{

		fprintf(mFile,"\"%s.crg.crgi\"",mName.c_str());
	}
	void getPenumbra(size_t pen_i)const
	{
		fprintf(mFile,"\"%s.pen[%i]\"",mName.c_str(),pen_i);
	}
	void getPenumbra()const
	{

		fprintf(mFile,"\"%s.pen\"",mName.c_str());
	}
	void getPenumbra_Position(size_t pen_i)const
	{
		fprintf(mFile,"\"%s.pen[%i].penp\"",mName.c_str(),pen_i);
	}
	void getPenumbra_Position()const
	{

		fprintf(mFile,"\"%s.pen.penp\"",mName.c_str());
	}
	void getPenumbra_FloatValue(size_t pen_i)const
	{
		fprintf(mFile,"\"%s.pen[%i].penfv\"",mName.c_str(),pen_i);
	}
	void getPenumbra_FloatValue()const
	{

		fprintf(mFile,"\"%s.pen.penfv\"",mName.c_str());
	}
	void getPenumbra_Interp(size_t pen_i)const
	{
		fprintf(mFile,"\"%s.pen[%i].peni\"",mName.c_str(),pen_i);
	}
	void getPenumbra_Interp()const
	{

		fprintf(mFile,"\"%s.pen.peni\"",mName.c_str());
	}
	void getEmitAmbient()const
	{
		fprintf(mFile,"\"%s.ema\"",mName.c_str());
	}
protected:
	VolumeLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PointLight(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMELIGHT_H__
