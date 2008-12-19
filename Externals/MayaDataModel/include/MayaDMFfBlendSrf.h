/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	FfBlendSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "ffBlendSrf"){}
	virtual ~FfBlendSrf(){}
	void setMultipleKnots(bool mk)
	{
		if(mk == true) return;
		fprintf(mFile,"setAttr \".mk\" %i;\n", mk);

	}
	void setPositionTolerance(double pt)
	{
		if(pt == 0.1) return;
		fprintf(mFile,"setAttr \".pt\" %f;\n", pt);

	}
	void setTangentTolerance(double tt)
	{
		if(tt == 0.1) return;
		fprintf(mFile,"setAttr \".tt\" %f;\n", tt);

	}
	void setAutoNormal(bool an)
	{
		if(an == true) return;
		fprintf(mFile,"setAttr \".an\" %i;\n", an);

	}
	void setFlipLeftNormal(bool fln)
	{
		if(fln == false) return;
		fprintf(mFile,"setAttr \".fln\" %i;\n", fln);

	}
	void setFlipRightNormal(bool frn)
	{
		if(frn == false) return;
		fprintf(mFile,"setAttr \".frn\" %i;\n", frn);

	}
	void setAutoAnchor(bool aa)
	{
		if(aa == true) return;
		fprintf(mFile,"setAttr \".aa\" %i;\n", aa);

	}
	void setLeftAnchor(double la)
	{
		if(la == 0.0) return;
		fprintf(mFile,"setAttr \".la\" %f;\n", la);

	}
	void setLeftStart(double ls)
	{
		if(ls == 0.0) return;
		fprintf(mFile,"setAttr \".ls\" %f;\n", ls);

	}
	void setLeftEnd(double le)
	{
		if(le == 1.0) return;
		fprintf(mFile,"setAttr \".le\" %f;\n", le);

	}
	void setReverseLeft(bool rvl)
	{
		if(rvl == false) return;
		fprintf(mFile,"setAttr \".rvl\" %i;\n", rvl);

	}
	void setRightAnchor(double ra)
	{
		if(ra == 0.0) return;
		fprintf(mFile,"setAttr \".ra\" %f;\n", ra);

	}
	void setRightStart(double rs)
	{
		if(rs == 0.0) return;
		fprintf(mFile,"setAttr \".rs\" %f;\n", rs);

	}
	void setRightEnd(double re)
	{
		if(re == 1.0) return;
		fprintf(mFile,"setAttr \".re\" %f;\n", re);

	}
	void setReverseRight(bool rvr)
	{
		if(rvr == false) return;
		fprintf(mFile,"setAttr \".rvr\" %i;\n", rvr);

	}
	void getLeftCurve(size_t lc_i)
	{
		fprintf(mFile,"\"%s.lc[%i]\"",mName.c_str(),lc_i);

	}
	void getRightCurve(size_t rc_i)
	{
		fprintf(mFile,"\"%s.rc[%i]\"",mName.c_str(),rc_i);

	}
	void getLeftRail()
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());

	}
	void getRightRail()
	{
		fprintf(mFile,"\"%s.rr\"",mName.c_str());

	}
	void getMultipleKnots()
	{
		fprintf(mFile,"\"%s.mk\"",mName.c_str());

	}
	void getPositionTolerance()
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());

	}
	void getTangentTolerance()
	{
		fprintf(mFile,"\"%s.tt\"",mName.c_str());

	}
	void getAutoNormal()
	{
		fprintf(mFile,"\"%s.an\"",mName.c_str());

	}
	void getFlipLeftNormal()
	{
		fprintf(mFile,"\"%s.fln\"",mName.c_str());

	}
	void getFlipRightNormal()
	{
		fprintf(mFile,"\"%s.frn\"",mName.c_str());

	}
	void getAutoAnchor()
	{
		fprintf(mFile,"\"%s.aa\"",mName.c_str());

	}
	void getLeftAnchor()
	{
		fprintf(mFile,"\"%s.la\"",mName.c_str());

	}
	void getLeftStart()
	{
		fprintf(mFile,"\"%s.ls\"",mName.c_str());

	}
	void getLeftEnd()
	{
		fprintf(mFile,"\"%s.le\"",mName.c_str());

	}
	void getReverseLeft()
	{
		fprintf(mFile,"\"%s.rvl\"",mName.c_str());

	}
	void getRightAnchor()
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());

	}
	void getRightStart()
	{
		fprintf(mFile,"\"%s.rs\"",mName.c_str());

	}
	void getRightEnd()
	{
		fprintf(mFile,"\"%s.re\"",mName.c_str());

	}
	void getReverseRight()
	{
		fprintf(mFile,"\"%s.rvr\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	FfBlendSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FFBLENDSRF_H__
