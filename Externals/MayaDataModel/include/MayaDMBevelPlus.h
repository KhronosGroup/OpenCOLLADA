/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	BevelPlus():AbstractBaseCreate(){}
	BevelPlus(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "bevelPlus", shared, create){}
	virtual ~BevelPlus(){}

	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void setWidth(double w)
	{
		if(w == 0) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setDepth(double d)
	{
		if(d == 0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setExtrudeDepth(double ed)
	{
		if(ed == 0) return;
		fprintf(mFile,"\tsetAttr \".ed\" %f;\n", ed);
	}
	void setNumberOfSides(int ns)
	{
		if(ns == 4) return;
		fprintf(mFile,"\tsetAttr \".ns\" %i;\n", ns);
	}
	void setCapSides(int cap)
	{
		if(cap == 1) return;
		fprintf(mFile,"\tsetAttr \".cap\" %i;\n", cap);
	}
	void setJoinSurfaces(bool js)
	{
		if(js == true) return;
		fprintf(mFile,"\tsetAttr \".js\" %i;\n", js);
	}
	void setOrderedCurves(bool oc)
	{
		if(oc == false) return;
		fprintf(mFile,"\tsetAttr \".oc\" %i;\n", oc);
	}
	void setNormalsOutwards(bool no)
	{
		if(no == false) return;
		fprintf(mFile,"\tsetAttr \".no\" %i;\n", no);
	}
	void setPolyOutMethod(unsigned int pom)
	{
		if(pom == 0) return;
		fprintf(mFile,"\tsetAttr \".pom\" %i;\n", pom);
	}
	void setPolyOutCount(int poc)
	{
		if(poc == 200) return;
		fprintf(mFile,"\tsetAttr \".poc\" %i;\n", poc);
	}
	void setPolyOutExtrusionType(unsigned int pet)
	{
		if(pet == 1) return;
		fprintf(mFile,"\tsetAttr \".pet\" %i;\n", pet);
	}
	void setPolyOutExtrusionSamples(int pes)
	{
		if(pes == 2) return;
		fprintf(mFile,"\tsetAttr \".pes\" %i;\n", pes);
	}
	void setPolyOutCurveType(unsigned int pct)
	{
		if(pct == 1) return;
		fprintf(mFile,"\tsetAttr \".pct\" %i;\n", pct);
	}
	void setPolyOutCurveSamples(int pcs)
	{
		if(pcs == 6) return;
		fprintf(mFile,"\tsetAttr \".pcs\" %i;\n", pcs);
	}
	void setPolyOutUseChordHeight(bool uch)
	{
		if(uch == false) return;
		fprintf(mFile,"\tsetAttr \".uch\" %i;\n", uch);
	}
	void setPolyOutChordHeight(double cht)
	{
		if(cht == 0) return;
		fprintf(mFile,"\tsetAttr \".cht\" %f;\n", cht);
	}
	void setPolyOutUseChordHeightRatio(bool ucr)
	{
		if(ucr == true) return;
		fprintf(mFile,"\tsetAttr \".ucr\" %i;\n", ucr);
	}
	void setPolyOutChordHeightRatio(double chr)
	{
		if(chr == 0.1) return;
		fprintf(mFile,"\tsetAttr \".chr\" %f;\n", chr);
	}
	void getInputCurves(size_t ics_i)const
	{
		fprintf(mFile,"\"%s.ics[%i]\"",mName.c_str(),ics_i);
	}
	void getInputCurves()const
	{

		fprintf(mFile,"\"%s.ics\"",mName.c_str());
	}
	void getOuterStyleCurve()const
	{
		fprintf(mFile,"\"%s.osc\"",mName.c_str());
	}
	void getInnerStyleCurve()const
	{
		fprintf(mFile,"\"%s.isc\"",mName.c_str());
	}
	void getOutputPoly()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getStartCapSurface()const
	{
		fprintf(mFile,"\"%s.scs\"",mName.c_str());
	}
	void getEndCapSurface()const
	{
		fprintf(mFile,"\"%s.ecs\"",mName.c_str());
	}
	void getOutputSurfaces(size_t os1_i)const
	{
		fprintf(mFile,"\"%s.os1[%i]\"",mName.c_str(),os1_i);
	}
	void getOutputSurfaces()const
	{

		fprintf(mFile,"\"%s.os1\"",mName.c_str());
	}
	void getCount(size_t c_i)const
	{
		fprintf(mFile,"\"%s.c[%i]\"",mName.c_str(),c_i);
	}
	void getCount()const
	{

		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getPosition(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);
	}
	void getPosition()const
	{

		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPositionX(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i].px\"",mName.c_str(),p_i);
	}
	void getPositionX()const
	{

		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPositionY(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i].py\"",mName.c_str(),p_i);
	}
	void getPositionY()const
	{

		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPositionZ(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i].pz\"",mName.c_str(),p_i);
	}
	void getPositionZ()const
	{

		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getWidth()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getDepth()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getExtrudeDepth()const
	{
		fprintf(mFile,"\"%s.ed\"",mName.c_str());
	}
	void getNumberOfSides()const
	{
		fprintf(mFile,"\"%s.ns\"",mName.c_str());
	}
	void getCapSides()const
	{
		fprintf(mFile,"\"%s.cap\"",mName.c_str());
	}
	void getJoinSurfaces()const
	{
		fprintf(mFile,"\"%s.js\"",mName.c_str());
	}
	void getOrderedCurves()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getNormalsOutwards()const
	{
		fprintf(mFile,"\"%s.no\"",mName.c_str());
	}
	void getPolyOutMethod()const
	{
		fprintf(mFile,"\"%s.pom\"",mName.c_str());
	}
	void getPolyOutCount()const
	{
		fprintf(mFile,"\"%s.poc\"",mName.c_str());
	}
	void getPolyOutExtrusionType()const
	{
		fprintf(mFile,"\"%s.pet\"",mName.c_str());
	}
	void getPolyOutExtrusionSamples()const
	{
		fprintf(mFile,"\"%s.pes\"",mName.c_str());
	}
	void getPolyOutCurveType()const
	{
		fprintf(mFile,"\"%s.pct\"",mName.c_str());
	}
	void getPolyOutCurveSamples()const
	{
		fprintf(mFile,"\"%s.pcs\"",mName.c_str());
	}
	void getPolyOutUseChordHeight()const
	{
		fprintf(mFile,"\"%s.uch\"",mName.c_str());
	}
	void getPolyOutChordHeight()const
	{
		fprintf(mFile,"\"%s.cht\"",mName.c_str());
	}
	void getPolyOutUseChordHeightRatio()const
	{
		fprintf(mFile,"\"%s.ucr\"",mName.c_str());
	}
	void getPolyOutChordHeightRatio()const
	{
		fprintf(mFile,"\"%s.chr\"",mName.c_str());
	}
protected:
	BevelPlus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BEVELPLUS_H__
