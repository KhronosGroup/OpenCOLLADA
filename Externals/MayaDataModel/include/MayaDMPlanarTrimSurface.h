/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PLANARTRIMSURFACE_H__
#define __MayaDM_PLANARTRIMSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class PlanarTrimSurface : public AbstractBaseCreate
{
public:
public:

	PlanarTrimSurface():AbstractBaseCreate(){}
	PlanarTrimSurface(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "planarTrimSurface", shared, create){}
	virtual ~PlanarTrimSurface(){}

	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setKeepOutside(bool ko)
	{
		if(ko == false) return;
		fprintf(mFile,"\tsetAttr \".ko\" %i;\n", ko);
	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void getInputCurve(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i]\"",mName.c_str(),ic_i);
	}
	void getInputCurve()const
	{

		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getKeepOutside()const
	{
		fprintf(mFile,"\"%s.ko\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
protected:
	PlanarTrimSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PLANARTRIMSURFACE_H__
