/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PFXTOON_H__
#define __MayaDM_PFXTOON_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPfxGeometry.h"
namespace MayaDM
{
class PfxToon : public PfxGeometry
{
public:
	struct InputSurface{
		void write(FILE* file) const
		{
		}
	};
	struct CurvatureWidth{
		float curvatureWidth_Position;
		float curvatureWidth_FloatValue;
		unsigned int curvatureWidth_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", curvatureWidth_Position);
			fprintf(file,"%f ", curvatureWidth_FloatValue);
			fprintf(file,"%i", curvatureWidth_Interp);
		}
	};
public:

	PfxToon():PfxGeometry(){}
	PfxToon(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PfxGeometry(file, name, parent, "pfxToon", shared, create){}
	virtual ~PfxToon(){}

	void setDisplayInViewport(bool div)
	{
		if(div == true) return;
		fprintf(mFile,"\tsetAttr \".div\" %i;\n", div);
	}
	void setProfileLines(unsigned int pln)
	{
		if(pln == 1) return;
		fprintf(mFile,"\tsetAttr \".pln\" %i;\n", pln);
	}
	void setCreaseLines(bool cln)
	{
		if(cln == true) return;
		fprintf(mFile,"\tsetAttr \".cln\" %i;\n", cln);
	}
	void setBorderLines(unsigned int bln)
	{
		if(bln == 1) return;
		fprintf(mFile,"\tsetAttr \".bln\" %i;\n", bln);
	}
	void setIntersectionLines(bool iln)
	{
		if(iln == false) return;
		fprintf(mFile,"\tsetAttr \".iln\" %i;\n", iln);
	}
	void setSelfIntersect(bool sei)
	{
		if(sei == false) return;
		fprintf(mFile,"\tsetAttr \".sei\" %i;\n", sei);
	}
	void setLineWidth(double lwd)
	{
		if(lwd == 0.1) return;
		fprintf(mFile,"\tsetAttr \".lwd\" %f;\n", lwd);
	}
	void setLineWidthMap(double lwm)
	{
		if(lwm == 0.5) return;
		fprintf(mFile,"\tsetAttr \".lwm\" %f;\n", lwm);
	}
	void setLineOpacity(double lop)
	{
		if(lop == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lop\" %f;\n", lop);
	}
	void setLineOpacityMap(double lpm)
	{
		if(lpm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lpm\" %f;\n", lpm);
	}
	void setLocalOcclusion(unsigned int lcl)
	{
		if(lcl == 0) return;
		fprintf(mFile,"\tsetAttr \".lcl\" %i;\n", lcl);
	}
	void setOcclusionTolerance(double otl)
	{
		if(otl == 0.01) return;
		fprintf(mFile,"\tsetAttr \".otl\" %f;\n", otl);
	}
	void setDepthBias(double dbs)
	{
		if(dbs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dbs\" %f;\n", dbs);
	}
	void setProfileLineWidth(double plw)
	{
		if(plw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".plw\" %f;\n", plw);
	}
	void setCreaseLineWidth(double clw)
	{
		if(clw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".clw\" %f;\n", clw);
	}
	void setBorderLineWidth(double blw)
	{
		if(blw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".blw\" %f;\n", blw);
	}
	void setIntersectionLineWidth(double ilw)
	{
		if(ilw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ilw\" %f;\n", ilw);
	}
	void setLineOffset(double lof)
	{
		if(lof == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lof\" %f;\n", lof);
	}
	void setLineOffsetMap(double lom)
	{
		if(lom == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lom\" %f;\n", lom);
	}
	void setLightingBasedWidth(double lbw)
	{
		if(lbw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lbw\" %f;\n", lbw);
	}
	void setOcclusionWidthScale(bool ows)
	{
		if(ows == true) return;
		fprintf(mFile,"\tsetAttr \".ows\" %i;\n", ows);
	}
	void setDepthOffset(double dff)
	{
		if(dff == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dff\" %f;\n", dff);
	}
	void setCreaseAngleMin(double amn)
	{
		if(amn == 20.0) return;
		fprintf(mFile,"\tsetAttr \".amn\" %f;\n", amn);
	}
	void setCreaseAngleMax(double amx)
	{
		if(amx == 90.0) return;
		fprintf(mFile,"\tsetAttr \".amx\" %f;\n", amx);
	}
	void setHardCreasesOnly(bool hco)
	{
		if(hco == true) return;
		fprintf(mFile,"\tsetAttr \".hco\" %i;\n", hco);
	}
	void setBackfacingCreases(bool bfc)
	{
		if(bfc == true) return;
		fprintf(mFile,"\tsetAttr \".bfc\" %i;\n", bfc);
	}
	void setIntersectionAngleMin(double imn)
	{
		if(imn == 1.0) return;
		fprintf(mFile,"\tsetAttr \".imn\" %f;\n", imn);
	}
	void setIntersectionAngleMax(double imx)
	{
		if(imx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".imx\" %f;\n", imx);
	}
	void setSmoothProfile(bool spf)
	{
		if(spf == true) return;
		fprintf(mFile,"\tsetAttr \".spf\" %i;\n", spf);
	}
	void setTighterProfile(bool tpf)
	{
		if(tpf == false) return;
		fprintf(mFile,"\tsetAttr \".tpf\" %i;\n", tpf);
	}
	void setCurvatureModulation(bool cmo)
	{
		if(cmo == false) return;
		fprintf(mFile,"\tsetAttr \".cmo\" %i;\n", cmo);
	}
	void setCurvatureWidth(size_t cwd_i,const CurvatureWidth& cwd)
	{
		fprintf(mFile,"\tsetAttr \".cwd[%i]\" ",cwd_i);
		cwd.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCurvatureWidth(size_t cwd_start,size_t cwd_end,CurvatureWidth* cwd)
	{
		fprintf(mFile,"\tsetAttr \".cwd[%i:%i]\" ", cwd_start,cwd_end);
		size_t size = (cwd_end-cwd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cwd[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCurvatureWidth(size_t cwd_start,size_t cwd_end)const
	{
		fprintf(mFile,"\tsetAttr \".cwd[%i:%i]\"",cwd_start,cwd_end);
		fprintf(mFile," -type \"CurvatureWidth\" ");
	}
	void appendCurvatureWidth(const CurvatureWidth& cwd)const
	{
		fprintf(mFile," ");
		cwd.write(mFile);
	}
	void endCurvatureWidth()const
	{
		fprintf(mFile,";\n");
	}
	void setCurvatureWidth_Position(size_t cwd_i,float cwdp)
	{
		if(cwdp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cwd[%i].cwdp\" %f;\n", cwd_i,cwdp);
	}
	void setCurvatureWidth_FloatValue(size_t cwd_i,float cwdfv)
	{
		if(cwdfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cwd[%i].cwdfv\" %f;\n", cwd_i,cwdfv);
	}
	void setCurvatureWidth_Interp(size_t cwd_i,unsigned int cwdi)
	{
		if(cwdi == 0) return;
		fprintf(mFile,"\tsetAttr \".cwd[%i].cwdi\" %i;\n", cwd_i,cwdi);
	}
	void setProfileWidthModulation(double pwm)
	{
		if(pwm == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pwm\" %f;\n", pwm);
	}
	void setCreaseWidthModulation(double cwm)
	{
		if(cwm == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cwm\" %f;\n", cwm);
	}
	void setBorderWidthModulation(double bwm)
	{
		if(bwm == 0.5) return;
		fprintf(mFile,"\tsetAttr \".bwm\" %f;\n", bwm);
	}
	void setIntersectionWidthModulation(double imd)
	{
		if(imd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imd\" %f;\n", imd);
	}
	void setProfileBreakAngle(double pba)
	{
		if(pba == 180.0) return;
		fprintf(mFile,"\tsetAttr \".pba\" %f;\n", pba);
	}
	void setCreaseBreakAngle(double cba)
	{
		if(cba == 80) return;
		fprintf(mFile,"\tsetAttr \".cba\" %f;\n", cba);
	}
	void setBorderBreakAngle(double bba)
	{
		if(bba == 80.0) return;
		fprintf(mFile,"\tsetAttr \".bba\" %f;\n", bba);
	}
	void setIntersectionBreakAngle(double iba)
	{
		if(iba == 180.0) return;
		fprintf(mFile,"\tsetAttr \".iba\" %f;\n", iba);
	}
	void setRemoveFlushBorders(bool rfb)
	{
		if(rfb == false) return;
		fprintf(mFile,"\tsetAttr \".rfb\" %i;\n", rfb);
	}
	void setFlushTolerance(double tfl)
	{
		if(tfl == 0.01) return;
		fprintf(mFile,"\tsetAttr \".tfl\" %f;\n", tfl);
	}
	void setFlushAngleMax(double fmx)
	{
		if(fmx == 4.0) return;
		fprintf(mFile,"\tsetAttr \".fmx\" %f;\n", fmx);
	}
	void setLineEndThinning(double let)
	{
		if(let == 0.0) return;
		fprintf(mFile,"\tsetAttr \".let\" %f;\n", let);
	}
	void setLineExtend(double lex)
	{
		if(lex == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lex\" %f;\n", lex);
	}
	void setResampleProfile(bool rpf)
	{
		if(rpf == false) return;
		fprintf(mFile,"\tsetAttr \".rpf\" %i;\n", rpf);
	}
	void setResampleCrease(bool rcr)
	{
		if(rcr == false) return;
		fprintf(mFile,"\tsetAttr \".rcr\" %i;\n", rcr);
	}
	void setResampleBorder(bool rbd)
	{
		if(rbd == false) return;
		fprintf(mFile,"\tsetAttr \".rbd\" %i;\n", rbd);
	}
	void setResampleIntersection(bool rin)
	{
		if(rin == false) return;
		fprintf(mFile,"\tsetAttr \".rin\" %i;\n", rin);
	}
	void setMaxSegmentLength(double msl)
	{
		if(msl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".msl\" %f;\n", msl);
	}
	void setMinSegmentLength(double mns)
	{
		if(mns == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mns\" %f;\n", mns);
	}
	void setScreenSpaceResampling(double ssr)
	{
		if(ssr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ssr\" %f;\n", ssr);
	}
	void setPfxRandomize(bool prz)
	{
		if(prz == false) return;
		fprintf(mFile,"\tsetAttr \".prz\" %i;\n", prz);
	}
	void setScreenspaceWidth(bool spw)
	{
		if(spw == false) return;
		fprintf(mFile,"\tsetAttr \".spw\" %i;\n", spw);
	}
	void setDistanceScaling(double dsl)
	{
		if(dsl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dsl\" %f;\n", dsl);
	}
	void setMinPixelWidth(double mpw)
	{
		if(mpw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mpw\" %f;\n", mpw);
	}
	void setMaxPixelWidth(double mxp)
	{
		if(mxp == 1000.0) return;
		fprintf(mFile,"\tsetAttr \".mxp\" %f;\n", mxp);
	}
	void setProfileColor(const float3& pcl)
	{
		fprintf(mFile,"\tsetAttr \".pcl\" -type \"float3\" ");
		pcl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setProfileColorR(float pcr)
	{
		if(pcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pcl.pcr\" %f;\n", pcr);
	}
	void setProfileColorG(float pcg)
	{
		if(pcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pcl.pcg\" %f;\n", pcg);
	}
	void setProfileColorB(float pcb)
	{
		if(pcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pcl.pcb\" %f;\n", pcb);
	}
	void setCreaseColor(const float3& ccl)
	{
		fprintf(mFile,"\tsetAttr \".ccl\" -type \"float3\" ");
		ccl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCreaseColorR(float ccr)
	{
		if(ccr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ccl.ccr\" %f;\n", ccr);
	}
	void setCreaseColorG(float ccg)
	{
		if(ccg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ccl.ccg\" %f;\n", ccg);
	}
	void setCreaseColorB(float ccb)
	{
		if(ccb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ccl.ccb\" %f;\n", ccb);
	}
	void setBorderColor(const float3& bcl)
	{
		fprintf(mFile,"\tsetAttr \".bcl\" -type \"float3\" ");
		bcl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBorderColorR(float bcr)
	{
		if(bcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bcl.bcr\" %f;\n", bcr);
	}
	void setBorderColorG(float bcg)
	{
		if(bcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bcl.bcg\" %f;\n", bcg);
	}
	void setBorderColorB(float bcb)
	{
		if(bcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bcl.bcb\" %f;\n", bcb);
	}
	void setIntersectionColor(const float3& icl)
	{
		fprintf(mFile,"\tsetAttr \".icl\" -type \"float3\" ");
		icl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIntersectionColorR(float icr)
	{
		if(icr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".icl.icr\" %f;\n", icr);
	}
	void setIntersectionColorG(float icg)
	{
		if(icg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".icl.icg\" %f;\n", icg);
	}
	void setIntersectionColorB(float icb)
	{
		if(icb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".icl.icb\" %f;\n", icb);
	}
	void getInputSurface(size_t ins_i)const
	{
		fprintf(mFile,"\"%s.ins[%i]\"",mName.c_str(),ins_i);
	}
	void getInputSurface()const
	{

		fprintf(mFile,"\"%s.ins\"",mName.c_str());
	}
	void getSurface(size_t ins_i)const
	{
		fprintf(mFile,"\"%s.ins[%i].srf\"",mName.c_str(),ins_i);
	}
	void getSurface()const
	{

		fprintf(mFile,"\"%s.ins.srf\"",mName.c_str());
	}
	void getInputWorldMatrix(size_t ins_i)const
	{
		fprintf(mFile,"\"%s.ins[%i].iwm\"",mName.c_str(),ins_i);
	}
	void getInputWorldMatrix()const
	{

		fprintf(mFile,"\"%s.ins.iwm\"",mName.c_str());
	}
	void getDisplayInViewport()const
	{
		fprintf(mFile,"\"%s.div\"",mName.c_str());
	}
	void getProfileLines()const
	{
		fprintf(mFile,"\"%s.pln\"",mName.c_str());
	}
	void getCreaseLines()const
	{
		fprintf(mFile,"\"%s.cln\"",mName.c_str());
	}
	void getBorderLines()const
	{
		fprintf(mFile,"\"%s.bln\"",mName.c_str());
	}
	void getIntersectionLines()const
	{
		fprintf(mFile,"\"%s.iln\"",mName.c_str());
	}
	void getSelfIntersect()const
	{
		fprintf(mFile,"\"%s.sei\"",mName.c_str());
	}
	void getLineWidth()const
	{
		fprintf(mFile,"\"%s.lwd\"",mName.c_str());
	}
	void getLineWidthMap()const
	{
		fprintf(mFile,"\"%s.lwm\"",mName.c_str());
	}
	void getLineOpacity()const
	{
		fprintf(mFile,"\"%s.lop\"",mName.c_str());
	}
	void getLineOpacityMap()const
	{
		fprintf(mFile,"\"%s.lpm\"",mName.c_str());
	}
	void getLocalOcclusion()const
	{
		fprintf(mFile,"\"%s.lcl\"",mName.c_str());
	}
	void getOcclusionTolerance()const
	{
		fprintf(mFile,"\"%s.otl\"",mName.c_str());
	}
	void getDepthBias()const
	{
		fprintf(mFile,"\"%s.dbs\"",mName.c_str());
	}
	void getProfileLineWidth()const
	{
		fprintf(mFile,"\"%s.plw\"",mName.c_str());
	}
	void getCreaseLineWidth()const
	{
		fprintf(mFile,"\"%s.clw\"",mName.c_str());
	}
	void getBorderLineWidth()const
	{
		fprintf(mFile,"\"%s.blw\"",mName.c_str());
	}
	void getIntersectionLineWidth()const
	{
		fprintf(mFile,"\"%s.ilw\"",mName.c_str());
	}
	void getLineOffset()const
	{
		fprintf(mFile,"\"%s.lof\"",mName.c_str());
	}
	void getLineOffsetMap()const
	{
		fprintf(mFile,"\"%s.lom\"",mName.c_str());
	}
	void getLightingBasedWidth()const
	{
		fprintf(mFile,"\"%s.lbw\"",mName.c_str());
	}
	void getOcclusionWidthScale()const
	{
		fprintf(mFile,"\"%s.ows\"",mName.c_str());
	}
	void getDepthOffset()const
	{
		fprintf(mFile,"\"%s.dff\"",mName.c_str());
	}
	void getCreaseAngleMin()const
	{
		fprintf(mFile,"\"%s.amn\"",mName.c_str());
	}
	void getCreaseAngleMax()const
	{
		fprintf(mFile,"\"%s.amx\"",mName.c_str());
	}
	void getHardCreasesOnly()const
	{
		fprintf(mFile,"\"%s.hco\"",mName.c_str());
	}
	void getBackfacingCreases()const
	{
		fprintf(mFile,"\"%s.bfc\"",mName.c_str());
	}
	void getIntersectionAngleMin()const
	{
		fprintf(mFile,"\"%s.imn\"",mName.c_str());
	}
	void getIntersectionAngleMax()const
	{
		fprintf(mFile,"\"%s.imx\"",mName.c_str());
	}
	void getSmoothProfile()const
	{
		fprintf(mFile,"\"%s.spf\"",mName.c_str());
	}
	void getTighterProfile()const
	{
		fprintf(mFile,"\"%s.tpf\"",mName.c_str());
	}
	void getCurvatureModulation()const
	{
		fprintf(mFile,"\"%s.cmo\"",mName.c_str());
	}
	void getCurvatureWidth(size_t cwd_i)const
	{
		fprintf(mFile,"\"%s.cwd[%i]\"",mName.c_str(),cwd_i);
	}
	void getCurvatureWidth()const
	{

		fprintf(mFile,"\"%s.cwd\"",mName.c_str());
	}
	void getCurvatureWidth_Position(size_t cwd_i)const
	{
		fprintf(mFile,"\"%s.cwd[%i].cwdp\"",mName.c_str(),cwd_i);
	}
	void getCurvatureWidth_Position()const
	{

		fprintf(mFile,"\"%s.cwd.cwdp\"",mName.c_str());
	}
	void getCurvatureWidth_FloatValue(size_t cwd_i)const
	{
		fprintf(mFile,"\"%s.cwd[%i].cwdfv\"",mName.c_str(),cwd_i);
	}
	void getCurvatureWidth_FloatValue()const
	{

		fprintf(mFile,"\"%s.cwd.cwdfv\"",mName.c_str());
	}
	void getCurvatureWidth_Interp(size_t cwd_i)const
	{
		fprintf(mFile,"\"%s.cwd[%i].cwdi\"",mName.c_str(),cwd_i);
	}
	void getCurvatureWidth_Interp()const
	{

		fprintf(mFile,"\"%s.cwd.cwdi\"",mName.c_str());
	}
	void getProfileWidthModulation()const
	{
		fprintf(mFile,"\"%s.pwm\"",mName.c_str());
	}
	void getCreaseWidthModulation()const
	{
		fprintf(mFile,"\"%s.cwm\"",mName.c_str());
	}
	void getBorderWidthModulation()const
	{
		fprintf(mFile,"\"%s.bwm\"",mName.c_str());
	}
	void getIntersectionWidthModulation()const
	{
		fprintf(mFile,"\"%s.imd\"",mName.c_str());
	}
	void getProfileBreakAngle()const
	{
		fprintf(mFile,"\"%s.pba\"",mName.c_str());
	}
	void getCreaseBreakAngle()const
	{
		fprintf(mFile,"\"%s.cba\"",mName.c_str());
	}
	void getBorderBreakAngle()const
	{
		fprintf(mFile,"\"%s.bba\"",mName.c_str());
	}
	void getIntersectionBreakAngle()const
	{
		fprintf(mFile,"\"%s.iba\"",mName.c_str());
	}
	void getRemoveFlushBorders()const
	{
		fprintf(mFile,"\"%s.rfb\"",mName.c_str());
	}
	void getFlushTolerance()const
	{
		fprintf(mFile,"\"%s.tfl\"",mName.c_str());
	}
	void getFlushAngleMax()const
	{
		fprintf(mFile,"\"%s.fmx\"",mName.c_str());
	}
	void getLineEndThinning()const
	{
		fprintf(mFile,"\"%s.let\"",mName.c_str());
	}
	void getLineExtend()const
	{
		fprintf(mFile,"\"%s.lex\"",mName.c_str());
	}
	void getResampleProfile()const
	{
		fprintf(mFile,"\"%s.rpf\"",mName.c_str());
	}
	void getResampleCrease()const
	{
		fprintf(mFile,"\"%s.rcr\"",mName.c_str());
	}
	void getResampleBorder()const
	{
		fprintf(mFile,"\"%s.rbd\"",mName.c_str());
	}
	void getResampleIntersection()const
	{
		fprintf(mFile,"\"%s.rin\"",mName.c_str());
	}
	void getMaxSegmentLength()const
	{
		fprintf(mFile,"\"%s.msl\"",mName.c_str());
	}
	void getMinSegmentLength()const
	{
		fprintf(mFile,"\"%s.mns\"",mName.c_str());
	}
	void getScreenSpaceResampling()const
	{
		fprintf(mFile,"\"%s.ssr\"",mName.c_str());
	}
	void getPfxRandomize()const
	{
		fprintf(mFile,"\"%s.prz\"",mName.c_str());
	}
	void getScreenspaceWidth()const
	{
		fprintf(mFile,"\"%s.spw\"",mName.c_str());
	}
	void getDistanceScaling()const
	{
		fprintf(mFile,"\"%s.dsl\"",mName.c_str());
	}
	void getMinPixelWidth()const
	{
		fprintf(mFile,"\"%s.mpw\"",mName.c_str());
	}
	void getMaxPixelWidth()const
	{
		fprintf(mFile,"\"%s.mxp\"",mName.c_str());
	}
	void getProfileColor()const
	{
		fprintf(mFile,"\"%s.pcl\"",mName.c_str());
	}
	void getProfileColorR()const
	{
		fprintf(mFile,"\"%s.pcl.pcr\"",mName.c_str());
	}
	void getProfileColorG()const
	{
		fprintf(mFile,"\"%s.pcl.pcg\"",mName.c_str());
	}
	void getProfileColorB()const
	{
		fprintf(mFile,"\"%s.pcl.pcb\"",mName.c_str());
	}
	void getCreaseColor()const
	{
		fprintf(mFile,"\"%s.ccl\"",mName.c_str());
	}
	void getCreaseColorR()const
	{
		fprintf(mFile,"\"%s.ccl.ccr\"",mName.c_str());
	}
	void getCreaseColorG()const
	{
		fprintf(mFile,"\"%s.ccl.ccg\"",mName.c_str());
	}
	void getCreaseColorB()const
	{
		fprintf(mFile,"\"%s.ccl.ccb\"",mName.c_str());
	}
	void getBorderColor()const
	{
		fprintf(mFile,"\"%s.bcl\"",mName.c_str());
	}
	void getBorderColorR()const
	{
		fprintf(mFile,"\"%s.bcl.bcr\"",mName.c_str());
	}
	void getBorderColorG()const
	{
		fprintf(mFile,"\"%s.bcl.bcg\"",mName.c_str());
	}
	void getBorderColorB()const
	{
		fprintf(mFile,"\"%s.bcl.bcb\"",mName.c_str());
	}
	void getIntersectionColor()const
	{
		fprintf(mFile,"\"%s.icl\"",mName.c_str());
	}
	void getIntersectionColorR()const
	{
		fprintf(mFile,"\"%s.icl.icr\"",mName.c_str());
	}
	void getIntersectionColorG()const
	{
		fprintf(mFile,"\"%s.icl.icg\"",mName.c_str());
	}
	void getIntersectionColorB()const
	{
		fprintf(mFile,"\"%s.icl.icb\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.ocl\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.ocl.ocr\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.ocl.ocg\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.ocl.ocb\"",mName.c_str());
	}
	void getOutProfileMesh(size_t opm_i)const
	{
		fprintf(mFile,"\"%s.opm[%i]\"",mName.c_str(),opm_i);
	}
	void getOutProfileMesh()const
	{

		fprintf(mFile,"\"%s.opm\"",mName.c_str());
	}
protected:
	PfxToon(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PfxGeometry(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PFXTOON_H__
