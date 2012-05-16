/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERGLOBALS_H__
#define __MayaDM_RENDERGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RenderGlobals : public DependNode
{
public:
public:

	RenderGlobals():DependNode(){}
	RenderGlobals(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "renderGlobals", shared, create){}
	virtual ~RenderGlobals(){}

	void setMacCodec(int macc)
	{
		if(macc == 1919706400) return;
		fprintf(mFile,"\tsetAttr \".macc\" %i;\n", macc);
	}
	void setMacDepth(int macd)
	{
		if(macd == 32) return;
		fprintf(mFile,"\tsetAttr \".macd\" %i;\n", macd);
	}
	void setMacQual(int macq)
	{
		if(macq == 1024) return;
		fprintf(mFile,"\tsetAttr \".macq\" %i;\n", macq);
	}
	void setComFrrt(int mcfr)
	{
		if(mcfr == 24) return;
		fprintf(mFile,"\tsetAttr \".mcfr\" %i;\n", mcfr);
	}
	void setIgnoreFilmGate(bool ifg)
	{
		if(ifg == true) return;
		fprintf(mFile,"\tsetAttr \".ifg\" %i;\n", ifg);
	}
	void setClipFinalShadedColor(bool clip)
	{
		if(clip == true) return;
		fprintf(mFile,"\tsetAttr \".clip\" %i;\n", clip);
	}
	void setEnableDepthMaps(bool edm)
	{
		if(edm == true) return;
		fprintf(mFile,"\tsetAttr \".edm\" %i;\n", edm);
	}
	void setEnableDefaultLight(bool edl)
	{
		if(edl == true) return;
		fprintf(mFile,"\tsetAttr \".edl\" %i;\n", edl);
	}
	void setCurrentRenderer(const string& ren)
	{
		if(ren == "mayaSoftware") return;
		fprintf(mFile,"\tsetAttr \".ren\" -type \"string\" ");
		ren.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEnableStrokeRender(bool esr)
	{
		if(esr == true) return;
		fprintf(mFile,"\tsetAttr \".esr\" %i;\n", esr);
	}
	void setOnlyRenderStrokes(bool ors)
	{
		if(ors == false) return;
		fprintf(mFile,"\tsetAttr \".ors\" %i;\n", ors);
	}
	void setStrokesDepthFile(const string& sdf)
	{
		if(sdf == "NULL") return;
		fprintf(mFile,"\tsetAttr \".sdf\" -type \"string\" ");
		sdf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImageFormat(unsigned int outf)
	{
		if(outf == 7) return;
		fprintf(mFile,"\tsetAttr \".outf\" %i;\n", outf);
	}
	void setImfPluginKey(const string& imfkey)
	{
		if(imfkey == "") return;
		fprintf(mFile,"\tsetAttr \".imfkey\" -type \"string\" ");
		imfkey.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGammaCorrection(float gama)
	{
		if(gama == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gama\" %f;\n", gama);
	}
	void setAnimation(bool an)
	{
		if(an == false) return;
		fprintf(mFile,"\tsetAttr \".an\" %i;\n", an);
	}
	void setAnimationRange(unsigned int ar)
	{
		if(ar == 1) return;
		fprintf(mFile,"\tsetAttr \".ar\" %i;\n", ar);
	}
	void setStartFrame(double fs)
	{
		if(fs == 1) return;
		fprintf(mFile,"\tsetAttr \".fs\" %f;\n", fs);
	}
	void setEndFrame(double ef)
	{
		if(ef == 1) return;
		fprintf(mFile,"\tsetAttr \".ef\" %f;\n", ef);
	}
	void setByFrameStep(float bfs)
	{
		if(bfs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bfs\" %f;\n", bfs);
	}
	void setModifyExtension(bool me)
	{
		if(me == false) return;
		fprintf(mFile,"\tsetAttr \".me\" %i;\n", me);
	}
	void setStartExtension(float se)
	{
		if(se == 1.0) return;
		fprintf(mFile,"\tsetAttr \".se\" %f;\n", se);
	}
	void setByExtension(float be)
	{
		if(be == 1.0) return;
		fprintf(mFile,"\tsetAttr \".be\" %f;\n", be);
	}
	void setExtensionPadding(int ep)
	{
		if(ep == 1) return;
		fprintf(mFile,"\tsetAttr \".ep\" %i;\n", ep);
	}
	void setFieldExtControl(unsigned int fec)
	{
		if(fec == 0) return;
		fprintf(mFile,"\tsetAttr \".fec\" %i;\n", fec);
	}
	void setOutFormatControl(unsigned int ofc)
	{
		if(ofc == 0) return;
		fprintf(mFile,"\tsetAttr \".ofc\" %i;\n", ofc);
	}
	void setOddFieldExt(const string& ofe)
	{
		if(ofe == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ofe\" -type \"string\" ");
		ofe.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEvenFieldExt(const string& efe)
	{
		if(efe == "NULL") return;
		fprintf(mFile,"\tsetAttr \".efe\" -type \"string\" ");
		efe.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOutFormatExt(const string& oft)
	{
		if(oft == "NULL") return;
		fprintf(mFile,"\tsetAttr \".oft\" -type \"string\" ");
		oft.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUseMayaFileName(bool umfn)
	{
		if(umfn == true) return;
		fprintf(mFile,"\tsetAttr \".umfn\" %i;\n", umfn);
	}
	void setUseFrameExt(bool ufe)
	{
		if(ufe == false) return;
		fprintf(mFile,"\tsetAttr \".ufe\" %i;\n", ufe);
	}
	void setPutFrameBeforeExt(bool pff)
	{
		if(pff == false) return;
		fprintf(mFile,"\tsetAttr \".pff\" %i;\n", pff);
	}
	void setPeriodInExt(unsigned int peie)
	{
		if(peie == 1) return;
		fprintf(mFile,"\tsetAttr \".peie\" %i;\n", peie);
	}
	void setImageFilePrefix(const string& ifp)
	{
		if(ifp == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ifp\" -type \"string\" ");
		ifp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRenderVersion(const string& rv)
	{
		if(rv == "NULL") return;
		fprintf(mFile,"\tsetAttr \".rv\" -type \"string\" ");
		rv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setComposite(bool comp)
	{
		if(comp == false) return;
		fprintf(mFile,"\tsetAttr \".comp\" %i;\n", comp);
	}
	void setCompositeThreshold(float cth)
	{
		if(cth == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cth\" %f;\n", cth);
	}
	void setShadowsObeyLightLinking(bool soll)
	{
		if(soll == true) return;
		fprintf(mFile,"\tsetAttr \".soll\" %i;\n", soll);
	}
	void setShadowsObeyShadowLinking(bool sosl)
	{
		if(sosl == false) return;
		fprintf(mFile,"\tsetAttr \".sosl\" %i;\n", sosl);
	}
	void setRecursionDepth(int rd)
	{
		if(rd == 2) return;
		fprintf(mFile,"\tsetAttr \".rd\" %i;\n", rd);
	}
	void setLeafPrimitives(int lp)
	{
		if(lp == 200) return;
		fprintf(mFile,"\tsetAttr \".lp\" %i;\n", lp);
	}
	void setSubdivisionPower(float sp)
	{
		if(sp == 0.25) return;
		fprintf(mFile,"\tsetAttr \".sp\" %f;\n", sp);
	}
	void setSubdivisionHashSize(int shs)
	{
		if(shs == 5) return;
		fprintf(mFile,"\tsetAttr \".shs\" %i;\n", shs);
	}
	void setLogRenderPerformance(bool lpr)
	{
		if(lpr == false) return;
		fprintf(mFile,"\tsetAttr \".lpr\" %i;\n", lpr);
	}
	void setGeometryVector(int gv)
	{
		if(gv == 20) return;
		fprintf(mFile,"\tsetAttr \".gv\" %i;\n", gv);
	}
	void setShadingVector(int sv)
	{
		if(sv == 60) return;
		fprintf(mFile,"\tsetAttr \".sv\" %i;\n", sv);
	}
	void setMaximumMemory(int mm)
	{
		if(mm == 48) return;
		fprintf(mFile,"\tsetAttr \".mm\" %i;\n", mm);
	}
	void setNumCpusToUse(int npu)
	{
		if(npu == 0) return;
		fprintf(mFile,"\tsetAttr \".npu\" %i;\n", npu);
	}
	void setInterruptFrequency(int itf)
	{
		if(itf == 1) return;
		fprintf(mFile,"\tsetAttr \".itf\" %i;\n", itf);
	}
	void setShadowPass(bool shp)
	{
		if(shp == false) return;
		fprintf(mFile,"\tsetAttr \".shp\" %i;\n", shp);
	}
	void setIprShadowPass(bool isp)
	{
		if(isp == false) return;
		fprintf(mFile,"\tsetAttr \".isp\" %i;\n", isp);
	}
	void setUseFileCache(bool uf)
	{
		if(uf == true) return;
		fprintf(mFile,"\tsetAttr \".uf\" %i;\n", uf);
	}
	void setOptimizeInstances(bool oi)
	{
		if(oi == true) return;
		fprintf(mFile,"\tsetAttr \".oi\" %i;\n", oi);
	}
	void setReuseTessellations(bool rut)
	{
		if(rut == true) return;
		fprintf(mFile,"\tsetAttr \".rut\" %i;\n", rut);
	}
	void setMatteOpacityUsesTransparency(bool mot)
	{
		if(mot == true) return;
		fprintf(mFile,"\tsetAttr \".mot\" %i;\n", mot);
	}
	void setMotionBlur(bool mb)
	{
		if(mb == false) return;
		fprintf(mFile,"\tsetAttr \".mb\" %i;\n", mb);
	}
	void setMotionBlurByFrame(float mbf)
	{
		if(mbf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mbf\" %f;\n", mbf);
	}
	void setApplyFogInPost(bool afp)
	{
		if(afp == false) return;
		fprintf(mFile,"\tsetAttr \".afp\" %i;\n", afp);
	}
	void setPostFogBlur(int pfb)
	{
		if(pfb == 1) return;
		fprintf(mFile,"\tsetAttr \".pfb\" %i;\n", pfb);
	}
	void setPreMel(const string& pram)
	{
		if(pram == "NULL") return;
		fprintf(mFile,"\tsetAttr \".pram\" -type \"string\" ");
		pram.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPostMel(const string& poam)
	{
		if(poam == "NULL") return;
		fprintf(mFile,"\tsetAttr \".poam\" -type \"string\" ");
		poam.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPreRenderLayerMel(const string& prlm)
	{
		if(prlm == "NULL") return;
		fprintf(mFile,"\tsetAttr \".prlm\" -type \"string\" ");
		prlm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPostRenderLayerMel(const string& polm)
	{
		if(polm == "NULL") return;
		fprintf(mFile,"\tsetAttr \".polm\" -type \"string\" ");
		polm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPreRenderMel(const string& prm)
	{
		if(prm == "NULL") return;
		fprintf(mFile,"\tsetAttr \".prm\" -type \"string\" ");
		prm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPostRenderMel(const string& pom)
	{
		if(pom == "NULL") return;
		fprintf(mFile,"\tsetAttr \".pom\" -type \"string\" ");
		pom.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPreFurRenderMel(const string& pfrm)
	{
		if(pfrm == "NULL") return;
		fprintf(mFile,"\tsetAttr \".pfrm\" -type \"string\" ");
		pfrm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPostFurRenderMel(const string& pfom)
	{
		if(pfom == "NULL") return;
		fprintf(mFile,"\tsetAttr \".pfom\" -type \"string\" ");
		pfom.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBlurLength(float bll)
	{
		if(bll == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bll\" %f;\n", bll);
	}
	void setBlurSharpness(float bls)
	{
		if(bls == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bls\" %f;\n", bls);
	}
	void setSmoothValue(int smv)
	{
		if(smv == 2) return;
		fprintf(mFile,"\tsetAttr \".smv\" %i;\n", smv);
	}
	void setUseBlur2DMemoryCap(bool ubc)
	{
		if(ubc == true) return;
		fprintf(mFile,"\tsetAttr \".ubc\" %i;\n", ubc);
	}
	void setBlur2DMemoryCap(float mbc)
	{
		if(mbc == 200.0) return;
		fprintf(mFile,"\tsetAttr \".mbc\" %f;\n", mbc);
	}
	void setMotionBlurType(unsigned int mbt)
	{
		if(mbt == 1) return;
		fprintf(mFile,"\tsetAttr \".mbt\" %i;\n", mbt);
	}
	void setUseDisplacementBoundingBox(bool udbx)
	{
		if(udbx == true) return;
		fprintf(mFile,"\tsetAttr \".udbx\" %i;\n", udbx);
	}
	void setSmoothColor(bool smc)
	{
		if(smc == false) return;
		fprintf(mFile,"\tsetAttr \".smc\" %i;\n", smc);
	}
	void setKeepMotionVector(bool kmv)
	{
		if(kmv == false) return;
		fprintf(mFile,"\tsetAttr \".kmv\" %i;\n", kmv);
	}
	void setIprRenderShading(bool isl)
	{
		if(isl == true) return;
		fprintf(mFile,"\tsetAttr \".isl\" %i;\n", isl);
	}
	void setIprRenderShadowMaps(bool ism)
	{
		if(ism == true) return;
		fprintf(mFile,"\tsetAttr \".ism\" %i;\n", ism);
	}
	void setIprRenderMotionBlur(bool imb)
	{
		if(imb == true) return;
		fprintf(mFile,"\tsetAttr \".imb\" %i;\n", imb);
	}
	void setRenderLayerEnable(bool rlen)
	{
		if(rlen == false) return;
		fprintf(mFile,"\tsetAttr \".rlen\" %i;\n", rlen);
	}
	void setForceTileSize(bool frts)
	{
		if(frts == false) return;
		fprintf(mFile,"\tsetAttr \".frts\" %i;\n", frts);
	}
	void setTileWidth(short tlwd)
	{
		if(tlwd == 64) return;
		fprintf(mFile,"\tsetAttr \".tlwd\" %i;\n", tlwd);
	}
	void setTileHeight(short tlht)
	{
		if(tlht == 64) return;
		fprintf(mFile,"\tsetAttr \".tlht\" %i;\n", tlht);
	}
	void setJitterFinalColor(bool jfc)
	{
		if(jfc == true) return;
		fprintf(mFile,"\tsetAttr \".jfc\" %i;\n", jfc);
	}
	void setRaysSeeBackground(bool rsb)
	{
		if(rsb == true) return;
		fprintf(mFile,"\tsetAttr \".rsb\" %i;\n", rsb);
	}
	void setOversamplePaintEffects(bool ope)
	{
		if(ope == false) return;
		fprintf(mFile,"\tsetAttr \".ope\" %i;\n", ope);
	}
	void setOversamplePfxPostFilter(bool oppf)
	{
		if(oppf == false) return;
		fprintf(mFile,"\tsetAttr \".oppf\" %i;\n", oppf);
	}
	void setHyperShadeBinList(const string& hbl)
	{
		if(hbl == "NULL") return;
		fprintf(mFile,"\tsetAttr \".hbl\" -type \"string\" ");
		hbl.write(mFile);
		fprintf(mFile,";\n");
	}
	void getMacCodec()const
	{
		fprintf(mFile,"\"%s.macc\"",mName.c_str());
	}
	void getMacDepth()const
	{
		fprintf(mFile,"\"%s.macd\"",mName.c_str());
	}
	void getMacQual()const
	{
		fprintf(mFile,"\"%s.macq\"",mName.c_str());
	}
	void getComFrrt()const
	{
		fprintf(mFile,"\"%s.mcfr\"",mName.c_str());
	}
	void getRenderAll()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getQuality()const
	{
		fprintf(mFile,"\"%s.qual\"",mName.c_str());
	}
	void getResolution()const
	{
		fprintf(mFile,"\"%s.res\"",mName.c_str());
	}
	void getClipFinalShadedColor()const
	{
		fprintf(mFile,"\"%s.clip\"",mName.c_str());
	}
	void getEnableDepthMaps()const
	{
		fprintf(mFile,"\"%s.edm\"",mName.c_str());
	}
	void getEnableDefaultLight()const
	{
		fprintf(mFile,"\"%s.edl\"",mName.c_str());
	}
	void getEnableStrokeRender()const
	{
		fprintf(mFile,"\"%s.esr\"",mName.c_str());
	}
	void getOnlyRenderStrokes()const
	{
		fprintf(mFile,"\"%s.ors\"",mName.c_str());
	}
	void getStrokesDepthFile()const
	{
		fprintf(mFile,"\"%s.sdf\"",mName.c_str());
	}
	void getImageFormat()const
	{
		fprintf(mFile,"\"%s.outf\"",mName.c_str());
	}
	void getImfPluginKey()const
	{
		fprintf(mFile,"\"%s.imfkey\"",mName.c_str());
	}
	void getGammaCorrection()const
	{
		fprintf(mFile,"\"%s.gama\"",mName.c_str());
	}
	void getTopRegion()const
	{
		fprintf(mFile,"\"%s.top\"",mName.c_str());
	}
	void getLeftRegion()const
	{
		fprintf(mFile,"\"%s.left\"",mName.c_str());
	}
	void getBottomRegion()const
	{
		fprintf(mFile,"\"%s.bot\"",mName.c_str());
	}
	void getRightRegion()const
	{
		fprintf(mFile,"\"%s.rght\"",mName.c_str());
	}
	void getUseRenderRegion()const
	{
		fprintf(mFile,"\"%s.urr\"",mName.c_str());
	}
	void getByFrame()const
	{
		fprintf(mFile,"\"%s.bf\"",mName.c_str());
	}
	void getByFrameStep()const
	{
		fprintf(mFile,"\"%s.bfs\"",mName.c_str());
	}
	void getByExtension()const
	{
		fprintf(mFile,"\"%s.be\"",mName.c_str());
	}
	void getFieldExtControl()const
	{
		fprintf(mFile,"\"%s.fec\"",mName.c_str());
	}
	void getOutFormatControl()const
	{
		fprintf(mFile,"\"%s.ofc\"",mName.c_str());
	}
	void getOddFieldExt()const
	{
		fprintf(mFile,"\"%s.ofe\"",mName.c_str());
	}
	void getEvenFieldExt()const
	{
		fprintf(mFile,"\"%s.efe\"",mName.c_str());
	}
	void getOutFormatExt()const
	{
		fprintf(mFile,"\"%s.oft\"",mName.c_str());
	}
	void getComposite()const
	{
		fprintf(mFile,"\"%s.comp\"",mName.c_str());
	}
	void getCompositeThreshold()const
	{
		fprintf(mFile,"\"%s.cth\"",mName.c_str());
	}
	void getShadowsObeyLightLinking()const
	{
		fprintf(mFile,"\"%s.soll\"",mName.c_str());
	}
	void getShadowsObeyShadowLinking()const
	{
		fprintf(mFile,"\"%s.sosl\"",mName.c_str());
	}
	void getRecursionDepth()const
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());
	}
	void getLeafPrimitives()const
	{
		fprintf(mFile,"\"%s.lp\"",mName.c_str());
	}
	void getSubdivisionPower()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getSubdivisionHashSize()const
	{
		fprintf(mFile,"\"%s.shs\"",mName.c_str());
	}
	void getLogRenderPerformance()const
	{
		fprintf(mFile,"\"%s.lpr\"",mName.c_str());
	}
	void getGeometryVector()const
	{
		fprintf(mFile,"\"%s.gv\"",mName.c_str());
	}
	void getShadingVector()const
	{
		fprintf(mFile,"\"%s.sv\"",mName.c_str());
	}
	void getMaximumMemory()const
	{
		fprintf(mFile,"\"%s.mm\"",mName.c_str());
	}
	void getNumCpusToUse()const
	{
		fprintf(mFile,"\"%s.npu\"",mName.c_str());
	}
	void getInterruptFrequency()const
	{
		fprintf(mFile,"\"%s.itf\"",mName.c_str());
	}
	void getShadowPass()const
	{
		fprintf(mFile,"\"%s.shp\"",mName.c_str());
	}
	void getIprShadowPass()const
	{
		fprintf(mFile,"\"%s.isp\"",mName.c_str());
	}
	void getUseFileCache()const
	{
		fprintf(mFile,"\"%s.uf\"",mName.c_str());
	}
	void getOptimizeInstances()const
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());
	}
	void getReuseTessellations()const
	{
		fprintf(mFile,"\"%s.rut\"",mName.c_str());
	}
	void getMatteOpacityUsesTransparency()const
	{
		fprintf(mFile,"\"%s.mot\"",mName.c_str());
	}
	void getMotionBlurByFrame()const
	{
		fprintf(mFile,"\"%s.mbf\"",mName.c_str());
	}
	void getFogGeometry()const
	{
		fprintf(mFile,"\"%s.fg\"",mName.c_str());
	}
	void getApplyFogInPost()const
	{
		fprintf(mFile,"\"%s.afp\"",mName.c_str());
	}
	void getPostFogBlur()const
	{
		fprintf(mFile,"\"%s.pfb\"",mName.c_str());
	}
	void getPreMel()const
	{
		fprintf(mFile,"\"%s.pram\"",mName.c_str());
	}
	void getPostMel()const
	{
		fprintf(mFile,"\"%s.poam\"",mName.c_str());
	}
	void getPreRenderLayerMel()const
	{
		fprintf(mFile,"\"%s.prlm\"",mName.c_str());
	}
	void getPostRenderLayerMel()const
	{
		fprintf(mFile,"\"%s.polm\"",mName.c_str());
	}
	void getPreRenderMel()const
	{
		fprintf(mFile,"\"%s.prm\"",mName.c_str());
	}
	void getPostRenderMel()const
	{
		fprintf(mFile,"\"%s.pom\"",mName.c_str());
	}
	void getPreFurRenderMel()const
	{
		fprintf(mFile,"\"%s.pfrm\"",mName.c_str());
	}
	void getPostFurRenderMel()const
	{
		fprintf(mFile,"\"%s.pfom\"",mName.c_str());
	}
	void getCreateIprFile()const
	{
		fprintf(mFile,"\"%s.cif\"",mName.c_str());
	}
	void getBlurLength()const
	{
		fprintf(mFile,"\"%s.bll\"",mName.c_str());
	}
	void getBlurSharpness()const
	{
		fprintf(mFile,"\"%s.bls\"",mName.c_str());
	}
	void getSmoothValue()const
	{
		fprintf(mFile,"\"%s.smv\"",mName.c_str());
	}
	void getUseBlur2DMemoryCap()const
	{
		fprintf(mFile,"\"%s.ubc\"",mName.c_str());
	}
	void getBlur2DMemoryCap()const
	{
		fprintf(mFile,"\"%s.mbc\"",mName.c_str());
	}
	void getUseDisplacementBoundingBox()const
	{
		fprintf(mFile,"\"%s.udbx\"",mName.c_str());
	}
	void getSmoothColor()const
	{
		fprintf(mFile,"\"%s.smc\"",mName.c_str());
	}
	void getKeepMotionVector()const
	{
		fprintf(mFile,"\"%s.kmv\"",mName.c_str());
	}
	void getIprRenderShading()const
	{
		fprintf(mFile,"\"%s.isl\"",mName.c_str());
	}
	void getIprRenderShadowMaps()const
	{
		fprintf(mFile,"\"%s.ism\"",mName.c_str());
	}
	void getIprRenderMotionBlur()const
	{
		fprintf(mFile,"\"%s.imb\"",mName.c_str());
	}
	void getRendercallback()const
	{
		fprintf(mFile,"\"%s.rcb\"",mName.c_str());
	}
	void getRenderLayerEnable()const
	{
		fprintf(mFile,"\"%s.rlen\"",mName.c_str());
	}
	void getForceTileSize()const
	{
		fprintf(mFile,"\"%s.frts\"",mName.c_str());
	}
	void getTileWidth()const
	{
		fprintf(mFile,"\"%s.tlwd\"",mName.c_str());
	}
	void getTileHeight()const
	{
		fprintf(mFile,"\"%s.tlht\"",mName.c_str());
	}
	void getJitterFinalColor()const
	{
		fprintf(mFile,"\"%s.jfc\"",mName.c_str());
	}
	void getRaysSeeBackground()const
	{
		fprintf(mFile,"\"%s.rsb\"",mName.c_str());
	}
	void getOversamplePaintEffects()const
	{
		fprintf(mFile,"\"%s.ope\"",mName.c_str());
	}
	void getOversamplePfxPostFilter()const
	{
		fprintf(mFile,"\"%s.oppf\"",mName.c_str());
	}
protected:
	RenderGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERGLOBALS_H__
