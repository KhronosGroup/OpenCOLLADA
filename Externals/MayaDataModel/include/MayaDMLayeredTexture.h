/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LAYEREDTEXTURE_H__
#define __MayaDM_LAYEREDTEXTURE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class LayeredTexture : public DependNode
{
public:
	struct Inputs{
		float3 color;
		float alpha;
		unsigned int blendMode;
		bool isVisible;
		void write(FILE* file) const
		{
			color.write(file);
			fprintf(file, " ");
			fprintf(file,"%f ", alpha);
			fprintf(file,"%i ", blendMode);
			fprintf(file,"%i", isVisible);
		}
	};
public:

	LayeredTexture():DependNode(){}
	LayeredTexture(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "layeredTexture", shared, create){}
	virtual ~LayeredTexture(){}

	void setInputs(size_t cs_i,const Inputs& cs)
	{
		fprintf(mFile,"\tsetAttr \".cs[%i]\" ",cs_i);
		cs.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputs(size_t cs_start,size_t cs_end,Inputs* cs)
	{
		fprintf(mFile,"\tsetAttr \".cs[%i:%i]\" ", cs_start,cs_end);
		size_t size = (cs_end-cs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cs[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInputs(size_t cs_start,size_t cs_end)const
	{
		fprintf(mFile,"\tsetAttr \".cs[%i:%i]\"",cs_start,cs_end);
		fprintf(mFile," -type \"Inputs\" ");
	}
	void appendInputs(const Inputs& cs)const
	{
		fprintf(mFile," ");
		cs.write(mFile);
	}
	void endInputs()const
	{
		fprintf(mFile,";\n");
	}
	void setColor(size_t cs_i,const float3& c)
	{
		fprintf(mFile,"\tsetAttr \".cs[%i].c\" -type \"float3\" ",cs_i);
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(size_t cs_i,float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].c.cr\" %f;\n", cs_i,cr);
	}
	void setColorG(size_t cs_i,float cg)
	{
		if(cg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].c.cg\" %f;\n", cs_i,cg);
	}
	void setColorB(size_t cs_i,float cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].c.cb\" %f;\n", cs_i,cb);
	}
	void setAlpha(size_t cs_i,float a)
	{
		if(a == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].a\" %f;\n", cs_i,a);
	}
	void setBlendMode(size_t cs_i,unsigned int bm)
	{
		if(bm == 1) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].bm\" %i;\n", cs_i,bm);
	}
	void setIsVisible(size_t cs_i,bool iv)
	{
		if(iv == true) return;
		fprintf(mFile,"\tsetAttr \".cs[%i].iv\" %i;\n", cs_i,iv);
	}
	void setHardwareColor(const float3& hc)
	{
		fprintf(mFile,"\tsetAttr \".hc\" -type \"float3\" ");
		hc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHardwareColorR(float hcr)
	{
		if(hcr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hc.hcr\" %f;\n", hcr);
	}
	void setHardwareColorG(float hcg)
	{
		if(hcg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hc.hcg\" %f;\n", hcg);
	}
	void setHardwareColorB(float hcb)
	{
		if(hcb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hc.hcb\" %f;\n", hcb);
	}
	void setAlphaIsLuminance(bool ail)
	{
		if(ail == false) return;
		fprintf(mFile,"\tsetAttr \".ail\" %i;\n", ail);
	}
	void getInputs(size_t cs_i)const
	{
		fprintf(mFile,"\"%s.cs[%i]\"",mName.c_str(),cs_i);
	}
	void getInputs()const
	{

		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
	void getColor(size_t cs_i)const
	{
		fprintf(mFile,"\"%s.cs[%i].c\"",mName.c_str(),cs_i);
	}
	void getColor()const
	{

		fprintf(mFile,"\"%s.cs.c\"",mName.c_str());
	}
	void getColorR(size_t cs_i)const
	{
		fprintf(mFile,"\"%s.cs[%i].c.cr\"",mName.c_str(),cs_i);
	}
	void getColorR()const
	{

		fprintf(mFile,"\"%s.cs.c.cr\"",mName.c_str());
	}
	void getColorG(size_t cs_i)const
	{
		fprintf(mFile,"\"%s.cs[%i].c.cg\"",mName.c_str(),cs_i);
	}
	void getColorG()const
	{

		fprintf(mFile,"\"%s.cs.c.cg\"",mName.c_str());
	}
	void getColorB(size_t cs_i)const
	{
		fprintf(mFile,"\"%s.cs[%i].c.cb\"",mName.c_str(),cs_i);
	}
	void getColorB()const
	{

		fprintf(mFile,"\"%s.cs.c.cb\"",mName.c_str());
	}
	void getAlpha(size_t cs_i)const
	{
		fprintf(mFile,"\"%s.cs[%i].a\"",mName.c_str(),cs_i);
	}
	void getAlpha()const
	{

		fprintf(mFile,"\"%s.cs.a\"",mName.c_str());
	}
	void getBlendMode(size_t cs_i)const
	{
		fprintf(mFile,"\"%s.cs[%i].bm\"",mName.c_str(),cs_i);
	}
	void getBlendMode()const
	{

		fprintf(mFile,"\"%s.cs.bm\"",mName.c_str());
	}
	void getIsVisible(size_t cs_i)const
	{
		fprintf(mFile,"\"%s.cs[%i].iv\"",mName.c_str(),cs_i);
	}
	void getIsVisible()const
	{

		fprintf(mFile,"\"%s.cs.iv\"",mName.c_str());
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
	void getOutAlpha()const
	{
		fprintf(mFile,"\"%s.oa\"",mName.c_str());
	}
	void getAlphaIsLuminance()const
	{
		fprintf(mFile,"\"%s.ail\"",mName.c_str());
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
protected:
	LayeredTexture(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LAYEREDTEXTURE_H__
