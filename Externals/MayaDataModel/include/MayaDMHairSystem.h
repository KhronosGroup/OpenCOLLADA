/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HAIRSYSTEM_H__
#define __MayaDM_HAIRSYSTEM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class HairSystem : public Shape
{
public:
	struct StiffnessScale{
		float stiffnessScale_Position;
		float stiffnessScale_FloatValue;
		unsigned int stiffnessScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", stiffnessScale_Position);
			fprintf(file,"%f ", stiffnessScale_FloatValue);
			fprintf(file,"%i", stiffnessScale_Interp);
		}
	};
	struct AttractionScale{
		float attractionScale_Position;
		float attractionScale_FloatValue;
		unsigned int attractionScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", attractionScale_Position);
			fprintf(file,"%f ", attractionScale_FloatValue);
			fprintf(file,"%i", attractionScale_Interp);
		}
	};
	struct ClumpWidthScale{
		float clumpWidthScale_Position;
		float clumpWidthScale_FloatValue;
		unsigned int clumpWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", clumpWidthScale_Position);
			fprintf(file,"%f ", clumpWidthScale_FloatValue);
			fprintf(file,"%i", clumpWidthScale_Interp);
		}
	};
	struct ClumpCurl{
		float clumpCurl_Position;
		float clumpCurl_FloatValue;
		unsigned int clumpCurl_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", clumpCurl_Position);
			fprintf(file,"%f ", clumpCurl_FloatValue);
			fprintf(file,"%i", clumpCurl_Interp);
		}
	};
	struct ClumpFlatness{
		float clumpFlatness_Position;
		float clumpFlatness_FloatValue;
		unsigned int clumpFlatness_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", clumpFlatness_Position);
			fprintf(file,"%f ", clumpFlatness_FloatValue);
			fprintf(file,"%i", clumpFlatness_Interp);
		}
	};
	struct HairWidthScale{
		float hairWidthScale_Position;
		float hairWidthScale_FloatValue;
		unsigned int hairWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", hairWidthScale_Position);
			fprintf(file,"%f ", hairWidthScale_FloatValue);
			fprintf(file,"%i", hairWidthScale_Interp);
		}
	};
	struct HairColorScale{
		float hairColorScale_Position;
		float3 hairColorScale_Color;
		unsigned int hairColorScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", hairColorScale_Position);
			hairColorScale_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", hairColorScale_Interp);
		}
	};
	struct DisplacementScale{
		float displacementScale_Position;
		float displacementScale_FloatValue;
		unsigned int displacementScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", displacementScale_Position);
			fprintf(file,"%f ", displacementScale_FloatValue);
			fprintf(file,"%i", displacementScale_Interp);
		}
	};
	struct FieldData{
		void write(FILE* file) const
		{
		}
	};
	struct CollisionData{
		void write(FILE* file) const
		{
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
	HairSystem():Shape(){}
	HairSystem(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "hairSystem"){}
	virtual ~HairSystem(){}
	void setSimulationMethod(unsigned int sim)
	{
		if(sim == 3) return;
		fprintf(mFile,"\tsetAttr \".sim\" %i;\n", sim);

	}
	void setCollide(bool cld)
	{
		if(cld == true) return;
		fprintf(mFile,"\tsetAttr \".cld\" %i;\n", cld);

	}
	void setCollideOverSample(int cos)
	{
		if(cos == 0) return;
		fprintf(mFile,"\tsetAttr \".cos\" %i;\n", cos);

	}
	void setSelfCollide(bool scd)
	{
		if(scd == false) return;
		fprintf(mFile,"\tsetAttr \".scd\" %i;\n", scd);

	}
	void setCollideGround(bool cdg)
	{
		if(cdg == false) return;
		fprintf(mFile,"\tsetAttr \".cdg\" %i;\n", cdg);

	}
	void setGroundHeight(double ghe)
	{
		if(ghe == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ghe\" %f;\n", ghe);

	}
	void setStiffness(double sfn)
	{
		if(sfn == 0.15) return;
		fprintf(mFile,"\tsetAttr \".sfn\" %f;\n", sfn);

	}
	void setStiffnessScale(size_t sts_i,const StiffnessScale& sts)
	{
		fprintf(mFile,"\tsetAttr \".sts[%i]\" ",sts_i);
		sts.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStiffnessScale_Position(size_t sts_i,float stsp)
	{
		if(stsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sts[%i].stsp\" %f;\n", sts_i,stsp);

	}
	void setStiffnessScale_FloatValue(size_t sts_i,float stsfv)
	{
		if(stsfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sts[%i].stsfv\" %f;\n", sts_i,stsfv);

	}
	void setStiffnessScale_Interp(size_t sts_i,unsigned int stsi)
	{
		if(stsi == 0) return;
		fprintf(mFile,"\tsetAttr \".sts[%i].stsi\" %i;\n", sts_i,stsi);

	}
	void setLengthFlex(double lfx)
	{
		if(lfx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lfx\" %f;\n", lfx);

	}
	void setDamp(double dmp)
	{
		if(dmp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dmp\" %f;\n", dmp);

	}
	void setDrag(double drg)
	{
		if(drg == 0.05) return;
		fprintf(mFile,"\tsetAttr \".drg\" %f;\n", drg);

	}
	void setFriction(double frc)
	{
		if(frc == 0.5) return;
		fprintf(mFile,"\tsetAttr \".frc\" %f;\n", frc);

	}
	void setMass(double mss)
	{
		if(mss == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mss\" %f;\n", mss);

	}
	void setDynamicsWeight(double dw)
	{
		if(dw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dw\" %f;\n", dw);

	}
	void setCollideWidthOffset(double wid)
	{
		if(wid == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wid\" %f;\n", wid);

	}
	void setStaticCling(double stc)
	{
		if(stc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".stc\" %f;\n", stc);

	}
	void setRepulsion(double rpl)
	{
		if(rpl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".rpl\" %f;\n", rpl);

	}
	void setNumCollideNeighbors(int ncn)
	{
		if(ncn == 4) return;
		fprintf(mFile,"\tsetAttr \".ncn\" %i;\n", ncn);

	}
	void setIterations(int itr)
	{
		if(itr == 4) return;
		fprintf(mFile,"\tsetAttr \".itr\" %i;\n", itr);

	}
	void setDrawCollideWidth(bool dwd)
	{
		if(dwd == false) return;
		fprintf(mFile,"\tsetAttr \".dwd\" %i;\n", dwd);

	}
	void setWidthDrawSkip(int wds)
	{
		if(wds == 2) return;
		fprintf(mFile,"\tsetAttr \".wds\" %i;\n", wds);

	}
	void setGravity(double grv)
	{
		if(grv == 0.98) return;
		fprintf(mFile,"\tsetAttr \".grv\" %f;\n", grv);

	}
	void setTurbulenceStrength(double tst)
	{
		if(tst == 0) return;
		fprintf(mFile,"\tsetAttr \".tst\" %f;\n", tst);

	}
	void setTurbulenceFrequency(double tfr)
	{
		if(tfr == 0.2) return;
		fprintf(mFile,"\tsetAttr \".tfr\" %f;\n", tfr);

	}
	void setTurbulenceSpeed(double tbs)
	{
		if(tbs == .2) return;
		fprintf(mFile,"\tsetAttr \".tbs\" %f;\n", tbs);

	}
	void setAttractionDamp(double ad)
	{
		if(ad == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ad\" %f;\n", ad);

	}
	void setStartCurveAttract(double sct)
	{
		if(sct == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sct\" %f;\n", sct);

	}
	void setAttractionScale(size_t ats_i,const AttractionScale& ats)
	{
		fprintf(mFile,"\tsetAttr \".ats[%i]\" ",ats_i);
		ats.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAttractionScale_Position(size_t ats_i,float atsp)
	{
		if(atsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ats[%i].atsp\" %f;\n", ats_i,atsp);

	}
	void setAttractionScale_FloatValue(size_t ats_i,float atsfv)
	{
		if(atsfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ats[%i].atsfv\" %f;\n", ats_i,atsfv);

	}
	void setAttractionScale_Interp(size_t ats_i,unsigned int atsi)
	{
		if(atsi == 0) return;
		fprintf(mFile,"\tsetAttr \".ats[%i].atsi\" %i;\n", ats_i,atsi);

	}
	void setMotionDrag(double mdg)
	{
		if(mdg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mdg\" %f;\n", mdg);

	}
	void setDisplayQuality(double dpq)
	{
		if(dpq == 100.0) return;
		fprintf(mFile,"\tsetAttr \".dpq\" %f;\n", dpq);

	}
	void setNoStretch(bool nst)
	{
		if(nst == false) return;
		fprintf(mFile,"\tsetAttr \".nst\" %i;\n", nst);

	}
	void setSubSegments(int ssg)
	{
		if(ssg == 0) return;
		fprintf(mFile,"\tsetAttr \".ssg\" %i;\n", ssg);

	}
	void setClumpWidth(double cwd)
	{
		if(cwd == 0.3) return;
		fprintf(mFile,"\tsetAttr \".cwd\" %f;\n", cwd);

	}
	void setClumpWidthScale(size_t cws_i,const ClumpWidthScale& cws)
	{
		fprintf(mFile,"\tsetAttr \".cws[%i]\" ",cws_i);
		cws.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpWidthScale_Position(size_t cws_i,float cwsp)
	{
		if(cwsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cws[%i].cwsp\" %f;\n", cws_i,cwsp);

	}
	void setClumpWidthScale_FloatValue(size_t cws_i,float cwsfv)
	{
		if(cwsfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cws[%i].cwsfv\" %f;\n", cws_i,cwsfv);

	}
	void setClumpWidthScale_Interp(size_t cws_i,unsigned int cwsi)
	{
		if(cwsi == 0) return;
		fprintf(mFile,"\tsetAttr \".cws[%i].cwsi\" %i;\n", cws_i,cwsi);

	}
	void setClumpTwist(double ctw)
	{
		if(ctw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ctw\" %f;\n", ctw);

	}
	void setClumpCurl(size_t clc_i,const ClumpCurl& clc)
	{
		fprintf(mFile,"\tsetAttr \".clc[%i]\" ",clc_i);
		clc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpCurl_Position(size_t clc_i,float clcp)
	{
		if(clcp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clc[%i].clcp\" %f;\n", clc_i,clcp);

	}
	void setClumpCurl_FloatValue(size_t clc_i,float clcfv)
	{
		if(clcfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clc[%i].clcfv\" %f;\n", clc_i,clcfv);

	}
	void setClumpCurl_Interp(size_t clc_i,unsigned int clci)
	{
		if(clci == 0) return;
		fprintf(mFile,"\tsetAttr \".clc[%i].clci\" %i;\n", clc_i,clci);

	}
	void setClumpFlatness(size_t cfl_i,const ClumpFlatness& cfl)
	{
		fprintf(mFile,"\tsetAttr \".cfl[%i]\" ",cfl_i);
		cfl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpFlatness_Position(size_t cfl_i,float cflp)
	{
		if(cflp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfl[%i].cflp\" %f;\n", cfl_i,cflp);

	}
	void setClumpFlatness_FloatValue(size_t cfl_i,float cflfv)
	{
		if(cflfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfl[%i].cflfv\" %f;\n", cfl_i,cflfv);

	}
	void setClumpFlatness_Interp(size_t cfl_i,unsigned int cfli)
	{
		if(cfli == 0) return;
		fprintf(mFile,"\tsetAttr \".cfl[%i].cfli\" %i;\n", cfl_i,cfli);

	}
	void setBendFollow(double bnf)
	{
		if(bnf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bnf\" %f;\n", bnf);

	}
	void setHairWidth(double hwd)
	{
		if(hwd == 0.01) return;
		fprintf(mFile,"\tsetAttr \".hwd\" %f;\n", hwd);

	}
	void setHairWidthScale(size_t hws_i,const HairWidthScale& hws)
	{
		fprintf(mFile,"\tsetAttr \".hws[%i]\" ",hws_i);
		hws.write(mFile);
		fprintf(mFile,";\n");

	}
	void setHairWidthScale_Position(size_t hws_i,float hwsp)
	{
		if(hwsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hws[%i].hwsp\" %f;\n", hws_i,hwsp);

	}
	void setHairWidthScale_FloatValue(size_t hws_i,float hwsfv)
	{
		if(hwsfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hws[%i].hwsfv\" %f;\n", hws_i,hwsfv);

	}
	void setHairWidthScale_Interp(size_t hws_i,unsigned int hwsi)
	{
		if(hwsi == 0) return;
		fprintf(mFile,"\tsetAttr \".hws[%i].hwsi\" %i;\n", hws_i,hwsi);

	}
	void setBaldnessMap(double bmp)
	{
		if(bmp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bmp\" %f;\n", bmp);

	}
	void setOpacity(double opc)
	{
		if(opc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".opc\" %f;\n", opc);

	}
	void setHairColor(const float3& hcl)
	{
		fprintf(mFile,"\tsetAttr \".hcl\" -type \"float3\" ");
		hcl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setHairColorR(float hcr)
	{
		if(hcr == 0.3) return;
		fprintf(mFile,"\tsetAttr \".hcl.hcr\" %f;\n", hcr);

	}
	void setHairColorG(float hcg)
	{
		if(hcg == 0.25) return;
		fprintf(mFile,"\tsetAttr \".hcl.hcg\" %f;\n", hcg);

	}
	void setHairColorB(float hcb)
	{
		if(hcb == 0.15) return;
		fprintf(mFile,"\tsetAttr \".hcl.hcb\" %f;\n", hcb);

	}
	void setHairColorScale(size_t hcs_i,const HairColorScale& hcs)
	{
		fprintf(mFile,"\tsetAttr \".hcs[%i]\" ",hcs_i);
		hcs.write(mFile);
		fprintf(mFile,";\n");

	}
	void setHairColorScale_Position(size_t hcs_i,float hcsp)
	{
		if(hcsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hcs[%i].hcsp\" %f;\n", hcs_i,hcsp);

	}
	void setHairColorScale_Color(size_t hcs_i,const float3& hcsc)
	{
		fprintf(mFile,"\tsetAttr \".hcs[%i].hcsc\" -type \"float3\" ",hcs_i);
		hcsc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setHairColorScale_ColorR(size_t hcs_i,float hcscr)
	{
		if(hcscr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hcs[%i].hcsc.hcscr\" %f;\n", hcs_i,hcscr);

	}
	void setHairColorScale_ColorG(size_t hcs_i,float hcscg)
	{
		if(hcscg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hcs[%i].hcsc.hcscg\" %f;\n", hcs_i,hcscg);

	}
	void setHairColorScale_ColorB(size_t hcs_i,float hcscb)
	{
		if(hcscb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hcs[%i].hcsc.hcscb\" %f;\n", hcs_i,hcscb);

	}
	void setHairColorScale_Interp(size_t hcs_i,unsigned int hcsi)
	{
		if(hcsi == 0) return;
		fprintf(mFile,"\tsetAttr \".hcs[%i].hcsi\" %i;\n", hcs_i,hcsi);

	}
	void setHairsPerClump(int hpc)
	{
		if(hpc == 10) return;
		fprintf(mFile,"\tsetAttr \".hpc\" %i;\n", hpc);

	}
	void setThinning(double thn)
	{
		if(thn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".thn\" %f;\n", thn);

	}
	void setTranslucence(double tlc)
	{
		if(tlc == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tlc\" %f;\n", tlc);

	}
	void setSpecularColor(const float3& spc)
	{
		fprintf(mFile,"\tsetAttr \".spc\" -type \"float3\" ");
		spc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpecularColorR(float spr)
	{
		if(spr == 0.35) return;
		fprintf(mFile,"\tsetAttr \".spc.spr\" %f;\n", spr);

	}
	void setSpecularColorG(float spg)
	{
		if(spg == 0.35) return;
		fprintf(mFile,"\tsetAttr \".spc.spg\" %f;\n", spg);

	}
	void setSpecularColorB(float spb)
	{
		if(spb == 0.3) return;
		fprintf(mFile,"\tsetAttr \".spc.spb\" %f;\n", spb);

	}
	void setSpecularPower(double spp)
	{
		if(spp == 3.0) return;
		fprintf(mFile,"\tsetAttr \".spp\" %f;\n", spp);

	}
	void setCastShadows(bool csd)
	{
		if(csd == true) return;
		fprintf(mFile,"\tsetAttr \".csd\" %i;\n", csd);

	}
	void setDiffuseRand(double dfr)
	{
		if(dfr == 0.2) return;
		fprintf(mFile,"\tsetAttr \".dfr\" %f;\n", dfr);

	}
	void setSpecularRand(double sra)
	{
		if(sra == 0.4) return;
		fprintf(mFile,"\tsetAttr \".sra\" %f;\n", sra);

	}
	void setHueRand(double chr)
	{
		if(chr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".chr\" %f;\n", chr);

	}
	void setSatRand(double csr)
	{
		if(csr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csr\" %f;\n", csr);

	}
	void setValRand(double cvr)
	{
		if(cvr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cvr\" %f;\n", cvr);

	}
	void setMultiStreaks(int mst)
	{
		if(mst == 0) return;
		fprintf(mFile,"\tsetAttr \".mst\" %i;\n", mst);

	}
	void setMultiStreakSpread1(double ms1)
	{
		if(ms1 == 0.3) return;
		fprintf(mFile,"\tsetAttr \".ms1\" %f;\n", ms1);

	}
	void setMultiStreakSpread2(double ms2)
	{
		if(ms2 == 0.1) return;
		fprintf(mFile,"\tsetAttr \".ms2\" %f;\n", ms2);

	}
	void setLightEachHair(bool leh)
	{
		if(leh == false) return;
		fprintf(mFile,"\tsetAttr \".leh\" %i;\n", leh);

	}
	void setDisplacementScale(size_t dsc_i,const DisplacementScale& dsc)
	{
		fprintf(mFile,"\tsetAttr \".dsc[%i]\" ",dsc_i);
		dsc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDisplacementScale_Position(size_t dsc_i,float dscp)
	{
		if(dscp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dsc[%i].dscp\" %f;\n", dsc_i,dscp);

	}
	void setDisplacementScale_FloatValue(size_t dsc_i,float dscfv)
	{
		if(dscfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dsc[%i].dscfv\" %f;\n", dsc_i,dscfv);

	}
	void setDisplacementScale_Interp(size_t dsc_i,unsigned int dsci)
	{
		if(dsci == 0) return;
		fprintf(mFile,"\tsetAttr \".dsc[%i].dsci\" %i;\n", dsc_i,dsci);

	}
	void setCurl(double crl)
	{
		if(crl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crl\" %f;\n", crl);

	}
	void setCurlFrequency(double crf)
	{
		if(crf == 10) return;
		fprintf(mFile,"\tsetAttr \".crf\" %f;\n", crf);

	}
	void setNoiseMethod(unsigned int nmt)
	{
		if(nmt == 0) return;
		fprintf(mFile,"\tsetAttr \".nmt\" %i;\n", nmt);

	}
	void setNoise(double noi)
	{
		if(noi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".noi\" %f;\n", noi);

	}
	void setDetailNoise(double dno)
	{
		if(dno == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dno\" %f;\n", dno);

	}
	void setNoiseFrequency(double nof)
	{
		if(nof == 0.4) return;
		fprintf(mFile,"\tsetAttr \".nof\" %f;\n", nof);

	}
	void setNoiseFrequencyU(double nfu)
	{
		if(nfu == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nfu\" %f;\n", nfu);

	}
	void setNoiseFrequencyV(double nfv)
	{
		if(nfv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nfv\" %f;\n", nfv);

	}
	void setNoiseFrequencyW(double nfw)
	{
		if(nfw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".nfw\" %f;\n", nfw);

	}
	void setSubClumpMethod(unsigned int scm)
	{
		if(scm == 0) return;
		fprintf(mFile,"\tsetAttr \".scm\" %i;\n", scm);

	}
	void setSubClumping(double scp)
	{
		if(scp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scp\" %f;\n", scp);

	}
	void setSubClumpRand(double scr)
	{
		if(scr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".scr\" %f;\n", scr);

	}
	void setNumUClumps(double nuc)
	{
		if(nuc == 15.0) return;
		fprintf(mFile,"\tsetAttr \".nuc\" %f;\n", nuc);

	}
	void setNumVClumps(double nvc)
	{
		if(nvc == 15.0) return;
		fprintf(mFile,"\tsetAttr \".nvc\" %f;\n", nvc);

	}
	void setClumpInterpolation(double cin)
	{
		if(cin == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cin\" %f;\n", cin);

	}
	void setInterpolationRange(double inr)
	{
		if(inr == 8.0) return;
		fprintf(mFile,"\tsetAttr \".inr\" %f;\n", inr);

	}
	void setStartFrame(double stf)
	{
		if(stf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".stf\" %f;\n", stf);

	}
	void setUsePre70ForceIntensity(bool upfi)
	{
		if(upfi == false) return;
		fprintf(mFile,"\tsetAttr \".upfi\" %i;\n", upfi);

	}
	void setReceiveShadows(bool rcsh)
	{
		if(rcsh == true) return;
		fprintf(mFile,"\tsetAttr \".rcsh\" %i;\n", rcsh);

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
		if(mins == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.mins\" %i;\n", mins);

	}
	void setMiMaxSamples(short maxs)
	{
		if(maxs == 2) return;
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
	void setOutputHair(size_t oh_i,const vectorArray& oh)
	{
		if(oh.size == 0) return;
		fprintf(mFile,"\tsetAttr \".oh[%i]\" -type \"vectorArray\" ",oh_i);
		oh.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutputHair(size_t oh_start,size_t oh_end,vectorArray* oh)
	{
		fprintf(mFile,"\tsetAttr \".oh[%i:%i]\" ", oh_start,oh_end);
		size_t size = (oh_end-oh_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			oh[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startOutputHair(size_t oh_start,size_t oh_end)
	{
		fprintf(mFile,"\tsetAttr \".oh[%i:%i]\"",oh_start,oh_end);
		fprintf(mFile," -type \"vectorArray\" ");

	}
	void appendOutputHair(const vectorArray& oh)
	{
		fprintf(mFile,"\n");
		oh.write(mFile);

	}
	void endOutputHair()
	{
		fprintf(mFile,";\n");

	}
	void getSimulationMethod()
	{
		fprintf(mFile,"\"%s.sim\"",mName.c_str());

	}
	void getInputHair(size_t ih_i)
	{
		fprintf(mFile,"\"%s.ih[%i]\"",mName.c_str(),ih_i);

	}
	void getInputHairPin(size_t ihp_i)
	{
		fprintf(mFile,"\"%s.ihp[%i]\"",mName.c_str(),ihp_i);

	}
	void getCollide()
	{
		fprintf(mFile,"\"%s.cld\"",mName.c_str());

	}
	void getCollideOverSample()
	{
		fprintf(mFile,"\"%s.cos\"",mName.c_str());

	}
	void getSelfCollide()
	{
		fprintf(mFile,"\"%s.scd\"",mName.c_str());

	}
	void getCollideGround()
	{
		fprintf(mFile,"\"%s.cdg\"",mName.c_str());

	}
	void getGroundHeight()
	{
		fprintf(mFile,"\"%s.ghe\"",mName.c_str());

	}
	void getStiffness()
	{
		fprintf(mFile,"\"%s.sfn\"",mName.c_str());

	}
	void getStiffnessScale(size_t sts_i)
	{
		fprintf(mFile,"\"%s.sts[%i]\"",mName.c_str(),sts_i);

	}
	void getStiffnessScale_Position(size_t sts_i)
	{
		fprintf(mFile,"\"%s.sts[%i].stsp\"",mName.c_str(),sts_i);

	}
	void getStiffnessScale_FloatValue(size_t sts_i)
	{
		fprintf(mFile,"\"%s.sts[%i].stsfv\"",mName.c_str(),sts_i);

	}
	void getStiffnessScale_Interp(size_t sts_i)
	{
		fprintf(mFile,"\"%s.sts[%i].stsi\"",mName.c_str(),sts_i);

	}
	void getLengthFlex()
	{
		fprintf(mFile,"\"%s.lfx\"",mName.c_str());

	}
	void getDamp()
	{
		fprintf(mFile,"\"%s.dmp\"",mName.c_str());

	}
	void getDrag()
	{
		fprintf(mFile,"\"%s.drg\"",mName.c_str());

	}
	void getFriction()
	{
		fprintf(mFile,"\"%s.frc\"",mName.c_str());

	}
	void getMass()
	{
		fprintf(mFile,"\"%s.mss\"",mName.c_str());

	}
	void getDynamicsWeight()
	{
		fprintf(mFile,"\"%s.dw\"",mName.c_str());

	}
	void getCollideWidthOffset()
	{
		fprintf(mFile,"\"%s.wid\"",mName.c_str());

	}
	void getStaticCling()
	{
		fprintf(mFile,"\"%s.stc\"",mName.c_str());

	}
	void getRepulsion()
	{
		fprintf(mFile,"\"%s.rpl\"",mName.c_str());

	}
	void getNumCollideNeighbors()
	{
		fprintf(mFile,"\"%s.ncn\"",mName.c_str());

	}
	void getIterations()
	{
		fprintf(mFile,"\"%s.itr\"",mName.c_str());

	}
	void getDrawCollideWidth()
	{
		fprintf(mFile,"\"%s.dwd\"",mName.c_str());

	}
	void getWidthDrawSkip()
	{
		fprintf(mFile,"\"%s.wds\"",mName.c_str());

	}
	void getGravity()
	{
		fprintf(mFile,"\"%s.grv\"",mName.c_str());

	}
	void getTurbulenceStrength()
	{
		fprintf(mFile,"\"%s.tst\"",mName.c_str());

	}
	void getTurbulenceFrequency()
	{
		fprintf(mFile,"\"%s.tfr\"",mName.c_str());

	}
	void getTurbulenceSpeed()
	{
		fprintf(mFile,"\"%s.tbs\"",mName.c_str());

	}
	void getAttractionDamp()
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());

	}
	void getStartCurveAttract()
	{
		fprintf(mFile,"\"%s.sct\"",mName.c_str());

	}
	void getAttractionScale(size_t ats_i)
	{
		fprintf(mFile,"\"%s.ats[%i]\"",mName.c_str(),ats_i);

	}
	void getAttractionScale_Position(size_t ats_i)
	{
		fprintf(mFile,"\"%s.ats[%i].atsp\"",mName.c_str(),ats_i);

	}
	void getAttractionScale_FloatValue(size_t ats_i)
	{
		fprintf(mFile,"\"%s.ats[%i].atsfv\"",mName.c_str(),ats_i);

	}
	void getAttractionScale_Interp(size_t ats_i)
	{
		fprintf(mFile,"\"%s.ats[%i].atsi\"",mName.c_str(),ats_i);

	}
	void getMotionDrag()
	{
		fprintf(mFile,"\"%s.mdg\"",mName.c_str());

	}
	void getDisplayQuality()
	{
		fprintf(mFile,"\"%s.dpq\"",mName.c_str());

	}
	void getNoStretch()
	{
		fprintf(mFile,"\"%s.nst\"",mName.c_str());

	}
	void getSubSegments()
	{
		fprintf(mFile,"\"%s.ssg\"",mName.c_str());

	}
	void getClumpWidth()
	{
		fprintf(mFile,"\"%s.cwd\"",mName.c_str());

	}
	void getClumpWidthScale(size_t cws_i)
	{
		fprintf(mFile,"\"%s.cws[%i]\"",mName.c_str(),cws_i);

	}
	void getClumpWidthScale_Position(size_t cws_i)
	{
		fprintf(mFile,"\"%s.cws[%i].cwsp\"",mName.c_str(),cws_i);

	}
	void getClumpWidthScale_FloatValue(size_t cws_i)
	{
		fprintf(mFile,"\"%s.cws[%i].cwsfv\"",mName.c_str(),cws_i);

	}
	void getClumpWidthScale_Interp(size_t cws_i)
	{
		fprintf(mFile,"\"%s.cws[%i].cwsi\"",mName.c_str(),cws_i);

	}
	void getClumpTwist()
	{
		fprintf(mFile,"\"%s.ctw\"",mName.c_str());

	}
	void getClumpCurl(size_t clc_i)
	{
		fprintf(mFile,"\"%s.clc[%i]\"",mName.c_str(),clc_i);

	}
	void getClumpCurl_Position(size_t clc_i)
	{
		fprintf(mFile,"\"%s.clc[%i].clcp\"",mName.c_str(),clc_i);

	}
	void getClumpCurl_FloatValue(size_t clc_i)
	{
		fprintf(mFile,"\"%s.clc[%i].clcfv\"",mName.c_str(),clc_i);

	}
	void getClumpCurl_Interp(size_t clc_i)
	{
		fprintf(mFile,"\"%s.clc[%i].clci\"",mName.c_str(),clc_i);

	}
	void getClumpFlatness(size_t cfl_i)
	{
		fprintf(mFile,"\"%s.cfl[%i]\"",mName.c_str(),cfl_i);

	}
	void getClumpFlatness_Position(size_t cfl_i)
	{
		fprintf(mFile,"\"%s.cfl[%i].cflp\"",mName.c_str(),cfl_i);

	}
	void getClumpFlatness_FloatValue(size_t cfl_i)
	{
		fprintf(mFile,"\"%s.cfl[%i].cflfv\"",mName.c_str(),cfl_i);

	}
	void getClumpFlatness_Interp(size_t cfl_i)
	{
		fprintf(mFile,"\"%s.cfl[%i].cfli\"",mName.c_str(),cfl_i);

	}
	void getBendFollow()
	{
		fprintf(mFile,"\"%s.bnf\"",mName.c_str());

	}
	void getHairWidth()
	{
		fprintf(mFile,"\"%s.hwd\"",mName.c_str());

	}
	void getHairWidthScale(size_t hws_i)
	{
		fprintf(mFile,"\"%s.hws[%i]\"",mName.c_str(),hws_i);

	}
	void getHairWidthScale_Position(size_t hws_i)
	{
		fprintf(mFile,"\"%s.hws[%i].hwsp\"",mName.c_str(),hws_i);

	}
	void getHairWidthScale_FloatValue(size_t hws_i)
	{
		fprintf(mFile,"\"%s.hws[%i].hwsfv\"",mName.c_str(),hws_i);

	}
	void getHairWidthScale_Interp(size_t hws_i)
	{
		fprintf(mFile,"\"%s.hws[%i].hwsi\"",mName.c_str(),hws_i);

	}
	void getBaldnessMap()
	{
		fprintf(mFile,"\"%s.bmp\"",mName.c_str());

	}
	void getOpacity()
	{
		fprintf(mFile,"\"%s.opc\"",mName.c_str());

	}
	void getHairColor()
	{
		fprintf(mFile,"\"%s.hcl\"",mName.c_str());

	}
	void getHairColorR()
	{
		fprintf(mFile,"\"%s.hcl.hcr\"",mName.c_str());

	}
	void getHairColorG()
	{
		fprintf(mFile,"\"%s.hcl.hcg\"",mName.c_str());

	}
	void getHairColorB()
	{
		fprintf(mFile,"\"%s.hcl.hcb\"",mName.c_str());

	}
	void getHairColorScale(size_t hcs_i)
	{
		fprintf(mFile,"\"%s.hcs[%i]\"",mName.c_str(),hcs_i);

	}
	void getHairColorScale_Position(size_t hcs_i)
	{
		fprintf(mFile,"\"%s.hcs[%i].hcsp\"",mName.c_str(),hcs_i);

	}
	void getHairColorScale_Color(size_t hcs_i)
	{
		fprintf(mFile,"\"%s.hcs[%i].hcsc\"",mName.c_str(),hcs_i);

	}
	void getHairColorScale_ColorR(size_t hcs_i)
	{
		fprintf(mFile,"\"%s.hcs[%i].hcsc.hcscr\"",mName.c_str(),hcs_i);

	}
	void getHairColorScale_ColorG(size_t hcs_i)
	{
		fprintf(mFile,"\"%s.hcs[%i].hcsc.hcscg\"",mName.c_str(),hcs_i);

	}
	void getHairColorScale_ColorB(size_t hcs_i)
	{
		fprintf(mFile,"\"%s.hcs[%i].hcsc.hcscb\"",mName.c_str(),hcs_i);

	}
	void getHairColorScale_Interp(size_t hcs_i)
	{
		fprintf(mFile,"\"%s.hcs[%i].hcsi\"",mName.c_str(),hcs_i);

	}
	void getHairsPerClump()
	{
		fprintf(mFile,"\"%s.hpc\"",mName.c_str());

	}
	void getThinning()
	{
		fprintf(mFile,"\"%s.thn\"",mName.c_str());

	}
	void getTranslucence()
	{
		fprintf(mFile,"\"%s.tlc\"",mName.c_str());

	}
	void getSpecularColor()
	{
		fprintf(mFile,"\"%s.spc\"",mName.c_str());

	}
	void getSpecularColorR()
	{
		fprintf(mFile,"\"%s.spc.spr\"",mName.c_str());

	}
	void getSpecularColorG()
	{
		fprintf(mFile,"\"%s.spc.spg\"",mName.c_str());

	}
	void getSpecularColorB()
	{
		fprintf(mFile,"\"%s.spc.spb\"",mName.c_str());

	}
	void getSpecularPower()
	{
		fprintf(mFile,"\"%s.spp\"",mName.c_str());

	}
	void getCastShadows()
	{
		fprintf(mFile,"\"%s.csd\"",mName.c_str());

	}
	void getDiffuseRand()
	{
		fprintf(mFile,"\"%s.dfr\"",mName.c_str());

	}
	void getSpecularRand()
	{
		fprintf(mFile,"\"%s.sra\"",mName.c_str());

	}
	void getHueRand()
	{
		fprintf(mFile,"\"%s.chr\"",mName.c_str());

	}
	void getSatRand()
	{
		fprintf(mFile,"\"%s.csr\"",mName.c_str());

	}
	void getValRand()
	{
		fprintf(mFile,"\"%s.cvr\"",mName.c_str());

	}
	void getMultiStreaks()
	{
		fprintf(mFile,"\"%s.mst\"",mName.c_str());

	}
	void getMultiStreakSpread1()
	{
		fprintf(mFile,"\"%s.ms1\"",mName.c_str());

	}
	void getMultiStreakSpread2()
	{
		fprintf(mFile,"\"%s.ms2\"",mName.c_str());

	}
	void getLightEachHair()
	{
		fprintf(mFile,"\"%s.leh\"",mName.c_str());

	}
	void getDisplacementScale(size_t dsc_i)
	{
		fprintf(mFile,"\"%s.dsc[%i]\"",mName.c_str(),dsc_i);

	}
	void getDisplacementScale_Position(size_t dsc_i)
	{
		fprintf(mFile,"\"%s.dsc[%i].dscp\"",mName.c_str(),dsc_i);

	}
	void getDisplacementScale_FloatValue(size_t dsc_i)
	{
		fprintf(mFile,"\"%s.dsc[%i].dscfv\"",mName.c_str(),dsc_i);

	}
	void getDisplacementScale_Interp(size_t dsc_i)
	{
		fprintf(mFile,"\"%s.dsc[%i].dsci\"",mName.c_str(),dsc_i);

	}
	void getCurl()
	{
		fprintf(mFile,"\"%s.crl\"",mName.c_str());

	}
	void getCurlFrequency()
	{
		fprintf(mFile,"\"%s.crf\"",mName.c_str());

	}
	void getNoiseMethod()
	{
		fprintf(mFile,"\"%s.nmt\"",mName.c_str());

	}
	void getNoise()
	{
		fprintf(mFile,"\"%s.noi\"",mName.c_str());

	}
	void getDetailNoise()
	{
		fprintf(mFile,"\"%s.dno\"",mName.c_str());

	}
	void getNoiseFrequency()
	{
		fprintf(mFile,"\"%s.nof\"",mName.c_str());

	}
	void getNoiseFrequencyU()
	{
		fprintf(mFile,"\"%s.nfu\"",mName.c_str());

	}
	void getNoiseFrequencyV()
	{
		fprintf(mFile,"\"%s.nfv\"",mName.c_str());

	}
	void getNoiseFrequencyW()
	{
		fprintf(mFile,"\"%s.nfw\"",mName.c_str());

	}
	void getSubClumpMethod()
	{
		fprintf(mFile,"\"%s.scm\"",mName.c_str());

	}
	void getSubClumping()
	{
		fprintf(mFile,"\"%s.scp\"",mName.c_str());

	}
	void getSubClumpRand()
	{
		fprintf(mFile,"\"%s.scr\"",mName.c_str());

	}
	void getNumUClumps()
	{
		fprintf(mFile,"\"%s.nuc\"",mName.c_str());

	}
	void getNumVClumps()
	{
		fprintf(mFile,"\"%s.nvc\"",mName.c_str());

	}
	void getClumpInterpolation()
	{
		fprintf(mFile,"\"%s.cin\"",mName.c_str());

	}
	void getInterpolationRange()
	{
		fprintf(mFile,"\"%s.inr\"",mName.c_str());

	}
	void getCurrentTime()
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());

	}
	void getStartTime()
	{
		fprintf(mFile,"\"%s.sti\"",mName.c_str());

	}
	void getStartFrame()
	{
		fprintf(mFile,"\"%s.stf\"",mName.c_str());

	}
	void getInputForce(size_t ifc_i)
	{
		fprintf(mFile,"\"%s.ifc[%i]\"",mName.c_str(),ifc_i);

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
	void getUsePre70ForceIntensity()
	{
		fprintf(mFile,"\"%s.upfi\"",mName.c_str());

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
	void getDiskCache()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getReceiveShadows()
	{
		fprintf(mFile,"\"%s.rcsh\"",mName.c_str());

	}
	void getVisibleInReflections()
	{
		fprintf(mFile,"\"%s.vir\"",mName.c_str());

	}
	void getVisibleInRefractions()
	{
		fprintf(mFile,"\"%s.vif\"",mName.c_str());

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
	void getOutputHair(size_t oh_i)
	{
		fprintf(mFile,"\"%s.oh[%i]\"",mName.c_str(),oh_i);

	}
	void getOutputRenderHairs()
	{
		fprintf(mFile,"\"%s.orh\"",mName.c_str());

	}
protected:
	HairSystem(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HAIRSYSTEM_H__
