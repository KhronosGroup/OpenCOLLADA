/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolyExtrudeVertex(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyExtrudeVertex"){}
	virtual ~PolyExtrudeVertex(){}
	void setLength(float l)
	{
		if(l == 0.0) return;
		fprintf(mFile,"setAttr \".l\" %f;\n", l);

	}
	void setWidth(float w)
	{
		if(w == 0.0) return;
		fprintf(mFile,"setAttr \".w\" %f;\n", w);

	}
	void setDivisions(int d)
	{
		if(d == 1) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void getLength()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getWidth()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getDivisions()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
protected:
	PolyExtrudeVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYEXTRUDEVERTEX_H__
