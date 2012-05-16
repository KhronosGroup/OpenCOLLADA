/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	PointOnCurveInfo():AbstractBaseCreate(){}
	PointOnCurveInfo(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "pointOnCurveInfo", shared, create){}
	virtual ~PointOnCurveInfo(){}

	void setParameter(double pr)
	{
		if(pr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pr\" %f;\n", pr);
	}
	void setTurnOnPercentage(bool top)
	{
		if(top == false) return;
		fprintf(mFile,"\tsetAttr \".top\" %i;\n", top);
	}
	void getInputCurve()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getParameter()const
	{
		fprintf(mFile,"\"%s.pr\"",mName.c_str());
	}
	void getTurnOnPercentage()const
	{
		fprintf(mFile,"\"%s.top\"",mName.c_str());
	}
	void getResult()const
	{
		fprintf(mFile,"\"%s.rs\"",mName.c_str());
	}
	void getPosition()const
	{
		fprintf(mFile,"\"%s.rs.p\"",mName.c_str());
	}
	void getPositionX()const
	{
		fprintf(mFile,"\"%s.rs.p.px\"",mName.c_str());
	}
	void getPositionY()const
	{
		fprintf(mFile,"\"%s.rs.p.py\"",mName.c_str());
	}
	void getPositionZ()const
	{
		fprintf(mFile,"\"%s.rs.p.pz\"",mName.c_str());
	}
	void getNormal()const
	{
		fprintf(mFile,"\"%s.rs.n\"",mName.c_str());
	}
	void getNormalX()const
	{
		fprintf(mFile,"\"%s.rs.n.nx\"",mName.c_str());
	}
	void getNormalY()const
	{
		fprintf(mFile,"\"%s.rs.n.ny\"",mName.c_str());
	}
	void getNormalZ()const
	{
		fprintf(mFile,"\"%s.rs.n.nz\"",mName.c_str());
	}
	void getNormalizedNormal()const
	{
		fprintf(mFile,"\"%s.rs.nn\"",mName.c_str());
	}
	void getNormalizedNormalX()const
	{
		fprintf(mFile,"\"%s.rs.nn.nnx\"",mName.c_str());
	}
	void getNormalizedNormalY()const
	{
		fprintf(mFile,"\"%s.rs.nn.nny\"",mName.c_str());
	}
	void getNormalizedNormalZ()const
	{
		fprintf(mFile,"\"%s.rs.nn.nnz\"",mName.c_str());
	}
	void getTangent()const
	{
		fprintf(mFile,"\"%s.rs.t\"",mName.c_str());
	}
	void getTangentX()const
	{
		fprintf(mFile,"\"%s.rs.t.tx\"",mName.c_str());
	}
	void getTangentY()const
	{
		fprintf(mFile,"\"%s.rs.t.ty\"",mName.c_str());
	}
	void getTangentZ()const
	{
		fprintf(mFile,"\"%s.rs.t.tz\"",mName.c_str());
	}
	void getNormalizedTangent()const
	{
		fprintf(mFile,"\"%s.rs.nt\"",mName.c_str());
	}
	void getNormalizedTangentX()const
	{
		fprintf(mFile,"\"%s.rs.nt.ntx\"",mName.c_str());
	}
	void getNormalizedTangentY()const
	{
		fprintf(mFile,"\"%s.rs.nt.nty\"",mName.c_str());
	}
	void getNormalizedTangentZ()const
	{
		fprintf(mFile,"\"%s.rs.nt.ntz\"",mName.c_str());
	}
	void getCurvatureCenter()const
	{
		fprintf(mFile,"\"%s.rs.cc\"",mName.c_str());
	}
	void getCurvatureCenterX()const
	{
		fprintf(mFile,"\"%s.rs.cc.ccx\"",mName.c_str());
	}
	void getCurvatureCenterY()const
	{
		fprintf(mFile,"\"%s.rs.cc.ccy\"",mName.c_str());
	}
	void getCurvatureCenterZ()const
	{
		fprintf(mFile,"\"%s.rs.cc.ccz\"",mName.c_str());
	}
	void getCurvatureRadius()const
	{
		fprintf(mFile,"\"%s.rs.cr\"",mName.c_str());
	}
protected:
	PointOnCurveInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POINTONCURVEINFO_H__
