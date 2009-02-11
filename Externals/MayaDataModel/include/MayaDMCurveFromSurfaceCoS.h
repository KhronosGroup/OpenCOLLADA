/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSURFACECOS_H__
#define __MayaDM_CURVEFROMSURFACECOS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSurface.h"
namespace MayaDM
{
class CurveFromSurfaceCoS : public CurveFromSurface
{
public:
public:
	CurveFromSurfaceCoS():CurveFromSurface(){}
	CurveFromSurfaceCoS(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSurface(file, name, parent, "curveFromSurfaceCoS"){}
	virtual ~CurveFromSurfaceCoS(){}
	void getCurveOnSurface()
	{
		fprintf(mFile,"\"%s.cos\"",mName.c_str());

	}
protected:
	CurveFromSurfaceCoS(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:CurveFromSurface(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSURFACECOS_H__
