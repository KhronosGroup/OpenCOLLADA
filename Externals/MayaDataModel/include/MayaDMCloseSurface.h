/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOSESURFACE_H__
#define __MayaDM_CLOSESURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class CloseSurface : public AbstractBaseCreate
{
public:
public:
	CloseSurface():AbstractBaseCreate(){}
	CloseSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "closeSurface"){}
	virtual ~CloseSurface(){}
	void setPreserveShape(unsigned int ps)
	{
		if(ps == 1) return;
		fprintf(mFile,"\tsetAttr \".ps\" %i;\n", ps);

	}
	void setBlendBias(double bb)
	{
		if(bb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".bb\" %f;\n", bb);

	}
	void setBlendKnotInsertion(bool bki)
	{
		if(bki == false) return;
		fprintf(mFile,"\tsetAttr \".bki\" %i;\n", bki);

	}
	void setParameter(double p)
	{
		if(p == 0.1) return;
		fprintf(mFile,"\tsetAttr \".p\" %f;\n", p);

	}
	void setDirection(unsigned int d)
	{
		if(d == 0) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getPreserveShape()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getBlendBias()
	{
		fprintf(mFile,"\"%s.bb\"",mName.c_str());

	}
	void getBlendKnotInsertion()
	{
		fprintf(mFile,"\"%s.bki\"",mName.c_str());

	}
	void getParameter()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	CloseSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLOSESURFACE_H__
