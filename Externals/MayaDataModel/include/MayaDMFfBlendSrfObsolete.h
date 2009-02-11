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
	FfBlendSrfObsolete(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "ffBlendSrfObsolete"){}
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
	void getLeftCurve(size_t lc_i)
	{
		fprintf(mFile,"\"%s.lc[%i]\"",mName.c_str(),lc_i);

	}
	void getRightCurve(size_t rc_i)
	{
		fprintf(mFile,"\"%s.rc[%i]\"",mName.c_str(),rc_i);

	}
	void getPositionTolerance()
	{
		fprintf(mFile,"\"%s.pt\"",mName.c_str());

	}
	void getTangentTolerance()
	{
		fprintf(mFile,"\"%s.tt\"",mName.c_str());

	}
	void getFlipLeft()
	{
		fprintf(mFile,"\"%s.fl\"",mName.c_str());

	}
	void getFlipRight()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getAutoDirection()
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());

	}
	void getLeftRail()
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());

	}
	void getRightRail()
	{
		fprintf(mFile,"\"%s.rr\"",mName.c_str());

	}
	void getLeftParameter()
	{
		fprintf(mFile,"\"%s.lp\"",mName.c_str());

	}
	void getRightParameter()
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getMultipleKnots()
	{
		fprintf(mFile,"\"%s.mk\"",mName.c_str());

	}
protected:
	FfBlendSrfObsolete(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FFBLENDSRFOBSOLETE_H__
