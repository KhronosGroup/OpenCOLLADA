/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FOLLICLE_H__
#define __MayaDM_FOLLICLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class Follicle : public Shape
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
public:

	Follicle():Shape(){}
	Follicle(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "follicle", shared, create){}
	virtual ~Follicle(){}

	void setParameterU(double pu)
	{
		if(pu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pu\" %f;\n", pu);
	}
	void setParameterV(double pv)
	{
		if(pv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pv\" %f;\n", pv);
	}
	void setRestPose(unsigned int rsp)
	{
		if(rsp == 0) return;
		fprintf(mFile,"\tsetAttr \".rsp\" %i;\n", rsp);
	}
	void setPointLock(unsigned int ptl)
	{
		if(ptl == 1) return;
		fprintf(mFile,"\tsetAttr \".ptl\" %i;\n", ptl);
	}
	void setSimulationMethod(unsigned int sim)
	{
		if(sim == 2) return;
		fprintf(mFile,"\tsetAttr \".sim\" %i;\n", sim);
	}
	void setStartDirection(unsigned int sdr)
	{
		if(sdr == 0) return;
		fprintf(mFile,"\tsetAttr \".sdr\" %i;\n", sdr);
	}
	void setFlipDirection(bool fld)
	{
		if(fld == false) return;
		fprintf(mFile,"\tsetAttr \".fld\" %i;\n", fld);
	}
	void setHairSysGravity(double hsg)
	{
		if(hsg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hsg\" %f;\n", hsg);
	}
	void setHairSysStiffness(double hss)
	{
		if(hss == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hss\" %f;\n", hss);
	}
	void setOverrideDynamics(bool ovd)
	{
		if(ovd == false) return;
		fprintf(mFile,"\tsetAttr \".ovd\" %i;\n", ovd);
	}
	void setCollide(bool cld)
	{
		if(cld == true) return;
		fprintf(mFile,"\tsetAttr \".cld\" %i;\n", cld);
	}
	void setDamp(double dmp)
	{
		if(dmp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dmp\" %f;\n", dmp);
	}
	void setStiffness(double stf)
	{
		if(stf == 0.15) return;
		fprintf(mFile,"\tsetAttr \".stf\" %f;\n", stf);
	}
	void setStiffnessScale(size_t sts_i,const StiffnessScale& sts)
	{
		fprintf(mFile,"\tsetAttr \".sts[%i]\" ",sts_i);
		sts.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStiffnessScale(size_t sts_start,size_t sts_end,StiffnessScale* sts)
	{
		fprintf(mFile,"\tsetAttr \".sts[%i:%i]\" ", sts_start,sts_end);
		size_t size = (sts_end-sts_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			sts[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startStiffnessScale(size_t sts_start,size_t sts_end)const
	{
		fprintf(mFile,"\tsetAttr \".sts[%i:%i]\"",sts_start,sts_end);
		fprintf(mFile," -type \"StiffnessScale\" ");
	}
	void appendStiffnessScale(const StiffnessScale& sts)const
	{
		fprintf(mFile," ");
		sts.write(mFile);
	}
	void endStiffnessScale()const
	{
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
	void setLengthFlex(double lfl)
	{
		if(lfl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lfl\" %f;\n", lfl);
	}
	void setClumpWidthMult(double cwm)
	{
		if(cwm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cwm\" %f;\n", cwm);
	}
	void setClumpWidthScale(size_t cws_i,const ClumpWidthScale& cws)
	{
		fprintf(mFile,"\tsetAttr \".cws[%i]\" ",cws_i);
		cws.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClumpWidthScale(size_t cws_start,size_t cws_end,ClumpWidthScale* cws)
	{
		fprintf(mFile,"\tsetAttr \".cws[%i:%i]\" ", cws_start,cws_end);
		size_t size = (cws_end-cws_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cws[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startClumpWidthScale(size_t cws_start,size_t cws_end)const
	{
		fprintf(mFile,"\tsetAttr \".cws[%i:%i]\"",cws_start,cws_end);
		fprintf(mFile," -type \"ClumpWidthScale\" ");
	}
	void appendClumpWidthScale(const ClumpWidthScale& cws)const
	{
		fprintf(mFile," ");
		cws.write(mFile);
	}
	void endClumpWidthScale()const
	{
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
	void setAttractionScale(size_t ats_start,size_t ats_end,AttractionScale* ats)
	{
		fprintf(mFile,"\tsetAttr \".ats[%i:%i]\" ", ats_start,ats_end);
		size_t size = (ats_end-ats_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ats[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startAttractionScale(size_t ats_start,size_t ats_end)const
	{
		fprintf(mFile,"\tsetAttr \".ats[%i:%i]\"",ats_start,ats_end);
		fprintf(mFile," -type \"AttractionScale\" ");
	}
	void appendAttractionScale(const AttractionScale& ats)const
	{
		fprintf(mFile," ");
		ats.write(mFile);
	}
	void endAttractionScale()const
	{
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
	void setAttractionDamp(double ad)
	{
		if(ad == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ad\" %f;\n", ad);
	}
	void setDensityMult(double dml)
	{
		if(dml == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dml\" %f;\n", dml);
	}
	void setCurlMult(double cml)
	{
		if(cml == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cml\" %f;\n", cml);
	}
	void setClumpTwistOffset(double ctf)
	{
		if(ctf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ctf\" %f;\n", ctf);
	}
	void setBraid(bool brd)
	{
		if(brd == false) return;
		fprintf(mFile,"\tsetAttr \".brd\" %i;\n", brd);
	}
	void setColorBlend(double cbl)
	{
		if(cbl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cbl\" %f;\n", cbl);
	}
	void setColor(const float3& cl)
	{
		fprintf(mFile,"\tsetAttr \".cl\" -type \"float3\" ");
		cl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl.cr\" %f;\n", cr);
	}
	void setColorG(float cg)
	{
		if(cg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl.cg\" %f;\n", cg);
	}
	void setColorB(float cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl.cb\" %f;\n", cb);
	}
	void setFixedSegmentLength(bool fsl)
	{
		if(fsl == 0) return;
		fprintf(mFile,"\tsetAttr \".fsl\" %i;\n", fsl);
	}
	void setSegmentLength(double sgl)
	{
		if(sgl == 1) return;
		fprintf(mFile,"\tsetAttr \".sgl\" %f;\n", sgl);
	}
	void setSampleDensity(double sdn)
	{
		if(sdn == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sdn\" %f;\n", sdn);
	}
	void setDegree(int dgr)
	{
		if(dgr == 2) return;
		fprintf(mFile,"\tsetAttr \".dgr\" %i;\n", dgr);
	}
	void setClumpWidth(float cw)
	{
		if(cw == 0.3) return;
		fprintf(mFile,"\tsetAttr \".cw\" %f;\n", cw);
	}
	void setMapSetName(const string& msn)
	{
		if(msn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".msn\" -type \"string\" ");
		msn.write(mFile);
		fprintf(mFile,";\n");
	}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getInputMesh()const
	{
		fprintf(mFile,"\"%s.inm\"",mName.c_str());
	}
	void getInputWorldMatrix()const
	{
		fprintf(mFile,"\"%s.iwm\"",mName.c_str());
	}
	void getParameterU()const
	{
		fprintf(mFile,"\"%s.pu\"",mName.c_str());
	}
	void getParameterV()const
	{
		fprintf(mFile,"\"%s.pv\"",mName.c_str());
	}
	void getStartPosition()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getRestPosition()const
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());
	}
	void getCurrentPosition()const
	{
		fprintf(mFile,"\"%s.crp\"",mName.c_str());
	}
	void getRestPose()const
	{
		fprintf(mFile,"\"%s.rsp\"",mName.c_str());
	}
	void getPointLock()const
	{
		fprintf(mFile,"\"%s.ptl\"",mName.c_str());
	}
	void getSimulationMethod()const
	{
		fprintf(mFile,"\"%s.sim\"",mName.c_str());
	}
	void getStartDirection()const
	{
		fprintf(mFile,"\"%s.sdr\"",mName.c_str());
	}
	void getFlipDirection()const
	{
		fprintf(mFile,"\"%s.fld\"",mName.c_str());
	}
	void getHairSysGravity()const
	{
		fprintf(mFile,"\"%s.hsg\"",mName.c_str());
	}
	void getHairSysStiffness()const
	{
		fprintf(mFile,"\"%s.hss\"",mName.c_str());
	}
	void getOverrideDynamics()const
	{
		fprintf(mFile,"\"%s.ovd\"",mName.c_str());
	}
	void getCollide()const
	{
		fprintf(mFile,"\"%s.cld\"",mName.c_str());
	}
	void getDamp()const
	{
		fprintf(mFile,"\"%s.dmp\"",mName.c_str());
	}
	void getStiffness()const
	{
		fprintf(mFile,"\"%s.stf\"",mName.c_str());
	}
	void getStiffnessScale(size_t sts_i)const
	{
		fprintf(mFile,"\"%s.sts[%i]\"",mName.c_str(),sts_i);
	}
	void getStiffnessScale()const
	{

		fprintf(mFile,"\"%s.sts\"",mName.c_str());
	}
	void getStiffnessScale_Position(size_t sts_i)const
	{
		fprintf(mFile,"\"%s.sts[%i].stsp\"",mName.c_str(),sts_i);
	}
	void getStiffnessScale_Position()const
	{

		fprintf(mFile,"\"%s.sts.stsp\"",mName.c_str());
	}
	void getStiffnessScale_FloatValue(size_t sts_i)const
	{
		fprintf(mFile,"\"%s.sts[%i].stsfv\"",mName.c_str(),sts_i);
	}
	void getStiffnessScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.sts.stsfv\"",mName.c_str());
	}
	void getStiffnessScale_Interp(size_t sts_i)const
	{
		fprintf(mFile,"\"%s.sts[%i].stsi\"",mName.c_str(),sts_i);
	}
	void getStiffnessScale_Interp()const
	{

		fprintf(mFile,"\"%s.sts.stsi\"",mName.c_str());
	}
	void getLengthFlex()const
	{
		fprintf(mFile,"\"%s.lfl\"",mName.c_str());
	}
	void getClumpWidthMult()const
	{
		fprintf(mFile,"\"%s.cwm\"",mName.c_str());
	}
	void getClumpWidthScale(size_t cws_i)const
	{
		fprintf(mFile,"\"%s.cws[%i]\"",mName.c_str(),cws_i);
	}
	void getClumpWidthScale()const
	{

		fprintf(mFile,"\"%s.cws\"",mName.c_str());
	}
	void getClumpWidthScale_Position(size_t cws_i)const
	{
		fprintf(mFile,"\"%s.cws[%i].cwsp\"",mName.c_str(),cws_i);
	}
	void getClumpWidthScale_Position()const
	{

		fprintf(mFile,"\"%s.cws.cwsp\"",mName.c_str());
	}
	void getClumpWidthScale_FloatValue(size_t cws_i)const
	{
		fprintf(mFile,"\"%s.cws[%i].cwsfv\"",mName.c_str(),cws_i);
	}
	void getClumpWidthScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.cws.cwsfv\"",mName.c_str());
	}
	void getClumpWidthScale_Interp(size_t cws_i)const
	{
		fprintf(mFile,"\"%s.cws[%i].cwsi\"",mName.c_str(),cws_i);
	}
	void getClumpWidthScale_Interp()const
	{

		fprintf(mFile,"\"%s.cws.cwsi\"",mName.c_str());
	}
	void getStartCurveAttract()const
	{
		fprintf(mFile,"\"%s.sct\"",mName.c_str());
	}
	void getAttractionScale(size_t ats_i)const
	{
		fprintf(mFile,"\"%s.ats[%i]\"",mName.c_str(),ats_i);
	}
	void getAttractionScale()const
	{

		fprintf(mFile,"\"%s.ats\"",mName.c_str());
	}
	void getAttractionScale_Position(size_t ats_i)const
	{
		fprintf(mFile,"\"%s.ats[%i].atsp\"",mName.c_str(),ats_i);
	}
	void getAttractionScale_Position()const
	{

		fprintf(mFile,"\"%s.ats.atsp\"",mName.c_str());
	}
	void getAttractionScale_FloatValue(size_t ats_i)const
	{
		fprintf(mFile,"\"%s.ats[%i].atsfv\"",mName.c_str(),ats_i);
	}
	void getAttractionScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.ats.atsfv\"",mName.c_str());
	}
	void getAttractionScale_Interp(size_t ats_i)const
	{
		fprintf(mFile,"\"%s.ats[%i].atsi\"",mName.c_str(),ats_i);
	}
	void getAttractionScale_Interp()const
	{

		fprintf(mFile,"\"%s.ats.atsi\"",mName.c_str());
	}
	void getAttractionDamp()const
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());
	}
	void getDensityMult()const
	{
		fprintf(mFile,"\"%s.dml\"",mName.c_str());
	}
	void getCurlMult()const
	{
		fprintf(mFile,"\"%s.cml\"",mName.c_str());
	}
	void getClumpTwistOffset()const
	{
		fprintf(mFile,"\"%s.ctf\"",mName.c_str());
	}
	void getBraid()const
	{
		fprintf(mFile,"\"%s.brd\"",mName.c_str());
	}
	void getColorBlend()const
	{
		fprintf(mFile,"\"%s.cbl\"",mName.c_str());
	}
	void getColor()const
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getColorR()const
	{
		fprintf(mFile,"\"%s.cl.cr\"",mName.c_str());
	}
	void getColorG()const
	{
		fprintf(mFile,"\"%s.cl.cg\"",mName.c_str());
	}
	void getColorB()const
	{
		fprintf(mFile,"\"%s.cl.cb\"",mName.c_str());
	}
	void getFixedSegmentLength()const
	{
		fprintf(mFile,"\"%s.fsl\"",mName.c_str());
	}
	void getSegmentLength()const
	{
		fprintf(mFile,"\"%s.sgl\"",mName.c_str());
	}
	void getSampleDensity()const
	{
		fprintf(mFile,"\"%s.sdn\"",mName.c_str());
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.dgr\"",mName.c_str());
	}
	void getClumpWidth()const
	{
		fprintf(mFile,"\"%s.cw\"",mName.c_str());
	}
	void getOutTranslate()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getOutTranslateX()const
	{
		fprintf(mFile,"\"%s.ot.otx\"",mName.c_str());
	}
	void getOutTranslateY()const
	{
		fprintf(mFile,"\"%s.ot.oty\"",mName.c_str());
	}
	void getOutTranslateZ()const
	{
		fprintf(mFile,"\"%s.ot.otz\"",mName.c_str());
	}
	void getOutRotate()const
	{
		fprintf(mFile,"\"%s.or\"",mName.c_str());
	}
	void getOutRotateX()const
	{
		fprintf(mFile,"\"%s.or.orx\"",mName.c_str());
	}
	void getOutRotateY()const
	{
		fprintf(mFile,"\"%s.or.ory\"",mName.c_str());
	}
	void getOutRotateZ()const
	{
		fprintf(mFile,"\"%s.or.orz\"",mName.c_str());
	}
	void getOutTangent()const
	{
		fprintf(mFile,"\"%s.otn\"",mName.c_str());
	}
	void getOutTangentX()const
	{
		fprintf(mFile,"\"%s.otn.otnx\"",mName.c_str());
	}
	void getOutTangentY()const
	{
		fprintf(mFile,"\"%s.otn.otny\"",mName.c_str());
	}
	void getOutTangentZ()const
	{
		fprintf(mFile,"\"%s.otn.otnz\"",mName.c_str());
	}
	void getOutNormal()const
	{
		fprintf(mFile,"\"%s.onm\"",mName.c_str());
	}
	void getOutNormalX()const
	{
		fprintf(mFile,"\"%s.onm.onx\"",mName.c_str());
	}
	void getOutNormalY()const
	{
		fprintf(mFile,"\"%s.onm.ony\"",mName.c_str());
	}
	void getOutNormalZ()const
	{
		fprintf(mFile,"\"%s.onm.onz\"",mName.c_str());
	}
	void getOutHair()const
	{
		fprintf(mFile,"\"%s.oha\"",mName.c_str());
	}
	void getOutCurve()const
	{
		fprintf(mFile,"\"%s.ocr\"",mName.c_str());
	}
	void getValidUv()const
	{
		fprintf(mFile,"\"%s.vuv\"",mName.c_str());
	}
	void getMapSetName()const
	{
		fprintf(mFile,"\"%s.msn\"",mName.c_str());
	}
protected:
	Follicle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FOLLICLE_H__
