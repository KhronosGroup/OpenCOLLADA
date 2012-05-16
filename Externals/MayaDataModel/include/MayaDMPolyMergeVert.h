/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMERGEVERT_H__
#define __MayaDM_POLYMERGEVERT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyMergeVert : public PolyModifierWorld
{
public:
public:

	PolyMergeVert():PolyModifierWorld(){}
	PolyMergeVert(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polyMergeVert", shared, create){}
	virtual ~PolyMergeVert(){}

	void setDistance(double d)
	{
		if(d == 0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setAlwaysMergeTwoVertices(bool am)
	{
		if(am == false) return;
		fprintf(mFile,"\tsetAttr \".am\" %i;\n", am);
	}
	void setTexture(bool tx)
	{
		if(tx == true) return;
		fprintf(mFile,"\tsetAttr \".tx\" %i;\n", tx);
	}
	void getDistance()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getAlwaysMergeTwoVertices()const
	{
		fprintf(mFile,"\"%s.am\"",mName.c_str());
	}
	void getTexture()const
	{
		fprintf(mFile,"\"%s.tx\"",mName.c_str());
	}
protected:
	PolyMergeVert(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMERGEVERT_H__
