/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	OpticalFX(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "opticalFX"){}
	virtual ~OpticalFX(){}
	void setActive(bool act)
	{
		if(act == true) return;
		fprintf(mFile,"setAttr \".act\" %i;\n", act);

	}
	void setGlowType(unsigned int gt)
	{
		if(gt == 1) return;
		fprintf(mFile,"setAttr \".gt\" %i;\n", gt);

	}
	void setHaloType(unsigned int ht)
	{
		if(ht == 0) return;
		fprintf(mFile,"setAttr \".ht\" %i;\n", ht);

	}
	void setFogType(short ft)
	{
		if(ft == 0) return;
		fprintf(mFile,"setAttr \".ft\" %i;\n", ft);

	}
	void setLensFlare(bool lf)
	{
		if(lf == false) return;
		fprintf(mFile,"setAttr \".lf\" %i;\n", lf);

	}
	void setGlowColor(const float3& gc)
	{
		if(gc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".gc\" -type \"float3\" ");
		gc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGlowColorR(float gr)
	{
		if(gr == 0.0) return;
		fprintf(mFile,"setAttr \".gc.gr\" %f;\n", gr);

	}
	void setGlowColorG(float gg)
	{
		if(gg == 0.0) return;
		fprintf(mFile,"setAttr \".gc.gg\" %f;\n", gg);

	}
	void setGlowColorB(float gb)
	{
		if(gb == 0.0) return;
		fprintf(mFile,"setAttr \".gc.gb\" %f;\n", gb);

	}
	void setHaloColor(const float3& hc)
	{
		if(hc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".hc\" -type \"float3\" ");
		hc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setHaloColorR(float hr)
	{
		if(hr == 0.0) return;
		fprintf(mFile,"setAttr \".hc.hr\" %f;\n", hr);

	}
	void setHaloColorG(float hg)
	{
		if(hg == 0.0) return;
		fprintf(mFile,"setAttr \".hc.hg\" %f;\n", hg);

	}
	void setHaloColorB(float hb)
	{
		if(hb == 0.0) return;
		fprintf(mFile,"setAttr \".hc.hb\" %f;\n", hb);

	}
	void setFogColor(const float3& fc)
	{
		if(fc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".fc\" -type \"float3\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFogColorR(float fr)
	{
		if(fr == 0.0) return;
		fprintf(mFile,"setAttr \".fc.fr\" %f;\n", fr);

	}
	void setFogColorG(float fg)
	{
		if(fg == 0.0) return;
		fprintf(mFile,"setAttr \".fc.fg\" %f;\n", fg);

	}
	void setFogColorB(float fb)
	{
		if(fb == 0.0) return;
		fprintf(mFile,"setAttr \".fc.fb\" %f;\n", fb);

	}
	void setFlareColor(const float3& rc)
	{
		if(rc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".rc\" -type \"float3\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFlareColorR(float rr)
	{
		if(rr == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rr\" %f;\n", rr);

	}
	void setFlareColorG(float rg)
	{
		if(rg == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rg\" %f;\n", rg);

	}
	void setFlareColorB(float rb)
	{
		if(rb == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rb\" %f;\n", rb);

	}
	void setFlareIntensity(float fi)
	{
		if(fi == 1.0) return;
		fprintf(mFile,"setAttr \".fi\" %f;\n", fi);

	}
	void setFlareNumCircles(float fn)
	{
		if(fn == 20.0) return;
		fprintf(mFile,"setAttr \".fn\" %f;\n", fn);

	}
	void setFlareMinSize(float fm)
	{
		if(fm == 0.1) return;
		fprintf(mFile,"setAttr \".fm\" %f;\n", fm);

	}
	void setFlareMaxSize(float fa)
	{
		if(fa == 1.0) return;
		fprintf(mFile,"setAttr \".fa\" %f;\n", fa);

	}
	void setFlareColSpread(float lc)
	{
		if(lc == 0.5) return;
		fprintf(mFile,"setAttr \".lc\" %f;\n", lc);

	}
	void setFlareFocus(float ff)
	{
		if(ff == 0.6) return;
		fprintf(mFile,"setAttr \".ff\" %f;\n", ff);

	}
	void setFlareVertical(float fv)
	{
		if(fv == 1.0) return;
		fprintf(mFile,"setAttr \".fv\" %f;\n", fv);

	}
	void setFlareHorizontal(float fh)
	{
		if(fh == 1.0) return;
		fprintf(mFile,"setAttr \".fh\" %f;\n", fh);

	}
	void setFlareLength(float fl)
	{
		if(fl == 1.0) return;
		fprintf(mFile,"setAttr \".fl\" %f;\n", fl);

	}
	void setHexagonFlare(bool hf)
	{
		if(hf == false) return;
		fprintf(mFile,"setAttr \".hf\" %i;\n", hf);

	}
	void setGlowIntensity(float gi)
	{
		if(gi == 1.0) return;
		fprintf(mFile,"setAttr \".gi\" %f;\n", gi);

	}
	void setHaloIntensity(float hi)
	{
		if(hi == 1.0) return;
		fprintf(mFile,"setAttr \".hi\" %f;\n", hi);

	}
	void setFogIntensity(float oi)
	{
		if(oi == 1.0) return;
		fprintf(mFile,"setAttr \".oi\" %f;\n", oi);

	}
	void setGlowSpread(float gs)
	{
		if(gs == 1.0) return;
		fprintf(mFile,"setAttr \".gs\" %f;\n", gs);

	}
	void setHaloSpread(float hs)
	{
		if(hs == 1.0) return;
		fprintf(mFile,"setAttr \".hs\" %f;\n", hs);

	}
	void setFogSpread(float fs)
	{
		if(fs == 1.0) return;
		fprintf(mFile,"setAttr \".fs\" %f;\n", fs);

	}
	void setGlowNoise(float gd)
	{
		if(gd == 0.0) return;
		fprintf(mFile,"setAttr \".gd\" %f;\n", gd);

	}
	void setFogNoise(float fd)
	{
		if(fd == 0.0) return;
		fprintf(mFile,"setAttr \".fd\" %f;\n", fd);

	}
	void setGlowRadialNoise(float gn)
	{
		if(gn == 0.0) return;
		fprintf(mFile,"setAttr \".gn\" %f;\n", gn);

	}
	void setFogRadialNoise(float fz)
	{
		if(fz == 0.0) return;
		fprintf(mFile,"setAttr \".fz\" %f;\n", fz);

	}
	void setGlowStarLevel(float gv)
	{
		if(gv == 3.0) return;
		fprintf(mFile,"setAttr \".gv\" %f;\n", gv);

	}
	void setFogStarlevel(float fe)
	{
		if(fe == 0.0) return;
		fprintf(mFile,"setAttr \".fe\" %f;\n", fe);

	}
	void setGlowOpacity(float go)
	{
		if(go == 0.0) return;
		fprintf(mFile,"setAttr \".go\" %f;\n", go);

	}
	void setFogOpacity(float fo)
	{
		if(fo == 0.0) return;
		fprintf(mFile,"setAttr \".fo\" %f;\n", fo);

	}
	void setRadialFrequency(float rf)
	{
		if(rf == 0.5) return;
		fprintf(mFile,"setAttr \".rf\" %f;\n", rf);

	}
	void setStarPoints(float sp)
	{
		if(sp == 4.0) return;
		fprintf(mFile,"setAttr \".sp\" %f;\n", sp);

	}
	void setRotation(float ra)
	{
		if(ra == 0.0) return;
		fprintf(mFile,"setAttr \".ra\" %f;\n", ra);

	}
	void setNoiseUscale(float nu)
	{
		if(nu == 1.0) return;
		fprintf(mFile,"setAttr \".nu\" %f;\n", nu);

	}
	void setNoiseVscale(float nv)
	{
		if(nv == 1.0) return;
		fprintf(mFile,"setAttr \".nv\" %f;\n", nv);

	}
	void setNoiseUoffset(float ni)
	{
		if(ni == 1.0) return;
		fprintf(mFile,"setAttr \".ni\" %f;\n", ni);

	}
	void setNoiseVoffset(float nf)
	{
		if(nf == 0.5) return;
		fprintf(mFile,"setAttr \".nf\" %f;\n", nf);

	}
	void setNoiseThreshold(float nt)
	{
		if(nt == 0.5) return;
		fprintf(mFile,"setAttr \".nt\" %f;\n", nt);

	}
	void setIgnoreLight(bool il)
	{
		if(il == false) return;
		fprintf(mFile,"setAttr \".il\" %i;\n", il);

	}
	void setLightWorldMat(const matrix& lw)
	{
		if(lw == identity) return;
		fprintf(mFile,"setAttr \".lw\" -type \"matrix\" ");
		lw.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGlowVisibility(float gvb)
	{
		if(gvb == 1.0) return;
		fprintf(mFile,"setAttr \".gvb\" %f;\n", gvb);

	}
	void setLightColor(const float3& lr)
	{
		if(lr == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".lr\" -type \"float3\" ");
		lr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLightColorR(float lcr)
	{
		if(lcr == 0.0) return;
		fprintf(mFile,"setAttr \".lr.lcr\" %f;\n", lcr);

	}
	void setLightColorG(float lcg)
	{
		if(lcg == 0.0) return;
		fprintf(mFile,"setAttr \".lr.lcg\" %f;\n", lcg);

	}
	void setLightColorB(float lgb)
	{
		if(lgb == 0.0) return;
		fprintf(mFile,"setAttr \".lr.lgb\" %f;\n", lgb);

	}
	void setVisibility(const float3& vb)
	{
		if(vb == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".vb\" -type \"float3\" ");
		vb.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVisibilityR(float vbr)
	{
		if(vbr == 0.0) return;
		fprintf(mFile,"setAttr \".vb.vbr\" %f;\n", vbr);

	}
	void setVisibilityG(float vbg)
	{
		if(vbg == 0.0) return;
		fprintf(mFile,"setAttr \".vb.vbg\" %f;\n", vbg);

	}
	void setVisibilityB(float vbb)
	{
		if(vbb == 0.0) return;
		fprintf(mFile,"setAttr \".vb.vbb\" %f;\n", vbb);

	}
	void getActive()
	{
		fprintf(mFile,"\"%s.act\"",mName.c_str());

	}
	void getGlowType()
	{
		fprintf(mFile,"\"%s.gt\"",mName.c_str());

	}
	void getHaloType()
	{
		fprintf(mFile,"\"%s.ht\"",mName.c_str());

	}
	void getFogType()
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());

	}
	void getLensFlare()
	{
		fprintf(mFile,"\"%s.lf\"",mName.c_str());

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
	void getFogColor()
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());

	}
	void getFogColorR()
	{
		fprintf(mFile,"\"%s.fc.fr\"",mName.c_str());

	}
	void getFogColorG()
	{
		fprintf(mFile,"\"%s.fc.fg\"",mName.c_str());

	}
	void getFogColorB()
	{
		fprintf(mFile,"\"%s.fc.fb\"",mName.c_str());

	}
	void getFlareColor()
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());

	}
	void getFlareColorR()
	{
		fprintf(mFile,"\"%s.rc.rr\"",mName.c_str());

	}
	void getFlareColorG()
	{
		fprintf(mFile,"\"%s.rc.rg\"",mName.c_str());

	}
	void getFlareColorB()
	{
		fprintf(mFile,"\"%s.rc.rb\"",mName.c_str());

	}
	void getFlareIntensity()
	{
		fprintf(mFile,"\"%s.fi\"",mName.c_str());

	}
	void getFlareNumCircles()
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());

	}
	void getFlareMinSize()
	{
		fprintf(mFile,"\"%s.fm\"",mName.c_str());

	}
	void getFlareMaxSize()
	{
		fprintf(mFile,"\"%s.fa\"",mName.c_str());

	}
	void getFlareColSpread()
	{
		fprintf(mFile,"\"%s.lc\"",mName.c_str());

	}
	void getFlareFocus()
	{
		fprintf(mFile,"\"%s.ff\"",mName.c_str());

	}
	void getFlareVertical()
	{
		fprintf(mFile,"\"%s.fv\"",mName.c_str());

	}
	void getFlareHorizontal()
	{
		fprintf(mFile,"\"%s.fh\"",mName.c_str());

	}
	void getFlareLength()
	{
		fprintf(mFile,"\"%s.fl\"",mName.c_str());

	}
	void getHexagonFlare()
	{
		fprintf(mFile,"\"%s.hf\"",mName.c_str());

	}
	void getGlowIntensity()
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());

	}
	void getHaloIntensity()
	{
		fprintf(mFile,"\"%s.hi\"",mName.c_str());

	}
	void getFogIntensity()
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());

	}
	void getGlowSpread()
	{
		fprintf(mFile,"\"%s.gs\"",mName.c_str());

	}
	void getHaloSpread()
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());

	}
	void getFogSpread()
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());

	}
	void getGlowNoise()
	{
		fprintf(mFile,"\"%s.gd\"",mName.c_str());

	}
	void getFogNoise()
	{
		fprintf(mFile,"\"%s.fd\"",mName.c_str());

	}
	void getGlowRadialNoise()
	{
		fprintf(mFile,"\"%s.gn\"",mName.c_str());

	}
	void getFogRadialNoise()
	{
		fprintf(mFile,"\"%s.fz\"",mName.c_str());

	}
	void getGlowStarLevel()
	{
		fprintf(mFile,"\"%s.gv\"",mName.c_str());

	}
	void getFogStarlevel()
	{
		fprintf(mFile,"\"%s.fe\"",mName.c_str());

	}
	void getGlowOpacity()
	{
		fprintf(mFile,"\"%s.go\"",mName.c_str());

	}
	void getFogOpacity()
	{
		fprintf(mFile,"\"%s.fo\"",mName.c_str());

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
	void getNoiseUscale()
	{
		fprintf(mFile,"\"%s.nu\"",mName.c_str());

	}
	void getNoiseVscale()
	{
		fprintf(mFile,"\"%s.nv\"",mName.c_str());

	}
	void getNoiseUoffset()
	{
		fprintf(mFile,"\"%s.ni\"",mName.c_str());

	}
	void getNoiseVoffset()
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());

	}
	void getNoiseThreshold()
	{
		fprintf(mFile,"\"%s.nt\"",mName.c_str());

	}
	void getIgnoreLight()
	{
		fprintf(mFile,"\"%s.il\"",mName.c_str());

	}
	void getLightConnection()
	{
		fprintf(mFile,"\"%s.ln\"",mName.c_str());

	}
protected:
	OpticalFX(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OPTICALFX_H__
