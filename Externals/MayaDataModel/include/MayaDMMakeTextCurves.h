/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKETEXTCURVES_H__
#define __MayaDM_MAKETEXTCURVES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class MakeTextCurves : public AbstractBaseCreate
{
public:
public:

	MakeTextCurves():AbstractBaseCreate(){}
	MakeTextCurves(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "makeTextCurves", shared, create){}
	virtual ~MakeTextCurves(){}

	void setText(const string& t)
	{
		if(t == "Maya") return;
		fprintf(mFile,"\tsetAttr \".t\" -type \"string\" ");
		t.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFont(const string& f)
	{
		if(f == "Times-Roman") return;
		fprintf(mFile,"\tsetAttr \".f\" -type \"string\" ");
		f.write(mFile);
		fprintf(mFile,";\n");
	}
	void getText()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getFont()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getOutputCurve(size_t oc_i)const
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);
	}
	void getOutputCurve()const
	{

		fprintf(mFile,"\"%s.oc\"",mName.c_str());
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
	void getCount(size_t c_i)const
	{
		fprintf(mFile,"\"%s.c[%i]\"",mName.c_str(),c_i);
	}
	void getCount()const
	{

		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
protected:
	MakeTextCurves(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKETEXTCURVES_H__
