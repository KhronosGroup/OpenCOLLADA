/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCOLORMOD_H__
#define __MayaDM_POLYCOLORMOD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyColorMod : public PolyModifier
{
public:
	struct RedScale{
		float redScale_Position;
		float redScale_FloatValue;
		unsigned int redScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", redScale_Position);
			fprintf(file,"%f ", redScale_FloatValue);
			fprintf(file,"%i", redScale_Interp);
		}
	};
	struct GreenScale{
		float greenScale_Position;
		float greenScale_FloatValue;
		unsigned int greenScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", greenScale_Position);
			fprintf(file,"%f ", greenScale_FloatValue);
			fprintf(file,"%i", greenScale_Interp);
		}
	};
	struct BlueScale{
		float blueScale_Position;
		float blueScale_FloatValue;
		unsigned int blueScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", blueScale_Position);
			fprintf(file,"%f ", blueScale_FloatValue);
			fprintf(file,"%i", blueScale_Interp);
		}
	};
	struct AlphaScale{
		float alphaScale_Position;
		float alphaScale_FloatValue;
		unsigned int alphaScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", alphaScale_Position);
			fprintf(file,"%f ", alphaScale_FloatValue);
			fprintf(file,"%i", alphaScale_Interp);
		}
	};
	struct IntensityScale{
		float intensityScale_Position;
		float intensityScale_FloatValue;
		unsigned int intensityScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", intensityScale_Position);
			fprintf(file,"%f ", intensityScale_FloatValue);
			fprintf(file,"%i", intensityScale_Interp);
		}
	};
