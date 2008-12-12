/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NETWORK_H__
#define __MayaDM_NETWORK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    Represents an "affects" relationship between two objects.  Each object is
    represented by a node of this type and a connection between the nodes mean
    that one object affects the other.  Connection A -> B will represent the
    notion that object A affects object B.
</pre></p>
*/
class Network : public DependNode
{
public:
public:
	Network(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "network"){}
	virtual ~Network(){}
	/*Output that leads to things that this node affects*/
	void setAffects(size_t a_i,const MessageID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a[%i]\";\n",mName.c_str(),a_i);}
	/*Input that leads from things that this node is affected by*/
	void setAffectedBy(size_t ab_i,const MessageID& ab){fprintf_s(mFile,"connectAttr \"");ab.write(mFile);fprintf_s(mFile,"\" \"%s.ab[%i]\";\n",mName.c_str(),ab_i);}
	/*Output that leads to things that this node affects*/
	const MessageID& getAffects(size_t a_i){char buffer[4096];sprintf_s (buffer, "%s.a[%i]",mName.c_str(),a_i);return (const char*)buffer;}
	/*Input that leads from things that this node is affected by*/
	const MessageID& getAffectedBy(size_t ab_i){char buffer[4096];sprintf_s (buffer, "%s.ab[%i]",mName.c_str(),ab_i);return (const char*)buffer;}
protected:
	Network(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NETWORK_H__
