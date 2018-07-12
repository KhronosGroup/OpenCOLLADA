/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACESAMPLER_H__
#define __MayaDM_SURFACESAMPLER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SurfaceSampler : public DependNode
{
public:
public:

	SurfaceSampler():DependNode(){}
	SurfaceSampler(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "surfaceSampler", shared, create){}
	virtual ~SurfaceSampler(){}

	void setMaxDist(float S00)
	{
		if(S00 == 0) return;
		fprintf(mFile,"\tsetAttr \".S00\" %f;\n", S00);
	}
	void setEnveloperSearch(int S02)
	{
		if(S02 == 0) return;
		fprintf(mFile,"\tsetAttr \".S02\" %i;\n", S02);
	}
	void setEvaluateMaterial(bool S03)
	{
		if(S03 == 0) return;
		fprintf(mFile,"\tsetAttr \".S03\" %i;\n", S03);
	}
	void setEvaluateCustomShader(bool S04)
	{
		if(S04 == 0) return;
		fprintf(mFile,"\tsetAttr \".S04\" %i;\n", S04);
	}
	void setCustomColor(const float3& S05)
	{
		if(S05 == float3(1,1,1)) return;
		fprintf(mFile,"\tsetAttr \".S05\" -type \"float3\" ");
		S05.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDefaultColor(const float3& S06)
	{
		fprintf(mFile,"\tsetAttr \".S06\" -type \"float3\" ");
		S06.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCoordinate(int S07)
	{
		if(S07 == 1) return;
		fprintf(mFile,"\tsetAttr \".S07\" %i;\n", S07);
	}
	void setAutoInverseNormal(bool S08)
	{
		if(S08 == 1) return;
		fprintf(mFile,"\tsetAttr \".S08\" %i;\n", S08);
	}
	void setVectorToColor(bool S09)
	{
		if(S09 == 0) return;
		fprintf(mFile,"\tsetAttr \".S09\" %i;\n", S09);
	}
	void getMaxDist()const
	{
		fprintf(mFile,"\"%s.S00\"",mName.c_str());
	}
	void getEnvelopes(size_t S01_i)const
	{
		fprintf(mFile,"\"%s.S01[%i]\"",mName.c_str(),S01_i);
	}
	void getEnvelopes()const
	{

		fprintf(mFile,"\"%s.S01\"",mName.c_str());
	}
	void getEnveloperSearch()const
	{
		fprintf(mFile,"\"%s.S02\"",mName.c_str());
	}
	void getEvaluateMaterial()const
	{
		fprintf(mFile,"\"%s.S03\"",mName.c_str());
	}
	void getEvaluateCustomShader()const
	{
		fprintf(mFile,"\"%s.S04\"",mName.c_str());
	}
	void getCustomColor()const
	{
		fprintf(mFile,"\"%s.S05\"",mName.c_str());
	}
	void getDefaultColor()const
	{
		fprintf(mFile,"\"%s.S06\"",mName.c_str());
	}
	void getCoordinate()const
	{
		fprintf(mFile,"\"%s.S07\"",mName.c_str());
	}
	void getAutoInverseNormal()const
	{
		fprintf(mFile,"\"%s.S08\"",mName.c_str());
	}
	void getVectorToColor()const
	{
		fprintf(mFile,"\"%s.S09\"",mName.c_str());
	}
	void getSources(size_t S10_i)const
	{
		fprintf(mFile,"\"%s.S10[%i]\"",mName.c_str(),S10_i);
	}
	void getSources()const
	{

		fprintf(mFile,"\"%s.S10\"",mName.c_str());
	}
protected:
	SurfaceSampler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SURFACESAMPLER_H__
