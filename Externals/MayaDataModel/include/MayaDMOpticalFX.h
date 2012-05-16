/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OPTICALFX_H__
#define __MayaDM_OPTICALFX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class OpticalFX : public DependNode
{
public:
public:

	OpticalFX():DependNode(){}
	OpticalFX(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "opticalFX", shared, create){}
	virtual ~OpticalFX(){}

	void setActive(bool act)
	{
		if(act == true) return;
		fprintf(mFile,"\tsetAttr \".act\" %i;\n", act);
	}
	void setGlowType(unsigned int gt)
	{
		if(gt == 1) return;
		fprintf(mFile,"\tsetAttr \".gt\" %i;\n", gt);
	}
	void setHaloType(unsigned int ht)
	{
		if(ht == 0) return;
		fprintf(mFile,"\tsetAttr \".ht\" %i;\n", ht);
	}
	void setFogType(short ft)
	{
		if(ft == 0) return;
		fprintf(mFile,"\tsetAttr \".ft\" %i;\n", ft);
	}
	void setLensFlare(bool lf)
	{
		if(lf == false) return;
		fprintf(mFile,"\tsetAttr \".lf\" %i;\n", lf);
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
	void setFogColor(const float3& fc)
	{
		if(fc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".fc\" -type \"float3\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFogColorR(float fr)
	{
		if(fr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fr\" %f;\n", fr);
	}
	void setFogColorG(float fg)
	{
		if(fg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fg\" %f;\n", fg);
	}
	void setFogColorB(float fb)
	{
		if(fb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fb\" %f;\n", fb);
	}
	void setFlareColor(const float3& rc)
	{
		if(rc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".rc\" -type \"float3\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFlareColorR(float rr)
	{
		if(rr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rr\" %f;\n", rr);
	}
	void setFlareColorG(float rg)
	{
		if(rg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rg\" %f;\n", rg);
	}
	void setFlareColorB(float rb)
	{
		if(rb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rb\" %f;\n", rb);
	}
	void setFlareIntensity(float fi)
	{
		if(fi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fi\" %f;\n", fi);
	}
	void setFlareNumCircles(float fn)
	{
		if(fn == 20.0) return;
		fprintf(mFile,"\tsetAttr \".fn\" %f;\n", fn);
	}
	void setFlareMinSize(float fm)
	{
		if(fm == 0.1) return;
		fprintf(mFile,"\tsetAttr \".fm\" %f;\n", fm);
	}
	void setFlareMaxSize(float fa)
	{
		if(fa == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fa\" %f;\n", fa);
	}
	void setFlareColSpread(float lc)
	{
		if(lc == 0.5) return;
		fprintf(mFile,"\tsetAttr \".lc\" %f;\n", lc);
	}
	void setFlareFocus(float ff)
	{
		if(ff == 0.6) return;
		fprintf(mFile,"\tsetAttr \".ff\" %f;\n", ff);
	}
	void setFlareVertical(float fv)
	{
		if(fv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fv\" %f;\n", fv);
	}
	void setFlareHorizontal(float fh)
	{
		if(fh == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fh\" %f;\n", fh);
	}
	void setFlareLength(float fl)
	{
		if(fl == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fl\" %f;\n", fl);
	}
	void setHexagonFlare(bool hf)
	{
		if(hf == false) return;
		fprintf(mFile,"\tsetAttr \".hf\" %i;\n", hf);
	}
	void setGlowIntensity(float gi)
	{
		if(gi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gi\" %f;\n", gi);
	}
	void setHaloIntensity(float hi)
	{
		if(hi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hi\" %f;\n", hi);
	}
	void setFogIntensity(float oi)
	{
		if(oi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".oi\" %f;\n", oi);
	}
	void setGlowSpread(float gs)
	{
		if(gs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gs\" %f;\n", gs);
	}
	void setHaloSpread(float hs)
	{
		if(hs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hs\" %f;\n", hs);
	}
	void setFogSpread(float fs)
	{
		if(fs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fs\" %f;\n", fs);
	}
	void setGlowNoise(float gd)
	{
		if(gd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gd\" %f;\n", gd);
	}
	void setFogNoise(float fd)
	{
		if(fd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fd\" %f;\n", fd);
	}
	void setGlowRadialNoise(float gn)
	{
		if(gn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gn\" %f;\n", gn);
	}
	void setFogRadialNoise(float fz)
	{
		if(fz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fz\" %f;\n", fz);
	}
	void setGlowStarLevel(float gv)
	{
		if(gv == 3.0) return;
		fprintf(mFile,"\tsetAttr \".gv\" %f;\n", gv);
	}
	void setFogStarlevel(float fe)
	{
		if(fe == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fe\" %f;\n", fe);
	}
	void setGlowOpacity(float go)
	{
		if(go == 0.0) return;
		fprintf(mFile,"\tsetAttr \".go\" %f;\n", go);
	}
	void setFogOpacity(float fo)
	{
		if(fo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fo\" %f;\n", fo);
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
	void setNoiseUscale(float nu)
	{
		if(nu == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nu\" %f;\n", nu);
	}
	void setNoiseVscale(float nv)
	{
		if(nv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nv\" %f;\n", nv);
	}
	void setNoiseUoffset(float ni)
	{
		if(ni == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ni\" %f;\n", ni);
	}
	void setNoiseVoffset(float nf)
	{
		if(nf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".nf\" %f;\n", nf);
	}
	void setNoiseThreshold(float nt)
	{
		if(nt == 0.5) return;
		fprintf(mFile,"\tsetAttr \".nt\" %f;\n", nt);
	}
	void setIgnoreLight(bool il)
	{
		if(il == false) return;
		fprintf(mFile,"\tsetAttr \".il\" %i;\n", il);
	}
	void setLightWorldMat(const matrix& lw)
	{
		if(lw == identity) return;
		fprintf(mFile,"\tsetAttr \".lw\" -type \"matrix\" ");
		lw.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGlowVisibility(float gvb)
	{
		if(gvb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gvb\" %f;\n", gvb);
	}
	void setLightColor(const float3& lr)
	{
		if(lr == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".lr\" -type \"float3\" ");
		lr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLightColorR(float lcr)
	{
		if(lcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lr.lcr\" %f;\n", lcr);
	}
	void setLightColorG(float lcg)
	{
		if(lcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lr.lcg\" %f;\n", lcg);
	}
	void setLightColorB(float lgb)
	{
		if(lgb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lr.lgb\" %f;\n", lgb);
	}
	void setVisibility(const float3& vb)
	{
		if(vb == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".vb\" -type \"float3\" ");
		vb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVisibilityR(float vbr)
	{
		if(vbr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vb.vbr\" %f;\n", vbr);
	}
	void setVisibilityG(float vbg)
	{
		if(vbg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vb.vbg\" %f;\n", vbg);
	}
	void setVisibilityB(float vbb)
	{
		if(vbb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vb.vbb\" %f;\n", vbb);
	}
	void getActive()const
	{
		fprintf(mFile,"\"%s.act\"",mName.c_str());
	}
	void getGlowType()const
	{
		fprintf(mFile,"\"%s.gt\"",mName.c_str());
	}
	void getHaloType()const
	{
		fprintf(mFile,"\"%s.ht\"",mName.c_str());
	}
	void getFogType()const
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());
	}
	void getLensFlare()const
	{
		fprintf(mFile,"\"%s.lf\"",mName.c_str());
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
	void getFogColor()const
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getFogColorR()const
	{
		fprintf(mFile,"\"%s.fc.fr\"",mName.c_str());
	}
	void getFogColorG()const
	{
		fprintf(mFile,"\"%s.fc.fg\"",mName.c_str());
	}
	void getFogColorB()const
	{
		fprintf(mFile,"\"%s.fc.fb\"",mName.c_str());
	}
	void getFlareColor()const
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());
	}
	void getFlareColorR()const
	{
		fprintf(mFile,"\"%s.rc.rr\"",mName.c_str());
	}
	void getFlareColorG()const
	{
		fprintf(mFile,"\"%s.rc.rg\"",mName.c_str());
	}
	void getFlareColorB()const
	{
		fprintf(mFile,"\"%s.rc.rb\"",mName.c_str());
	}
	void getFlareIntensity()const
	{
		fprintf(mFile,"\"%s.fi\"",mName.c_str());
	}
	void getFlareNumCircles()const
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());
	}
	void getFlareMinSize()const
	{
		fprintf(mFile,"\"%s.fm\"",mName.c_str());
	}
	void getFlareMaxSize()const
	{
		fprintf(mFile,"\"%s.fa\"",mName.c_str());
	}
	void getFlareColSpread()const
	{
		fprintf(mFile,"\"%s.lc\"",mName.c_str());
	}
	void getFlareFocus()const
	{
		fprintf(mFile,"\"%s.ff\"",mName.c_str());
	}
	void getFlareVertical()const
	{
		fprintf(mFile,"\"%s.fv\"",mName.c_str());
	}
	void getFlareHorizontal()const
	{
		fprintf(mFile,"\"%s.fh\"",mName.c_str());
	}
	void getFlareLength()const
	{
		fprintf(mFile,"\"%s.fl\"",mName.c_str());
	}
	void getHexagonFlare()const
	{
		fprintf(mFile,"\"%s.hf\"",mName.c_str());
	}
	void getGlowIntensity()const
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());
	}
	void getHaloIntensity()const
	{
		fprintf(mFile,"\"%s.hi\"",mName.c_str());
	}
	void getFogIntensity()const
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());
	}
	void getGlowSpread()const
	{
		fprintf(mFile,"\"%s.gs\"",mName.c_str());
	}
	void getHaloSpread()const
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());
	}
	void getFogSpread()const
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getGlowNoise()const
	{
		fprintf(mFile,"\"%s.gd\"",mName.c_str());
	}
	void getFogNoise()const
	{
		fprintf(mFile,"\"%s.fd\"",mName.c_str());
	}
	void getGlowRadialNoise()const
	{
		fprintf(mFile,"\"%s.gn\"",mName.c_str());
	}
	void getFogRadialNoise()const
	{
		fprintf(mFile,"\"%s.fz\"",mName.c_str());
	}
	void getGlowStarLevel()const
	{
		fprintf(mFile,"\"%s.gv\"",mName.c_str());
	}
	void getFogStarlevel()const
	{
		fprintf(mFile,"\"%s.fe\"",mName.c_str());
	}
	void getGlowOpacity()const
	{
		fprintf(mFile,"\"%s.go\"",mName.c_str());
	}
	void getFogOpacity()const
	{
		fprintf(mFile,"\"%s.fo\"",mName.c_str());
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
	void getNoiseUscale()const
	{
		fprintf(mFile,"\"%s.nu\"",mName.c_str());
	}
	void getNoiseVscale()const
	{
		fprintf(mFile,"\"%s.nv\"",mName.c_str());
	}
	void getNoiseUoffset()const
	{
		fprintf(mFile,"\"%s.ni\"",mName.c_str());
	}
	void getNoiseVoffset()const
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());
	}
	void getNoiseThreshold()const
	{
		fprintf(mFile,"\"%s.nt\"",mName.c_str());
	}
	void getIgnoreLight()const
	{
		fprintf(mFile,"\"%s.il\"",mName.c_str());
	}
	void getLightWorldMat()const
	{
		fprintf(mFile,"\"%s.lw\"",mName.c_str());
	}
	void getLightConnection()const
	{
		fprintf(mFile,"\"%s.ln\"",mName.c_str());
	}
	void getGlowVisibility()const
	{
		fprintf(mFile,"\"%s.gvb\"",mName.c_str());
	}
	void getLightColor()const
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());
	}
	void getLightColorR()const
	{
		fprintf(mFile,"\"%s.lr.lcr\"",mName.c_str());
	}
	void getLightColorG()const
	{
		fprintf(mFile,"\"%s.lr.lcg\"",mName.c_str());
	}
	void getLightColorB()const
	{
		fprintf(mFile,"\"%s.lr.lgb\"",mName.c_str());
	}
	void getVisibility()const
	{
		fprintf(mFile,"\"%s.vb\"",mName.c_str());
	}
	void getVisibilityR()const
	{
		fprintf(mFile,"\"%s.vb.vbr\"",mName.c_str());
	}
	void getVisibilityG()const
	{
		fprintf(mFile,"\"%s.vb.vbg\"",mName.c_str());
	}
	void getVisibilityB()const
	{
		fprintf(mFile,"\"%s.vb.vbb\"",mName.c_str());
	}
protected:
	OpticalFX(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OPTICALFX_H__
