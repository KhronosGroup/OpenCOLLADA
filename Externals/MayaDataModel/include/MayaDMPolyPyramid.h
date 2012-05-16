/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPYRAMID_H__
#define __MayaDM_POLYPYRAMID_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
class PolyPyramid : public PolyPrimitive
{
public:
public:

	PolyPyramid():PolyPrimitive(){}
	PolyPyramid(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, "polyPyramid", shared, create){}
	virtual ~PolyPyramid(){}

	void setSideLength(double w)
	{
		if(w == 1) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setNumderOfSides(unsigned int ns)
	{
		if(ns == 1) return;
		fprintf(mFile,"\tsetAttr \".ns\" %i;\n", ns);
	}
	void setSubdivisionsHeight(int sh)
	{
		if(sh == 1) return;
		fprintf(mFile,"\tsetAttr \".sh\" %i;\n", sh);
	}
	void setSubdivisionsCaps(int sc)
	{
		if(sc == 0) return;
		fprintf(mFile,"\tsetAttr \".sc\" %i;\n", sc);
	}
	void setTexture(bool tx)
	{
		if(tx == true) return;
		fprintf(mFile,"\tsetAttr \".tx\" %i;\n", tx);
	}
	void setCreateUVs(unsigned int cuv)
	{
		if(cuv == 2) return;
		fprintf(mFile,"\tsetAttr \".cuv\" %i;\n", cuv);
	}
	void getSideLength()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getNumderOfSides()const
	{
		fprintf(mFile,"\"%s.ns\"",mName.c_str());
	}
	void getSubdivisionsHeight()const
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());
	}
	void getSubdivisionsCaps()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getTexture()const
	{
		fprintf(mFile,"\"%s.tx\"",mName.c_str());
	}
	void getCreateUVs()const
	{
		fprintf(mFile,"\"%s.cuv\"",mName.c_str());
	}
protected:
	PolyPyramid(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPYRAMID_H__
