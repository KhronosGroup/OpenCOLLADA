/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXTENDSURFACE_H__
#define __MayaDM_EXTENDSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class ExtendSurface : public AbstractBaseCreate
{
public:
public:

	ExtendSurface():AbstractBaseCreate(){}
	ExtendSurface(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "extendSurface", shared, create){}
	virtual ~ExtendSurface(){}

	void setExtensionType(unsigned int et)
	{
		if(et == 0) return;
		fprintf(mFile,"\tsetAttr \".et\" %i;\n", et);
	}
	void setExtendMethod(unsigned int em)
	{
		if(em == 0) return;
		fprintf(mFile,"\tsetAttr \".em\" %i;\n", em);
	}
	void setExtendSide(unsigned int es)
	{
		if(es == 1) return;
		fprintf(mFile,"\tsetAttr \".es\" %i;\n", es);
	}
	void setExtendDirection(unsigned int ed)
	{
		if(ed == 0) return;
		fprintf(mFile,"\tsetAttr \".ed\" %i;\n", ed);
	}
	void setJoin(bool jn)
	{
		if(jn == true) return;
		fprintf(mFile,"\tsetAttr \".jn\" %i;\n", jn);
	}
	void setDistance(double d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getTargetObject()const
	{
		fprintf(mFile,"\"%s.to\"",mName.c_str());
	}
	void getExtensionType()const
	{
		fprintf(mFile,"\"%s.et\"",mName.c_str());
	}
	void getExtendMethod()const
	{
		fprintf(mFile,"\"%s.em\"",mName.c_str());
	}
	void getExtendSide()const
	{
		fprintf(mFile,"\"%s.es\"",mName.c_str());
	}
	void getExtendDirection()const
	{
		fprintf(mFile,"\"%s.ed\"",mName.c_str());
	}
	void getJoin()const
	{
		fprintf(mFile,"\"%s.jn\"",mName.c_str());
	}
	void getDistance()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
protected:
	ExtendSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_EXTENDSURFACE_H__
