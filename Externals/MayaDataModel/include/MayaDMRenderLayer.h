/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERLAYER_H__
#define __MayaDM_RENDERLAYER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RenderLayer : public DependNode
{
public:
	struct RenderInfo{
		short identification;
		bool renderable;
		unsigned char drawColor;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", identification);
			fprintf(file,"%i ", renderable);
			fprintf(file,"%i", drawColor);
		}
	};
	struct RenderPassInfo{
		bool beauty;
		bool color;
		bool ambient;
		bool diffuse;
		bool specular;
		bool shadow;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", beauty);
			fprintf(file,"%i ", color);
			fprintf(file,"%i ", ambient);
			fprintf(file,"%i ", diffuse);
			fprintf(file,"%i ", specular);
			fprintf(file,"%i", shadow);
		}
	};
	struct MentalRayControls{
		bool globalIllum;
		void write(FILE* file) const
		{
			fprintf(file,"%i", globalIllum);
		}
	};
	struct Adjustments{
		void write(FILE* file) const
		{
		}
	};
	struct OutAdjustments{
		void write(FILE* file) const
		{
		}
	};
public:

	RenderLayer():DependNode(){}
	RenderLayer(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "renderLayer", shared, create){}
	virtual ~RenderLayer(){}

	void setGlobal(bool g)
	{
		if(g == false) return;
		fprintf(mFile,"\tsetAttr \".g\" %i;\n", g);
	}
	void setRenderInfo(const RenderInfo& ri)
	{
		fprintf(mFile,"\tsetAttr \".ri\" ");
		ri.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIdentification(short rlid)
	{
		if(rlid == 0) return;
		fprintf(mFile,"\tsetAttr \".ri.rlid\" %i;\n", rlid);
	}
	void setRenderable(bool rndr)
	{
		if(rndr == true) return;
		fprintf(mFile,"\tsetAttr \".ri.rndr\" %i;\n", rndr);
	}
	void setDrawColor(unsigned char c)
	{
		if(c == 0) return;
		fprintf(mFile,"\tsetAttr \".ri.c\" %i;\n", c);
	}
	void setLayerParent(short rlp)
	{
		if(rlp == 0) return;
		fprintf(mFile,"\tsetAttr \".rlp\" %i;\n", rlp);
	}
	void setLayerChildren(size_t rlc_i,short rlc)
	{
		if(rlc == 0) return;
		fprintf(mFile,"\tsetAttr \".rlc[%i]\" %i;\n", rlc_i,rlc);
	}
	void setLayerChildren(size_t rlc_start,size_t rlc_end,short* rlc)
	{
		fprintf(mFile,"\tsetAttr \".rlc[%i:%i]\" ", rlc_start,rlc_end);
		size_t size = (rlc_end-rlc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",rlc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startLayerChildren(size_t rlc_start,size_t rlc_end)const
	{
		fprintf(mFile,"\tsetAttr \".rlc[%i:%i]\"",rlc_start,rlc_end);
	}
	void appendLayerChildren(short rlc)const
	{
		fprintf(mFile," %i",rlc);
	}
	void endLayerChildren()const
	{
		fprintf(mFile,";\n");
	}
	void setRenderPassInfo(const RenderPassInfo& rp)
	{
		fprintf(mFile,"\tsetAttr \".rp\" ");
		rp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBeauty(bool b)
	{
		if(b == true) return;
		fprintf(mFile,"\tsetAttr \".rp.b\" %i;\n", b);
	}
	void setColor(bool cp)
	{
		if(cp == false) return;
		fprintf(mFile,"\tsetAttr \".rp.cp\" %i;\n", cp);
	}
	void setAmbient(bool am)
	{
		if(am == false) return;
		fprintf(mFile,"\tsetAttr \".rp.am\" %i;\n", am);
	}
	void setDiffuse(bool di)
	{
		if(di == false) return;
		fprintf(mFile,"\tsetAttr \".rp.di\" %i;\n", di);
	}
	void setSpecular(bool sp)
	{
		if(sp == false) return;
		fprintf(mFile,"\tsetAttr \".rp.sp\" %i;\n", sp);
	}
	void setShadow(bool s)
	{
		if(s == false) return;
		fprintf(mFile,"\tsetAttr \".rp.s\" %i;\n", s);
	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"\tsetAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGlobalIllum(bool gp)
	{
		if(gp == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.gp\" %i;\n", gp);
	}
	void setAdjustments(size_t adjs_i,const Adjustments& adjs)
	{
		fprintf(mFile,"\tsetAttr \".adjs[%i]\" ",adjs_i);
		adjs.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAdjustments(size_t adjs_start,size_t adjs_end,Adjustments* adjs)
	{
		fprintf(mFile,"\tsetAttr \".adjs[%i:%i]\" ", adjs_start,adjs_end);
		size_t size = (adjs_end-adjs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			adjs[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startAdjustments(size_t adjs_start,size_t adjs_end)const
	{
		fprintf(mFile,"\tsetAttr \".adjs[%i:%i]\"",adjs_start,adjs_end);
		fprintf(mFile," -type \"Adjustments\" ");
	}
	void appendAdjustments(const Adjustments& adjs)const
	{
		fprintf(mFile," ");
		adjs.write(mFile);
	}
	void endAdjustments()const
	{
		fprintf(mFile,";\n");
	}
	void setOutAdjustments(size_t oajs_i,const OutAdjustments& oajs)
	{
		fprintf(mFile,"\tsetAttr \".oajs[%i]\" ",oajs_i);
		oajs.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOutAdjustments(size_t oajs_start,size_t oajs_end,OutAdjustments* oajs)
	{
		fprintf(mFile,"\tsetAttr \".oajs[%i:%i]\" ", oajs_start,oajs_end);
		size_t size = (oajs_end-oajs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			oajs[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startOutAdjustments(size_t oajs_start,size_t oajs_end)const
	{
		fprintf(mFile,"\tsetAttr \".oajs[%i:%i]\"",oajs_start,oajs_end);
		fprintf(mFile," -type \"OutAdjustments\" ");
	}
	void appendOutAdjustments(const OutAdjustments& oajs)const
	{
		fprintf(mFile," ");
		oajs.write(mFile);
	}
	void endOutAdjustments()const
	{
		fprintf(mFile,";\n");
	}
	void setAttributeOverrideScript(const string& aos)
	{
		if(aos == "NULL") return;
		fprintf(mFile,"\tsetAttr \".aos\" -type \"string\" ");
		aos.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDisplayOrder(short do_)
	{
		if(do_ == 0) return;
		fprintf(mFile,"\tsetAttr \".do\" %i;\n", do_);
	}
	void setPsdBlendMode(short bm)
	{
		if(bm == 0) return;
		fprintf(mFile,"\tsetAttr \".bm\" %i;\n", bm);
	}
	void setPsdAlphaChannel(short ac)
	{
		if(ac == 0) return;
		fprintf(mFile,"\tsetAttr \".ac\" %i;\n", ac);
	}
	void getGlobal()const
	{
		fprintf(mFile,"\"%s.g\"",mName.c_str());
	}
	void getRenderInfo()const
	{
		fprintf(mFile,"\"%s.ri\"",mName.c_str());
	}
	void getIdentification()const
	{
		fprintf(mFile,"\"%s.ri.rlid\"",mName.c_str());
	}
	void getRenderable()const
	{
		fprintf(mFile,"\"%s.ri.rndr\"",mName.c_str());
	}
	void getDrawColor()const
	{
		fprintf(mFile,"\"%s.ri.c\"",mName.c_str());
	}
	void getLayerParent()const
	{
		fprintf(mFile,"\"%s.rlp\"",mName.c_str());
	}
	void getLayerChildren(size_t rlc_i)const
	{
		fprintf(mFile,"\"%s.rlc[%i]\"",mName.c_str(),rlc_i);
	}
	void getLayerChildren()const
	{

		fprintf(mFile,"\"%s.rlc\"",mName.c_str());
	}
	void getRenderPassInfo()const
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());
	}
	void getBeauty()const
	{
		fprintf(mFile,"\"%s.rp.b\"",mName.c_str());
	}
	void getColor()const
	{
		fprintf(mFile,"\"%s.rp.cp\"",mName.c_str());
	}
	void getAmbient()const
	{
		fprintf(mFile,"\"%s.rp.am\"",mName.c_str());
	}
	void getDiffuse()const
	{
		fprintf(mFile,"\"%s.rp.di\"",mName.c_str());
	}
	void getSpecular()const
	{
		fprintf(mFile,"\"%s.rp.sp\"",mName.c_str());
	}
	void getShadow()const
	{
		fprintf(mFile,"\"%s.rp.s\"",mName.c_str());
	}
	void getMentalRayControls()const
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());
	}
	void getGlobalIllum()const
	{
		fprintf(mFile,"\"%s.mrc.gp\"",mName.c_str());
	}
	void getAdjustments(size_t adjs_i)const
	{
		fprintf(mFile,"\"%s.adjs[%i]\"",mName.c_str(),adjs_i);
	}
	void getAdjustments()const
	{

		fprintf(mFile,"\"%s.adjs\"",mName.c_str());
	}
	void getPlug(size_t adjs_i)const
	{
		fprintf(mFile,"\"%s.adjs[%i].plg\"",mName.c_str(),adjs_i);
	}
	void getPlug()const
	{

		fprintf(mFile,"\"%s.adjs.plg\"",mName.c_str());
	}
	void getValue(size_t adjs_i)const
	{
		fprintf(mFile,"\"%s.adjs[%i].val\"",mName.c_str(),adjs_i);
	}
	void getValue()const
	{

		fprintf(mFile,"\"%s.adjs.val\"",mName.c_str());
	}
	void getOutAdjustments(size_t oajs_i)const
	{
		fprintf(mFile,"\"%s.oajs[%i]\"",mName.c_str(),oajs_i);
	}
	void getOutAdjustments()const
	{

		fprintf(mFile,"\"%s.oajs\"",mName.c_str());
	}
	void getOutPlug(size_t oajs_i)const
	{
		fprintf(mFile,"\"%s.oajs[%i].opg\"",mName.c_str(),oajs_i);
	}
	void getOutPlug()const
	{

		fprintf(mFile,"\"%s.oajs.opg\"",mName.c_str());
	}
	void getOutValue(size_t oajs_i)const
	{
		fprintf(mFile,"\"%s.oajs[%i].ovl\"",mName.c_str(),oajs_i);
	}
	void getOutValue()const
	{

		fprintf(mFile,"\"%s.oajs.ovl\"",mName.c_str());
	}
	void getShadingGroupOverride()const
	{
		fprintf(mFile,"\"%s.sgo\"",mName.c_str());
	}
	void getAttributeOverrideScript()const
	{
		fprintf(mFile,"\"%s.aos\"",mName.c_str());
	}
	void getImageRendered()const
	{
		fprintf(mFile,"\"%s.ird\"",mName.c_str());
	}
	void getRecycleImage()const
	{
		fprintf(mFile,"\"%s.rci\"",mName.c_str());
	}
	void getImageName()const
	{
		fprintf(mFile,"\"%s.img\"",mName.c_str());
	}
	void getDisplayOrder()const
	{
		fprintf(mFile,"\"%s.do\"",mName.c_str());
	}
	void getPsdBlendMode()const
	{
		fprintf(mFile,"\"%s.bm\"",mName.c_str());
	}
	void getPsdAlphaChannel()const
	{
		fprintf(mFile,"\"%s.ac\"",mName.c_str());
	}
protected:
	RenderLayer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERLAYER_H__
