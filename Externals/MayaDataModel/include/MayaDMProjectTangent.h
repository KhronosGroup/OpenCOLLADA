/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PROJECTTANGENT_H__
#define __MayaDM_PROJECTTANGENT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class ProjectTangent : public AbstractBaseCreate
{
public:
public:

	ProjectTangent():AbstractBaseCreate(){}
	ProjectTangent(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "projectTangent", shared, create){}
	virtual ~ProjectTangent(){}

	void setTangentScale(double ts)
	{
		if(ts == 1) return;
		fprintf(mFile,"\tsetAttr \".ts\" %f;\n", ts);
	}
	void setCurvatureScale(double cs)
	{
		if(cs == 0) return;
		fprintf(mFile,"\tsetAttr \".cs\" %f;\n", cs);
	}
	void setRotate(double ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"\tsetAttr \".ro\" %f;\n", ro);
	}
	void setTangentDirection(unsigned int td)
	{
		if(td == 1) return;
		fprintf(mFile,"\tsetAttr \".td\" %i;\n", td);
	}
	void setCurvature(bool c)
	{
		if(c == false) return;
		fprintf(mFile,"\tsetAttr \".c\" %i;\n", c);
	}
	void setReverseTangent(bool rt)
	{
		if(rt == false) return;
		fprintf(mFile,"\tsetAttr \".rt\" %i;\n", rt);
	}
	void setIgnoreEdges(bool ie)
	{
		if(ie == false) return;
		fprintf(mFile,"\tsetAttr \".ie\" %i;\n", ie);
	}
	void getInputCurveToProject()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getInputCurve1ToProjectTo()const
	{
		fprintf(mFile,"\"%s.ic1\"",mName.c_str());
	}
	void getInputCurve2ToProjectTo()const
	{
		fprintf(mFile,"\"%s.ic2\"",mName.c_str());
	}
	void getInputSurfaceToProjectTo()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getOutputCurve()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getTangentScale()const
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());
	}
	void getCurvatureScale()const
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
	void getRotate()const
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());
	}
	void getTangentDirection()const
	{
		fprintf(mFile,"\"%s.td\"",mName.c_str());
	}
	void getCurvature()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getReverseTangent()const
	{
		fprintf(mFile,"\"%s.rt\"",mName.c_str());
	}
	void getIgnoreEdges()const
	{
		fprintf(mFile,"\"%s.ie\"",mName.c_str());
	}
protected:
	ProjectTangent(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PROJECTTANGENT_H__
