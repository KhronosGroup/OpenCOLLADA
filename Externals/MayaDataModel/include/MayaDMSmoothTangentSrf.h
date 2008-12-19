/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SMOOTHTANGENTSRF_H__
#define __MayaDM_SMOOTHTANGENTSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class SmoothTangentSrf : public AbstractBaseCreate
{
public:
public:
	SmoothTangentSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "smoothTangentSrf"){}
	virtual ~SmoothTangentSrf(){}
	void setParameter(size_t p_i,double p)
	{
		if(p == 0.0) return;
		fprintf(mFile,"setAttr \".p[%i]\" %f;\n", p_i,p);

	}
	void setDirection(unsigned int d)
	{
		if(d == 1) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setSmoothness(unsigned int s)
	{
		if(s == 1) return;
		fprintf(mFile,"setAttr \".s\" %i;\n", s);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getParameter(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getSmoothness()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	SmoothTangentSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SMOOTHTANGENTSRF_H__
