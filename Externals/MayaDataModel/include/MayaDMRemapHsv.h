/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REMAPHSV_H__
#define __MayaDM_REMAPHSV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RemapHsv : public DependNode
{
public:
	struct Hue{
		float hue_Position;
		float hue_FloatValue;
		unsigned int hue_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", hue_Position);
			fprintf(file,"%f ", hue_FloatValue);
			fprintf(file,"%i", hue_Interp);
		}
	};
	struct Saturation{
		float saturation_Position;
		float saturation_FloatValue;
		unsigned int saturation_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", saturation_Position);
			fprintf(file,"%f ", saturation_FloatValue);
			fprintf(file,"%i", saturation_Interp);
		}
	};
	struct Value{
		float value_Position;
		float value_FloatValue;
		unsigned int value_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", value_Position);
			fprintf(file,"%f ", value_FloatValue);
			fprintf(file,"%i", value_Interp);
		}
	};
public:

	RemapHsv():DependNode(){}
	RemapHsv(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "remapHsv", shared, create){}
	virtual ~RemapHsv(){}

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
	void setHue(size_t h_i,const Hue& h)
	{
		fprintf(mFile,"\tsetAttr \".h[%i]\" ",h_i);
		h.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHue(size_t h_start,size_t h_end,Hue* h)
	{
		fprintf(mFile,"\tsetAttr \".h[%i:%i]\" ", h_start,h_end);
		size_t size = (h_end-h_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			h[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startHue(size_t h_start,size_t h_end)const
	{
		fprintf(mFile,"\tsetAttr \".h[%i:%i]\"",h_start,h_end);
		fprintf(mFile," -type \"Hue\" ");
	}
	void appendHue(const Hue& h)const
	{
		fprintf(mFile," ");
		h.write(mFile);
	}
	void endHue()const
	{
		fprintf(mFile,";\n");
	}
	void setHue_Position(size_t h_i,float hp)
	{
		if(hp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".h[%i].hp\" %f;\n", h_i,hp);
	}
	void setHue_FloatValue(size_t h_i,float hfv)
	{
		if(hfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".h[%i].hfv\" %f;\n", h_i,hfv);
	}
	void setHue_Interp(size_t h_i,unsigned int hi)
	{
		if(hi == 0) return;
		fprintf(mFile,"\tsetAttr \".h[%i].hi\" %i;\n", h_i,hi);
	}
	void setSaturation(size_t s_i,const Saturation& s)
	{
		fprintf(mFile,"\tsetAttr \".s[%i]\" ",s_i);
		s.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSaturation(size_t s_start,size_t s_end,Saturation* s)
	{
		fprintf(mFile,"\tsetAttr \".s[%i:%i]\" ", s_start,s_end);
		size_t size = (s_end-s_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			s[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startSaturation(size_t s_start,size_t s_end)const
	{
		fprintf(mFile,"\tsetAttr \".s[%i:%i]\"",s_start,s_end);
		fprintf(mFile," -type \"Saturation\" ");
	}
	void appendSaturation(const Saturation& s)const
	{
		fprintf(mFile," ");
		s.write(mFile);
	}
	void endSaturation()const
	{
		fprintf(mFile,";\n");
	}
	void setSaturation_Position(size_t s_i,float sp)
	{
		if(sp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s[%i].sp\" %f;\n", s_i,sp);
	}
	void setSaturation_FloatValue(size_t s_i,float sfv)
	{
		if(sfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s[%i].sfv\" %f;\n", s_i,sfv);
	}
	void setSaturation_Interp(size_t s_i,unsigned int si)
	{
		if(si == 0) return;
		fprintf(mFile,"\tsetAttr \".s[%i].si\" %i;\n", s_i,si);
	}
	void setValue(size_t v_i,const Value& v)
	{
		fprintf(mFile,"\tsetAttr \".v[%i]\" ",v_i);
		v.write(mFile);
		fprintf(mFile,";\n");
	}
	void setValue(size_t v_start,size_t v_end,Value* v)
	{
		fprintf(mFile,"\tsetAttr \".v[%i:%i]\" ", v_start,v_end);
		size_t size = (v_end-v_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			v[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startValue(size_t v_start,size_t v_end)const
	{
		fprintf(mFile,"\tsetAttr \".v[%i:%i]\"",v_start,v_end);
		fprintf(mFile," -type \"Value\" ");
	}
	void appendValue(const Value& v)const
	{
		fprintf(mFile," ");
		v.write(mFile);
	}
	void endValue()const
	{
		fprintf(mFile,";\n");
	}
	void setValue_Position(size_t v_i,float vp)
	{
		if(vp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v[%i].vp\" %f;\n", v_i,vp);
	}
	void setValue_FloatValue(size_t v_i,float vfv)
	{
		if(vfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v[%i].vfv\" %f;\n", v_i,vfv);
	}
	void setValue_Interp(size_t v_i,unsigned int vi)
	{
		if(vi == 0) return;
		fprintf(mFile,"\tsetAttr \".v[%i].vi\" %i;\n", v_i,vi);
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
	void getHue(size_t h_i)const
	{
		fprintf(mFile,"\"%s.h[%i]\"",mName.c_str(),h_i);
	}
	void getHue()const
	{

		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getHue_Position(size_t h_i)const
	{
		fprintf(mFile,"\"%s.h[%i].hp\"",mName.c_str(),h_i);
	}
	void getHue_Position()const
	{

		fprintf(mFile,"\"%s.h.hp\"",mName.c_str());
	}
	void getHue_FloatValue(size_t h_i)const
	{
		fprintf(mFile,"\"%s.h[%i].hfv\"",mName.c_str(),h_i);
	}
	void getHue_FloatValue()const
	{

		fprintf(mFile,"\"%s.h.hfv\"",mName.c_str());
	}
	void getHue_Interp(size_t h_i)const
	{
		fprintf(mFile,"\"%s.h[%i].hi\"",mName.c_str(),h_i);
	}
	void getHue_Interp()const
	{

		fprintf(mFile,"\"%s.h.hi\"",mName.c_str());
	}
	void getSaturation(size_t s_i)const
	{
		fprintf(mFile,"\"%s.s[%i]\"",mName.c_str(),s_i);
	}
	void getSaturation()const
	{

		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getSaturation_Position(size_t s_i)const
	{
		fprintf(mFile,"\"%s.s[%i].sp\"",mName.c_str(),s_i);
	}
	void getSaturation_Position()const
	{

		fprintf(mFile,"\"%s.s.sp\"",mName.c_str());
	}
	void getSaturation_FloatValue(size_t s_i)const
	{
		fprintf(mFile,"\"%s.s[%i].sfv\"",mName.c_str(),s_i);
	}
	void getSaturation_FloatValue()const
	{

		fprintf(mFile,"\"%s.s.sfv\"",mName.c_str());
	}
	void getSaturation_Interp(size_t s_i)const
	{
		fprintf(mFile,"\"%s.s[%i].si\"",mName.c_str(),s_i);
	}
	void getSaturation_Interp()const
	{

		fprintf(mFile,"\"%s.s.si\"",mName.c_str());
	}
	void getValue(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i]\"",mName.c_str(),v_i);
	}
	void getValue()const
	{

		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getValue_Position(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i].vp\"",mName.c_str(),v_i);
	}
	void getValue_Position()const
	{

		fprintf(mFile,"\"%s.v.vp\"",mName.c_str());
	}
	void getValue_FloatValue(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i].vfv\"",mName.c_str(),v_i);
	}
	void getValue_FloatValue()const
	{

		fprintf(mFile,"\"%s.v.vfv\"",mName.c_str());
	}
	void getValue_Interp(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i].vi\"",mName.c_str(),v_i);
	}
	void getValue_Interp()const
	{

		fprintf(mFile,"\"%s.v.vi\"",mName.c_str());
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
	RemapHsv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_REMAPHSV_H__
