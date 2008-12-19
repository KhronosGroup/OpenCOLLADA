/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	SurfaceSampler(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "surfaceSampler"){}
	virtual ~SurfaceSampler(){}
	void setMaxDist(float S00)
	{
		if(S00 == 0) return;
		fprintf(mFile,"setAttr \".S00\" %f;\n", S00);

	}
	void setEnveloperSearch(int S02)
	{
		if(S02 == 0) return;
		fprintf(mFile,"setAttr \".S02\" %i;\n", S02);

	}
	void setEvaluateMaterial(bool S03)
	{
		if(S03 == 0) return;
		fprintf(mFile,"setAttr \".S03\" %i;\n", S03);

	}
	void setEvaluateCustomShader(bool S04)
	{
		if(S04 == 0) return;
		fprintf(mFile,"setAttr \".S04\" %i;\n", S04);

	}
	void setCustomColor(const float3& S05)
	{
		if(S05 == float3(1,1,1)) return;
		fprintf(mFile,"setAttr \".S05\" -type \"float3\" ");
		S05.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDefaultColor(const float3& S06)
	{
		fprintf(mFile,"setAttr \".S06\" -type \"float3\" ");
		S06.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCoordinate(int S07)
	{
		if(S07 == 1) return;
		fprintf(mFile,"setAttr \".S07\" %i;\n", S07);

	}
	void setAutoInverseNormal(bool S08)
	{
		if(S08 == 1) return;
		fprintf(mFile,"setAttr \".S08\" %i;\n", S08);

	}
	void setVectorToColor(bool S09)
	{
		if(S09 == 0) return;
		fprintf(mFile,"setAttr \".S09\" %i;\n", S09);

	}
	void getMaxDist()
	{
		fprintf(mFile,"\"%s.S00\"",mName.c_str());

	}
	void getEnvelopes(size_t S01_i)
	{
		fprintf(mFile,"\"%s.S01[%i]\"",mName.c_str(),S01_i);

	}
	void getEnveloperSearch()
	{
		fprintf(mFile,"\"%s.S02\"",mName.c_str());

	}
	void getEvaluateMaterial()
	{
		fprintf(mFile,"\"%s.S03\"",mName.c_str());

	}
	void getEvaluateCustomShader()
	{
		fprintf(mFile,"\"%s.S04\"",mName.c_str());

	}
	void getCustomColor()
	{
		fprintf(mFile,"\"%s.S05\"",mName.c_str());

	}
	void getDefaultColor()
	{
		fprintf(mFile,"\"%s.S06\"",mName.c_str());

	}
	void getCoordinate()
	{
		fprintf(mFile,"\"%s.S07\"",mName.c_str());

	}
	void getAutoInverseNormal()
	{
		fprintf(mFile,"\"%s.S08\"",mName.c_str());

	}
	void getVectorToColor()
	{
		fprintf(mFile,"\"%s.S09\"",mName.c_str());

	}
	void getSources(size_t S10_i)
	{
		fprintf(mFile,"\"%s.S10[%i]\"",mName.c_str(),S10_i);

	}
protected:
	SurfaceSampler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SURFACESAMPLER_H__
