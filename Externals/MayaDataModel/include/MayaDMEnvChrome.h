/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVCHROME_H__
#define __MayaDM_ENVCHROME_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTextureEnv.h"
namespace MayaDM
{
class EnvChrome : public TextureEnv
{
public:
public:

	EnvChrome():TextureEnv(){}
	EnvChrome(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:TextureEnv(file, name, parent, "envChrome", shared, create){}
	virtual ~EnvChrome(){}

	void setSkyColor(const float3& sc)
	{
		if(sc == float3(0.784f,0.784f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSkyColorR(float scr)
	{
		if(scr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc.scr\" %f;\n", scr);
	}
	void setSkyColorG(float scg)
	{
		if(scg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc.scg\" %f;\n", scg);
	}
	void setSkyColorB(float scb)
	{
		if(scb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc.scb\" %f;\n", scb);
	}
	void setZenithColor(const float3& zc)
	{
		if(zc == float3(0.392f,0.392f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".zc\" -type \"float3\" ");
		zc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setZenithColorR(float zcr)
	{
		if(zcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".zc.zcr\" %f;\n", zcr);
	}
	void setZenithColorG(float zcg)
	{
		if(zcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".zc.zcg\" %f;\n", zcg);
	}
	void setZenithColorB(float zcb)
	{
		if(zcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".zc.zcb\" %f;\n", zcb);
	}
	void setLightColor(const float3& lc)
	{
		if(lc == float3(0.784f,0.784f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".lc\" -type \"float3\" ");
		lc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLightColorR(float lcr)
	{
		if(lcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lc.lcr\" %f;\n", lcr);
	}
	void setLightColorG(float lcg)
	{
		if(lcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lc.lcg\" %f;\n", lcg);
	}
	void setLightColorB(float lcb)
	{
		if(lcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lc.lcb\" %f;\n", lcb);
	}
	void setLightWidth(float lw)
	{
		if(lw == 0.5) return;
		fprintf(mFile,"\tsetAttr \".lw\" %f;\n", lw);
	}
	void setLightWidthGain(float lwg)
	{
		if(lwg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lwg\" %f;\n", lwg);
	}
	void setLightWidthOffset(float lwo)
	{
		if(lwo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lwo\" %f;\n", lwo);
	}
	void setLightDepth(float ld)
	{
		if(ld == 0.1) return;
		fprintf(mFile,"\tsetAttr \".ld\" %f;\n", ld);
	}
	void setLightDepthGain(float ldg)
	{
		if(ldg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ldg\" %f;\n", ldg);
	}
	void setLightDepthOffset(float ldo)
	{
		if(ldo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ldo\" %f;\n", ldo);
	}
	void setRealFloor(bool rf)
	{
		if(rf == true) return;
		fprintf(mFile,"\tsetAttr \".rf\" %i;\n", rf);
	}
	void setFloorColor(const float3& fc)
	{
		if(fc == float3(0.588f,0.588f,0.784f)) return;
		fprintf(mFile,"\tsetAttr \".fc\" -type \"float3\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFloorColorR(float fcr)
	{
		if(fcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcr\" %f;\n", fcr);
	}
	void setFloorColorG(float fcg)
	{
		if(fcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcg\" %f;\n", fcg);
	}
	void setFloorColorB(float fcb)
	{
		if(fcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcb\" %f;\n", fcb);
	}
	void setFloorAltitude(float fa)
	{
		if(fa == -1.0) return;
		fprintf(mFile,"\tsetAttr \".fa\" %f;\n", fa);
	}
	void setHorizonColor(const float3& hc)
	{
		if(hc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".hc\" -type \"float3\" ");
		hc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHorizonColorR(float hcr)
	{
		if(hcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hc.hcr\" %f;\n", hcr);
	}
	void setHorizonColorG(float hcg)
	{
		if(hcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hc.hcg\" %f;\n", hcg);
	}
	void setHorizonColorB(float hcb)
	{
		if(hcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hc.hcb\" %f;\n", hcb);
	}
	void setGridColor(const float3& gc)
	{
		if(gc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".gc\" -type \"float3\" ");
		gc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGridColorR(float gcr)
	{
		if(gcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gcr\" %f;\n", gcr);
	}
	void setGridColorG(float gcg)
	{
		if(gcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gcg\" %f;\n", gcg);
	}
	void setGridColorB(float gcb)
	{
		if(gcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gcb\" %f;\n", gcb);
	}
	void setGridWidth(float gw)
	{
		if(gw == 0.1) return;
		fprintf(mFile,"\tsetAttr \".gw\" %f;\n", gw);
	}
	void setGridWidthGain(float gwg)
	{
		if(gwg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gwg\" %f;\n", gwg);
	}
	void setGridWidthOffset(float gwo)
	{
		if(gwo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gwo\" %f;\n", gwo);
	}
	void setGridDepth(float gd)
	{
		if(gd == 0.1) return;
		fprintf(mFile,"\tsetAttr \".gd\" %f;\n", gd);
	}
	void setGridDepthGain(float gdg)
	{
		if(gdg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gdg\" %f;\n", gdg);
	}
	void setGridDepthOffset(float gdo)
	{
		if(gdo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gdo\" %f;\n", gdo);
	}
	void getPointCamera()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPointCameraX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPointCameraY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPointCameraZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getSkyColor()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getSkyColorR()const
	{
		fprintf(mFile,"\"%s.sc.scr\"",mName.c_str());
	}
	void getSkyColorG()const
	{
		fprintf(mFile,"\"%s.sc.scg\"",mName.c_str());
	}
	void getSkyColorB()const
	{
		fprintf(mFile,"\"%s.sc.scb\"",mName.c_str());
	}
	void getZenithColor()const
	{
		fprintf(mFile,"\"%s.zc\"",mName.c_str());
	}
	void getZenithColorR()const
	{
		fprintf(mFile,"\"%s.zc.zcr\"",mName.c_str());
	}
	void getZenithColorG()const
	{
		fprintf(mFile,"\"%s.zc.zcg\"",mName.c_str());
	}
	void getZenithColorB()const
	{
		fprintf(mFile,"\"%s.zc.zcb\"",mName.c_str());
	}
	void getLightColor()const
	{
		fprintf(mFile,"\"%s.lc\"",mName.c_str());
	}
	void getLightColorR()const
	{
		fprintf(mFile,"\"%s.lc.lcr\"",mName.c_str());
	}
	void getLightColorG()const
	{
		fprintf(mFile,"\"%s.lc.lcg\"",mName.c_str());
	}
	void getLightColorB()const
	{
		fprintf(mFile,"\"%s.lc.lcb\"",mName.c_str());
	}
	void getLightWidth()const
	{
		fprintf(mFile,"\"%s.lw\"",mName.c_str());
	}
	void getLightWidthGain()const
	{
		fprintf(mFile,"\"%s.lwg\"",mName.c_str());
	}
	void getLightWidthOffset()const
	{
		fprintf(mFile,"\"%s.lwo\"",mName.c_str());
	}
	void getLightDepth()const
	{
		fprintf(mFile,"\"%s.ld\"",mName.c_str());
	}
	void getLightDepthGain()const
	{
		fprintf(mFile,"\"%s.ldg\"",mName.c_str());
	}
	void getLightDepthOffset()const
	{
		fprintf(mFile,"\"%s.ldo\"",mName.c_str());
	}
	void getRealFloor()const
	{
		fprintf(mFile,"\"%s.rf\"",mName.c_str());
	}
	void getFloorColor()const
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getFloorColorR()const
	{
		fprintf(mFile,"\"%s.fc.fcr\"",mName.c_str());
	}
	void getFloorColorG()const
	{
		fprintf(mFile,"\"%s.fc.fcg\"",mName.c_str());
	}
	void getFloorColorB()const
	{
		fprintf(mFile,"\"%s.fc.fcb\"",mName.c_str());
	}
	void getFloorAltitude()const
	{
		fprintf(mFile,"\"%s.fa\"",mName.c_str());
	}
	void getHorizonColor()const
	{
		fprintf(mFile,"\"%s.hc\"",mName.c_str());
	}
	void getHorizonColorR()const
	{
		fprintf(mFile,"\"%s.hc.hcr\"",mName.c_str());
	}
	void getHorizonColorG()const
	{
		fprintf(mFile,"\"%s.hc.hcg\"",mName.c_str());
	}
	void getHorizonColorB()const
	{
		fprintf(mFile,"\"%s.hc.hcb\"",mName.c_str());
	}
	void getGridColor()const
	{
		fprintf(mFile,"\"%s.gc\"",mName.c_str());
	}
	void getGridColorR()const
	{
		fprintf(mFile,"\"%s.gc.gcr\"",mName.c_str());
	}
	void getGridColorG()const
	{
		fprintf(mFile,"\"%s.gc.gcg\"",mName.c_str());
	}
	void getGridColorB()const
	{
		fprintf(mFile,"\"%s.gc.gcb\"",mName.c_str());
	}
	void getGridWidth()const
	{
		fprintf(mFile,"\"%s.gw\"",mName.c_str());
	}
	void getGridWidthGain()const
	{
		fprintf(mFile,"\"%s.gwg\"",mName.c_str());
	}
	void getGridWidthOffset()const
	{
		fprintf(mFile,"\"%s.gwo\"",mName.c_str());
	}
	void getGridDepth()const
	{
		fprintf(mFile,"\"%s.gd\"",mName.c_str());
	}
	void getGridDepthGain()const
	{
		fprintf(mFile,"\"%s.gdg\"",mName.c_str());
	}
	void getGridDepthOffset()const
	{
		fprintf(mFile,"\"%s.gdo\"",mName.c_str());
	}
protected:
	EnvChrome(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:TextureEnv(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ENVCHROME_H__
