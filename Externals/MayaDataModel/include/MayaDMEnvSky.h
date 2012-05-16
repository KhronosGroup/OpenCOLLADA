/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVSKY_H__
#define __MayaDM_ENVSKY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTextureEnv.h"
namespace MayaDM
{
class EnvSky : public TextureEnv
{
public:
public:

	EnvSky():TextureEnv(){}
	EnvSky(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:TextureEnv(file, name, parent, "envSky", shared, create){}
	virtual ~EnvSky(){}

	void setTotalBrightness(float tb)
	{
		if(tb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tb\" %f;\n", tb);
	}
	void setSunBrightness(const float3& su)
	{
		if(su == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".su\" -type \"float3\" ");
		su.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSunBrightnessR(float sur)
	{
		if(sur == 0.0) return;
		fprintf(mFile,"\tsetAttr \".su.sur\" %f;\n", sur);
	}
	void setSunBrightnessG(float sug)
	{
		if(sug == 0.0) return;
		fprintf(mFile,"\tsetAttr \".su.sug\" %f;\n", sug);
	}
	void setSunBrightnessB(float sub)
	{
		if(sub == 0.0) return;
		fprintf(mFile,"\tsetAttr \".su.sub\" %f;\n", sub);
	}
	void setHaloBrightness(const float3& hb)
	{
		if(hb == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".hb\" -type \"float3\" ");
		hb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHaloBrightnessR(float hbr)
	{
		if(hbr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hb.hbr\" %f;\n", hbr);
	}
	void setHaloBrightnessG(float hbg)
	{
		if(hbg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hb.hbg\" %f;\n", hbg);
	}
	void setHaloBrightnessB(float hbb)
	{
		if(hbb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hb.hbb\" %f;\n", hbb);
	}
	void setElevation(double e)
	{
		if(e == 4) return;
		fprintf(mFile,"\tsetAttr \".e\" %f;\n", e);
	}
	void setAzimuth(double az)
	{
		if(az == 1) return;
		fprintf(mFile,"\tsetAttr \".az\" %f;\n", az);
	}
	void setSize(float sz)
	{
		if(sz == 0.531) return;
		fprintf(mFile,"\tsetAttr \".sz\" %f;\n", sz);
	}
	void setBlur(float b)
	{
		if(b == 1.0) return;
		fprintf(mFile,"\tsetAttr \".b\" %f;\n", b);
	}
	void setSkyBrightness(const float3& sk)
	{
		if(sk == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".sk\" -type \"float3\" ");
		sk.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSkyBrightnessR(float skr)
	{
		if(skr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sk.skr\" %f;\n", skr);
	}
	void setSkyBrightnessG(float skg)
	{
		if(skg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sk.skg\" %f;\n", skg);
	}
	void setSkyBrightnessB(float skb)
	{
		if(skb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sk.skb\" %f;\n", skb);
	}
	void setAirDensity(float ad)
	{
		if(ad == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ad\" %f;\n", ad);
	}
	void setDustDensity(float dd)
	{
		if(dd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dd\" %f;\n", dd);
	}
	void setSkyThickness(float st)
	{
		if(st == 1000.0) return;
		fprintf(mFile,"\tsetAttr \".st\" %f;\n", st);
	}
	void setSkyRadius(float sr)
	{
		if(sr == 50.0) return;
		fprintf(mFile,"\tsetAttr \".sr\" %f;\n", sr);
	}
	void setHasFloor(bool hf)
	{
		if(hf == true) return;
		fprintf(mFile,"\tsetAttr \".hf\" %i;\n", hf);
	}
	void setFloorColor(const float3& fc)
	{
		if(fc == float3(0.4f,0.4f,0.4f)) return;
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
		if(fa == -10.0) return;
		fprintf(mFile,"\tsetAttr \".fa\" %f;\n", fa);
	}
	void setUseTexture(bool ut)
	{
		if(ut == false) return;
		fprintf(mFile,"\tsetAttr \".ut\" %i;\n", ut);
	}
	void setCloudTexture(float ct)
	{
		if(ct == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ct\" %f;\n", ct);
	}
	void setCloudBrightness(const float3& cb)
	{
		if(cb == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".cb\" -type \"float3\" ");
		cb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCloudBrightnessR(float cbr)
	{
		if(cbr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cb.cbr\" %f;\n", cbr);
	}
	void setCloudBrightnessG(float cbg)
	{
		if(cbg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cb.cbg\" %f;\n", cbg);
	}
	void setCloudBrightnessB(float cbb)
	{
		if(cbb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cb.cbb\" %f;\n", cbb);
	}
	void setSunsetBrightness(const float3& ss)
	{
		if(ss == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".ss\" -type \"float3\" ");
		ss.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSunsetBrightnessR(float ssr)
	{
		if(ssr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ss.ssr\" %f;\n", ssr);
	}
	void setSunsetBrightnessG(float ssg)
	{
		if(ssg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ss.ssg\" %f;\n", ssg);
	}
	void setSunsetBrightnessB(float ssb)
	{
		if(ssb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ss.ssb\" %f;\n", ssb);
	}
	void setDensity(float d)
	{
		if(d == 1.0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setThreshold(float t)
	{
		if(t == 0.5) return;
		fprintf(mFile,"\tsetAttr \".t\" %f;\n", t);
	}
	void setPower(float po)
	{
		if(po == 1.0) return;
		fprintf(mFile,"\tsetAttr \".po\" %f;\n", po);
	}
	void setAltitude(float a)
	{
		if(a == 0.2) return;
		fprintf(mFile,"\tsetAttr \".a\" %f;\n", a);
	}
	void setHaloSize(float hs)
	{
		if(hs == 20.0) return;
		fprintf(mFile,"\tsetAttr \".hs\" %f;\n", hs);
	}
	void setSkySamples(float ssa)
	{
		if(ssa == 5.0) return;
		fprintf(mFile,"\tsetAttr \".ssa\" %f;\n", ssa);
	}
	void setFloorSamples(float fsa)
	{
		if(fsa == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fsa\" %f;\n", fsa);
	}
	void setCloudSamples(float csa)
	{
		if(csa == 5.0) return;
		fprintf(mFile,"\tsetAttr \".csa\" %f;\n", csa);
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
	void getRefPointCamera()const
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());
	}
	void getRefPointCameraX()const
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());
	}
	void getRefPointCameraY()const
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());
	}
	void getRefPointCameraZ()const
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());
	}
	void getTotalBrightness()const
	{
		fprintf(mFile,"\"%s.tb\"",mName.c_str());
	}
	void getSunBrightness()const
	{
		fprintf(mFile,"\"%s.su\"",mName.c_str());
	}
	void getSunBrightnessR()const
	{
		fprintf(mFile,"\"%s.su.sur\"",mName.c_str());
	}
	void getSunBrightnessG()const
	{
		fprintf(mFile,"\"%s.su.sug\"",mName.c_str());
	}
	void getSunBrightnessB()const
	{
		fprintf(mFile,"\"%s.su.sub\"",mName.c_str());
	}
	void getHaloBrightness()const
	{
		fprintf(mFile,"\"%s.hb\"",mName.c_str());
	}
	void getHaloBrightnessR()const
	{
		fprintf(mFile,"\"%s.hb.hbr\"",mName.c_str());
	}
	void getHaloBrightnessG()const
	{
		fprintf(mFile,"\"%s.hb.hbg\"",mName.c_str());
	}
	void getHaloBrightnessB()const
	{
		fprintf(mFile,"\"%s.hb.hbb\"",mName.c_str());
	}
	void getElevation()const
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());
	}
	void getAzimuth()const
	{
		fprintf(mFile,"\"%s.az\"",mName.c_str());
	}
	void getSize()const
	{
		fprintf(mFile,"\"%s.sz\"",mName.c_str());
	}
	void getBlur()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getSkyBrightness()const
	{
		fprintf(mFile,"\"%s.sk\"",mName.c_str());
	}
	void getSkyBrightnessR()const
	{
		fprintf(mFile,"\"%s.sk.skr\"",mName.c_str());
	}
	void getSkyBrightnessG()const
	{
		fprintf(mFile,"\"%s.sk.skg\"",mName.c_str());
	}
	void getSkyBrightnessB()const
	{
		fprintf(mFile,"\"%s.sk.skb\"",mName.c_str());
	}
	void getAirDensity()const
	{
		fprintf(mFile,"\"%s.ad\"",mName.c_str());
	}
	void getDustDensity()const
	{
		fprintf(mFile,"\"%s.dd\"",mName.c_str());
	}
	void getSkyThickness()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getSkyRadius()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getHasFloor()const
	{
		fprintf(mFile,"\"%s.hf\"",mName.c_str());
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
	void getUseTexture()const
	{
		fprintf(mFile,"\"%s.ut\"",mName.c_str());
	}
	void getCloudTexture()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getCloudBrightness()const
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());
	}
	void getCloudBrightnessR()const
	{
		fprintf(mFile,"\"%s.cb.cbr\"",mName.c_str());
	}
	void getCloudBrightnessG()const
	{
		fprintf(mFile,"\"%s.cb.cbg\"",mName.c_str());
	}
	void getCloudBrightnessB()const
	{
		fprintf(mFile,"\"%s.cb.cbb\"",mName.c_str());
	}
	void getSunsetBrightness()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getSunsetBrightnessR()const
	{
		fprintf(mFile,"\"%s.ss.ssr\"",mName.c_str());
	}
	void getSunsetBrightnessG()const
	{
		fprintf(mFile,"\"%s.ss.ssg\"",mName.c_str());
	}
	void getSunsetBrightnessB()const
	{
		fprintf(mFile,"\"%s.ss.ssb\"",mName.c_str());
	}
	void getDensity()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getThreshold()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getPower()const
	{
		fprintf(mFile,"\"%s.po\"",mName.c_str());
	}
	void getAltitude()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getHaloSize()const
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());
	}
	void getSkySamples()const
	{
		fprintf(mFile,"\"%s.ssa\"",mName.c_str());
	}
	void getFloorSamples()const
	{
		fprintf(mFile,"\"%s.fsa\"",mName.c_str());
	}
	void getCloudSamples()const
	{
		fprintf(mFile,"\"%s.csa\"",mName.c_str());
	}
protected:
	EnvSky(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:TextureEnv(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ENVSKY_H__
