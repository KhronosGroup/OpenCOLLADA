/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYAVERAGEVERTEX_H__
#define __MayaDM_POLYAVERAGEVERTEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyAverageVertex : public PolyModifierWorld
{
public:
public:

	PolyAverageVertex():PolyModifierWorld(){}
	PolyAverageVertex(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polyAverageVertex", shared, create){}
	virtual ~PolyAverageVertex(){}

	void setAlpha(float a)
	{
		if(a == 0.5) return;
		fprintf(mFile,"\tsetAttr \".a\" %f;\n", a);
	}
	void setBeta(float b)
	{
		if(b == 0.7) return;
		fprintf(mFile,"\tsetAttr \".b\" %f;\n", b);
	}
	void setIterations(int i_)
	{
		if(i_ == 10) return;
		fprintf(mFile,"\tsetAttr \".i\" %i;\n", i_);
	}
	void getAlpha()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getBeta()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getIterations()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
protected:
	PolyAverageVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYAVERAGEVERTEX_H__
