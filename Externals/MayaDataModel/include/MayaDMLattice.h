/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LATTICE_H__
#define __MayaDM_LATTICE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMControlPoint.h"
namespace MayaDM
{
class Lattice : public ControlPoint
{
public:
public:
	Lattice():ControlPoint(){}
	Lattice(FILE* file,const std::string& name,const std::string& parent=""):ControlPoint(file, name, parent, "lattice"){}
	virtual ~Lattice(){}
	void setSDivisions(short sd)
	{
		if(sd == 2) return;
		fprintf(mFile,"\tsetAttr \".sd\" %i;\n", sd);

	}
	void setTDivisions(short td)
	{
		if(td == 5) return;
		fprintf(mFile,"\tsetAttr \".td\" %i;\n", td);

	}
	void setUDivisions(short ud)
	{
		if(ud == 2) return;
		fprintf(mFile,"\tsetAttr \".ud\" %i;\n", ud);

	}
	void setCached(const lattice& cc)
	{
		fprintf(mFile,"\tsetAttr \".cc\" -type \"lattice\" ");
		cc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDispPoints(bool dcv)
	{
		if(dcv == off) return;
		fprintf(mFile,"\tsetAttr \".dcv\" %i;\n", dcv);

	}
	void setDispLattice(bool dep)
	{
		if(dep == on) return;
		fprintf(mFile,"\tsetAttr \".dep\" %i;\n", dep);

	}
	void setOrigin(const double3& or)
	{
		fprintf(mFile,"\tsetAttr \".or\" -type \"double3\" ");
		or.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOriginX(double ox)
	{
		if(ox == 0) return;
		fprintf(mFile,"\tsetAttr \".or.ox\" %f;\n", ox);

	}
	void setOriginY(double oy)
	{
		if(oy == 0) return;
		fprintf(mFile,"\tsetAttr \".or.oy\" %f;\n", oy);

	}
	void setOriginZ(double oz)
	{
		if(oz == 0) return;
		fprintf(mFile,"\tsetAttr \".or.oz\" %f;\n", oz);

	}
	void getLatticeOutput()
	{
		fprintf(mFile,"\"%s.lo\"",mName.c_str());

	}
	void getWorldLattice(size_t wl_i)
	{
		fprintf(mFile,"\"%s.wl[%i]\"",mName.c_str(),wl_i);

	}
	void getLatticeInput()
	{
		fprintf(mFile,"\"%s.li\"",mName.c_str());

	}
	void getCached()
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());

	}
	void getLatticePointMoved()
	{
		fprintf(mFile,"\"%s.lpm\"",mName.c_str());

	}
	void getDisplayControl()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getDispPoints()
	{
		fprintf(mFile,"\"%s.dcv\"",mName.c_str());

	}
	void getDispLattice()
	{
		fprintf(mFile,"\"%s.dep\"",mName.c_str());

	}
	void getOrigin()
	{
		fprintf(mFile,"\"%s.or\"",mName.c_str());

	}
	void getOriginX()
	{
		fprintf(mFile,"\"%s.or.ox\"",mName.c_str());

	}
	void getOriginY()
	{
		fprintf(mFile,"\"%s.or.oy\"",mName.c_str());

	}
	void getOriginZ()
	{
		fprintf(mFile,"\"%s.or.oz\"",mName.c_str());

	}
protected:
	Lattice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:ControlPoint(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_LATTICE_H__
