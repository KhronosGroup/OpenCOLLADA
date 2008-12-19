/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OCEANSHADER_H__
#define __MayaDM_OCEANSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class OceanShader : public DependNode
{
public:
	struct Environment{
		float environment_Position;
		float3 environment_Color;
		unsigned int environment_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", environment_Position);
			environment_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", environment_Interp);
		}
	};
	struct WaveHeight{
		float waveHeight_Position;
		float waveHeight_FloatValue;
		unsigned int waveHeight_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", waveHeight_Position);
			fprintf(file,"%f ", waveHeight_FloatValue);
			fprintf(file,"%i", waveHeight_Interp);
		}
	};
	struct WaveTurbulence{
		float waveTurbulence_Position;
		float waveTurbulence_FloatValue;
		unsigned int waveTurbulence_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", waveTurbulence_Position);
			fprintf(file,"%f ", waveTurbulence_FloatValue);
			fprintf(file,"%i", waveTurbulence_Interp);
		}
	};
	struct WavePeaking{
		float wavePeaking_Position;
		float wavePeaking_FloatValue;
		unsigned int wavePeaking_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", wavePeaking_Position);
			fprintf(file,"%f ", wavePeaking_FloatValue);
			fprintf(file,"%i", wavePeaking_Interp);
		}
	};
