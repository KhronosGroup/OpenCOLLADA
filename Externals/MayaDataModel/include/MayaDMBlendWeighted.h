/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	BlendWeighted(FILE* file,const std::string& name,const std::string& parent=""):Blend(file, name, parent, "blendWeighted"){}
	virtual ~BlendWeighted(){}
	void setWeight(size_t w_i,float w)
	{
		if(w == 1.0) return;
		fprintf(mFile,"setAttr \".w[%i]\" %f;\n", w_i,w);

	}
	void setWeight(size_t w_start,size_t w_end,float* w)
	{
		fprintf(mFile,"setAttr \".w[%i:%i]\" ", w_start,w_end);
		size_t size = (w_end-w_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",w[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startWeight(size_t w_start,size_t w_end)
	{
		fprintf(mFile,"setAttr \".w[%i:%i]\"",w_start,w_end);

	}
	void appendWeight(float w)
	{
		fprintf(mFile," %f",w);

	}
	void endWeight()
	{
		fprintf(mFile,";\n");

	}
	void getWeight(size_t w_i)
	{
		fprintf(mFile,"\"%s.w[%i]\"",mName.c_str(),w_i);

	}
protected:
	BlendWeighted(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Blend(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLENDWEIGHTED_H__
