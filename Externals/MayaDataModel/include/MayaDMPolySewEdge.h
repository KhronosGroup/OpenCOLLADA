/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSEWEDGE_H__
#define __MayaDM_POLYSEWEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolySewEdge : public PolyModifierWorld
{
public:
public:

	PolySewEdge():PolyModifierWorld(){}
	PolySewEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polySewEdge", shared, create){}
	virtual ~PolySewEdge(){}

	void setTolerance(double t)
	{
		if(t == 0) return;
		fprintf(mFile,"\tsetAttr \".t\" %f;\n", t);
	}
	void setTexture(bool tx)
	{
		if(tx == true) return;
		fprintf(mFile,"\tsetAttr \".tx\" %i;\n", tx);
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getTexture()const
	{
		fprintf(mFile,"\"%s.tx\"",mName.c_str());
	}
protected:
	PolySewEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSEWEDGE_H__
