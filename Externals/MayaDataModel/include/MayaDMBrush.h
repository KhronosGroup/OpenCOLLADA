/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BRUSH_H__
#define __MayaDM_BRUSH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Brush : public DependNode
{
public:
	struct LeafCurl{
		float leafCurl_Position;
		float leafCurl_FloatValue;
		unsigned int leafCurl_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", leafCurl_Position);
			fprintf(file,"%f ", leafCurl_FloatValue);
			fprintf(file,"%i", leafCurl_Interp);
		}
	};
	struct PetalCurl{
		float petalCurl_Position;
		float petalCurl_FloatValue;
		unsigned int petalCurl_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", petalCurl_Position);
			fprintf(file,"%f ", petalCurl_FloatValue);
			fprintf(file,"%i", petalCurl_Interp);
		}
	};
	struct WidthScale{
		float widthScale_Position;
		float widthScale_FloatValue;
		unsigned int widthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", widthScale_Position);
			fprintf(file,"%f ", widthScale_FloatValue);
			fprintf(file,"%i", widthScale_Interp);
		}
	};
	struct LeafWidthScale{
		float leafWidthScale_Position;
		float leafWidthScale_FloatValue;
		unsigned int leafWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", leafWidthScale_Position);
			fprintf(file,"%f ", leafWidthScale_FloatValue);
			fprintf(file,"%i", leafWidthScale_Interp);
		}
	};
	struct PetalWidthScale{
		float petalWidthScale_Position;
		float petalWidthScale_FloatValue;
		unsigned int petalWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", petalWidthScale_Position);
			fprintf(file,"%f ", petalWidthScale_FloatValue);
			fprintf(file,"%i", petalWidthScale_Interp);
		}
	};
	struct TwigLengthScale{
		float twigLengthScale_Position;
		float twigLengthScale_FloatValue;
		unsigned int twigLengthScale_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", twigLengthScale_Position);
			fprintf(file,"%f ", twigLengthScale_FloatValue);
			fprintf(file,"%i", twigLengthScale_Interp);
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
	struct ReflectionRolloff{
		float reflectionRolloff_Position;
		float reflectionRolloff_FloatValue;
		unsigned int reflectionRolloff_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", reflectionRolloff_Position);
			fprintf(file,"%f ", reflectionRolloff_FloatValue);
			fprintf(file,"%i", reflectionRolloff_Interp);
		}
	};
