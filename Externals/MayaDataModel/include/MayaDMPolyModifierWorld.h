/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMODIFIERWORLD_H__
#define __MayaDM_POLYMODIFIERWORLD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyModifierWorld : public PolyModifier
{
public:
public:

	PolyModifierWorld():PolyModifier(){}
	PolyModifierWorld(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyModifierWorld", shared, create){}
	virtual ~PolyModifierWorld(){}

	void setInputMatrix(const matrix& ix)
	{
		fprintf(mFile,"\tsetAttr \".ix\" -type \"matrix\" ");
		ix.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWorldSpace(bool ws)
	{
		if(ws == false) return;
		fprintf(mFile,"\tsetAttr \".ws\" %i;\n", ws);
	}
	void setManipMatrix(const matrix& mp)
	{
		fprintf(mFile,"\tsetAttr \".mp\" -type \"matrix\" ");
		mp.write(mFile);
		fprintf(mFile,";\n");
	}
	void getInputMatrix()const
	{
		fprintf(mFile,"\"%s.ix\"",mName.c_str());
	}
	void getWorldSpace()const
	{
		fprintf(mFile,"\"%s.ws\"",mName.c_str());
	}
	void getManipMatrix()const
	{
		fprintf(mFile,"\"%s.mp\"",mName.c_str());
	}
protected:
	PolyModifierWorld(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMODIFIERWORLD_H__
