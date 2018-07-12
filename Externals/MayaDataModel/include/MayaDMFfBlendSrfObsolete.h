/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FFBLENDSRFOBSOLETE_H__
#define __MayaDM_FFBLENDSRFOBSOLETE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class FfBlendSrfObsolete : public AbstractBaseCreate
{
public:
public:

	FfBlendSrfObsolete():AbstractBaseCreate(){}
	FfBlendSrfObsolete(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "ffBlendSrfObsolete", shared, create){}
	virtual ~FfBlendSrfObsolete(){}

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
	void setFlipLeft(bool fl)
	{
		if(fl == false) return;
		fprintf(mFile,"\tsetAttr \".fl\" %i;\n", fl);
	}
	void setFlipRight(bool fr)
	{
		if(fr == false) return;
		fprintf(mFile,"\tsetAttr \".fr\" %i;\n", fr);
	}
	void setAutoDirection(bool ad)
	{
		if(ad == true) return;
		fprintf(mFile,"\tsetAttr \".ad\" %i;\n", ad);
	}
	void setLeftParameter(double lp)
	{
		if(lp == 123456.0) return;
		fprintf(mFile,"\tsetAttr \".lp\" %f;\n", lp);
	}
	void setRightParameter(double rp)
	{
		if(rp == 123456.0) return;
		fprintf(mFile,"\tsetAttr \".rp\" %f;\n", rp);
	}
	void setMultipleKnots(bool mk)
	{
		if(mk == true) return;
		fprintf(mFile,"\tsetAttr \".mk\" %i;\n", mk);
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
	void getPositionTolerance()const
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());
	}
	void getTangentTolerance()const
	{
		fprintf(mFile,"\"%s.tt\"",mName.c_str());
	}
	void getFlipLeft()const
	{
		fprintf(mFile,"\"%s.fl\"",mName.c_str());
	}
	void getFlipRight()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
	void getAutoDirection()const
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());
	}
	void getLeftRail()const
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());
	}
	void getRightRail()const
	{
		fprintf(mFile,"\"%s.rr\"",mName.c_str());
	}
	void getLeftParameter()const
	{
		fprintf(mFile,"\"%s.lp\"",mName.c_str());
	}
	void getRightParameter()const
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getMultipleKnots()const
	{
		fprintf(mFile,"\"%s.mk\"",mName.c_str());
	}
protected:
	FfBlendSrfObsolete(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FFBLENDSRFOBSOLETE_H__
