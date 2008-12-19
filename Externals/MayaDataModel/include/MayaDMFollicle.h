/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Follicle(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "follicle"){}
	virtual ~Follicle(){}
	void setParameterU(double pu)
	{
		if(pu == 0.0) return;
		fprintf(mFile,"setAttr \".pu\" %f;\n", pu);

	}
	void setParameterV(double pv)
	{
		if(pv == 0.0) return;
		fprintf(mFile,"setAttr \".pv\" %f;\n", pv);

	}
	void setRestPose(unsigned int rsp)
	{
		if(rsp == 0) return;
		fprintf(mFile,"setAttr \".rsp\" %i;\n", rsp);

	}
	void setPointLock(unsigned int ptl)
	{
		if(ptl == 1) return;
		fprintf(mFile,"setAttr \".ptl\" %i;\n", ptl);

	}
	void setSimulationMethod(unsigned int sim)
	{
		if(sim == 2) return;
		fprintf(mFile,"setAttr \".sim\" %i;\n", sim);

	}
	void setStartDirection(unsigned int sdr)
	{
		if(sdr == 0) return;
		fprintf(mFile,"setAttr \".sdr\" %i;\n", sdr);

	}
	void setFlipDirection(bool fld)
	{
		if(fld == false) return;
		fprintf(mFile,"setAttr \".fld\" %i;\n", fld);

	}
	void setHairSysGravity(double hsg)
	{
		if(hsg == 1.0) return;
		fprintf(mFile,"setAttr \".hsg\" %f;\n", hsg);

	}
	void setHairSysStiffness(double hss)
	{
		if(hss == 0.5) return;
		fprintf(mFile,"setAttr \".hss\" %f;\n", hss);

	}
	void setOverrideDynamics(bool ovd)
	{
		if(ovd == false) return;
		fprintf(mFile,"setAttr \".ovd\" %i;\n", ovd);

	}
	void setCollide(bool cld)
	{
		if(cld == true) return;
		fprintf(mFile,"setAttr \".cld\" %i;\n", cld);

	}
	void setDamp(double dmp)
	{
		if(dmp == 0.0) return;
		fprintf(mFile,"setAttr \".dmp\" %f;\n", dmp);

	}
	void setStiffness(double stf)
	{
		if(stf == 0.15) return;
		fprintf(mFile,"setAttr \".stf\" %f;\n", stf);

	}
	void setStiffnessScale(size_t sts_i,const StiffnessScale& sts)
	{
		fprintf(mFile,"setAttr \".sts[%i]\" ",sts_i);
		sts.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStiffnessScale_Position(size_t sts_i,float stsp)
	{
		if(stsp == 0.0) return;
		fprintf(mFile,"setAttr \".sts[%i].stsp\" %f;\n", sts_i,stsp);

	}
	void setStiffnessScale_FloatValue(size_t sts_i,float stsfv)
	{
		if(stsfv == 0.0) return;
		fprintf(mFile,"setAttr \".sts[%i].stsfv\" %f;\n", sts_i,stsfv);

	}
	void setStiffnessScale_Interp(size_t sts_i,unsigned int stsi)
	{
		if(stsi == 0) return;
		fprintf(mFile,"setAttr \".sts[%i].stsi\" %i;\n", sts_i,stsi);

	}
	void setLengthFlex(double lfl)
	{
		if(lfl == 0.0) return;
		fprintf(mFile,"setAttr \".lfl\" %f;\n", lfl);

	}
	void setClumpWidthMult(double cwm)
	{
		if(cwm == 1.0) return;
		fprintf(mFile,"setAttr \".cwm\" %f;\n", cwm);

	}
	void setClumpWidthScale(size_t cws_i,const ClumpWidthScale& cws)
	{
		fprintf(mFile,"setAttr \".cws[%i]\" ",cws_i);
		cws.write(mFile);
		fprintf(mFile,";\n");

	}
	void setClumpWidthScale_Position(size_t cws_i,float cwsp)
	{
		if(cwsp == 0.0) return;
		fprintf(mFile,"setAttr \".cws[%i].cwsp\" %f;\n", cws_i,cwsp);

	}
	void setClumpWidthScale_FloatValue(size_t cws_i,float cwsfv)
	{
		if(cwsfv == 0.0) return;
		fprintf(mFile,"setAttr \".cws[%i].cwsfv\" %f;\n", cws_i,cwsfv);

	}
	void setClumpWidthScale_Interp(size_t cws_i,unsigned int cwsi)
	{
		if(cwsi == 0) return;
		fprintf(mFile,"setAttr \".cws[%i].cwsi\" %i;\n", cws_i,cwsi);

	}
	void setStartCurveAttract(double sct)
	{
		if(sct == 0.0) return;
		fprintf(mFile,"setAttr \".sct\" %f;\n", sct);

	}
	void setAttractionScale(size_t ats_i,const AttractionScale& ats)
	{
		fprintf(mFile,"setAttr \".ats[%i]\" ",ats_i);
		ats.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAttractionScale_Position(size_t ats_i,float atsp)
	{
		if(atsp == 0.0) return;
		fprintf(mFile,"setAttr \".ats[%i].atsp\" %f;\n", ats_i,atsp);

	}
	void setAttractionScale_FloatValue(size_t ats_i,float atsfv)
	{
		if(atsfv == 0.0) return;
		fprintf(mFile,"setAttr \".ats[%i].atsfv\" %f;\n", ats_i,atsfv);

	}
	void setAttractionScale_Interp(size_t ats_i,unsigned int atsi)
	{
		if(atsi == 0) return;
		fprintf(mFile,"setAttr \".ats[%i].atsi\" %i;\n", ats_i,atsi);

	}
	void setAttractionDamp(double ad)
	{
		if(ad == 0.0) return;
		fprintf(mFile,"setAttr \".ad\" %f;\n", ad);

	}
	void setDensityMult(double dml)
	{
		if(dml == 1.0) return;
		fprintf(mFile,"setAttr \".dml\" %f;\n", dml);

	}
	void setCurlMult(double cml)
	{
		if(cml == 1.0) return;
		fprintf(mFile,"setAttr \".cml\" %f;\n", cml);

	}
	void setClumpTwistOffset(double ctf)
	{
		if(ctf == 0.0) return;
		fprintf(mFile,"setAttr \".ctf\" %f;\n", ctf);

	}
	void setBraid(bool brd)
	{
		if(brd == false) return;
		fprintf(mFile,"setAttr \".brd\" %i;\n", brd);

	}
	void setColorBlend(double cbl)
	{
		if(cbl == 0.0) return;
		fprintf(mFile,"setAttr \".cbl\" %f;\n", cbl);

	}
	void setColor(const float3& cl)
	{
		fprintf(mFile,"setAttr \".cl\" -type \"float3\" ");
		cl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"setAttr \".cl.cr\" %f;\n", cr);

	}
	void setColorG(float cg)
	{
		if(cg == 0.0) return;
		fprintf(mFile,"setAttr \".cl.cg\" %f;\n", cg);

	}
	void setColorB(float cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"setAttr \".cl.cb\" %f;\n", cb);

	}
	void setFixedSegmentLength(bool fsl)
	{
		if(fsl == 0) return;
		fprintf(mFile,"setAttr \".fsl\" %i;\n", fsl);

	}
	void setSegmentLength(double sgl)
	{
		if(sgl == 1) return;
		fprintf(mFile,"setAttr \".sgl\" %f;\n", sgl);

	}
	void setSampleDensity(double sdn)
	{
		if(sdn == 1.0) return;
		fprintf(mFile,"setAttr \".sdn\" %f;\n", sdn);

	}
	void setDegree(int dgr)
	{
		if(dgr == 2) return;
		fprintf(mFile,"setAttr \".dgr\" %i;\n", dgr);

	}
	void setClumpWidth(float cw)
	{
		if(cw == 0.3) return;
		fprintf(mFile,"setAttr \".cw\" %f;\n", cw);

	}
	void setMapSetName(const string& msn)
	{
		if(msn == "NULL") return;
		fprintf(mFile,"setAttr \".msn\" -type \"string\" ");
		msn.write(mFile);
		fprintf(mFile,";\n");

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getInputMesh()
	{
		fprintf(mFile,"\"%s.inm\"",mName.c_str());

	}
	void getInputWorldMatrix()
	{
		fprintf(mFile,"\"%s.iwm\"",mName.c_str());

	}
	void getParameterU()
	{
		fprintf(mFile,"\"%s.pu\"",mName.c_str());

	}
	void getParameterV()
	{
		fprintf(mFile,"\"%s.pv\"",mName.c_str());

	}
	void getStartPosition()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getRestPosition()
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());

	}
	void getCurrentPosition()
	{
		fprintf(mFile,"\"%s.crp\"",mName.c_str());

	}
	void getRestPose()
	{
		fprintf(mFile,"\"%s.rsp\"",mName.c_str());

	}
	void getPointLock()
	{
		fprintf(mFile,"\"%s.ptl\"",mName.c_str());

	}
	void getSimulationMethod()
	{
		fprintf(mFile,"\"%s.sim\"",mName.c_str());

	}
	void getStartDirection()
	{
		fprintf(mFile,"\"%s.sdr\"",mName.c_str());

	}
	void getFlipDirection()
	{
		fprintf(mFile,"\"%s.fld\"",mName.c_str());

	}
	void getHairSysGravity()
	{
		fprintf(mFile,"\"%s.hsg\"",mName.c_str());

	}
	void getHairSysStiffness()
	{
		fprintf(mFile,"\"%s.hss\"",mName.c_str());

	}
	void getOverrideDynamics()
	{
		fprintf(mFile,"\"%s.ovd\"",mName.c_str());

	}
	void getCollide()
	{
		fprintf(mFile,"\"%s.cld\"",mName.c_str());

	}
	void getDamp()
	{
		fprintf(mFile,"\"%s.dmp\"",mName.c_str());

	}
	void getStiffness()
	{
		fprintf(mFile,"\"%s.stf\"",mName.c_str());

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
		fprintf(mFile,"\"%s.lfl\"",mName.c_str());

	}
	void getClumpWidthMult()
	{
		fprintf(mFile,"\"%s.cwm\"",mName.c_str());

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
	void getAttractionDamp()
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());

	}
	void getDensityMult()
	{
		fprintf(mFile,"\"%s.dml\"",mName.c_str());

	}
	void getCurlMult()
	{
		fprintf(mFile,"\"%s.cml\"",mName.c_str());

	}
	void getClumpTwistOffset()
	{
		fprintf(mFile,"\"%s.ctf\"",mName.c_str());

	}
	void getBraid()
	{
		fprintf(mFile,"\"%s.brd\"",mName.c_str());

	}
	void getColorBlend()
	{
		fprintf(mFile,"\"%s.cbl\"",mName.c_str());

	}
	void getColor()
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());

	}
	void getColorR()
	{
		fprintf(mFile,"\"%s.cl.cr\"",mName.c_str());

	}
	void getColorG()
	{
		fprintf(mFile,"\"%s.cl.cg\"",mName.c_str());

	}
	void getColorB()
	{
		fprintf(mFile,"\"%s.cl.cb\"",mName.c_str());

	}
	void getFixedSegmentLength()
	{
		fprintf(mFile,"\"%s.fsl\"",mName.c_str());

	}
	void getSegmentLength()
	{
		fprintf(mFile,"\"%s.sgl\"",mName.c_str());

	}
	void getSampleDensity()
	{
		fprintf(mFile,"\"%s.sdn\"",mName.c_str());

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.dgr\"",mName.c_str());

	}
	void getClumpWidth()
	{
		fprintf(mFile,"\"%s.cw\"",mName.c_str());

	}
	void getOutTranslate()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getOutTranslateX()
	{
		fprintf(mFile,"\"%s.ot.otx\"",mName.c_str());

	}
	void getOutTranslateY()
	{
		fprintf(mFile,"\"%s.ot.oty\"",mName.c_str());

	}
	void getOutTranslateZ()
	{
		fprintf(mFile,"\"%s.ot.otz\"",mName.c_str());

	}
	void getOutRotate()
	{
		fprintf(mFile,"\"%s.or\"",mName.c_str());

	}
	void getOutRotateX()
	{
		fprintf(mFile,"\"%s.or.orx\"",mName.c_str());

	}
	void getOutRotateY()
	{
		fprintf(mFile,"\"%s.or.ory\"",mName.c_str());

	}
	void getOutRotateZ()
	{
		fprintf(mFile,"\"%s.or.orz\"",mName.c_str());

	}
	void getOutTangent()
	{
		fprintf(mFile,"\"%s.otn\"",mName.c_str());

	}
	void getOutTangentX()
	{
		fprintf(mFile,"\"%s.otn.otnx\"",mName.c_str());

	}
	void getOutTangentY()
	{
		fprintf(mFile,"\"%s.otn.otny\"",mName.c_str());

	}
	void getOutTangentZ()
	{
		fprintf(mFile,"\"%s.otn.otnz\"",mName.c_str());

	}
	void getOutNormal()
	{
		fprintf(mFile,"\"%s.onm\"",mName.c_str());

	}
	void getOutNormalX()
	{
		fprintf(mFile,"\"%s.onm.onx\"",mName.c_str());

	}
	void getOutNormalY()
	{
		fprintf(mFile,"\"%s.onm.ony\"",mName.c_str());

	}
	void getOutNormalZ()
	{
		fprintf(mFile,"\"%s.onm.onz\"",mName.c_str());

	}
	void getOutHair()
	{
		fprintf(mFile,"\"%s.oha\"",mName.c_str());

	}
	void getOutCurve()
	{
		fprintf(mFile,"\"%s.ocr\"",mName.c_str());

	}
	void getValidUv()
	{
		fprintf(mFile,"\"%s.vuv\"",mName.c_str());

	}
	void getMapSetName()
	{
		fprintf(mFile,"\"%s.msn\"",mName.c_str());

	}
protected:
	Follicle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FOLLICLE_H__
