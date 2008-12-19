/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPLATONICSOLID_H__
#define __MayaDM_POLYPLATONICSOLID_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
class PolyPlatonicSolid : public PolyPrimitive
{
public:
public:
	PolyPlatonicSolid(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyPlatonicSolid"){}
	virtual ~PolyPlatonicSolid(){}
	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setSideLength(double l)
	{
		if(l == 0) return;
		fprintf(mFile,"setAttr \".l\" %f;\n", l);

	}
	void setSolidType(unsigned int st)
	{
		if(st == 0) return;
		fprintf(mFile,"setAttr \".st\" %i;\n", st);

	}
	void setTexture(unsigned int tx)
	{
		if(tx == 2) return;
		fprintf(mFile,"setAttr \".tx\" %i;\n", tx);

	}
	void setCreateUVs(unsigned int cuv)
	{
		if(cuv == 3) return;
		fprintf(mFile,"setAttr \".cuv\" %i;\n", cuv);

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getSideLength()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getSolidType()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

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
	PolyPlatonicSolid(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPLATONICSOLID_H__
