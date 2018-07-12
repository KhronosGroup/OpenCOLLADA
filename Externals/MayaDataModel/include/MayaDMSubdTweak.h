/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDTWEAK_H__
#define __MayaDM_SUBDTWEAK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifier.h"
namespace MayaDM
{
class SubdTweak : public SubdModifier
{
public:
public:

	SubdTweak():SubdModifier(){}
	SubdTweak(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SubdModifier(file, name, parent, "subdTweak", shared, create){}
	virtual ~SubdTweak(){}

	void setTweak(size_t tk_i,const double3& tk)
	{
		if(tk == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".tk[%i]\" -type \"double3\" ",tk_i);
		tk.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTweak(size_t tk_start,size_t tk_end,double* tk)
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
	void appendTweak(double tk)const
	{
		fprintf(mFile," %f",tk);
	}
	void endTweak()const
	{
		fprintf(mFile,";\n");
	}
	void setTweakX(size_t tk_i,double tx)
	{
		if(tx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tk[%i].tx\" %f;\n", tk_i,tx);
	}
	void setTweakY(size_t tk_i,double ty)
	{
		if(ty == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tk[%i].ty\" %f;\n", tk_i,ty);
	}
	void setTweakZ(size_t tk_i,double tz)
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
	void getMap64BitIndices()const
	{
		fprintf(mFile,"\"%s.map\"",mName.c_str());
	}
protected:
	SubdTweak(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SubdModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDTWEAK_H__
