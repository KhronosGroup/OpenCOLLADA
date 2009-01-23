/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDTWEAKUV_H__
#define __MayaDM_SUBDTWEAKUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifier.h"
namespace MayaDM
{
class SubdTweakUV : public SubdModifier
{
public:
public:
	SubdTweakUV(FILE* file,const std::string& name,const std::string& parent=""):SubdModifier(file, name, parent, "subdTweakUV"){}
	virtual ~SubdTweakUV(){}
	void setUvTweak(size_t uvtk_i,const float2& uvtk)
	{
		if(uvtk == float2(0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".uvtk[%i]\" -type \"float2\" ",uvtk_i);
		uvtk.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvTweak(size_t uvtk_start,size_t uvtk_end,float* uvtk)
	{
		fprintf(mFile,"setAttr \".uvtk[%i:%i]\" ", uvtk_start,uvtk_end);
		size_t size = (uvtk_end-uvtk_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uvtk[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startUvTweak(size_t uvtk_start,size_t uvtk_end)
	{
		fprintf(mFile,"setAttr \".uvtk[%i:%i]\"",uvtk_start,uvtk_end);

	}
	void appendUvTweak(float uvtk)
	{
		fprintf(mFile," %f",uvtk);

	}
	void endUvTweak()
	{
		fprintf(mFile,";\n");

	}
	void setUvTweakU(size_t uvtk_i,float tu)
	{
		if(tu == 0.0) return;
		fprintf(mFile,"setAttr \".uvtk[%i].tu\" %f;\n", uvtk_i,tu);

	}
	void setUvTweakV(size_t uvtk_i,float tv)
	{
		if(tv == 0.0) return;
		fprintf(mFile,"setAttr \".uvtk[%i].tv\" %f;\n", uvtk_i,tv);

	}
	void getUvTweak(size_t uvtk_i)
	{
		fprintf(mFile,"\"%s.uvtk[%i]\"",mName.c_str(),uvtk_i);

	}
	void getUvTweakU(size_t uvtk_i)
	{
		fprintf(mFile,"\"%s.uvtk[%i].tu\"",mName.c_str(),uvtk_i);

	}
	void getUvTweakV(size_t uvtk_i)
	{
		fprintf(mFile,"\"%s.uvtk[%i].tv\"",mName.c_str(),uvtk_i);

	}
protected:
	SubdTweakUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDTWEAKUV_H__
