/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Particle():DeformableShape(){}
	Particle(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DeformableShape(file, name, parent, "particle", shared, create){}
	virtual ~Particle(){}

	void setPosition0(const vectorArray& pos0)
	{
		if(pos0.size == 0) return;
		fprintf(mFile,"\tsetAttr \".pos0\" -type \"vectorArray\" ");
		pos0.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVelocity0(const vectorArray& vel0)
	{
		if(vel0.size == 0) return;
		fprintf(mFile,"\tsetAttr \".vel0\" -type \"vectorArray\" ");
		vel0.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAcceleration0(const vectorArray& acc0)
	{
		if(acc0.size == 0) return;
		fprintf(mFile,"\tsetAttr \".acc0\" -type \"vectorArray\" ");
		acc0.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUseStartupCache(bool usc)
	{
		if(usc == false) return;
		fprintf(mFile,"\tsetAttr \".usc\" %i;\n", usc);
	}
	void setStartupCachePath(const string& scp)
	{
		if(scp == "NULL") return;
		fprintf(mFile,"\tsetAttr \".scp\" -type \"string\" ");
		scp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStartupCacheFrame(int scf)
	{
		if(scf == 0) return;
		fprintf(mFile,"\tsetAttr \".scf\" %i;\n", scf);
	}
	void setMass0(const doubleArray& mas0)
	{
		if(mas0.size == 0) return;
		fprintf(mFile,"\tsetAttr \".mas0\" -type \"doubleArray\" ");
		mas0.write(mFile);
		fprintf(mFile,";\n");
	}
	void setParticleId0(const doubleArray& id0)
	{
		if(id0.size == 0) return;
		fprintf(mFile,"\tsetAttr \".id0\" -type \"doubleArray\" ");
		id0.write(mFile);
		fprintf(mFile,";\n");
	}
	void setNextId(int nid)
	{
		if(nid == 0) return;
		fprintf(mFile,"\tsetAttr \".nid\" %i;\n", nid);
	}
	void setNextId0(int nid0)
	{
		if(nid0 == 0) return;
		fprintf(mFile,"\tsetAttr \".nid0\" %i;\n", nid0);
	}
	void setBirthTime0(const doubleArray& bt0)
	{
		if(bt0.size == 0) return;
		fprintf(mFile,"\tsetAttr \".bt0\" -type \"doubleArray\" ");
		bt0.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAge0(const doubleArray& ag0)
	{
		if(ag0.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ag0\" -type \"doubleArray\" ");
		ag0.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDieOnEmissionVolumeExit(bool dve)
	{
		if(dve == false) return;
		fprintf(mFile,"\tsetAttr \".dve\" %i;\n", dve);
	}
	void setLifespanMode(unsigned int lfm)
	{
		if(lfm == 0) return;
		fprintf(mFile,"\tsetAttr \".lfm\" %i;\n", lfm);
	}
	void setLifespanRandom(double lfr)
	{
		if(lfr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lfr\" %f;\n", lfr);
	}
	void setExpressionsAfterDynamics(bool ead)
	{
		if(ead == false) return;
		fprintf(mFile,"\tsetAttr \".ead\" %i;\n", ead);
	}
	void setInternalRuntimeBeforeDynamicsExpression(const string& irbx)
	{
		if(irbx == "NULL") return;
		fprintf(mFile,"\tsetAttr \".irbx\" -type \"string\" ");
		irbx.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInternalRuntimeAfterDynamicsExpression(const string& irax)
	{
		if(irax == "NULL") return;
		fprintf(mFile,"\tsetAttr \".irax\" -type \"string\" ");
		irax.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInternalCreationExpression(const string& icx)
	{
		if(icx == "NULL") return;
		fprintf(mFile,"\tsetAttr \".icx\" -type \"string\" ");
		icx.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIsDynamic(bool isd)
	{
		if(isd == true) return;
		fprintf(mFile,"\tsetAttr \".isd\" %i;\n", isd);
	}
	void setDynamicsWeight(double dw)
	{
		if(dw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dw\" %f;\n", dw);
	}
	void setForcesInWorld(bool fiw)
	{
		if(fiw == true) return;
		fprintf(mFile,"\tsetAttr \".fiw\" %i;\n", fiw);
	}
	void setConserve(double con)
	{
		if(con == 1.0) return;
		fprintf(mFile,"\tsetAttr \".con\" %f;\n", con);
	}
	void setEmissionInWorld(bool eiw)
	{
		if(eiw == true) return;
		fprintf(mFile,"\tsetAttr \".eiw\" %i;\n", eiw);
	}
	void setMaxCount(int mxc)
	{
		if(mxc == -1) return;
		fprintf(mFile,"\tsetAttr \".mxc\" %i;\n", mxc);
	}
	void setLevelOfDetail(double lod)
	{
		if(lod == 1) return;
		fprintf(mFile,"\tsetAttr \".lod\" %f;\n", lod);
	}
	void setInheritFactor(double inh)
	{
		if(inh == 0.0) return;
		fprintf(mFile,"\tsetAttr \".inh\" %f;\n", inh);
	}
	void setSeed(size_t sd_i,int sd)
	{
		if(sd == 1) return;
		fprintf(mFile,"\tsetAttr \".sd[%i]\" %i;\n", sd_i,sd);
	}
	void setSeed(size_t sd_start,size_t sd_end,int* sd)
	{
		fprintf(mFile,"\tsetAttr \".sd[%i:%i]\" ", sd_start,sd_end);
		size_t size = (sd_end-sd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",sd[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startSeed(size_t sd_start,size_t sd_end)const
	{
		fprintf(mFile,"\tsetAttr \".sd[%i:%i]\"",sd_start,sd_end);
	}
	void appendSeed(int sd)const
	{
		fprintf(mFile," %i",sd);
	}
	void endSeed()const
	{
		fprintf(mFile,";\n");
	}
	void setCurrentTimeSave(double cts)
	{
		if(cts == 0) return;
		fprintf(mFile,"\tsetAttr \".cts\" %f;\n", cts);
	}
	void setStartFrame(double stf)
	{
		if(stf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".stf\" %f;\n", stf);
	}
	void setInputGeometrySpace(unsigned int igs)
	{
		if(igs == 0) return;
		fprintf(mFile,"\tsetAttr \".igs\" %i;\n", igs);
	}
	void setEnforceCountFromHistory(bool ecfh)
	{
		if(ecfh == true) return;
		fprintf(mFile,"\tsetAttr \".ecfh\" %i;\n", ecfh);
	}
	void setTargetGeometrySpace(unsigned int tgs)
	{
		if(tgs == 2) return;
		fprintf(mFile,"\tsetAttr \".tgs\" %i;\n", tgs);
	}
	void setGoalSmoothness(double gsm)
	{
		if(gsm == 3) return;
		fprintf(mFile,"\tsetAttr \".gsm\" %f;\n", gsm);
	}
	void setGoalWeight(size_t gw_i,double gw)
	{
		if(gw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gw[%i]\" %f;\n", gw_i,gw);
	}
	void setGoalWeight(size_t gw_start,size_t gw_end,double* gw)
	{
		fprintf(mFile,"\tsetAttr \".gw[%i:%i]\" ", gw_start,gw_end);
		size_t size = (gw_end-gw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",gw[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startGoalWeight(size_t gw_start,size_t gw_end)const
	{
		fprintf(mFile,"\tsetAttr \".gw[%i:%i]\"",gw_start,gw_end);
	}
	void appendGoalWeight(double gw)const
	{
		fprintf(mFile," %f",gw);
	}
	void endGoalWeight()const
	{
		fprintf(mFile,";\n");
	}
	void setGoalActive(size_t ga_i,bool ga)
	{
		if(ga == true) return;
		fprintf(mFile,"\tsetAttr \".ga[%i]\" %i;\n", ga_i,ga);
	}
	void setGoalActive(size_t ga_start,size_t ga_end,bool* ga)
	{
		fprintf(mFile,"\tsetAttr \".ga[%i:%i]\" ", ga_start,ga_end);
		size_t size = (ga_end-ga_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ga[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startGoalActive(size_t ga_start,size_t ga_end)const
	{
		fprintf(mFile,"\tsetAttr \".ga[%i:%i]\"",ga_start,ga_end);
	}
	void appendGoalActive(bool ga)const
	{
		fprintf(mFile," %i",ga);
	}
	void endGoalActive()const
	{
		fprintf(mFile,";\n");
	}
	void setGoalUvSetName(size_t guv_i,const string& guv)
	{
		if(guv == "NULL") return;
		fprintf(mFile,"\tsetAttr \".guv[%i]\" -type \"string\" ",guv_i);
		guv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGoalUvSetName(size_t guv_start,size_t guv_end,string* guv)
	{
		fprintf(mFile,"\tsetAttr \".guv[%i:%i]\" ", guv_start,guv_end);
		size_t size = (guv_end-guv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			guv[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startGoalUvSetName(size_t guv_start,size_t guv_end)const
	{
		fprintf(mFile,"\tsetAttr \".guv[%i:%i]\"",guv_start,guv_end);
		fprintf(mFile," -type \"string\" ");
	}
	void appendGoalUvSetName(const string& guv)const
	{
		fprintf(mFile," ");
		guv.write(mFile);
	}
	void endGoalUvSetName()const
	{
		fprintf(mFile,";\n");
	}
	void setCacheData(bool chd)
	{
		if(chd == 0) return;
		fprintf(mFile,"\tsetAttr \".chd\" %i;\n", chd);
	}
	void setCacheWidth(int chw)
	{
		if(chw == 1) return;
		fprintf(mFile,"\tsetAttr \".chw\" %i;\n", chw);
	}
	void setTraceDepth(int trd)
	{
		if(trd == 10) return;
		fprintf(mFile,"\tsetAttr \".trd\" %i;\n", trd);
	}
	void setEventName(size_t evn_i,const string& evn)
	{
		if(evn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".evn[%i]\" -type \"string\" ",evn_i);
		evn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEventName(size_t evn_start,size_t evn_end,string* evn)
	{
		fprintf(mFile,"\tsetAttr \".evn[%i:%i]\" ", evn_start,evn_end);
		size_t size = (evn_end-evn_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			evn[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startEventName(size_t evn_start,size_t evn_end)const
	{
		fprintf(mFile,"\tsetAttr \".evn[%i:%i]\"",evn_start,evn_end);
		fprintf(mFile," -type \"string\" ");
	}
	void appendEventName(const string& evn)const
	{
		fprintf(mFile," ");
		evn.write(mFile);
	}
	void endEventName()const
	{
		fprintf(mFile,";\n");
	}
	void setEventValid(size_t evv_i,int evv)
	{
		if(evv == -1) return;
		fprintf(mFile,"\tsetAttr \".evv[%i]\" %i;\n", evv_i,evv);
	}
	void setEventValid(size_t evv_start,size_t evv_end,int* evv)
	{
		fprintf(mFile,"\tsetAttr \".evv[%i:%i]\" ", evv_start,evv_end);
		size_t size = (evv_end-evv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",evv[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEventValid(size_t evv_start,size_t evv_end)const
	{
		fprintf(mFile,"\tsetAttr \".evv[%i:%i]\"",evv_start,evv_end);
	}
	void appendEventValid(int evv)const
	{
		fprintf(mFile," %i",evv);
	}
	void endEventValid()const
	{
		fprintf(mFile,";\n");
	}
	void setEventCount(size_t ecp_i,short ecp)
	{
		if(ecp == -1) return;
		fprintf(mFile,"\tsetAttr \".ecp[%i]\" %i;\n", ecp_i,ecp);
	}
	void setEventCount(size_t ecp_start,size_t ecp_end,short* ecp)
	{
		fprintf(mFile,"\tsetAttr \".ecp[%i:%i]\" ", ecp_start,ecp_end);
		size_t size = (ecp_end-ecp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ecp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEventCount(size_t ecp_start,size_t ecp_end)const
	{
		fprintf(mFile,"\tsetAttr \".ecp[%i:%i]\"",ecp_start,ecp_end);
	}
	void appendEventCount(short ecp)const
	{
		fprintf(mFile," %i",ecp);
	}
	void endEventCount()const
	{
		fprintf(mFile,";\n");
	}
	void setEventEmit(size_t eve_i,short eve)
	{
		if(eve == -1) return;
		fprintf(mFile,"\tsetAttr \".eve[%i]\" %i;\n", eve_i,eve);
	}
	void setEventEmit(size_t eve_start,size_t eve_end,short* eve)
	{
		fprintf(mFile,"\tsetAttr \".eve[%i:%i]\" ", eve_start,eve_end);
		size_t size = (eve_end-eve_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",eve[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEventEmit(size_t eve_start,size_t eve_end)const
	{
		fprintf(mFile,"\tsetAttr \".eve[%i:%i]\"",eve_start,eve_end);
	}
	void appendEventEmit(short eve)const
	{
		fprintf(mFile," %i",eve);
	}
	void endEventEmit()const
	{
		fprintf(mFile,";\n");
	}
	void setEventSplit(size_t evs_i,short evs)
	{
		if(evs == -1) return;
		fprintf(mFile,"\tsetAttr \".evs[%i]\" %i;\n", evs_i,evs);
	}
	void setEventSplit(size_t evs_start,size_t evs_end,short* evs)
	{
		fprintf(mFile,"\tsetAttr \".evs[%i:%i]\" ", evs_start,evs_end);
		size_t size = (evs_end-evs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",evs[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEventSplit(size_t evs_start,size_t evs_end)const
	{
		fprintf(mFile,"\tsetAttr \".evs[%i:%i]\"",evs_start,evs_end);
	}
	void appendEventSplit(short evs)const
	{
		fprintf(mFile," %i",evs);
	}
	void endEventSplit()const
	{
		fprintf(mFile,";\n");
	}
	void setEventDie(size_t evd_i,short evd)
	{
		if(evd == -1) return;
		fprintf(mFile,"\tsetAttr \".evd[%i]\" %i;\n", evd_i,evd);
	}
	void setEventDie(size_t evd_start,size_t evd_end,short* evd)
	{
		fprintf(mFile,"\tsetAttr \".evd[%i:%i]\" ", evd_start,evd_end);
		size_t size = (evd_end-evd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",evd[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEventDie(size_t evd_start,size_t evd_end)const
	{
		fprintf(mFile,"\tsetAttr \".evd[%i:%i]\"",evd_start,evd_end);
	}
	void appendEventDie(short evd)const
	{
		fprintf(mFile," %i",evd);
	}
	void endEventDie()const
	{
		fprintf(mFile,";\n");
	}
	void setEventRandom(size_t evr_i,short evr)
	{
		if(evr == -1) return;
		fprintf(mFile,"\tsetAttr \".evr[%i]\" %i;\n", evr_i,evr);
	}
	void setEventRandom(size_t evr_start,size_t evr_end,short* evr)
	{
		fprintf(mFile,"\tsetAttr \".evr[%i:%i]\" ", evr_start,evr_end);
		size_t size = (evr_end-evr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",evr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEventRandom(size_t evr_start,size_t evr_end)const
	{
		fprintf(mFile,"\tsetAttr \".evr[%i:%i]\"",evr_start,evr_end);
	}
	void appendEventRandom(short evr)const
	{
		fprintf(mFile," %i",evr);
	}
	void endEventRandom()const
	{
		fprintf(mFile,";\n");
	}
	void setEventSpread(size_t esp_i,double esp)
	{
		if(esp == -1.0) return;
		fprintf(mFile,"\tsetAttr \".esp[%i]\" %f;\n", esp_i,esp);
	}
	void setEventSpread(size_t esp_start,size_t esp_end,double* esp)
	{
		fprintf(mFile,"\tsetAttr \".esp[%i:%i]\" ", esp_start,esp_end);
		size_t size = (esp_end-esp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",esp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEventSpread(size_t esp_start,size_t esp_end)const
	{
		fprintf(mFile,"\tsetAttr \".esp[%i:%i]\"",esp_start,esp_end);
	}
	void appendEventSpread(double esp)const
	{
		fprintf(mFile," %f",esp);
	}
	void endEventSpread()const
	{
		fprintf(mFile,";\n");
	}
	void setEventProc(size_t epr_i,const string& epr)
	{
		if(epr == "NULL") return;
		fprintf(mFile,"\tsetAttr \".epr[%i]\" -type \"string\" ",epr_i);
		epr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEventProc(size_t epr_start,size_t epr_end,string* epr)
	{
		fprintf(mFile,"\tsetAttr \".epr[%i:%i]\" ", epr_start,epr_end);
		size_t size = (epr_end-epr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			epr[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startEventProc(size_t epr_start,size_t epr_end)const
	{
		fprintf(mFile,"\tsetAttr \".epr[%i:%i]\"",epr_start,epr_end);
		fprintf(mFile," -type \"string\" ");
	}
	void appendEventProc(const string& epr)const
	{
		fprintf(mFile," ");
		epr.write(mFile);
	}
	void endEventProc()const
	{
		fprintf(mFile,";\n");
	}
	void setInstanceData(size_t idt_i,const InstanceData& idt)
	{
		fprintf(mFile,"\tsetAttr \".idt[%i]\" ",idt_i);
		idt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInstanceData(size_t idt_start,size_t idt_end,InstanceData* idt)
	{
		fprintf(mFile,"\tsetAttr \".idt[%i:%i]\" ", idt_start,idt_end);
		size_t size = (idt_end-idt_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			idt[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInstanceData(size_t idt_start,size_t idt_end)const
	{
		fprintf(mFile,"\tsetAttr \".idt[%i:%i]\"",idt_start,idt_end);
		fprintf(mFile," -type \"InstanceData\" ");
	}
	void appendInstanceData(const InstanceData& idt)const
	{
		fprintf(mFile," ");
		idt.write(mFile);
	}
	void endInstanceData()const
	{
		fprintf(mFile,";\n");
	}
	void setInstanceAttributeMapping(size_t idt_i,const stringArray& iam)
	{
		fprintf(mFile,"\tsetAttr \".idt[%i].iam\" -type \"stringArray\" ",idt_i);
		iam.write(mFile);
		fprintf(mFile,";\n");
	}
	void setNewFileFormat(short nff)
	{
		if(nff == 0) return;
		fprintf(mFile,"\tsetAttr \".nff\" %i;\n", nff);
	}
	void setDepthSort(bool ds)
	{
		if(ds == false) return;
		fprintf(mFile,"\tsetAttr \".ds\" %i;\n", ds);
	}
	void setParticleRenderType(unsigned int prt)
	{
		if(prt == 3) return;
		fprintf(mFile,"\tsetAttr \".prt\" %i;\n", prt);
	}
	void setDisableCloudAxis(bool dca)
	{
		if(dca == false) return;
		fprintf(mFile,"\tsetAttr \".dca\" %i;\n", dca);
	}
	void setNormalizeVelocity(bool nvl)
	{
		if(nvl == false) return;
		fprintf(mFile,"\tsetAttr \".nvl\" %i;\n", nvl);
	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"\tsetAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiOverrideCaustics(bool oca)
	{
		if(oca == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.oca\" %i;\n", oca);
	}
	void setMiCausticAccuracy(short caa)
	{
		if(caa == 64) return;
		fprintf(mFile,"\tsetAttr \".mrc.caa\" %i;\n", caa);
	}
	void setMiCausticRadius(float car)
	{
		if(car == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.car\" %f;\n", car);
	}
	void setMiOverrideGlobalIllumination(bool ogi)
	{
		if(ogi == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.ogi\" %i;\n", ogi);
	}
	void setMiGlobillumAccuracy(short gia)
	{
		if(gia == 64) return;
		fprintf(mFile,"\tsetAttr \".mrc.gia\" %i;\n", gia);
	}
	void setMiGlobillumRadius(float gir)
	{
		if(gir == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.gir\" %f;\n", gir);
	}
	void setMiOverrideFinalGather(bool ofg)
	{
		if(ofg == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.ofg\" %i;\n", ofg);
	}
	void setMiFinalGatherRays(int fry)
	{
		if(fry == 1000) return;
		fprintf(mFile,"\tsetAttr \".mrc.fry\" %i;\n", fry);
	}
	void setMiFinalGatherMinRadius(float fmn)
	{
		if(fmn == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.fmn\" %f;\n", fmn);
	}
	void setMiFinalGatherMaxRadius(float fmx)
	{
		if(fmx == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.fmx\" %f;\n", fmx);
	}
	void setMiFinalGatherFilter(short ffi)
	{
		if(ffi == 1) return;
		fprintf(mFile,"\tsetAttr \".mrc.ffi\" %i;\n", ffi);
	}
	void setMiFinalGatherView(bool fgv)
	{
		if(fgv == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.fgv\" %i;\n", fgv);
	}
	void setMiOverrideSamples(bool oos)
	{
		if(oos == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.oos\" %i;\n", oos);
	}
	void setMiMinSamples(short mins)
	{
		if(mins == 1) return;
		fprintf(mFile,"\tsetAttr \".mrc.mins\" %i;\n", mins);
	}
	void setMiMaxSamples(short maxs)
	{
		if(maxs == 2) return;
		fprintf(mFile,"\tsetAttr \".mrc.maxs\" %i;\n", maxs);
	}
	void getPosition()const
	{
		fprintf(mFile,"\"%s.pos\"",mName.c_str());
	}
	void getRampPosition()const
	{
		fprintf(mFile,"\"%s.rps\"",mName.c_str());
	}
	void getCentroid()const
	{
		fprintf(mFile,"\"%s.ctd\"",mName.c_str());
	}
	void getCentroidX()const
	{
		fprintf(mFile,"\"%s.ctd.ctdx\"",mName.c_str());
	}
	void getCentroidY()const
	{
		fprintf(mFile,"\"%s.ctd.ctdy\"",mName.c_str());
	}
	void getCentroidZ()const
	{
		fprintf(mFile,"\"%s.ctd.ctdz\"",mName.c_str());
	}
	void getLastPosition()const
	{
		fprintf(mFile,"\"%s.lpos\"",mName.c_str());
	}
	void getVelocity()const
	{
		fprintf(mFile,"\"%s.vel\"",mName.c_str());
	}
	void getRampVelocity()const
	{
		fprintf(mFile,"\"%s.rvl\"",mName.c_str());
	}
	void getLastVelocity()const
	{
		fprintf(mFile,"\"%s.lvel\"",mName.c_str());
	}
	void getAcceleration()const
	{
		fprintf(mFile,"\"%s.acc\"",mName.c_str());
	}
	void getRampAcceleration()const
	{
		fprintf(mFile,"\"%s.rac\"",mName.c_str());
	}
	void getForce()const
	{
		fprintf(mFile,"\"%s.frc\"",mName.c_str());
	}
	void getInputForce(size_t ifc_i)const
	{
		fprintf(mFile,"\"%s.ifc[%i]\"",mName.c_str(),ifc_i);
	}
	void getInputForce()const
	{

		fprintf(mFile,"\"%s.ifc\"",mName.c_str());
	}
	void getWorldPosition()const
	{
		fprintf(mFile,"\"%s.wps\"",mName.c_str());
	}
	void getWorldCentroid()const
	{
		fprintf(mFile,"\"%s.wctn\"",mName.c_str());
	}
	void getWorldCentroidX()const
	{
		fprintf(mFile,"\"%s.wctn.wctx\"",mName.c_str());
	}
	void getWorldCentroidY()const
	{
		fprintf(mFile,"\"%s.wctn.wcty\"",mName.c_str());
	}
	void getWorldCentroidZ()const
	{
		fprintf(mFile,"\"%s.wctn.wctz\"",mName.c_str());
	}
	void getLastWorldPosition()const
	{
		fprintf(mFile,"\"%s.lwps\"",mName.c_str());
	}
	void getWorldVelocity()const
	{
		fprintf(mFile,"\"%s.wvl\"",mName.c_str());
	}
	void getWorldVelocityInObjectSpace()const
	{
		fprintf(mFile,"\"%s.wvo\"",mName.c_str());
	}
	void getLastWorldVelocity()const
	{
		fprintf(mFile,"\"%s.lwvl\"",mName.c_str());
	}
	void getLastWorldMatrix()const
	{
		fprintf(mFile,"\"%s.lwm\"",mName.c_str());
	}
	void getPosition0()const
	{
		fprintf(mFile,"\"%s.pos0\"",mName.c_str());
	}
	void getVelocity0()const
	{
		fprintf(mFile,"\"%s.vel0\"",mName.c_str());
	}
	void getAcceleration0()const
	{
		fprintf(mFile,"\"%s.acc0\"",mName.c_str());
	}
	void getStartupCachePath()const
	{
		fprintf(mFile,"\"%s.scp\"",mName.c_str());
	}
	void getStartupCacheFrame()const
	{
		fprintf(mFile,"\"%s.scf\"",mName.c_str());
	}
	void getCachedPosition()const
	{
		fprintf(mFile,"\"%s.cpos\"",mName.c_str());
	}
	void getLastCachedPosition()const
	{
		fprintf(mFile,"\"%s.lcps\"",mName.c_str());
	}
	void getCachedWorldPosition()const
	{
		fprintf(mFile,"\"%s.cwps\"",mName.c_str());
	}
	void getCachedWorldCentroid()const
	{
		fprintf(mFile,"\"%s.cwcn\"",mName.c_str());
	}
	void getCachedWorldCentroidX()const
	{
		fprintf(mFile,"\"%s.cwcn.cwcx\"",mName.c_str());
	}
	void getCachedWorldCentroidY()const
	{
		fprintf(mFile,"\"%s.cwcn.cwcy\"",mName.c_str());
	}
	void getCachedWorldCentroidZ()const
	{
		fprintf(mFile,"\"%s.cwcn.cwcz\"",mName.c_str());
	}
	void getCachedVelocity()const
	{
		fprintf(mFile,"\"%s.cvel\"",mName.c_str());
	}
	void getCachedWorldVelocity()const
	{
		fprintf(mFile,"\"%s.cwvl\"",mName.c_str());
	}
	void getCount()const
	{
		fprintf(mFile,"\"%s.cnt\"",mName.c_str());
	}
	void getMass()const
	{
		fprintf(mFile,"\"%s.mas\"",mName.c_str());
	}
	void getMass0()const
	{
		fprintf(mFile,"\"%s.mas0\"",mName.c_str());
	}
	void getMassCache()const
	{
		fprintf(mFile,"\"%s.masc\"",mName.c_str());
	}
	void getParticleId()const
	{
		fprintf(mFile,"\"%s.id\"",mName.c_str());
	}
	void getParticleId0()const
	{
		fprintf(mFile,"\"%s.id0\"",mName.c_str());
	}
	void getIdCache()const
	{
		fprintf(mFile,"\"%s.idc\"",mName.c_str());
	}
	void getIdMapping()const
	{
		fprintf(mFile,"\"%s.idm\"",mName.c_str());
	}
	void getSortedId()const
	{
		fprintf(mFile,"\"%s.idm.sid\"",mName.c_str());
	}
	void getIdIndex()const
	{
		fprintf(mFile,"\"%s.idm.idix\"",mName.c_str());
	}
	void getBirthTime()const
	{
		fprintf(mFile,"\"%s.bt\"",mName.c_str());
	}
	void getBirthTime0()const
	{
		fprintf(mFile,"\"%s.bt0\"",mName.c_str());
	}
	void getBirthTimeCache()const
	{
		fprintf(mFile,"\"%s.btc\"",mName.c_str());
	}
	void getAge()const
	{
		fprintf(mFile,"\"%s.ag\"",mName.c_str());
	}
	void getAge0()const
	{
		fprintf(mFile,"\"%s.ag0\"",mName.c_str());
	}
	void getAgeCache()const
	{
		fprintf(mFile,"\"%s.agc\"",mName.c_str());
	}
	void getEmission()const
	{
		fprintf(mFile,"\"%s.emt\"",mName.c_str());
	}
	void getDieOnEmissionVolumeExit()const
	{
		fprintf(mFile,"\"%s.dve\"",mName.c_str());
	}
	void getIsFull()const
	{
		fprintf(mFile,"\"%s.ifl\"",mName.c_str());
	}
	void getNewParticles(size_t npt_i)const
	{
		fprintf(mFile,"\"%s.npt[%i]\"",mName.c_str(),npt_i);
	}
	void getNewParticles()const
	{

		fprintf(mFile,"\"%s.npt\"",mName.c_str());
	}
	void getLifespanMode()const
	{
		fprintf(mFile,"\"%s.lfm\"",mName.c_str());
	}
	void getLifespanRandom()const
	{
		fprintf(mFile,"\"%s.lfr\"",mName.c_str());
	}
	void getFinalLifespanPP()const
	{
		fprintf(mFile,"\"%s.flp\"",mName.c_str());
	}
	void getExpressionsAfterDynamics()const
	{
		fprintf(mFile,"\"%s.ead\"",mName.c_str());
	}
	void getInput(size_t xi_i)const
	{
		fprintf(mFile,"\"%s.xi[%i]\"",mName.c_str(),xi_i);
	}
	void getInput()const
	{

		fprintf(mFile,"\"%s.xi\"",mName.c_str());
	}
	void getOutput(size_t xo_i)const
	{
		fprintf(mFile,"\"%s.xo[%i]\"",mName.c_str(),xo_i);
	}
	void getOutput()const
	{

		fprintf(mFile,"\"%s.xo\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());
	}
	void getFrame()const
	{
		fprintf(mFile,"\"%s.frm\"",mName.c_str());
	}
	void getDiedLastTime()const
	{
		fprintf(mFile,"\"%s.dlt\"",mName.c_str());
	}
	void getNetEmittedLastTime()const
	{
		fprintf(mFile,"\"%s.nlt\"",mName.c_str());
	}
	void getStartEmittedIndex()const
	{
		fprintf(mFile,"\"%s.sei\"",mName.c_str());
	}
	void getIsDynamic()const
	{
		fprintf(mFile,"\"%s.isd\"",mName.c_str());
	}
	void getDynamicsWeight()const
	{
		fprintf(mFile,"\"%s.dw\"",mName.c_str());
	}
	void getForcesInWorld()const
	{
		fprintf(mFile,"\"%s.fiw\"",mName.c_str());
	}
	void getConserve()const
	{
		fprintf(mFile,"\"%s.con\"",mName.c_str());
	}
	void getEmissionInWorld()const
	{
		fprintf(mFile,"\"%s.eiw\"",mName.c_str());
	}
	void getMaxCount()const
	{
		fprintf(mFile,"\"%s.mxc\"",mName.c_str());
	}
	void getLevelOfDetail()const
	{
		fprintf(mFile,"\"%s.lod\"",mName.c_str());
	}
	void getInheritFactor()const
	{
		fprintf(mFile,"\"%s.inh\"",mName.c_str());
	}
	void getSeed(size_t sd_i)const
	{
		fprintf(mFile,"\"%s.sd[%i]\"",mName.c_str(),sd_i);
	}
	void getSeed()const
	{

		fprintf(mFile,"\"%s.sd\"",mName.c_str());
	}
	void getFieldData()const
	{
		fprintf(mFile,"\"%s.fd\"",mName.c_str());
	}
	void getFieldDataPosition()const
	{
		fprintf(mFile,"\"%s.fd.fdp\"",mName.c_str());
	}
	void getFieldDataVelocity()const
	{
		fprintf(mFile,"\"%s.fd.fdv\"",mName.c_str());
	}
	void getFieldDataMass()const
	{
		fprintf(mFile,"\"%s.fd.fdm\"",mName.c_str());
	}
	void getFieldDataDeltaTime()const
	{
		fprintf(mFile,"\"%s.fd.fdt\"",mName.c_str());
	}
	void getEmitterData()const
	{
		fprintf(mFile,"\"%s.ed\"",mName.c_str());
	}
	void getEmitterDataPosition()const
	{
		fprintf(mFile,"\"%s.ed.edp\"",mName.c_str());
	}
	void getEmitterDataVelocity()const
	{
		fprintf(mFile,"\"%s.ed.edv\"",mName.c_str());
	}
	void getEmitterDataDeltaTime()const
	{
		fprintf(mFile,"\"%s.ed.edt\"",mName.c_str());
	}
	void getCurrentTime()const
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());
	}
	void getLastTimeEvaluated()const
	{
		fprintf(mFile,"\"%s.lti\"",mName.c_str());
	}
	void getCachedTime()const
	{
		fprintf(mFile,"\"%s.chti\"",mName.c_str());
	}
	void getTimeStepSize()const
	{
		fprintf(mFile,"\"%s.tss\"",mName.c_str());
	}
	void getSceneTimeStepSize()const
	{
		fprintf(mFile,"\"%s.sts\"",mName.c_str());
	}
	void getStartFrame()const
	{
		fprintf(mFile,"\"%s.stf\"",mName.c_str());
	}
	void getStartTime()const
	{
		fprintf(mFile,"\"%s.stt\"",mName.c_str());
	}
	void getInputGeometry()const
	{
		fprintf(mFile,"\"%s.igeo\"",mName.c_str());
	}
	void getInputGeometryPoints()const
	{
		fprintf(mFile,"\"%s.igpt\"",mName.c_str());
	}
	void getInputGeometrySpace()const
	{
		fprintf(mFile,"\"%s.igs\"",mName.c_str());
	}
	void getEnforceCountFromHistory()const
	{
		fprintf(mFile,"\"%s.ecfh\"",mName.c_str());
	}
	void getTargetGeometry()const
	{
		fprintf(mFile,"\"%s.tgeo\"",mName.c_str());
	}
	void getTargetGeometryWorldMatrix()const
	{
		fprintf(mFile,"\"%s.tgm\"",mName.c_str());
	}
	void getTargetGeometrySpace()const
	{
		fprintf(mFile,"\"%s.tgs\"",mName.c_str());
	}
	void getGoalSmoothness()const
	{
		fprintf(mFile,"\"%s.gsm\"",mName.c_str());
	}
	void getGoalGeometry(size_t ggeo_i)const
	{
		fprintf(mFile,"\"%s.ggeo[%i]\"",mName.c_str(),ggeo_i);
	}
	void getGoalGeometry()const
	{

		fprintf(mFile,"\"%s.ggeo\"",mName.c_str());
	}
	void getGoalWeight(size_t gw_i)const
	{
		fprintf(mFile,"\"%s.gw[%i]\"",mName.c_str(),gw_i);
	}
	void getGoalWeight()const
	{

		fprintf(mFile,"\"%s.gw\"",mName.c_str());
	}
	void getGoalActive(size_t ga_i)const
	{
		fprintf(mFile,"\"%s.ga[%i]\"",mName.c_str(),ga_i);
	}
	void getGoalActive()const
	{

		fprintf(mFile,"\"%s.ga\"",mName.c_str());
	}
	void getGoalUvSetName(size_t guv_i)const
	{
		fprintf(mFile,"\"%s.guv[%i]\"",mName.c_str(),guv_i);
	}
	void getGoalUvSetName()const
	{

		fprintf(mFile,"\"%s.guv\"",mName.c_str());
	}
	void getCacheData()const
	{
		fprintf(mFile,"\"%s.chd\"",mName.c_str());
	}
	void getCacheWidth()const
	{
		fprintf(mFile,"\"%s.chw\"",mName.c_str());
	}
	void getTraceDepth()const
	{
		fprintf(mFile,"\"%s.trd\"",mName.c_str());
	}
	void getCollisionData()const
	{
		fprintf(mFile,"\"%s.cda\"",mName.c_str());
	}
	void getCollisionGeometry(size_t cge_i)const
	{
		fprintf(mFile,"\"%s.cda.cge[%i]\"",mName.c_str(),cge_i);
	}
	void getCollisionResilience(size_t crs_i)const
	{
		fprintf(mFile,"\"%s.cda.crs[%i]\"",mName.c_str(),crs_i);
	}
	void getCollisionFriction(size_t cfr_i)const
	{
		fprintf(mFile,"\"%s.cda.cfr[%i]\"",mName.c_str(),cfr_i);
	}
	void getCollisionOffset(size_t cof_i)const
	{
		fprintf(mFile,"\"%s.cda.cof[%i]\"",mName.c_str(),cof_i);
	}
	void getCollisionRecords()const
	{
		fprintf(mFile,"\"%s.crc\"",mName.c_str());
	}
	void getTotalEventCount()const
	{
		fprintf(mFile,"\"%s.tec\"",mName.c_str());
	}
	void getEventTest()const
	{
		fprintf(mFile,"\"%s.evt\"",mName.c_str());
	}
	void getLastTotalEventCount()const
	{
		fprintf(mFile,"\"%s.ltec\"",mName.c_str());
	}
	void getEventTarget(size_t etg_i)const
	{
		fprintf(mFile,"\"%s.etg[%i]\"",mName.c_str(),etg_i);
	}
	void getEventTarget()const
	{

		fprintf(mFile,"\"%s.etg\"",mName.c_str());
	}
	void getEventName(size_t evn_i)const
	{
		fprintf(mFile,"\"%s.evn[%i]\"",mName.c_str(),evn_i);
	}
	void getEventName()const
	{

		fprintf(mFile,"\"%s.evn\"",mName.c_str());
	}
	void getEventValid(size_t evv_i)const
	{
		fprintf(mFile,"\"%s.evv[%i]\"",mName.c_str(),evv_i);
	}
	void getEventValid()const
	{

		fprintf(mFile,"\"%s.evv\"",mName.c_str());
	}
	void getEventCount(size_t ecp_i)const
	{
		fprintf(mFile,"\"%s.ecp[%i]\"",mName.c_str(),ecp_i);
	}
	void getEventCount()const
	{

		fprintf(mFile,"\"%s.ecp\"",mName.c_str());
	}
	void getEventEmit(size_t eve_i)const
	{
		fprintf(mFile,"\"%s.eve[%i]\"",mName.c_str(),eve_i);
	}
	void getEventEmit()const
	{

		fprintf(mFile,"\"%s.eve\"",mName.c_str());
	}
	void getEventSplit(size_t evs_i)const
	{
		fprintf(mFile,"\"%s.evs[%i]\"",mName.c_str(),evs_i);
	}
	void getEventSplit()const
	{

		fprintf(mFile,"\"%s.evs\"",mName.c_str());
	}
	void getEventDie(size_t evd_i)const
	{
		fprintf(mFile,"\"%s.evd[%i]\"",mName.c_str(),evd_i);
	}
	void getEventDie()const
	{

		fprintf(mFile,"\"%s.evd\"",mName.c_str());
	}
	void getEventRandom(size_t evr_i)const
	{
		fprintf(mFile,"\"%s.evr[%i]\"",mName.c_str(),evr_i);
	}
	void getEventRandom()const
	{

		fprintf(mFile,"\"%s.evr\"",mName.c_str());
	}
	void getEventSpread(size_t esp_i)const
	{
		fprintf(mFile,"\"%s.esp[%i]\"",mName.c_str(),esp_i);
	}
	void getEventSpread()const
	{

		fprintf(mFile,"\"%s.esp\"",mName.c_str());
	}
	void getEventProc(size_t epr_i)const
	{
		fprintf(mFile,"\"%s.epr[%i]\"",mName.c_str(),epr_i);
	}
	void getEventProc()const
	{

		fprintf(mFile,"\"%s.epr\"",mName.c_str());
	}
	void getInstanceData(size_t idt_i)const
	{
		fprintf(mFile,"\"%s.idt[%i]\"",mName.c_str(),idt_i);
	}
	void getInstanceData()const
	{

		fprintf(mFile,"\"%s.idt\"",mName.c_str());
	}
	void getInstancePointData(size_t idt_i)const
	{
		fprintf(mFile,"\"%s.idt[%i].ipd\"",mName.c_str(),idt_i);
	}
	void getInstancePointData()const
	{

		fprintf(mFile,"\"%s.idt.ipd\"",mName.c_str());
	}
	void getNumberOfEvents()const
	{
		fprintf(mFile,"\"%s.nev\"",mName.c_str());
	}
	void getEventNameCount()const
	{
		fprintf(mFile,"\"%s.enc\"",mName.c_str());
	}
	void getFieldConnections(size_t fc_i)const
	{
		fprintf(mFile,"\"%s.fc[%i]\"",mName.c_str(),fc_i);
	}
	void getFieldConnections()const
	{

		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getCollisionConnections(size_t cc_i)const
	{
		fprintf(mFile,"\"%s.cc[%i]\"",mName.c_str(),cc_i);
	}
	void getCollisionConnections()const
	{

		fprintf(mFile,"\"%s.cc\"",mName.c_str());
	}
	void getConnectionsToMe(size_t ct_i)const
	{
		fprintf(mFile,"\"%s.ct[%i]\"",mName.c_str(),ct_i);
	}
	void getConnectionsToMe()const
	{

		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getAuxiliariesOwned()const
	{
		fprintf(mFile,"\"%s.ao\"",mName.c_str());
	}
	void getEmitterConnections(size_t ec_i)const
	{
		fprintf(mFile,"\"%s.ec[%i]\"",mName.c_str(),ec_i);
	}
	void getEmitterConnections()const
	{

		fprintf(mFile,"\"%s.ec\"",mName.c_str());
	}
	void getInheritColor()const
	{
		fprintf(mFile,"\"%s.inc\"",mName.c_str());
	}
	void getShapeNameMsg()const
	{
		fprintf(mFile,"\"%s.snmg\"",mName.c_str());
	}
	void getDoDynamics()const
	{
		fprintf(mFile,"\"%s.ddy\"",mName.c_str());
	}
	void getDoEmission()const
	{
		fprintf(mFile,"\"%s.dem\"",mName.c_str());
	}
	void getForceEmission()const
	{
		fprintf(mFile,"\"%s.fem\"",mName.c_str());
	}
	void getDoAge()const
	{
		fprintf(mFile,"\"%s.dag\"",mName.c_str());
	}
	void getAgesLastDone()const
	{
		fprintf(mFile,"\"%s.agld\"",mName.c_str());
	}
	void getTimeLastComputed()const
	{
		fprintf(mFile,"\"%s.tlc\"",mName.c_str());
	}
	void getParentMatrixDirty()const
	{
		fprintf(mFile,"\"%s.pmd\"",mName.c_str());
	}
	void getNewFileFormat()const
	{
		fprintf(mFile,"\"%s.nff\"",mName.c_str());
	}
	void getDepthSort()const
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());
	}
	void getParticleRenderType()const
	{
		fprintf(mFile,"\"%s.prt\"",mName.c_str());
	}
	void getDisableCloudAxis()const
	{
		fprintf(mFile,"\"%s.dca\"",mName.c_str());
	}
	void getNormalizeVelocity()const
	{
		fprintf(mFile,"\"%s.nvl\"",mName.c_str());
	}
	void getMentalRayControls()const
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());
	}
	void getMiOverrideCaustics()const
	{
		fprintf(mFile,"\"%s.mrc.oca\"",mName.c_str());
	}
	void getMiCausticAccuracy()const
	{
		fprintf(mFile,"\"%s.mrc.caa\"",mName.c_str());
	}
	void getMiCausticRadius()const
	{
		fprintf(mFile,"\"%s.mrc.car\"",mName.c_str());
	}
	void getMiOverrideGlobalIllumination()const
	{
		fprintf(mFile,"\"%s.mrc.ogi\"",mName.c_str());
	}
	void getMiGlobillumAccuracy()const
	{
		fprintf(mFile,"\"%s.mrc.gia\"",mName.c_str());
	}
	void getMiGlobillumRadius()const
	{
		fprintf(mFile,"\"%s.mrc.gir\"",mName.c_str());
	}
	void getMiOverrideFinalGather()const
	{
		fprintf(mFile,"\"%s.mrc.ofg\"",mName.c_str());
	}
	void getMiFinalGatherRays()const
	{
		fprintf(mFile,"\"%s.mrc.fry\"",mName.c_str());
	}
	void getMiFinalGatherMinRadius()const
	{
		fprintf(mFile,"\"%s.mrc.fmn\"",mName.c_str());
	}
	void getMiFinalGatherMaxRadius()const
	{
		fprintf(mFile,"\"%s.mrc.fmx\"",mName.c_str());
	}
	void getMiFinalGatherFilter()const
	{
		fprintf(mFile,"\"%s.mrc.ffi\"",mName.c_str());
	}
	void getMiFinalGatherView()const
	{
		fprintf(mFile,"\"%s.mrc.fgv\"",mName.c_str());
	}
	void getMiOverrideSamples()const
	{
		fprintf(mFile,"\"%s.mrc.oos\"",mName.c_str());
	}
	void getMiMinSamples()const
	{
		fprintf(mFile,"\"%s.mrc.mins\"",mName.c_str());
	}
	void getMiMaxSamples()const
	{
		fprintf(mFile,"\"%s.mrc.maxs\"",mName.c_str());
	}
	void getPpFieldData(size_t ppfd_i)const
	{
		fprintf(mFile,"\"%s.ppfd[%i]\"",mName.c_str(),ppfd_i);
	}
	void getPpFieldData()const
	{

		fprintf(mFile,"\"%s.ppfd\"",mName.c_str());
	}
	void getOwnerPPFieldData(size_t opfd_i)const
	{
		fprintf(mFile,"\"%s.opfd[%i]\"",mName.c_str(),opfd_i);
	}
	void getOwnerPPFieldData()const
	{

		fprintf(mFile,"\"%s.opfd\"",mName.c_str());
	}
	void getDeformedPosition()const
	{
		fprintf(mFile,"\"%s.dpos\"",mName.c_str());
	}
protected:
	Particle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DeformableShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLE_H__
