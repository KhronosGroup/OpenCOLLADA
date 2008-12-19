/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTORUS_H__
#define __MayaDM_POLYTORUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
class PolyTorus : public PolyPrimitive
{
public:
public:
	PolyTorus(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyTorus"){}
	virtual ~PolyTorus(){}
	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setSectionRadius(double sr)
	{
		if(sr == 0) return;
		fprintf(mFile,"setAttr \".sr\" %f;\n", sr);

	}
	void setTwist(double tw)
	{
		if(tw == 0) return;
		fprintf(mFile,"setAttr \".tw\" %f;\n", tw);

	}
	void setSubdivisionsAxis(int sa)
	{
		if(sa == 20) return;
		fprintf(mFile,"setAttr \".sa\" %i;\n", sa);

	}
	void setSubdivisionsHeight(int sh)
	{
		if(sh == 20) return;
		fprintf(mFile,"setAttr \".sh\" %i;\n", sh);

	}
	void setTexture(bool tx)
	{
		if(tx == true) return;
		fprintf(mFile,"setAttr \".tx\" %i;\n", tx);

	}
	void setCreateUVs(bool cuv)
	{
		if(cuv == true) return;
		fprintf(mFile,"setAttr \".cuv\" %i;\n", cuv);

	}
	void setReverseTexture(bool rtx)
	{
		if(rtx == false) return;
		fprintf(mFile,"setAttr \".rtx\" %i;\n", rtx);

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getSectionRadius()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getTwist()
	{
		fprintf(mFile,"\"%s.tw\"",mName.c_str());

	}
	void getSubdivisionsAxis()
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());

	}
	void getSubdivisionsHeight()
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());

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
	PolyTorus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYTORUS_H__
