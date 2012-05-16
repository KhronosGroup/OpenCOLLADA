/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKECIRCULARARC_H__
#define __MayaDM_MAKECIRCULARARC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class MakeCircularArc : public AbstractBaseCreate
{
public:
public:

	MakeCircularArc():AbstractBaseCreate(){}
	MakeCircularArc(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "makeCircularArc", shared, create){}
	virtual ~MakeCircularArc(){}

	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setSections(int s)
	{
		if(s == 8) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSections()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getCenter()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getCenterX()const
	{
		fprintf(mFile,"\"%s.c.cx\"",mName.c_str());
	}
	void getCenterY()const
	{
		fprintf(mFile,"\"%s.c.cy\"",mName.c_str());
	}
	void getCenterZ()const
	{
		fprintf(mFile,"\"%s.c.cz\"",mName.c_str());
	}
	void getNormal()const
	{
		fprintf(mFile,"\"%s.nr\"",mName.c_str());
	}
	void getNormalX()const
	{
		fprintf(mFile,"\"%s.nr.nrx\"",mName.c_str());
	}
	void getNormalY()const
	{
		fprintf(mFile,"\"%s.nr.nry\"",mName.c_str());
	}
	void getNormalZ()const
	{
		fprintf(mFile,"\"%s.nr.nrz\"",mName.c_str());
	}
	void getSweep()const
	{
		fprintf(mFile,"\"%s.sw\"",mName.c_str());
	}
	void getOutputCurve()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
protected:
	MakeCircularArc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKECIRCULARARC_H__
