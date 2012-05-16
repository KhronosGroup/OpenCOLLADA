/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	RevolvedPrimitive():Primitive(){}
	RevolvedPrimitive(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Primitive(file, name, parent, "revolvedPrimitive", shared, create){}
	virtual ~RevolvedPrimitive(){}

	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"\tsetAttr \".r\" %f;\n", r);
	}
	void setStartSweep(double ssw)
	{
		if(ssw == 0) return;
		fprintf(mFile,"\tsetAttr \".ssw\" %f;\n", ssw);
	}
	void setEndSweep(double esw)
	{
		if(esw == 6.2831853) return;
		fprintf(mFile,"\tsetAttr \".esw\" %f;\n", esw);
	}
	void setUseTolerance(bool ut)
	{
		if(ut == false) return;
		fprintf(mFile,"\tsetAttr \".ut\" %i;\n", ut);
	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setSections(int s)
	{
		if(s == 8) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);
	}
	void setSpans(int nsp)
	{
		if(nsp == 1) return;
		fprintf(mFile,"\tsetAttr \".nsp\" %i;\n", nsp);
	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void setHeightRatio(double hr)
	{
		if(hr == 2.0) return;
		fprintf(mFile,"\tsetAttr \".hr\" %f;\n", hr);
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getStartSweep()const
	{
		fprintf(mFile,"\"%s.ssw\"",mName.c_str());
	}
	void getEndSweep()const
	{
		fprintf(mFile,"\"%s.esw\"",mName.c_str());
	}
	void getUseTolerance()const
	{
		fprintf(mFile,"\"%s.ut\"",mName.c_str());
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSections()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getSpans()const
	{
		fprintf(mFile,"\"%s.nsp\"",mName.c_str());
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getHeightRatio()const
	{
		fprintf(mFile,"\"%s.hr\"",mName.c_str());
	}
	void getTopCapCurve()const
	{
		fprintf(mFile,"\"%s.tcc\"",mName.c_str());
	}
	void getBottomCapCurve()const
	{
		fprintf(mFile,"\"%s.bcc\"",mName.c_str());
	}
	void getAbsoluteSweepDifference()const
	{
		fprintf(mFile,"\"%s.asd\"",mName.c_str());
	}
protected:
	RevolvedPrimitive(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Primitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_REVOLVEDPRIMITIVE_H__
