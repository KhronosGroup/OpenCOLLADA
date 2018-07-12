/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRIPLESHADINGSWITCH_H__
#define __MayaDM_TRIPLESHADINGSWITCH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseShadingSwitch.h"
namespace MayaDM
{
class TripleShadingSwitch : public BaseShadingSwitch
{
public:
	struct Input{
		float3 inTriple;
		void write(FILE* file) const
		{
			inTriple.write(file);
			fprintf(file, " ");
		}
	};
public:

	TripleShadingSwitch():BaseShadingSwitch(){}
	TripleShadingSwitch(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:BaseShadingSwitch(file, name, parent, "tripleShadingSwitch", shared, create){}
	virtual ~TripleShadingSwitch(){}

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
	void setInTriple(size_t i_i,const float3& it)
	{
		fprintf(mFile,"\tsetAttr \".i[%i].it\" -type \"float3\" ",i_i);
		it.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInComp1(size_t i_i,float ic1)
	{
		if(ic1 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].it.ic1\" %f;\n", i_i,ic1);
	}
	void setInComp2(size_t i_i,float ic2)
	{
		if(ic2 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].it.ic2\" %f;\n", i_i,ic2);
	}
	void setInComp3(size_t i_i,float ic3)
	{
		if(ic3 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].it.ic3\" %f;\n", i_i,ic3);
	}
	void setDefault(const float3& def)
	{
		if(def == float3(0.8f,0.8f,0.8f)) return;
		fprintf(mFile,"\tsetAttr \".def\" -type \"float3\" ");
		def.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDefComp1(float dc1)
	{
		if(dc1 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".def.dc1\" %f;\n", dc1);
	}
	void setDefComp2(float dc2)
	{
		if(dc2 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".def.dc2\" %f;\n", dc2);
	}
	void setDefComp3(float dc3)
	{
		if(dc3 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".def.dc3\" %f;\n", dc3);
	}
	void getInput(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);
	}
	void getInput()const
	{

		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getInTriple(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].it\"",mName.c_str(),i_i);
	}
	void getInTriple()const
	{

		fprintf(mFile,"\"%s.i.it\"",mName.c_str());
	}
	void getInComp1(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].it.ic1\"",mName.c_str(),i_i);
	}
	void getInComp1()const
	{

		fprintf(mFile,"\"%s.i.it.ic1\"",mName.c_str());
	}
	void getInComp2(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].it.ic2\"",mName.c_str(),i_i);
	}
	void getInComp2()const
	{

		fprintf(mFile,"\"%s.i.it.ic2\"",mName.c_str());
	}
	void getInComp3(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].it.ic3\"",mName.c_str(),i_i);
	}
	void getInComp3()const
	{

		fprintf(mFile,"\"%s.i.it.ic3\"",mName.c_str());
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
	void getDefComp1()const
	{
		fprintf(mFile,"\"%s.def.dc1\"",mName.c_str());
	}
	void getDefComp2()const
	{
		fprintf(mFile,"\"%s.def.dc2\"",mName.c_str());
	}
	void getDefComp3()const
	{
		fprintf(mFile,"\"%s.def.dc3\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());
	}
	void getOutComp1()const
	{
		fprintf(mFile,"\"%s.out.oc1\"",mName.c_str());
	}
	void getOutComp2()const
	{
		fprintf(mFile,"\"%s.out.oc2\"",mName.c_str());
	}
	void getOutComp3()const
	{
		fprintf(mFile,"\"%s.out.oc3\"",mName.c_str());
	}
protected:
	TripleShadingSwitch(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:BaseShadingSwitch(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_TRIPLESHADINGSWITCH_H__
