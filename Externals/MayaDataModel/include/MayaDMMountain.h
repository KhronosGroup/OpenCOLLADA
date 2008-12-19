/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MOUNTAIN_H__
#define __MayaDM_MOUNTAIN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Mountain : public Texture2d
{
public:
public:
	Mountain(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "mountain"){}
	virtual ~Mountain(){}
	void setSnowColor(const float3& sc)
	{
		if(sc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSnowColorR(float scr)
	{
		if(scr == 0.0) return;
		fprintf(mFile,"setAttr \".sc.scr\" %f;\n", scr);

	}
	void setSnowColorG(float scg)
	{
		if(scg == 0.0) return;
		fprintf(mFile,"setAttr \".sc.scg\" %f;\n", scg);

	}
	void setSnowColorB(float scb)
	{
		if(scb == 0.0) return;
		fprintf(mFile,"setAttr \".sc.scb\" %f;\n", scb);

	}
	void setRockColor(const float3& rc)
	{
		if(rc == float3(0.262f,0.102f,0.0f)) return;
		fprintf(mFile,"setAttr \".rc\" -type \"float3\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRockColorR(float rcr)
	{
		if(rcr == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rcr\" %f;\n", rcr);

	}
	void setRockColorG(float rcg)
	{
		if(rcg == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rcg\" %f;\n", rcg);

	}
	void setRockColorB(float rcb)
	{
		if(rcb == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rcb\" %f;\n", rcb);

	}
	void setAmplitude(float a)
	{
		if(a == 1.0) return;
		fprintf(mFile,"setAttr \".a\" %f;\n", a);

	}
	void setSnowRoughness(float sr)
	{
		if(sr == 0.4) return;
		fprintf(mFile,"setAttr \".sr\" %f;\n", sr);

	}
	void setRockRoughness(float rr)
	{
		if(rr == 0.707) return;
		fprintf(mFile,"setAttr \".rr\" %f;\n", rr);

	}
	void setBoundary(float bo)
	{
		if(bo == 1.0) return;
		fprintf(mFile,"setAttr \".bo\" %f;\n", bo);

	}
	void setSnowAltitude(float sa)
	{
		if(sa == 0.5) return;
		fprintf(mFile,"setAttr \".sa\" %f;\n", sa);

	}
	void setSnowDropoff(float sd)
	{
		if(sd == 2.0) return;
		fprintf(mFile,"setAttr \".sd\" %f;\n", sd);

	}
	void setSnowSlope(float ss)
	{
		if(ss == 0.8) return;
		fprintf(mFile,"setAttr \".ss\" %f;\n", ss);

	}
	void setDepthMax(float dmx)
	{
		if(dmx == 20.0) return;
		fprintf(mFile,"setAttr \".dmx\" %f;\n", dmx);

	}
	void getSnowColor()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getSnowColorR()
	{
		fprintf(mFile,"\"%s.sc.scr\"",mName.c_str());

	}
	void getSnowColorG()
	{
		fprintf(mFile,"\"%s.sc.scg\"",mName.c_str());

	}
	void getSnowColorB()
	{
		fprintf(mFile,"\"%s.sc.scb\"",mName.c_str());

	}
	void getRockColor()
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());

	}
	void getRockColorR()
	{
		fprintf(mFile,"\"%s.rc.rcr\"",mName.c_str());

	}
	void getRockColorG()
	{
		fprintf(mFile,"\"%s.rc.rcg\"",mName.c_str());

	}
	void getRockColorB()
	{
		fprintf(mFile,"\"%s.rc.rcb\"",mName.c_str());

	}
	void getAmplitude()
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());

	}
	void getSnowRoughness()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getRockRoughness()
	{
		fprintf(mFile,"\"%s.rr\"",mName.c_str());

	}
	void getBoundary()
	{
		fprintf(mFile,"\"%s.bo\"",mName.c_str());

	}
	void getSnowAltitude()
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());

	}
	void getSnowDropoff()
	{
		fprintf(mFile,"\"%s.sd\"",mName.c_str());

	}
	void getSnowSlope()
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getDepthMax()
	{
		fprintf(mFile,"\"%s.dmx\"",mName.c_str());

	}
protected:
	Mountain(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MOUNTAIN_H__
