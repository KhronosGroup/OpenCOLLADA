/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GRID_H__
#define __MayaDM_GRID_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Grid : public Texture2d
{
public:
public:

	Grid():Texture2d(){}
	Grid(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture2d(file, name, parent, "grid", shared, create){}
	virtual ~Grid(){}

	void setFillerColor(const float3& fc)
	{
		if(fc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".fc\" -type \"float3\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFillerColorR(float fcr)
	{
		if(fcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcr\" %f;\n", fcr);
	}
	void setFillerColorG(float fcg)
	{
		if(fcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcg\" %f;\n", fcg);
	}
	void setFillerColorB(float fcb)
	{
		if(fcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcb\" %f;\n", fcb);
	}
	void setLineColor(const float3& lc)
	{
		if(lc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".lc\" -type \"float3\" ");
		lc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLineColorR(float lcr)
	{
		if(lcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lc.lcr\" %f;\n", lcr);
	}
	void setLineColorG(float lcg)
	{
		if(lcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lc.lcg\" %f;\n", lcg);
	}
	void setLineColorB(float lcb)
	{
		if(lcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lc.lcb\" %f;\n", lcb);
	}
	void setContrast(float c)
	{
		if(c == 1.0) return;
		fprintf(mFile,"\tsetAttr \".c\" %f;\n", c);
	}
	void setUWidth(float uw)
	{
		if(uw == 0.1) return;
		fprintf(mFile,"\tsetAttr \".uw\" %f;\n", uw);
	}
	void setVWidth(float vw)
	{
		if(vw == 0.1) return;
		fprintf(mFile,"\tsetAttr \".vw\" %f;\n", vw);
	}
	void getFillerColor()const
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getFillerColorR()const
	{
		fprintf(mFile,"\"%s.fc.fcr\"",mName.c_str());
	}
	void getFillerColorG()const
	{
		fprintf(mFile,"\"%s.fc.fcg\"",mName.c_str());
	}
	void getFillerColorB()const
	{
		fprintf(mFile,"\"%s.fc.fcb\"",mName.c_str());
	}
	void getLineColor()const
	{
		fprintf(mFile,"\"%s.lc\"",mName.c_str());
	}
	void getLineColorR()const
	{
		fprintf(mFile,"\"%s.lc.lcr\"",mName.c_str());
	}
	void getLineColorG()const
	{
		fprintf(mFile,"\"%s.lc.lcg\"",mName.c_str());
	}
	void getLineColorB()const
	{
		fprintf(mFile,"\"%s.lc.lcb\"",mName.c_str());
	}
	void getContrast()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getUWidth()const
	{
		fprintf(mFile,"\"%s.uw\"",mName.c_str());
	}
	void getVWidth()const
	{
		fprintf(mFile,"\"%s.vw\"",mName.c_str());
	}
protected:
	Grid(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture2d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_GRID_H__
