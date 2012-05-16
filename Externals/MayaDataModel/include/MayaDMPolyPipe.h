/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPIPE_H__
#define __MayaDM_POLYPIPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
class PolyPipe : public PolyPrimitive
{
public:
public:

	PolyPipe():PolyPrimitive(){}
	PolyPipe(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, "polyPipe", shared, create){}
	virtual ~PolyPipe(){}

	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"\tsetAttr \".r\" %f;\n", r);
	}
	void setHeight(double h)
	{
		if(h == 2) return;
		fprintf(mFile,"\tsetAttr \".h\" %f;\n", h);
	}
	void setThickness(double t)
	{
		if(t == 0) return;
		fprintf(mFile,"\tsetAttr \".t\" %f;\n", t);
	}
	void setSubdivisionsAxis(int sa)
	{
		if(sa == 20) return;
		fprintf(mFile,"\tsetAttr \".sa\" %i;\n", sa);
	}
	void setSubdivisionsHeight(int sh)
	{
		if(sh == 1) return;
		fprintf(mFile,"\tsetAttr \".sh\" %i;\n", sh);
	}
	void setSubdivisionsCaps(int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"\tsetAttr \".sc\" %i;\n", sc);
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
	void setRoundCap(bool rcp)
	{
		if(rcp == false) return;
		fprintf(mFile,"\tsetAttr \".rcp\" %i;\n", rcp);
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getHeight()const
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getThickness()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getSubdivisionsAxis()const
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());
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
	void getRoundCap()const
	{
		fprintf(mFile,"\"%s.rcp\"",mName.c_str());
	}
protected:
	PolyPipe(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPIPE_H__
