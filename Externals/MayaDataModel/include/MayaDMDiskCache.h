/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	DiskCache(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "diskCache"){}
	virtual ~DiskCache(){}
	void setEnable(bool ebl)
	{
		if(ebl == true) return;
		fprintf(mFile,"setAttr \".ebl\" %i;\n", ebl);

	}
	void setCacheName(const string& cn)
	{
		if(cn == "NULL") return;
		fprintf(mFile,"setAttr \".cn\" -type \"string\" ");
		cn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCacheType(const string& ct)
	{
		if(ct == "NULL") return;
		fprintf(mFile,"setAttr \".ct\" -type \"string\" ");
		ct.write(mFile);
		fprintf(mFile,";\n");

	}
	void setHiddenCacheName(const string& hcn)
	{
		if(hcn == "NULL") return;
		fprintf(mFile,"setAttr \".hcn\" -type \"string\" ");
		hcn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCopyLocally(bool cpl)
	{
		if(cpl == true) return;
		fprintf(mFile,"setAttr \".cpl\" %i;\n", cpl);

	}
	void getDiskCache()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getEnable()
	{
		fprintf(mFile,"\"%s.ebl\"",mName.c_str());

	}
	void getCacheName()
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());

	}
	void getStartTime()
	{
		fprintf(mFile,"\"%s.stim\"",mName.c_str());

	}
	void getEndTime()
	{
		fprintf(mFile,"\"%s.etim\"",mName.c_str());

	}
	void getSamplingType()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getSamplingRate()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getCacheType()
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());

	}
	void getHiddenCacheName()
	{
		fprintf(mFile,"\"%s.hcn\"",mName.c_str());

	}
	void getCopyLocally()
	{
		fprintf(mFile,"\"%s.cpl\"",mName.c_str());

	}
protected:
	DiskCache(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DISKCACHE_H__
