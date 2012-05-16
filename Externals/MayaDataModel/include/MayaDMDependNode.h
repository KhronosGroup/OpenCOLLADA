/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class DependNode
{
public:
public:
protected:
	FILE* mFile;
	std::string mName;
	std::string mParent;
	std::string mNodeType;
	bool mShared;
public:
	const std::string& getName()const
	{
		return mName;
	}
	const std::string& getParent()const
	{
		return mParent;
	}
	bool getShared()const
	{
		return mShared;
	}
	const std::string& getType()const
	{
		return mNodeType;
	}
	void setFile(FILE* file)
	{
		mFile = file;
	}
	void setName(const std::string& name)
	{
		mName = name;
	}
	void setParent(const std::string& parent)
	{
		mParent = parent;
	}
	void setShared(bool shared)
	{
		mShared = shared;
	}
public:

	DependNode(){}
	virtual ~DependNode(){}

	void setIsHistoricallyInteresting(unsigned char ihi)
	{
		if(ihi == 2) return;
		fprintf(mFile,"\tsetAttr \".ihi\" %i;\n", ihi);
	}
	void setCaching(bool cch)
	{
		if(cch == false) return;
		fprintf(mFile,"\tsetAttr \".cch\" %i;\n", cch);
	}
	void setNodeState(unsigned int nds)
	{
		if(nds == 0) return;
		fprintf(mFile,"\tsetAttr \".nds\" %i;\n", nds);
	}
	void setBinMembership(const string& bnm)
	{
		if(bnm == "NULL") return;
		fprintf(mFile,"\tsetAttr \".bnm\" -type \"string\" ");
		bnm.write(mFile);
		fprintf(mFile,";\n");
	}
	void getMessage()const
	{
		fprintf(mFile,"\"%s.msg\"",mName.c_str());
	}
	void getIsHistoricallyInteresting()const
	{
		fprintf(mFile,"\"%s.ihi\"",mName.c_str());
	}
	void getCaching()const
	{
		fprintf(mFile,"\"%s.cch\"",mName.c_str());
	}
	void getNodeState()const
	{
		fprintf(mFile,"\"%s.nds\"",mName.c_str());
	}
protected:
	DependNode(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:mFile(file), mName(name), mParent(parent), mNodeType(nodeType), mShared(shared) 
	{
		if(create)
			createNode();
	}
private:
	void createNode()const
	{
		if(mShared)
			fprintf(mFile, "createNode %s -s -n \"%s\"", mNodeType.c_str(),mName.c_str());
		else
			fprintf(mFile, "createNode %s -n \"%s\"", mNodeType.c_str(),mName.c_str());
		if(mParent != "") 
			fprintf(mFile, " -p \"%s\"", mParent.c_str());
		fprintf(mFile, ";\n");
	}

};
}//namespace MayaDM
#endif//__MayaDM_DEPENDNODE_H__
