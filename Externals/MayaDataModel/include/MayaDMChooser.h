/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHOOSER_H__
#define __MayaDM_CHOOSER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Chooser : public DependNode
{
public:
public:
	Chooser(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "chooser"){}
	virtual ~Chooser(){}
	void setInLevel(size_t il_i,bool il)
	{
		if(il == false) return;
		fprintf(mFile,"setAttr \".il[%i]\" %i;\n", il_i,il);

	}
	void setDisplayLevel(size_t dl_i,unsigned int dl)
	{
		if(dl == 0) return;
		fprintf(mFile,"setAttr \".dl[%i]\" %i;\n", dl_i,dl);

	}
	void getInLevel(size_t il_i)
	{
		fprintf(mFile,"\"%s.il[%i]\"",mName.c_str(),il_i);

	}
	void getDisplayLevel(size_t dl_i)
	{
		fprintf(mFile,"\"%s.dl[%i]\"",mName.c_str(),dl_i);

	}
	void getOutput(size_t o_i)
	{
		fprintf(mFile,"\"%s.o[%i]\"",mName.c_str(),o_i);

	}
protected:
	Chooser(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CHOOSER_H__
