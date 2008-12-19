/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REVOLVEDPRIMITIVE_H__
#define __MayaDM_REVOLVEDPRIMITIVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPrimitive.h"
namespace MayaDM
{
class RevolvedPrimitive : public Primitive
{
public:
public:
	RevolvedPrimitive(FILE* file,const std::string& name,const std::string& parent=""):Primitive(file, name, parent, "revolvedPrimitive"){}
	virtual ~RevolvedPrimitive(){}
	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setStartSweep(double ssw)
	{
		if(ssw == 0) return;
		fprintf(mFile,"setAttr \".ssw\" %f;\n", ssw);

	}
	void setEndSweep(double esw)
	{
		if(esw == 6.2831853) return;
		fprintf(mFile,"setAttr \".esw\" %f;\n", esw);

	}
	void setUseTolerance(bool ut)
	{
		if(ut == false) return;
		fprintf(mFile,"setAttr \".ut\" %i;\n", ut);

	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setSections(int s)
	{
		if(s == 8) return;
		fprintf(mFile,"setAttr \".s\" %i;\n", s);

	}
	void setSpans(int nsp)
	{
		if(nsp == 1) return;
		fprintf(mFile,"setAttr \".nsp\" %i;\n", nsp);

	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void setHeightRatio(double hr)
	{
		if(hr == 2.0) return;
		fprintf(mFile,"setAttr \".hr\" %f;\n", hr);

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getStartSweep()
	{
		fprintf(mFile,"\"%s.ssw\"",mName.c_str());

	}
	void getEndSweep()
	{
		fprintf(mFile,"\"%s.esw\"",mName.c_str());

	}
	void getUseTolerance()
	{
		fprintf(mFile,"\"%s.ut\"",mName.c_str());

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getSections()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getSpans()
	{
		fprintf(mFile,"\"%s.nsp\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getHeightRatio()
	{
		fprintf(mFile,"\"%s.hr\"",mName.c_str());

	}
	void getTopCapCurve()
	{
		fprintf(mFile,"\"%s.tcc\"",mName.c_str());

	}
	void getBottomCapCurve()
	{
		fprintf(mFile,"\"%s.bcc\"",mName.c_str());

	}
	void getAbsoluteSweepDifference()
	{
		fprintf(mFile,"\"%s.asd\"",mName.c_str());

	}
protected:
	RevolvedPrimitive(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Primitive(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_REVOLVEDPRIMITIVE_H__
