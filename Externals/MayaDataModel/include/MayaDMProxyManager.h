/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PROXYMANAGER_H__
#define __MayaDM_PROXYMANAGER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
 A file can either have a single reference (cf TdnReference), or it can have
 a collection of references, with at most one of those references being
 loaded at any point in time. These collections of references are referred to
 as the proxies, whereas the node that manages the proxies (this node) is
 called the proxyManager.

 The proxyManager node maintains both a list of proxies that are available, as
 well as the proxy that is active (if any). Eventually, it should also
 contain various utilities for managing proxies.

</pre></p>
*/
class ProxyManager : public DependNode
{
public:
public:
	ProxyManager(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "proxyManager"){}
	virtual ~ProxyManager(){}
	/*
	This attribute is a list of messages to keep track of the set of
	proxies that are related to one another.
	*/
	void setProxyList(size_t plst_i,const MessageID& plst){fprintf_s(mFile,"connectAttr \"");plst.write(mFile);fprintf_s(mFile,"\" \"%s.plst[%i]\";\n",mName.c_str(),plst_i);}
	/*
	This attribute is used to connect a message from activeProxy to the
	entry in the proxyList that corresponds to the active proxy. We do it
	this way to avoid a fan-in connection to the activeProxy, and to avoid
	connecting from the proxyManager to the reference, and then back to the
	proxyManager.
	*/
	void setActiveProxy(const MessageID& aprx){fprintf_s(mFile,"connectAttr \"");aprx.write(mFile);fprintf_s(mFile,"\" \"%s.aprx\";\n",mName.c_str());}
	/*
	This attribute is used to keep track of the proxy that owns the edits
	in a proxy set with shared edits. In such a case, the .proxyMsg of the
	reference node that currently owns the edits is connected to this
	attribute.
	*/
	void setSharedEditsOwner(const MessageID& psed){fprintf_s(mFile,"connectAttr \"");psed.write(mFile);fprintf_s(mFile,"\" \"%s.psed\";\n",mName.c_str());}
	/*
	This attribute is a list of messages to keep track of the set of
	proxies that are related to one another.
	*/
	const MessageID& getProxyList(size_t plst_i){char buffer[4096];sprintf_s (buffer, "%s.plst[%i]",mName.c_str(),plst_i);return (const char*)buffer;}
	/*
	This attribute is used to connect a message from activeProxy to the
	entry in the proxyList that corresponds to the active proxy. We do it
	this way to avoid a fan-in connection to the activeProxy, and to avoid
	connecting from the proxyManager to the reference, and then back to the
	proxyManager.
	*/
	MessageID getActiveProxy(){char buffer[4096];sprintf_s (buffer, "%s.aprx",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is used to keep track of the proxy that owns the edits
	in a proxy set with shared edits. In such a case, the .proxyMsg of the
	reference node that currently owns the edits is connected to this
	attribute.
	*/
	MessageID getSharedEditsOwner(){char buffer[4096];sprintf_s (buffer, "%s.psed",mName.c_str());return (const char*)buffer;}
protected:
	ProxyManager(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PROXYMANAGER_H__
