/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBCUBE_H__
#define __MayaDM_MAKENURBCUBE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPrimitive.h"
namespace MayaDM
{
class MakeNurbCube : public Primitive
{
public:
public:

	MakeNurbCube():Primitive(){}
	MakeNurbCube(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Primitive(file, name, parent, "makeNurbCube", shared, create){}
	virtual ~MakeNurbCube(){}

	void setWidth(double w)
	{
		if(w == 1) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setLengthRatio(double lr)
	{
		if(lr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lr\" %f;\n", lr);
	}
	void setHeightRatio(double hr)
	{
		if(hr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hr\" %f;\n", hr);
	}
	void setPatchesU(int u)
	{
		if(u == 1) return;
		fprintf(mFile,"\tsetAttr \".u\" %i;\n", u);
	}
	void setPatchesV(int v)
	{
		if(v == 1) return;
		fprintf(mFile,"\tsetAttr \".v\" %i;\n", v);
	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void getWidth()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getLengthRatio()const
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());
	}
	void getHeightRatio()const
	{
		fprintf(mFile,"\"%s.hr\"",mName.c_str());
	}
	void getPatchesU()const
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());
	}
	void getPatchesV()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getOutputSurface1()const
	{
		fprintf(mFile,"\"%s.os1\"",mName.c_str());
	}
	void getOutputSurface2()const
	{
		fprintf(mFile,"\"%s.os2\"",mName.c_str());
	}
	void getOutputSurface3()const
	{
		fprintf(mFile,"\"%s.os3\"",mName.c_str());
	}
	void getOutputSurface4()const
	{
		fprintf(mFile,"\"%s.os4\"",mName.c_str());
	}
	void getOutputSurface5()const
	{
		fprintf(mFile,"\"%s.os5\"",mName.c_str());
	}
protected:
	MakeNurbCube(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Primitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBCUBE_H__
