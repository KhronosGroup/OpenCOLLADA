/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IMPLICITBOX_H__
#define __MayaDM_IMPLICITBOX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
class ImplicitBox : public GeometryShape
{
public:
public:

	ImplicitBox():GeometryShape(){}
	ImplicitBox(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, "implicitBox", shared, create){}
	virtual ~ImplicitBox(){}

	void setSize(const double3& siz)
	{
		fprintf(mFile,"\tsetAttr \".siz\" -type \"double3\" ");
		siz.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSizeX(double szx)
	{
		if(szx == 2.0) return;
		fprintf(mFile,"\tsetAttr \".siz.szx\" %f;\n", szx);
	}
	void setSizeY(double szy)
	{
		if(szy == 2.0) return;
		fprintf(mFile,"\tsetAttr \".siz.szy\" %f;\n", szy);
	}
	void setSizeZ(double szz)
	{
		if(szz == 2.0) return;
		fprintf(mFile,"\tsetAttr \".siz.szz\" %f;\n", szz);
	}
	void getBox()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getSize()const
	{
		fprintf(mFile,"\"%s.siz\"",mName.c_str());
	}
	void getSizeX()const
	{
		fprintf(mFile,"\"%s.siz.szx\"",mName.c_str());
	}
	void getSizeY()const
	{
		fprintf(mFile,"\"%s.siz.szy\"",mName.c_str());
	}
	void getSizeZ()const
	{
		fprintf(mFile,"\"%s.siz.szz\"",mName.c_str());
	}
protected:
	ImplicitBox(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IMPLICITBOX_H__
