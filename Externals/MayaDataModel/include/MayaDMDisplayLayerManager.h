/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	DisplayLayerManager():DependNode(){}
	DisplayLayerManager(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "displayLayerManager", shared, create){}
	virtual ~DisplayLayerManager(){}

	void setCurrentDisplayLayer(short cdl)
	{
		if(cdl == 0) return;
		fprintf(mFile,"\tsetAttr \".cdl\" %i;\n", cdl);
	}
	void setDisplayLayerId(size_t dli_i,short dli)
	{
		if(dli == 0) return;
		fprintf(mFile,"\tsetAttr \".dli[%i]\" %i;\n", dli_i,dli);
	}
	void setDisplayLayerId(size_t dli_start,size_t dli_end,short* dli)
	{
		fprintf(mFile,"\tsetAttr \".dli[%i:%i]\" ", dli_start,dli_end);
		size_t size = (dli_end-dli_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",dli[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startDisplayLayerId(size_t dli_start,size_t dli_end)const
	{
		fprintf(mFile,"\tsetAttr \".dli[%i:%i]\"",dli_start,dli_end);
	}
	void appendDisplayLayerId(short dli)const
	{
		fprintf(mFile," %i",dli);
	}
	void endDisplayLayerId()const
	{
		fprintf(mFile,";\n");
	}
	void getCurrentDisplayLayer()const
	{
		fprintf(mFile,"\"%s.cdl\"",mName.c_str());
	}
	void getDisplayLayerId(size_t dli_i)const
	{
		fprintf(mFile,"\"%s.dli[%i]\"",mName.c_str(),dli_i);
	}
	void getDisplayLayerId()const
	{

		fprintf(mFile,"\"%s.dli\"",mName.c_str());
	}
protected:
	DisplayLayerManager(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DISPLAYLAYERMANAGER_H__
