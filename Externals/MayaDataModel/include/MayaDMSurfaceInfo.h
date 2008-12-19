/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACEINFO_H__
#define __MayaDM_SURFACEINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class SurfaceInfo : public AbstractBaseCreate
{
public:
public:
	SurfaceInfo(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "surfaceInfo"){}
	virtual ~SurfaceInfo(){}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getControlPoints(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i]\"",mName.c_str(),cp_i);

	}
	void getXValue(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i].xv\"",mName.c_str(),cp_i);

	}
	void getYValue(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i].yv\"",mName.c_str(),cp_i);

	}
	void getZValue(size_t cp_i)
	{
		fprintf(mFile,"\"%s.cp[%i].zv\"",mName.c_str(),cp_i);

	}
	void getWeights(size_t wt_i)
	{
		fprintf(mFile,"\"%s.wt[%i]\"",mName.c_str(),wt_i);

	}
	void getKnotsU(size_t ku_i)
	{
		fprintf(mFile,"\"%s.ku[%i]\"",mName.c_str(),ku_i);

	}
	void getKnotsV(size_t kv_i)
	{
		fprintf(mFile,"\"%s.kv[%i]\"",mName.c_str(),kv_i);

	}
protected:
	SurfaceInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SURFACEINFO_H__
