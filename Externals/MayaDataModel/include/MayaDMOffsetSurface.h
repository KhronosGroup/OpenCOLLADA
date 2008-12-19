/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OFFSETSURFACE_H__
#define __MayaDM_OFFSETSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class OffsetSurface : public AbstractBaseCreate
{
public:
public:
	OffsetSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "offsetSurface"){}
	virtual ~OffsetSurface(){}
	void setDistance(double d)
	{
		if(d == 1) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setMethod(unsigned int m)
	{
		if(m == 0) return;
		fprintf(mFile,"setAttr \".m\" %i;\n", m);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getDistance()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getMethod()
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	OffsetSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OFFSETSURFACE_H__
