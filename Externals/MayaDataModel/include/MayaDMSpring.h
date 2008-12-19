/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SPRING_H__
#define __MayaDM_SPRING_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class Spring : public Shape
{
public:
	struct IdMapping{
		void write(FILE* file) const
		{
		}
	};
public:
	Spring(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "spring"){}
	virtual ~Spring(){}
	void setEnd1Weight(double f)
	{
		if(f == 1) return;
		fprintf(mFile,"setAttr \".f\" %f;\n", f);

	}
	void setEnd2Weight(double t)
	{
		if(t == 1) return;
		fprintf(mFile,"setAttr \".t\" %f;\n", t);

	}
	void setUseStiffnessPS(bool usps)
	{
		if(usps == true) return;
		fprintf(mFile,"setAttr \".usps\" %i;\n", usps);

	}
	void setUseDampingPS(bool udps)
	{
		if(udps == true) return;
		fprintf(mFile,"setAttr \".udps\" %i;\n", udps);

	}
	void setUseRestLengthPS(bool urps)
	{
		if(urps == true) return;
		fprintf(mFile,"setAttr \".urps\" %i;\n", urps);

	}
	void setStiffness(double s)
	{
		if(s == 1) return;
		fprintf(mFile,"setAttr \".s\" %f;\n", s);

	}
	void setDamping(double d)
	{
		if(d == .2) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setRestLength(double r)
	{
		if(r == 0) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setStiffnessPS(const doubleArray& sps)
	{
		if(sps.size == 0) return;
		fprintf(mFile,"setAttr \".sps\" -type \"doubleArray\" ");
		sps.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDampingPS(const doubleArray& dps)
	{
		if(dps.size == 0) return;
		fprintf(mFile,"setAttr \".dps\" -type \"doubleArray\" ");
		dps.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRestLengthPS(const doubleArray& rps)
	{
		if(rps.size == 0) return;
		fprintf(mFile,"setAttr \".rps\" -type \"doubleArray\" ");
		rps.write(mFile);
		fprintf(mFile,";\n");

	}
	void setObjectPositions(size_t opos_i,const vectorArray& opos)
	{
		if(opos.size == 0) return;
		fprintf(mFile,"setAttr \".opos[%i]\" -type \"vectorArray\" ",opos_i);
		opos.write(mFile);
		fprintf(mFile,";\n");

	}
	void setObjectVelocities(size_t ovel_i,const vectorArray& ovel)
	{
		if(ovel.size == 0) return;
		fprintf(mFile,"setAttr \".ovel[%i]\" -type \"vectorArray\" ",ovel_i);
		ovel.write(mFile);
		fprintf(mFile,";\n");

	}
	void setObjectMass(size_t omas_i,const doubleArray& omas)
	{
		if(omas.size == 0) return;
		fprintf(mFile,"setAttr \".omas[%i]\" -type \"doubleArray\" ",omas_i);
		omas.write(mFile);
		fprintf(mFile,";\n");

	}
	void setValidIndex(const intArray& vali)
	{
		if(vali.size == 0) return;
		fprintf(mFile,"setAttr \".vali\" -type \"intArray\" ");
		vali.write(mFile);
		fprintf(mFile,";\n");

	}
	void setObject0(const intArray& obz)
	{
		if(obz.size == 0) return;
		fprintf(mFile,"setAttr \".obz\" -type \"intArray\" ");
		obz.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPoint0(const intArray& ptz)
	{
		if(ptz.size == 0) return;
		fprintf(mFile,"setAttr \".ptz\" -type \"intArray\" ");
		ptz.write(mFile);
		fprintf(mFile,";\n");

	}
	void setObject1(const intArray& obo)
	{
		if(obo.size == 0) return;
		fprintf(mFile,"setAttr \".obo\" -type \"intArray\" ");
		obo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPoint1(const intArray& pto)
	{
		if(pto.size == 0) return;
		fprintf(mFile,"setAttr \".pto\" -type \"intArray\" ");
		pto.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinSprings(int ms)
	{
		if(ms == 0) return;
		fprintf(mFile,"setAttr \".ms\" %i;\n", ms);

	}
	void setManageParticleDeath(bool mpd)
	{
		if(mpd == true) return;
		fprintf(mFile,"setAttr \".mpd\" %i;\n", mpd);

	}
	void setLengths(const doubleArray& lns)
	{
		if(lns.size == 0) return;
		fprintf(mFile,"setAttr \".lns\" -type \"doubleArray\" ");
		lns.write(mFile);
		fprintf(mFile,";\n");

	}
	void getEnd1Weight()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getEnd2Weight()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getStiffness()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getDamping()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getRestLength()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getStiffnessPS()
	{
		fprintf(mFile,"\"%s.sps\"",mName.c_str());

	}
	void getDampingPS()
	{
		fprintf(mFile,"\"%s.dps\"",mName.c_str());

	}
	void getRestLengthPS()
	{
		fprintf(mFile,"\"%s.rps\"",mName.c_str());

	}
	void getObjectPositions(size_t opos_i)
	{
		fprintf(mFile,"\"%s.opos[%i]\"",mName.c_str(),opos_i);

	}
	void getObjectVelocities(size_t ovel_i)
	{
		fprintf(mFile,"\"%s.ovel[%i]\"",mName.c_str(),ovel_i);

	}
	void getObjectMass(size_t omas_i)
	{
		fprintf(mFile,"\"%s.omas[%i]\"",mName.c_str(),omas_i);

	}
	void getDeltaTime(size_t dt_i)
	{
		fprintf(mFile,"\"%s.dt[%i]\"",mName.c_str(),dt_i);

	}
	void getOutputForce(size_t of_i)
	{
		fprintf(mFile,"\"%s.of[%i]\"",mName.c_str(),of_i);

	}
	void getIdMapping(size_t idm_i)
	{
		fprintf(mFile,"\"%s.idm[%i]\"",mName.c_str(),idm_i);

	}
	void getSortedId(size_t idm_i)
	{
		fprintf(mFile,"\"%s.idm[%i].sid\"",mName.c_str(),idm_i);

	}
	void getIdIndex(size_t idm_i)
	{
		fprintf(mFile,"\"%s.idm[%i].idix\"",mName.c_str(),idm_i);

	}
	void getCount()
	{
		fprintf(mFile,"\"%s.cnt\"",mName.c_str());

	}
	void getObjects(size_t obj_i)
	{
		fprintf(mFile,"\"%s.obj[%i]\"",mName.c_str(),obj_i);

	}
	void getObjCount()
	{
		fprintf(mFile,"\"%s.obc\"",mName.c_str());

	}
	void getLengths()
	{
		fprintf(mFile,"\"%s.lns\"",mName.c_str());

	}
	void getMinUsed()
	{
		fprintf(mFile,"\"%s.mnu\"",mName.c_str());

	}
	void getMaxUsed()
	{
		fprintf(mFile,"\"%s.mxu\"",mName.c_str());

	}
	void getPt0Index()
	{
		fprintf(mFile,"\"%s.pzi\"",mName.c_str());

	}
	void getPt1Index()
	{
		fprintf(mFile,"\"%s.poi\"",mName.c_str());

	}
	void getObj0Index()
	{
		fprintf(mFile,"\"%s.ozi\"",mName.c_str());

	}
	void getObj1Index()
	{
		fprintf(mFile,"\"%s.ooi\"",mName.c_str());

	}
protected:
	Spring(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SPRING_H__
