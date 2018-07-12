/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSCURVE_H__
#define __MayaDM_NURBSCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveShape.h"
namespace MayaDM
{
class NurbsCurve : public CurveShape
{
public:
public:

	NurbsCurve():CurveShape(){}
	NurbsCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:CurveShape(file, name, parent, "nurbsCurve", shared, create){}
	virtual ~NurbsCurve(){}

	void setCached(const nurbsCurve& cc)
	{
		fprintf(mFile,"\tsetAttr \".cc\" -type \"nurbsCurve\" ");
		cc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInPlace(bool ipo)
	{
		if(ipo == false) return;
		fprintf(mFile,"\tsetAttr \".ipo\" %i;\n", ipo);
	}
	void setDispCV(bool dcv)
	{
		if(dcv == false) return;
		fprintf(mFile,"\tsetAttr \".dcv\" %i;\n", dcv);
	}
	void setDispEP(bool dep)
	{
		if(dep == false) return;
		fprintf(mFile,"\tsetAttr \".dep\" %i;\n", dep);
	}
	void setDispHull(bool dh)
	{
		if(dh == false) return;
		fprintf(mFile,"\tsetAttr \".dh\" %i;\n", dh);
	}
	void setDispGeometry(bool dg)
	{
		if(dg == true) return;
		fprintf(mFile,"\tsetAttr \".dg\" %i;\n", dg);
	}
	void getCreate()const
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getLocal()const
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getWorldSpace(size_t ws_i)const
	{
		fprintf(mFile,"\"%s.ws[%i]\"",mName.c_str(),ws_i);
	}
	void getWorldSpace()const
	{

		fprintf(mFile,"\"%s.ws\"",mName.c_str());
	}
	void getWorldNormal(size_t wn_i)const
	{
		fprintf(mFile,"\"%s.wn[%i]\"",mName.c_str(),wn_i);
	}
	void getWorldNormal()const
	{

		fprintf(mFile,"\"%s.wn\"",mName.c_str());
	}
	void getWorldNormalX(size_t wn_i)const
	{
		fprintf(mFile,"\"%s.wn[%i].wnx\"",mName.c_str(),wn_i);
	}
	void getWorldNormalX()const
	{

		fprintf(mFile,"\"%s.wn.wnx\"",mName.c_str());
	}
	void getWorldNormalY(size_t wn_i)const
	{
		fprintf(mFile,"\"%s.wn[%i].wny\"",mName.c_str(),wn_i);
	}
	void getWorldNormalY()const
	{

		fprintf(mFile,"\"%s.wn.wny\"",mName.c_str());
	}
	void getWorldNormalZ(size_t wn_i)const
	{
		fprintf(mFile,"\"%s.wn[%i].wnz\"",mName.c_str(),wn_i);
	}
	void getWorldNormalZ()const
	{

		fprintf(mFile,"\"%s.wn.wnz\"",mName.c_str());
	}
	void getForm()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSpans()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getEditPoints(size_t eps_i)const
	{
		fprintf(mFile,"\"%s.eps[%i]\"",mName.c_str(),eps_i);
	}
	void getEditPoints()const
	{

		fprintf(mFile,"\"%s.eps\"",mName.c_str());
	}
	void getXValueEp(size_t eps_i)const
	{
		fprintf(mFile,"\"%s.eps[%i].xve\"",mName.c_str(),eps_i);
	}
	void getXValueEp()const
	{

		fprintf(mFile,"\"%s.eps.xve\"",mName.c_str());
	}
	void getYValueEp(size_t eps_i)const
	{
		fprintf(mFile,"\"%s.eps[%i].yve\"",mName.c_str(),eps_i);
	}
	void getYValueEp()const
	{

		fprintf(mFile,"\"%s.eps.yve\"",mName.c_str());
	}
	void getZValueEp(size_t eps_i)const
	{
		fprintf(mFile,"\"%s.eps[%i].zve\"",mName.c_str(),eps_i);
	}
	void getZValueEp()const
	{

		fprintf(mFile,"\"%s.eps.zve\"",mName.c_str());
	}
	void getCached()const
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());
	}
	void getInPlace()const
	{
		fprintf(mFile,"\"%s.ipo\"",mName.c_str());
	}
	void getDispCV()const
	{
		fprintf(mFile,"\"%s.dcv\"",mName.c_str());
	}
	void getDispEP()const
	{
		fprintf(mFile,"\"%s.dep\"",mName.c_str());
	}
	void getDispHull()const
	{
		fprintf(mFile,"\"%s.dh\"",mName.c_str());
	}
	void getDispCurveEndPoints()const
	{
		fprintf(mFile,"\"%s.dce\"",mName.c_str());
	}
	void getDispGeometry()const
	{
		fprintf(mFile,"\"%s.dg\"",mName.c_str());
	}
	void getTweakSize()const
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());
	}
	void getMinMaxValue()const
	{
		fprintf(mFile,"\"%s.mmv\"",mName.c_str());
	}
	void getMinValue()const
	{
		fprintf(mFile,"\"%s.mmv.min\"",mName.c_str());
	}
	void getMaxValue()const
	{
		fprintf(mFile,"\"%s.mmv.max\"",mName.c_str());
	}
protected:
	NurbsCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:CurveShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NURBSCURVE_H__
