/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Instancer(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "instancer"){}
	virtual ~Instancer(){}
	void setRotationOrder(unsigned int ror)
	{
		if(ror == 0) return;
		fprintf(mFile,"setAttr \".ror\" %i;\n", ror);

	}
	void setRotationAngleUnits(unsigned int rau)
	{
		if(rau == 0) return;
		fprintf(mFile,"setAttr \".rau\" %i;\n", rau);

	}
	void setCycle(unsigned int cyc)
	{
		if(cyc == 0) return;
		fprintf(mFile,"setAttr \".cyc\" %i;\n", cyc);

	}
	void setCycleStep(double cs)
	{
		if(cs == 1.0) return;
		fprintf(mFile,"setAttr \".cs\" %f;\n", cs);

	}
	void setCycleStepUnit(unsigned int csu)
	{
		if(csu == 0) return;
		fprintf(mFile,"setAttr \".csu\" %i;\n", csu);

	}
	void setLevelOfDetail(unsigned int lod)
	{
		if(lod == 0) return;
		fprintf(mFile,"setAttr \".lod\" %i;\n", lod);

	}
	void getInputPoints()
	{
		fprintf(mFile,"\"%s.inp\"",mName.c_str());

	}
	void getRotationOrder()
	{
		fprintf(mFile,"\"%s.ror\"",mName.c_str());

	}
	void getRotationAngleUnits()
	{
		fprintf(mFile,"\"%s.rau\"",mName.c_str());

	}
	void getCycle()
	{
		fprintf(mFile,"\"%s.cyc\"",mName.c_str());

	}
	void getCycleStep()
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());

	}
	void getCycleStepUnit()
	{
		fprintf(mFile,"\"%s.csu\"",mName.c_str());

	}
	void getLevelOfDetail()
	{
		fprintf(mFile,"\"%s.lod\"",mName.c_str());

	}
	void getInstanceCount()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getHierarchyCount()
	{
		fprintf(mFile,"\"%s.hc\"",mName.c_str());

	}
protected:
	Instancer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_INSTANCER_H__
