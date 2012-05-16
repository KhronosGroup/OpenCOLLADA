/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PHONGE_H__
#define __MayaDM_PHONGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMReflect.h"
namespace MayaDM
{
class PhongE : public Reflect
{
public:
public:

	PhongE():Reflect(){}
	PhongE(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Reflect(file, name, parent, "phongE", shared, create){}
	virtual ~PhongE(){}

	void setRoughness(float rn)
	{
		if(rn == 0.5) return;
		fprintf(mFile,"\tsetAttr \".rn\" %f;\n", rn);
	}
	void setHighlightSize(float hls)
	{
		if(hls == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hls\" %f;\n", hls);
	}
	void setWhiteness(const float3& wn)
	{
		if(wn == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".wn\" -type \"float3\" ");
		wn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWhitenessR(float wnr)
	{
		if(wnr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wn.wnr\" %f;\n", wnr);
	}
	void setWhitenessG(float wng)
	{
		if(wng == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wn.wng\" %f;\n", wng);
	}
	void setWhitenessB(float wnb)
	{
		if(wnb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wn.wnb\" %f;\n", wnb);
	}
	void setMiReflectionBlur(float mircb)
	{
		if(mircb == 0) return;
		fprintf(mFile,"\tsetAttr \".mircb\" %f;\n", mircb);
	}
	void setMiReflectionRays(short mircr)
	{
		if(mircr == 1) return;
		fprintf(mFile,"\tsetAttr \".mircr\" %i;\n", mircr);
	}
	void setMiShinyness(float mis)
	{
		if(mis == 10) return;
		fprintf(mFile,"\tsetAttr \".mis\" %f;\n", mis);
	}
	void setMiWhiteness(const float3& miwn)
	{
		fprintf(mFile,"\tsetAttr \".miwn\" -type \"float3\" ");
		miwn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiWhitenessR(float miwnr)
	{
		if(miwnr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".miwn.miwnr\" %f;\n", miwnr);
	}
	void setMiWhitenessG(float miwng)
	{
		if(miwng == 0.5) return;
		fprintf(mFile,"\tsetAttr \".miwn.miwng\" %f;\n", miwng);
	}
	void setMiWhitenessB(float miwnb)
	{
		if(miwnb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".miwn.miwnb\" %f;\n", miwnb);
	}
	void setMiSpecularColor(const float3& misc)
	{
		fprintf(mFile,"\tsetAttr \".misc\" -type \"float3\" ");
		misc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiSpecularColorR(float miscr)
	{
		if(miscr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscr\" %f;\n", miscr);
	}
	void setMiSpecularColorG(float miscg)
	{
		if(miscg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscg\" %f;\n", miscg);
	}
	void setMiSpecularColorB(float miscb)
	{
		if(miscb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscb\" %f;\n", miscb);
	}
	void setMiReflectivity(float mirf)
	{
		if(mirf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mirf\" %f;\n", mirf);
	}
	void getRoughness()const
	{
		fprintf(mFile,"\"%s.rn\"",mName.c_str());
	}
	void getHighlightSize()const
	{
		fprintf(mFile,"\"%s.hls\"",mName.c_str());
	}
	void getWhiteness()const
	{
		fprintf(mFile,"\"%s.wn\"",mName.c_str());
	}
	void getWhitenessR()const
	{
		fprintf(mFile,"\"%s.wn.wnr\"",mName.c_str());
	}
	void getWhitenessG()const
	{
		fprintf(mFile,"\"%s.wn.wng\"",mName.c_str());
	}
	void getWhitenessB()const
	{
		fprintf(mFile,"\"%s.wn.wnb\"",mName.c_str());
	}
	void getMiReflectionBlur()const
	{
		fprintf(mFile,"\"%s.mircb\"",mName.c_str());
	}
	void getMiReflectionRays()const
	{
		fprintf(mFile,"\"%s.mircr\"",mName.c_str());
	}
	void getMiShinyness()const
	{
		fprintf(mFile,"\"%s.mis\"",mName.c_str());
	}
	void getMiWhiteness()const
	{
		fprintf(mFile,"\"%s.miwn\"",mName.c_str());
	}
	void getMiWhitenessR()const
	{
		fprintf(mFile,"\"%s.miwn.miwnr\"",mName.c_str());
	}
	void getMiWhitenessG()const
	{
		fprintf(mFile,"\"%s.miwn.miwng\"",mName.c_str());
	}
	void getMiWhitenessB()const
	{
		fprintf(mFile,"\"%s.miwn.miwnb\"",mName.c_str());
	}
	void getMiSpecularColor()const
	{
		fprintf(mFile,"\"%s.misc\"",mName.c_str());
	}
	void getMiSpecularColorR()const
	{
		fprintf(mFile,"\"%s.misc.miscr\"",mName.c_str());
	}
	void getMiSpecularColorG()const
	{
		fprintf(mFile,"\"%s.misc.miscg\"",mName.c_str());
	}
	void getMiSpecularColorB()const
	{
		fprintf(mFile,"\"%s.misc.miscb\"",mName.c_str());
	}
	void getMiReflectivity()const
	{
		fprintf(mFile,"\"%s.mirf\"",mName.c_str());
	}
protected:
	PhongE(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Reflect(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PHONGE_H__
