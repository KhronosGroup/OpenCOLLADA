/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	MakeNurbCube(FILE* file,const std::string& name,const std::string& parent=""):Primitive(file, name, parent, "makeNurbCube"){}
	virtual ~MakeNurbCube(){}
	void setWidth(double w)
	{
		if(w == 1) return;
		fprintf(mFile,"setAttr \".w\" %f;\n", w);

	}
	void setLengthRatio(double lr)
	{
		if(lr == 1.0) return;
		fprintf(mFile,"setAttr \".lr\" %f;\n", lr);

	}
	void setHeightRatio(double hr)
	{
		if(hr == 1.0) return;
		fprintf(mFile,"setAttr \".hr\" %f;\n", hr);

	}
	void setPatchesU(int u)
	{
		if(u == 1) return;
		fprintf(mFile,"setAttr \".u\" %i;\n", u);

	}
	void setPatchesV(int v)
	{
		if(v == 1) return;
		fprintf(mFile,"setAttr \".v\" %i;\n", v);

	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void getWidth()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getLengthRatio()
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());

	}
	void getHeightRatio()
	{
		fprintf(mFile,"\"%s.hr\"",mName.c_str());

	}
	void getPatchesU()
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());

	}
	void getPatchesV()
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getOutputSurface1()
	{
		fprintf(mFile,"\"%s.os1\"",mName.c_str());

	}
	void getOutputSurface2()
	{
		fprintf(mFile,"\"%s.os2\"",mName.c_str());

	}
	void getOutputSurface3()
	{
		fprintf(mFile,"\"%s.os3\"",mName.c_str());

	}
	void getOutputSurface4()
	{
		fprintf(mFile,"\"%s.os4\"",mName.c_str());

	}
	void getOutputSurface5()
	{
		fprintf(mFile,"\"%s.os5\"",mName.c_str());

	}
protected:
	MakeNurbCube(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Primitive(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBCUBE_H__
