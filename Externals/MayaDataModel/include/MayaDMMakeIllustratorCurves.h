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
	MakeIllustratorCurves(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "makeIllustratorCurves"){}
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
	void getIllustratorFilename()
	{
		fprintf(mFile,"\"%s.ifn\"",mName.c_str());

	}
	void getScaleFactor()
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());

	}
	void getReload()
	{
		fprintf(mFile,"\"%s.rl\"",mName.c_str());

	}
	void getOutputCurves(size_t oc_i)
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);

	}
	void getCount(size_t c_i)
	{
		fprintf(mFile,"\"%s.c[%i]\"",mName.c_str(),c_i);

	}
	void getPosition(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);

	}
	void getPositionX(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].px\"",mName.c_str(),p_i);

	}
	void getPositionY(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].py\"",mName.c_str(),p_i);

	}
	void getPositionZ(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i].pz\"",mName.c_str(),p_i);

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tl\"",mName.c_str());

	}
protected:
	MakeIllustratorCurves(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKEILLUSTRATORCURVES_H__
