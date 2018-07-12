/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STITCHSRF_H__
#define __MayaDM_STITCHSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class StitchSrf : public AbstractBaseCreate
{
public:
public:

	StitchSrf():AbstractBaseCreate(){}
	StitchSrf(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "stitchSrf", shared, create){}
	virtual ~StitchSrf(){}

	void setPositionalContinuity(size_t pc_i,bool pc)
	{
		if(pc == true) return;
		fprintf(mFile,"\tsetAttr \".pc[%i]\" %i;\n", pc_i,pc);
	}
	void setPositionalContinuity(size_t pc_start,size_t pc_end,bool* pc)
	{
		fprintf(mFile,"\tsetAttr \".pc[%i:%i]\" ", pc_start,pc_end);
		size_t size = (pc_end-pc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",pc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startPositionalContinuity(size_t pc_start,size_t pc_end)const
	{
		fprintf(mFile,"\tsetAttr \".pc[%i:%i]\"",pc_start,pc_end);
	}
	void appendPositionalContinuity(bool pc)const
	{
		fprintf(mFile," %i",pc);
	}
	void endPositionalContinuity()const
	{
		fprintf(mFile,";\n");
	}
	void setTangentialContinuity(size_t tc_i,bool tc)
	{
		if(tc == false) return;
		fprintf(mFile,"\tsetAttr \".tc[%i]\" %i;\n", tc_i,tc);
	}
	void setTangentialContinuity(size_t tc_start,size_t tc_end,bool* tc)
	{
		fprintf(mFile,"\tsetAttr \".tc[%i:%i]\" ", tc_start,tc_end);
		size_t size = (tc_end-tc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",tc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startTangentialContinuity(size_t tc_start,size_t tc_end)const
	{
		fprintf(mFile,"\tsetAttr \".tc[%i:%i]\"",tc_start,tc_end);
	}
	void appendTangentialContinuity(bool tc)const
	{
		fprintf(mFile," %i",tc);
	}
	void endTangentialContinuity()const
	{
		fprintf(mFile,";\n");
	}
	void setToggleTolerance(size_t tt_i,bool tt)
	{
		if(tt == false) return;
		fprintf(mFile,"\tsetAttr \".tt[%i]\" %i;\n", tt_i,tt);
	}
	void setToggleTolerance(size_t tt_start,size_t tt_end,bool* tt)
	{
		fprintf(mFile,"\tsetAttr \".tt[%i:%i]\" ", tt_start,tt_end);
		size_t size = (tt_end-tt_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",tt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startToggleTolerance(size_t tt_start,size_t tt_end)const
	{
		fprintf(mFile,"\tsetAttr \".tt[%i:%i]\"",tt_start,tt_end);
	}
	void appendToggleTolerance(bool tt)const
	{
		fprintf(mFile," %i",tt);
	}
	void endToggleTolerance()const
	{
		fprintf(mFile,";\n");
	}
	void setTolerance(size_t tol_i,double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol[%i]\" %f;\n", tol_i,tol);
	}
	void setTolerance(size_t tol_start,size_t tol_end,double* tol)
	{
		fprintf(mFile,"\tsetAttr \".tol[%i:%i]\" ", tol_start,tol_end);
		size_t size = (tol_end-tol_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",tol[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startTolerance(size_t tol_start,size_t tol_end)const
	{
		fprintf(mFile,"\tsetAttr \".tol[%i:%i]\"",tol_start,tol_end);
	}
	void appendTolerance(double tol)const
	{
		fprintf(mFile," %f",tol);
	}
	void endTolerance()const
	{
		fprintf(mFile,";\n");
	}
	void setStepCount(size_t sc_i,int sc)
	{
		if(sc == 20) return;
		fprintf(mFile,"\tsetAttr \".sc[%i]\" %i;\n", sc_i,sc);
	}
	void setStepCount(size_t sc_start,size_t sc_end,int* sc)
	{
		fprintf(mFile,"\tsetAttr \".sc[%i:%i]\" ", sc_start,sc_end);
		size_t size = (sc_end-sc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",sc[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startStepCount(size_t sc_start,size_t sc_end)const
	{
		fprintf(mFile,"\tsetAttr \".sc[%i:%i]\"",sc_start,sc_end);
	}
	void appendStepCount(int sc)const
	{
		fprintf(mFile," %i",sc);
	}
	void endStepCount()const
	{
		fprintf(mFile,";\n");
	}
	void setParameterU(size_t u_i,double u)
	{
		if(u == -10000) return;
		fprintf(mFile,"\tsetAttr \".u[%i]\" %f;\n", u_i,u);
	}
	void setParameterU(size_t u_start,size_t u_end,double* u)
	{
		fprintf(mFile,"\tsetAttr \".u[%i:%i]\" ", u_start,u_end);
		size_t size = (u_end-u_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",u[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startParameterU(size_t u_start,size_t u_end)const
	{
		fprintf(mFile,"\tsetAttr \".u[%i:%i]\"",u_start,u_end);
	}
	void appendParameterU(double u)const
	{
		fprintf(mFile," %f",u);
	}
	void endParameterU()const
	{
		fprintf(mFile,";\n");
	}
	void setParameterV(size_t v_i,double v)
	{
		if(v == -10000) return;
		fprintf(mFile,"\tsetAttr \".v[%i]\" %f;\n", v_i,v);
	}
	void setParameterV(size_t v_start,size_t v_end,double* v)
	{
		fprintf(mFile,"\tsetAttr \".v[%i:%i]\" ", v_start,v_end);
		size_t size = (v_end-v_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",v[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startParameterV(size_t v_start,size_t v_end)const
	{
		fprintf(mFile,"\tsetAttr \".v[%i:%i]\"",v_start,v_end);
	}
	void appendParameterV(double v)const
	{
		fprintf(mFile," %f",v);
	}
	void endParameterV()const
	{
		fprintf(mFile,";\n");
	}
	void setTogglePointNormals(bool tpn)
	{
		if(tpn == false) return;
		fprintf(mFile,"\tsetAttr \".tpn\" %i;\n", tpn);
	}
	void setTogglePointPosition(bool tpp)
	{
		if(tpp == true) return;
		fprintf(mFile,"\tsetAttr \".tpp\" %i;\n", tpp);
	}
	void setCvIthIndex(size_t ci_i,int ci)
	{
		if(ci == -1) return;
		fprintf(mFile,"\tsetAttr \".ci[%i]\" %i;\n", ci_i,ci);
	}
	void setCvIthIndex(size_t ci_start,size_t ci_end,int* ci)
	{
		fprintf(mFile,"\tsetAttr \".ci[%i:%i]\" ", ci_start,ci_end);
		size_t size = (ci_end-ci_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ci[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startCvIthIndex(size_t ci_start,size_t ci_end)const
	{
		fprintf(mFile,"\tsetAttr \".ci[%i:%i]\"",ci_start,ci_end);
	}
	void appendCvIthIndex(int ci)const
	{
		fprintf(mFile," %i",ci);
	}
	void endCvIthIndex()const
	{
		fprintf(mFile,";\n");
	}
	void setCvJthIndex(size_t cj_i,int cj)
	{
		if(cj == -1) return;
		fprintf(mFile,"\tsetAttr \".cj[%i]\" %i;\n", cj_i,cj);
	}
	void setCvJthIndex(size_t cj_start,size_t cj_end,int* cj)
	{
		fprintf(mFile,"\tsetAttr \".cj[%i:%i]\" ", cj_start,cj_end);
		size_t size = (cj_end-cj_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",cj[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startCvJthIndex(size_t cj_start,size_t cj_end)const
	{
		fprintf(mFile,"\tsetAttr \".cj[%i:%i]\"",cj_start,cj_end);
	}
	void appendCvJthIndex(int cj)const
	{
		fprintf(mFile," %i",cj);
	}
	void endCvJthIndex()const
	{
		fprintf(mFile,";\n");
	}
	void setBias(double b)
	{
		if(b == 1.0) return;
		fprintf(mFile,"\tsetAttr \".b\" %f;\n", b);
	}
	void setFixBoundary(bool fb)
	{
		if(fb == false) return;
		fprintf(mFile,"\tsetAttr \".fb\" %i;\n", fb);
	}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getInputCurve(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i]\"",mName.c_str(),ic_i);
	}
	void getInputCurve()const
	{

		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getInputMatchCurve(size_t imc_i)const
	{
		fprintf(mFile,"\"%s.imc[%i]\"",mName.c_str(),imc_i);
	}
	void getInputMatchCurve()const
	{

		fprintf(mFile,"\"%s.imc\"",mName.c_str());
	}
	void getInputReferenceCOS(size_t ir_i)const
	{
		fprintf(mFile,"\"%s.ir[%i]\"",mName.c_str(),ir_i);
	}
	void getInputReferenceCOS()const
	{

		fprintf(mFile,"\"%s.ir\"",mName.c_str());
	}
	void getPositionalContinuity(size_t pc_i)const
	{
		fprintf(mFile,"\"%s.pc[%i]\"",mName.c_str(),pc_i);
	}
	void getPositionalContinuity()const
	{

		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getTangentialContinuity(size_t tc_i)const
	{
		fprintf(mFile,"\"%s.tc[%i]\"",mName.c_str(),tc_i);
	}
	void getTangentialContinuity()const
	{

		fprintf(mFile,"\"%s.tc\"",mName.c_str());
	}
	void getToggleTolerance(size_t tt_i)const
	{
		fprintf(mFile,"\"%s.tt[%i]\"",mName.c_str(),tt_i);
	}
	void getToggleTolerance()const
	{

		fprintf(mFile,"\"%s.tt\"",mName.c_str());
	}
	void getTolerance(size_t tol_i)const
	{
		fprintf(mFile,"\"%s.tol[%i]\"",mName.c_str(),tol_i);
	}
	void getTolerance()const
	{

		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getStepCount(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i]\"",mName.c_str(),sc_i);
	}
	void getStepCount()const
	{

		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getParameterU(size_t u_i)const
	{
		fprintf(mFile,"\"%s.u[%i]\"",mName.c_str(),u_i);
	}
	void getParameterU()const
	{

		fprintf(mFile,"\"%s.u\"",mName.c_str());
	}
	void getParameterV(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i]\"",mName.c_str(),v_i);
	}
	void getParameterV()const
	{

		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getPosition(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);
	}
	void getPosition()const
	{

		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPositionX(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i].px\"",mName.c_str(),p_i);
	}
	void getPositionX()const
	{

		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPositionY(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i].py\"",mName.c_str(),p_i);
	}
	void getPositionY()const
	{

		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPositionZ(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i].pz\"",mName.c_str(),p_i);
	}
	void getPositionZ()const
	{

		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getNormal(size_t n_i)const
	{
		fprintf(mFile,"\"%s.n[%i]\"",mName.c_str(),n_i);
	}
	void getNormal()const
	{

		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNormalX(size_t n_i)const
	{
		fprintf(mFile,"\"%s.n[%i].nx\"",mName.c_str(),n_i);
	}
	void getNormalX()const
	{

		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());
	}
	void getNormalY(size_t n_i)const
	{
		fprintf(mFile,"\"%s.n[%i].ny\"",mName.c_str(),n_i);
	}
	void getNormalY()const
	{

		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());
	}
	void getNormalZ(size_t n_i)const
	{
		fprintf(mFile,"\"%s.n[%i].nz\"",mName.c_str(),n_i);
	}
	void getNormalZ()const
	{

		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());
	}
	void getTogglePointNormals()const
	{
		fprintf(mFile,"\"%s.tpn\"",mName.c_str());
	}
	void getTogglePointPosition()const
	{
		fprintf(mFile,"\"%s.tpp\"",mName.c_str());
	}
	void getCvIthIndex(size_t ci_i)const
	{
		fprintf(mFile,"\"%s.ci[%i]\"",mName.c_str(),ci_i);
	}
	void getCvIthIndex()const
	{

		fprintf(mFile,"\"%s.ci\"",mName.c_str());
	}
	void getCvJthIndex(size_t cj_i)const
	{
		fprintf(mFile,"\"%s.cj[%i]\"",mName.c_str(),cj_i);
	}
	void getCvJthIndex()const
	{

		fprintf(mFile,"\"%s.cj\"",mName.c_str());
	}
	void getCvPosition(size_t cv_i)const
	{
		fprintf(mFile,"\"%s.cv[%i]\"",mName.c_str(),cv_i);
	}
	void getCvPosition()const
	{

		fprintf(mFile,"\"%s.cv\"",mName.c_str());
	}
	void getCvpositionX(size_t cv_i)const
	{
		fprintf(mFile,"\"%s.cv[%i].cvx\"",mName.c_str(),cv_i);
	}
	void getCvpositionX()const
	{

		fprintf(mFile,"\"%s.cv.cvx\"",mName.c_str());
	}
	void getCvpositionY(size_t cv_i)const
	{
		fprintf(mFile,"\"%s.cv[%i].cvy\"",mName.c_str(),cv_i);
	}
	void getCvpositionY()const
	{

		fprintf(mFile,"\"%s.cv.cvy\"",mName.c_str());
	}
	void getCvpositionZ(size_t cv_i)const
	{
		fprintf(mFile,"\"%s.cv[%i].cvz\"",mName.c_str(),cv_i);
	}
	void getCvpositionZ()const
	{

		fprintf(mFile,"\"%s.cv.cvz\"",mName.c_str());
	}
	void getBias()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getFixBoundary()const
	{
		fprintf(mFile,"\"%s.fb\"",mName.c_str());
	}
	void getShouldBeLast()const
	{
		fprintf(mFile,"\"%s.sbl\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
protected:
	StitchSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_STITCHSRF_H__
