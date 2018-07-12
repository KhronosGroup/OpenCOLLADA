/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REMAPCOLOR_H__
#define __MayaDM_REMAPCOLOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RemapColor : public DependNode
{
public:
	struct Red{
		float red_Position;
		float red_FloatValue;
		unsigned int red_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", red_Position);
			fprintf(file,"%f ", red_FloatValue);
			fprintf(file,"%i", red_Interp);
		}
	};
	struct Green{
		float green_Position;
		float green_FloatValue;
		unsigned int green_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", green_Position);
			fprintf(file,"%f ", green_FloatValue);
			fprintf(file,"%i", green_Interp);
		}
	};
	struct Blue{
		float blue_Position;
		float blue_FloatValue;
		unsigned int blue_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", blue_Position);
			fprintf(file,"%f ", blue_FloatValue);
			fprintf(file,"%i", blue_Interp);
		}
	};
public:

	RemapColor():DependNode(){}
	RemapColor(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "remapColor", shared, create){}
	virtual ~RemapColor(){}

	void setColor(const float3& cl)
	{
		fprintf(mFile,"\tsetAttr \".cl\" -type \"float3\" ");
		cl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(float cr)
	{
		if(cr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".cl.cr\" %f;\n", cr);
	}
	void setColorG(float cg)
	{
		if(cg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".cl.cg\" %f;\n", cg);
	}
	void setColorB(float cb)
	{
		if(cb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".cl.cb\" %f;\n", cb);
	}
	void setInputMin(float imn)
	{
		if(imn == 0) return;
		fprintf(mFile,"\tsetAttr \".imn\" %f;\n", imn);
	}
	void setInputMax(float imx)
	{
		if(imx == 1) return;
		fprintf(mFile,"\tsetAttr \".imx\" %f;\n", imx);
	}
	void setOutputMin(float omn)
	{
		if(omn == 0) return;
		fprintf(mFile,"\tsetAttr \".omn\" %f;\n", omn);
	}
	void setOutputMax(float omx)
	{
		if(omx == 1) return;
		fprintf(mFile,"\tsetAttr \".omx\" %f;\n", omx);
	}
	void setRed(size_t r_i,const Red& r)
	{
		fprintf(mFile,"\tsetAttr \".r[%i]\" ",r_i);
		r.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRed(size_t r_start,size_t r_end,Red* r)
	{
		fprintf(mFile,"\tsetAttr \".r[%i:%i]\" ", r_start,r_end);
		size_t size = (r_end-r_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			r[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startRed(size_t r_start,size_t r_end)const
	{
		fprintf(mFile,"\tsetAttr \".r[%i:%i]\"",r_start,r_end);
		fprintf(mFile," -type \"Red\" ");
	}
	void appendRed(const Red& r)const
	{
		fprintf(mFile," ");
		r.write(mFile);
	}
	void endRed()const
	{
		fprintf(mFile,";\n");
	}
	void setRed_Position(size_t r_i,float rp)
	{
		if(rp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r[%i].rp\" %f;\n", r_i,rp);
	}
	void setRed_FloatValue(size_t r_i,float rfv)
	{
		if(rfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r[%i].rfv\" %f;\n", r_i,rfv);
	}
	void setRed_Interp(size_t r_i,unsigned int ri)
	{
		if(ri == 0) return;
		fprintf(mFile,"\tsetAttr \".r[%i].ri\" %i;\n", r_i,ri);
	}
	void setGreen(size_t g_i,const Green& g)
	{
		fprintf(mFile,"\tsetAttr \".g[%i]\" ",g_i);
		g.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGreen(size_t g_start,size_t g_end,Green* g)
	{
		fprintf(mFile,"\tsetAttr \".g[%i:%i]\" ", g_start,g_end);
		size_t size = (g_end-g_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			g[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startGreen(size_t g_start,size_t g_end)const
	{
		fprintf(mFile,"\tsetAttr \".g[%i:%i]\"",g_start,g_end);
		fprintf(mFile," -type \"Green\" ");
	}
	void appendGreen(const Green& g)const
	{
		fprintf(mFile," ");
		g.write(mFile);
	}
	void endGreen()const
	{
		fprintf(mFile,";\n");
	}
	void setGreen_Position(size_t g_i,float gp)
	{
		if(gp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g[%i].gp\" %f;\n", g_i,gp);
	}
	void setGreen_FloatValue(size_t g_i,float gfv)
	{
		if(gfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g[%i].gfv\" %f;\n", g_i,gfv);
	}
	void setGreen_Interp(size_t g_i,unsigned int gi)
	{
		if(gi == 0) return;
		fprintf(mFile,"\tsetAttr \".g[%i].gi\" %i;\n", g_i,gi);
	}
	void setBlue(size_t b_i,const Blue& b)
	{
		fprintf(mFile,"\tsetAttr \".b[%i]\" ",b_i);
		b.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlue(size_t b_start,size_t b_end,Blue* b)
	{
		fprintf(mFile,"\tsetAttr \".b[%i:%i]\" ", b_start,b_end);
		size_t size = (b_end-b_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			b[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBlue(size_t b_start,size_t b_end)const
	{
		fprintf(mFile,"\tsetAttr \".b[%i:%i]\"",b_start,b_end);
		fprintf(mFile," -type \"Blue\" ");
	}
	void appendBlue(const Blue& b)const
	{
		fprintf(mFile," ");
		b.write(mFile);
	}
	void endBlue()const
	{
		fprintf(mFile,";\n");
	}
	void setBlue_Position(size_t b_i,float bp)
	{
		if(bp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".b[%i].bp\" %f;\n", b_i,bp);
	}
	void setBlue_FloatValue(size_t b_i,float bfv)
	{
		if(bfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".b[%i].bfv\" %f;\n", b_i,bfv);
	}
	void setBlue_Interp(size_t b_i,unsigned int bi)
	{
		if(bi == 0) return;
		fprintf(mFile,"\tsetAttr \".b[%i].bi\" %i;\n", b_i,bi);
	}
	void getColor()const
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getColorR()const
	{
		fprintf(mFile,"\"%s.cl.cr\"",mName.c_str());
	}
	void getColorG()const
	{
		fprintf(mFile,"\"%s.cl.cg\"",mName.c_str());
	}
	void getColorB()const
	{
		fprintf(mFile,"\"%s.cl.cb\"",mName.c_str());
	}
	void getInputMin()const
	{
		fprintf(mFile,"\"%s.imn\"",mName.c_str());
	}
	void getInputMax()const
	{
		fprintf(mFile,"\"%s.imx\"",mName.c_str());
	}
	void getOutputMin()const
	{
		fprintf(mFile,"\"%s.omn\"",mName.c_str());
	}
	void getOutputMax()const
	{
		fprintf(mFile,"\"%s.omx\"",mName.c_str());
	}
	void getRed(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i]\"",mName.c_str(),r_i);
	}
	void getRed()const
	{

		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getRed_Position(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i].rp\"",mName.c_str(),r_i);
	}
	void getRed_Position()const
	{

		fprintf(mFile,"\"%s.r.rp\"",mName.c_str());
	}
	void getRed_FloatValue(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i].rfv\"",mName.c_str(),r_i);
	}
	void getRed_FloatValue()const
	{

		fprintf(mFile,"\"%s.r.rfv\"",mName.c_str());
	}
	void getRed_Interp(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i].ri\"",mName.c_str(),r_i);
	}
	void getRed_Interp()const
	{

		fprintf(mFile,"\"%s.r.ri\"",mName.c_str());
	}
	void getGreen(size_t g_i)const
	{
		fprintf(mFile,"\"%s.g[%i]\"",mName.c_str(),g_i);
	}
	void getGreen()const
	{

		fprintf(mFile,"\"%s.g\"",mName.c_str());
	}
	void getGreen_Position(size_t g_i)const
	{
		fprintf(mFile,"\"%s.g[%i].gp\"",mName.c_str(),g_i);
	}
	void getGreen_Position()const
	{

		fprintf(mFile,"\"%s.g.gp\"",mName.c_str());
	}
	void getGreen_FloatValue(size_t g_i)const
	{
		fprintf(mFile,"\"%s.g[%i].gfv\"",mName.c_str(),g_i);
	}
	void getGreen_FloatValue()const
	{

		fprintf(mFile,"\"%s.g.gfv\"",mName.c_str());
	}
	void getGreen_Interp(size_t g_i)const
	{
		fprintf(mFile,"\"%s.g[%i].gi\"",mName.c_str(),g_i);
	}
	void getGreen_Interp()const
	{

		fprintf(mFile,"\"%s.g.gi\"",mName.c_str());
	}
	void getBlue(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i]\"",mName.c_str(),b_i);
	}
	void getBlue()const
	{

		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getBlue_Position(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i].bp\"",mName.c_str(),b_i);
	}
	void getBlue_Position()const
	{

		fprintf(mFile,"\"%s.b.bp\"",mName.c_str());
	}
	void getBlue_FloatValue(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i].bfv\"",mName.c_str(),b_i);
	}
	void getBlue_FloatValue()const
	{

		fprintf(mFile,"\"%s.b.bfv\"",mName.c_str());
	}
	void getBlue_Interp(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i].bi\"",mName.c_str(),b_i);
	}
	void getBlue_Interp()const
	{

		fprintf(mFile,"\"%s.b.bi\"",mName.c_str());
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
protected:
	RemapColor(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_REMAPCOLOR_H__
