/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLINN_H__
#define __MayaDM_BLINN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMReflect.h"
namespace MayaDM
{
class Blinn : public Reflect
{
public:
public:
	Blinn():Reflect(){}
	Blinn(FILE* file,const std::string& name,const std::string& parent=""):Reflect(file, name, parent, "blinn"){}
	virtual ~Blinn(){}
	void setEccentricity(float ec)
	{
		if(ec == 0.3) return;
		fprintf(mFile,"\tsetAttr \".ec\" %f;\n", ec);

	}
	void setSpecularRollOff(float sro)
	{
		if(sro == 0.7) return;
		fprintf(mFile,"\tsetAttr \".sro\" %f;\n", sro);

	}
	void setReflectionRolloff(bool rro)
	{
		if(rro == true) return;
		fprintf(mFile,"\tsetAttr \".rro\" %i;\n", rro);

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
	void getEccentricity()
	{
		fprintf(mFile,"\"%s.ec\"",mName.c_str());

	}
	void getSpecularRollOff()
	{
		fprintf(mFile,"\"%s.sro\"",mName.c_str());

	}
	void getReflectionRolloff()
	{
		fprintf(mFile,"\"%s.rro\"",mName.c_str());

	}
	void getMiReflectionBlur()
	{
		fprintf(mFile,"\"%s.mircb\"",mName.c_str());

	}
	void getMiReflectionRays()
	{
		fprintf(mFile,"\"%s.mircr\"",mName.c_str());

	}
	void getMiShinyness()
	{
		fprintf(mFile,"\"%s.mis\"",mName.c_str());

	}
	void getMiSpecularColor()
	{
		fprintf(mFile,"\"%s.misc\"",mName.c_str());

	}
	void getMiSpecularColorR()
	{
		fprintf(mFile,"\"%s.misc.miscr\"",mName.c_str());

	}
	void getMiSpecularColorG()
	{
		fprintf(mFile,"\"%s.misc.miscg\"",mName.c_str());

	}
	void getMiSpecularColorB()
	{
		fprintf(mFile,"\"%s.misc.miscb\"",mName.c_str());

	}
	void getMiReflectivity()
	{
		fprintf(mFile,"\"%s.mirf\"",mName.c_str());

	}
protected:
	Blinn(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Reflect(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLINN_H__
