/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	ParticleCloud():DependNode(){}
	ParticleCloud(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "particleCloud", shared, create){}
	virtual ~ParticleCloud(){}

	void setColor(const float3& c)
	{
		fprintf(mFile,"\tsetAttr \".c\" -type \"float3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cr\" %f;\n", cr);
	}
	void setColorG(float cg)
	{
		if(cg == 0.58824) return;
		fprintf(mFile,"\tsetAttr \".c.cg\" %f;\n", cg);
	}
	void setColorB(float cb)
	{
		if(cb == 0.644) return;
		fprintf(mFile,"\tsetAttr \".c.cb\" %f;\n", cb);
	}
	void setTransparency(const float3& t)
	{
		fprintf(mFile,"\tsetAttr \".t\" -type \"float3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransparencyR(float tr)
	{
		if(tr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".t.tr\" %f;\n", tr);
	}
	void setTransparencyG(float tg)
	{
		if(tg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".t.tg\" %f;\n", tg);
	}
	void setTransparencyB(float tb)
	{
		if(tb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".t.tb\" %f;\n", tb);
	}
	void setIncandescence(const float3& i_)
	{
		fprintf(mFile,"\tsetAttr \".i\" -type \"float3\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIncandescenceR(float ir)
	{
		if(ir == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ir\" %f;\n", ir);
	}
	void setIncandescenceG(float ig)
	{
		if(ig == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ig\" %f;\n", ig);
	}
	void setIncandescenceB(float ib)
	{
		if(ib == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ib\" %f;\n", ib);
	}
	void setDensity(float d)
	{
		if(d == 1.0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setGlowIntensity(float gi)
	{
		if(gi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gi\" %f;\n", gi);
	}
	void setNoise(float n)
	{
		if(n == 0.75) return;
		fprintf(mFile,"\tsetAttr \".n\" %f;\n", n);
	}
	void setNoiseFreq(float nf)
	{
		if(nf == 0.15) return;
		fprintf(mFile,"\tsetAttr \".nf\" %f;\n", nf);
	}
	void setNoiseAspect(float na)
	{
		if(na == 0.0) return;
		fprintf(mFile,"\tsetAttr \".na\" %f;\n", na);
	}
	void setBlobMap(const float3& m)
	{
		fprintf(mFile,"\tsetAttr \".m\" -type \"float3\" ");
		m.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlobMapR(float mr)
	{
		if(mr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".m.mr\" %f;\n", mr);
	}
	void setBlobMapG(float mg)
	{
		if(mg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".m.mg\" %f;\n", mg);
	}
	void setBlobMapB(float mb)
	{
		if(mb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".m.mb\" %f;\n", mb);
	}
	void setTranslucenceCoeff(float tc)
	{
		if(tc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tc\" %f;\n", tc);
	}
	void setDiffuseCoeff(float dc)
	{
		if(dc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dc\" %f;\n", dc);
	}
	void setSurfaceShadingShadow(bool sss)
	{
		if(sss == false) return;
		fprintf(mFile,"\tsetAttr \".sss\" %i;\n", sss);
	}
	void setSurfaceColor(const float3& sc)
	{
		fprintf(mFile,"\tsetAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSurfaceColorR(float scr)
	{
		if(scr == 0.4) return;
		fprintf(mFile,"\tsetAttr \".sc.scr\" %f;\n", scr);
	}
	void setSurfaceColorG(float scg)
	{
		if(scg == 0.4) return;
		fprintf(mFile,"\tsetAttr \".sc.scg\" %f;\n", scg);
	}
	void setSurfaceColorB(float scb)
	{
		if(scb == 0.4) return;
		fprintf(mFile,"\tsetAttr \".sc.scb\" %f;\n", scb);
	}
	void setSolidCoreSize(float scs)
	{
		if(scs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scs\" %f;\n", scs);
	}
	void setTranslucence(float trsl)
	{
		if(trsl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".trsl\" %f;\n", trsl);
	}
	void setNoiseAnimRate(float nanr)
	{
		if(nanr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".nanr\" %f;\n", nanr);
	}
	void setRoundness(float rdns)
	{
		if(rdns == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rdns\" %f;\n", rdns);
	}
	void setFilterRadius(float flrs)
	{
		if(flrs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".flrs\" %f;\n", flrs);
	}
	void setRenderState(int rdst)
	{
		if(rdst == 0) return;
		fprintf(mFile,"\tsetAttr \".rdst\" %i;\n", rdst);
	}
	void getOutParticleEmission()const
	{
		fprintf(mFile,"\"%s.oe\"",mName.c_str());
	}
	void getOutParticleEmissionR()const
	{
		fprintf(mFile,"\"%s.oe.oer\"",mName.c_str());
	}
	void getOutParticleEmissionG()const
	{
		fprintf(mFile,"\"%s.oe.oeg\"",mName.c_str());
	}
	void getOutParticleEmissionB()const
	{
		fprintf(mFile,"\"%s.oe.oeb\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.oi.oir\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.oi.oig\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.oi.oib\"",mName.c_str());
	}
	void getOutGlowColor()const
	{
		fprintf(mFile,"\"%s.ogi\"",mName.c_str());
	}
	void getOutGlowColorR()const
	{
		fprintf(mFile,"\"%s.ogi.ogr\"",mName.c_str());
	}
	void getOutGlowColorG()const
	{
		fprintf(mFile,"\"%s.ogi.ogg\"",mName.c_str());
	}
	void getOutGlowColorB()const
	{
		fprintf(mFile,"\"%s.ogi.ogb\"",mName.c_str());
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
	void getColor()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getColorR()const
	{
		fprintf(mFile,"\"%s.c.cr\"",mName.c_str());
	}
	void getColorG()const
	{
		fprintf(mFile,"\"%s.c.cg\"",mName.c_str());
	}
	void getColorB()const
	{
		fprintf(mFile,"\"%s.c.cb\"",mName.c_str());
	}
	void getTransparency()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getTransparencyR()const
	{
		fprintf(mFile,"\"%s.t.tr\"",mName.c_str());
	}
	void getTransparencyG()const
	{
		fprintf(mFile,"\"%s.t.tg\"",mName.c_str());
	}
	void getTransparencyB()const
	{
		fprintf(mFile,"\"%s.t.tb\"",mName.c_str());
	}
	void getIncandescence()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getIncandescenceR()const
	{
		fprintf(mFile,"\"%s.i.ir\"",mName.c_str());
	}
	void getIncandescenceG()const
	{
		fprintf(mFile,"\"%s.i.ig\"",mName.c_str());
	}
	void getIncandescenceB()const
	{
		fprintf(mFile,"\"%s.i.ib\"",mName.c_str());
	}
	void getDensity()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getGlowIntensity()const
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());
	}
	void getNoise()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNoiseFreq()const
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());
	}
	void getNoiseAspect()const
	{
		fprintf(mFile,"\"%s.na\"",mName.c_str());
	}
	void getParticleWeight()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getParticleEmission()const
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());
	}
	void getParticleEmissionR()const
	{
		fprintf(mFile,"\"%s.e.er\"",mName.c_str());
	}
	void getParticleEmissionG()const
	{
		fprintf(mFile,"\"%s.e.eg\"",mName.c_str());
	}
	void getParticleEmissionB()const
	{
		fprintf(mFile,"\"%s.e.eb\"",mName.c_str());
	}
	void getBlobMap()const
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getBlobMapR()const
	{
		fprintf(mFile,"\"%s.m.mr\"",mName.c_str());
	}
	void getBlobMapG()const
	{
		fprintf(mFile,"\"%s.m.mg\"",mName.c_str());
	}
	void getBlobMapB()const
	{
		fprintf(mFile,"\"%s.m.mb\"",mName.c_str());
	}
	void getLightDataArray(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i]\"",mName.c_str(),ltd_i);
	}
	void getLightDataArray()const
	{

		fprintf(mFile,"\"%s.ltd\"",mName.c_str());
	}
	void getLightDirection(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld\"",mName.c_str(),ltd_i);
	}
	void getLightDirection()const
	{

		fprintf(mFile,"\"%s.ltd.ld\"",mName.c_str());
	}
	void getLightDirectionX(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldx\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionX()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldx\"",mName.c_str());
	}
	void getLightDirectionY(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldy\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionY()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldy\"",mName.c_str());
	}
	void getLightDirectionZ(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldz\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionZ()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldz\"",mName.c_str());
	}
	void getLightIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li\"",mName.c_str(),ltd_i);
	}
	void getLightIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.li\"",mName.c_str());
	}
	void getLightIntensityR(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lir\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityR()const
	{

		fprintf(mFile,"\"%s.ltd.li.lir\"",mName.c_str());
	}
	void getLightIntensityG(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lig\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityG()const
	{

		fprintf(mFile,"\"%s.ltd.li.lig\"",mName.c_str());
	}
	void getLightIntensityB(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lib\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityB()const
	{

		fprintf(mFile,"\"%s.ltd.li.lib\"",mName.c_str());
	}
	void getLightAmbient(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].la\"",mName.c_str(),ltd_i);
	}
	void getLightAmbient()const
	{

		fprintf(mFile,"\"%s.ltd.la\"",mName.c_str());
	}
	void getLightDiffuse(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ldf\"",mName.c_str(),ltd_i);
	}
	void getLightDiffuse()const
	{

		fprintf(mFile,"\"%s.ltd.ldf\"",mName.c_str());
	}
	void getLightSpecular(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ls\"",mName.c_str(),ltd_i);
	}
	void getLightSpecular()const
	{

		fprintf(mFile,"\"%s.ltd.ls\"",mName.c_str());
	}
	void getLightShadowFraction(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lsf\"",mName.c_str(),ltd_i);
	}
	void getLightShadowFraction()const
	{

		fprintf(mFile,"\"%s.ltd.lsf\"",mName.c_str());
	}
	void getPreShadowIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].psi\"",mName.c_str(),ltd_i);
	}
	void getPreShadowIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.psi\"",mName.c_str());
	}
	void getLightBlindData(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lbd\"",mName.c_str(),ltd_i);
	}
	void getLightBlindData()const
	{

		fprintf(mFile,"\"%s.ltd.lbd\"",mName.c_str());
	}
	void getPointObj()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPointObjX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPointObjY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPointObjZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getNormalCamera()const
	{
		fprintf(mFile,"\"%s.nc\"",mName.c_str());
	}
	void getNormalCameraX()const
	{
		fprintf(mFile,"\"%s.nc.ncx\"",mName.c_str());
	}
	void getNormalCameraY()const
	{
		fprintf(mFile,"\"%s.nc.ncy\"",mName.c_str());
	}
	void getNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.nc.ncz\"",mName.c_str());
	}
	void getTranslucenceCoeff()const
	{
		fprintf(mFile,"\"%s.tc\"",mName.c_str());
	}
	void getDiffuseCoeff()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getSurfaceShadingShadow()const
	{
		fprintf(mFile,"\"%s.sss\"",mName.c_str());
	}
	void getSurfaceColor()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getSurfaceColorR()const
	{
		fprintf(mFile,"\"%s.sc.scr\"",mName.c_str());
	}
	void getSurfaceColorG()const
	{
		fprintf(mFile,"\"%s.sc.scg\"",mName.c_str());
	}
	void getSurfaceColorB()const
	{
		fprintf(mFile,"\"%s.sc.scb\"",mName.c_str());
	}
	void getSolidCoreSize()const
	{
		fprintf(mFile,"\"%s.scs\"",mName.c_str());
	}
	void getTranslucence()const
	{
		fprintf(mFile,"\"%s.trsl\"",mName.c_str());
	}
	void getNoiseAnimRate()const
	{
		fprintf(mFile,"\"%s.nanr\"",mName.c_str());
	}
	void getRoundness()const
	{
		fprintf(mFile,"\"%s.rdns\"",mName.c_str());
	}
	void getRayDepth()const
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());
	}
	void getParticleOrder()const
	{
		fprintf(mFile,"\"%s.podr\"",mName.c_str());
	}
	void getFilterRadius()const
	{
		fprintf(mFile,"\"%s.flrs\"",mName.c_str());
	}
	void getRenderState()const
	{
		fprintf(mFile,"\"%s.rdst\"",mName.c_str());
	}
protected:
	ParticleCloud(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLECLOUD_H__
