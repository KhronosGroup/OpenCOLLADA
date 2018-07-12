/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTWEAK_H__
#define __MayaDM_POLYTWEAK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyTweak : public PolyModifier
{
public:
public:

	PolyTweak():PolyModifier(){}
	PolyTweak(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyTweak", shared, create){}
	virtual ~PolyTweak(){}

	void setTweak(size_t tk_i,const float3& tk)
	{
		if(tk == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".tk[%i]\" -type \"float3\" ",tk_i);
		tk.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTweak(size_t tk_start,size_t tk_end,float* tk)
	{
		fprintf(mFile,"\tsetAttr \".tk[%i:%i]\" ", tk_start,tk_end);
		size_t size = (tk_end-tk_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",tk[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startTweak(size_t tk_start,size_t tk_end)const
	{
		fprintf(mFile,"\tsetAttr \".tk[%i:%i]\"",tk_start,tk_end);
	}
	void appendTweak(float tk)const
	{
		fprintf(mFile," %f",tk);
	}
	void endTweak()const
	{
		fprintf(mFile,";\n");
	}
	void setTweakX(size_t tk_i,float tx)
	{
		if(tx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tk[%i].tx\" %f;\n", tk_i,tx);
	}
	void setTweakY(size_t tk_i,float ty)
	{
		if(ty == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tk[%i].ty\" %f;\n", tk_i,ty);
	}
	void setTweakZ(size_t tk_i,float tz)
	{
		if(tz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tk[%i].tz\" %f;\n", tk_i,tz);
	}
	void getTweak(size_t tk_i)const
	{
		fprintf(mFile,"\"%s.tk[%i]\"",mName.c_str(),tk_i);
	}
	void getTweak()const
	{

		fprintf(mFile,"\"%s.tk\"",mName.c_str());
	}
	void getTweakX(size_t tk_i)const
	{
		fprintf(mFile,"\"%s.tk[%i].tx\"",mName.c_str(),tk_i);
	}
	void getTweakX()const
	{

		fprintf(mFile,"\"%s.tk.tx\"",mName.c_str());
	}
	void getTweakY(size_t tk_i)const
	{
		fprintf(mFile,"\"%s.tk[%i].ty\"",mName.c_str(),tk_i);
	}
	void getTweakY()const
	{

		fprintf(mFile,"\"%s.tk.ty\"",mName.c_str());
	}
	void getTweakZ(size_t tk_i)const
	{
		fprintf(mFile,"\"%s.tk[%i].tz\"",mName.c_str(),tk_i);
	}
	void getTweakZ()const
	{

		fprintf(mFile,"\"%s.tk.tz\"",mName.c_str());
	}
protected:
	PolyTweak(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYTWEAK_H__
