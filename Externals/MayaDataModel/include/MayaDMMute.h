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
	Mute(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "mute", shared, create){}
	virtual ~Mute(){}

	void setHoldTime(double ht)
	{
		if(ht == 0) return;
		fprintf(mFile,"\tsetAttr \".ht\" %f;\n", ht);
	}
	void setMute(bool m)
	{
		if(m == false) return;
		fprintf(mFile,"\tsetAttr \".m\" %i;\n", m);
	}
	void getInput()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getHold()const
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getHoldTime()const
	{
		fprintf(mFile,"\"%s.ht\"",mName.c_str());
	}
	void getMute()const
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	Mute(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MUTE_H__
