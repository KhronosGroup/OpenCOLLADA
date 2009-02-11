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
	FrameCache(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "frameCache"){}
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
	void getFuture(size_t f_i)
	{
		fprintf(mFile,"\"%s.f[%i]\"",mName.c_str(),f_i);

	}
	void getPast(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);

	}
	void getVarying()
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());

	}
	void getVaryTime()
	{
		fprintf(mFile,"\"%s.vt\"",mName.c_str());

	}
	void getStream()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
protected:
	FrameCache(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FRAMECACHE_H__
