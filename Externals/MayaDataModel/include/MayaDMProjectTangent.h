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
	ProjectTangent(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "projectTangent"){}
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
	void getInputCurveToProject()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getInputCurve1ToProjectTo()
	{
		fprintf(mFile,"\"%s.ic1\"",mName.c_str());

	}
	void getInputCurve2ToProjectTo()
	{
		fprintf(mFile,"\"%s.ic2\"",mName.c_str());

	}
	void getInputSurfaceToProjectTo()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getOutputCurve()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getTangentScale()
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());

	}
	void getCurvatureScale()
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());

	}
	void getRotate()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getTangentDirection()
	{
		fprintf(mFile,"\"%s.td\"",mName.c_str());

	}
	void getCurvature()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getReverseTangent()
	{
		fprintf(mFile,"\"%s.rt\"",mName.c_str());

	}
	void getIgnoreEdges()
	{
		fprintf(mFile,"\"%s.ie\"",mName.c_str());

	}
protected:
	ProjectTangent(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PROJECTTANGENT_H__
