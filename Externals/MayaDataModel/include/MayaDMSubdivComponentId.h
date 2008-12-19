/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVCOMPONENTID_H__
#define __MayaDM_SUBDIVCOMPONENTID_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SubdivComponentId : public DependNode
{
public:
public:
	SubdivComponentId(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdivComponentId"){}
	virtual ~SubdivComponentId(){}
	void setInBase(int ib)
	{
		if(ib == 0) return;
		fprintf(mFile,"setAttr \".ib\" %i;\n", ib);

	}
	void setInEdge(int ie)
	{
		if(ie == 0) return;
		fprintf(mFile,"setAttr \".ie\" %i;\n", ie);

	}
	void setInLevel(unsigned int il)
	{
		if(il == 0) return;
		fprintf(mFile,"setAttr \".il\" %i;\n", il);

	}
	void setInPath(int ip)
	{
		if(ip == 0) return;
		fprintf(mFile,"setAttr \".ip\" %i;\n", ip);

	}
	void setInFinal(unsigned int if_)
	{
		if(if_ == 0) return;
		fprintf(mFile,"setAttr \".if\" %i;\n", if_);

	}
	void setInLeft(int ilt)
	{
		if(ilt == 0) return;
		fprintf(mFile,"setAttr \".ilt\" %i;\n", ilt);

	}
	void setInRight(int ir)
	{
		if(ir == 0) return;
		fprintf(mFile,"setAttr \".ir\" %i;\n", ir);

	}
	void getInBase()
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());

	}
	void getInEdge()
	{
		fprintf(mFile,"\"%s.ie\"",mName.c_str());

	}
	void getInLevel()
	{
		fprintf(mFile,"\"%s.il\"",mName.c_str());

	}
	void getInPath()
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());

	}
	void getInFinal()
	{
		fprintf(mFile,"\"%s.if\"",mName.c_str());

	}
	void getOutLeft()
	{
		fprintf(mFile,"\"%s.olt\"",mName.c_str());

	}
	void getOutRight()
	{
		fprintf(mFile,"\"%s.or\"",mName.c_str());

	}
	void getInLeft()
	{
		fprintf(mFile,"\"%s.ilt\"",mName.c_str());

	}
	void getInRight()
	{
		fprintf(mFile,"\"%s.ir\"",mName.c_str());

	}
	void getOutBase()
	{
		fprintf(mFile,"\"%s.ob\"",mName.c_str());

	}
	void getOutEdge()
	{
		fprintf(mFile,"\"%s.oe\"",mName.c_str());

	}
	void getOutLevel()
	{
		fprintf(mFile,"\"%s.ol\"",mName.c_str());

	}
	void getOutPath()
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());

	}
	void getOutFinal()
	{
		fprintf(mFile,"\"%s.of\"",mName.c_str());

	}
protected:
	SubdivComponentId(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVCOMPONENTID_H__
