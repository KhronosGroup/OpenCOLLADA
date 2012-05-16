/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AVGCURVES_H__
#define __MayaDM_AVGCURVES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class AvgCurves : public AbstractBaseCreate
{
public:
public:

	AvgCurves():AbstractBaseCreate(){}
	AvgCurves(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "avgCurves", shared, create){}
	virtual ~AvgCurves(){}

	void setWeight1(double w1)
	{
		if(w1 == 0.5) return;
		fprintf(mFile,"\tsetAttr \".w1\" %f;\n", w1);
	}
	void setWeight2(double w2)
	{
		if(w2 == 0.5) return;
		fprintf(mFile,"\tsetAttr \".w2\" %f;\n", w2);
	}
	void setAutomaticWeight(bool aw)
	{
		if(aw == true) return;
		fprintf(mFile,"\tsetAttr \".aw\" %i;\n", aw);
	}
	void setNormalizeWeights(bool nw)
	{
		if(nw == true) return;
		fprintf(mFile,"\tsetAttr \".nw\" %i;\n", nw);
	}
	void getInputCurve1()const
	{
		fprintf(mFile,"\"%s.ic1\"",mName.c_str());
	}
	void getInputCurve2()const
	{
		fprintf(mFile,"\"%s.ic2\"",mName.c_str());
	}
	void getWeight1()const
	{
		fprintf(mFile,"\"%s.w1\"",mName.c_str());
	}
	void getWeight2()const
	{
		fprintf(mFile,"\"%s.w2\"",mName.c_str());
	}
	void getAutomaticWeight()const
	{
		fprintf(mFile,"\"%s.aw\"",mName.c_str());
	}
	void getNormalizeWeights()const
	{
		fprintf(mFile,"\"%s.nw\"",mName.c_str());
	}
	void getOutputCurve()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
protected:
	AvgCurves(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_AVGCURVES_H__
