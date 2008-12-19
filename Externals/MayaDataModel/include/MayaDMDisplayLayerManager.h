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
