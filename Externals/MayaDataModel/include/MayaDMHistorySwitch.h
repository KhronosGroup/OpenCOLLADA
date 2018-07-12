/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HISTORYSWITCH_H__
#define __MayaDM_HISTORYSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class HistorySwitch : public GeometryFilter
{
public:
public:

	HistorySwitch():GeometryFilter(){}
	HistorySwitch(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, "historySwitch", shared, create){}
	virtual ~HistorySwitch(){}

	void setPlayFromCache(bool pfc)
	{
		if(pfc == false) return;
		fprintf(mFile,"\tsetAttr \".pfc\" %i;\n", pfc);
	}
	void getUndeformedGeometry(size_t ug_i)const
	{
		fprintf(mFile,"\"%s.ug[%i]\"",mName.c_str(),ug_i);
	}
	void getUndeformedGeometry()const
	{

		fprintf(mFile,"\"%s.ug\"",mName.c_str());
	}
	void getPlayFromCache()const
	{
		fprintf(mFile,"\"%s.pfc\"",mName.c_str());
	}
	void getInPositions(size_t inp_i)const
	{
		fprintf(mFile,"\"%s.inp[%i]\"",mName.c_str(),inp_i);
	}
	void getInPositions()const
	{

		fprintf(mFile,"\"%s.inp\"",mName.c_str());
	}
	void getOutPositions(size_t op_i)const
	{
		fprintf(mFile,"\"%s.op[%i]\"",mName.c_str(),op_i);
	}
	void getOutPositions()const
	{

		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
protected:
	HistorySwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HISTORYSWITCH_H__
