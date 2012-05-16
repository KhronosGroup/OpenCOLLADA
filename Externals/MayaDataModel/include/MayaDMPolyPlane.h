/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPLANE_H__
#define __MayaDM_POLYPLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
class PolyPlane : public PolyPrimitive
{
public:
public:

	PolyPlane():PolyPrimitive(){}
	PolyPlane(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, "polyPlane", shared, create){}
	virtual ~PolyPlane(){}

	void setWidth(double w)
	{
		if(w == 1) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setHeight(double h)
	{
		if(h == 1) return;
		fprintf(mFile,"\tsetAttr \".h\" %f;\n", h);
	}
	void setSubdivisionsWidth(int sw)
	{
		if(sw == 10) return;
		fprintf(mFile,"\tsetAttr \".sw\" %i;\n", sw);
	}
	void setSubdivisionsHeight(int sh)
	{
		if(sh == 10) return;
		fprintf(mFile,"\tsetAttr \".sh\" %i;\n", sh);
	}
	void setTexture(unsigned int tx)
	{
		if(tx == 1) return;
		fprintf(mFile,"\tsetAttr \".tx\" %i;\n", tx);
	}
	void setCreateUVs(unsigned int cuv)
	{
		if(cuv == 1) return;
		fprintf(mFile,"\tsetAttr \".cuv\" %i;\n", cuv);
	}
	void getWidth()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getHeight()const
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getSubdivisionsWidth()const
	{
		fprintf(mFile,"\"%s.sw\"",mName.c_str());
	}
	void getSubdivisionsHeight()const
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());
	}
	void getTexture()const
	{
		fprintf(mFile,"\"%s.tx\"",mName.c_str());
	}
	void getCreateUVs()const
	{
		fprintf(mFile,"\"%s.cuv\"",mName.c_str());
	}
protected:
	PolyPlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPLANE_H__
