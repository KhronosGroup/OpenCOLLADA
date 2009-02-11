/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_INTERSECTSURFACE_H__
#define __MayaDM_INTERSECTSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class IntersectSurface : public AbstractBaseCreate
{
public:
public:
	IntersectSurface():AbstractBaseCreate(){}
	IntersectSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "intersectSurface"){}
	virtual ~IntersectSurface(){}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);

	}
	void getInputSurface1()
	{
		fprintf(mFile,"\"%s.is1\"",mName.c_str());

	}
	void getInputSurface2()
	{
		fprintf(mFile,"\"%s.is2\"",mName.c_str());

	}
	void getCurveOnSurface1(size_t cs1_i)
	{
		fprintf(mFile,"\"%s.cs1[%i]\"",mName.c_str(),cs1_i);

	}
	void getCurveOnSurface2(size_t cs2_i)
	{
		fprintf(mFile,"\"%s.cs2[%i]\"",mName.c_str(),cs2_i);

	}
	void getOutput3dCurve(size_t oc_i)
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
protected:
	IntersectSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_INTERSECTSURFACE_H__
