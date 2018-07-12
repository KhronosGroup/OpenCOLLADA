/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FFBLENDSRF_H__
#define __MayaDM_FFBLENDSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class FfBlendSrf : public AbstractBaseCreate
{
public:
public:

	FfBlendSrf():AbstractBaseCreate(){}
	FfBlendSrf(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "ffBlendSrf", shared, create){}
	virtual ~FfBlendSrf(){}

	void setMultipleKnots(bool mk)
	{
		if(mk == true) return;
		fprintf(mFile,"\tsetAttr \".mk\" %i;\n", mk);
	}
	void setPositionTolerance(double pt)
	{
		if(pt == 0.1) return;
		fprintf(mFile,"\tsetAttr \".pt\" %f;\n", pt);
	}
	void setTangentTolerance(double tt)
	{
		if(tt == 0.1) return;
		fprintf(mFile,"\tsetAttr \".tt\" %f;\n", tt);
	}
	void setAutoNormal(bool an)
	{
		if(an == true) return;
		fprintf(mFile,"\tsetAttr \".an\" %i;\n", an);
	}
	void setFlipLeftNormal(bool fln)
	{
		if(fln == false) return;
		fprintf(mFile,"\tsetAttr \".fln\" %i;\n", fln);
	}
	void setFlipRightNormal(bool frn)
	{
		if(frn == false) return;
		fprintf(mFile,"\tsetAttr \".frn\" %i;\n", frn);
	}
	void setAutoAnchor(bool aa)
	{
		if(aa == true) return;
		fprintf(mFile,"\tsetAttr \".aa\" %i;\n", aa);
	}
	void setLeftAnchor(double la)
	{
		if(la == 0.0) return;
		fprintf(mFile,"\tsetAttr \".la\" %f;\n", la);
	}
	void setLeftStart(double ls)
	{
		if(ls == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ls\" %f;\n", ls);
	}
	void setLeftEnd(double le)
	{
		if(le == 1.0) return;
		fprintf(mFile,"\tsetAttr \".le\" %f;\n", le);
	}
	void setReverseLeft(bool rvl)
	{
		if(rvl == false) return;
		fprintf(mFile,"\tsetAttr \".rvl\" %i;\n", rvl);
	}
	void setRightAnchor(double ra)
	{
		if(ra == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
	}
	void setRightStart(double rs)
	{
		if(rs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rs\" %f;\n", rs);
	}
	void setRightEnd(double re)
	{
		if(re == 1.0) return;
		fprintf(mFile,"\tsetAttr \".re\" %f;\n", re);
	}
	void setReverseRight(bool rvr)
	{
		if(rvr == false) return;
		fprintf(mFile,"\tsetAttr \".rvr\" %i;\n", rvr);
	}
	void getLeftCurve(size_t lc_i)const
	{
		fprintf(mFile,"\"%s.lc[%i]\"",mName.c_str(),lc_i);
	}
	void getLeftCurve()const
	{

		fprintf(mFile,"\"%s.lc\"",mName.c_str());
	}
	void getRightCurve(size_t rc_i)const
	{
		fprintf(mFile,"\"%s.rc[%i]\"",mName.c_str(),rc_i);
	}
	void getRightCurve()const
	{

		fprintf(mFile,"\"%s.rc\"",mName.c_str());
	}
	void getLeftRail()const
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());
	}
	void getRightRail()const
	{
		fprintf(mFile,"\"%s.rr\"",mName.c_str());
	}
	void getMultipleKnots()const
	{
		fprintf(mFile,"\"%s.mk\"",mName.c_str());
	}
	void getPositionTolerance()const
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());
	}
	void getTangentTolerance()const
	{
		fprintf(mFile,"\"%s.tt\"",mName.c_str());
	}
	void getAutoNormal()const
	{
		fprintf(mFile,"\"%s.an\"",mName.c_str());
	}
	void getFlipLeftNormal()const
	{
		fprintf(mFile,"\"%s.fln\"",mName.c_str());
	}
	void getFlipRightNormal()const
	{
		fprintf(mFile,"\"%s.frn\"",mName.c_str());
	}
	void getAutoAnchor()const
	{
		fprintf(mFile,"\"%s.aa\"",mName.c_str());
	}
	void getLeftAnchor()const
	{
		fprintf(mFile,"\"%s.la\"",mName.c_str());
	}
	void getLeftStart()const
	{
		fprintf(mFile,"\"%s.ls\"",mName.c_str());
	}
	void getLeftEnd()const
	{
		fprintf(mFile,"\"%s.le\"",mName.c_str());
	}
	void getReverseLeft()const
	{
		fprintf(mFile,"\"%s.rvl\"",mName.c_str());
	}
	void getRightAnchor()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getRightStart()const
	{
		fprintf(mFile,"\"%s.rs\"",mName.c_str());
	}
	void getRightEnd()const
	{
		fprintf(mFile,"\"%s.re\"",mName.c_str());
	}
	void getReverseRight()const
	{
		fprintf(mFile,"\"%s.rvr\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
protected:
	FfBlendSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FFBLENDSRF_H__
