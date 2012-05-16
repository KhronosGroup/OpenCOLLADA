/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	PolySoftEdge():PolyModifierWorld(){}
	PolySoftEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polySoftEdge", shared, create){}
	virtual ~PolySoftEdge(){}

	void setAngle(double a)
	{
		if(a == 3) return;
		fprintf(mFile,"\tsetAttr \".a\" %f;\n", a);
	}
	void getAngle()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
protected:
	PolySoftEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSOFTEDGE_H__
