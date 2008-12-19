/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEINTERSECT_H__
#define __MayaDM_CURVEINTERSECT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class CurveIntersect : public AbstractBaseCreate
{
public:
public:
	CurveIntersect(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "curveIntersect"){}
	virtual ~CurveIntersect(){}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void setUseDirection(bool ud)
	{
		if(ud == false) return;
		fprintf(mFile,"setAttr \".ud\" %i;\n", ud);

	}
	void setDirection(const double3& d)
	{
		fprintf(mFile,"setAttr \".d\" -type \"double3\" ");
		d.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDirectionX(double dx)
	{
		if(dx == 0) return;
		fprintf(mFile,"setAttr \".d.dx\" %f;\n", dx);

	}
	void setDirectionY(double dy)
	{
		if(dy == 1) return;
		fprintf(mFile,"setAttr \".d.dy\" %f;\n", dy);

	}
	void setDirectionZ(double dz)
	{
		if(dz == 0) return;
		fprintf(mFile,"setAttr \".d.dz\" %f;\n", dz);

	}
	void getInputCurve1()
	{
		fprintf(mFile,"\"%s.ic1\"",mName.c_str());

	}
	void getInputCurve2()
	{
		fprintf(mFile,"\"%s.ic2\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getUseDirection()
	{
		fprintf(mFile,"\"%s.ud\"",mName.c_str());

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getDirectionX()
	{
		fprintf(mFile,"\"%s.d.dx\"",mName.c_str());

	}
	void getDirectionY()
	{
		fprintf(mFile,"\"%s.d.dy\"",mName.c_str());

	}
	void getDirectionZ()
	{
		fprintf(mFile,"\"%s.d.dz\"",mName.c_str());

	}
	void getParameter1(size_t p1_i)
	{
		fprintf(mFile,"\"%s.p1[%i]\"",mName.c_str(),p1_i);

	}
	void getParameter2(size_t p2_i)
	{
		fprintf(mFile,"\"%s.p2[%i]\"",mName.c_str(),p2_i);

	}
protected:
	CurveIntersect(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEINTERSECT_H__
