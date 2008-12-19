/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSOFTEDGE_H__
#define __MayaDM_POLYSOFTEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolySoftEdge : public PolyModifierWorld
{
public:
public:
	PolySoftEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polySoftEdge"){}
	virtual ~PolySoftEdge(){}
	void setAngle(double a)
	{
		if(a == 3) return;
		fprintf(mFile,"setAttr \".a\" %f;\n", a);

	}
	void getAngle()
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());

	}
protected:
	PolySoftEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSOFTEDGE_H__
