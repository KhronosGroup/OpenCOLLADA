/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSUBDFACE_H__
#define __MayaDM_POLYSUBDFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolySubdFace : public PolyModifier
{
public:
public:

	PolySubdFace():PolyModifier(){}
	PolySubdFace(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polySubdFace", shared, create){}
	virtual ~PolySubdFace(){}

	void setDivisions(int dv)
	{
		if(dv == 1) return;
		fprintf(mFile,"\tsetAttr \".dv\" %i;\n", dv);
	}
	void setDivisionsU(int duv)
	{
		if(duv == 1) return;
		fprintf(mFile,"\tsetAttr \".duv\" %i;\n", duv);
	}
	void setDivisionsV(int dvv)
	{
		if(dvv == 1) return;
		fprintf(mFile,"\tsetAttr \".dvv\" %i;\n", dvv);
	}
	void setMode(unsigned int m)
	{
		if(m == 0) return;
		fprintf(mFile,"\tsetAttr \".m\" %i;\n", m);
	}
	void setSubdMethod(unsigned int sbm)
	{
		if(sbm == 0) return;
		fprintf(mFile,"\tsetAttr \".sbm\" %i;\n", sbm);
	}
	void getDivisions()const
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());
	}
	void getDivisionsU()const
	{
		fprintf(mFile,"\"%s.duv\"",mName.c_str());
	}
	void getDivisionsV()const
	{
		fprintf(mFile,"\"%s.dvv\"",mName.c_str());
	}
	void getMode()const
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getSubdMethod()const
	{
		fprintf(mFile,"\"%s.sbm\"",mName.c_str());
	}
protected:
	PolySubdFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSUBDFACE_H__
