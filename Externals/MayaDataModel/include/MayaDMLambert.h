/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LAMBERT_H__
#define __MayaDM_LAMBERT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Lambert : public DependNode
{
public:
public:

	Lambert():DependNode(){}
	Lambert(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "lambert", shared, create){}
	virtual ~Lambert(){}

	void setRefractionLimit(short rdl)
	{
		if(rdl == 6) return;
		fprintf(mFile,"\tsetAttr \".rdl\" %i;\n", rdl);
	}
	void setRefractiveIndex(float rfi)
	{
		if(rfi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rfi\" %f;\n", rfi);
	}
	void setRefractions(bool rfc)
	{
		if(rfc == false) return;
		fprintf(mFile,"\tsetAttr \".rfc\" %i;\n", rfc);
	}
	void setDiffuse(float dc)
	{
		if(dc == 0.8) return;
		fprintf(mFile,"\tsetAttr \".dc\" %f;\n", dc);
	}
	void setColor(const float3& c)
	{
		fprintf(mFile,"\tsetAttr \".c\" -type \"float3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(float cr)
	{
		if(cr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".c.cr\" %f;\n", cr);
	}
	void setColorG(float cg)
	{
		if(cg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".c.cg\" %f;\n", cg);
	}
	void setColorB(float cb)
	{
		if(cb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".c.cb\" %f;\n", cb);
	}
	void setTransparency(const float3& it)
	{
		fprintf(mFile,"\tsetAttr \".it\" -type \"float3\" ");
		it.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransparencyR(float itr)
	{
		if(itr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it.itr\" %f;\n", itr);
	}
	void setTransparencyG(float itg)
	{
		if(itg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it.itg\" %f;\n", itg);
	}
	void setTransparencyB(float itb)
	{
		if(itb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it.itb\" %f;\n", itb);
	}
	void setAmbientColor(const float3& ambc)
	{
		fprintf(mFile,"\tsetAttr \".ambc\" -type \"float3\" ");
		ambc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAmbientColorR(float acr)
	{
		if(acr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ambc.acr\" %f;\n", acr);
	}
	void setAmbientColorG(float acg)
	{
		if(acg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ambc.acg\" %f;\n", acg);
	}
	void setAmbientColorB(float acb)
	{
		if(acb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ambc.acb\" %f;\n", acb);
	}
	void setIncandescence(const float3& ic)
	{
		fprintf(mFile,"\tsetAttr \".ic\" -type \"float3\" ");
		ic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIncandescenceR(float ir)
	{
		if(ir == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic.ir\" %f;\n", ir);
	}
	void setIncandescenceG(float ig)
	{
		if(ig == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic.ig\" %f;\n", ig);
	}
	void setIncandescenceB(float ib)
	{
		if(ib == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic.ib\" %f;\n", ib);
	}
	void setTranslucence(float tc)
	{
		if(tc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tc\" %f;\n", tc);
	}
	void setTranslucenceFocus(float tcf)
	{
		if(tcf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tcf\" %f;\n", tcf);
	}
	void setTranslucenceDepth(float trsd)
	{
		if(trsd == 0.5) return;
		fprintf(mFile,"\tsetAttr \".trsd\" %f;\n", trsd);
	}
	void setOpacityDepth(float opad)
	{
		if(opad == 0.0) return;
		fprintf(mFile,"\tsetAttr \".opad\" %f;\n", opad);
	}
	void setGlowIntensity(float gi)
	{
		if(gi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gi\" %f;\n", gi);
	}
	void setVrOverwriteDefaults(bool vrod)
	{
		if(vrod == 0) return;
		fprintf(mFile,"\tsetAttr \".vrod\" %i;\n", vrod);
	}
	void setVrFillObject(unsigned int vrfo)
	{
		if(vrfo == 0) return;
		fprintf(mFile,"\tsetAttr \".vrfo\" %i;\n", vrfo);
	}
	void setVrEdgeWeight(double vrew)
	{
		if(vrew == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vrew\" %f;\n", vrew);
	}
	void setVrEdgeColor(const float3& vrec)
	{
		fprintf(mFile,"\tsetAttr \".vrec\" -type \"float3\" ");
		vrec.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVrEdgeColorR(float vecr)
	{
		if(vecr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".vrec.vecr\" %f;\n", vecr);
	}
	void setVrEdgeColorG(float vecg)
	{
		if(vecg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".vrec.vecg\" %f;\n", vecg);
	}
	void setVrEdgeColorB(float vecb)
	{
		if(vecb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".vrec.vecb\" %f;\n", vecb);
	}
	void setVrEdgeStyle(unsigned int vres)
	{
		if(vres == 0) return;
		fprintf(mFile,"\tsetAttr \".vres\" %i;\n", vres);
	}
	void setVrEdgePriority(int vrep)
	{
		if(vrep == 0) return;
		fprintf(mFile,"\tsetAttr \".vrep\" %i;\n", vrep);
	}
	void setVrHiddenEdges(bool vrhe)
	{
		if(vrhe == 0) return;
		fprintf(mFile,"\tsetAttr \".vrhe\" %i;\n", vrhe);
	}
	void setVrHiddenEdgesOnTransparent(bool vrht)
	{
		if(vrht == 0) return;
		fprintf(mFile,"\tsetAttr \".vrht\" %i;\n", vrht);
	}
	void setVrOutlinesAtIntersections(bool vroi)
	{
		if(vroi == 1) return;
		fprintf(mFile,"\tsetAttr \".vroi\" %i;\n", vroi);
	}
	void setMaterialAlphaGain(float maga)
	{
		if(maga == 1.0) return;
		fprintf(mFile,"\tsetAttr \".maga\" %f;\n", maga);
	}
	void setHideSource(bool hs)
	{
		if(hs == false) return;
		fprintf(mFile,"\tsetAttr \".hs\" %i;\n", hs);
	}
	void setSurfaceThickness(float thik)
	{
		if(thik == 0.0) return;
		fprintf(mFile,"\tsetAttr \".thik\" %f;\n", thik);
	}
	void setShadowAttenuation(float fakc)
	{
		if(fakc == 0.5) return;
		fprintf(mFile,"\tsetAttr \".fakc\" %f;\n", fakc);
	}
	void setTransparencyDepth(float trdp)
	{
		if(trdp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".trdp\" %f;\n", trdp);
	}
	void setLightAbsorbance(float absb)
	{
		if(absb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".absb\" %f;\n", absb);
	}
	void setChromaticAberration(bool crab)
	{
		if(crab == false) return;
		fprintf(mFile,"\tsetAttr \".crab\" %i;\n", crab);
	}
	void setMatteOpacityMode(unsigned int mom)
	{
		if(mom == 2) return;
		fprintf(mFile,"\tsetAttr \".mom\" %i;\n", mom);
	}
	void setMatteOpacity(float mog)
	{
		if(mog == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mog\" %f;\n", mog);
	}
	void setMiRefractionBlur(float mirfb)
	{
		if(mirfb == 0) return;
		fprintf(mFile,"\tsetAttr \".mirfb\" %f;\n", mirfb);
	}
	void setMiRefractionRays(short mirfr)
	{
		if(mirfr == 1) return;
		fprintf(mFile,"\tsetAttr \".mirfr\" %i;\n", mirfr);
	}
	void setMiIrradiance(const float3& mii)
	{
		fprintf(mFile,"\tsetAttr \".mii\" -type \"float3\" ");
		mii.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiIrradianceR(float miir)
	{
		if(miir == 0) return;
		fprintf(mFile,"\tsetAttr \".mii.miir\" %f;\n", miir);
	}
	void setMiIrradianceG(float miig)
	{
		if(miig == 0) return;
		fprintf(mFile,"\tsetAttr \".mii.miig\" %f;\n", miig);
	}
	void setMiIrradianceB(float miib)
	{
		if(miib == 0) return;
		fprintf(mFile,"\tsetAttr \".mii.miib\" %f;\n", miib);
	}
	void setMiIrradianceColor(const float3& miic)
	{
		fprintf(mFile,"\tsetAttr \".miic\" -type \"float3\" ");
		miic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiIrradianceColorR(float miicr)
	{
		if(miicr == 1) return;
		fprintf(mFile,"\tsetAttr \".miic.miicr\" %f;\n", miicr);
	}
	void setMiIrradianceColorG(float miicg)
	{
		if(miicg == 1) return;
		fprintf(mFile,"\tsetAttr \".miic.miicg\" %f;\n", miicg);
	}
	void setMiIrradianceColorB(float miicb)
	{
		if(miicb == 1) return;
		fprintf(mFile,"\tsetAttr \".miic.miicb\" %f;\n", miicb);
	}
	void setMiDeriveFromMaya(bool mifm)
	{
		if(mifm == true) return;
		fprintf(mFile,"\tsetAttr \".mifm\" %i;\n", mifm);
	}
	void setMiRefractiveIndex(float miri)
	{
		if(miri == 1) return;
		fprintf(mFile,"\tsetAttr \".miri\" %f;\n", miri);
	}
	void setMiRefractions(bool mirc)
	{
		if(mirc == true) return;
		fprintf(mFile,"\tsetAttr \".mirc\" %i;\n", mirc);
	}
	void setMiAbsorbs(bool miab)
	{
		if(miab == true) return;
		fprintf(mFile,"\tsetAttr \".miab\" %i;\n", miab);
	}
	void setMiDiffuse(float midc)
	{
		if(midc == 0.8) return;
		fprintf(mFile,"\tsetAttr \".midc\" %f;\n", midc);
	}
	void setMiColor(const float3& mic)
	{
		fprintf(mFile,"\tsetAttr \".mic\" -type \"float3\" ");
		mic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiColorR(float micr)
	{
		if(micr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micr\" %f;\n", micr);
	}
	void setMiColorG(float micg)
	{
		if(micg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micg\" %f;\n", micg);
	}
	void setMiColorB(float micb)
	{
		if(micb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micb\" %f;\n", micb);
	}
	void setMiTransparency(const float3& mit)
	{
		fprintf(mFile,"\tsetAttr \".mit\" -type \"float3\" ");
		mit.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiTransparencyR(float mitr)
	{
		if(mitr == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitr\" %f;\n", mitr);
	}
	void setMiTransparencyG(float mitg)
	{
		if(mitg == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitg\" %f;\n", mitg);
	}
	void setMiTransparencyB(float mitb)
	{
		if(mitb == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitb\" %f;\n", mitb);
	}
	void setMiTranslucence(float mitc)
	{
		if(mitc == 0) return;
		fprintf(mFile,"\tsetAttr \".mitc\" %f;\n", mitc);
	}
	void setMiTranslucenceFocus(float mitf)
	{
		if(mitf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mitf\" %f;\n", mitf);
	}
	void setMiNormalCamera(const float3& minc)
	{
		fprintf(mFile,"\tsetAttr \".minc\" -type \"float3\" ");
		minc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiNormalCameraX(float mincx)
	{
		if(mincx == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincx\" %f;\n", mincx);
	}
	void setMiNormalCameraY(float mincy)
	{
		if(mincy == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincy\" %f;\n", mincy);
	}
	void setMiNormalCameraZ(float mincz)
	{
		if(mincz == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincz\" %f;\n", mincz);
	}
	void getObjectId()const
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());
	}
	void getPrimitiveId()const
	{
		fprintf(mFile,"\"%s.pi\"",mName.c_str());
	}
	void getRaySampler()const
	{
		fprintf(mFile,"\"%s.rtr\"",mName.c_str());
	}
	void getRayDepth()const
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());
	}
	void getRayInstance()const
	{
		fprintf(mFile,"\"%s.ryi\"",mName.c_str());
	}
	void getRefractionLimit()const
	{
		fprintf(mFile,"\"%s.rdl\"",mName.c_str());
	}
	void getRefractiveIndex()const
	{
		fprintf(mFile,"\"%s.rfi\"",mName.c_str());
	}
	void getMediumRefractiveIndex()const
	{
		fprintf(mFile,"\"%s.mrfi\"",mName.c_str());
	}
	void getRefractions()const
	{
		fprintf(mFile,"\"%s.rfc\"",mName.c_str());
	}
	void getDiffuse()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getRayDirection()const
	{
		fprintf(mFile,"\"%s.rad\"",mName.c_str());
	}
	void getRayDirectionX()const
	{
		fprintf(mFile,"\"%s.rad.rdx\"",mName.c_str());
	}
	void getRayDirectionY()const
	{
		fprintf(mFile,"\"%s.rad.rdy\"",mName.c_str());
	}
	void getRayDirectionZ()const
	{
		fprintf(mFile,"\"%s.rad.rdz\"",mName.c_str());
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
		fprintf(mFile,"\"%s.it\"",mName.c_str());
	}
	void getTransparencyR()const
	{
		fprintf(mFile,"\"%s.it.itr\"",mName.c_str());
	}
	void getTransparencyG()const
	{
		fprintf(mFile,"\"%s.it.itg\"",mName.c_str());
	}
	void getTransparencyB()const
	{
		fprintf(mFile,"\"%s.it.itb\"",mName.c_str());
	}
	void getAmbientColor()const
	{
		fprintf(mFile,"\"%s.ambc\"",mName.c_str());
	}
	void getAmbientColorR()const
	{
		fprintf(mFile,"\"%s.ambc.acr\"",mName.c_str());
	}
	void getAmbientColorG()const
	{
		fprintf(mFile,"\"%s.ambc.acg\"",mName.c_str());
	}
	void getAmbientColorB()const
	{
		fprintf(mFile,"\"%s.ambc.acb\"",mName.c_str());
	}
	void getIncandescence()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getIncandescenceR()const
	{
		fprintf(mFile,"\"%s.ic.ir\"",mName.c_str());
	}
	void getIncandescenceG()const
	{
		fprintf(mFile,"\"%s.ic.ig\"",mName.c_str());
	}
	void getIncandescenceB()const
	{
		fprintf(mFile,"\"%s.ic.ib\"",mName.c_str());
	}
	void getTranslucence()const
	{
		fprintf(mFile,"\"%s.tc\"",mName.c_str());
	}
	void getTranslucenceFocus()const
	{
		fprintf(mFile,"\"%s.tcf\"",mName.c_str());
	}
	void getTranslucenceDepth()const
	{
		fprintf(mFile,"\"%s.trsd\"",mName.c_str());
	}
	void getOpacityDepth()const
	{
		fprintf(mFile,"\"%s.opad\"",mName.c_str());
	}
	void getGlowIntensity()const
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());
	}
	void getVrOverwriteDefaults()const
	{
		fprintf(mFile,"\"%s.vrod\"",mName.c_str());
	}
	void getVrFillObject()const
	{
		fprintf(mFile,"\"%s.vrfo\"",mName.c_str());
	}
	void getVrEdgeWeight()const
	{
		fprintf(mFile,"\"%s.vrew\"",mName.c_str());
	}
	void getVrEdgeColor()const
	{
		fprintf(mFile,"\"%s.vrec\"",mName.c_str());
	}
	void getVrEdgeColorR()const
	{
		fprintf(mFile,"\"%s.vrec.vecr\"",mName.c_str());
	}
	void getVrEdgeColorG()const
	{
		fprintf(mFile,"\"%s.vrec.vecg\"",mName.c_str());
	}
	void getVrEdgeColorB()const
	{
		fprintf(mFile,"\"%s.vrec.vecb\"",mName.c_str());
	}
	void getVrEdgeStyle()const
	{
		fprintf(mFile,"\"%s.vres\"",mName.c_str());
	}
	void getVrEdgePriority()const
	{
		fprintf(mFile,"\"%s.vrep\"",mName.c_str());
	}
	void getVrHiddenEdges()const
	{
		fprintf(mFile,"\"%s.vrhe\"",mName.c_str());
	}
	void getVrHiddenEdgesOnTransparent()const
	{
		fprintf(mFile,"\"%s.vrht\"",mName.c_str());
	}
	void getVrOutlinesAtIntersections()const
	{
		fprintf(mFile,"\"%s.vroi\"",mName.c_str());
	}
	void getMaterialAlphaGain()const
	{
		fprintf(mFile,"\"%s.maga\"",mName.c_str());
	}
	void getHideSource()const
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());
	}
	void getSurfaceThickness()const
	{
		fprintf(mFile,"\"%s.thik\"",mName.c_str());
	}
	void getShadowAttenuation()const
	{
		fprintf(mFile,"\"%s.fakc\"",mName.c_str());
	}
	void getTransparencyDepth()const
	{
		fprintf(mFile,"\"%s.trdp\"",mName.c_str());
	}
	void getLightAbsorbance()const
	{
		fprintf(mFile,"\"%s.absb\"",mName.c_str());
	}
	void getChromaticAberration()const
	{
		fprintf(mFile,"\"%s.crab\"",mName.c_str());
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
	void getOutGlowColor()const
	{
		fprintf(mFile,"\"%s.ogc\"",mName.c_str());
	}
	void getOutGlowColorR()const
	{
		fprintf(mFile,"\"%s.ogc.ogr\"",mName.c_str());
	}
	void getOutGlowColorG()const
	{
		fprintf(mFile,"\"%s.ogc.ogg\"",mName.c_str());
	}
	void getOutGlowColorB()const
	{
		fprintf(mFile,"\"%s.ogc.ogb\"",mName.c_str());
	}
	void getPointCamera()const
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getPointCameraX()const
	{
		fprintf(mFile,"\"%s.pc.px\"",mName.c_str());
	}
	void getPointCameraY()const
	{
		fprintf(mFile,"\"%s.pc.py\"",mName.c_str());
	}
	void getPointCameraZ()const
	{
		fprintf(mFile,"\"%s.pc.pz\"",mName.c_str());
	}
	void getNormalCamera()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNormalCameraX()const
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());
	}
	void getNormalCameraY()const
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());
	}
	void getNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());
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
	void getMatteOpacityMode()const
	{
		fprintf(mFile,"\"%s.mom\"",mName.c_str());
	}
	void getMatteOpacity()const
	{
		fprintf(mFile,"\"%s.mog\"",mName.c_str());
	}
	void getOutMatteOpacity()const
	{
		fprintf(mFile,"\"%s.omo\"",mName.c_str());
	}
	void getOutMatteOpacityR()const
	{
		fprintf(mFile,"\"%s.omo.omor\"",mName.c_str());
	}
	void getOutMatteOpacityG()const
	{
		fprintf(mFile,"\"%s.omo.omog\"",mName.c_str());
	}
	void getOutMatteOpacityB()const
	{
		fprintf(mFile,"\"%s.omo.omob\"",mName.c_str());
	}
	void getHardwareShader()const
	{
		fprintf(mFile,"\"%s.hws\"",mName.c_str());
	}
	void getHardwareShaderR()const
	{
		fprintf(mFile,"\"%s.hws.hwr\"",mName.c_str());
	}
	void getHardwareShaderG()const
	{
		fprintf(mFile,"\"%s.hws.hwg\"",mName.c_str());
	}
	void getHardwareShaderB()const
	{
		fprintf(mFile,"\"%s.hws.hwb\"",mName.c_str());
	}
	void getMiRefractionBlur()const
	{
		fprintf(mFile,"\"%s.mirfb\"",mName.c_str());
	}
	void getMiRefractionRays()const
	{
		fprintf(mFile,"\"%s.mirfr\"",mName.c_str());
	}
	void getMiIrradiance()const
	{
		fprintf(mFile,"\"%s.mii\"",mName.c_str());
	}
	void getMiIrradianceR()const
	{
		fprintf(mFile,"\"%s.mii.miir\"",mName.c_str());
	}
	void getMiIrradianceG()const
	{
		fprintf(mFile,"\"%s.mii.miig\"",mName.c_str());
	}
	void getMiIrradianceB()const
	{
		fprintf(mFile,"\"%s.mii.miib\"",mName.c_str());
	}
	void getMiIrradianceColor()const
	{
		fprintf(mFile,"\"%s.miic\"",mName.c_str());
	}
	void getMiIrradianceColorR()const
	{
		fprintf(mFile,"\"%s.miic.miicr\"",mName.c_str());
	}
	void getMiIrradianceColorG()const
	{
		fprintf(mFile,"\"%s.miic.miicg\"",mName.c_str());
	}
	void getMiIrradianceColorB()const
	{
		fprintf(mFile,"\"%s.miic.miicb\"",mName.c_str());
	}
	void getMiDeriveFromMaya()const
	{
		fprintf(mFile,"\"%s.mifm\"",mName.c_str());
	}
	void getMiRefractiveIndex()const
	{
		fprintf(mFile,"\"%s.miri\"",mName.c_str());
	}
	void getMiRefractions()const
	{
		fprintf(mFile,"\"%s.mirc\"",mName.c_str());
	}
	void getMiAbsorbs()const
	{
		fprintf(mFile,"\"%s.miab\"",mName.c_str());
	}
	void getMiDiffuse()const
	{
		fprintf(mFile,"\"%s.midc\"",mName.c_str());
	}
	void getMiColor()const
	{
		fprintf(mFile,"\"%s.mic\"",mName.c_str());
	}
	void getMiColorR()const
	{
		fprintf(mFile,"\"%s.mic.micr\"",mName.c_str());
	}
	void getMiColorG()const
	{
		fprintf(mFile,"\"%s.mic.micg\"",mName.c_str());
	}
	void getMiColorB()const
	{
		fprintf(mFile,"\"%s.mic.micb\"",mName.c_str());
	}
	void getMiTransparency()const
	{
		fprintf(mFile,"\"%s.mit\"",mName.c_str());
	}
	void getMiTransparencyR()const
	{
		fprintf(mFile,"\"%s.mit.mitr\"",mName.c_str());
	}
	void getMiTransparencyG()const
	{
		fprintf(mFile,"\"%s.mit.mitg\"",mName.c_str());
	}
	void getMiTransparencyB()const
	{
		fprintf(mFile,"\"%s.mit.mitb\"",mName.c_str());
	}
	void getMiTranslucence()const
	{
		fprintf(mFile,"\"%s.mitc\"",mName.c_str());
	}
	void getMiTranslucenceFocus()const
	{
		fprintf(mFile,"\"%s.mitf\"",mName.c_str());
	}
	void getMiNormalCamera()const
	{
		fprintf(mFile,"\"%s.minc\"",mName.c_str());
	}
	void getMiNormalCameraX()const
	{
		fprintf(mFile,"\"%s.minc.mincx\"",mName.c_str());
	}
	void getMiNormalCameraY()const
	{
		fprintf(mFile,"\"%s.minc.mincy\"",mName.c_str());
	}
	void getMiNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.minc.mincz\"",mName.c_str());
	}
protected:
	Lambert(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LAMBERT_H__
