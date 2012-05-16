/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	SubdAutoProj():SubdModifierUV(){}
	SubdAutoProj(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SubdModifierUV(file, name, parent, "subdAutoProj", shared, create){}
	virtual ~SubdAutoProj(){}

	void setPlanes(int p)
	{
		if(p == 6) return;
		fprintf(mFile,"\tsetAttr \".p\" %i;\n", p);
	}
	void setOptimize(unsigned int o)
	{
		if(o == 1) return;
		fprintf(mFile,"\tsetAttr \".o\" %i;\n", o);
	}
	void setSkipIntersect(bool si)
	{
		if(si == false) return;
		fprintf(mFile,"\tsetAttr \".si\" %i;\n", si);
	}
	void setLayout(unsigned int l)
	{
		if(l == 1) return;
		fprintf(mFile,"\tsetAttr \".l\" %i;\n", l);
	}
	void setLayoutMethod(unsigned int lm)
	{
		if(lm == 0) return;
		fprintf(mFile,"\tsetAttr \".lm\" %i;\n", lm);
	}
	void setPercentageSpace(float ps)
	{
		if(ps == 0) return;
		fprintf(mFile,"\tsetAttr \".ps\" %f;\n", ps);
	}
	void setScale(unsigned int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"\tsetAttr \".sc\" %i;\n", sc);
	}
	void setDenseLayout(bool dl)
	{
		if(dl == false) return;
		fprintf(mFile,"\tsetAttr \".dl\" %i;\n", dl);
	}
	void getPlanes()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getOptimize()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getSkipIntersect()const
	{
		fprintf(mFile,"\"%s.si\"",mName.c_str());
	}
	void getLayout()const
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getLayoutMethod()const
	{
		fprintf(mFile,"\"%s.lm\"",mName.c_str());
	}
	void getPercentageSpace()const
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getDenseLayout()const
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
protected:
	SubdAutoProj(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SubdModifierUV(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDAUTOPROJ_H__
