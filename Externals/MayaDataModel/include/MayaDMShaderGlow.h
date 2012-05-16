/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SHADERGLOW_H__
#define __MayaDM_SHADERGLOW_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ShaderGlow : public DependNode
{
public:
public:

	ShaderGlow():DependNode(){}
	ShaderGlow(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "shaderGlow", shared, create){}
	virtual ~ShaderGlow(){}

	void setGlowType(unsigned int gt)
	{
		if(gt == 1) return;
		fprintf(mFile,"\tsetAttr \".gt\" %i;\n", gt);
	}
	void setHaloType(unsigned int ht)
	{
		if(ht == 1) return;
		fprintf(mFile,"\tsetAttr \".ht\" %i;\n", ht);
	}
	void setGlowIntensity(float gi)
	{
		if(gi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gi\" %f;\n", gi);
	}
	void setGlowColor(const float3& gc)
	{
		if(gc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".gc\" -type \"float3\" ");
		gc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGlowColorR(float gr)
	{
		if(gr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gr\" %f;\n", gr);
	}
	void setGlowColorG(float gg)
	{
		if(gg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gg\" %f;\n", gg);
	}
	void setGlowColorB(float gb)
	{
		if(gb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gb\" %f;\n", gb);
	}
	void setGlowSpread(float gs)
	{
		if(gs == 0.05) return;
		fprintf(mFile,"\tsetAttr \".gs\" %f;\n", gs);
	}
	void setGlowEccentricity(float gecc)
	{
		if(gecc == 0.1) return;
		fprintf(mFile,"\tsetAttr \".gecc\" %f;\n", gecc);
	}
	void setGlowRadialNoise(float gn)
	{
		if(gn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gn\" %f;\n", gn);
	}
	void setGlowStarLevel(float gv)
	{
		if(gv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gv\" %f;\n", gv);
	}
	void setGlowOpacity(float go)
	{
		if(go == 0.0) return;
		fprintf(mFile,"\tsetAttr \".go\" %f;\n", go);
	}
	void setGlowRingIntensity(float gri)
	{
		if(gri == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gri\" %f;\n", gri);
	}
	void setGlowRingFrequency(float grf)
	{
		if(grf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".grf\" %f;\n", grf);
	}
	void setGlowFilterWidth(int gfw)
	{
		if(gfw == 1) return;
		fprintf(mFile,"\tsetAttr \".gfw\" %i;\n", gfw);
	}
	void setHaloIntensity(float hi)
	{
		if(hi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hi\" %f;\n", hi);
	}
	void setHaloColor(const float3& hc)
	{
		if(hc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".hc\" -type \"float3\" ");
		hc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHaloColorR(float hr)
	{
		if(hr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hc.hr\" %f;\n", hr);
	}
	void setHaloColorG(float hg)
	{
		if(hg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hc.hg\" %f;\n", hg);
	}
	void setHaloColorB(float hb)
	{
		if(hb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hc.hb\" %f;\n", hb);
	}
	void setHaloSpread(float hs)
	{
		if(hs == 0.3) return;
		fprintf(mFile,"\tsetAttr \".hs\" %f;\n", hs);
	}
	void setHaloEccentricity(float hecc)
	{
		if(hecc == 0.1) return;
		fprintf(mFile,"\tsetAttr \".hecc\" %f;\n", hecc);
	}
	void setHaloRadialNoise(float hn)
	{
		if(hn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hn\" %f;\n", hn);
	}
	void setHaloStarLevel(float hv)
	{
		if(hv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hv\" %f;\n", hv);
	}
	void setHaloOpacity(float ho)
	{
		if(ho == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ho\" %f;\n", ho);
	}
	void setHaloRingIntensity(float hri)
	{
		if(hri == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hri\" %f;\n", hri);
	}
	void setHaloRingFrequency(float hrf)
	{
		if(hrf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hrf\" %f;\n", hrf);
	}
	void setHaloFilterWidth(int hfw)
	{
		if(hfw == 1) return;
		fprintf(mFile,"\tsetAttr \".hfw\" %i;\n", hfw);
	}
	void setQuality(float qual)
	{
		if(qual == 0.5) return;
		fprintf(mFile,"\tsetAttr \".qual\" %f;\n", qual);
	}
	void setThreshold(float th)
	{
		if(th == 0.0) return;
		fprintf(mFile,"\tsetAttr \".th\" %f;\n", th);
	}
	void setRadialFrequency(float rf)
	{
		if(rf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".rf\" %f;\n", rf);
	}
	void setStarPoints(float sp)
	{
		if(sp == 4.0) return;
		fprintf(mFile,"\tsetAttr \".sp\" %f;\n", sp);
	}
	void setRotation(float ra)
	{
		if(ra == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
	}
	void setAutoExposure(bool ae)
	{
		if(ae == true) return;
		fprintf(mFile,"\tsetAttr \".ae\" %i;\n", ae);
	}
	void getGlowType()const
	{
		fprintf(mFile,"\"%s.gt\"",mName.c_str());
	}
	void getHaloType()const
	{
		fprintf(mFile,"\"%s.ht\"",mName.c_str());
	}
	void getGlowIntensity()const
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());
	}
	void getGlowColor()const
	{
		fprintf(mFile,"\"%s.gc\"",mName.c_str());
	}
	void getGlowColorR()const
	{
		fprintf(mFile,"\"%s.gc.gr\"",mName.c_str());
	}
	void getGlowColorG()const
	{
		fprintf(mFile,"\"%s.gc.gg\"",mName.c_str());
	}
	void getGlowColorB()const
	{
		fprintf(mFile,"\"%s.gc.gb\"",mName.c_str());
	}
	void getGlowSpread()const
	{
		fprintf(mFile,"\"%s.gs\"",mName.c_str());
	}
	void getGlowEccentricity()const
	{
		fprintf(mFile,"\"%s.gecc\"",mName.c_str());
	}
	void getGlowRadialNoise()const
	{
		fprintf(mFile,"\"%s.gn\"",mName.c_str());
	}
	void getGlowStarLevel()const
	{
		fprintf(mFile,"\"%s.gv\"",mName.c_str());
	}
	void getGlowOpacity()const
	{
		fprintf(mFile,"\"%s.go\"",mName.c_str());
	}
	void getGlowRingIntensity()const
	{
		fprintf(mFile,"\"%s.gri\"",mName.c_str());
	}
	void getGlowRingFrequency()const
	{
		fprintf(mFile,"\"%s.grf\"",mName.c_str());
	}
	void getGlowFilterWidth()const
	{
		fprintf(mFile,"\"%s.gfw\"",mName.c_str());
	}
	void getHaloIntensity()const
	{
		fprintf(mFile,"\"%s.hi\"",mName.c_str());
	}
	void getHaloColor()const
	{
		fprintf(mFile,"\"%s.hc\"",mName.c_str());
	}
	void getHaloColorR()const
	{
		fprintf(mFile,"\"%s.hc.hr\"",mName.c_str());
	}
	void getHaloColorG()const
	{
		fprintf(mFile,"\"%s.hc.hg\"",mName.c_str());
	}
	void getHaloColorB()const
	{
		fprintf(mFile,"\"%s.hc.hb\"",mName.c_str());
	}
	void getHaloSpread()const
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());
	}
	void getHaloEccentricity()const
	{
		fprintf(mFile,"\"%s.hecc\"",mName.c_str());
	}
	void getHaloRadialNoise()const
	{
		fprintf(mFile,"\"%s.hn\"",mName.c_str());
	}
	void getHaloStarLevel()const
	{
		fprintf(mFile,"\"%s.hv\"",mName.c_str());
	}
	void getHaloOpacity()const
	{
		fprintf(mFile,"\"%s.ho\"",mName.c_str());
	}
	void getHaloRingIntensity()const
	{
		fprintf(mFile,"\"%s.hri\"",mName.c_str());
	}
	void getHaloRingFrequency()const
	{
		fprintf(mFile,"\"%s.hrf\"",mName.c_str());
	}
	void getHaloFilterWidth()const
	{
		fprintf(mFile,"\"%s.hfw\"",mName.c_str());
	}
	void getQuality()const
	{
		fprintf(mFile,"\"%s.qual\"",mName.c_str());
	}
	void getThreshold()const
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());
	}
	void getRadialFrequency()const
	{
		fprintf(mFile,"\"%s.rf\"",mName.c_str());
	}
	void getStarPoints()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getRotation()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getAutoExposure()const
	{
		fprintf(mFile,"\"%s.ae\"",mName.c_str());
	}
protected:
	ShaderGlow(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SHADERGLOW_H__
