/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FRAMECACHE_H__
#define __MayaDM_FRAMECACHE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class FrameCache : public DependNode
{
public:
public:

	FrameCache():DependNode(){}
	FrameCache(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "frameCache", shared, create){}
	virtual ~FrameCache(){}

	void setVaryTime(double vt)
	{
		if(vt == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt\" %f;\n", vt);
	}
	void setStream(double s)
	{
		if(s == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void getFuture(size_t f_i)const
	{
		fprintf(mFile,"\"%s.f[%i]\"",mName.c_str(),f_i);
	}
	void getFuture()const
	{

		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getPast(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);
	}
	void getPast()const
	{

		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getVarying()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getVaryTime()const
	{
		fprintf(mFile,"\"%s.vt\"",mName.c_str());
	}
	void getStream()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
protected:
	FrameCache(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FRAMECACHE_H__
