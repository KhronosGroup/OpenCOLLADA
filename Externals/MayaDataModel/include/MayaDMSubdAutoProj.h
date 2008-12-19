/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDAUTOPROJ_H__
#define __MayaDM_SUBDAUTOPROJ_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifierUV.h"
namespace MayaDM
{
class SubdAutoProj : public SubdModifierUV
{
public:
public:
	SubdAutoProj(FILE* file,const std::string& name,const std::string& parent=""):SubdModifierUV(file, name, parent, "subdAutoProj"){}
	virtual ~SubdAutoProj(){}
	void setPlanes(int p)
	{
		if(p == 6) return;
		fprintf(mFile,"setAttr \".p\" %i;\n", p);

	}
	void setOptimize(unsigned int o)
	{
		if(o == 1) return;
		fprintf(mFile,"setAttr \".o\" %i;\n", o);

	}
	void setSkipIntersect(bool si)
	{
		if(si == false) return;
		fprintf(mFile,"setAttr \".si\" %i;\n", si);

	}
	void setLayout(unsigned int l)
	{
		if(l == 1) return;
		fprintf(mFile,"setAttr \".l\" %i;\n", l);

	}
	void setLayoutMethod(unsigned int lm)
	{
		if(lm == 0) return;
		fprintf(mFile,"setAttr \".lm\" %i;\n", lm);

	}
	void setPercentageSpace(float ps)
	{
		if(ps == 0) return;
		fprintf(mFile,"setAttr \".ps\" %f;\n", ps);

	}
	void setScale(unsigned int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"setAttr \".sc\" %i;\n", sc);

	}
	void setDenseLayout(bool dl)
	{
		if(dl == false) return;
		fprintf(mFile,"setAttr \".dl\" %i;\n", dl);

	}
	void getPlanes()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getOptimize()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getSkipIntersect()
	{
		fprintf(mFile,"\"%s.si\"",mName.c_str());

	}
	void getLayout()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getLayoutMethod()
	{
		fprintf(mFile,"\"%s.lm\"",mName.c_str());

	}
	void getPercentageSpace()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getDenseLayout()
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());

	}
protected:
	SubdAutoProj(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdModifierUV(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDAUTOPROJ_H__
