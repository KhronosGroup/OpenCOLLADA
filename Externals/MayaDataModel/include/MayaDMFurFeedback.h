/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	FurFeedback(FILE* file,const std::string& name,const std::string& parent=""):Locator(file, name, parent, "FurFeedback"){}
	virtual ~FurFeedback(){}
	void setInputSurface(const nurbsSurface& is)
	{
		fprintf(mFile,"setAttr \".is\" -type \"nurbsSurface\" ");
		is.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputMesh(const mesh& imsh)
	{
		fprintf(mFile,"setAttr \".imsh\" -type \"mesh\" ");
		imsh.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRealUSamples(int rus)
	{
		if(rus == 32) return;
		fprintf(mFile,"setAttr \".rus\" %i;\n", rus);

	}
	void setRealVSamples(int rvs)
	{
		if(rvs == 32) return;
		fprintf(mFile,"setAttr \".rvs\" %i;\n", rvs);

	}
	void setUSamples(int us)
	{
		if(us == 32) return;
		fprintf(mFile,"setAttr \".us\" %i;\n", us);

	}
	void setVSamples(int vs)
	{
		if(vs == 32) return;
		fprintf(mFile,"setAttr \".vs\" %i;\n", vs);

	}
	void setFlipNormals(bool fn)
	{
		if(fn == false) return;
		fprintf(mFile,"setAttr \".fn\" %i;\n", fn);

	}
	void setHairs(const pointArray& h)
	{
		fprintf(mFile,"setAttr \".h\" -type \"pointArray\" ");
		h.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFurAccuracy(float ha)
	{
		if(ha == 0.0) return;
		fprintf(mFile,"setAttr \".ha\" %f;\n", ha);

	}
	void setFurGlobalScale(float fgs)
	{
		if(fgs == 1.0) return;
		fprintf(mFile,"setAttr \".fgs\" %f;\n", fgs);

	}
	void setAttractorGlobalScale(float ags)
	{
		if(ags == 1.0) return;
		fprintf(mFile,"setAttr \".ags\" %f;\n", ags);

	}
	void setExportAttr(const string& ea)
	{
		if(ea == "n/a") return;
		fprintf(mFile,"setAttr \".ea\" -type \"string\" ");
		ea.write(mFile);
		fprintf(mFile,";\n");

	}
	void setExportFile(const string& ef)
	{
		if(ef == "n/a") return;
		fprintf(mFile,"setAttr \".ef\" -type \"string\" ");
		ef.write(mFile);
		fprintf(mFile,";\n");

	}
	void setExportWidth(int ew)
	{
		if(ew == 256) return;
		fprintf(mFile,"setAttr \".ew\" %i;\n", ew);

	}
	void setExportHeight(int eh)
	{
		if(eh == 256) return;
		fprintf(mFile,"setAttr \".eh\" %i;\n", eh);

	}
	void setColorFeedbackEnabled(bool cfe)
	{
		if(cfe == false) return;
		fprintf(mFile,"setAttr \".cfe\" %i;\n", cfe);

	}
	void setAttractorModel(unsigned int amd)
	{
		if(amd == 0) return;
		fprintf(mFile,"setAttr \".amd\" %i;\n", amd);

	}
	void setAttractorsPerHair(int aph)
	{
		if(aph == 1) return;
		fprintf(mFile,"setAttr \".aph\" %i;\n", aph);

	}
	void setDrawAttractors(bool drat)
	{
		if(drat == false) return;
		fprintf(mFile,"setAttr \".drat\" %i;\n", drat);

	}
	void setLength(double dl)
	{
		if(dl == 1) return;
		fprintf(mFile,"setAttr \".dl\" %f;\n", dl);

	}
	void setLengthSamples(size_t ls_i,double ls)
	{
		if(ls == 0.0) return;
		fprintf(mFile,"setAttr \".ls[%i]\" %f;\n", ls_i,ls);

	}
	void setLengthMap(const string& lm)
	{
		if(lm == "n/a") return;
		fprintf(mFile,"setAttr \".lm\" -type \"string\" ");
		lm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLengthMapOffset(double lmo)
	{
		if(lmo == 0) return;
		fprintf(mFile,"setAttr \".lmo\" %f;\n", lmo);

	}
	void setLengthMapMult(double lmm)
	{
		if(lmm == 1) return;
		fprintf(mFile,"setAttr \".lmm\" %f;\n", lmm);

	}
	void setLengthNoise(double ln)
	{
		if(ln == 0) return;
		fprintf(mFile,"setAttr \".ln\" %f;\n", ln);

	}
	void setLengthNoiseFreq(float lnf)
	{
		if(lnf == 10.0) return;
		fprintf(mFile,"setAttr \".lnf\" %f;\n", lnf);

	}
	void setLengthSamplesDirty(int lsd)
	{
		if(lsd == 0.0) return;
		fprintf(mFile,"setAttr \".lsd\" %i;\n", lsd);

	}
	void setLengthMapDirty(int lmd)
	{
		if(lmd == 0.0) return;
		fprintf(mFile,"setAttr \".lmd\" %i;\n", lmd);

	}
	void setInclination(float din)
	{
		if(din == 0.0) return;
		fprintf(mFile,"setAttr \".din\" %f;\n", din);

	}
	void setInclinationSamples(size_t ins_i,double ins)
	{
		if(ins == 0.0) return;
		fprintf(mFile,"setAttr \".ins[%i]\" %f;\n", ins_i,ins);

	}
	void setInclinationMap(const string& inm)
	{
		if(inm == "n/a") return;
		fprintf(mFile,"setAttr \".inm\" -type \"string\" ");
		inm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInclinationMapOffset(float inmo)
	{
		if(inmo == 0.0) return;
		fprintf(mFile,"setAttr \".inmo\" %f;\n", inmo);

	}
	void setInclinationMapMult(float inmm)
	{
		if(inmm == 1.0) return;
		fprintf(mFile,"setAttr \".inmm\" %f;\n", inmm);

	}
	void setInclinationNoise(float inn)
	{
		if(inn == 0.0) return;
		fprintf(mFile,"setAttr \".inn\" %f;\n", inn);

	}
	void setInclinationNoiseFreq(float innf)
	{
		if(innf == 10.0) return;
		fprintf(mFile,"setAttr \".innf\" %f;\n", innf);

	}
	void setInclinationSamplesDirty(int insd)
	{
		if(insd == 0.0) return;
		fprintf(mFile,"setAttr \".insd\" %i;\n", insd);

	}
	void setInclinationMapDirty(int inmd)
	{
		if(inmd == 0.0) return;
		fprintf(mFile,"setAttr \".inmd\" %i;\n", inmd);

	}
	void setRoll(float drl)
	{
		if(drl == 0.5) return;
		fprintf(mFile,"setAttr \".drl\" %f;\n", drl);

	}
	void setRollSamples(size_t rls_i,double rls)
	{
		if(rls == 0.0) return;
		fprintf(mFile,"setAttr \".rls[%i]\" %f;\n", rls_i,rls);

	}
	void setRollMap(const string& rlm)
	{
		if(rlm == "n/a") return;
		fprintf(mFile,"setAttr \".rlm\" -type \"string\" ");
		rlm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRollMapOffset(float rlmo)
	{
		if(rlmo == 0.0) return;
		fprintf(mFile,"setAttr \".rlmo\" %f;\n", rlmo);

	}
	void setRollMapMult(float rlmm)
	{
		if(rlmm == 1.0) return;
		fprintf(mFile,"setAttr \".rlmm\" %f;\n", rlmm);

	}
	void setRollNoise(float rln)
	{
		if(rln == 0.0) return;
		fprintf(mFile,"setAttr \".rln\" %f;\n", rln);

	}
	void setRollNoiseFreq(float rlnf)
	{
		if(rlnf == 10.0) return;
		fprintf(mFile,"setAttr \".rlnf\" %f;\n", rlnf);

	}
	void setRollSamplesDirty(int rlsd)
	{
		if(rlsd == 0.0) return;
		fprintf(mFile,"setAttr \".rlsd\" %i;\n", rlsd);

	}
	void setRollMapDirty(int rlmd)
	{
		if(rlmd == 0.0) return;
		fprintf(mFile,"setAttr \".rlmd\" %i;\n", rlmd);

	}
	void setPolar(float dpo)
	{
		if(dpo == 0.5) return;
		fprintf(mFile,"setAttr \".dpo\" %f;\n", dpo);

	}
	void setPolarSamples(size_t pos_i,double pos)
	{
		if(pos == 0.0) return;
		fprintf(mFile,"setAttr \".pos[%i]\" %f;\n", pos_i,pos);

	}
	void setPolarMap(const string& pom)
	{
		if(pom == "n/a") return;
		fprintf(mFile,"setAttr \".pom\" -type \"string\" ");
		pom.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPolarMapOffset(float pomo)
	{
		if(pomo == 0.0) return;
		fprintf(mFile,"setAttr \".pomo\" %f;\n", pomo);

	}
	void setPolarMapMult(float pomm)
	{
		if(pomm == 1.0) return;
		fprintf(mFile,"setAttr \".pomm\" %f;\n", pomm);

	}
	void setPolarNoise(float pon)
	{
		if(pon == 0.0) return;
		fprintf(mFile,"setAttr \".pon\" %f;\n", pon);

	}
	void setPolarNoiseFreq(float ponf)
	{
		if(ponf == 10.0) return;
		fprintf(mFile,"setAttr \".ponf\" %f;\n", ponf);

	}
	void setPolarSamplesDirty(int posd)
	{
		if(posd == 0.0) return;
		fprintf(mFile,"setAttr \".posd\" %i;\n", posd);

	}
	void setPolarMapDirty(int pomd)
	{
		if(pomd == 0.0) return;
		fprintf(mFile,"setAttr \".pomd\" %i;\n", pomd);

	}
	void setBaldness(float db)
	{
		if(db == 1.0) return;
		fprintf(mFile,"setAttr \".db\" %f;\n", db);

	}
	void setBaldnessSamples(size_t bs_i,double bs)
	{
		if(bs == 0.0) return;
		fprintf(mFile,"setAttr \".bs[%i]\" %f;\n", bs_i,bs);

	}
	void setBaldnessMap(const string& bm)
	{
		if(bm == "n/a") return;
		fprintf(mFile,"setAttr \".bm\" -type \"string\" ");
		bm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaldnessMapOffset(float bmo)
	{
		if(bmo == 0.0) return;
		fprintf(mFile,"setAttr \".bmo\" %f;\n", bmo);

	}
	void setBaldnessMapMult(float bmm)
	{
		if(bmm == 1.0) return;
		fprintf(mFile,"setAttr \".bmm\" %f;\n", bmm);

	}
	void setBaldnessNoise(float bn)
	{
		if(bn == 0.0) return;
		fprintf(mFile,"setAttr \".bn\" %f;\n", bn);

	}
	void setBaldnessNoiseFreq(float bnf)
	{
		if(bnf == 10.0) return;
		fprintf(mFile,"setAttr \".bnf\" %f;\n", bnf);

	}
	void setBaldnessSamplesDirty(int bsd)
	{
		if(bsd == 0.0) return;
		fprintf(mFile,"setAttr \".bsd\" %i;\n", bsd);

	}
	void setBaldnessMapDirty(int bmd)
	{
		if(bmd == 0.0) return;
		fprintf(mFile,"setAttr \".bmd\" %i;\n", bmd);

	}
	void setBaseOpacity(float dbo)
	{
		if(dbo == 1.0) return;
		fprintf(mFile,"setAttr \".dbo\" %f;\n", dbo);

	}
	void setBaseOpacitySamples(size_t bos_i,double bos)
	{
		if(bos == 0.0) return;
		fprintf(mFile,"setAttr \".bos[%i]\" %f;\n", bos_i,bos);

	}
	void setBaseOpacityMap(const string& bom)
	{
		if(bom == "n/a") return;
		fprintf(mFile,"setAttr \".bom\" -type \"string\" ");
		bom.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseOpacityMapOffset(float bomo)
	{
		if(bomo == 0.0) return;
		fprintf(mFile,"setAttr \".bomo\" %f;\n", bomo);

	}
	void setBaseOpacityMapMult(float bomm)
	{
		if(bomm == 1.0) return;
		fprintf(mFile,"setAttr \".bomm\" %f;\n", bomm);

	}
	void setBaseOpacityNoise(float bon)
	{
		if(bon == 0.0) return;
		fprintf(mFile,"setAttr \".bon\" %f;\n", bon);

	}
	void setBaseOpacityNoiseFreq(float bonf)
	{
		if(bonf == 10.0) return;
		fprintf(mFile,"setAttr \".bonf\" %f;\n", bonf);

	}
	void setBaseOpacitySamplesDirty(int bosd)
	{
		if(bosd == 0.0) return;
		fprintf(mFile,"setAttr \".bosd\" %i;\n", bosd);

	}
	void setBaseOpacityMapDirty(int bomd)
	{
		if(bomd == 0.0) return;
		fprintf(mFile,"setAttr \".bomd\" %i;\n", bomd);

	}
	void setTipOpacity(float dto)
	{
		if(dto == 1.0) return;
		fprintf(mFile,"setAttr \".dto\" %f;\n", dto);

	}
	void setTipOpacitySamples(size_t tos_i,double tos)
	{
		if(tos == 0.0) return;
		fprintf(mFile,"setAttr \".tos[%i]\" %f;\n", tos_i,tos);

	}
	void setTipOpacityMap(const string& tom)
	{
		if(tom == "n/a") return;
		fprintf(mFile,"setAttr \".tom\" -type \"string\" ");
		tom.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipOpacityMapOffset(float tomo)
	{
		if(tomo == 0.0) return;
		fprintf(mFile,"setAttr \".tomo\" %f;\n", tomo);

	}
	void setTipOpacityMapMult(float tomm)
	{
		if(tomm == 1.0) return;
		fprintf(mFile,"setAttr \".tomm\" %f;\n", tomm);

	}
	void setTipOpacityNoise(float ton)
	{
		if(ton == 0.0) return;
		fprintf(mFile,"setAttr \".ton\" %f;\n", ton);

	}
	void setTipOpacityNoiseFreq(float tonf)
	{
		if(tonf == 10.0) return;
		fprintf(mFile,"setAttr \".tonf\" %f;\n", tonf);

	}
	void setTipOpacitySamplesDirty(int tosd)
	{
		if(tosd == 0.0) return;
		fprintf(mFile,"setAttr \".tosd\" %i;\n", tosd);

	}
	void setTipOpacityMapDirty(int tomd)
	{
		if(tomd == 0.0) return;
		fprintf(mFile,"setAttr \".tomd\" %i;\n", tomd);

	}
	void setBaseCurl(float dbcl)
	{
		if(dbcl == 0.50) return;
		fprintf(mFile,"setAttr \".dbcl\" %f;\n", dbcl);

	}
	void setBaseCurlSamples(size_t bcls_i,double bcls)
	{
		if(bcls == 0.0) return;
		fprintf(mFile,"setAttr \".bcls[%i]\" %f;\n", bcls_i,bcls);

	}
	void setBaseCurlMap(const string& bclm)
	{
		if(bclm == "n/a") return;
		fprintf(mFile,"setAttr \".bclm\" -type \"string\" ");
		bclm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseCurlMapOffset(float bclmo)
	{
		if(bclmo == 0.0) return;
		fprintf(mFile,"setAttr \".bclmo\" %f;\n", bclmo);

	}
	void setBaseCurlMapMult(float bclmm)
	{
		if(bclmm == 1.0) return;
		fprintf(mFile,"setAttr \".bclmm\" %f;\n", bclmm);

	}
	void setBaseCurlNoise(float bcln)
	{
		if(bcln == 0.0) return;
		fprintf(mFile,"setAttr \".bcln\" %f;\n", bcln);

	}
	void setBaseCurlNoiseFreq(float bclnf)
	{
		if(bclnf == 10.0) return;
		fprintf(mFile,"setAttr \".bclnf\" %f;\n", bclnf);

	}
	void setBaseCurlSamplesDirty(int bclsd)
	{
		if(bclsd == 0.0) return;
		fprintf(mFile,"setAttr \".bclsd\" %i;\n", bclsd);

	}
	void setBaseCurlMapDirty(int bclmd)
	{
		if(bclmd == 0.0) return;
		fprintf(mFile,"setAttr \".bclmd\" %i;\n", bclmd);

	}
	void setTipCurl(float dtcl)
	{
		if(dtcl == 0.5) return;
		fprintf(mFile,"setAttr \".dtcl\" %f;\n", dtcl);

	}
	void setTipCurlSamples(size_t tcls_i,double tcls)
	{
		if(tcls == 0.0) return;
		fprintf(mFile,"setAttr \".tcls[%i]\" %f;\n", tcls_i,tcls);

	}
	void setTipCurlMap(const string& tclm)
	{
		if(tclm == "n/a") return;
		fprintf(mFile,"setAttr \".tclm\" -type \"string\" ");
		tclm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipCurlMapOffset(float tclmo)
	{
		if(tclmo == 0.0) return;
		fprintf(mFile,"setAttr \".tclmo\" %f;\n", tclmo);

	}
	void setTipCurlMapMult(float tclmm)
	{
		if(tclmm == 1.0) return;
		fprintf(mFile,"setAttr \".tclmm\" %f;\n", tclmm);

	}
	void setTipCurlNoise(float tcln)
	{
		if(tcln == 0.0) return;
		fprintf(mFile,"setAttr \".tcln\" %f;\n", tcln);

	}
	void setTipCurlNoiseFreq(float tclnf)
	{
		if(tclnf == 10.0) return;
		fprintf(mFile,"setAttr \".tclnf\" %f;\n", tclnf);

	}
	void setTipCurlSamplesDirty(int tclsd)
	{
		if(tclsd == 0.0) return;
		fprintf(mFile,"setAttr \".tclsd\" %i;\n", tclsd);

	}
	void setTipCurlMapDirty(int tclmd)
	{
		if(tclmd == 0.0) return;
		fprintf(mFile,"setAttr \".tclmd\" %i;\n", tclmd);

	}
	void setBaseWidth(double dbw)
	{
		if(dbw == 0) return;
		fprintf(mFile,"setAttr \".dbw\" %f;\n", dbw);

	}
	void setBaseWidthSamples(size_t bws_i,double bws)
	{
		if(bws == 0.0) return;
		fprintf(mFile,"setAttr \".bws[%i]\" %f;\n", bws_i,bws);

	}
	void setBaseWidthMap(const string& bwm)
	{
		if(bwm == "n/a") return;
		fprintf(mFile,"setAttr \".bwm\" -type \"string\" ");
		bwm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseWidthMapOffset(double bwmo)
	{
		if(bwmo == 0) return;
		fprintf(mFile,"setAttr \".bwmo\" %f;\n", bwmo);

	}
	void setBaseWidthMapMult(double bwmm)
	{
		if(bwmm == 1) return;
		fprintf(mFile,"setAttr \".bwmm\" %f;\n", bwmm);

	}
	void setBaseWidthNoise(double bwn)
	{
		if(bwn == 0) return;
		fprintf(mFile,"setAttr \".bwn\" %f;\n", bwn);

	}
	void setBaseWidthNoiseFreq(float bwnf)
	{
		if(bwnf == 10.0) return;
		fprintf(mFile,"setAttr \".bwnf\" %f;\n", bwnf);

	}
	void setBaseWidthSamplesDirty(int bwsd)
	{
		if(bwsd == 0.0) return;
		fprintf(mFile,"setAttr \".bwsd\" %i;\n", bwsd);

	}
	void setBaseWidthMapDirty(int bwmd)
	{
		if(bwmd == 0.0) return;
		fprintf(mFile,"setAttr \".bwmd\" %i;\n", bwmd);

	}
	void setTipWidth(double dtw)
	{
		if(dtw == 0) return;
		fprintf(mFile,"setAttr \".dtw\" %f;\n", dtw);

	}
	void setTipWidthSamples(size_t tws_i,double tws)
	{
		if(tws == 0.0) return;
		fprintf(mFile,"setAttr \".tws[%i]\" %f;\n", tws_i,tws);

	}
	void setTipWidthMap(const string& twm)
	{
		if(twm == "n/a") return;
		fprintf(mFile,"setAttr \".twm\" -type \"string\" ");
		twm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipWidthMapOffset(double twmo)
	{
		if(twmo == 0) return;
		fprintf(mFile,"setAttr \".twmo\" %f;\n", twmo);

	}
	void setTipWidthMapMult(double twmm)
	{
		if(twmm == 1) return;
		fprintf(mFile,"setAttr \".twmm\" %f;\n", twmm);

	}
	void setTipWidthNoise(double twn)
	{
		if(twn == 0) return;
		fprintf(mFile,"setAttr \".twn\" %f;\n", twn);

	}
	void setTipWidthNoiseFreq(float twnf)
	{
		if(twnf == 10.0) return;
		fprintf(mFile,"setAttr \".twnf\" %f;\n", twnf);

	}
	void setTipWidthSamplesDirty(int twsd)
	{
		if(twsd == 0.0) return;
		fprintf(mFile,"setAttr \".twsd\" %i;\n", twsd);

	}
	void setTipWidthMapDirty(int twmd)
	{
		if(twmd == 0.0) return;
		fprintf(mFile,"setAttr \".twmd\" %i;\n", twmd);

	}
	void setScraggle(float ds)
	{
		if(ds == 0.0) return;
		fprintf(mFile,"setAttr \".ds\" %f;\n", ds);

	}
	void setScraggleSamples(size_t ss_i,double ss)
	{
		if(ss == 0.0) return;
		fprintf(mFile,"setAttr \".ss[%i]\" %f;\n", ss_i,ss);

	}
	void setScraggleMap(const string& sm)
	{
		if(sm == "n/a") return;
		fprintf(mFile,"setAttr \".sm\" -type \"string\" ");
		sm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScraggleMapOffset(float smo)
	{
		if(smo == 0.0) return;
		fprintf(mFile,"setAttr \".smo\" %f;\n", smo);

	}
	void setScraggleMapMult(float smm)
	{
		if(smm == 1.0) return;
		fprintf(mFile,"setAttr \".smm\" %f;\n", smm);

	}
	void setScraggleNoise(float sn)
	{
		if(sn == 0.0) return;
		fprintf(mFile,"setAttr \".sn\" %f;\n", sn);

	}
	void setScraggleNoiseFreq(float snf)
	{
		if(snf == 10.0) return;
		fprintf(mFile,"setAttr \".snf\" %f;\n", snf);

	}
	void setScraggleSamplesDirty(int ssd)
	{
		if(ssd == 0.0) return;
		fprintf(mFile,"setAttr \".ssd\" %i;\n", ssd);

	}
	void setScraggleMapDirty(int smd)
	{
		if(smd == 0.0) return;
		fprintf(mFile,"setAttr \".smd\" %i;\n", smd);

	}
	void setScraggleCorrelation(float dsco)
	{
		if(dsco == 0.0) return;
		fprintf(mFile,"setAttr \".dsco\" %f;\n", dsco);

	}
	void setScraggleCorrelationSamples(size_t scos_i,double scos)
	{
		if(scos == 0.0) return;
		fprintf(mFile,"setAttr \".scos[%i]\" %f;\n", scos_i,scos);

	}
	void setScraggleCorrelationMap(const string& scom)
	{
		if(scom == "n/a") return;
		fprintf(mFile,"setAttr \".scom\" -type \"string\" ");
		scom.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScraggleCorrelationMapOffset(float scomo)
	{
		if(scomo == 0.0) return;
		fprintf(mFile,"setAttr \".scomo\" %f;\n", scomo);

	}
	void setScraggleCorrelationMapMult(float scomm)
	{
		if(scomm == 1.0) return;
		fprintf(mFile,"setAttr \".scomm\" %f;\n", scomm);

	}
	void setScraggleCorrelationNoise(float scon)
	{
		if(scon == 0.0) return;
		fprintf(mFile,"setAttr \".scon\" %f;\n", scon);

	}
	void setScraggleCorrelationNoiseFreq(float sconf)
	{
		if(sconf == 10.0) return;
		fprintf(mFile,"setAttr \".sconf\" %f;\n", sconf);

	}
	void setScraggleCorrelationSamplesDirty(int scosd)
	{
		if(scosd == 0.0) return;
		fprintf(mFile,"setAttr \".scosd\" %i;\n", scosd);

	}
	void setScraggleCorrelationMapDirty(int scomd)
	{
		if(scomd == 0.0) return;
		fprintf(mFile,"setAttr \".scomd\" %i;\n", scomd);

	}
	void setScraggleFrequency(float dscf)
	{
		if(dscf == 5.0) return;
		fprintf(mFile,"setAttr \".dscf\" %f;\n", dscf);

	}
	void setScraggleFrequencySamples(size_t scfs_i,double scfs)
	{
		if(scfs == 0.0) return;
		fprintf(mFile,"setAttr \".scfs[%i]\" %f;\n", scfs_i,scfs);

	}
	void setScraggleFrequencyMap(const string& scfm)
	{
		if(scfm == "n/a") return;
		fprintf(mFile,"setAttr \".scfm\" -type \"string\" ");
		scfm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScraggleFrequencyMapOffset(float scfmo)
	{
		if(scfmo == 0.0) return;
		fprintf(mFile,"setAttr \".scfmo\" %f;\n", scfmo);

	}
	void setScraggleFrequencyMapMult(float scfmm)
	{
		if(scfmm == 1.0) return;
		fprintf(mFile,"setAttr \".scfmm\" %f;\n", scfmm);

	}
	void setScraggleFrequencyNoise(float scfn)
	{
		if(scfn == 0.0) return;
		fprintf(mFile,"setAttr \".scfn\" %f;\n", scfn);

	}
	void setScraggleFrequencyNoiseFreq(float scfnf)
	{
		if(scfnf == 10.0) return;
		fprintf(mFile,"setAttr \".scfnf\" %f;\n", scfnf);

	}
	void setScraggleFrequencySamplesDirty(int scfsd)
	{
		if(scfsd == 0.0) return;
		fprintf(mFile,"setAttr \".scfsd\" %i;\n", scfsd);

	}
	void setScraggleFrequencyMapDirty(int scfmd)
	{
		if(scfmd == 0.0) return;
		fprintf(mFile,"setAttr \".scfmd\" %i;\n", scfmd);

	}
	void setSegments(float dseg)
	{
		if(dseg == 10) return;
		fprintf(mFile,"setAttr \".dseg\" %f;\n", dseg);

	}
	void setSegmentsSamples(size_t segs_i,double segs)
	{
		if(segs == 0.0) return;
		fprintf(mFile,"setAttr \".segs[%i]\" %f;\n", segs_i,segs);

	}
	void setSegmentsMap(const string& segm)
	{
		if(segm == "n/a") return;
		fprintf(mFile,"setAttr \".segm\" -type \"string\" ");
		segm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSegmentsMapOffset(float segmo)
	{
		if(segmo == 0.0) return;
		fprintf(mFile,"setAttr \".segmo\" %f;\n", segmo);

	}
	void setSegmentsMapMult(float segmm)
	{
		if(segmm == 1.0) return;
		fprintf(mFile,"setAttr \".segmm\" %f;\n", segmm);

	}
	void setSegmentsNoise(float segn)
	{
		if(segn == 0.0) return;
		fprintf(mFile,"setAttr \".segn\" %f;\n", segn);

	}
	void setSegmentsNoiseFreq(float segnf)
	{
		if(segnf == 10.0) return;
		fprintf(mFile,"setAttr \".segnf\" %f;\n", segnf);

	}
	void setSegmentsSamplesDirty(int segsd)
	{
		if(segsd == 0.0) return;
		fprintf(mFile,"setAttr \".segsd\" %i;\n", segsd);

	}
	void setSegmentsMapDirty(int segmd)
	{
		if(segmd == 0.0) return;
		fprintf(mFile,"setAttr \".segmd\" %i;\n", segmd);

	}
	void setAttraction(float dat)
	{
		if(dat == 1.0) return;
		fprintf(mFile,"setAttr \".dat\" %f;\n", dat);

	}
	void setAttractionSamples(size_t ats_i,double ats)
	{
		if(ats == 0.0) return;
		fprintf(mFile,"setAttr \".ats[%i]\" %f;\n", ats_i,ats);

	}
	void setAttractionMap(const string& atm)
	{
		if(atm == "n/a") return;
		fprintf(mFile,"setAttr \".atm\" -type \"string\" ");
		atm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAttractionMapOffset(float atmo)
	{
		if(atmo == 0.0) return;
		fprintf(mFile,"setAttr \".atmo\" %f;\n", atmo);

	}
	void setAttractionMapMult(float atmm)
	{
		if(atmm == 1.0) return;
		fprintf(mFile,"setAttr \".atmm\" %f;\n", atmm);

	}
	void setAttractionNoise(float atn)
	{
		if(atn == 0.0) return;
		fprintf(mFile,"setAttr \".atn\" %f;\n", atn);

	}
	void setAttractionNoiseFreq(float atnf)
	{
		if(atnf == 10.0) return;
		fprintf(mFile,"setAttr \".atnf\" %f;\n", atnf);

	}
	void setAttractionSamplesDirty(int atsd)
	{
		if(atsd == 0.0) return;
		fprintf(mFile,"setAttr \".atsd\" %i;\n", atsd);

	}
	void setAttractionMapDirty(int atmd)
	{
		if(atmd == 0.0) return;
		fprintf(mFile,"setAttr \".atmd\" %i;\n", atmd);

	}
	void setOffset(double dofs)
	{
		if(dofs == 0) return;
		fprintf(mFile,"setAttr \".dofs\" %f;\n", dofs);

	}
	void setOffsetSamples(size_t ofss_i,double ofss)
	{
		if(ofss == 0.0) return;
		fprintf(mFile,"setAttr \".ofss[%i]\" %f;\n", ofss_i,ofss);

	}
	void setOffsetMap(const string& ofsm)
	{
		if(ofsm == "n/a") return;
		fprintf(mFile,"setAttr \".ofsm\" -type \"string\" ");
		ofsm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffsetMapOffset(double ofsmo)
	{
		if(ofsmo == 0) return;
		fprintf(mFile,"setAttr \".ofsmo\" %f;\n", ofsmo);

	}
	void setOffsetMapMult(double ofsmm)
	{
		if(ofsmm == 1) return;
		fprintf(mFile,"setAttr \".ofsmm\" %f;\n", ofsmm);

	}
	void setOffsetNoise(double ofsn)
	{
		if(ofsn == 0) return;
		fprintf(mFile,"setAttr \".ofsn\" %f;\n", ofsn);

	}
	void setOffsetNoiseFreq(float ofsnf)
	{
		if(ofsnf == 10.0) return;
		fprintf(mFile,"setAttr \".ofsnf\" %f;\n", ofsnf);

	}
	void setOffsetSamplesDirty(int ofssd)
	{
		if(ofssd == 0.0) return;
		fprintf(mFile,"setAttr \".ofssd\" %i;\n", ofssd);

	}
	void setOffsetMapDirty(int ofsmd)
	{
		if(ofsmd == 0.0) return;
		fprintf(mFile,"setAttr \".ofsmd\" %i;\n", ofsmd);

	}
	void setClumping(float dc)
	{
		if(dc == 0.0) return;
		fprintf(mFile,"setAttr \".dc\" %f;\n", dc);

	}
	void setClumpingSamples(size_t cs_i,double cs)
	{
		if(cs == 0.0) return;
		fprintf(mFile,"setAttr \".cs[%i]\" %f;\n", cs_i,cs);

	}
	void setClumpingMap(const string& cm)
	{
		if(cm == "n/a") return;
		fprintf(mFile,"setAttr \".cm\" -type \"string\" ");
		cm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpingMapOffset(float cmo)
	{
		if(cmo == 0.0) return;
		fprintf(mFile,"setAttr \".cmo\" %f;\n", cmo);

	}
	void setClumpingMapMult(float cmm)
	{
		if(cmm == 0.0) return;
		fprintf(mFile,"setAttr \".cmm\" %f;\n", cmm);

	}
	void setClumpingNoise(float cn)
	{
		if(cn == 0.0) return;
		fprintf(mFile,"setAttr \".cn\" %f;\n", cn);

	}
	void setClumpingNoiseFreq(float cnf)
	{
		if(cnf == 0.0) return;
		fprintf(mFile,"setAttr \".cnf\" %f;\n", cnf);

	}
	void setClumpingSamplesDirty(int csd)
	{
		if(csd == 0.0) return;
		fprintf(mFile,"setAttr \".csd\" %i;\n", csd);

	}
	void setClumpingMapDirty(int cmd)
	{
		if(cmd == 0.0) return;
		fprintf(mFile,"setAttr \".cmd\" %i;\n", cmd);

	}
	void setClumpingFrequency(float dcf)
	{
		if(dcf == 0.0) return;
		fprintf(mFile,"setAttr \".dcf\" %f;\n", dcf);

	}
	void setClumpingFrequencySamples(size_t cfs_i,double cfs)
	{
		if(cfs == 0.0) return;
		fprintf(mFile,"setAttr \".cfs[%i]\" %f;\n", cfs_i,cfs);

	}
	void setClumpingFrequencyMap(const string& cfm)
	{
		if(cfm == "n/a") return;
		fprintf(mFile,"setAttr \".cfm\" -type \"string\" ");
		cfm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpingFrequencyMapOffset(float cfmo)
	{
		if(cfmo == 0.0) return;
		fprintf(mFile,"setAttr \".cfmo\" %f;\n", cfmo);

	}
	void setClumpingFrequencyMapMult(float cfmm)
	{
		if(cfmm == 0.0) return;
		fprintf(mFile,"setAttr \".cfmm\" %f;\n", cfmm);

	}
	void setClumpingFrequencyNoise(float cfn)
	{
		if(cfn == 0.0) return;
		fprintf(mFile,"setAttr \".cfn\" %f;\n", cfn);

	}
	void setClumpingFrequencyNoiseFreq(float cfnf)
	{
		if(cfnf == 0.0) return;
		fprintf(mFile,"setAttr \".cfnf\" %f;\n", cfnf);

	}
	void setClumpingFrequencySamplesDirty(int cfsd)
	{
		if(cfsd == 0.0) return;
		fprintf(mFile,"setAttr \".cfsd\" %i;\n", cfsd);

	}
	void setClumpingFrequencyMapDirty(int cfmd)
	{
		if(cfmd == 0.0) return;
		fprintf(mFile,"setAttr \".cfmd\" %i;\n", cfmd);

	}
	void setClumpingShape(float dcs)
	{
		if(dcs == 0.0) return;
		fprintf(mFile,"setAttr \".dcs\" %f;\n", dcs);

	}
	void setClumpingShapeSamples(size_t css_i,double css)
	{
		if(css == 0.0) return;
		fprintf(mFile,"setAttr \".css[%i]\" %f;\n", css_i,css);

	}
	void setClumpingShapeMap(const string& csm)
	{
		if(csm == "n/a") return;
		fprintf(mFile,"setAttr \".csm\" -type \"string\" ");
		csm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpingShapeMapOffset(float csmo)
	{
		if(csmo == 0.0) return;
		fprintf(mFile,"setAttr \".csmo\" %f;\n", csmo);

	}
	void setClumpingShapeMapMult(float csmm)
	{
		if(csmm == 0.0) return;
		fprintf(mFile,"setAttr \".csmm\" %f;\n", csmm);

	}
	void setClumpingShapeNoise(float csn)
	{
		if(csn == 0.0) return;
		fprintf(mFile,"setAttr \".csn\" %f;\n", csn);

	}
	void setClumpingShapeNoiseFreq(float csnf)
	{
		if(csnf == 0.0) return;
		fprintf(mFile,"setAttr \".csnf\" %f;\n", csnf);

	}
	void setClumpingShapeSamplesDirty(int cssd)
	{
		if(cssd == 0.0) return;
		fprintf(mFile,"setAttr \".cssd\" %i;\n", cssd);

	}
	void setClumpingShapeMapDirty(int csmd)
	{
		if(csmd == 0.0) return;
		fprintf(mFile,"setAttr \".csmd\" %i;\n", csmd);

	}
	void setBaseColor(const float3& dbc)
	{
		if(dbc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".dbc\" -type \"float3\" ");
		dbc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseColorR(float dbcr)
	{
		if(dbcr == 1.0) return;
		fprintf(mFile,"setAttr \".dbcr\" %f;\n", dbcr);

	}
	void setBaseColorG(float dbcg)
	{
		if(dbcg == 1.0) return;
		fprintf(mFile,"setAttr \".dbcg\" %f;\n", dbcg);

	}
	void setBaseColorB(float dbcb)
	{
		if(dbcb == 1.0) return;
		fprintf(mFile,"setAttr \".dbcb\" %f;\n", dbcb);

	}
	void setBaseColorSamples(size_t bcs_i,double bcs)
	{
		if(bcs == 0.0) return;
		fprintf(mFile,"setAttr \".bcs[%i]\" %f;\n", bcs_i,bcs);

	}
	void setBaseColorMap(const string& bcm)
	{
		if(bcm == "n/a") return;
		fprintf(mFile,"setAttr \".bcm\" -type \"string\" ");
		bcm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseColorNoise(float bcn)
	{
		if(bcn == 0.0) return;
		fprintf(mFile,"setAttr \".bcn\" %f;\n", bcn);

	}
	void setBaseColorNoiseFreq(float bcnf)
	{
		if(bcnf == 10.0) return;
		fprintf(mFile,"setAttr \".bcnf\" %f;\n", bcnf);

	}
	void setBaseColorSamplesDirty(int bcsd)
	{
		if(bcsd == 0.0) return;
		fprintf(mFile,"setAttr \".bcsd\" %i;\n", bcsd);

	}
	void setBaseColorMapDirty(int bcmd)
	{
		if(bcmd == 0.0) return;
		fprintf(mFile,"setAttr \".bcmd\" %i;\n", bcmd);

	}
	void setTipColor(const float3& dtc)
	{
		if(dtc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".dtc\" -type \"float3\" ");
		dtc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipColorR(float dtcr)
	{
		if(dtcr == 1.0) return;
		fprintf(mFile,"setAttr \".dtcr\" %f;\n", dtcr);

	}
	void setTipColorG(float dtcg)
	{
		if(dtcg == 1.0) return;
		fprintf(mFile,"setAttr \".dtcg\" %f;\n", dtcg);

	}
	void setTipColorB(float dtcb)
	{
		if(dtcb == 1.0) return;
		fprintf(mFile,"setAttr \".dtcb\" %f;\n", dtcb);

	}
	void setTipColorSamples(size_t tcs_i,double tcs)
	{
		if(tcs == 0.0) return;
		fprintf(mFile,"setAttr \".tcs[%i]\" %f;\n", tcs_i,tcs);

	}
	void setTipColorMap(const string& tcm)
	{
		if(tcm == "n/a") return;
		fprintf(mFile,"setAttr \".tcm\" -type \"string\" ");
		tcm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipColorNoise(float tcn)
	{
		if(tcn == 0.0) return;
		fprintf(mFile,"setAttr \".tcn\" %f;\n", tcn);

	}
	void setTipColorNoiseFreq(float tcnf)
	{
		if(tcnf == 10.0) return;
		fprintf(mFile,"setAttr \".tcnf\" %f;\n", tcnf);

	}
	void setTipColorSamplesDirty(int tcsd)
	{
		if(tcsd == 0.0) return;
		fprintf(mFile,"setAttr \".tcsd\" %i;\n", tcsd);

	}
	void setTipColorMapDirty(int tcmd)
	{
		if(tcmd == 0.0) return;
		fprintf(mFile,"setAttr \".tcmd\" %i;\n", tcmd);

	}
	void setRadius(double dar)
	{
		if(dar == 1) return;
		fprintf(mFile,"setAttr \".dar\" %f;\n", dar);

	}
	void setRadiusSamples(size_t ars_i,double ars)
	{
		if(ars == 0.0) return;
		fprintf(mFile,"setAttr \".ars[%i]\" %f;\n", ars_i,ars);

	}
	void setRadiusMap(const string& arm)
	{
		if(arm == "n/a") return;
		fprintf(mFile,"setAttr \".arm\" -type \"string\" ");
		arm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRadiusMapOffset(double armo)
	{
		if(armo == 0) return;
		fprintf(mFile,"setAttr \".armo\" %f;\n", armo);

	}
	void setRadiusMapMult(double armm)
	{
		if(armm == 1) return;
		fprintf(mFile,"setAttr \".armm\" %f;\n", armm);

	}
	void setRadiusNoise(double arn)
	{
		if(arn == 0) return;
		fprintf(mFile,"setAttr \".arn\" %f;\n", arn);

	}
	void setRadiusNoiseFreq(float arnf)
	{
		if(arnf == 10.0) return;
		fprintf(mFile,"setAttr \".arnf\" %f;\n", arnf);

	}
	void setRadiusSamplesDirty(int arsd)
	{
		if(arsd == 0.0) return;
		fprintf(mFile,"setAttr \".arsd\" %i;\n", arsd);

	}
	void setRadiusMapDirty(int armd)
	{
		if(armd == 0.0) return;
		fprintf(mFile,"setAttr \".armd\" %i;\n", armd);

	}
	void setPower(float dap)
	{
		if(dap == 1.0) return;
		fprintf(mFile,"setAttr \".dap\" %f;\n", dap);

	}
	void setPowerSamples(size_t aps_i,double aps)
	{
		if(aps == 0.0) return;
		fprintf(mFile,"setAttr \".aps[%i]\" %f;\n", aps_i,aps);

	}
	void setPowerMap(const string& apm)
	{
		if(apm == "n/a") return;
		fprintf(mFile,"setAttr \".apm\" -type \"string\" ");
		apm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPowerMapOffset(float apmo)
	{
		if(apmo == 0.0) return;
		fprintf(mFile,"setAttr \".apmo\" %f;\n", apmo);

	}
	void setPowerMapMult(float apmm)
	{
		if(apmm == 1.0) return;
		fprintf(mFile,"setAttr \".apmm\" %f;\n", apmm);

	}
	void setPowerNoise(float apn)
	{
		if(apn == 0.0) return;
		fprintf(mFile,"setAttr \".apn\" %f;\n", apn);

	}
	void setPowerNoiseFreq(float apnf)
	{
		if(apnf == 10.0) return;
		fprintf(mFile,"setAttr \".apnf\" %f;\n", apnf);

	}
	void setPowerSamplesDirty(int apsd)
	{
		if(apsd == 0.0) return;
		fprintf(mFile,"setAttr \".apsd\" %i;\n", apsd);

	}
	void setPowerMapDirty(int apmd)
	{
		if(apmd == 0.0) return;
		fprintf(mFile,"setAttr \".apmd\" %i;\n", apmd);

	}
	void setInfluence(float dai)
	{
		if(dai == 1.0) return;
		fprintf(mFile,"setAttr \".dai\" %f;\n", dai);

	}
	void setInfluenceSamples(size_t ais_i,double ais)
	{
		if(ais == 0.0) return;
		fprintf(mFile,"setAttr \".ais[%i]\" %f;\n", ais_i,ais);

	}
	void setInfluenceMap(const string& aim)
	{
		if(aim == "n/a") return;
		fprintf(mFile,"setAttr \".aim\" -type \"string\" ");
		aim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInfluenceMapOffset(float aimo)
	{
		if(aimo == 0.0) return;
		fprintf(mFile,"setAttr \".aimo\" %f;\n", aimo);

	}
	void setInfluenceMapMult(float aimm)
	{
		if(aimm == 1.0) return;
		fprintf(mFile,"setAttr \".aimm\" %f;\n", aimm);

	}
	void setInfluenceNoise(float ain)
	{
		if(ain == 0.0) return;
		fprintf(mFile,"setAttr \".ain\" %f;\n", ain);

	}
	void setInfluenceNoiseFreq(float ainf)
	{
		if(ainf == 10.0) return;
		fprintf(mFile,"setAttr \".ainf\" %f;\n", ainf);

	}
	void setInfluenceSamplesDirty(int aisd)
	{
		if(aisd == 0.0) return;
		fprintf(mFile,"setAttr \".aisd\" %i;\n", aisd);

	}
	void setInfluenceMapDirty(int aimd)
	{
		if(aimd == 0.0) return;
		fprintf(mFile,"setAttr \".aimd\" %i;\n", aimd);

	}
	void setStartLength(double dasl)
	{
		if(dasl == 0) return;
		fprintf(mFile,"setAttr \".dasl\" %f;\n", dasl);

	}
	void setStartLengthSamples(size_t asls_i,double asls)
	{
		if(asls == 0.0) return;
		fprintf(mFile,"setAttr \".asls[%i]\" %f;\n", asls_i,asls);

	}
	void setStartLengthMap(const string& aslm)
	{
		if(aslm == "n/a") return;
		fprintf(mFile,"setAttr \".aslm\" -type \"string\" ");
		aslm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStartLengthMapOffset(double aslmo)
	{
		if(aslmo == 0) return;
		fprintf(mFile,"setAttr \".aslmo\" %f;\n", aslmo);

	}
	void setStartLengthMapMult(double aslmm)
	{
		if(aslmm == 1) return;
		fprintf(mFile,"setAttr \".aslmm\" %f;\n", aslmm);

	}
	void setStartLengthNoise(double asln)
	{
		if(asln == 0) return;
		fprintf(mFile,"setAttr \".asln\" %f;\n", asln);

	}
	void setStartLengthNoiseFreq(float aslnf)
	{
		if(aslnf == 10.0) return;
		fprintf(mFile,"setAttr \".aslnf\" %f;\n", aslnf);

	}
	void setStartLengthSamplesDirty(int aslsd)
	{
		if(aslsd == 0.0) return;
		fprintf(mFile,"setAttr \".aslsd\" %i;\n", aslsd);

	}
	void setStartLengthMapDirty(int aslmd)
	{
		if(aslmd == 0.0) return;
		fprintf(mFile,"setAttr \".aslmd\" %i;\n", aslmd);

	}
	void setEndLength(double dael)
	{
		if(dael == 5) return;
		fprintf(mFile,"setAttr \".dael\" %f;\n", dael);

	}
	void setEndLengthSamples(size_t aels_i,double aels)
	{
		if(aels == 0.0) return;
		fprintf(mFile,"setAttr \".aels[%i]\" %f;\n", aels_i,aels);

	}
	void setEndLengthMap(const string& aelm)
	{
		if(aelm == "n/a") return;
		fprintf(mFile,"setAttr \".aelm\" -type \"string\" ");
		aelm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEndLengthMapOffset(double aelmo)
	{
		if(aelmo == 0) return;
		fprintf(mFile,"setAttr \".aelmo\" %f;\n", aelmo);

	}
	void setEndLengthMapMult(double aelmm)
	{
		if(aelmm == 1) return;
		fprintf(mFile,"setAttr \".aelmm\" %f;\n", aelmm);

	}
	void setEndLengthNoise(double aeln)
	{
		if(aeln == 0) return;
		fprintf(mFile,"setAttr \".aeln\" %f;\n", aeln);

	}
	void setEndLengthNoiseFreq(float aelnf)
	{
		if(aelnf == 10.0) return;
		fprintf(mFile,"setAttr \".aelnf\" %f;\n", aelnf);

	}
	void setEndLengthSamplesDirty(int aelsd)
	{
		if(aelsd == 0.0) return;
		fprintf(mFile,"setAttr \".aelsd\" %i;\n", aelsd);

	}
	void setEndLengthMapDirty(int aelmd)
	{
		if(aelmd == 0.0) return;
		fprintf(mFile,"setAttr \".aelmd\" %i;\n", aelmd);

	}
	void setThresholdLength(double datl)
	{
		if(datl == 0) return;
		fprintf(mFile,"setAttr \".datl\" %f;\n", datl);

	}
	void setThresholdLengthSamples(size_t atls_i,double atls)
	{
		if(atls == 0.0) return;
		fprintf(mFile,"setAttr \".atls[%i]\" %f;\n", atls_i,atls);

	}
	void setThresholdLengthMap(const string& atlm)
	{
		if(atlm == "n/a") return;
		fprintf(mFile,"setAttr \".atlm\" -type \"string\" ");
		atlm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setThresholdLengthMapOffset(double atlmo)
	{
		if(atlmo == 0) return;
		fprintf(mFile,"setAttr \".atlmo\" %f;\n", atlmo);

	}
	void setThresholdLengthMapMult(double atlmm)
	{
		if(atlmm == 1) return;
		fprintf(mFile,"setAttr \".atlmm\" %f;\n", atlmm);

	}
	void setThresholdLengthNoise(double atln)
	{
		if(atln == 0) return;
		fprintf(mFile,"setAttr \".atln\" %f;\n", atln);

	}
	void setThresholdLengthNoiseFreq(float atlnf)
	{
		if(atlnf == 10.0) return;
		fprintf(mFile,"setAttr \".atlnf\" %f;\n", atlnf);

	}
	void setThresholdLengthSamplesDirty(int atlsd)
	{
		if(atlsd == 0.0) return;
		fprintf(mFile,"setAttr \".atlsd\" %i;\n", atlsd);

	}
	void setThresholdLengthMapDirty(int atlmd)
	{
		if(atlmd == 0.0) return;
		fprintf(mFile,"setAttr \".atlmd\" %i;\n", atlmd);

	}
	void setUnused(float dun)
	{
		if(dun == 1.0) return;
		fprintf(mFile,"setAttr \".dun\" %f;\n", dun);

	}
	void setUnusedSamples(size_t uns_i,double uns)
	{
		if(uns == 0.0) return;
		fprintf(mFile,"setAttr \".uns[%i]\" %f;\n", uns_i,uns);

	}
	void setUnusedMap(const string& unm)
	{
		if(unm == "n/a") return;
		fprintf(mFile,"setAttr \".unm\" -type \"string\" ");
		unm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUnusedMapOffset(float unmo)
	{
		if(unmo == 0.0) return;
		fprintf(mFile,"setAttr \".unmo\" %f;\n", unmo);

	}
	void setUnusedMapMult(float unmm)
	{
		if(unmm == 1.0) return;
		fprintf(mFile,"setAttr \".unmm\" %f;\n", unmm);

	}
	void setUnusedNoise(float unn)
	{
		if(unn == 0.0) return;
		fprintf(mFile,"setAttr \".unn\" %f;\n", unn);

	}
	void setUnusedNoiseFreq(float unnf)
	{
		if(unnf == 10.0) return;
		fprintf(mFile,"setAttr \".unnf\" %f;\n", unnf);

	}
	void setUnusedSamplesDirty(int unsd)
	{
		if(unsd == 0.0) return;
		fprintf(mFile,"setAttr \".unsd\" %i;\n", unsd);

	}
	void setUnusedMapDirty(int unmd)
	{
		if(unmd == 0.0) return;
		fprintf(mFile,"setAttr \".unmd\" %i;\n", unmd);

	}
	void setEqualizer(float dem)
	{
		if(dem == 1.0) return;
		fprintf(mFile,"setAttr \".dem\" %f;\n", dem);

	}
	void setEqualizerSamples(size_t ems_i,double ems)
	{
		if(ems == 0.0) return;
		fprintf(mFile,"setAttr \".ems[%i]\" %f;\n", ems_i,ems);

	}
	void setEqualizerMap(const string& emm)
	{
		if(emm == "n/a") return;
		fprintf(mFile,"setAttr \".emm\" -type \"string\" ");
		emm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEqualizerMapOffset(float emmo)
	{
		if(emmo == 0.0) return;
		fprintf(mFile,"setAttr \".emmo\" %f;\n", emmo);

	}
	void setEqualizerMapMult(float emmm)
	{
		if(emmm == 1.0) return;
		fprintf(mFile,"setAttr \".emmm\" %f;\n", emmm);

	}
	void setEqualizerNoise(float emn)
	{
		if(emn == 0.0) return;
		fprintf(mFile,"setAttr \".emn\" %f;\n", emn);

	}
	void setEqualizerNoiseFreq(float emnf)
	{
		if(emnf == 10.0) return;
		fprintf(mFile,"setAttr \".emnf\" %f;\n", emnf);

	}
	void setEqualizerSamplesDirty(int emsd)
	{
		if(emsd == 0.0) return;
		fprintf(mFile,"setAttr \".emsd\" %i;\n", emsd);

	}
	void setEqualizerMapDirty(int emmd)
	{
		if(emmd == 0.0) return;
		fprintf(mFile,"setAttr \".emmd\" %i;\n", emmd);

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
		if(mins == -2) return;
		fprintf(mFile,"setAttr \".mrc.mins\" %i;\n", mins);

	}
	void setMiMaxSamples(short maxs)
	{
		if(maxs == 0) return;
		fprintf(mFile,"setAttr \".mrc.maxs\" %i;\n", maxs);

	}
	void setMiFinalGatherCast(bool fgc)
	{
		if(fgc == true) return;
		fprintf(mFile,"setAttr \".mrc.fgc\" %i;\n", fgc);

	}
	void setMiFinalGatherReceive(bool fge)
	{
		if(fge == true) return;
		fprintf(mFile,"setAttr \".mrc.fge\" %i;\n", fge);

	}
	void setMiTransparencyCast(bool tpc)
	{
		if(tpc == true) return;
		fprintf(mFile,"setAttr \".mrc.tpc\" %i;\n", tpc);

	}
	void setMiTransparencyReceive(bool tpr)
	{
		if(tpr == true) return;
		fprintf(mFile,"setAttr \".mrc.tpr\" %i;\n", tpr);

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
	FurFeedback(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Locator(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURFEEDBACK_H__
