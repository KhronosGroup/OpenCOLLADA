/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTRANSFER_H__
#define __MayaDM_POLYTRANSFER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyTransfer : public PolyModifier
{
public:
public:

	PolyTransfer():PolyModifier(){}
	PolyTransfer(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyTransfer", shared, create){}
	virtual ~PolyTransfer(){}

	void setOtherPoly(const mesh& op)
	{
		fprintf(mFile,"\tsetAttr \".op\" -type \"mesh\" ");
		op.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertices(bool v)
	{
		if(v == false) return;
		fprintf(mFile,"\tsetAttr \".v\" %i;\n", v);
	}
	void setUvSets(bool uv)
	{
		if(uv == true) return;
		fprintf(mFile,"\tsetAttr \".uv\" %i;\n", uv);
	}
	void setVertexColor(bool vc)
	{
		if(vc == false) return;
		fprintf(mFile,"\tsetAttr \".vc\" %i;\n", vc);
	}
	void getOtherPoly()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getVertices()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getUvSets()const
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());
	}
	void getVertexColor()const
	{
		fprintf(mFile,"\"%s.vc\"",mName.c_str());
	}
protected:
	PolyTransfer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYTRANSFER_H__
