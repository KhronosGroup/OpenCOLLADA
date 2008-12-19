/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolyPipe(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyPipe"){}
	virtual ~PolyPipe(){}
	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setHeight(double h)
	{
		if(h == 2) return;
		fprintf(mFile,"setAttr \".h\" %f;\n", h);

	}
	void setThickness(double t)
	{
		if(t == 0) return;
		fprintf(mFile,"setAttr \".t\" %f;\n", t);

	}
	void setSubdivisionsAxis(int sa)
	{
		if(sa == 20) return;
		fprintf(mFile,"setAttr \".sa\" %i;\n", sa);

	}
	void setSubdivisionsHeight(int sh)
	{
		if(sh == 1) return;
		fprintf(mFile,"setAttr \".sh\" %i;\n", sh);

	}
	void setSubdivisionsCaps(int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"setAttr \".sc\" %i;\n", sc);

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
	void setRoundCap(bool rcp)
	{
		if(rcp == false) return;
		fprintf(mFile,"setAttr \".rcp\" %i;\n", rcp);

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getHeight()
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());

	}
	void getThickness()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getSubdivisionsAxis()
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());

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
	void getRoundCap()
	{
		fprintf(mFile,"\"%s.rcp\"",mName.c_str());

	}
protected:
	PolyPipe(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPIPE_H__
