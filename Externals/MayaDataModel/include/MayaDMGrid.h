/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Grid(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "grid"){}
	virtual ~Grid(){}
	void setFillerColor(const float3& fc)
	{
		if(fc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".fc\" -type \"float3\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFillerColorR(float fcr)
	{
		if(fcr == 0.0) return;
		fprintf(mFile,"setAttr \".fc.fcr\" %f;\n", fcr);

	}
	void setFillerColorG(float fcg)
	{
		if(fcg == 0.0) return;
		fprintf(mFile,"setAttr \".fc.fcg\" %f;\n", fcg);

	}
	void setFillerColorB(float fcb)
	{
		if(fcb == 0.0) return;
		fprintf(mFile,"setAttr \".fc.fcb\" %f;\n", fcb);

	}
	void setLineColor(const float3& lc)
	{
		if(lc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".lc\" -type \"float3\" ");
		lc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLineColorR(float lcr)
	{
		if(lcr == 0.0) return;
		fprintf(mFile,"setAttr \".lc.lcr\" %f;\n", lcr);

	}
	void setLineColorG(float lcg)
	{
		if(lcg == 0.0) return;
		fprintf(mFile,"setAttr \".lc.lcg\" %f;\n", lcg);

	}
	void setLineColorB(float lcb)
	{
		if(lcb == 0.0) return;
		fprintf(mFile,"setAttr \".lc.lcb\" %f;\n", lcb);

	}
	void setContrast(float c)
	{
		if(c == 1.0) return;
		fprintf(mFile,"setAttr \".c\" %f;\n", c);

	}
	void setUWidth(float uw)
	{
		if(uw == 0.1) return;
		fprintf(mFile,"setAttr \".uw\" %f;\n", uw);

	}
	void setVWidth(float vw)
	{
		if(vw == 0.1) return;
		fprintf(mFile,"setAttr \".vw\" %f;\n", vw);

	}
	void getFillerColor()
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());

	}
	void getFillerColorR()
	{
		fprintf(mFile,"\"%s.fc.fcr\"",mName.c_str());

	}
	void getFillerColorG()
	{
		fprintf(mFile,"\"%s.fc.fcg\"",mName.c_str());

	}
	void getFillerColorB()
	{
		fprintf(mFile,"\"%s.fc.fcb\"",mName.c_str());

	}
	void getLineColor()
	{
		fprintf(mFile,"\"%s.lc\"",mName.c_str());

	}
	void getLineColorR()
	{
		fprintf(mFile,"\"%s.lc.lcr\"",mName.c_str());

	}
	void getLineColorG()
	{
		fprintf(mFile,"\"%s.lc.lcg\"",mName.c_str());

	}
	void getLineColorB()
	{
		fprintf(mFile,"\"%s.lc.lcb\"",mName.c_str());

	}
	void getContrast()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getUWidth()
	{
		fprintf(mFile,"\"%s.uw\"",mName.c_str());

	}
	void getVWidth()
	{
		fprintf(mFile,"\"%s.vw\"",mName.c_str());

	}
protected:
	Grid(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_GRID_H__
