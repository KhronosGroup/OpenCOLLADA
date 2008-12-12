/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEPENDNODE_H__
#define __MayaDM_DEPENDNODE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
namespace MayaDM
{
/*
The base dependency node.  Implements default behaviour for the operation
 of the dependency graph.
*/
class DependNode
{
public:
protected:
	FILE* mFile;
	std::string mName;
	std::string mParent;
	std::string mNodeType;
public:
	const std::string& getName(){return mName;}
	const std::string& getParent(){return mParent;}
	const std::string& getType(){return mNodeType;}
public:
		virtual ~DependNode(){}
	/*Messaging attribute.  For connecting without dataflow.*/
	void setMessage(const MessageID& msg){fprintf_s(mFile,"connectAttr \"");msg.write(mFile);fprintf_s(mFile,"\" \"%s.msg\";\n",mName.c_str());}
	/*Defines whether a particular node is useful for construction history*/
	void setIsHistoricallyInteresting(unsigned char ihi){if(ihi == 2) return; fprintf_s(mFile, "setAttr \".ihi\" %i;\n", ihi);}
	/*Defines whether a particular node is useful for construction history*/
	void setIsHistoricallyInteresting(const UnsignedcharID& ihi){fprintf_s(mFile,"connectAttr \"");ihi.write(mFile);fprintf_s(mFile,"\" \"%s.ihi\";\n",mName.c_str());}
	/*Toggle caching for all attributes so that no recomputation is needed*/
	void setCaching(bool cch){if(cch == false) return; fprintf_s(mFile, "setAttr \".cch\" %i;\n", cch);}
	/*Toggle caching for all attributes so that no recomputation is needed*/
	void setCaching(const BoolID& cch){fprintf_s(mFile,"connectAttr \"");cch.write(mFile);fprintf_s(mFile,"\" \"%s.cch\";\n",mName.c_str());}
	/*
	Defines how to evaluate the node.  0=Normal, 1=PassThrough, 2=Blocking
	3=Internally disabled.  Will return to Normal state when enabled.
	4=Internally disabled.  Will return to PassThrough state when enabled.
	5=Internally disabled.  Will return to Blocking state when enabled.
	*/
	void setNodeState(unsigned int nds){if(nds == 0) return; fprintf_s(mFile, "setAttr \".nds\" %i;\n", nds);}
	/*
	Defines how to evaluate the node.  0=Normal, 1=PassThrough, 2=Blocking
	3=Internally disabled.  Will return to Normal state when enabled.
	4=Internally disabled.  Will return to PassThrough state when enabled.
	5=Internally disabled.  Will return to Blocking state when enabled.
	*/
	void setNodeState(const UnsignedintID& nds){fprintf_s(mFile,"connectAttr \"");nds.write(mFile);fprintf_s(mFile,"\" \"%s.nds\";\n",mName.c_str());}
	/*List of bins that the node belongs to*/
	void setBinMembership(const string& bnm){if(bnm == "NULL") return; fprintf_s(mFile, "setAttr \".bnm\" -type \"string\" ");bnm.write(mFile);fprintf_s(mFile,";\n");}
	/*Messaging attribute.  For connecting without dataflow.*/
	MessageID getMessage(){char buffer[4096];sprintf_s (buffer, "%s.msg",mName.c_str());return (const char*)buffer;}
	/*Defines whether a particular node is useful for construction history*/
	UnsignedcharID getIsHistoricallyInteresting(){char buffer[4096];sprintf_s (buffer, "%s.ihi",mName.c_str());return (const char*)buffer;}
	/*Toggle caching for all attributes so that no recomputation is needed*/
	BoolID getCaching(){char buffer[4096];sprintf_s (buffer, "%s.cch",mName.c_str());return (const char*)buffer;}
	/*
	Defines how to evaluate the node.  0=Normal, 1=PassThrough, 2=Blocking
	3=Internally disabled.  Will return to Normal state when enabled.
	4=Internally disabled.  Will return to PassThrough state when enabled.
	5=Internally disabled.  Will return to Blocking state when enabled.
	*/
	UnsignedintID getNodeState(){char buffer[4096];sprintf_s (buffer, "%s.nds",mName.c_str());return (const char*)buffer;}
protected:
	DependNode(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):mFile(file), mName(name), mParent(parent), mNodeType(nodeType){createNode();}
private:
	void createNode(){fprintf_s(mFile, "createNode %s -n \"%s\"", mNodeType.c_str(),mName.c_str());if(mParent != "") fprintf_s(mFile, " -p \"%s\"", mParent.c_str());fprintf_s(mFile, ";\n");}

};
}//namespace MayaDM
#endif//__MayaDM_DEPENDNODE_H__
