/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURDESCRIPTION_H__
#define __MayaDM_FURDESCRIPTION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class FurDescription : public DependNode
{
public:
	struct BaseColorMap{
	};
	struct BaseColorMapUSamples{
	};
	struct BaseColorMapVSamples{
	};
	struct TipColorMap{
	};
	struct TipColorMapUSamples{
	};
	struct TipColorMapVSamples{
	};
	struct BaseAmbientColorMap{
	};
	struct BaseAmbientColorMapUSamples{
	};
	struct BaseAmbientColorMapVSamples{
	};
	struct TipAmbientColorMap{
	};
	struct TipAmbientColorMapUSamples{
	};
	struct TipAmbientColorMapVSamples{
	};
	struct SpecularColorMap{
	};
	struct SpecularColorMapUSamples{
	};
	struct SpecularColorMapVSamples{
	};
	struct LengthMap{
	};
	struct LengthMapUSamples{
	};
	struct LengthMapVSamples{
	};
	struct SpecularSharpnessMap{
	};
	struct SpecularSharpnessMapUSamples{
	};
	struct SpecularSharpnessMapVSamples{
	};
	struct BaldnessMap{
	};
	struct BaldnessMapUSamples{
	};
	struct BaldnessMapVSamples{
	};
	struct BaseOpacityMap{
	};
	struct BaseOpacityMapUSamples{
	};
	struct BaseOpacityMapVSamples{
	};
	struct TipOpacityMap{
	};
	struct TipOpacityMapUSamples{
	};
	struct TipOpacityMapVSamples{
	};
	struct BaseWidthMap{
	};
	struct BaseWidthMapUSamples{
	};
	struct BaseWidthMapVSamples{
	};
	struct TipWidthMap{
	};
	struct TipWidthMapUSamples{
	};
	struct TipWidthMapVSamples{
	};
	struct SegmentsMap{
	};
	struct SegmentsMapUSamples{
	};
	struct SegmentsMapVSamples{
	};
	struct BaseCurlMap{
	};
	struct BaseCurlMapUSamples{
	};
	struct BaseCurlMapVSamples{
	};
	struct TipCurlMap{
	};
	struct TipCurlMapUSamples{
	};
	struct TipCurlMapVSamples{
	};
	struct ScraggleMap{
	};
	struct ScraggleMapUSamples{
	};
	struct ScraggleMapVSamples{
	};
	struct ScraggleFrequencyMap{
	};
	struct ScraggleFrequencyMapUSamples{
	};
	struct ScraggleFrequencyMapVSamples{
	};
	struct ScraggleCorrelationMap{
	};
	struct ScraggleCorrelationMapUSamples{
	};
	struct ScraggleCorrelationMapVSamples{
	};
	struct InclinationMap{
	};
	struct InclinationMapUSamples{
	};
	struct InclinationMapVSamples{
	};
	struct RollMap{
	};
	struct RollMapUSamples{
	};
	struct RollMapVSamples{
	};
	struct PolarMap{
	};
	struct PolarMapUSamples{
	};
	struct PolarMapVSamples{
	};
	struct AttractionMap{
	};
	struct AttractionMapUSamples{
	};
	struct AttractionMapVSamples{
	};
	struct OffsetMap{
	};
	struct OffsetMapUSamples{
	};
	struct OffsetMapVSamples{
	};
	struct ClumpingMap{
	};
	struct ClumpingMapUSamples{
	};
	struct ClumpingMapVSamples{
	};
	struct ClumpingFrequencyMap{
	};
	struct ClumpingFrequencyMapUSamples{
	};
	struct ClumpingFrequencyMapVSamples{
	};
	struct ClumpShapeMap{
	};
	struct ClumpShapeMapUSamples{
	};
	struct ClumpShapeMapVSamples{
	};
public:
	FurDescription(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "FurDescription"){}
	virtual ~FurDescription(){}
	void setLightModel(unsigned int lmd)
	{
		if(lmd == 2) return;
		fprintf(mFile,"setAttr \".lmd\" %i;\n", lmd);

	}
	void setDensity(int d)
	{
		if(d == 1000.0) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setGlobalScale(float gs)
	{
		if(gs == 1.0) return;
		fprintf(mFile,"setAttr \".gs\" %f;\n", gs);

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
	void setBaseAmbientColor(const float3& dbac)
	{
		if(dbac == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".dbac\" -type \"float3\" ");
		dbac.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBaseAmbientColorR(float dbacr)
	{
		if(dbacr == 0.0) return;
		fprintf(mFile,"setAttr \".dbacr\" %f;\n", dbacr);

	}
	void setBaseAmbientColorG(float dbacg)
	{
		if(dbacg == 0.0) return;
		fprintf(mFile,"setAttr \".dbacg\" %f;\n", dbacg);

	}
	void setBaseAmbientColorB(float dbacb)
	{
		if(dbacb == 0.0) return;
		fprintf(mFile,"setAttr \".dbacb\" %f;\n", dbacb);

	}
	void setBaseAmbientColorNoise(float bacn)
	{
		if(bacn == 0.0) return;
		fprintf(mFile,"setAttr \".bacn\" %f;\n", bacn);

	}
	void setBaseAmbientColorNoiseFreq(float bacnf)
	{
		if(bacnf == 10.0) return;
		fprintf(mFile,"setAttr \".bacnf\" %f;\n", bacnf);

	}
	void setTipAmbientColor(const float3& dtac)
	{
		if(dtac == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".dtac\" -type \"float3\" ");
		dtac.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTipAmbientColorR(float dtacr)
	{
		if(dtacr == 0.0) return;
		fprintf(mFile,"setAttr \".dtacr\" %f;\n", dtacr);

	}
	void setTipAmbientColorG(float dtacg)
	{
		if(dtacg == 0.0) return;
		fprintf(mFile,"setAttr \".dtacg\" %f;\n", dtacg);

	}
	void setTipAmbientColorB(float dtacb)
	{
		if(dtacb == 0.0) return;
		fprintf(mFile,"setAttr \".dtacb\" %f;\n", dtacb);

	}
	void setTipAmbientColorNoise(float tacn)
	{
		if(tacn == 0.0) return;
		fprintf(mFile,"setAttr \".tacn\" %f;\n", tacn);

	}
	void setTipAmbientColorNoiseFreq(float tacnf)
	{
		if(tacnf == 10.0) return;
		fprintf(mFile,"setAttr \".tacnf\" %f;\n", tacnf);

	}
	void setSpecularColor(const float3& dsc)
	{
		if(dsc == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"setAttr \".dsc\" -type \"float3\" ");
		dsc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpecularColorR(float dscr)
	{
		if(dscr == 0.5) return;
		fprintf(mFile,"setAttr \".dscr\" %f;\n", dscr);

	}
	void setSpecularColorG(float dscg)
	{
		if(dscg == 0.5) return;
		fprintf(mFile,"setAttr \".dscg\" %f;\n", dscg);

	}
	void setSpecularColorB(float dscb)
	{
		if(dscb == 0.5) return;
		fprintf(mFile,"setAttr \".dscb\" %f;\n", dscb);

	}
	void setSpecularColorNoise(float scn)
	{
		if(scn == 0.0) return;
		fprintf(mFile,"setAttr \".scn\" %f;\n", scn);

	}
	void setSpecularColorNoiseFreq(float scnf)
	{
		if(scnf == 10.0) return;
		fprintf(mFile,"setAttr \".scnf\" %f;\n", scnf);

	}
	void setLength(double dl)
	{
		if(dl == 1) return;
		fprintf(mFile,"setAttr \".dl\" %f;\n", dl);

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
	void setSpecularSharpness(double dss)
	{
		if(dss == 5) return;
		fprintf(mFile,"setAttr \".dss\" %f;\n", dss);

	}
	void setSpecularSharpnessMapOffset(double ssmo)
	{
		if(ssmo == 0) return;
		fprintf(mFile,"setAttr \".ssmo\" %f;\n", ssmo);

	}
	void setSpecularSharpnessMapMult(double ssmm)
	{
		if(ssmm == 1) return;
		fprintf(mFile,"setAttr \".ssmm\" %f;\n", ssmm);

	}
	void setSpecularSharpnessNoise(double ssn)
	{
		if(ssn == 0) return;
		fprintf(mFile,"setAttr \".ssn\" %f;\n", ssn);

	}
	void setSpecularSharpnessNoiseFreq(float ssnf)
	{
		if(ssnf == 10.0) return;
		fprintf(mFile,"setAttr \".ssnf\" %f;\n", ssnf);

	}
	void setBaldness(double db)
	{
		if(db == 1) return;
		fprintf(mFile,"setAttr \".db\" %f;\n", db);

	}
	void setBaldnessMapOffset(double bmo)
	{
		if(bmo == 0) return;
		fprintf(mFile,"setAttr \".bmo\" %f;\n", bmo);

	}
	void setBaldnessMapMult(double bmm)
	{
		if(bmm == 1) return;
		fprintf(mFile,"setAttr \".bmm\" %f;\n", bmm);

	}
	void setBaldnessNoise(double bn)
	{
		if(bn == 0) return;
		fprintf(mFile,"setAttr \".bn\" %f;\n", bn);

	}
	void setBaldnessNoiseFreq(float bnf)
	{
		if(bnf == 10.0) return;
		fprintf(mFile,"setAttr \".bnf\" %f;\n", bnf);

	}
	void setBaseOpacity(double dbo)
	{
		if(dbo == 1) return;
		fprintf(mFile,"setAttr \".dbo\" %f;\n", dbo);

	}
	void setBaseOpacityMapOffset(double bomo)
	{
		if(bomo == 0) return;
		fprintf(mFile,"setAttr \".bomo\" %f;\n", bomo);

	}
	void setBaseOpacityMapMult(double bomm)
	{
		if(bomm == 1) return;
		fprintf(mFile,"setAttr \".bomm\" %f;\n", bomm);

	}
	void setBaseOpacityNoise(double bon)
	{
		if(bon == 0) return;
		fprintf(mFile,"setAttr \".bon\" %f;\n", bon);

	}
	void setBaseOpacityNoiseFreq(float bonf)
	{
		if(bonf == 10.0) return;
		fprintf(mFile,"setAttr \".bonf\" %f;\n", bonf);

	}
	void setTipOpacity(double dto)
	{
		if(dto == 1) return;
		fprintf(mFile,"setAttr \".dto\" %f;\n", dto);

	}
	void setTipOpacityMapOffset(double tomo)
	{
		if(tomo == 0) return;
		fprintf(mFile,"setAttr \".tomo\" %f;\n", tomo);

	}
	void setTipOpacityMapMult(double tomm)
	{
		if(tomm == 1) return;
		fprintf(mFile,"setAttr \".tomm\" %f;\n", tomm);

	}
	void setTipOpacityNoise(double ton)
	{
		if(ton == 0) return;
		fprintf(mFile,"setAttr \".ton\" %f;\n", ton);

	}
	void setTipOpacityNoiseFreq(float tonf)
	{
		if(tonf == 10.0) return;
		fprintf(mFile,"setAttr \".tonf\" %f;\n", tonf);

	}
	void setBaseWidth(double dbw)
	{
		if(dbw == 0) return;
		fprintf(mFile,"setAttr \".dbw\" %f;\n", dbw);

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
	void setTipWidth(double dtw)
	{
		if(dtw == 0) return;
		fprintf(mFile,"setAttr \".dtw\" %f;\n", dtw);

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
	void setSegments(double dsg)
	{
		if(dsg == 1) return;
		fprintf(mFile,"setAttr \".dsg\" %f;\n", dsg);

	}
	void setSegmentsMapOffset(double sgmo)
	{
		if(sgmo == 0) return;
		fprintf(mFile,"setAttr \".sgmo\" %f;\n", sgmo);

	}
	void setSegmentsMapMult(double sgmm)
	{
		if(sgmm == 1) return;
		fprintf(mFile,"setAttr \".sgmm\" %f;\n", sgmm);

	}
	void setSegmentsNoise(double sgn)
	{
		if(sgn == 0) return;
		fprintf(mFile,"setAttr \".sgn\" %f;\n", sgn);

	}
	void setSegmentsNoiseFreq(float sgnf)
	{
		if(sgnf == 10.0) return;
		fprintf(mFile,"setAttr \".sgnf\" %f;\n", sgnf);

	}
	void setBaseCurl(double dbcl)
	{
		if(dbcl == 0) return;
		fprintf(mFile,"setAttr \".dbcl\" %f;\n", dbcl);

	}
	void setBaseCurlMapOffset(double bclmo)
	{
		if(bclmo == 0) return;
		fprintf(mFile,"setAttr \".bclmo\" %f;\n", bclmo);

	}
	void setBaseCurlMapMult(double bclmm)
	{
		if(bclmm == 1) return;
		fprintf(mFile,"setAttr \".bclmm\" %f;\n", bclmm);

	}
	void setBaseCurlNoise(double bcln)
	{
		if(bcln == 0) return;
		fprintf(mFile,"setAttr \".bcln\" %f;\n", bcln);

	}
	void setBaseCurlNoiseFreq(float bclnf)
	{
		if(bclnf == 10.0) return;
		fprintf(mFile,"setAttr \".bclnf\" %f;\n", bclnf);

	}
	void setTipCurl(double dtcl)
	{
		if(dtcl == 0) return;
		fprintf(mFile,"setAttr \".dtcl\" %f;\n", dtcl);

	}
	void setTipCurlMapOffset(double tclmo)
	{
		if(tclmo == 0) return;
		fprintf(mFile,"setAttr \".tclmo\" %f;\n", tclmo);

	}
	void setTipCurlMapMult(double tclmm)
	{
		if(tclmm == 1) return;
		fprintf(mFile,"setAttr \".tclmm\" %f;\n", tclmm);

	}
	void setTipCurlNoise(double tcln)
	{
		if(tcln == 0) return;
		fprintf(mFile,"setAttr \".tcln\" %f;\n", tcln);

	}
	void setTipCurlNoiseFreq(float tclnf)
	{
		if(tclnf == 10.0) return;
		fprintf(mFile,"setAttr \".tclnf\" %f;\n", tclnf);

	}
	void setScraggle(double ds)
	{
		if(ds == 0) return;
		fprintf(mFile,"setAttr \".ds\" %f;\n", ds);

	}
	void setScraggleMapOffset(double smo)
	{
		if(smo == 0) return;
		fprintf(mFile,"setAttr \".smo\" %f;\n", smo);

	}
	void setScraggleMapMult(double smm)
	{
		if(smm == 1) return;
		fprintf(mFile,"setAttr \".smm\" %f;\n", smm);

	}
	void setScraggleNoise(double sn)
	{
		if(sn == 0) return;
		fprintf(mFile,"setAttr \".sn\" %f;\n", sn);

	}
	void setScraggleNoiseFreq(float snf)
	{
		if(snf == 10.0) return;
		fprintf(mFile,"setAttr \".snf\" %f;\n", snf);

	}
	void setScraggleFrequency(double dsf)
	{
		if(dsf == 5) return;
		fprintf(mFile,"setAttr \".dsf\" %f;\n", dsf);

	}
	void setScraggleFrequencyMapOffset(double sfmo)
	{
		if(sfmo == 0) return;
		fprintf(mFile,"setAttr \".sfmo\" %f;\n", sfmo);

	}
	void setScraggleFrequencyMapMult(double sfmm)
	{
		if(sfmm == 1) return;
		fprintf(mFile,"setAttr \".sfmm\" %f;\n", sfmm);

	}
	void setScraggleFrequencyNoise(double sfn)
	{
		if(sfn == 0) return;
		fprintf(mFile,"setAttr \".sfn\" %f;\n", sfn);

	}
	void setScraggleFrequencyNoiseFreq(float sfnf)
	{
		if(sfnf == 10.0) return;
		fprintf(mFile,"setAttr \".sfnf\" %f;\n", sfnf);

	}
	void setScraggleCorrelation(double dsco)
	{
		if(dsco == 0) return;
		fprintf(mFile,"setAttr \".dsco\" %f;\n", dsco);

	}
	void setScraggleCorrelationMapOffset(double scomo)
	{
		if(scomo == 0) return;
		fprintf(mFile,"setAttr \".scomo\" %f;\n", scomo);

	}
	void setScraggleCorrelationMapMult(double scomm)
	{
		if(scomm == 1) return;
		fprintf(mFile,"setAttr \".scomm\" %f;\n", scomm);

	}
	void setScraggleCorrelationNoise(double scon)
	{
		if(scon == 0) return;
		fprintf(mFile,"setAttr \".scon\" %f;\n", scon);

	}
	void setScraggleCorrelationNoiseFreq(float sconf)
	{
		if(sconf == 10.0) return;
		fprintf(mFile,"setAttr \".sconf\" %f;\n", sconf);

	}
	void setInclination(double di)
	{
		if(di == 0) return;
		fprintf(mFile,"setAttr \".di\" %f;\n", di);

	}
	void setInclinationMapOffset(double imo)
	{
		if(imo == 0) return;
		fprintf(mFile,"setAttr \".imo\" %f;\n", imo);

	}
	void setInclinationMapMult(double imm)
	{
		if(imm == 1) return;
		fprintf(mFile,"setAttr \".imm\" %f;\n", imm);

	}
	void setInclinationNoise(double in)
	{
		if(in == 0) return;
		fprintf(mFile,"setAttr \".in\" %f;\n", in);

	}
	void setInclinationNoiseFreq(float inf)
	{
		if(inf == 10.0) return;
		fprintf(mFile,"setAttr \".inf\" %f;\n", inf);

	}
	void setRoll(double dr)
	{
		if(dr == 0) return;
		fprintf(mFile,"setAttr \".dr\" %f;\n", dr);

	}
	void setRollMapOffset(double rmo)
	{
		if(rmo == 0) return;
		fprintf(mFile,"setAttr \".rmo\" %f;\n", rmo);

	}
	void setRollMapMult(double rmm)
	{
		if(rmm == 1) return;
		fprintf(mFile,"setAttr \".rmm\" %f;\n", rmm);

	}
	void setRollNoise(double rn)
	{
		if(rn == 0) return;
		fprintf(mFile,"setAttr \".rn\" %f;\n", rn);

	}
	void setRollNoiseFreq(float rnf)
	{
		if(rnf == 10.0) return;
		fprintf(mFile,"setAttr \".rnf\" %f;\n", rnf);

	}
	void setPolar(double dp)
	{
		if(dp == 0) return;
		fprintf(mFile,"setAttr \".dp\" %f;\n", dp);

	}
	void setPolarMapOffset(double pmo)
	{
		if(pmo == 0) return;
		fprintf(mFile,"setAttr \".pmo\" %f;\n", pmo);

	}
	void setPolarMapMult(double pmm)
	{
		if(pmm == 1) return;
		fprintf(mFile,"setAttr \".pmm\" %f;\n", pmm);

	}
	void setPolarNoise(double pn)
	{
		if(pn == 0) return;
		fprintf(mFile,"setAttr \".pn\" %f;\n", pn);

	}
	void setPolarNoiseFreq(float pnf)
	{
		if(pnf == 10.0) return;
		fprintf(mFile,"setAttr \".pnf\" %f;\n", pnf);

	}
	void setAttraction(double dat)
	{
		if(dat == 1) return;
		fprintf(mFile,"setAttr \".dat\" %f;\n", dat);

	}
	void setAttractionMapOffset(double atmo)
	{
		if(atmo == 0) return;
		fprintf(mFile,"setAttr \".atmo\" %f;\n", atmo);

	}
	void setAttractionMapMult(double atmm)
	{
		if(atmm == 1) return;
		fprintf(mFile,"setAttr \".atmm\" %f;\n", atmm);

	}
	void setAttractionNoise(double atn)
	{
		if(atn == 0) return;
		fprintf(mFile,"setAttr \".atn\" %f;\n", atn);

	}
	void setAttractionNoiseFreq(float atnf)
	{
		if(atnf == 10.0) return;
		fprintf(mFile,"setAttr \".atnf\" %f;\n", atnf);

	}
	void setOffset(double dofs)
	{
		if(dofs == 0) return;
		fprintf(mFile,"setAttr \".dofs\" %f;\n", dofs);

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
	void setClumping(float dc)
	{
		if(dc == 0.0) return;
		fprintf(mFile,"setAttr \".dc\" %f;\n", dc);

	}
	void setClumpingMapOffset(float cmo)
	{
		if(cmo == 0.0) return;
		fprintf(mFile,"setAttr \".cmo\" %f;\n", cmo);

	}
	void setClumpingMapMult(float cmm)
	{
		if(cmm == 1.0) return;
		fprintf(mFile,"setAttr \".cmm\" %f;\n", cmm);

	}
	void setClumpingNoise(float cn)
	{
		if(cn == 0.0) return;
		fprintf(mFile,"setAttr \".cn\" %f;\n", cn);

	}
	void setClumpingNoiseFreq(float cnf)
	{
		if(cnf == 10.0) return;
		fprintf(mFile,"setAttr \".cnf\" %f;\n", cnf);

	}
	void setClumpingFrequency(float dcf)
	{
		if(dcf == 50) return;
		fprintf(mFile,"setAttr \".dcf\" %f;\n", dcf);

	}
	void setClumpingFrequencyMapOffset(float cfmo)
	{
		if(cfmo == 0.0) return;
		fprintf(mFile,"setAttr \".cfmo\" %f;\n", cfmo);

	}
	void setClumpingFrequencyMapMult(float cfmm)
	{
		if(cfmm == 1.0) return;
		fprintf(mFile,"setAttr \".cfmm\" %f;\n", cfmm);

	}
	void setClumpingFrequencyNoise(float cfn)
	{
		if(cfn == 0.0) return;
		fprintf(mFile,"setAttr \".cfn\" %f;\n", cfn);

	}
	void setClumpingFrequencyNoiseFreq(float cfnf)
	{
		if(cfnf == 10.0) return;
		fprintf(mFile,"setAttr \".cfnf\" %f;\n", cfnf);

	}
	void setClumpShape(float dcs)
	{
		if(dcs == 0.0) return;
		fprintf(mFile,"setAttr \".dcs\" %f;\n", dcs);

	}
	void setClumpShapeMapOffset(float csmo)
	{
		if(csmo == 0.0) return;
		fprintf(mFile,"setAttr \".csmo\" %f;\n", csmo);

	}
	void setClumpShapeMapMult(float csmm)
	{
		if(csmm == 1.0) return;
		fprintf(mFile,"setAttr \".csmm\" %f;\n", csmm);

	}
	void setClumpShapeNoise(float csn)
	{
		if(csn == 0.0) return;
		fprintf(mFile,"setAttr \".csn\" %f;\n", csn);

	}
	void setClumpShapeNoiseFreq(float csnf)
	{
		if(csnf == 10.0) return;
		fprintf(mFile,"setAttr \".csnf\" %f;\n", csnf);

	}
	void getLightModel()
	{
		fprintf(mFile,"\"%s.lmd\"",mName.c_str());

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
	void getBaseColorMapUSamples()
	{
		fprintf(mFile,"\"%s.bcmus\"",mName.c_str());

	}
	void getBaseColorMapVSamples()
	{
		fprintf(mFile,"\"%s.bcmvs\"",mName.c_str());

	}
	void getBaseColorNoise()
	{
		fprintf(mFile,"\"%s.bcn\"",mName.c_str());

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
	void getTipColorMapUSamples()
	{
		fprintf(mFile,"\"%s.tcmus\"",mName.c_str());

	}
	void getTipColorMapVSamples()
	{
		fprintf(mFile,"\"%s.tcmvs\"",mName.c_str());

	}
	void getTipColorNoise()
	{
		fprintf(mFile,"\"%s.tcn\"",mName.c_str());

	}
	void getBaseAmbientColor()
	{
		fprintf(mFile,"\"%s.dbac\"",mName.c_str());

	}
	void getBaseAmbientColorR()
	{
		fprintf(mFile,"\"%s.dbacr\"",mName.c_str());

	}
	void getBaseAmbientColorG()
	{
		fprintf(mFile,"\"%s.dbacg\"",mName.c_str());

	}
	void getBaseAmbientColorB()
	{
		fprintf(mFile,"\"%s.dbacb\"",mName.c_str());

	}
	void getBaseAmbientColorMapUSamples()
	{
		fprintf(mFile,"\"%s.bacmus\"",mName.c_str());

	}
	void getBaseAmbientColorMapVSamples()
	{
		fprintf(mFile,"\"%s.bacmvs\"",mName.c_str());

	}
	void getBaseAmbientColorNoise()
	{
		fprintf(mFile,"\"%s.bacn\"",mName.c_str());

	}
	void getTipAmbientColor()
	{
		fprintf(mFile,"\"%s.dtac\"",mName.c_str());

	}
	void getTipAmbientColorR()
	{
		fprintf(mFile,"\"%s.dtacr\"",mName.c_str());

	}
	void getTipAmbientColorG()
	{
		fprintf(mFile,"\"%s.dtacg\"",mName.c_str());

	}
	void getTipAmbientColorB()
	{
		fprintf(mFile,"\"%s.dtacb\"",mName.c_str());

	}
	void getTipAmbientColorMapUSamples()
	{
		fprintf(mFile,"\"%s.tacmus\"",mName.c_str());

	}
	void getTipAmbientColorMapVSamples()
	{
		fprintf(mFile,"\"%s.tacmvs\"",mName.c_str());

	}
	void getTipAmbientColorNoise()
	{
		fprintf(mFile,"\"%s.tacn\"",mName.c_str());

	}
	void getSpecularColor()
	{
		fprintf(mFile,"\"%s.dsc\"",mName.c_str());

	}
	void getSpecularColorR()
	{
		fprintf(mFile,"\"%s.dscr\"",mName.c_str());

	}
	void getSpecularColorG()
	{
		fprintf(mFile,"\"%s.dscg\"",mName.c_str());

	}
	void getSpecularColorB()
	{
		fprintf(mFile,"\"%s.dscb\"",mName.c_str());

	}
	void getSpecularColorMapUSamples()
	{
		fprintf(mFile,"\"%s.scmus\"",mName.c_str());

	}
	void getSpecularColorMapVSamples()
	{
		fprintf(mFile,"\"%s.scmvs\"",mName.c_str());

	}
	void getSpecularColorNoise()
	{
		fprintf(mFile,"\"%s.scn\"",mName.c_str());

	}
	void getLength()
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());

	}
	void getLengthMapUSamples()
	{
		fprintf(mFile,"\"%s.lmus\"",mName.c_str());

	}
	void getLengthMapVSamples()
	{
		fprintf(mFile,"\"%s.lmvs\"",mName.c_str());

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
	void getSpecularSharpness()
	{
		fprintf(mFile,"\"%s.dss\"",mName.c_str());

	}
	void getSpecularSharpnessMapUSamples()
	{
		fprintf(mFile,"\"%s.ssmus\"",mName.c_str());

	}
	void getSpecularSharpnessMapVSamples()
	{
		fprintf(mFile,"\"%s.ssmvs\"",mName.c_str());

	}
	void getSpecularSharpnessMapOffset()
	{
		fprintf(mFile,"\"%s.ssmo\"",mName.c_str());

	}
	void getSpecularSharpnessMapMult()
	{
		fprintf(mFile,"\"%s.ssmm\"",mName.c_str());

	}
	void getSpecularSharpnessNoise()
	{
		fprintf(mFile,"\"%s.ssn\"",mName.c_str());

	}
	void getBaldness()
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());

	}
	void getBaldnessMapUSamples()
	{
		fprintf(mFile,"\"%s.bmus\"",mName.c_str());

	}
	void getBaldnessMapVSamples()
	{
		fprintf(mFile,"\"%s.bmvs\"",mName.c_str());

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
	void getBaseOpacity()
	{
		fprintf(mFile,"\"%s.dbo\"",mName.c_str());

	}
	void getBaseOpacityMapUSamples()
	{
		fprintf(mFile,"\"%s.bomus\"",mName.c_str());

	}
	void getBaseOpacityMapVSamples()
	{
		fprintf(mFile,"\"%s.bomvs\"",mName.c_str());

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
	void getTipOpacity()
	{
		fprintf(mFile,"\"%s.dto\"",mName.c_str());

	}
	void getTipOpacityMapUSamples()
	{
		fprintf(mFile,"\"%s.tomus\"",mName.c_str());

	}
	void getTipOpacityMapVSamples()
	{
		fprintf(mFile,"\"%s.tomvs\"",mName.c_str());

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
	void getBaseWidth()
	{
		fprintf(mFile,"\"%s.dbw\"",mName.c_str());

	}
	void getBaseWidthMapUSamples()
	{
		fprintf(mFile,"\"%s.bwmus\"",mName.c_str());

	}
	void getBaseWidthMapVSamples()
	{
		fprintf(mFile,"\"%s.bwmvs\"",mName.c_str());

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
	void getTipWidth()
	{
		fprintf(mFile,"\"%s.dtw\"",mName.c_str());

	}
	void getTipWidthMapUSamples()
	{
		fprintf(mFile,"\"%s.twmus\"",mName.c_str());

	}
	void getTipWidthMapVSamples()
	{
		fprintf(mFile,"\"%s.twmvs\"",mName.c_str());

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
	void getSegments()
	{
		fprintf(mFile,"\"%s.dsg\"",mName.c_str());

	}
	void getSegmentsMapUSamples()
	{
		fprintf(mFile,"\"%s.sgmus\"",mName.c_str());

	}
	void getSegmentsMapVSamples()
	{
		fprintf(mFile,"\"%s.sgmvs\"",mName.c_str());

	}
	void getSegmentsMapOffset()
	{
		fprintf(mFile,"\"%s.sgmo\"",mName.c_str());

	}
	void getSegmentsMapMult()
	{
		fprintf(mFile,"\"%s.sgmm\"",mName.c_str());

	}
	void getSegmentsNoise()
	{
		fprintf(mFile,"\"%s.sgn\"",mName.c_str());

	}
	void getBaseCurl()
	{
		fprintf(mFile,"\"%s.dbcl\"",mName.c_str());

	}
	void getBaseCurlMapUSamples()
	{
		fprintf(mFile,"\"%s.bclmus\"",mName.c_str());

	}
	void getBaseCurlMapVSamples()
	{
		fprintf(mFile,"\"%s.bclmvs\"",mName.c_str());

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
	void getTipCurl()
	{
		fprintf(mFile,"\"%s.dtcl\"",mName.c_str());

	}
	void getTipCurlMapUSamples()
	{
		fprintf(mFile,"\"%s.tclmus\"",mName.c_str());

	}
	void getTipCurlMapVSamples()
	{
		fprintf(mFile,"\"%s.tclmvs\"",mName.c_str());

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
	void getScraggle()
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());

	}
	void getScraggleMapUSamples()
	{
		fprintf(mFile,"\"%s.smus\"",mName.c_str());

	}
	void getScraggleMapVSamples()
	{
		fprintf(mFile,"\"%s.smvs\"",mName.c_str());

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
	void getScraggleFrequency()
	{
		fprintf(mFile,"\"%s.dsf\"",mName.c_str());

	}
	void getScraggleFrequencyMapUSamples()
	{
		fprintf(mFile,"\"%s.sfmus\"",mName.c_str());

	}
	void getScraggleFrequencyMapVSamples()
	{
		fprintf(mFile,"\"%s.sfmvs\"",mName.c_str());

	}
	void getScraggleFrequencyMapOffset()
	{
		fprintf(mFile,"\"%s.sfmo\"",mName.c_str());

	}
	void getScraggleFrequencyMapMult()
	{
		fprintf(mFile,"\"%s.sfmm\"",mName.c_str());

	}
	void getScraggleFrequencyNoise()
	{
		fprintf(mFile,"\"%s.sfn\"",mName.c_str());

	}
	void getScraggleCorrelation()
	{
		fprintf(mFile,"\"%s.dsco\"",mName.c_str());

	}
	void getScraggleCorrelationMapUSamples()
	{
		fprintf(mFile,"\"%s.scomus\"",mName.c_str());

	}
	void getScraggleCorrelationMapVSamples()
	{
		fprintf(mFile,"\"%s.scomvs\"",mName.c_str());

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
	void getInclination()
	{
		fprintf(mFile,"\"%s.di\"",mName.c_str());

	}
	void getInclinationMapUSamples()
	{
		fprintf(mFile,"\"%s.imus\"",mName.c_str());

	}
	void getInclinationMapVSamples()
	{
		fprintf(mFile,"\"%s.imvs\"",mName.c_str());

	}
	void getInclinationMapOffset()
	{
		fprintf(mFile,"\"%s.imo\"",mName.c_str());

	}
	void getInclinationMapMult()
	{
		fprintf(mFile,"\"%s.imm\"",mName.c_str());

	}
	void getInclinationNoise()
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());

	}
	void getRoll()
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());

	}
	void getRollMapUSamples()
	{
		fprintf(mFile,"\"%s.rmus\"",mName.c_str());

	}
	void getRollMapVSamples()
	{
		fprintf(mFile,"\"%s.rmvs\"",mName.c_str());

	}
	void getRollMapOffset()
	{
		fprintf(mFile,"\"%s.rmo\"",mName.c_str());

	}
	void getRollMapMult()
	{
		fprintf(mFile,"\"%s.rmm\"",mName.c_str());

	}
	void getRollNoise()
	{
		fprintf(mFile,"\"%s.rn\"",mName.c_str());

	}
	void getPolar()
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());

	}
	void getPolarMapUSamples()
	{
		fprintf(mFile,"\"%s.pmus\"",mName.c_str());

	}
	void getPolarMapVSamples()
	{
		fprintf(mFile,"\"%s.pmvs\"",mName.c_str());

	}
	void getPolarMapOffset()
	{
		fprintf(mFile,"\"%s.pmo\"",mName.c_str());

	}
	void getPolarMapMult()
	{
		fprintf(mFile,"\"%s.pmm\"",mName.c_str());

	}
	void getPolarNoise()
	{
		fprintf(mFile,"\"%s.pn\"",mName.c_str());

	}
	void getAttraction()
	{
		fprintf(mFile,"\"%s.dat\"",mName.c_str());

	}
	void getAttractionMapUSamples()
	{
		fprintf(mFile,"\"%s.atmus\"",mName.c_str());

	}
	void getAttractionMapVSamples()
	{
		fprintf(mFile,"\"%s.atmvs\"",mName.c_str());

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
	void getOffset()
	{
		fprintf(mFile,"\"%s.dofs\"",mName.c_str());

	}
	void getOffsetMapUSamples()
	{
		fprintf(mFile,"\"%s.ofsmus\"",mName.c_str());

	}
	void getOffsetMapVSamples()
	{
		fprintf(mFile,"\"%s.ofsmvs\"",mName.c_str());

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
	void getClumping()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getClumpingMapUSamples()
	{
		fprintf(mFile,"\"%s.cmus\"",mName.c_str());

	}
	void getClumpingMapVSamples()
	{
		fprintf(mFile,"\"%s.cmvs\"",mName.c_str());

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
	void getClumpingFrequency()
	{
		fprintf(mFile,"\"%s.dcf\"",mName.c_str());

	}
	void getClumpingFrequencyMapUSamples()
	{
		fprintf(mFile,"\"%s.cfmus\"",mName.c_str());

	}
	void getClumpingFrequencyMapVSamples()
	{
		fprintf(mFile,"\"%s.cfmvs\"",mName.c_str());

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
	void getClumpShape()
	{
		fprintf(mFile,"\"%s.dcs\"",mName.c_str());

	}
	void getClumpShapeMapUSamples()
	{
		fprintf(mFile,"\"%s.csmus\"",mName.c_str());

	}
	void getClumpShapeMapVSamples()
	{
		fprintf(mFile,"\"%s.csmvs\"",mName.c_str());

	}
	void getClumpShapeMapOffset()
	{
		fprintf(mFile,"\"%s.csmo\"",mName.c_str());

	}
	void getClumpShapeMapMult()
	{
		fprintf(mFile,"\"%s.csmm\"",mName.c_str());

	}
	void getClumpShapeNoise()
	{
		fprintf(mFile,"\"%s.csn\"",mName.c_str());

	}
protected:
	FurDescription(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURDESCRIPTION_H__
