/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSTOSUBDIVPROC_H__
#define __MayaDM_NURBSTOSUBDIVPROC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNurbsToSubdiv.h"
namespace MayaDM
{
class NurbsToSubdivProc : public NurbsToSubdiv
{
public:
public:

	NurbsToSubdivProc():NurbsToSubdiv(){}
	NurbsToSubdivProc(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:NurbsToSubdiv(file, name, parent, "nurbsToSubdivProc", shared, create){}
	virtual ~NurbsToSubdivProc(){}

	void setSolidType(unsigned int st)
	{
		if(st == 2) return;
		fprintf(mFile,"\tsetAttr \".st\" %i;\n", st);
	}
	void setCapType(unsigned int ct)
	{
		if(ct == 0) return;
		fprintf(mFile,"\tsetAttr \".ct\" %i;\n", ct);
	}
	void setTransform(const matrix& t)
	{
		if(t == identity) return;
		fprintf(mFile,"\tsetAttr \".t\" -type \"matrix\" ");
		t.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOffset(double o)
	{
		if(o == 1) return;
		fprintf(mFile,"\tsetAttr \".o\" %f;\n", o);
	}
	void setBridge(unsigned int br)
	{
		if(br == 0) return;
		fprintf(mFile,"\tsetAttr \".br\" %i;\n", br);
	}
	void getSolidType()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getCapType()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getTransform()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getBridge()const
	{
		fprintf(mFile,"\"%s.br\"",mName.c_str());
	}
	void getBridgeInU()const
	{
		fprintf(mFile,"\"%s.biu\"",mName.c_str());
	}
	void getBridgeInV()const
	{
		fprintf(mFile,"\"%s.biv\"",mName.c_str());
	}
protected:
	NurbsToSubdivProc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:NurbsToSubdiv(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NURBSTOSUBDIVPROC_H__
