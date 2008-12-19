/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	StitchSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "stitchSrf"){}
	virtual ~StitchSrf(){}
	void setPositionalContinuity(size_t pc_i,bool pc)
	{
		if(pc == true) return;
		fprintf(mFile,"setAttr \".pc[%i]\" %i;\n", pc_i,pc);

	}
	void setTangentialContinuity(size_t tc_i,bool tc)
	{
		if(tc == false) return;
		fprintf(mFile,"setAttr \".tc[%i]\" %i;\n", tc_i,tc);

	}
	void setToggleTolerance(size_t tt_i,bool tt)
	{
		if(tt == false) return;
		fprintf(mFile,"setAttr \".tt[%i]\" %i;\n", tt_i,tt);

	}
	void setTolerance(size_t tol_i,double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol[%i]\" %f;\n", tol_i,tol);

	}
	void setStepCount(size_t sc_i,int sc)
	{
		if(sc == 20) return;
		fprintf(mFile,"setAttr \".sc[%i]\" %i;\n", sc_i,sc);

	}
	void setParameterU(size_t u_i,double u)
	{
		if(u == -10000) return;
		fprintf(mFile,"setAttr \".u[%i]\" %f;\n", u_i,u);

	}
	void setParameterV(size_t v_i,double v)
	{
		if(v == -10000) return;
		fprintf(mFile,"setAttr \".v[%i]\" %f;\n", v_i,v);

	}
	void setTogglePointNormals(bool tpn)
	{
		if(tpn == false) return;
		fprintf(mFile,"setAttr \".tpn\" %i;\n", tpn);

	}
	void setTogglePointPosition(bool tpp)
	{
		if(tpp == true) return;
		fprintf(mFile,"setAttr \".tpp\" %i;\n", tpp);

	}
	void setCvIthIndex(size_t ci_i,int ci)
	{
		if(ci == -1) return;
		fprintf(mFile,"setAttr \".ci[%i]\" %i;\n", ci_i,ci);

	}
	void setCvJthIndex(size_t cj_i,int cj)
	{
		if(cj == -1) return;
		fprintf(mFile,"setAttr \".cj[%i]\" %i;\n", cj_i,cj);

	}
	void setBias(double b)
	{
		if(b == 1.0) return;
		fprintf(mFile,"setAttr \".b\" %f;\n", b);

	}
	void setFixBoundary(bool fb)
	{
		if(fb == false) return;
		fprintf(mFile,"setAttr \".fb\" %i;\n", fb);

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
	StitchSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_STITCHSRF_H__
