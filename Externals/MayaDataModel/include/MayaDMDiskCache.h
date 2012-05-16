/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISKCACHE_H__
#define __MayaDM_DISKCACHE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DiskCache : public DependNode
{
public:
public:

	DiskCache():DependNode(){}
	DiskCache(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "diskCache", shared, create){}
	virtual ~DiskCache(){}

	void setEnable(bool ebl)
	{
		if(ebl == true) return;
		fprintf(mFile,"\tsetAttr \".ebl\" %i;\n", ebl);
	}
	void setCacheName(const string& cn)
	{
		if(cn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cn\" -type \"string\" ");
		cn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCacheType(const string& ct)
	{
		if(ct == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ct\" -type \"string\" ");
		ct.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHiddenCacheName(const string& hcn)
	{
		if(hcn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".hcn\" -type \"string\" ");
		hcn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCopyLocally(bool cpl)
	{
		if(cpl == true) return;
		fprintf(mFile,"\tsetAttr \".cpl\" %i;\n", cpl);
	}
	void getDiskCache()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getEnable()const
	{
		fprintf(mFile,"\"%s.ebl\"",mName.c_str());
	}
	void getCacheName()const
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());
	}
	void getStartTime()const
	{
		fprintf(mFile,"\"%s.stim\"",mName.c_str());
	}
	void getEndTime()const
	{
		fprintf(mFile,"\"%s.etim\"",mName.c_str());
	}
	void getSamplingType()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getSamplingRate()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getCacheType()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getHiddenCacheName()const
	{
		fprintf(mFile,"\"%s.hcn\"",mName.c_str());
	}
	void getCopyLocally()const
	{
		fprintf(mFile,"\"%s.cpl\"",mName.c_str());
	}
protected:
	DiskCache(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DISKCACHE_H__
