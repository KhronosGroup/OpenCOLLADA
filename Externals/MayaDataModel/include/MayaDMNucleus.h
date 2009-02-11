/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NUCLEUS_H__
#define __MayaDM_NUCLEUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Nucleus : public DependNode
{
public:
public:
	Nucleus():DependNode(){}
	Nucleus(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "nucleus"){}
	virtual ~Nucleus(){}
	void setStartFrame(double stf)
	{
		if(stf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".stf\" %f;\n", stf);

	}
	void setEnable(bool ena)
	{
		if(ena == true) return;
		fprintf(mFile,"\tsetAttr \".ena\" %i;\n", ena);

	}
	void setGravity(float grty)
	{
		if(grty == 9.8) return;
		fprintf(mFile,"\tsetAttr \".grty\" %f;\n", grty);

	}
	void setGravityDirection(const float3& grdi)
	{
		fprintf(mFile,"\tsetAttr \".grdi\" -type \"float3\" ");
		grdi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGravityDirectionX(float grdx)
	{
		if(grdx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".grdi.grdx\" %f;\n", grdx);

	}
	void setGravityDirectionY(float grdy)
	{
		if(grdy == -1.0) return;
		fprintf(mFile,"\tsetAttr \".grdi.grdy\" %f;\n", grdy);

	}
	void setGravityDirectionZ(float grdz)
	{
		if(grdz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".grdi.grdz\" %f;\n", grdz);

	}
	void setAirDensity(float ady)
	{
		if(ady == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ady\" %f;\n", ady);

	}
	void setWindSpeed(float wisp)
	{
		if(wisp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wisp\" %f;\n", wisp);

	}
	void setWindDirection(const float3& widi)
	{
		fprintf(mFile,"\tsetAttr \".widi\" -type \"float3\" ");
		widi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWindDirectionX(float widx)
	{
		if(widx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".widi.widx\" %f;\n", widx);

	}
	void setWindDirectionY(float widy)
	{
		if(widy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".widi.widy\" %f;\n", widy);

	}
	void setWindDirectionZ(float widz)
	{
		if(widz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".widi.widz\" %f;\n", widz);

	}
	void setWindNoise(float wnoi)
	{
		if(wnoi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wnoi\" %f;\n", wnoi);

	}
	void setCollisionLayerRange(float clra)
	{
		if(clra == 4.0) return;
		fprintf(mFile,"\tsetAttr \".clra\" %f;\n", clra);

	}
	void setCollisionSoftness(float clso)
	{
		if(clso == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clso\" %f;\n", clso);

	}
	void setUsePlane(bool nupl)
	{
		if(nupl == false) return;
		fprintf(mFile,"\tsetAttr \".nupl\" %i;\n", nupl);

	}
	void setPlaneOrigin(const float3& npor)
	{
		fprintf(mFile,"\tsetAttr \".npor\" -type \"float3\" ");
		npor.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPlaneOriginX(float npox)
	{
		if(npox == 0.0) return;
		fprintf(mFile,"\tsetAttr \".npor.npox\" %f;\n", npox);

	}
	void setPlaneOriginY(float npoy)
	{
		if(npoy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".npor.npoy\" %f;\n", npoy);

	}
	void setPlaneOriginZ(float npoz)
	{
		if(npoz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".npor.npoz\" %f;\n", npoz);

	}
	void setPlaneNormal(const float3& npun)
	{
		fprintf(mFile,"\tsetAttr \".npun\" -type \"float3\" ");
		npun.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPlaneNormalX(float npnx)
	{
		if(npnx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".npun.npnx\" %f;\n", npnx);

	}
	void setPlaneNormalY(float npny)
	{
		if(npny == 1.0) return;
		fprintf(mFile,"\tsetAttr \".npun.npny\" %f;\n", npny);

	}
	void setPlaneNormalZ(float npnz)
	{
		if(npnz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".npun.npnz\" %f;\n", npnz);

	}
	void setPlaneBounce(float npbc)
	{
		if(npbc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".npbc\" %f;\n", npbc);

	}
	void setPlaneFriction(float npfr)
	{
		if(npfr == 0.1) return;
		fprintf(mFile,"\tsetAttr \".npfr\" %f;\n", npfr);

	}
	void setSubSteps(int sstp)
	{
		if(sstp == 3) return;
		fprintf(mFile,"\tsetAttr \".sstp\" %i;\n", sstp);

	}
	void setMaxCollisionIterations(int mcit)
	{
		if(mcit == 4) return;
		fprintf(mFile,"\tsetAttr \".mcit\" %i;\n", mcit);

	}
	void setCollisionFlag(unsigned int cofl)
	{
		if(cofl == 4) return;
		fprintf(mFile,"\tsetAttr \".cofl\" %i;\n", cofl);

	}
	void setSelfCollisionFlag(unsigned int scfl)
	{
		if(scfl == 1) return;
		fprintf(mFile,"\tsetAttr \".scfl\" %i;\n", scfl);

	}
	void setTimeScale(float tisc)
	{
		if(tisc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tisc\" %f;\n", tisc);

	}
	void setSpaceScale(float spsc)
	{
		if(spsc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".spsc\" %f;\n", spsc);

	}
	void getInputStart(size_t is_i)
	{
		fprintf(mFile,"\"%s.is[%i]\"",mName.c_str(),is_i);

	}
	void getInputCurrent(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i]\"",mName.c_str(),ic_i);

	}
	void getInputActive(size_t niao_i)
	{
		fprintf(mFile,"\"%s.niao[%i]\"",mName.c_str(),niao_i);

	}
	void getInputPassive(size_t nipo_i)
	{
		fprintf(mFile,"\"%s.nipo[%i]\"",mName.c_str(),nipo_i);

	}
	void getInputActiveStart(size_t nias_i)
	{
		fprintf(mFile,"\"%s.nias[%i]\"",mName.c_str(),nias_i);

	}
	void getInputPassiveStart(size_t nips_i)
	{
		fprintf(mFile,"\"%s.nips[%i]\"",mName.c_str(),nips_i);

	}
	void getOutputObjects(size_t noao_i)
	{
		fprintf(mFile,"\"%s.noao[%i]\"",mName.c_str(),noao_i);

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
	void getEnable()
	{
		fprintf(mFile,"\"%s.ena\"",mName.c_str());

	}
	void getGravity()
	{
		fprintf(mFile,"\"%s.grty\"",mName.c_str());

	}
	void getGravityDirection()
	{
		fprintf(mFile,"\"%s.grdi\"",mName.c_str());

	}
	void getGravityDirectionX()
	{
		fprintf(mFile,"\"%s.grdi.grdx\"",mName.c_str());

	}
	void getGravityDirectionY()
	{
		fprintf(mFile,"\"%s.grdi.grdy\"",mName.c_str());

	}
	void getGravityDirectionZ()
	{
		fprintf(mFile,"\"%s.grdi.grdz\"",mName.c_str());

	}
	void getAirDensity()
	{
		fprintf(mFile,"\"%s.ady\"",mName.c_str());

	}
	void getWindSpeed()
	{
		fprintf(mFile,"\"%s.wisp\"",mName.c_str());

	}
	void getWindDirection()
	{
		fprintf(mFile,"\"%s.widi\"",mName.c_str());

	}
	void getWindDirectionX()
	{
		fprintf(mFile,"\"%s.widi.widx\"",mName.c_str());

	}
	void getWindDirectionY()
	{
		fprintf(mFile,"\"%s.widi.widy\"",mName.c_str());

	}
	void getWindDirectionZ()
	{
		fprintf(mFile,"\"%s.widi.widz\"",mName.c_str());

	}
	void getWindNoise()
	{
		fprintf(mFile,"\"%s.wnoi\"",mName.c_str());

	}
	void getCollisionLayerRange()
	{
		fprintf(mFile,"\"%s.clra\"",mName.c_str());

	}
	void getCollisionSoftness()
	{
		fprintf(mFile,"\"%s.clso\"",mName.c_str());

	}
	void getUsePlane()
	{
		fprintf(mFile,"\"%s.nupl\"",mName.c_str());

	}
	void getPlaneOrigin()
	{
		fprintf(mFile,"\"%s.npor\"",mName.c_str());

	}
	void getPlaneOriginX()
	{
		fprintf(mFile,"\"%s.npor.npox\"",mName.c_str());

	}
	void getPlaneOriginY()
	{
		fprintf(mFile,"\"%s.npor.npoy\"",mName.c_str());

	}
	void getPlaneOriginZ()
	{
		fprintf(mFile,"\"%s.npor.npoz\"",mName.c_str());

	}
	void getPlaneNormal()
	{
		fprintf(mFile,"\"%s.npun\"",mName.c_str());

	}
	void getPlaneNormalX()
	{
		fprintf(mFile,"\"%s.npun.npnx\"",mName.c_str());

	}
	void getPlaneNormalY()
	{
		fprintf(mFile,"\"%s.npun.npny\"",mName.c_str());

	}
	void getPlaneNormalZ()
	{
		fprintf(mFile,"\"%s.npun.npnz\"",mName.c_str());

	}
	void getPlaneBounce()
	{
		fprintf(mFile,"\"%s.npbc\"",mName.c_str());

	}
	void getPlaneFriction()
	{
		fprintf(mFile,"\"%s.npfr\"",mName.c_str());

	}
	void getSubSteps()
	{
		fprintf(mFile,"\"%s.sstp\"",mName.c_str());

	}
	void getMaxCollisionIterations()
	{
		fprintf(mFile,"\"%s.mcit\"",mName.c_str());

	}
	void getCollisionFlag()
	{
		fprintf(mFile,"\"%s.cofl\"",mName.c_str());

	}
	void getSelfCollisionFlag()
	{
		fprintf(mFile,"\"%s.scfl\"",mName.c_str());

	}
	void getTimeScale()
	{
		fprintf(mFile,"\"%s.tisc\"",mName.c_str());

	}
	void getSpaceScale()
	{
		fprintf(mFile,"\"%s.spsc\"",mName.c_str());

	}
protected:
	Nucleus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_NUCLEUS_H__
