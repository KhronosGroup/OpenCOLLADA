/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERGLOBALSLIST_H__
#define __MayaDM_RENDERGLOBALSLIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RenderGlobalsList : public DependNode
{
public:
public:
	RenderGlobalsList(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "renderGlobalsList"){}
	virtual ~RenderGlobalsList(){}
	void getRenderGlobals(size_t rg_i)
	{
		fprintf(mFile,"\"%s.rg[%i]\"",mName.c_str(),rg_i);

	}
	void getRenderQualities(size_t rq_i)
	{
		fprintf(mFile,"\"%s.rq[%i]\"",mName.c_str(),rq_i);

	}
	void getRenderResolutions(size_t rr_i)
	{
		fprintf(mFile,"\"%s.rr[%i]\"",mName.c_str(),rr_i);

	}
protected:
	RenderGlobalsList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERGLOBALSLIST_H__
