/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	OffsetCos(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "offsetCos"){}
	virtual ~OffsetCos(){}
	void setCutLoop(bool cl)
	{
		if(cl == false) return;
		fprintf(mFile,"setAttr \".cl\" %i;\n", cl);

	}
	void setConnectBreaks(unsigned int cb)
	{
		if(cb == 2) return;
		fprintf(mFile,"setAttr \".cb\" %i;\n", cb);

	}
	void setDistance(double d)
	{
		if(d == 1) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void setSubdivisionDensity(int sd)
	{
		if(sd == 5) return;
		fprintf(mFile,"setAttr \".sd\" %i;\n", sd);

	}
	void setCheckPoints(short cp)
	{
		if(cp == 3) return;
		fprintf(mFile,"setAttr \".cp\" %i;\n", cp);

	}
	void setStitch(bool st)
	{
		if(st == true) return;
		fprintf(mFile,"setAttr \".st\" %i;\n", st);

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getCutLoop()
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());

	}
	void getConnectBreaks()
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());

	}
	void getDistance()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getSubdivisionDensity()
	{
		fprintf(mFile,"\"%s.sd\"",mName.c_str());

	}
	void getCheckPoints()
	{
		fprintf(mFile,"\"%s.cp\"",mName.c_str());

	}
	void getStitch()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getOutputCurve(size_t oc_i)
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);

	}
protected:
	OffsetCos(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OFFSETCOS_H__
