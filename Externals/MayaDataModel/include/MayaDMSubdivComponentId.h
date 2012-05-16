/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	SubdivComponentId():DependNode(){}
	SubdivComponentId(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "subdivComponentId", shared, create){}
	virtual ~SubdivComponentId(){}

	void setInBase(int ib)
	{
		if(ib == 0) return;
		fprintf(mFile,"\tsetAttr \".ib\" %i;\n", ib);
	}
	void setInEdge(int ie)
	{
		if(ie == 0) return;
		fprintf(mFile,"\tsetAttr \".ie\" %i;\n", ie);
	}
	void setInLevel(unsigned int il)
	{
		if(il == 0) return;
		fprintf(mFile,"\tsetAttr \".il\" %i;\n", il);
	}
	void setInPath(int ip)
	{
		if(ip == 0) return;
		fprintf(mFile,"\tsetAttr \".ip\" %i;\n", ip);
	}
	void setInFinal(unsigned int if_)
	{
		if(if_ == 0) return;
		fprintf(mFile,"\tsetAttr \".if\" %i;\n", if_);
	}
	void setInLeft(int ilt)
	{
		if(ilt == 0) return;
		fprintf(mFile,"\tsetAttr \".ilt\" %i;\n", ilt);
	}
	void setInRight(int ir)
	{
		if(ir == 0) return;
		fprintf(mFile,"\tsetAttr \".ir\" %i;\n", ir);
	}
	void getInBase()const
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());
	}
	void getInEdge()const
	{
		fprintf(mFile,"\"%s.ie\"",mName.c_str());
	}
	void getInLevel()const
	{
		fprintf(mFile,"\"%s.il\"",mName.c_str());
	}
	void getInPath()const
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());
	}
	void getInFinal()const
	{
		fprintf(mFile,"\"%s.if\"",mName.c_str());
	}
	void getOutLeft()const
	{
		fprintf(mFile,"\"%s.olt\"",mName.c_str());
	}
	void getOutRight()const
	{
		fprintf(mFile,"\"%s.or\"",mName.c_str());
	}
	void getInLeft()const
	{
		fprintf(mFile,"\"%s.ilt\"",mName.c_str());
	}
	void getInRight()const
	{
		fprintf(mFile,"\"%s.ir\"",mName.c_str());
	}
	void getOutBase()const
	{
		fprintf(mFile,"\"%s.ob\"",mName.c_str());
	}
	void getOutEdge()const
	{
		fprintf(mFile,"\"%s.oe\"",mName.c_str());
	}
	void getOutLevel()const
	{
		fprintf(mFile,"\"%s.ol\"",mName.c_str());
	}
	void getOutPath()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getOutFinal()const
	{
		fprintf(mFile,"\"%s.of\"",mName.c_str());
	}
protected:
	SubdivComponentId(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVCOMPONENTID_H__
