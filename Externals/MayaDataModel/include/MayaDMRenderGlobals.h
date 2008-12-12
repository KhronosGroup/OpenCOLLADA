/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
*/
class RenderGlobals : public DependNode
{
public:
public:
	RenderGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "renderGlobals"){}
	virtual ~RenderGlobals(){}
	/*Type of Codec on Mac.*/
	void setMacCodec(int macc){if(macc == 1919706400) return; fprintf_s(mFile, "setAttr \".macc\" %i;\n", macc);}
	/*Type of Codec on Mac.*/
	void setMacCodec(const IntID& macc){fprintf_s(mFile,"connectAttr \"");macc.write(mFile);fprintf_s(mFile,"\" \"%s.macc\";\n",mName.c_str());}
	/*Type of Codec on Mac.*/
	void setMacDepth(int macd){if(macd == 32) return; fprintf_s(mFile, "setAttr \".macd\" %i;\n", macd);}
	/*Type of Codec on Mac.*/
	void setMacDepth(const IntID& macd){fprintf_s(mFile,"connectAttr \"");macd.write(mFile);fprintf_s(mFile,"\" \"%s.macd\";\n",mName.c_str());}
	/*Type of Codec on Mac.*/
	void setMacQual(int macq){if(macq == 1024) return; fprintf_s(mFile, "setAttr \".macq\" %i;\n", macq);}
	/*Type of Codec on Mac.*/
	void setMacQual(const IntID& macq){fprintf_s(mFile,"connectAttr \"");macq.write(mFile);fprintf_s(mFile,"\" \"%s.macq\";\n",mName.c_str());}
	/*Frame rate information for compression*/
	void setComFrrt(int mcfr){if(mcfr == 24) return; fprintf_s(mFile, "setAttr \".mcfr\" %i;\n", mcfr);}
	/*Frame rate information for compression*/
	void setComFrrt(const IntID& mcfr){fprintf_s(mFile,"connectAttr \"");mcfr.write(mFile);fprintf_s(mFile,"\" \"%s.mcfr\";\n",mName.c_str());}
	/*Render all (1) or just render active (0).*/
	void setRenderAll(const BoolID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*If true, the film gate is respected if it intersects the viewport, if false, the film gate is ignored and every pixel is rendered.*/
	void setIgnoreFilmGate(bool ifg){if(ifg == true) return; fprintf_s(mFile, "setAttr \".ifg\" %i;\n", ifg);}
	/*The Quality to be used for this Render (the node at other end of this message plug is a renderQuality node).*/
	void setQuality(const MessageID& qual){fprintf_s(mFile,"connectAttr \"");qual.write(mFile);fprintf_s(mFile,"\" \"%s.qual\";\n",mName.c_str());}
	/*The Resolution to be used for this Render (the node at other end of this message plug is a resolution node).*/
	void setResolution(const MessageID& res){fprintf_s(mFile,"connectAttr \"");res.write(mFile);fprintf_s(mFile,"\" \"%s.res\";\n",mName.c_str());}
	/*if we should clamp the shader output*/
	void setClipFinalShadedColor(bool clip){if(clip == true) return; fprintf_s(mFile, "setAttr \".clip\" %i;\n", clip);}
	/*if we should clamp the shader output*/
	void setClipFinalShadedColor(const BoolID& clip){fprintf_s(mFile,"connectAttr \"");clip.write(mFile);fprintf_s(mFile,"\" \"%s.clip\";\n",mName.c_str());}
	/*Enable or Disable the depth map shadows.*/
	void setEnableDepthMaps(bool edm){if(edm == true) return; fprintf_s(mFile, "setAttr \".edm\" %i;\n", edm);}
	/*Enable or Disable the depth map shadows.*/
	void setEnableDepthMaps(const BoolID& edm){fprintf_s(mFile,"connectAttr \"");edm.write(mFile);fprintf_s(mFile,"\" \"%s.edm\";\n",mName.c_str());}
	/*Toggles whether a default light is created for rendering when there are no lights in the scene.*/
	void setEnableDefaultLight(bool edl){if(edl == true) return; fprintf_s(mFile, "setAttr \".edl\" %i;\n", edl);}
	/*Toggles whether a default light is created for rendering when there are no lights in the scene.*/
	void setEnableDefaultLight(const BoolID& edl){fprintf_s(mFile,"connectAttr \"");edl.write(mFile);fprintf_s(mFile,"\" \"%s.edl\";\n",mName.c_str());}
	/*Current renderer*/
	void setCurrentRenderer(const string& ren){if(ren == "mayaSoftware") return; fprintf_s(mFile, "setAttr \".ren\" -type \"string\" ");ren.write(mFile);fprintf_s(mFile,";\n");}
	/*Enable or Disable the rendering of Paint Effects Strokes. If true, the particle paint module must be present and there must be renderable strokes in the scene before it will really render the strokes.*/
	void setEnableStrokeRender(bool esr){if(esr == true) return; fprintf_s(mFile, "setAttr \".esr\" %i;\n", esr);}
	/*Enable or Disable the rendering of Paint Effects Strokes. If true, the particle paint module must be present and there must be renderable strokes in the scene before it will really render the strokes.*/
	void setEnableStrokeRender(const BoolID& esr){fprintf_s(mFile,"connectAttr \"");esr.write(mFile);fprintf_s(mFile,"\" \"%s.esr\";\n",mName.c_str());}
	/*Only render Paint Effects Strokes - no geometry, depth file must be specified.*/
	void setOnlyRenderStrokes(bool ors){if(ors == false) return; fprintf_s(mFile, "setAttr \".ors\" %i;\n", ors);}
	/*Only render Paint Effects Strokes - no geometry, depth file must be specified.*/
	void setOnlyRenderStrokes(const BoolID& ors){fprintf_s(mFile,"connectAttr \"");ors.write(mFile);fprintf_s(mFile,"\" \"%s.ors\";\n",mName.c_str());}
	/*If we are only rendering strokes, this depth file (plus possible extensions) is used for depth masking.*/
	void setStrokesDepthFile(const string& sdf){if(sdf == "NULL") return; fprintf_s(mFile, "setAttr \".sdf\" -type \"string\" ");sdf.write(mFile);fprintf_s(mFile,";\n");}
	/*If we are only rendering strokes, this depth file (plus possible extensions) is used for depth masking.*/
	void setStrokesDepthFile(const StringID& sdf){fprintf_s(mFile,"connectAttr \"");sdf.write(mFile);fprintf_s(mFile,"\" \"%s.sdf\";\n",mName.c_str());}
	/*
	Specifies the output image file format - choices:
	GIF (0), SI (1), RLA (2), Tiff (3), Tiff16 (4), SGI (5), Alias (6)
	IFF (7) JPEG (8) EPS (9) IFF16 (10) Cineon (11) Quantel (12)
	SGI16 (13) TARGA (19) BMP (20)
	SGIMV (21) QT (22) AVI (23)
	MACPAINT (30) PHOTOSHOP (31) PNG (32) QUICKDRAW (33)
	QTIMAGE (34) DDS (35) DDS (36)
	IMFplugin (50) Custom (51)
	SWF (60) AI (61) SVG (62) SWFT (63)
	*/
	void setImageFormat(unsigned int outf){if(outf == 7) return; fprintf_s(mFile, "setAttr \".outf\" %i;\n", outf);}
	/*
	Specifies the output image file format - choices:
	GIF (0), SI (1), RLA (2), Tiff (3), Tiff16 (4), SGI (5), Alias (6)
	IFF (7) JPEG (8) EPS (9) IFF16 (10) Cineon (11) Quantel (12)
	SGI16 (13) TARGA (19) BMP (20)
	SGIMV (21) QT (22) AVI (23)
	MACPAINT (30) PHOTOSHOP (31) PNG (32) QUICKDRAW (33)
	QTIMAGE (34) DDS (35) DDS (36)
	IMFplugin (50) Custom (51)
	SWF (60) AI (61) SVG (62) SWFT (63)
	*/
	void setImageFormat(const UnsignedintID& outf){fprintf_s(mFile,"connectAttr \"");outf.write(mFile);fprintf_s(mFile,"\" \"%s.outf\";\n",mName.c_str());}
	/*IMF plugin keyword*/
	void setImfPluginKey(const string& imfkey){if(imfkey == "") return; fprintf_s(mFile, "setAttr \".imfkey\" -type \"string\" ");imfkey.write(mFile);fprintf_s(mFile,";\n");}
	/*IMF plugin keyword*/
	void setImfPluginKey(const StringID& imfkey){fprintf_s(mFile,"connectAttr \"");imfkey.write(mFile);fprintf_s(mFile,"\" \"%s.imfkey\";\n",mName.c_str());}
	/*Gamma correction value.*/
	void setGammaCorrection(float gama){if(gama == 1.0) return; fprintf_s(mFile, "setAttr \".gama\" %f;\n", gama);}
	/*Gamma correction value.*/
	void setGammaCorrection(const FloatID& gama){fprintf_s(mFile,"connectAttr \"");gama.write(mFile);fprintf_s(mFile,"\" \"%s.gama\";\n",mName.c_str());}
	/*The top 2d coord of render region (for use if useRenderRegion is true).*/
	void setTopRegion(const IntID& top){fprintf_s(mFile,"connectAttr \"");top.write(mFile);fprintf_s(mFile,"\" \"%s.top\";\n",mName.c_str());}
	/*The left 2d coord of render region (for use if useRenderRegion is true).*/
	void setLeftRegion(const IntID& left){fprintf_s(mFile,"connectAttr \"");left.write(mFile);fprintf_s(mFile,"\" \"%s.left\";\n",mName.c_str());}
	/*The bottom 2d coord of render region (for use if useRenderRegion is true).*/
	void setBottomRegion(const IntID& bot){fprintf_s(mFile,"connectAttr \"");bot.write(mFile);fprintf_s(mFile,"\" \"%s.bot\";\n",mName.c_str());}
	/*The right 2d coord of render region (for use if useRenderRegion is true).*/
	void setRightRegion(const IntID& rght){fprintf_s(mFile,"connectAttr \"");rght.write(mFile);fprintf_s(mFile,"\" \"%s.rght\";\n",mName.c_str());}
	/*Use the render region (use the previous coordinates if true (1)).*/
	void setUseRenderRegion(const BoolID& urr){fprintf_s(mFile,"connectAttr \"");urr.write(mFile);fprintf_s(mFile,"\" \"%s.urr\";\n",mName.c_str());}
	/*Render an animation (if true) or just the current frame (if false).*/
	void setAnimation(bool an){if(an == false) return; fprintf_s(mFile, "setAttr \".an\" %i;\n", an);}
	/*Use the frame range from renderGlobals (0), or time slider (1).*/
	void setAnimationRange(unsigned int ar){if(ar == 1) return; fprintf_s(mFile, "setAttr \".ar\" %i;\n", ar);}
	/*The renderGlobals frame step ('by' or increment) value.  This is no longer used, but kept for backwards compatibility.*/
	void setByFrame(const TimeID& bf){fprintf_s(mFile,"connectAttr \"");bf.write(mFile);fprintf_s(mFile,"\" \"%s.bf\";\n",mName.c_str());}
	/*Unitless (floating point) by frame.*/
	void setByFrameStep(float bfs){if(bfs == 1.0) return; fprintf_s(mFile, "setAttr \".bfs\" %f;\n", bfs);}
	/*Unitless (floating point) by frame.*/
	void setByFrameStep(const FloatID& bfs){fprintf_s(mFile,"connectAttr \"");bfs.write(mFile);fprintf_s(mFile,"\" \"%s.bfs\";\n",mName.c_str());}
	/*Should start and by output image filename extension modifiers be used? (false-> use the current frame value as the filename extension, true->use startExtension + ((currentFrame-startFrame)/byFrame) * byExtension value as the filename extension).*/
	void setModifyExtension(bool me){if(me == false) return; fprintf_s(mFile, "setAttr \".me\" %i;\n", me);}
	/*The starting output image filename extension value.*/
	void setStartExtension(float se){if(se == 1.0) return; fprintf_s(mFile, "setAttr \".se\" %f;\n", se);}
	/*The output image filename extension step ('by' or increment) value.*/
	void setByExtension(float be){if(be == 1.0) return; fprintf_s(mFile, "setAttr \".be\" %f;\n", be);}
	/*The output image filename extension step ('by' or increment) value.*/
	void setByExtension(const FloatID& be){fprintf_s(mFile,"connectAttr \"");be.write(mFile);fprintf_s(mFile,"\" \"%s.be\";\n",mName.c_str());}
	/*The number of digits in the output image filename extension (3 -> "image.001").*/
	void setExtensionPadding(int ep){if(ep == 1) return; fprintf_s(mFile, "setAttr \".ep\" %i;\n", ep);}
	/*Controls the type of filename extension to be used for fields: o/e (0), no extension (Caution! Do not use with when interlace set to 'both'.) (1), user input (2)*/
	void setFieldExtControl(unsigned int fec){if(fec == 0) return; fprintf_s(mFile, "setAttr \".fec\" %i;\n", fec);}
	/*Controls the type of filename extension to be used for fields: o/e (0), no extension (Caution! Do not use with when interlace set to 'both'.) (1), user input (2)*/
	void setFieldExtControl(const UnsignedintID& fec){fprintf_s(mFile,"connectAttr \"");fec.write(mFile);fprintf_s(mFile,"\" \"%s.fec\";\n",mName.c_str());}
	/*Controls the type of filename format to be used for image files: use the default 'out format' abbreviation (0), no image file format type (1), user input (2)*/
	void setOutFormatControl(unsigned int ofc){if(ofc == 0) return; fprintf_s(mFile, "setAttr \".ofc\" %i;\n", ofc);}
	/*Controls the type of filename format to be used for image files: use the default 'out format' abbreviation (0), no image file format type (1), user input (2)*/
	void setOutFormatControl(const UnsignedintID& ofc){fprintf_s(mFile,"connectAttr \"");ofc.write(mFile);fprintf_s(mFile,"\" \"%s.ofc\";\n",mName.c_str());}
	/*The user specified odd field extension if aFieldExtControl = 2*/
	void setOddFieldExt(const string& ofe){if(ofe == "NULL") return; fprintf_s(mFile, "setAttr \".ofe\" -type \"string\" ");ofe.write(mFile);fprintf_s(mFile,";\n");}
	/*The user specified odd field extension if aFieldExtControl = 2*/
	void setOddFieldExt(const StringID& ofe){fprintf_s(mFile,"connectAttr \"");ofe.write(mFile);fprintf_s(mFile,"\" \"%s.ofe\";\n",mName.c_str());}
	/*The user specified even field extension if aFieldExtControl = 2*/
	void setEvenFieldExt(const string& efe){if(efe == "NULL") return; fprintf_s(mFile, "setAttr \".efe\" -type \"string\" ");efe.write(mFile);fprintf_s(mFile,";\n");}
	/*The user specified even field extension if aFieldExtControl = 2*/
	void setEvenFieldExt(const StringID& efe){fprintf_s(mFile,"connectAttr \"");efe.write(mFile);fprintf_s(mFile,"\" \"%s.efe\";\n",mName.c_str());}
	/*The string added at the end of the file name if aOutFormatControl = 2*/
	void setOutFormatExt(const string& oft){if(oft == "NULL") return; fprintf_s(mFile, "setAttr \".oft\" -type \"string\" ");oft.write(mFile);fprintf_s(mFile,";\n");}
	/*The string added at the end of the file name if aOutFormatControl = 2*/
	void setOutFormatExt(const StringID& oft){fprintf_s(mFile,"connectAttr \"");oft.write(mFile);fprintf_s(mFile,"\" \"%s.oft\";\n",mName.c_str());}
	/*If the maya file name is to be concatenated with the output file.*/
	void setUseMayaFileName(bool umfn){if(umfn == true) return; fprintf_s(mFile, "setAttr \".umfn\" %i;\n", umfn);}
	/*If the frame extension is to be concatenated with the output file.*/
	void setUseFrameExt(bool ufe){if(ufe == false) return; fprintf_s(mFile, "setAttr \".ufe\" %i;\n", ufe);}
	/*Should frame number precede the output type extension in file name?*/
	void setPutFrameBeforeExt(bool pff){if(pff == false) return; fprintf_s(mFile, "setAttr \".pff\" %i;\n", pff);}
	/*Controls the character between the filename and the file extension: no such character (0), a period (1), or an underscore (2).*/
	void setPeriodInExt(unsigned int peie){if(peie == 1) return; fprintf_s(mFile, "setAttr \".peie\" %i;\n", peie);}
	/*String that forms the prefix of each output image file name*/
	void setImageFilePrefix(const string& ifp){if(ifp == "NULL") return; fprintf_s(mFile, "setAttr \".ifp\" -type \"string\" ");ifp.write(mFile);fprintf_s(mFile,";\n");}
	/*String that labels versions of rendered images*/
	void setRenderVersion(const string& rv){if(rv == "NULL") return; fprintf_s(mFile, "setAttr \".rv\" -type \"string\" ");rv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Compositing rendering; Do not blend alpha with image color.
	(unassociated alpha)
	*/
	void setComposite(bool comp){if(comp == false) return; fprintf_s(mFile, "setAttr \".comp\" %i;\n", comp);}
	/*
	Compositing rendering; Do not blend alpha with image color.
	(unassociated alpha)
	*/
	void setComposite(const BoolID& comp){fprintf_s(mFile,"connectAttr \"");comp.write(mFile);fprintf_s(mFile,"\" \"%s.comp\";\n",mName.c_str());}
	/*Mainly for games support. The percentage of a pixel which must be covered by the object before the alpha should consider it part of the object. Animation customers should leave this at 0.0.*/
	void setCompositeThreshold(float cth){if(cth == 0.0) return; fprintf_s(mFile, "setAttr \".cth\" %f;\n", cth);}
	/*Mainly for games support. The percentage of a pixel which must be covered by the object before the alpha should consider it part of the object. Animation customers should leave this at 0.0.*/
	void setCompositeThreshold(const FloatID& cth){fprintf_s(mFile,"connectAttr \"");cth.write(mFile);fprintf_s(mFile,"\" \"%s.cth\";\n",mName.c_str());}
	/*Objects not lit by a light will not cast shadow from that light*/
	void setShadowsObeyLightLinking(bool soll){if(soll == true) return; fprintf_s(mFile, "setAttr \".soll\" %i;\n", soll);}
	/*Objects not lit by a light will not cast shadow from that light*/
	void setShadowsObeyLightLinking(const BoolID& soll){fprintf_s(mFile,"connectAttr \"");soll.write(mFile);fprintf_s(mFile,"\" \"%s.soll\";\n",mName.c_str());}
	/*Objects not shadow linked to a light will not cast shadow from that light*/
	void setShadowsObeyShadowLinking(bool sosl){if(sosl == false) return; fprintf_s(mFile, "setAttr \".sosl\" %i;\n", sosl);}
	/*Objects not shadow linked to a light will not cast shadow from that light*/
	void setShadowsObeyShadowLinking(const BoolID& sosl){fprintf_s(mFile,"connectAttr \"");sosl.write(mFile);fprintf_s(mFile,"\" \"%s.sosl\";\n",mName.c_str());}
	/*Recursion depth for ray tracing. (for spatial subdivision 0,1,2,3 - useful range)*/
	void setRecursionDepth(int rd){if(rd == 2) return; fprintf_s(mFile, "setAttr \".rd\" %i;\n", rd);}
	/*Recursion depth for ray tracing. (for spatial subdivision 0,1,2,3 - useful range)*/
	void setRecursionDepth(const IntID& rd){fprintf_s(mFile,"connectAttr \"");rd.write(mFile);fprintf_s(mFile,"\" \"%s.rd\";\n",mName.c_str());}
	/*Max number of primitives per leaf in raytracing subdivision*/
	void setLeafPrimitives(int lp){if(lp == 200) return; fprintf_s(mFile, "setAttr \".lp\" %i;\n", lp);}
	/*Max number of primitives per leaf in raytracing subdivision*/
	void setLeafPrimitives(const IntID& lp){fprintf_s(mFile,"connectAttr \"");lp.write(mFile);fprintf_s(mFile,"\" \"%s.lp\";\n",mName.c_str());}
	/*The power of the number of primitives to regulate axial subdivision*/
	void setSubdivisionPower(float sp){if(sp == 0.25) return; fprintf_s(mFile, "setAttr \".sp\" %f;\n", sp);}
	/*The power of the number of primitives to regulate axial subdivision*/
	void setSubdivisionPower(const FloatID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*The minimum hash table size for a subdivsion node*/
	void setSubdivisionHashSize(int shs){if(shs == 5) return; fprintf_s(mFile, "setAttr \".shs\" %i;\n", shs);}
	/*The minimum hash table size for a subdivsion node*/
	void setSubdivisionHashSize(const IntID& shs){fprintf_s(mFile,"connectAttr \"");shs.write(mFile);fprintf_s(mFile,"\" \"%s.shs\";\n",mName.c_str());}
	/*Do we write a performance log or not*/
	void setLogRenderPerformance(bool lpr){if(lpr == false) return; fprintf_s(mFile, "setAttr \".lpr\" %i;\n", lpr);}
	/*Do we write a performance log or not*/
	void setLogRenderPerformance(const BoolID& lpr){fprintf_s(mFile,"connectAttr \"");lpr.write(mFile);fprintf_s(mFile,"\" \"%s.lpr\";\n",mName.c_str());}
	/*Vector length for geometry samples.*/
	void setGeometryVector(int gv){if(gv == 20) return; fprintf_s(mFile, "setAttr \".gv\" %i;\n", gv);}
	/*Vector length for geometry samples.*/
	void setGeometryVector(const IntID& gv){fprintf_s(mFile,"connectAttr \"");gv.write(mFile);fprintf_s(mFile,"\" \"%s.gv\";\n",mName.c_str());}
	/*Vector length for shading samples.*/
	void setShadingVector(int sv){if(sv == 60) return; fprintf_s(mFile, "setAttr \".sv\" %i;\n", sv);}
	/*Vector length for shading samples.*/
	void setShadingVector(const IntID& sv){fprintf_s(mFile,"connectAttr \"");sv.write(mFile);fprintf_s(mFile,"\" \"%s.sv\";\n",mName.c_str());}
	/*Maximum memory (in megabytes) to be used by the renderer.*/
	void setMaximumMemory(int mm){if(mm == 48) return; fprintf_s(mFile, "setAttr \".mm\" %i;\n", mm);}
	/*Maximum memory (in megabytes) to be used by the renderer.*/
	void setMaximumMemory(const IntID& mm){fprintf_s(mFile,"connectAttr \"");mm.write(mFile);fprintf_s(mFile,"\" \"%s.mm\";\n",mName.c_str());}
	/*Number of cpus to use for rendering or IPR (0 means use all).*/
	void setNumCpusToUse(int npu){if(npu == 0) return; fprintf_s(mFile, "setAttr \".npu\" %i;\n", npu);}
	/*Number of cpus to use for rendering or IPR (0 means use all).*/
	void setNumCpusToUse(const IntID& npu){fprintf_s(mFile,"connectAttr \"");npu.write(mFile);fprintf_s(mFile,"\" \"%s.npu\";\n",mName.c_str());}
	/*
	Number of seconds between checks for user interrupt. A value of
	-1 will disable interrupt checking.
	*/
	void setInterruptFrequency(int itf){if(itf == 1) return; fprintf_s(mFile, "setAttr \".itf\" %i;\n", itf);}
	/*
	Number of seconds between checks for user interrupt. A value of
	-1 will disable interrupt checking.
	*/
	void setInterruptFrequency(const IntID& itf){fprintf_s(mFile,"connectAttr \"");itf.write(mFile);fprintf_s(mFile,"\" \"%s.itf\";\n",mName.c_str());}
	/*Whether we want to just do the shadow depth map pass.*/
	void setShadowPass(bool shp){if(shp == false) return; fprintf_s(mFile, "setAttr \".shp\" %i;\n", shp);}
	/*Whether we want to just do the shadow depth map pass.*/
	void setShadowPass(const BoolID& shp){fprintf_s(mFile,"connectAttr \"");shp.write(mFile);fprintf_s(mFile,"\" \"%s.shp\";\n",mName.c_str());}
	/*Whether we want to just do the ipr shadow depth map pass.*/
	void setIprShadowPass(bool isp){if(isp == false) return; fprintf_s(mFile, "setAttr \".isp\" %i;\n", isp);}
	/*Whether we want to just do the ipr shadow depth map pass.*/
	void setIprShadowPass(const BoolID& isp){fprintf_s(mFile,"connectAttr \"");isp.write(mFile);fprintf_s(mFile,"\" \"%s.isp\";\n",mName.c_str());}
	/*When true, render swappable objects (ie. tessellations or RT voxels) can be stored on disk in the swap file. If false, tessellations and voxels are deleted and recomputed when needed.*/
	void setUseFileCache(bool uf){if(uf == true) return; fprintf_s(mFile, "setAttr \".uf\" %i;\n", uf);}
	/*When true, render swappable objects (ie. tessellations or RT voxels) can be stored on disk in the swap file. If false, tessellations and voxels are deleted and recomputed when needed.*/
	void setUseFileCache(const BoolID& uf){fprintf_s(mFile,"connectAttr \"");uf.write(mFile);fprintf_s(mFile,"\" \"%s.uf\";\n",mName.c_str());}
	/*When true, the renderer attempts to recognize similarly tesselated shapes.*/
	void setOptimizeInstances(bool oi){if(oi == true) return; fprintf_s(mFile, "setAttr \".oi\" %i;\n", oi);}
	/*When true, the renderer attempts to recognize similarly tesselated shapes.*/
	void setOptimizeInstances(const BoolID& oi){fprintf_s(mFile,"connectAttr \"");oi.write(mFile);fprintf_s(mFile,"\" \"%s.oi\";\n",mName.c_str());}
	/*When true, the rendered tessellations are used during the shadow map generation phase.*/
	void setReuseTessellations(bool rut){if(rut == true) return; fprintf_s(mFile, "setAttr \".rut\" %i;\n", rut);}
	/*When true, the rendered tessellations are used during the shadow map generation phase.*/
	void setReuseTessellations(const BoolID& rut){fprintf_s(mFile,"connectAttr \"");rut.write(mFile);fprintf_s(mFile,"\" \"%s.rut\";\n",mName.c_str());}
	/*Composite matte using scene transparency rather that residual matte transparency.*/
	void setMatteOpacityUsesTransparency(bool mot){if(mot == true) return; fprintf_s(mFile, "setAttr \".mot\" %i;\n", mot);}
	/*Composite matte using scene transparency rather that residual matte transparency.*/
	void setMatteOpacityUsesTransparency(const BoolID& mot){fprintf_s(mFile,"connectAttr \"");mot.write(mFile);fprintf_s(mFile,"\" \"%s.mot\";\n",mName.c_str());}
	/*Do not (0) or do render using motion blur (1).*/
	void setMotionBlur(bool mb){if(mb == false) return; fprintf_s(mFile, "setAttr \".mb\" %i;\n", mb);}
	/*Use this as the by frame in conjunction with shutterAngle (instead of byFrame) to compute the shutterOpen, shutterMid, and shutterClose frame times.*/
	void setMotionBlurByFrame(float mbf){if(mbf == 1.0) return; fprintf_s(mFile, "setAttr \".mbf\" %f;\n", mbf);}
	/*Use this as the by frame in conjunction with shutterAngle (instead of byFrame) to compute the shutterOpen, shutterMid, and shutterClose frame times.*/
	void setMotionBlurByFrame(const FloatID& mbf){fprintf_s(mFile,"connectAttr \"");mbf.write(mFile);fprintf_s(mFile,"\" \"%s.mbf\";\n",mName.c_str());}
	/*Connect this to the fog geometry.*/
	void setFogGeometry(const MessageID& fg){fprintf_s(mFile,"connectAttr \"");fg.write(mFile);fprintf_s(mFile,"\" \"%s.fg\";\n",mName.c_str());}
	/*Render and composite fog using depthbuffer at end of normal render (paint effects must be loaded)*/
	void setApplyFogInPost(bool afp){if(afp == false) return; fprintf_s(mFile, "setAttr \".afp\" %i;\n", afp);}
	/*Render and composite fog using depthbuffer at end of normal render (paint effects must be loaded)*/
	void setApplyFogInPost(const BoolID& afp){fprintf_s(mFile,"connectAttr \"");afp.write(mFile);fprintf_s(mFile,"\" \"%s.afp\";\n",mName.c_str());}
	/*blurring of fog into foreground applied before compositing on scene (only if applyFogInPost is on)*/
	void setPostFogBlur(int pfb){if(pfb == 1) return; fprintf_s(mFile, "setAttr \".pfb\" %i;\n", pfb);}
	/*blurring of fog into foreground applied before compositing on scene (only if applyFogInPost is on)*/
	void setPostFogBlur(const IntID& pfb){fprintf_s(mFile,"connectAttr \"");pfb.write(mFile);fprintf_s(mFile,"\" \"%s.pfb\";\n",mName.c_str());}
	/*MEL function to be called just before rendering*/
	void setPreMel(const string& pram){if(pram == "NULL") return; fprintf_s(mFile, "setAttr \".pram\" -type \"string\" ");pram.write(mFile);fprintf_s(mFile,";\n");}
	/*MEL function to be called just before rendering*/
	void setPreMel(const StringID& pram){fprintf_s(mFile,"connectAttr \"");pram.write(mFile);fprintf_s(mFile,"\" \"%s.pram\";\n",mName.c_str());}
	/*MEL function to be called just after rendering*/
	void setPostMel(const string& poam){if(poam == "NULL") return; fprintf_s(mFile, "setAttr \".poam\" -type \"string\" ");poam.write(mFile);fprintf_s(mFile,";\n");}
	/*MEL function to be called just after rendering*/
	void setPostMel(const StringID& poam){fprintf_s(mFile,"connectAttr \"");poam.write(mFile);fprintf_s(mFile,"\" \"%s.poam\";\n",mName.c_str());}
	/*MEL function to be called just before rendering of each render layer*/
	void setPreRenderLayerMel(const string& prlm){if(prlm == "NULL") return; fprintf_s(mFile, "setAttr \".prlm\" -type \"string\" ");prlm.write(mFile);fprintf_s(mFile,";\n");}
	/*MEL function to be called just before rendering of each render layer*/
	void setPreRenderLayerMel(const StringID& prlm){fprintf_s(mFile,"connectAttr \"");prlm.write(mFile);fprintf_s(mFile,"\" \"%s.prlm\";\n",mName.c_str());}
	/*MEL function to be called just after rendering of each render layer*/
	void setPostRenderLayerMel(const string& polm){if(polm == "NULL") return; fprintf_s(mFile, "setAttr \".polm\" -type \"string\" ");polm.write(mFile);fprintf_s(mFile,";\n");}
	/*MEL function to be called just after rendering of each render layer*/
	void setPostRenderLayerMel(const StringID& polm){fprintf_s(mFile,"connectAttr \"");polm.write(mFile);fprintf_s(mFile,"\" \"%s.polm\";\n",mName.c_str());}
	/*MEL function to be called just before rendering each frame*/
	void setPreRenderMel(const string& prm){if(prm == "NULL") return; fprintf_s(mFile, "setAttr \".prm\" -type \"string\" ");prm.write(mFile);fprintf_s(mFile,";\n");}
	/*MEL function to be called just before rendering each frame*/
	void setPreRenderMel(const StringID& prm){fprintf_s(mFile,"connectAttr \"");prm.write(mFile);fprintf_s(mFile,"\" \"%s.prm\";\n",mName.c_str());}
	/*MEL function to be called just after rendering each frame*/
	void setPostRenderMel(const string& pom){if(pom == "NULL") return; fprintf_s(mFile, "setAttr \".pom\" -type \"string\" ");pom.write(mFile);fprintf_s(mFile,";\n");}
	/*MEL function to be called just after rendering each frame*/
	void setPostRenderMel(const StringID& pom){fprintf_s(mFile,"connectAttr \"");pom.write(mFile);fprintf_s(mFile,"\" \"%s.pom\";\n",mName.c_str());}
	/*MEL function to be called just before rendering of current fur frame*/
	void setPreFurRenderMel(const string& pfrm){if(pfrm == "NULL") return; fprintf_s(mFile, "setAttr \".pfrm\" -type \"string\" ");pfrm.write(mFile);fprintf_s(mFile,";\n");}
	/*MEL function to be called just before rendering of current fur frame*/
	void setPreFurRenderMel(const StringID& pfrm){fprintf_s(mFile,"connectAttr \"");pfrm.write(mFile);fprintf_s(mFile,"\" \"%s.pfrm\";\n",mName.c_str());}
	/*MEL function to be called just after rendering of current fur frame*/
	void setPostFurRenderMel(const string& pfom){if(pfom == "NULL") return; fprintf_s(mFile, "setAttr \".pfom\" -type \"string\" ");pfom.write(mFile);fprintf_s(mFile,";\n");}
	/*MEL function to be called just after rendering of current fur frame*/
	void setPostFurRenderMel(const StringID& pfom){fprintf_s(mFile,"connectAttr \"");pfom.write(mFile);fprintf_s(mFile,"\" \"%s.pfom\";\n",mName.c_str());}
	/*Create an IPR file.*/
	void setCreateIprFile(const BoolID& cif){fprintf_s(mFile,"connectAttr \"");cif.write(mFile);fprintf_s(mFile,"\" \"%s.cif\";\n",mName.c_str());}
	/*This is the scale applied on the motion vectors.*/
	void setBlurLength(float bll){if(bll == 1.0) return; fprintf_s(mFile, "setAttr \".bll\" %f;\n", bll);}
	/*This is the scale applied on the motion vectors.*/
	void setBlurLength(const FloatID& bll){fprintf_s(mFile,"connectAttr \"");bll.write(mFile);fprintf_s(mFile,"\" \"%s.bll\";\n",mName.c_str());}
	/*The higher the value, the sharper the blur. The lower the value, the softer the blur.*/
	void setBlurSharpness(float bls){if(bls == 1.0) return; fprintf_s(mFile, "setAttr \".bls\" %f;\n", bls);}
	/*The higher the value, the sharper the blur. The lower the value, the softer the blur.*/
	void setBlurSharpness(const FloatID& bls){fprintf_s(mFile,"connectAttr \"");bls.write(mFile);fprintf_s(mFile,"\" \"%s.bls\";\n",mName.c_str());}
	/*The higher the value, the more anti-aliased the alpha channel.*/
	void setSmoothValue(int smv){if(smv == 2) return; fprintf_s(mFile, "setAttr \".smv\" %i;\n", smv);}
	/*The higher the value, the more anti-aliased the alpha channel.*/
	void setSmoothValue(const IntID& smv){fprintf_s(mFile,"connectAttr \"");smv.write(mFile);fprintf_s(mFile,"\" \"%s.smv\";\n",mName.c_str());}
	/*Enables an absolute memory limit for the 2d blur operation (limit given by the 'blur2DMemoryCap' attribute)*/
	void setUseBlur2DMemoryCap(bool ubc){if(ubc == true) return; fprintf_s(mFile, "setAttr \".ubc\" %i;\n", ubc);}
	/*Enables an absolute memory limit for the 2d blur operation (limit given by the 'blur2DMemoryCap' attribute)*/
	void setUseBlur2DMemoryCap(const BoolID& ubc){fprintf_s(mFile,"connectAttr \"");ubc.write(mFile);fprintf_s(mFile,"\" \"%s.ubc\";\n",mName.c_str());}
	/*Absolute memory limit for the 2d blur operation*/
	void setBlur2DMemoryCap(float mbc){if(mbc == 200.0) return; fprintf_s(mFile, "setAttr \".mbc\" %f;\n", mbc);}
	/*Absolute memory limit for the 2d blur operation*/
	void setBlur2DMemoryCap(const FloatID& mbc){fprintf_s(mFile,"connectAttr \"");mbc.write(mFile);fprintf_s(mFile,"\" \"%s.mbc\";\n",mName.c_str());}
	/*Do 2D (0), or 3D (1) motion blur.*/
	void setMotionBlurType(unsigned int mbt){if(mbt == 1) return; fprintf_s(mFile, "setAttr \".mbt\" %i;\n", mbt);}
	/*When true, the bounding box scale is used to predict a bounding box for displacement-mapped objects. If false, all displacment-mapped objects are pre-tessellated to find their bounding boxes.*/
	void setUseDisplacementBoundingBox(bool udbx){if(udbx == true) return; fprintf_s(mFile, "setAttr \".udbx\" %i;\n", udbx);}
	/*When true, the bounding box scale is used to predict a bounding box for displacement-mapped objects. If false, all displacment-mapped objects are pre-tessellated to find their bounding boxes.*/
	void setUseDisplacementBoundingBox(const BoolID& udbx){fprintf_s(mFile,"connectAttr \"");udbx.write(mFile);fprintf_s(mFile,"\" \"%s.udbx\";\n",mName.c_str());}
	/*When true, the color channels will be smoothened during the 2.5D motion blur just as the mask channel. If false, only the mask channel is smoothened and the color channels are scaled based on the mask change.*/
	void setSmoothColor(bool smc){if(smc == false) return; fprintf_s(mFile, "setAttr \".smc\" %i;\n", smc);}
	/*When true, the color channels will be smoothened during the 2.5D motion blur just as the mask channel. If false, only the mask channel is smoothened and the color channels are scaled based on the mask change.*/
	void setSmoothColor(const BoolID& smc){fprintf_s(mFile,"connectAttr \"");smc.write(mFile);fprintf_s(mFile,"\" \"%s.smc\";\n",mName.c_str());}
	/*When true, the motion vector file generated from 2.5D motion blur will be kept. If false, the motion vector file generated from 2.5D motion blur is deleted after the blur is computed.*/
	void setKeepMotionVector(bool kmv){if(kmv == false) return; fprintf_s(mFile, "setAttr \".kmv\" %i;\n", kmv);}
	/*When true, the motion vector file generated from 2.5D motion blur will be kept. If false, the motion vector file generated from 2.5D motion blur is deleted after the blur is computed.*/
	void setKeepMotionVector(const BoolID& kmv){fprintf_s(mFile,"connectAttr \"");kmv.write(mFile);fprintf_s(mFile,"\" \"%s.kmv\";\n",mName.c_str());}
	/*Create an IPR file containing shading, lighting, and glow.*/
	void setIprRenderShading(bool isl){if(isl == true) return; fprintf_s(mFile, "setAttr \".isl\" %i;\n", isl);}
	/*Create an IPR file containing shading, lighting, and glow.*/
	void setIprRenderShading(const BoolID& isl){fprintf_s(mFile,"connectAttr \"");isl.write(mFile);fprintf_s(mFile,"\" \"%s.isl\";\n",mName.c_str());}
	/*Create an IPR file containing shadow maps.*/
	void setIprRenderShadowMaps(bool ism){if(ism == true) return; fprintf_s(mFile, "setAttr \".ism\" %i;\n", ism);}
	/*Create an IPR file containing shadow maps.*/
	void setIprRenderShadowMaps(const BoolID& ism){fprintf_s(mFile,"connectAttr \"");ism.write(mFile);fprintf_s(mFile,"\" \"%s.ism\";\n",mName.c_str());}
	/*Create an IPR file containint motion blur.*/
	void setIprRenderMotionBlur(bool imb){if(imb == true) return; fprintf_s(mFile, "setAttr \".imb\" %i;\n", imb);}
	/*Create an IPR file containint motion blur.*/
	void setIprRenderMotionBlur(const BoolID& imb){fprintf_s(mFile,"connectAttr \"");imb.write(mFile);fprintf_s(mFile,"\" \"%s.imb\";\n",mName.c_str());}
	/*The Render callback to be used for this Render (the node at other end of this message plug is a render callback node)*/
	void setRendercallback(const MessageID& rcb){fprintf_s(mFile,"connectAttr \"");rcb.write(mFile);fprintf_s(mFile,"\" \"%s.rcb\";\n",mName.c_str());}
	/*Render out multiple layers*/
	void setRenderLayerEnable(bool rlen){if(rlen == false) return; fprintf_s(mFile, "setAttr \".rlen\" %i;\n", rlen);}
	/*Render out multiple layers*/
	void setRenderLayerEnable(const BoolID& rlen){fprintf_s(mFile,"connectAttr \"");rlen.write(mFile);fprintf_s(mFile,"\" \"%s.rlen\";\n",mName.c_str());}
	/*Should the tile size be forced?*/
	void setForceTileSize(bool frts){if(frts == false) return; fprintf_s(mFile, "setAttr \".frts\" %i;\n", frts);}
	/*Should the tile size be forced?*/
	void setForceTileSize(const BoolID& frts){fprintf_s(mFile,"connectAttr \"");frts.write(mFile);fprintf_s(mFile,"\" \"%s.frts\";\n",mName.c_str());}
	/*Tile width.*/
	void setTileWidth(short tlwd){if(tlwd == 64) return; fprintf_s(mFile, "setAttr \".tlwd\" %i;\n", tlwd);}
	/*Tile width.*/
	void setTileWidth(const ShortID& tlwd){fprintf_s(mFile,"connectAttr \"");tlwd.write(mFile);fprintf_s(mFile,"\" \"%s.tlwd\";\n",mName.c_str());}
	/*Tile height.*/
	void setTileHeight(short tlht){if(tlht == 64) return; fprintf_s(mFile, "setAttr \".tlht\" %i;\n", tlht);}
	/*Tile height.*/
	void setTileHeight(const ShortID& tlht){fprintf_s(mFile,"connectAttr \"");tlht.write(mFile);fprintf_s(mFile,"\" \"%s.tlht\";\n",mName.c_str());}
	/*When turned on, the image color is jittered to reduce banding.*/
	void setJitterFinalColor(bool jfc){if(jfc == true) return; fprintf_s(mFile, "setAttr \".jfc\" %i;\n", jfc);}
	/*When turned on, the image color is jittered to reduce banding.*/
	void setJitterFinalColor(const BoolID& jfc){fprintf_s(mFile,"connectAttr \"");jfc.write(mFile);fprintf_s(mFile,"\" \"%s.jfc\";\n",mName.c_str());}
	/*
	This switch controls whether the camera's environment background
	color is applied to reflection and refraction rays which don't
	intersect anything.
	*/
	void setRaysSeeBackground(bool rsb){if(rsb == true) return; fprintf_s(mFile, "setAttr \".rsb\" %i;\n", rsb);}
	/*
	This switch controls whether the camera's environment background
	color is applied to reflection and refraction rays which don't
	intersect anything.
	*/
	void setRaysSeeBackground(const BoolID& rsb){fprintf_s(mFile,"connectAttr \"");rsb.write(mFile);fprintf_s(mFile,"\" \"%s.rsb\";\n",mName.c_str());}
	/*
	Make the pixel buffers used for paint effects twice the
	render resolution in order to enhance antialiasing quality.
	*/
	void setOversamplePaintEffects(bool ope){if(ope == false) return; fprintf_s(mFile, "setAttr \".ope\" %i;\n", ope);}
	/*
	Make the pixel buffers used for paint effects twice the
	render resolution in order to enhance antialiasing quality.
	*/
	void setOversamplePaintEffects(const BoolID& ope){fprintf_s(mFile,"connectAttr \"");ope.write(mFile);fprintf_s(mFile,"\" \"%s.ope\";\n",mName.c_str());}
	/*
	Apply a slight blur to the oversampled paint effects buffer before
	resizing down to the output resolution. This helps further enhance
	antialiasing in an oversample paint effects render. Note that it
	may also cause a very slight blurring of the non-paint effects portion
	of the render.
	*/
	void setOversamplePfxPostFilter(bool oppf){if(oppf == false) return; fprintf_s(mFile, "setAttr \".oppf\" %i;\n", oppf);}
	/*
	Apply a slight blur to the oversampled paint effects buffer before
	resizing down to the output resolution. This helps further enhance
	antialiasing in an oversample paint effects render. Note that it
	may also cause a very slight blurring of the non-paint effects portion
	of the render.
	*/
	void setOversamplePfxPostFilter(const BoolID& oppf){fprintf_s(mFile,"connectAttr \"");oppf.write(mFile);fprintf_s(mFile,"\" \"%s.oppf\";\n",mName.c_str());}
	/*String that keeps the hyper shade bin list.*/
	void setHyperShadeBinList(const string& hbl){if(hbl == "NULL") return; fprintf_s(mFile, "setAttr \".hbl\" -type \"string\" ");hbl.write(mFile);fprintf_s(mFile,";\n");}
	/*Type of Codec on Mac.*/
	IntID getMacCodec(){char buffer[4096];sprintf_s (buffer, "%s.macc",mName.c_str());return (const char*)buffer;}
	/*Type of Codec on Mac.*/
	IntID getMacDepth(){char buffer[4096];sprintf_s (buffer, "%s.macd",mName.c_str());return (const char*)buffer;}
	/*Type of Codec on Mac.*/
	IntID getMacQual(){char buffer[4096];sprintf_s (buffer, "%s.macq",mName.c_str());return (const char*)buffer;}
	/*Frame rate information for compression*/
	IntID getComFrrt(){char buffer[4096];sprintf_s (buffer, "%s.mcfr",mName.c_str());return (const char*)buffer;}
	/*Render all (1) or just render active (0).*/
	BoolID getRenderAll(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*The Quality to be used for this Render (the node at other end of this message plug is a renderQuality node).*/
	MessageID getQuality(){char buffer[4096];sprintf_s (buffer, "%s.qual",mName.c_str());return (const char*)buffer;}
	/*The Resolution to be used for this Render (the node at other end of this message plug is a resolution node).*/
	MessageID getResolution(){char buffer[4096];sprintf_s (buffer, "%s.res",mName.c_str());return (const char*)buffer;}
	/*if we should clamp the shader output*/
	BoolID getClipFinalShadedColor(){char buffer[4096];sprintf_s (buffer, "%s.clip",mName.c_str());return (const char*)buffer;}
	/*Enable or Disable the depth map shadows.*/
	BoolID getEnableDepthMaps(){char buffer[4096];sprintf_s (buffer, "%s.edm",mName.c_str());return (const char*)buffer;}
	/*Toggles whether a default light is created for rendering when there are no lights in the scene.*/
	BoolID getEnableDefaultLight(){char buffer[4096];sprintf_s (buffer, "%s.edl",mName.c_str());return (const char*)buffer;}
	/*Enable or Disable the rendering of Paint Effects Strokes. If true, the particle paint module must be present and there must be renderable strokes in the scene before it will really render the strokes.*/
	BoolID getEnableStrokeRender(){char buffer[4096];sprintf_s (buffer, "%s.esr",mName.c_str());return (const char*)buffer;}
	/*Only render Paint Effects Strokes - no geometry, depth file must be specified.*/
	BoolID getOnlyRenderStrokes(){char buffer[4096];sprintf_s (buffer, "%s.ors",mName.c_str());return (const char*)buffer;}
	/*If we are only rendering strokes, this depth file (plus possible extensions) is used for depth masking.*/
	StringID getStrokesDepthFile(){char buffer[4096];sprintf_s (buffer, "%s.sdf",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the output image file format - choices:
	GIF (0), SI (1), RLA (2), Tiff (3), Tiff16 (4), SGI (5), Alias (6)
	IFF (7) JPEG (8) EPS (9) IFF16 (10) Cineon (11) Quantel (12)
	SGI16 (13) TARGA (19) BMP (20)
	SGIMV (21) QT (22) AVI (23)
	MACPAINT (30) PHOTOSHOP (31) PNG (32) QUICKDRAW (33)
	QTIMAGE (34) DDS (35) DDS (36)
	IMFplugin (50) Custom (51)
	SWF (60) AI (61) SVG (62) SWFT (63)
	*/
	UnsignedintID getImageFormat(){char buffer[4096];sprintf_s (buffer, "%s.outf",mName.c_str());return (const char*)buffer;}
	/*IMF plugin keyword*/
	StringID getImfPluginKey(){char buffer[4096];sprintf_s (buffer, "%s.imfkey",mName.c_str());return (const char*)buffer;}
	/*Gamma correction value.*/
	FloatID getGammaCorrection(){char buffer[4096];sprintf_s (buffer, "%s.gama",mName.c_str());return (const char*)buffer;}
	/*The top 2d coord of render region (for use if useRenderRegion is true).*/
	IntID getTopRegion(){char buffer[4096];sprintf_s (buffer, "%s.top",mName.c_str());return (const char*)buffer;}
	/*The left 2d coord of render region (for use if useRenderRegion is true).*/
	IntID getLeftRegion(){char buffer[4096];sprintf_s (buffer, "%s.left",mName.c_str());return (const char*)buffer;}
	/*The bottom 2d coord of render region (for use if useRenderRegion is true).*/
	IntID getBottomRegion(){char buffer[4096];sprintf_s (buffer, "%s.bot",mName.c_str());return (const char*)buffer;}
	/*The right 2d coord of render region (for use if useRenderRegion is true).*/
	IntID getRightRegion(){char buffer[4096];sprintf_s (buffer, "%s.rght",mName.c_str());return (const char*)buffer;}
	/*Use the render region (use the previous coordinates if true (1)).*/
	BoolID getUseRenderRegion(){char buffer[4096];sprintf_s (buffer, "%s.urr",mName.c_str());return (const char*)buffer;}
	/*The renderGlobals frame step ('by' or increment) value.  This is no longer used, but kept for backwards compatibility.*/
	TimeID getByFrame(){char buffer[4096];sprintf_s (buffer, "%s.bf",mName.c_str());return (const char*)buffer;}
	/*Unitless (floating point) by frame.*/
	FloatID getByFrameStep(){char buffer[4096];sprintf_s (buffer, "%s.bfs",mName.c_str());return (const char*)buffer;}
	/*The output image filename extension step ('by' or increment) value.*/
	FloatID getByExtension(){char buffer[4096];sprintf_s (buffer, "%s.be",mName.c_str());return (const char*)buffer;}
	/*Controls the type of filename extension to be used for fields: o/e (0), no extension (Caution! Do not use with when interlace set to 'both'.) (1), user input (2)*/
	UnsignedintID getFieldExtControl(){char buffer[4096];sprintf_s (buffer, "%s.fec",mName.c_str());return (const char*)buffer;}
	/*Controls the type of filename format to be used for image files: use the default 'out format' abbreviation (0), no image file format type (1), user input (2)*/
	UnsignedintID getOutFormatControl(){char buffer[4096];sprintf_s (buffer, "%s.ofc",mName.c_str());return (const char*)buffer;}
	/*The user specified odd field extension if aFieldExtControl = 2*/
	StringID getOddFieldExt(){char buffer[4096];sprintf_s (buffer, "%s.ofe",mName.c_str());return (const char*)buffer;}
	/*The user specified even field extension if aFieldExtControl = 2*/
	StringID getEvenFieldExt(){char buffer[4096];sprintf_s (buffer, "%s.efe",mName.c_str());return (const char*)buffer;}
	/*The string added at the end of the file name if aOutFormatControl = 2*/
	StringID getOutFormatExt(){char buffer[4096];sprintf_s (buffer, "%s.oft",mName.c_str());return (const char*)buffer;}
	/*
	Compositing rendering; Do not blend alpha with image color.
	(unassociated alpha)
	*/
	BoolID getComposite(){char buffer[4096];sprintf_s (buffer, "%s.comp",mName.c_str());return (const char*)buffer;}
	/*Mainly for games support. The percentage of a pixel which must be covered by the object before the alpha should consider it part of the object. Animation customers should leave this at 0.0.*/
	FloatID getCompositeThreshold(){char buffer[4096];sprintf_s (buffer, "%s.cth",mName.c_str());return (const char*)buffer;}
	/*Objects not lit by a light will not cast shadow from that light*/
	BoolID getShadowsObeyLightLinking(){char buffer[4096];sprintf_s (buffer, "%s.soll",mName.c_str());return (const char*)buffer;}
	/*Objects not shadow linked to a light will not cast shadow from that light*/
	BoolID getShadowsObeyShadowLinking(){char buffer[4096];sprintf_s (buffer, "%s.sosl",mName.c_str());return (const char*)buffer;}
	/*Recursion depth for ray tracing. (for spatial subdivision 0,1,2,3 - useful range)*/
	IntID getRecursionDepth(){char buffer[4096];sprintf_s (buffer, "%s.rd",mName.c_str());return (const char*)buffer;}
	/*Max number of primitives per leaf in raytracing subdivision*/
	IntID getLeafPrimitives(){char buffer[4096];sprintf_s (buffer, "%s.lp",mName.c_str());return (const char*)buffer;}
	/*The power of the number of primitives to regulate axial subdivision*/
	FloatID getSubdivisionPower(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*The minimum hash table size for a subdivsion node*/
	IntID getSubdivisionHashSize(){char buffer[4096];sprintf_s (buffer, "%s.shs",mName.c_str());return (const char*)buffer;}
	/*Do we write a performance log or not*/
	BoolID getLogRenderPerformance(){char buffer[4096];sprintf_s (buffer, "%s.lpr",mName.c_str());return (const char*)buffer;}
	/*Vector length for geometry samples.*/
	IntID getGeometryVector(){char buffer[4096];sprintf_s (buffer, "%s.gv",mName.c_str());return (const char*)buffer;}
	/*Vector length for shading samples.*/
	IntID getShadingVector(){char buffer[4096];sprintf_s (buffer, "%s.sv",mName.c_str());return (const char*)buffer;}
	/*Maximum memory (in megabytes) to be used by the renderer.*/
	IntID getMaximumMemory(){char buffer[4096];sprintf_s (buffer, "%s.mm",mName.c_str());return (const char*)buffer;}
	/*Number of cpus to use for rendering or IPR (0 means use all).*/
	IntID getNumCpusToUse(){char buffer[4096];sprintf_s (buffer, "%s.npu",mName.c_str());return (const char*)buffer;}
	/*
	Number of seconds between checks for user interrupt. A value of
	-1 will disable interrupt checking.
	*/
	IntID getInterruptFrequency(){char buffer[4096];sprintf_s (buffer, "%s.itf",mName.c_str());return (const char*)buffer;}
	/*Whether we want to just do the shadow depth map pass.*/
	BoolID getShadowPass(){char buffer[4096];sprintf_s (buffer, "%s.shp",mName.c_str());return (const char*)buffer;}
	/*Whether we want to just do the ipr shadow depth map pass.*/
	BoolID getIprShadowPass(){char buffer[4096];sprintf_s (buffer, "%s.isp",mName.c_str());return (const char*)buffer;}
	/*When true, render swappable objects (ie. tessellations or RT voxels) can be stored on disk in the swap file. If false, tessellations and voxels are deleted and recomputed when needed.*/
	BoolID getUseFileCache(){char buffer[4096];sprintf_s (buffer, "%s.uf",mName.c_str());return (const char*)buffer;}
	/*When true, the renderer attempts to recognize similarly tesselated shapes.*/
	BoolID getOptimizeInstances(){char buffer[4096];sprintf_s (buffer, "%s.oi",mName.c_str());return (const char*)buffer;}
	/*When true, the rendered tessellations are used during the shadow map generation phase.*/
	BoolID getReuseTessellations(){char buffer[4096];sprintf_s (buffer, "%s.rut",mName.c_str());return (const char*)buffer;}
	/*Composite matte using scene transparency rather that residual matte transparency.*/
	BoolID getMatteOpacityUsesTransparency(){char buffer[4096];sprintf_s (buffer, "%s.mot",mName.c_str());return (const char*)buffer;}
	/*Use this as the by frame in conjunction with shutterAngle (instead of byFrame) to compute the shutterOpen, shutterMid, and shutterClose frame times.*/
	FloatID getMotionBlurByFrame(){char buffer[4096];sprintf_s (buffer, "%s.mbf",mName.c_str());return (const char*)buffer;}
	/*Connect this to the fog geometry.*/
	MessageID getFogGeometry(){char buffer[4096];sprintf_s (buffer, "%s.fg",mName.c_str());return (const char*)buffer;}
	/*Render and composite fog using depthbuffer at end of normal render (paint effects must be loaded)*/
	BoolID getApplyFogInPost(){char buffer[4096];sprintf_s (buffer, "%s.afp",mName.c_str());return (const char*)buffer;}
	/*blurring of fog into foreground applied before compositing on scene (only if applyFogInPost is on)*/
	IntID getPostFogBlur(){char buffer[4096];sprintf_s (buffer, "%s.pfb",mName.c_str());return (const char*)buffer;}
	/*MEL function to be called just before rendering*/
	StringID getPreMel(){char buffer[4096];sprintf_s (buffer, "%s.pram",mName.c_str());return (const char*)buffer;}
	/*MEL function to be called just after rendering*/
	StringID getPostMel(){char buffer[4096];sprintf_s (buffer, "%s.poam",mName.c_str());return (const char*)buffer;}
	/*MEL function to be called just before rendering of each render layer*/
	StringID getPreRenderLayerMel(){char buffer[4096];sprintf_s (buffer, "%s.prlm",mName.c_str());return (const char*)buffer;}
	/*MEL function to be called just after rendering of each render layer*/
	StringID getPostRenderLayerMel(){char buffer[4096];sprintf_s (buffer, "%s.polm",mName.c_str());return (const char*)buffer;}
	/*MEL function to be called just before rendering each frame*/
	StringID getPreRenderMel(){char buffer[4096];sprintf_s (buffer, "%s.prm",mName.c_str());return (const char*)buffer;}
	/*MEL function to be called just after rendering each frame*/
	StringID getPostRenderMel(){char buffer[4096];sprintf_s (buffer, "%s.pom",mName.c_str());return (const char*)buffer;}
	/*MEL function to be called just before rendering of current fur frame*/
	StringID getPreFurRenderMel(){char buffer[4096];sprintf_s (buffer, "%s.pfrm",mName.c_str());return (const char*)buffer;}
	/*MEL function to be called just after rendering of current fur frame*/
	StringID getPostFurRenderMel(){char buffer[4096];sprintf_s (buffer, "%s.pfom",mName.c_str());return (const char*)buffer;}
	/*Create an IPR file.*/
	BoolID getCreateIprFile(){char buffer[4096];sprintf_s (buffer, "%s.cif",mName.c_str());return (const char*)buffer;}
	/*This is the scale applied on the motion vectors.*/
	FloatID getBlurLength(){char buffer[4096];sprintf_s (buffer, "%s.bll",mName.c_str());return (const char*)buffer;}
	/*The higher the value, the sharper the blur. The lower the value, the softer the blur.*/
	FloatID getBlurSharpness(){char buffer[4096];sprintf_s (buffer, "%s.bls",mName.c_str());return (const char*)buffer;}
	/*The higher the value, the more anti-aliased the alpha channel.*/
	IntID getSmoothValue(){char buffer[4096];sprintf_s (buffer, "%s.smv",mName.c_str());return (const char*)buffer;}
	/*Enables an absolute memory limit for the 2d blur operation (limit given by the 'blur2DMemoryCap' attribute)*/
	BoolID getUseBlur2DMemoryCap(){char buffer[4096];sprintf_s (buffer, "%s.ubc",mName.c_str());return (const char*)buffer;}
	/*Absolute memory limit for the 2d blur operation*/
	FloatID getBlur2DMemoryCap(){char buffer[4096];sprintf_s (buffer, "%s.mbc",mName.c_str());return (const char*)buffer;}
	/*When true, the bounding box scale is used to predict a bounding box for displacement-mapped objects. If false, all displacment-mapped objects are pre-tessellated to find their bounding boxes.*/
	BoolID getUseDisplacementBoundingBox(){char buffer[4096];sprintf_s (buffer, "%s.udbx",mName.c_str());return (const char*)buffer;}
	/*When true, the color channels will be smoothened during the 2.5D motion blur just as the mask channel. If false, only the mask channel is smoothened and the color channels are scaled based on the mask change.*/
	BoolID getSmoothColor(){char buffer[4096];sprintf_s (buffer, "%s.smc",mName.c_str());return (const char*)buffer;}
	/*When true, the motion vector file generated from 2.5D motion blur will be kept. If false, the motion vector file generated from 2.5D motion blur is deleted after the blur is computed.*/
	BoolID getKeepMotionVector(){char buffer[4096];sprintf_s (buffer, "%s.kmv",mName.c_str());return (const char*)buffer;}
	/*Create an IPR file containing shading, lighting, and glow.*/
	BoolID getIprRenderShading(){char buffer[4096];sprintf_s (buffer, "%s.isl",mName.c_str());return (const char*)buffer;}
	/*Create an IPR file containing shadow maps.*/
	BoolID getIprRenderShadowMaps(){char buffer[4096];sprintf_s (buffer, "%s.ism",mName.c_str());return (const char*)buffer;}
	/*Create an IPR file containint motion blur.*/
	BoolID getIprRenderMotionBlur(){char buffer[4096];sprintf_s (buffer, "%s.imb",mName.c_str());return (const char*)buffer;}
	/*The Render callback to be used for this Render (the node at other end of this message plug is a render callback node)*/
	MessageID getRendercallback(){char buffer[4096];sprintf_s (buffer, "%s.rcb",mName.c_str());return (const char*)buffer;}
	/*Render out multiple layers*/
	BoolID getRenderLayerEnable(){char buffer[4096];sprintf_s (buffer, "%s.rlen",mName.c_str());return (const char*)buffer;}
	/*Should the tile size be forced?*/
	BoolID getForceTileSize(){char buffer[4096];sprintf_s (buffer, "%s.frts",mName.c_str());return (const char*)buffer;}
	/*Tile width.*/
	ShortID getTileWidth(){char buffer[4096];sprintf_s (buffer, "%s.tlwd",mName.c_str());return (const char*)buffer;}
	/*Tile height.*/
	ShortID getTileHeight(){char buffer[4096];sprintf_s (buffer, "%s.tlht",mName.c_str());return (const char*)buffer;}
	/*When turned on, the image color is jittered to reduce banding.*/
	BoolID getJitterFinalColor(){char buffer[4096];sprintf_s (buffer, "%s.jfc",mName.c_str());return (const char*)buffer;}
	/*
	This switch controls whether the camera's environment background
	color is applied to reflection and refraction rays which don't
	intersect anything.
	*/
	BoolID getRaysSeeBackground(){char buffer[4096];sprintf_s (buffer, "%s.rsb",mName.c_str());return (const char*)buffer;}
	/*
	Make the pixel buffers used for paint effects twice the
	render resolution in order to enhance antialiasing quality.
	*/
	BoolID getOversamplePaintEffects(){char buffer[4096];sprintf_s (buffer, "%s.ope",mName.c_str());return (const char*)buffer;}
	/*
	Apply a slight blur to the oversampled paint effects buffer before
	resizing down to the output resolution. This helps further enhance
	antialiasing in an oversample paint effects render. Note that it
	may also cause a very slight blurring of the non-paint effects portion
	of the render.
	*/
	BoolID getOversamplePfxPostFilter(){char buffer[4096];sprintf_s (buffer, "%s.oppf",mName.c_str());return (const char*)buffer;}
protected:
	RenderGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RENDERGLOBALS_H__
