/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSURFACEBND_H__
#define __MayaDM_CURVEFROMSURFACEBND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSurface.h"
namespace MayaDM
{
class CurveFromSurfaceBnd : public CurveFromSurface
{
public:
public:

	CurveFromSurfaceBnd():CurveFromSurface(){}
	CurveFromSurfaceBnd(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:CurveFromSurface(file, name, parent, "curveFromSurfaceBnd", shared, create){}
	virtual ~CurveFromSurfaceBnd(){}

	void setFace(int f)
	{
		if(f == 0) return;
		fprintf(mFile,"\tsetAttr \".f\" %i;\n", f);
	}
	void setBoundary(int b)
	{
		if(b == 0) return;
		fprintf(mFile,"\tsetAttr \".b\" %i;\n", b);
	}
	void setEdge(int e)
	{
		if(e == -1) return;
		fprintf(mFile,"\tsetAttr \".e\" %i;\n", e);
	}
	void getFace()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getBoundary()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getEdge()const
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());
	}
protected:
	CurveFromSurfaceBnd(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:CurveFromSurface(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSURFACEBND_H__
