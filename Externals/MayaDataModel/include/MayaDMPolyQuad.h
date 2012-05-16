/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYQUAD_H__
#define __MayaDM_POLYQUAD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyQuad : public PolyModifierWorld
{
public:
public:

	PolyQuad():PolyModifierWorld(){}
	PolyQuad(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polyQuad", shared, create){}
	virtual ~PolyQuad(){}

	void setAngle(double a)
	{
		if(a == 3) return;
		fprintf(mFile,"\tsetAttr \".a\" %f;\n", a);
	}
	void setKeepGroupBorder(bool kgb)
	{
		if(kgb == true) return;
		fprintf(mFile,"\tsetAttr \".kgb\" %i;\n", kgb);
	}
	void setKeepTextureBorders(bool ktb)
	{
		if(ktb == true) return;
		fprintf(mFile,"\tsetAttr \".ktb\" %i;\n", ktb);
	}
	void setKeepHardEdges(bool khe)
	{
		if(khe == true) return;
		fprintf(mFile,"\tsetAttr \".khe\" %i;\n", khe);
	}
	void setMaya80(bool m80)
	{
		if(m80 == true) return;
		fprintf(mFile,"\tsetAttr \".m80\" %i;\n", m80);
	}
	void getAngle()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getKeepGroupBorder()const
	{
		fprintf(mFile,"\"%s.kgb\"",mName.c_str());
	}
	void getKeepTextureBorders()const
	{
		fprintf(mFile,"\"%s.ktb\"",mName.c_str());
	}
	void getKeepHardEdges()const
	{
		fprintf(mFile,"\"%s.khe\"",mName.c_str());
	}
protected:
	PolyQuad(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYQUAD_H__
