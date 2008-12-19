/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	MakeCircularArc(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "makeCircularArc"){}
	virtual ~MakeCircularArc(){}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setSections(int s)
	{
		if(s == 8) return;
		fprintf(mFile,"setAttr \".s\" %i;\n", s);

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getSections()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getCenter()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getCenterX()
	{
		fprintf(mFile,"\"%s.c.cx\"",mName.c_str());

	}
	void getCenterY()
	{
		fprintf(mFile,"\"%s.c.cy\"",mName.c_str());

	}
	void getCenterZ()
	{
		fprintf(mFile,"\"%s.c.cz\"",mName.c_str());

	}
	void getNormal()
	{
		fprintf(mFile,"\"%s.nr\"",mName.c_str());

	}
	void getNormalX()
	{
		fprintf(mFile,"\"%s.nr.nrx\"",mName.c_str());

	}
	void getNormalY()
	{
		fprintf(mFile,"\"%s.nr.nry\"",mName.c_str());

	}
	void getNormalZ()
	{
		fprintf(mFile,"\"%s.nr.nrz\"",mName.c_str());

	}
	void getSweep()
	{
		fprintf(mFile,"\"%s.sw\"",mName.c_str());

	}
	void getOutputCurve()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
protected:
	MakeCircularArc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKECIRCULARARC_H__