public:
	OceanShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "oceanShader"){}
	virtual ~OceanShader(){}
	void setRefractionLimit(short rdl)
	{
		if(rdl == 6) return;
		fprintf(mFile,"setAttr \".rdl\" %i;\n", rdl);

	}
	void setRefractiveIndex(float rfi)
	{
		if(rfi == 1.3) return;
		fprintf(mFile,"setAttr \".rfi\" %f;\n", rfi);

	}
	void setRefractions(bool rfc)
	{
		if(rfc == false) return;
		fprintf(mFile,"setAttr \".rfc\" %i;\n", rfc);

	}
	void setDiffuse(float dc)
	{
		if(dc == 0.3) return;
		fprintf(mFile,"setAttr \".dc\" %f;\n", dc);

	}
	void setWaterColor(const float3& wc)
	{
		fprintf(mFile,"setAttr \".wc\" -type \"float3\" ");
		wc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWaterColorR(float wcr)
	{
		if(wcr == 0.0) return;
		fprintf(mFile,"setAttr \".wc.wcr\" %f;\n", wcr);

	}
	void setWaterColorG(float wcg)
	{
		if(wcg == 0.36) return;
		fprintf(mFile,"setAttr \".wc.wcg\" %f;\n", wcg);

	}
	void setWaterColorB(float wcb)
	{
		if(wcb == 0.4) return;
		fprintf(mFile,"setAttr \".wc.wcb\" %f;\n", wcb);

	}
	void setTransparency(const float3& it)
	{
		fprintf(mFile,"setAttr \".it\" -type \"float3\" ");
		it.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTransparencyR(float itr)
	{
		if(itr == 0.0) return;
		fprintf(mFile,"setAttr \".it.itr\" %f;\n", itr);

	}
	void setTransparencyG(float itg)
	{
		if(itg == 0.0) return;
		fprintf(mFile,"setAttr \".it.itg\" %f;\n", itg);

	}
	void setTransparencyB(float itb)
	{
		if(itb == 0.0) return;
		fprintf(mFile,"setAttr \".it.itb\" %f;\n", itb);

	}
	void setAmbientColor(const float3& ambc)
	{
		fprintf(mFile,"setAttr \".ambc\" -type \"float3\" ");
		ambc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAmbientColorR(float acr)
	{
		if(acr == 0.0) return;
		fprintf(mFile,"setAttr \".ambc.acr\" %f;\n", acr);

	}
	void setAmbientColorG(float acg)
	{
		if(acg == 0.0) return;
		fprintf(mFile,"setAttr \".ambc.acg\" %f;\n", acg);

	}
	void setAmbientColorB(float acb)
	{
		if(acb == 0.0) return;
		fprintf(mFile,"setAttr \".ambc.acb\" %f;\n", acb);

	}
	void setIncandescence(const float3& ic)
	{
		fprintf(mFile,"setAttr \".ic\" -type \"float3\" ");
		ic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIncandescenceR(float ir)
	{
		if(ir == 0.0) return;
		fprintf(mFile,"setAttr \".ic.ir\" %f;\n", ir);

	}
	void setIncandescenceG(float ig)
	{
		if(ig == 0.0) return;
		fprintf(mFile,"setAttr \".ic.ig\" %f;\n", ig);

	}
	void setIncandescenceB(float ib)
	{
		if(ib == 0.0) return;
		fprintf(mFile,"setAttr \".ic.ib\" %f;\n", ib);

	}
	void setTranslucence(float tc)
	{
		if(tc == 0.3) return;
		fprintf(mFile,"setAttr \".tc\" %f;\n", tc);

	}
	void setTranslucenceFocus(float tcf)
	{
		if(tcf == 0.0) return;
		fprintf(mFile,"setAttr \".tcf\" %f;\n", tcf);

	}
	void setTranslucenceDepth(float trsd)
	{
		if(trsd == 10.0) return;
		fprintf(mFile,"setAttr \".trsd\" %f;\n", trsd);

	}
	void setOpacityDepth(float opad)
	{
		if(opad == 0.0) return;
		fprintf(mFile,"setAttr \".opad\" %f;\n", opad);

	}
	void setGlowIntensity(float gi)
	{
		if(gi == 0.0) return;
		fprintf(mFile,"setAttr \".gi\" %f;\n", gi);

	}
	void setSpecularGlow(float spg)
	{
		if(spg == 0.0) return;
		fprintf(mFile,"setAttr \".spg\" %f;\n", spg);

	}
	void setShadowAttenuation(float fakc)
	{
		if(fakc == 0.5) return;
		fprintf(mFile,"setAttr \".fakc\" %f;\n", fakc);

	}
	void setEccentricity(float ec)
	{
		if(ec == 0.03) return;
		fprintf(mFile,"setAttr \".ec\" %f;\n", ec);

	}
	void setSpecularity(float spl)
	{
		if(spl == 0.7) return;
		fprintf(mFile,"setAttr \".spl\" %f;\n", spl);

	}
	void setReflectionLimit(short fll)
	{
		if(fll == 1) return;
		fprintf(mFile,"setAttr \".fll\" %i;\n", fll);

	}
	void setSpecularColor(const float3& sc)
	{
		fprintf(mFile,"setAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpecularColorR(float sr)
	{
		if(sr == 1.0) return;
		fprintf(mFile,"setAttr \".sc.sr\" %f;\n", sr);

	}
	void setSpecularColorG(float sg)
	{
		if(sg == 1.0) return;
		fprintf(mFile,"setAttr \".sc.sg\" %f;\n", sg);

	}
	void setSpecularColorB(float sb)
	{
		if(sb == 1.0) return;
		fprintf(mFile,"setAttr \".sc.sb\" %f;\n", sb);

	}
	void setReflectivity(float rfl)
	{
		if(rfl == 0.7) return;
		fprintf(mFile,"setAttr \".rfl\" %f;\n", rfl);

	}
	void setEnvironment(size_t env_i,const Environment& env)
	{
		fprintf(mFile,"setAttr \".env[%i]\" ",env_i);
		env.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEnvironment_Position(size_t env_i,float envp)
	{
		if(envp == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envp\" %f;\n", env_i,envp);

	}
	void setEnvironment_Color(size_t env_i,const float3& envc)
	{
		fprintf(mFile,"setAttr \".env[%i].envc\" -type \"float3\" ",env_i);
		envc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEnvironment_ColorR(size_t env_i,float envcr)
	{
		if(envcr == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envc.envcr\" %f;\n", env_i,envcr);

	}
	void setEnvironment_ColorG(size_t env_i,float envcg)
	{
		if(envcg == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envc.envcg\" %f;\n", env_i,envcg);

	}
	void setEnvironment_ColorB(size_t env_i,float envcb)
	{
		if(envcb == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envc.envcb\" %f;\n", env_i,envcb);

	}
	void setEnvironment_Interp(size_t env_i,unsigned int envi)
	{
		if(envi == 0) return;
		fprintf(mFile,"setAttr \".env[%i].envi\" %i;\n", env_i,envi);

	}
	void setReflectedColor(const float3& rc)
	{
		fprintf(mFile,"setAttr \".rc\" -type \"float3\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setReflectedColorR(float rr)
	{
		if(rr == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rr\" %f;\n", rr);

	}
	void setReflectedColorG(float rg)
	{
		if(rg == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rg\" %f;\n", rg);

	}
	void setReflectedColorB(float rb)
	{
		if(rb == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rb\" %f;\n", rb);

	}
	void setReflectionSpecularity(float rsp)
	{
		if(rsp == 1.0) return;
		fprintf(mFile,"setAttr \".rsp\" %f;\n", rsp);

	}
	void setMatteOpacityMode(unsigned int mom)
	{
		if(mom == 2) return;
		fprintf(mFile,"setAttr \".mom\" %i;\n", mom);

	}
	void setMatteOpacity(float mog)
	{
		if(mog == 1.0) return;
		fprintf(mFile,"setAttr \".mog\" %f;\n", mog);

	}
	void setScale(float scl)
	{
		if(scl == 1.0) return;
		fprintf(mFile,"setAttr \".scl\" %f;\n", scl);

	}
	void setWindUV(const float2& wi)
	{
		if(wi == float2(1.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".wi\" -type \"float2\" ");
		wi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWindU(float wiu)
	{
		if(wiu == 0.0) return;
		fprintf(mFile,"setAttr \".wi.wiu\" %f;\n", wiu);

	}
	void setWindV(float wiv)
	{
		if(wiv == 0.0) return;
		fprintf(mFile,"setAttr \".wi.wiv\" %f;\n", wiv);

	}
	void setObserverSpeed(float os)
	{
		if(os == 0.0) return;
		fprintf(mFile,"setAttr \".os\" %f;\n", os);

	}
	void setWaveDirSpread(float wd)
	{
		if(wd == 0.2) return;
		fprintf(mFile,"setAttr \".wd\" %f;\n", wd);

	}
	void setNumFrequencies(float nf)
	{
		if(nf == 3.0) return;
		fprintf(mFile,"setAttr \".nf\" %f;\n", nf);

	}
	void setWaveLengthMin(float wlm)
	{
		if(wlm == 0.3) return;
		fprintf(mFile,"setAttr \".wlm\" %f;\n", wlm);

	}
	void setWaveLengthMax(float wlx)
	{
		if(wlx == 4.0) return;
		fprintf(mFile,"setAttr \".wlx\" %f;\n", wlx);

	}
	void setWaveHeight(size_t wh_i,const WaveHeight& wh)
	{
		fprintf(mFile,"setAttr \".wh[%i]\" ",wh_i);
		wh.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWaveHeight_Position(size_t wh_i,float whp)
	{
		if(whp == 0.0) return;
		fprintf(mFile,"setAttr \".wh[%i].whp\" %f;\n", wh_i,whp);

	}
	void setWaveHeight_FloatValue(size_t wh_i,float whfv)
	{
		if(whfv == 0.0) return;
		fprintf(mFile,"setAttr \".wh[%i].whfv\" %f;\n", wh_i,whfv);

	}
	void setWaveHeight_Interp(size_t wh_i,unsigned int whi)
	{
		if(whi == 0) return;
		fprintf(mFile,"setAttr \".wh[%i].whi\" %i;\n", wh_i,whi);

	}
	void setWaveTurbulence(size_t wtb_i,const WaveTurbulence& wtb)
	{
		fprintf(mFile,"setAttr \".wtb[%i]\" ",wtb_i);
		wtb.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWaveTurbulence_Position(size_t wtb_i,float wtbp)
	{
		if(wtbp == 0.0) return;
		fprintf(mFile,"setAttr \".wtb[%i].wtbp\" %f;\n", wtb_i,wtbp);

	}
	void setWaveTurbulence_FloatValue(size_t wtb_i,float wtbfv)
	{
		if(wtbfv == 0.0) return;
		fprintf(mFile,"setAttr \".wtb[%i].wtbfv\" %f;\n", wtb_i,wtbfv);

	}
	void setWaveTurbulence_Interp(size_t wtb_i,unsigned int wtbi)
	{
		if(wtbi == 0) return;
		fprintf(mFile,"setAttr \".wtb[%i].wtbi\" %i;\n", wtb_i,wtbi);

	}
	void setWavePeaking(size_t wp_i,const WavePeaking& wp)
	{
		fprintf(mFile,"setAttr \".wp[%i]\" ",wp_i);
		wp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWavePeaking_Position(size_t wp_i,float wpp)
	{
		if(wpp == 0.0) return;
		fprintf(mFile,"setAttr \".wp[%i].wpp\" %f;\n", wp_i,wpp);

	}
	void setWavePeaking_FloatValue(size_t wp_i,float wpfv)
	{
		if(wpfv == 0.0) return;
		fprintf(mFile,"setAttr \".wp[%i].wpfv\" %f;\n", wp_i,wpfv);

	}
	void setWavePeaking_Interp(size_t wp_i,unsigned int wpi)
	{
		if(wpi == 0) return;
		fprintf(mFile,"setAttr \".wp[%i].wpi\" %i;\n", wp_i,wpi);

	}
	void setWaveHeightOffset(float who)
	{
		if(who == 0.0) return;
		fprintf(mFile,"setAttr \".who\" %f;\n", who);

	}
	void setTroughShadowing(float tsh)
	{
		if(tsh == 0.5) return;
		fprintf(mFile,"setAttr \".tsh\" %f;\n", tsh);

	}
	void setFoamColor(const float3& fc)
	{
		fprintf(mFile,"setAttr \".fc\" -type \"float3\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFoamColorR(float fcr)
	{
		if(fcr == 1.0) return;
		fprintf(mFile,"setAttr \".fc.fcr\" %f;\n", fcr);

	}
	void setFoamColorG(float fcg)
	{
		if(fcg == 1.0) return;
		fprintf(mFile,"setAttr \".fc.fcg\" %f;\n", fcg);

	}
	void setFoamColorB(float fcb)
	{
		if(fcb == 1.0) return;
		fprintf(mFile,"setAttr \".fc.fcb\" %f;\n", fcb);

	}
	void setFoamEmission(float fme)
	{
		if(fme == 0.0) return;
		fprintf(mFile,"setAttr \".fme\" %f;\n", fme);

	}
	void setFoamThreshold(float fmt)
	{
		if(fmt == 0.51) return;
		fprintf(mFile,"setAttr \".fmt\" %f;\n", fmt);

	}
	void setFoamOffset(float fmo)
	{
		if(fmo == 0.0) return;
		fprintf(mFile,"setAttr \".fmo\" %f;\n", fmo);

	}
	void setDisplacement(float d)
	{
		if(d == 0.0) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setBumpBlur(float bbl)
	{
		if(bbl == 0.1) return;
		fprintf(mFile,"setAttr \".bbl\" %f;\n", bbl);

	}
	void setHorizonFilter(float hft)
	{
		if(hft == 1.0) return;
		fprintf(mFile,"setAttr \".hft\" %f;\n", hft);

	}
	void setWaveSpeed(float wvs)
	{
		if(wvs == 1.0) return;
		fprintf(mFile,"setAttr \".wvs\" %f;\n", wvs);

	}
	void setMiRefractionBlur(float mirfb)
	{
		if(mirfb == 0) return;
		fprintf(mFile,"setAttr \".mirfb\" %f;\n", mirfb);

	}
	void setMiRefractionRays(short mirfr)
	{
		if(mirfr == 1) return;
		fprintf(mFile,"setAttr \".mirfr\" %i;\n", mirfr);

	}
	void setMiReflectionBlur(float mircb)
	{
		if(mircb == 0) return;
		fprintf(mFile,"setAttr \".mircb\" %f;\n", mircb);

	}
	void setMiReflectionRays(short mircr)
	{
		if(mircr == 1) return;
		fprintf(mFile,"setAttr \".mircr\" %i;\n", mircr);

	}
	void setMiIrradiance(const float3& mii)
	{
		fprintf(mFile,"setAttr \".mii\" -type \"float3\" ");
		mii.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiIrradianceR(float miir)
	{
		if(miir == 0) return;
		fprintf(mFile,"setAttr \".mii.miir\" %f;\n", miir);

	}
	void setMiIrradianceG(float miig)
	{
		if(miig == 0) return;
		fprintf(mFile,"setAttr \".mii.miig\" %f;\n", miig);

	}
	void setMiIrradianceB(float miib)
	{
		if(miib == 0) return;
		fprintf(mFile,"setAttr \".mii.miib\" %f;\n", miib);

	}
	void setMiIrradianceColor(const float3& miic)
	{
		fprintf(mFile,"setAttr \".miic\" -type \"float3\" ");
		miic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiIrradianceColorR(float miicr)
	{
		if(miicr == 1) return;
		fprintf(mFile,"setAttr \".miic.miicr\" %f;\n", miicr);

	}
	void setMiIrradianceColorG(float miicg)
	{
		if(miicg == 1) return;
		fprintf(mFile,"setAttr \".miic.miicg\" %f;\n", miicg);

	}
	void setMiIrradianceColorB(float miicb)
	{
		if(miicb == 1) return;
		fprintf(mFile,"setAttr \".miic.miicb\" %f;\n", miicb);

	}
	void setMiDeriveFromMaya(bool mifm)
	{
		if(mifm == true) return;
		fprintf(mFile,"setAttr \".mifm\" %i;\n", mifm);

	}
	void setMiShinyness(float mis)
	{
		if(mis == 10) return;
		fprintf(mFile,"setAttr \".mis\" %f;\n", mis);

	}
	void setMiSpecularColor(const float3& misc)
	{
		fprintf(mFile,"setAttr \".misc\" -type \"float3\" ");
		misc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiSpecularColorR(float miscr)
	{
		if(miscr == 0.5) return;
		fprintf(mFile,"setAttr \".misc.miscr\" %f;\n", miscr);

	}
	void setMiSpecularColorG(float miscg)
	{
		if(miscg == 0.5) return;
		fprintf(mFile,"setAttr \".misc.miscg\" %f;\n", miscg);

	}
	void setMiSpecularColorB(float miscb)
	{
		if(miscb == 0.5) return;
		fprintf(mFile,"setAttr \".misc.miscb\" %f;\n", miscb);

	}
	void setMiReflectivity(float mirf)
	{
		if(mirf == 0.5) return;
		fprintf(mFile,"setAttr \".mirf\" %f;\n", mirf);

	}
	void setMiRefractiveIndex(float miri)
	{
		if(miri == 1) return;
		fprintf(mFile,"setAttr \".miri\" %f;\n", miri);

	}
	void setMiRefractions(bool mirc)
	{
		if(mirc == true) return;
		fprintf(mFile,"setAttr \".mirc\" %i;\n", mirc);

	}
	void setMiAbsorbs(bool miab)
	{
		if(miab == true) return;
		fprintf(mFile,"setAttr \".miab\" %i;\n", miab);

	}
	void setMiDiffuse(float midc)
	{
		if(midc == 0.8) return;
		fprintf(mFile,"setAttr \".midc\" %f;\n", midc);

	}
	void setMiColor(const float3& mic)
	{
		fprintf(mFile,"setAttr \".mic\" -type \"float3\" ");
		mic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiColorR(float micr)
	{
		if(micr == 0.5) return;
		fprintf(mFile,"setAttr \".mic.micr\" %f;\n", micr);

	}
	void setMiColorG(float micg)
	{
		if(micg == 0.5) return;
		fprintf(mFile,"setAttr \".mic.micg\" %f;\n", micg);

	}
	void setMiColorB(float micb)
	{
		if(micb == 0.5) return;
		fprintf(mFile,"setAttr \".mic.micb\" %f;\n", micb);

	}
	void setMiTransparency(const float3& mit)
	{
		fprintf(mFile,"setAttr \".mit\" -type \"float3\" ");
		mit.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiTransparencyR(float mitr)
	{
		if(mitr == 0) return;
		fprintf(mFile,"setAttr \".mit.mitr\" %f;\n", mitr);

	}
	void setMiTransparencyG(float mitg)
	{
		if(mitg == 0) return;
		fprintf(mFile,"setAttr \".mit.mitg\" %f;\n", mitg);

	}
	void setMiTransparencyB(float mitb)
	{
		if(mitb == 0) return;
		fprintf(mFile,"setAttr \".mit.mitb\" %f;\n", mitb);

	}
	void setMiTranslucence(float mitc)
	{
		if(mitc == 0) return;
		fprintf(mFile,"setAttr \".mitc\" %f;\n", mitc);

	}
	void setMiTranslucenceFocus(float mitf)
	{
		if(mitf == 0.5) return;
		fprintf(mFile,"setAttr \".mitf\" %f;\n", mitf);

	}
	void setMiNormalCamera(const float3& minc)
	{
		fprintf(mFile,"setAttr \".minc\" -type \"float3\" ");
		minc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiNormalCameraX(float mincx)
	{
		if(mincx == 0) return;
		fprintf(mFile,"setAttr \".minc.mincx\" %f;\n", mincx);

	}
	void setMiNormalCameraY(float mincy)
	{
		if(mincy == 0) return;
		fprintf(mFile,"setAttr \".minc.mincy\" %f;\n", mincy);

	}
	void setMiNormalCameraZ(float mincz)
	{
		if(mincz == 0) return;
		fprintf(mFile,"setAttr \".minc.mincz\" %f;\n", mincz);

	}
	void getRefractionLimit()
	{
		fprintf(mFile,"\"%s.rdl\"",mName.c_str());

	}
	void getRefractiveIndex()
	{
		fprintf(mFile,"\"%s.rfi\"",mName.c_str());

	}
	void getRefractions()
	{
		fprintf(mFile,"\"%s.rfc\"",mName.c_str());

	}
	void getDiffuse()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getWaterColor()
	{
		fprintf(mFile,"\"%s.wc\"",mName.c_str());

	}
	void getWaterColorR()
	{
		fprintf(mFile,"\"%s.wc.wcr\"",mName.c_str());

	}
	void getWaterColorG()
	{
		fprintf(mFile,"\"%s.wc.wcg\"",mName.c_str());

	}
	void getWaterColorB()
	{
		fprintf(mFile,"\"%s.wc.wcb\"",mName.c_str());

	}
	void getTransparency()
	{
		fprintf(mFile,"\"%s.it\"",mName.c_str());

	}
	void getTransparencyR()
	{
		fprintf(mFile,"\"%s.it.itr\"",mName.c_str());

	}
	void getTransparencyG()
	{
		fprintf(mFile,"\"%s.it.itg\"",mName.c_str());

	}
	void getTransparencyB()
	{
		fprintf(mFile,"\"%s.it.itb\"",mName.c_str());

	}
	void getAmbientColor()
	{
		fprintf(mFile,"\"%s.ambc\"",mName.c_str());

	}
	void getAmbientColorR()
	{
		fprintf(mFile,"\"%s.ambc.acr\"",mName.c_str());

	}
	void getAmbientColorG()
	{
		fprintf(mFile,"\"%s.ambc.acg\"",mName.c_str());

	}
	void getAmbientColorB()
	{
		fprintf(mFile,"\"%s.ambc.acb\"",mName.c_str());

	}
	void getIncandescence()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getIncandescenceR()
	{
		fprintf(mFile,"\"%s.ic.ir\"",mName.c_str());

	}
	void getIncandescenceG()
	{
		fprintf(mFile,"\"%s.ic.ig\"",mName.c_str());

	}
	void getIncandescenceB()
	{
		fprintf(mFile,"\"%s.ic.ib\"",mName.c_str());

	}
	void getTranslucence()
	{
		fprintf(mFile,"\"%s.tc\"",mName.c_str());

	}
	void getTranslucenceFocus()
	{
		fprintf(mFile,"\"%s.tcf\"",mName.c_str());

	}
	void getTranslucenceDepth()
	{
		fprintf(mFile,"\"%s.trsd\"",mName.c_str());

	}
	void getOpacityDepth()
	{
		fprintf(mFile,"\"%s.opad\"",mName.c_str());

	}
	void getGlowIntensity()
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());

	}
	void getSpecularGlow()
	{
		fprintf(mFile,"\"%s.spg\"",mName.c_str());

	}
	void getShadowAttenuation()
	{
		fprintf(mFile,"\"%s.fakc\"",mName.c_str());

	}
	void getEccentricity()
	{
		fprintf(mFile,"\"%s.ec\"",mName.c_str());

	}
	void getSpecularity()
	{
		fprintf(mFile,"\"%s.spl\"",mName.c_str());

	}
	void getReflectionLimit()
	{
		fprintf(mFile,"\"%s.fll\"",mName.c_str());

	}
	void getSpecularColor()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getSpecularColorR()
	{
		fprintf(mFile,"\"%s.sc.sr\"",mName.c_str());

	}
	void getSpecularColorG()
	{
		fprintf(mFile,"\"%s.sc.sg\"",mName.c_str());

	}
	void getSpecularColorB()
	{
		fprintf(mFile,"\"%s.sc.sb\"",mName.c_str());

	}
	void getReflectivity()
	{
		fprintf(mFile,"\"%s.rfl\"",mName.c_str());

	}
	void getEnvironment(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i]\"",mName.c_str(),env_i);

	}
	void getEnvironment_Position(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envp\"",mName.c_str(),env_i);

	}
	void getEnvironment_Color(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc\"",mName.c_str(),env_i);

	}
	void getEnvironment_ColorR(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcr\"",mName.c_str(),env_i);

	}
	void getEnvironment_ColorG(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcg\"",mName.c_str(),env_i);

	}
	void getEnvironment_ColorB(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcb\"",mName.c_str(),env_i);

	}
	void getEnvironment_Interp(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envi\"",mName.c_str(),env_i);

	}
	void getReflectedColor()
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());

	}
	void getReflectedColorR()
	{
		fprintf(mFile,"\"%s.rc.rr\"",mName.c_str());

	}
	void getReflectedColorG()
	{
		fprintf(mFile,"\"%s.rc.rg\"",mName.c_str());

	}
	void getReflectedColorB()
	{
		fprintf(mFile,"\"%s.rc.rb\"",mName.c_str());

	}
	void getTriangleNormalCamera()
	{
		fprintf(mFile,"\"%s.tnc\"",mName.c_str());

	}
	void getTriangleNormalCameraX()
	{
		fprintf(mFile,"\"%s.tnc.tnx\"",mName.c_str());

	}
	void getTriangleNormalCameraY()
	{
		fprintf(mFile,"\"%s.tnc.tny\"",mName.c_str());

	}
	void getTriangleNormalCameraZ()
	{
		fprintf(mFile,"\"%s.tnc.tnz\"",mName.c_str());

	}
	void getReflectionSpecularity()
	{
		fprintf(mFile,"\"%s.rsp\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());

	}
	void getOutTransparency()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getOutTransparencyR()
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());

	}
	void getOutTransparencyG()
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());

	}
	void getOutTransparencyB()
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());

	}
	void getOutGlowColor()
	{
		fprintf(mFile,"\"%s.ogc\"",mName.c_str());

	}
	void getOutGlowColorR()
	{
		fprintf(mFile,"\"%s.ogc.ogr\"",mName.c_str());

	}
	void getOutGlowColorG()
	{
		fprintf(mFile,"\"%s.ogc.ogg\"",mName.c_str());

	}
	void getOutGlowColorB()
	{
		fprintf(mFile,"\"%s.ogc.ogb\"",mName.c_str());

	}
	void getPointCamera()
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());

	}
	void getPointCameraX()
	{
		fprintf(mFile,"\"%s.pc.px\"",mName.c_str());

	}
	void getPointCameraY()
	{
		fprintf(mFile,"\"%s.pc.py\"",mName.c_str());

	}
	void getPointCameraZ()
	{
		fprintf(mFile,"\"%s.pc.pz\"",mName.c_str());

	}
	void getNormalCamera()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getNormalCameraX()
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());

	}
	void getNormalCameraY()
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());

	}
	void getNormalCameraZ()
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());

	}
	void getFilterSize()
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());

	}
	void getFilterSizeX()
	{
		fprintf(mFile,"\"%s.fs.fsx\"",mName.c_str());

	}
	void getFilterSizeY()
	{
		fprintf(mFile,"\"%s.fs.fsy\"",mName.c_str());

	}
	void getFilterSizeZ()
	{
		fprintf(mFile,"\"%s.fs.fsz\"",mName.c_str());

	}
	void getMatrixWorldToEye()
	{
		fprintf(mFile,"\"%s.wte\"",mName.c_str());

	}
	void getMatrixEyeToWorld()
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());

	}
	void getMatteOpacityMode()
	{
		fprintf(mFile,"\"%s.mom\"",mName.c_str());

	}
	void getMatteOpacity()
	{
		fprintf(mFile,"\"%s.mog\"",mName.c_str());

	}
	void getOutMatteOpacity()
	{
		fprintf(mFile,"\"%s.omo\"",mName.c_str());

	}
	void getOutMatteOpacityR()
	{
		fprintf(mFile,"\"%s.omo.omor\"",mName.c_str());

	}
	void getOutMatteOpacityG()
	{
		fprintf(mFile,"\"%s.omo.omog\"",mName.c_str());

	}
	void getOutMatteOpacityB()
	{
		fprintf(mFile,"\"%s.omo.omob\"",mName.c_str());

	}
	void getTime()
	{
		fprintf(mFile,"\"%s.ti\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.scl\"",mName.c_str());

	}
	void getWindUV()
	{
		fprintf(mFile,"\"%s.wi\"",mName.c_str());

	}
	void getWindU()
	{
		fprintf(mFile,"\"%s.wi.wiu\"",mName.c_str());

	}
	void getWindV()
	{
		fprintf(mFile,"\"%s.wi.wiv\"",mName.c_str());

	}
	void getObserverSpeed()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getWaveDirSpread()
	{
		fprintf(mFile,"\"%s.wd\"",mName.c_str());

	}
	void getNumFrequencies()
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());

	}
	void getWaveLengthMin()
	{
		fprintf(mFile,"\"%s.wlm\"",mName.c_str());

	}
	void getWaveLengthMax()
	{
		fprintf(mFile,"\"%s.wlx\"",mName.c_str());

	}
	void getWaveHeight(size_t wh_i)
	{
		fprintf(mFile,"\"%s.wh[%i]\"",mName.c_str(),wh_i);

	}
	void getWaveHeight_Position(size_t wh_i)
	{
		fprintf(mFile,"\"%s.wh[%i].whp\"",mName.c_str(),wh_i);

	}
	void getWaveHeight_FloatValue(size_t wh_i)
	{
		fprintf(mFile,"\"%s.wh[%i].whfv\"",mName.c_str(),wh_i);

	}
	void getWaveHeight_Interp(size_t wh_i)
	{
		fprintf(mFile,"\"%s.wh[%i].whi\"",mName.c_str(),wh_i);

	}
	void getWaveTurbulence(size_t wtb_i)
	{
		fprintf(mFile,"\"%s.wtb[%i]\"",mName.c_str(),wtb_i);

	}
	void getWaveTurbulence_Position(size_t wtb_i)
	{
		fprintf(mFile,"\"%s.wtb[%i].wtbp\"",mName.c_str(),wtb_i);

	}
	void getWaveTurbulence_FloatValue(size_t wtb_i)
	{
		fprintf(mFile,"\"%s.wtb[%i].wtbfv\"",mName.c_str(),wtb_i);

	}
	void getWaveTurbulence_Interp(size_t wtb_i)
	{
		fprintf(mFile,"\"%s.wtb[%i].wtbi\"",mName.c_str(),wtb_i);

	}
	void getWavePeaking(size_t wp_i)
	{
		fprintf(mFile,"\"%s.wp[%i]\"",mName.c_str(),wp_i);

	}
	void getWavePeaking_Position(size_t wp_i)
	{
		fprintf(mFile,"\"%s.wp[%i].wpp\"",mName.c_str(),wp_i);

	}
	void getWavePeaking_FloatValue(size_t wp_i)
	{
		fprintf(mFile,"\"%s.wp[%i].wpfv\"",mName.c_str(),wp_i);

	}
	void getWavePeaking_Interp(size_t wp_i)
	{
		fprintf(mFile,"\"%s.wp[%i].wpi\"",mName.c_str(),wp_i);

	}
	void getWaveHeightOffset()
	{
		fprintf(mFile,"\"%s.who\"",mName.c_str());

	}
	void getTroughShadowing()
	{
		fprintf(mFile,"\"%s.tsh\"",mName.c_str());

	}
	void getFoamColor()
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());

	}
	void getFoamColorR()
	{
		fprintf(mFile,"\"%s.fc.fcr\"",mName.c_str());

	}
	void getFoamColorG()
	{
		fprintf(mFile,"\"%s.fc.fcg\"",mName.c_str());

	}
	void getFoamColorB()
	{
		fprintf(mFile,"\"%s.fc.fcb\"",mName.c_str());

	}
	void getFoamEmission()
	{
		fprintf(mFile,"\"%s.fme\"",mName.c_str());

	}
	void getFoamThreshold()
	{
		fprintf(mFile,"\"%s.fmt\"",mName.c_str());

	}
	void getFoamOffset()
	{
		fprintf(mFile,"\"%s.fmo\"",mName.c_str());

	}
	void getOutFoam()
	{
		fprintf(mFile,"\"%s.ofm\"",mName.c_str());

	}
	void getDisplacement()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getBumpBlur()
	{
		fprintf(mFile,"\"%s.bbl\"",mName.c_str());

	}
	void getHorizonFilter()
	{
		fprintf(mFile,"\"%s.hft\"",mName.c_str());

	}
	void getWaveSpeed()
	{
		fprintf(mFile,"\"%s.wvs\"",mName.c_str());

	}
	void getRefPointCamera()
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());

	}
	void getRefPointCameraX()
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());

	}
	void getRefPointCameraY()
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());

	}
	void getRefPointCameraZ()
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());

	}
	void getMiRefractionBlur()
	{
		fprintf(mFile,"\"%s.mirfb\"",mName.c_str());

	}
	void getMiRefractionRays()
	{
		fprintf(mFile,"\"%s.mirfr\"",mName.c_str());

	}
	void getMiReflectionBlur()
	{
		fprintf(mFile,"\"%s.mircb\"",mName.c_str());

	}
	void getMiReflectionRays()
	{
		fprintf(mFile,"\"%s.mircr\"",mName.c_str());

	}
	void getMiIrradiance()
	{
		fprintf(mFile,"\"%s.mii\"",mName.c_str());

	}
	void getMiIrradianceR()
	{
		fprintf(mFile,"\"%s.mii.miir\"",mName.c_str());

	}
	void getMiIrradianceG()
	{
		fprintf(mFile,"\"%s.mii.miig\"",mName.c_str());

	}
	void getMiIrradianceB()
	{
		fprintf(mFile,"\"%s.mii.miib\"",mName.c_str());

	}
	void getMiIrradianceColor()
	{
		fprintf(mFile,"\"%s.miic\"",mName.c_str());

	}
	void getMiIrradianceColorR()
	{
		fprintf(mFile,"\"%s.miic.miicr\"",mName.c_str());

	}
	void getMiIrradianceColorG()
	{
		fprintf(mFile,"\"%s.miic.miicg\"",mName.c_str());

	}
	void getMiIrradianceColorB()
	{
		fprintf(mFile,"\"%s.miic.miicb\"",mName.c_str());

	}
	void getMiDeriveFromMaya()
	{
		fprintf(mFile,"\"%s.mifm\"",mName.c_str());

	}
	void getMiShinyness()
	{
		fprintf(mFile,"\"%s.mis\"",mName.c_str());

	}
	void getMiSpecularColor()
	{
		fprintf(mFile,"\"%s.misc\"",mName.c_str());

	}
	void getMiSpecularColorR()
	{
		fprintf(mFile,"\"%s.misc.miscr\"",mName.c_str());

	}
	void getMiSpecularColorG()
	{
		fprintf(mFile,"\"%s.misc.miscg\"",mName.c_str());

	}
	void getMiSpecularColorB()
	{
		fprintf(mFile,"\"%s.misc.miscb\"",mName.c_str());

	}
	void getMiReflectivity()
	{
		fprintf(mFile,"\"%s.mirf\"",mName.c_str());

	}
	void getMiRefractiveIndex()
	{
		fprintf(mFile,"\"%s.miri\"",mName.c_str());

	}
	void getMiRefractions()
	{
		fprintf(mFile,"\"%s.mirc\"",mName.c_str());

	}
	void getMiAbsorbs()
	{
		fprintf(mFile,"\"%s.miab\"",mName.c_str());

	}
	void getMiDiffuse()
	{
		fprintf(mFile,"\"%s.midc\"",mName.c_str());

	}
	void getMiColor()
	{
		fprintf(mFile,"\"%s.mic\"",mName.c_str());

	}
	void getMiColorR()
	{
		fprintf(mFile,"\"%s.mic.micr\"",mName.c_str());

	}
	void getMiColorG()
	{
		fprintf(mFile,"\"%s.mic.micg\"",mName.c_str());

	}
	void getMiColorB()
	{
		fprintf(mFile,"\"%s.mic.micb\"",mName.c_str());

	}
	void getMiTransparency()
	{
		fprintf(mFile,"\"%s.mit\"",mName.c_str());

	}
	void getMiTransparencyR()
	{
		fprintf(mFile,"\"%s.mit.mitr\"",mName.c_str());

	}
	void getMiTransparencyG()
	{
		fprintf(mFile,"\"%s.mit.mitg\"",mName.c_str());

	}
	void getMiTransparencyB()
	{
		fprintf(mFile,"\"%s.mit.mitb\"",mName.c_str());

	}
	void getMiTranslucence()
	{
		fprintf(mFile,"\"%s.mitc\"",mName.c_str());

	}
	void getMiTranslucenceFocus()
	{
		fprintf(mFile,"\"%s.mitf\"",mName.c_str());

	}
	void getMiNormalCamera()
	{
		fprintf(mFile,"\"%s.minc\"",mName.c_str());

	}
	void getMiNormalCameraX()
	{
		fprintf(mFile,"\"%s.minc.mincx\"",mName.c_str());

	}
	void getMiNormalCameraY()
	{
		fprintf(mFile,"\"%s.minc.mincy\"",mName.c_str());

	}
	void getMiNormalCameraZ()
	{
		fprintf(mFile,"\"%s.minc.mincz\"",mName.c_str());

	}
protected:
	OceanShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OCEANSHADER_H__
