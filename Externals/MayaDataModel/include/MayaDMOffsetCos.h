/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OFFSETCOS_H__
#define __MayaDM_OFFSETCOS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class OffsetCos : public AbstractBaseCreate
{
public:
public:

	OffsetCos():AbstractBaseCreate(){}
	OffsetCos(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "offsetCos", shared, create){}
	virtual ~OffsetCos(){}

	void setCutLoop(bool cl)
	{
		if(cl == false) return;
		fprintf(mFile,"\tsetAttr \".cl\" %i;\n", cl);
	}
	void setConnectBreaks(unsigned int cb)
	{
		if(cb == 2) return;
		fprintf(mFile,"\tsetAttr \".cb\" %i;\n", cb);
	}
	void setDistance(double d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void setSubdivisionDensity(int sd)
	{
		if(sd == 5) return;
		fprintf(mFile,"\tsetAttr \".sd\" %i;\n", sd);
	}
	void setCheckPoints(short cp)
	{
		if(cp == 3) return;
		fprintf(mFile,"\tsetAttr \".cp\" %i;\n", cp);
	}
	void setStitch(bool st)
	{
		if(st == true) return;
		fprintf(mFile,"\tsetAttr \".st\" %i;\n", st);
	}
	void getInputCurve()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getCutLoop()const
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getConnectBreaks()const
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());
	}
	void getDistance()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getSubdivisionDensity()const
	{
		fprintf(mFile,"\"%s.sd\"",mName.c_str());
	}
	void getCheckPoints()const
	{
		fprintf(mFile,"\"%s.cp\"",mName.c_str());
	}
	void getStitch()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getOutputCurve(size_t oc_i)const
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);
	}
	void getOutputCurve()const
	{

		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
protected:
	OffsetCos(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OFFSETCOS_H__
