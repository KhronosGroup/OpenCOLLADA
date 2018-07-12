/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Chooser():DependNode(){}
	Chooser(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "chooser", shared, create){}
	virtual ~Chooser(){}

	void setInLevel(size_t il_i,bool il)
	{
		if(il == false) return;
		fprintf(mFile,"\tsetAttr \".il[%i]\" %i;\n", il_i,il);
	}
	void setInLevel(size_t il_start,size_t il_end,bool* il)
	{
		fprintf(mFile,"\tsetAttr \".il[%i:%i]\" ", il_start,il_end);
		size_t size = (il_end-il_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",il[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startInLevel(size_t il_start,size_t il_end)const
	{
		fprintf(mFile,"\tsetAttr \".il[%i:%i]\"",il_start,il_end);
	}
	void appendInLevel(bool il)const
	{
		fprintf(mFile," %i",il);
	}
	void endInLevel()const
	{
		fprintf(mFile,";\n");
	}
	void setDisplayLevel(size_t dl_i,unsigned int dl)
	{
		if(dl == 0) return;
		fprintf(mFile,"\tsetAttr \".dl[%i]\" %i;\n", dl_i,dl);
	}
	void setDisplayLevel(size_t dl_start,size_t dl_end,unsigned int* dl)
	{
		fprintf(mFile,"\tsetAttr \".dl[%i:%i]\" ", dl_start,dl_end);
		size_t size = (dl_end-dl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",dl[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startDisplayLevel(size_t dl_start,size_t dl_end)const
	{
		fprintf(mFile,"\tsetAttr \".dl[%i:%i]\"",dl_start,dl_end);
	}
	void appendDisplayLevel(unsigned int dl)const
	{
		fprintf(mFile," %i",dl);
	}
	void endDisplayLevel()const
	{
		fprintf(mFile,";\n");
	}
	void getInLevel(size_t il_i)const
	{
		fprintf(mFile,"\"%s.il[%i]\"",mName.c_str(),il_i);
	}
	void getInLevel()const
	{

		fprintf(mFile,"\"%s.il\"",mName.c_str());
	}
	void getDisplayLevel(size_t dl_i)const
	{
		fprintf(mFile,"\"%s.dl[%i]\"",mName.c_str(),dl_i);
	}
	void getDisplayLevel()const
	{

		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getOutput(size_t o_i)const
	{
		fprintf(mFile,"\"%s.o[%i]\"",mName.c_str(),o_i);
	}
	void getOutput()const
	{

		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	Chooser(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CHOOSER_H__
