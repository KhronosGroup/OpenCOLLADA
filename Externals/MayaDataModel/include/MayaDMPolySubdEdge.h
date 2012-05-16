/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSUBDEDGE_H__
#define __MayaDM_POLYSUBDEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolySubdEdge : public PolyModifierWorld
{
public:
public:

	PolySubdEdge():PolyModifierWorld(){}
	PolySubdEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polySubdEdge", shared, create){}
	virtual ~PolySubdEdge(){}

	void setDivisions(int dv)
	{
		if(dv == 1) return;
		fprintf(mFile,"\tsetAttr \".dv\" %i;\n", dv);
	}
	void setSize(double s)
	{
		if(s == 0) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void getDivisions()const
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());
	}
	void getSize()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
protected:
	PolySubdEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSUBDEDGE_H__
