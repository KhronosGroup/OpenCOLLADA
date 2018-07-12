/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDWEIGHTED_H__
#define __MayaDM_BLENDWEIGHTED_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBlend.h"
namespace MayaDM
{
class BlendWeighted : public Blend
{
public:
public:

	BlendWeighted():Blend(){}
	BlendWeighted(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Blend(file, name, parent, "blendWeighted", shared, create){}
	virtual ~BlendWeighted(){}

	void setWeight(size_t w_i,float w)
	{
		if(w == 1.0) return;
		fprintf(mFile,"\tsetAttr \".w[%i]\" %f;\n", w_i,w);
	}
	void setWeight(size_t w_start,size_t w_end,float* w)
	{
		fprintf(mFile,"\tsetAttr \".w[%i:%i]\" ", w_start,w_end);
		size_t size = (w_end-w_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",w[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startWeight(size_t w_start,size_t w_end)const
	{
		fprintf(mFile,"\tsetAttr \".w[%i:%i]\"",w_start,w_end);
	}
	void appendWeight(float w)const
	{
		fprintf(mFile," %f",w);
	}
	void endWeight()const
	{
		fprintf(mFile,";\n");
	}
	void getWeight(size_t w_i)const
	{
		fprintf(mFile,"\"%s.w[%i]\"",mName.c_str(),w_i);
	}
	void getWeight()const
	{

		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
protected:
	BlendWeighted(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Blend(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLENDWEIGHTED_H__
