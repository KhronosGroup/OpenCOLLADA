/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	RampShader():DependNode(){}
	RampShader(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "rampShader", shared, create){}
	virtual ~RampShader(){}

	void setRefractionLimit(short rdl)
	{
		if(rdl == 6) return;
		fprintf(mFile,"\tsetAttr \".rdl\" %i;\n", rdl);
	}
	void setRefractiveIndex(float rfi)
	{
		if(rfi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rfi\" %f;\n", rfi);
	}
	void setRefractions(bool rfc)
	{
		if(rfc == false) return;
		fprintf(mFile,"\tsetAttr \".rfc\" %i;\n", rfc);
	}
	void setDiffuse(float dc)
	{
		if(dc == 0.8) return;
		fprintf(mFile,"\tsetAttr \".dc\" %f;\n", dc);
	}
	void setForwardScatter(float fsc)
	{
		if(fsc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fsc\" %f;\n", fsc);
	}
	void setColor(size_t clr_i,const Color& clr)
	{
		fprintf(mFile,"\tsetAttr \".clr[%i]\" ",clr_i);
		clr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor(size_t clr_start,size_t clr_end,Color* clr)
	{
		fprintf(mFile,"\tsetAttr \".clr[%i:%i]\" ", clr_start,clr_end);
		size_t size = (clr_end-clr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			clr[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startColor(size_t clr_start,size_t clr_end)const
	{
		fprintf(mFile,"\tsetAttr \".clr[%i:%i]\"",clr_start,clr_end);
		fprintf(mFile," -type \"Color\" ");
	}
	void appendColor(const Color& clr)const
	{
		fprintf(mFile," ");
		clr.write(mFile);
	}
	void endColor()const
	{
		fprintf(mFile,";\n");
	}
	void setColor_Position(size_t clr_i,float clrp)
	{
		if(clrp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr[%i].clrp\" %f;\n", clr_i,clrp);
	}
	void setColor_Color(size_t clr_i,const float3& clrc)
	{
		fprintf(mFile,"\tsetAttr \".clr[%i].clrc\" -type \"float3\" ",clr_i);
		clrc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor_ColorR(size_t clr_i,float clrcr)
	{
		if(clrcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr[%i].clrc.clrcr\" %f;\n", clr_i,clrcr);
	}
	void setColor_ColorG(size_t clr_i,float clrcg)
	{
		if(clrcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr[%i].clrc.clrcg\" %f;\n", clr_i,clrcg);
	}
	void setColor_ColorB(size_t clr_i,float clrcb)
	{
		if(clrcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr[%i].clrc.clrcb\" %f;\n", clr_i,clrcb);
	}
	void setColor_Interp(size_t clr_i,unsigned int clri)
	{
		if(clri == 0) return;
		fprintf(mFile,"\tsetAttr \".clr[%i].clri\" %i;\n", clr_i,clri);
	}
	void setColorInput(unsigned int cin)
	{
		if(cin == 0) return;
		fprintf(mFile,"\tsetAttr \".cin\" %i;\n", cin);
	}
	void setShadowMode(unsigned int smd)
	{
		if(smd == 0) return;
		fprintf(mFile,"\tsetAttr \".smd\" %i;\n", smd);
	}
	void setShadowColor(const float3& shc)
	{
		fprintf(mFile,"\tsetAttr \".shc\" -type \"float3\" ");
		shc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setShadowColorR(float shr)
	{
		if(shr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".shc.shr\" %f;\n", shr);
	}
	void setShadowColorG(float shg)
	{
		if(shg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".shc.shg\" %f;\n", shg);
	}
	void setShadowColorB(float shb)
	{
		if(shb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".shc.shb\" %f;\n", shb);
	}
	void setShadowThreshold(float sht)
	{
		if(sht == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sht\" %f;\n", sht);
	}
	void setTransparency(size_t it_i,const Transparency& it)
	{
		fprintf(mFile,"\tsetAttr \".it[%i]\" ",it_i);
		it.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransparency(size_t it_start,size_t it_end,Transparency* it)
	{
		fprintf(mFile,"\tsetAttr \".it[%i:%i]\" ", it_start,it_end);
		size_t size = (it_end-it_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			it[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startTransparency(size_t it_start,size_t it_end)const
	{
		fprintf(mFile,"\tsetAttr \".it[%i:%i]\"",it_start,it_end);
		fprintf(mFile," -type \"Transparency\" ");
	}
	void appendTransparency(const Transparency& it)const
	{
		fprintf(mFile," ");
		it.write(mFile);
	}
	void endTransparency()const
	{
		fprintf(mFile,";\n");
	}
	void setTransparency_Position(size_t it_i,float itp)
	{
		if(itp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it[%i].itp\" %f;\n", it_i,itp);
	}
	void setTransparency_Color(size_t it_i,const float3& itc)
	{
		fprintf(mFile,"\tsetAttr \".it[%i].itc\" -type \"float3\" ",it_i);
		itc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransparency_ColorR(size_t it_i,float itcr)
	{
		if(itcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it[%i].itc.itcr\" %f;\n", it_i,itcr);
	}
	void setTransparency_ColorG(size_t it_i,float itcg)
	{
		if(itcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it[%i].itc.itcg\" %f;\n", it_i,itcg);
	}
	void setTransparency_ColorB(size_t it_i,float itcb)
	{
		if(itcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it[%i].itc.itcb\" %f;\n", it_i,itcb);
	}
	void setTransparency_Interp(size_t it_i,unsigned int iti)
	{
		if(iti == 0) return;
		fprintf(mFile,"\tsetAttr \".it[%i].iti\" %i;\n", it_i,iti);
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
	void setIncandescence(size_t ic_i,const Incandescence& ic)
	{
		fprintf(mFile,"\tsetAttr \".ic[%i]\" ",ic_i);
		ic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIncandescence(size_t ic_start,size_t ic_end,Incandescence* ic)
	{
		fprintf(mFile,"\tsetAttr \".ic[%i:%i]\" ", ic_start,ic_end);
		size_t size = (ic_end-ic_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ic[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startIncandescence(size_t ic_start,size_t ic_end)const
	{
		fprintf(mFile,"\tsetAttr \".ic[%i:%i]\"",ic_start,ic_end);
		fprintf(mFile," -type \"Incandescence\" ");
	}
	void appendIncandescence(const Incandescence& ic)const
	{
		fprintf(mFile," ");
		ic.write(mFile);
	}
	void endIncandescence()const
	{
		fprintf(mFile,";\n");
	}
	void setIncandescence_Position(size_t ic_i,float icp)
	{
		if(icp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic[%i].icp\" %f;\n", ic_i,icp);
	}
	void setIncandescence_Color(size_t ic_i,const float3& icc)
	{
		fprintf(mFile,"\tsetAttr \".ic[%i].icc\" -type \"float3\" ",ic_i);
		icc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIncandescence_ColorR(size_t ic_i,float iccr)
	{
		if(iccr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic[%i].icc.iccr\" %f;\n", ic_i,iccr);
	}
	void setIncandescence_ColorG(size_t ic_i,float iccg)
	{
		if(iccg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic[%i].icc.iccg\" %f;\n", ic_i,iccg);
	}
	void setIncandescence_ColorB(size_t ic_i,float iccb)
	{
		if(iccb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic[%i].icc.iccb\" %f;\n", ic_i,iccb);
	}
	void setIncandescence_Interp(size_t ic_i,unsigned int ici)
	{
		if(ici == 0) return;
		fprintf(mFile,"\tsetAttr \".ic[%i].ici\" %i;\n", ic_i,ici);
	}
	void setTranslucence(float tc)
	{
		if(tc == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tc\" %f;\n", tc);
	}
	void setTranslucenceFocus(float tcf)
	{
		if(tcf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tcf\" %f;\n", tcf);
	}
	void setTranslucenceDepth(float trsd)
	{
		if(trsd == 0.05) return;
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
	void setHideSource(bool hs)
	{
		if(hs == false) return;
		fprintf(mFile,"\tsetAttr \".hs\" %i;\n", hs);
	}
	void setSurfaceThickness(float thik)
	{
		if(thik == 0.0) return;
		fprintf(mFile,"\tsetAttr \".thik\" %f;\n", thik);
	}
	void setShadowAttenuation(float fakc)
	{
		if(fakc == 0.5) return;
		fprintf(mFile,"\tsetAttr \".fakc\" %f;\n", fakc);
	}
	void setTransparencyDepth(float trdp)
	{
		if(trdp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".trdp\" %f;\n", trdp);
	}
	void setLightAbsorbance(float absb)
	{
		if(absb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".absb\" %f;\n", absb);
	}
	void setChromaticAberration(bool crab)
	{
		if(crab == false) return;
		fprintf(mFile,"\tsetAttr \".crab\" %i;\n", crab);
	}
	void setEccentricity(float ec)
	{
		if(ec == 0.3) return;
		fprintf(mFile,"\tsetAttr \".ec\" %f;\n", ec);
	}
	void setSpecularity(float spl)
	{
		if(spl == 0.3) return;
		fprintf(mFile,"\tsetAttr \".spl\" %f;\n", spl);
	}
	void setSpecularRollOff(size_t sro_i,const SpecularRollOff& sro)
	{
		fprintf(mFile,"\tsetAttr \".sro[%i]\" ",sro_i);
		sro.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpecularRollOff(size_t sro_start,size_t sro_end,SpecularRollOff* sro)
	{
		fprintf(mFile,"\tsetAttr \".sro[%i:%i]\" ", sro_start,sro_end);
		size_t size = (sro_end-sro_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			sro[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startSpecularRollOff(size_t sro_start,size_t sro_end)const
	{
		fprintf(mFile,"\tsetAttr \".sro[%i:%i]\"",sro_start,sro_end);
		fprintf(mFile," -type \"SpecularRollOff\" ");
	}
	void appendSpecularRollOff(const SpecularRollOff& sro)const
	{
		fprintf(mFile," ");
		sro.write(mFile);
	}
	void endSpecularRollOff()const
	{
		fprintf(mFile,";\n");
	}
	void setSpecularRollOff_Position(size_t sro_i,float srop)
	{
		if(srop == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sro[%i].srop\" %f;\n", sro_i,srop);
	}
	void setSpecularRollOff_FloatValue(size_t sro_i,float srofv)
	{
		if(srofv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sro[%i].srofv\" %f;\n", sro_i,srofv);
	}
	void setSpecularRollOff_Interp(size_t sro_i,unsigned int sroi)
	{
		if(sroi == 0) return;
		fprintf(mFile,"\tsetAttr \".sro[%i].sroi\" %i;\n", sro_i,sroi);
	}
	void setReflectionLimit(short fll)
	{
		if(fll == 1) return;
		fprintf(mFile,"\tsetAttr \".fll\" %i;\n", fll);
	}
	void setSpecularColor(size_t sc_i,const SpecularColor& sc)
	{
		fprintf(mFile,"\tsetAttr \".sc[%i]\" ",sc_i);
		sc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpecularColor(size_t sc_start,size_t sc_end,SpecularColor* sc)
	{
		fprintf(mFile,"\tsetAttr \".sc[%i:%i]\" ", sc_start,sc_end);
		size_t size = (sc_end-sc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			sc[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startSpecularColor(size_t sc_start,size_t sc_end)const
	{
		fprintf(mFile,"\tsetAttr \".sc[%i:%i]\"",sc_start,sc_end);
		fprintf(mFile," -type \"SpecularColor\" ");
	}
	void appendSpecularColor(const SpecularColor& sc)const
	{
		fprintf(mFile," ");
		sc.write(mFile);
	}
	void endSpecularColor()const
	{
		fprintf(mFile,";\n");
	}
	void setSpecularColor_Position(size_t sc_i,float scp)
	{
		if(scp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc[%i].scp\" %f;\n", sc_i,scp);
	}
	void setSpecularColor_Color(size_t sc_i,const float3& scc)
	{
		fprintf(mFile,"\tsetAttr \".sc[%i].scc\" -type \"float3\" ",sc_i);
		scc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpecularColor_ColorR(size_t sc_i,float sccr)
	{
		if(sccr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc[%i].scc.sccr\" %f;\n", sc_i,sccr);
	}
	void setSpecularColor_ColorG(size_t sc_i,float sccg)
	{
		if(sccg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc[%i].scc.sccg\" %f;\n", sc_i,sccg);
	}
	void setSpecularColor_ColorB(size_t sc_i,float sccb)
	{
		if(sccb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc[%i].scc.sccb\" %f;\n", sc_i,sccb);
	}
	void setSpecularColor_Interp(size_t sc_i,unsigned int sci)
	{
		if(sci == 0) return;
		fprintf(mFile,"\tsetAttr \".sc[%i].sci\" %i;\n", sc_i,sci);
	}
	void setReflectivity(size_t rfl_i,const Reflectivity& rfl)
	{
		fprintf(mFile,"\tsetAttr \".rfl[%i]\" ",rfl_i);
		rfl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setReflectivity(size_t rfl_start,size_t rfl_end,Reflectivity* rfl)
	{
		fprintf(mFile,"\tsetAttr \".rfl[%i:%i]\" ", rfl_start,rfl_end);
		size_t size = (rfl_end-rfl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			rfl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startReflectivity(size_t rfl_start,size_t rfl_end)const
	{
		fprintf(mFile,"\tsetAttr \".rfl[%i:%i]\"",rfl_start,rfl_end);
		fprintf(mFile," -type \"Reflectivity\" ");
	}
	void appendReflectivity(const Reflectivity& rfl)const
	{
		fprintf(mFile," ");
		rfl.write(mFile);
	}
	void endReflectivity()const
	{
		fprintf(mFile,";\n");
	}
	void setReflectivity_Position(size_t rfl_i,float rflp)
	{
		if(rflp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rfl[%i].rflp\" %f;\n", rfl_i,rflp);
	}
	void setReflectivity_FloatValue(size_t rfl_i,float rflfv)
	{
		if(rflfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rfl[%i].rflfv\" %f;\n", rfl_i,rflfv);
	}
	void setReflectivity_Interp(size_t rfl_i,unsigned int rfli)
	{
		if(rfli == 0) return;
		fprintf(mFile,"\tsetAttr \".rfl[%i].rfli\" %i;\n", rfl_i,rfli);
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
	void getForwardScatter()const
	{
		fprintf(mFile,"\"%s.fsc\"",mName.c_str());
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
	void getColor(size_t clr_i)const
	{
		fprintf(mFile,"\"%s.clr[%i]\"",mName.c_str(),clr_i);
	}
	void getColor()const
	{

		fprintf(mFile,"\"%s.clr\"",mName.c_str());
	}
	void getColor_Position(size_t clr_i)const
	{
		fprintf(mFile,"\"%s.clr[%i].clrp\"",mName.c_str(),clr_i);
	}
	void getColor_Position()const
	{

		fprintf(mFile,"\"%s.clr.clrp\"",mName.c_str());
	}
	void getColor_Color(size_t clr_i)const
	{
		fprintf(mFile,"\"%s.clr[%i].clrc\"",mName.c_str(),clr_i);
	}
	void getColor_Color()const
	{

		fprintf(mFile,"\"%s.clr.clrc\"",mName.c_str());
	}
	void getColor_ColorR(size_t clr_i)const
	{
		fprintf(mFile,"\"%s.clr[%i].clrc.clrcr\"",mName.c_str(),clr_i);
	}
	void getColor_ColorR()const
	{

		fprintf(mFile,"\"%s.clr.clrc.clrcr\"",mName.c_str());
	}
	void getColor_ColorG(size_t clr_i)const
	{
		fprintf(mFile,"\"%s.clr[%i].clrc.clrcg\"",mName.c_str(),clr_i);
	}
	void getColor_ColorG()const
	{

		fprintf(mFile,"\"%s.clr.clrc.clrcg\"",mName.c_str());
	}
	void getColor_ColorB(size_t clr_i)const
	{
		fprintf(mFile,"\"%s.clr[%i].clrc.clrcb\"",mName.c_str(),clr_i);
	}
	void getColor_ColorB()const
	{

		fprintf(mFile,"\"%s.clr.clrc.clrcb\"",mName.c_str());
	}
	void getColor_Interp(size_t clr_i)const
	{
		fprintf(mFile,"\"%s.clr[%i].clri\"",mName.c_str(),clr_i);
	}
	void getColor_Interp()const
	{

		fprintf(mFile,"\"%s.clr.clri\"",mName.c_str());
	}
	void getColorInput()const
	{
		fprintf(mFile,"\"%s.cin\"",mName.c_str());
	}
	void getShadowMode()const
	{
		fprintf(mFile,"\"%s.smd\"",mName.c_str());
	}
	void getShadowColor()const
	{
		fprintf(mFile,"\"%s.shc\"",mName.c_str());
	}
	void getShadowColorR()const
	{
		fprintf(mFile,"\"%s.shc.shr\"",mName.c_str());
	}
	void getShadowColorG()const
	{
		fprintf(mFile,"\"%s.shc.shg\"",mName.c_str());
	}
	void getShadowColorB()const
	{
		fprintf(mFile,"\"%s.shc.shb\"",mName.c_str());
	}
	void getShadowThreshold()const
	{
		fprintf(mFile,"\"%s.sht\"",mName.c_str());
	}
	void getTransparency(size_t it_i)const
	{
		fprintf(mFile,"\"%s.it[%i]\"",mName.c_str(),it_i);
	}
	void getTransparency()const
	{

		fprintf(mFile,"\"%s.it\"",mName.c_str());
	}
	void getTransparency_Position(size_t it_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itp\"",mName.c_str(),it_i);
	}
	void getTransparency_Position()const
	{

		fprintf(mFile,"\"%s.it.itp\"",mName.c_str());
	}
	void getTransparency_Color(size_t it_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itc\"",mName.c_str(),it_i);
	}
	void getTransparency_Color()const
	{

		fprintf(mFile,"\"%s.it.itc\"",mName.c_str());
	}
	void getTransparency_ColorR(size_t it_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itc.itcr\"",mName.c_str(),it_i);
	}
	void getTransparency_ColorR()const
	{

		fprintf(mFile,"\"%s.it.itc.itcr\"",mName.c_str());
	}
	void getTransparency_ColorG(size_t it_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itc.itcg\"",mName.c_str(),it_i);
	}
	void getTransparency_ColorG()const
	{

		fprintf(mFile,"\"%s.it.itc.itcg\"",mName.c_str());
	}
	void getTransparency_ColorB(size_t it_i)const
	{
		fprintf(mFile,"\"%s.it[%i].itc.itcb\"",mName.c_str(),it_i);
	}
	void getTransparency_ColorB()const
	{

		fprintf(mFile,"\"%s.it.itc.itcb\"",mName.c_str());
	}
	void getTransparency_Interp(size_t it_i)const
	{
		fprintf(mFile,"\"%s.it[%i].iti\"",mName.c_str(),it_i);
	}
	void getTransparency_Interp()const
	{

		fprintf(mFile,"\"%s.it.iti\"",mName.c_str());
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
	void getIncandescence(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i]\"",mName.c_str(),ic_i);
	}
	void getIncandescence()const
	{

		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getIncandescence_Position(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i].icp\"",mName.c_str(),ic_i);
	}
	void getIncandescence_Position()const
	{

		fprintf(mFile,"\"%s.ic.icp\"",mName.c_str());
	}
	void getIncandescence_Color(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i].icc\"",mName.c_str(),ic_i);
	}
	void getIncandescence_Color()const
	{

		fprintf(mFile,"\"%s.ic.icc\"",mName.c_str());
	}
	void getIncandescence_ColorR(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i].icc.iccr\"",mName.c_str(),ic_i);
	}
	void getIncandescence_ColorR()const
	{

		fprintf(mFile,"\"%s.ic.icc.iccr\"",mName.c_str());
	}
	void getIncandescence_ColorG(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i].icc.iccg\"",mName.c_str(),ic_i);
	}
	void getIncandescence_ColorG()const
	{

		fprintf(mFile,"\"%s.ic.icc.iccg\"",mName.c_str());
	}
	void getIncandescence_ColorB(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i].icc.iccb\"",mName.c_str(),ic_i);
	}
	void getIncandescence_ColorB()const
	{

		fprintf(mFile,"\"%s.ic.icc.iccb\"",mName.c_str());
	}
	void getIncandescence_Interp(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i].ici\"",mName.c_str(),ic_i);
	}
	void getIncandescence_Interp()const
	{

		fprintf(mFile,"\"%s.ic.ici\"",mName.c_str());
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
	void getHideSource()const
	{
		fprintf(mFile,"\"%s.hs\"",mName.c_str());
	}
	void getSurfaceThickness()const
	{
		fprintf(mFile,"\"%s.thik\"",mName.c_str());
	}
	void getShadowAttenuation()const
	{
		fprintf(mFile,"\"%s.fakc\"",mName.c_str());
	}
	void getTransparencyDepth()const
	{
		fprintf(mFile,"\"%s.trdp\"",mName.c_str());
	}
	void getLightAbsorbance()const
	{
		fprintf(mFile,"\"%s.absb\"",mName.c_str());
	}
	void getChromaticAberration()const
	{
		fprintf(mFile,"\"%s.crab\"",mName.c_str());
	}
	void getEccentricity()const
	{
		fprintf(mFile,"\"%s.ec\"",mName.c_str());
	}
	void getSpecularity()const
	{
		fprintf(mFile,"\"%s.spl\"",mName.c_str());
	}
	void getSpecularRollOff(size_t sro_i)const
	{
		fprintf(mFile,"\"%s.sro[%i]\"",mName.c_str(),sro_i);
	}
	void getSpecularRollOff()const
	{

		fprintf(mFile,"\"%s.sro\"",mName.c_str());
	}
	void getSpecularRollOff_Position(size_t sro_i)const
	{
		fprintf(mFile,"\"%s.sro[%i].srop\"",mName.c_str(),sro_i);
	}
	void getSpecularRollOff_Position()const
	{

		fprintf(mFile,"\"%s.sro.srop\"",mName.c_str());
	}
	void getSpecularRollOff_FloatValue(size_t sro_i)const
	{
		fprintf(mFile,"\"%s.sro[%i].srofv\"",mName.c_str(),sro_i);
	}
	void getSpecularRollOff_FloatValue()const
	{

		fprintf(mFile,"\"%s.sro.srofv\"",mName.c_str());
	}
	void getSpecularRollOff_Interp(size_t sro_i)const
	{
		fprintf(mFile,"\"%s.sro[%i].sroi\"",mName.c_str(),sro_i);
	}
	void getSpecularRollOff_Interp()const
	{

		fprintf(mFile,"\"%s.sro.sroi\"",mName.c_str());
	}
	void getReflectionLimit()const
	{
		fprintf(mFile,"\"%s.fll\"",mName.c_str());
	}
	void getSpecularColor(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i]\"",mName.c_str(),sc_i);
	}
	void getSpecularColor()const
	{

		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getSpecularColor_Position(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i].scp\"",mName.c_str(),sc_i);
	}
	void getSpecularColor_Position()const
	{

		fprintf(mFile,"\"%s.sc.scp\"",mName.c_str());
	}
	void getSpecularColor_Color(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i].scc\"",mName.c_str(),sc_i);
	}
	void getSpecularColor_Color()const
	{

		fprintf(mFile,"\"%s.sc.scc\"",mName.c_str());
	}
	void getSpecularColor_ColorR(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i].scc.sccr\"",mName.c_str(),sc_i);
	}
	void getSpecularColor_ColorR()const
	{

		fprintf(mFile,"\"%s.sc.scc.sccr\"",mName.c_str());
	}
	void getSpecularColor_ColorG(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i].scc.sccg\"",mName.c_str(),sc_i);
	}
	void getSpecularColor_ColorG()const
	{

		fprintf(mFile,"\"%s.sc.scc.sccg\"",mName.c_str());
	}
	void getSpecularColor_ColorB(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i].scc.sccb\"",mName.c_str(),sc_i);
	}
	void getSpecularColor_ColorB()const
	{

		fprintf(mFile,"\"%s.sc.scc.sccb\"",mName.c_str());
	}
	void getSpecularColor_Interp(size_t sc_i)const
	{
		fprintf(mFile,"\"%s.sc[%i].sci\"",mName.c_str(),sc_i);
	}
	void getSpecularColor_Interp()const
	{

		fprintf(mFile,"\"%s.sc.sci\"",mName.c_str());
	}
	void getReflectivity(size_t rfl_i)const
	{
		fprintf(mFile,"\"%s.rfl[%i]\"",mName.c_str(),rfl_i);
	}
	void getReflectivity()const
	{

		fprintf(mFile,"\"%s.rfl\"",mName.c_str());
	}
	void getReflectivity_Position(size_t rfl_i)const
	{
		fprintf(mFile,"\"%s.rfl[%i].rflp\"",mName.c_str(),rfl_i);
	}
	void getReflectivity_Position()const
	{

		fprintf(mFile,"\"%s.rfl.rflp\"",mName.c_str());
	}
	void getReflectivity_FloatValue(size_t rfl_i)const
	{
		fprintf(mFile,"\"%s.rfl[%i].rflfv\"",mName.c_str(),rfl_i);
	}
	void getReflectivity_FloatValue()const
	{

		fprintf(mFile,"\"%s.rfl.rflfv\"",mName.c_str());
	}
	void getReflectivity_Interp(size_t rfl_i)const
	{
		fprintf(mFile,"\"%s.rfl[%i].rfli\"",mName.c_str(),rfl_i);
	}
	void getReflectivity_Interp()const
	{

		fprintf(mFile,"\"%s.rfl.rfli\"",mName.c_str());
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
	RampShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RAMPSHADER_H__
