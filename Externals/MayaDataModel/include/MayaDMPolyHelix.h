/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	PolyHelix():PolyPrimitive(){}
	PolyHelix(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, "polyHelix", shared, create){}
	virtual ~PolyHelix(){}

	void setCoils(double c)
	{
		if(c == 3) return;
		fprintf(mFile,"\tsetAttr \".c\" %f;\n", c);
	}
	void setHeight(double h)
	{
		if(h == 2) return;
		fprintf(mFile,"\tsetAttr \".h\" %f;\n", h);
	}
	void setWidth(double w)
	{
		if(w == 2) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setRadius(double r)
	{
		if(r == 0) return;
		fprintf(mFile,"\tsetAttr \".r\" %f;\n", r);
	}
	void setDirection(unsigned int d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setSubdivisionsAxis(int sa)
	{
		if(sa == 8) return;
		fprintf(mFile,"\tsetAttr \".sa\" %i;\n", sa);
	}
	void setSubdivisionsCoil(int sco)
	{
		if(sco == 50) return;
		fprintf(mFile,"\tsetAttr \".sco\" %i;\n", sco);
	}
	void setSubdivisionsCaps(int sc)
	{
		if(sc == 0) return;
		fprintf(mFile,"\tsetAttr \".sc\" %i;\n", sc);
	}
	void setTexture(unsigned int tx)
	{
		if(tx == 2) return;
		fprintf(mFile,"\tsetAttr \".tx\" %i;\n", tx);
	}
	void setCreateUVs(unsigned int cuv)
	{
		if(cuv == 2) return;
		fprintf(mFile,"\tsetAttr \".cuv\" %i;\n", cuv);
	}
	void setRoundCap(bool rcp)
	{
		if(rcp == false) return;
		fprintf(mFile,"\tsetAttr \".rcp\" %i;\n", rcp);
	}
	void setUseOldInitBehaviour(bool oib)
	{
		if(oib == false) return;
		fprintf(mFile,"\tsetAttr \".oib\" %i;\n", oib);
	}
	void getCoils()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getHeight()const
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getWidth()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getDirection()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSubdivisionsAxis()const
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());
	}
	void getSubdivisionsCoil()const
	{
		fprintf(mFile,"\"%s.sco\"",mName.c_str());
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
	void getUseOldInitBehaviour()const
	{
		fprintf(mFile,"\"%s.oib\"",mName.c_str());
	}
protected:
	PolyHelix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyPrimitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYHELIX_H__
