/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHARACTERMAP_H__
#define __MayaDM_CHARACTERMAP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class CharacterMap : public DependNode
{
public:
public:

	CharacterMap():DependNode(){}
	CharacterMap(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "characterMap", shared, create){}
	virtual ~CharacterMap(){}

	void setMemberIndex(size_t mi_i,const intArray& mi)
	{
		if(mi.size == 0) return;
		fprintf(mFile,"\tsetAttr \".mi[%i]\" -type \"intArray\" ",mi_i);
		mi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMemberIndex(size_t mi_start,size_t mi_end,intArray* mi)
	{
		fprintf(mFile,"\tsetAttr \".mi[%i:%i]\" ", mi_start,mi_end);
		size_t size = (mi_end-mi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			mi[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startMemberIndex(size_t mi_start,size_t mi_end)const
	{
		fprintf(mFile,"\tsetAttr \".mi[%i:%i]\"",mi_start,mi_end);
		fprintf(mFile," -type \"intArray\" ");
	}
	void appendMemberIndex(const intArray& mi)const
	{
		fprintf(mFile," ");
		mi.write(mFile);
	}
	void endMemberIndex()const
	{
		fprintf(mFile,";\n");
	}
	void getMember(size_t m_i)const
	{
		fprintf(mFile,"\"%s.m[%i]\"",mName.c_str(),m_i);
	}
	void getMember()const
	{

		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
protected:
	CharacterMap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CHARACTERMAP_H__
