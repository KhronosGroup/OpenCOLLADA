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
	ShaderGlow(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "shaderGlow"){}
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
	void getGlowType()
	{
		fprintf(mFile,"\"%s.gt\"",mName.c_str());

	}
	void getHaloType()
	{
		fprintf(mFile,"\"%s.ht\"",mName.c_str());

	}
	void getGlowIntensity()
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());

	}
	void getGlowColor()
	{
		fprintf(mFile,"\"%s.gc\"",mName.c_str());

	}
	void getGlowColorR()
	{
		fprintf(mFile,"\"%s.gc.gr\"",mName.c_str());

	}
	void getGlowColorG()
	{
		fprintf(mFile,"\"%s.gc.gg\"",mName.c_str());

	}
	void getGlowColorB()
	{
		fprintf(mFile,"\"%s.gc.gb\"",mName.c_str());

	}
	void getGlowSpread()
	{
		fprintf(mFile,"\"%s.gs\"",mName.c_str());

	}
	void getGlowEccentricity()
	{
		fprintf(mFile,"\"%s.gecc\"",mName.c_str());

	}
	void getGlowRadialNoise()
	{
		fprintf(mFile,"\"%s.gn\"",mName.c_str());

	}
	void getGlowStarLevel()
	{
		fprintf(mFile,"\"%s.gv\"",mName.c_str());

	}
	void getGlowOpacity()
	{
		fprintf(mFile,"\"%s.go\"",mName.c_str());

	}
	void getGlowRingIntensity()
	{
		fprintf(mFile,"\"%s.gri\"",mName.c_str());

	}
	void getGlowRingFrequency()
	{
		fprintf(mFile,"\"%s.grf\"",mName.c_str());

	}
	void getGlowFilterWidth()
	{
		fprintf(mFile,"\"%s.gfw\"",mName.c_str());

	}
	void getHaloIntensity()
	{
		fprintf(mFile,"\"%s.hi\"",mName.c_str());

	}
	void getHaloColor()
	{
		fprintf(mFile,"\"%s.hc\"",mName.c_str());

	}
	void getHaloColorR()
	{
		fprintf(mFile,"\"%s.hc.hr\"",mName.c_str());

	}
	void getHaloColorG()
	{
		fprintf(mFile,"\"%s.hc.hg\"",mName.c_str());

	}
	void getHaloColorB()
	{
		fprintf(mFile,"\"%s.hc.hb\"",mName.c_str());

	}
	void getHaloSpread()
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());

	}
	void getHaloEccentricity()
	{
		fprintf(mFile,"\"%s.hecc\"",mName.c_str());

	}
	void getHaloRadialNoise()
	{
		fprintf(mFile,"\"%s.hn\"",mName.c_str());

	}
	void getHaloStarLevel()
	{
		fprintf(mFile,"\"%s.hv\"",mName.c_str());

	}
	void getHaloOpacity()
	{
		fprintf(mFile,"\"%s.ho\"",mName.c_str());

	}
	void getHaloRingIntensity()
	{
		fprintf(mFile,"\"%s.hri\"",mName.c_str());

	}
	void getHaloRingFrequency()
	{
		fprintf(mFile,"\"%s.hrf\"",mName.c_str());

	}
	void getHaloFilterWidth()
	{
		fprintf(mFile,"\"%s.hfw\"",mName.c_str());

	}
	void getQuality()
	{
		fprintf(mFile,"\"%s.qual\"",mName.c_str());

	}
	void getThreshold()
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());

	}
	void getRadialFrequency()
	{
		fprintf(mFile,"\"%s.rf\"",mName.c_str());

	}
	void getStarPoints()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getRotation()
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());

	}
	void getAutoExposure()
	{
		fprintf(mFile,"\"%s.ae\"",mName.c_str());

	}
protected:
	ShaderGlow(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SHADERGLOW_H__
