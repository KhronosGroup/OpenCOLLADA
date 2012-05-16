/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYDELEDGE_H__
#define __MayaDM_POLYDELEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyDelEdge : public PolyModifier
{
public:
public:

	PolyDelEdge():PolyModifier(){}
	PolyDelEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyDelEdge", shared, create){}
	virtual ~PolyDelEdge(){}

	void setCleanVertices(bool cv)
	{
		if(cv == false) return;
		fprintf(mFile,"\tsetAttr \".cv\" %i;\n", cv);
	}
	void getCleanVertices()const
	{
		fprintf(mFile,"\"%s.cv\"",mName.c_str());
	}
protected:
	PolyDelEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYDELEDGE_H__
