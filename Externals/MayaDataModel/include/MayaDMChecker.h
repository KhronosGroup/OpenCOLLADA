/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHECKER_H__
#define __MayaDM_CHECKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Checker : public Texture2d
{
public:
public:

	Checker():Texture2d(){}
	Checker(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture2d(file, name, parent, "checker", shared, create){}
	virtual ~Checker(){}

	void setColor1(const float3& c1)
	{
		if(c1 == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".c1\" -type \"float3\" ");
		c1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor1R(float c1r)
	{
		if(c1r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c1.c1r\" %f;\n", c1r);
	}
	void setColor1G(float c1g)
	{
		if(c1g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c1.c1g\" %f;\n", c1g);
	}
	void setColor1B(float c1b)
	{
		if(c1b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c1.c1b\" %f;\n", c1b);
	}
	void setColor2(const float3& c2)
	{
		if(c2 == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".c2\" -type \"float3\" ");
		c2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor2R(float c2r)
	{
		if(c2r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c2.c2r\" %f;\n", c2r);
	}
	void setColor2G(float c2g)
	{
		if(c2g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c2.c2g\" %f;\n", c2g);
	}
	void setColor2B(float c2b)
	{
		if(c2b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c2.c2b\" %f;\n", c2b);
	}
	void setContrast(float ct)
	{
		if(ct == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ct\" %f;\n", ct);
	}
	void getColor1()const
	{
		fprintf(mFile,"\"%s.c1\"",mName.c_str());
	}
	void getColor1R()const
	{
		fprintf(mFile,"\"%s.c1.c1r\"",mName.c_str());
	}
	void getColor1G()const
	{
		fprintf(mFile,"\"%s.c1.c1g\"",mName.c_str());
	}
	void getColor1B()const
	{
		fprintf(mFile,"\"%s.c1.c1b\"",mName.c_str());
	}
	void getColor2()const
	{
		fprintf(mFile,"\"%s.c2\"",mName.c_str());
	}
	void getColor2R()const
	{
		fprintf(mFile,"\"%s.c2.c2r\"",mName.c_str());
	}
	void getColor2G()const
	{
		fprintf(mFile,"\"%s.c2.c2g\"",mName.c_str());
	}
	void getColor2B()const
	{
		fprintf(mFile,"\"%s.c2.c2b\"",mName.c_str());
	}
	void getContrast()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
protected:
	Checker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture2d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CHECKER_H__
