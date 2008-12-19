/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCONE_H__
#define __MayaDM_POLYCONE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
class PolyCone : public PolyPrimitive
{
public:
public:
	PolyCone(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyCone"){}
	virtual ~PolyCone(){}
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
	void setSubdivisionsCap(int sc)
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
	void getSubdivisionsAxis()
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());

	}
	void getSubdivisionsHeight()
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());

	}
	void getSubdivisionsCap()
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
	PolyCone(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCONE_H__
