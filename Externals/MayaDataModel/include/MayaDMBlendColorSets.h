/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDCOLORSETS_H__
#define __MayaDM_BLENDCOLORSETS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class BlendColorSets : public PolyModifier
{
public:
public:

	BlendColorSets():PolyModifier(){}
	BlendColorSets(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "blendColorSets", shared, create){}
	virtual ~BlendColorSets(){}

	void setBaseColorName(const string& bcn)
	{
		if(bcn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".bcn\" -type \"string\" ");
		bcn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSrcColorName(const string& src)
	{
		if(src == "NULL") return;
		fprintf(mFile,"\tsetAttr \".src\" -type \"string\" ");
		src.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDstColorName(const string& dst)
	{
		if(dst == "NULL") return;
		fprintf(mFile,"\tsetAttr \".dst\" -type \"string\" ");
		dst.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlendFunc(unsigned int bfn)
	{
		if(bfn == 0) return;
		fprintf(mFile,"\tsetAttr \".bfn\" %i;\n", bfn);
	}
	void setBlendWeightA(float bwa)
	{
		if(bwa == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bwa\" %f;\n", bwa);
	}
	void setBlendWeightB(float bwb)
	{
		if(bwb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bwb\" %f;\n", bwb);
	}
	void setBlendWeightC(float bwc)
	{
		if(bwc == 0.5) return;
		fprintf(mFile,"\tsetAttr \".bwc\" %f;\n", bwc);
	}
	void setBlendWeightD(float bwd)
	{
		if(bwd == 0.5) return;
		fprintf(mFile,"\tsetAttr \".bwd\" %f;\n", bwd);
	}
	void getBaseColorName()const
	{
		fprintf(mFile,"\"%s.bcn\"",mName.c_str());
	}
	void getSrcColorName()const
	{
		fprintf(mFile,"\"%s.src\"",mName.c_str());
	}
	void getDstColorName()const
	{
		fprintf(mFile,"\"%s.dst\"",mName.c_str());
	}
	void getBlendFunc()const
	{
		fprintf(mFile,"\"%s.bfn\"",mName.c_str());
	}
	void getBlendWeightA()const
	{
		fprintf(mFile,"\"%s.bwa\"",mName.c_str());
	}
	void getBlendWeightB()const
	{
		fprintf(mFile,"\"%s.bwb\"",mName.c_str());
	}
	void getBlendWeightC()const
	{
		fprintf(mFile,"\"%s.bwc\"",mName.c_str());
	}
	void getBlendWeightD()const
	{
		fprintf(mFile,"\"%s.bwd\"",mName.c_str());
	}
protected:
	BlendColorSets(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLENDCOLORSETS_H__
