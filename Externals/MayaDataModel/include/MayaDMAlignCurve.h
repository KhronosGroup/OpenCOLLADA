/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ALIGNCURVE_H__
#define __MayaDM_ALIGNCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class AlignCurve : public AbstractBaseCreate
{
public:
public:
	AlignCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "alignCurve"){}
	virtual ~AlignCurve(){}
	void setTangentScale1(double ts1)
	{
		if(ts1 == 1.0) return;
		fprintf(mFile,"setAttr \".ts1\" %f;\n", ts1);

	}
	void setTangentScale2(double ts2)
	{
		if(ts2 == 1.0) return;
		fprintf(mFile,"setAttr \".ts2\" %f;\n", ts2);

	}
	void setCurvatureScale1(double cs1)
	{
		if(cs1 == 0.0) return;
		fprintf(mFile,"setAttr \".cs1\" %f;\n", cs1);

	}
	void setCurvatureScale2(double cs2)
	{
		if(cs2 == 0.0) return;
		fprintf(mFile,"setAttr \".cs2\" %f;\n", cs2);

	}
	void setPositionalContinuityType(unsigned int pct)
	{
		if(pct == 1) return;
		fprintf(mFile,"setAttr \".pct\" %i;\n", pct);

	}
	void setTangentContinuityType(unsigned int tct)
	{
		if(tct == 1) return;
		fprintf(mFile,"setAttr \".tct\" %i;\n", tct);

	}
	void setJoinParameter(float jnp)
	{
		if(jnp == 123456.0) return;
		fprintf(mFile,"setAttr \".jnp\" %f;\n", jnp);

	}
	void setReverse1(bool rv1)
	{
		if(rv1 == false) return;
		fprintf(mFile,"setAttr \".rv1\" %i;\n", rv1);

	}
	void setReverse2(bool rv2)
	{
		if(rv2 == false) return;
		fprintf(mFile,"setAttr \".rv2\" %i;\n", rv2);

	}
	void setAttach(bool at)
	{
		if(at == false) return;
		fprintf(mFile,"setAttr \".at\" %i;\n", at);

	}
	void setKeepMultipleKnots(bool kmk)
	{
		if(kmk == true) return;
		fprintf(mFile,"setAttr \".kmk\" %i;\n", kmk);

	}
	void setPositionalContinuity(bool pc)
	{
		if(pc == true) return;
		fprintf(mFile,"setAttr \".pc\" %i;\n", pc);

	}
	void setTangentContinuity(bool tc)
	{
		if(tc == true) return;
		fprintf(mFile,"setAttr \".tc\" %i;\n", tc);

	}
	void setCurvatureContinuity(bool cc)
	{
		if(cc == false) return;
		fprintf(mFile,"setAttr \".cc\" %i;\n", cc);

	}
	void getInputCurve1()
	{
		fprintf(mFile,"\"%s.ic1\"",mName.c_str());

	}
	void getInputCurve2()
	{
		fprintf(mFile,"\"%s.ic2\"",mName.c_str());

	}
	void getOutputCurve1()
	{
		fprintf(mFile,"\"%s.oc1\"",mName.c_str());

	}
	void getOutputCurve2()
	{
		fprintf(mFile,"\"%s.oc2\"",mName.c_str());

	}
	void getTangentScale1()
	{
		fprintf(mFile,"\"%s.ts1\"",mName.c_str());

	}
	void getTangentScale2()
	{
		fprintf(mFile,"\"%s.ts2\"",mName.c_str());

	}
	void getCurvatureScale1()
	{
		fprintf(mFile,"\"%s.cs1\"",mName.c_str());

	}
	void getCurvatureScale2()
	{
		fprintf(mFile,"\"%s.cs2\"",mName.c_str());

	}
	void getPositionalContinuityType()
	{
		fprintf(mFile,"\"%s.pct\"",mName.c_str());

	}
	void getTangentContinuityType()
	{
		fprintf(mFile,"\"%s.tct\"",mName.c_str());

	}
	void getJoinParameter()
	{
		fprintf(mFile,"\"%s.jnp\"",mName.c_str());

	}
	void getReverse1()
	{
		fprintf(mFile,"\"%s.rv1\"",mName.c_str());

	}
	void getReverse2()
	{
		fprintf(mFile,"\"%s.rv2\"",mName.c_str());

	}
	void getAttach()
	{
		fprintf(mFile,"\"%s.at\"",mName.c_str());

	}
	void getKeepMultipleKnots()
	{
		fprintf(mFile,"\"%s.kmk\"",mName.c_str());

	}
	void getPositionalContinuity()
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());

	}
	void getTangentContinuity()
	{
		fprintf(mFile,"\"%s.tc\"",mName.c_str());

	}
	void getCurvatureContinuity()
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());

	}
protected:
	AlignCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ALIGNCURVE_H__
