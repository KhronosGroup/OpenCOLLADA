/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolyPyramid(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyPyramid"){}
	virtual ~PolyPyramid(){}
	void setSideLength(double w)
	{
		if(w == 1) return;
		fprintf(mFile,"setAttr \".w\" %f;\n", w);

	}
	void setNumderOfSides(unsigned int ns)
	{
		if(ns == 1) return;
		fprintf(mFile,"setAttr \".ns\" %i;\n", ns);

	}
	void setSubdivisionsHeight(int sh)
	{
		if(sh == 1) return;
		fprintf(mFile,"setAttr \".sh\" %i;\n", sh);

	}
	void setSubdivisionsCaps(int sc)
	{
		if(sc == 0) return;
		fprintf(mFile,"setAttr \".sc\" %i;\n", sc);

	}
	void setTexture(bool tx)
	{
		if(tx == true) return;
		fprintf(mFile,"setAttr \".tx\" %i;\n", tx);

	}
	void setCreateUVs(unsigned int cuv)
	{
		if(cuv == 2) return;
		fprintf(mFile,"setAttr \".cuv\" %i;\n", cuv);

	}
	void getSideLength()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getNumderOfSides()
	{
		fprintf(mFile,"\"%s.ns\"",mName.c_str());

	}
	void getSubdivisionsHeight()
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());

	}
	void getSubdivisionsCaps()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getTexture()
	{
		fprintf(mFile,"\"%s.tx\"",mName.c_str());

	}
	void getCreateUVs()
	{
		fprintf(mFile,"\"%s.cuv\"",mName.c_str());

	}
protected:
	PolyPyramid(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPYRAMID_H__
