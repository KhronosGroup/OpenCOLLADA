/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POINTEMITTER_H__
#define __MayaDM_POINTEMITTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDynBase.h"
namespace MayaDM
{
class PointEmitter : public DynBase
{
public:
public:

	PointEmitter():DynBase(){}
	PointEmitter(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DynBase(file, name, parent, "pointEmitter", shared, create){}
	virtual ~PointEmitter(){}

	void setEmitterType(unsigned int emt)
	{
		if(emt == 1) return;
		fprintf(mFile,"\tsetAttr \".emt\" %i;\n", emt);
	}
	void setRate(double rat)
	{
		if(rat == 100) return;
		fprintf(mFile,"\tsetAttr \".rat\" %f;\n", rat);
	}
	void setScaleRateByObjectSize(bool sro)
	{
		if(sro == true) return;
		fprintf(mFile,"\tsetAttr \".sro\" %i;\n", sro);
	}
	void setUseRatePP(bool urpp)
	{
		if(urpp == false) return;
		fprintf(mFile,"\tsetAttr \".urpp\" %i;\n", urpp);
	}
	void setNeedParentUV(bool npuv)
	{
		if(npuv == false) return;
		fprintf(mFile,"\tsetAttr \".npuv\" %i;\n", npuv);
	}
	void setCycleEmission(unsigned int cye)
	{
		if(cye == 0) return;
		fprintf(mFile,"\tsetAttr \".cye\" %i;\n", cye);
	}
	void setCycleInterval(int cyi)
	{
		if(cyi == 1) return;
		fprintf(mFile,"\tsetAttr \".cyi\" %i;\n", cyi);
	}
	void setDeltaTimeCycle(size_t dtc_i,double dtc)
	{
		if(dtc == 0) return;
		fprintf(mFile,"\tsetAttr \".dtc[%i]\" %f;\n", dtc_i,dtc);
	}
	void setDeltaTimeCycle(size_t dtc_start,size_t dtc_end,double* dtc)
	{
		fprintf(mFile,"\tsetAttr \".dtc[%i:%i]\" ", dtc_start,dtc_end);
		size_t size = (dtc_end-dtc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",dtc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startDeltaTimeCycle(size_t dtc_start,size_t dtc_end)const
	{
		fprintf(mFile,"\tsetAttr \".dtc[%i:%i]\"",dtc_start,dtc_end);
	}
	void appendDeltaTimeCycle(double dtc)const
	{
		fprintf(mFile," %f",dtc);
	}
	void endDeltaTimeCycle()const
	{
		fprintf(mFile,";\n");
	}
	void setMaxDistance(double max)
	{
		if(max == 0) return;
		fprintf(mFile,"\tsetAttr \".max\" %f;\n", max);
	}
	void setMinDistance(double min)
	{
		if(min == 0) return;
		fprintf(mFile,"\tsetAttr \".min\" %f;\n", min);
	}
	void setDirection(const double3& d)
	{
		fprintf(mFile,"\tsetAttr \".d\" -type \"double3\" ");
		d.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDirectionX(double dx)
	{
		if(dx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".d.dx\" %f;\n", dx);
	}
	void setDirectionY(double dy)
	{
		if(dy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d.dy\" %f;\n", dy);
	}
	void setDirectionZ(double dz)
	{
		if(dz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d.dz\" %f;\n", dz);
	}
	void setSpread(double spr)
	{
		if(spr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spr\" %f;\n", spr);
	}
	void setSpeed(double spd)
	{
		if(spd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".spd\" %f;\n", spd);
	}
	void setSpeedRandom(double srnd)
	{
		if(srnd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".srnd\" %f;\n", srnd);
	}
	void setTangentSpeed(double tspd)
	{
		if(tspd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tspd\" %f;\n", tspd);
	}
	void setNormalSpeed(double nspd)
	{
		if(nspd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nspd\" %f;\n", nspd);
	}
	void setInheritFactor(size_t inh_i,double inh)
	{
		if(inh == 0.0) return;
		fprintf(mFile,"\tsetAttr \".inh[%i]\" %f;\n", inh_i,inh);
	}
	void setInheritFactor(size_t inh_start,size_t inh_end,double* inh)
	{
		fprintf(mFile,"\tsetAttr \".inh[%i:%i]\" ", inh_start,inh_end);
		size_t size = (inh_end-inh_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",inh[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInheritFactor(size_t inh_start,size_t inh_end)const
	{
		fprintf(mFile,"\tsetAttr \".inh[%i:%i]\"",inh_start,inh_end);
	}
	void appendInheritFactor(double inh)const
	{
		fprintf(mFile," %f",inh);
	}
	void endInheritFactor()const
	{
		fprintf(mFile,";\n");
	}
	void setIsFull(size_t full_i,bool full)
	{
		if(full == false) return;
		fprintf(mFile,"\tsetAttr \".full[%i]\" %i;\n", full_i,full);
	}
	void setIsFull(size_t full_start,size_t full_end,bool* full)
	{
		fprintf(mFile,"\tsetAttr \".full[%i:%i]\" ", full_start,full_end);
		size_t size = (full_end-full_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",full[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startIsFull(size_t full_start,size_t full_end)const
	{
		fprintf(mFile,"\tsetAttr \".full[%i:%i]\"",full_start,full_end);
	}
	void appendIsFull(bool full)const
	{
		fprintf(mFile," %i",full);
	}
	void endIsFull()const
	{
		fprintf(mFile,";\n");
	}
	void setRatePP(const doubleArray& rpp)
	{
		if(rpp.size == 0) return;
		fprintf(mFile,"\tsetAttr \".rpp\" -type \"doubleArray\" ");
		rpp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setParentId(const doubleArray& paid)
	{
		if(paid.size == 0) return;
		fprintf(mFile,"\tsetAttr \".paid\" -type \"doubleArray\" ");
		paid.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRandStateX(size_t rst_i,int rstx)
	{
		if(rstx == 0) return;
		fprintf(mFile,"\tsetAttr \".rst[%i].rstx\" %i;\n", rst_i,rstx);
	}
	void setRandStateY(size_t rst_i,int rsty)
	{
		if(rsty == 0) return;
		fprintf(mFile,"\tsetAttr \".rst[%i].rsty\" %i;\n", rst_i,rsty);
	}
	void setRandStateZ(size_t rst_i,int rstz)
	{
		if(rstz == 0) return;
		fprintf(mFile,"\tsetAttr \".rst[%i].rstz\" %i;\n", rst_i,rstz);
	}
	void setEnableTextureRate(bool etr)
	{
		if(etr == false) return;
		fprintf(mFile,"\tsetAttr \".etr\" %i;\n", etr);
	}
	void setTextureRate(const float3& txr)
	{
		if(txr == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".txr\" -type \"float3\" ");
		txr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTextureRateR(float txrr)
	{
		if(txrr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".txr.txrr\" %f;\n", txrr);
	}
	void setTextureRateG(float txrg)
	{
		if(txrg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".txr.txrg\" %f;\n", txrg);
	}
	void setTextureRateB(float txrb)
	{
		if(txrb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".txr.txrb\" %f;\n", txrb);
	}
	void setEmitFromDark(bool efd)
	{
		if(efd == false) return;
		fprintf(mFile,"\tsetAttr \".efd\" %i;\n", efd);
	}
	void setInheritColor(bool inhc)
	{
		if(inhc == false) return;
		fprintf(mFile,"\tsetAttr \".inhc\" %i;\n", inhc);
	}
	void setInheritOpacity(bool inho)
	{
		if(inho == false) return;
		fprintf(mFile,"\tsetAttr \".inho\" %i;\n", inho);
	}
	void setInvertOpacity(bool invo)
	{
		if(invo == false) return;
		fprintf(mFile,"\tsetAttr \".invo\" %i;\n", invo);
	}
	void setUseLuminance(bool usel)
	{
		if(usel == false) return;
		fprintf(mFile,"\tsetAttr \".usel\" %i;\n", usel);
	}
	void setParticleColor(const float3& pc)
	{
		if(pc == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".pc\" -type \"float3\" ");
		pc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setParticleColorR(float pcr)
	{
		if(pcr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".pc.pcr\" %f;\n", pcr);
	}
	void setParticleColorG(float pcg)
	{
		if(pcg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".pc.pcg\" %f;\n", pcg);
	}
	void setParticleColorB(float pcb)
	{
		if(pcb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".pc.pcb\" %f;\n", pcb);
	}
	void setVolumeShape(unsigned int vol)
	{
		if(vol == 0) return;
		fprintf(mFile,"\tsetAttr \".vol\" %i;\n", vol);
	}
	void setVolumeOffset(const double3& vof)
	{
		fprintf(mFile,"\tsetAttr \".vof\" -type \"double3\" ");
		vof.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVolumeOffsetX(double vfx)
	{
		if(vfx == 0) return;
		fprintf(mFile,"\tsetAttr \".vof.vfx\" %f;\n", vfx);
	}
	void setVolumeOffsetY(double vfy)
	{
		if(vfy == 0) return;
		fprintf(mFile,"\tsetAttr \".vof.vfy\" %f;\n", vfy);
	}
	void setVolumeOffsetZ(double vfz)
	{
		if(vfz == 0) return;
		fprintf(mFile,"\tsetAttr \".vof.vfz\" %f;\n", vfz);
	}
	void setVolumeSweep(double vsw)
	{
		if(vsw == 3) return;
		fprintf(mFile,"\tsetAttr \".vsw\" %f;\n", vsw);
	}
	void setSectionRadius(double vsr)
	{
		if(vsr == 0) return;
		fprintf(mFile,"\tsetAttr \".vsr\" %f;\n", vsr);
	}
	void setAwayFromCenter(double afc)
	{
		if(afc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".afc\" %f;\n", afc);
	}
	void setAwayFromAxis(double afa)
	{
		if(afa == 1.0) return;
		fprintf(mFile,"\tsetAttr \".afa\" %f;\n", afa);
	}
	void setAlongAxis(double alx)
	{
		if(alx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".alx\" %f;\n", alx);
	}
	void setAroundAxis(double arx)
	{
		if(arx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".arx\" %f;\n", arx);
	}
	void setRandomDirection(double rnd)
	{
		if(rnd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rnd\" %f;\n", rnd);
	}
	void setDirectionalSpeed(double drs)
	{
		if(drs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".drs\" %f;\n", drs);
	}
	void setScaleSpeedBySize(bool ssz)
	{
		if(ssz == false) return;
		fprintf(mFile,"\tsetAttr \".ssz\" %i;\n", ssz);
	}
	void setDisplaySpeed(bool dss)
	{
		if(dss == true) return;
		fprintf(mFile,"\tsetAttr \".dss\" %i;\n", dss);
	}
	void getEmitterType()const
	{
		fprintf(mFile,"\"%s.emt\"",mName.c_str());
	}
	void getRate()const
	{
		fprintf(mFile,"\"%s.rat\"",mName.c_str());
	}
	void getCycleEmission()const
	{
		fprintf(mFile,"\"%s.cye\"",mName.c_str());
	}
	void getCycleInterval()const
	{
		fprintf(mFile,"\"%s.cyi\"",mName.c_str());
	}
	void getMaxDistance()const
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());
	}
	void getMinDistance()const
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());
	}
	void getDirection()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getDirectionX()const
	{
		fprintf(mFile,"\"%s.d.dx\"",mName.c_str());
	}
	void getDirectionY()const
	{
		fprintf(mFile,"\"%s.d.dy\"",mName.c_str());
	}
	void getDirectionZ()const
	{
		fprintf(mFile,"\"%s.d.dz\"",mName.c_str());
	}
	void getSpread()const
	{
		fprintf(mFile,"\"%s.spr\"",mName.c_str());
	}
	void getSpeed()const
	{
		fprintf(mFile,"\"%s.spd\"",mName.c_str());
	}
	void getSpeedRandom()const
	{
		fprintf(mFile,"\"%s.srnd\"",mName.c_str());
	}
	void getTangentSpeed()const
	{
		fprintf(mFile,"\"%s.tspd\"",mName.c_str());
	}
	void getNormalSpeed()const
	{
		fprintf(mFile,"\"%s.nspd\"",mName.c_str());
	}
	void getCurrentTime()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getInheritFactor(size_t inh_i)const
	{
		fprintf(mFile,"\"%s.inh[%i]\"",mName.c_str(),inh_i);
	}
	void getInheritFactor()const
	{

		fprintf(mFile,"\"%s.inh\"",mName.c_str());
	}
	void getIsFull(size_t full_i)const
	{
		fprintf(mFile,"\"%s.full[%i]\"",mName.c_str(),full_i);
	}
	void getIsFull()const
	{

		fprintf(mFile,"\"%s.full\"",mName.c_str());
	}
	void getStartTime(size_t stt_i)const
	{
		fprintf(mFile,"\"%s.stt[%i]\"",mName.c_str(),stt_i);
	}
	void getStartTime()const
	{

		fprintf(mFile,"\"%s.stt\"",mName.c_str());
	}
	void getDeltaTime(size_t dt_i)const
	{
		fprintf(mFile,"\"%s.dt[%i]\"",mName.c_str(),dt_i);
	}
	void getDeltaTime()const
	{

		fprintf(mFile,"\"%s.dt\"",mName.c_str());
	}
	void getEmitCountRemainder(size_t ecr_i)const
	{
		fprintf(mFile,"\"%s.ecr[%i]\"",mName.c_str(),ecr_i);
	}
	void getEmitCountRemainder()const
	{

		fprintf(mFile,"\"%s.ecr\"",mName.c_str());
	}
	void getRatePP()const
	{
		fprintf(mFile,"\"%s.rpp\"",mName.c_str());
	}
	void getParentId()const
	{
		fprintf(mFile,"\"%s.paid\"",mName.c_str());
	}
	void getSweptGeometry()const
	{
		fprintf(mFile,"\"%s.swge\"",mName.c_str());
	}
	void getOutput(size_t ot_i)const
	{
		fprintf(mFile,"\"%s.ot[%i]\"",mName.c_str(),ot_i);
	}
	void getOutput()const
	{

		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getSeed(size_t sd_i)const
	{
		fprintf(mFile,"\"%s.sd[%i]\"",mName.c_str(),sd_i);
	}
	void getSeed()const
	{

		fprintf(mFile,"\"%s.sd\"",mName.c_str());
	}
	void getEnableTextureRate()const
	{
		fprintf(mFile,"\"%s.etr\"",mName.c_str());
	}
	void getTextureRate()const
	{
		fprintf(mFile,"\"%s.txr\"",mName.c_str());
	}
	void getTextureRateR()const
	{
		fprintf(mFile,"\"%s.txr.txrr\"",mName.c_str());
	}
	void getTextureRateG()const
	{
		fprintf(mFile,"\"%s.txr.txrg\"",mName.c_str());
	}
	void getTextureRateB()const
	{
		fprintf(mFile,"\"%s.txr.txrb\"",mName.c_str());
	}
	void getEmitFromDark()const
	{
		fprintf(mFile,"\"%s.efd\"",mName.c_str());
	}
	void getInheritColor()const
	{
		fprintf(mFile,"\"%s.inhc\"",mName.c_str());
	}
	void getInheritOpacity()const
	{
		fprintf(mFile,"\"%s.inho\"",mName.c_str());
	}
	void getInvertOpacity()const
	{
		fprintf(mFile,"\"%s.invo\"",mName.c_str());
	}
	void getUseLuminance()const
	{
		fprintf(mFile,"\"%s.usel\"",mName.c_str());
	}
	void getParticleColor()const
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getParticleColorR()const
	{
		fprintf(mFile,"\"%s.pc.pcr\"",mName.c_str());
	}
	void getParticleColorG()const
	{
		fprintf(mFile,"\"%s.pc.pcg\"",mName.c_str());
	}
	void getParticleColorB()const
	{
		fprintf(mFile,"\"%s.pc.pcb\"",mName.c_str());
	}
	void getVolumeShape()const
	{
		fprintf(mFile,"\"%s.vol\"",mName.c_str());
	}
	void getVolumeOffset()const
	{
		fprintf(mFile,"\"%s.vof\"",mName.c_str());
	}
	void getVolumeOffsetX()const
	{
		fprintf(mFile,"\"%s.vof.vfx\"",mName.c_str());
	}
	void getVolumeOffsetY()const
	{
		fprintf(mFile,"\"%s.vof.vfy\"",mName.c_str());
	}
	void getVolumeOffsetZ()const
	{
		fprintf(mFile,"\"%s.vof.vfz\"",mName.c_str());
	}
	void getVolumeEfficiency()const
	{
		fprintf(mFile,"\"%s.vef\"",mName.c_str());
	}
	void getVolumeSweep()const
	{
		fprintf(mFile,"\"%s.vsw\"",mName.c_str());
	}
	void getSectionRadius()const
	{
		fprintf(mFile,"\"%s.vsr\"",mName.c_str());
	}
	void getAwayFromCenter()const
	{
		fprintf(mFile,"\"%s.afc\"",mName.c_str());
	}
	void getAwayFromAxis()const
	{
		fprintf(mFile,"\"%s.afa\"",mName.c_str());
	}
	void getAlongAxis()const
	{
		fprintf(mFile,"\"%s.alx\"",mName.c_str());
	}
	void getAroundAxis()const
	{
		fprintf(mFile,"\"%s.arx\"",mName.c_str());
	}
	void getRandomDirection()const
	{
		fprintf(mFile,"\"%s.rnd\"",mName.c_str());
	}
	void getDirectionalSpeed()const
	{
		fprintf(mFile,"\"%s.drs\"",mName.c_str());
	}
	void getScaleSpeedBySize()const
	{
		fprintf(mFile,"\"%s.ssz\"",mName.c_str());
	}
	void getDisplaySpeed()const
	{
		fprintf(mFile,"\"%s.dss\"",mName.c_str());
	}
protected:
	PointEmitter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DynBase(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POINTEMITTER_H__
