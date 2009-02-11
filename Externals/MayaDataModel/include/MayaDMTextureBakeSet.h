/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TEXTUREBAKESET_H__
#define __MayaDM_TEXTUREBAKESET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBakeSet.h"
namespace MayaDM
{
class TextureBakeSet : public BakeSet
{
public:
public:
	TextureBakeSet():BakeSet(){}
	TextureBakeSet(FILE* file,const std::string& name,const std::string& parent=""):BakeSet(file, name, parent, "textureBakeSet"){}
	virtual ~TextureBakeSet(){}
	void setSeparation(unsigned int sep)
	{
		if(sep == 0) return;
		fprintf(mFile,"\tsetAttr \".sep\" %i;\n", sep);

	}
	void setXResolution(int xres)
	{
		if(xres == 512) return;
		fprintf(mFile,"\tsetAttr \".xres\" %i;\n", xres);

	}
	void setYResolution(int yres)
	{
		if(yres == 512) return;
		fprintf(mFile,"\tsetAttr \".yres\" %i;\n", yres);

	}
	void setFileFormat(unsigned int format)
	{
		if(format == 0) return;
		fprintf(mFile,"\tsetAttr \".format\" %i;\n", format);

	}
	void setBitsPerChannel(unsigned int bits)
	{
		if(bits == 0) return;
		fprintf(mFile,"\tsetAttr \".bits\" %i;\n", bits);

	}
	void setOverrideUvSet(bool overrideuv)
	{
		if(overrideuv == 0) return;
		fprintf(mFile,"\tsetAttr \".overrideuv\" %i;\n", overrideuv);

	}
	void setUvSetName(const string& set)
	{
		if(set == "uvSet1") return;
		fprintf(mFile,"\tsetAttr \".set\" -type \"string\" ");
		set.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvRange(unsigned int range)
	{
		if(range == 0) return;
		fprintf(mFile,"\tsetAttr \".range\" %i;\n", range);

	}
	void setUMin(float ul)
	{
		if(ul == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ul\" %f;\n", ul);

	}
	void setUMax(float uh)
	{
		if(uh == 1.0) return;
		fprintf(mFile,"\tsetAttr \".uh\" %f;\n", uh);

	}
	void setVMin(float vl)
	{
		if(vl == 1.0) return;
		fprintf(mFile,"\tsetAttr \".vl\" %f;\n", vl);

	}
	void setVMax(float vh)
	{
		if(vh == 1.0) return;
		fprintf(mFile,"\tsetAttr \".vh\" %f;\n", vh);

	}
	void setBackgroundMode(unsigned int bmode)
	{
		if(bmode == 0) return;
		fprintf(mFile,"\tsetAttr \".bmode\" %i;\n", bmode);

	}
	void setBackgroundColor(const float3& bgc)
	{
		if(bgc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".bgc\" -type \"float3\" ");
		bgc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBackgroundColorR(float bgr)
	{
		if(bgr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bgc.bgr\" %f;\n", bgr);

	}
	void setBackgroundColorG(float bgg)
	{
		if(bgg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bgc.bgg\" %f;\n", bgg);

	}
	void setBackgroundColorB(float bgb)
	{
		if(bgb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bgc.bgb\" %f;\n", bgb);

	}
	void setFillTextureSeams(float fillseams)
	{
		if(fillseams == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fillseams\" %f;\n", fillseams);

	}
	void setFinalGatherQuality(float fgq)
	{
		if(fgq == 1) return;
		fprintf(mFile,"\tsetAttr \".fgq\" %f;\n", fgq);

	}
	void setFinalGatherReflect(float fgr)
	{
		if(fgr == 0) return;
		fprintf(mFile,"\tsetAttr \".fgr\" %f;\n", fgr);

	}
	void setBakeToOneMap(bool one)
	{
		if(one == 0) return;
		fprintf(mFile,"\tsetAttr \".one\" %i;\n", one);

	}
	void setSamples(int nsp)
	{
		if(nsp == 1) return;
		fprintf(mFile,"\tsetAttr \".nsp\" %i;\n", nsp);

	}
	void getSeparation()
	{
		fprintf(mFile,"\"%s.sep\"",mName.c_str());

	}
	void getPrefix()
	{
		fprintf(mFile,"\"%s.pre\"",mName.c_str());

	}
	void getXResolution()
	{
		fprintf(mFile,"\"%s.xres\"",mName.c_str());

	}
	void getYResolution()
	{
		fprintf(mFile,"\"%s.yres\"",mName.c_str());

	}
	void getFileFormat()
	{
		fprintf(mFile,"\"%s.format\"",mName.c_str());

	}
	void getBitsPerChannel()
	{
		fprintf(mFile,"\"%s.bits\"",mName.c_str());

	}
	void getOverrideUvSet()
	{
		fprintf(mFile,"\"%s.overrideuv\"",mName.c_str());

	}
	void getUvSetName()
	{
		fprintf(mFile,"\"%s.set\"",mName.c_str());

	}
	void getUvRange()
	{
		fprintf(mFile,"\"%s.range\"",mName.c_str());

	}
	void getUMin()
	{
		fprintf(mFile,"\"%s.ul\"",mName.c_str());

	}
	void getUMax()
	{
		fprintf(mFile,"\"%s.uh\"",mName.c_str());

	}
	void getVMin()
	{
		fprintf(mFile,"\"%s.vl\"",mName.c_str());

	}
	void getVMax()
	{
		fprintf(mFile,"\"%s.vh\"",mName.c_str());

	}
	void getBackgroundMode()
	{
		fprintf(mFile,"\"%s.bmode\"",mName.c_str());

	}
	void getBackgroundColor()
	{
		fprintf(mFile,"\"%s.bgc\"",mName.c_str());

	}
	void getBackgroundColorR()
	{
		fprintf(mFile,"\"%s.bgc.bgr\"",mName.c_str());

	}
	void getBackgroundColorG()
	{
		fprintf(mFile,"\"%s.bgc.bgg\"",mName.c_str());

	}
	void getBackgroundColorB()
	{
		fprintf(mFile,"\"%s.bgc.bgb\"",mName.c_str());

	}
	void getFillTextureSeams()
	{
		fprintf(mFile,"\"%s.fillseams\"",mName.c_str());

	}
	void getFillScale()
	{
		fprintf(mFile,"\"%s.fillscale\"",mName.c_str());

	}
	void getFinalGatherQuality()
	{
		fprintf(mFile,"\"%s.fgq\"",mName.c_str());

	}
	void getFinalGatherReflect()
	{
		fprintf(mFile,"\"%s.fgr\"",mName.c_str());

	}
	void getBakeToOneMap()
	{
		fprintf(mFile,"\"%s.one\"",mName.c_str());

	}
	void getSamples()
	{
		fprintf(mFile,"\"%s.nsp\"",mName.c_str());

	}
protected:
	TextureBakeSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:BakeSet(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TEXTUREBAKESET_H__
