/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolySubdEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polySubdEdge"){}
	virtual ~PolySubdEdge(){}
	void setDivisions(int dv)
	{
		if(dv == 1) return;
		fprintf(mFile,"setAttr \".dv\" %i;\n", dv);

	}
	void setSize(double s)
	{
		if(s == 0) return;
		fprintf(mFile,"setAttr \".s\" %f;\n", s);

	}
	void getDivisions()
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());

	}
	void getSize()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
protected:
	PolySubdEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSUBDEDGE_H__
