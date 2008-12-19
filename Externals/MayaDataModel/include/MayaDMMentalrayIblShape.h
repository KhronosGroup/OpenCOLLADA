/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
public:
	const std::string& getName()
	{
return mName;
	}
	const std::string& getParent()
	{
return mParent;
	}
	const std::string& getType()
	{
return mNodeType;
	}
public:
		virtual ~MentalrayIblShape(){}
	void setMapping(unsigned int map)
	{
		if(map == 0) return;
		fprintf(mFile,"setAttr \".map\" %i;\n", map);

	}
	void setType(unsigned int typ)
	{
		if(typ == 0) return;
		fprintf(mFile,"setAttr \".typ\" %i;\n", typ);

	}
	void setTexture(const string& tx)
	{
		if(tx == "NULL") return;
		fprintf(mFile,"setAttr \".tx\" -type \"string\" ");
		tx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUseFrameExtension(bool ufe)
	{
		if(ufe == false) return;
		fprintf(mFile,"setAttr \".ufe\" %i;\n", ufe);

	}
	void setFrameExtension(int fe)
	{
		if(fe == 1) return;
		fprintf(mFile,"setAttr \".fe\" %i;\n", fe);

	}
	void setColor(const float3& col)
	{
		if(col == float3(0,0,0)) return;
		fprintf(mFile,"setAttr \".col\" -type \"float3\" ");
		col.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(float colr)
	{
		if(colr == 0) return;
		fprintf(mFile,"setAttr \".col.colr\" %f;\n", colr);

	}
	void setColorG(float colg)
	{
		if(colg == 0) return;
		fprintf(mFile,"setAttr \".col.colg\" %f;\n", colg);

	}
	void setColorB(float colb)
	{
		if(colb == 0) return;
		fprintf(mFile,"setAttr \".col.colb\" %f;\n", colb);

	}
	void setHardwareFilter(unsigned int hwf)
	{
		if(hwf == 0) return;
		fprintf(mFile,"setAttr \".hwf\" %i;\n", hwf);

	}
	void setHardwareAlpha(float hwt)
	{
		if(hwt == 0.5) return;
		fprintf(mFile,"setAttr \".hwt\" %f;\n", hwt);

	}
	void setColorGain(const float3& cg)
	{
		if(cg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".cg\" -type \"float3\" ");
		cg.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorGainR(float cgr)
	{
		if(cgr == 1.0) return;
		fprintf(mFile,"setAttr \".cg.cgr\" %f;\n", cgr);

	}
	void setColorGainG(float cgg)
	{
		if(cgg == 1.0) return;
		fprintf(mFile,"setAttr \".cg.cgg\" %f;\n", cgg);

	}
	void setColorGainB(float cgb)
	{
		if(cgb == 1.0) return;
		fprintf(mFile,"setAttr \".cg.cgb\" %f;\n", cgb);

	}
	void setColorOffset(const float3& cof)
	{
		if(cof == float3(0,0,0)) return;
		fprintf(mFile,"setAttr \".cof\" -type \"float3\" ");
		cof.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorOffsetR(float cofr)
	{
		if(cofr == 0) return;
		fprintf(mFile,"setAttr \".cof.cofr\" %f;\n", cofr);

	}
	void setColorOffsetG(float cofg)
	{
		if(cofg == 0) return;
		fprintf(mFile,"setAttr \".cof.cofg\" %f;\n", cofg);

	}
	void setColorOffsetB(float cofb)
	{
		if(cofb == 0) return;
		fprintf(mFile,"setAttr \".cof.cofb\" %f;\n", cofb);

	}
	void setInvert(bool inv)
	{
		if(inv == false) return;
		fprintf(mFile,"setAttr \".inv\" %i;\n", inv);

	}
	void setAlphaIsLuminance(bool ail)
	{
		if(ail == false) return;
		fprintf(mFile,"setAttr \".ail\" %i;\n", ail);

	}
	void setPrimaryVisibility(bool vis)
	{
		if(vis == true) return;
		fprintf(mFile,"setAttr \".vis\" %i;\n", vis);

	}
	void setVisibleInEnvironment(bool vien)
	{
		if(vien == false) return;
		fprintf(mFile,"setAttr \".vien\" %i;\n", vien);

	}
	void setVisibleInReflections(bool vir)
	{
		if(vir == false) return;
		fprintf(mFile,"setAttr \".vir\" %i;\n", vir);

	}
	void setVisibleInRefractions(bool vif)
	{
		if(vif == false) return;
		fprintf(mFile,"setAttr \".vif\" %i;\n", vif);

	}
	void setVisibleInFinalGather(bool vifg)
	{
		if(vifg == false) return;
		fprintf(mFile,"setAttr \".vifg\" %i;\n", vifg);

	}
	void setOverrideEnvColorFx(bool oefx)
	{
		if(oefx == false) return;
		fprintf(mFile,"setAttr \".oefx\" %i;\n", oefx);

	}
	void setEnvInvert(bool einv)
	{
		if(einv == false) return;
		fprintf(mFile,"setAttr \".einv\" %i;\n", einv);

	}
	void setEnvColorGain(const float3& ecg)
	{
		if(ecg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".ecg\" -type \"float3\" ");
		ecg.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEnvColorGainR(float ecgr)
	{
		if(ecgr == 1.0) return;
		fprintf(mFile,"setAttr \".ecg.ecgr\" %f;\n", ecgr);

	}
	void setEnvColorGainG(float ecgg)
	{
		if(ecgg == 1.0) return;
		fprintf(mFile,"setAttr \".ecg.ecgg\" %f;\n", ecgg);

	}
	void setEnvColorGainB(float ecgb)
	{
		if(ecgb == 1.0) return;
		fprintf(mFile,"setAttr \".ecg.ecgb\" %f;\n", ecgb);

	}
	void setEnvColorOffset(const float3& eco)
	{
		if(eco == float3(0,0,0)) return;
		fprintf(mFile,"setAttr \".eco\" -type \"float3\" ");
		eco.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEnvColorOffsetR(float ecor)
	{
		if(ecor == 0) return;
		fprintf(mFile,"setAttr \".eco.ecor\" %f;\n", ecor);

	}
	void setEnvColorOffsetG(float ecog)
	{
		if(ecog == 0) return;
		fprintf(mFile,"setAttr \".eco.ecog\" %f;\n", ecog);

	}
	void setEnvColorOffsetB(float ecorb)
	{
		if(ecorb == 0) return;
		fprintf(mFile,"setAttr \".eco.ecorb\" %f;\n", ecorb);

	}
	void setOverrideFgColorFx(bool offx)
	{
		if(offx == false) return;
		fprintf(mFile,"setAttr \".offx\" %i;\n", offx);

	}
	void setFgInvert(bool finv)
	{
		if(finv == false) return;
		fprintf(mFile,"setAttr \".finv\" %i;\n", finv);

	}
	void setFgColorGain(const float3& fcg)
	{
		if(fcg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".fcg\" -type \"float3\" ");
		fcg.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFgColorGainR(float fcgr)
	{
		if(fcgr == 1.0) return;
		fprintf(mFile,"setAttr \".fcg.fcgr\" %f;\n", fcgr);

	}
	void setFgColorGainG(float fcgg)
	{
		if(fcgg == 1.0) return;
		fprintf(mFile,"setAttr \".fcg.fcgg\" %f;\n", fcgg);

	}
	void setFgColorGainB(float fcgb)
	{
		if(fcgb == 1.0) return;
		fprintf(mFile,"setAttr \".fcg.fcgb\" %f;\n", fcgb);

	}
	void setFgColorOffset(const float3& fco)
	{
		if(fco == float3(0,0,0)) return;
		fprintf(mFile,"setAttr \".fco\" -type \"float3\" ");
		fco.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFgColorOffsetR(float fcor)
	{
		if(fcor == 0) return;
		fprintf(mFile,"setAttr \".fco.fcor\" %f;\n", fcor);

	}
	void setFgColorOffsetG(float fcog)
	{
		if(fcog == 0) return;
		fprintf(mFile,"setAttr \".fco.fcog\" %f;\n", fcog);

	}
	void setFgColorOffsetB(float fcob)
	{
		if(fcob == 0) return;
		fprintf(mFile,"setAttr \".fco.fcob\" %f;\n", fcob);

	}
	void setEmitLight(bool el)
	{
		if(el == false) return;
		fprintf(mFile,"setAttr \".el\" %i;\n", el);

	}
	void setFilter(const long2& flt)
	{
		if(flt == long2(256, 256)) return;
		fprintf(mFile,"setAttr \".flt\" -type \"long2\" ");
		flt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFilterU(int fiu)
	{
		if(fiu == 256) return;
		fprintf(mFile,"setAttr \".flt.fiu\" %i;\n", fiu);

	}
	void setFilterV(int fiv)
	{
		if(fiv == 256) return;
		fprintf(mFile,"setAttr \".flt.fiv\" %i;\n", fiv);

	}
	void setSamples(const long2& smp)
	{
		if(smp == long2(40, 16)) return;
		fprintf(mFile,"setAttr \".smp\" -type \"long2\" ");
		smp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSamplesU(int smpu)
	{
		if(smpu == 40) return;
		fprintf(mFile,"setAttr \".smp.smpu\" %i;\n", smpu);

	}
	void setSamplesV(int smpv)
	{
		if(smpv == 16) return;
		fprintf(mFile,"setAttr \".smp.smpv\" %i;\n", smpv);

	}
	void setLowSamples(const long2& low)
	{
		if(low == long2(5, 2)) return;
		fprintf(mFile,"setAttr \".low\" -type \"long2\" ");
		low.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLowSamplesU(int lowu)
	{
		if(lowu == 5) return;
		fprintf(mFile,"setAttr \".low.lowu\" %i;\n", lowu);

	}
	void setLowSamplesV(int lowv)
	{
		if(lowv == 2) return;
		fprintf(mFile,"setAttr \".low.lowv\" %i;\n", lowv);

	}
	void setJitter(float jit)
	{
		if(jit == 0.8) return;
		fprintf(mFile,"setAttr \".jit\" %f;\n", jit);

	}
	void setSkipBack(bool skb)
	{
		if(skb == true) return;
		fprintf(mFile,"setAttr \".skb\" %i;\n", skb);

	}
	void setEmitDiffuse(bool emdf)
	{
		if(emdf == true) return;
		fprintf(mFile,"setAttr \".emdf\" %i;\n", emdf);

	}
	void setEmitSpecular(bool emsp)
	{
		if(emsp == true) return;
		fprintf(mFile,"setAttr \".emsp\" %i;\n", emsp);

	}
	void setUseRayTraceShadows(bool rts)
	{
		if(rts == true) return;
		fprintf(mFile,"setAttr \".rts\" %i;\n", rts);

	}
	void setShadowColor(const float3& shc)
	{
		if(shc == float3(0,0,0)) return;
		fprintf(mFile,"setAttr \".shc\" -type \"float3\" ");
		shc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setShadowColorR(float shcr)
	{
		if(shcr == 0) return;
		fprintf(mFile,"setAttr \".shc.shcr\" %f;\n", shcr);

	}
	void setShadowColorG(float shcg)
	{
		if(shcg == 0) return;
		fprintf(mFile,"setAttr \".shc.shcg\" %f;\n", shcg);

	}
	void setShadowColorB(float shcb)
	{
		if(shcb == 0) return;
		fprintf(mFile,"setAttr \".shc.shcb\" %f;\n", shcb);

	}
	void setRayDepthLimit(int rdl)
	{
		if(rdl == 2) return;
		fprintf(mFile,"setAttr \".rdl\" %i;\n", rdl);

	}
	void setOverrideLightColorFx(bool olfx)
	{
		if(olfx == false) return;
		fprintf(mFile,"setAttr \".olfx\" %i;\n", olfx);

	}
	void setLightInvert(bool linv)
	{
		if(linv == false) return;
		fprintf(mFile,"setAttr \".linv\" %i;\n", linv);

	}
	void setLightColorGain(const float3& lcg)
	{
		if(lcg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".lcg\" -type \"float3\" ");
		lcg.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLightColorGainR(float lcgr)
	{
		if(lcgr == 1.0) return;
		fprintf(mFile,"setAttr \".lcg.lcgr\" %f;\n", lcgr);

	}
	void setLightColorGainG(float lcgg)
	{
		if(lcgg == 1.0) return;
		fprintf(mFile,"setAttr \".lcg.lcgg\" %f;\n", lcgg);

	}
	void setLightColorGainB(float lcgb)
	{
		if(lcgb == 1.0) return;
		fprintf(mFile,"setAttr \".lcg.lcgb\" %f;\n", lcgb);

	}
	void setLightColorOffset(const float3& lco)
	{
		if(lco == float3(0,0,0)) return;
		fprintf(mFile,"setAttr \".lco\" -type \"float3\" ");
		lco.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLightColorOffsetR(float lcor)
	{
		if(lcor == 0) return;
		fprintf(mFile,"setAttr \".lco.lcor\" %f;\n", lcor);

	}
	void setLightColorOffsetG(float lcog)
	{
		if(lcog == 0) return;
		fprintf(mFile,"setAttr \".lco.lcog\" %f;\n", lcog);

	}
	void setLightColorOffsetB(float lcob)
	{
		if(lcob == 0) return;
		fprintf(mFile,"setAttr \".lco.lcob\" %f;\n", lcob);

	}
	void setEmitPhotons(bool ep)
	{
		if(ep == false) return;
		fprintf(mFile,"setAttr \".ep\" %i;\n", ep);

	}
	void setGlobillumPhotons(int giph)
	{
		if(giph == 25000) return;
		fprintf(mFile,"setAttr \".giph\" %i;\n", giph);

	}
	void setCausticPhotons(int caph)
	{
		if(caph == 15000) return;
		fprintf(mFile,"setAttr \".caph\" %i;\n", caph);

	}
	void setExponent(float exp)
	{
		if(exp == 2.0) return;
		fprintf(mFile,"setAttr \".exp\" %f;\n", exp);

	}
	void setStandardEmission(bool se)
	{
		if(se == false) return;
		fprintf(mFile,"setAttr \".se\" %i;\n", se);

	}
	void setOverridePhotonColorFx(bool opfx)
	{
		if(opfx == false) return;
		fprintf(mFile,"setAttr \".opfx\" %i;\n", opfx);

	}
	void setPhotonInvert(bool pinv)
	{
		if(pinv == false) return;
		fprintf(mFile,"setAttr \".pinv\" %i;\n", pinv);

	}
	void setPhotonColorGain(const float3& pcg)
	{
		if(pcg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".pcg\" -type \"float3\" ");
		pcg.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPhotonColorGainR(float pcgr)
	{
		if(pcgr == 1.0) return;
		fprintf(mFile,"setAttr \".pcg.pcgr\" %f;\n", pcgr);

	}
	void setPhotonColorGainG(float pcgg)
	{
		if(pcgg == 1.0) return;
		fprintf(mFile,"setAttr \".pcg.pcgg\" %f;\n", pcgg);

	}
	void setPhotonColorGainB(float pcgb)
	{
		if(pcgb == 1.0) return;
		fprintf(mFile,"setAttr \".pcg.pcgb\" %f;\n", pcgb);

	}
	void setPhotonColorOffset(const float3& pco)
	{
		if(pco == float3(0,0,0)) return;
		fprintf(mFile,"setAttr \".pco\" -type \"float3\" ");
		pco.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPhotonColorOffsetR(float pcor)
	{
		if(pcor == 0) return;
		fprintf(mFile,"setAttr \".pco.pcor\" %f;\n", pcor);

	}
	void setPhotonColorOffsetG(float pcog)
	{
		if(pcog == 0) return;
		fprintf(mFile,"setAttr \".pco.pcog\" %f;\n", pcog);

	}
	void setPhotonColorOffsetB(float pcob)
	{
		if(pcob == 0) return;
		fprintf(mFile,"setAttr \".pco.pcob\" %f;\n", pcob);

	}
	void getFrameExtension()
	{
		fprintf(mFile,"\"%s.fe\"",mName.c_str());

	}
	void getColor()
	{
		fprintf(mFile,"\"%s.col\"",mName.c_str());

	}
	void getColorR()
	{
		fprintf(mFile,"\"%s.col.colr\"",mName.c_str());

	}
	void getColorG()
	{
		fprintf(mFile,"\"%s.col.colg\"",mName.c_str());

	}
	void getColorB()
	{
		fprintf(mFile,"\"%s.col.colb\"",mName.c_str());

	}
	void getColorGain()
	{
		fprintf(mFile,"\"%s.cg\"",mName.c_str());

	}
	void getColorGainR()
	{
		fprintf(mFile,"\"%s.cg.cgr\"",mName.c_str());

	}
	void getColorGainG()
	{
		fprintf(mFile,"\"%s.cg.cgg\"",mName.c_str());

	}
	void getColorGainB()
	{
		fprintf(mFile,"\"%s.cg.cgb\"",mName.c_str());

	}
	void getColorOffset()
	{
		fprintf(mFile,"\"%s.cof\"",mName.c_str());

	}
	void getColorOffsetR()
	{
		fprintf(mFile,"\"%s.cof.cofr\"",mName.c_str());

	}
	void getColorOffsetG()
	{
		fprintf(mFile,"\"%s.cof.cofg\"",mName.c_str());

	}
	void getColorOffsetB()
	{
		fprintf(mFile,"\"%s.cof.cofb\"",mName.c_str());

	}
	void getEnvColorGain()
	{
		fprintf(mFile,"\"%s.ecg\"",mName.c_str());

	}
	void getEnvColorGainR()
	{
		fprintf(mFile,"\"%s.ecg.ecgr\"",mName.c_str());

	}
	void getEnvColorGainG()
	{
		fprintf(mFile,"\"%s.ecg.ecgg\"",mName.c_str());

	}
	void getEnvColorGainB()
	{
		fprintf(mFile,"\"%s.ecg.ecgb\"",mName.c_str());

	}
	void getEnvColorOffset()
	{
		fprintf(mFile,"\"%s.eco\"",mName.c_str());

	}
	void getEnvColorOffsetR()
	{
		fprintf(mFile,"\"%s.eco.ecor\"",mName.c_str());

	}
	void getEnvColorOffsetG()
	{
		fprintf(mFile,"\"%s.eco.ecog\"",mName.c_str());

	}
	void getEnvColorOffsetB()
	{
		fprintf(mFile,"\"%s.eco.ecorb\"",mName.c_str());

	}
	void getFgColorGain()
	{
		fprintf(mFile,"\"%s.fcg\"",mName.c_str());

	}
	void getFgColorGainR()
	{
		fprintf(mFile,"\"%s.fcg.fcgr\"",mName.c_str());

	}
	void getFgColorGainG()
	{
		fprintf(mFile,"\"%s.fcg.fcgg\"",mName.c_str());

	}
	void getFgColorGainB()
	{
		fprintf(mFile,"\"%s.fcg.fcgb\"",mName.c_str());

	}
	void getFgColorOffset()
	{
		fprintf(mFile,"\"%s.fco\"",mName.c_str());

	}
	void getFgColorOffsetR()
	{
		fprintf(mFile,"\"%s.fco.fcor\"",mName.c_str());

	}
	void getFgColorOffsetG()
	{
		fprintf(mFile,"\"%s.fco.fcog\"",mName.c_str());

	}
	void getFgColorOffsetB()
	{
		fprintf(mFile,"\"%s.fco.fcob\"",mName.c_str());

	}
	void getFilterU()
	{
		fprintf(mFile,"\"%s.flt.fiu\"",mName.c_str());

	}
	void getFilterV()
	{
		fprintf(mFile,"\"%s.flt.fiv\"",mName.c_str());

	}
	void getSamplesU()
	{
		fprintf(mFile,"\"%s.smp.smpu\"",mName.c_str());

	}
	void getSamplesV()
	{
		fprintf(mFile,"\"%s.smp.smpv\"",mName.c_str());

	}
	void getLowSamplesU()
	{
		fprintf(mFile,"\"%s.low.lowu\"",mName.c_str());

	}
	void getLowSamplesV()
	{
		fprintf(mFile,"\"%s.low.lowv\"",mName.c_str());

	}
	void getShadowColor()
	{
		fprintf(mFile,"\"%s.shc\"",mName.c_str());

	}
	void getShadowColorR()
	{
		fprintf(mFile,"\"%s.shc.shcr\"",mName.c_str());

	}
	void getShadowColorG()
	{
		fprintf(mFile,"\"%s.shc.shcg\"",mName.c_str());

	}
	void getShadowColorB()
	{
		fprintf(mFile,"\"%s.shc.shcb\"",mName.c_str());

	}
	void getLightColorGain()
	{
		fprintf(mFile,"\"%s.lcg\"",mName.c_str());

	}
	void getLightColorGainR()
	{
		fprintf(mFile,"\"%s.lcg.lcgr\"",mName.c_str());

	}
	void getLightColorGainG()
	{
		fprintf(mFile,"\"%s.lcg.lcgg\"",mName.c_str());

	}
	void getLightColorGainB()
	{
		fprintf(mFile,"\"%s.lcg.lcgb\"",mName.c_str());

	}
	void getLightColorOffset()
	{
		fprintf(mFile,"\"%s.lco\"",mName.c_str());

	}
	void getLightColorOffsetR()
	{
		fprintf(mFile,"\"%s.lco.lcor\"",mName.c_str());

	}
	void getLightColorOffsetG()
	{
		fprintf(mFile,"\"%s.lco.lcog\"",mName.c_str());

	}
	void getLightColorOffsetB()
	{
		fprintf(mFile,"\"%s.lco.lcob\"",mName.c_str());

	}
	void getPhotonColorGain()
	{
		fprintf(mFile,"\"%s.pcg\"",mName.c_str());

	}
	void getPhotonColorGainR()
	{
		fprintf(mFile,"\"%s.pcg.pcgr\"",mName.c_str());

	}
	void getPhotonColorGainG()
	{
		fprintf(mFile,"\"%s.pcg.pcgg\"",mName.c_str());

	}
	void getPhotonColorGainB()
	{
		fprintf(mFile,"\"%s.pcg.pcgb\"",mName.c_str());

	}
	void getPhotonColorOffset()
	{
		fprintf(mFile,"\"%s.pco\"",mName.c_str());

	}
	void getPhotonColorOffsetR()
	{
		fprintf(mFile,"\"%s.pco.pcor\"",mName.c_str());

	}
	void getPhotonColorOffsetG()
	{
		fprintf(mFile,"\"%s.pco.pcog\"",mName.c_str());

	}
	void getPhotonColorOffsetB()
	{
		fprintf(mFile,"\"%s.pco.pcob\"",mName.c_str());

	}
protected:
	MentalrayIblShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):mFile(file), mName(name), mParent(parent), mNodeType(nodeType){createNode();}
private:
	void createNode()
	{
fprintf(mFile, "createNode %s -n \"%s\"", mNodeType.c_str(),mName.c_str());if(mParent != "") fprintf(mFile, " -p \"%s\"", mParent.c_str());fprintf(mFile, ";\n");
	}

};
}//namespace MayaDM
#endif//__MayaDM_MENTALRAYIBLSHAPE_H__
