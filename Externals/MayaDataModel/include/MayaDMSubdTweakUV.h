/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	SubdTweakUV():SubdModifier(){}
	SubdTweakUV(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SubdModifier(file, name, parent, "subdTweakUV", shared, create){}
	virtual ~SubdTweakUV(){}

	void setUvTweak(size_t uvtk_i,const float2& uvtk)
	{
		if(uvtk == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".uvtk[%i]\" -type \"float2\" ",uvtk_i);
		uvtk.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUvTweak(size_t uvtk_start,size_t uvtk_end,float* uvtk)
	{
		fprintf(mFile,"\tsetAttr \".uvtk[%i:%i]\" ", uvtk_start,uvtk_end);
		size_t size = (uvtk_end-uvtk_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uvtk[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startUvTweak(size_t uvtk_start,size_t uvtk_end)const
	{
		fprintf(mFile,"\tsetAttr \".uvtk[%i:%i]\"",uvtk_start,uvtk_end);
	}
	void appendUvTweak(float uvtk)const
	{
		fprintf(mFile," %f",uvtk);
	}
	void endUvTweak()const
	{
		fprintf(mFile,";\n");
	}
	void setUvTweakU(size_t uvtk_i,float tu)
	{
		if(tu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uvtk[%i].tu\" %f;\n", uvtk_i,tu);
	}
	void setUvTweakV(size_t uvtk_i,float tv)
	{
		if(tv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uvtk[%i].tv\" %f;\n", uvtk_i,tv);
	}
	void getUvTweak(size_t uvtk_i)const
	{
		fprintf(mFile,"\"%s.uvtk[%i]\"",mName.c_str(),uvtk_i);
	}
	void getUvTweak()const
	{

		fprintf(mFile,"\"%s.uvtk\"",mName.c_str());
	}
	void getUvTweakU(size_t uvtk_i)const
	{
		fprintf(mFile,"\"%s.uvtk[%i].tu\"",mName.c_str(),uvtk_i);
	}
	void getUvTweakU()const
	{

		fprintf(mFile,"\"%s.uvtk.tu\"",mName.c_str());
	}
	void getUvTweakV(size_t uvtk_i)const
	{
		fprintf(mFile,"\"%s.uvtk[%i].tv\"",mName.c_str(),uvtk_i);
	}
	void getUvTweakV()const
	{

		fprintf(mFile,"\"%s.uvtk.tv\"",mName.c_str());
	}
protected:
	SubdTweakUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SubdModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDTWEAKUV_H__
