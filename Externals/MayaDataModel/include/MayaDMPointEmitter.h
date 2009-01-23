/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PointEmitter(FILE* file,const std::string& name,const std::string& parent=""):DynBase(file, name, parent, "pointEmitter"){}
	virtual ~PointEmitter(){}
	void setEmitterType(unsigned int emt)
	{
		if(emt == 1) return;
		fprintf(mFile,"setAttr \".emt\" %i;\n", emt);

	}
	void setRate(double rat)
	{
		if(rat == 100) return;
		fprintf(mFile,"setAttr \".rat\" %f;\n", rat);

	}
	void setScaleRateByObjectSize(bool sro)
	{
		if(sro == true) return;
		fprintf(mFile,"setAttr \".sro\" %i;\n", sro);

	}
	void setUseRatePP(bool urpp)
	{
		if(urpp == false) return;
		fprintf(mFile,"setAttr \".urpp\" %i;\n", urpp);

	}
	void setNeedParentUV(bool npuv)
	{
		if(npuv == false) return;
		fprintf(mFile,"setAttr \".npuv\" %i;\n", npuv);

	}
	void setCycleEmission(unsigned int cye)
	{
		if(cye == 0) return;
		fprintf(mFile,"setAttr \".cye\" %i;\n", cye);

	}
	void setCycleInterval(int cyi)
	{
		if(cyi == 1) return;
		fprintf(mFile,"setAttr \".cyi\" %i;\n", cyi);

	}
	void setMaxDistance(double max)
	{
		if(max == 0) return;
		fprintf(mFile,"setAttr \".max\" %f;\n", max);

	}
	void setMinDistance(double min)
	{
		if(min == 0) return;
		fprintf(mFile,"setAttr \".min\" %f;\n", min);

	}
	void setDirection(const double3& d)
	{
		fprintf(mFile,"setAttr \".d\" -type \"double3\" ");
		d.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDirectionX(double dx)
	{
		if(dx == 1.0) return;
		fprintf(mFile,"setAttr \".d.dx\" %f;\n", dx);

	}
	void setDirectionY(double dy)
	{
		if(dy == 0.0) return;
		fprintf(mFile,"setAttr \".d.dy\" %f;\n", dy);

	}
	void setDirectionZ(double dz)
	{
		if(dz == 0.0) return;
		fprintf(mFile,"setAttr \".d.dz\" %f;\n", dz);

	}
	void setSpread(double spr)
	{
		if(spr == 0.0) return;
		fprintf(mFile,"setAttr \".spr\" %f;\n", spr);

	}
	void setSpeed(double spd)
	{
		if(spd == 1.0) return;
		fprintf(mFile,"setAttr \".spd\" %f;\n", spd);

	}
	void setSpeedRandom(double srnd)
	{
		if(srnd == 0.0) return;
		fprintf(mFile,"setAttr \".srnd\" %f;\n", srnd);

	}
	void setTangentSpeed(double tspd)
	{
		if(tspd == 0.0) return;
		fprintf(mFile,"setAttr \".tspd\" %f;\n", tspd);

	}
	void setNormalSpeed(double nspd)
	{
		if(nspd == 1.0) return;
		fprintf(mFile,"setAttr \".nspd\" %f;\n", nspd);

	}
	void setInheritFactor(size_t inh_i,double inh)
	{
		if(inh == 0.0) return;
		fprintf(mFile,"setAttr \".inh[%i]\" %f;\n", inh_i,inh);

	}
	void setInheritFactor(size_t inh_start,size_t inh_end,double* inh)
	{
		fprintf(mFile,"setAttr \".inh[%i:%i]\" ", inh_start,inh_end);
		size_t size = (inh_end-inh_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",inh[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startInheritFactor(size_t inh_start,size_t inh_end)
	{
		fprintf(mFile,"setAttr \".inh[%i:%i]\"",inh_start,inh_end);

	}
	void appendInheritFactor(double inh)
	{
		fprintf(mFile," %f",inh);

	}
	void endInheritFactor()
	{
		fprintf(mFile,";\n");

	}
	void setIsFull(size_t full_i,bool full)
	{
		if(full == false) return;
		fprintf(mFile,"setAttr \".full[%i]\" %i;\n", full_i,full);

	}
	void setIsFull(size_t full_start,size_t full_end,bool* full)
	{
		fprintf(mFile,"setAttr \".full[%i:%i]\" ", full_start,full_end);
		size_t size = (full_end-full_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",full[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startIsFull(size_t full_start,size_t full_end)
	{
		fprintf(mFile,"setAttr \".full[%i:%i]\"",full_start,full_end);

	}
	void appendIsFull(bool full)
	{
		fprintf(mFile," %i",full);

	}
	void endIsFull()
	{
		fprintf(mFile,";\n");

	}
	void setRatePP(const doubleArray& rpp)
	{
		if(rpp.size == 0) return;
		fprintf(mFile,"setAttr \".rpp\" -type \"doubleArray\" ");
		rpp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setParentId(const doubleArray& paid)
	{
		if(paid.size == 0) return;
		fprintf(mFile,"setAttr \".paid\" -type \"doubleArray\" ");
		paid.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRandStateX(size_t rst_i,int rstx)
	{
		if(rstx == 0) return;
		fprintf(mFile,"setAttr \".rst[%i].rstx\" %i;\n", rst_i,rstx);

	}
	void setRandStateY(size_t rst_i,int rsty)
	{
		if(rsty == 0) return;
		fprintf(mFile,"setAttr \".rst[%i].rsty\" %i;\n", rst_i,rsty);

	}
	void setRandStateZ(size_t rst_i,int rstz)
	{
		if(rstz == 0) return;
		fprintf(mFile,"setAttr \".rst[%i].rstz\" %i;\n", rst_i,rstz);

	}
	void setEnableTextureRate(bool etr)
	{
		if(etr == false) return;
		fprintf(mFile,"setAttr \".etr\" %i;\n", etr);

	}
	void setTextureRate(const float3& txr)
	{
		if(txr == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".txr\" -type \"float3\" ");
		txr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTextureRateR(float txrr)
	{
		if(txrr == 0.0) return;
		fprintf(mFile,"setAttr \".txr.txrr\" %f;\n", txrr);

	}
	void setTextureRateG(float txrg)
	{
		if(txrg == 0.0) return;
		fprintf(mFile,"setAttr \".txr.txrg\" %f;\n", txrg);

	}
	void setTextureRateB(float txrb)
	{
		if(txrb == 0.0) return;
		fprintf(mFile,"setAttr \".txr.txrb\" %f;\n", txrb);

	}
	void setEmitFromDark(bool efd)
	{
		if(efd == false) return;
		fprintf(mFile,"setAttr \".efd\" %i;\n", efd);

	}
	void setInheritColor(bool inhc)
	{
		if(inhc == false) return;
		fprintf(mFile,"setAttr \".inhc\" %i;\n", inhc);

	}
	void setInheritOpacity(bool inho)
	{
		if(inho == false) return;
		fprintf(mFile,"setAttr \".inho\" %i;\n", inho);

	}
	void setInvertOpacity(bool invo)
	{
		if(invo == false) return;
		fprintf(mFile,"setAttr \".invo\" %i;\n", invo);

	}
	void setUseLuminance(bool usel)
	{
		if(usel == false) return;
		fprintf(mFile,"setAttr \".usel\" %i;\n", usel);

	}
	void setParticleColor(const float3& pc)
	{
		if(pc == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"setAttr \".pc\" -type \"float3\" ");
		pc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setParticleColorR(float pcr)
	{
		if(pcr == 0.5) return;
		fprintf(mFile,"setAttr \".pc.pcr\" %f;\n", pcr);

	}
	void setParticleColorG(float pcg)
	{
		if(pcg == 0.5) return;
		fprintf(mFile,"setAttr \".pc.pcg\" %f;\n", pcg);

	}
	void setParticleColorB(float pcb)
	{
		if(pcb == 0.5) return;
		fprintf(mFile,"setAttr \".pc.pcb\" %f;\n", pcb);

	}
	void setVolumeShape(unsigned int vol)
	{
		if(vol == 0) return;
		fprintf(mFile,"setAttr \".vol\" %i;\n", vol);

	}
	void setVolumeOffset(const double3& vof)
	{
		fprintf(mFile,"setAttr \".vof\" -type \"double3\" ");
		vof.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVolumeOffsetX(double vfx)
	{
		if(vfx == 0) return;
		fprintf(mFile,"setAttr \".vof.vfx\" %f;\n", vfx);

	}
	void setVolumeOffsetY(double vfy)
	{
		if(vfy == 0) return;
		fprintf(mFile,"setAttr \".vof.vfy\" %f;\n", vfy);

	}
	void setVolumeOffsetZ(double vfz)
	{
		if(vfz == 0) return;
		fprintf(mFile,"setAttr \".vof.vfz\" %f;\n", vfz);

	}
	void setVolumeSweep(double vsw)
	{
		if(vsw == 3) return;
		fprintf(mFile,"setAttr \".vsw\" %f;\n", vsw);

	}
	void setSectionRadius(double vsr)
	{
		if(vsr == 0) return;
		fprintf(mFile,"setAttr \".vsr\" %f;\n", vsr);

	}
	void setAwayFromCenter(double afc)
	{
		if(afc == 1.0) return;
		fprintf(mFile,"setAttr \".afc\" %f;\n", afc);

	}
	void setAwayFromAxis(double afa)
	{
		if(afa == 1.0) return;
		fprintf(mFile,"setAttr \".afa\" %f;\n", afa);

	}
	void setAlongAxis(double alx)
	{
		if(alx == 0.0) return;
		fprintf(mFile,"setAttr \".alx\" %f;\n", alx);

	}
	void setAroundAxis(double arx)
	{
		if(arx == 0.0) return;
		fprintf(mFile,"setAttr \".arx\" %f;\n", arx);

	}
	void setRandomDirection(double rnd)
	{
		if(rnd == 0.0) return;
		fprintf(mFile,"setAttr \".rnd\" %f;\n", rnd);

	}
	void setDirectionalSpeed(double drs)
	{
		if(drs == 0.0) return;
		fprintf(mFile,"setAttr \".drs\" %f;\n", drs);

	}
	void setScaleSpeedBySize(bool ssz)
	{
		if(ssz == false) return;
		fprintf(mFile,"setAttr \".ssz\" %i;\n", ssz);

	}
	void setDisplaySpeed(bool dss)
	{
		if(dss == true) return;
		fprintf(mFile,"setAttr \".dss\" %i;\n", dss);

	}
	void getEmitterType()
	{
		fprintf(mFile,"\"%s.emt\"",mName.c_str());

	}
	void getRate()
	{
		fprintf(mFile,"\"%s.rat\"",mName.c_str());

	}
	void getCycleEmission()
	{
		fprintf(mFile,"\"%s.cye\"",mName.c_str());

	}
	void getCycleInterval()
	{
		fprintf(mFile,"\"%s.cyi\"",mName.c_str());

	}
	void getMaxDistance()
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());

	}
	void getMinDistance()
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getDirectionX()
	{
		fprintf(mFile,"\"%s.d.dx\"",mName.c_str());

	}
	void getDirectionY()
	{
		fprintf(mFile,"\"%s.d.dy\"",mName.c_str());

	}
	void getDirectionZ()
	{
		fprintf(mFile,"\"%s.d.dz\"",mName.c_str());

	}
	void getSpread()
	{
		fprintf(mFile,"\"%s.spr\"",mName.c_str());

	}
	void getSpeed()
	{
		fprintf(mFile,"\"%s.spd\"",mName.c_str());

	}
	void getSpeedRandom()
	{
		fprintf(mFile,"\"%s.srnd\"",mName.c_str());

	}
	void getTangentSpeed()
	{
		fprintf(mFile,"\"%s.tspd\"",mName.c_str());

	}
	void getNormalSpeed()
	{
		fprintf(mFile,"\"%s.nspd\"",mName.c_str());

	}
	void getCurrentTime()
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());

	}
	void getInheritFactor(size_t inh_i)
	{
		fprintf(mFile,"\"%s.inh[%i]\"",mName.c_str(),inh_i);

	}
	void getIsFull(size_t full_i)
	{
		fprintf(mFile,"\"%s.full[%i]\"",mName.c_str(),full_i);

	}
	void getStartTime(size_t stt_i)
	{
		fprintf(mFile,"\"%s.stt[%i]\"",mName.c_str(),stt_i);

	}
	void getDeltaTime(size_t dt_i)
	{
		fprintf(mFile,"\"%s.dt[%i]\"",mName.c_str(),dt_i);

	}
	void getEmitCountRemainder(size_t ecr_i)
	{
		fprintf(mFile,"\"%s.ecr[%i]\"",mName.c_str(),ecr_i);

	}
	void getSweptGeometry()
	{
		fprintf(mFile,"\"%s.swge\"",mName.c_str());

	}
	void getOutput(size_t ot_i)
	{
		fprintf(mFile,"\"%s.ot[%i]\"",mName.c_str(),ot_i);

	}
	void getSeed(size_t sd_i)
	{
		fprintf(mFile,"\"%s.sd[%i]\"",mName.c_str(),sd_i);

	}
	void getEnableTextureRate()
	{
		fprintf(mFile,"\"%s.etr\"",mName.c_str());

	}
	void getTextureRate()
	{
		fprintf(mFile,"\"%s.txr\"",mName.c_str());

	}
	void getTextureRateR()
	{
		fprintf(mFile,"\"%s.txr.txrr\"",mName.c_str());

	}
	void getTextureRateG()
	{
		fprintf(mFile,"\"%s.txr.txrg\"",mName.c_str());

	}
	void getTextureRateB()
	{
		fprintf(mFile,"\"%s.txr.txrb\"",mName.c_str());

	}
	void getEmitFromDark()
	{
		fprintf(mFile,"\"%s.efd\"",mName.c_str());

	}
	void getInheritColor()
	{
		fprintf(mFile,"\"%s.inhc\"",mName.c_str());

	}
	void getInheritOpacity()
	{
		fprintf(mFile,"\"%s.inho\"",mName.c_str());

	}
	void getInvertOpacity()
	{
		fprintf(mFile,"\"%s.invo\"",mName.c_str());

	}
	void getUseLuminance()
	{
		fprintf(mFile,"\"%s.usel\"",mName.c_str());

	}
	void getParticleColor()
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());

	}
	void getParticleColorR()
	{
		fprintf(mFile,"\"%s.pc.pcr\"",mName.c_str());

	}
	void getParticleColorG()
	{
		fprintf(mFile,"\"%s.pc.pcg\"",mName.c_str());

	}
	void getParticleColorB()
	{
		fprintf(mFile,"\"%s.pc.pcb\"",mName.c_str());

	}
	void getVolumeShape()
	{
		fprintf(mFile,"\"%s.vol\"",mName.c_str());

	}
	void getVolumeOffset()
	{
		fprintf(mFile,"\"%s.vof\"",mName.c_str());

	}
	void getVolumeOffsetX()
	{
		fprintf(mFile,"\"%s.vof.vfx\"",mName.c_str());

	}
	void getVolumeOffsetY()
	{
		fprintf(mFile,"\"%s.vof.vfy\"",mName.c_str());

	}
	void getVolumeOffsetZ()
	{
		fprintf(mFile,"\"%s.vof.vfz\"",mName.c_str());

	}
	void getVolumeEfficiency()
	{
		fprintf(mFile,"\"%s.vef\"",mName.c_str());

	}
	void getVolumeSweep()
	{
		fprintf(mFile,"\"%s.vsw\"",mName.c_str());

	}
	void getSectionRadius()
	{
		fprintf(mFile,"\"%s.vsr\"",mName.c_str());

	}
	void getAwayFromCenter()
	{
		fprintf(mFile,"\"%s.afc\"",mName.c_str());

	}
	void getAwayFromAxis()
	{
		fprintf(mFile,"\"%s.afa\"",mName.c_str());

	}
	void getAlongAxis()
	{
		fprintf(mFile,"\"%s.alx\"",mName.c_str());

	}
	void getAroundAxis()
	{
		fprintf(mFile,"\"%s.arx\"",mName.c_str());

	}
	void getRandomDirection()
	{
		fprintf(mFile,"\"%s.rnd\"",mName.c_str());

	}
	void getDirectionalSpeed()
	{
		fprintf(mFile,"\"%s.drs\"",mName.c_str());

	}
	void getScaleSpeedBySize()
	{
		fprintf(mFile,"\"%s.ssz\"",mName.c_str());

	}
	void getDisplaySpeed()
	{
		fprintf(mFile,"\"%s.dss\"",mName.c_str());

	}
protected:
	PointEmitter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DynBase(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POINTEMITTER_H__
