/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYHELIX_H__
#define __MayaDM_POLYHELIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
class PolyHelix : public PolyPrimitive
{
public:
public:
	PolyHelix(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyHelix"){}
	virtual ~PolyHelix(){}
	void setCoils(double c)
	{
		if(c == 3) return;
		fprintf(mFile,"setAttr \".c\" %f;\n", c);

	}
	void setHeight(double h)
	{
		if(h == 2) return;
		fprintf(mFile,"setAttr \".h\" %f;\n", h);

	}
	void setWidth(double w)
	{
		if(w == 2) return;
		fprintf(mFile,"setAttr \".w\" %f;\n", w);

	}
	void setRadius(double r)
	{
		if(r == 0) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setDirection(unsigned int d)
	{
		if(d == 1) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setSubdivisionsAxis(int sa)
	{
		if(sa == 8) return;
		fprintf(mFile,"setAttr \".sa\" %i;\n", sa);

	}
	void setSubdivisionsCoil(int sco)
	{
		if(sco == 50) return;
		fprintf(mFile,"setAttr \".sco\" %i;\n", sco);

	}
	void setSubdivisionsCaps(int sc)
	{
		if(sc == 0) return;
		fprintf(mFile,"setAttr \".sc\" %i;\n", sc);

	}
	void setTexture(unsigned int tx)
	{
		if(tx == 2) return;
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
	void setUseOldInitBehaviour(bool oib)
	{
		if(oib == false) return;
		fprintf(mFile,"setAttr \".oib\" %i;\n", oib);

	}
	void getCoils()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getHeight()
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());

	}
	void getWidth()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getSubdivisionsAxis()
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());

	}
	void getSubdivisionsCoil()
	{
		fprintf(mFile,"\"%s.sco\"",mName.c_str());

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
	void getUseOldInitBehaviour()
	{
		fprintf(mFile,"\"%s.oib\"",mName.c_str());

	}
protected:
	PolyHelix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYHELIX_H__
