/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYWEDGEFACE_H__
#define __MayaDM_POLYWEDGEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyWedgeFace : public PolyModifierWorld
{
public:
public:
	PolyWedgeFace(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyWedgeFace"){}
	virtual ~PolyWedgeFace(){}
	void setWedgeAngle(double wa)
	{
		if(wa == 0) return;
		fprintf(mFile,"setAttr \".wa\" %f;\n", wa);

	}
	void setDivisions(int d)
	{
		if(d == 1) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setEdge(size_t ed_i,int ed)
	{
		if(ed == 0) return;
		fprintf(mFile,"setAttr \".ed[%i]\" %i;\n", ed_i,ed);

	}
	void getWedgeAngle()
	{
		fprintf(mFile,"\"%s.wa\"",mName.c_str());

	}
	void getDivisions()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getEdge(size_t ed_i)
	{
		fprintf(mFile,"\"%s.ed[%i]\"",mName.c_str(),ed_i);

	}
protected:
	PolyWedgeFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYWEDGEFACE_H__
