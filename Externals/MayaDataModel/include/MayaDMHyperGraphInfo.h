/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HYPERGRAPHINFO_H__
#define __MayaDM_HYPERGRAPHINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node represents Hypergraph bookmark information.
        Specifically, it saves information on the connections to the Hypergraph
        view bookmarks.  <p/>
*/
class HyperGraphInfo : public DependNode
{
public:
public:
	HyperGraphInfo(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hyperGraphInfo"){}
	virtual ~HyperGraphInfo(){}
	/*Bookmarks for HyperGraph views*/
	void setBookmarks(size_t b_i,const MessageID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b[%i]\";\n",mName.c_str(),b_i);}
	/*Bookmarks for HyperGraph views*/
	const MessageID& getBookmarks(size_t b_i){char buffer[4096];sprintf_s (buffer, "%s.b[%i]",mName.c_str(),b_i);return (const char*)buffer;}
protected:
	HyperGraphInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HYPERGRAPHINFO_H__