public:

	Brush():DependNode(){}
	Brush(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "brush", shared, create){}
	virtual ~Brush(){}

	void setTime(double tim)
	{
		if(tim == 0) return;
		fprintf(mFile,"\tsetAttr \".tim\" %f;\n", tim);
	}
	void setGlobalScale(double gsc)
	{
		if(gsc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gsc\" %f;\n", gsc);
	}
	void setDepth(bool dep)
	{
		if(dep == false) return;
		fprintf(mFile,"\tsetAttr \".dep\" %i;\n", dep);
	}
	void setModifyDepth(bool mdp)
	{
		if(mdp == true) return;
		fprintf(mFile,"\tsetAttr \".mdp\" %i;\n", mdp);
	}
	void setModifyColor(bool mdc)
	{
		if(mdc == true) return;
		fprintf(mFile,"\tsetAttr \".mdc\" %i;\n", mdc);
	}
	void setModifyAlpha(bool mda)
	{
		if(mda == true) return;
		fprintf(mFile,"\tsetAttr \".mda\" %i;\n", mda);
	}
	void setIlluminated(bool ill)
	{
		if(ill == false) return;
		fprintf(mFile,"\tsetAttr \".ill\" %i;\n", ill);
	}
	void setCastShadows(bool csd)
	{
		if(csd == false) return;
		fprintf(mFile,"\tsetAttr \".csd\" %i;\n", csd);
	}
	void setLightingBasedWidth(double lbw)
	{
		if(lbw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lbw\" %f;\n", lbw);
	}
	void setBranches(bool brc)
	{
		if(brc == false) return;
		fprintf(mFile,"\tsetAttr \".brc\" %i;\n", brc);
	}
	void setTwigs(bool twg)
	{
		if(twg == false) return;
		fprintf(mFile,"\tsetAttr \".twg\" %i;\n", twg);
	}
	void setBuds(bool bud)
	{
		if(bud == false) return;
		fprintf(mFile,"\tsetAttr \".bud\" %i;\n", bud);
	}
	void setLeaves(bool lvs)
	{
		if(lvs == false) return;
		fprintf(mFile,"\tsetAttr \".lvs\" %i;\n", lvs);
	}
	void setFlowers(bool flw)
	{
		if(flw == false) return;
		fprintf(mFile,"\tsetAttr \".flw\" %i;\n", flw);
	}
	void setBrushType(unsigned int brt)
	{
		if(brt == 0) return;
		fprintf(mFile,"\tsetAttr \".brt\" %i;\n", brt);
	}
	void setBrushWidth(double bwd)
	{
		if(bwd == 0.05) return;
		fprintf(mFile,"\tsetAttr \".bwd\" %f;\n", bwd);
	}
	void setScreenspaceWidth(bool spw)
	{
		if(spw == false) return;
		fprintf(mFile,"\tsetAttr \".spw\" %i;\n", spw);
	}
	void setDistanceScaling(double dsl)
	{
		if(dsl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dsl\" %f;\n", dsl);
	}
	void setMinPixelWidth(double mpw)
	{
		if(mpw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mpw\" %f;\n", mpw);
	}
	void setMaxPixelWidth(double mxp)
	{
		if(mxp == 1000.0) return;
		fprintf(mFile,"\tsetAttr \".mxp\" %f;\n", mxp);
	}
	void setStampDensity(double sdn)
	{
		if(sdn == 8.0) return;
		fprintf(mFile,"\tsetAttr \".sdn\" %f;\n", sdn);
	}
	void setSoftness(double sft)
	{
		if(sft == 0.2) return;
		fprintf(mFile,"\tsetAttr \".sft\" %f;\n", sft);
	}
	void setEdgeAntialias(bool eaa)
	{
		if(eaa == true) return;
		fprintf(mFile,"\tsetAttr \".eaa\" %i;\n", eaa);
	}
	void setEdgeClip(bool ecl)
	{
		if(ecl == false) return;
		fprintf(mFile,"\tsetAttr \".ecl\" %i;\n", ecl);
	}
	void setEdgeClipDepth(double ecd)
	{
		if(ecd == 0.1) return;
		fprintf(mFile,"\tsetAttr \".ecd\" %f;\n", ecd);
	}
	void setOcclusionWidthScale(bool ows)
	{
		if(ows == false) return;
		fprintf(mFile,"\tsetAttr \".ows\" %i;\n", ows);
	}
	void setBlurIntensity(int bin)
	{
		if(bin == 4) return;
		fprintf(mFile,"\tsetAttr \".bin\" %i;\n", bin);
	}
	void setColor1(const float3& cl1)
	{
		fprintf(mFile,"\tsetAttr \".cl1\" -type \"float3\" ");
		cl1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor1R(float c1r)
	{
		if(c1r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl1.c1r\" %f;\n", c1r);
	}
	void setColor1G(float c1g)
	{
		if(c1g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl1.c1g\" %f;\n", c1g);
	}
	void setColor1B(float c1b)
	{
		if(c1b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl1.c1b\" %f;\n", c1b);
	}
	void setColor2(const float3& cl2)
	{
		fprintf(mFile,"\tsetAttr \".cl2\" -type \"float3\" ");
		cl2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor2R(float c2r)
	{
		if(c2r == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cl2.c2r\" %f;\n", c2r);
	}
	void setColor2G(float c2g)
	{
		if(c2g == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cl2.c2g\" %f;\n", c2g);
	}
	void setColor2B(float c2b)
	{
		if(c2b == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cl2.c2b\" %f;\n", c2b);
	}
	void setTransparency1(const float3& tn1)
	{
		fprintf(mFile,"\tsetAttr \".tn1\" -type \"float3\" ");
		tn1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransparency1R(float t1r)
	{
		if(t1r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tn1.t1r\" %f;\n", t1r);
	}
	void setTransparency1G(float t1g)
	{
		if(t1g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tn1.t1g\" %f;\n", t1g);
	}
	void setTransparency1B(float t1b)
	{
		if(t1b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tn1.t1b\" %f;\n", t1b);
	}
	void setTransparency2(const float3& tn2)
	{
		fprintf(mFile,"\tsetAttr \".tn2\" -type \"float3\" ");
		tn2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransparency2R(float t2r)
	{
		if(t2r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tn2.t2r\" %f;\n", t2r);
	}
	void setTransparency2G(float t2g)
	{
		if(t2g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tn2.t2g\" %f;\n", t2g);
	}
	void setTransparency2B(float t2b)
	{
		if(t2b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tn2.t2b\" %f;\n", t2b);
	}
	void setIncandescence1(const float3& in1)
	{
		fprintf(mFile,"\tsetAttr \".in1\" -type \"float3\" ");
		in1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIncandescence1R(float i1r)
	{
		if(i1r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".in1.i1r\" %f;\n", i1r);
	}
	void setIncandescence1G(float i1g)
	{
		if(i1g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".in1.i1g\" %f;\n", i1g);
	}
	void setIncandescence1B(float i1b)
	{
		if(i1b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".in1.i1b\" %f;\n", i1b);
	}
	void setIncandescence2(const float3& in2)
	{
		fprintf(mFile,"\tsetAttr \".in2\" -type \"float3\" ");
		in2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIncandescence2R(float i2r)
	{
		if(i2r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".in2.i2r\" %f;\n", i2r);
	}
	void setIncandescence2G(float i2g)
	{
		if(i2g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".in2.i2g\" %f;\n", i2g);
	}
	void setIncandescence2B(float i2b)
	{
		if(i2b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".in2.i2b\" %f;\n", i2b);
	}
	void setSpecularColor(const float3& spc)
	{
		fprintf(mFile,"\tsetAttr \".spc\" -type \"float3\" ");
		spc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpecularColorR(float spr)
	{
		if(spr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".spc.spr\" %f;\n", spr);
	}
	void setSpecularColorG(float spg)
	{
		if(spg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".spc.spg\" %f;\n", spg);
	}
	void setSpecularColorB(float spb)
	{
		if(spb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".spc.spb\" %f;\n", spb);
	}
	void setSpecular(double spe)
	{
		if(spe == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spe\" %f;\n", spe);
	}
	void setSpecularPower(double spp)
	{
		if(spp == 10.0) return;
		fprintf(mFile,"\tsetAttr \".spp\" %f;\n", spp);
	}
	void setTranslucence(double trn)
	{
		if(trn == 0.2) return;
		fprintf(mFile,"\tsetAttr \".trn\" %f;\n", trn);
	}
	void setGlow(double glw)
	{
		if(glw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".glw\" %f;\n", glw);
	}
	void setGlowColor(const float3& glc)
	{
		fprintf(mFile,"\tsetAttr \".glc\" -type \"float3\" ");
		glc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGlowColorR(float glr)
	{
		if(glr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".glc.glr\" %f;\n", glr);
	}
	void setGlowColorG(float glg)
	{
		if(glg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".glc.glg\" %f;\n", glg);
	}
	void setGlowColorB(float glb)
	{
		if(glb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".glc.glb\" %f;\n", glb);
	}
	void setGlowSpread(double gls)
	{
		if(gls == 3.0) return;
		fprintf(mFile,"\tsetAttr \".gls\" %f;\n", gls);
	}
	void setShaderGlow(double sgl)
	{
		if(sgl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sgl\" %f;\n", sgl);
	}
	void setHueRand(double chr)
	{
		if(chr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".chr\" %f;\n", chr);
	}
	void setSatRand(double csr)
	{
		if(csr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".csr\" %f;\n", csr);
	}
	void setValRand(double cvr)
	{
		if(cvr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cvr\" %f;\n", cvr);
	}
	void setRootFade(double rfd)
	{
		if(rfd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rfd\" %f;\n", rfd);
	}
	void setTipFade(double tfd)
	{
		if(tfd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tfd\" %f;\n", tfd);
	}
	void setFakeShadow(unsigned int fks)
	{
		if(fks == 0) return;
		fprintf(mFile,"\tsetAttr \".fks\" %i;\n", fks);
	}
	void setShadowOffset(double sof)
	{
		if(sof == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sof\" %f;\n", sof);
	}
	void setShadowDiffusion(double sdf)
	{
		if(sdf == 0.1) return;
		fprintf(mFile,"\tsetAttr \".sdf\" %f;\n", sdf);
	}
	void setShadowTransparency(double stn)
	{
		if(stn == 0.8) return;
		fprintf(mFile,"\tsetAttr \".stn\" %f;\n", stn);
	}
	void setBackShadow(double bks)
	{
		if(bks == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bks\" %f;\n", bks);
	}
	void setBrightnessRand(double brn)
	{
		if(brn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".brn\" %f;\n", brn);
	}
	void setCenterShadow(double cns)
	{
		if(cns == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cns\" %f;\n", cns);
	}
	void setDepthShadowType(unsigned int dpt)
	{
		if(dpt == 0) return;
		fprintf(mFile,"\tsetAttr \".dpt\" %i;\n", dpt);
	}
	void setDepthShadow(double dpl)
	{
		if(dpl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dpl\" %f;\n", dpl);
	}
	void setDepthShadowDepth(double dps)
	{
		if(dps == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dps\" %f;\n", dps);
	}
	void setRealLights(bool rll)
	{
		if(rll == false) return;
		fprintf(mFile,"\tsetAttr \".rll\" %i;\n", rll);
	}
	void setLightDirection(const double3& ldr)
	{
		fprintf(mFile,"\tsetAttr \".ldr\" -type \"double3\" ");
		ldr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLightDirectionX(double ldx)
	{
		if(ldx == 0.5) return;
		fprintf(mFile,"\tsetAttr \".ldr.ldx\" %f;\n", ldx);
	}
	void setLightDirectionY(double ldy)
	{
		if(ldy == 0.5) return;
		fprintf(mFile,"\tsetAttr \".ldr.ldy\" %f;\n", ldy);
	}
	void setLightDirectionZ(double ldz)
	{
		if(ldz == -0.5) return;
		fprintf(mFile,"\tsetAttr \".ldr.ldz\" %f;\n", ldz);
	}
	void setGapSize(double gsz)
	{
		if(gsz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gsz\" %f;\n", gsz);
	}
	void setGapSpacing(double gsp)
	{
		if(gsp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gsp\" %f;\n", gsp);
	}
	void setGapRand(double grn)
	{
		if(grn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".grn\" %f;\n", grn);
	}
	void setFlowSpeed(double fws)
	{
		if(fws == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fws\" %f;\n", fws);
	}
	void setTextureFlow(bool tfl)
	{
		if(tfl == true) return;
		fprintf(mFile,"\tsetAttr \".tfl\" %i;\n", tfl);
	}
	void setTimeClip(bool tcl)
	{
		if(tcl == false) return;
		fprintf(mFile,"\tsetAttr \".tcl\" %i;\n", tcl);
	}
	void setStrokeTime(bool srm)
	{
		if(srm == false) return;
		fprintf(mFile,"\tsetAttr \".srm\" %i;\n", srm);
	}
	void setStartTime(double sti)
	{
		if(sti == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sti\" %f;\n", sti);
	}
	void setEndTime(double eti)
	{
		if(eti == 1000.0) return;
		fprintf(mFile,"\tsetAttr \".eti\" %f;\n", eti);
	}
	void setTubes(bool tub)
	{
		if(tub == false) return;
		fprintf(mFile,"\tsetAttr \".tub\" %i;\n", tub);
	}
	void setCreationScript(const string& csc)
	{
		if(csc == "NULL") return;
		fprintf(mFile,"\tsetAttr \".csc\" -type \"string\" ");
		csc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRuntimeScript(const string& rsc)
	{
		if(rsc == "NULL") return;
		fprintf(mFile,"\tsetAttr \".rsc\" -type \"string\" ");
		rsc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTubeCompletion(bool tcm)
	{
		if(tcm == true) return;
		fprintf(mFile,"\tsetAttr \".tcm\" %i;\n", tcm);
	}
	void setTubesPerStep(double tps)
	{
		if(tps == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tps\" %f;\n", tps);
	}
	void setTubeRand(double trd)
	{
		if(trd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".trd\" %f;\n", trd);
	}
	void setStartTubes(int stb)
	{
		if(stb == 0) return;
		fprintf(mFile,"\tsetAttr \".stb\" %i;\n", stb);
	}
	void setLengthMax(double lnx)
	{
		if(lnx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lnx\" %f;\n", lnx);
	}
	void setLengthMin(double lnn)
	{
		if(lnn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lnn\" %f;\n", lnn);
	}
	void setSegments(int sgm)
	{
		if(sgm == 10) return;
		fprintf(mFile,"\tsetAttr \".sgm\" %i;\n", sgm);
	}
	void setTubeWidth1(double tw1)
	{
		if(tw1 == 0.01) return;
		fprintf(mFile,"\tsetAttr \".tw1\" %f;\n", tw1);
	}
	void setTubeWidth2(double tw2)
	{
		if(tw2 == 0.01) return;
		fprintf(mFile,"\tsetAttr \".tw2\" %f;\n", tw2);
	}
	void setWidthRand(double wdr)
	{
		if(wdr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wdr\" %f;\n", wdr);
	}
	void setWidthBias(double wdb)
	{
		if(wdb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wdb\" %f;\n", wdb);
	}
	void setLengthFlex(double lfx)
	{
		if(lfx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lfx\" %f;\n", lfx);
	}
	void setSegmentLengthBias(double sgb)
	{
		if(sgb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sgb\" %f;\n", sgb);
	}
	void setSegmentWidthBias(double swb)
	{
		if(swb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".swb\" %f;\n", swb);
	}
	void setTubeDirection(unsigned int tdr)
	{
		if(tdr == 0) return;
		fprintf(mFile,"\tsetAttr \".tdr\" %i;\n", tdr);
	}
	void setElevationMin(double elm)
	{
		if(elm == 0.2) return;
		fprintf(mFile,"\tsetAttr \".elm\" %f;\n", elm);
	}
	void setElevationMax(double elx)
	{
		if(elx == 0.5) return;
		fprintf(mFile,"\tsetAttr \".elx\" %f;\n", elx);
	}
	void setAzimuthMin(double azn)
	{
		if(azn == -0.1) return;
		fprintf(mFile,"\tsetAttr \".azn\" %f;\n", azn);
	}
	void setAzimuthMax(double azx)
	{
		if(azx == 0.1) return;
		fprintf(mFile,"\tsetAttr \".azx\" %f;\n", azx);
	}
	void setFlatness1(double fl1)
	{
		if(fl1 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fl1\" %f;\n", fl1);
	}
	void setFlatness2(double fl2)
	{
		if(fl2 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fl2\" %f;\n", fl2);
	}
	void setTwist(double twi)
	{
		if(twi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".twi\" %f;\n", twi);
	}
	void setTwistRate(double twr)
	{
		if(twr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".twr\" %f;\n", twr);
	}
	void setTwistRand(double twd)
	{
		if(twd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".twd\" %f;\n", twd);
	}
	void setSpiralMin(double spm)
	{
		if(spm == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spm\" %f;\n", spm);
	}
	void setSpiralMax(double spx)
	{
		if(spx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spx\" %f;\n", spx);
	}
	void setSpiralDecay(double spd)
	{
		if(spd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spd\" %f;\n", spd);
	}
	void setBend(double ben)
	{
		if(ben == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ben\" %f;\n", ben);
	}
	void setBendBias(double bnb)
	{
		if(bnb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bnb\" %f;\n", bnb);
	}
	void setDisplacementDelay(double ddl)
	{
		if(ddl == 0.2) return;
		fprintf(mFile,"\tsetAttr \".ddl\" %f;\n", ddl);
	}
	void setWiggle(double wgl)
	{
		if(wgl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wgl\" %f;\n", wgl);
	}
	void setWiggleFrequency(double wgf)
	{
		if(wgf == 3) return;
		fprintf(mFile,"\tsetAttr \".wgf\" %f;\n", wgf);
	}
	void setWiggleOffset(double wgo)
	{
		if(wgo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wgo\" %f;\n", wgo);
	}
	void setCurl(double crl)
	{
		if(crl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crl\" %f;\n", crl);
	}
	void setCurlFrequency(double crf)
	{
		if(crf == 1) return;
		fprintf(mFile,"\tsetAttr \".crf\" %f;\n", crf);
	}
	void setCurlOffset(double cro)
	{
		if(cro == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cro\" %f;\n", cro);
	}
	void setNoise(double noi)
	{
		if(noi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".noi\" %f;\n", noi);
	}
	void setNoiseFrequency(double nof)
	{
		if(nof == 0.2) return;
		fprintf(mFile,"\tsetAttr \".nof\" %f;\n", nof);
	}
	void setNoiseOffset(double noo)
	{
		if(noo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".noo\" %f;\n", noo);
	}
	void setSplitMaxDepth(double smd)
	{
		if(smd == 2.0) return;
		fprintf(mFile,"\tsetAttr \".smd\" %f;\n", smd);
	}
	void setSplitRand(double srd)
	{
		if(srd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".srd\" %f;\n", srd);
	}
	void setSplitAngle(double spa)
	{
		if(spa == 30.0) return;
		fprintf(mFile,"\tsetAttr \".spa\" %f;\n", spa);
	}
	void setSplitSizeDecay(double ssd)
	{
		if(ssd == 0.7) return;
		fprintf(mFile,"\tsetAttr \".ssd\" %f;\n", ssd);
	}
	void setSplitBias(double slb)
	{
		if(slb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".slb\" %f;\n", slb);
	}
	void setSplitTwist(double slt)
	{
		if(slt == 0.5) return;
		fprintf(mFile,"\tsetAttr \".slt\" %f;\n", slt);
	}
	void setStartBranches(double sbr)
	{
		if(sbr == 0) return;
		fprintf(mFile,"\tsetAttr \".sbr\" %f;\n", sbr);
	}
	void setNumBranches(int nbr)
	{
		if(nbr == 2) return;
		fprintf(mFile,"\tsetAttr \".nbr\" %i;\n", nbr);
	}
	void setBranchDropout(double bdr)
	{
		if(bdr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bdr\" %f;\n", bdr);
	}
	void setMiddleBranch(bool mbr)
	{
		if(mbr == false) return;
		fprintf(mFile,"\tsetAttr \".mbr\" %i;\n", mbr);
	}
	void setMinSize(double mms)
	{
		if(mms == 0.0001) return;
		fprintf(mFile,"\tsetAttr \".mms\" %f;\n", mms);
	}
	void setPathFollow(double pfl)
	{
		if(pfl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pfl\" %f;\n", pfl);
	}
	void setPathAttract(double pat)
	{
		if(pat == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pat\" %f;\n", pat);
	}
	void setCurveFollow(double cfw)
	{
		if(cfw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cfw\" %f;\n", cfw);
	}
	void setCurveAttract(double cva)
	{
		if(cva == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cva\" %f;\n", cva);
	}
	void setCurveMaxDist(double cmd)
	{
		if(cmd == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cmd\" %f;\n", cmd);
	}
	void setUniformForce(const double3& ufr)
	{
		fprintf(mFile,"\tsetAttr \".ufr\" -type \"double3\" ");
		ufr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUniformForceX(double ufx)
	{
		if(ufx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ufr.ufx\" %f;\n", ufx);
	}
	void setUniformForceY(double ufy)
	{
		if(ufy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ufr.ufy\" %f;\n", ufy);
	}
	void setUniformForceZ(double ufz)
	{
		if(ufz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ufr.ufz\" %f;\n", ufz);
	}
	void setTurbulenceType(unsigned int trt)
	{
		if(trt == 0) return;
		fprintf(mFile,"\tsetAttr \".trt\" %i;\n", trt);
	}
	void setTurbulenceInterpolation(unsigned int tin)
	{
		if(tin == 0) return;
		fprintf(mFile,"\tsetAttr \".tin\" %i;\n", tin);
	}
	void setTurbulence(double tur)
	{
		if(tur == 0.2) return;
		fprintf(mFile,"\tsetAttr \".tur\" %f;\n", tur);
	}
	void setTurbulenceFrequency(double trf)
	{
		if(trf == 0.2) return;
		fprintf(mFile,"\tsetAttr \".trf\" %f;\n", trf);
	}
	void setTurbulenceSpeed(double trs)
	{
		if(trs == 0.5) return;
		fprintf(mFile,"\tsetAttr \".trs\" %f;\n", trs);
	}
	void setTurbulenceOffset(const double3& tro)
	{
		fprintf(mFile,"\tsetAttr \".tro\" -type \"double3\" ");
		tro.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTurbulenceOffsetX(double trx)
	{
		if(trx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tro.trx\" %f;\n", trx);
	}
	void setTurbulenceOffsetY(double try_)
	{
		if(try_ == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tro.try\" %f;\n", try_);
	}
	void setTurbulenceOffsetZ(double trz)
	{
		if(trz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tro.trz\" %f;\n", trz);
	}
	void setRandom(double ran)
	{
		if(ran == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ran\" %f;\n", ran);
	}
	void setGravity(double grv)
	{
		if(grv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".grv\" %f;\n", grv);
	}
	void setMomentum(double mmt)
	{
		if(mmt == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mmt\" %f;\n", mmt);
	}
	void setDeflection(bool def)
	{
		if(def == false) return;
		fprintf(mFile,"\tsetAttr \".def\" %i;\n", def);
	}
	void setDeflectionMin(double dfm)
	{
		if(dfm == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dfm\" %f;\n", dfm);
	}
	void setDeflectionMax(double dfx)
	{
		if(dfx == 0.3) return;
		fprintf(mFile,"\tsetAttr \".dfx\" %f;\n", dfx);
	}
	void setTwigsInCluster(int tic)
	{
		if(tic == 1) return;
		fprintf(mFile,"\tsetAttr \".tic\" %i;\n", tic);
	}
	void setTwigDropout(double tdp)
	{
		if(tdp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tdp\" %f;\n", tdp);
	}
	void setTwigAngle1(double ta1)
	{
		if(ta1 == 90.0) return;
		fprintf(mFile,"\tsetAttr \".ta1\" %f;\n", ta1);
	}
	void setTwigAngle2(double ta2)
	{
		if(ta2 == 80.0) return;
		fprintf(mFile,"\tsetAttr \".ta2\" %f;\n", ta2);
	}
	void setTwigTwist(double ttw)
	{
		if(ttw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ttw\" %f;\n", ttw);
	}
	void setTwigLength(double twl)
	{
		if(twl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".twl\" %f;\n", twl);
	}
	void setTwigStart(double tst)
	{
		if(tst == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tst\" %f;\n", tst);
	}
	void setNumTwigClusters(double ntc)
	{
		if(ntc == 4) return;
		fprintf(mFile,"\tsetAttr \".ntc\" %f;\n", ntc);
	}
	void setTwigBaseWidth(double twb)
	{
		if(twb == 0.4) return;
		fprintf(mFile,"\tsetAttr \".twb\" %f;\n", twb);
	}
	void setTwigTipWidth(double twt)
	{
		if(twt == 0.2) return;
		fprintf(mFile,"\tsetAttr \".twt\" %f;\n", twt);
	}
	void setTwigStiffness(double tgs)
	{
		if(tgs == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tgs\" %f;\n", tgs);
	}
	void setBranchAfterTwigs(bool bat)
	{
		if(bat == false) return;
		fprintf(mFile,"\tsetAttr \".bat\" %i;\n", bat);
	}
	void setLeavesInCluster(int lic)
	{
		if(lic == 1) return;
		fprintf(mFile,"\tsetAttr \".lic\" %i;\n", lic);
	}
	void setLeafLocation(unsigned int llo)
	{
		if(llo == 0) return;
		fprintf(mFile,"\tsetAttr \".llo\" %i;\n", llo);
	}
	void setLeafDropout(double ldp)
	{
		if(ldp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ldp\" %f;\n", ldp);
	}
	void setLeafAngle1(double ll1)
	{
		if(ll1 == 75.0) return;
		fprintf(mFile,"\tsetAttr \".ll1\" %f;\n", ll1);
	}
	void setLeafAngle2(double ll2)
	{
		if(ll2 == 25.0) return;
		fprintf(mFile,"\tsetAttr \".ll2\" %f;\n", ll2);
	}
	void setLeafTwist(double ltw)
	{
		if(ltw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ltw\" %f;\n", ltw);
	}
	void setLeafBend(double lbn)
	{
		if(lbn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lbn\" %f;\n", lbn);
	}
	void setLeafCurl(size_t lcl_i,const LeafCurl& lcl)
	{
		fprintf(mFile,"\tsetAttr \".lcl[%i]\" ",lcl_i);
		lcl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeafCurl(size_t lcl_start,size_t lcl_end,LeafCurl* lcl)
	{
		fprintf(mFile,"\tsetAttr \".lcl[%i:%i]\" ", lcl_start,lcl_end);
		size_t size = (lcl_end-lcl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			lcl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startLeafCurl(size_t lcl_start,size_t lcl_end)const
	{
		fprintf(mFile,"\tsetAttr \".lcl[%i:%i]\"",lcl_start,lcl_end);
		fprintf(mFile," -type \"LeafCurl\" ");
	}
	void appendLeafCurl(const LeafCurl& lcl)const
	{
		fprintf(mFile," ");
		lcl.write(mFile);
	}
	void endLeafCurl()const
	{
		fprintf(mFile,";\n");
	}
	void setLeafCurl_Position(size_t lcl_i,float lclp)
	{
		if(lclp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lcl[%i].lclp\" %f;\n", lcl_i,lclp);
	}
	void setLeafCurl_FloatValue(size_t lcl_i,float lclfv)
	{
		if(lclfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lcl[%i].lclfv\" %f;\n", lcl_i,lclfv);
	}
	void setLeafCurl_Interp(size_t lcl_i,unsigned int lcli)
	{
		if(lcli == 0) return;
		fprintf(mFile,"\tsetAttr \".lcl[%i].lcli\" %i;\n", lcl_i,lcli);
	}
	void setLeafTwirl(double ltwl)
	{
		if(ltwl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ltwl\" %f;\n", ltwl);
	}
	void setLeafSegments(int lsg)
	{
		if(lsg == 5) return;
		fprintf(mFile,"\tsetAttr \".lsg\" %i;\n", lsg);
	}
	void setLeafStart(double lst)
	{
		if(lst == .5) return;
		fprintf(mFile,"\tsetAttr \".lst\" %f;\n", lst);
	}
	void setNumLeafClusters(double nlc)
	{
		if(nlc == 3) return;
		fprintf(mFile,"\tsetAttr \".nlc\" %f;\n", nlc);
	}
	void setLeafFlatness(double lft)
	{
		if(lft == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lft\" %f;\n", lft);
	}
	void setLeafLength(double lln)
	{
		if(lln == 0.3) return;
		fprintf(mFile,"\tsetAttr \".lln\" %f;\n", lln);
	}
	void setLeafBaseWidth(double leb)
	{
		if(leb == 0.15) return;
		fprintf(mFile,"\tsetAttr \".leb\" %f;\n", leb);
	}
	void setLeafTipWidth(double let)
	{
		if(let == 0.05) return;
		fprintf(mFile,"\tsetAttr \".let\" %f;\n", let);
	}
	void setLeafSizeDecay(double lsd)
	{
		if(lsd == 0.7) return;
		fprintf(mFile,"\tsetAttr \".lsd\" %f;\n", lsd);
	}
	void setLeafTranslucence(double ltr)
	{
		if(ltr == 0.7) return;
		fprintf(mFile,"\tsetAttr \".ltr\" %f;\n", ltr);
	}
	void setLeafSpecular(double lsp)
	{
		if(lsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lsp\" %f;\n", lsp);
	}
	void setTerminalLeaf(bool tml)
	{
		if(tml == false) return;
		fprintf(mFile,"\tsetAttr \".tml\" %i;\n", tml);
	}
	void setLeafColor1(const float3& lc1)
	{
		fprintf(mFile,"\tsetAttr \".lc1\" -type \"float3\" ");
		lc1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeafColor1R(float lr1)
	{
		if(lr1 == 0.2) return;
		fprintf(mFile,"\tsetAttr \".lc1.lr1\" %f;\n", lr1);
	}
	void setLeafColor1G(float lg1)
	{
		if(lg1 == 0.6) return;
		fprintf(mFile,"\tsetAttr \".lc1.lg1\" %f;\n", lg1);
	}
	void setLeafColor1B(float lb1)
	{
		if(lb1 == 0.3) return;
		fprintf(mFile,"\tsetAttr \".lc1.lb1\" %f;\n", lb1);
	}
	void setLeafColor2(const float3& lc2)
	{
		fprintf(mFile,"\tsetAttr \".lc2\" -type \"float3\" ");
		lc2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeafColor2R(float lr2)
	{
		if(lr2 == 0.4) return;
		fprintf(mFile,"\tsetAttr \".lc2.lr2\" %f;\n", lr2);
	}
	void setLeafColor2G(float lg2)
	{
		if(lg2 == 0.6) return;
		fprintf(mFile,"\tsetAttr \".lc2.lg2\" %f;\n", lg2);
	}
	void setLeafColor2B(float lb2)
	{
		if(lb2 == 0.3) return;
		fprintf(mFile,"\tsetAttr \".lc2.lb2\" %f;\n", lb2);
	}
	void setLeafHueRand(double lhr)
	{
		if(lhr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lhr\" %f;\n", lhr);
	}
	void setLeafSatRand(double lsr)
	{
		if(lsr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lsr\" %f;\n", lsr);
	}
	void setLeafValRand(double lvr)
	{
		if(lvr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lvr\" %f;\n", lvr);
	}
	void setLeafUseBranchTex(bool lub)
	{
		if(lub == true) return;
		fprintf(mFile,"\tsetAttr \".lub\" %i;\n", lub);
	}
	void setLeafImage(const string& lim)
	{
		if(lim == "NULL") return;
		fprintf(mFile,"\tsetAttr \".lim\" -type \"string\" ");
		lim.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeafStiffness(double lfs)
	{
		if(lfs == 0.5) return;
		fprintf(mFile,"\tsetAttr \".lfs\" %f;\n", lfs);
	}
	void setBudSize(double bds)
	{
		if(bds == 0.03) return;
		fprintf(mFile,"\tsetAttr \".bds\" %f;\n", bds);
	}
	void setBudColor(const float3& bcr)
	{
		fprintf(mFile,"\tsetAttr \".bcr\" -type \"float3\" ");
		bcr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBudColorR(float bur)
	{
		if(bur == 0.4) return;
		fprintf(mFile,"\tsetAttr \".bcr.bur\" %f;\n", bur);
	}
	void setBudColorG(float bug)
	{
		if(bug == 0.8) return;
		fprintf(mFile,"\tsetAttr \".bcr.bug\" %f;\n", bug);
	}
	void setBudColorB(float bub)
	{
		if(bub == 0.2) return;
		fprintf(mFile,"\tsetAttr \".bcr.bub\" %f;\n", bub);
	}
	void setPetalsInFlower(int pif)
	{
		if(pif == 1) return;
		fprintf(mFile,"\tsetAttr \".pif\" %i;\n", pif);
	}
	void setFlowerLocation(unsigned int flc)
	{
		if(flc == 0) return;
		fprintf(mFile,"\tsetAttr \".flc\" %i;\n", flc);
	}
	void setPetalDropout(double pdp)
	{
		if(pdp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pdp\" %f;\n", pdp);
	}
	void setFlowerAngle1(double fw1)
	{
		if(fw1 == 75.0) return;
		fprintf(mFile,"\tsetAttr \".fw1\" %f;\n", fw1);
	}
	void setFlowerAngle2(double fw2)
	{
		if(fw2 == 25.0) return;
		fprintf(mFile,"\tsetAttr \".fw2\" %f;\n", fw2);
	}
	void setFlowerTwist(double ftw)
	{
		if(ftw == 0.23) return;
		fprintf(mFile,"\tsetAttr \".ftw\" %f;\n", ftw);
	}
	void setPetalBend(double pbn)
	{
		if(pbn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pbn\" %f;\n", pbn);
	}
	void setPetalCurl(size_t pcl_i,const PetalCurl& pcl)
	{
		fprintf(mFile,"\tsetAttr \".pcl[%i]\" ",pcl_i);
		pcl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPetalCurl(size_t pcl_start,size_t pcl_end,PetalCurl* pcl)
	{
		fprintf(mFile,"\tsetAttr \".pcl[%i:%i]\" ", pcl_start,pcl_end);
		size_t size = (pcl_end-pcl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			pcl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startPetalCurl(size_t pcl_start,size_t pcl_end)const
	{
		fprintf(mFile,"\tsetAttr \".pcl[%i:%i]\"",pcl_start,pcl_end);
		fprintf(mFile," -type \"PetalCurl\" ");
	}
	void appendPetalCurl(const PetalCurl& pcl)const
	{
		fprintf(mFile," ");
		pcl.write(mFile);
	}
	void endPetalCurl()const
	{
		fprintf(mFile,";\n");
	}
	void setPetalCurl_Position(size_t pcl_i,float pclp)
	{
		if(pclp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pcl[%i].pclp\" %f;\n", pcl_i,pclp);
	}
	void setPetalCurl_FloatValue(size_t pcl_i,float pclfv)
	{
		if(pclfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pcl[%i].pclfv\" %f;\n", pcl_i,pclfv);
	}
	void setPetalCurl_Interp(size_t pcl_i,unsigned int pcli)
	{
		if(pcli == 0) return;
		fprintf(mFile,"\tsetAttr \".pcl[%i].pcli\" %i;\n", pcl_i,pcli);
	}
	void setPetalTwirl(double lpwl)
	{
		if(lpwl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lpwl\" %f;\n", lpwl);
	}
	void setPetalSegments(int psg)
	{
		if(psg == 5) return;
		fprintf(mFile,"\tsetAttr \".psg\" %i;\n", psg);
	}
	void setFlowerStart(double fst)
	{
		if(fst == 1) return;
		fprintf(mFile,"\tsetAttr \".fst\" %f;\n", fst);
	}
	void setNumFlowers(double nfl)
	{
		if(nfl == 10) return;
		fprintf(mFile,"\tsetAttr \".nfl\" %f;\n", nfl);
	}
	void setPetalFlatness(double pft)
	{
		if(pft == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pft\" %f;\n", pft);
	}
	void setPetalLength(double pln)
	{
		if(pln == 0.2) return;
		fprintf(mFile,"\tsetAttr \".pln\" %f;\n", pln);
	}
	void setPetalBaseWidth(double ptb)
	{
		if(ptb == 0.05) return;
		fprintf(mFile,"\tsetAttr \".ptb\" %f;\n", ptb);
	}
	void setPetalTipWidth(double ptt)
	{
		if(ptt == 0.1) return;
		fprintf(mFile,"\tsetAttr \".ptt\" %f;\n", ptt);
	}
	void setFlowerSizeDecay(double fsd)
	{
		if(fsd == 0.7) return;
		fprintf(mFile,"\tsetAttr \".fsd\" %f;\n", fsd);
	}
	void setFlowerTranslucence(double ftr)
	{
		if(ftr == 0.7) return;
		fprintf(mFile,"\tsetAttr \".ftr\" %f;\n", ftr);
	}
	void setFlowerSpecular(double fsp)
	{
		if(fsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fsp\" %f;\n", fsp);
	}
	void setPetalColor1(const float3& pc1)
	{
		fprintf(mFile,"\tsetAttr \".pc1\" -type \"float3\" ");
		pc1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPetalColor1R(float pr1)
	{
		if(pr1 == 0.8) return;
		fprintf(mFile,"\tsetAttr \".pc1.pr1\" %f;\n", pr1);
	}
	void setPetalColor1G(float pg1)
	{
		if(pg1 == 0.2) return;
		fprintf(mFile,"\tsetAttr \".pc1.pg1\" %f;\n", pg1);
	}
	void setPetalColor1B(float pb1)
	{
		if(pb1 == 0.1) return;
		fprintf(mFile,"\tsetAttr \".pc1.pb1\" %f;\n", pb1);
	}
	void setPetalColor2(const float3& pc2)
	{
		fprintf(mFile,"\tsetAttr \".pc2\" -type \"float3\" ");
		pc2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPetalColor2R(float pr2)
	{
		if(pr2 == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pc2.pr2\" %f;\n", pr2);
	}
	void setPetalColor2G(float pg2)
	{
		if(pg2 == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pc2.pg2\" %f;\n", pg2);
	}
	void setPetalColor2B(float pb2)
	{
		if(pb2 == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pc2.pb2\" %f;\n", pb2);
	}
	void setFlowerHueRand(double fhr)
	{
		if(fhr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fhr\" %f;\n", fhr);
	}
	void setFlowerSatRand(double fsr)
	{
		if(fsr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fsr\" %f;\n", fsr);
	}
	void setFlowerValRand(double fvr)
	{
		if(fvr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fvr\" %f;\n", fvr);
	}
	void setFlowerUseBranchTex(bool fub)
	{
		if(fub == true) return;
		fprintf(mFile,"\tsetAttr \".fub\" %i;\n", fub);
	}
	void setFlowerImage(const string& fim)
	{
		if(fim == "NULL") return;
		fprintf(mFile,"\tsetAttr \".fim\" -type \"string\" ");
		fim.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFlowerStiffness(double fls)
	{
		if(fls == 0.5) return;
		fprintf(mFile,"\tsetAttr \".fls\" %f;\n", fls);
	}
	void setSimplifyMethod(unsigned int smp)
	{
		if(smp == 0) return;
		fprintf(mFile,"\tsetAttr \".smp\" %i;\n", smp);
	}
	void setColorLengthMap(unsigned int clm)
	{
		if(clm == 0) return;
		fprintf(mFile,"\tsetAttr \".clm\" %i;\n", clm);
	}
	void setTranspLengthMap(unsigned int tlm)
	{
		if(tlm == 0) return;
		fprintf(mFile,"\tsetAttr \".tlm\" %i;\n", tlm);
	}
	void setIncandLengthMap(unsigned int ilm)
	{
		if(ilm == 0) return;
		fprintf(mFile,"\tsetAttr \".ilm\" %i;\n", ilm);
	}
	void setWidthLengthMap(unsigned int wlm)
	{
		if(wlm == 0) return;
		fprintf(mFile,"\tsetAttr \".wlm\" %i;\n", wlm);
	}
	void setSplitLengthMap(unsigned int spl)
	{
		if(spl == 0) return;
		fprintf(mFile,"\tsetAttr \".spl\" %i;\n", spl);
	}
	void setMapColor(bool mcl)
	{
		if(mcl == false) return;
		fprintf(mFile,"\tsetAttr \".mcl\" %i;\n", mcl);
	}
	void setMapOpacity(bool mop)
	{
		if(mop == false) return;
		fprintf(mFile,"\tsetAttr \".mop\" %i;\n", mop);
	}
	void setMapDisplacement(bool mds)
	{
		if(mds == false) return;
		fprintf(mFile,"\tsetAttr \".mds\" %i;\n", mds);
	}
	void setTextureType(unsigned int txt)
	{
		if(txt == 0) return;
		fprintf(mFile,"\tsetAttr \".txt\" %i;\n", txt);
	}
	void setMapMethod(unsigned int mmd)
	{
		if(mmd == 0) return;
		fprintf(mFile,"\tsetAttr \".mmd\" %i;\n", mmd);
	}
	void setTexColorScale(double tcs)
	{
		if(tcs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tcs\" %f;\n", tcs);
	}
	void setTexColorOffset(double tco)
	{
		if(tco == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tco\" %f;\n", tco);
	}
	void setTexOpacityScale(double tos)
	{
		if(tos == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tos\" %f;\n", tos);
	}
	void setTexOpacityOffset(double too)
	{
		if(too == 0.0) return;
		fprintf(mFile,"\tsetAttr \".too\" %f;\n", too);
	}
	void setDisplacementScale(double dsc)
	{
		if(dsc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dsc\" %f;\n", dsc);
	}
	void setDisplacementOffset(double dof)
	{
		if(dof == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dof\" %f;\n", dof);
	}
	void setBumpIntensity(double bmi)
	{
		if(bmi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bmi\" %f;\n", bmi);
	}
	void setBumpBlur(double bbl)
	{
		if(bbl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".bbl\" %f;\n", bbl);
	}
	void setLuminanceIsDisplacement(bool lid)
	{
		if(lid == true) return;
		fprintf(mFile,"\tsetAttr \".lid\" %i;\n", lid);
	}
	void setTexColor1(const float3& tc1)
	{
		fprintf(mFile,"\tsetAttr \".tc1\" -type \"float3\" ");
		tc1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTexColor1R(float x1r)
	{
		if(x1r == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tc1.x1r\" %f;\n", x1r);
	}
	void setTexColor1G(float x1g)
	{
		if(x1g == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tc1.x1g\" %f;\n", x1g);
	}
	void setTexColor1B(float x1b)
	{
		if(x1b == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tc1.x1b\" %f;\n", x1b);
	}
	void setTexColor2(const float3& tc2)
	{
		fprintf(mFile,"\tsetAttr \".tc2\" -type \"float3\" ");
		tc2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTexColor2R(float x2r)
	{
		if(x2r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tc2.x2r\" %f;\n", x2r);
	}
	void setTexColor2G(float x2g)
	{
		if(x2g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tc2.x2g\" %f;\n", x2g);
	}
	void setTexColor2B(float x2b)
	{
		if(x2b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tc2.x2b\" %f;\n", x2b);
	}
	void setTexAlpha1(double al1)
	{
		if(al1 == 1.0) return;
		fprintf(mFile,"\tsetAttr \".al1\" %f;\n", al1);
	}
	void setTexAlpha2(double al2)
	{
		if(al2 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".al2\" %f;\n", al2);
	}
	void setTexUniformity(double txu)
	{
		if(txu == 0.5) return;
		fprintf(mFile,"\tsetAttr \".txu\" %f;\n", txu);
	}
	void setFringeRemoval(bool frm)
	{
		if(frm == true) return;
		fprintf(mFile,"\tsetAttr \".frm\" %i;\n", frm);
	}
	void setRepeatU(double rpu)
	{
		if(rpu == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rpu\" %f;\n", rpu);
	}
	void setRepeatV(double rpv)
	{
		if(rpv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rpv\" %f;\n", rpv);
	}
	void setOffsetU(double ofu)
	{
		if(ofu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ofu\" %f;\n", ofu);
	}
	void setOffsetV(double ofv)
	{
		if(ofv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ofv\" %f;\n", ofv);
	}
	void setBlurMult(double bmt)
	{
		if(bmt == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bmt\" %f;\n", bmt);
	}
	void setSmear(double smr)
	{
		if(smr == 0.1) return;
		fprintf(mFile,"\tsetAttr \".smr\" %f;\n", smr);
	}
	void setSmearU(double sru)
	{
		if(sru == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sru\" %f;\n", sru);
	}
	void setSmearV(double srv)
	{
		if(srv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".srv\" %f;\n", srv);
	}
	void setImageName(const string& imn)
	{
		if(imn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".imn\" -type \"string\" ");
		imn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUseFrameExtension(bool ufe)
	{
		if(ufe == false) return;
		fprintf(mFile,"\tsetAttr \".ufe\" %i;\n", ufe);
	}
	void setFrameExtension(int fe)
	{
		if(fe == 1) return;
		fprintf(mFile,"\tsetAttr \".fe\" %i;\n", fe);
	}
	void setFractalRatio(double fra)
	{
		if(fra == 0.7) return;
		fprintf(mFile,"\tsetAttr \".fra\" %f;\n", fra);
	}
	void setFractalAmplitude(double fam)
	{
		if(fam == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fam\" %f;\n", fam);
	}
	void setFractalThreshold(double fth)
	{
		if(fth == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fth\" %f;\n", fth);
	}
	void setMultiStreaks(int mst)
	{
		if(mst == 0) return;
		fprintf(mFile,"\tsetAttr \".mst\" %i;\n", mst);
	}
	void setMultiStreakSpread1(double ms1)
	{
		if(ms1 == 0.2) return;
		fprintf(mFile,"\tsetAttr \".ms1\" %f;\n", ms1);
	}
	void setMultiStreakSpread2(double ms2)
	{
		if(ms2 == 0.2) return;
		fprintf(mFile,"\tsetAttr \".ms2\" %f;\n", ms2);
	}
	void setMultiStreakDiffuseRand(double msdr)
	{
		if(msdr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".msdr\" %f;\n", msdr);
	}
	void setMultiStreakSpecularRand(double mssr)
	{
		if(mssr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mssr\" %f;\n", mssr);
	}
	void setMultiStreakLightAll(bool msla)
	{
		if(msla == false) return;
		fprintf(mFile,"\tsetAttr \".msla\" %i;\n", msla);
	}
	void setSingleSided(bool snsd)
	{
		if(snsd == false) return;
		fprintf(mFile,"\tsetAttr \".snsd\" %i;\n", snsd);
	}
	void setTubeSections(int tbs)
	{
		if(tbs == 6) return;
		fprintf(mFile,"\tsetAttr \".tbs\" %i;\n", tbs);
	}
	void setSubSegments(int ssg)
	{
		if(ssg == 1) return;
		fprintf(mFile,"\tsetAttr \".ssg\" %i;\n", ssg);
	}
	void setPerPixelLighting(bool ppl)
	{
		if(ppl == false) return;
		fprintf(mFile,"\tsetAttr \".ppl\" %i;\n", ppl);
	}
	void setWidthScale(size_t wsc_i,const WidthScale& wsc)
	{
		fprintf(mFile,"\tsetAttr \".wsc[%i]\" ",wsc_i);
		wsc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWidthScale(size_t wsc_start,size_t wsc_end,WidthScale* wsc)
	{
		fprintf(mFile,"\tsetAttr \".wsc[%i:%i]\" ", wsc_start,wsc_end);
		size_t size = (wsc_end-wsc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			wsc[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWidthScale(size_t wsc_start,size_t wsc_end)const
	{
		fprintf(mFile,"\tsetAttr \".wsc[%i:%i]\"",wsc_start,wsc_end);
		fprintf(mFile," -type \"WidthScale\" ");
	}
	void appendWidthScale(const WidthScale& wsc)const
	{
		fprintf(mFile," ");
		wsc.write(mFile);
	}
	void endWidthScale()const
	{
		fprintf(mFile,";\n");
	}
	void setWidthScale_Position(size_t wsc_i,float wscp)
	{
		if(wscp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wsc[%i].wscp\" %f;\n", wsc_i,wscp);
	}
	void setWidthScale_FloatValue(size_t wsc_i,float wscfv)
	{
		if(wscfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wsc[%i].wscfv\" %f;\n", wsc_i,wscfv);
	}
	void setWidthScale_Interp(size_t wsc_i,unsigned int wsci)
	{
		if(wsci == 0) return;
		fprintf(mFile,"\tsetAttr \".wsc[%i].wsci\" %i;\n", wsc_i,wsci);
	}
	void setLeafWidthScale(size_t lws_i,const LeafWidthScale& lws)
	{
		fprintf(mFile,"\tsetAttr \".lws[%i]\" ",lws_i);
		lws.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLeafWidthScale(size_t lws_start,size_t lws_end,LeafWidthScale* lws)
	{
		fprintf(mFile,"\tsetAttr \".lws[%i:%i]\" ", lws_start,lws_end);
		size_t size = (lws_end-lws_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			lws[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startLeafWidthScale(size_t lws_start,size_t lws_end)const
	{
		fprintf(mFile,"\tsetAttr \".lws[%i:%i]\"",lws_start,lws_end);
		fprintf(mFile," -type \"LeafWidthScale\" ");
	}
	void appendLeafWidthScale(const LeafWidthScale& lws)const
	{
		fprintf(mFile," ");
		lws.write(mFile);
	}
	void endLeafWidthScale()const
	{
		fprintf(mFile,";\n");
	}
	void setLeafWidthScale_Position(size_t lws_i,float lwsp)
	{
		if(lwsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lws[%i].lwsp\" %f;\n", lws_i,lwsp);
	}
	void setLeafWidthScale_FloatValue(size_t lws_i,float lwsfv)
	{
		if(lwsfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lws[%i].lwsfv\" %f;\n", lws_i,lwsfv);
	}
	void setLeafWidthScale_Interp(size_t lws_i,unsigned int lwsi)
	{
		if(lwsi == 0) return;
		fprintf(mFile,"\tsetAttr \".lws[%i].lwsi\" %i;\n", lws_i,lwsi);
	}
	void setPetalWidthScale(size_t pws_i,const PetalWidthScale& pws)
	{
		fprintf(mFile,"\tsetAttr \".pws[%i]\" ",pws_i);
		pws.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPetalWidthScale(size_t pws_start,size_t pws_end,PetalWidthScale* pws)
	{
		fprintf(mFile,"\tsetAttr \".pws[%i:%i]\" ", pws_start,pws_end);
		size_t size = (pws_end-pws_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			pws[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startPetalWidthScale(size_t pws_start,size_t pws_end)const
	{
		fprintf(mFile,"\tsetAttr \".pws[%i:%i]\"",pws_start,pws_end);
		fprintf(mFile," -type \"PetalWidthScale\" ");
	}
	void appendPetalWidthScale(const PetalWidthScale& pws)const
	{
		fprintf(mFile," ");
		pws.write(mFile);
	}
	void endPetalWidthScale()const
	{
		fprintf(mFile,";\n");
	}
	void setPetalWidthScale_Position(size_t pws_i,float pwsp)
	{
		if(pwsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pws[%i].pwsp\" %f;\n", pws_i,pwsp);
	}
	void setPetalWidthScale_FloatValue(size_t pws_i,float pwsfv)
	{
		if(pwsfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pws[%i].pwsfv\" %f;\n", pws_i,pwsfv);
	}
	void setPetalWidthScale_Interp(size_t pws_i,unsigned int pwsi)
	{
		if(pwsi == 0) return;
		fprintf(mFile,"\tsetAttr \".pws[%i].pwsi\" %i;\n", pws_i,pwsi);
	}
	void setTwigLengthScale(size_t tls_i,const TwigLengthScale& tls)
	{
		fprintf(mFile,"\tsetAttr \".tls[%i]\" ",tls_i);
		tls.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTwigLengthScale(size_t tls_start,size_t tls_end,TwigLengthScale* tls)
	{
		fprintf(mFile,"\tsetAttr \".tls[%i:%i]\" ", tls_start,tls_end);
		size_t size = (tls_end-tls_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			tls[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startTwigLengthScale(size_t tls_start,size_t tls_end)const
	{
		fprintf(mFile,"\tsetAttr \".tls[%i:%i]\"",tls_start,tls_end);
		fprintf(mFile," -type \"TwigLengthScale\" ");
	}
	void appendTwigLengthScale(const TwigLengthScale& tls)const
	{
		fprintf(mFile," ");
		tls.write(mFile);
	}
	void endTwigLengthScale()const
	{
		fprintf(mFile,";\n");
	}
	void setTwigLengthScale_Position(size_t tls_i,float tlsp)
	{
		if(tlsp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tls[%i].tlsp\" %f;\n", tls_i,tlsp);
	}
	void setTwigLengthScale_FloatValue(size_t tls_i,float tlsfv)
	{
		if(tlsfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tls[%i].tlsfv\" %f;\n", tls_i,tlsfv);
	}
	void setTwigLengthScale_Interp(size_t tls_i,unsigned int tlsi)
	{
		if(tlsi == 0) return;
		fprintf(mFile,"\tsetAttr \".tls[%i].tlsi\" %i;\n", tls_i,tlsi);
	}
	void setBranchThorns(bool bth)
	{
		if(bth == false) return;
		fprintf(mFile,"\tsetAttr \".bth\" %i;\n", bth);
	}
	void setTwigThorns(bool tth)
	{
		if(tth == false) return;
		fprintf(mFile,"\tsetAttr \".tth\" %i;\n", tth);
	}
	void setLeafThorns(bool lth)
	{
		if(lth == false) return;
		fprintf(mFile,"\tsetAttr \".lth\" %i;\n", lth);
	}
	void setFlowerThorns(bool flt)
	{
		if(flt == false) return;
		fprintf(mFile,"\tsetAttr \".flt\" %i;\n", flt);
	}
	void setThornDensity(double nth)
	{
		if(nth == 10.0) return;
		fprintf(mFile,"\tsetAttr \".nth\" %f;\n", nth);
	}
	void setThornLength(double tln)
	{
		if(tln == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tln\" %f;\n", tln);
	}
	void setThornBaseWidth(double tbwd)
	{
		if(tbwd == 0.05) return;
		fprintf(mFile,"\tsetAttr \".tbwd\" %f;\n", tbwd);
	}
	void setThornTipWidth(double ttwd)
	{
		if(ttwd == 0.01) return;
		fprintf(mFile,"\tsetAttr \".ttwd\" %f;\n", ttwd);
	}
	void setThornElevation(double tel)
	{
		if(tel == 0.6) return;
		fprintf(mFile,"\tsetAttr \".tel\" %f;\n", tel);
	}
	void setThornSpecular(double tsp)
	{
		if(tsp == 0.4) return;
		fprintf(mFile,"\tsetAttr \".tsp\" %f;\n", tsp);
	}
	void setThornBaseColor(const float3& tbc)
	{
		fprintf(mFile,"\tsetAttr \".tbc\" -type \"float3\" ");
		tbc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setThornBaseColorR(float tbcr)
	{
		if(tbcr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tbc.tbcr\" %f;\n", tbcr);
	}
	void setThornBaseColorG(float tbcg)
	{
		if(tbcg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tbc.tbcg\" %f;\n", tbcg);
	}
	void setThornBaseColorB(float tbcb)
	{
		if(tbcb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tbc.tbcb\" %f;\n", tbcb);
	}
	void setThornTipColor(const float3& ttc)
	{
		fprintf(mFile,"\tsetAttr \".ttc\" -type \"float3\" ");
		ttc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setThornTipColorR(float ttcr)
	{
		if(ttcr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".ttc.ttcr\" %f;\n", ttcr);
	}
	void setThornTipColorG(float ttcg)
	{
		if(ttcg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".ttc.ttcg\" %f;\n", ttcg);
	}
	void setThornTipColorB(float ttcb)
	{
		if(ttcb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".ttc.ttcb\" %f;\n", ttcb);
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
	void setReflectionRolloff(size_t rro_i,const ReflectionRolloff& rro)
	{
		fprintf(mFile,"\tsetAttr \".rro[%i]\" ",rro_i);
		rro.write(mFile);
		fprintf(mFile,";\n");
	}
	void setReflectionRolloff(size_t rro_start,size_t rro_end,ReflectionRolloff* rro)
	{
		fprintf(mFile,"\tsetAttr \".rro[%i:%i]\" ", rro_start,rro_end);
		size_t size = (rro_end-rro_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			rro[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startReflectionRolloff(size_t rro_start,size_t rro_end)const
	{
		fprintf(mFile,"\tsetAttr \".rro[%i:%i]\"",rro_start,rro_end);
		fprintf(mFile," -type \"ReflectionRolloff\" ");
	}
	void appendReflectionRolloff(const ReflectionRolloff& rro)const
	{
		fprintf(mFile," ");
		rro.write(mFile);
	}
	void endReflectionRolloff()const
	{
		fprintf(mFile,";\n");
	}
	void setReflectionRolloff_Position(size_t rro_i,float rrop)
	{
		if(rrop == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rro[%i].rrop\" %f;\n", rro_i,rrop);
	}
	void setReflectionRolloff_FloatValue(size_t rro_i,float rrofv)
	{
		if(rrofv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rro[%i].rrofv\" %f;\n", rro_i,rrofv);
	}
	void setReflectionRolloff_Interp(size_t rro_i,unsigned int rroi)
	{
		if(rroi == 0) return;
		fprintf(mFile,"\tsetAttr \".rro[%i].rroi\" %i;\n", rro_i,rroi);
	}
	void setBranchReflectivity(double brf)
	{
		if(brf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".brf\" %f;\n", brf);
	}
	void setLeafReflectivity(double lrf)
	{
		if(lrf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lrf\" %f;\n", lrf);
	}
	void setFlowerReflectivity(double frf)
	{
		if(frf == 0.0) return;
		fprintf(mFile,"\tsetAttr \".frf\" %f;\n", frf);
	}
	void setForwardTwist(bool fwt)
	{
		if(fwt == false) return;
		fprintf(mFile,"\tsetAttr \".fwt\" %i;\n", fwt);
	}
	void setLeafForwardTwist(bool lfwt)
	{
		if(lfwt == false) return;
		fprintf(mFile,"\tsetAttr \".lfwt\" %i;\n", lfwt);
	}
	void setPetalForwardTwist(bool lpwt)
	{
		if(lpwt == false) return;
		fprintf(mFile,"\tsetAttr \".lpwt\" %i;\n", lpwt);
	}
	void setEndCaps(bool edc)
	{
		if(edc == false) return;
		fprintf(mFile,"\tsetAttr \".edc\" %i;\n", edc);
	}
	void setHardEdges(bool hde)
	{
		if(hde == false) return;
		fprintf(mFile,"\tsetAttr \".hde\" %i;\n", hde);
	}
	void getOutBrush()const
	{
		fprintf(mFile,"\"%s.obr\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());
	}
	void getGlobalScale()const
	{
		fprintf(mFile,"\"%s.gsc\"",mName.c_str());
	}
	void getDepth()const
	{
		fprintf(mFile,"\"%s.dep\"",mName.c_str());
	}
	void getModifyDepth()const
	{
		fprintf(mFile,"\"%s.mdp\"",mName.c_str());
	}
	void getModifyColor()const
	{
		fprintf(mFile,"\"%s.mdc\"",mName.c_str());
	}
	void getModifyAlpha()const
	{
		fprintf(mFile,"\"%s.mda\"",mName.c_str());
	}
	void getIlluminated()const
	{
		fprintf(mFile,"\"%s.ill\"",mName.c_str());
	}
	void getCastShadows()const
	{
		fprintf(mFile,"\"%s.csd\"",mName.c_str());
	}
	void getLightingBasedWidth()const
	{
		fprintf(mFile,"\"%s.lbw\"",mName.c_str());
	}
	void getBranches()const
	{
		fprintf(mFile,"\"%s.brc\"",mName.c_str());
	}
	void getTwigs()const
	{
		fprintf(mFile,"\"%s.twg\"",mName.c_str());
	}
	void getBuds()const
	{
		fprintf(mFile,"\"%s.bud\"",mName.c_str());
	}
	void getLeaves()const
	{
		fprintf(mFile,"\"%s.lvs\"",mName.c_str());
	}
	void getFlowers()const
	{
		fprintf(mFile,"\"%s.flw\"",mName.c_str());
	}
	void getBrushType()const
	{
		fprintf(mFile,"\"%s.brt\"",mName.c_str());
	}
	void getBrushWidth()const
	{
		fprintf(mFile,"\"%s.bwd\"",mName.c_str());
	}
	void getScreenspaceWidth()const
	{
		fprintf(mFile,"\"%s.spw\"",mName.c_str());
	}
	void getDistanceScaling()const
	{
		fprintf(mFile,"\"%s.dsl\"",mName.c_str());
	}
	void getMinPixelWidth()const
	{
		fprintf(mFile,"\"%s.mpw\"",mName.c_str());
	}
	void getMaxPixelWidth()const
	{
		fprintf(mFile,"\"%s.mxp\"",mName.c_str());
	}
	void getStampDensity()const
	{
		fprintf(mFile,"\"%s.sdn\"",mName.c_str());
	}
	void getSoftness()const
	{
		fprintf(mFile,"\"%s.sft\"",mName.c_str());
	}
	void getEdgeAntialias()const
	{
		fprintf(mFile,"\"%s.eaa\"",mName.c_str());
	}
	void getEdgeClip()const
	{
		fprintf(mFile,"\"%s.ecl\"",mName.c_str());
	}
	void getEdgeClipDepth()const
	{
		fprintf(mFile,"\"%s.ecd\"",mName.c_str());
	}
	void getOcclusionWidthScale()const
	{
		fprintf(mFile,"\"%s.ows\"",mName.c_str());
	}
	void getBlurIntensity()const
	{
		fprintf(mFile,"\"%s.bin\"",mName.c_str());
	}
	void getColor1()const
	{
		fprintf(mFile,"\"%s.cl1\"",mName.c_str());
	}
	void getColor1R()const
	{
		fprintf(mFile,"\"%s.cl1.c1r\"",mName.c_str());
	}
	void getColor1G()const
	{
		fprintf(mFile,"\"%s.cl1.c1g\"",mName.c_str());
	}
	void getColor1B()const
	{
		fprintf(mFile,"\"%s.cl1.c1b\"",mName.c_str());
	}
	void getColor2()const
	{
		fprintf(mFile,"\"%s.cl2\"",mName.c_str());
	}
	void getColor2R()const
	{
		fprintf(mFile,"\"%s.cl2.c2r\"",mName.c_str());
	}
	void getColor2G()const
	{
		fprintf(mFile,"\"%s.cl2.c2g\"",mName.c_str());
	}
	void getColor2B()const
	{
		fprintf(mFile,"\"%s.cl2.c2b\"",mName.c_str());
	}
	void getTransparency1()const
	{
		fprintf(mFile,"\"%s.tn1\"",mName.c_str());
	}
	void getTransparency1R()const
	{
		fprintf(mFile,"\"%s.tn1.t1r\"",mName.c_str());
	}
	void getTransparency1G()const
	{
		fprintf(mFile,"\"%s.tn1.t1g\"",mName.c_str());
	}
	void getTransparency1B()const
	{
		fprintf(mFile,"\"%s.tn1.t1b\"",mName.c_str());
	}
	void getTransparency2()const
	{
		fprintf(mFile,"\"%s.tn2\"",mName.c_str());
	}
	void getTransparency2R()const
	{
		fprintf(mFile,"\"%s.tn2.t2r\"",mName.c_str());
	}
	void getTransparency2G()const
	{
		fprintf(mFile,"\"%s.tn2.t2g\"",mName.c_str());
	}
	void getTransparency2B()const
	{
		fprintf(mFile,"\"%s.tn2.t2b\"",mName.c_str());
	}
	void getIncandescence1()const
	{
		fprintf(mFile,"\"%s.in1\"",mName.c_str());
	}
	void getIncandescence1R()const
	{
		fprintf(mFile,"\"%s.in1.i1r\"",mName.c_str());
	}
	void getIncandescence1G()const
	{
		fprintf(mFile,"\"%s.in1.i1g\"",mName.c_str());
	}
	void getIncandescence1B()const
	{
		fprintf(mFile,"\"%s.in1.i1b\"",mName.c_str());
	}
	void getIncandescence2()const
	{
		fprintf(mFile,"\"%s.in2\"",mName.c_str());
	}
	void getIncandescence2R()const
	{
		fprintf(mFile,"\"%s.in2.i2r\"",mName.c_str());
	}
	void getIncandescence2G()const
	{
		fprintf(mFile,"\"%s.in2.i2g\"",mName.c_str());
	}
	void getIncandescence2B()const
	{
		fprintf(mFile,"\"%s.in2.i2b\"",mName.c_str());
	}
	void getSpecularColor()const
	{
		fprintf(mFile,"\"%s.spc\"",mName.c_str());
	}
	void getSpecularColorR()const
	{
		fprintf(mFile,"\"%s.spc.spr\"",mName.c_str());
	}
	void getSpecularColorG()const
	{
		fprintf(mFile,"\"%s.spc.spg\"",mName.c_str());
	}
	void getSpecularColorB()const
	{
		fprintf(mFile,"\"%s.spc.spb\"",mName.c_str());
	}
	void getSpecular()const
	{
		fprintf(mFile,"\"%s.spe\"",mName.c_str());
	}
	void getSpecularPower()const
	{
		fprintf(mFile,"\"%s.spp\"",mName.c_str());
	}
	void getTranslucence()const
	{
		fprintf(mFile,"\"%s.trn\"",mName.c_str());
	}
	void getGlow()const
	{
		fprintf(mFile,"\"%s.glw\"",mName.c_str());
	}
	void getGlowColor()const
	{
		fprintf(mFile,"\"%s.glc\"",mName.c_str());
	}
	void getGlowColorR()const
	{
		fprintf(mFile,"\"%s.glc.glr\"",mName.c_str());
	}
	void getGlowColorG()const
	{
		fprintf(mFile,"\"%s.glc.glg\"",mName.c_str());
	}
	void getGlowColorB()const
	{
		fprintf(mFile,"\"%s.glc.glb\"",mName.c_str());
	}
	void getGlowSpread()const
	{
		fprintf(mFile,"\"%s.gls\"",mName.c_str());
	}
	void getShaderGlow()const
	{
		fprintf(mFile,"\"%s.sgl\"",mName.c_str());
	}
	void getHueRand()const
	{
		fprintf(mFile,"\"%s.chr\"",mName.c_str());
	}
	void getSatRand()const
	{
		fprintf(mFile,"\"%s.csr\"",mName.c_str());
	}
	void getValRand()const
	{
		fprintf(mFile,"\"%s.cvr\"",mName.c_str());
	}
	void getRootFade()const
	{
		fprintf(mFile,"\"%s.rfd\"",mName.c_str());
	}
	void getTipFade()const
	{
		fprintf(mFile,"\"%s.tfd\"",mName.c_str());
	}
	void getFakeShadow()const
	{
		fprintf(mFile,"\"%s.fks\"",mName.c_str());
	}
	void getShadowOffset()const
	{
		fprintf(mFile,"\"%s.sof\"",mName.c_str());
	}
	void getShadowDiffusion()const
	{
		fprintf(mFile,"\"%s.sdf\"",mName.c_str());
	}
	void getShadowTransparency()const
	{
		fprintf(mFile,"\"%s.stn\"",mName.c_str());
	}
	void getBackShadow()const
	{
		fprintf(mFile,"\"%s.bks\"",mName.c_str());
	}
	void getBrightnessRand()const
	{
		fprintf(mFile,"\"%s.brn\"",mName.c_str());
	}
	void getCenterShadow()const
	{
		fprintf(mFile,"\"%s.cns\"",mName.c_str());
	}
	void getDepthShadowType()const
	{
		fprintf(mFile,"\"%s.dpt\"",mName.c_str());
	}
	void getDepthShadow()const
	{
		fprintf(mFile,"\"%s.dpl\"",mName.c_str());
	}
	void getDepthShadowDepth()const
	{
		fprintf(mFile,"\"%s.dps\"",mName.c_str());
	}
	void getRealLights()const
	{
		fprintf(mFile,"\"%s.rll\"",mName.c_str());
	}
	void getLightDirection()const
	{
		fprintf(mFile,"\"%s.ldr\"",mName.c_str());
	}
	void getLightDirectionX()const
	{
		fprintf(mFile,"\"%s.ldr.ldx\"",mName.c_str());
	}
	void getLightDirectionY()const
	{
		fprintf(mFile,"\"%s.ldr.ldy\"",mName.c_str());
	}
	void getLightDirectionZ()const
	{
		fprintf(mFile,"\"%s.ldr.ldz\"",mName.c_str());
	}
	void getGapSize()const
	{
		fprintf(mFile,"\"%s.gsz\"",mName.c_str());
	}
	void getGapSpacing()const
	{
		fprintf(mFile,"\"%s.gsp\"",mName.c_str());
	}
	void getGapRand()const
	{
		fprintf(mFile,"\"%s.grn\"",mName.c_str());
	}
	void getFlowSpeed()const
	{
		fprintf(mFile,"\"%s.fws\"",mName.c_str());
	}
	void getTextureFlow()const
	{
		fprintf(mFile,"\"%s.tfl\"",mName.c_str());
	}
	void getTimeClip()const
	{
		fprintf(mFile,"\"%s.tcl\"",mName.c_str());
	}
	void getStrokeTime()const
	{
		fprintf(mFile,"\"%s.srm\"",mName.c_str());
	}
	void getStartTime()const
	{
		fprintf(mFile,"\"%s.sti\"",mName.c_str());
	}
	void getEndTime()const
	{
		fprintf(mFile,"\"%s.eti\"",mName.c_str());
	}
	void getTubes()const
	{
		fprintf(mFile,"\"%s.tub\"",mName.c_str());
	}
	void getCreationScript()const
	{
		fprintf(mFile,"\"%s.csc\"",mName.c_str());
	}
	void getRuntimeScript()const
	{
		fprintf(mFile,"\"%s.rsc\"",mName.c_str());
	}
	void getTubeCompletion()const
	{
		fprintf(mFile,"\"%s.tcm\"",mName.c_str());
	}
	void getTubesPerStep()const
	{
		fprintf(mFile,"\"%s.tps\"",mName.c_str());
	}
	void getTubeRand()const
	{
		fprintf(mFile,"\"%s.trd\"",mName.c_str());
	}
	void getStartTubes()const
	{
		fprintf(mFile,"\"%s.stb\"",mName.c_str());
	}
	void getLengthMax()const
	{
		fprintf(mFile,"\"%s.lnx\"",mName.c_str());
	}
	void getLengthMin()const
	{
		fprintf(mFile,"\"%s.lnn\"",mName.c_str());
	}
	void getSegments()const
	{
		fprintf(mFile,"\"%s.sgm\"",mName.c_str());
	}
	void getTubeWidth1()const
	{
		fprintf(mFile,"\"%s.tw1\"",mName.c_str());
	}
	void getTubeWidth2()const
	{
		fprintf(mFile,"\"%s.tw2\"",mName.c_str());
	}
	void getWidthRand()const
	{
		fprintf(mFile,"\"%s.wdr\"",mName.c_str());
	}
	void getWidthBias()const
	{
		fprintf(mFile,"\"%s.wdb\"",mName.c_str());
	}
	void getLengthFlex()const
	{
		fprintf(mFile,"\"%s.lfx\"",mName.c_str());
	}
	void getSegmentLengthBias()const
	{
		fprintf(mFile,"\"%s.sgb\"",mName.c_str());
	}
	void getSegmentWidthBias()const
	{
		fprintf(mFile,"\"%s.swb\"",mName.c_str());
	}
	void getTubeDirection()const
	{
		fprintf(mFile,"\"%s.tdr\"",mName.c_str());
	}
	void getElevationMin()const
	{
		fprintf(mFile,"\"%s.elm\"",mName.c_str());
	}
	void getElevationMax()const
	{
		fprintf(mFile,"\"%s.elx\"",mName.c_str());
	}
	void getAzimuthMin()const
	{
		fprintf(mFile,"\"%s.azn\"",mName.c_str());
	}
	void getAzimuthMax()const
	{
		fprintf(mFile,"\"%s.azx\"",mName.c_str());
	}
	void getFlatness1()const
	{
		fprintf(mFile,"\"%s.fl1\"",mName.c_str());
	}
	void getFlatness2()const
	{
		fprintf(mFile,"\"%s.fl2\"",mName.c_str());
	}
	void getTwist()const
	{
		fprintf(mFile,"\"%s.twi\"",mName.c_str());
	}
	void getTwistRate()const
	{
		fprintf(mFile,"\"%s.twr\"",mName.c_str());
	}
	void getTwistRand()const
	{
		fprintf(mFile,"\"%s.twd\"",mName.c_str());
	}
	void getSpiralMin()const
	{
		fprintf(mFile,"\"%s.spm\"",mName.c_str());
	}
	void getSpiralMax()const
	{
		fprintf(mFile,"\"%s.spx\"",mName.c_str());
	}
	void getSpiralDecay()const
	{
		fprintf(mFile,"\"%s.spd\"",mName.c_str());
	}
	void getBend()const
	{
		fprintf(mFile,"\"%s.ben\"",mName.c_str());
	}
	void getBendBias()const
	{
		fprintf(mFile,"\"%s.bnb\"",mName.c_str());
	}
	void getDisplacementDelay()const
	{
		fprintf(mFile,"\"%s.ddl\"",mName.c_str());
	}
	void getWiggle()const
	{
		fprintf(mFile,"\"%s.wgl\"",mName.c_str());
	}
	void getWiggleFrequency()const
	{
		fprintf(mFile,"\"%s.wgf\"",mName.c_str());
	}
	void getWiggleOffset()const
	{
		fprintf(mFile,"\"%s.wgo\"",mName.c_str());
	}
	void getCurl()const
	{
		fprintf(mFile,"\"%s.crl\"",mName.c_str());
	}
	void getCurlFrequency()const
	{
		fprintf(mFile,"\"%s.crf\"",mName.c_str());
	}
	void getCurlOffset()const
	{
		fprintf(mFile,"\"%s.cro\"",mName.c_str());
	}
	void getNoise()const
	{
		fprintf(mFile,"\"%s.noi\"",mName.c_str());
	}
	void getNoiseFrequency()const
	{
		fprintf(mFile,"\"%s.nof\"",mName.c_str());
	}
	void getNoiseOffset()const
	{
		fprintf(mFile,"\"%s.noo\"",mName.c_str());
	}
	void getSplitMaxDepth()const
	{
		fprintf(mFile,"\"%s.smd\"",mName.c_str());
	}
	void getSplitRand()const
	{
		fprintf(mFile,"\"%s.srd\"",mName.c_str());
	}
	void getSplitAngle()const
	{
		fprintf(mFile,"\"%s.spa\"",mName.c_str());
	}
	void getSplitSizeDecay()const
	{
		fprintf(mFile,"\"%s.ssd\"",mName.c_str());
	}
	void getSplitBias()const
	{
		fprintf(mFile,"\"%s.slb\"",mName.c_str());
	}
	void getSplitTwist()const
	{
		fprintf(mFile,"\"%s.slt\"",mName.c_str());
	}
	void getStartBranches()const
	{
		fprintf(mFile,"\"%s.sbr\"",mName.c_str());
	}
	void getNumBranches()const
	{
		fprintf(mFile,"\"%s.nbr\"",mName.c_str());
	}
	void getBranchDropout()const
	{
		fprintf(mFile,"\"%s.bdr\"",mName.c_str());
	}
	void getMiddleBranch()const
	{
		fprintf(mFile,"\"%s.mbr\"",mName.c_str());
	}
	void getMinSize()const
	{
		fprintf(mFile,"\"%s.mms\"",mName.c_str());
	}
	void getPathFollow()const
	{
		fprintf(mFile,"\"%s.pfl\"",mName.c_str());
	}
	void getPathAttract()const
	{
		fprintf(mFile,"\"%s.pat\"",mName.c_str());
	}
	void getCurveFollow()const
	{
		fprintf(mFile,"\"%s.cfw\"",mName.c_str());
	}
	void getCurveAttract()const
	{
		fprintf(mFile,"\"%s.cva\"",mName.c_str());
	}
	void getCurveMaxDist()const
	{
		fprintf(mFile,"\"%s.cmd\"",mName.c_str());
	}
	void getUniformForce()const
	{
		fprintf(mFile,"\"%s.ufr\"",mName.c_str());
	}
	void getUniformForceX()const
	{
		fprintf(mFile,"\"%s.ufr.ufx\"",mName.c_str());
	}
	void getUniformForceY()const
	{
		fprintf(mFile,"\"%s.ufr.ufy\"",mName.c_str());
	}
	void getUniformForceZ()const
	{
		fprintf(mFile,"\"%s.ufr.ufz\"",mName.c_str());
	}
	void getTurbulenceType()const
	{
		fprintf(mFile,"\"%s.trt\"",mName.c_str());
	}
	void getTurbulenceInterpolation()const
	{
		fprintf(mFile,"\"%s.tin\"",mName.c_str());
	}
	void getTurbulence()const
	{
		fprintf(mFile,"\"%s.tur\"",mName.c_str());
	}
	void getTurbulenceFrequency()const
	{
		fprintf(mFile,"\"%s.trf\"",mName.c_str());
	}
	void getTurbulenceSpeed()const
	{
		fprintf(mFile,"\"%s.trs\"",mName.c_str());
	}
	void getTurbulenceOffset()const
	{
		fprintf(mFile,"\"%s.tro\"",mName.c_str());
	}
	void getTurbulenceOffsetX()const
	{
		fprintf(mFile,"\"%s.tro.trx\"",mName.c_str());
	}
	void getTurbulenceOffsetY()const
	{
		fprintf(mFile,"\"%s.tro.try\"",mName.c_str());
	}
	void getTurbulenceOffsetZ()const
	{
		fprintf(mFile,"\"%s.tro.trz\"",mName.c_str());
	}
	void getRandom()const
	{
		fprintf(mFile,"\"%s.ran\"",mName.c_str());
	}
	void getGravity()const
	{
		fprintf(mFile,"\"%s.grv\"",mName.c_str());
	}
	void getMomentum()const
	{
		fprintf(mFile,"\"%s.mmt\"",mName.c_str());
	}
	void getDeflection()const
	{
		fprintf(mFile,"\"%s.def\"",mName.c_str());
	}
	void getDeflectionMin()const
	{
		fprintf(mFile,"\"%s.dfm\"",mName.c_str());
	}
	void getDeflectionMax()const
	{
		fprintf(mFile,"\"%s.dfx\"",mName.c_str());
	}
	void getTwigsInCluster()const
	{
		fprintf(mFile,"\"%s.tic\"",mName.c_str());
	}
	void getTwigDropout()const
	{
		fprintf(mFile,"\"%s.tdp\"",mName.c_str());
	}
	void getTwigAngle1()const
	{
		fprintf(mFile,"\"%s.ta1\"",mName.c_str());
	}
	void getTwigAngle2()const
	{
		fprintf(mFile,"\"%s.ta2\"",mName.c_str());
	}
	void getTwigTwist()const
	{
		fprintf(mFile,"\"%s.ttw\"",mName.c_str());
	}
	void getTwigLength()const
	{
		fprintf(mFile,"\"%s.twl\"",mName.c_str());
	}
	void getTwigStart()const
	{
		fprintf(mFile,"\"%s.tst\"",mName.c_str());
	}
	void getNumTwigClusters()const
	{
		fprintf(mFile,"\"%s.ntc\"",mName.c_str());
	}
	void getTwigBaseWidth()const
	{
		fprintf(mFile,"\"%s.twb\"",mName.c_str());
	}
	void getTwigTipWidth()const
	{
		fprintf(mFile,"\"%s.twt\"",mName.c_str());
	}
	void getTwigStiffness()const
	{
		fprintf(mFile,"\"%s.tgs\"",mName.c_str());
	}
	void getBranchAfterTwigs()const
	{
		fprintf(mFile,"\"%s.bat\"",mName.c_str());
	}
	void getLeavesInCluster()const
	{
		fprintf(mFile,"\"%s.lic\"",mName.c_str());
	}
	void getLeafLocation()const
	{
		fprintf(mFile,"\"%s.llo\"",mName.c_str());
	}
	void getLeafDropout()const
	{
		fprintf(mFile,"\"%s.ldp\"",mName.c_str());
	}
	void getLeafAngle1()const
	{
		fprintf(mFile,"\"%s.ll1\"",mName.c_str());
	}
	void getLeafAngle2()const
	{
		fprintf(mFile,"\"%s.ll2\"",mName.c_str());
	}
	void getLeafTwist()const
	{
		fprintf(mFile,"\"%s.ltw\"",mName.c_str());
	}
	void getLeafBend()const
	{
		fprintf(mFile,"\"%s.lbn\"",mName.c_str());
	}
	void getLeafCurl(size_t lcl_i)const
	{
		fprintf(mFile,"\"%s.lcl[%i]\"",mName.c_str(),lcl_i);
	}
	void getLeafCurl()const
	{

		fprintf(mFile,"\"%s.lcl\"",mName.c_str());
	}
	void getLeafCurl_Position(size_t lcl_i)const
	{
		fprintf(mFile,"\"%s.lcl[%i].lclp\"",mName.c_str(),lcl_i);
	}
	void getLeafCurl_Position()const
	{

		fprintf(mFile,"\"%s.lcl.lclp\"",mName.c_str());
	}
	void getLeafCurl_FloatValue(size_t lcl_i)const
	{
		fprintf(mFile,"\"%s.lcl[%i].lclfv\"",mName.c_str(),lcl_i);
	}
	void getLeafCurl_FloatValue()const
	{

		fprintf(mFile,"\"%s.lcl.lclfv\"",mName.c_str());
	}
	void getLeafCurl_Interp(size_t lcl_i)const
	{
		fprintf(mFile,"\"%s.lcl[%i].lcli\"",mName.c_str(),lcl_i);
	}
	void getLeafCurl_Interp()const
	{

		fprintf(mFile,"\"%s.lcl.lcli\"",mName.c_str());
	}
	void getLeafTwirl()const
	{
		fprintf(mFile,"\"%s.ltwl\"",mName.c_str());
	}
	void getLeafSegments()const
	{
		fprintf(mFile,"\"%s.lsg\"",mName.c_str());
	}
	void getLeafStart()const
	{
		fprintf(mFile,"\"%s.lst\"",mName.c_str());
	}
	void getNumLeafClusters()const
	{
		fprintf(mFile,"\"%s.nlc\"",mName.c_str());
	}
	void getLeafFlatness()const
	{
		fprintf(mFile,"\"%s.lft\"",mName.c_str());
	}
	void getLeafLength()const
	{
		fprintf(mFile,"\"%s.lln\"",mName.c_str());
	}
	void getLeafBaseWidth()const
	{
		fprintf(mFile,"\"%s.leb\"",mName.c_str());
	}
	void getLeafTipWidth()const
	{
		fprintf(mFile,"\"%s.let\"",mName.c_str());
	}
	void getLeafSizeDecay()const
	{
		fprintf(mFile,"\"%s.lsd\"",mName.c_str());
	}
	void getLeafTranslucence()const
	{
		fprintf(mFile,"\"%s.ltr\"",mName.c_str());
	}
	void getLeafSpecular()const
	{
		fprintf(mFile,"\"%s.lsp\"",mName.c_str());
	}
	void getTerminalLeaf()const
	{
		fprintf(mFile,"\"%s.tml\"",mName.c_str());
	}
	void getLeafColor1()const
	{
		fprintf(mFile,"\"%s.lc1\"",mName.c_str());
	}
	void getLeafColor1R()const
	{
		fprintf(mFile,"\"%s.lc1.lr1\"",mName.c_str());
	}
	void getLeafColor1G()const
	{
		fprintf(mFile,"\"%s.lc1.lg1\"",mName.c_str());
	}
	void getLeafColor1B()const
	{
		fprintf(mFile,"\"%s.lc1.lb1\"",mName.c_str());
	}
	void getLeafColor2()const
	{
		fprintf(mFile,"\"%s.lc2\"",mName.c_str());
	}
	void getLeafColor2R()const
	{
		fprintf(mFile,"\"%s.lc2.lr2\"",mName.c_str());
	}
	void getLeafColor2G()const
	{
		fprintf(mFile,"\"%s.lc2.lg2\"",mName.c_str());
	}
	void getLeafColor2B()const
	{
		fprintf(mFile,"\"%s.lc2.lb2\"",mName.c_str());
	}
	void getLeafHueRand()const
	{
		fprintf(mFile,"\"%s.lhr\"",mName.c_str());
	}
	void getLeafSatRand()const
	{
		fprintf(mFile,"\"%s.lsr\"",mName.c_str());
	}
	void getLeafValRand()const
	{
		fprintf(mFile,"\"%s.lvr\"",mName.c_str());
	}
	void getLeafUseBranchTex()const
	{
		fprintf(mFile,"\"%s.lub\"",mName.c_str());
	}
	void getLeafImage()const
	{
		fprintf(mFile,"\"%s.lim\"",mName.c_str());
	}
	void getLeafStiffness()const
	{
		fprintf(mFile,"\"%s.lfs\"",mName.c_str());
	}
	void getBudSize()const
	{
		fprintf(mFile,"\"%s.bds\"",mName.c_str());
	}
	void getBudColor()const
	{
		fprintf(mFile,"\"%s.bcr\"",mName.c_str());
	}
	void getBudColorR()const
	{
		fprintf(mFile,"\"%s.bcr.bur\"",mName.c_str());
	}
	void getBudColorG()const
	{
		fprintf(mFile,"\"%s.bcr.bug\"",mName.c_str());
	}
	void getBudColorB()const
	{
		fprintf(mFile,"\"%s.bcr.bub\"",mName.c_str());
	}
	void getPetalsInFlower()const
	{
		fprintf(mFile,"\"%s.pif\"",mName.c_str());
	}
	void getFlowerLocation()const
	{
		fprintf(mFile,"\"%s.flc\"",mName.c_str());
	}
	void getPetalDropout()const
	{
		fprintf(mFile,"\"%s.pdp\"",mName.c_str());
	}
	void getFlowerAngle1()const
	{
		fprintf(mFile,"\"%s.fw1\"",mName.c_str());
	}
	void getFlowerAngle2()const
	{
		fprintf(mFile,"\"%s.fw2\"",mName.c_str());
	}
	void getFlowerTwist()const
	{
		fprintf(mFile,"\"%s.ftw\"",mName.c_str());
	}
	void getPetalBend()const
	{
		fprintf(mFile,"\"%s.pbn\"",mName.c_str());
	}
	void getPetalCurl(size_t pcl_i)const
	{
		fprintf(mFile,"\"%s.pcl[%i]\"",mName.c_str(),pcl_i);
	}
	void getPetalCurl()const
	{

		fprintf(mFile,"\"%s.pcl\"",mName.c_str());
	}
	void getPetalCurl_Position(size_t pcl_i)const
	{
		fprintf(mFile,"\"%s.pcl[%i].pclp\"",mName.c_str(),pcl_i);
	}
	void getPetalCurl_Position()const
	{

		fprintf(mFile,"\"%s.pcl.pclp\"",mName.c_str());
	}
	void getPetalCurl_FloatValue(size_t pcl_i)const
	{
		fprintf(mFile,"\"%s.pcl[%i].pclfv\"",mName.c_str(),pcl_i);
	}
	void getPetalCurl_FloatValue()const
	{

		fprintf(mFile,"\"%s.pcl.pclfv\"",mName.c_str());
	}
	void getPetalCurl_Interp(size_t pcl_i)const
	{
		fprintf(mFile,"\"%s.pcl[%i].pcli\"",mName.c_str(),pcl_i);
	}
	void getPetalCurl_Interp()const
	{

		fprintf(mFile,"\"%s.pcl.pcli\"",mName.c_str());
	}
	void getPetalTwirl()const
	{
		fprintf(mFile,"\"%s.lpwl\"",mName.c_str());
	}
	void getPetalSegments()const
	{
		fprintf(mFile,"\"%s.psg\"",mName.c_str());
	}
	void getFlowerStart()const
	{
		fprintf(mFile,"\"%s.fst\"",mName.c_str());
	}
	void getNumFlowers()const
	{
		fprintf(mFile,"\"%s.nfl\"",mName.c_str());
	}
	void getPetalFlatness()const
	{
		fprintf(mFile,"\"%s.pft\"",mName.c_str());
	}
	void getPetalLength()const
	{
		fprintf(mFile,"\"%s.pln\"",mName.c_str());
	}
	void getPetalBaseWidth()const
	{
		fprintf(mFile,"\"%s.ptb\"",mName.c_str());
	}
	void getPetalTipWidth()const
	{
		fprintf(mFile,"\"%s.ptt\"",mName.c_str());
	}
	void getFlowerSizeDecay()const
	{
		fprintf(mFile,"\"%s.fsd\"",mName.c_str());
	}
	void getFlowerTranslucence()const
	{
		fprintf(mFile,"\"%s.ftr\"",mName.c_str());
	}
	void getFlowerSpecular()const
	{
		fprintf(mFile,"\"%s.fsp\"",mName.c_str());
	}
	void getPetalColor1()const
	{
		fprintf(mFile,"\"%s.pc1\"",mName.c_str());
	}
	void getPetalColor1R()const
	{
		fprintf(mFile,"\"%s.pc1.pr1\"",mName.c_str());
	}
	void getPetalColor1G()const
	{
		fprintf(mFile,"\"%s.pc1.pg1\"",mName.c_str());
	}
	void getPetalColor1B()const
	{
		fprintf(mFile,"\"%s.pc1.pb1\"",mName.c_str());
	}
	void getPetalColor2()const
	{
		fprintf(mFile,"\"%s.pc2\"",mName.c_str());
	}
	void getPetalColor2R()const
	{
		fprintf(mFile,"\"%s.pc2.pr2\"",mName.c_str());
	}
	void getPetalColor2G()const
	{
		fprintf(mFile,"\"%s.pc2.pg2\"",mName.c_str());
	}
	void getPetalColor2B()const
	{
		fprintf(mFile,"\"%s.pc2.pb2\"",mName.c_str());
	}
	void getFlowerHueRand()const
	{
		fprintf(mFile,"\"%s.fhr\"",mName.c_str());
	}
	void getFlowerSatRand()const
	{
		fprintf(mFile,"\"%s.fsr\"",mName.c_str());
	}
	void getFlowerValRand()const
	{
		fprintf(mFile,"\"%s.fvr\"",mName.c_str());
	}
	void getFlowerUseBranchTex()const
	{
		fprintf(mFile,"\"%s.fub\"",mName.c_str());
	}
	void getFlowerImage()const
	{
		fprintf(mFile,"\"%s.fim\"",mName.c_str());
	}
	void getFlowerStiffness()const
	{
		fprintf(mFile,"\"%s.fls\"",mName.c_str());
	}
	void getSimplifyMethod()const
	{
		fprintf(mFile,"\"%s.smp\"",mName.c_str());
	}
	void getColorLengthMap()const
	{
		fprintf(mFile,"\"%s.clm\"",mName.c_str());
	}
	void getTranspLengthMap()const
	{
		fprintf(mFile,"\"%s.tlm\"",mName.c_str());
	}
	void getIncandLengthMap()const
	{
		fprintf(mFile,"\"%s.ilm\"",mName.c_str());
	}
	void getWidthLengthMap()const
	{
		fprintf(mFile,"\"%s.wlm\"",mName.c_str());
	}
	void getSplitLengthMap()const
	{
		fprintf(mFile,"\"%s.spl\"",mName.c_str());
	}
	void getMapColor()const
	{
		fprintf(mFile,"\"%s.mcl\"",mName.c_str());
	}
	void getMapOpacity()const
	{
		fprintf(mFile,"\"%s.mop\"",mName.c_str());
	}
	void getMapDisplacement()const
	{
		fprintf(mFile,"\"%s.mds\"",mName.c_str());
	}
	void getTextureType()const
	{
		fprintf(mFile,"\"%s.txt\"",mName.c_str());
	}
	void getMapMethod()const
	{
		fprintf(mFile,"\"%s.mmd\"",mName.c_str());
	}
	void getTexColorScale()const
	{
		fprintf(mFile,"\"%s.tcs\"",mName.c_str());
	}
	void getTexColorOffset()const
	{
		fprintf(mFile,"\"%s.tco\"",mName.c_str());
	}
	void getTexOpacityScale()const
	{
		fprintf(mFile,"\"%s.tos\"",mName.c_str());
	}
	void getTexOpacityOffset()const
	{
		fprintf(mFile,"\"%s.too\"",mName.c_str());
	}
	void getDisplacementScale()const
	{
		fprintf(mFile,"\"%s.dsc\"",mName.c_str());
	}
	void getDisplacementOffset()const
	{
		fprintf(mFile,"\"%s.dof\"",mName.c_str());
	}
	void getBumpIntensity()const
	{
		fprintf(mFile,"\"%s.bmi\"",mName.c_str());
	}
	void getBumpBlur()const
	{
		fprintf(mFile,"\"%s.bbl\"",mName.c_str());
	}
	void getLuminanceIsDisplacement()const
	{
		fprintf(mFile,"\"%s.lid\"",mName.c_str());
	}
	void getTexColor1()const
	{
		fprintf(mFile,"\"%s.tc1\"",mName.c_str());
	}
	void getTexColor1R()const
	{
		fprintf(mFile,"\"%s.tc1.x1r\"",mName.c_str());
	}
	void getTexColor1G()const
	{
		fprintf(mFile,"\"%s.tc1.x1g\"",mName.c_str());
	}
	void getTexColor1B()const
	{
		fprintf(mFile,"\"%s.tc1.x1b\"",mName.c_str());
	}
	void getTexColor2()const
	{
		fprintf(mFile,"\"%s.tc2\"",mName.c_str());
	}
	void getTexColor2R()const
	{
		fprintf(mFile,"\"%s.tc2.x2r\"",mName.c_str());
	}
	void getTexColor2G()const
	{
		fprintf(mFile,"\"%s.tc2.x2g\"",mName.c_str());
	}
	void getTexColor2B()const
	{
		fprintf(mFile,"\"%s.tc2.x2b\"",mName.c_str());
	}
	void getTexAlpha1()const
	{
		fprintf(mFile,"\"%s.al1\"",mName.c_str());
	}
	void getTexAlpha2()const
	{
		fprintf(mFile,"\"%s.al2\"",mName.c_str());
	}
	void getTexUniformity()const
	{
		fprintf(mFile,"\"%s.txu\"",mName.c_str());
	}
	void getFringeRemoval()const
	{
		fprintf(mFile,"\"%s.frm\"",mName.c_str());
	}
	void getRepeatU()const
	{
		fprintf(mFile,"\"%s.rpu\"",mName.c_str());
	}
	void getRepeatV()const
	{
		fprintf(mFile,"\"%s.rpv\"",mName.c_str());
	}
	void getOffsetU()const
	{
		fprintf(mFile,"\"%s.ofu\"",mName.c_str());
	}
	void getOffsetV()const
	{
		fprintf(mFile,"\"%s.ofv\"",mName.c_str());
	}
	void getBlurMult()const
	{
		fprintf(mFile,"\"%s.bmt\"",mName.c_str());
	}
	void getSmear()const
	{
		fprintf(mFile,"\"%s.smr\"",mName.c_str());
	}
	void getSmearU()const
	{
		fprintf(mFile,"\"%s.sru\"",mName.c_str());
	}
	void getSmearV()const
	{
		fprintf(mFile,"\"%s.srv\"",mName.c_str());
	}
	void getImageName()const
	{
		fprintf(mFile,"\"%s.imn\"",mName.c_str());
	}
	void getUseFrameExtension()const
	{
		fprintf(mFile,"\"%s.ufe\"",mName.c_str());
	}
	void getFrameExtension()const
	{
		fprintf(mFile,"\"%s.fe\"",mName.c_str());
	}
	void getFractalRatio()const
	{
		fprintf(mFile,"\"%s.fra\"",mName.c_str());
	}
	void getFractalAmplitude()const
	{
		fprintf(mFile,"\"%s.fam\"",mName.c_str());
	}
	void getFractalThreshold()const
	{
		fprintf(mFile,"\"%s.fth\"",mName.c_str());
	}
	void getMultiStreaks()const
	{
		fprintf(mFile,"\"%s.mst\"",mName.c_str());
	}
	void getMultiStreakSpread1()const
	{
		fprintf(mFile,"\"%s.ms1\"",mName.c_str());
	}
	void getMultiStreakSpread2()const
	{
		fprintf(mFile,"\"%s.ms2\"",mName.c_str());
	}
	void getMultiStreakDiffuseRand()const
	{
		fprintf(mFile,"\"%s.msdr\"",mName.c_str());
	}
	void getMultiStreakSpecularRand()const
	{
		fprintf(mFile,"\"%s.mssr\"",mName.c_str());
	}
	void getMultiStreakLightAll()const
	{
		fprintf(mFile,"\"%s.msla\"",mName.c_str());
	}
	void getSingleSided()const
	{
		fprintf(mFile,"\"%s.snsd\"",mName.c_str());
	}
	void getTubeSections()const
	{
		fprintf(mFile,"\"%s.tbs\"",mName.c_str());
	}
	void getSubSegments()const
	{
		fprintf(mFile,"\"%s.ssg\"",mName.c_str());
	}
	void getPerPixelLighting()const
	{
		fprintf(mFile,"\"%s.ppl\"",mName.c_str());
	}
	void getWidthScale(size_t wsc_i)const
	{
		fprintf(mFile,"\"%s.wsc[%i]\"",mName.c_str(),wsc_i);
	}
	void getWidthScale()const
	{

		fprintf(mFile,"\"%s.wsc\"",mName.c_str());
	}
	void getWidthScale_Position(size_t wsc_i)const
	{
		fprintf(mFile,"\"%s.wsc[%i].wscp\"",mName.c_str(),wsc_i);
	}
	void getWidthScale_Position()const
	{

		fprintf(mFile,"\"%s.wsc.wscp\"",mName.c_str());
	}
	void getWidthScale_FloatValue(size_t wsc_i)const
	{
		fprintf(mFile,"\"%s.wsc[%i].wscfv\"",mName.c_str(),wsc_i);
	}
	void getWidthScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.wsc.wscfv\"",mName.c_str());
	}
	void getWidthScale_Interp(size_t wsc_i)const
	{
		fprintf(mFile,"\"%s.wsc[%i].wsci\"",mName.c_str(),wsc_i);
	}
	void getWidthScale_Interp()const
	{

		fprintf(mFile,"\"%s.wsc.wsci\"",mName.c_str());
	}
	void getLeafWidthScale(size_t lws_i)const
	{
		fprintf(mFile,"\"%s.lws[%i]\"",mName.c_str(),lws_i);
	}
	void getLeafWidthScale()const
	{

		fprintf(mFile,"\"%s.lws\"",mName.c_str());
	}
	void getLeafWidthScale_Position(size_t lws_i)const
	{
		fprintf(mFile,"\"%s.lws[%i].lwsp\"",mName.c_str(),lws_i);
	}
	void getLeafWidthScale_Position()const
	{

		fprintf(mFile,"\"%s.lws.lwsp\"",mName.c_str());
	}
	void getLeafWidthScale_FloatValue(size_t lws_i)const
	{
		fprintf(mFile,"\"%s.lws[%i].lwsfv\"",mName.c_str(),lws_i);
	}
	void getLeafWidthScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.lws.lwsfv\"",mName.c_str());
	}
	void getLeafWidthScale_Interp(size_t lws_i)const
	{
		fprintf(mFile,"\"%s.lws[%i].lwsi\"",mName.c_str(),lws_i);
	}
	void getLeafWidthScale_Interp()const
	{

		fprintf(mFile,"\"%s.lws.lwsi\"",mName.c_str());
	}
	void getPetalWidthScale(size_t pws_i)const
	{
		fprintf(mFile,"\"%s.pws[%i]\"",mName.c_str(),pws_i);
	}
	void getPetalWidthScale()const
	{

		fprintf(mFile,"\"%s.pws\"",mName.c_str());
	}
	void getPetalWidthScale_Position(size_t pws_i)const
	{
		fprintf(mFile,"\"%s.pws[%i].pwsp\"",mName.c_str(),pws_i);
	}
	void getPetalWidthScale_Position()const
	{

		fprintf(mFile,"\"%s.pws.pwsp\"",mName.c_str());
	}
	void getPetalWidthScale_FloatValue(size_t pws_i)const
	{
		fprintf(mFile,"\"%s.pws[%i].pwsfv\"",mName.c_str(),pws_i);
	}
	void getPetalWidthScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.pws.pwsfv\"",mName.c_str());
	}
	void getPetalWidthScale_Interp(size_t pws_i)const
	{
		fprintf(mFile,"\"%s.pws[%i].pwsi\"",mName.c_str(),pws_i);
	}
	void getPetalWidthScale_Interp()const
	{

		fprintf(mFile,"\"%s.pws.pwsi\"",mName.c_str());
	}
	void getTwigLengthScale(size_t tls_i)const
	{
		fprintf(mFile,"\"%s.tls[%i]\"",mName.c_str(),tls_i);
	}
	void getTwigLengthScale()const
	{

		fprintf(mFile,"\"%s.tls\"",mName.c_str());
	}
	void getTwigLengthScale_Position(size_t tls_i)const
	{
		fprintf(mFile,"\"%s.tls[%i].tlsp\"",mName.c_str(),tls_i);
	}
	void getTwigLengthScale_Position()const
	{

		fprintf(mFile,"\"%s.tls.tlsp\"",mName.c_str());
	}
	void getTwigLengthScale_FloatValue(size_t tls_i)const
	{
		fprintf(mFile,"\"%s.tls[%i].tlsfv\"",mName.c_str(),tls_i);
	}
	void getTwigLengthScale_FloatValue()const
	{

		fprintf(mFile,"\"%s.tls.tlsfv\"",mName.c_str());
	}
	void getTwigLengthScale_Interp(size_t tls_i)const
	{
		fprintf(mFile,"\"%s.tls[%i].tlsi\"",mName.c_str(),tls_i);
	}
	void getTwigLengthScale_Interp()const
	{

		fprintf(mFile,"\"%s.tls.tlsi\"",mName.c_str());
	}
	void getBranchThorns()const
	{
		fprintf(mFile,"\"%s.bth\"",mName.c_str());
	}
	void getTwigThorns()const
	{
		fprintf(mFile,"\"%s.tth\"",mName.c_str());
	}
	void getLeafThorns()const
	{
		fprintf(mFile,"\"%s.lth\"",mName.c_str());
	}
	void getFlowerThorns()const
	{
		fprintf(mFile,"\"%s.flt\"",mName.c_str());
	}
	void getThornDensity()const
	{
		fprintf(mFile,"\"%s.nth\"",mName.c_str());
	}
	void getThornLength()const
	{
		fprintf(mFile,"\"%s.tln\"",mName.c_str());
	}
	void getThornBaseWidth()const
	{
		fprintf(mFile,"\"%s.tbwd\"",mName.c_str());
	}
	void getThornTipWidth()const
	{
		fprintf(mFile,"\"%s.ttwd\"",mName.c_str());
	}
	void getThornElevation()const
	{
		fprintf(mFile,"\"%s.tel\"",mName.c_str());
	}
	void getThornSpecular()const
	{
		fprintf(mFile,"\"%s.tsp\"",mName.c_str());
	}
	void getThornBaseColor()const
	{
		fprintf(mFile,"\"%s.tbc\"",mName.c_str());
	}
	void getThornBaseColorR()const
	{
		fprintf(mFile,"\"%s.tbc.tbcr\"",mName.c_str());
	}
	void getThornBaseColorG()const
	{
		fprintf(mFile,"\"%s.tbc.tbcg\"",mName.c_str());
	}
	void getThornBaseColorB()const
	{
		fprintf(mFile,"\"%s.tbc.tbcb\"",mName.c_str());
	}
	void getThornTipColor()const
	{
		fprintf(mFile,"\"%s.ttc\"",mName.c_str());
	}
	void getThornTipColorR()const
	{
		fprintf(mFile,"\"%s.ttc.ttcr\"",mName.c_str());
	}
	void getThornTipColorG()const
	{
		fprintf(mFile,"\"%s.ttc.ttcg\"",mName.c_str());
	}
	void getThornTipColorB()const
	{
		fprintf(mFile,"\"%s.ttc.ttcb\"",mName.c_str());
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
	void getReflectionRolloff(size_t rro_i)const
	{
		fprintf(mFile,"\"%s.rro[%i]\"",mName.c_str(),rro_i);
	}
	void getReflectionRolloff()const
	{

		fprintf(mFile,"\"%s.rro\"",mName.c_str());
	}
	void getReflectionRolloff_Position(size_t rro_i)const
	{
		fprintf(mFile,"\"%s.rro[%i].rrop\"",mName.c_str(),rro_i);
	}
	void getReflectionRolloff_Position()const
	{

		fprintf(mFile,"\"%s.rro.rrop\"",mName.c_str());
	}
	void getReflectionRolloff_FloatValue(size_t rro_i)const
	{
		fprintf(mFile,"\"%s.rro[%i].rrofv\"",mName.c_str(),rro_i);
	}
	void getReflectionRolloff_FloatValue()const
	{

		fprintf(mFile,"\"%s.rro.rrofv\"",mName.c_str());
	}
	void getReflectionRolloff_Interp(size_t rro_i)const
	{
		fprintf(mFile,"\"%s.rro[%i].rroi\"",mName.c_str(),rro_i);
	}
	void getReflectionRolloff_Interp()const
	{

		fprintf(mFile,"\"%s.rro.rroi\"",mName.c_str());
	}
	void getBranchReflectivity()const
	{
		fprintf(mFile,"\"%s.brf\"",mName.c_str());
	}
	void getLeafReflectivity()const
	{
		fprintf(mFile,"\"%s.lrf\"",mName.c_str());
	}
	void getFlowerReflectivity()const
	{
		fprintf(mFile,"\"%s.frf\"",mName.c_str());
	}
	void getForwardTwist()const
	{
		fprintf(mFile,"\"%s.fwt\"",mName.c_str());
	}
	void getLeafForwardTwist()const
	{
		fprintf(mFile,"\"%s.lfwt\"",mName.c_str());
	}
	void getPetalForwardTwist()const
	{
		fprintf(mFile,"\"%s.lpwt\"",mName.c_str());
	}
	void getEndCaps()const
	{
		fprintf(mFile,"\"%s.edc\"",mName.c_str());
	}
	void getHardEdges()const
	{
		fprintf(mFile,"\"%s.hde\"",mName.c_str());
	}
protected:
	Brush(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BRUSH_H__
