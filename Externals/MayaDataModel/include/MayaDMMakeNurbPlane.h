/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBPLANE_H__
#define __MayaDM_MAKENURBPLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPrimitive.h"
namespace MayaDM
{
class MakeNurbPlane : public Primitive
{
public:
public:

	MakeNurbPlane():Primitive(){}
	MakeNurbPlane(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Primitive(file, name, parent, "makeNurbPlane", shared, create){}
	virtual ~MakeNurbPlane(){}

	void setWidth(double w)
	{
		if(w == 1) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setLengthRatio(double lr)
	{
		if(lr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lr\" %f;\n", lr);
	}
	void setPatchesU(int u)
	{
		if(u == 1) return;
		fprintf(mFile,"\tsetAttr \".u\" %i;\n", u);
	}
	void setPatchesV(int v)
	{
		if(v == 1) return;
		fprintf(mFile,"\tsetAttr \".v\" %i;\n", v);
	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void getWidth()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getLengthRatio()const
	{
		fprintf(mFile,"\"%s.lr\"",mName.c_str());
	}
	void getPatchesU()const
	{
		fprintf(mFile,"\"%s.u\"",mName.c_str());
	}
	void getPatchesV()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
protected:
	MakeNurbPlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Primitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBPLANE_H__
