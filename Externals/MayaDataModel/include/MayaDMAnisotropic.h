/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANISOTROPIC_H__
#define __MayaDM_ANISOTROPIC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMReflect.h"
namespace MayaDM
{
class Anisotropic : public Reflect
{
public:
public:

	Anisotropic():Reflect(){}
	Anisotropic(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Reflect(file, name, parent, "anisotropic", shared, create){}
	virtual ~Anisotropic(){}

	void setSpreadX(float sprx)
	{
		if(sprx == 13.0) return;
		fprintf(mFile,"\tsetAttr \".sprx\" %f;\n", sprx);
	}
	void setSpreadY(float spry)
	{
		if(spry == 3.0) return;
		fprintf(mFile,"\tsetAttr \".spry\" %f;\n", spry);
	}
	void setRoughness(float roug)
	{
		if(roug == 0.7) return;
		fprintf(mFile,"\tsetAttr \".roug\" %f;\n", roug);
	}
	void setAngle(float angl)
	{
		if(angl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".angl\" %f;\n", angl);
	}
	void setFresnelRefractiveIndex(float frfi)
	{
		if(frfi == 6.0) return;
		fprintf(mFile,"\tsetAttr \".frfi\" %f;\n", frfi);
	}
	void setAnisotropicReflectivity(bool arfl)
	{
		if(arfl == true) return;
		fprintf(mFile,"\tsetAttr \".arfl\" %i;\n", arfl);
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
	void setMiAngle(float mia)
	{
		if(mia == 0) return;
		fprintf(mFile,"\tsetAttr \".mia\" %f;\n", mia);
	}
	void setMiSpreadX(float misx)
	{
		if(misx == 10) return;
		fprintf(mFile,"\tsetAttr \".misx\" %f;\n", misx);
	}
	void setMiSpreadY(float misy)
	{
		if(misy == 5) return;
		fprintf(mFile,"\tsetAttr \".misy\" %f;\n", misy);
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
	void getTangentUCamera()const
	{
		fprintf(mFile,"\"%s.utan\"",mName.c_str());
	}
	void getTangentUCameraX()const
	{
		fprintf(mFile,"\"%s.utan.utnx\"",mName.c_str());
	}
	void getTangentUCameraY()const
	{
		fprintf(mFile,"\"%s.utan.utny\"",mName.c_str());
	}
	void getTangentUCameraZ()const
	{
		fprintf(mFile,"\"%s.utan.utnz\"",mName.c_str());
	}
	void getTangentVCamera()const
	{
		fprintf(mFile,"\"%s.vtan\"",mName.c_str());
	}
	void getTangentVCameraX()const
	{
		fprintf(mFile,"\"%s.vtan.vtnx\"",mName.c_str());
	}
	void getTangentVCameraY()const
	{
		fprintf(mFile,"\"%s.vtan.vtny\"",mName.c_str());
	}
	void getTangentVCameraZ()const
	{
		fprintf(mFile,"\"%s.vtan.vtnz\"",mName.c_str());
	}
	void getSpreadX()const
	{
		fprintf(mFile,"\"%s.sprx\"",mName.c_str());
	}
	void getSpreadY()const
	{
		fprintf(mFile,"\"%s.spry\"",mName.c_str());
	}
	void getRoughness()const
	{
		fprintf(mFile,"\"%s.roug\"",mName.c_str());
	}
	void getAngle()const
	{
		fprintf(mFile,"\"%s.angl\"",mName.c_str());
	}
	void getFresnelRefractiveIndex()const
	{
		fprintf(mFile,"\"%s.frfi\"",mName.c_str());
	}
	void getAnisotropicReflectivity()const
	{
		fprintf(mFile,"\"%s.arfl\"",mName.c_str());
	}
	void getMiReflectionBlur()const
	{
		fprintf(mFile,"\"%s.mircb\"",mName.c_str());
	}
	void getMiReflectionRays()const
	{
		fprintf(mFile,"\"%s.mircr\"",mName.c_str());
	}
	void getMiAngle()const
	{
		fprintf(mFile,"\"%s.mia\"",mName.c_str());
	}
	void getMiSpreadX()const
	{
		fprintf(mFile,"\"%s.misx\"",mName.c_str());
	}
	void getMiSpreadY()const
	{
		fprintf(mFile,"\"%s.misy\"",mName.c_str());
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
	Anisotropic(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Reflect(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANISOTROPIC_H__
