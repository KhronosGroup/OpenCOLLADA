/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MENTALRAYIBLSHAPE_H__
#define __MayaDM_MENTALRAYIBLSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
namespace MayaDM
{
class MentalrayIblShape
{
public:
public:
protected:
	FILE* mFile;
	std::string mName;
	std::string mParent;
	std::string mNodeType;
	bool mShared;
public:
	const std::string& getName()const
	{
		return mName;
	}
	const std::string& getParent()const
	{
		return mParent;
	}
	bool getShared()const
	{
		return mShared;
	}
	const std::string& getType()const
	{
		return mNodeType;
	}
	void setFile(FILE* file)
	{
		mFile = file;
	}
	void setName(const std::string& name)
	{
		mName = name;
	}
	void setParent(const std::string& parent)
	{
		mParent = parent;
	}
	void setShared(bool shared)
	{
		mShared = shared;
	}
public:

	MentalrayIblShape(){}
	virtual ~MentalrayIblShape(){}

	void setMapping(unsigned int map)
	{
		if(map == 0) return;
		fprintf(mFile,"\tsetAttr \".map\" %i;\n", map);
	}
	void setType(unsigned int typ)
	{
		if(typ == 0) return;
		fprintf(mFile,"\tsetAttr \".typ\" %i;\n", typ);
	}
	void setTexture(const string& tx)
	{
		if(tx == "NULL") return;
		fprintf(mFile,"\tsetAttr \".tx\" -type \"string\" ");
		tx.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUseFrameExtension(bool ufe)
	{
		if(ufe == false) return;
		fprintf(mFile,"\tsetAttr \".ufe\" %i;\n", ufe);
	}
	void setFrameExtension(int fe)
	{
		if(fe == 1) return;
		fprintf(mFile,"\tsetAttr \".fe\" %i;\n", fe);
	}
	void setColor(const float3& col)
	{
		if(col == float3(0,0,0)) return;
		fprintf(mFile,"\tsetAttr \".col\" -type \"float3\" ");
		col.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(float colr)
	{
		if(colr == 0) return;
		fprintf(mFile,"\tsetAttr \".col.colr\" %f;\n", colr);
	}
	void setColorG(float colg)
	{
		if(colg == 0) return;
		fprintf(mFile,"\tsetAttr \".col.colg\" %f;\n", colg);
	}
	void setColorB(float colb)
	{
		if(colb == 0) return;
		fprintf(mFile,"\tsetAttr \".col.colb\" %f;\n", colb);
	}
	void setHardwareFilter(unsigned int hwf)
	{
		if(hwf == 0) return;
		fprintf(mFile,"\tsetAttr \".hwf\" %i;\n", hwf);
	}
	void setHardwareAlpha(float hwt)
	{
		if(hwt == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hwt\" %f;\n", hwt);
	}
	void setColorGain(const float3& cg)
	{
		if(cg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".cg\" -type \"float3\" ");
		cg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorGainR(float cgr)
	{
		if(cgr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cg.cgr\" %f;\n", cgr);
	}
	void setColorGainG(float cgg)
	{
		if(cgg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cg.cgg\" %f;\n", cgg);
	}
	void setColorGainB(float cgb)
	{
		if(cgb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cg.cgb\" %f;\n", cgb);
	}
	void setColorOffset(const float3& cof)
	{
		if(cof == float3(0,0,0)) return;
		fprintf(mFile,"\tsetAttr \".cof\" -type \"float3\" ");
		cof.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorOffsetR(float cofr)
	{
		if(cofr == 0) return;
		fprintf(mFile,"\tsetAttr \".cof.cofr\" %f;\n", cofr);
	}
	void setColorOffsetG(float cofg)
	{
		if(cofg == 0) return;
		fprintf(mFile,"\tsetAttr \".cof.cofg\" %f;\n", cofg);
	}
	void setColorOffsetB(float cofb)
	{
		if(cofb == 0) return;
		fprintf(mFile,"\tsetAttr \".cof.cofb\" %f;\n", cofb);
	}
	void setInvert(bool inv)
	{
		if(inv == false) return;
		fprintf(mFile,"\tsetAttr \".inv\" %i;\n", inv);
	}
	void setAlphaIsLuminance(bool ail)
	{
		if(ail == false) return;
		fprintf(mFile,"\tsetAttr \".ail\" %i;\n", ail);
	}
	void setPrimaryVisibility(bool vis)
	{
		if(vis == true) return;
		fprintf(mFile,"\tsetAttr \".vis\" %i;\n", vis);
	}
	void setVisibleInEnvironment(bool vien)
	{
		if(vien == false) return;
		fprintf(mFile,"\tsetAttr \".vien\" %i;\n", vien);
	}
	void setVisibleInReflections(bool vir)
	{
		if(vir == false) return;
		fprintf(mFile,"\tsetAttr \".vir\" %i;\n", vir);
	}
	void setVisibleInRefractions(bool vif)
	{
		if(vif == false) return;
		fprintf(mFile,"\tsetAttr \".vif\" %i;\n", vif);
	}
	void setVisibleInFinalGather(bool vifg)
	{
		if(vifg == false) return;
		fprintf(mFile,"\tsetAttr \".vifg\" %i;\n", vifg);
	}
	void setOverrideEnvColorFx(bool oefx)
	{
		if(oefx == false) return;
		fprintf(mFile,"\tsetAttr \".oefx\" %i;\n", oefx);
	}
	void setEnvInvert(bool einv)
	{
		if(einv == false) return;
		fprintf(mFile,"\tsetAttr \".einv\" %i;\n", einv);
	}
	void setEnvColorGain(const float3& ecg)
	{
		if(ecg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".ecg\" -type \"float3\" ");
		ecg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEnvColorGainR(float ecgr)
	{
		if(ecgr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ecg.ecgr\" %f;\n", ecgr);
	}
	void setEnvColorGainG(float ecgg)
	{
		if(ecgg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ecg.ecgg\" %f;\n", ecgg);
	}
	void setEnvColorGainB(float ecgb)
	{
		if(ecgb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ecg.ecgb\" %f;\n", ecgb);
	}
	void setEnvColorOffset(const float3& eco)
	{
		if(eco == float3(0,0,0)) return;
		fprintf(mFile,"\tsetAttr \".eco\" -type \"float3\" ");
		eco.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEnvColorOffsetR(float ecor)
	{
		if(ecor == 0) return;
		fprintf(mFile,"\tsetAttr \".eco.ecor\" %f;\n", ecor);
	}
	void setEnvColorOffsetG(float ecog)
	{
		if(ecog == 0) return;
		fprintf(mFile,"\tsetAttr \".eco.ecog\" %f;\n", ecog);
	}
	void setEnvColorOffsetB(float ecorb)
	{
		if(ecorb == 0) return;
		fprintf(mFile,"\tsetAttr \".eco.ecorb\" %f;\n", ecorb);
	}
	void setOverrideFgColorFx(bool offx)
	{
		if(offx == false) return;
		fprintf(mFile,"\tsetAttr \".offx\" %i;\n", offx);
	}
	void setFgInvert(bool finv)
	{
		if(finv == false) return;
		fprintf(mFile,"\tsetAttr \".finv\" %i;\n", finv);
	}
	void setFgColorGain(const float3& fcg)
	{
		if(fcg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".fcg\" -type \"float3\" ");
		fcg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFgColorGainR(float fcgr)
	{
		if(fcgr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fcg.fcgr\" %f;\n", fcgr);
	}
	void setFgColorGainG(float fcgg)
	{
		if(fcgg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fcg.fcgg\" %f;\n", fcgg);
	}
	void setFgColorGainB(float fcgb)
	{
		if(fcgb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fcg.fcgb\" %f;\n", fcgb);
	}
	void setFgColorOffset(const float3& fco)
	{
		if(fco == float3(0,0,0)) return;
		fprintf(mFile,"\tsetAttr \".fco\" -type \"float3\" ");
		fco.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFgColorOffsetR(float fcor)
	{
		if(fcor == 0) return;
		fprintf(mFile,"\tsetAttr \".fco.fcor\" %f;\n", fcor);
	}
	void setFgColorOffsetG(float fcog)
	{
		if(fcog == 0) return;
		fprintf(mFile,"\tsetAttr \".fco.fcog\" %f;\n", fcog);
	}
	void setFgColorOffsetB(float fcob)
	{
		if(fcob == 0) return;
		fprintf(mFile,"\tsetAttr \".fco.fcob\" %f;\n", fcob);
	}
	void setEmitLight(bool el)
	{
		if(el == false) return;
		fprintf(mFile,"\tsetAttr \".el\" %i;\n", el);
	}
	void setFilter(const long2& flt)
	{
		if(flt == long2(256, 256)) return;
		fprintf(mFile,"\tsetAttr \".flt\" -type \"long2\" ");
		flt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFilterU(int fiu)
	{
		if(fiu == 256) return;
		fprintf(mFile,"\tsetAttr \".flt.fiu\" %i;\n", fiu);
	}
	void setFilterV(int fiv)
	{
		if(fiv == 256) return;
		fprintf(mFile,"\tsetAttr \".flt.fiv\" %i;\n", fiv);
	}
	void setSamples(const long2& smp)
	{
		if(smp == long2(40, 16)) return;
		fprintf(mFile,"\tsetAttr \".smp\" -type \"long2\" ");
		smp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSamplesU(int smpu)
	{
		if(smpu == 40) return;
		fprintf(mFile,"\tsetAttr \".smp.smpu\" %i;\n", smpu);
	}
	void setSamplesV(int smpv)
	{
		if(smpv == 16) return;
		fprintf(mFile,"\tsetAttr \".smp.smpv\" %i;\n", smpv);
	}
	void setLowSamples(const long2& low)
	{
		if(low == long2(5, 2)) return;
		fprintf(mFile,"\tsetAttr \".low\" -type \"long2\" ");
		low.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLowSamplesU(int lowu)
	{
		if(lowu == 5) return;
		fprintf(mFile,"\tsetAttr \".low.lowu\" %i;\n", lowu);
	}
	void setLowSamplesV(int lowv)
	{
		if(lowv == 2) return;
		fprintf(mFile,"\tsetAttr \".low.lowv\" %i;\n", lowv);
	}
	void setJitter(float jit)
	{
		if(jit == 0.8) return;
		fprintf(mFile,"\tsetAttr \".jit\" %f;\n", jit);
	}
	void setSkipBack(bool skb)
	{
		if(skb == true) return;
		fprintf(mFile,"\tsetAttr \".skb\" %i;\n", skb);
	}
	void setEmitDiffuse(bool emdf)
	{
		if(emdf == true) return;
		fprintf(mFile,"\tsetAttr \".emdf\" %i;\n", emdf);
	}
	void setEmitSpecular(bool emsp)
	{
		if(emsp == true) return;
		fprintf(mFile,"\tsetAttr \".emsp\" %i;\n", emsp);
	}
	void setUseRayTraceShadows(bool rts)
	{
		if(rts == true) return;
		fprintf(mFile,"\tsetAttr \".rts\" %i;\n", rts);
	}
	void setShadowColor(const float3& shc)
	{
		if(shc == float3(0,0,0)) return;
		fprintf(mFile,"\tsetAttr \".shc\" -type \"float3\" ");
		shc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setShadowColorR(float shcr)
	{
		if(shcr == 0) return;
		fprintf(mFile,"\tsetAttr \".shc.shcr\" %f;\n", shcr);
	}
	void setShadowColorG(float shcg)
	{
		if(shcg == 0) return;
		fprintf(mFile,"\tsetAttr \".shc.shcg\" %f;\n", shcg);
	}
	void setShadowColorB(float shcb)
	{
		if(shcb == 0) return;
		fprintf(mFile,"\tsetAttr \".shc.shcb\" %f;\n", shcb);
	}
	void setRayDepthLimit(int rdl)
	{
		if(rdl == 2) return;
		fprintf(mFile,"\tsetAttr \".rdl\" %i;\n", rdl);
	}
	void setOverrideLightColorFx(bool olfx)
	{
		if(olfx == false) return;
		fprintf(mFile,"\tsetAttr \".olfx\" %i;\n", olfx);
	}
	void setLightInvert(bool linv)
	{
		if(linv == false) return;
		fprintf(mFile,"\tsetAttr \".linv\" %i;\n", linv);
	}
	void setLightColorGain(const float3& lcg)
	{
		if(lcg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".lcg\" -type \"float3\" ");
		lcg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLightColorGainR(float lcgr)
	{
		if(lcgr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lcg.lcgr\" %f;\n", lcgr);
	}
	void setLightColorGainG(float lcgg)
	{
		if(lcgg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lcg.lcgg\" %f;\n", lcgg);
	}
	void setLightColorGainB(float lcgb)
	{
		if(lcgb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lcg.lcgb\" %f;\n", lcgb);
	}
	void setLightColorOffset(const float3& lco)
	{
		if(lco == float3(0,0,0)) return;
		fprintf(mFile,"\tsetAttr \".lco\" -type \"float3\" ");
		lco.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLightColorOffsetR(float lcor)
	{
		if(lcor == 0) return;
		fprintf(mFile,"\tsetAttr \".lco.lcor\" %f;\n", lcor);
	}
	void setLightColorOffsetG(float lcog)
	{
		if(lcog == 0) return;
		fprintf(mFile,"\tsetAttr \".lco.lcog\" %f;\n", lcog);
	}
	void setLightColorOffsetB(float lcob)
	{
		if(lcob == 0) return;
		fprintf(mFile,"\tsetAttr \".lco.lcob\" %f;\n", lcob);
	}
	void setEmitPhotons(bool ep)
	{
		if(ep == false) return;
		fprintf(mFile,"\tsetAttr \".ep\" %i;\n", ep);
	}
	void setGlobillumPhotons(int giph)
	{
		if(giph == 25000) return;
		fprintf(mFile,"\tsetAttr \".giph\" %i;\n", giph);
	}
	void setCausticPhotons(int caph)
	{
		if(caph == 15000) return;
		fprintf(mFile,"\tsetAttr \".caph\" %i;\n", caph);
	}
	void setExponent(float exp)
	{
		if(exp == 2.0) return;
		fprintf(mFile,"\tsetAttr \".exp\" %f;\n", exp);
	}
	void setStandardEmission(bool se)
	{
		if(se == false) return;
		fprintf(mFile,"\tsetAttr \".se\" %i;\n", se);
	}
	void setOverridePhotonColorFx(bool opfx)
	{
		if(opfx == false) return;
		fprintf(mFile,"\tsetAttr \".opfx\" %i;\n", opfx);
	}
	void setPhotonInvert(bool pinv)
	{
		if(pinv == false) return;
		fprintf(mFile,"\tsetAttr \".pinv\" %i;\n", pinv);
	}
	void setPhotonColorGain(const float3& pcg)
	{
		if(pcg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".pcg\" -type \"float3\" ");
		pcg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPhotonColorGainR(float pcgr)
	{
		if(pcgr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pcg.pcgr\" %f;\n", pcgr);
	}
	void setPhotonColorGainG(float pcgg)
	{
		if(pcgg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pcg.pcgg\" %f;\n", pcgg);
	}
	void setPhotonColorGainB(float pcgb)
	{
		if(pcgb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pcg.pcgb\" %f;\n", pcgb);
	}
	void setPhotonColorOffset(const float3& pco)
	{
		if(pco == float3(0,0,0)) return;
		fprintf(mFile,"\tsetAttr \".pco\" -type \"float3\" ");
		pco.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPhotonColorOffsetR(float pcor)
	{
		if(pcor == 0) return;
		fprintf(mFile,"\tsetAttr \".pco.pcor\" %f;\n", pcor);
	}
	void setPhotonColorOffsetG(float pcog)
	{
		if(pcog == 0) return;
		fprintf(mFile,"\tsetAttr \".pco.pcog\" %f;\n", pcog);
	}
	void setPhotonColorOffsetB(float pcob)
	{
		if(pcob == 0) return;
		fprintf(mFile,"\tsetAttr \".pco.pcob\" %f;\n", pcob);
	}
	void getFrameExtension()const
	{
		fprintf(mFile,"\"%s.fe\"",mName.c_str());
	}
	void getColor()const
	{
		fprintf(mFile,"\"%s.col\"",mName.c_str());
	}
	void getColorR()const
	{
		fprintf(mFile,"\"%s.col.colr\"",mName.c_str());
	}
	void getColorG()const
	{
		fprintf(mFile,"\"%s.col.colg\"",mName.c_str());
	}
	void getColorB()const
	{
		fprintf(mFile,"\"%s.col.colb\"",mName.c_str());
	}
	void getColorGain()const
	{
		fprintf(mFile,"\"%s.cg\"",mName.c_str());
	}
	void getColorGainR()const
	{
		fprintf(mFile,"\"%s.cg.cgr\"",mName.c_str());
	}
	void getColorGainG()const
	{
		fprintf(mFile,"\"%s.cg.cgg\"",mName.c_str());
	}
	void getColorGainB()const
	{
		fprintf(mFile,"\"%s.cg.cgb\"",mName.c_str());
	}
	void getColorOffset()const
	{
		fprintf(mFile,"\"%s.cof\"",mName.c_str());
	}
	void getColorOffsetR()const
	{
		fprintf(mFile,"\"%s.cof.cofr\"",mName.c_str());
	}
	void getColorOffsetG()const
	{
		fprintf(mFile,"\"%s.cof.cofg\"",mName.c_str());
	}
	void getColorOffsetB()const
	{
		fprintf(mFile,"\"%s.cof.cofb\"",mName.c_str());
	}
	void getEnvColorGain()const
	{
		fprintf(mFile,"\"%s.ecg\"",mName.c_str());
	}
	void getEnvColorGainR()const
	{
		fprintf(mFile,"\"%s.ecg.ecgr\"",mName.c_str());
	}
	void getEnvColorGainG()const
	{
		fprintf(mFile,"\"%s.ecg.ecgg\"",mName.c_str());
	}
	void getEnvColorGainB()const
	{
		fprintf(mFile,"\"%s.ecg.ecgb\"",mName.c_str());
	}
	void getEnvColorOffset()const
	{
		fprintf(mFile,"\"%s.eco\"",mName.c_str());
	}
	void getEnvColorOffsetR()const
	{
		fprintf(mFile,"\"%s.eco.ecor\"",mName.c_str());
	}
	void getEnvColorOffsetG()const
	{
		fprintf(mFile,"\"%s.eco.ecog\"",mName.c_str());
	}
	void getEnvColorOffsetB()const
	{
		fprintf(mFile,"\"%s.eco.ecorb\"",mName.c_str());
	}
	void getFgColorGain()const
	{
		fprintf(mFile,"\"%s.fcg\"",mName.c_str());
	}
	void getFgColorGainR()const
	{
		fprintf(mFile,"\"%s.fcg.fcgr\"",mName.c_str());
	}
	void getFgColorGainG()const
	{
		fprintf(mFile,"\"%s.fcg.fcgg\"",mName.c_str());
	}
	void getFgColorGainB()const
	{
		fprintf(mFile,"\"%s.fcg.fcgb\"",mName.c_str());
	}
	void getFgColorOffset()const
	{
		fprintf(mFile,"\"%s.fco\"",mName.c_str());
	}
	void getFgColorOffsetR()const
	{
		fprintf(mFile,"\"%s.fco.fcor\"",mName.c_str());
	}
	void getFgColorOffsetG()const
	{
		fprintf(mFile,"\"%s.fco.fcog\"",mName.c_str());
	}
	void getFgColorOffsetB()const
	{
		fprintf(mFile,"\"%s.fco.fcob\"",mName.c_str());
	}
	void getFilterU()const
	{
		fprintf(mFile,"\"%s.flt.fiu\"",mName.c_str());
	}
	void getFilterV()const
	{
		fprintf(mFile,"\"%s.flt.fiv\"",mName.c_str());
	}
	void getSamplesU()const
	{
		fprintf(mFile,"\"%s.smp.smpu\"",mName.c_str());
	}
	void getSamplesV()const
	{
		fprintf(mFile,"\"%s.smp.smpv\"",mName.c_str());
	}
	void getLowSamplesU()const
	{
		fprintf(mFile,"\"%s.low.lowu\"",mName.c_str());
	}
	void getLowSamplesV()const
	{
		fprintf(mFile,"\"%s.low.lowv\"",mName.c_str());
	}
	void getShadowColor()const
	{
		fprintf(mFile,"\"%s.shc\"",mName.c_str());
	}
	void getShadowColorR()const
	{
		fprintf(mFile,"\"%s.shc.shcr\"",mName.c_str());
	}
	void getShadowColorG()const
	{
		fprintf(mFile,"\"%s.shc.shcg\"",mName.c_str());
	}
	void getShadowColorB()const
	{
		fprintf(mFile,"\"%s.shc.shcb\"",mName.c_str());
	}
	void getLightColorGain()const
	{
		fprintf(mFile,"\"%s.lcg\"",mName.c_str());
	}
	void getLightColorGainR()const
	{
		fprintf(mFile,"\"%s.lcg.lcgr\"",mName.c_str());
	}
	void getLightColorGainG()const
	{
		fprintf(mFile,"\"%s.lcg.lcgg\"",mName.c_str());
	}
	void getLightColorGainB()const
	{
		fprintf(mFile,"\"%s.lcg.lcgb\"",mName.c_str());
	}
	void getLightColorOffset()const
	{
		fprintf(mFile,"\"%s.lco\"",mName.c_str());
	}
	void getLightColorOffsetR()const
	{
		fprintf(mFile,"\"%s.lco.lcor\"",mName.c_str());
	}
	void getLightColorOffsetG()const
	{
		fprintf(mFile,"\"%s.lco.lcog\"",mName.c_str());
	}
	void getLightColorOffsetB()const
	{
		fprintf(mFile,"\"%s.lco.lcob\"",mName.c_str());
	}
	void getPhotonColorGain()const
	{
		fprintf(mFile,"\"%s.pcg\"",mName.c_str());
	}
	void getPhotonColorGainR()const
	{
		fprintf(mFile,"\"%s.pcg.pcgr\"",mName.c_str());
	}
	void getPhotonColorGainG()const
	{
		fprintf(mFile,"\"%s.pcg.pcgg\"",mName.c_str());
	}
	void getPhotonColorGainB()const
	{
		fprintf(mFile,"\"%s.pcg.pcgb\"",mName.c_str());
	}
	void getPhotonColorOffset()const
	{
		fprintf(mFile,"\"%s.pco\"",mName.c_str());
	}
	void getPhotonColorOffsetR()const
	{
		fprintf(mFile,"\"%s.pco.pcor\"",mName.c_str());
	}
	void getPhotonColorOffsetG()const
	{
		fprintf(mFile,"\"%s.pco.pcog\"",mName.c_str());
	}
	void getPhotonColorOffsetB()const
	{
		fprintf(mFile,"\"%s.pco.pcob\"",mName.c_str());
	}
protected:
	MentalrayIblShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:mFile(file), mName(name), mParent(parent), mNodeType(nodeType), mShared(shared) 
	{
		if(create)
			createNode();
	}
private:
	void createNode()const
	{
		if(mShared)
			fprintf(mFile, "createNode %s -s -n \"%s\"", mNodeType.c_str(),mName.c_str());
		else
			fprintf(mFile, "createNode %s -n \"%s\"", mNodeType.c_str(),mName.c_str());
		if(mParent != "") 
			fprintf(mFile, " -p \"%s\"", mParent.c_str());
		fprintf(mFile, ";\n");
	}

};
}//namespace MayaDM
#endif//__MayaDM_MENTALRAYIBLSHAPE_H__
