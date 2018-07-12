/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	SurfaceInfo():AbstractBaseCreate(){}
	SurfaceInfo(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "surfaceInfo", shared, create){}
	virtual ~SurfaceInfo(){}

	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getControlPoints(size_t cp_i)const
	{
		fprintf(mFile,"\"%s.cp[%i]\"",mName.c_str(),cp_i);
	}
	void getControlPoints()const
	{

		fprintf(mFile,"\"%s.cp\"",mName.c_str());
	}
	void getXValue(size_t cp_i)const
	{
		fprintf(mFile,"\"%s.cp[%i].xv\"",mName.c_str(),cp_i);
	}
	void getXValue()const
	{

		fprintf(mFile,"\"%s.cp.xv\"",mName.c_str());
	}
	void getYValue(size_t cp_i)const
	{
		fprintf(mFile,"\"%s.cp[%i].yv\"",mName.c_str(),cp_i);
	}
	void getYValue()const
	{

		fprintf(mFile,"\"%s.cp.yv\"",mName.c_str());
	}
	void getZValue(size_t cp_i)const
	{
		fprintf(mFile,"\"%s.cp[%i].zv\"",mName.c_str(),cp_i);
	}
	void getZValue()const
	{

		fprintf(mFile,"\"%s.cp.zv\"",mName.c_str());
	}
	void getWeights(size_t wt_i)const
	{
		fprintf(mFile,"\"%s.wt[%i]\"",mName.c_str(),wt_i);
	}
	void getWeights()const
	{

		fprintf(mFile,"\"%s.wt\"",mName.c_str());
	}
	void getKnotsU(size_t ku_i)const
	{
		fprintf(mFile,"\"%s.ku[%i]\"",mName.c_str(),ku_i);
	}
	void getKnotsU()const
	{

		fprintf(mFile,"\"%s.ku\"",mName.c_str());
	}
	void getKnotsV(size_t kv_i)const
	{
		fprintf(mFile,"\"%s.kv[%i]\"",mName.c_str(),kv_i);
	}
	void getKnotsV()const
	{

		fprintf(mFile,"\"%s.kv\"",mName.c_str());
	}
protected:
	SurfaceInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SURFACEINFO_H__
