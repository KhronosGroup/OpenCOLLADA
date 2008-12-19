/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RAMPSHADER_H__
#define __MayaDM_RAMPSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RampShader : public DependNode
{
public:
	struct Color{
		float color_Position;
		float3 color_Color;
		unsigned int color_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", color_Position);
			color_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", color_Interp);
		}
	};
	struct Transparency{
		float transparency_Position;
		float3 transparency_Color;
		unsigned int transparency_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", transparency_Position);
			transparency_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", transparency_Interp);
		}
	};
	struct Incandescence{
		float incandescence_Position;
		float3 incandescence_Color;
		unsigned int incandescence_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", incandescence_Position);
			incandescence_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", incandescence_Interp);
		}
	};
	struct SpecularRollOff{
		float specularRollOff_Position;
		float specularRollOff_FloatValue;
		unsigned int specularRollOff_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", specularRollOff_Position);
			fprintf(file,"%f ", specularRollOff_FloatValue);
			fprintf(file,"%i", specularRollOff_Interp);
		}
	};
	struct SpecularColor{
		float specularColor_Position;
		float3 specularColor_Color;
		unsigned int specularColor_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", specularColor_Position);
			specularColor_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", specularColor_Interp);
		}
	};
	struct Reflectivity{
		float reflectivity_Position;
		float reflectivity_FloatValue;
		unsigned int reflectivity_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", reflectivity_Position);
			fprintf(file,"%f ", reflectivity_FloatValue);
			fprintf(file,"%i", reflectivity_Interp);
		}
	};
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
public:
	RampShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "rampShader"){}
	virtual ~RampShader(){}
	void setRefractionLimit(short rdl)
	{
		if(rdl == 6) return;
		fprintf(mFile,"setAttr \".rdl\" %i;\n", rdl);

	}
	void setRefractiveIndex(float rfi)
	{
		if(rfi == 1.0) return;
		fprintf(mFile,"setAttr \".rfi\" %f;\n", rfi);

	}
	void setRefractions(bool rfc)
	{
		if(rfc == false) return;
		fprintf(mFile,"setAttr \".rfc\" %i;\n", rfc);

	}
	void setDiffuse(float dc)
	{
		if(dc == 0.8) return;
		fprintf(mFile,"setAttr \".dc\" %f;\n", dc);

	}
	void setForwardScatter(float fsc)
	{
		if(fsc == 0.0) return;
		fprintf(mFile,"setAttr \".fsc\" %f;\n", fsc);

	}
	void setColor(size_t clr_i,const Color& clr)
	{
		fprintf(mFile,"setAttr \".clr[%i]\" ",clr_i);
		clr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor_Position(size_t clr_i,float clrp)
	{
		if(clrp == 0.0) return;
		fprintf(mFile,"setAttr \".clr[%i].clrp\" %f;\n", clr_i,clrp);

	}
	void setColor_Color(size_t clr_i,const float3& clrc)
	{
		fprintf(mFile,"setAttr \".clr[%i].clrc\" -type \"float3\" ",clr_i);
		clrc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor_ColorR(size_t clr_i,float clrcr)
	{
		if(clrcr == 0.0) return;
		fprintf(mFile,"setAttr \".clr[%i].clrc.clrcr\" %f;\n", clr_i,clrcr);

	}
	void setColor_ColorG(size_t clr_i,float clrcg)
	{
		if(clrcg == 0.0) return;
		fprintf(mFile,"setAttr \".clr[%i].clrc.clrcg\" %f;\n", clr_i,clrcg);

	}
	void setColor_ColorB(size_t clr_i,float clrcb)
	{
		if(clrcb == 0.0) return;
		fprintf(mFile,"setAttr \".clr[%i].clrc.clrcb\" %f;\n", clr_i,clrcb);

	}
	void setColor_Interp(size_t clr_i,unsigned int clri)
	{
		if(clri == 0) return;
		fprintf(mFile,"setAttr \".clr[%i].clri\" %i;\n", clr_i,clri);

	}
	void setColorInput(unsigned int cin)
	{
		if(cin == 0) return;
		fprintf(mFile,"setAttr \".cin\" %i;\n", cin);

	}
	void setShadowMode(unsigned int smd)
	{
		if(smd == 0) return;
		fprintf(mFile,"setAttr \".smd\" %i;\n", smd);

	}
	void setShadowColor(const float3& shc)
	{
		fprintf(mFile,"setAttr \".shc\" -type \"float3\" ");
		shc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setShadowColorR(float shr)
	{
		if(shr == 0.0) return;
		fprintf(mFile,"setAttr \".shc.shr\" %f;\n", shr);

	}
	void setShadowColorG(float shg)
	{
		if(shg == 0.0) return;
		fprintf(mFile,"setAttr \".shc.shg\" %f;\n", shg);

	}
	void setShadowColorB(float shb)
	{
		if(shb == 0.0) return;
		fprintf(mFile,"setAttr \".shc.shb\" %f;\n", shb);

	}
	void setShadowThreshold(float sht)
	{
		if(sht == 0.0) return;
		fprintf(mFile,"setAttr \".sht\" %f;\n", sht);

	}
	void setTransparency(size_t it_i,const Transparency& it)
	{
		fprintf(mFile,"setAttr \".it[%i]\" ",it_i);
		it.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTransparency_Position(size_t it_i,float itp)
	{
		if(itp == 0.0) return;
		fprintf(mFile,"setAttr \".it[%i].itp\" %f;\n", it_i,itp);

	}
	void setTransparency_Color(size_t it_i,const float3& itc)
	{
		fprintf(mFile,"setAttr \".it[%i].itc\" -type \"float3\" ",it_i);
		itc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTransparency_ColorR(size_t it_i,float itcr)
	{
		if(itcr == 0.0) return;
		fprintf(mFile,"setAttr \".it[%i].itc.itcr\" %f;\n", it_i,itcr);

	}
	void setTransparency_ColorG(size_t it_i,float itcg)
	{
		if(itcg == 0.0) return;
		fprintf(mFile,"setAttr \".it[%i].itc.itcg\" %f;\n", it_i,itcg);

	}
	void setTransparency_ColorB(size_t it_i,float itcb)
	{
		if(itcb == 0.0) return;
		fprintf(mFile,"setAttr \".it[%i].itc.itcb\" %f;\n", it_i,itcb);

	}
	void setTransparency_Interp(size_t it_i,unsigned int iti)
	{
		if(iti == 0) return;
		fprintf(mFile,"setAttr \".it[%i].iti\" %i;\n", it_i,iti);

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
	void setIncandescence(size_t ic_i,const Incandescence& ic)
	{
		fprintf(mFile,"setAttr \".ic[%i]\" ",ic_i);
		ic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIncandescence_Position(size_t ic_i,float icp)
	{
		if(icp == 0.0) return;
		fprintf(mFile,"setAttr \".ic[%i].icp\" %f;\n", ic_i,icp);

	}
	void setIncandescence_Color(size_t ic_i,const float3& icc)
	{
		fprintf(mFile,"setAttr \".ic[%i].icc\" -type \"float3\" ",ic_i);
		icc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIncandescence_ColorR(size_t ic_i,float iccr)
	{
		if(iccr == 0.0) return;
		fprintf(mFile,"setAttr \".ic[%i].icc.iccr\" %f;\n", ic_i,iccr);

	}
	void setIncandescence_ColorG(size_t ic_i,float iccg)
	{
		if(iccg == 0.0) return;
		fprintf(mFile,"setAttr \".ic[%i].icc.iccg\" %f;\n", ic_i,iccg);

	}
	void setIncandescence_ColorB(size_t ic_i,float iccb)
	{
		if(iccb == 0.0) return;
		fprintf(mFile,"setAttr \".ic[%i].icc.iccb\" %f;\n", ic_i,iccb);

	}
	void setIncandescence_Interp(size_t ic_i,unsigned int ici)
	{
		if(ici == 0) return;
		fprintf(mFile,"setAttr \".ic[%i].ici\" %i;\n", ic_i,ici);

	}
	void setTranslucence(float tc)
	{
		if(tc == 0.0) return;
		fprintf(mFile,"setAttr \".tc\" %f;\n", tc);

	}
	void setTranslucenceFocus(float tcf)
	{
		if(tcf == 0.0) return;
		fprintf(mFile,"setAttr \".tcf\" %f;\n", tcf);

	}
	void setTranslucenceDepth(float trsd)
	{
		if(trsd == 0.05) return;
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
	void setHideSource(bool hs)
	{
		if(hs == false) return;
		fprintf(mFile,"setAttr \".hs\" %i;\n", hs);

	}
	void setSurfaceThickness(float thik)
	{
		if(thik == 0.0) return;
		fprintf(mFile,"setAttr \".thik\" %f;\n", thik);

	}
	void setShadowAttenuation(float fakc)
	{
		if(fakc == 0.5) return;
		fprintf(mFile,"setAttr \".fakc\" %f;\n", fakc);

	}
	void setTransparencyDepth(float trdp)
	{
		if(trdp == 0.0) return;
		fprintf(mFile,"setAttr \".trdp\" %f;\n", trdp);

	}
	void setLightAbsorbance(float absb)
	{
		if(absb == 0.0) return;
		fprintf(mFile,"setAttr \".absb\" %f;\n", absb);

	}
	void setChromaticAberration(bool crab)
	{
		if(crab == false) return;
		fprintf(mFile,"setAttr \".crab\" %i;\n", crab);

	}
	void setEccentricity(float ec)
	{
		if(ec == 0.3) return;
		fprintf(mFile,"setAttr \".ec\" %f;\n", ec);

	}
	void setSpecularity(float spl)
	{
		if(spl == 0.3) return;
		fprintf(mFile,"setAttr \".spl\" %f;\n", spl);

	}
	void setSpecularRollOff(size_t sro_i,const SpecularRollOff& sro)
	{
		fprintf(mFile,"setAttr \".sro[%i]\" ",sro_i);
		sro.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpecularRollOff_Position(size_t sro_i,float srop)
	{
		if(srop == 0.0) return;
		fprintf(mFile,"setAttr \".sro[%i].srop\" %f;\n", sro_i,srop);

	}
	void setSpecularRollOff_FloatValue(size_t sro_i,float srofv)
	{
		if(srofv == 0.0) return;
		fprintf(mFile,"setAttr \".sro[%i].srofv\" %f;\n", sro_i,srofv);

	}
	void setSpecularRollOff_Interp(size_t sro_i,unsigned int sroi)
	{
		if(sroi == 0) return;
		fprintf(mFile,"setAttr \".sro[%i].sroi\" %i;\n", sro_i,sroi);

	}
	void setReflectionLimit(short fll)
	{
		if(fll == 1) return;
		fprintf(mFile,"setAttr \".fll\" %i;\n", fll);

	}
	void setSpecularColor(size_t sc_i,const SpecularColor& sc)
	{
		fprintf(mFile,"setAttr \".sc[%i]\" ",sc_i);
		sc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpecularColor_Position(size_t sc_i,float scp)
	{
		if(scp == 0.0) return;
		fprintf(mFile,"setAttr \".sc[%i].scp\" %f;\n", sc_i,scp);

	}
	void setSpecularColor_Color(size_t sc_i,const float3& scc)
	{
		fprintf(mFile,"setAttr \".sc[%i].scc\" -type \"float3\" ",sc_i);
		scc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpecularColor_ColorR(size_t sc_i,float sccr)
	{
		if(sccr == 0.0) return;
		fprintf(mFile,"setAttr \".sc[%i].scc.sccr\" %f;\n", sc_i,sccr);

	}
	void setSpecularColor_ColorG(size_t sc_i,float sccg)
	{
		if(sccg == 0.0) return;
		fprintf(mFile,"setAttr \".sc[%i].scc.sccg\" %f;\n", sc_i,sccg);

	}
	void setSpecularColor_ColorB(size_t sc_i,float sccb)
	{
		if(sccb == 0.0) return;
		fprintf(mFile,"setAttr \".sc[%i].scc.sccb\" %f;\n", sc_i,sccb);

	}
	void setSpecularColor_Interp(size_t sc_i,unsigned int sci)
	{
		if(sci == 0) return;
		fprintf(mFile,"setAttr \".sc[%i].sci\" %i;\n", sc_i,sci);

	}
	void setReflectivity(size_t rfl_i,const Reflectivity& rfl)
	{
		fprintf(mFile,"setAttr \".rfl[%i]\" ",rfl_i);
		rfl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setReflectivity_Position(size_t rfl_i,float rflp)
	{
		if(rflp == 0.0) return;
		fprintf(mFile,"setAttr \".rfl[%i].rflp\" %f;\n", rfl_i,rflp);

	}
	void setReflectivity_FloatValue(size_t rfl_i,float rflfv)
	{
		if(rflfv == 0.0) return;
		fprintf(mFile,"setAttr \".rfl[%i].rflfv\" %f;\n", rfl_i,rflfv);

	}
	void setReflectivity_Interp(size_t rfl_i,unsigned int rfli)
	{
		if(rfli == 0) return;
		fprintf(mFile,"setAttr \".rfl[%i].rfli\" %i;\n", rfl_i,rfli);

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
	void getForwardScatter()
	{
		fprintf(mFile,"\"%s.fsc\"",mName.c_str());

	}
	void getColor(size_t clr_i)
	{
		fprintf(mFile,"\"%s.clr[%i]\"",mName.c_str(),clr_i);

	}
	void getColor_Position(size_t clr_i)
	{
		fprintf(mFile,"\"%s.clr[%i].clrp\"",mName.c_str(),clr_i);

	}
	void getColor_Color(size_t clr_i)
	{
		fprintf(mFile,"\"%s.clr[%i].clrc\"",mName.c_str(),clr_i);

	}
	void getColor_ColorR(size_t clr_i)
	{
		fprintf(mFile,"\"%s.clr[%i].clrc.clrcr\"",mName.c_str(),clr_i);

	}
	void getColor_ColorG(size_t clr_i)
	{
		fprintf(mFile,"\"%s.clr[%i].clrc.clrcg\"",mName.c_str(),clr_i);

	}
	void getColor_ColorB(size_t clr_i)
	{
		fprintf(mFile,"\"%s.clr[%i].clrc.clrcb\"",mName.c_str(),clr_i);

	}
	void getColor_Interp(size_t clr_i)
	{
		fprintf(mFile,"\"%s.clr[%i].clri\"",mName.c_str(),clr_i);

	}
	void getColorInput()
	{
		fprintf(mFile,"\"%s.cin\"",mName.c_str());

	}
	void getShadowMode()
	{
		fprintf(mFile,"\"%s.smd\"",mName.c_str());

	}
	void getShadowColor()
	{
		fprintf(mFile,"\"%s.shc\"",mName.c_str());

	}
	void getShadowColorR()
	{
		fprintf(mFile,"\"%s.shc.shr\"",mName.c_str());

	}
	void getShadowColorG()
	{
		fprintf(mFile,"\"%s.shc.shg\"",mName.c_str());

	}
	void getShadowColorB()
	{
		fprintf(mFile,"\"%s.shc.shb\"",mName.c_str());

	}
	void getShadowThreshold()
	{
		fprintf(mFile,"\"%s.sht\"",mName.c_str());

	}
	void getTransparency(size_t it_i)
	{
		fprintf(mFile,"\"%s.it[%i]\"",mName.c_str(),it_i);

	}
	void getTransparency_Position(size_t it_i)
	{
		fprintf(mFile,"\"%s.it[%i].itp\"",mName.c_str(),it_i);

	}
	void getTransparency_Color(size_t it_i)
	{
		fprintf(mFile,"\"%s.it[%i].itc\"",mName.c_str(),it_i);

	}
	void getTransparency_ColorR(size_t it_i)
	{
		fprintf(mFile,"\"%s.it[%i].itc.itcr\"",mName.c_str(),it_i);

	}
	void getTransparency_ColorG(size_t it_i)
	{
		fprintf(mFile,"\"%s.it[%i].itc.itcg\"",mName.c_str(),it_i);

	}
	void getTransparency_ColorB(size_t it_i)
	{
		fprintf(mFile,"\"%s.it[%i].itc.itcb\"",mName.c_str(),it_i);

	}
	void getTransparency_Interp(size_t it_i)
	{
		fprintf(mFile,"\"%s.it[%i].iti\"",mName.c_str(),it_i);

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
	void getIncandescence(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i]\"",mName.c_str(),ic_i);

	}
	void getIncandescence_Position(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i].icp\"",mName.c_str(),ic_i);

	}
	void getIncandescence_Color(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i].icc\"",mName.c_str(),ic_i);

	}
	void getIncandescence_ColorR(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i].icc.iccr\"",mName.c_str(),ic_i);

	}
	void getIncandescence_ColorG(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i].icc.iccg\"",mName.c_str(),ic_i);

	}
	void getIncandescence_ColorB(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i].icc.iccb\"",mName.c_str(),ic_i);

	}
	void getIncandescence_Interp(size_t ic_i)
	{
		fprintf(mFile,"\"%s.ic[%i].ici\"",mName.c_str(),ic_i);

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
	void getHideSource()
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());

	}
	void getSurfaceThickness()
	{
		fprintf(mFile,"\"%s.thik\"",mName.c_str());

	}
	void getShadowAttenuation()
	{
		fprintf(mFile,"\"%s.fakc\"",mName.c_str());

	}
	void getTransparencyDepth()
	{
		fprintf(mFile,"\"%s.trdp\"",mName.c_str());

	}
	void getLightAbsorbance()
	{
		fprintf(mFile,"\"%s.absb\"",mName.c_str());

	}
	void getChromaticAberration()
	{
		fprintf(mFile,"\"%s.crab\"",mName.c_str());

	}
	void getEccentricity()
	{
		fprintf(mFile,"\"%s.ec\"",mName.c_str());

	}
	void getSpecularity()
	{
		fprintf(mFile,"\"%s.spl\"",mName.c_str());

	}
	void getSpecularRollOff(size_t sro_i)
	{
		fprintf(mFile,"\"%s.sro[%i]\"",mName.c_str(),sro_i);

	}
	void getSpecularRollOff_Position(size_t sro_i)
	{
		fprintf(mFile,"\"%s.sro[%i].srop\"",mName.c_str(),sro_i);

	}
	void getSpecularRollOff_FloatValue(size_t sro_i)
	{
		fprintf(mFile,"\"%s.sro[%i].srofv\"",mName.c_str(),sro_i);

	}
	void getSpecularRollOff_Interp(size_t sro_i)
	{
		fprintf(mFile,"\"%s.sro[%i].sroi\"",mName.c_str(),sro_i);

	}
	void getReflectionLimit()
	{
		fprintf(mFile,"\"%s.fll\"",mName.c_str());

	}
	void getSpecularColor(size_t sc_i)
	{
		fprintf(mFile,"\"%s.sc[%i]\"",mName.c_str(),sc_i);

	}
	void getSpecularColor_Position(size_t sc_i)
	{
		fprintf(mFile,"\"%s.sc[%i].scp\"",mName.c_str(),sc_i);

	}
	void getSpecularColor_Color(size_t sc_i)
	{
		fprintf(mFile,"\"%s.sc[%i].scc\"",mName.c_str(),sc_i);

	}
	void getSpecularColor_ColorR(size_t sc_i)
	{
		fprintf(mFile,"\"%s.sc[%i].scc.sccr\"",mName.c_str(),sc_i);

	}
	void getSpecularColor_ColorG(size_t sc_i)
	{
		fprintf(mFile,"\"%s.sc[%i].scc.sccg\"",mName.c_str(),sc_i);

	}
	void getSpecularColor_ColorB(size_t sc_i)
	{
		fprintf(mFile,"\"%s.sc[%i].scc.sccb\"",mName.c_str(),sc_i);

	}
	void getSpecularColor_Interp(size_t sc_i)
	{
		fprintf(mFile,"\"%s.sc[%i].sci\"",mName.c_str(),sc_i);

	}
	void getReflectivity(size_t rfl_i)
	{
		fprintf(mFile,"\"%s.rfl[%i]\"",mName.c_str(),rfl_i);

	}
	void getReflectivity_Position(size_t rfl_i)
	{
		fprintf(mFile,"\"%s.rfl[%i].rflp\"",mName.c_str(),rfl_i);

	}
	void getReflectivity_FloatValue(size_t rfl_i)
	{
		fprintf(mFile,"\"%s.rfl[%i].rflfv\"",mName.c_str(),rfl_i);

	}
	void getReflectivity_Interp(size_t rfl_i)
	{
		fprintf(mFile,"\"%s.rfl[%i].rfli\"",mName.c_str(),rfl_i);

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
	RampShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RAMPSHADER_H__
