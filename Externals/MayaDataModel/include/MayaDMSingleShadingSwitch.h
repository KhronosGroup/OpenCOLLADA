/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SINGLESHADINGSWITCH_H__
#define __MayaDM_SINGLESHADINGSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseShadingSwitch.h"
namespace MayaDM
{
class SingleShadingSwitch : public BaseShadingSwitch
{
public:
	struct Input{
		float inSingle;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", inSingle);
		}
	};
public:

	SingleShadingSwitch():BaseShadingSwitch(){}
	SingleShadingSwitch(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:BaseShadingSwitch(file, name, parent, "singleShadingSwitch", shared, create){}
	virtual ~SingleShadingSwitch(){}

	void setInput(size_t i_i,const Input& i_)
	{
		fprintf(mFile,"\tsetAttr \".i[%i]\" ",i_i);
		i_.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInput(size_t i_start,size_t i_end,Input* i_)
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\" ", i_start,i_end);
		size_t size = (i_end-i_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			i_[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInput(size_t i_start,size_t i_end)const
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\"",i_start,i_end);
		fprintf(mFile," -type \"Input\" ");
	}
	void appendInput(const Input& i)const
	{
		fprintf(mFile," ");
		i.write(mFile);
	}
	void endInput()const
	{
		fprintf(mFile,";\n");
	}
	void setInSingle(size_t i_i,float it)
	{
		if(it == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].it\" %f;\n", i_i,it);
	}
	void setDefault(float def)
	{
		if(def == 0.0) return;
		fprintf(mFile,"\tsetAttr \".def\" %f;\n", def);
	}
	void getInput(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);
	}
	void getInput()const
	{

		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getInSingle(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].it\"",mName.c_str(),i_i);
	}
	void getInSingle()const
	{

		fprintf(mFile,"\"%s.i.it\"",mName.c_str());
	}
	void getInShape(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].is\"",mName.c_str(),i_i);
	}
	void getInShape()const
	{

		fprintf(mFile,"\"%s.i.is\"",mName.c_str());
	}
	void getDefault()const
	{
		fprintf(mFile,"\"%s.def\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());
	}
protected:
	SingleShadingSwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:BaseShadingSwitch(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SINGLESHADINGSWITCH_H__
