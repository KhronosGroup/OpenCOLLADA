/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLECLOUD_H__
#define __MayaDM_PARTICLECLOUD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ParticleCloud : public DependNode
{
public:
public:
	ParticleCloud(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleCloud"){}
	virtual ~ParticleCloud(){}
	void setColor(const float3& c)
	{
		fprintf(mFile,"setAttr \".c\" -type \"float3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"setAttr \".c.cr\" %f;\n", cr);

	}
	void setColorG(float cg)
	{
		if(cg == 0.58824) return;
		fprintf(mFile,"setAttr \".c.cg\" %f;\n", cg);

	}
	void setColorB(float cb)
	{
		if(cb == 0.644) return;
		fprintf(mFile,"setAttr \".c.cb\" %f;\n", cb);

	}
	void setTransparency(const float3& t)
	{
		fprintf(mFile,"setAttr \".t\" -type \"float3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTransparencyR(float tr)
	{
		if(tr == 0.5) return;
		fprintf(mFile,"setAttr \".t.tr\" %f;\n", tr);

	}
	void setTransparencyG(float tg)
	{
		if(tg == 0.5) return;
		fprintf(mFile,"setAttr \".t.tg\" %f;\n", tg);

	}
	void setTransparencyB(float tb)
	{
		if(tb == 0.5) return;
		fprintf(mFile,"setAttr \".t.tb\" %f;\n", tb);

	}
	void setIncandescence(const float3& i_)
	{
		fprintf(mFile,"setAttr \".i\" -type \"float3\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIncandescenceR(float ir)
	{
		if(ir == 0.0) return;
		fprintf(mFile,"setAttr \".i.ir\" %f;\n", ir);

	}
	void setIncandescenceG(float ig)
	{
		if(ig == 0.0) return;
		fprintf(mFile,"setAttr \".i.ig\" %f;\n", ig);

	}
	void setIncandescenceB(float ib)
	{
		if(ib == 0.0) return;
		fprintf(mFile,"setAttr \".i.ib\" %f;\n", ib);

	}
	void setDensity(float d)
	{
		if(d == 1.0) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setGlowIntensity(float gi)
	{
		if(gi == 0.0) return;
		fprintf(mFile,"setAttr \".gi\" %f;\n", gi);

	}
	void setNoise(float n)
	{
		if(n == 0.75) return;
		fprintf(mFile,"setAttr \".n\" %f;\n", n);

	}
	void setNoiseFreq(float nf)
	{
		if(nf == 0.15) return;
		fprintf(mFile,"setAttr \".nf\" %f;\n", nf);

	}
	void setNoiseAspect(float na)
	{
		if(na == 0.0) return;
		fprintf(mFile,"setAttr \".na\" %f;\n", na);

	}
	void setBlobMap(const float3& m)
	{
		fprintf(mFile,"setAttr \".m\" -type \"float3\" ");
		m.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBlobMapR(float mr)
	{
		if(mr == 1.0) return;
		fprintf(mFile,"setAttr \".m.mr\" %f;\n", mr);

	}
	void setBlobMapG(float mg)
	{
		if(mg == 1.0) return;
		fprintf(mFile,"setAttr \".m.mg\" %f;\n", mg);

	}
	void setBlobMapB(float mb)
	{
		if(mb == 1.0) return;
		fprintf(mFile,"setAttr \".m.mb\" %f;\n", mb);

	}
	void setTranslucenceCoeff(float tc)
	{
		if(tc == 0.0) return;
		fprintf(mFile,"setAttr \".tc\" %f;\n", tc);

	}
	void setDiffuseCoeff(float dc)
	{
		if(dc == 0.0) return;
		fprintf(mFile,"setAttr \".dc\" %f;\n", dc);

	}
	void setSurfaceShadingShadow(bool sss)
	{
		if(sss == false) return;
		fprintf(mFile,"setAttr \".sss\" %i;\n", sss);

	}
	void setSurfaceColor(const float3& sc)
	{
		fprintf(mFile,"setAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSurfaceColorR(float scr)
	{
		if(scr == 0.4) return;
		fprintf(mFile,"setAttr \".sc.scr\" %f;\n", scr);

	}
	void setSurfaceColorG(float scg)
	{
		if(scg == 0.4) return;
		fprintf(mFile,"setAttr \".sc.scg\" %f;\n", scg);

	}
	void setSurfaceColorB(float scb)
	{
		if(scb == 0.4) return;
		fprintf(mFile,"setAttr \".sc.scb\" %f;\n", scb);

	}
	void setSolidCoreSize(float scs)
	{
		if(scs == 0.0) return;
		fprintf(mFile,"setAttr \".scs\" %f;\n", scs);

	}
	void setTranslucence(float trsl)
	{
		if(trsl == 0.5) return;
		fprintf(mFile,"setAttr \".trsl\" %f;\n", trsl);

	}
	void setNoiseAnimRate(float nanr)
	{
		if(nanr == 0.0) return;
		fprintf(mFile,"setAttr \".nanr\" %f;\n", nanr);

	}
	void setRoundness(float rdns)
	{
		if(rdns == 1.0) return;
		fprintf(mFile,"setAttr \".rdns\" %f;\n", rdns);

	}
	void setFilterRadius(float flrs)
	{
		if(flrs == 0.0) return;
		fprintf(mFile,"setAttr \".flrs\" %f;\n", flrs);

	}
	void setRenderState(int rdst)
	{
		if(rdst == 0) return;
		fprintf(mFile,"setAttr \".rdst\" %i;\n", rdst);

	}
	void getOutParticleEmission()
	{
		fprintf(mFile,"\"%s.oe\"",mName.c_str());

	}
	void getOutParticleEmissionR()
	{
		fprintf(mFile,"\"%s.oe.oer\"",mName.c_str());

	}
	void getOutParticleEmissionG()
	{
		fprintf(mFile,"\"%s.oe.oeg\"",mName.c_str());

	}
	void getOutParticleEmissionB()
	{
		fprintf(mFile,"\"%s.oe.oeb\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oi.oir\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oi.oig\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oi.oib\"",mName.c_str());

	}
	void getOutGlowColor()
	{
		fprintf(mFile,"\"%s.ogi\"",mName.c_str());

	}
	void getOutGlowColorR()
	{
		fprintf(mFile,"\"%s.ogi.ogr\"",mName.c_str());

	}
	void getOutGlowColorG()
	{
		fprintf(mFile,"\"%s.ogi.ogg\"",mName.c_str());

	}
	void getOutGlowColorB()
	{
		fprintf(mFile,"\"%s.ogi.ogb\"",mName.c_str());

	}
	void getOutTransparency()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getOutTransparencyR()
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());

	}
	void getOutTransparencyG()
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());

	}
	void getOutTransparencyB()
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());

	}
	void getColor()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getColorR()
	{
		fprintf(mFile,"\"%s.c.cr\"",mName.c_str());

	}
	void getColorG()
	{
		fprintf(mFile,"\"%s.c.cg\"",mName.c_str());

	}
	void getColorB()
	{
		fprintf(mFile,"\"%s.c.cb\"",mName.c_str());

	}
	void getTransparency()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getTransparencyR()
	{
		fprintf(mFile,"\"%s.t.tr\"",mName.c_str());

	}
	void getTransparencyG()
	{
		fprintf(mFile,"\"%s.t.tg\"",mName.c_str());

	}
	void getTransparencyB()
	{
		fprintf(mFile,"\"%s.t.tb\"",mName.c_str());

	}
	void getIncandescence()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getIncandescenceR()
	{
		fprintf(mFile,"\"%s.i.ir\"",mName.c_str());

	}
	void getIncandescenceG()
	{
		fprintf(mFile,"\"%s.i.ig\"",mName.c_str());

	}
	void getIncandescenceB()
	{
		fprintf(mFile,"\"%s.i.ib\"",mName.c_str());

	}
	void getDensity()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getGlowIntensity()
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());

	}
	void getNoise()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getNoiseFreq()
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());

	}
	void getNoiseAspect()
	{
		fprintf(mFile,"\"%s.na\"",mName.c_str());

	}
	void getParticleWeight()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getParticleEmission()
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());

	}
	void getParticleEmissionR()
	{
		fprintf(mFile,"\"%s.e.er\"",mName.c_str());

	}
	void getParticleEmissionG()
	{
		fprintf(mFile,"\"%s.e.eg\"",mName.c_str());

	}
	void getParticleEmissionB()
	{
		fprintf(mFile,"\"%s.e.eb\"",mName.c_str());

	}
	void getBlobMap()
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());

	}
	void getBlobMapR()
	{
		fprintf(mFile,"\"%s.m.mr\"",mName.c_str());

	}
	void getBlobMapG()
	{
		fprintf(mFile,"\"%s.m.mg\"",mName.c_str());

	}
	void getBlobMapB()
	{
		fprintf(mFile,"\"%s.m.mb\"",mName.c_str());

	}
	void getLightDataArray(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i]\"",mName.c_str(),ltd_i);

	}
	void getLightDirection(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld\"",mName.c_str(),ltd_i);

	}
	void getLightDirectionX(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldx\"",mName.c_str(),ltd_i);

	}
	void getLightDirectionY(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldy\"",mName.c_str(),ltd_i);

	}
	void getLightDirectionZ(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldz\"",mName.c_str(),ltd_i);

	}
	void getLightIntensity(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li\"",mName.c_str(),ltd_i);

	}
	void getLightIntensityR(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lir\"",mName.c_str(),ltd_i);

	}
	void getLightIntensityG(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lig\"",mName.c_str(),ltd_i);

	}
	void getLightIntensityB(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lib\"",mName.c_str(),ltd_i);

	}
	void getLightAmbient(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].la\"",mName.c_str(),ltd_i);

	}
	void getLightDiffuse(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ldf\"",mName.c_str(),ltd_i);

	}
	void getLightSpecular(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ls\"",mName.c_str(),ltd_i);

	}
	void getLightShadowFraction(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].lsf\"",mName.c_str(),ltd_i);

	}
	void getPreShadowIntensity(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].psi\"",mName.c_str(),ltd_i);

	}
	void getLightBlindData(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].lbd\"",mName.c_str(),ltd_i);

	}
	void getPointObj()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getPointObjX()
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());

	}
	void getPointObjY()
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());

	}
	void getPointObjZ()
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());

	}
	void getNormalCamera()
	{
		fprintf(mFile,"\"%s.nc\"",mName.c_str());

	}
	void getNormalCameraX()
	{
		fprintf(mFile,"\"%s.nc.ncx\"",mName.c_str());

	}
	void getNormalCameraY()
	{
		fprintf(mFile,"\"%s.nc.ncy\"",mName.c_str());

	}
	void getNormalCameraZ()
	{
		fprintf(mFile,"\"%s.nc.ncz\"",mName.c_str());

	}
	void getTranslucenceCoeff()
	{
		fprintf(mFile,"\"%s.tc\"",mName.c_str());

	}
	void getDiffuseCoeff()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getSurfaceShadingShadow()
	{
		fprintf(mFile,"\"%s.sss\"",mName.c_str());

	}
	void getSurfaceColor()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getSurfaceColorR()
	{
		fprintf(mFile,"\"%s.sc.scr\"",mName.c_str());

	}
	void getSurfaceColorG()
	{
		fprintf(mFile,"\"%s.sc.scg\"",mName.c_str());

	}
	void getSurfaceColorB()
	{
		fprintf(mFile,"\"%s.sc.scb\"",mName.c_str());

	}
	void getSolidCoreSize()
	{
		fprintf(mFile,"\"%s.scs\"",mName.c_str());

	}
	void getTranslucence()
	{
		fprintf(mFile,"\"%s.trsl\"",mName.c_str());

	}
	void getNoiseAnimRate()
	{
		fprintf(mFile,"\"%s.nanr\"",mName.c_str());

	}
	void getRoundness()
	{
		fprintf(mFile,"\"%s.rdns\"",mName.c_str());

	}
	void getRayDepth()
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());

	}
	void getParticleOrder()
	{
		fprintf(mFile,"\"%s.podr\"",mName.c_str());

	}
	void getFilterRadius()
	{
		fprintf(mFile,"\"%s.flrs\"",mName.c_str());

	}
protected:
	ParticleCloud(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLECLOUD_H__
