/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURFEEDBACK_H__
#define __MayaDM_FURFEEDBACK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLocator.h"
namespace MayaDM
{
class FurFeedback : public Locator
{
public:
	struct Attractors{
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
		bool miFinalGatherCast;
		bool miFinalGatherReceive;
		bool miTransparencyCast;
		bool miTransparencyReceive;
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
			fprintf(file,"%i ", miMaxSamples);
			fprintf(file,"%i ", miFinalGatherCast);
			fprintf(file,"%i ", miFinalGatherReceive);
			fprintf(file,"%i ", miTransparencyCast);
			fprintf(file,"%i", miTransparencyReceive);
		}
	};
public:
	FurFeedback():Locator(){}
	FurFeedback(FILE* file,const std::string& name,const std::string& parent=""):Locator(file, name, parent, "FurFeedback"){}
	virtual ~FurFeedback(){}
	void setInputSurface(const nurbsSurface& is)
	{
		fprintf(mFile,"\tsetAttr \".is\" -type \"nurbsSurface\" ");
		is.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputMesh(const mesh& imsh)
	{
		fprintf(mFile,"\tsetAttr \".imsh\" -type \"mesh\" ");
		imsh.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRealUSamples(int rus)
	{
		if(rus == 32) return;
		fprintf(mFile,"\tsetAttr \".rus\" %i;\n", rus);

	}
	void setRealVSamples(int rvs)
	{
		if(rvs == 32) return;
		fprintf(mFile,"\tsetAttr \".rvs\" %i;\n", rvs);

	}
	void setUSamples(int us)
	{
		if(us == 32) return;
		fprintf(mFile,"\tsetAttr \".us\" %i;\n", us);

	}
	void setVSamples(int vs)
	{
		if(vs == 32) return;
		fprintf(mFile,"\tsetAttr \".vs\" %i;\n", vs);

	}
	void setFlipNormals(bool fn)
	{
		if(fn == false) return;
		fprintf(mFile,"\tsetAttr \".fn\" %i;\n", fn);

	}
	void setHairs(const pointArray& h)
	{
		fprintf(mFile,"\tsetAttr \".h\" -type \"pointArray\" ");
		h.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFurAccuracy(float ha)
	{
		if(ha == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ha\" %f;\n", ha);

	}
	void setFurGlobalScale(float fgs)
	{
		if(fgs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fgs\" %f;\n", fgs);

	}
	void setAttractorGlobalScale(float ags)
	{
		if(ags == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ags\" %f;\n", ags);

	}
	void setExportAttr(const string& ea)
	{
		if(ea == "n/a") return;
		fprintf(mFile,"\tsetAttr \".ea\" -type \"string\" ");
		ea.write(mFile);
		fprintf(mFile,";\n");

	}
	void setExportFile(const string& ef)
	{
		if(ef == "n/a") return;
		fprintf(mFile,"\tsetAttr \".ef\" -type \"string\" ");
		ef.write(mFile);
		fprintf(mFile,";\n");

	}
	void setExportWidth(int ew)
	{
		if(ew == 256) return;
		fprintf(mFile,"\tsetAttr \".ew\" %i;\n", ew);

	}
	void setExportHeight(int eh)
	{
		if(eh == 256) return;
		fprintf(mFile,"\tsetAttr \".eh\" %i;\n", eh);

	}
	void setColorFeedbackEnabled(bool cfe)
	{
		if(cfe == false) return;
		fprintf(mFile,"\tsetAttr \".cfe\" %i;\n", cfe);

	}
	void setAttractorModel(unsigned int amd)
	{
		if(amd == 0) return;
		fprintf(mFile,"\tsetAttr \".amd\" %i;\n", amd);

	}
	void setAttractorsPerHair(int aph)
	{
		if(aph == 1) return;
		fprintf(mFile,"\tsetAttr \".aph\" %i;\n", aph);

	}
	void setDrawAttractors(bool drat)
	{
		if(drat == false) return;
		fprintf(mFile,"\tsetAttr \".drat\" %i;\n", drat);

	}
	void setLength(double dl)
	{
		if(dl == 1) return;
		fprintf(mFile,"\tsetAttr \".dl\" %f;\n", dl);

	}
	void setLengthSamples(size_t ls_i,double ls)
	{
		if(ls == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ls[%i]\" %f;\n", ls_i,ls);

	}
	void setLengthSamples(size_t ls_start,size_t ls_end,double* ls)
	{
		fprintf(mFile,"\tsetAttr \".ls[%i:%i]\" ", ls_start,ls_end);
		size_t size = (ls_end-ls_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ls[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startLengthSamples(size_t ls_start,size_t ls_end)
	{
		fprintf(mFile,"\tsetAttr \".ls[%i:%i]\"",ls_start,ls_end);

	}
	void appendLengthSamples(double ls)
	{
		fprintf(mFile," %f",ls);

	}
	void endLengthSamples()
	{
		fprintf(mFile,";\n");

	}
	void setLengthMap(const string& lm)
	{
		if(lm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".lm\" -type \"string\" ");
		lm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLengthMapOffset(double lmo)
	{
		if(lmo == 0) return;
		fprintf(mFile,"\tsetAttr \".lmo\" %f;\n", lmo);

	}
	void setLengthMapMult(double lmm)
	{
		if(lmm == 1) return;
		fprintf(mFile,"\tsetAttr \".lmm\" %f;\n", lmm);

	}
	void setLengthNoise(double ln)
	{
		if(ln == 0) return;
		fprintf(mFile,"\tsetAttr \".ln\" %f;\n", ln);

	}
	void setLengthNoiseFreq(float lnf)
	{
		if(lnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".lnf\" %f;\n", lnf);

	}
	void setLengthSamplesDirty(int lsd)
	{
		if(lsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lsd\" %i;\n", lsd);

	}
	void setLengthMapDirty(int lmd)
	{
		if(lmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lmd\" %i;\n", lmd);

	}
	void setInclination(float din)
	{
		if(din == 0.0) return;
		fprintf(mFile,"\tsetAttr \".din\" %f;\n", din);

	}
	void setInclinationSamples(size_t ins_i,double ins)
	{
		if(ins == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ins[%i]\" %f;\n", ins_i,ins);

	}
	void setInclinationSamples(size_t ins_start,size_t ins_end,double* ins)
	{
		fprintf(mFile,"\tsetAttr \".ins[%i:%i]\" ", ins_start,ins_end);
		size_t size = (ins_end-ins_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ins[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startInclinationSamples(size_t ins_start,size_t ins_end)
	{
		fprintf(mFile,"\tsetAttr \".ins[%i:%i]\"",ins_start,ins_end);

	}
	void appendInclinationSamples(double ins)
	{
		fprintf(mFile," %f",ins);

	}
	void endInclinationSamples()
	{
		fprintf(mFile,";\n");

	}
	void setInclinationMap(const string& inm)
	{
		if(inm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".inm\" -type \"string\" ");
		inm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInclinationMapOffset(float inmo)
	{
		if(inmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".inmo\" %f;\n", inmo);

	}
	void setInclinationMapMult(float inmm)
	{
		if(inmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".inmm\" %f;\n", inmm);

	}
	void setInclinationNoise(float inn)
	{
		if(inn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".inn\" %f;\n", inn);

	}
	void setInclinationNoiseFreq(float innf)
	{
		if(innf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".innf\" %f;\n", innf);

	}
	void setInclinationSamplesDirty(int insd)
	{
		if(insd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".insd\" %i;\n", insd);

	}
	void setInclinationMapDirty(int inmd)
	{
		if(inmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".inmd\" %i;\n", inmd);

	}
	void setRoll(float drl)
	{
		if(drl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".drl\" %f;\n", drl);

	}
	void setRollSamples(size_t rls_i,double rls)
	{
		if(rls == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rls[%i]\" %f;\n", rls_i,rls);

	}
	void setRollSamples(size_t rls_start,size_t rls_end,double* rls)
	{
		fprintf(mFile,"\tsetAttr \".rls[%i:%i]\" ", rls_start,rls_end);
		size_t size = (rls_end-rls_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",rls[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startRollSamples(size_t rls_start,size_t rls_end)
	{
		fprintf(mFile,"\tsetAttr \".rls[%i:%i]\"",rls_start,rls_end);

	}
	void appendRollSamples(double rls)
	{
		fprintf(mFile," %f",rls);

	}
	void endRollSamples()
	{
		fprintf(mFile,";\n");

	}
	void setRollMap(const string& rlm)
	{
		if(rlm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".rlm\" -type \"string\" ");
		rlm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRollMapOffset(float rlmo)
	{
		if(rlmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rlmo\" %f;\n", rlmo);

	}
	void setRollMapMult(float rlmm)
	{
		if(rlmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rlmm\" %f;\n", rlmm);

	}
	void setRollNoise(float rln)
	{
		if(rln == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rln\" %f;\n", rln);

	}
	void setRollNoiseFreq(float rlnf)
	{
		if(rlnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".rlnf\" %f;\n", rlnf);

	}
	void setRollSamplesDirty(int rlsd)
	{
		if(rlsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rlsd\" %i;\n", rlsd);

	}
	void setRollMapDirty(int rlmd)
	{
		if(rlmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rlmd\" %i;\n", rlmd);

	}
	void setPolar(float dpo)
	{
		if(dpo == 0.5) return;
		fprintf(mFile,"\tsetAttr \".dpo\" %f;\n", dpo);

	}
	void setPolarSamples(size_t pos_i,double pos)
	{
		if(pos == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pos[%i]\" %f;\n", pos_i,pos);

	}
	void setPolarSamples(size_t pos_start,size_t pos_end,double* pos)
	{
		fprintf(mFile,"\tsetAttr \".pos[%i:%i]\" ", pos_start,pos_end);
		size_t size = (pos_end-pos_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",pos[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startPolarSamples(size_t pos_start,size_t pos_end)
	{
		fprintf(mFile,"\tsetAttr \".pos[%i:%i]\"",pos_start,pos_end);

	}
	void appendPolarSamples(double pos)
	{
		fprintf(mFile," %f",pos);

	}
	void endPolarSamples()
	{
		fprintf(mFile,";\n");

	}
	void setPolarMap(const string& pom)
	{
		if(pom == "n/a") return;
		fprintf(mFile,"\tsetAttr \".pom\" -type \"string\" ");
		pom.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPolarMapOffset(float pomo)
	{
		if(pomo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pomo\" %f;\n", pomo);

	}
	void setPolarMapMult(float pomm)
	{
		if(pomm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pomm\" %f;\n", pomm);

	}
	void setPolarNoise(float pon)
	{
		if(pon == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pon\" %f;\n", pon);

	}
	void setPolarNoiseFreq(float ponf)
	{
		if(ponf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".ponf\" %f;\n", ponf);

	}
	void setPolarSamplesDirty(int posd)
	{
		if(posd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".posd\" %i;\n", posd);

	}
	void setPolarMapDirty(int pomd)
	{
		if(pomd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pomd\" %i;\n", pomd);

	}
	void setBaldness(float db)
	{
		if(db == 1.0) return;
		fprintf(mFile,"\tsetAttr \".db\" %f;\n", db);

	}
	void setBaldnessSamples(size_t bs_i,double bs)
	{
		if(bs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bs[%i]\" %f;\n", bs_i,bs);

	}
	void setBaldnessSamples(size_t bs_start,size_t bs_end,double* bs)
	{
		fprintf(mFile,"\tsetAttr \".bs[%i:%i]\" ", bs_start,bs_end);
		size_t size = (bs_end-bs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",bs[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startBaldnessSamples(size_t bs_start,size_t bs_end)
	{
		fprintf(mFile,"\tsetAttr \".bs[%i:%i]\"",bs_start,bs_end);

	}
	void appendBaldnessSamples(double bs)
	{
		fprintf(mFile," %f",bs);

	}
	void endBaldnessSamples()
	{
		fprintf(mFile,";\n");

	}
	void setBaldnessMap(const string& bm)
	{
		if(bm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".bm\" -type \"string\" ");
		bm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaldnessMapOffset(float bmo)
	{
		if(bmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bmo\" %f;\n", bmo);

	}
	void setBaldnessMapMult(float bmm)
	{
		if(bmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bmm\" %f;\n", bmm);

	}
	void setBaldnessNoise(float bn)
	{
		if(bn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bn\" %f;\n", bn);

	}
	void setBaldnessNoiseFreq(float bnf)
	{
		if(bnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".bnf\" %f;\n", bnf);

	}
	void setBaldnessSamplesDirty(int bsd)
	{
		if(bsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bsd\" %i;\n", bsd);

	}
	void setBaldnessMapDirty(int bmd)
	{
		if(bmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bmd\" %i;\n", bmd);

	}
	void setBaseOpacity(float dbo)
	{
		if(dbo == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dbo\" %f;\n", dbo);

	}
	void setBaseOpacitySamples(size_t bos_i,double bos)
	{
		if(bos == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bos[%i]\" %f;\n", bos_i,bos);

	}
	void setBaseOpacitySamples(size_t bos_start,size_t bos_end,double* bos)
	{
		fprintf(mFile,"\tsetAttr \".bos[%i:%i]\" ", bos_start,bos_end);
		size_t size = (bos_end-bos_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",bos[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startBaseOpacitySamples(size_t bos_start,size_t bos_end)
	{
		fprintf(mFile,"\tsetAttr \".bos[%i:%i]\"",bos_start,bos_end);

	}
	void appendBaseOpacitySamples(double bos)
	{
		fprintf(mFile," %f",bos);

	}
	void endBaseOpacitySamples()
	{
		fprintf(mFile,";\n");

	}
	void setBaseOpacityMap(const string& bom)
	{
		if(bom == "n/a") return;
		fprintf(mFile,"\tsetAttr \".bom\" -type \"string\" ");
		bom.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseOpacityMapOffset(float bomo)
	{
		if(bomo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bomo\" %f;\n", bomo);

	}
	void setBaseOpacityMapMult(float bomm)
	{
		if(bomm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bomm\" %f;\n", bomm);

	}
	void setBaseOpacityNoise(float bon)
	{
		if(bon == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bon\" %f;\n", bon);

	}
	void setBaseOpacityNoiseFreq(float bonf)
	{
		if(bonf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".bonf\" %f;\n", bonf);

	}
	void setBaseOpacitySamplesDirty(int bosd)
	{
		if(bosd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bosd\" %i;\n", bosd);

	}
	void setBaseOpacityMapDirty(int bomd)
	{
		if(bomd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bomd\" %i;\n", bomd);

	}
	void setTipOpacity(float dto)
	{
		if(dto == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dto\" %f;\n", dto);

	}
	void setTipOpacitySamples(size_t tos_i,double tos)
	{
		if(tos == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tos[%i]\" %f;\n", tos_i,tos);

	}
	void setTipOpacitySamples(size_t tos_start,size_t tos_end,double* tos)
	{
		fprintf(mFile,"\tsetAttr \".tos[%i:%i]\" ", tos_start,tos_end);
		size_t size = (tos_end-tos_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",tos[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startTipOpacitySamples(size_t tos_start,size_t tos_end)
	{
		fprintf(mFile,"\tsetAttr \".tos[%i:%i]\"",tos_start,tos_end);

	}
	void appendTipOpacitySamples(double tos)
	{
		fprintf(mFile," %f",tos);

	}
	void endTipOpacitySamples()
	{
		fprintf(mFile,";\n");

	}
	void setTipOpacityMap(const string& tom)
	{
		if(tom == "n/a") return;
		fprintf(mFile,"\tsetAttr \".tom\" -type \"string\" ");
		tom.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipOpacityMapOffset(float tomo)
	{
		if(tomo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tomo\" %f;\n", tomo);

	}
	void setTipOpacityMapMult(float tomm)
	{
		if(tomm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tomm\" %f;\n", tomm);

	}
	void setTipOpacityNoise(float ton)
	{
		if(ton == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ton\" %f;\n", ton);

	}
	void setTipOpacityNoiseFreq(float tonf)
	{
		if(tonf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".tonf\" %f;\n", tonf);

	}
	void setTipOpacitySamplesDirty(int tosd)
	{
		if(tosd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tosd\" %i;\n", tosd);

	}
	void setTipOpacityMapDirty(int tomd)
	{
		if(tomd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tomd\" %i;\n", tomd);

	}
	void setBaseCurl(float dbcl)
	{
		if(dbcl == 0.50) return;
		fprintf(mFile,"\tsetAttr \".dbcl\" %f;\n", dbcl);

	}
	void setBaseCurlSamples(size_t bcls_i,double bcls)
	{
		if(bcls == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bcls[%i]\" %f;\n", bcls_i,bcls);

	}
	void setBaseCurlSamples(size_t bcls_start,size_t bcls_end,double* bcls)
	{
		fprintf(mFile,"\tsetAttr \".bcls[%i:%i]\" ", bcls_start,bcls_end);
		size_t size = (bcls_end-bcls_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",bcls[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startBaseCurlSamples(size_t bcls_start,size_t bcls_end)
	{
		fprintf(mFile,"\tsetAttr \".bcls[%i:%i]\"",bcls_start,bcls_end);

	}
	void appendBaseCurlSamples(double bcls)
	{
		fprintf(mFile," %f",bcls);

	}
	void endBaseCurlSamples()
	{
		fprintf(mFile,";\n");

	}
	void setBaseCurlMap(const string& bclm)
	{
		if(bclm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".bclm\" -type \"string\" ");
		bclm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseCurlMapOffset(float bclmo)
	{
		if(bclmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bclmo\" %f;\n", bclmo);

	}
	void setBaseCurlMapMult(float bclmm)
	{
		if(bclmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bclmm\" %f;\n", bclmm);

	}
	void setBaseCurlNoise(float bcln)
	{
		if(bcln == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bcln\" %f;\n", bcln);

	}
	void setBaseCurlNoiseFreq(float bclnf)
	{
		if(bclnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".bclnf\" %f;\n", bclnf);

	}
	void setBaseCurlSamplesDirty(int bclsd)
	{
		if(bclsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bclsd\" %i;\n", bclsd);

	}
	void setBaseCurlMapDirty(int bclmd)
	{
		if(bclmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bclmd\" %i;\n", bclmd);

	}
	void setTipCurl(float dtcl)
	{
		if(dtcl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".dtcl\" %f;\n", dtcl);

	}
	void setTipCurlSamples(size_t tcls_i,double tcls)
	{
		if(tcls == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tcls[%i]\" %f;\n", tcls_i,tcls);

	}
	void setTipCurlSamples(size_t tcls_start,size_t tcls_end,double* tcls)
	{
		fprintf(mFile,"\tsetAttr \".tcls[%i:%i]\" ", tcls_start,tcls_end);
		size_t size = (tcls_end-tcls_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",tcls[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startTipCurlSamples(size_t tcls_start,size_t tcls_end)
	{
		fprintf(mFile,"\tsetAttr \".tcls[%i:%i]\"",tcls_start,tcls_end);

	}
	void appendTipCurlSamples(double tcls)
	{
		fprintf(mFile," %f",tcls);

	}
	void endTipCurlSamples()
	{
		fprintf(mFile,";\n");

	}
	void setTipCurlMap(const string& tclm)
	{
		if(tclm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".tclm\" -type \"string\" ");
		tclm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipCurlMapOffset(float tclmo)
	{
		if(tclmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tclmo\" %f;\n", tclmo);

	}
	void setTipCurlMapMult(float tclmm)
	{
		if(tclmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tclmm\" %f;\n", tclmm);

	}
	void setTipCurlNoise(float tcln)
	{
		if(tcln == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tcln\" %f;\n", tcln);

	}
	void setTipCurlNoiseFreq(float tclnf)
	{
		if(tclnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".tclnf\" %f;\n", tclnf);

	}
	void setTipCurlSamplesDirty(int tclsd)
	{
		if(tclsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tclsd\" %i;\n", tclsd);

	}
	void setTipCurlMapDirty(int tclmd)
	{
		if(tclmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tclmd\" %i;\n", tclmd);

	}
	void setBaseWidth(double dbw)
	{
		if(dbw == 0) return;
		fprintf(mFile,"\tsetAttr \".dbw\" %f;\n", dbw);

	}
	void setBaseWidthSamples(size_t bws_i,double bws)
	{
		if(bws == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bws[%i]\" %f;\n", bws_i,bws);

	}
	void setBaseWidthSamples(size_t bws_start,size_t bws_end,double* bws)
	{
		fprintf(mFile,"\tsetAttr \".bws[%i:%i]\" ", bws_start,bws_end);
		size_t size = (bws_end-bws_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",bws[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startBaseWidthSamples(size_t bws_start,size_t bws_end)
	{
		fprintf(mFile,"\tsetAttr \".bws[%i:%i]\"",bws_start,bws_end);

	}
	void appendBaseWidthSamples(double bws)
	{
		fprintf(mFile," %f",bws);

	}
	void endBaseWidthSamples()
	{
		fprintf(mFile,";\n");

	}
	void setBaseWidthMap(const string& bwm)
	{
		if(bwm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".bwm\" -type \"string\" ");
		bwm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseWidthMapOffset(double bwmo)
	{
		if(bwmo == 0) return;
		fprintf(mFile,"\tsetAttr \".bwmo\" %f;\n", bwmo);

	}
	void setBaseWidthMapMult(double bwmm)
	{
		if(bwmm == 1) return;
		fprintf(mFile,"\tsetAttr \".bwmm\" %f;\n", bwmm);

	}
	void setBaseWidthNoise(double bwn)
	{
		if(bwn == 0) return;
		fprintf(mFile,"\tsetAttr \".bwn\" %f;\n", bwn);

	}
	void setBaseWidthNoiseFreq(float bwnf)
	{
		if(bwnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".bwnf\" %f;\n", bwnf);

	}
	void setBaseWidthSamplesDirty(int bwsd)
	{
		if(bwsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bwsd\" %i;\n", bwsd);

	}
	void setBaseWidthMapDirty(int bwmd)
	{
		if(bwmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bwmd\" %i;\n", bwmd);

	}
	void setTipWidth(double dtw)
	{
		if(dtw == 0) return;
		fprintf(mFile,"\tsetAttr \".dtw\" %f;\n", dtw);

	}
	void setTipWidthSamples(size_t tws_i,double tws)
	{
		if(tws == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tws[%i]\" %f;\n", tws_i,tws);

	}
	void setTipWidthSamples(size_t tws_start,size_t tws_end,double* tws)
	{
		fprintf(mFile,"\tsetAttr \".tws[%i:%i]\" ", tws_start,tws_end);
		size_t size = (tws_end-tws_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",tws[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startTipWidthSamples(size_t tws_start,size_t tws_end)
	{
		fprintf(mFile,"\tsetAttr \".tws[%i:%i]\"",tws_start,tws_end);

	}
	void appendTipWidthSamples(double tws)
	{
		fprintf(mFile," %f",tws);

	}
	void endTipWidthSamples()
	{
		fprintf(mFile,";\n");

	}
	void setTipWidthMap(const string& twm)
	{
		if(twm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".twm\" -type \"string\" ");
		twm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipWidthMapOffset(double twmo)
	{
		if(twmo == 0) return;
		fprintf(mFile,"\tsetAttr \".twmo\" %f;\n", twmo);

	}
	void setTipWidthMapMult(double twmm)
	{
		if(twmm == 1) return;
		fprintf(mFile,"\tsetAttr \".twmm\" %f;\n", twmm);

	}
	void setTipWidthNoise(double twn)
	{
		if(twn == 0) return;
		fprintf(mFile,"\tsetAttr \".twn\" %f;\n", twn);

	}
	void setTipWidthNoiseFreq(float twnf)
	{
		if(twnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".twnf\" %f;\n", twnf);

	}
	void setTipWidthSamplesDirty(int twsd)
	{
		if(twsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".twsd\" %i;\n", twsd);

	}
	void setTipWidthMapDirty(int twmd)
	{
		if(twmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".twmd\" %i;\n", twmd);

	}
	void setScraggle(float ds)
	{
		if(ds == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ds\" %f;\n", ds);

	}
	void setScraggleSamples(size_t ss_i,double ss)
	{
		if(ss == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ss[%i]\" %f;\n", ss_i,ss);

	}
	void setScraggleSamples(size_t ss_start,size_t ss_end,double* ss)
	{
		fprintf(mFile,"\tsetAttr \".ss[%i:%i]\" ", ss_start,ss_end);
		size_t size = (ss_end-ss_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ss[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startScraggleSamples(size_t ss_start,size_t ss_end)
	{
		fprintf(mFile,"\tsetAttr \".ss[%i:%i]\"",ss_start,ss_end);

	}
	void appendScraggleSamples(double ss)
	{
		fprintf(mFile," %f",ss);

	}
	void endScraggleSamples()
	{
		fprintf(mFile,";\n");

	}
	void setScraggleMap(const string& sm)
	{
		if(sm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".sm\" -type \"string\" ");
		sm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScraggleMapOffset(float smo)
	{
		if(smo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".smo\" %f;\n", smo);

	}
	void setScraggleMapMult(float smm)
	{
		if(smm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".smm\" %f;\n", smm);

	}
	void setScraggleNoise(float sn)
	{
		if(sn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sn\" %f;\n", sn);

	}
	void setScraggleNoiseFreq(float snf)
	{
		if(snf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".snf\" %f;\n", snf);

	}
	void setScraggleSamplesDirty(int ssd)
	{
		if(ssd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ssd\" %i;\n", ssd);

	}
	void setScraggleMapDirty(int smd)
	{
		if(smd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".smd\" %i;\n", smd);

	}
	void setScraggleCorrelation(float dsco)
	{
		if(dsco == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dsco\" %f;\n", dsco);

	}
	void setScraggleCorrelationSamples(size_t scos_i,double scos)
	{
		if(scos == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scos[%i]\" %f;\n", scos_i,scos);

	}
	void setScraggleCorrelationSamples(size_t scos_start,size_t scos_end,double* scos)
	{
		fprintf(mFile,"\tsetAttr \".scos[%i:%i]\" ", scos_start,scos_end);
		size_t size = (scos_end-scos_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",scos[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startScraggleCorrelationSamples(size_t scos_start,size_t scos_end)
	{
		fprintf(mFile,"\tsetAttr \".scos[%i:%i]\"",scos_start,scos_end);

	}
	void appendScraggleCorrelationSamples(double scos)
	{
		fprintf(mFile," %f",scos);

	}
	void endScraggleCorrelationSamples()
	{
		fprintf(mFile,";\n");

	}
	void setScraggleCorrelationMap(const string& scom)
	{
		if(scom == "n/a") return;
		fprintf(mFile,"\tsetAttr \".scom\" -type \"string\" ");
		scom.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScraggleCorrelationMapOffset(float scomo)
	{
		if(scomo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scomo\" %f;\n", scomo);

	}
	void setScraggleCorrelationMapMult(float scomm)
	{
		if(scomm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".scomm\" %f;\n", scomm);

	}
	void setScraggleCorrelationNoise(float scon)
	{
		if(scon == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scon\" %f;\n", scon);

	}
	void setScraggleCorrelationNoiseFreq(float sconf)
	{
		if(sconf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".sconf\" %f;\n", sconf);

	}
	void setScraggleCorrelationSamplesDirty(int scosd)
	{
		if(scosd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scosd\" %i;\n", scosd);

	}
	void setScraggleCorrelationMapDirty(int scomd)
	{
		if(scomd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scomd\" %i;\n", scomd);

	}
	void setScraggleFrequency(float dscf)
	{
		if(dscf == 5.0) return;
		fprintf(mFile,"\tsetAttr \".dscf\" %f;\n", dscf);

	}
	void setScraggleFrequencySamples(size_t scfs_i,double scfs)
	{
		if(scfs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scfs[%i]\" %f;\n", scfs_i,scfs);

	}
	void setScraggleFrequencySamples(size_t scfs_start,size_t scfs_end,double* scfs)
	{
		fprintf(mFile,"\tsetAttr \".scfs[%i:%i]\" ", scfs_start,scfs_end);
		size_t size = (scfs_end-scfs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",scfs[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startScraggleFrequencySamples(size_t scfs_start,size_t scfs_end)
	{
		fprintf(mFile,"\tsetAttr \".scfs[%i:%i]\"",scfs_start,scfs_end);

	}
	void appendScraggleFrequencySamples(double scfs)
	{
		fprintf(mFile," %f",scfs);

	}
	void endScraggleFrequencySamples()
	{
		fprintf(mFile,";\n");

	}
	void setScraggleFrequencyMap(const string& scfm)
	{
		if(scfm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".scfm\" -type \"string\" ");
		scfm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScraggleFrequencyMapOffset(float scfmo)
	{
		if(scfmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scfmo\" %f;\n", scfmo);

	}
	void setScraggleFrequencyMapMult(float scfmm)
	{
		if(scfmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".scfmm\" %f;\n", scfmm);

	}
	void setScraggleFrequencyNoise(float scfn)
	{
		if(scfn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scfn\" %f;\n", scfn);

	}
	void setScraggleFrequencyNoiseFreq(float scfnf)
	{
		if(scfnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".scfnf\" %f;\n", scfnf);

	}
	void setScraggleFrequencySamplesDirty(int scfsd)
	{
		if(scfsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scfsd\" %i;\n", scfsd);

	}
	void setScraggleFrequencyMapDirty(int scfmd)
	{
		if(scfmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scfmd\" %i;\n", scfmd);

	}
	void setSegments(float dseg)
	{
		if(dseg == 10) return;
		fprintf(mFile,"\tsetAttr \".dseg\" %f;\n", dseg);

	}
	void setSegmentsSamples(size_t segs_i,double segs)
	{
		if(segs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".segs[%i]\" %f;\n", segs_i,segs);

	}
	void setSegmentsSamples(size_t segs_start,size_t segs_end,double* segs)
	{
		fprintf(mFile,"\tsetAttr \".segs[%i:%i]\" ", segs_start,segs_end);
		size_t size = (segs_end-segs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",segs[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startSegmentsSamples(size_t segs_start,size_t segs_end)
	{
		fprintf(mFile,"\tsetAttr \".segs[%i:%i]\"",segs_start,segs_end);

	}
	void appendSegmentsSamples(double segs)
	{
		fprintf(mFile," %f",segs);

	}
	void endSegmentsSamples()
	{
		fprintf(mFile,";\n");

	}
	void setSegmentsMap(const string& segm)
	{
		if(segm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".segm\" -type \"string\" ");
		segm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSegmentsMapOffset(float segmo)
	{
		if(segmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".segmo\" %f;\n", segmo);

	}
	void setSegmentsMapMult(float segmm)
	{
		if(segmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".segmm\" %f;\n", segmm);

	}
	void setSegmentsNoise(float segn)
	{
		if(segn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".segn\" %f;\n", segn);

	}
	void setSegmentsNoiseFreq(float segnf)
	{
		if(segnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".segnf\" %f;\n", segnf);

	}
	void setSegmentsSamplesDirty(int segsd)
	{
		if(segsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".segsd\" %i;\n", segsd);

	}
	void setSegmentsMapDirty(int segmd)
	{
		if(segmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".segmd\" %i;\n", segmd);

	}
	void setAttraction(float dat)
	{
		if(dat == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dat\" %f;\n", dat);

	}
	void setAttractionSamples(size_t ats_i,double ats)
	{
		if(ats == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ats[%i]\" %f;\n", ats_i,ats);

	}
	void setAttractionSamples(size_t ats_start,size_t ats_end,double* ats)
	{
		fprintf(mFile,"\tsetAttr \".ats[%i:%i]\" ", ats_start,ats_end);
		size_t size = (ats_end-ats_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ats[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startAttractionSamples(size_t ats_start,size_t ats_end)
	{
		fprintf(mFile,"\tsetAttr \".ats[%i:%i]\"",ats_start,ats_end);

	}
	void appendAttractionSamples(double ats)
	{
		fprintf(mFile," %f",ats);

	}
	void endAttractionSamples()
	{
		fprintf(mFile,";\n");

	}
	void setAttractionMap(const string& atm)
	{
		if(atm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".atm\" -type \"string\" ");
		atm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAttractionMapOffset(float atmo)
	{
		if(atmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".atmo\" %f;\n", atmo);

	}
	void setAttractionMapMult(float atmm)
	{
		if(atmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".atmm\" %f;\n", atmm);

	}
	void setAttractionNoise(float atn)
	{
		if(atn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".atn\" %f;\n", atn);

	}
	void setAttractionNoiseFreq(float atnf)
	{
		if(atnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".atnf\" %f;\n", atnf);

	}
	void setAttractionSamplesDirty(int atsd)
	{
		if(atsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".atsd\" %i;\n", atsd);

	}
	void setAttractionMapDirty(int atmd)
	{
		if(atmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".atmd\" %i;\n", atmd);

	}
	void setOffset(double dofs)
	{
		if(dofs == 0) return;
		fprintf(mFile,"\tsetAttr \".dofs\" %f;\n", dofs);

	}
	void setOffsetSamples(size_t ofss_i,double ofss)
	{
		if(ofss == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ofss[%i]\" %f;\n", ofss_i,ofss);

	}
	void setOffsetSamples(size_t ofss_start,size_t ofss_end,double* ofss)
	{
		fprintf(mFile,"\tsetAttr \".ofss[%i:%i]\" ", ofss_start,ofss_end);
		size_t size = (ofss_end-ofss_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ofss[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startOffsetSamples(size_t ofss_start,size_t ofss_end)
	{
		fprintf(mFile,"\tsetAttr \".ofss[%i:%i]\"",ofss_start,ofss_end);

	}
	void appendOffsetSamples(double ofss)
	{
		fprintf(mFile," %f",ofss);

	}
	void endOffsetSamples()
	{
		fprintf(mFile,";\n");

	}
	void setOffsetMap(const string& ofsm)
	{
		if(ofsm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".ofsm\" -type \"string\" ");
		ofsm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffsetMapOffset(double ofsmo)
	{
		if(ofsmo == 0) return;
		fprintf(mFile,"\tsetAttr \".ofsmo\" %f;\n", ofsmo);

	}
	void setOffsetMapMult(double ofsmm)
	{
		if(ofsmm == 1) return;
		fprintf(mFile,"\tsetAttr \".ofsmm\" %f;\n", ofsmm);

	}
	void setOffsetNoise(double ofsn)
	{
		if(ofsn == 0) return;
		fprintf(mFile,"\tsetAttr \".ofsn\" %f;\n", ofsn);

	}
	void setOffsetNoiseFreq(float ofsnf)
	{
		if(ofsnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".ofsnf\" %f;\n", ofsnf);

	}
	void setOffsetSamplesDirty(int ofssd)
	{
		if(ofssd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ofssd\" %i;\n", ofssd);

	}
	void setOffsetMapDirty(int ofsmd)
	{
		if(ofsmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ofsmd\" %i;\n", ofsmd);

	}
	void setClumping(float dc)
	{
		if(dc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dc\" %f;\n", dc);

	}
	void setClumpingSamples(size_t cs_i,double cs)
	{
		if(cs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cs[%i]\" %f;\n", cs_i,cs);

	}
	void setClumpingSamples(size_t cs_start,size_t cs_end,double* cs)
	{
		fprintf(mFile,"\tsetAttr \".cs[%i:%i]\" ", cs_start,cs_end);
		size_t size = (cs_end-cs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cs[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startClumpingSamples(size_t cs_start,size_t cs_end)
	{
		fprintf(mFile,"\tsetAttr \".cs[%i:%i]\"",cs_start,cs_end);

	}
	void appendClumpingSamples(double cs)
	{
		fprintf(mFile," %f",cs);

	}
	void endClumpingSamples()
	{
		fprintf(mFile,";\n");

	}
	void setClumpingMap(const string& cm)
	{
		if(cm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".cm\" -type \"string\" ");
		cm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpingMapOffset(float cmo)
	{
		if(cmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cmo\" %f;\n", cmo);

	}
	void setClumpingMapMult(float cmm)
	{
		if(cmm == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cmm\" %f;\n", cmm);

	}
	void setClumpingNoise(float cn)
	{
		if(cn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cn\" %f;\n", cn);

	}
	void setClumpingNoiseFreq(float cnf)
	{
		if(cnf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cnf\" %f;\n", cnf);

	}
	void setClumpingSamplesDirty(int csd)
	{
		if(csd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csd\" %i;\n", csd);

	}
	void setClumpingMapDirty(int cmd)
	{
		if(cmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cmd\" %i;\n", cmd);

	}
	void setClumpingFrequency(float dcf)
	{
		if(dcf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dcf\" %f;\n", dcf);

	}
	void setClumpingFrequencySamples(size_t cfs_i,double cfs)
	{
		if(cfs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfs[%i]\" %f;\n", cfs_i,cfs);

	}
	void setClumpingFrequencySamples(size_t cfs_start,size_t cfs_end,double* cfs)
	{
		fprintf(mFile,"\tsetAttr \".cfs[%i:%i]\" ", cfs_start,cfs_end);
		size_t size = (cfs_end-cfs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cfs[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startClumpingFrequencySamples(size_t cfs_start,size_t cfs_end)
	{
		fprintf(mFile,"\tsetAttr \".cfs[%i:%i]\"",cfs_start,cfs_end);

	}
	void appendClumpingFrequencySamples(double cfs)
	{
		fprintf(mFile," %f",cfs);

	}
	void endClumpingFrequencySamples()
	{
		fprintf(mFile,";\n");

	}
	void setClumpingFrequencyMap(const string& cfm)
	{
		if(cfm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".cfm\" -type \"string\" ");
		cfm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpingFrequencyMapOffset(float cfmo)
	{
		if(cfmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfmo\" %f;\n", cfmo);

	}
	void setClumpingFrequencyMapMult(float cfmm)
	{
		if(cfmm == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfmm\" %f;\n", cfmm);

	}
	void setClumpingFrequencyNoise(float cfn)
	{
		if(cfn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfn\" %f;\n", cfn);

	}
	void setClumpingFrequencyNoiseFreq(float cfnf)
	{
		if(cfnf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfnf\" %f;\n", cfnf);

	}
	void setClumpingFrequencySamplesDirty(int cfsd)
	{
		if(cfsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfsd\" %i;\n", cfsd);

	}
	void setClumpingFrequencyMapDirty(int cfmd)
	{
		if(cfmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfmd\" %i;\n", cfmd);

	}
	void setClumpingShape(float dcs)
	{
		if(dcs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dcs\" %f;\n", dcs);

	}
	void setClumpingShapeSamples(size_t css_i,double css)
	{
		if(css == 0.0) return;
		fprintf(mFile,"\tsetAttr \".css[%i]\" %f;\n", css_i,css);

	}
	void setClumpingShapeSamples(size_t css_start,size_t css_end,double* css)
	{
		fprintf(mFile,"\tsetAttr \".css[%i:%i]\" ", css_start,css_end);
		size_t size = (css_end-css_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",css[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startClumpingShapeSamples(size_t css_start,size_t css_end)
	{
		fprintf(mFile,"\tsetAttr \".css[%i:%i]\"",css_start,css_end);

	}
	void appendClumpingShapeSamples(double css)
	{
		fprintf(mFile," %f",css);

	}
	void endClumpingShapeSamples()
	{
		fprintf(mFile,";\n");

	}
	void setClumpingShapeMap(const string& csm)
	{
		if(csm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".csm\" -type \"string\" ");
		csm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpingShapeMapOffset(float csmo)
	{
		if(csmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csmo\" %f;\n", csmo);

	}
	void setClumpingShapeMapMult(float csmm)
	{
		if(csmm == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csmm\" %f;\n", csmm);

	}
	void setClumpingShapeNoise(float csn)
	{
		if(csn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csn\" %f;\n", csn);

	}
	void setClumpingShapeNoiseFreq(float csnf)
	{
		if(csnf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csnf\" %f;\n", csnf);

	}
	void setClumpingShapeSamplesDirty(int cssd)
	{
		if(cssd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cssd\" %i;\n", cssd);

	}
	void setClumpingShapeMapDirty(int csmd)
	{
		if(csmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csmd\" %i;\n", csmd);

	}
	void setBaseColor(const float3& dbc)
	{
		if(dbc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".dbc\" -type \"float3\" ");
		dbc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseColorR(float dbcr)
	{
		if(dbcr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dbcr\" %f;\n", dbcr);

	}
	void setBaseColorG(float dbcg)
	{
		if(dbcg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dbcg\" %f;\n", dbcg);

	}
	void setBaseColorB(float dbcb)
	{
		if(dbcb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dbcb\" %f;\n", dbcb);

	}
	void setBaseColorSamples(size_t bcs_i,double bcs)
	{
		if(bcs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bcs[%i]\" %f;\n", bcs_i,bcs);

	}
	void setBaseColorSamples(size_t bcs_start,size_t bcs_end,double* bcs)
	{
		fprintf(mFile,"\tsetAttr \".bcs[%i:%i]\" ", bcs_start,bcs_end);
		size_t size = (bcs_end-bcs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",bcs[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startBaseColorSamples(size_t bcs_start,size_t bcs_end)
	{
		fprintf(mFile,"\tsetAttr \".bcs[%i:%i]\"",bcs_start,bcs_end);

	}
	void appendBaseColorSamples(double bcs)
	{
		fprintf(mFile," %f",bcs);

	}
	void endBaseColorSamples()
	{
		fprintf(mFile,";\n");

	}
	void setBaseColorMap(const string& bcm)
	{
		if(bcm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".bcm\" -type \"string\" ");
		bcm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseColorNoise(float bcn)
	{
		if(bcn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bcn\" %f;\n", bcn);

	}
	void setBaseColorNoiseFreq(float bcnf)
	{
		if(bcnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".bcnf\" %f;\n", bcnf);

	}
	void setBaseColorSamplesDirty(int bcsd)
	{
		if(bcsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bcsd\" %i;\n", bcsd);

	}
	void setBaseColorMapDirty(int bcmd)
	{
		if(bcmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bcmd\" %i;\n", bcmd);

	}
	void setTipColor(const float3& dtc)
	{
		if(dtc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".dtc\" -type \"float3\" ");
		dtc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipColorR(float dtcr)
	{
		if(dtcr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dtcr\" %f;\n", dtcr);

	}
	void setTipColorG(float dtcg)
	{
		if(dtcg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dtcg\" %f;\n", dtcg);

	}
	void setTipColorB(float dtcb)
	{
		if(dtcb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dtcb\" %f;\n", dtcb);

	}
	void setTipColorSamples(size_t tcs_i,double tcs)
	{
		if(tcs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tcs[%i]\" %f;\n", tcs_i,tcs);

	}
	void setTipColorSamples(size_t tcs_start,size_t tcs_end,double* tcs)
	{
		fprintf(mFile,"\tsetAttr \".tcs[%i:%i]\" ", tcs_start,tcs_end);
		size_t size = (tcs_end-tcs_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",tcs[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startTipColorSamples(size_t tcs_start,size_t tcs_end)
	{
		fprintf(mFile,"\tsetAttr \".tcs[%i:%i]\"",tcs_start,tcs_end);

	}
	void appendTipColorSamples(double tcs)
	{
		fprintf(mFile," %f",tcs);

	}
	void endTipColorSamples()
	{
		fprintf(mFile,";\n");

	}
	void setTipColorMap(const string& tcm)
	{
		if(tcm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".tcm\" -type \"string\" ");
		tcm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipColorNoise(float tcn)
	{
		if(tcn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tcn\" %f;\n", tcn);

	}
	void setTipColorNoiseFreq(float tcnf)
	{
		if(tcnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".tcnf\" %f;\n", tcnf);

	}
	void setTipColorSamplesDirty(int tcsd)
	{
		if(tcsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tcsd\" %i;\n", tcsd);

	}
	void setTipColorMapDirty(int tcmd)
	{
		if(tcmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tcmd\" %i;\n", tcmd);

	}
	void setRadius(double dar)
	{
		if(dar == 1) return;
		fprintf(mFile,"\tsetAttr \".dar\" %f;\n", dar);

	}
	void setRadiusSamples(size_t ars_i,double ars)
	{
		if(ars == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ars[%i]\" %f;\n", ars_i,ars);

	}
	void setRadiusSamples(size_t ars_start,size_t ars_end,double* ars)
	{
		fprintf(mFile,"\tsetAttr \".ars[%i:%i]\" ", ars_start,ars_end);
		size_t size = (ars_end-ars_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ars[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startRadiusSamples(size_t ars_start,size_t ars_end)
	{
		fprintf(mFile,"\tsetAttr \".ars[%i:%i]\"",ars_start,ars_end);

	}
	void appendRadiusSamples(double ars)
	{
		fprintf(mFile," %f",ars);

	}
	void endRadiusSamples()
	{
		fprintf(mFile,";\n");

	}
	void setRadiusMap(const string& arm)
	{
		if(arm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".arm\" -type \"string\" ");
		arm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRadiusMapOffset(double armo)
	{
		if(armo == 0) return;
		fprintf(mFile,"\tsetAttr \".armo\" %f;\n", armo);

	}
	void setRadiusMapMult(double armm)
	{
		if(armm == 1) return;
		fprintf(mFile,"\tsetAttr \".armm\" %f;\n", armm);

	}
	void setRadiusNoise(double arn)
	{
		if(arn == 0) return;
		fprintf(mFile,"\tsetAttr \".arn\" %f;\n", arn);

	}
	void setRadiusNoiseFreq(float arnf)
	{
		if(arnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".arnf\" %f;\n", arnf);

	}
	void setRadiusSamplesDirty(int arsd)
	{
		if(arsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".arsd\" %i;\n", arsd);

	}
	void setRadiusMapDirty(int armd)
	{
		if(armd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".armd\" %i;\n", armd);

	}
	void setPower(float dap)
	{
		if(dap == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dap\" %f;\n", dap);

	}
	void setPowerSamples(size_t aps_i,double aps)
	{
		if(aps == 0.0) return;
		fprintf(mFile,"\tsetAttr \".aps[%i]\" %f;\n", aps_i,aps);

	}
	void setPowerSamples(size_t aps_start,size_t aps_end,double* aps)
	{
		fprintf(mFile,"\tsetAttr \".aps[%i:%i]\" ", aps_start,aps_end);
		size_t size = (aps_end-aps_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",aps[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startPowerSamples(size_t aps_start,size_t aps_end)
	{
		fprintf(mFile,"\tsetAttr \".aps[%i:%i]\"",aps_start,aps_end);

	}
	void appendPowerSamples(double aps)
	{
		fprintf(mFile," %f",aps);

	}
	void endPowerSamples()
	{
		fprintf(mFile,";\n");

	}
	void setPowerMap(const string& apm)
	{
		if(apm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".apm\" -type \"string\" ");
		apm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPowerMapOffset(float apmo)
	{
		if(apmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".apmo\" %f;\n", apmo);

	}
	void setPowerMapMult(float apmm)
	{
		if(apmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".apmm\" %f;\n", apmm);

	}
	void setPowerNoise(float apn)
	{
		if(apn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".apn\" %f;\n", apn);

	}
	void setPowerNoiseFreq(float apnf)
	{
		if(apnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".apnf\" %f;\n", apnf);

	}
	void setPowerSamplesDirty(int apsd)
	{
		if(apsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".apsd\" %i;\n", apsd);

	}
	void setPowerMapDirty(int apmd)
	{
		if(apmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".apmd\" %i;\n", apmd);

	}
	void setInfluence(float dai)
	{
		if(dai == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dai\" %f;\n", dai);

	}
	void setInfluenceSamples(size_t ais_i,double ais)
	{
		if(ais == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ais[%i]\" %f;\n", ais_i,ais);

	}
	void setInfluenceSamples(size_t ais_start,size_t ais_end,double* ais)
	{
		fprintf(mFile,"\tsetAttr \".ais[%i:%i]\" ", ais_start,ais_end);
		size_t size = (ais_end-ais_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ais[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startInfluenceSamples(size_t ais_start,size_t ais_end)
	{
		fprintf(mFile,"\tsetAttr \".ais[%i:%i]\"",ais_start,ais_end);

	}
	void appendInfluenceSamples(double ais)
	{
		fprintf(mFile," %f",ais);

	}
	void endInfluenceSamples()
	{
		fprintf(mFile,";\n");

	}
	void setInfluenceMap(const string& aim)
	{
		if(aim == "n/a") return;
		fprintf(mFile,"\tsetAttr \".aim\" -type \"string\" ");
		aim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInfluenceMapOffset(float aimo)
	{
		if(aimo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".aimo\" %f;\n", aimo);

	}
	void setInfluenceMapMult(float aimm)
	{
		if(aimm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".aimm\" %f;\n", aimm);

	}
	void setInfluenceNoise(float ain)
	{
		if(ain == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ain\" %f;\n", ain);

	}
	void setInfluenceNoiseFreq(float ainf)
	{
		if(ainf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".ainf\" %f;\n", ainf);

	}
	void setInfluenceSamplesDirty(int aisd)
	{
		if(aisd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".aisd\" %i;\n", aisd);

	}
	void setInfluenceMapDirty(int aimd)
	{
		if(aimd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".aimd\" %i;\n", aimd);

	}
	void setStartLength(double dasl)
	{
		if(dasl == 0) return;
		fprintf(mFile,"\tsetAttr \".dasl\" %f;\n", dasl);

	}
	void setStartLengthSamples(size_t asls_i,double asls)
	{
		if(asls == 0.0) return;
		fprintf(mFile,"\tsetAttr \".asls[%i]\" %f;\n", asls_i,asls);

	}
	void setStartLengthSamples(size_t asls_start,size_t asls_end,double* asls)
	{
		fprintf(mFile,"\tsetAttr \".asls[%i:%i]\" ", asls_start,asls_end);
		size_t size = (asls_end-asls_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",asls[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startStartLengthSamples(size_t asls_start,size_t asls_end)
	{
		fprintf(mFile,"\tsetAttr \".asls[%i:%i]\"",asls_start,asls_end);

	}
	void appendStartLengthSamples(double asls)
	{
		fprintf(mFile," %f",asls);

	}
	void endStartLengthSamples()
	{
		fprintf(mFile,";\n");

	}
	void setStartLengthMap(const string& aslm)
	{
		if(aslm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".aslm\" -type \"string\" ");
		aslm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStartLengthMapOffset(double aslmo)
	{
		if(aslmo == 0) return;
		fprintf(mFile,"\tsetAttr \".aslmo\" %f;\n", aslmo);

	}
	void setStartLengthMapMult(double aslmm)
	{
		if(aslmm == 1) return;
		fprintf(mFile,"\tsetAttr \".aslmm\" %f;\n", aslmm);

	}
	void setStartLengthNoise(double asln)
	{
		if(asln == 0) return;
		fprintf(mFile,"\tsetAttr \".asln\" %f;\n", asln);

	}
	void setStartLengthNoiseFreq(float aslnf)
	{
		if(aslnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".aslnf\" %f;\n", aslnf);

	}
	void setStartLengthSamplesDirty(int aslsd)
	{
		if(aslsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".aslsd\" %i;\n", aslsd);

	}
	void setStartLengthMapDirty(int aslmd)
	{
		if(aslmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".aslmd\" %i;\n", aslmd);

	}
	void setEndLength(double dael)
	{
		if(dael == 5) return;
		fprintf(mFile,"\tsetAttr \".dael\" %f;\n", dael);

	}
	void setEndLengthSamples(size_t aels_i,double aels)
	{
		if(aels == 0.0) return;
		fprintf(mFile,"\tsetAttr \".aels[%i]\" %f;\n", aels_i,aels);

	}
	void setEndLengthSamples(size_t aels_start,size_t aels_end,double* aels)
	{
		fprintf(mFile,"\tsetAttr \".aels[%i:%i]\" ", aels_start,aels_end);
		size_t size = (aels_end-aels_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",aels[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEndLengthSamples(size_t aels_start,size_t aels_end)
	{
		fprintf(mFile,"\tsetAttr \".aels[%i:%i]\"",aels_start,aels_end);

	}
	void appendEndLengthSamples(double aels)
	{
		fprintf(mFile," %f",aels);

	}
	void endEndLengthSamples()
	{
		fprintf(mFile,";\n");

	}
	void setEndLengthMap(const string& aelm)
	{
		if(aelm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".aelm\" -type \"string\" ");
		aelm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEndLengthMapOffset(double aelmo)
	{
		if(aelmo == 0) return;
		fprintf(mFile,"\tsetAttr \".aelmo\" %f;\n", aelmo);

	}
	void setEndLengthMapMult(double aelmm)
	{
		if(aelmm == 1) return;
		fprintf(mFile,"\tsetAttr \".aelmm\" %f;\n", aelmm);

	}
	void setEndLengthNoise(double aeln)
	{
		if(aeln == 0) return;
		fprintf(mFile,"\tsetAttr \".aeln\" %f;\n", aeln);

	}
	void setEndLengthNoiseFreq(float aelnf)
	{
		if(aelnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".aelnf\" %f;\n", aelnf);

	}
	void setEndLengthSamplesDirty(int aelsd)
	{
		if(aelsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".aelsd\" %i;\n", aelsd);

	}
	void setEndLengthMapDirty(int aelmd)
	{
		if(aelmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".aelmd\" %i;\n", aelmd);

	}
	void setThresholdLength(double datl)
	{
		if(datl == 0) return;
		fprintf(mFile,"\tsetAttr \".datl\" %f;\n", datl);

	}
	void setThresholdLengthSamples(size_t atls_i,double atls)
	{
		if(atls == 0.0) return;
		fprintf(mFile,"\tsetAttr \".atls[%i]\" %f;\n", atls_i,atls);

	}
	void setThresholdLengthSamples(size_t atls_start,size_t atls_end,double* atls)
	{
		fprintf(mFile,"\tsetAttr \".atls[%i:%i]\" ", atls_start,atls_end);
		size_t size = (atls_end-atls_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",atls[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startThresholdLengthSamples(size_t atls_start,size_t atls_end)
	{
		fprintf(mFile,"\tsetAttr \".atls[%i:%i]\"",atls_start,atls_end);

	}
	void appendThresholdLengthSamples(double atls)
	{
		fprintf(mFile," %f",atls);

	}
	void endThresholdLengthSamples()
	{
		fprintf(mFile,";\n");

	}
	void setThresholdLengthMap(const string& atlm)
	{
		if(atlm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".atlm\" -type \"string\" ");
		atlm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setThresholdLengthMapOffset(double atlmo)
	{
		if(atlmo == 0) return;
		fprintf(mFile,"\tsetAttr \".atlmo\" %f;\n", atlmo);

	}
	void setThresholdLengthMapMult(double atlmm)
	{
		if(atlmm == 1) return;
		fprintf(mFile,"\tsetAttr \".atlmm\" %f;\n", atlmm);

	}
	void setThresholdLengthNoise(double atln)
	{
		if(atln == 0) return;
		fprintf(mFile,"\tsetAttr \".atln\" %f;\n", atln);

	}
	void setThresholdLengthNoiseFreq(float atlnf)
	{
		if(atlnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".atlnf\" %f;\n", atlnf);

	}
	void setThresholdLengthSamplesDirty(int atlsd)
	{
		if(atlsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".atlsd\" %i;\n", atlsd);

	}
	void setThresholdLengthMapDirty(int atlmd)
	{
		if(atlmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".atlmd\" %i;\n", atlmd);

	}
	void setUnused(float dun)
	{
		if(dun == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dun\" %f;\n", dun);

	}
	void setUnusedSamples(size_t uns_i,double uns)
	{
		if(uns == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uns[%i]\" %f;\n", uns_i,uns);

	}
	void setUnusedSamples(size_t uns_start,size_t uns_end,double* uns)
	{
		fprintf(mFile,"\tsetAttr \".uns[%i:%i]\" ", uns_start,uns_end);
		size_t size = (uns_end-uns_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uns[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startUnusedSamples(size_t uns_start,size_t uns_end)
	{
		fprintf(mFile,"\tsetAttr \".uns[%i:%i]\"",uns_start,uns_end);

	}
	void appendUnusedSamples(double uns)
	{
		fprintf(mFile," %f",uns);

	}
	void endUnusedSamples()
	{
		fprintf(mFile,";\n");

	}
	void setUnusedMap(const string& unm)
	{
		if(unm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".unm\" -type \"string\" ");
		unm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUnusedMapOffset(float unmo)
	{
		if(unmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".unmo\" %f;\n", unmo);

	}
	void setUnusedMapMult(float unmm)
	{
		if(unmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".unmm\" %f;\n", unmm);

	}
	void setUnusedNoise(float unn)
	{
		if(unn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".unn\" %f;\n", unn);

	}
	void setUnusedNoiseFreq(float unnf)
	{
		if(unnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".unnf\" %f;\n", unnf);

	}
	void setUnusedSamplesDirty(int unsd)
	{
		if(unsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".unsd\" %i;\n", unsd);

	}
	void setUnusedMapDirty(int unmd)
	{
		if(unmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".unmd\" %i;\n", unmd);

	}
	void setEqualizer(float dem)
	{
		if(dem == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dem\" %f;\n", dem);

	}
	void setEqualizerSamples(size_t ems_i,double ems)
	{
		if(ems == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ems[%i]\" %f;\n", ems_i,ems);

	}
	void setEqualizerSamples(size_t ems_start,size_t ems_end,double* ems)
	{
		fprintf(mFile,"\tsetAttr \".ems[%i:%i]\" ", ems_start,ems_end);
		size_t size = (ems_end-ems_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ems[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEqualizerSamples(size_t ems_start,size_t ems_end)
	{
		fprintf(mFile,"\tsetAttr \".ems[%i:%i]\"",ems_start,ems_end);

	}
	void appendEqualizerSamples(double ems)
	{
		fprintf(mFile," %f",ems);

	}
	void endEqualizerSamples()
	{
		fprintf(mFile,";\n");

	}
	void setEqualizerMap(const string& emm)
	{
		if(emm == "n/a") return;
		fprintf(mFile,"\tsetAttr \".emm\" -type \"string\" ");
		emm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEqualizerMapOffset(float emmo)
	{
		if(emmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".emmo\" %f;\n", emmo);

	}
	void setEqualizerMapMult(float emmm)
	{
		if(emmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".emmm\" %f;\n", emmm);

	}
	void setEqualizerNoise(float emn)
	{
		if(emn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".emn\" %f;\n", emn);

	}
	void setEqualizerNoiseFreq(float emnf)
	{
		if(emnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".emnf\" %f;\n", emnf);

	}
	void setEqualizerSamplesDirty(int emsd)
	{
		if(emsd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".emsd\" %i;\n", emsd);

	}
	void setEqualizerMapDirty(int emmd)
	{
		if(emmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".emmd\" %i;\n", emmd);

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
		if(mins == -2) return;
		fprintf(mFile,"\tsetAttr \".mrc.mins\" %i;\n", mins);

	}
	void setMiMaxSamples(short maxs)
	{
		if(maxs == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.maxs\" %i;\n", maxs);

	}
	void setMiFinalGatherCast(bool fgc)
	{
		if(fgc == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.fgc\" %i;\n", fgc);

	}
	void setMiFinalGatherReceive(bool fge)
	{
		if(fge == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.fge\" %i;\n", fge);

	}
	void setMiTransparencyCast(bool tpc)
	{
		if(tpc == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.tpc\" %i;\n", tpc);

	}
	void setMiTransparencyReceive(bool tpr)
	{
		if(tpr == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.tpr\" %i;\n", tpr);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getInputMesh()
	{
		fprintf(mFile,"\"%s.imsh\"",mName.c_str());

	}
	void getRealUSamples()
	{
		fprintf(mFile,"\"%s.rus\"",mName.c_str());

	}
	void getRealVSamples()
	{
		fprintf(mFile,"\"%s.rvs\"",mName.c_str());

	}
	void getUSamples()
	{
		fprintf(mFile,"\"%s.us\"",mName.c_str());

	}
	void getVSamples()
	{
		fprintf(mFile,"\"%s.vs\"",mName.c_str());

	}
	void getFlipNormals()
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());

	}
	void getHairs()
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());

	}
	void getFurAccuracy()
	{
		fprintf(mFile,"\"%s.ha\"",mName.c_str());

	}
	void getFurGlobalScale()
	{
		fprintf(mFile,"\"%s.fgs\"",mName.c_str());

	}
	void getAttractorGlobalScale()
	{
		fprintf(mFile,"\"%s.ags\"",mName.c_str());

	}
	void getExportAttr()
	{
		fprintf(mFile,"\"%s.ea\"",mName.c_str());

	}
	void getExportFile()
	{
		fprintf(mFile,"\"%s.ef\"",mName.c_str());

	}
	void getExportWidth()
	{
		fprintf(mFile,"\"%s.ew\"",mName.c_str());

	}
	void getExportHeight()
	{
		fprintf(mFile,"\"%s.eh\"",mName.c_str());

	}
	void getColorFeedbackEnabled()
	{
		fprintf(mFile,"\"%s.cfe\"",mName.c_str());

	}
	void getAttractors()
	{
		fprintf(mFile,"\"%s.atr\"",mName.c_str());

	}
	void getAttractorModel()
	{
		fprintf(mFile,"\"%s.amd\"",mName.c_str());

	}
	void getAttractorsPerHair()
	{
		fprintf(mFile,"\"%s.aph\"",mName.c_str());

	}
	void getDrawAttractors()
	{
		fprintf(mFile,"\"%s.drat\"",mName.c_str());

	}
	void getLength()
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());

	}
	void getLengthSamples(size_t ls_i)
	{
		fprintf(mFile,"\"%s.ls[%i]\"",mName.c_str(),ls_i);

	}
	void getLengthMap()
	{
		fprintf(mFile,"\"%s.lm\"",mName.c_str());

	}
	void getLengthMapOffset()
	{
		fprintf(mFile,"\"%s.lmo\"",mName.c_str());

	}
	void getLengthMapMult()
	{
		fprintf(mFile,"\"%s.lmm\"",mName.c_str());

	}
	void getLengthNoise()
	{
		fprintf(mFile,"\"%s.ln\"",mName.c_str());

	}
	void getLengthNoiseFreq()
	{
		fprintf(mFile,"\"%s.lnf\"",mName.c_str());

	}
	void getLengthSamplesDirty()
	{
		fprintf(mFile,"\"%s.lsd\"",mName.c_str());

	}
	void getLengthMapDirty()
	{
		fprintf(mFile,"\"%s.lmd\"",mName.c_str());

	}
	void getInclination()
	{
		fprintf(mFile,"\"%s.din\"",mName.c_str());

	}
	void getInclinationSamples(size_t ins_i)
	{
		fprintf(mFile,"\"%s.ins[%i]\"",mName.c_str(),ins_i);

	}
	void getInclinationMap()
	{
		fprintf(mFile,"\"%s.inm\"",mName.c_str());

	}
	void getInclinationMapOffset()
	{
		fprintf(mFile,"\"%s.inmo\"",mName.c_str());

	}
	void getInclinationMapMult()
	{
		fprintf(mFile,"\"%s.inmm\"",mName.c_str());

	}
	void getInclinationNoise()
	{
		fprintf(mFile,"\"%s.inn\"",mName.c_str());

	}
	void getInclinationNoiseFreq()
	{
		fprintf(mFile,"\"%s.innf\"",mName.c_str());

	}
	void getInclinationSamplesDirty()
	{
		fprintf(mFile,"\"%s.insd\"",mName.c_str());

	}
	void getInclinationMapDirty()
	{
		fprintf(mFile,"\"%s.inmd\"",mName.c_str());

	}
	void getRoll()
	{
		fprintf(mFile,"\"%s.drl\"",mName.c_str());

	}
	void getRollSamples(size_t rls_i)
	{
		fprintf(mFile,"\"%s.rls[%i]\"",mName.c_str(),rls_i);

	}
	void getRollMap()
	{
		fprintf(mFile,"\"%s.rlm\"",mName.c_str());

	}
	void getRollMapOffset()
	{
		fprintf(mFile,"\"%s.rlmo\"",mName.c_str());

	}
	void getRollMapMult()
	{
		fprintf(mFile,"\"%s.rlmm\"",mName.c_str());

	}
	void getRollNoise()
	{
		fprintf(mFile,"\"%s.rln\"",mName.c_str());

	}
	void getRollNoiseFreq()
	{
		fprintf(mFile,"\"%s.rlnf\"",mName.c_str());

	}
	void getRollSamplesDirty()
	{
		fprintf(mFile,"\"%s.rlsd\"",mName.c_str());

	}
	void getRollMapDirty()
	{
		fprintf(mFile,"\"%s.rlmd\"",mName.c_str());

	}
	void getPolar()
	{
		fprintf(mFile,"\"%s.dpo\"",mName.c_str());

	}
	void getPolarSamples(size_t pos_i)
	{
		fprintf(mFile,"\"%s.pos[%i]\"",mName.c_str(),pos_i);

	}
	void getPolarMap()
	{
		fprintf(mFile,"\"%s.pom\"",mName.c_str());

	}
	void getPolarMapOffset()
	{
		fprintf(mFile,"\"%s.pomo\"",mName.c_str());

	}
	void getPolarMapMult()
	{
		fprintf(mFile,"\"%s.pomm\"",mName.c_str());

	}
	void getPolarNoise()
	{
		fprintf(mFile,"\"%s.pon\"",mName.c_str());

	}
	void getPolarNoiseFreq()
	{
		fprintf(mFile,"\"%s.ponf\"",mName.c_str());

	}
	void getPolarSamplesDirty()
	{
		fprintf(mFile,"\"%s.posd\"",mName.c_str());

	}
	void getPolarMapDirty()
	{
		fprintf(mFile,"\"%s.pomd\"",mName.c_str());

	}
	void getBaldness()
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());

	}
	void getBaldnessSamples(size_t bs_i)
	{
		fprintf(mFile,"\"%s.bs[%i]\"",mName.c_str(),bs_i);

	}
	void getBaldnessMap()
	{
		fprintf(mFile,"\"%s.bm\"",mName.c_str());

	}
	void getBaldnessMapOffset()
	{
		fprintf(mFile,"\"%s.bmo\"",mName.c_str());

	}
	void getBaldnessMapMult()
	{
		fprintf(mFile,"\"%s.bmm\"",mName.c_str());

	}
	void getBaldnessNoise()
	{
		fprintf(mFile,"\"%s.bn\"",mName.c_str());

	}
	void getBaldnessNoiseFreq()
	{
		fprintf(mFile,"\"%s.bnf\"",mName.c_str());

	}
	void getBaldnessSamplesDirty()
	{
		fprintf(mFile,"\"%s.bsd\"",mName.c_str());

	}
	void getBaldnessMapDirty()
	{
		fprintf(mFile,"\"%s.bmd\"",mName.c_str());

	}
	void getBaseOpacity()
	{
		fprintf(mFile,"\"%s.dbo\"",mName.c_str());

	}
	void getBaseOpacitySamples(size_t bos_i)
	{
		fprintf(mFile,"\"%s.bos[%i]\"",mName.c_str(),bos_i);

	}
	void getBaseOpacityMap()
	{
		fprintf(mFile,"\"%s.bom\"",mName.c_str());

	}
	void getBaseOpacityMapOffset()
	{
		fprintf(mFile,"\"%s.bomo\"",mName.c_str());

	}
	void getBaseOpacityMapMult()
	{
		fprintf(mFile,"\"%s.bomm\"",mName.c_str());

	}
	void getBaseOpacityNoise()
	{
		fprintf(mFile,"\"%s.bon\"",mName.c_str());

	}
	void getBaseOpacityNoiseFreq()
	{
		fprintf(mFile,"\"%s.bonf\"",mName.c_str());

	}
	void getBaseOpacitySamplesDirty()
	{
		fprintf(mFile,"\"%s.bosd\"",mName.c_str());

	}
	void getBaseOpacityMapDirty()
	{
		fprintf(mFile,"\"%s.bomd\"",mName.c_str());

	}
	void getTipOpacity()
	{
		fprintf(mFile,"\"%s.dto\"",mName.c_str());

	}
	void getTipOpacitySamples(size_t tos_i)
	{
		fprintf(mFile,"\"%s.tos[%i]\"",mName.c_str(),tos_i);

	}
	void getTipOpacityMap()
	{
		fprintf(mFile,"\"%s.tom\"",mName.c_str());

	}
	void getTipOpacityMapOffset()
	{
		fprintf(mFile,"\"%s.tomo\"",mName.c_str());

	}
	void getTipOpacityMapMult()
	{
		fprintf(mFile,"\"%s.tomm\"",mName.c_str());

	}
	void getTipOpacityNoise()
	{
		fprintf(mFile,"\"%s.ton\"",mName.c_str());

	}
	void getTipOpacityNoiseFreq()
	{
		fprintf(mFile,"\"%s.tonf\"",mName.c_str());

	}
	void getTipOpacitySamplesDirty()
	{
		fprintf(mFile,"\"%s.tosd\"",mName.c_str());

	}
	void getTipOpacityMapDirty()
	{
		fprintf(mFile,"\"%s.tomd\"",mName.c_str());

	}
	void getBaseCurl()
	{
		fprintf(mFile,"\"%s.dbcl\"",mName.c_str());

	}
	void getBaseCurlSamples(size_t bcls_i)
	{
		fprintf(mFile,"\"%s.bcls[%i]\"",mName.c_str(),bcls_i);

	}
	void getBaseCurlMap()
	{
		fprintf(mFile,"\"%s.bclm\"",mName.c_str());

	}
	void getBaseCurlMapOffset()
	{
		fprintf(mFile,"\"%s.bclmo\"",mName.c_str());

	}
	void getBaseCurlMapMult()
	{
		fprintf(mFile,"\"%s.bclmm\"",mName.c_str());

	}
	void getBaseCurlNoise()
	{
		fprintf(mFile,"\"%s.bcln\"",mName.c_str());

	}
	void getBaseCurlNoiseFreq()
	{
		fprintf(mFile,"\"%s.bclnf\"",mName.c_str());

	}
	void getBaseCurlSamplesDirty()
	{
		fprintf(mFile,"\"%s.bclsd\"",mName.c_str());

	}
	void getBaseCurlMapDirty()
	{
		fprintf(mFile,"\"%s.bclmd\"",mName.c_str());

	}
	void getTipCurl()
	{
		fprintf(mFile,"\"%s.dtcl\"",mName.c_str());

	}
	void getTipCurlSamples(size_t tcls_i)
	{
		fprintf(mFile,"\"%s.tcls[%i]\"",mName.c_str(),tcls_i);

	}
	void getTipCurlMap()
	{
		fprintf(mFile,"\"%s.tclm\"",mName.c_str());

	}
	void getTipCurlMapOffset()
	{
		fprintf(mFile,"\"%s.tclmo\"",mName.c_str());

	}
	void getTipCurlMapMult()
	{
		fprintf(mFile,"\"%s.tclmm\"",mName.c_str());

	}
	void getTipCurlNoise()
	{
		fprintf(mFile,"\"%s.tcln\"",mName.c_str());

	}
	void getTipCurlNoiseFreq()
	{
		fprintf(mFile,"\"%s.tclnf\"",mName.c_str());

	}
	void getTipCurlSamplesDirty()
	{
		fprintf(mFile,"\"%s.tclsd\"",mName.c_str());

	}
	void getTipCurlMapDirty()
	{
		fprintf(mFile,"\"%s.tclmd\"",mName.c_str());

	}
	void getBaseWidth()
	{
		fprintf(mFile,"\"%s.dbw\"",mName.c_str());

	}
	void getBaseWidthSamples(size_t bws_i)
	{
		fprintf(mFile,"\"%s.bws[%i]\"",mName.c_str(),bws_i);

	}
	void getBaseWidthMap()
	{
		fprintf(mFile,"\"%s.bwm\"",mName.c_str());

	}
	void getBaseWidthMapOffset()
	{
		fprintf(mFile,"\"%s.bwmo\"",mName.c_str());

	}
	void getBaseWidthMapMult()
	{
		fprintf(mFile,"\"%s.bwmm\"",mName.c_str());

	}
	void getBaseWidthNoise()
	{
		fprintf(mFile,"\"%s.bwn\"",mName.c_str());

	}
	void getBaseWidthNoiseFreq()
	{
		fprintf(mFile,"\"%s.bwnf\"",mName.c_str());

	}
	void getBaseWidthSamplesDirty()
	{
		fprintf(mFile,"\"%s.bwsd\"",mName.c_str());

	}
	void getBaseWidthMapDirty()
	{
		fprintf(mFile,"\"%s.bwmd\"",mName.c_str());

	}
	void getTipWidth()
	{
		fprintf(mFile,"\"%s.dtw\"",mName.c_str());

	}
	void getTipWidthSamples(size_t tws_i)
	{
		fprintf(mFile,"\"%s.tws[%i]\"",mName.c_str(),tws_i);

	}
	void getTipWidthMap()
	{
		fprintf(mFile,"\"%s.twm\"",mName.c_str());

	}
	void getTipWidthMapOffset()
	{
		fprintf(mFile,"\"%s.twmo\"",mName.c_str());

	}
	void getTipWidthMapMult()
	{
		fprintf(mFile,"\"%s.twmm\"",mName.c_str());

	}
	void getTipWidthNoise()
	{
		fprintf(mFile,"\"%s.twn\"",mName.c_str());

	}
	void getTipWidthNoiseFreq()
	{
		fprintf(mFile,"\"%s.twnf\"",mName.c_str());

	}
	void getTipWidthSamplesDirty()
	{
		fprintf(mFile,"\"%s.twsd\"",mName.c_str());

	}
	void getTipWidthMapDirty()
	{
		fprintf(mFile,"\"%s.twmd\"",mName.c_str());

	}
	void getScraggle()
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());

	}
	void getScraggleSamples(size_t ss_i)
	{
		fprintf(mFile,"\"%s.ss[%i]\"",mName.c_str(),ss_i);

	}
	void getScraggleMap()
	{
		fprintf(mFile,"\"%s.sm\"",mName.c_str());

	}
	void getScraggleMapOffset()
	{
		fprintf(mFile,"\"%s.smo\"",mName.c_str());

	}
	void getScraggleMapMult()
	{
		fprintf(mFile,"\"%s.smm\"",mName.c_str());

	}
	void getScraggleNoise()
	{
		fprintf(mFile,"\"%s.sn\"",mName.c_str());

	}
	void getScraggleNoiseFreq()
	{
		fprintf(mFile,"\"%s.snf\"",mName.c_str());

	}
	void getScraggleSamplesDirty()
	{
		fprintf(mFile,"\"%s.ssd\"",mName.c_str());

	}
	void getScraggleMapDirty()
	{
		fprintf(mFile,"\"%s.smd\"",mName.c_str());

	}
	void getScraggleCorrelation()
	{
		fprintf(mFile,"\"%s.dsco\"",mName.c_str());

	}
	void getScraggleCorrelationSamples(size_t scos_i)
	{
		fprintf(mFile,"\"%s.scos[%i]\"",mName.c_str(),scos_i);

	}
	void getScraggleCorrelationMap()
	{
		fprintf(mFile,"\"%s.scom\"",mName.c_str());

	}
	void getScraggleCorrelationMapOffset()
	{
		fprintf(mFile,"\"%s.scomo\"",mName.c_str());

	}
	void getScraggleCorrelationMapMult()
	{
		fprintf(mFile,"\"%s.scomm\"",mName.c_str());

	}
	void getScraggleCorrelationNoise()
	{
		fprintf(mFile,"\"%s.scon\"",mName.c_str());

	}
	void getScraggleCorrelationNoiseFreq()
	{
		fprintf(mFile,"\"%s.sconf\"",mName.c_str());

	}
	void getScraggleCorrelationSamplesDirty()
	{
		fprintf(mFile,"\"%s.scosd\"",mName.c_str());

	}
	void getScraggleCorrelationMapDirty()
	{
		fprintf(mFile,"\"%s.scomd\"",mName.c_str());

	}
	void getScraggleFrequency()
	{
		fprintf(mFile,"\"%s.dscf\"",mName.c_str());

	}
	void getScraggleFrequencySamples(size_t scfs_i)
	{
		fprintf(mFile,"\"%s.scfs[%i]\"",mName.c_str(),scfs_i);

	}
	void getScraggleFrequencyMap()
	{
		fprintf(mFile,"\"%s.scfm\"",mName.c_str());

	}
	void getScraggleFrequencyMapOffset()
	{
		fprintf(mFile,"\"%s.scfmo\"",mName.c_str());

	}
	void getScraggleFrequencyMapMult()
	{
		fprintf(mFile,"\"%s.scfmm\"",mName.c_str());

	}
	void getScraggleFrequencyNoise()
	{
		fprintf(mFile,"\"%s.scfn\"",mName.c_str());

	}
	void getScraggleFrequencyNoiseFreq()
	{
		fprintf(mFile,"\"%s.scfnf\"",mName.c_str());

	}
	void getScraggleFrequencySamplesDirty()
	{
		fprintf(mFile,"\"%s.scfsd\"",mName.c_str());

	}
	void getScraggleFrequencyMapDirty()
	{
		fprintf(mFile,"\"%s.scfmd\"",mName.c_str());

	}
	void getSegments()
	{
		fprintf(mFile,"\"%s.dseg\"",mName.c_str());

	}
	void getSegmentsSamples(size_t segs_i)
	{
		fprintf(mFile,"\"%s.segs[%i]\"",mName.c_str(),segs_i);

	}
	void getSegmentsMap()
	{
		fprintf(mFile,"\"%s.segm\"",mName.c_str());

	}
	void getSegmentsMapOffset()
	{
		fprintf(mFile,"\"%s.segmo\"",mName.c_str());

	}
	void getSegmentsMapMult()
	{
		fprintf(mFile,"\"%s.segmm\"",mName.c_str());

	}
	void getSegmentsNoise()
	{
		fprintf(mFile,"\"%s.segn\"",mName.c_str());

	}
	void getSegmentsNoiseFreq()
	{
		fprintf(mFile,"\"%s.segnf\"",mName.c_str());

	}
	void getSegmentsSamplesDirty()
	{
		fprintf(mFile,"\"%s.segsd\"",mName.c_str());

	}
	void getSegmentsMapDirty()
	{
		fprintf(mFile,"\"%s.segmd\"",mName.c_str());

	}
	void getAttraction()
	{
		fprintf(mFile,"\"%s.dat\"",mName.c_str());

	}
	void getAttractionSamples(size_t ats_i)
	{
		fprintf(mFile,"\"%s.ats[%i]\"",mName.c_str(),ats_i);

	}
	void getAttractionMap()
	{
		fprintf(mFile,"\"%s.atm\"",mName.c_str());

	}
	void getAttractionMapOffset()
	{
		fprintf(mFile,"\"%s.atmo\"",mName.c_str());

	}
	void getAttractionMapMult()
	{
		fprintf(mFile,"\"%s.atmm\"",mName.c_str());

	}
	void getAttractionNoise()
	{
		fprintf(mFile,"\"%s.atn\"",mName.c_str());

	}
	void getAttractionNoiseFreq()
	{
		fprintf(mFile,"\"%s.atnf\"",mName.c_str());

	}
	void getAttractionSamplesDirty()
	{
		fprintf(mFile,"\"%s.atsd\"",mName.c_str());

	}
	void getAttractionMapDirty()
	{
		fprintf(mFile,"\"%s.atmd\"",mName.c_str());

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.dofs\"",mName.c_str());

	}
	void getOffsetSamples(size_t ofss_i)
	{
		fprintf(mFile,"\"%s.ofss[%i]\"",mName.c_str(),ofss_i);

	}
	void getOffsetMap()
	{
		fprintf(mFile,"\"%s.ofsm\"",mName.c_str());

	}
	void getOffsetMapOffset()
	{
		fprintf(mFile,"\"%s.ofsmo\"",mName.c_str());

	}
	void getOffsetMapMult()
	{
		fprintf(mFile,"\"%s.ofsmm\"",mName.c_str());

	}
	void getOffsetNoise()
	{
		fprintf(mFile,"\"%s.ofsn\"",mName.c_str());

	}
	void getOffsetNoiseFreq()
	{
		fprintf(mFile,"\"%s.ofsnf\"",mName.c_str());

	}
	void getOffsetSamplesDirty()
	{
		fprintf(mFile,"\"%s.ofssd\"",mName.c_str());

	}
	void getOffsetMapDirty()
	{
		fprintf(mFile,"\"%s.ofsmd\"",mName.c_str());

	}
	void getClumping()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getClumpingSamples(size_t cs_i)
	{
		fprintf(mFile,"\"%s.cs[%i]\"",mName.c_str(),cs_i);

	}
	void getClumpingMap()
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());

	}
	void getClumpingMapOffset()
	{
		fprintf(mFile,"\"%s.cmo\"",mName.c_str());

	}
	void getClumpingMapMult()
	{
		fprintf(mFile,"\"%s.cmm\"",mName.c_str());

	}
	void getClumpingNoise()
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());

	}
	void getClumpingNoiseFreq()
	{
		fprintf(mFile,"\"%s.cnf\"",mName.c_str());

	}
	void getClumpingSamplesDirty()
	{
		fprintf(mFile,"\"%s.csd\"",mName.c_str());

	}
	void getClumpingMapDirty()
	{
		fprintf(mFile,"\"%s.cmd\"",mName.c_str());

	}
	void getClumpingFrequency()
	{
		fprintf(mFile,"\"%s.dcf\"",mName.c_str());

	}
	void getClumpingFrequencySamples(size_t cfs_i)
	{
		fprintf(mFile,"\"%s.cfs[%i]\"",mName.c_str(),cfs_i);

	}
	void getClumpingFrequencyMap()
	{
		fprintf(mFile,"\"%s.cfm\"",mName.c_str());

	}
	void getClumpingFrequencyMapOffset()
	{
		fprintf(mFile,"\"%s.cfmo\"",mName.c_str());

	}
	void getClumpingFrequencyMapMult()
	{
		fprintf(mFile,"\"%s.cfmm\"",mName.c_str());

	}
	void getClumpingFrequencyNoise()
	{
		fprintf(mFile,"\"%s.cfn\"",mName.c_str());

	}
	void getClumpingFrequencyNoiseFreq()
	{
		fprintf(mFile,"\"%s.cfnf\"",mName.c_str());

	}
	void getClumpingFrequencySamplesDirty()
	{
		fprintf(mFile,"\"%s.cfsd\"",mName.c_str());

	}
	void getClumpingFrequencyMapDirty()
	{
		fprintf(mFile,"\"%s.cfmd\"",mName.c_str());

	}
	void getClumpingShape()
	{
		fprintf(mFile,"\"%s.dcs\"",mName.c_str());

	}
	void getClumpingShapeSamples(size_t css_i)
	{
		fprintf(mFile,"\"%s.css[%i]\"",mName.c_str(),css_i);

	}
	void getClumpingShapeMap()
	{
		fprintf(mFile,"\"%s.csm\"",mName.c_str());

	}
	void getClumpingShapeMapOffset()
	{
		fprintf(mFile,"\"%s.csmo\"",mName.c_str());

	}
	void getClumpingShapeMapMult()
	{
		fprintf(mFile,"\"%s.csmm\"",mName.c_str());

	}
	void getClumpingShapeNoise()
	{
		fprintf(mFile,"\"%s.csn\"",mName.c_str());

	}
	void getClumpingShapeNoiseFreq()
	{
		fprintf(mFile,"\"%s.csnf\"",mName.c_str());

	}
	void getClumpingShapeSamplesDirty()
	{
		fprintf(mFile,"\"%s.cssd\"",mName.c_str());

	}
	void getClumpingShapeMapDirty()
	{
		fprintf(mFile,"\"%s.csmd\"",mName.c_str());

	}
	void getBaseColor()
	{
		fprintf(mFile,"\"%s.dbc\"",mName.c_str());

	}
	void getBaseColorR()
	{
		fprintf(mFile,"\"%s.dbcr\"",mName.c_str());

	}
	void getBaseColorG()
	{
		fprintf(mFile,"\"%s.dbcg\"",mName.c_str());

	}
	void getBaseColorB()
	{
		fprintf(mFile,"\"%s.dbcb\"",mName.c_str());

	}
	void getBaseColorSamples(size_t bcs_i)
	{
		fprintf(mFile,"\"%s.bcs[%i]\"",mName.c_str(),bcs_i);

	}
	void getBaseColorMap()
	{
		fprintf(mFile,"\"%s.bcm\"",mName.c_str());

	}
	void getBaseColorNoise()
	{
		fprintf(mFile,"\"%s.bcn\"",mName.c_str());

	}
	void getBaseColorNoiseFreq()
	{
		fprintf(mFile,"\"%s.bcnf\"",mName.c_str());

	}
	void getBaseColorSamplesDirty()
	{
		fprintf(mFile,"\"%s.bcsd\"",mName.c_str());

	}
	void getBaseColorMapDirty()
	{
		fprintf(mFile,"\"%s.bcmd\"",mName.c_str());

	}
	void getTipColor()
	{
		fprintf(mFile,"\"%s.dtc\"",mName.c_str());

	}
	void getTipColorR()
	{
		fprintf(mFile,"\"%s.dtcr\"",mName.c_str());

	}
	void getTipColorG()
	{
		fprintf(mFile,"\"%s.dtcg\"",mName.c_str());

	}
	void getTipColorB()
	{
		fprintf(mFile,"\"%s.dtcb\"",mName.c_str());

	}
	void getTipColorSamples(size_t tcs_i)
	{
		fprintf(mFile,"\"%s.tcs[%i]\"",mName.c_str(),tcs_i);

	}
	void getTipColorMap()
	{
		fprintf(mFile,"\"%s.tcm\"",mName.c_str());

	}
	void getTipColorNoise()
	{
		fprintf(mFile,"\"%s.tcn\"",mName.c_str());

	}
	void getTipColorNoiseFreq()
	{
		fprintf(mFile,"\"%s.tcnf\"",mName.c_str());

	}
	void getTipColorSamplesDirty()
	{
		fprintf(mFile,"\"%s.tcsd\"",mName.c_str());

	}
	void getTipColorMapDirty()
	{
		fprintf(mFile,"\"%s.tcmd\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.dar\"",mName.c_str());

	}
	void getRadiusSamples(size_t ars_i)
	{
		fprintf(mFile,"\"%s.ars[%i]\"",mName.c_str(),ars_i);

	}
	void getRadiusMap()
	{
		fprintf(mFile,"\"%s.arm\"",mName.c_str());

	}
	void getRadiusMapOffset()
	{
		fprintf(mFile,"\"%s.armo\"",mName.c_str());

	}
	void getRadiusMapMult()
	{
		fprintf(mFile,"\"%s.armm\"",mName.c_str());

	}
	void getRadiusNoise()
	{
		fprintf(mFile,"\"%s.arn\"",mName.c_str());

	}
	void getRadiusNoiseFreq()
	{
		fprintf(mFile,"\"%s.arnf\"",mName.c_str());

	}
	void getRadiusSamplesDirty()
	{
		fprintf(mFile,"\"%s.arsd\"",mName.c_str());

	}
	void getRadiusMapDirty()
	{
		fprintf(mFile,"\"%s.armd\"",mName.c_str());

	}
	void getPower()
	{
		fprintf(mFile,"\"%s.dap\"",mName.c_str());

	}
	void getPowerSamples(size_t aps_i)
	{
		fprintf(mFile,"\"%s.aps[%i]\"",mName.c_str(),aps_i);

	}
	void getPowerMap()
	{
		fprintf(mFile,"\"%s.apm\"",mName.c_str());

	}
	void getPowerMapOffset()
	{
		fprintf(mFile,"\"%s.apmo\"",mName.c_str());

	}
	void getPowerMapMult()
	{
		fprintf(mFile,"\"%s.apmm\"",mName.c_str());

	}
	void getPowerNoise()
	{
		fprintf(mFile,"\"%s.apn\"",mName.c_str());

	}
	void getPowerNoiseFreq()
	{
		fprintf(mFile,"\"%s.apnf\"",mName.c_str());

	}
	void getPowerSamplesDirty()
	{
		fprintf(mFile,"\"%s.apsd\"",mName.c_str());

	}
	void getPowerMapDirty()
	{
		fprintf(mFile,"\"%s.apmd\"",mName.c_str());

	}
	void getInfluence()
	{
		fprintf(mFile,"\"%s.dai\"",mName.c_str());

	}
	void getInfluenceSamples(size_t ais_i)
	{
		fprintf(mFile,"\"%s.ais[%i]\"",mName.c_str(),ais_i);

	}
	void getInfluenceMap()
	{
		fprintf(mFile,"\"%s.aim\"",mName.c_str());

	}
	void getInfluenceMapOffset()
	{
		fprintf(mFile,"\"%s.aimo\"",mName.c_str());

	}
	void getInfluenceMapMult()
	{
		fprintf(mFile,"\"%s.aimm\"",mName.c_str());

	}
	void getInfluenceNoise()
	{
		fprintf(mFile,"\"%s.ain\"",mName.c_str());

	}
	void getInfluenceNoiseFreq()
	{
		fprintf(mFile,"\"%s.ainf\"",mName.c_str());

	}
	void getInfluenceSamplesDirty()
	{
		fprintf(mFile,"\"%s.aisd\"",mName.c_str());

	}
	void getInfluenceMapDirty()
	{
		fprintf(mFile,"\"%s.aimd\"",mName.c_str());

	}
	void getStartLength()
	{
		fprintf(mFile,"\"%s.dasl\"",mName.c_str());

	}
	void getStartLengthSamples(size_t asls_i)
	{
		fprintf(mFile,"\"%s.asls[%i]\"",mName.c_str(),asls_i);

	}
	void getStartLengthMap()
	{
		fprintf(mFile,"\"%s.aslm\"",mName.c_str());

	}
	void getStartLengthMapOffset()
	{
		fprintf(mFile,"\"%s.aslmo\"",mName.c_str());

	}
	void getStartLengthMapMult()
	{
		fprintf(mFile,"\"%s.aslmm\"",mName.c_str());

	}
	void getStartLengthNoise()
	{
		fprintf(mFile,"\"%s.asln\"",mName.c_str());

	}
	void getStartLengthNoiseFreq()
	{
		fprintf(mFile,"\"%s.aslnf\"",mName.c_str());

	}
	void getStartLengthSamplesDirty()
	{
		fprintf(mFile,"\"%s.aslsd\"",mName.c_str());

	}
	void getStartLengthMapDirty()
	{
		fprintf(mFile,"\"%s.aslmd\"",mName.c_str());

	}
	void getEndLength()
	{
		fprintf(mFile,"\"%s.dael\"",mName.c_str());

	}
	void getEndLengthSamples(size_t aels_i)
	{
		fprintf(mFile,"\"%s.aels[%i]\"",mName.c_str(),aels_i);

	}
	void getEndLengthMap()
	{
		fprintf(mFile,"\"%s.aelm\"",mName.c_str());

	}
	void getEndLengthMapOffset()
	{
		fprintf(mFile,"\"%s.aelmo\"",mName.c_str());

	}
	void getEndLengthMapMult()
	{
		fprintf(mFile,"\"%s.aelmm\"",mName.c_str());

	}
	void getEndLengthNoise()
	{
		fprintf(mFile,"\"%s.aeln\"",mName.c_str());

	}
	void getEndLengthNoiseFreq()
	{
		fprintf(mFile,"\"%s.aelnf\"",mName.c_str());

	}
	void getEndLengthSamplesDirty()
	{
		fprintf(mFile,"\"%s.aelsd\"",mName.c_str());

	}
	void getEndLengthMapDirty()
	{
		fprintf(mFile,"\"%s.aelmd\"",mName.c_str());

	}
	void getThresholdLength()
	{
		fprintf(mFile,"\"%s.datl\"",mName.c_str());

	}
	void getThresholdLengthSamples(size_t atls_i)
	{
		fprintf(mFile,"\"%s.atls[%i]\"",mName.c_str(),atls_i);

	}
	void getThresholdLengthMap()
	{
		fprintf(mFile,"\"%s.atlm\"",mName.c_str());

	}
	void getThresholdLengthMapOffset()
	{
		fprintf(mFile,"\"%s.atlmo\"",mName.c_str());

	}
	void getThresholdLengthMapMult()
	{
		fprintf(mFile,"\"%s.atlmm\"",mName.c_str());

	}
	void getThresholdLengthNoise()
	{
		fprintf(mFile,"\"%s.atln\"",mName.c_str());

	}
	void getThresholdLengthNoiseFreq()
	{
		fprintf(mFile,"\"%s.atlnf\"",mName.c_str());

	}
	void getThresholdLengthSamplesDirty()
	{
		fprintf(mFile,"\"%s.atlsd\"",mName.c_str());

	}
	void getThresholdLengthMapDirty()
	{
		fprintf(mFile,"\"%s.atlmd\"",mName.c_str());

	}
	void getUnused()
	{
		fprintf(mFile,"\"%s.dun\"",mName.c_str());

	}
	void getUnusedSamples(size_t uns_i)
	{
		fprintf(mFile,"\"%s.uns[%i]\"",mName.c_str(),uns_i);

	}
	void getUnusedMap()
	{
		fprintf(mFile,"\"%s.unm\"",mName.c_str());

	}
	void getUnusedMapOffset()
	{
		fprintf(mFile,"\"%s.unmo\"",mName.c_str());

	}
	void getUnusedMapMult()
	{
		fprintf(mFile,"\"%s.unmm\"",mName.c_str());

	}
	void getUnusedNoise()
	{
		fprintf(mFile,"\"%s.unn\"",mName.c_str());

	}
	void getUnusedSamplesDirty()
	{
		fprintf(mFile,"\"%s.unsd\"",mName.c_str());

	}
	void getUnusedMapDirty()
	{
		fprintf(mFile,"\"%s.unmd\"",mName.c_str());

	}
	void getEqualizer()
	{
		fprintf(mFile,"\"%s.dem\"",mName.c_str());

	}
	void getEqualizerSamples(size_t ems_i)
	{
		fprintf(mFile,"\"%s.ems[%i]\"",mName.c_str(),ems_i);

	}
	void getEqualizerMap()
	{
		fprintf(mFile,"\"%s.emm\"",mName.c_str());

	}
	void getEqualizerMapOffset()
	{
		fprintf(mFile,"\"%s.emmo\"",mName.c_str());

	}
	void getEqualizerMapMult()
	{
		fprintf(mFile,"\"%s.emmm\"",mName.c_str());

	}
	void getEqualizerNoise()
	{
		fprintf(mFile,"\"%s.emn\"",mName.c_str());

	}
	void getEqualizerNoiseFreq()
	{
		fprintf(mFile,"\"%s.emnf\"",mName.c_str());

	}
	void getEqualizerSamplesDirty()
	{
		fprintf(mFile,"\"%s.emsd\"",mName.c_str());

	}
	void getEqualizerMapDirty()
	{
		fprintf(mFile,"\"%s.emmd\"",mName.c_str());

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
	void getMiFinalGatherCast()
	{
		fprintf(mFile,"\"%s.mrc.fgc\"",mName.c_str());

	}
	void getMiFinalGatherReceive()
	{
		fprintf(mFile,"\"%s.mrc.fge\"",mName.c_str());

	}
	void getMiTransparencyCast()
	{
		fprintf(mFile,"\"%s.mrc.tpc\"",mName.c_str());

	}
	void getMiTransparencyReceive()
	{
		fprintf(mFile,"\"%s.mrc.tpr\"",mName.c_str());

	}
protected:
	FurFeedback(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Locator(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURFEEDBACK_H__
