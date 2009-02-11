/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVREVERSEFACES_H__
#define __MayaDM_SUBDIVREVERSEFACES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SubdivReverseFaces : public DependNode
{
public:
public:
	SubdivReverseFaces():DependNode(){}
	SubdivReverseFaces(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdivReverseFaces"){}
	virtual ~SubdivReverseFaces(){}
	void setXMirror(bool xm)
	{
		if(xm == false) return;
		fprintf(mFile,"\tsetAttr \".xm\" %i;\n", xm);

	}
	void setYMirror(bool ym)
	{
		if(ym == false) return;
		fprintf(mFile,"\tsetAttr \".ym\" %i;\n", ym);

	}
	void setZMirror(bool zm)
	{
		if(zm == false) return;
		fprintf(mFile,"\tsetAttr \".zm\" %i;\n", zm);

	}
	void getInSubdiv()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getXMirror()
	{
		fprintf(mFile,"\"%s.xm\"",mName.c_str());

	}
	void getYMirror()
	{
		fprintf(mFile,"\"%s.ym\"",mName.c_str());

	}
	void getZMirror()
	{
		fprintf(mFile,"\"%s.zm\"",mName.c_str());

	}
	void getOutSubdiv()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	SubdivReverseFaces(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVREVERSEFACES_H__
