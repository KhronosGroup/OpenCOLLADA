/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	PolyTorus():PolyPrimitive(){}
	PolyTorus(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, "polyTorus", shared, create){}
	virtual ~PolyTorus(){}

	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"\tsetAttr \".r\" %f;\n", r);
	}
	void setSectionRadius(double sr)
	{
		if(sr == 0) return;
		fprintf(mFile,"\tsetAttr \".sr\" %f;\n", sr);
	}
	void setTwist(double tw)
	{
		if(tw == 0) return;
		fprintf(mFile,"\tsetAttr \".tw\" %f;\n", tw);
	}
	void setSubdivisionsAxis(int sa)
	{
		if(sa == 20) return;
		fprintf(mFile,"\tsetAttr \".sa\" %i;\n", sa);
	}
	void setSubdivisionsHeight(int sh)
	{
		if(sh == 20) return;
		fprintf(mFile,"\tsetAttr \".sh\" %i;\n", sh);
	}
	void setTexture(bool tx)
	{
		if(tx == true) return;
		fprintf(mFile,"\tsetAttr \".tx\" %i;\n", tx);
	}
	void setCreateUVs(bool cuv)
	{
		if(cuv == true) return;
		fprintf(mFile,"\tsetAttr \".cuv\" %i;\n", cuv);
	}
	void setReverseTexture(bool rtx)
	{
		if(rtx == false) return;
		fprintf(mFile,"\tsetAttr \".rtx\" %i;\n", rtx);
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getSectionRadius()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getTwist()const
	{
		fprintf(mFile,"\"%s.tw\"",mName.c_str());
	}
	void getSubdivisionsAxis()const
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());
	}
	void getSubdivisionsHeight()const
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());
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
	PolyTorus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYTORUS_H__