public:

	PolyColorMod():PolyModifier(){}
	PolyColorMod(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyColorMod", shared, create){}
	virtual ~PolyColorMod(){}

	void setBaseColorName(const string& bcn)
	{
		if(bcn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".bcn\" -type \"string\" ");
		bcn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRedScale(size_t r_i,const RedScale& r)
	{
		fprintf(mFile,"\tsetAttr \".r[%i]\" ",r_i);
		r.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRedScale(size_t r_start,size_t r_end,RedScale* r)
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
	void startRedScale(size_t r_start,size_t r_end)const
	{
		fprintf(mFile,"\tsetAttr \".r[%i:%i]\"",r_start,r_end);
		fprintf(mFile," -type \"RedScale\" ");
	}
	void appendRedScale(const RedScale& r)const
	{
		fprintf(mFile," ");
		r.write(mFile);
	}
	void endRedScale()const
	{
		fprintf(mFile,";\n");
	}
	void setRedScale_Position(size_t r_i,float rp)
	{
		if(rp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r[%i].rp\" %f;\n", r_i,rp);
	}
	void setRedScale_FloatValue(size_t r_i,float rfv)
	{
		if(rfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r[%i].rfv\" %f;\n", r_i,rfv);
	}
	void setRedScale_Interp(size_t r_i,unsigned int ri)
	{
		if(ri == 0) return;
		fprintf(mFile,"\tsetAttr \".r[%i].ri\" %i;\n", r_i,ri);
	}
	void setGreenScale(size_t g_i,const GreenScale& g)
	{
		fprintf(mFile,"\tsetAttr \".g[%i]\" ",g_i);
		g.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGreenScale(size_t g_start,size_t g_end,GreenScale* g)
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
	void startGreenScale(size_t g_start,size_t g_end)const
	{
		fprintf(mFile,"\tsetAttr \".g[%i:%i]\"",g_start,g_end);
		fprintf(mFile," -type \"GreenScale\" ");
	}
	void appendGreenScale(const GreenScale& g)const
	{
		fprintf(mFile," ");
		g.write(mFile);
	}
	void endGreenScale()const
	{
		fprintf(mFile,";\n");
	}
	void setGreenScale_Position(size_t g_i,float gp)
	{
		if(gp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g[%i].gp\" %f;\n", g_i,gp);
	}
	void setGreenScale_FloatValue(size_t g_i,float gfv)
	{
		if(gfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g[%i].gfv\" %f;\n", g_i,gfv);
	}
	void setGreenScale_Interp(size_t g_i,unsigned int gi)
	{
		if(gi == 0) return;
		fprintf(mFile,"\tsetAttr \".g[%i].gi\" %i;\n", g_i,gi);
	}
	void setBlueScale(size_t b_i,const BlueScale& b)
	{
		fprintf(mFile,"\tsetAttr \".b[%i]\" ",b_i);
		b.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlueScale(size_t b_start,size_t b_end,BlueScale* b)
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
	void startBlueScale(size_t b_start,size_t b_end)const
	{
		fprintf(mFile,"\tsetAttr \".b[%i:%i]\"",b_start,b_end);
		fprintf(mFile," -type \"BlueScale\" ");
	}
	void appendBlueScale(const BlueScale& b)const
	{
		fprintf(mFile," ");
		b.write(mFile);
	}
	void endBlueScale()const
	{
		fprintf(mFile,";\n");
	}
	void setBlueScale_Position(size_t b_i,float bp)
	{
		if(bp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".b[%i].bp\" %f;\n", b_i,bp);
	}
	void setBlueScale_FloatValue(size_t b_i,float bfv)
	{
		if(bfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".b[%i].bfv\" %f;\n", b_i,bfv);
	}
	void setBlueScale_Interp(size_t b_i,unsigned int bi)
	{
		if(bi == 0) return;
		fprintf(mFile,"\tsetAttr \".b[%i].bi\" %i;\n", b_i,bi);
	}
	void setAlphaScale(size_t a_i,const AlphaScale& a)
	{
		fprintf(mFile,"\tsetAttr \".a[%i]\" ",a_i);
		a.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAlphaScale(size_t a_start,size_t a_end,AlphaScale* a)
	{
		fprintf(mFile,"\tsetAttr \".a[%i:%i]\" ", a_start,a_end);
		size_t size = (a_end-a_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			a[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startAlphaScale(size_t a_start,size_t a_end)const
	{
		fprintf(mFile,"\tsetAttr \".a[%i:%i]\"",a_start,a_end);
		fprintf(mFile," -type \"AlphaScale\" ");
	}
	void appendAlphaScale(const AlphaScale& a)const
	{
		fprintf(mFile," ");
		a.write(mFile);
	}
	void endAlphaScale()const
	{
		fprintf(mFile,";\n");
	}
	void setAlphaScale_Position(size_t a_i,float ap)
	{
		if(ap == 0.0) return;
		fprintf(mFile,"\tsetAttr \".a[%i].ap\" %f;\n", a_i,ap);
	}
	void setAlphaScale_FloatValue(size_t a_i,float afv)
	{
		if(afv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".a[%i].afv\" %f;\n", a_i,afv);
	}
	void setAlphaScale_Interp(size_t a_i,unsigned int ai)
	{
		if(ai == 0) return;
		fprintf(mFile,"\tsetAttr \".a[%i].ai\" %i;\n", a_i,ai);
	}
	void setIntensityScale(size_t n_i,const IntensityScale& n)
	{
		fprintf(mFile,"\tsetAttr \".n[%i]\" ",n_i);
		n.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIntensityScale(size_t n_start,size_t n_end,IntensityScale* n)
	{
		fprintf(mFile,"\tsetAttr \".n[%i:%i]\" ", n_start,n_end);
		size_t size = (n_end-n_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			n[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startIntensityScale(size_t n_start,size_t n_end)const
	{
		fprintf(mFile,"\tsetAttr \".n[%i:%i]\"",n_start,n_end);
		fprintf(mFile," -type \"IntensityScale\" ");
	}
	void appendIntensityScale(const IntensityScale& n)const
	{
		fprintf(mFile," ");
		n.write(mFile);
	}
	void endIntensityScale()const
	{
		fprintf(mFile,";\n");
	}
	void setIntensityScale_Position(size_t n_i,float np)
	{
		if(np == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n[%i].np\" %f;\n", n_i,np);
	}
	void setIntensityScale_FloatValue(size_t n_i,float nfv)
	{
		if(nfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n[%i].nfv\" %f;\n", n_i,nfv);
	}
	void setIntensityScale_Interp(size_t n_i,unsigned int ni)
	{
		if(ni == 0) return;
		fprintf(mFile,"\tsetAttr \".n[%i].ni\" %i;\n", n_i,ni);
	}
	void setHuev(float h)
	{
		if(h == 0.0) return;
		fprintf(mFile,"\tsetAttr \".h\" %f;\n", h);
	}
	void setSatv(float s)
	{
		if(s == 1.0) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void setValue(float v)
	{
		if(v == 1.0) return;
		fprintf(mFile,"\tsetAttr \".v\" %f;\n", v);
	}
	void getBaseColorName()const
	{
		fprintf(mFile,"\"%s.bcn\"",mName.c_str());
	}
	void getRedScale(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i]\"",mName.c_str(),r_i);
	}
	void getRedScale()const
	{

		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getRedScale_Position(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i].rp\"",mName.c_str(),r_i);
	}
	void getRedScale_Position()const
	{

		fprintf(mFile,"\"%s.r.rp\"",mName.c_str());
	}
	void getRedScale_FloatValue(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i].rfv\"",mName.c_str(),r_i);
	}
	void getRedScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.r.rfv\"",mName.c_str());
	}
	void getRedScale_Interp(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i].ri\"",mName.c_str(),r_i);
	}
	void getRedScale_Interp()const
	{

		fprintf(mFile,"\"%s.r.ri\"",mName.c_str());
	}
	void getGreenScale(size_t g_i)const
	{
		fprintf(mFile,"\"%s.g[%i]\"",mName.c_str(),g_i);
	}
	void getGreenScale()const
	{

		fprintf(mFile,"\"%s.g\"",mName.c_str());
	}
	void getGreenScale_Position(size_t g_i)const
	{
		fprintf(mFile,"\"%s.g[%i].gp\"",mName.c_str(),g_i);
	}
	void getGreenScale_Position()const
	{

		fprintf(mFile,"\"%s.g.gp\"",mName.c_str());
	}
	void getGreenScale_FloatValue(size_t g_i)const
	{
		fprintf(mFile,"\"%s.g[%i].gfv\"",mName.c_str(),g_i);
	}
	void getGreenScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.g.gfv\"",mName.c_str());
	}
	void getGreenScale_Interp(size_t g_i)const
	{
		fprintf(mFile,"\"%s.g[%i].gi\"",mName.c_str(),g_i);
	}
	void getGreenScale_Interp()const
	{

		fprintf(mFile,"\"%s.g.gi\"",mName.c_str());
	}
	void getBlueScale(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i]\"",mName.c_str(),b_i);
	}
	void getBlueScale()const
	{

		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getBlueScale_Position(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i].bp\"",mName.c_str(),b_i);
	}
	void getBlueScale_Position()const
	{

		fprintf(mFile,"\"%s.b.bp\"",mName.c_str());
	}
	void getBlueScale_FloatValue(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i].bfv\"",mName.c_str(),b_i);
	}
	void getBlueScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.b.bfv\"",mName.c_str());
	}
	void getBlueScale_Interp(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i].bi\"",mName.c_str(),b_i);
	}
	void getBlueScale_Interp()const
	{

		fprintf(mFile,"\"%s.b.bi\"",mName.c_str());
	}
	void getAlphaScale(size_t a_i)const
	{
		fprintf(mFile,"\"%s.a[%i]\"",mName.c_str(),a_i);
	}
	void getAlphaScale()const
	{

		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getAlphaScale_Position(size_t a_i)const
	{
		fprintf(mFile,"\"%s.a[%i].ap\"",mName.c_str(),a_i);
	}
	void getAlphaScale_Position()const
	{

		fprintf(mFile,"\"%s.a.ap\"",mName.c_str());
	}
	void getAlphaScale_FloatValue(size_t a_i)const
	{
		fprintf(mFile,"\"%s.a[%i].afv\"",mName.c_str(),a_i);
	}
	void getAlphaScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.a.afv\"",mName.c_str());
	}
	void getAlphaScale_Interp(size_t a_i)const
	{
		fprintf(mFile,"\"%s.a[%i].ai\"",mName.c_str(),a_i);
	}
	void getAlphaScale_Interp()const
	{

		fprintf(mFile,"\"%s.a.ai\"",mName.c_str());
	}
	void getIntensityScale(size_t n_i)const
	{
		fprintf(mFile,"\"%s.n[%i]\"",mName.c_str(),n_i);
	}
	void getIntensityScale()const
	{

		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getIntensityScale_Position(size_t n_i)const
	{
		fprintf(mFile,"\"%s.n[%i].np\"",mName.c_str(),n_i);
	}
	void getIntensityScale_Position()const
	{

		fprintf(mFile,"\"%s.n.np\"",mName.c_str());
	}
	void getIntensityScale_FloatValue(size_t n_i)const
	{
		fprintf(mFile,"\"%s.n[%i].nfv\"",mName.c_str(),n_i);
	}
	void getIntensityScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.n.nfv\"",mName.c_str());
	}
	void getIntensityScale_Interp(size_t n_i)const
	{
		fprintf(mFile,"\"%s.n[%i].ni\"",mName.c_str(),n_i);
	}
	void getIntensityScale_Interp()const
	{

		fprintf(mFile,"\"%s.n.ni\"",mName.c_str());
	}
	void getHuev()const
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getSatv()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getValue()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
protected:
	PolyColorMod(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOLORMOD_H__
