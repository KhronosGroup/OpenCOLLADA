/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RIGIDSOLVER_H__
#define __MayaDM_RIGIDSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RigidSolver : public DependNode
{
public:
	struct GeneralForce{
		vectorArray inputForce;
		vectorArray inputTorque;
		void write(FILE* file) const
		{
			inputForce.write(file);
			fprintf(file, " ");
			inputTorque.write(file);
		}
	};
public:

	RigidSolver():DependNode(){}
	RigidSolver(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "rigidSolver", shared, create){}
	virtual ~RigidSolver(){}

	void setStartTime(double stm)
	{
		if(stm == 0) return;
		fprintf(mFile,"\tsetAttr \".stm\" %f;\n", stm);
	}
	void setGeneralForce(size_t gfr_i,const GeneralForce& gfr)
	{
		fprintf(mFile,"\tsetAttr \".gfr[%i]\" ",gfr_i);
		gfr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGeneralForce(size_t gfr_start,size_t gfr_end,GeneralForce* gfr)
	{
		fprintf(mFile,"\tsetAttr \".gfr[%i:%i]\" ", gfr_start,gfr_end);
		size_t size = (gfr_end-gfr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			gfr[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startGeneralForce(size_t gfr_start,size_t gfr_end)const
	{
		fprintf(mFile,"\tsetAttr \".gfr[%i:%i]\"",gfr_start,gfr_end);
		fprintf(mFile," -type \"GeneralForce\" ");
	}
	void appendGeneralForce(const GeneralForce& gfr)const
	{
		fprintf(mFile," ");
		gfr.write(mFile);
	}
	void endGeneralForce()const
	{
		fprintf(mFile,";\n");
	}
	void setInputForce(size_t gfr_i,const vectorArray& ifr)
	{
		if(ifr.size == 0) return;
		fprintf(mFile,"\tsetAttr \".gfr[%i].ifr\" -type \"vectorArray\" ",gfr_i);
		ifr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputTorque(size_t gfr_i,const vectorArray& itr)
	{
		if(itr.size == 0) return;
		fprintf(mFile,"\tsetAttr \".gfr[%i].itr\" -type \"vectorArray\" ",gfr_i);
		itr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTranslate(size_t t_i,const double3& t)
	{
		fprintf(mFile,"\tsetAttr \".t[%i]\" -type \"double3\" ",t_i);
		t.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTranslate(size_t t_start,size_t t_end,double* t)
	{
		fprintf(mFile,"\tsetAttr \".t[%i:%i]\" ", t_start,t_end);
		size_t size = (t_end-t_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",t[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startTranslate(size_t t_start,size_t t_end)const
	{
		fprintf(mFile,"\tsetAttr \".t[%i:%i]\"",t_start,t_end);
	}
	void appendTranslate(double t)const
	{
		fprintf(mFile," %f",t);
	}
	void endTranslate()const
	{
		fprintf(mFile,";\n");
	}
	void setTranslateX(size_t t_i,double tx)
	{
		if(tx == 0) return;
		fprintf(mFile,"\tsetAttr \".t[%i].tx\" %f;\n", t_i,tx);
	}
	void setTranslateY(size_t t_i,double ty)
	{
		if(ty == 0) return;
		fprintf(mFile,"\tsetAttr \".t[%i].ty\" %f;\n", t_i,ty);
	}
	void setTranslateZ(size_t t_i,double tz)
	{
		if(tz == 0) return;
		fprintf(mFile,"\tsetAttr \".t[%i].tz\" %f;\n", t_i,tz);
	}
	void setRotate(size_t r_i,const double3& r)
	{
		fprintf(mFile,"\tsetAttr \".r[%i]\" -type \"double3\" ",r_i);
		r.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRotate(size_t r_start,size_t r_end,double* r)
	{
		fprintf(mFile,"\tsetAttr \".r[%i:%i]\" ", r_start,r_end);
		size_t size = (r_end-r_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",r[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startRotate(size_t r_start,size_t r_end)const
	{
		fprintf(mFile,"\tsetAttr \".r[%i:%i]\"",r_start,r_end);
	}
	void appendRotate(double r)const
	{
		fprintf(mFile," %f",r);
	}
	void endRotate()const
	{
		fprintf(mFile,";\n");
	}
	void setRotateX(size_t r_i,double rx)
	{
		if(rx == 0) return;
		fprintf(mFile,"\tsetAttr \".r[%i].rx\" %f;\n", r_i,rx);
	}
	void setRotateY(size_t r_i,double ry)
	{
		if(ry == 0) return;
		fprintf(mFile,"\tsetAttr \".r[%i].ry\" %f;\n", r_i,ry);
	}
	void setRotateZ(size_t r_i,double rz)
	{
		if(rz == 0) return;
		fprintf(mFile,"\tsetAttr \".r[%i].rz\" %f;\n", r_i,rz);
	}
	void setConstraintTranslate(size_t ctr_i,const double3& ctr)
	{
		fprintf(mFile,"\tsetAttr \".ctr[%i]\" -type \"double3\" ",ctr_i);
		ctr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setConstraintTranslate(size_t ctr_start,size_t ctr_end,double* ctr)
	{
		fprintf(mFile,"\tsetAttr \".ctr[%i:%i]\" ", ctr_start,ctr_end);
		size_t size = (ctr_end-ctr_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ctr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startConstraintTranslate(size_t ctr_start,size_t ctr_end)const
	{
		fprintf(mFile,"\tsetAttr \".ctr[%i:%i]\"",ctr_start,ctr_end);
	}
	void appendConstraintTranslate(double ctr)const
	{
		fprintf(mFile," %f",ctr);
	}
	void endConstraintTranslate()const
	{
		fprintf(mFile,";\n");
	}
	void setConstraintTranslateX(size_t ctr_i,double ctx)
	{
		if(ctx == 0) return;
		fprintf(mFile,"\tsetAttr \".ctr[%i].ctx\" %f;\n", ctr_i,ctx);
	}
	void setConstraintTranslateY(size_t ctr_i,double cty)
	{
		if(cty == 0) return;
		fprintf(mFile,"\tsetAttr \".ctr[%i].cty\" %f;\n", ctr_i,cty);
	}
	void setConstraintTranslateZ(size_t ctr_i,double ctz)
	{
		if(ctz == 0) return;
		fprintf(mFile,"\tsetAttr \".ctr[%i].ctz\" %f;\n", ctr_i,ctz);
	}
	void setConstraintRotate(size_t cr_i,const double3& cr)
	{
		fprintf(mFile,"\tsetAttr \".cr[%i]\" -type \"double3\" ",cr_i);
		cr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setConstraintRotate(size_t cr_start,size_t cr_end,double* cr)
	{
		fprintf(mFile,"\tsetAttr \".cr[%i:%i]\" ", cr_start,cr_end);
		size_t size = (cr_end-cr_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startConstraintRotate(size_t cr_start,size_t cr_end)const
	{
		fprintf(mFile,"\tsetAttr \".cr[%i:%i]\"",cr_start,cr_end);
	}
	void appendConstraintRotate(double cr)const
	{
		fprintf(mFile," %f",cr);
	}
	void endConstraintRotate()const
	{
		fprintf(mFile,";\n");
	}
	void setConstraintRotateX(size_t cr_i,double crx)
	{
		if(crx == 0) return;
		fprintf(mFile,"\tsetAttr \".cr[%i].crx\" %f;\n", cr_i,crx);
	}
	void setConstraintRotateY(size_t cr_i,double cry)
	{
		if(cry == 0) return;
		fprintf(mFile,"\tsetAttr \".cr[%i].cry\" %f;\n", cr_i,cry);
	}
	void setConstraintRotateZ(size_t cr_i,double crz)
	{
		if(crz == 0) return;
		fprintf(mFile,"\tsetAttr \".cr[%i].crz\" %f;\n", cr_i,crz);
	}
	void setCollisionTolerance(double ctl)
	{
		if(ctl == 0.02) return;
		fprintf(mFile,"\tsetAttr \".ctl\" %f;\n", ctl);
	}
	void setStepSize(double ss)
	{
		if(ss == 0.03) return;
		fprintf(mFile,"\tsetAttr \".ss\" %f;\n", ss);
	}
	void setScaleVelocity(double svv)
	{
		if(svv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".svv\" %f;\n", svv);
	}
	void setSolverMethod(unsigned int slm)
	{
		if(slm == 2) return;
		fprintf(mFile,"\tsetAttr \".slm\" %i;\n", slm);
	}
	void setFriction(bool f)
	{
		if(f == true) return;
		fprintf(mFile,"\tsetAttr \".f\" %i;\n", f);
	}
	void setBounciness(bool b)
	{
		if(b == true) return;
		fprintf(mFile,"\tsetAttr \".b\" %i;\n", b);
	}
	void setDynamics(bool dyn)
	{
		if(dyn == true) return;
		fprintf(mFile,"\tsetAttr \".dyn\" %i;\n", dyn);
	}
	void setAutoSolverTolerances(bool ast)
	{
		if(ast == false) return;
		fprintf(mFile,"\tsetAttr \".ast\" %i;\n", ast);
	}
	void setDisplayVelocity(bool dv)
	{
		if(dv == false) return;
		fprintf(mFile,"\tsetAttr \".dv\" %i;\n", dv);
	}
	void setDisplayCenterOfMass(bool dcom)
	{
		if(dcom == true) return;
		fprintf(mFile,"\tsetAttr \".dcom\" %i;\n", dcom);
	}
	void setDisplayConstraint(bool dc)
	{
		if(dc == true) return;
		fprintf(mFile,"\tsetAttr \".dc\" %i;\n", dc);
	}
	void setDisplayLabel(bool dl)
	{
		if(dl == false) return;
		fprintf(mFile,"\tsetAttr \".dl\" %i;\n", dl);
	}
	void setCacheData(bool cd)
	{
		if(cd == false) return;
		fprintf(mFile,"\tsetAttr \".cd\" %i;\n", cd);
	}
	void setContactData(bool ctd)
	{
		if(ctd == false) return;
		fprintf(mFile,"\tsetAttr \".ctd\" %i;\n", ctd);
	}
	void setState(bool stt)
	{
		if(stt == true) return;
		fprintf(mFile,"\tsetAttr \".stt\" %i;\n", stt);
	}
	void setCurrent(bool cur)
	{
		if(cur == false) return;
		fprintf(mFile,"\tsetAttr \".cur\" %i;\n", cur);
	}
	void setForceDynamics(bool fdn)
	{
		if(fdn == false) return;
		fprintf(mFile,"\tsetAttr \".fdn\" %i;\n", fdn);
	}
	void setAllowDisconnection(bool ad)
	{
		if(ad == false) return;
		fprintf(mFile,"\tsetAttr \".ad\" %i;\n", ad);
	}
	void setStatistics(bool st)
	{
		if(st == false) return;
		fprintf(mFile,"\tsetAttr \".st\" %i;\n", st);
	}
	void getCurrentTime()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getStartTime()const
	{
		fprintf(mFile,"\"%s.stm\"",mName.c_str());
	}
	void getGeneralForce(size_t gfr_i)const
	{
		fprintf(mFile,"\"%s.gfr[%i]\"",mName.c_str(),gfr_i);
	}
	void getGeneralForce()const
	{

		fprintf(mFile,"\"%s.gfr\"",mName.c_str());
	}
	void getInputForce(size_t gfr_i)const
	{
		fprintf(mFile,"\"%s.gfr[%i].ifr\"",mName.c_str(),gfr_i);
	}
	void getInputForce()const
	{

		fprintf(mFile,"\"%s.gfr.ifr\"",mName.c_str());
	}
	void getInputTorque(size_t gfr_i)const
	{
		fprintf(mFile,"\"%s.gfr[%i].itr\"",mName.c_str(),gfr_i);
	}
	void getInputTorque()const
	{

		fprintf(mFile,"\"%s.gfr.itr\"",mName.c_str());
	}
	void getTranslate(size_t t_i)const
	{
		fprintf(mFile,"\"%s.t[%i]\"",mName.c_str(),t_i);
	}
	void getTranslate()const
	{

		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getTranslateX(size_t t_i)const
	{
		fprintf(mFile,"\"%s.t[%i].tx\"",mName.c_str(),t_i);
	}
	void getTranslateX()const
	{

		fprintf(mFile,"\"%s.t.tx\"",mName.c_str());
	}
	void getTranslateY(size_t t_i)const
	{
		fprintf(mFile,"\"%s.t[%i].ty\"",mName.c_str(),t_i);
	}
	void getTranslateY()const
	{

		fprintf(mFile,"\"%s.t.ty\"",mName.c_str());
	}
	void getTranslateZ(size_t t_i)const
	{
		fprintf(mFile,"\"%s.t[%i].tz\"",mName.c_str(),t_i);
	}
	void getTranslateZ()const
	{

		fprintf(mFile,"\"%s.t.tz\"",mName.c_str());
	}
	void getRotate(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i]\"",mName.c_str(),r_i);
	}
	void getRotate()const
	{

		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getRotateX(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i].rx\"",mName.c_str(),r_i);
	}
	void getRotateX()const
	{

		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());
	}
	void getRotateY(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i].ry\"",mName.c_str(),r_i);
	}
	void getRotateY()const
	{

		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());
	}
	void getRotateZ(size_t r_i)const
	{
		fprintf(mFile,"\"%s.r[%i].rz\"",mName.c_str(),r_i);
	}
	void getRotateZ()const
	{

		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());
	}
	void getConstraintTranslate(size_t ctr_i)const
	{
		fprintf(mFile,"\"%s.ctr[%i]\"",mName.c_str(),ctr_i);
	}
	void getConstraintTranslate()const
	{

		fprintf(mFile,"\"%s.ctr\"",mName.c_str());
	}
	void getConstraintTranslateX(size_t ctr_i)const
	{
		fprintf(mFile,"\"%s.ctr[%i].ctx\"",mName.c_str(),ctr_i);
	}
	void getConstraintTranslateX()const
	{

		fprintf(mFile,"\"%s.ctr.ctx\"",mName.c_str());
	}
	void getConstraintTranslateY(size_t ctr_i)const
	{
		fprintf(mFile,"\"%s.ctr[%i].cty\"",mName.c_str(),ctr_i);
	}
	void getConstraintTranslateY()const
	{

		fprintf(mFile,"\"%s.ctr.cty\"",mName.c_str());
	}
	void getConstraintTranslateZ(size_t ctr_i)const
	{
		fprintf(mFile,"\"%s.ctr[%i].ctz\"",mName.c_str(),ctr_i);
	}
	void getConstraintTranslateZ()const
	{

		fprintf(mFile,"\"%s.ctr.ctz\"",mName.c_str());
	}
	void getConstraintRotate(size_t cr_i)const
	{
		fprintf(mFile,"\"%s.cr[%i]\"",mName.c_str(),cr_i);
	}
	void getConstraintRotate()const
	{

		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getConstraintRotateX(size_t cr_i)const
	{
		fprintf(mFile,"\"%s.cr[%i].crx\"",mName.c_str(),cr_i);
	}
	void getConstraintRotateX()const
	{

		fprintf(mFile,"\"%s.cr.crx\"",mName.c_str());
	}
	void getConstraintRotateY(size_t cr_i)const
	{
		fprintf(mFile,"\"%s.cr[%i].cry\"",mName.c_str(),cr_i);
	}
	void getConstraintRotateY()const
	{

		fprintf(mFile,"\"%s.cr.cry\"",mName.c_str());
	}
	void getConstraintRotateZ(size_t cr_i)const
	{
		fprintf(mFile,"\"%s.cr[%i].crz\"",mName.c_str(),cr_i);
	}
	void getConstraintRotateZ()const
	{

		fprintf(mFile,"\"%s.cr.crz\"",mName.c_str());
	}
	void getScaleVelocity()const
	{
		fprintf(mFile,"\"%s.svv\"",mName.c_str());
	}
	void getSolverMethod()const
	{
		fprintf(mFile,"\"%s.slm\"",mName.c_str());
	}
	void getFriction()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getBounciness()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getDynamics()const
	{
		fprintf(mFile,"\"%s.dyn\"",mName.c_str());
	}
	void getAutoSolverTolerances()const
	{
		fprintf(mFile,"\"%s.ast\"",mName.c_str());
	}
	void getDisplayVelocity()const
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());
	}
	void getDisplayCenterOfMass()const
	{
		fprintf(mFile,"\"%s.dcom\"",mName.c_str());
	}
	void getDisplayConstraint()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getDisplayLabel()const
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getCacheData()const
	{
		fprintf(mFile,"\"%s.cd\"",mName.c_str());
	}
	void getContactData()const
	{
		fprintf(mFile,"\"%s.ctd\"",mName.c_str());
	}
	void getState()const
	{
		fprintf(mFile,"\"%s.stt\"",mName.c_str());
	}
protected:
	RigidSolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RIGIDSOLVER_H__
