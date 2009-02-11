/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYFLIPEDGE_H__
#define __MayaDM_POLYFLIPEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyFlipEdge : public PolyModifier
{
public:
public:
	PolyFlipEdge():PolyModifier(){}
	PolyFlipEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyFlipEdge"){}
	virtual ~PolyFlipEdge(){}
	void setEdge(const componentList& e)
	{
		fprintf(mFile,"\tsetAttr \".e\" -type \"componentList\" ");
		e.write(mFile);
		fprintf(mFile,";\n");

	}
	void getEdge()
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());

	}
protected:
	PolyFlipEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:PolyModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYFLIPEDGE_H__
