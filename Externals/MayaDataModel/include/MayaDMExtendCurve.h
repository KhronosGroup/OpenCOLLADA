/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXTENDCURVE_H__
#define __MayaDM_EXTENDCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class ExtendCurve : public AbstractBaseCreate
{
public:
public:

	ExtendCurve():AbstractBaseCreate(){}
	ExtendCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "extendCurve", shared, create){}
	virtual ~ExtendCurve(){}

	void setInputPoint(const double3& ip)
	{
		fprintf(mFile,"\tsetAttr \".ip\" -type \"double3\" ");
		ip.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointX(double px)
	{
		if(px == 0) return;
		fprintf(mFile,"\tsetAttr \".ip.px\" %f;\n", px);
	}
	void setPointY(double py)
	{
		if(py == 0) return;
		fprintf(mFile,"\tsetAttr \".ip.py\" %f;\n", py);
	}
	void setPointZ(double pz)
	{
		if(pz == 0) return;
		fprintf(mFile,"\tsetAttr \".ip.pz\" %f;\n", pz);
	}
	void setExtensionType(unsigned int et)
	{
		if(et == 0) return;
		fprintf(mFile,"\tsetAttr \".et\" %i;\n", et);
	}
	void setExtendMethod(unsigned int em)
	{
		if(em == 0) return;
		fprintf(mFile,"\tsetAttr \".em\" %i;\n", em);
	}
	void setStart(unsigned int s)
	{
		if(s == 1) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);
	}
	void setJoin(bool jn)
	{
		if(jn == true) return;
		fprintf(mFile,"\tsetAttr \".jn\" %i;\n", jn);
	}
	void setDistance(double d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setRemoveMultipleKnots(bool rmk)
	{
		if(rmk == false) return;
		fprintf(mFile,"\tsetAttr \".rmk\" %i;\n", rmk);
	}
	void getInputCurve1()const
	{
		fprintf(mFile,"\"%s.ic1\"",mName.c_str());
	}
	void getInputCurve2()const
	{
		fprintf(mFile,"\"%s.ic2\"",mName.c_str());
	}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getInputPoint()const
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());
	}
	void getPointX()const
	{
		fprintf(mFile,"\"%s.ip.px\"",mName.c_str());
	}
	void getPointY()const
	{
		fprintf(mFile,"\"%s.ip.py\"",mName.c_str());
	}
	void getPointZ()const
	{
		fprintf(mFile,"\"%s.ip.pz\"",mName.c_str());
	}
	void getExtensionType()const
	{
		fprintf(mFile,"\"%s.et\"",mName.c_str());
	}
	void getExtendMethod()const
	{
		fprintf(mFile,"\"%s.em\"",mName.c_str());
	}
	void getStart()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getBothEnds()const
	{
		fprintf(mFile,"\"%s.be\"",mName.c_str());
	}
	void getJoin()const
	{
		fprintf(mFile,"\"%s.jn\"",mName.c_str());
	}
	void getDistance()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getRemoveMultipleKnots()const
	{
		fprintf(mFile,"\"%s.rmk\"",mName.c_str());
	}
	void getOutputCurve()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
protected:
	ExtendCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_EXTENDCURVE_H__
