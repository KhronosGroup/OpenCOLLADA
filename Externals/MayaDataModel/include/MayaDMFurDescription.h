/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	FurDescription():DependNode(){}
	FurDescription(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "FurDescription", shared, create){}
	virtual ~FurDescription(){}

	void setLightModel(unsigned int lmd)
	{
		if(lmd == 2) return;
		fprintf(mFile,"\tsetAttr \".lmd\" %i;\n", lmd);
	}
	void setDensity(int d)
	{
		if(d == 1000.0) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setGlobalScale(float gs)
	{
		if(gs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gs\" %f;\n", gs);
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
	void setBaseAmbientColor(const float3& dbac)
	{
		if(dbac == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".dbac\" -type \"float3\" ");
		dbac.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBaseAmbientColorR(float dbacr)
	{
		if(dbacr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dbacr\" %f;\n", dbacr);
	}
	void setBaseAmbientColorG(float dbacg)
	{
		if(dbacg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dbacg\" %f;\n", dbacg);
	}
	void setBaseAmbientColorB(float dbacb)
	{
		if(dbacb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dbacb\" %f;\n", dbacb);
	}
	void setBaseAmbientColorNoise(float bacn)
	{
		if(bacn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bacn\" %f;\n", bacn);
	}
	void setBaseAmbientColorNoiseFreq(float bacnf)
	{
		if(bacnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".bacnf\" %f;\n", bacnf);
	}
	void setTipAmbientColor(const float3& dtac)
	{
		if(dtac == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".dtac\" -type \"float3\" ");
		dtac.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTipAmbientColorR(float dtacr)
	{
		if(dtacr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtacr\" %f;\n", dtacr);
	}
	void setTipAmbientColorG(float dtacg)
	{
		if(dtacg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtacg\" %f;\n", dtacg);
	}
	void setTipAmbientColorB(float dtacb)
	{
		if(dtacb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtacb\" %f;\n", dtacb);
	}
	void setTipAmbientColorNoise(float tacn)
	{
		if(tacn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tacn\" %f;\n", tacn);
	}
	void setTipAmbientColorNoiseFreq(float tacnf)
	{
		if(tacnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".tacnf\" %f;\n", tacnf);
	}
	void setSpecularColor(const float3& dsc)
	{
		if(dsc == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".dsc\" -type \"float3\" ");
		dsc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpecularColorR(float dscr)
	{
		if(dscr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".dscr\" %f;\n", dscr);
	}
	void setSpecularColorG(float dscg)
	{
		if(dscg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".dscg\" %f;\n", dscg);
	}
	void setSpecularColorB(float dscb)
	{
		if(dscb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".dscb\" %f;\n", dscb);
	}
	void setSpecularColorNoise(float scn)
	{
		if(scn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scn\" %f;\n", scn);
	}
	void setSpecularColorNoiseFreq(float scnf)
	{
		if(scnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".scnf\" %f;\n", scnf);
	}
	void setLength(double dl)
	{
		if(dl == 1) return;
		fprintf(mFile,"\tsetAttr \".dl\" %f;\n", dl);
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
	void setSpecularSharpness(double dss)
	{
		if(dss == 5) return;
		fprintf(mFile,"\tsetAttr \".dss\" %f;\n", dss);
	}
	void setSpecularSharpnessMapOffset(double ssmo)
	{
		if(ssmo == 0) return;
		fprintf(mFile,"\tsetAttr \".ssmo\" %f;\n", ssmo);
	}
	void setSpecularSharpnessMapMult(double ssmm)
	{
		if(ssmm == 1) return;
		fprintf(mFile,"\tsetAttr \".ssmm\" %f;\n", ssmm);
	}
	void setSpecularSharpnessNoise(double ssn)
	{
		if(ssn == 0) return;
		fprintf(mFile,"\tsetAttr \".ssn\" %f;\n", ssn);
	}
	void setSpecularSharpnessNoiseFreq(float ssnf)
	{
		if(ssnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".ssnf\" %f;\n", ssnf);
	}
	void setBaldness(double db)
	{
		if(db == 1) return;
		fprintf(mFile,"\tsetAttr \".db\" %f;\n", db);
	}
	void setBaldnessMapOffset(double bmo)
	{
		if(bmo == 0) return;
		fprintf(mFile,"\tsetAttr \".bmo\" %f;\n", bmo);
	}
	void setBaldnessMapMult(double bmm)
	{
		if(bmm == 1) return;
		fprintf(mFile,"\tsetAttr \".bmm\" %f;\n", bmm);
	}
	void setBaldnessNoise(double bn)
	{
		if(bn == 0) return;
		fprintf(mFile,"\tsetAttr \".bn\" %f;\n", bn);
	}
	void setBaldnessNoiseFreq(float bnf)
	{
		if(bnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".bnf\" %f;\n", bnf);
	}
	void setBaseOpacity(double dbo)
	{
		if(dbo == 1) return;
		fprintf(mFile,"\tsetAttr \".dbo\" %f;\n", dbo);
	}
	void setBaseOpacityMapOffset(double bomo)
	{
		if(bomo == 0) return;
		fprintf(mFile,"\tsetAttr \".bomo\" %f;\n", bomo);
	}
	void setBaseOpacityMapMult(double bomm)
	{
		if(bomm == 1) return;
		fprintf(mFile,"\tsetAttr \".bomm\" %f;\n", bomm);
	}
	void setBaseOpacityNoise(double bon)
	{
		if(bon == 0) return;
		fprintf(mFile,"\tsetAttr \".bon\" %f;\n", bon);
	}
	void setBaseOpacityNoiseFreq(float bonf)
	{
		if(bonf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".bonf\" %f;\n", bonf);
	}
	void setTipOpacity(double dto)
	{
		if(dto == 1) return;
		fprintf(mFile,"\tsetAttr \".dto\" %f;\n", dto);
	}
	void setTipOpacityMapOffset(double tomo)
	{
		if(tomo == 0) return;
		fprintf(mFile,"\tsetAttr \".tomo\" %f;\n", tomo);
	}
	void setTipOpacityMapMult(double tomm)
	{
		if(tomm == 1) return;
		fprintf(mFile,"\tsetAttr \".tomm\" %f;\n", tomm);
	}
	void setTipOpacityNoise(double ton)
	{
		if(ton == 0) return;
		fprintf(mFile,"\tsetAttr \".ton\" %f;\n", ton);
	}
	void setTipOpacityNoiseFreq(float tonf)
	{
		if(tonf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".tonf\" %f;\n", tonf);
	}
	void setBaseWidth(double dbw)
	{
		if(dbw == 0) return;
		fprintf(mFile,"\tsetAttr \".dbw\" %f;\n", dbw);
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
	void setTipWidth(double dtw)
	{
		if(dtw == 0) return;
		fprintf(mFile,"\tsetAttr \".dtw\" %f;\n", dtw);
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
	void setSegments(double dsg)
	{
		if(dsg == 1) return;
		fprintf(mFile,"\tsetAttr \".dsg\" %f;\n", dsg);
	}
	void setSegmentsMapOffset(double sgmo)
	{
		if(sgmo == 0) return;
		fprintf(mFile,"\tsetAttr \".sgmo\" %f;\n", sgmo);
	}
	void setSegmentsMapMult(double sgmm)
	{
		if(sgmm == 1) return;
		fprintf(mFile,"\tsetAttr \".sgmm\" %f;\n", sgmm);
	}
	void setSegmentsNoise(double sgn)
	{
		if(sgn == 0) return;
		fprintf(mFile,"\tsetAttr \".sgn\" %f;\n", sgn);
	}
	void setSegmentsNoiseFreq(float sgnf)
	{
		if(sgnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".sgnf\" %f;\n", sgnf);
	}
	void setBaseCurl(double dbcl)
	{
		if(dbcl == 0) return;
		fprintf(mFile,"\tsetAttr \".dbcl\" %f;\n", dbcl);
	}
	void setBaseCurlMapOffset(double bclmo)
	{
		if(bclmo == 0) return;
		fprintf(mFile,"\tsetAttr \".bclmo\" %f;\n", bclmo);
	}
	void setBaseCurlMapMult(double bclmm)
	{
		if(bclmm == 1) return;
		fprintf(mFile,"\tsetAttr \".bclmm\" %f;\n", bclmm);
	}
	void setBaseCurlNoise(double bcln)
	{
		if(bcln == 0) return;
		fprintf(mFile,"\tsetAttr \".bcln\" %f;\n", bcln);
	}
	void setBaseCurlNoiseFreq(float bclnf)
	{
		if(bclnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".bclnf\" %f;\n", bclnf);
	}
	void setTipCurl(double dtcl)
	{
		if(dtcl == 0) return;
		fprintf(mFile,"\tsetAttr \".dtcl\" %f;\n", dtcl);
	}
	void setTipCurlMapOffset(double tclmo)
	{
		if(tclmo == 0) return;
		fprintf(mFile,"\tsetAttr \".tclmo\" %f;\n", tclmo);
	}
	void setTipCurlMapMult(double tclmm)
	{
		if(tclmm == 1) return;
		fprintf(mFile,"\tsetAttr \".tclmm\" %f;\n", tclmm);
	}
	void setTipCurlNoise(double tcln)
	{
		if(tcln == 0) return;
		fprintf(mFile,"\tsetAttr \".tcln\" %f;\n", tcln);
	}
	void setTipCurlNoiseFreq(float tclnf)
	{
		if(tclnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".tclnf\" %f;\n", tclnf);
	}
	void setScraggle(double ds)
	{
		if(ds == 0) return;
		fprintf(mFile,"\tsetAttr \".ds\" %f;\n", ds);
	}
	void setScraggleMapOffset(double smo)
	{
		if(smo == 0) return;
		fprintf(mFile,"\tsetAttr \".smo\" %f;\n", smo);
	}
	void setScraggleMapMult(double smm)
	{
		if(smm == 1) return;
		fprintf(mFile,"\tsetAttr \".smm\" %f;\n", smm);
	}
	void setScraggleNoise(double sn)
	{
		if(sn == 0) return;
		fprintf(mFile,"\tsetAttr \".sn\" %f;\n", sn);
	}
	void setScraggleNoiseFreq(float snf)
	{
		if(snf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".snf\" %f;\n", snf);
	}
	void setScraggleFrequency(double dsf)
	{
		if(dsf == 5) return;
		fprintf(mFile,"\tsetAttr \".dsf\" %f;\n", dsf);
	}
	void setScraggleFrequencyMapOffset(double sfmo)
	{
		if(sfmo == 0) return;
		fprintf(mFile,"\tsetAttr \".sfmo\" %f;\n", sfmo);
	}
	void setScraggleFrequencyMapMult(double sfmm)
	{
		if(sfmm == 1) return;
		fprintf(mFile,"\tsetAttr \".sfmm\" %f;\n", sfmm);
	}
	void setScraggleFrequencyNoise(double sfn)
	{
		if(sfn == 0) return;
		fprintf(mFile,"\tsetAttr \".sfn\" %f;\n", sfn);
	}
	void setScraggleFrequencyNoiseFreq(float sfnf)
	{
		if(sfnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".sfnf\" %f;\n", sfnf);
	}
	void setScraggleCorrelation(double dsco)
	{
		if(dsco == 0) return;
		fprintf(mFile,"\tsetAttr \".dsco\" %f;\n", dsco);
	}
	void setScraggleCorrelationMapOffset(double scomo)
	{
		if(scomo == 0) return;
		fprintf(mFile,"\tsetAttr \".scomo\" %f;\n", scomo);
	}
	void setScraggleCorrelationMapMult(double scomm)
	{
		if(scomm == 1) return;
		fprintf(mFile,"\tsetAttr \".scomm\" %f;\n", scomm);
	}
	void setScraggleCorrelationNoise(double scon)
	{
		if(scon == 0) return;
		fprintf(mFile,"\tsetAttr \".scon\" %f;\n", scon);
	}
	void setScraggleCorrelationNoiseFreq(float sconf)
	{
		if(sconf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".sconf\" %f;\n", sconf);
	}
	void setInclination(double di)
	{
		if(di == 0) return;
		fprintf(mFile,"\tsetAttr \".di\" %f;\n", di);
	}
	void setInclinationMapOffset(double imo)
	{
		if(imo == 0) return;
		fprintf(mFile,"\tsetAttr \".imo\" %f;\n", imo);
	}
	void setInclinationMapMult(double imm)
	{
		if(imm == 1) return;
		fprintf(mFile,"\tsetAttr \".imm\" %f;\n", imm);
	}
	void setInclinationNoise(double in)
	{
		if(in == 0) return;
		fprintf(mFile,"\tsetAttr \".in\" %f;\n", in);
	}
	void setInclinationNoiseFreq(float inf)
	{
		if(inf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".inf\" %f;\n", inf);
	}
	void setRoll(double dr)
	{
		if(dr == 0) return;
		fprintf(mFile,"\tsetAttr \".dr\" %f;\n", dr);
	}
	void setRollMapOffset(double rmo)
	{
		if(rmo == 0) return;
		fprintf(mFile,"\tsetAttr \".rmo\" %f;\n", rmo);
	}
	void setRollMapMult(double rmm)
	{
		if(rmm == 1) return;
		fprintf(mFile,"\tsetAttr \".rmm\" %f;\n", rmm);
	}
	void setRollNoise(double rn)
	{
		if(rn == 0) return;
		fprintf(mFile,"\tsetAttr \".rn\" %f;\n", rn);
	}
	void setRollNoiseFreq(float rnf)
	{
		if(rnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".rnf\" %f;\n", rnf);
	}
	void setPolar(double dp)
	{
		if(dp == 0) return;
		fprintf(mFile,"\tsetAttr \".dp\" %f;\n", dp);
	}
	void setPolarMapOffset(double pmo)
	{
		if(pmo == 0) return;
		fprintf(mFile,"\tsetAttr \".pmo\" %f;\n", pmo);
	}
	void setPolarMapMult(double pmm)
	{
		if(pmm == 1) return;
		fprintf(mFile,"\tsetAttr \".pmm\" %f;\n", pmm);
	}
	void setPolarNoise(double pn)
	{
		if(pn == 0) return;
		fprintf(mFile,"\tsetAttr \".pn\" %f;\n", pn);
	}
	void setPolarNoiseFreq(float pnf)
	{
		if(pnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".pnf\" %f;\n", pnf);
	}
	void setAttraction(double dat)
	{
		if(dat == 1) return;
		fprintf(mFile,"\tsetAttr \".dat\" %f;\n", dat);
	}
	void setAttractionMapOffset(double atmo)
	{
		if(atmo == 0) return;
		fprintf(mFile,"\tsetAttr \".atmo\" %f;\n", atmo);
	}
	void setAttractionMapMult(double atmm)
	{
		if(atmm == 1) return;
		fprintf(mFile,"\tsetAttr \".atmm\" %f;\n", atmm);
	}
	void setAttractionNoise(double atn)
	{
		if(atn == 0) return;
		fprintf(mFile,"\tsetAttr \".atn\" %f;\n", atn);
	}
	void setAttractionNoiseFreq(float atnf)
	{
		if(atnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".atnf\" %f;\n", atnf);
	}
	void setOffset(double dofs)
	{
		if(dofs == 0) return;
		fprintf(mFile,"\tsetAttr \".dofs\" %f;\n", dofs);
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
	void setClumping(float dc)
	{
		if(dc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dc\" %f;\n", dc);
	}
	void setClumpingMapOffset(float cmo)
	{
		if(cmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cmo\" %f;\n", cmo);
	}
	void setClumpingMapMult(float cmm)
	{
		if(cmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cmm\" %f;\n", cmm);
	}
	void setClumpingNoise(float cn)
	{
		if(cn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cn\" %f;\n", cn);
	}
	void setClumpingNoiseFreq(float cnf)
	{
		if(cnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".cnf\" %f;\n", cnf);
	}
	void setClumpingFrequency(float dcf)
	{
		if(dcf == 50) return;
		fprintf(mFile,"\tsetAttr \".dcf\" %f;\n", dcf);
	}
	void setClumpingFrequencyMapOffset(float cfmo)
	{
		if(cfmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfmo\" %f;\n", cfmo);
	}
	void setClumpingFrequencyMapMult(float cfmm)
	{
		if(cfmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cfmm\" %f;\n", cfmm);
	}
	void setClumpingFrequencyNoise(float cfn)
	{
		if(cfn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfn\" %f;\n", cfn);
	}
	void setClumpingFrequencyNoiseFreq(float cfnf)
	{
		if(cfnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".cfnf\" %f;\n", cfnf);
	}
	void setClumpShape(float dcs)
	{
		if(dcs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dcs\" %f;\n", dcs);
	}
	void setClumpShapeMapOffset(float csmo)
	{
		if(csmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csmo\" %f;\n", csmo);
	}
	void setClumpShapeMapMult(float csmm)
	{
		if(csmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".csmm\" %f;\n", csmm);
	}
	void setClumpShapeNoise(float csn)
	{
		if(csn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csn\" %f;\n", csn);
	}
	void setClumpShapeNoiseFreq(float csnf)
	{
		if(csnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".csnf\" %f;\n", csnf);
	}
	void getLightModel()const
	{
		fprintf(mFile,"\"%s.lmd\"",mName.c_str());
	}
	void getDagSetMembers()const
	{
		fprintf(mFile,"\"%s.dsm\"",mName.c_str());
	}
	void getUvSetName()const
	{
		fprintf(mFile,"\"%s.uvsn\"",mName.c_str());
	}
	void getFurGlobals()const
	{
		fprintf(mFile,"\"%s.fgc\"",mName.c_str());
	}
	void getBaseColor()const
	{
		fprintf(mFile,"\"%s.dbc\"",mName.c_str());
	}
	void getBaseColorR()const
	{
		fprintf(mFile,"\"%s.dbcr\"",mName.c_str());
	}
	void getBaseColorG()const
	{
		fprintf(mFile,"\"%s.dbcg\"",mName.c_str());
	}
	void getBaseColorB()const
	{
		fprintf(mFile,"\"%s.dbcb\"",mName.c_str());
	}
	void getBaseColorMap()const
	{
		fprintf(mFile,"\"%s.bcm\"",mName.c_str());
	}
	void getBaseColorMapUSamples()const
	{
		fprintf(mFile,"\"%s.bcmus\"",mName.c_str());
	}
	void getBaseColorMapVSamples()const
	{
		fprintf(mFile,"\"%s.bcmvs\"",mName.c_str());
	}
	void getBaseColorNoise()const
	{
		fprintf(mFile,"\"%s.bcn\"",mName.c_str());
	}
	void getTipColor()const
	{
		fprintf(mFile,"\"%s.dtc\"",mName.c_str());
	}
	void getTipColorR()const
	{
		fprintf(mFile,"\"%s.dtcr\"",mName.c_str());
	}
	void getTipColorG()const
	{
		fprintf(mFile,"\"%s.dtcg\"",mName.c_str());
	}
	void getTipColorB()const
	{
		fprintf(mFile,"\"%s.dtcb\"",mName.c_str());
	}
	void getTipColorMap()const
	{
		fprintf(mFile,"\"%s.tcm\"",mName.c_str());
	}
	void getTipColorMapUSamples()const
	{
		fprintf(mFile,"\"%s.tcmus\"",mName.c_str());
	}
	void getTipColorMapVSamples()const
	{
		fprintf(mFile,"\"%s.tcmvs\"",mName.c_str());
	}
	void getTipColorNoise()const
	{
		fprintf(mFile,"\"%s.tcn\"",mName.c_str());
	}
	void getBaseAmbientColor()const
	{
		fprintf(mFile,"\"%s.dbac\"",mName.c_str());
	}
	void getBaseAmbientColorR()const
	{
		fprintf(mFile,"\"%s.dbacr\"",mName.c_str());
	}
	void getBaseAmbientColorG()const
	{
		fprintf(mFile,"\"%s.dbacg\"",mName.c_str());
	}
	void getBaseAmbientColorB()const
	{
		fprintf(mFile,"\"%s.dbacb\"",mName.c_str());
	}
	void getBaseAmbientColorMap()const
	{
		fprintf(mFile,"\"%s.bacm\"",mName.c_str());
	}
	void getBaseAmbientColorMapUSamples()const
	{
		fprintf(mFile,"\"%s.bacmus\"",mName.c_str());
	}
	void getBaseAmbientColorMapVSamples()const
	{
		fprintf(mFile,"\"%s.bacmvs\"",mName.c_str());
	}
	void getBaseAmbientColorNoise()const
	{
		fprintf(mFile,"\"%s.bacn\"",mName.c_str());
	}
	void getTipAmbientColor()const
	{
		fprintf(mFile,"\"%s.dtac\"",mName.c_str());
	}
	void getTipAmbientColorR()const
	{
		fprintf(mFile,"\"%s.dtacr\"",mName.c_str());
	}
	void getTipAmbientColorG()const
	{
		fprintf(mFile,"\"%s.dtacg\"",mName.c_str());
	}
	void getTipAmbientColorB()const
	{
		fprintf(mFile,"\"%s.dtacb\"",mName.c_str());
	}
	void getTipAmbientColorMap()const
	{
		fprintf(mFile,"\"%s.tacm\"",mName.c_str());
	}
	void getTipAmbientColorMapUSamples()const
	{
		fprintf(mFile,"\"%s.tacmus\"",mName.c_str());
	}
	void getTipAmbientColorMapVSamples()const
	{
		fprintf(mFile,"\"%s.tacmvs\"",mName.c_str());
	}
	void getTipAmbientColorNoise()const
	{
		fprintf(mFile,"\"%s.tacn\"",mName.c_str());
	}
	void getSpecularColor()const
	{
		fprintf(mFile,"\"%s.dsc\"",mName.c_str());
	}
	void getSpecularColorR()const
	{
		fprintf(mFile,"\"%s.dscr\"",mName.c_str());
	}
	void getSpecularColorG()const
	{
		fprintf(mFile,"\"%s.dscg\"",mName.c_str());
	}
	void getSpecularColorB()const
	{
		fprintf(mFile,"\"%s.dscb\"",mName.c_str());
	}
	void getSpecularColorMap()const
	{
		fprintf(mFile,"\"%s.scm\"",mName.c_str());
	}
	void getSpecularColorMapUSamples()const
	{
		fprintf(mFile,"\"%s.scmus\"",mName.c_str());
	}
	void getSpecularColorMapVSamples()const
	{
		fprintf(mFile,"\"%s.scmvs\"",mName.c_str());
	}
	void getSpecularColorNoise()const
	{
		fprintf(mFile,"\"%s.scn\"",mName.c_str());
	}
	void getLength()const
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getLengthMap()const
	{
		fprintf(mFile,"\"%s.lm\"",mName.c_str());
	}
	void getLengthMapUSamples()const
	{
		fprintf(mFile,"\"%s.lmus\"",mName.c_str());
	}
	void getLengthMapVSamples()const
	{
		fprintf(mFile,"\"%s.lmvs\"",mName.c_str());
	}
	void getLengthMapOffset()const
	{
		fprintf(mFile,"\"%s.lmo\"",mName.c_str());
	}
	void getLengthMapMult()const
	{
		fprintf(mFile,"\"%s.lmm\"",mName.c_str());
	}
	void getLengthNoise()const
	{
		fprintf(mFile,"\"%s.ln\"",mName.c_str());
	}
	void getSpecularSharpness()const
	{
		fprintf(mFile,"\"%s.dss\"",mName.c_str());
	}
	void getSpecularSharpnessMap()const
	{
		fprintf(mFile,"\"%s.ssm\"",mName.c_str());
	}
	void getSpecularSharpnessMapUSamples()const
	{
		fprintf(mFile,"\"%s.ssmus\"",mName.c_str());
	}
	void getSpecularSharpnessMapVSamples()const
	{
		fprintf(mFile,"\"%s.ssmvs\"",mName.c_str());
	}
	void getSpecularSharpnessMapOffset()const
	{
		fprintf(mFile,"\"%s.ssmo\"",mName.c_str());
	}
	void getSpecularSharpnessMapMult()const
	{
		fprintf(mFile,"\"%s.ssmm\"",mName.c_str());
	}
	void getSpecularSharpnessNoise()const
	{
		fprintf(mFile,"\"%s.ssn\"",mName.c_str());
	}
	void getBaldness()const
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());
	}
	void getBaldnessMap()const
	{
		fprintf(mFile,"\"%s.bm\"",mName.c_str());
	}
	void getBaldnessMapUSamples()const
	{
		fprintf(mFile,"\"%s.bmus\"",mName.c_str());
	}
	void getBaldnessMapVSamples()const
	{
		fprintf(mFile,"\"%s.bmvs\"",mName.c_str());
	}
	void getBaldnessMapOffset()const
	{
		fprintf(mFile,"\"%s.bmo\"",mName.c_str());
	}
	void getBaldnessMapMult()const
	{
		fprintf(mFile,"\"%s.bmm\"",mName.c_str());
	}
	void getBaldnessNoise()const
	{
		fprintf(mFile,"\"%s.bn\"",mName.c_str());
	}
	void getBaseOpacity()const
	{
		fprintf(mFile,"\"%s.dbo\"",mName.c_str());
	}
	void getBaseOpacityMap()const
	{
		fprintf(mFile,"\"%s.bom\"",mName.c_str());
	}
	void getBaseOpacityMapUSamples()const
	{
		fprintf(mFile,"\"%s.bomus\"",mName.c_str());
	}
	void getBaseOpacityMapVSamples()const
	{
		fprintf(mFile,"\"%s.bomvs\"",mName.c_str());
	}
	void getBaseOpacityMapOffset()const
	{
		fprintf(mFile,"\"%s.bomo\"",mName.c_str());
	}
	void getBaseOpacityMapMult()const
	{
		fprintf(mFile,"\"%s.bomm\"",mName.c_str());
	}
	void getBaseOpacityNoise()const
	{
		fprintf(mFile,"\"%s.bon\"",mName.c_str());
	}
	void getTipOpacity()const
	{
		fprintf(mFile,"\"%s.dto\"",mName.c_str());
	}
	void getTipOpacityMap()const
	{
		fprintf(mFile,"\"%s.tom\"",mName.c_str());
	}
	void getTipOpacityMapUSamples()const
	{
		fprintf(mFile,"\"%s.tomus\"",mName.c_str());
	}
	void getTipOpacityMapVSamples()const
	{
		fprintf(mFile,"\"%s.tomvs\"",mName.c_str());
	}
	void getTipOpacityMapOffset()const
	{
		fprintf(mFile,"\"%s.tomo\"",mName.c_str());
	}
	void getTipOpacityMapMult()const
	{
		fprintf(mFile,"\"%s.tomm\"",mName.c_str());
	}
	void getTipOpacityNoise()const
	{
		fprintf(mFile,"\"%s.ton\"",mName.c_str());
	}
	void getBaseWidth()const
	{
		fprintf(mFile,"\"%s.dbw\"",mName.c_str());
	}
	void getBaseWidthMap()const
	{
		fprintf(mFile,"\"%s.bwm\"",mName.c_str());
	}
	void getBaseWidthMapUSamples()const
	{
		fprintf(mFile,"\"%s.bwmus\"",mName.c_str());
	}
	void getBaseWidthMapVSamples()const
	{
		fprintf(mFile,"\"%s.bwmvs\"",mName.c_str());
	}
	void getBaseWidthMapOffset()const
	{
		fprintf(mFile,"\"%s.bwmo\"",mName.c_str());
	}
	void getBaseWidthMapMult()const
	{
		fprintf(mFile,"\"%s.bwmm\"",mName.c_str());
	}
	void getBaseWidthNoise()const
	{
		fprintf(mFile,"\"%s.bwn\"",mName.c_str());
	}
	void getTipWidth()const
	{
		fprintf(mFile,"\"%s.dtw\"",mName.c_str());
	}
	void getTipWidthMap()const
	{
		fprintf(mFile,"\"%s.twm\"",mName.c_str());
	}
	void getTipWidthMapUSamples()const
	{
		fprintf(mFile,"\"%s.twmus\"",mName.c_str());
	}
	void getTipWidthMapVSamples()const
	{
		fprintf(mFile,"\"%s.twmvs\"",mName.c_str());
	}
	void getTipWidthMapOffset()const
	{
		fprintf(mFile,"\"%s.twmo\"",mName.c_str());
	}
	void getTipWidthMapMult()const
	{
		fprintf(mFile,"\"%s.twmm\"",mName.c_str());
	}
	void getTipWidthNoise()const
	{
		fprintf(mFile,"\"%s.twn\"",mName.c_str());
	}
	void getSegments()const
	{
		fprintf(mFile,"\"%s.dsg\"",mName.c_str());
	}
	void getSegmentsMap()const
	{
		fprintf(mFile,"\"%s.sgm\"",mName.c_str());
	}
	void getSegmentsMapUSamples()const
	{
		fprintf(mFile,"\"%s.sgmus\"",mName.c_str());
	}
	void getSegmentsMapVSamples()const
	{
		fprintf(mFile,"\"%s.sgmvs\"",mName.c_str());
	}
	void getSegmentsMapOffset()const
	{
		fprintf(mFile,"\"%s.sgmo\"",mName.c_str());
	}
	void getSegmentsMapMult()const
	{
		fprintf(mFile,"\"%s.sgmm\"",mName.c_str());
	}
	void getSegmentsNoise()const
	{
		fprintf(mFile,"\"%s.sgn\"",mName.c_str());
	}
	void getBaseCurl()const
	{
		fprintf(mFile,"\"%s.dbcl\"",mName.c_str());
	}
	void getBaseCurlMap()const
	{
		fprintf(mFile,"\"%s.bclm\"",mName.c_str());
	}
	void getBaseCurlMapUSamples()const
	{
		fprintf(mFile,"\"%s.bclmus\"",mName.c_str());
	}
	void getBaseCurlMapVSamples()const
	{
		fprintf(mFile,"\"%s.bclmvs\"",mName.c_str());
	}
	void getBaseCurlMapOffset()const
	{
		fprintf(mFile,"\"%s.bclmo\"",mName.c_str());
	}
	void getBaseCurlMapMult()const
	{
		fprintf(mFile,"\"%s.bclmm\"",mName.c_str());
	}
	void getBaseCurlNoise()const
	{
		fprintf(mFile,"\"%s.bcln\"",mName.c_str());
	}
	void getTipCurl()const
	{
		fprintf(mFile,"\"%s.dtcl\"",mName.c_str());
	}
	void getTipCurlMap()const
	{
		fprintf(mFile,"\"%s.tclm\"",mName.c_str());
	}
	void getTipCurlMapUSamples()const
	{
		fprintf(mFile,"\"%s.tclmus\"",mName.c_str());
	}
	void getTipCurlMapVSamples()const
	{
		fprintf(mFile,"\"%s.tclmvs\"",mName.c_str());
	}
	void getTipCurlMapOffset()const
	{
		fprintf(mFile,"\"%s.tclmo\"",mName.c_str());
	}
	void getTipCurlMapMult()const
	{
		fprintf(mFile,"\"%s.tclmm\"",mName.c_str());
	}
	void getTipCurlNoise()const
	{
		fprintf(mFile,"\"%s.tcln\"",mName.c_str());
	}
	void getScraggle()const
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());
	}
	void getScraggleMap()const
	{
		fprintf(mFile,"\"%s.sm\"",mName.c_str());
	}
	void getScraggleMapUSamples()const
	{
		fprintf(mFile,"\"%s.smus\"",mName.c_str());
	}
	void getScraggleMapVSamples()const
	{
		fprintf(mFile,"\"%s.smvs\"",mName.c_str());
	}
	void getScraggleMapOffset()const
	{
		fprintf(mFile,"\"%s.smo\"",mName.c_str());
	}
	void getScraggleMapMult()const
	{
		fprintf(mFile,"\"%s.smm\"",mName.c_str());
	}
	void getScraggleNoise()const
	{
		fprintf(mFile,"\"%s.sn\"",mName.c_str());
	}
	void getScraggleFrequency()const
	{
		fprintf(mFile,"\"%s.dsf\"",mName.c_str());
	}
	void getScraggleFrequencyMap()const
	{
		fprintf(mFile,"\"%s.sfm\"",mName.c_str());
	}
	void getScraggleFrequencyMapUSamples()const
	{
		fprintf(mFile,"\"%s.sfmus\"",mName.c_str());
	}
	void getScraggleFrequencyMapVSamples()const
	{
		fprintf(mFile,"\"%s.sfmvs\"",mName.c_str());
	}
	void getScraggleFrequencyMapOffset()const
	{
		fprintf(mFile,"\"%s.sfmo\"",mName.c_str());
	}
	void getScraggleFrequencyMapMult()const
	{
		fprintf(mFile,"\"%s.sfmm\"",mName.c_str());
	}
	void getScraggleFrequencyNoise()const
	{
		fprintf(mFile,"\"%s.sfn\"",mName.c_str());
	}
	void getScraggleCorrelation()const
	{
		fprintf(mFile,"\"%s.dsco\"",mName.c_str());
	}
	void getScraggleCorrelationMap()const
	{
		fprintf(mFile,"\"%s.scom\"",mName.c_str());
	}
	void getScraggleCorrelationMapUSamples()const
	{
		fprintf(mFile,"\"%s.scomus\"",mName.c_str());
	}
	void getScraggleCorrelationMapVSamples()const
	{
		fprintf(mFile,"\"%s.scomvs\"",mName.c_str());
	}
	void getScraggleCorrelationMapOffset()const
	{
		fprintf(mFile,"\"%s.scomo\"",mName.c_str());
	}
	void getScraggleCorrelationMapMult()const
	{
		fprintf(mFile,"\"%s.scomm\"",mName.c_str());
	}
	void getScraggleCorrelationNoise()const
	{
		fprintf(mFile,"\"%s.scon\"",mName.c_str());
	}
	void getInclination()const
	{
		fprintf(mFile,"\"%s.di\"",mName.c_str());
	}
	void getInclinationMap()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getInclinationMapUSamples()const
	{
		fprintf(mFile,"\"%s.imus\"",mName.c_str());
	}
	void getInclinationMapVSamples()const
	{
		fprintf(mFile,"\"%s.imvs\"",mName.c_str());
	}
	void getInclinationMapOffset()const
	{
		fprintf(mFile,"\"%s.imo\"",mName.c_str());
	}
	void getInclinationMapMult()const
	{
		fprintf(mFile,"\"%s.imm\"",mName.c_str());
	}
	void getInclinationNoise()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getRoll()const
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());
	}
	void getRollMap()const
	{
		fprintf(mFile,"\"%s.rm\"",mName.c_str());
	}
	void getRollMapUSamples()const
	{
		fprintf(mFile,"\"%s.rmus\"",mName.c_str());
	}
	void getRollMapVSamples()const
	{
		fprintf(mFile,"\"%s.rmvs\"",mName.c_str());
	}
	void getRollMapOffset()const
	{
		fprintf(mFile,"\"%s.rmo\"",mName.c_str());
	}
	void getRollMapMult()const
	{
		fprintf(mFile,"\"%s.rmm\"",mName.c_str());
	}
	void getRollNoise()const
	{
		fprintf(mFile,"\"%s.rn\"",mName.c_str());
	}
	void getPolar()const
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());
	}
	void getPolarMap()const
	{
		fprintf(mFile,"\"%s.pm\"",mName.c_str());
	}
	void getPolarMapUSamples()const
	{
		fprintf(mFile,"\"%s.pmus\"",mName.c_str());
	}
	void getPolarMapVSamples()const
	{
		fprintf(mFile,"\"%s.pmvs\"",mName.c_str());
	}
	void getPolarMapOffset()const
	{
		fprintf(mFile,"\"%s.pmo\"",mName.c_str());
	}
	void getPolarMapMult()const
	{
		fprintf(mFile,"\"%s.pmm\"",mName.c_str());
	}
	void getPolarNoise()const
	{
		fprintf(mFile,"\"%s.pn\"",mName.c_str());
	}
	void getAttraction()const
	{
		fprintf(mFile,"\"%s.dat\"",mName.c_str());
	}
	void getAttractionMap()const
	{
		fprintf(mFile,"\"%s.atm\"",mName.c_str());
	}
	void getAttractionMapUSamples()const
	{
		fprintf(mFile,"\"%s.atmus\"",mName.c_str());
	}
	void getAttractionMapVSamples()const
	{
		fprintf(mFile,"\"%s.atmvs\"",mName.c_str());
	}
	void getAttractionMapOffset()const
	{
		fprintf(mFile,"\"%s.atmo\"",mName.c_str());
	}
	void getAttractionMapMult()const
	{
		fprintf(mFile,"\"%s.atmm\"",mName.c_str());
	}
	void getAttractionNoise()const
	{
		fprintf(mFile,"\"%s.atn\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.dofs\"",mName.c_str());
	}
	void getOffsetMap()const
	{
		fprintf(mFile,"\"%s.ofsm\"",mName.c_str());
	}
	void getOffsetMapUSamples()const
	{
		fprintf(mFile,"\"%s.ofsmus\"",mName.c_str());
	}
	void getOffsetMapVSamples()const
	{
		fprintf(mFile,"\"%s.ofsmvs\"",mName.c_str());
	}
	void getOffsetMapOffset()const
	{
		fprintf(mFile,"\"%s.ofsmo\"",mName.c_str());
	}
	void getOffsetMapMult()const
	{
		fprintf(mFile,"\"%s.ofsmm\"",mName.c_str());
	}
	void getOffsetNoise()const
	{
		fprintf(mFile,"\"%s.ofsn\"",mName.c_str());
	}
	void getClumping()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getClumpingMap()const
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());
	}
	void getClumpingMapUSamples()const
	{
		fprintf(mFile,"\"%s.cmus\"",mName.c_str());
	}
	void getClumpingMapVSamples()const
	{
		fprintf(mFile,"\"%s.cmvs\"",mName.c_str());
	}
	void getClumpingMapOffset()const
	{
		fprintf(mFile,"\"%s.cmo\"",mName.c_str());
	}
	void getClumpingMapMult()const
	{
		fprintf(mFile,"\"%s.cmm\"",mName.c_str());
	}
	void getClumpingNoise()const
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());
	}
	void getClumpingFrequency()const
	{
		fprintf(mFile,"\"%s.dcf\"",mName.c_str());
	}
	void getClumpingFrequencyMap()const
	{
		fprintf(mFile,"\"%s.cfm\"",mName.c_str());
	}
	void getClumpingFrequencyMapUSamples()const
	{
		fprintf(mFile,"\"%s.cfmus\"",mName.c_str());
	}
	void getClumpingFrequencyMapVSamples()const
	{
		fprintf(mFile,"\"%s.cfmvs\"",mName.c_str());
	}
	void getClumpingFrequencyMapOffset()const
	{
		fprintf(mFile,"\"%s.cfmo\"",mName.c_str());
	}
	void getClumpingFrequencyMapMult()const
	{
		fprintf(mFile,"\"%s.cfmm\"",mName.c_str());
	}
	void getClumpingFrequencyNoise()const
	{
		fprintf(mFile,"\"%s.cfn\"",mName.c_str());
	}
	void getClumpShape()const
	{
		fprintf(mFile,"\"%s.dcs\"",mName.c_str());
	}
	void getClumpShapeMap()const
	{
		fprintf(mFile,"\"%s.csm\"",mName.c_str());
	}
	void getClumpShapeMapUSamples()const
	{
		fprintf(mFile,"\"%s.csmus\"",mName.c_str());
	}
	void getClumpShapeMapVSamples()const
	{
		fprintf(mFile,"\"%s.csmvs\"",mName.c_str());
	}
	void getClumpShapeMapOffset()const
	{
		fprintf(mFile,"\"%s.csmo\"",mName.c_str());
	}
	void getClumpShapeMapMult()const
	{
		fprintf(mFile,"\"%s.csmm\"",mName.c_str());
	}
	void getClumpShapeNoise()const
	{
		fprintf(mFile,"\"%s.csn\"",mName.c_str());
	}
protected:
	FurDescription(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURDESCRIPTION_H__
