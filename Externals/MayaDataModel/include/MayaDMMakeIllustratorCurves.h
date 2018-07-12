/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKEILLUSTRATORCURVES_H__
#define __MayaDM_MAKEILLUSTRATORCURVES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class MakeIllustratorCurves : public AbstractBaseCreate
{
public:
public:

	MakeIllustratorCurves():AbstractBaseCreate(){}
	MakeIllustratorCurves(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "makeIllustratorCurves", shared, create){}
	virtual ~MakeIllustratorCurves(){}

	void setIllustratorFilename(const string& ifn)
	{
		if(ifn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ifn\" -type \"string\" ");
		ifn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setScaleFactor(float sf)
	{
		if(sf == 1.0f) return;
		fprintf(mFile,"\tsetAttr \".sf\" %f;\n", sf);
	}
	void setTolerance(float tl)
	{
		if(tl == 0.001f) return;
		fprintf(mFile,"\tsetAttr \".tl\" %f;\n", tl);
	}
	void getIllustratorFilename()const
	{
		fprintf(mFile,"\"%s.ifn\"",mName.c_str());
	}
	void getScaleFactor()const
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());
	}
	void getReload()const
	{
		fprintf(mFile,"\"%s.rl\"",mName.c_str());
	}
	void getOutputCurves(size_t oc_i)const
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);
	}
	void getOutputCurves()const
	{

		fprintf(mFile,"\"%s.oc\"",mName.c_str());
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
		fprintf(mFile,"\"%s.tl\"",mName.c_str());
	}
protected:
	MakeIllustratorCurves(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKEILLUSTRATORCURVES_H__
