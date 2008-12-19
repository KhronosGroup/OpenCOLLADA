/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LOFT_H__
#define __MayaDM_LOFT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class Loft : public AbstractBaseCreate
{
public:
public:
	Loft(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "loft"){}
	virtual ~Loft(){}
	void setUniform(bool u)
	{
		if(u == false) return;
		fprintf(mFile,"setAttr \".u\" %i;\n", u);

	}
	void setClose(bool c)
	{
		if(c == false) return;
		fprintf(mFile,"setAttr \".c\" %i;\n", c);

	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setAutoReverse(bool ar)
	{
		if(ar == true) return;
		fprintf(mFile,"setAttr \".ar\" %i;\n", ar);

	}
	void setReverse(size_t r_i,bool r)
	{
		if(r == false) return;
		fprintf(mFile,"setAttr \".r[%i]\" %i;\n", r_i,r);

	}
	void setReverseSurfaceNormals(bool rsn)
	{
		if(rsn == false) return;
		fprintf(mFile,"setAttr \".rsn\" %i;\n", rsn);

	}
	void setSectionSpans(int ss)
	{
		if(ss == 1) return;
		fprintf(mFile,"setAttr \".ss\" %i;\n", ss);

	}
	void setCreateCusp(size_t cc_i,bool cc)
	{
		if(cc == false) return;
		fprintf(mFile,"setAttr \".cc[%i]\" %i;\n", cc_i,cc);

	}
	void getInputCurve(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i]\"",mName.c_str(),ic_i);

	}
	void getUniform()
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());

	}
	void getClose()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getAutoReverse()
	{
		fprintf(mFile,"\"%s.ar\"",mName.c_str());

	}
	void getReverse(size_t r_i)
	{
		fprintf(mFile,"\"%s.r[%i]\"",mName.c_str(),r_i);

	}
	void getReverseSurfaceNormals()
	{
		fprintf(mFile,"\"%s.rsn\"",mName.c_str());

	}
	void getSectionSpans()
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getCreateCusp(size_t cc_i)
	{
		fprintf(mFile,"\"%s.cc[%i]\"",mName.c_str(),cc_i);

	}
protected:
	Loft(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_LOFT_H__
