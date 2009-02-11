/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVFOG_H__
#define __MayaDM_ENVFOG_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLightFog.h"
namespace MayaDM
{
class EnvFog : public LightFog
{
public:
public:
	EnvFog():LightFog(){}
	EnvFog(FILE* file,const std::string& name,const std::string& parent=""):LightFog(file, name, parent, "envFog"){}
	virtual ~EnvFog(){}
	void setDistanceClipPlanes(unsigned int dcp)
	{
		if(dcp == 1) return;
		fprintf(mFile,"\tsetAttr \".dcp\" %i;\n", dcp);

	}
	void setUseLayer(bool ul)
	{
		if(ul == false) return;
		fprintf(mFile,"\tsetAttr \".ul\" %i;\n", ul);

	}
	void setUseHeight(bool uh)
	{
		if(uh == false) return;
		fprintf(mFile,"\tsetAttr \".uh\" %i;\n", uh);

	}
	void setBlendRange(float br)
	{
		if(br == 1.0) return;
		fprintf(mFile,"\tsetAttr \".br\" %f;\n", br);

	}
	void setSaturationDistance(float sdt)
	{
		if(sdt == 100.0) return;
		fprintf(mFile,"\tsetAttr \".sdt\" %f;\n", sdt);

	}
	void setFogNearDistance(float fnd)
	{
		if(fnd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fnd\" %f;\n", fnd);

	}
	void setFogFarDistance(float ffd)
	{
		if(ffd == 200.0) return;
		fprintf(mFile,"\tsetAttr \".ffd\" %f;\n", ffd);

	}
	void setLayer(float l)
	{
		if(l == 1.0) return;
		fprintf(mFile,"\tsetAttr \".l\" %f;\n", l);

	}
	void setMinHeight(float mnh)
	{
		if(mnh == -1.0) return;
		fprintf(mFile,"\tsetAttr \".mnh\" %f;\n", mnh);

	}
	void setMaxHeight(float mxh)
	{
		if(mxh == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mxh\" %f;\n", mxh);

	}
	void setUseDistance(bool ud)
	{
		if(ud == false) return;
		fprintf(mFile,"\tsetAttr \".ud\" %i;\n", ud);

	}
	void setStartDistance(float sd)
	{
		if(sd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sd\" %f;\n", sd);

	}
	void setEndDistance(float ed)
	{
		if(ed == -1.0) return;
		fprintf(mFile,"\tsetAttr \".ed\" %f;\n", ed);

	}
	void setPhysicalFog(bool sff)
	{
		if(sff == false) return;
		fprintf(mFile,"\tsetAttr \".sff\" %i;\n", sff);

	}
	void setFogType(unsigned int ftp)
	{
		if(ftp == 0) return;
		fprintf(mFile,"\tsetAttr \".ftp\" %i;\n", ftp);

	}
	void setFogDensity(double fdn)
	{
		if(fdn == 0.4) return;
		fprintf(mFile,"\tsetAttr \".fdn\" %f;\n", fdn);

	}
	void setFogColor(const float3& fcl)
	{
		fprintf(mFile,"\tsetAttr \".fcl\" -type \"float3\" ");
		fcl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFogColorR(float fcr)
	{
		if(fcr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fcl.fcr\" %f;\n", fcr);

	}
	void setFogColorG(float fcg)
	{
		if(fcg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fcl.fcg\" %f;\n", fcg);

	}
	void setFogColorB(float fcb)
	{
		if(fcb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fcl.fcb\" %f;\n", fcb);

	}
	void setFogOpacity(const float3& fop)
	{
		fprintf(mFile,"\tsetAttr \".fop\" -type \"float3\" ");
		fop.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFogOpacityR(float for_)
	{
		if(for_ == 0.5) return;
		fprintf(mFile,"\tsetAttr \".fop.for\" %f;\n", for_);

	}
	void setFogOpacityG(float fog)
	{
		if(fog == 0.5) return;
		fprintf(mFile,"\tsetAttr \".fop.fog\" %f;\n", fog);

	}
	void setFogOpacityB(float fob)
	{
		if(fob == 0.5) return;
		fprintf(mFile,"\tsetAttr \".fop.fob\" %f;\n", fob);

	}
	void setFogMinHeight(double fmh)
	{
		if(fmh == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fmh\" %f;\n", fmh);

	}
	void setFogMaxHeight(double fxh)
	{
		if(fxh == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fxh\" %f;\n", fxh);

	}
	void setFogDecay(double fdc)
	{
		if(fdc == 0.2) return;
		fprintf(mFile,"\tsetAttr \".fdc\" %f;\n", fdc);

	}
	void setFogLightScatter(double flc)
	{
		if(flc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".flc\" %f;\n", flc);

	}
	void setAirDensity(double adn)
	{
		if(adn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".adn\" %f;\n", adn);

	}
	void setAirColor(const float3& acl)
	{
		fprintf(mFile,"\tsetAttr \".acl\" -type \"float3\" ");
		acl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAirColorR(float acr)
	{
		if(acr == 0.6) return;
		fprintf(mFile,"\tsetAttr \".acl.acr\" %f;\n", acr);

	}
	void setAirColorG(float acg)
	{
		if(acg == 0.8) return;
		fprintf(mFile,"\tsetAttr \".acl.acg\" %f;\n", acg);

	}
	void setAirColorB(float acb)
	{
		if(acb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".acl.acb\" %f;\n", acb);

	}
	void setAirOpacity(const float3& aop)
	{
		fprintf(mFile,"\tsetAttr \".aop\" -type \"float3\" ");
		aop.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAirOpacityR(float aor)
	{
		if(aor == 0.37) return;
		fprintf(mFile,"\tsetAttr \".aop.aor\" %f;\n", aor);

	}
	void setAirOpacityG(float aog)
	{
		if(aog == 0.47) return;
		fprintf(mFile,"\tsetAttr \".aop.aog\" %f;\n", aog);

	}
	void setAirOpacityB(float aob)
	{
		if(aob == 0.9) return;
		fprintf(mFile,"\tsetAttr \".aop.aob\" %f;\n", aob);

	}
	void setAirMinHeight(double amh)
	{
		if(amh == 0.0) return;
		fprintf(mFile,"\tsetAttr \".amh\" %f;\n", amh);

	}
	void setAirMaxHeight(double axh)
	{
		if(axh == 50.0) return;
		fprintf(mFile,"\tsetAttr \".axh\" %f;\n", axh);

	}
	void setAirDecay(double adc)
	{
		if(adc == 0.1) return;
		fprintf(mFile,"\tsetAttr \".adc\" %f;\n", adc);

	}
	void setAirLightScatter(double alc)
	{
		if(alc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".alc\" %f;\n", alc);

	}
	void setWaterDensity(double wdn)
	{
		if(wdn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wdn\" %f;\n", wdn);

	}
	void setWaterColor(const float3& wcl)
	{
		fprintf(mFile,"\tsetAttr \".wcl\" -type \"float3\" ");
		wcl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWaterColorR(float wcr)
	{
		if(wcr == 0.6) return;
		fprintf(mFile,"\tsetAttr \".wcl.wcr\" %f;\n", wcr);

	}
	void setWaterColorG(float wcg)
	{
		if(wcg == 0.8) return;
		fprintf(mFile,"\tsetAttr \".wcl.wcg\" %f;\n", wcg);

	}
	void setWaterColorB(float wcb)
	{
		if(wcb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".wcl.wcb\" %f;\n", wcb);

	}
	void setWaterOpacity(const float3& wop)
	{
		fprintf(mFile,"\tsetAttr \".wop\" -type \"float3\" ");
		wop.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWaterOpacityR(float wor)
	{
		if(wor == 0.37) return;
		fprintf(mFile,"\tsetAttr \".wop.wor\" %f;\n", wor);

	}
	void setWaterOpacityG(float wog)
	{
		if(wog == 0.47) return;
		fprintf(mFile,"\tsetAttr \".wop.wog\" %f;\n", wog);

	}
	void setWaterOpacityB(float wob)
	{
		if(wob == 0.9) return;
		fprintf(mFile,"\tsetAttr \".wop.wob\" %f;\n", wob);

	}
	void setWaterLevel(double wlv)
	{
		if(wlv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wlv\" %f;\n", wlv);

	}
	void setWaterDepth(double wdp)
	{
		if(wdp == 50.0) return;
		fprintf(mFile,"\tsetAttr \".wdp\" %f;\n", wdp);

	}
	void setWaterLightDecay(double wdc)
	{
		if(wdc == 2.0) return;
		fprintf(mFile,"\tsetAttr \".wdc\" %f;\n", wdc);

	}
	void setWaterLightScatter(double wlc)
	{
		if(wlc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".wlc\" %f;\n", wlc);

	}
	void setPlanetRadius(double prd)
	{
		if(prd == 1000.0) return;
		fprintf(mFile,"\tsetAttr \".prd\" %f;\n", prd);

	}
	void setFogAxis(unsigned int fax)
	{
		if(fax == 0) return;
		fprintf(mFile,"\tsetAttr \".fax\" %i;\n", fax);

	}
	void setSunIntensity(double sin)
	{
		if(sin == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sin\" %f;\n", sin);

	}
	void setSunAzimuth(double saz)
	{
		if(saz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".saz\" %f;\n", saz);

	}
	void setSunElevation(double sel)
	{
		if(sel == 45.0) return;
		fprintf(mFile,"\tsetAttr \".sel\" %f;\n", sel);

	}
	void setSunColor(const float3& snc)
	{
		fprintf(mFile,"\tsetAttr \".snc\" -type \"float3\" ");
		snc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSunColorR(float snr)
	{
		if(snr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".snc.snr\" %f;\n", snr);

	}
	void setSunColorG(float sng)
	{
		if(sng == 1.0) return;
		fprintf(mFile,"\tsetAttr \".snc.sng\" %f;\n", sng);

	}
	void setSunColorB(float snb)
	{
		if(snb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".snc.snb\" %f;\n", snb);

	}
	void getMatrixEyeToWorld()
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());

	}
	void getPointCamera()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getPointCameraX()
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());

	}
	void getPointCameraY()
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());

	}
	void getPointCameraZ()
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());

	}
	void getPointWorld()
	{
		fprintf(mFile,"\"%s.pw\"",mName.c_str());

	}
	void getPointWorldX()
	{
		fprintf(mFile,"\"%s.pw.pwx\"",mName.c_str());

	}
	void getPointWorldY()
	{
		fprintf(mFile,"\"%s.pw.pwy\"",mName.c_str());

	}
	void getPointWorldZ()
	{
		fprintf(mFile,"\"%s.pw.pwz\"",mName.c_str());

	}
	void getRayDirection()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getRayDirectionX()
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());

	}
	void getRayDirectionY()
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());

	}
	void getRayDirectionZ()
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());

	}
	void getDistanceClipPlanes()
	{
		fprintf(mFile,"\"%s.dcp\"",mName.c_str());

	}
	void getUseLayer()
	{
		fprintf(mFile,"\"%s.ul\"",mName.c_str());

	}
	void getUseHeight()
	{
		fprintf(mFile,"\"%s.uh\"",mName.c_str());

	}
	void getBlendRange()
	{
		fprintf(mFile,"\"%s.br\"",mName.c_str());

	}
	void getSaturationDistance()
	{
		fprintf(mFile,"\"%s.sdt\"",mName.c_str());

	}
	void getFogNearDistance()
	{
		fprintf(mFile,"\"%s.fnd\"",mName.c_str());

	}
	void getFogFarDistance()
	{
		fprintf(mFile,"\"%s.ffd\"",mName.c_str());

	}
	void getLayer()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getMinHeight()
	{
		fprintf(mFile,"\"%s.mnh\"",mName.c_str());

	}
	void getMaxHeight()
	{
		fprintf(mFile,"\"%s.mxh\"",mName.c_str());

	}
	void getUseDistance()
	{
		fprintf(mFile,"\"%s.ud\"",mName.c_str());

	}
	void getStartDistance()
	{
		fprintf(mFile,"\"%s.sd\"",mName.c_str());

	}
	void getEndDistance()
	{
		fprintf(mFile,"\"%s.ed\"",mName.c_str());

	}
	void getPhysicalFog()
	{
		fprintf(mFile,"\"%s.sff\"",mName.c_str());

	}
	void getFogType()
	{
		fprintf(mFile,"\"%s.ftp\"",mName.c_str());

	}
	void getFogDensity()
	{
		fprintf(mFile,"\"%s.fdn\"",mName.c_str());

	}
	void getFogColor()
	{
		fprintf(mFile,"\"%s.fcl\"",mName.c_str());

	}
	void getFogColorR()
	{
		fprintf(mFile,"\"%s.fcl.fcr\"",mName.c_str());

	}
	void getFogColorG()
	{
		fprintf(mFile,"\"%s.fcl.fcg\"",mName.c_str());

	}
	void getFogColorB()
	{
		fprintf(mFile,"\"%s.fcl.fcb\"",mName.c_str());

	}
	void getFogOpacity()
	{
		fprintf(mFile,"\"%s.fop\"",mName.c_str());

	}
	void getFogOpacityR()
	{
		fprintf(mFile,"\"%s.fop.for\"",mName.c_str());

	}
	void getFogOpacityG()
	{
		fprintf(mFile,"\"%s.fop.fog\"",mName.c_str());

	}
	void getFogOpacityB()
	{
		fprintf(mFile,"\"%s.fop.fob\"",mName.c_str());

	}
	void getFogMinHeight()
	{
		fprintf(mFile,"\"%s.fmh\"",mName.c_str());

	}
	void getFogMaxHeight()
	{
		fprintf(mFile,"\"%s.fxh\"",mName.c_str());

	}
	void getFogDecay()
	{
		fprintf(mFile,"\"%s.fdc\"",mName.c_str());

	}
	void getFogLightScatter()
	{
		fprintf(mFile,"\"%s.flc\"",mName.c_str());

	}
	void getAirDensity()
	{
		fprintf(mFile,"\"%s.adn\"",mName.c_str());

	}
	void getAirColor()
	{
		fprintf(mFile,"\"%s.acl\"",mName.c_str());

	}
	void getAirColorR()
	{
		fprintf(mFile,"\"%s.acl.acr\"",mName.c_str());

	}
	void getAirColorG()
	{
		fprintf(mFile,"\"%s.acl.acg\"",mName.c_str());

	}
	void getAirColorB()
	{
		fprintf(mFile,"\"%s.acl.acb\"",mName.c_str());

	}
	void getAirOpacity()
	{
		fprintf(mFile,"\"%s.aop\"",mName.c_str());

	}
	void getAirOpacityR()
	{
		fprintf(mFile,"\"%s.aop.aor\"",mName.c_str());

	}
	void getAirOpacityG()
	{
		fprintf(mFile,"\"%s.aop.aog\"",mName.c_str());

	}
	void getAirOpacityB()
	{
		fprintf(mFile,"\"%s.aop.aob\"",mName.c_str());

	}
	void getAirMinHeight()
	{
		fprintf(mFile,"\"%s.amh\"",mName.c_str());

	}
	void getAirMaxHeight()
	{
		fprintf(mFile,"\"%s.axh\"",mName.c_str());

	}
	void getAirDecay()
	{
		fprintf(mFile,"\"%s.adc\"",mName.c_str());

	}
	void getAirLightScatter()
	{
		fprintf(mFile,"\"%s.alc\"",mName.c_str());

	}
	void getWaterDensity()
	{
		fprintf(mFile,"\"%s.wdn\"",mName.c_str());

	}
	void getWaterColor()
	{
		fprintf(mFile,"\"%s.wcl\"",mName.c_str());

	}
	void getWaterColorR()
	{
		fprintf(mFile,"\"%s.wcl.wcr\"",mName.c_str());

	}
	void getWaterColorG()
	{
		fprintf(mFile,"\"%s.wcl.wcg\"",mName.c_str());

	}
	void getWaterColorB()
	{
		fprintf(mFile,"\"%s.wcl.wcb\"",mName.c_str());

	}
	void getWaterOpacity()
	{
		fprintf(mFile,"\"%s.wop\"",mName.c_str());

	}
	void getWaterOpacityR()
	{
		fprintf(mFile,"\"%s.wop.wor\"",mName.c_str());

	}
	void getWaterOpacityG()
	{
		fprintf(mFile,"\"%s.wop.wog\"",mName.c_str());

	}
	void getWaterOpacityB()
	{
		fprintf(mFile,"\"%s.wop.wob\"",mName.c_str());

	}
	void getWaterLevel()
	{
		fprintf(mFile,"\"%s.wlv\"",mName.c_str());

	}
	void getWaterDepth()
	{
		fprintf(mFile,"\"%s.wdp\"",mName.c_str());

	}
	void getWaterLightDecay()
	{
		fprintf(mFile,"\"%s.wdc\"",mName.c_str());

	}
	void getWaterLightScatter()
	{
		fprintf(mFile,"\"%s.wlc\"",mName.c_str());

	}
	void getPlanetRadius()
	{
		fprintf(mFile,"\"%s.prd\"",mName.c_str());

	}
	void getFogAxis()
	{
		fprintf(mFile,"\"%s.fax\"",mName.c_str());

	}
	void getSunIntensity()
	{
		fprintf(mFile,"\"%s.sin\"",mName.c_str());

	}
	void getSunAzimuth()
	{
		fprintf(mFile,"\"%s.saz\"",mName.c_str());

	}
	void getSunElevation()
	{
		fprintf(mFile,"\"%s.sel\"",mName.c_str());

	}
	void getSunColor()
	{
		fprintf(mFile,"\"%s.snc\"",mName.c_str());

	}
	void getSunColorR()
	{
		fprintf(mFile,"\"%s.snc.snr\"",mName.c_str());

	}
	void getSunColorG()
	{
		fprintf(mFile,"\"%s.snc.sng\"",mName.c_str());

	}
	void getSunColorB()
	{
		fprintf(mFile,"\"%s.snc.snb\"",mName.c_str());

	}
protected:
	EnvFog(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:LightFog(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ENVFOG_H__
