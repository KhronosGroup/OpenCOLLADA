/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POINTONCURVEINFO_H__
#define __MayaDM_POINTONCURVEINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class PointOnCurveInfo : public AbstractBaseCreate
{
public:
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:
	PointOnCurveInfo(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "pointOnCurveInfo"){}
	virtual ~PointOnCurveInfo(){}
	void setParameter(double pr)
	{
		if(pr == 0.0) return;
		fprintf(mFile,"setAttr \".pr\" %f;\n", pr);

	}
	void setTurnOnPercentage(bool top)
	{
		if(top == false) return;
		fprintf(mFile,"setAttr \".top\" %i;\n", top);

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getParameter()
	{
		fprintf(mFile,"\"%s.pr\"",mName.c_str());

	}
	void getTurnOnPercentage()
	{
		fprintf(mFile,"\"%s.top\"",mName.c_str());

	}
	void getResult()
	{
		fprintf(mFile,"\"%s.rs\"",mName.c_str());

	}
	void getPosition()
	{
		fprintf(mFile,"\"%s.rs.p\"",mName.c_str());

	}
	void getPositionX()
	{
		fprintf(mFile,"\"%s.rs.p.px\"",mName.c_str());

	}
	void getPositionY()
	{
		fprintf(mFile,"\"%s.rs.p.py\"",mName.c_str());

	}
	void getPositionZ()
	{
		fprintf(mFile,"\"%s.rs.p.pz\"",mName.c_str());

	}
	void getNormal()
	{
		fprintf(mFile,"\"%s.rs.n\"",mName.c_str());

	}
	void getNormalX()
	{
		fprintf(mFile,"\"%s.rs.n.nx\"",mName.c_str());

	}
	void getNormalY()
	{
		fprintf(mFile,"\"%s.rs.n.ny\"",mName.c_str());

	}
	void getNormalZ()
	{
		fprintf(mFile,"\"%s.rs.n.nz\"",mName.c_str());

	}
	void getNormalizedNormal()
	{
		fprintf(mFile,"\"%s.rs.nn\"",mName.c_str());

	}
	void getNormalizedNormalX()
	{
		fprintf(mFile,"\"%s.rs.nn.nnx\"",mName.c_str());

	}
	void getNormalizedNormalY()
	{
		fprintf(mFile,"\"%s.rs.nn.nny\"",mName.c_str());

	}
	void getNormalizedNormalZ()
	{
		fprintf(mFile,"\"%s.rs.nn.nnz\"",mName.c_str());

	}
	void getTangent()
	{
		fprintf(mFile,"\"%s.rs.t\"",mName.c_str());

	}
	void getTangentX()
	{
		fprintf(mFile,"\"%s.rs.t.tx\"",mName.c_str());

	}
	void getTangentY()
	{
		fprintf(mFile,"\"%s.rs.t.ty\"",mName.c_str());

	}
	void getTangentZ()
	{
		fprintf(mFile,"\"%s.rs.t.tz\"",mName.c_str());

	}
	void getNormalizedTangent()
	{
		fprintf(mFile,"\"%s.rs.nt\"",mName.c_str());

	}
	void getNormalizedTangentX()
	{
		fprintf(mFile,"\"%s.rs.nt.ntx\"",mName.c_str());

	}
	void getNormalizedTangentY()
	{
		fprintf(mFile,"\"%s.rs.nt.nty\"",mName.c_str());

	}
	void getNormalizedTangentZ()
	{
		fprintf(mFile,"\"%s.rs.nt.ntz\"",mName.c_str());

	}
	void getCurvatureCenter()
	{
		fprintf(mFile,"\"%s.rs.cc\"",mName.c_str());

	}
	void getCurvatureCenterX()
	{
		fprintf(mFile,"\"%s.rs.cc.ccx\"",mName.c_str());

	}
	void getCurvatureCenterY()
	{
		fprintf(mFile,"\"%s.rs.cc.ccy\"",mName.c_str());

	}
	void getCurvatureCenterZ()
	{
		fprintf(mFile,"\"%s.rs.cc.ccz\"",mName.c_str());

	}
	void getCurvatureRadius()
	{
		fprintf(mFile,"\"%s.rs.cr\"",mName.c_str());

	}
protected:
	PointOnCurveInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POINTONCURVEINFO_H__
