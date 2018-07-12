/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DYNAMICCONSTRAINT_H__
#define __MayaDM_DYNAMICCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class DynamicConstraint : public Shape
{
public:
	struct ConnectionDensityRange{
		float connectionDensityRange_Position;
		float connectionDensityRange_FloatValue;
		unsigned int connectionDensityRange_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", connectionDensityRange_Position);
			fprintf(file,"%f ", connectionDensityRange_FloatValue);
			fprintf(file,"%i", connectionDensityRange_Interp);
		}
	};
	struct StrengthDropoff{
		float strengthDropoff_Position;
		float strengthDropoff_FloatValue;
		unsigned int strengthDropoff_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", strengthDropoff_Position);
			fprintf(file,"%f ", strengthDropoff_FloatValue);
			fprintf(file,"%i", strengthDropoff_Interp);
		}
	};
public:

	DynamicConstraint():Shape(){}
	DynamicConstraint(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "dynamicConstraint", shared, create){}
	virtual ~DynamicConstraint(){}

	void setIsDynamic(bool isd)
	{
		if(isd == true) return;
		fprintf(mFile,"\tsetAttr \".isd\" %i;\n", isd);
	}
	void setEnable(bool ena)
	{
		if(ena == true) return;
		fprintf(mFile,"\tsetAttr \".ena\" %i;\n", ena);
	}
	void setConstraintMethod(unsigned int cm)
	{
		if(cm == 1) return;
		fprintf(mFile,"\tsetAttr \".cm\" %i;\n", cm);
	}
	void setConnectionMethod(unsigned int cnm)
	{
		if(cnm == 0) return;
		fprintf(mFile,"\tsetAttr \".cnm\" %i;\n", cnm);
	}
	void setConstraintRelation(unsigned int crr)
	{
		if(crr == 1) return;
		fprintf(mFile,"\tsetAttr \".crr\" %i;\n", crr);
	}
	void setComponentRelation(unsigned int cmr)
	{
		if(cmr == 0) return;
		fprintf(mFile,"\tsetAttr \".cmr\" %i;\n", cmr);
	}
	void setConnectionUpdate(unsigned int cu)
	{
		if(cu == 0) return;
		fprintf(mFile,"\tsetAttr \".cu\" %i;\n", cu);
	}
	void setConnectWithinComponent(bool cwc)
	{
		if(cwc == false) return;
		fprintf(mFile,"\tsetAttr \".cwc\" %i;\n", cwc);
	}
	void setConnectionDensity(double cdn)
	{
		if(cdn == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cdn\" %f;\n", cdn);
	}
	void setConnectionDensityRange(size_t cdnr_i,const ConnectionDensityRange& cdnr)
	{
		fprintf(mFile,"\tsetAttr \".cdnr[%i]\" ",cdnr_i);
		cdnr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setConnectionDensityRange(size_t cdnr_start,size_t cdnr_end,ConnectionDensityRange* cdnr)
	{
		fprintf(mFile,"\tsetAttr \".cdnr[%i:%i]\" ", cdnr_start,cdnr_end);
		size_t size = (cdnr_end-cdnr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cdnr[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startConnectionDensityRange(size_t cdnr_start,size_t cdnr_end)const
	{
		fprintf(mFile,"\tsetAttr \".cdnr[%i:%i]\"",cdnr_start,cdnr_end);
		fprintf(mFile," -type \"ConnectionDensityRange\" ");
	}
	void appendConnectionDensityRange(const ConnectionDensityRange& cdnr)const
	{
		fprintf(mFile," ");
		cdnr.write(mFile);
	}
	void endConnectionDensityRange()const
	{
		fprintf(mFile,";\n");
	}
	void setConnectionDensityRange_Position(size_t cdnr_i,float cdnrp)
	{
		if(cdnrp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cdnr[%i].cdnrp\" %f;\n", cdnr_i,cdnrp);
	}
	void setConnectionDensityRange_FloatValue(size_t cdnr_i,float cdnrfv)
	{
		if(cdnrfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cdnr[%i].cdnrfv\" %f;\n", cdnr_i,cdnrfv);
	}
	void setConnectionDensityRange_Interp(size_t cdnr_i,unsigned int cdnri)
	{
		if(cdnri == 0) return;
		fprintf(mFile,"\tsetAttr \".cdnr[%i].cdnri\" %i;\n", cdnr_i,cdnri);
	}
	void setDisplayConnections(bool dcn)
	{
		if(dcn == true) return;
		fprintf(mFile,"\tsetAttr \".dcn\" %i;\n", dcn);
	}
	void setStrength(double str)
	{
		if(str == 20.0) return;
		fprintf(mFile,"\tsetAttr \".str\" %f;\n", str);
	}
	void setRestLengthMethod(unsigned int rlm)
	{
		if(rlm == 0) return;
		fprintf(mFile,"\tsetAttr \".rlm\" %i;\n", rlm);
	}
	void setRestLength(double rl)
	{
		if(rl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rl\" %f;\n", rl);
	}
	void setRestLengthScale(double rls)
	{
		if(rls == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rls\" %f;\n", rls);
	}
	void setTangentStrength(double tst)
	{
		if(tst == 10) return;
		fprintf(mFile,"\tsetAttr \".tst\" %f;\n", tst);
	}
	void setBend(bool bnd)
	{
		if(bnd == false) return;
		fprintf(mFile,"\tsetAttr \".bnd\" %i;\n", bnd);
	}
	void setBendStrength(double bns)
	{
		if(bns == 20.0) return;
		fprintf(mFile,"\tsetAttr \".bns\" %f;\n", bns);
	}
	void setBendBreakAngle(double bba)
	{
		if(bba == 360.0) return;
		fprintf(mFile,"\tsetAttr \".bba\" %f;\n", bba);
	}
	void setGlueStrength(double gls)
	{
		if(gls == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gls\" %f;\n", gls);
	}
	void setGlueStrengthScale(double glss)
	{
		if(glss == 1.0) return;
		fprintf(mFile,"\tsetAttr \".glss\" %f;\n", glss);
	}
	void setForce(double for_)
	{
		if(for_ == 0.0) return;
		fprintf(mFile,"\tsetAttr \".for\" %f;\n", for_);
	}
	void setMotionDrag(double mdg)
	{
		if(mdg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mdg\" %f;\n", mdg);
	}
	void setDropoff(double drp)
	{
		if(drp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".drp\" %f;\n", drp);
	}
	void setDropoffDistance(double ddd)
	{
		if(ddd == 50.0) return;
		fprintf(mFile,"\tsetAttr \".ddd\" %f;\n", ddd);
	}
	void setStrengthDropoff(size_t sdp_i,const StrengthDropoff& sdp)
	{
		fprintf(mFile,"\tsetAttr \".sdp[%i]\" ",sdp_i);
		sdp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStrengthDropoff(size_t sdp_start,size_t sdp_end,StrengthDropoff* sdp)
	{
		fprintf(mFile,"\tsetAttr \".sdp[%i:%i]\" ", sdp_start,sdp_end);
		size_t size = (sdp_end-sdp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			sdp[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startStrengthDropoff(size_t sdp_start,size_t sdp_end)const
	{
		fprintf(mFile,"\tsetAttr \".sdp[%i:%i]\"",sdp_start,sdp_end);
		fprintf(mFile," -type \"StrengthDropoff\" ");
	}
	void appendStrengthDropoff(const StrengthDropoff& sdp)const
	{
		fprintf(mFile," ");
		sdp.write(mFile);
	}
	void endStrengthDropoff()const
	{
		fprintf(mFile,";\n");
	}
	void setStrengthDropoff_Position(size_t sdp_i,float sdpp)
	{
		if(sdpp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sdp[%i].sdpp\" %f;\n", sdp_i,sdpp);
	}
	void setStrengthDropoff_FloatValue(size_t sdp_i,float sdpfv)
	{
		if(sdpfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sdp[%i].sdpfv\" %f;\n", sdp_i,sdpfv);
	}
	void setStrengthDropoff_Interp(size_t sdp_i,unsigned int sdpi)
	{
		if(sdpi == 0) return;
		fprintf(mFile,"\tsetAttr \".sdp[%i].sdpi\" %i;\n", sdp_i,sdpi);
	}
	void setMaxDistance(double mds)
	{
		if(mds == 0.1) return;
		fprintf(mFile,"\tsetAttr \".mds\" %f;\n", mds);
	}
	void setDamp(double dmp)
	{
		if(dmp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dmp\" %f;\n", dmp);
	}
	void setFriction(double frc)
	{
		if(frc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".frc\" %f;\n", frc);
	}
	void setLocalCollide(bool lcl)
	{
		if(lcl == false) return;
		fprintf(mFile,"\tsetAttr \".lcl\" %i;\n", lcl);
	}
	void setCollideWidthScale(double cws)
	{
		if(cws == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cws\" %f;\n", cws);
	}
	void setExcludeCollisions(bool excs)
	{
		if(excs == false) return;
		fprintf(mFile,"\tsetAttr \".excs\" %i;\n", excs);
	}
	void setSingleSided(bool ssd)
	{
		if(ssd == true) return;
		fprintf(mFile,"\tsetAttr \".ssd\" %i;\n", ssd);
	}
	void setMaxIterations(int mitr)
	{
		if(mitr == 500) return;
		fprintf(mFile,"\tsetAttr \".mitr\" %i;\n", mitr);
	}
	void setMinIterations(int mini)
	{
		if(mini == 0) return;
		fprintf(mFile,"\tsetAttr \".mini\" %i;\n", mini);
	}
	void getIsDynamic()const
	{
		fprintf(mFile,"\"%s.isd\"",mName.c_str());
	}
	void getEnable()const
	{
		fprintf(mFile,"\"%s.ena\"",mName.c_str());
	}
	void getCurrentTime()const
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());
	}
	void getComponentIds(size_t cid_i)const
	{
		fprintf(mFile,"\"%s.cid[%i]\"",mName.c_str(),cid_i);
	}
	void getComponentIds()const
	{

		fprintf(mFile,"\"%s.cid\"",mName.c_str());
	}
	void getConstraintMethod()const
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());
	}
	void getConnectionMethod()const
	{
		fprintf(mFile,"\"%s.cnm\"",mName.c_str());
	}
	void getConstraintRelation()const
	{
		fprintf(mFile,"\"%s.crr\"",mName.c_str());
	}
	void getComponentRelation()const
	{
		fprintf(mFile,"\"%s.cmr\"",mName.c_str());
	}
	void getConnectionUpdate()const
	{
		fprintf(mFile,"\"%s.cu\"",mName.c_str());
	}
	void getConnectWithinComponent()const
	{
		fprintf(mFile,"\"%s.cwc\"",mName.c_str());
	}
	void getConnectionDensity()const
	{
		fprintf(mFile,"\"%s.cdn\"",mName.c_str());
	}
	void getConnectionDensityRange(size_t cdnr_i)const
	{
		fprintf(mFile,"\"%s.cdnr[%i]\"",mName.c_str(),cdnr_i);
	}
	void getConnectionDensityRange()const
	{

		fprintf(mFile,"\"%s.cdnr\"",mName.c_str());
	}
	void getConnectionDensityRange_Position(size_t cdnr_i)const
	{
		fprintf(mFile,"\"%s.cdnr[%i].cdnrp\"",mName.c_str(),cdnr_i);
	}
	void getConnectionDensityRange_Position()const
	{

		fprintf(mFile,"\"%s.cdnr.cdnrp\"",mName.c_str());
	}
	void getConnectionDensityRange_FloatValue(size_t cdnr_i)const
	{
		fprintf(mFile,"\"%s.cdnr[%i].cdnrfv\"",mName.c_str(),cdnr_i);
	}
	void getConnectionDensityRange_FloatValue()const
	{

		fprintf(mFile,"\"%s.cdnr.cdnrfv\"",mName.c_str());
	}
	void getConnectionDensityRange_Interp(size_t cdnr_i)const
	{
		fprintf(mFile,"\"%s.cdnr[%i].cdnri\"",mName.c_str(),cdnr_i);
	}
	void getConnectionDensityRange_Interp()const
	{

		fprintf(mFile,"\"%s.cdnr.cdnri\"",mName.c_str());
	}
	void getDisplayConnections()const
	{
		fprintf(mFile,"\"%s.dcn\"",mName.c_str());
	}
	void getStrength()const
	{
		fprintf(mFile,"\"%s.str\"",mName.c_str());
	}
	void getRestLengthMethod()const
	{
		fprintf(mFile,"\"%s.rlm\"",mName.c_str());
	}
	void getRestLength()const
	{
		fprintf(mFile,"\"%s.rl\"",mName.c_str());
	}
	void getRestLengthScale()const
	{
		fprintf(mFile,"\"%s.rls\"",mName.c_str());
	}
	void getTangentStrength()const
	{
		fprintf(mFile,"\"%s.tst\"",mName.c_str());
	}
	void getBend()const
	{
		fprintf(mFile,"\"%s.bnd\"",mName.c_str());
	}
	void getBendStrength()const
	{
		fprintf(mFile,"\"%s.bns\"",mName.c_str());
	}
	void getBendBreakAngle()const
	{
		fprintf(mFile,"\"%s.bba\"",mName.c_str());
	}
	void getGlueStrength()const
	{
		fprintf(mFile,"\"%s.gls\"",mName.c_str());
	}
	void getGlueStrengthScale()const
	{
		fprintf(mFile,"\"%s.glss\"",mName.c_str());
	}
	void getForce()const
	{
		fprintf(mFile,"\"%s.for\"",mName.c_str());
	}
	void getMotionDrag()const
	{
		fprintf(mFile,"\"%s.mdg\"",mName.c_str());
	}
	void getDropoff()const
	{
		fprintf(mFile,"\"%s.drp\"",mName.c_str());
	}
	void getDropoffDistance()const
	{
		fprintf(mFile,"\"%s.ddd\"",mName.c_str());
	}
	void getStrengthDropoff(size_t sdp_i)const
	{
		fprintf(mFile,"\"%s.sdp[%i]\"",mName.c_str(),sdp_i);
	}
	void getStrengthDropoff()const
	{

		fprintf(mFile,"\"%s.sdp\"",mName.c_str());
	}
	void getStrengthDropoff_Position(size_t sdp_i)const
	{
		fprintf(mFile,"\"%s.sdp[%i].sdpp\"",mName.c_str(),sdp_i);
	}
	void getStrengthDropoff_Position()const
	{

		fprintf(mFile,"\"%s.sdp.sdpp\"",mName.c_str());
	}
	void getStrengthDropoff_FloatValue(size_t sdp_i)const
	{
		fprintf(mFile,"\"%s.sdp[%i].sdpfv\"",mName.c_str(),sdp_i);
	}
	void getStrengthDropoff_FloatValue()const
	{

		fprintf(mFile,"\"%s.sdp.sdpfv\"",mName.c_str());
	}
	void getStrengthDropoff_Interp(size_t sdp_i)const
	{
		fprintf(mFile,"\"%s.sdp[%i].sdpi\"",mName.c_str(),sdp_i);
	}
	void getStrengthDropoff_Interp()const
	{

		fprintf(mFile,"\"%s.sdp.sdpi\"",mName.c_str());
	}
	void getMaxDistance()const
	{
		fprintf(mFile,"\"%s.mds\"",mName.c_str());
	}
	void getDamp()const
	{
		fprintf(mFile,"\"%s.dmp\"",mName.c_str());
	}
	void getFriction()const
	{
		fprintf(mFile,"\"%s.frc\"",mName.c_str());
	}
	void getLocalCollide()const
	{
		fprintf(mFile,"\"%s.lcl\"",mName.c_str());
	}
	void getCollideWidthScale()const
	{
		fprintf(mFile,"\"%s.cws\"",mName.c_str());
	}
	void getExcludeCollisions()const
	{
		fprintf(mFile,"\"%s.excs\"",mName.c_str());
	}
	void getSingleSided()const
	{
		fprintf(mFile,"\"%s.ssd\"",mName.c_str());
	}
	void getMaxIterations()const
	{
		fprintf(mFile,"\"%s.mitr\"",mName.c_str());
	}
	void getMinIterations()const
	{
		fprintf(mFile,"\"%s.mini\"",mName.c_str());
	}
	void getEvalStart(size_t evs_i)const
	{
		fprintf(mFile,"\"%s.evs[%i]\"",mName.c_str(),evs_i);
	}
	void getEvalStart()const
	{

		fprintf(mFile,"\"%s.evs\"",mName.c_str());
	}
	void getEvalCurrent(size_t evc_i)const
	{
		fprintf(mFile,"\"%s.evc[%i]\"",mName.c_str(),evc_i);
	}
	void getEvalCurrent()const
	{

		fprintf(mFile,"\"%s.evc\"",mName.c_str());
	}
	void getIterations()const
	{
		fprintf(mFile,"\"%s.itr\"",mName.c_str());
	}
	void getCollide()const
	{
		fprintf(mFile,"\"%s.cld\"",mName.c_str());
	}
protected:
	DynamicConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DYNAMICCONSTRAINT_H__
