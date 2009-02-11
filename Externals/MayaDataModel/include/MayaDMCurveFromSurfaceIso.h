/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSURFACEISO_H__
#define __MayaDM_CURVEFROMSURFACEISO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSurface.h"
namespace MayaDM
{
class CurveFromSurfaceIso : public CurveFromSurface
{
public:
public:
	CurveFromSurfaceIso():CurveFromSurface(){}
	CurveFromSurfaceIso(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSurface(file, name, parent, "curveFromSurfaceIso"){}
	virtual ~CurveFromSurfaceIso(){}
	void setIsoparmValue(double iv)
	{
		if(iv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".iv\" %f;\n", iv);

	}
	void setIsoparmDirection(unsigned int idr)
	{
		if(idr == 0) return;
		fprintf(mFile,"\tsetAttr \".idr\" %i;\n", idr);

	}
	void setRelativeValue(bool rv)
	{
		if(rv == false) return;
		fprintf(mFile,"\tsetAttr \".rv\" %i;\n", rv);

	}
	void getIsoparmValue()
	{
		fprintf(mFile,"\"%s.iv\"",mName.c_str());

	}
	void getIsoparmDirection()
	{
		fprintf(mFile,"\"%s.idr\"",mName.c_str());

	}
	void getRelativeValue()
	{
		fprintf(mFile,"\"%s.rv\"",mName.c_str());

	}
protected:
	CurveFromSurfaceIso(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:CurveFromSurface(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSURFACEISO_H__
