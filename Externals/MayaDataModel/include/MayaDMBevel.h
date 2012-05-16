/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BEVEL_H__
#define __MayaDM_BEVEL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class Bevel : public AbstractBaseCreate
{
public:
public:

	Bevel():AbstractBaseCreate(){}
	Bevel(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "bevel", shared, create){}
	virtual ~Bevel(){}

	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void setWidth(double w)
	{
		if(w == 0) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setDepth(double d)
	{
		if(d == 0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setExtrudeDepth(double ed)
	{
		if(ed == 1) return;
		fprintf(mFile,"\tsetAttr \".ed\" %f;\n", ed);
	}
	void setCornerType(unsigned int ct)
	{
		if(ct == 2) return;
		fprintf(mFile,"\tsetAttr \".ct\" %i;\n", ct);
	}
	void setNumberOfSides(int ns)
	{
		if(ns == 4) return;
		fprintf(mFile,"\tsetAttr \".ns\" %i;\n", ns);
	}
	void setBevelShapeType(unsigned int bst)
	{
		if(bst == 1) return;
		fprintf(mFile,"\tsetAttr \".bst\" %i;\n", bst);
	}
	void setJoinSurfaces(bool js)
	{
		if(js == true) return;
		fprintf(mFile,"\tsetAttr \".js\" %i;\n", js);
	}
	void getInputCurve()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getUseDirectionCurve()const
	{
		fprintf(mFile,"\"%s.udc\"",mName.c_str());
	}
	void getOutputSurface1()const
	{
		fprintf(mFile,"\"%s.os1\"",mName.c_str());
	}
	void getOutputSurface2()const
	{
		fprintf(mFile,"\"%s.os2\"",mName.c_str());
	}
	void getOutputSurface3()const
	{
		fprintf(mFile,"\"%s.os3\"",mName.c_str());
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getWidth()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getDepth()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getExtrudeDepth()const
	{
		fprintf(mFile,"\"%s.ed\"",mName.c_str());
	}
	void getCornerType()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getNumberOfSides()const
	{
		fprintf(mFile,"\"%s.ns\"",mName.c_str());
	}
	void getBevelShapeType()const
	{
		fprintf(mFile,"\"%s.bst\"",mName.c_str());
	}
	void getJoinSurfaces()const
	{
		fprintf(mFile,"\"%s.js\"",mName.c_str());
	}
protected:
	Bevel(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BEVEL_H__
