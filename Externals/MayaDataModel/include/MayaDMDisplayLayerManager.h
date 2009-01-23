/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISPLAYLAYERMANAGER_H__
#define __MayaDM_DISPLAYLAYERMANAGER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DisplayLayerManager : public DependNode
{
public:
public:
	DisplayLayerManager(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "displayLayerManager"){}
	virtual ~DisplayLayerManager(){}
	void setCurrentDisplayLayer(short cdl)
	{
		if(cdl == 0) return;
		fprintf(mFile,"setAttr \".cdl\" %i;\n", cdl);

	}
	void setDisplayLayerId(size_t dli_i,short dli)
	{
		if(dli == 0) return;
		fprintf(mFile,"setAttr \".dli[%i]\" %i;\n", dli_i,dli);

	}
	void setDisplayLayerId(size_t dli_start,size_t dli_end,short* dli)
	{
		fprintf(mFile,"setAttr \".dli[%i:%i]\" ", dli_start,dli_end);
		size_t size = (dli_end-dli_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",dli[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startDisplayLayerId(size_t dli_start,size_t dli_end)
	{
		fprintf(mFile,"setAttr \".dli[%i:%i]\"",dli_start,dli_end);

	}
	void appendDisplayLayerId(short dli)
	{
		fprintf(mFile," %i",dli);

	}
	void endDisplayLayerId()
	{
		fprintf(mFile,";\n");

	}
	void getCurrentDisplayLayer()
	{
		fprintf(mFile,"\"%s.cdl\"",mName.c_str());

	}
	void getDisplayLayerId(size_t dli_i)
	{
		fprintf(mFile,"\"%s.dli[%i]\"",mName.c_str(),dli_i);

	}
protected:
	DisplayLayerManager(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DISPLAYLAYERMANAGER_H__
