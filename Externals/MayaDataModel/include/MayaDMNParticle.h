/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	NParticle(FILE* file,const std::string& name,const std::string& parent=""):Particle(file, name, parent, "nParticle"){}
	virtual ~NParticle(){}
	void setPlayFromCache(bool pfc)
	{
		if(pfc == false) return;
		fprintf(mFile,"setAttr \".pfc\" %i;\n", pfc);

	}
	void setStartPositions(const vectorArray& spns)
	{
		if(spns.size == 0) return;
		fprintf(mFile,"setAttr \".spns\" -type \"vectorArray\" ");
		spns.write(mFile);
		fprintf(mFile,";\n");

	}
	void setStartVelocities(const vectorArray& sves)
	{
		if(sves.size == 0) return;
		fprintf(mFile,"setAttr \".sves\" -type \"vectorArray\" ");
		sves.write(mFile);
		fprintf(mFile,";\n");

	}
	void setThickness(float thss)
	{
		if(thss == 0.1) return;
		fprintf(mFile,"setAttr \".thss\" %f;\n", thss);

	}
	void setThicknessMap(float thmp)
	{
		if(thmp == 0.1) return;
		fprintf(mFile,"setAttr \".thmp\" %f;\n", thmp);

	}
	void setThicknessPerVertex(const doubleArray& thpv)
	{
		if(thpv.size == 0) return;
		fprintf(mFile,"setAttr \".thpv\" -type \"doubleArray\" ");
		thpv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBounce(float boce)
	{
		if(boce == 0.0) return;
		fprintf(mFile,"setAttr \".boce\" %f;\n", boce);

	}
	void setBounceMap(float bomp)
	{
		if(bomp == 0.0) return;
		fprintf(mFile,"setAttr \".bomp\" %f;\n", bomp);

	}
	void setBouncePerVertex(const doubleArray& bpv)
	{
		if(bpv.size == 0) return;
		fprintf(mFile,"setAttr \".bpv\" -type \"doubleArray\" ");
		bpv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFriction(float fron)
	{
		if(fron == 0.1) return;
		fprintf(mFile,"setAttr \".fron\" %f;\n", fron);

	}
	void setFrictionMap(float frmp)
	{
		if(frmp == 0.0) return;
		fprintf(mFile,"setAttr \".frmp\" %f;\n", frmp);

	}
	void setFrictionPerVertex(const doubleArray& fpv)
	{
		if(fpv.size == 0) return;
		fprintf(mFile,"setAttr \".fpv\" -type \"doubleArray\" ");
		fpv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDamp(float adng)
	{
		if(adng == 0.0) return;
		fprintf(mFile,"setAttr \".adng\" %f;\n", adng);

	}
	void setDampMap(float admp)
	{
		if(admp == 0.0) return;
		fprintf(mFile,"setAttr \".admp\" %f;\n", admp);

	}
	void setDampPerVertex(const doubleArray& dpv)
	{
		if(dpv.size == 0) return;
		fprintf(mFile,"setAttr \".dpv\" -type \"doubleArray\" ");
		dpv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCollisionFlag(unsigned int cofl)
	{
		if(cofl == 2) return;
		fprintf(mFile,"setAttr \".cofl\" %i;\n", cofl);

	}
	void setSelfCollisionFlag(unsigned int scfl)
	{
		if(scfl == 0) return;
		fprintf(mFile,"setAttr \".scfl\" %i;\n", scfl);

	}
	void setMaxSelfCollisionIterations(int msci)
	{
		if(msci == 4) return;
		fprintf(mFile,"setAttr \".msci\" %i;\n", msci);

	}
	void setMaxIterations(int mxit)
	{
		if(mxit == 500) return;
		fprintf(mFile,"setAttr \".mxit\" %i;\n", mxit);

	}
	void setPointMass(float pmss)
	{
		if(pmss == 1.0) return;
		fprintf(mFile,"setAttr \".pmss\" %f;\n", pmss);

	}
	void setMassMap(float mamp)
	{
		if(mamp == 1.0) return;
		fprintf(mFile,"setAttr \".mamp\" %f;\n", mamp);

	}
	void setMassPerVertex(const doubleArray& mpv)
	{
		if(mpv.size == 0) return;
		fprintf(mFile,"setAttr \".mpv\" -type \"doubleArray\" ");
		mpv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRestLengthScale(float rlsc)
	{
		if(rlsc == 1.0) return;
		fprintf(mFile,"setAttr \".rlsc\" %f;\n", rlsc);

	}
	void setActive(bool actv)
	{
		if(actv == 1) return;
		fprintf(mFile,"setAttr \".actv\" %i;\n", actv);

	}
	void setCollide(bool cold)
	{
		if(cold == 1) return;
		fprintf(mFile,"setAttr \".cold\" %i;\n", cold);

	}
	void setSelfCollide(bool scld)
	{
		if(scld == 1) return;
		fprintf(mFile,"setAttr \".scld\" %i;\n", scld);

	}
	void setCollisionLayer(float cll)
	{
		if(cll == 0.0) return;
		fprintf(mFile,"setAttr \".cll\" %f;\n", cll);

	}
	void setWindShadowDiffusion(float wsdi)
	{
		if(wsdi == 0.0) return;
		fprintf(mFile,"setAttr \".wsdi\" %f;\n", wsdi);

	}
	void setWindShadowDistance(float wsds)
	{
		if(wsds == 0.0) return;
		fprintf(mFile,"setAttr \".wsds\" %f;\n", wsds);

	}
	void setAirPushDistance(float apds)
	{
		if(apds == 0.0) return;
		fprintf(mFile,"setAttr \".apds\" %f;\n", apds);

	}
	void setAirPushVorticity(float apvy)
	{
		if(apvy == 0.0) return;
		fprintf(mFile,"setAttr \".apvy\" %f;\n", apvy);

	}
	void setPushOut(float pou)
	{
		if(pou == 0.0) return;
		fprintf(mFile,"setAttr \".pou\" %f;\n", pou);

	}
	void setPushOutRadius(float por)
	{
		if(por == 10.0) return;
		fprintf(mFile,"setAttr \".por\" %f;\n", por);

	}
	void setCrossoverPush(float cop)
	{
		if(cop == 0.0) return;
		fprintf(mFile,"setAttr \".cop\" %f;\n", cop);

	}
	void setTrappedCheck(bool tpc)
	{
		if(tpc == 0) return;
		fprintf(mFile,"setAttr \".tpc\" %i;\n", tpc);

	}
	void setThicknessMapType(unsigned int tmt)
	{
		if(tmt == 2) return;
		fprintf(mFile,"setAttr \".tmt\" %i;\n", tmt);

	}
	void setBounceMapType(unsigned int bmt)
	{
		if(bmt == 2) return;
		fprintf(mFile,"setAttr \".bmt\" %i;\n", bmt);

	}
	void setFrictionMapType(unsigned int fmt)
	{
		if(fmt == 2) return;
		fprintf(mFile,"setAttr \".fmt\" %i;\n", fmt);

	}
	void setDampMapType(unsigned int dmt)
	{
		if(dmt == 2) return;
		fprintf(mFile,"setAttr \".dmt\" %i;\n", dmt);

	}
	void setMassMapType(unsigned int mmt)
	{
		if(mmt == 2) return;
		fprintf(mFile,"setAttr \".mmt\" %i;\n", mmt);

	}
	void setLocalSpaceOutput(bool lsou)
	{
		if(lsou == 0) return;
		fprintf(mFile,"setAttr \".lsou\" %i;\n", lsou);

	}
	void setDisplayColor(const float3& dcl)
	{
		fprintf(mFile,"setAttr \".dcl\" -type \"float3\" ");
		dcl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDisplayColorR(float dcr)
	{
		if(dcr == 1.0) return;
		fprintf(mFile,"setAttr \".dcl.dcr\" %f;\n", dcr);

	}
	void setDisplayColorG(float dcg)
	{
		if(dcg == 0.8) return;
		fprintf(mFile,"setAttr \".dcl.dcg\" %f;\n", dcg);

	}
	void setDisplayColorB(float dcb)
	{
		if(dcb == 0.0) return;
		fprintf(mFile,"setAttr \".dcl.dcb\" %f;\n", dcb);

	}
	void getInputMesh()
	{
		fprintf(mFile,"\"%s.imsh\"",mName.c_str());

	}
	void getPositions()
	{
		fprintf(mFile,"\"%s.poss\"",mName.c_str());

	}
	void getPlayFromCache()
	{
		fprintf(mFile,"\"%s.pfc\"",mName.c_str());

	}
	void getStartPositions()
	{
		fprintf(mFile,"\"%s.spns\"",mName.c_str());

	}
	void getStartVelocities()
	{
		fprintf(mFile,"\"%s.sves\"",mName.c_str());

	}
	void getThickness()
	{
		fprintf(mFile,"\"%s.thss\"",mName.c_str());

	}
	void getThicknessMap()
	{
		fprintf(mFile,"\"%s.thmp\"",mName.c_str());

	}
	void getThicknessPerVertex()
	{
		fprintf(mFile,"\"%s.thpv\"",mName.c_str());

	}
	void getBounce()
	{
		fprintf(mFile,"\"%s.boce\"",mName.c_str());

	}
	void getBounceMap()
	{
		fprintf(mFile,"\"%s.bomp\"",mName.c_str());

	}
	void getBouncePerVertex()
	{
		fprintf(mFile,"\"%s.bpv\"",mName.c_str());

	}
	void getFriction()
	{
		fprintf(mFile,"\"%s.fron\"",mName.c_str());

	}
	void getFrictionMap()
	{
		fprintf(mFile,"\"%s.frmp\"",mName.c_str());

	}
	void getFrictionPerVertex()
	{
		fprintf(mFile,"\"%s.fpv\"",mName.c_str());

	}
	void getDamp()
	{
		fprintf(mFile,"\"%s.adng\"",mName.c_str());

	}
	void getDampMap()
	{
		fprintf(mFile,"\"%s.admp\"",mName.c_str());

	}
	void getDampPerVertex()
	{
		fprintf(mFile,"\"%s.dpv\"",mName.c_str());

	}
	void getCollisionFlag()
	{
		fprintf(mFile,"\"%s.cofl\"",mName.c_str());

	}
	void getSelfCollisionFlag()
	{
		fprintf(mFile,"\"%s.scfl\"",mName.c_str());

	}
	void getMaxSelfCollisionIterations()
	{
		fprintf(mFile,"\"%s.msci\"",mName.c_str());

	}
	void getMaxIterations()
	{
		fprintf(mFile,"\"%s.mxit\"",mName.c_str());

	}
	void getPointMass()
	{
		fprintf(mFile,"\"%s.pmss\"",mName.c_str());

	}
	void getMassMap()
	{
		fprintf(mFile,"\"%s.mamp\"",mName.c_str());

	}
	void getMassPerVertex()
	{
		fprintf(mFile,"\"%s.mpv\"",mName.c_str());

	}
	void getRestLengthScale()
	{
		fprintf(mFile,"\"%s.rlsc\"",mName.c_str());

	}
	void getActive()
	{
		fprintf(mFile,"\"%s.actv\"",mName.c_str());

	}
	void getCollide()
	{
		fprintf(mFile,"\"%s.cold\"",mName.c_str());

	}
	void getSelfCollide()
	{
		fprintf(mFile,"\"%s.scld\"",mName.c_str());

	}
	void getCollisionLayer()
	{
		fprintf(mFile,"\"%s.cll\"",mName.c_str());

	}
	void getWindShadowDiffusion()
	{
		fprintf(mFile,"\"%s.wsdi\"",mName.c_str());

	}
	void getWindShadowDistance()
	{
		fprintf(mFile,"\"%s.wsds\"",mName.c_str());

	}
	void getAirPushDistance()
	{
		fprintf(mFile,"\"%s.apds\"",mName.c_str());

	}
	void getAirPushVorticity()
	{
		fprintf(mFile,"\"%s.apvy\"",mName.c_str());

	}
	void getPushOut()
	{
		fprintf(mFile,"\"%s.pou\"",mName.c_str());

	}
	void getPushOutRadius()
	{
		fprintf(mFile,"\"%s.por\"",mName.c_str());

	}
	void getCrossoverPush()
	{
		fprintf(mFile,"\"%s.cop\"",mName.c_str());

	}
	void getTrappedCheck()
	{
		fprintf(mFile,"\"%s.tpc\"",mName.c_str());

	}
	void getThicknessMapType()
	{
		fprintf(mFile,"\"%s.tmt\"",mName.c_str());

	}
	void getBounceMapType()
	{
		fprintf(mFile,"\"%s.bmt\"",mName.c_str());

	}
	void getFrictionMapType()
	{
		fprintf(mFile,"\"%s.fmt\"",mName.c_str());

	}
	void getDampMapType()
	{
		fprintf(mFile,"\"%s.dmt\"",mName.c_str());

	}
	void getMassMapType()
	{
		fprintf(mFile,"\"%s.mmt\"",mName.c_str());

	}
	void getCurrentState()
	{
		fprintf(mFile,"\"%s.cust\"",mName.c_str());

	}
	void getStartState()
	{
		fprintf(mFile,"\"%s.stst\"",mName.c_str());

	}
	void getNucleusId()
	{
		fprintf(mFile,"\"%s.nuid\"",mName.c_str());

	}
	void getLocalSpaceOutput()
	{
		fprintf(mFile,"\"%s.lsou\"",mName.c_str());

	}
	void getDisplayColor()
	{
		fprintf(mFile,"\"%s.dcl\"",mName.c_str());

	}
	void getDisplayColorR()
	{
		fprintf(mFile,"\"%s.dcl.dcr\"",mName.c_str());

	}
	void getDisplayColorG()
	{
		fprintf(mFile,"\"%s.dcl.dcg\"",mName.c_str());

	}
	void getDisplayColorB()
	{
		fprintf(mFile,"\"%s.dcl.dcb\"",mName.c_str());

	}
protected:
	NParticle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Particle(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_NPARTICLE_H__
