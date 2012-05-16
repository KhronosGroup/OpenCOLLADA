/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PRIMITIVE_H__
#define __MayaDM_PRIMITIVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class Primitive : public AbstractBaseCreate
{
public:
public:

	Primitive():AbstractBaseCreate(){}
	Primitive(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "primitive", shared, create){}
	virtual ~Primitive(){}

	void setPivot(const double3& p)
	{
		fprintf(mFile,"\tsetAttr \".p\" -type \"double3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPivotX(double px)
	{
		if(px == 0) return;
		fprintf(mFile,"\tsetAttr \".p.px\" %f;\n", px);
	}
	void setPivotY(double py)
	{
		if(py == 0) return;
		fprintf(mFile,"\tsetAttr \".p.py\" %f;\n", py);
	}
	void setPivotZ(double pz)
	{
		if(pz == 0) return;
		fprintf(mFile,"\tsetAttr \".p.pz\" %f;\n", pz);
	}
	void setAxis(const double3& ax)
	{
		fprintf(mFile,"\tsetAttr \".ax\" -type \"double3\" ");
		ax.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAxisX(double axx)
	{
		if(axx == 1) return;
		fprintf(mFile,"\tsetAttr \".ax.axx\" %f;\n", axx);
	}
	void setAxisY(double axy)
	{
		if(axy == 0) return;
		fprintf(mFile,"\tsetAttr \".ax.axy\" %f;\n", axy);
	}
	void setAxisZ(double axz)
	{
		if(axz == 0) return;
		fprintf(mFile,"\tsetAttr \".ax.axz\" %f;\n", axz);
	}
	void getPivot()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPivotX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPivotY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPivotZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getAxis()const
	{
		fprintf(mFile,"\"%s.ax\"",mName.c_str());
	}
	void getAxisX()const
	{
		fprintf(mFile,"\"%s.ax.axx\"",mName.c_str());
	}
	void getAxisY()const
	{
		fprintf(mFile,"\"%s.ax.axy\"",mName.c_str());
	}
	void getAxisZ()const
	{
		fprintf(mFile,"\"%s.ax.axz\"",mName.c_str());
	}
	void getOutputSurface()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
protected:
	Primitive(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PRIMITIVE_H__
