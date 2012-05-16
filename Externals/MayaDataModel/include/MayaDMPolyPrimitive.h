/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPRIMITIVE_H__
#define __MayaDM_POLYPRIMITIVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyCreator.h"
namespace MayaDM
{
class PolyPrimitive : public PolyCreator
{
public:
public:

	PolyPrimitive():PolyCreator(){}
	PolyPrimitive(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyCreator(file, name, parent, "polyPrimitive", shared, create){}
	virtual ~PolyPrimitive(){}

	void setAxis(const double3& ax)
	{
		fprintf(mFile,"\tsetAttr \".ax\" -type \"double3\" ");
		ax.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAxisX(double axx)
	{
		if(axx == 0) return;
		fprintf(mFile,"\tsetAttr \".ax.axx\" %f;\n", axx);
	}
	void setAxisY(double axy)
	{
		if(axy == 1) return;
		fprintf(mFile,"\tsetAttr \".ax.axy\" %f;\n", axy);
	}
	void setAxisZ(double axz)
	{
		if(axz == 0) return;
		fprintf(mFile,"\tsetAttr \".ax.axz\" %f;\n", axz);
	}
	void setParamWarn(bool pw)
	{
		if(pw == true) return;
		fprintf(mFile,"\tsetAttr \".pw\" %i;\n", pw);
	}
	void setUvSetName(const string& uvs)
	{
		if(uvs == "NULL") return;
		fprintf(mFile,"\tsetAttr \".uvs\" -type \"string\" ");
		uvs.write(mFile);
		fprintf(mFile,";\n");
	}
	void getAxis()const
	{
		fprintf(mFile,"\"%s.ax\"",mName.c_str());
	}
	void getAxisX()const
	{
		fprintf(mFile,"\"%s.ax.axx\"",mName.c_str());
	}
	void getAxisY()const
	{
		fprintf(mFile,"\"%s.ax.axy\"",mName.c_str());
	}
	void getAxisZ()const
	{
		fprintf(mFile,"\"%s.ax.axz\"",mName.c_str());
	}
	void getParamWarn()const
	{
		fprintf(mFile,"\"%s.pw\"",mName.c_str());
	}
	void getUvSetName()const
	{
		fprintf(mFile,"\"%s.uvs\"",mName.c_str());
	}
protected:
	PolyPrimitive(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyCreator(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYPRIMITIVE_H__
