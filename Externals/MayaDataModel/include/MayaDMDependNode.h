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
public:
	const std::string& getName()
	{
		return mName;
	}
	const std::string& getParent()
	{
		return mParent;
	}
	const std::string& getType()
	{
		return mNodeType;
	}
	void setName(const std::string& name)
	{
		mName = name;
	}
	void setParent(const std::string& parent)
	{
		mParent = parent;
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
	void getMessage()
	{
		fprintf(mFile,"\"%s.msg\"",mName.c_str());

	}
	void getIsHistoricallyInteresting()
	{
		fprintf(mFile,"\"%s.ihi\"",mName.c_str());

	}
	void getCaching()
	{
		fprintf(mFile,"\"%s.cch\"",mName.c_str());

	}
	void getNodeState()
	{
		fprintf(mFile,"\"%s.nds\"",mName.c_str());

	}
protected:
	DependNode(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:mFile(file), mName(name), mParent(parent), mNodeType(nodeType)
	{
		createNode();
	}
private:
	void createNode()
	{
		fprintf(mFile, "createNode %s -n \"%s\"", mNodeType.c_str(),mName.c_str());
		if(mParent != "") 
			fprintf(mFile, " -p \"%s\"", mParent.c_str());
		fprintf(mFile, ";\n");
	}

};
}//namespace MayaDM
#endif//__MayaDM_DEPENDNODE_H__
