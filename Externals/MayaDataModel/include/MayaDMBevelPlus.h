/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BEVELPLUS_H__
#define __MayaDM_BEVELPLUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class BevelPlus : public AbstractBaseCreate
{
public:
public:
	BevelPlus(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "bevelPlus"){}
	virtual ~BevelPlus(){}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void setWidth(double w)
	{
		if(w == 0) return;
		fprintf(mFile,"setAttr \".w\" %f;\n", w);

	}
	void setDepth(double d)
	{
		if(d == 0) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setExtrudeDepth(double ed)
	{
		if(ed == 0) return;
		fprintf(mFile,"setAttr \".ed\" %f;\n", ed);

	}
	void setNumberOfSides(int ns)
	{
		if(ns == 4) return;
		fprintf(mFile,"setAttr \".ns\" %i;\n", ns);

	}
	void setCapSides(int cap)
	{
		if(cap == 1) return;
		fprintf(mFile,"setAttr \".cap\" %i;\n", cap);

	}
	void setJoinSurfaces(bool js)
	{
		if(js == true) return;
		fprintf(mFile,"setAttr \".js\" %i;\n", js);

	}
	void setOrderedCurves(bool oc)
	{
		if(oc == false) return;
		fprintf(mFile,"setAttr \".oc\" %i;\n", oc);

	}
	void setNormalsOutwards(bool no)
	{
		if(no == false) return;
		fprintf(mFile,"setAttr \".no\" %i;\n", no);

	}
	void setPolyOutMethod(unsigned int pom)
	{
		if(pom == 0) return;
		fprintf(mFile,"setAttr \".pom\" %i;\n", pom);

	}
	void setPolyOutCount(int poc)
	{
		if(poc == 200) return;
		fprintf(mFile,"setAttr \".poc\" %i;\n", poc);

	}
	void setPolyOutExtrusionType(unsigned int pet)
	{
		if(pet == 1) return;
		fprintf(mFile,"setAttr \".pet\" %i;\n", pet);

	}
	void setPolyOutExtrusionSamples(int pes)
	{
		if(pes == 2) return;
		fprintf(mFile,"setAttr \".pes\" %i;\n", pes);

	}
	void setPolyOutCurveType(unsigned int pct)
	{
		if(pct == 1) return;
		fprintf(mFile,"setAttr \".pct\" %i;\n", pct);

	}
	void setPolyOutCurveSamples(int pcs)
	{
		if(pcs == 6) return;
		fprintf(mFile,"setAttr \".pcs\" %i;\n", pcs);

	}
	void setPolyOutUseChordHeight(bool uch)
	{
		if(uch == false) return;
		fprintf(mFile,"setAttr \".uch\" %i;\n", uch);

	}
	void setPolyOutChordHeight(double cht)
	{
		if(cht == 0) return;
		fprintf(mFile,"setAttr \".cht\" %f;\n", cht);

	}
	void setPolyOutUseChordHeightRatio(bool ucr)
	{
		if(ucr == true) return;
		fprintf(mFile,"setAttr \".ucr\" %i;\n", ucr);

	}
	void setPolyOutChordHeightRatio(double chr)
	{
		if(chr == 0.1) return;
		fprintf(mFile,"setAttr \".chr\" %f;\n", chr);

	}
	void getInputCurves(size_t ics_i)
	{
		fprintf(mFile,"\"%s.ics[%i]\"",mName.c_str(),ics_i);

	}
	void getOuterStyleCurve()
	{
		fprintf(mFile,"\"%s.osc\"",mName.c_str());

	}
	void getInnerStyleCurve()
	{
		fprintf(mFile,"\"%s.isc\"",mName.c_str());

	}
	void getOutputPoly()
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());

	}
	void getStartCapSurface()
	{
		fprintf(mFile,"\"%s.scs\"",mName.c_str());

	}
	void getEndCapSurface()
	{
		fprintf(mFile,"\"%s.ecs\"",mName.c_str());

	}
	void getOutputSurfaces(size_t os1_i)
	{
		fprintf(mFile,"\"%s.os1[%i]\"",mName.c_str(),os1_i);

	}
	void getCount(size_t c_i)
	{
		fprintf(mFile,"\"%s.c[%i]\"",mName.c_str(),c_i);

	}
	void getPosition(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);

	}
	void getPositionX(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].px\"",mName.c_str(),p_i);

	}
	void getPositionY(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].py\"",mName.c_str(),p_i);

	}
	void getPositionZ(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].pz\"",mName.c_str(),p_i);

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getWidth()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getDepth()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getExtrudeDepth()
	{
		fprintf(mFile,"\"%s.ed\"",mName.c_str());

	}
	void getNumberOfSides()
	{
		fprintf(mFile,"\"%s.ns\"",mName.c_str());

	}
	void getCapSides()
	{
		fprintf(mFile,"\"%s.cap\"",mName.c_str());

	}
	void getJoinSurfaces()
	{
		fprintf(mFile,"\"%s.js\"",mName.c_str());

	}
	void getOrderedCurves()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getNormalsOutwards()
	{
		fprintf(mFile,"\"%s.no\"",mName.c_str());

	}
	void getPolyOutMethod()
	{
		fprintf(mFile,"\"%s.pom\"",mName.c_str());

	}
	void getPolyOutCount()
	{
		fprintf(mFile,"\"%s.poc\"",mName.c_str());

	}
	void getPolyOutExtrusionType()
	{
		fprintf(mFile,"\"%s.pet\"",mName.c_str());

	}
	void getPolyOutExtrusionSamples()
	{
		fprintf(mFile,"\"%s.pes\"",mName.c_str());

	}
	void getPolyOutCurveType()
	{
		fprintf(mFile,"\"%s.pct\"",mName.c_str());

	}
	void getPolyOutCurveSamples()
	{
		fprintf(mFile,"\"%s.pcs\"",mName.c_str());

	}
	void getPolyOutUseChordHeight()
	{
		fprintf(mFile,"\"%s.uch\"",mName.c_str());

	}
	void getPolyOutChordHeight()
	{
		fprintf(mFile,"\"%s.cht\"",mName.c_str());

	}
	void getPolyOutUseChordHeightRatio()
	{
		fprintf(mFile,"\"%s.ucr\"",mName.c_str());

	}
	void getPolyOutChordHeightRatio()
	{
		fprintf(mFile,"\"%s.chr\"",mName.c_str());

	}
protected:
	BevelPlus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BEVELPLUS_H__
