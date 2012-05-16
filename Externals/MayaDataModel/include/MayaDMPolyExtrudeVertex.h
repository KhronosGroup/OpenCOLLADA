/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYEXTRUDEVERTEX_H__
#define __MayaDM_POLYEXTRUDEVERTEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyExtrudeVertex : public PolyModifierWorld
{
public:
public:

	PolyExtrudeVertex():PolyModifierWorld(){}
	PolyExtrudeVertex(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polyExtrudeVertex", shared, create){}
	virtual ~PolyExtrudeVertex(){}

	void setLength(float l)
	{
		if(l == 0.0) return;
		fprintf(mFile,"\tsetAttr \".l\" %f;\n", l);
	}
	void setWidth(float w)
	{
		if(w == 0.0) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setDivisions(int d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void getLength()const
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getWidth()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getDivisions()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
protected:
	PolyExtrudeVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYEXTRUDEVERTEX_H__
