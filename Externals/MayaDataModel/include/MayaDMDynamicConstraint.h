/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	DynamicConstraint(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "dynamicConstraint"){}
	virtual ~DynamicConstraint(){}
	void setIsDynamic(bool isd)
	{
		if(isd == true) return;
		fprintf(mFile,"setAttr \".isd\" %i;\n", isd);

	}
	void setEnable(bool ena)
	{
		if(ena == true) return;
		fprintf(mFile,"setAttr \".ena\" %i;\n", ena);

	}
	void setConstraintMethod(unsigned int cm)
	{
		if(cm == 1) return;
		fprintf(mFile,"setAttr \".cm\" %i;\n", cm);

	}
	void setConnectionMethod(unsigned int cnm)
	{
		if(cnm == 0) return;
		fprintf(mFile,"setAttr \".cnm\" %i;\n", cnm);

	}
	void setConstraintRelation(unsigned int crr)
	{
		if(crr == 1) return;
		fprintf(mFile,"setAttr \".crr\" %i;\n", crr);

	}
	void setComponentRelation(unsigned int cmr)
	{
		if(cmr == 0) return;
		fprintf(mFile,"setAttr \".cmr\" %i;\n", cmr);

	}
	void setConnectionUpdate(unsigned int cu)
	{
		if(cu == 0) return;
		fprintf(mFile,"setAttr \".cu\" %i;\n", cu);

	}
	void setConnectWithinComponent(bool cwc)
	{
		if(cwc == false) return;
		fprintf(mFile,"setAttr \".cwc\" %i;\n", cwc);

	}
	void setConnectionDensity(double cdn)
	{
		if(cdn == 1.0) return;
		fprintf(mFile,"setAttr \".cdn\" %f;\n", cdn);

	}
	void setConnectionDensityRange(size_t cdnr_i,const ConnectionDensityRange& cdnr)
	{
		fprintf(mFile,"setAttr \".cdnr[%i]\" ",cdnr_i);
		cdnr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setConnectionDensityRange_Position(size_t cdnr_i,float cdnrp)
	{
		if(cdnrp == 0.0) return;
		fprintf(mFile,"setAttr \".cdnr[%i].cdnrp\" %f;\n", cdnr_i,cdnrp);

	}
	void setConnectionDensityRange_FloatValue(size_t cdnr_i,float cdnrfv)
	{
		if(cdnrfv == 0.0) return;
		fprintf(mFile,"setAttr \".cdnr[%i].cdnrfv\" %f;\n", cdnr_i,cdnrfv);

	}
	void setConnectionDensityRange_Interp(size_t cdnr_i,unsigned int cdnri)
	{
		if(cdnri == 0) return;
		fprintf(mFile,"setAttr \".cdnr[%i].cdnri\" %i;\n", cdnr_i,cdnri);

	}
	void setDisplayConnections(bool dcn)
	{
		if(dcn == true) return;
		fprintf(mFile,"setAttr \".dcn\" %i;\n", dcn);

	}
	void setStrength(double str)
	{
		if(str == 20.0) return;
		fprintf(mFile,"setAttr \".str\" %f;\n", str);

	}
	void setRestLengthMethod(unsigned int rlm)
	{
		if(rlm == 0) return;
		fprintf(mFile,"setAttr \".rlm\" %i;\n", rlm);

	}
	void setRestLength(double rl)
	{
		if(rl == 0.0) return;
		fprintf(mFile,"setAttr \".rl\" %f;\n", rl);

	}
	void setRestLengthScale(double rls)
	{
		if(rls == 1.0) return;
		fprintf(mFile,"setAttr \".rls\" %f;\n", rls);

	}
	void setTangentStrength(double tst)
	{
		if(tst == 10) return;
		fprintf(mFile,"setAttr \".tst\" %f;\n", tst);

	}
	void setBend(bool bnd)
	{
		if(bnd == false) return;
		fprintf(mFile,"setAttr \".bnd\" %i;\n", bnd);

	}
	void setBendStrength(double bns)
	{
		if(bns == 20.0) return;
		fprintf(mFile,"setAttr \".bns\" %f;\n", bns);

	}
	void setBendBreakAngle(double bba)
	{
		if(bba == 360.0) return;
		fprintf(mFile,"setAttr \".bba\" %f;\n", bba);

	}
	void setGlueStrength(double gls)
	{
		if(gls == 1.0) return;
		fprintf(mFile,"setAttr \".gls\" %f;\n", gls);

	}
	void setGlueStrengthScale(double glss)
	{
		if(glss == 1.0) return;
		fprintf(mFile,"setAttr \".glss\" %f;\n", glss);

	}
	void setForce(double for_)
	{
		if(for_ == 0.0) return;
		fprintf(mFile,"setAttr \".for\" %f;\n", for_);

	}
	void setMotionDrag(double mdg)
	{
		if(mdg == 0.0) return;
		fprintf(mFile,"setAttr \".mdg\" %f;\n", mdg);

	}
	void setDropoff(double drp)
	{
		if(drp == 1.0) return;
		fprintf(mFile,"setAttr \".drp\" %f;\n", drp);

	}
	void setDropoffDistance(double ddd)
	{
		if(ddd == 50.0) return;
		fprintf(mFile,"setAttr \".ddd\" %f;\n", ddd);

	}
	void setStrengthDropoff(size_t sdp_i,const StrengthDropoff& sdp)
	{
		fprintf(mFile,"setAttr \".sdp[%i]\" ",sdp_i);
		sdp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStrengthDropoff_Position(size_t sdp_i,float sdpp)
	{
		if(sdpp == 0.0) return;
		fprintf(mFile,"setAttr \".sdp[%i].sdpp\" %f;\n", sdp_i,sdpp);

	}
	void setStrengthDropoff_FloatValue(size_t sdp_i,float sdpfv)
	{
		if(sdpfv == 0.0) return;
		fprintf(mFile,"setAttr \".sdp[%i].sdpfv\" %f;\n", sdp_i,sdpfv);

	}
	void setStrengthDropoff_Interp(size_t sdp_i,unsigned int sdpi)
	{
		if(sdpi == 0) return;
		fprintf(mFile,"setAttr \".sdp[%i].sdpi\" %i;\n", sdp_i,sdpi);

	}
	void setMaxDistance(double mds)
	{
		if(mds == 0.1) return;
		fprintf(mFile,"setAttr \".mds\" %f;\n", mds);

	}
	void setDamp(double dmp)
	{
		if(dmp == 0.0) return;
		fprintf(mFile,"setAttr \".dmp\" %f;\n", dmp);

	}
	void setFriction(double frc)
	{
		if(frc == 0.0) return;
		fprintf(mFile,"setAttr \".frc\" %f;\n", frc);

	}
	void setLocalCollide(bool lcl)
	{
		if(lcl == false) return;
		fprintf(mFile,"setAttr \".lcl\" %i;\n", lcl);

	}
	void setCollideWidthScale(double cws)
	{
		if(cws == 1.0) return;
		fprintf(mFile,"setAttr \".cws\" %f;\n", cws);

	}
	void setExcludeCollisions(bool excs)
	{
		if(excs == false) return;
		fprintf(mFile,"setAttr \".excs\" %i;\n", excs);

	}
	void setSingleSided(bool ssd)
	{
		if(ssd == true) return;
		fprintf(mFile,"setAttr \".ssd\" %i;\n", ssd);

	}
	void setMaxIterations(int mitr)
	{
		if(mitr == 500) return;
		fprintf(mFile,"setAttr \".mitr\" %i;\n", mitr);

	}
	void setMinIterations(int mini)
	{
		if(mini == 0) return;
		fprintf(mFile,"setAttr \".mini\" %i;\n", mini);

	}
	void getIsDynamic()
	{
		fprintf(mFile,"\"%s.isd\"",mName.c_str());

	}
	void getEnable()
	{
		fprintf(mFile,"\"%s.ena\"",mName.c_str());

	}
	void getCurrentTime()
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());

	}
	void getComponentIds(size_t cid_i)
	{
		fprintf(mFile,"\"%s.cid[%i]\"",mName.c_str(),cid_i);

	}
	void getConstraintMethod()
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());

	}
	void getConnectionMethod()
	{
		fprintf(mFile,"\"%s.cnm\"",mName.c_str());

	}
	void getConstraintRelation()
	{
		fprintf(mFile,"\"%s.crr\"",mName.c_str());

	}
	void getComponentRelation()
	{
		fprintf(mFile,"\"%s.cmr\"",mName.c_str());

	}
	void getConnectionUpdate()
	{
		fprintf(mFile,"\"%s.cu\"",mName.c_str());

	}
	void getConnectWithinComponent()
	{
		fprintf(mFile,"\"%s.cwc\"",mName.c_str());

	}
	void getConnectionDensity()
	{
		fprintf(mFile,"\"%s.cdn\"",mName.c_str());

	}
	void getConnectionDensityRange(size_t cdnr_i)
	{
		fprintf(mFile,"\"%s.cdnr[%i]\"",mName.c_str(),cdnr_i);

	}
	void getConnectionDensityRange_Position(size_t cdnr_i)
	{
		fprintf(mFile,"\"%s.cdnr[%i].cdnrp\"",mName.c_str(),cdnr_i);

	}
	void getConnectionDensityRange_FloatValue(size_t cdnr_i)
	{
		fprintf(mFile,"\"%s.cdnr[%i].cdnrfv\"",mName.c_str(),cdnr_i);

	}
	void getConnectionDensityRange_Interp(size_t cdnr_i)
	{
		fprintf(mFile,"\"%s.cdnr[%i].cdnri\"",mName.c_str(),cdnr_i);

	}
	void getDisplayConnections()
	{
		fprintf(mFile,"\"%s.dcn\"",mName.c_str());

	}
	void getStrength()
	{
		fprintf(mFile,"\"%s.str\"",mName.c_str());

	}
	void getRestLengthMethod()
	{
		fprintf(mFile,"\"%s.rlm\"",mName.c_str());

	}
	void getRestLength()
	{
		fprintf(mFile,"\"%s.rl\"",mName.c_str());

	}
	void getRestLengthScale()
	{
		fprintf(mFile,"\"%s.rls\"",mName.c_str());

	}
	void getTangentStrength()
	{
		fprintf(mFile,"\"%s.tst\"",mName.c_str());

	}
	void getBend()
	{
		fprintf(mFile,"\"%s.bnd\"",mName.c_str());

	}
	void getBendStrength()
	{
		fprintf(mFile,"\"%s.bns\"",mName.c_str());

	}
	void getBendBreakAngle()
	{
		fprintf(mFile,"\"%s.bba\"",mName.c_str());

	}
	void getGlueStrength()
	{
		fprintf(mFile,"\"%s.gls\"",mName.c_str());

	}
	void getGlueStrengthScale()
	{
		fprintf(mFile,"\"%s.glss\"",mName.c_str());

	}
	void getForce()
	{
		fprintf(mFile,"\"%s.for\"",mName.c_str());

	}
	void getMotionDrag()
	{
		fprintf(mFile,"\"%s.mdg\"",mName.c_str());

	}
	void getDropoff()
	{
		fprintf(mFile,"\"%s.drp\"",mName.c_str());

	}
	void getDropoffDistance()
	{
		fprintf(mFile,"\"%s.ddd\"",mName.c_str());

	}
	void getStrengthDropoff(size_t sdp_i)
	{
		fprintf(mFile,"\"%s.sdp[%i]\"",mName.c_str(),sdp_i);

	}
	void getStrengthDropoff_Position(size_t sdp_i)
	{
		fprintf(mFile,"\"%s.sdp[%i].sdpp\"",mName.c_str(),sdp_i);

	}
	void getStrengthDropoff_FloatValue(size_t sdp_i)
	{
		fprintf(mFile,"\"%s.sdp[%i].sdpfv\"",mName.c_str(),sdp_i);

	}
	void getStrengthDropoff_Interp(size_t sdp_i)
	{
		fprintf(mFile,"\"%s.sdp[%i].sdpi\"",mName.c_str(),sdp_i);

	}
	void getMaxDistance()
	{
		fprintf(mFile,"\"%s.mds\"",mName.c_str());

	}
	void getDamp()
	{
		fprintf(mFile,"\"%s.dmp\"",mName.c_str());

	}
	void getFriction()
	{
		fprintf(mFile,"\"%s.frc\"",mName.c_str());

	}
	void getLocalCollide()
	{
		fprintf(mFile,"\"%s.lcl\"",mName.c_str());

	}
	void getCollideWidthScale()
	{
		fprintf(mFile,"\"%s.cws\"",mName.c_str());

	}
	void getExcludeCollisions()
	{
		fprintf(mFile,"\"%s.excs\"",mName.c_str());

	}
	void getSingleSided()
	{
		fprintf(mFile,"\"%s.ssd\"",mName.c_str());

	}
	void getMaxIterations()
	{
		fprintf(mFile,"\"%s.mitr\"",mName.c_str());

	}
	void getMinIterations()
	{
		fprintf(mFile,"\"%s.mini\"",mName.c_str());

	}
	void getEvalStart(size_t evs_i)
	{
		fprintf(mFile,"\"%s.evs[%i]\"",mName.c_str(),evs_i);

	}
	void getEvalCurrent(size_t evc_i)
	{
		fprintf(mFile,"\"%s.evc[%i]\"",mName.c_str(),evc_i);

	}
	void getIterations()
	{
		fprintf(mFile,"\"%s.itr\"",mName.c_str());

	}
	void getCollide()
	{
		fprintf(mFile,"\"%s.cld\"",mName.c_str());

	}
protected:
	DynamicConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DYNAMICCONSTRAINT_H__
