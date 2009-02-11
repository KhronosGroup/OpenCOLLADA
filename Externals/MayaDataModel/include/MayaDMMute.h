/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MUTE_H__
#define __MayaDM_MUTE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Mute : public DependNode
{
public:
public:
	Mute():DependNode(){}
	Mute(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "mute"){}
	virtual ~Mute(){}
	void setMute(bool m)
	{
		if(m == false) return;
		fprintf(mFile,"\tsetAttr \".m\" %i;\n", m);

	}
	void getInput()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getHold()
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());

	}
	void getHoldTime()
	{
		fprintf(mFile,"\"%s.ht\"",mName.c_str());

	}
	void getMute()
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	Mute(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MUTE_H__
