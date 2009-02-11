/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REBUILDCURVE_H__
#define __MayaDM_REBUILDCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class RebuildCurve : public AbstractBaseCreate
{
public:
public:
	RebuildCurve():AbstractBaseCreate(){}
	RebuildCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "rebuildCurve"){}
	virtual ~RebuildCurve(){}
	void setFitRebuild(bool fr)
	{
		if(fr == true) return;
		fprintf(mFile,"\tsetAttr \".fr\" %i;\n", fr);

	}
	void setRebuildType(unsigned int rt)
	{
		if(rt == 0) return;
		fprintf(mFile,"\tsetAttr \".rt\" %i;\n", rt);

	}
	void setSpans(int s)
	{
		if(s == 4) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);

	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);

	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);

	}
	void setEndKnots(unsigned int end)
	{
		if(end == 0) return;
		fprintf(mFile,"\tsetAttr \".end\" %i;\n", end);

	}
	void setKeepRange(unsigned int kr)
	{
		if(kr == 1) return;
		fprintf(mFile,"\tsetAttr \".kr\" %i;\n", kr);

	}
	void setKeepEndPoints(bool kep)
	{
		if(kep == true) return;
		fprintf(mFile,"\tsetAttr \".kep\" %i;\n", kep);

	}
	void setKeepTangents(bool kt)
	{
		if(kt == true) return;
		fprintf(mFile,"\tsetAttr \".kt\" %i;\n", kt);

	}
	void setKeepControlPoints(bool kcp)
	{
		if(kcp == false) return;
		fprintf(mFile,"\tsetAttr \".kcp\" %i;\n", kcp);

	}
	void setSmartSurfaceCurveRebuild(bool scr)
	{
		if(scr == false) return;
		fprintf(mFile,"\tsetAttr \".scr\" %i;\n", scr);

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getMatchCurve()
	{
		fprintf(mFile,"\"%s.mc\"",mName.c_str());

	}
	void getFitRebuild()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getRebuildType()
	{
		fprintf(mFile,"\"%s.rt\"",mName.c_str());

	}
	void getSpans()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getEndKnots()
	{
		fprintf(mFile,"\"%s.end\"",mName.c_str());

	}
	void getKeepRange()
	{
		fprintf(mFile,"\"%s.kr\"",mName.c_str());

	}
	void getKeepEndPoints()
	{
		fprintf(mFile,"\"%s.kep\"",mName.c_str());

	}
	void getKeepTangents()
	{
		fprintf(mFile,"\"%s.kt\"",mName.c_str());

	}
	void getOutputCurve()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getKeepControlPoints()
	{
		fprintf(mFile,"\"%s.kcp\"",mName.c_str());

	}
	void getSmartSurfaceCurveRebuild()
	{
		fprintf(mFile,"\"%s.scr\"",mName.c_str());

	}
protected:
	RebuildCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_REBUILDCURVE_H__
