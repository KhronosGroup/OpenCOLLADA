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
	StitchSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "stitchSrf"){}
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
	void startPositionalContinuity(size_t pc_start,size_t pc_end)
	{
		fprintf(mFile,"\tsetAttr \".pc[%i:%i]\"",pc_start,pc_end);

	}
	void appendPositionalContinuity(bool pc)
	{
		fprintf(mFile," %i",pc);

	}
	void endPositionalContinuity()
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
	void startTangentialContinuity(size_t tc_start,size_t tc_end)
	{
		fprintf(mFile,"\tsetAttr \".tc[%i:%i]\"",tc_start,tc_end);

	}
	void appendTangentialContinuity(bool tc)
	{
		fprintf(mFile," %i",tc);

	}
	void endTangentialContinuity()
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
	void startToggleTolerance(size_t tt_start,size_t tt_end)
	{
		fprintf(mFile,"\tsetAttr \".tt[%i:%i]\"",tt_start,tt_end);

	}
	void appendToggleTolerance(bool tt)
	{
		fprintf(mFile," %i",tt);

	}
	void endToggleTolerance()
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
	void startTolerance(size_t tol_start,size_t tol_end)
	{
		fprintf(mFile,"\tsetAttr \".tol[%i:%i]\"",tol_start,tol_end);

	}
	void appendTolerance(double tol)
	{
		fprintf(mFile," %f",tol);

	}
	void endTolerance()
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
	void startStepCount(size_t sc_start,size_t sc_end)
	{
		fprintf(mFile,"\tsetAttr \".sc[%i:%i]\"",sc_start,sc_end);

	}
	void appendStepCount(int sc)
	{
		fprintf(mFile," %i",sc);

	}
	void endStepCount()
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
	void startParameterU(size_t u_start,size_t u_end)
	{
		fprintf(mFile,"\tsetAttr \".u[%i:%i]\"",u_start,u_end);

	}
	void appendParameterU(double u)
	{
		fprintf(mFile," %f",u);

	}
	void endParameterU()
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
	void startParameterV(size_t v_start,size_t v_end)
	{
		fprintf(mFile,"\tsetAttr \".v[%i:%i]\"",v_start,v_end);

	}
	void appendParameterV(double v)
	{
		fprintf(mFile," %f",v);

	}
	void endParameterV()
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
	void startCvIthIndex(size_t ci_start,size_t ci_end)
	{
		fprintf(mFile,"\tsetAttr \".ci[%i:%i]\"",ci_start,ci_end);

	}
	void appendCvIthIndex(int ci)
	{
		fprintf(mFile," %i",ci);

	}
	void endCvIthIndex()
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
	void startCvJthIndex(size_t cj_start,size_t cj_end)
	{
		fprintf(mFile,"\tsetAttr \".cj[%i:%i]\"",cj_start,cj_end);

	}
	void appendCvJthIndex(int cj)
	{
		fprintf(mFile," %i",cj);

	}
	void endCvJthIndex()
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
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getInputCurve(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i]\"",mName.c_str(),ic_i);

	}
	void getInputMatchCurve(size_t imc_i)
	{
		fprintf(mFile,"\"%s.imc[%i]\"",mName.c_str(),imc_i);

	}
	void getInputReferenceCOS(size_t ir_i)
	{
		fprintf(mFile,"\"%s.ir[%i]\"",mName.c_str(),ir_i);

	}
	void getPositionalContinuity(size_t pc_i)
	{
		fprintf(mFile,"\"%s.pc[%i]\"",mName.c_str(),pc_i);

	}
	void getTangentialContinuity(size_t tc_i)
	{
		fprintf(mFile,"\"%s.tc[%i]\"",mName.c_str(),tc_i);

	}
	void getToggleTolerance(size_t tt_i)
	{
		fprintf(mFile,"\"%s.tt[%i]\"",mName.c_str(),tt_i);

	}
	void getTolerance(size_t tol_i)
	{
		fprintf(mFile,"\"%s.tol[%i]\"",mName.c_str(),tol_i);

	}
	void getStepCount(size_t sc_i)
	{
		fprintf(mFile,"\"%s.sc[%i]\"",mName.c_str(),sc_i);

	}
	void getParameterU(size_t u_i)
	{
		fprintf(mFile,"\"%s.u[%i]\"",mName.c_str(),u_i);

	}
	void getParameterV(size_t v_i)
	{
		fprintf(mFile,"\"%s.v[%i]\"",mName.c_str(),v_i);

	}
	void getPosition(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);

	}
	void getPositionX(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].px\"",mName.c_str(),p_i);

	}
	void getPositionY(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].py\"",mName.c_str(),p_i);

	}
	void getPositionZ(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].pz\"",mName.c_str(),p_i);

	}
	void getNormal(size_t n_i)
	{
		fprintf(mFile,"\"%s.n[%i]\"",mName.c_str(),n_i);

	}
	void getNormalX(size_t n_i)
	{
		fprintf(mFile,"\"%s.n[%i].nx\"",mName.c_str(),n_i);

	}
	void getNormalY(size_t n_i)
	{
		fprintf(mFile,"\"%s.n[%i].ny\"",mName.c_str(),n_i);

	}
	void getNormalZ(size_t n_i)
	{
		fprintf(mFile,"\"%s.n[%i].nz\"",mName.c_str(),n_i);

	}
	void getTogglePointNormals()
	{
		fprintf(mFile,"\"%s.tpn\"",mName.c_str());

	}
	void getTogglePointPosition()
	{
		fprintf(mFile,"\"%s.tpp\"",mName.c_str());

	}
	void getCvIthIndex(size_t ci_i)
	{
		fprintf(mFile,"\"%s.ci[%i]\"",mName.c_str(),ci_i);

	}
	void getCvJthIndex(size_t cj_i)
	{
		fprintf(mFile,"\"%s.cj[%i]\"",mName.c_str(),cj_i);

	}
	void getCvPosition(size_t cv_i)
	{
		fprintf(mFile,"\"%s.cv[%i]\"",mName.c_str(),cv_i);

	}
	void getCvpositionX(size_t cv_i)
	{
		fprintf(mFile,"\"%s.cv[%i].cvx\"",mName.c_str(),cv_i);

	}
	void getCvpositionY(size_t cv_i)
	{
		fprintf(mFile,"\"%s.cv[%i].cvy\"",mName.c_str(),cv_i);

	}
	void getCvpositionZ(size_t cv_i)
	{
		fprintf(mFile,"\"%s.cv[%i].cvz\"",mName.c_str(),cv_i);

	}
	void getBias()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getFixBoundary()
	{
		fprintf(mFile,"\"%s.fb\"",mName.c_str());

	}
	void getShouldBeLast()
	{
		fprintf(mFile,"\"%s.sbl\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	StitchSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_STITCHSRF_H__
