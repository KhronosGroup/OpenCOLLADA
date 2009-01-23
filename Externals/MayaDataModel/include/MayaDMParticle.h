/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLE_H__
#define __MayaDM_PARTICLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformableShape.h"
namespace MayaDM
{
class Particle : public DeformableShape
{
public:
	struct IdMapping{
		void write(FILE* file) const
		{
		}
	};
	struct FieldData{
		void write(FILE* file) const
		{
		}
	};
	struct EmitterData{
		void write(FILE* file) const
		{
		}
	};
	struct CollisionData{
		void write(FILE* file) const
		{
		}
	};
	struct InstanceData{
		stringArray instanceAttributeMapping;
		void write(FILE* file) const
		{
			instanceAttributeMapping.write(file);
			fprintf(file, " ");
		}
	};
	struct MentalRayControls{
		bool miOverrideCaustics;
		short miCausticAccuracy;
		float miCausticRadius;
		bool miOverrideGlobalIllumination;
		short miGlobillumAccuracy;
		float miGlobillumRadius;
		bool miOverrideFinalGather;
		int miFinalGatherRays;
		float miFinalGatherMinRadius;
		float miFinalGatherMaxRadius;
		short miFinalGatherFilter;
		bool miFinalGatherView;
		bool miOverrideSamples;
		short miMinSamples;
		short miMaxSamples;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", miOverrideCaustics);
			fprintf(file,"%i ", miCausticAccuracy);
			fprintf(file,"%f ", miCausticRadius);
			fprintf(file,"%i ", miOverrideGlobalIllumination);
			fprintf(file,"%i ", miGlobillumAccuracy);
			fprintf(file,"%f ", miGlobillumRadius);
			fprintf(file,"%i ", miOverrideFinalGather);
			fprintf(file,"%i ", miFinalGatherRays);
			fprintf(file,"%f ", miFinalGatherMinRadius);
			fprintf(file,"%f ", miFinalGatherMaxRadius);
			fprintf(file,"%i ", miFinalGatherFilter);
			fprintf(file,"%i ", miFinalGatherView);
			fprintf(file,"%i ", miOverrideSamples);
			fprintf(file,"%i ", miMinSamples);
			fprintf(file,"%i", miMaxSamples);
		}
	};
public:
	Particle(FILE* file,const std::string& name,const std::string& parent=""):DeformableShape(file, name, parent, "particle"){}
	virtual ~Particle(){}
	void setPosition0(const vectorArray& pos0)
	{
		if(pos0.size == 0) return;
		fprintf(mFile,"setAttr \".pos0\" -type \"vectorArray\" ");
		pos0.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVelocity0(const vectorArray& vel0)
	{
		if(vel0.size == 0) return;
		fprintf(mFile,"setAttr \".vel0\" -type \"vectorArray\" ");
		vel0.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAcceleration0(const vectorArray& acc0)
	{
		if(acc0.size == 0) return;
		fprintf(mFile,"setAttr \".acc0\" -type \"vectorArray\" ");
		acc0.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUseStartupCache(bool usc)
	{
		if(usc == false) return;
		fprintf(mFile,"setAttr \".usc\" %i;\n", usc);

	}
	void setStartupCachePath(const string& scp)
	{
		if(scp == "NULL") return;
		fprintf(mFile,"setAttr \".scp\" -type \"string\" ");
		scp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStartupCacheFrame(int scf)
	{
		if(scf == 0) return;
		fprintf(mFile,"setAttr \".scf\" %i;\n", scf);

	}
	void setMass0(const doubleArray& mas0)
	{
		if(mas0.size == 0) return;
		fprintf(mFile,"setAttr \".mas0\" -type \"doubleArray\" ");
		mas0.write(mFile);
		fprintf(mFile,";\n");

	}
	void setParticleId0(const doubleArray& id0)
	{
		if(id0.size == 0) return;
		fprintf(mFile,"setAttr \".id0\" -type \"doubleArray\" ");
		id0.write(mFile);
		fprintf(mFile,";\n");

	}
	void setNextId(int nid)
	{
		if(nid == 0) return;
		fprintf(mFile,"setAttr \".nid\" %i;\n", nid);

	}
	void setNextId0(int nid0)
	{
		if(nid0 == 0) return;
		fprintf(mFile,"setAttr \".nid0\" %i;\n", nid0);

	}
	void setBirthTime0(const doubleArray& bt0)
	{
		if(bt0.size == 0) return;
		fprintf(mFile,"setAttr \".bt0\" -type \"doubleArray\" ");
		bt0.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAge0(const doubleArray& ag0)
	{
		if(ag0.size == 0) return;
		fprintf(mFile,"setAttr \".ag0\" -type \"doubleArray\" ");
		ag0.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDieOnEmissionVolumeExit(bool dve)
	{
		if(dve == false) return;
		fprintf(mFile,"setAttr \".dve\" %i;\n", dve);

	}
	void setLifespanMode(unsigned int lfm)
	{
		if(lfm == 0) return;
		fprintf(mFile,"setAttr \".lfm\" %i;\n", lfm);

	}
	void setLifespanRandom(double lfr)
	{
		if(lfr == 0.0) return;
		fprintf(mFile,"setAttr \".lfr\" %f;\n", lfr);

	}
	void setExpressionsAfterDynamics(bool ead)
	{
		if(ead == false) return;
		fprintf(mFile,"setAttr \".ead\" %i;\n", ead);

	}
	void setInternalRuntimeBeforeDynamicsExpression(const string& irbx)
	{
		if(irbx == "NULL") return;
		fprintf(mFile,"setAttr \".irbx\" -type \"string\" ");
		irbx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInternalRuntimeAfterDynamicsExpression(const string& irax)
	{
		if(irax == "NULL") return;
		fprintf(mFile,"setAttr \".irax\" -type \"string\" ");
		irax.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInternalCreationExpression(const string& icx)
	{
		if(icx == "NULL") return;
		fprintf(mFile,"setAttr \".icx\" -type \"string\" ");
		icx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIsDynamic(bool isd)
	{
		if(isd == true) return;
		fprintf(mFile,"setAttr \".isd\" %i;\n", isd);

	}
	void setDynamicsWeight(double dw)
	{
		if(dw == 1.0) return;
		fprintf(mFile,"setAttr \".dw\" %f;\n", dw);

	}
	void setForcesInWorld(bool fiw)
	{
		if(fiw == true) return;
		fprintf(mFile,"setAttr \".fiw\" %i;\n", fiw);

	}
	void setConserve(double con)
	{
		if(con == 1.0) return;
		fprintf(mFile,"setAttr \".con\" %f;\n", con);

	}
	void setEmissionInWorld(bool eiw)
	{
		if(eiw == true) return;
		fprintf(mFile,"setAttr \".eiw\" %i;\n", eiw);

	}
	void setMaxCount(int mxc)
	{
		if(mxc == -1) return;
		fprintf(mFile,"setAttr \".mxc\" %i;\n", mxc);

	}
	void setLevelOfDetail(double lod)
	{
		if(lod == 1) return;
		fprintf(mFile,"setAttr \".lod\" %f;\n", lod);

	}
	void setInheritFactor(double inh)
	{
		if(inh == 0.0) return;
		fprintf(mFile,"setAttr \".inh\" %f;\n", inh);

	}
	void setSeed(size_t sd_i,int sd)
	{
		if(sd == 1) return;
		fprintf(mFile,"setAttr \".sd[%i]\" %i;\n", sd_i,sd);

	}
	void setSeed(size_t sd_start,size_t sd_end,int* sd)
	{
		fprintf(mFile,"setAttr \".sd[%i:%i]\" ", sd_start,sd_end);
		size_t size = (sd_end-sd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",sd[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startSeed(size_t sd_start,size_t sd_end)
	{
		fprintf(mFile,"setAttr \".sd[%i:%i]\"",sd_start,sd_end);

	}
	void appendSeed(int sd)
	{
		fprintf(mFile," %i",sd);

	}
	void endSeed()
	{
		fprintf(mFile,";\n");

	}
	void setStartFrame(double stf)
	{
		if(stf == 1.0) return;
		fprintf(mFile,"setAttr \".stf\" %f;\n", stf);

	}
	void setInputGeometrySpace(unsigned int igs)
	{
		if(igs == 0) return;
		fprintf(mFile,"setAttr \".igs\" %i;\n", igs);

	}
	void setEnforceCountFromHistory(bool ecfh)
	{
		if(ecfh == true) return;
		fprintf(mFile,"setAttr \".ecfh\" %i;\n", ecfh);

	}
	void setTargetGeometrySpace(unsigned int tgs)
	{
		if(tgs == 2) return;
		fprintf(mFile,"setAttr \".tgs\" %i;\n", tgs);

	}
	void setGoalSmoothness(double gsm)
	{
		if(gsm == 3) return;
		fprintf(mFile,"setAttr \".gsm\" %f;\n", gsm);

	}
	void setGoalWeight(size_t gw_i,double gw)
	{
		if(gw == 0.0) return;
		fprintf(mFile,"setAttr \".gw[%i]\" %f;\n", gw_i,gw);

	}
	void setGoalWeight(size_t gw_start,size_t gw_end,double* gw)
	{
		fprintf(mFile,"setAttr \".gw[%i:%i]\" ", gw_start,gw_end);
		size_t size = (gw_end-gw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",gw[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startGoalWeight(size_t gw_start,size_t gw_end)
	{
		fprintf(mFile,"setAttr \".gw[%i:%i]\"",gw_start,gw_end);

	}
	void appendGoalWeight(double gw)
	{
		fprintf(mFile," %f",gw);

	}
	void endGoalWeight()
	{
		fprintf(mFile,";\n");

	}
	void setGoalActive(size_t ga_i,bool ga)
	{
		if(ga == true) return;
		fprintf(mFile,"setAttr \".ga[%i]\" %i;\n", ga_i,ga);

	}
	void setGoalActive(size_t ga_start,size_t ga_end,bool* ga)
	{
		fprintf(mFile,"setAttr \".ga[%i:%i]\" ", ga_start,ga_end);
		size_t size = (ga_end-ga_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ga[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startGoalActive(size_t ga_start,size_t ga_end)
	{
		fprintf(mFile,"setAttr \".ga[%i:%i]\"",ga_start,ga_end);

	}
	void appendGoalActive(bool ga)
	{
		fprintf(mFile," %i",ga);

	}
	void endGoalActive()
	{
		fprintf(mFile,";\n");

	}
	void setGoalUvSetName(size_t guv_i,const string& guv)
	{
		if(guv == "NULL") return;
		fprintf(mFile,"setAttr \".guv[%i]\" -type \"string\" ",guv_i);
		guv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGoalUvSetName(size_t guv_start,size_t guv_end,string* guv)
	{
		fprintf(mFile,"setAttr \".guv[%i:%i]\" ", guv_start,guv_end);
		size_t size = (guv_end-guv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			guv[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startGoalUvSetName(size_t guv_start,size_t guv_end)
	{
		fprintf(mFile,"setAttr \".guv[%i:%i]\"",guv_start,guv_end);
		fprintf(mFile," -type \"string\" ");

	}
	void appendGoalUvSetName(const string& guv)
	{
		fprintf(mFile,"\n");
		guv.write(mFile);

	}
	void endGoalUvSetName()
	{
		fprintf(mFile,";\n");

	}
	void setCacheData(bool chd)
	{
		if(chd == 0) return;
		fprintf(mFile,"setAttr \".chd\" %i;\n", chd);

	}
	void setCacheWidth(int chw)
	{
		if(chw == 1) return;
		fprintf(mFile,"setAttr \".chw\" %i;\n", chw);

	}
	void setTraceDepth(int trd)
	{
		if(trd == 10) return;
		fprintf(mFile,"setAttr \".trd\" %i;\n", trd);

	}
	void setEventName(size_t evn_i,const string& evn)
	{
		if(evn == "NULL") return;
		fprintf(mFile,"setAttr \".evn[%i]\" -type \"string\" ",evn_i);
		evn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEventName(size_t evn_start,size_t evn_end,string* evn)
	{
		fprintf(mFile,"setAttr \".evn[%i:%i]\" ", evn_start,evn_end);
		size_t size = (evn_end-evn_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			evn[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startEventName(size_t evn_start,size_t evn_end)
	{
		fprintf(mFile,"setAttr \".evn[%i:%i]\"",evn_start,evn_end);
		fprintf(mFile," -type \"string\" ");

	}
	void appendEventName(const string& evn)
	{
		fprintf(mFile,"\n");
		evn.write(mFile);

	}
	void endEventName()
	{
		fprintf(mFile,";\n");

	}
	void setEventValid(size_t evv_i,int evv)
	{
		if(evv == -1) return;
		fprintf(mFile,"setAttr \".evv[%i]\" %i;\n", evv_i,evv);

	}
	void setEventValid(size_t evv_start,size_t evv_end,int* evv)
	{
		fprintf(mFile,"setAttr \".evv[%i:%i]\" ", evv_start,evv_end);
		size_t size = (evv_end-evv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",evv[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEventValid(size_t evv_start,size_t evv_end)
	{
		fprintf(mFile,"setAttr \".evv[%i:%i]\"",evv_start,evv_end);

	}
	void appendEventValid(int evv)
	{
		fprintf(mFile," %i",evv);

	}
	void endEventValid()
	{
		fprintf(mFile,";\n");

	}
	void setEventCount(size_t ecp_i,short ecp)
	{
		if(ecp == -1) return;
		fprintf(mFile,"setAttr \".ecp[%i]\" %i;\n", ecp_i,ecp);

	}
	void setEventCount(size_t ecp_start,size_t ecp_end,short* ecp)
	{
		fprintf(mFile,"setAttr \".ecp[%i:%i]\" ", ecp_start,ecp_end);
		size_t size = (ecp_end-ecp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ecp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEventCount(size_t ecp_start,size_t ecp_end)
	{
		fprintf(mFile,"setAttr \".ecp[%i:%i]\"",ecp_start,ecp_end);

	}
	void appendEventCount(short ecp)
	{
		fprintf(mFile," %i",ecp);

	}
	void endEventCount()
	{
		fprintf(mFile,";\n");

	}
	void setEventEmit(size_t eve_i,short eve)
	{
		if(eve == -1) return;
		fprintf(mFile,"setAttr \".eve[%i]\" %i;\n", eve_i,eve);

	}
	void setEventEmit(size_t eve_start,size_t eve_end,short* eve)
	{
		fprintf(mFile,"setAttr \".eve[%i:%i]\" ", eve_start,eve_end);
		size_t size = (eve_end-eve_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",eve[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEventEmit(size_t eve_start,size_t eve_end)
	{
		fprintf(mFile,"setAttr \".eve[%i:%i]\"",eve_start,eve_end);

	}
	void appendEventEmit(short eve)
	{
		fprintf(mFile," %i",eve);

	}
	void endEventEmit()
	{
		fprintf(mFile,";\n");

	}
	void setEventSplit(size_t evs_i,short evs)
	{
		if(evs == -1) return;
		fprintf(mFile,"setAttr \".evs[%i]\" %i;\n", evs_i,evs);

	}
	void setEventSplit(size_t evs_start,size_t evs_end,short* evs)
	{
		fprintf(mFile,"setAttr \".evs[%i:%i]\" ", evs_start,evs_end);
		size_t size = (evs_end-evs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",evs[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEventSplit(size_t evs_start,size_t evs_end)
	{
		fprintf(mFile,"setAttr \".evs[%i:%i]\"",evs_start,evs_end);

	}
	void appendEventSplit(short evs)
	{
		fprintf(mFile," %i",evs);

	}
	void endEventSplit()
	{
		fprintf(mFile,";\n");

	}
	void setEventDie(size_t evd_i,short evd)
	{
		if(evd == -1) return;
		fprintf(mFile,"setAttr \".evd[%i]\" %i;\n", evd_i,evd);

	}
	void setEventDie(size_t evd_start,size_t evd_end,short* evd)
	{
		fprintf(mFile,"setAttr \".evd[%i:%i]\" ", evd_start,evd_end);
		size_t size = (evd_end-evd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",evd[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEventDie(size_t evd_start,size_t evd_end)
	{
		fprintf(mFile,"setAttr \".evd[%i:%i]\"",evd_start,evd_end);

	}
	void appendEventDie(short evd)
	{
		fprintf(mFile," %i",evd);

	}
	void endEventDie()
	{
		fprintf(mFile,";\n");

	}
	void setEventRandom(size_t evr_i,short evr)
	{
		if(evr == -1) return;
		fprintf(mFile,"setAttr \".evr[%i]\" %i;\n", evr_i,evr);

	}
	void setEventRandom(size_t evr_start,size_t evr_end,short* evr)
	{
		fprintf(mFile,"setAttr \".evr[%i:%i]\" ", evr_start,evr_end);
		size_t size = (evr_end-evr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",evr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEventRandom(size_t evr_start,size_t evr_end)
	{
		fprintf(mFile,"setAttr \".evr[%i:%i]\"",evr_start,evr_end);

	}
	void appendEventRandom(short evr)
	{
		fprintf(mFile," %i",evr);

	}
	void endEventRandom()
	{
		fprintf(mFile,";\n");

	}
	void setEventSpread(size_t esp_i,double esp)
	{
		if(esp == -1.0) return;
		fprintf(mFile,"setAttr \".esp[%i]\" %f;\n", esp_i,esp);

	}
	void setEventSpread(size_t esp_start,size_t esp_end,double* esp)
	{
		fprintf(mFile,"setAttr \".esp[%i:%i]\" ", esp_start,esp_end);
		size_t size = (esp_end-esp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",esp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEventSpread(size_t esp_start,size_t esp_end)
	{
		fprintf(mFile,"setAttr \".esp[%i:%i]\"",esp_start,esp_end);

	}
	void appendEventSpread(double esp)
	{
		fprintf(mFile," %f",esp);

	}
	void endEventSpread()
	{
		fprintf(mFile,";\n");

	}
	void setEventProc(size_t epr_i,const string& epr)
	{
		if(epr == "NULL") return;
		fprintf(mFile,"setAttr \".epr[%i]\" -type \"string\" ",epr_i);
		epr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEventProc(size_t epr_start,size_t epr_end,string* epr)
	{
		fprintf(mFile,"setAttr \".epr[%i:%i]\" ", epr_start,epr_end);
		size_t size = (epr_end-epr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			epr[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startEventProc(size_t epr_start,size_t epr_end)
	{
		fprintf(mFile,"setAttr \".epr[%i:%i]\"",epr_start,epr_end);
		fprintf(mFile," -type \"string\" ");

	}
	void appendEventProc(const string& epr)
	{
		fprintf(mFile,"\n");
		epr.write(mFile);

	}
	void endEventProc()
	{
		fprintf(mFile,";\n");

	}
	void setInstanceData(size_t idt_i,const InstanceData& idt)
	{
		fprintf(mFile,"setAttr \".idt[%i]\" ",idt_i);
		idt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInstanceAttributeMapping(size_t idt_i,const stringArray& iam)
	{
		fprintf(mFile,"setAttr \".idt[%i].iam\" -type \"stringArray\" ",idt_i);
		iam.write(mFile);
		fprintf(mFile,";\n");

	}
	void setNewFileFormat(short nff)
	{
		if(nff == 0) return;
		fprintf(mFile,"setAttr \".nff\" %i;\n", nff);

	}
	void setDepthSort(bool ds)
	{
		if(ds == false) return;
		fprintf(mFile,"setAttr \".ds\" %i;\n", ds);

	}
	void setParticleRenderType(unsigned int prt)
	{
		if(prt == 3) return;
		fprintf(mFile,"setAttr \".prt\" %i;\n", prt);

	}
	void setDisableCloudAxis(bool dca)
	{
		if(dca == false) return;
		fprintf(mFile,"setAttr \".dca\" %i;\n", dca);

	}
	void setNormalizeVelocity(bool nvl)
	{
		if(nvl == false) return;
		fprintf(mFile,"setAttr \".nvl\" %i;\n", nvl);

	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"setAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiOverrideCaustics(bool oca)
	{
		if(oca == false) return;
		fprintf(mFile,"setAttr \".mrc.oca\" %i;\n", oca);

	}
	void setMiCausticAccuracy(short caa)
	{
		if(caa == 64) return;
		fprintf(mFile,"setAttr \".mrc.caa\" %i;\n", caa);

	}
	void setMiCausticRadius(float car)
	{
		if(car == 0) return;
		fprintf(mFile,"setAttr \".mrc.car\" %f;\n", car);

	}
	void setMiOverrideGlobalIllumination(bool ogi)
	{
		if(ogi == false) return;
		fprintf(mFile,"setAttr \".mrc.ogi\" %i;\n", ogi);

	}
	void setMiGlobillumAccuracy(short gia)
	{
		if(gia == 64) return;
		fprintf(mFile,"setAttr \".mrc.gia\" %i;\n", gia);

	}
	void setMiGlobillumRadius(float gir)
	{
		if(gir == 0) return;
		fprintf(mFile,"setAttr \".mrc.gir\" %f;\n", gir);

	}
	void setMiOverrideFinalGather(bool ofg)
	{
		if(ofg == false) return;
		fprintf(mFile,"setAttr \".mrc.ofg\" %i;\n", ofg);

	}
	void setMiFinalGatherRays(int fry)
	{
		if(fry == 1000) return;
		fprintf(mFile,"setAttr \".mrc.fry\" %i;\n", fry);

	}
	void setMiFinalGatherMinRadius(float fmn)
	{
		if(fmn == 0) return;
		fprintf(mFile,"setAttr \".mrc.fmn\" %f;\n", fmn);

	}
	void setMiFinalGatherMaxRadius(float fmx)
	{
		if(fmx == 0) return;
		fprintf(mFile,"setAttr \".mrc.fmx\" %f;\n", fmx);

	}
	void setMiFinalGatherFilter(short ffi)
	{
		if(ffi == 1) return;
		fprintf(mFile,"setAttr \".mrc.ffi\" %i;\n", ffi);

	}
	void setMiFinalGatherView(bool fgv)
	{
		if(fgv == false) return;
		fprintf(mFile,"setAttr \".mrc.fgv\" %i;\n", fgv);

	}
	void setMiOverrideSamples(bool oos)
	{
		if(oos == false) return;
		fprintf(mFile,"setAttr \".mrc.oos\" %i;\n", oos);

	}
	void setMiMinSamples(short mins)
	{
		if(mins == 1) return;
		fprintf(mFile,"setAttr \".mrc.mins\" %i;\n", mins);

	}
	void setMiMaxSamples(short maxs)
	{
		if(maxs == 2) return;
		fprintf(mFile,"setAttr \".mrc.maxs\" %i;\n", maxs);

	}
	void getPosition()
	{
		fprintf(mFile,"\"%s.pos\"",mName.c_str());

	}
	void getRampPosition()
	{
		fprintf(mFile,"\"%s.rps\"",mName.c_str());

	}
	void getCentroid()
	{
		fprintf(mFile,"\"%s.ctd\"",mName.c_str());

	}
	void getCentroidX()
	{
		fprintf(mFile,"\"%s.ctd.ctdx\"",mName.c_str());

	}
	void getCentroidY()
	{
		fprintf(mFile,"\"%s.ctd.ctdy\"",mName.c_str());

	}
	void getCentroidZ()
	{
		fprintf(mFile,"\"%s.ctd.ctdz\"",mName.c_str());

	}
	void getLastPosition()
	{
		fprintf(mFile,"\"%s.lpos\"",mName.c_str());

	}
	void getVelocity()
	{
		fprintf(mFile,"\"%s.vel\"",mName.c_str());

	}
	void getRampVelocity()
	{
		fprintf(mFile,"\"%s.rvl\"",mName.c_str());

	}
	void getLastVelocity()
	{
		fprintf(mFile,"\"%s.lvel\"",mName.c_str());

	}
	void getAcceleration()
	{
		fprintf(mFile,"\"%s.acc\"",mName.c_str());

	}
	void getRampAcceleration()
	{
		fprintf(mFile,"\"%s.rac\"",mName.c_str());

	}
	void getForce()
	{
		fprintf(mFile,"\"%s.frc\"",mName.c_str());

	}
	void getInputForce(size_t ifc_i)
	{
		fprintf(mFile,"\"%s.ifc[%i]\"",mName.c_str(),ifc_i);

	}
	void getWorldPosition()
	{
		fprintf(mFile,"\"%s.wps\"",mName.c_str());

	}
	void getWorldCentroid()
	{
		fprintf(mFile,"\"%s.wctn\"",mName.c_str());

	}
	void getWorldCentroidX()
	{
		fprintf(mFile,"\"%s.wctn.wctx\"",mName.c_str());

	}
	void getWorldCentroidY()
	{
		fprintf(mFile,"\"%s.wctn.wcty\"",mName.c_str());

	}
	void getWorldCentroidZ()
	{
		fprintf(mFile,"\"%s.wctn.wctz\"",mName.c_str());

	}
	void getLastWorldPosition()
	{
		fprintf(mFile,"\"%s.lwps\"",mName.c_str());

	}
	void getWorldVelocity()
	{
		fprintf(mFile,"\"%s.wvl\"",mName.c_str());

	}
	void getWorldVelocityInObjectSpace()
	{
		fprintf(mFile,"\"%s.wvo\"",mName.c_str());

	}
	void getLastWorldVelocity()
	{
		fprintf(mFile,"\"%s.lwvl\"",mName.c_str());

	}
	void getLastWorldMatrix()
	{
		fprintf(mFile,"\"%s.lwm\"",mName.c_str());

	}
	void getPosition0()
	{
		fprintf(mFile,"\"%s.pos0\"",mName.c_str());

	}
	void getVelocity0()
	{
		fprintf(mFile,"\"%s.vel0\"",mName.c_str());

	}
	void getAcceleration0()
	{
		fprintf(mFile,"\"%s.acc0\"",mName.c_str());

	}
	void getStartupCachePath()
	{
		fprintf(mFile,"\"%s.scp\"",mName.c_str());

	}
	void getStartupCacheFrame()
	{
		fprintf(mFile,"\"%s.scf\"",mName.c_str());

	}
	void getCachedPosition()
	{
		fprintf(mFile,"\"%s.cpos\"",mName.c_str());

	}
	void getLastCachedPosition()
	{
		fprintf(mFile,"\"%s.lcps\"",mName.c_str());

	}
	void getCachedWorldPosition()
	{
		fprintf(mFile,"\"%s.cwps\"",mName.c_str());

	}
	void getCachedWorldCentroid()
	{
		fprintf(mFile,"\"%s.cwcn\"",mName.c_str());

	}
	void getCachedWorldCentroidX()
	{
		fprintf(mFile,"\"%s.cwcn.cwcx\"",mName.c_str());

	}
	void getCachedWorldCentroidY()
	{
		fprintf(mFile,"\"%s.cwcn.cwcy\"",mName.c_str());

	}
	void getCachedWorldCentroidZ()
	{
		fprintf(mFile,"\"%s.cwcn.cwcz\"",mName.c_str());

	}
	void getCachedVelocity()
	{
		fprintf(mFile,"\"%s.cvel\"",mName.c_str());

	}
	void getCachedWorldVelocity()
	{
		fprintf(mFile,"\"%s.cwvl\"",mName.c_str());

	}
	void getCount()
	{
		fprintf(mFile,"\"%s.cnt\"",mName.c_str());

	}
	void getMass()
	{
		fprintf(mFile,"\"%s.mas\"",mName.c_str());

	}
	void getMass0()
	{
		fprintf(mFile,"\"%s.mas0\"",mName.c_str());

	}
	void getMassCache()
	{
		fprintf(mFile,"\"%s.masc\"",mName.c_str());

	}
	void getParticleId()
	{
		fprintf(mFile,"\"%s.id\"",mName.c_str());

	}
	void getParticleId0()
	{
		fprintf(mFile,"\"%s.id0\"",mName.c_str());

	}
	void getIdCache()
	{
		fprintf(mFile,"\"%s.idc\"",mName.c_str());

	}
	void getIdMapping()
	{
		fprintf(mFile,"\"%s.idm\"",mName.c_str());

	}
	void getSortedId()
	{
		fprintf(mFile,"\"%s.idm.sid\"",mName.c_str());

	}
	void getIdIndex()
	{
		fprintf(mFile,"\"%s.idm.idix\"",mName.c_str());

	}
	void getBirthTime()
	{
		fprintf(mFile,"\"%s.bt\"",mName.c_str());

	}
	void getBirthTime0()
	{
		fprintf(mFile,"\"%s.bt0\"",mName.c_str());

	}
	void getBirthTimeCache()
	{
		fprintf(mFile,"\"%s.btc\"",mName.c_str());

	}
	void getAge()
	{
		fprintf(mFile,"\"%s.ag\"",mName.c_str());

	}
	void getAge0()
	{
		fprintf(mFile,"\"%s.ag0\"",mName.c_str());

	}
	void getAgeCache()
	{
		fprintf(mFile,"\"%s.agc\"",mName.c_str());

	}
	void getEmission()
	{
		fprintf(mFile,"\"%s.emt\"",mName.c_str());

	}
	void getDieOnEmissionVolumeExit()
	{
		fprintf(mFile,"\"%s.dve\"",mName.c_str());

	}
	void getIsFull()
	{
		fprintf(mFile,"\"%s.ifl\"",mName.c_str());

	}
	void getLifespanMode()
	{
		fprintf(mFile,"\"%s.lfm\"",mName.c_str());

	}
	void getLifespanRandom()
	{
		fprintf(mFile,"\"%s.lfr\"",mName.c_str());

	}
	void getFinalLifespanPP()
	{
		fprintf(mFile,"\"%s.flp\"",mName.c_str());

	}
	void getExpressionsAfterDynamics()
	{
		fprintf(mFile,"\"%s.ead\"",mName.c_str());

	}
	void getInput(size_t xi_i)
	{
		fprintf(mFile,"\"%s.xi[%i]\"",mName.c_str(),xi_i);

	}
	void getOutput(size_t xo_i)
	{
		fprintf(mFile,"\"%s.xo[%i]\"",mName.c_str(),xo_i);

	}
	void getDiedLastTime()
	{
		fprintf(mFile,"\"%s.dlt\"",mName.c_str());

	}
	void getNetEmittedLastTime()
	{
		fprintf(mFile,"\"%s.nlt\"",mName.c_str());

	}
	void getStartEmittedIndex()
	{
		fprintf(mFile,"\"%s.sei\"",mName.c_str());

	}
	void getIsDynamic()
	{
		fprintf(mFile,"\"%s.isd\"",mName.c_str());

	}
	void getDynamicsWeight()
	{
		fprintf(mFile,"\"%s.dw\"",mName.c_str());

	}
	void getForcesInWorld()
	{
		fprintf(mFile,"\"%s.fiw\"",mName.c_str());

	}
	void getConserve()
	{
		fprintf(mFile,"\"%s.con\"",mName.c_str());

	}
	void getEmissionInWorld()
	{
		fprintf(mFile,"\"%s.eiw\"",mName.c_str());

	}
	void getMaxCount()
	{
		fprintf(mFile,"\"%s.mxc\"",mName.c_str());

	}
	void getLevelOfDetail()
	{
		fprintf(mFile,"\"%s.lod\"",mName.c_str());

	}
	void getInheritFactor()
	{
		fprintf(mFile,"\"%s.inh\"",mName.c_str());

	}
	void getSeed(size_t sd_i)
	{
		fprintf(mFile,"\"%s.sd[%i]\"",mName.c_str(),sd_i);

	}
	void getFieldData()
	{
		fprintf(mFile,"\"%s.fd\"",mName.c_str());

	}
	void getFieldDataPosition()
	{
		fprintf(mFile,"\"%s.fd.fdp\"",mName.c_str());

	}
	void getFieldDataVelocity()
	{
		fprintf(mFile,"\"%s.fd.fdv\"",mName.c_str());

	}
	void getFieldDataMass()
	{
		fprintf(mFile,"\"%s.fd.fdm\"",mName.c_str());

	}
	void getFieldDataDeltaTime()
	{
		fprintf(mFile,"\"%s.fd.fdt\"",mName.c_str());

	}
	void getEmitterData()
	{
		fprintf(mFile,"\"%s.ed\"",mName.c_str());

	}
	void getEmitterDataPosition()
	{
		fprintf(mFile,"\"%s.ed.edp\"",mName.c_str());

	}
	void getEmitterDataVelocity()
	{
		fprintf(mFile,"\"%s.ed.edv\"",mName.c_str());

	}
	void getEmitterDataDeltaTime()
	{
		fprintf(mFile,"\"%s.ed.edt\"",mName.c_str());

	}
	void getCurrentTime()
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());

	}
	void getLastTimeEvaluated()
	{
		fprintf(mFile,"\"%s.lti\"",mName.c_str());

	}
	void getCachedTime()
	{
		fprintf(mFile,"\"%s.chti\"",mName.c_str());

	}
	void getTimeStepSize()
	{
		fprintf(mFile,"\"%s.tss\"",mName.c_str());

	}
	void getSceneTimeStepSize()
	{
		fprintf(mFile,"\"%s.sts\"",mName.c_str());

	}
	void getStartFrame()
	{
		fprintf(mFile,"\"%s.stf\"",mName.c_str());

	}
	void getStartTime()
	{
		fprintf(mFile,"\"%s.stt\"",mName.c_str());

	}
	void getInputGeometry()
	{
		fprintf(mFile,"\"%s.igeo\"",mName.c_str());

	}
	void getInputGeometryPoints()
	{
		fprintf(mFile,"\"%s.igpt\"",mName.c_str());

	}
	void getInputGeometrySpace()
	{
		fprintf(mFile,"\"%s.igs\"",mName.c_str());

	}
	void getEnforceCountFromHistory()
	{
		fprintf(mFile,"\"%s.ecfh\"",mName.c_str());

	}
	void getTargetGeometry()
	{
		fprintf(mFile,"\"%s.tgeo\"",mName.c_str());

	}
	void getTargetGeometryWorldMatrix()
	{
		fprintf(mFile,"\"%s.tgm\"",mName.c_str());

	}
	void getTargetGeometrySpace()
	{
		fprintf(mFile,"\"%s.tgs\"",mName.c_str());

	}
	void getGoalSmoothness()
	{
		fprintf(mFile,"\"%s.gsm\"",mName.c_str());

	}
	void getGoalGeometry(size_t ggeo_i)
	{
		fprintf(mFile,"\"%s.ggeo[%i]\"",mName.c_str(),ggeo_i);

	}
	void getGoalWeight(size_t gw_i)
	{
		fprintf(mFile,"\"%s.gw[%i]\"",mName.c_str(),gw_i);

	}
	void getGoalActive(size_t ga_i)
	{
		fprintf(mFile,"\"%s.ga[%i]\"",mName.c_str(),ga_i);

	}
	void getGoalUvSetName(size_t guv_i)
	{
		fprintf(mFile,"\"%s.guv[%i]\"",mName.c_str(),guv_i);

	}
	void getCacheData()
	{
		fprintf(mFile,"\"%s.chd\"",mName.c_str());

	}
	void getCacheWidth()
	{
		fprintf(mFile,"\"%s.chw\"",mName.c_str());

	}
	void getTraceDepth()
	{
		fprintf(mFile,"\"%s.trd\"",mName.c_str());

	}
	void getCollisionData()
	{
		fprintf(mFile,"\"%s.cda\"",mName.c_str());

	}
	void getCollisionGeometry(size_t cge_i)
	{
		fprintf(mFile,"\"%s.cda.cge[%i]\"",mName.c_str(),cge_i);

	}
	void getCollisionResilience(size_t crs_i)
	{
		fprintf(mFile,"\"%s.cda.crs[%i]\"",mName.c_str(),crs_i);

	}
	void getCollisionFriction(size_t cfr_i)
	{
		fprintf(mFile,"\"%s.cda.cfr[%i]\"",mName.c_str(),cfr_i);

	}
	void getCollisionOffset(size_t cof_i)
	{
		fprintf(mFile,"\"%s.cda.cof[%i]\"",mName.c_str(),cof_i);

	}
	void getCollisionRecords()
	{
		fprintf(mFile,"\"%s.crc\"",mName.c_str());

	}
	void getTotalEventCount()
	{
		fprintf(mFile,"\"%s.tec\"",mName.c_str());

	}
	void getEventTest()
	{
		fprintf(mFile,"\"%s.evt\"",mName.c_str());

	}
	void getLastTotalEventCount()
	{
		fprintf(mFile,"\"%s.ltec\"",mName.c_str());

	}
	void getEventTarget(size_t etg_i)
	{
		fprintf(mFile,"\"%s.etg[%i]\"",mName.c_str(),etg_i);

	}
	void getEventName(size_t evn_i)
	{
		fprintf(mFile,"\"%s.evn[%i]\"",mName.c_str(),evn_i);

	}
	void getEventValid(size_t evv_i)
	{
		fprintf(mFile,"\"%s.evv[%i]\"",mName.c_str(),evv_i);

	}
	void getEventCount(size_t ecp_i)
	{
		fprintf(mFile,"\"%s.ecp[%i]\"",mName.c_str(),ecp_i);

	}
	void getEventEmit(size_t eve_i)
	{
		fprintf(mFile,"\"%s.eve[%i]\"",mName.c_str(),eve_i);

	}
	void getEventSplit(size_t evs_i)
	{
		fprintf(mFile,"\"%s.evs[%i]\"",mName.c_str(),evs_i);

	}
	void getEventDie(size_t evd_i)
	{
		fprintf(mFile,"\"%s.evd[%i]\"",mName.c_str(),evd_i);

	}
	void getEventRandom(size_t evr_i)
	{
		fprintf(mFile,"\"%s.evr[%i]\"",mName.c_str(),evr_i);

	}
	void getEventSpread(size_t esp_i)
	{
		fprintf(mFile,"\"%s.esp[%i]\"",mName.c_str(),esp_i);

	}
	void getEventProc(size_t epr_i)
	{
		fprintf(mFile,"\"%s.epr[%i]\"",mName.c_str(),epr_i);

	}
	void getInstanceData(size_t idt_i)
	{
		fprintf(mFile,"\"%s.idt[%i]\"",mName.c_str(),idt_i);

	}
	void getInstancePointData(size_t idt_i)
	{
		fprintf(mFile,"\"%s.idt[%i].ipd\"",mName.c_str(),idt_i);

	}
	void getNumberOfEvents()
	{
		fprintf(mFile,"\"%s.nev\"",mName.c_str());

	}
	void getEventNameCount()
	{
		fprintf(mFile,"\"%s.enc\"",mName.c_str());

	}
	void getFieldConnections(size_t fc_i)
	{
		fprintf(mFile,"\"%s.fc[%i]\"",mName.c_str(),fc_i);

	}
	void getCollisionConnections(size_t cc_i)
	{
		fprintf(mFile,"\"%s.cc[%i]\"",mName.c_str(),cc_i);

	}
	void getConnectionsToMe(size_t ct_i)
	{
		fprintf(mFile,"\"%s.ct[%i]\"",mName.c_str(),ct_i);

	}
	void getAuxiliariesOwned()
	{
		fprintf(mFile,"\"%s.ao\"",mName.c_str());

	}
	void getEmitterConnections(size_t ec_i)
	{
		fprintf(mFile,"\"%s.ec[%i]\"",mName.c_str(),ec_i);

	}
	void getInheritColor()
	{
		fprintf(mFile,"\"%s.inc\"",mName.c_str());

	}
	void getShapeNameMsg()
	{
		fprintf(mFile,"\"%s.snmg\"",mName.c_str());

	}
	void getDoDynamics()
	{
		fprintf(mFile,"\"%s.ddy\"",mName.c_str());

	}
	void getDoEmission()
	{
		fprintf(mFile,"\"%s.dem\"",mName.c_str());

	}
	void getForceEmission()
	{
		fprintf(mFile,"\"%s.fem\"",mName.c_str());

	}
	void getDoAge()
	{
		fprintf(mFile,"\"%s.dag\"",mName.c_str());

	}
	void getAgesLastDone()
	{
		fprintf(mFile,"\"%s.agld\"",mName.c_str());

	}
	void getTimeLastComputed()
	{
		fprintf(mFile,"\"%s.tlc\"",mName.c_str());

	}
	void getParentMatrixDirty()
	{
		fprintf(mFile,"\"%s.pmd\"",mName.c_str());

	}
	void getNewFileFormat()
	{
		fprintf(mFile,"\"%s.nff\"",mName.c_str());

	}
	void getDepthSort()
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());

	}
	void getParticleRenderType()
	{
		fprintf(mFile,"\"%s.prt\"",mName.c_str());

	}
	void getDisableCloudAxis()
	{
		fprintf(mFile,"\"%s.dca\"",mName.c_str());

	}
	void getNormalizeVelocity()
	{
		fprintf(mFile,"\"%s.nvl\"",mName.c_str());

	}
	void getMentalRayControls()
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());

	}
	void getMiOverrideCaustics()
	{
		fprintf(mFile,"\"%s.mrc.oca\"",mName.c_str());

	}
	void getMiCausticAccuracy()
	{
		fprintf(mFile,"\"%s.mrc.caa\"",mName.c_str());

	}
	void getMiCausticRadius()
	{
		fprintf(mFile,"\"%s.mrc.car\"",mName.c_str());

	}
	void getMiOverrideGlobalIllumination()
	{
		fprintf(mFile,"\"%s.mrc.ogi\"",mName.c_str());

	}
	void getMiGlobillumAccuracy()
	{
		fprintf(mFile,"\"%s.mrc.gia\"",mName.c_str());

	}
	void getMiGlobillumRadius()
	{
		fprintf(mFile,"\"%s.mrc.gir\"",mName.c_str());

	}
	void getMiOverrideFinalGather()
	{
		fprintf(mFile,"\"%s.mrc.ofg\"",mName.c_str());

	}
	void getMiFinalGatherRays()
	{
		fprintf(mFile,"\"%s.mrc.fry\"",mName.c_str());

	}
	void getMiFinalGatherMinRadius()
	{
		fprintf(mFile,"\"%s.mrc.fmn\"",mName.c_str());

	}
	void getMiFinalGatherMaxRadius()
	{
		fprintf(mFile,"\"%s.mrc.fmx\"",mName.c_str());

	}
	void getMiFinalGatherFilter()
	{
		fprintf(mFile,"\"%s.mrc.ffi\"",mName.c_str());

	}
	void getMiFinalGatherView()
	{
		fprintf(mFile,"\"%s.mrc.fgv\"",mName.c_str());

	}
	void getMiOverrideSamples()
	{
		fprintf(mFile,"\"%s.mrc.oos\"",mName.c_str());

	}
	void getMiMinSamples()
	{
		fprintf(mFile,"\"%s.mrc.mins\"",mName.c_str());

	}
	void getMiMaxSamples()
	{
		fprintf(mFile,"\"%s.mrc.maxs\"",mName.c_str());

	}
	void getPpFieldData(size_t ppfd_i)
	{
		fprintf(mFile,"\"%s.ppfd[%i]\"",mName.c_str(),ppfd_i);

	}
	void getOwnerPPFieldData(size_t opfd_i)
	{
		fprintf(mFile,"\"%s.opfd[%i]\"",mName.c_str(),opfd_i);

	}
	void getDeformedPosition()
	{
		fprintf(mFile,"\"%s.dpos\"",mName.c_str());

	}
protected:
	Particle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DeformableShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLE_H__
