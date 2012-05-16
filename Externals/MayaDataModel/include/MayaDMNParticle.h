/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NPARTICLE_H__
#define __MayaDM_NPARTICLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMParticle.h"
namespace MayaDM
{
class NParticle : public Particle
{
public:
public:

	NParticle():Particle(){}
	NParticle(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Particle(file, name, parent, "nParticle", shared, create){}
	virtual ~NParticle(){}

	void setPlayFromCache(bool pfc)
	{
		if(pfc == false) return;
		fprintf(mFile,"\tsetAttr \".pfc\" %i;\n", pfc);
	}
	void setStartPositions(const vectorArray& spns)
	{
		if(spns.size == 0) return;
		fprintf(mFile,"\tsetAttr \".spns\" -type \"vectorArray\" ");
		spns.write(mFile);
		fprintf(mFile,";\n");
	}
	void setStartVelocities(const vectorArray& sves)
	{
		if(sves.size == 0) return;
		fprintf(mFile,"\tsetAttr \".sves\" -type \"vectorArray\" ");
		sves.write(mFile);
		fprintf(mFile,";\n");
	}
	void setThickness(float thss)
	{
		if(thss == 0.1) return;
		fprintf(mFile,"\tsetAttr \".thss\" %f;\n", thss);
	}
	void setThicknessMap(float thmp)
	{
		if(thmp == 0.1) return;
		fprintf(mFile,"\tsetAttr \".thmp\" %f;\n", thmp);
	}
	void setThicknessPerVertex(const doubleArray& thpv)
	{
		if(thpv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".thpv\" -type \"doubleArray\" ");
		thpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBounce(float boce)
	{
		if(boce == 0.0) return;
		fprintf(mFile,"\tsetAttr \".boce\" %f;\n", boce);
	}
	void setBounceMap(float bomp)
	{
		if(bomp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bomp\" %f;\n", bomp);
	}
	void setBouncePerVertex(const doubleArray& bpv)
	{
		if(bpv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".bpv\" -type \"doubleArray\" ");
		bpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFriction(float fron)
	{
		if(fron == 0.1) return;
		fprintf(mFile,"\tsetAttr \".fron\" %f;\n", fron);
	}
	void setFrictionMap(float frmp)
	{
		if(frmp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".frmp\" %f;\n", frmp);
	}
	void setFrictionPerVertex(const doubleArray& fpv)
	{
		if(fpv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".fpv\" -type \"doubleArray\" ");
		fpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDamp(float adng)
	{
		if(adng == 0.0) return;
		fprintf(mFile,"\tsetAttr \".adng\" %f;\n", adng);
	}
	void setDampMap(float admp)
	{
		if(admp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".admp\" %f;\n", admp);
	}
	void setDampPerVertex(const doubleArray& dpv)
	{
		if(dpv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".dpv\" -type \"doubleArray\" ");
		dpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCollisionFlag(unsigned int cofl)
	{
		if(cofl == 2) return;
		fprintf(mFile,"\tsetAttr \".cofl\" %i;\n", cofl);
	}
	void setSelfCollisionFlag(unsigned int scfl)
	{
		if(scfl == 0) return;
		fprintf(mFile,"\tsetAttr \".scfl\" %i;\n", scfl);
	}
	void setMaxSelfCollisionIterations(int msci)
	{
		if(msci == 4) return;
		fprintf(mFile,"\tsetAttr \".msci\" %i;\n", msci);
	}
	void setMaxIterations(int mxit)
	{
		if(mxit == 500) return;
		fprintf(mFile,"\tsetAttr \".mxit\" %i;\n", mxit);
	}
	void setPointMass(float pmss)
	{
		if(pmss == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pmss\" %f;\n", pmss);
	}
	void setMassMap(float mamp)
	{
		if(mamp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mamp\" %f;\n", mamp);
	}
	void setMassPerVertex(const doubleArray& mpv)
	{
		if(mpv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".mpv\" -type \"doubleArray\" ");
		mpv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRestLengthScale(float rlsc)
	{
		if(rlsc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rlsc\" %f;\n", rlsc);
	}
	void setActive(bool actv)
	{
		if(actv == 1) return;
		fprintf(mFile,"\tsetAttr \".actv\" %i;\n", actv);
	}
	void setCollide(bool cold)
	{
		if(cold == 1) return;
		fprintf(mFile,"\tsetAttr \".cold\" %i;\n", cold);
	}
	void setSelfCollide(bool scld)
	{
		if(scld == 1) return;
		fprintf(mFile,"\tsetAttr \".scld\" %i;\n", scld);
	}
	void setCollisionLayer(float cll)
	{
		if(cll == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cll\" %f;\n", cll);
	}
	void setWindShadowDiffusion(float wsdi)
	{
		if(wsdi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wsdi\" %f;\n", wsdi);
	}
	void setWindShadowDistance(float wsds)
	{
		if(wsds == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wsds\" %f;\n", wsds);
	}
	void setAirPushDistance(float apds)
	{
		if(apds == 0.0) return;
		fprintf(mFile,"\tsetAttr \".apds\" %f;\n", apds);
	}
	void setAirPushVorticity(float apvy)
	{
		if(apvy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".apvy\" %f;\n", apvy);
	}
	void setPushOut(float pou)
	{
		if(pou == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pou\" %f;\n", pou);
	}
	void setPushOutRadius(float por)
	{
		if(por == 10.0) return;
		fprintf(mFile,"\tsetAttr \".por\" %f;\n", por);
	}
	void setCrossoverPush(float cop)
	{
		if(cop == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cop\" %f;\n", cop);
	}
	void setTrappedCheck(bool tpc)
	{
		if(tpc == 0) return;
		fprintf(mFile,"\tsetAttr \".tpc\" %i;\n", tpc);
	}
	void setThicknessMapType(unsigned int tmt)
	{
		if(tmt == 2) return;
		fprintf(mFile,"\tsetAttr \".tmt\" %i;\n", tmt);
	}
	void setBounceMapType(unsigned int bmt)
	{
		if(bmt == 2) return;
		fprintf(mFile,"\tsetAttr \".bmt\" %i;\n", bmt);
	}
	void setFrictionMapType(unsigned int fmt)
	{
		if(fmt == 2) return;
		fprintf(mFile,"\tsetAttr \".fmt\" %i;\n", fmt);
	}
	void setDampMapType(unsigned int dmt)
	{
		if(dmt == 2) return;
		fprintf(mFile,"\tsetAttr \".dmt\" %i;\n", dmt);
	}
	void setMassMapType(unsigned int mmt)
	{
		if(mmt == 2) return;
		fprintf(mFile,"\tsetAttr \".mmt\" %i;\n", mmt);
	}
	void setLocalSpaceOutput(bool lsou)
	{
		if(lsou == 0) return;
		fprintf(mFile,"\tsetAttr \".lsou\" %i;\n", lsou);
	}
	void setDisplayColor(const float3& dcl)
	{
		fprintf(mFile,"\tsetAttr \".dcl\" -type \"float3\" ");
		dcl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDisplayColorR(float dcr)
	{
		if(dcr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dcl.dcr\" %f;\n", dcr);
	}
	void setDisplayColorG(float dcg)
	{
		if(dcg == 0.8) return;
		fprintf(mFile,"\tsetAttr \".dcl.dcg\" %f;\n", dcg);
	}
	void setDisplayColorB(float dcb)
	{
		if(dcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dcl.dcb\" %f;\n", dcb);
	}
	void getInputMesh()const
	{
		fprintf(mFile,"\"%s.imsh\"",mName.c_str());
	}
	void getPositions()const
	{
		fprintf(mFile,"\"%s.poss\"",mName.c_str());
	}
	void getPlayFromCache()const
	{
		fprintf(mFile,"\"%s.pfc\"",mName.c_str());
	}
	void getStartPositions()const
	{
		fprintf(mFile,"\"%s.spns\"",mName.c_str());
	}
	void getStartVelocities()const
	{
		fprintf(mFile,"\"%s.sves\"",mName.c_str());
	}
	void getThickness()const
	{
		fprintf(mFile,"\"%s.thss\"",mName.c_str());
	}
	void getThicknessMap()const
	{
		fprintf(mFile,"\"%s.thmp\"",mName.c_str());
	}
	void getThicknessPerVertex()const
	{
		fprintf(mFile,"\"%s.thpv\"",mName.c_str());
	}
	void getBounce()const
	{
		fprintf(mFile,"\"%s.boce\"",mName.c_str());
	}
	void getBounceMap()const
	{
		fprintf(mFile,"\"%s.bomp\"",mName.c_str());
	}
	void getBouncePerVertex()const
	{
		fprintf(mFile,"\"%s.bpv\"",mName.c_str());
	}
	void getFriction()const
	{
		fprintf(mFile,"\"%s.fron\"",mName.c_str());
	}
	void getFrictionMap()const
	{
		fprintf(mFile,"\"%s.frmp\"",mName.c_str());
	}
	void getFrictionPerVertex()const
	{
		fprintf(mFile,"\"%s.fpv\"",mName.c_str());
	}
	void getDamp()const
	{
		fprintf(mFile,"\"%s.adng\"",mName.c_str());
	}
	void getDampMap()const
	{
		fprintf(mFile,"\"%s.admp\"",mName.c_str());
	}
	void getDampPerVertex()const
	{
		fprintf(mFile,"\"%s.dpv\"",mName.c_str());
	}
	void getCollisionFlag()const
	{
		fprintf(mFile,"\"%s.cofl\"",mName.c_str());
	}
	void getSelfCollisionFlag()const
	{
		fprintf(mFile,"\"%s.scfl\"",mName.c_str());
	}
	void getMaxSelfCollisionIterations()const
	{
		fprintf(mFile,"\"%s.msci\"",mName.c_str());
	}
	void getMaxIterations()const
	{
		fprintf(mFile,"\"%s.mxit\"",mName.c_str());
	}
	void getPointMass()const
	{
		fprintf(mFile,"\"%s.pmss\"",mName.c_str());
	}
	void getMassMap()const
	{
		fprintf(mFile,"\"%s.mamp\"",mName.c_str());
	}
	void getMassPerVertex()const
	{
		fprintf(mFile,"\"%s.mpv\"",mName.c_str());
	}
	void getRestLengthScale()const
	{
		fprintf(mFile,"\"%s.rlsc\"",mName.c_str());
	}
	void getActive()const
	{
		fprintf(mFile,"\"%s.actv\"",mName.c_str());
	}
	void getCollide()const
	{
		fprintf(mFile,"\"%s.cold\"",mName.c_str());
	}
	void getSelfCollide()const
	{
		fprintf(mFile,"\"%s.scld\"",mName.c_str());
	}
	void getCollisionLayer()const
	{
		fprintf(mFile,"\"%s.cll\"",mName.c_str());
	}
	void getWindShadowDiffusion()const
	{
		fprintf(mFile,"\"%s.wsdi\"",mName.c_str());
	}
	void getWindShadowDistance()const
	{
		fprintf(mFile,"\"%s.wsds\"",mName.c_str());
	}
	void getAirPushDistance()const
	{
		fprintf(mFile,"\"%s.apds\"",mName.c_str());
	}
	void getAirPushVorticity()const
	{
		fprintf(mFile,"\"%s.apvy\"",mName.c_str());
	}
	void getPushOut()const
	{
		fprintf(mFile,"\"%s.pou\"",mName.c_str());
	}
	void getPushOutRadius()const
	{
		fprintf(mFile,"\"%s.por\"",mName.c_str());
	}
	void getCrossoverPush()const
	{
		fprintf(mFile,"\"%s.cop\"",mName.c_str());
	}
	void getTrappedCheck()const
	{
		fprintf(mFile,"\"%s.tpc\"",mName.c_str());
	}
	void getThicknessMapType()const
	{
		fprintf(mFile,"\"%s.tmt\"",mName.c_str());
	}
	void getBounceMapType()const
	{
		fprintf(mFile,"\"%s.bmt\"",mName.c_str());
	}
	void getFrictionMapType()const
	{
		fprintf(mFile,"\"%s.fmt\"",mName.c_str());
	}
	void getDampMapType()const
	{
		fprintf(mFile,"\"%s.dmt\"",mName.c_str());
	}
	void getMassMapType()const
	{
		fprintf(mFile,"\"%s.mmt\"",mName.c_str());
	}
	void getNextState()const
	{
		fprintf(mFile,"\"%s.nxst\"",mName.c_str());
	}
	void getCurrentState()const
	{
		fprintf(mFile,"\"%s.cust\"",mName.c_str());
	}
	void getStartState()const
	{
		fprintf(mFile,"\"%s.stst\"",mName.c_str());
	}
	void getNucleusId()const
	{
		fprintf(mFile,"\"%s.nuid\"",mName.c_str());
	}
	void getLocalSpaceOutput()const
	{
		fprintf(mFile,"\"%s.lsou\"",mName.c_str());
	}
	void getDisplayColor()const
	{
		fprintf(mFile,"\"%s.dcl\"",mName.c_str());
	}
	void getDisplayColorR()const
	{
		fprintf(mFile,"\"%s.dcl.dcr\"",mName.c_str());
	}
	void getDisplayColorG()const
	{
		fprintf(mFile,"\"%s.dcl.dcg\"",mName.c_str());
	}
	void getDisplayColorB()const
	{
		fprintf(mFile,"\"%s.dcl.dcb\"",mName.c_str());
	}
protected:
	NParticle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Particle(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NPARTICLE_H__
