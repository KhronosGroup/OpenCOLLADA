/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	OceanShader():DependNode(){}
	OceanShader(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "oceanShader", shared, create){}
	virtual ~OceanShader(){}

	void setRefractionLimit(short rdl)
	{
		if(rdl == 6) return;
		fprintf(mFile,"\tsetAttr \".rdl\" %i;\n", rdl);
	}
	void setRefractiveIndex(float rfi)
	{
		if(rfi == 1.3) return;
		fprintf(mFile,"\tsetAttr \".rfi\" %f;\n", rfi);
	}
	void setRefractions(bool rfc)
	{
		if(rfc == false) return;
		fprintf(mFile,"\tsetAttr \".rfc\" %i;\n", rfc);
	}
	void setDiffuse(float dc)
	{
		if(dc == 0.3) return;
		fprintf(mFile,"\tsetAttr \".dc\" %f;\n", dc);
	}
	void setWaterColor(const float3& wc)
	{
		fprintf(mFile,"\tsetAttr \".wc\" -type \"float3\" ");
		wc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWaterColorR(float wcr)
	{
		if(wcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wc.wcr\" %f;\n", wcr);
	}
	void setWaterColorG(float wcg)
	{
		if(wcg == 0.36) return;
		fprintf(mFile,"\tsetAttr \".wc.wcg\" %f;\n", wcg);
	}
	void setWaterColorB(float wcb)
	{
		if(wcb == 0.4) return;
		fprintf(mFile,"\tsetAttr \".wc.wcb\" %f;\n", wcb);
	}
	void setTransparency(const float3& it)
	{
		fprintf(mFile,"\tsetAttr \".it\" -type \"float3\" ");
		it.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransparencyR(float itr)
	{
		if(itr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it.itr\" %f;\n", itr);
	}
	void setTransparencyG(float itg)
	{
		if(itg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it.itg\" %f;\n", itg);
	}
	void setTransparencyB(float itb)
	{
		if(itb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it.itb\" %f;\n", itb);
	}
	void setAmbientColor(const float3& ambc)
	{
		fprintf(mFile,"\tsetAttr \".ambc\" -type \"float3\" ");
		ambc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAmbientColorR(float acr)
	{
		if(acr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ambc.acr\" %f;\n", acr);
	}
	void setAmbientColorG(float acg)
	{
		if(acg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ambc.acg\" %f;\n", acg);
	}
	void setAmbientColorB(float acb)
	{
		if(acb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ambc.acb\" %f;\n", acb);
	}
	void setIncandescence(const float3& ic)
	{
		fprintf(mFile,"\tsetAttr \".ic\" -type \"float3\" ");
		ic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIncandescenceR(float ir)
	{
		if(ir == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic.ir\" %f;\n", ir);
	}
	void setIncandescenceG(float ig)
	{
		if(ig == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic.ig\" %f;\n", ig);
	}
	void setIncandescenceB(float ib)
	{
		if(ib == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic.ib\" %f;\n", ib);
	}
	void setTranslucence(float tc)
	{
		if(tc == 0.3) return;
		fprintf(mFile,"\tsetAttr \".tc\" %f;\n", tc);
	}
	void setTranslucenceFocus(float tcf)
	{
		if(tcf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tcf\" %f;\n", tcf);
	}
	void setTranslucenceDepth(float trsd)
	{
		if(trsd == 10.0) return;
		fprintf(mFile,"\tsetAttr \".trsd\" %f;\n", trsd);
	}
	void setOpacityDepth(float opad)
	{
		if(opad == 0.0) return;
		fprintf(mFile,"\tsetAttr \".opad\" %f;\n", opad);
	}
	void setGlowIntensity(float gi)
	{
		if(gi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gi\" %f;\n", gi);
	}
	void setSpecularGlow(float spg)
	{
		if(spg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spg\" %f;\n", spg);
	}
	void setShadowAttenuation(float fakc)
	{
		if(fakc == 0.5) return;
		fprintf(mFile,"\tsetAttr \".fakc\" %f;\n", fakc);
	}
	void setEccentricity(float ec)
	{
		if(ec == 0.03) return;
		fprintf(mFile,"\tsetAttr \".ec\" %f;\n", ec);
	}
	void setSpecularity(float spl)
	{
		if(spl == 0.7) return;
		fprintf(mFile,"\tsetAttr \".spl\" %f;\n", spl);
	}
	void setReflectionLimit(short fll)
	{
		if(fll == 1) return;
		fprintf(mFile,"\tsetAttr \".fll\" %i;\n", fll);
	}
	void setSpecularColor(const float3& sc)
	{
		fprintf(mFile,"\tsetAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpecularColorR(float sr)
	{
		if(sr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sc.sr\" %f;\n", sr);
	}
	void setSpecularColorG(float sg)
	{
		if(sg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sc.sg\" %f;\n", sg);
	}
	void setSpecularColorB(float sb)
	{
		if(sb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sc.sb\" %f;\n", sb);
	}
	void setReflectivity(float rfl)
	{
		if(rfl == 0.7) return;
		fprintf(mFile,"\tsetAttr \".rfl\" %f;\n", rfl);
	}
	void setEnvironment(size_t env_i,const Environment& env)
	{
		fprintf(mFile,"\tsetAttr \".env[%i]\" ",env_i);
		env.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEnvironment(size_t env_start,size_t env_end,Environment* env)
	{
		fprintf(mFile,"\tsetAttr \".env[%i:%i]\" ", env_start,env_end);
		size_t size = (env_end-env_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			env[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startEnvironment(size_t env_start,size_t env_end)const
	{
		fprintf(mFile,"\tsetAttr \".env[%i:%i]\"",env_start,env_end);
		fprintf(mFile," -type \"Environment\" ");
	}
	void appendEnvironment(const Environment& env)const
	{
		fprintf(mFile," ");
		env.write(mFile);
	}
	void endEnvironment()const
	{
		fprintf(mFile,";\n");
	}
	void setEnvironment_Position(size_t env_i,float envp)
	{
		if(envp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envp\" %f;\n", env_i,envp);
	}
	void setEnvironment_Color(size_t env_i,const float3& envc)
	{
		fprintf(mFile,"\tsetAttr \".env[%i].envc\" -type \"float3\" ",env_i);
		envc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEnvironment_ColorR(size_t env_i,float envcr)
	{
		if(envcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envc.envcr\" %f;\n", env_i,envcr);
	}
	void setEnvironment_ColorG(size_t env_i,float envcg)
	{
		if(envcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envc.envcg\" %f;\n", env_i,envcg);
	}
	void setEnvironment_ColorB(size_t env_i,float envcb)
	{
		if(envcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envc.envcb\" %f;\n", env_i,envcb);
	}
	void setEnvironment_Interp(size_t env_i,unsigned int envi)
	{
		if(envi == 0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envi\" %i;\n", env_i,envi);
	}
	void setReflectedColor(const float3& rc)
	{
		fprintf(mFile,"\tsetAttr \".rc\" -type \"float3\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setReflectedColorR(float rr)
	{
		if(rr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rr\" %f;\n", rr);
	}
	void setReflectedColorG(float rg)
	{
		if(rg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rg\" %f;\n", rg);
	}
	void setReflectedColorB(float rb)
	{
		if(rb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rb\" %f;\n", rb);
	}
	void setReflectionSpecularity(float rsp)
	{
		if(rsp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rsp\" %f;\n", rsp);
	}
	void setMatteOpacityMode(unsigned int mom)
	{
		if(mom == 2) return;
		fprintf(mFile,"\tsetAttr \".mom\" %i;\n", mom);
	}
	void setMatteOpacity(float mog)
	{
		if(mog == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mog\" %f;\n", mog);
	}
	void setTime(double ti)
	{
		if(ti == 0) return;
		fprintf(mFile,"\tsetAttr \".ti\" %f;\n", ti);
	}
	void setScale(float scl)
	{
		if(scl == 1.0) return;
		fprintf(mFile,"\tsetAttr \".scl\" %f;\n", scl);
	}
	void setWindUV(const float2& wi)
	{
		if(wi == float2(1.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".wi\" -type \"float2\" ");
		wi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWindU(float wiu)
	{
		if(wiu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wi.wiu\" %f;\n", wiu);
	}
	void setWindV(float wiv)
	{
		if(wiv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wi.wiv\" %f;\n", wiv);
	}
	void setObserverSpeed(float os)
	{
		if(os == 0.0) return;
		fprintf(mFile,"\tsetAttr \".os\" %f;\n", os);
	}
	void setWaveDirSpread(float wd)
	{
		if(wd == 0.2) return;
		fprintf(mFile,"\tsetAttr \".wd\" %f;\n", wd);
	}
	void setNumFrequencies(float nf)
	{
		if(nf == 3.0) return;
		fprintf(mFile,"\tsetAttr \".nf\" %f;\n", nf);
	}
	void setWaveLengthMin(float wlm)
	{
		if(wlm == 0.3) return;
		fprintf(mFile,"\tsetAttr \".wlm\" %f;\n", wlm);
	}
	void setWaveLengthMax(float wlx)
	{
		if(wlx == 4.0) return;
		fprintf(mFile,"\tsetAttr \".wlx\" %f;\n", wlx);
	}
	void setWaveHeight(size_t wh_i,const WaveHeight& wh)
	{
		fprintf(mFile,"\tsetAttr \".wh[%i]\" ",wh_i);
		wh.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWaveHeight(size_t wh_start,size_t wh_end,WaveHeight* wh)
	{
		fprintf(mFile,"\tsetAttr \".wh[%i:%i]\" ", wh_start,wh_end);
		size_t size = (wh_end-wh_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			wh[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWaveHeight(size_t wh_start,size_t wh_end)const
	{
		fprintf(mFile,"\tsetAttr \".wh[%i:%i]\"",wh_start,wh_end);
		fprintf(mFile," -type \"WaveHeight\" ");
	}
	void appendWaveHeight(const WaveHeight& wh)const
	{
		fprintf(mFile," ");
		wh.write(mFile);
	}
	void endWaveHeight()const
	{
		fprintf(mFile,";\n");
	}
	void setWaveHeight_Position(size_t wh_i,float whp)
	{
		if(whp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wh[%i].whp\" %f;\n", wh_i,whp);
	}
	void setWaveHeight_FloatValue(size_t wh_i,float whfv)
	{
		if(whfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wh[%i].whfv\" %f;\n", wh_i,whfv);
	}
	void setWaveHeight_Interp(size_t wh_i,unsigned int whi)
	{
		if(whi == 0) return;
		fprintf(mFile,"\tsetAttr \".wh[%i].whi\" %i;\n", wh_i,whi);
	}
	void setWaveTurbulence(size_t wtb_i,const WaveTurbulence& wtb)
	{
		fprintf(mFile,"\tsetAttr \".wtb[%i]\" ",wtb_i);
		wtb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWaveTurbulence(size_t wtb_start,size_t wtb_end,WaveTurbulence* wtb)
	{
		fprintf(mFile,"\tsetAttr \".wtb[%i:%i]\" ", wtb_start,wtb_end);
		size_t size = (wtb_end-wtb_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			wtb[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWaveTurbulence(size_t wtb_start,size_t wtb_end)const
	{
		fprintf(mFile,"\tsetAttr \".wtb[%i:%i]\"",wtb_start,wtb_end);
		fprintf(mFile," -type \"WaveTurbulence\" ");
	}
	void appendWaveTurbulence(const WaveTurbulence& wtb)const
	{
		fprintf(mFile," ");
		wtb.write(mFile);
	}
	void endWaveTurbulence()const
	{
		fprintf(mFile,";\n");
	}
	void setWaveTurbulence_Position(size_t wtb_i,float wtbp)
	{
		if(wtbp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wtb[%i].wtbp\" %f;\n", wtb_i,wtbp);
	}
	void setWaveTurbulence_FloatValue(size_t wtb_i,float wtbfv)
	{
		if(wtbfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wtb[%i].wtbfv\" %f;\n", wtb_i,wtbfv);
	}
	void setWaveTurbulence_Interp(size_t wtb_i,unsigned int wtbi)
	{
		if(wtbi == 0) return;
		fprintf(mFile,"\tsetAttr \".wtb[%i].wtbi\" %i;\n", wtb_i,wtbi);
	}
	void setWavePeaking(size_t wp_i,const WavePeaking& wp)
	{
		fprintf(mFile,"\tsetAttr \".wp[%i]\" ",wp_i);
		wp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWavePeaking(size_t wp_start,size_t wp_end,WavePeaking* wp)
	{
		fprintf(mFile,"\tsetAttr \".wp[%i:%i]\" ", wp_start,wp_end);
		size_t size = (wp_end-wp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			wp[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWavePeaking(size_t wp_start,size_t wp_end)const
	{
		fprintf(mFile,"\tsetAttr \".wp[%i:%i]\"",wp_start,wp_end);
		fprintf(mFile," -type \"WavePeaking\" ");
	}
	void appendWavePeaking(const WavePeaking& wp)const
	{
		fprintf(mFile," ");
		wp.write(mFile);
	}
	void endWavePeaking()const
	{
		fprintf(mFile,";\n");
	}
	void setWavePeaking_Position(size_t wp_i,float wpp)
	{
		if(wpp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wp[%i].wpp\" %f;\n", wp_i,wpp);
	}
	void setWavePeaking_FloatValue(size_t wp_i,float wpfv)
	{
		if(wpfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wp[%i].wpfv\" %f;\n", wp_i,wpfv);
	}
	void setWavePeaking_Interp(size_t wp_i,unsigned int wpi)
	{
		if(wpi == 0) return;
		fprintf(mFile,"\tsetAttr \".wp[%i].wpi\" %i;\n", wp_i,wpi);
	}
	void setWaveHeightOffset(float who)
	{
		if(who == 0.0) return;
		fprintf(mFile,"\tsetAttr \".who\" %f;\n", who);
	}
	void setTroughShadowing(float tsh)
	{
		if(tsh == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tsh\" %f;\n", tsh);
	}
	void setFoamColor(const float3& fc)
	{
		fprintf(mFile,"\tsetAttr \".fc\" -type \"float3\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFoamColorR(float fcr)
	{
		if(fcr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcr\" %f;\n", fcr);
	}
	void setFoamColorG(float fcg)
	{
		if(fcg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcg\" %f;\n", fcg);
	}
	void setFoamColorB(float fcb)
	{
		if(fcb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcb\" %f;\n", fcb);
	}
	void setFoamEmission(float fme)
	{
		if(fme == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fme\" %f;\n", fme);
	}
	void setFoamThreshold(float fmt)
	{
		if(fmt == 0.51) return;
		fprintf(mFile,"\tsetAttr \".fmt\" %f;\n", fmt);
	}
	void setFoamOffset(float fmo)
	{
		if(fmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fmo\" %f;\n", fmo);
	}
	void setDisplacement(float d)
	{
		if(d == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setBumpBlur(float bbl)
	{
		if(bbl == 0.1) return;
		fprintf(mFile,"\tsetAttr \".bbl\" %f;\n", bbl);
	}
	void setHorizonFilter(float hft)
	{
		if(hft == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hft\" %f;\n", hft);
	}
	void setWaveSpeed(float wvs)
	{
		if(wvs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".wvs\" %f;\n", wvs);
	}
	void setMiRefractionBlur(float mirfb)
	{
		if(mirfb == 0) return;
		fprintf(mFile,"\tsetAttr \".mirfb\" %f;\n", mirfb);
	}
	void setMiRefractionRays(short mirfr)
	{
		if(mirfr == 1) return;
		fprintf(mFile,"\tsetAttr \".mirfr\" %i;\n", mirfr);
	}
	void setMiReflectionBlur(float mircb)
	{
		if(mircb == 0) return;
		fprintf(mFile,"\tsetAttr \".mircb\" %f;\n", mircb);
	}
	void setMiReflectionRays(short mircr)
	{
		if(mircr == 1) return;
		fprintf(mFile,"\tsetAttr \".mircr\" %i;\n", mircr);
	}
	void setMiIrradiance(const float3& mii)
	{
		fprintf(mFile,"\tsetAttr \".mii\" -type \"float3\" ");
		mii.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiIrradianceR(float miir)
	{
		if(miir == 0) return;
		fprintf(mFile,"\tsetAttr \".mii.miir\" %f;\n", miir);
	}
	void setMiIrradianceG(float miig)
	{
		if(miig == 0) return;
		fprintf(mFile,"\tsetAttr \".mii.miig\" %f;\n", miig);
	}
	void setMiIrradianceB(float miib)
	{
		if(miib == 0) return;
		fprintf(mFile,"\tsetAttr \".mii.miib\" %f;\n", miib);
	}
	void setMiIrradianceColor(const float3& miic)
	{
		fprintf(mFile,"\tsetAttr \".miic\" -type \"float3\" ");
		miic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiIrradianceColorR(float miicr)
	{
		if(miicr == 1) return;
		fprintf(mFile,"\tsetAttr \".miic.miicr\" %f;\n", miicr);
	}
	void setMiIrradianceColorG(float miicg)
	{
		if(miicg == 1) return;
		fprintf(mFile,"\tsetAttr \".miic.miicg\" %f;\n", miicg);
	}
	void setMiIrradianceColorB(float miicb)
	{
		if(miicb == 1) return;
		fprintf(mFile,"\tsetAttr \".miic.miicb\" %f;\n", miicb);
	}
	void setMiDeriveFromMaya(bool mifm)
	{
		if(mifm == true) return;
		fprintf(mFile,"\tsetAttr \".mifm\" %i;\n", mifm);
	}
	void setMiShinyness(float mis)
	{
		if(mis == 10) return;
		fprintf(mFile,"\tsetAttr \".mis\" %f;\n", mis);
	}
	void setMiSpecularColor(const float3& misc)
	{
		fprintf(mFile,"\tsetAttr \".misc\" -type \"float3\" ");
		misc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiSpecularColorR(float miscr)
	{
		if(miscr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscr\" %f;\n", miscr);
	}
	void setMiSpecularColorG(float miscg)
	{
		if(miscg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscg\" %f;\n", miscg);
	}
	void setMiSpecularColorB(float miscb)
	{
		if(miscb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscb\" %f;\n", miscb);
	}
	void setMiReflectivity(float mirf)
	{
		if(mirf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mirf\" %f;\n", mirf);
	}
	void setMiRefractiveIndex(float miri)
	{
		if(miri == 1) return;
		fprintf(mFile,"\tsetAttr \".miri\" %f;\n", miri);
	}
	void setMiRefractions(bool mirc)
	{
		if(mirc == true) return;
		fprintf(mFile,"\tsetAttr \".mirc\" %i;\n", mirc);
	}
	void setMiAbsorbs(bool miab)
	{
		if(miab == true) return;
		fprintf(mFile,"\tsetAttr \".miab\" %i;\n", miab);
	}
	void setMiDiffuse(float midc)
	{
		if(midc == 0.8) return;
		fprintf(mFile,"\tsetAttr \".midc\" %f;\n", midc);
	}
	void setMiColor(const float3& mic)
	{
		fprintf(mFile,"\tsetAttr \".mic\" -type \"float3\" ");
		mic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiColorR(float micr)
	{
		if(micr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micr\" %f;\n", micr);
	}
	void setMiColorG(float micg)
	{
		if(micg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micg\" %f;\n", micg);
	}
	void setMiColorB(float micb)
	{
		if(micb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micb\" %f;\n", micb);
	}
	void setMiTransparency(const float3& mit)
	{
		fprintf(mFile,"\tsetAttr \".mit\" -type \"float3\" ");
		mit.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiTransparencyR(float mitr)
	{
		if(mitr == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitr\" %f;\n", mitr);
	}
	void setMiTransparencyG(float mitg)
	{
		if(mitg == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitg\" %f;\n", mitg);
	}
	void setMiTransparencyB(float mitb)
	{
		if(mitb == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitb\" %f;\n", mitb);
	}
	void setMiTranslucence(float mitc)
	{
		if(mitc == 0) return;
		fprintf(mFile,"\tsetAttr \".mitc\" %f;\n", mitc);
	}
	void setMiTranslucenceFocus(float mitf)
	{
		if(mitf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mitf\" %f;\n", mitf);
	}
	void setMiNormalCamera(const float3& minc)
	{
		fprintf(mFile,"\tsetAttr \".minc\" -type \"float3\" ");
		minc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiNormalCameraX(float mincx)
	{
		if(mincx == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincx\" %f;\n", mincx);
	}
	void setMiNormalCameraY(float mincy)
	{
		if(mincy == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincy\" %f;\n", mincy);
	}
	void setMiNormalCameraZ(float mincz)
	{
		if(mincz == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincz\" %f;\n", mincz);
	}
	void getObjectId()const
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());
	}
	void getPrimitiveId()const
	{
		fprintf(mFile,"\"%s.pi\"",mName.c_str());
	}
	void getRaySampler()const
	{
		fprintf(mFile,"\"%s.rtr\"",mName.c_str());
	}
	void getRayDepth()const
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());
	}
	void getRayInstance()const
	{
		fprintf(mFile,"\"%s.ryi\"",mName.c_str());
	}
	void getRefractionLimit()const
	{
		fprintf(mFile,"\"%s.rdl\"",mName.c_str());
	}
	void getRefractiveIndex()const
	{
		fprintf(mFile,"\"%s.rfi\"",mName.c_str());
	}
	void getMediumRefractiveIndex()const
	{
		fprintf(mFile,"\"%s.mrfi\"",mName.c_str());
	}
	void getRefractions()const
	{
		fprintf(mFile,"\"%s.rfc\"",mName.c_str());
	}
	void getDiffuse()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getRayDirection()const
	{
		fprintf(mFile,"\"%s.rad\"",mName.c_str());
	}
	void getRayDirectionX()const
	{
		fprintf(mFile,"\"%s.rad.rdx\"",mName.c_str());
	}
	void getRayDirectionY()const
	{
		fprintf(mFile,"\"%s.rad.rdy\"",mName.c_str());
	}
	void getRayDirectionZ()const
	{
		fprintf(mFile,"\"%s.rad.rdz\"",mName.c_str());
	}
	void getWaterColor()const
	{
		fprintf(mFile,"\"%s.wc\"",mName.c_str());
	}
	void getWaterColorR()const
	{
		fprintf(mFile,"\"%s.wc.wcr\"",mName.c_str());
	}
	void getWaterColorG()const
	{
		fprintf(mFile,"\"%s.wc.wcg\"",mName.c_str());
	}
	void getWaterColorB()const
	{
		fprintf(mFile,"\"%s.wc.wcb\"",mName.c_str());
	}
	void getTransparency()const
	{
		fprintf(mFile,"\"%s.it\"",mName.c_str());
	}
	void getTransparencyR()const
	{
		fprintf(mFile,"\"%s.it.itr\"",mName.c_str());
	}
	void getTransparencyG()const
	{
		fprintf(mFile,"\"%s.it.itg\"",mName.c_str());
	}
	void getTransparencyB()const
	{
		fprintf(mFile,"\"%s.it.itb\"",mName.c_str());
	}
	void getAmbientColor()const
	{
		fprintf(mFile,"\"%s.ambc\"",mName.c_str());
	}
	void getAmbientColorR()const
	{
		fprintf(mFile,"\"%s.ambc.acr\"",mName.c_str());
	}
	void getAmbientColorG()const
	{
		fprintf(mFile,"\"%s.ambc.acg\"",mName.c_str());
	}
	void getAmbientColorB()const
	{
		fprintf(mFile,"\"%s.ambc.acb\"",mName.c_str());
	}
	void getIncandescence()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getIncandescenceR()const
	{
		fprintf(mFile,"\"%s.ic.ir\"",mName.c_str());
	}
	void getIncandescenceG()const
	{
		fprintf(mFile,"\"%s.ic.ig\"",mName.c_str());
	}
	void getIncandescenceB()const
	{
		fprintf(mFile,"\"%s.ic.ib\"",mName.c_str());
	}
	void getTranslucence()const
	{
		fprintf(mFile,"\"%s.tc\"",mName.c_str());
	}
	void getTranslucenceFocus()const
	{
		fprintf(mFile,"\"%s.tcf\"",mName.c_str());
	}
	void getTranslucenceDepth()const
	{
		fprintf(mFile,"\"%s.trsd\"",mName.c_str());
	}
	void getOpacityDepth()const
	{
		fprintf(mFile,"\"%s.opad\"",mName.c_str());
	}
	void getGlowIntensity()const
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());
	}
	void getSpecularGlow()const
	{
		fprintf(mFile,"\"%s.spg\"",mName.c_str());
	}
	void getShadowAttenuation()const
	{
		fprintf(mFile,"\"%s.fakc\"",mName.c_str());
	}
	void getEccentricity()const
	{
		fprintf(mFile,"\"%s.ec\"",mName.c_str());
	}
	void getSpecularity()const
	{
		fprintf(mFile,"\"%s.spl\"",mName.c_str());
	}
	void getReflectionLimit()const
	{
		fprintf(mFile,"\"%s.fll\"",mName.c_str());
	}
	void getSpecularColor()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getSpecularColorR()const
	{
		fprintf(mFile,"\"%s.sc.sr\"",mName.c_str());
	}
	void getSpecularColorG()const
	{
		fprintf(mFile,"\"%s.sc.sg\"",mName.c_str());
	}
	void getSpecularColorB()const
	{
		fprintf(mFile,"\"%s.sc.sb\"",mName.c_str());
	}
	void getReflectivity()const
	{
		fprintf(mFile,"\"%s.rfl\"",mName.c_str());
	}
	void getEnvironment(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i]\"",mName.c_str(),env_i);
	}
	void getEnvironment()const
	{

		fprintf(mFile,"\"%s.env\"",mName.c_str());
	}
	void getEnvironment_Position(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envp\"",mName.c_str(),env_i);
	}
	void getEnvironment_Position()const
	{

		fprintf(mFile,"\"%s.env.envp\"",mName.c_str());
	}
	void getEnvironment_Color(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envc\"",mName.c_str(),env_i);
	}
	void getEnvironment_Color()const
	{

		fprintf(mFile,"\"%s.env.envc\"",mName.c_str());
	}
	void getEnvironment_ColorR(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcr\"",mName.c_str(),env_i);
	}
	void getEnvironment_ColorR()const
	{

		fprintf(mFile,"\"%s.env.envc.envcr\"",mName.c_str());
	}
	void getEnvironment_ColorG(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcg\"",mName.c_str(),env_i);
	}
	void getEnvironment_ColorG()const
	{

		fprintf(mFile,"\"%s.env.envc.envcg\"",mName.c_str());
	}
	void getEnvironment_ColorB(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcb\"",mName.c_str(),env_i);
	}
	void getEnvironment_ColorB()const
	{

		fprintf(mFile,"\"%s.env.envc.envcb\"",mName.c_str());
	}
	void getEnvironment_Interp(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envi\"",mName.c_str(),env_i);
	}
	void getEnvironment_Interp()const
	{

		fprintf(mFile,"\"%s.env.envi\"",mName.c_str());
	}
	void getReflectedColor()const
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());
	}
	void getReflectedColorR()const
	{
		fprintf(mFile,"\"%s.rc.rr\"",mName.c_str());
	}
	void getReflectedColorG()const
	{
		fprintf(mFile,"\"%s.rc.rg\"",mName.c_str());
	}
	void getReflectedColorB()const
	{
		fprintf(mFile,"\"%s.rc.rb\"",mName.c_str());
	}
	void getTriangleNormalCamera()const
	{
		fprintf(mFile,"\"%s.tnc\"",mName.c_str());
	}
	void getTriangleNormalCameraX()const
	{
		fprintf(mFile,"\"%s.tnc.tnx\"",mName.c_str());
	}
	void getTriangleNormalCameraY()const
	{
		fprintf(mFile,"\"%s.tnc.tny\"",mName.c_str());
	}
	void getTriangleNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.tnc.tnz\"",mName.c_str());
	}
	void getReflectionSpecularity()const
	{
		fprintf(mFile,"\"%s.rsp\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());
	}
	void getOutTransparency()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getOutTransparencyR()const
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());
	}
	void getOutTransparencyG()const
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());
	}
	void getOutTransparencyB()const
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());
	}
	void getOutGlowColor()const
	{
		fprintf(mFile,"\"%s.ogc\"",mName.c_str());
	}
	void getOutGlowColorR()const
	{
		fprintf(mFile,"\"%s.ogc.ogr\"",mName.c_str());
	}
	void getOutGlowColorG()const
	{
		fprintf(mFile,"\"%s.ogc.ogg\"",mName.c_str());
	}
	void getOutGlowColorB()const
	{
		fprintf(mFile,"\"%s.ogc.ogb\"",mName.c_str());
	}
	void getPointCamera()const
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getPointCameraX()const
	{
		fprintf(mFile,"\"%s.pc.px\"",mName.c_str());
	}
	void getPointCameraY()const
	{
		fprintf(mFile,"\"%s.pc.py\"",mName.c_str());
	}
	void getPointCameraZ()const
	{
		fprintf(mFile,"\"%s.pc.pz\"",mName.c_str());
	}
	void getNormalCamera()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNormalCameraX()const
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());
	}
	void getNormalCameraY()const
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());
	}
	void getNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());
	}
	void getFilterSize()const
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getFilterSizeX()const
	{
		fprintf(mFile,"\"%s.fs.fsx\"",mName.c_str());
	}
	void getFilterSizeY()const
	{
		fprintf(mFile,"\"%s.fs.fsy\"",mName.c_str());
	}
	void getFilterSizeZ()const
	{
		fprintf(mFile,"\"%s.fs.fsz\"",mName.c_str());
	}
	void getMatrixWorldToEye()const
	{
		fprintf(mFile,"\"%s.wte\"",mName.c_str());
	}
	void getMatrixEyeToWorld()const
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());
	}
	void getLightDataArray(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i]\"",mName.c_str(),ltd_i);
	}
	void getLightDataArray()const
	{

		fprintf(mFile,"\"%s.ltd\"",mName.c_str());
	}
	void getLightDirection(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld\"",mName.c_str(),ltd_i);
	}
	void getLightDirection()const
	{

		fprintf(mFile,"\"%s.ltd.ld\"",mName.c_str());
	}
	void getLightDirectionX(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldx\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionX()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldx\"",mName.c_str());
	}
	void getLightDirectionY(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldy\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionY()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldy\"",mName.c_str());
	}
	void getLightDirectionZ(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldz\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionZ()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldz\"",mName.c_str());
	}
	void getLightIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li\"",mName.c_str(),ltd_i);
	}
	void getLightIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.li\"",mName.c_str());
	}
	void getLightIntensityR(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lir\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityR()const
	{

		fprintf(mFile,"\"%s.ltd.li.lir\"",mName.c_str());
	}
	void getLightIntensityG(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lig\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityG()const
	{

		fprintf(mFile,"\"%s.ltd.li.lig\"",mName.c_str());
	}
	void getLightIntensityB(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lib\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityB()const
	{

		fprintf(mFile,"\"%s.ltd.li.lib\"",mName.c_str());
	}
	void getLightAmbient(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].la\"",mName.c_str(),ltd_i);
	}
	void getLightAmbient()const
	{

		fprintf(mFile,"\"%s.ltd.la\"",mName.c_str());
	}
	void getLightDiffuse(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ldf\"",mName.c_str(),ltd_i);
	}
	void getLightDiffuse()const
	{

		fprintf(mFile,"\"%s.ltd.ldf\"",mName.c_str());
	}
	void getLightSpecular(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ls\"",mName.c_str(),ltd_i);
	}
	void getLightSpecular()const
	{

		fprintf(mFile,"\"%s.ltd.ls\"",mName.c_str());
	}
	void getLightShadowFraction(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lsf\"",mName.c_str(),ltd_i);
	}
	void getLightShadowFraction()const
	{

		fprintf(mFile,"\"%s.ltd.lsf\"",mName.c_str());
	}
	void getPreShadowIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].psi\"",mName.c_str(),ltd_i);
	}
	void getPreShadowIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.psi\"",mName.c_str());
	}
	void getLightBlindData(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lbd\"",mName.c_str(),ltd_i);
	}
	void getLightBlindData()const
	{

		fprintf(mFile,"\"%s.ltd.lbd\"",mName.c_str());
	}
	void getMatteOpacityMode()const
	{
		fprintf(mFile,"\"%s.mom\"",mName.c_str());
	}
	void getMatteOpacity()const
	{
		fprintf(mFile,"\"%s.mog\"",mName.c_str());
	}
	void getOutMatteOpacity()const
	{
		fprintf(mFile,"\"%s.omo\"",mName.c_str());
	}
	void getOutMatteOpacityR()const
	{
		fprintf(mFile,"\"%s.omo.omor\"",mName.c_str());
	}
	void getOutMatteOpacityG()const
	{
		fprintf(mFile,"\"%s.omo.omog\"",mName.c_str());
	}
	void getOutMatteOpacityB()const
	{
		fprintf(mFile,"\"%s.omo.omob\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.ti\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.scl\"",mName.c_str());
	}
	void getWindUV()const
	{
		fprintf(mFile,"\"%s.wi\"",mName.c_str());
	}
	void getWindU()const
	{
		fprintf(mFile,"\"%s.wi.wiu\"",mName.c_str());
	}
	void getWindV()const
	{
		fprintf(mFile,"\"%s.wi.wiv\"",mName.c_str());
	}
	void getObserverSpeed()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getWaveDirSpread()const
	{
		fprintf(mFile,"\"%s.wd\"",mName.c_str());
	}
	void getNumFrequencies()const
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());
	}
	void getWaveLengthMin()const
	{
		fprintf(mFile,"\"%s.wlm\"",mName.c_str());
	}
	void getWaveLengthMax()const
	{
		fprintf(mFile,"\"%s.wlx\"",mName.c_str());
	}
	void getWaveHeight(size_t wh_i)const
	{
		fprintf(mFile,"\"%s.wh[%i]\"",mName.c_str(),wh_i);
	}
	void getWaveHeight()const
	{

		fprintf(mFile,"\"%s.wh\"",mName.c_str());
	}
	void getWaveHeight_Position(size_t wh_i)const
	{
		fprintf(mFile,"\"%s.wh[%i].whp\"",mName.c_str(),wh_i);
	}
	void getWaveHeight_Position()const
	{

		fprintf(mFile,"\"%s.wh.whp\"",mName.c_str());
	}
	void getWaveHeight_FloatValue(size_t wh_i)const
	{
		fprintf(mFile,"\"%s.wh[%i].whfv\"",mName.c_str(),wh_i);
	}
	void getWaveHeight_FloatValue()const
	{

		fprintf(mFile,"\"%s.wh.whfv\"",mName.c_str());
	}
	void getWaveHeight_Interp(size_t wh_i)const
	{
		fprintf(mFile,"\"%s.wh[%i].whi\"",mName.c_str(),wh_i);
	}
	void getWaveHeight_Interp()const
	{

		fprintf(mFile,"\"%s.wh.whi\"",mName.c_str());
	}
	void getWaveTurbulence(size_t wtb_i)const
	{
		fprintf(mFile,"\"%s.wtb[%i]\"",mName.c_str(),wtb_i);
	}
	void getWaveTurbulence()const
	{

		fprintf(mFile,"\"%s.wtb\"",mName.c_str());
	}
	void getWaveTurbulence_Position(size_t wtb_i)const
	{
		fprintf(mFile,"\"%s.wtb[%i].wtbp\"",mName.c_str(),wtb_i);
	}
	void getWaveTurbulence_Position()const
	{

		fprintf(mFile,"\"%s.wtb.wtbp\"",mName.c_str());
	}
	void getWaveTurbulence_FloatValue(size_t wtb_i)const
	{
		fprintf(mFile,"\"%s.wtb[%i].wtbfv\"",mName.c_str(),wtb_i);
	}
	void getWaveTurbulence_FloatValue()const
	{

		fprintf(mFile,"\"%s.wtb.wtbfv\"",mName.c_str());
	}
	void getWaveTurbulence_Interp(size_t wtb_i)const
	{
		fprintf(mFile,"\"%s.wtb[%i].wtbi\"",mName.c_str(),wtb_i);
	}
	void getWaveTurbulence_Interp()const
	{

		fprintf(mFile,"\"%s.wtb.wtbi\"",mName.c_str());
	}
	void getWavePeaking(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i]\"",mName.c_str(),wp_i);
	}
	void getWavePeaking()const
	{

		fprintf(mFile,"\"%s.wp\"",mName.c_str());
	}
	void getWavePeaking_Position(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i].wpp\"",mName.c_str(),wp_i);
	}
	void getWavePeaking_Position()const
	{

		fprintf(mFile,"\"%s.wp.wpp\"",mName.c_str());
	}
	void getWavePeaking_FloatValue(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i].wpfv\"",mName.c_str(),wp_i);
	}
	void getWavePeaking_FloatValue()const
	{

		fprintf(mFile,"\"%s.wp.wpfv\"",mName.c_str());
	}
	void getWavePeaking_Interp(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i].wpi\"",mName.c_str(),wp_i);
	}
	void getWavePeaking_Interp()const
	{

		fprintf(mFile,"\"%s.wp.wpi\"",mName.c_str());
	}
	void getWaveHeightOffset()const
	{
		fprintf(mFile,"\"%s.who\"",mName.c_str());
	}
	void getTroughShadowing()const
	{
		fprintf(mFile,"\"%s.tsh\"",mName.c_str());
	}
	void getFoamColor()const
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getFoamColorR()const
	{
		fprintf(mFile,"\"%s.fc.fcr\"",mName.c_str());
	}
	void getFoamColorG()const
	{
		fprintf(mFile,"\"%s.fc.fcg\"",mName.c_str());
	}
	void getFoamColorB()const
	{
		fprintf(mFile,"\"%s.fc.fcb\"",mName.c_str());
	}
	void getFoamEmission()const
	{
		fprintf(mFile,"\"%s.fme\"",mName.c_str());
	}
	void getFoamThreshold()const
	{
		fprintf(mFile,"\"%s.fmt\"",mName.c_str());
	}
	void getFoamOffset()const
	{
		fprintf(mFile,"\"%s.fmo\"",mName.c_str());
	}
	void getOutFoam()const
	{
		fprintf(mFile,"\"%s.ofm\"",mName.c_str());
	}
	void getDisplacement()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getBumpBlur()const
	{
		fprintf(mFile,"\"%s.bbl\"",mName.c_str());
	}
	void getHorizonFilter()const
	{
		fprintf(mFile,"\"%s.hft\"",mName.c_str());
	}
	void getWaveSpeed()const
	{
		fprintf(mFile,"\"%s.wvs\"",mName.c_str());
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
	void getMiRefractionBlur()const
	{
		fprintf(mFile,"\"%s.mirfb\"",mName.c_str());
	}
	void getMiRefractionRays()const
	{
		fprintf(mFile,"\"%s.mirfr\"",mName.c_str());
	}
	void getMiReflectionBlur()const
	{
		fprintf(mFile,"\"%s.mircb\"",mName.c_str());
	}
	void getMiReflectionRays()const
	{
		fprintf(mFile,"\"%s.mircr\"",mName.c_str());
	}
	void getMiIrradiance()const
	{
		fprintf(mFile,"\"%s.mii\"",mName.c_str());
	}
	void getMiIrradianceR()const
	{
		fprintf(mFile,"\"%s.mii.miir\"",mName.c_str());
	}
	void getMiIrradianceG()const
	{
		fprintf(mFile,"\"%s.mii.miig\"",mName.c_str());
	}
	void getMiIrradianceB()const
	{
		fprintf(mFile,"\"%s.mii.miib\"",mName.c_str());
	}
	void getMiIrradianceColor()const
	{
		fprintf(mFile,"\"%s.miic\"",mName.c_str());
	}
	void getMiIrradianceColorR()const
	{
		fprintf(mFile,"\"%s.miic.miicr\"",mName.c_str());
	}
	void getMiIrradianceColorG()const
	{
		fprintf(mFile,"\"%s.miic.miicg\"",mName.c_str());
	}
	void getMiIrradianceColorB()const
	{
		fprintf(mFile,"\"%s.miic.miicb\"",mName.c_str());
	}
	void getMiDeriveFromMaya()const
	{
		fprintf(mFile,"\"%s.mifm\"",mName.c_str());
	}
	void getMiShinyness()const
	{
		fprintf(mFile,"\"%s.mis\"",mName.c_str());
	}
	void getMiSpecularColor()const
	{
		fprintf(mFile,"\"%s.misc\"",mName.c_str());
	}
	void getMiSpecularColorR()const
	{
		fprintf(mFile,"\"%s.misc.miscr\"",mName.c_str());
	}
	void getMiSpecularColorG()const
	{
		fprintf(mFile,"\"%s.misc.miscg\"",mName.c_str());
	}
	void getMiSpecularColorB()const
	{
		fprintf(mFile,"\"%s.misc.miscb\"",mName.c_str());
	}
	void getMiReflectivity()const
	{
		fprintf(mFile,"\"%s.mirf\"",mName.c_str());
	}
	void getMiRefractiveIndex()const
	{
		fprintf(mFile,"\"%s.miri\"",mName.c_str());
	}
	void getMiRefractions()const
	{
		fprintf(mFile,"\"%s.mirc\"",mName.c_str());
	}
	void getMiAbsorbs()const
	{
		fprintf(mFile,"\"%s.miab\"",mName.c_str());
	}
	void getMiDiffuse()const
	{
		fprintf(mFile,"\"%s.midc\"",mName.c_str());
	}
	void getMiColor()const
	{
		fprintf(mFile,"\"%s.mic\"",mName.c_str());
	}
	void getMiColorR()const
	{
		fprintf(mFile,"\"%s.mic.micr\"",mName.c_str());
	}
	void getMiColorG()const
	{
		fprintf(mFile,"\"%s.mic.micg\"",mName.c_str());
	}
	void getMiColorB()const
	{
		fprintf(mFile,"\"%s.mic.micb\"",mName.c_str());
	}
	void getMiTransparency()const
	{
		fprintf(mFile,"\"%s.mit\"",mName.c_str());
	}
	void getMiTransparencyR()const
	{
		fprintf(mFile,"\"%s.mit.mitr\"",mName.c_str());
	}
	void getMiTransparencyG()const
	{
		fprintf(mFile,"\"%s.mit.mitg\"",mName.c_str());
	}
	void getMiTransparencyB()const
	{
		fprintf(mFile,"\"%s.mit.mitb\"",mName.c_str());
	}
	void getMiTranslucence()const
	{
		fprintf(mFile,"\"%s.mitc\"",mName.c_str());
	}
	void getMiTranslucenceFocus()const
	{
		fprintf(mFile,"\"%s.mitf\"",mName.c_str());
	}
	void getMiNormalCamera()const
	{
		fprintf(mFile,"\"%s.minc\"",mName.c_str());
	}
	void getMiNormalCameraX()const
	{
		fprintf(mFile,"\"%s.minc.mincx\"",mName.c_str());
	}
	void getMiNormalCameraY()const
	{
		fprintf(mFile,"\"%s.minc.mincy\"",mName.c_str());
	}
	void getMiNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.minc.mincz\"",mName.c_str());
	}
protected:
	OceanShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OCEANSHADER_H__
