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
/*
*/
class RenderGlobalsList : public DependNode
{
public:
public:
	RenderGlobalsList(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "renderGlobalsList"){}
	virtual ~RenderGlobalsList(){}
	/*Connection to this attribute means that you are a renderGlobals.*/
	void setRenderGlobals(size_t rg_i,const MessageID& rg){fprintf_s(mFile,"connectAttr \"");rg.write(mFile);fprintf_s(mFile,"\" \"%s.rg[%i]\";\n",mName.c_str(),rg_i);}
	/*Connection to this attribute means that you are a renderQuality.*/
	void setRenderQualities(size_t rq_i,const MessageID& rq){fprintf_s(mFile,"connectAttr \"");rq.write(mFile);fprintf_s(mFile,"\" \"%s.rq[%i]\";\n",mName.c_str(),rq_i);}
	/*Connection to this attribute means that you are a renderResolution.*/
	void setRenderResolutions(size_t rr_i,const MessageID& rr){fprintf_s(mFile,"connectAttr \"");rr.write(mFile);fprintf_s(mFile,"\" \"%s.rr[%i]\";\n",mName.c_str(),rr_i);}
	/*Connection to this attribute means that you are a renderGlobals.*/
	const MessageID& getRenderGlobals(size_t rg_i){char buffer[4096];sprintf_s (buffer, "%s.rg[%i]",mName.c_str(),rg_i);return (const char*)buffer;}
	/*Connection to this attribute means that you are a renderQuality.*/
	const MessageID& getRenderQualities(size_t rq_i){char buffer[4096];sprintf_s (buffer, "%s.rq[%i]",mName.c_str(),rq_i);return (const char*)buffer;}
	/*Connection to this attribute means that you are a renderResolution.*/
	const MessageID& getRenderResolutions(size_t rr_i){char buffer[4096];sprintf_s (buffer, "%s.rr[%i]",mName.c_str(),rr_i);return (const char*)buffer;}
protected:
	RenderGlobalsList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RENDERGLOBALSLIST_H__
