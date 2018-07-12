/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	RenderGlobalsList():DependNode(){}
	RenderGlobalsList(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "renderGlobalsList", shared, create){}
	virtual ~RenderGlobalsList(){}

	void getRenderGlobals(size_t rg_i)const
	{
		fprintf(mFile,"\"%s.rg[%i]\"",mName.c_str(),rg_i);
	}
	void getRenderGlobals()const
	{

		fprintf(mFile,"\"%s.rg\"",mName.c_str());
	}
	void getRenderQualities(size_t rq_i)const
	{
		fprintf(mFile,"\"%s.rq[%i]\"",mName.c_str(),rq_i);
	}
	void getRenderQualities()const
	{

		fprintf(mFile,"\"%s.rq\"",mName.c_str());
	}
	void getRenderResolutions(size_t rr_i)const
	{
		fprintf(mFile,"\"%s.rr[%i]\"",mName.c_str(),rr_i);
	}
	void getRenderResolutions()const
	{

		fprintf(mFile,"\"%s.rr\"",mName.c_str());
	}
protected:
	RenderGlobalsList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERGLOBALSLIST_H__
