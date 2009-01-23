/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	RenderLayer(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "renderLayer"){}
	virtual ~RenderLayer(){}
	void setGlobal(bool g)
	{
		if(g == false) return;
		fprintf(mFile,"setAttr \".g\" %i;\n", g);

	}
	void setRenderInfo(const RenderInfo& ri)
	{
		fprintf(mFile,"setAttr \".ri\" ");
		ri.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIdentification(short rlid)
	{
		if(rlid == 0) return;
		fprintf(mFile,"setAttr \".ri.rlid\" %i;\n", rlid);

	}
	void setRenderable(bool rndr)
	{
		if(rndr == true) return;
		fprintf(mFile,"setAttr \".ri.rndr\" %i;\n", rndr);

	}
	void setDrawColor(unsigned char c)
	{
		if(c == 0) return;
		fprintf(mFile,"setAttr \".ri.c\" %i;\n", c);

	}
	void setLayerParent(short rlp)
	{
		if(rlp == 0) return;
		fprintf(mFile,"setAttr \".rlp\" %i;\n", rlp);

	}
	void setLayerChildren(size_t rlc_i,short rlc)
	{
		if(rlc == 0) return;
		fprintf(mFile,"setAttr \".rlc[%i]\" %i;\n", rlc_i,rlc);

	}
	void setLayerChildren(size_t rlc_start,size_t rlc_end,short* rlc)
	{
		fprintf(mFile,"setAttr \".rlc[%i:%i]\" ", rlc_start,rlc_end);
		size_t size = (rlc_end-rlc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",rlc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startLayerChildren(size_t rlc_start,size_t rlc_end)
	{
		fprintf(mFile,"setAttr \".rlc[%i:%i]\"",rlc_start,rlc_end);

	}
	void appendLayerChildren(short rlc)
	{
		fprintf(mFile," %i",rlc);

	}
	void endLayerChildren()
	{
		fprintf(mFile,";\n");

	}
	void setRenderPassInfo(const RenderPassInfo& rp)
	{
		fprintf(mFile,"setAttr \".rp\" ");
		rp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBeauty(bool b)
	{
		if(b == true) return;
		fprintf(mFile,"setAttr \".rp.b\" %i;\n", b);

	}
	void setColor(bool cp)
	{
		if(cp == false) return;
		fprintf(mFile,"setAttr \".rp.cp\" %i;\n", cp);

	}
	void setAmbient(bool am)
	{
		if(am == false) return;
		fprintf(mFile,"setAttr \".rp.am\" %i;\n", am);

	}
	void setDiffuse(bool di)
	{
		if(di == false) return;
		fprintf(mFile,"setAttr \".rp.di\" %i;\n", di);

	}
	void setSpecular(bool sp)
	{
		if(sp == false) return;
		fprintf(mFile,"setAttr \".rp.sp\" %i;\n", sp);

	}
	void setShadow(bool s)
	{
		if(s == false) return;
		fprintf(mFile,"setAttr \".rp.s\" %i;\n", s);

	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"setAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGlobalIllum(bool gp)
	{
		if(gp == false) return;
		fprintf(mFile,"setAttr \".mrc.gp\" %i;\n", gp);

	}
	void setAdjustments(size_t adjs_i,const Adjustments& adjs)
	{
		fprintf(mFile,"setAttr \".adjs[%i]\" ",adjs_i);
		adjs.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutAdjustments(size_t oajs_i,const OutAdjustments& oajs)
	{
		fprintf(mFile,"setAttr \".oajs[%i]\" ",oajs_i);
		oajs.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAttributeOverrideScript(const string& aos)
	{
		if(aos == "NULL") return;
		fprintf(mFile,"setAttr \".aos\" -type \"string\" ");
		aos.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDisplayOrder(short do_)
	{
		if(do_ == 0) return;
		fprintf(mFile,"setAttr \".do\" %i;\n", do_);

	}
	void setPsdBlendMode(short bm)
	{
		if(bm == 0) return;
		fprintf(mFile,"setAttr \".bm\" %i;\n", bm);

	}
	void setPsdAlphaChannel(short ac)
	{
		if(ac == 0) return;
		fprintf(mFile,"setAttr \".ac\" %i;\n", ac);

	}
	void getGlobal()
	{
		fprintf(mFile,"\"%s.g\"",mName.c_str());

	}
	void getRenderInfo()
	{
		fprintf(mFile,"\"%s.ri\"",mName.c_str());

	}
	void getIdentification()
	{
		fprintf(mFile,"\"%s.ri.rlid\"",mName.c_str());

	}
	void getRenderable()
	{
		fprintf(mFile,"\"%s.ri.rndr\"",mName.c_str());

	}
	void getDrawColor()
	{
		fprintf(mFile,"\"%s.ri.c\"",mName.c_str());

	}
	void getLayerParent()
	{
		fprintf(mFile,"\"%s.rlp\"",mName.c_str());

	}
	void getRenderPassInfo()
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());

	}
	void getBeauty()
	{
		fprintf(mFile,"\"%s.rp.b\"",mName.c_str());

	}
	void getColor()
	{
		fprintf(mFile,"\"%s.rp.cp\"",mName.c_str());

	}
	void getAmbient()
	{
		fprintf(mFile,"\"%s.rp.am\"",mName.c_str());

	}
	void getDiffuse()
	{
		fprintf(mFile,"\"%s.rp.di\"",mName.c_str());

	}
	void getSpecular()
	{
		fprintf(mFile,"\"%s.rp.sp\"",mName.c_str());

	}
	void getShadow()
	{
		fprintf(mFile,"\"%s.rp.s\"",mName.c_str());

	}
	void getMentalRayControls()
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());

	}
	void getGlobalIllum()
	{
		fprintf(mFile,"\"%s.mrc.gp\"",mName.c_str());

	}
	void getAdjustments(size_t adjs_i)
	{
		fprintf(mFile,"\"%s.adjs[%i]\"",mName.c_str(),adjs_i);

	}
	void getValue(size_t adjs_i)
	{
		fprintf(mFile,"\"%s.adjs[%i].val\"",mName.c_str(),adjs_i);

	}
	void getOutAdjustments(size_t oajs_i)
	{
		fprintf(mFile,"\"%s.oajs[%i]\"",mName.c_str(),oajs_i);

	}
	void getOutValue(size_t oajs_i)
	{
		fprintf(mFile,"\"%s.oajs[%i].ovl\"",mName.c_str(),oajs_i);

	}
	void getShadingGroupOverride()
	{
		fprintf(mFile,"\"%s.sgo\"",mName.c_str());

	}
	void getAttributeOverrideScript()
	{
		fprintf(mFile,"\"%s.aos\"",mName.c_str());

	}
	void getImageRendered()
	{
		fprintf(mFile,"\"%s.ird\"",mName.c_str());

	}
	void getRecycleImage()
	{
		fprintf(mFile,"\"%s.rci\"",mName.c_str());

	}
	void getImageName()
	{
		fprintf(mFile,"\"%s.img\"",mName.c_str());

	}
	void getDisplayOrder()
	{
		fprintf(mFile,"\"%s.do\"",mName.c_str());

	}
	void getPsdBlendMode()
	{
		fprintf(mFile,"\"%s.bm\"",mName.c_str());

	}
	void getPsdAlphaChannel()
	{
		fprintf(mFile,"\"%s.ac\"",mName.c_str());

	}
protected:
	RenderLayer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERLAYER_H__
