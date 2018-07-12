/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_INSTANCER_H__
#define __MayaDM_INSTANCER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class Instancer : public Transform
{
public:
public:

	Instancer():Transform(){}
	Instancer(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Transform(file, name, parent, "instancer", shared, create){}
	virtual ~Instancer(){}

	void setRotationOrder(unsigned int ror)
	{
		if(ror == 0) return;
		fprintf(mFile,"\tsetAttr \".ror\" %i;\n", ror);
	}
	void setRotationAngleUnits(unsigned int rau)
	{
		if(rau == 0) return;
		fprintf(mFile,"\tsetAttr \".rau\" %i;\n", rau);
	}
	void setCycle(unsigned int cyc)
	{
		if(cyc == 0) return;
		fprintf(mFile,"\tsetAttr \".cyc\" %i;\n", cyc);
	}
	void setCycleStep(double cs)
	{
		if(cs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cs\" %f;\n", cs);
	}
	void setCycleStepUnit(unsigned int csu)
	{
		if(csu == 0) return;
		fprintf(mFile,"\tsetAttr \".csu\" %i;\n", csu);
	}
	void setLevelOfDetail(unsigned int lod)
	{
		if(lod == 0) return;
		fprintf(mFile,"\tsetAttr \".lod\" %i;\n", lod);
	}
	void getInputPoints()const
	{
		fprintf(mFile,"\"%s.inp\"",mName.c_str());
	}
	void getInputHierarchy(size_t inh_i)const
	{
		fprintf(mFile,"\"%s.inh[%i]\"",mName.c_str(),inh_i);
	}
	void getInputHierarchy()const
	{

		fprintf(mFile,"\"%s.inh\"",mName.c_str());
	}
	void getRotationOrder()const
	{
		fprintf(mFile,"\"%s.ror\"",mName.c_str());
	}
	void getRotationAngleUnits()const
	{
		fprintf(mFile,"\"%s.rau\"",mName.c_str());
	}
	void getCycle()const
	{
		fprintf(mFile,"\"%s.cyc\"",mName.c_str());
	}
	void getCycleStep()const
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
	void getCycleStepUnit()const
	{
		fprintf(mFile,"\"%s.csu\"",mName.c_str());
	}
	void getLevelOfDetail()const
	{
		fprintf(mFile,"\"%s.lod\"",mName.c_str());
	}
	void getInstanceCount()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getHierarchyCount()const
	{
		fprintf(mFile,"\"%s.hc\"",mName.c_str());
	}
protected:
	Instancer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Transform(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_INSTANCER_H__
