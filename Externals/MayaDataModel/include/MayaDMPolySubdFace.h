/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolySubdFace(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polySubdFace"){}
	virtual ~PolySubdFace(){}
	void setDivisions(int dv)
	{
		if(dv == 1) return;
		fprintf(mFile,"setAttr \".dv\" %i;\n", dv);

	}
	void setDivisionsU(int duv)
	{
		if(duv == 1) return;
		fprintf(mFile,"setAttr \".duv\" %i;\n", duv);

	}
	void setDivisionsV(int dvv)
	{
		if(dvv == 1) return;
		fprintf(mFile,"setAttr \".dvv\" %i;\n", dvv);

	}
	void setMode(unsigned int m)
	{
		if(m == 0) return;
		fprintf(mFile,"setAttr \".m\" %i;\n", m);

	}
	void setSubdMethod(unsigned int sbm)
	{
		if(sbm == 0) return;
		fprintf(mFile,"setAttr \".sbm\" %i;\n", sbm);

	}
	void getDivisions()
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());

	}
	void getDivisionsU()
	{
		fprintf(mFile,"\"%s.duv\"",mName.c_str());

	}
	void getDivisionsV()
	{
		fprintf(mFile,"\"%s.dvv\"",mName.c_str());

	}
	void getMode()
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());

	}
	void getSubdMethod()
	{
		fprintf(mFile,"\"%s.sbm\"",mName.c_str());

	}
protected:
	PolySubdFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSUBDFACE_H__
