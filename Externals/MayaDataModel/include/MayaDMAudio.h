/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AUDIO_H__
#define __MayaDM_AUDIO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Audio : public DependNode
{
public:
public:
	Audio():DependNode(){}
	Audio(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "audio"){}
	virtual ~Audio(){}
	void setFilename(const string& f)
	{
		if(f == "NULL") return;
		fprintf(mFile,"\tsetAttr \".f\" -type \"string\" ");
		f.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOrder(int r)
	{
		if(r == 1) return;
		fprintf(mFile,"\tsetAttr \".r\" %i;\n", r);

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getFilename()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getOrder()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
protected:
	Audio(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_AUDIO_H__
