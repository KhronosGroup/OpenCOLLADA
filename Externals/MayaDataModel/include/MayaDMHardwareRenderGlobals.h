/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HARDWARERENDERGLOBALS_H__
#define __MayaDM_HARDWARERENDERGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    Node used to store global hardware render attributes. By using
    a node, these attributes will be read/written to file. There
    should only be one of these nodes.
</pre></p>
*/
class HardwareRenderGlobals : public DependNode
{
public:
public:
	HardwareRenderGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hardwareRenderGlobals"){}
	virtual ~HardwareRenderGlobals(){}
	/*Baked texture resolution for textures mapped to color channels on shaders.*/
	void setColorTextureResolution(int ctrs){if(ctrs == 128) return; fprintf_s(mFile, "setAttr \".ctrs\" %i;\n", ctrs);}
	/*Baked texture resolution for textures mapped to color channels on shaders.*/
	void setColorTextureResolution(const IntID& ctrs){fprintf_s(mFile,"connectAttr \"");ctrs.write(mFile);fprintf_s(mFile,"\" \"%s.ctrs\";\n",mName.c_str());}
	/*Baked texture resolution for textures mapped to bump channel on shaders.*/
	void setBumpTextureResolution(int btrs){if(btrs == 256) return; fprintf_s(mFile, "setAttr \".btrs\" %i;\n", btrs);}
	/*Baked texture resolution for textures mapped to bump channel on shaders.*/
	void setBumpTextureResolution(const IntID& btrs){fprintf_s(mFile,"connectAttr \"");btrs.write(mFile);fprintf_s(mFile,"\" \"%s.btrs\";\n",mName.c_str());}
	/*
	Specifies the desired format of the frame buffer used for output.
	The default is RGBA format with 8 bits fixed point per channel precision.
	Note that not all graphics hardware can support all frame buffer
	formats. If the format is not supported the default format will
	be attempted to be used.
	*/
	void setFrameBufferFormat(unsigned int fbfm){if(fbfm == 0) return; fprintf_s(mFile, "setAttr \".fbfm\" %i;\n", fbfm);}
	/*
	Specifies the desired format of the frame buffer used for output.
	The default is RGBA format with 8 bits fixed point per channel precision.
	Note that not all graphics hardware can support all frame buffer
	formats. If the format is not supported the default format will
	be attempted to be used.
	*/
	void setFrameBufferFormat(const UnsignedintID& fbfm){fprintf_s(mFile,"connectAttr \"");fbfm.write(mFile);fprintf_s(mFile,"\" \"%s.fbfm\";\n",mName.c_str());}
	/*
	Enable high quality lighting. This option will enable lighting
	effects like bump mapping and per-pixel specular highlights.
	Render times may be 2 to 5 longer as compared to when this
	option is disabled (ie. low quality lighting).
	*/
	void setEnableHighQualityLighting(bool ehql){if(ehql == true) return; fprintf_s(mFile, "setAttr \".ehql\" %i;\n", ehql);}
	/*
	Enable high quality lighting. This option will enable lighting
	effects like bump mapping and per-pixel specular highlights.
	Render times may be 2 to 5 longer as compared to when this
	option is disabled (ie. low quality lighting).
	*/
	void setEnableHighQualityLighting(const BoolID& ehql){fprintf_s(mFile,"connectAttr \"");ehql.write(mFile);fprintf_s(mFile,"\" \"%s.ehql\";\n",mName.c_str());}
	/*
	Enable hardware multi-sampling if available. This will give an
	additional 4 samples per exposure at little cost to rendering
	time, although more memory usage may be required.
	*/
	void setEnableAcceleratedMultiSampling(bool eams){if(eams == true) return; fprintf_s(mFile, "setAttr \".eams\" %i;\n", eams);}
	/*
	Enable hardware multi-sampling if available. This will give an
	additional 4 samples per exposure at little cost to rendering
	time, although more memory usage may be required.
	*/
	void setEnableAcceleratedMultiSampling(const BoolID& eams){fprintf_s(mFile,"connectAttr \"");eams.write(mFile);fprintf_s(mFile,"\" \"%s.eams\";\n",mName.c_str());}
	/*Enable/Disable edge anti-aliasing. With this flag turned on, hardware multisampling is automatically enabled alongside software multipass rendering. A number of passes can be specified via the multipleExposuresSamples attribute.*/
	void setEnableEdgeAntiAliasing(bool eeaa){if(eeaa == false) return; fprintf_s(mFile, "setAttr \".eeaa\" %i;\n", eeaa);}
	/*Enable/Disable edge anti-aliasing. With this flag turned on, hardware multisampling is automatically enabled alongside software multipass rendering. A number of passes can be specified via the multipleExposuresSamples attribute.*/
	void setEnableEdgeAntiAliasing(const BoolID& eeaa){fprintf_s(mFile,"connectAttr \"");eeaa.write(mFile);fprintf_s(mFile,"\" \"%s.eeaa\";\n",mName.c_str());}
	/*Enable/Disable geometry mask. When this option is enabled, opaque geometry objects will "mask out" particle objects, while transparent geometry will simply not get drawn. This flag is typically used when compositing particle passes over software-rendered geometry passes.*/
	void setEnableGeometryMask(bool engm){if(engm == false) return; fprintf_s(mFile, "setAttr \".engm\" %i;\n", engm);}
	/*Enable/Disable geometry mask. When this option is enabled, opaque geometry objects will "mask out" particle objects, while transparent geometry will simply not get drawn. This flag is typically used when compositing particle passes over software-rendered geometry passes.*/
	void setEnableGeometryMask(const BoolID& engm){fprintf_s(mFile,"connectAttr \"");engm.write(mFile);fprintf_s(mFile,"\" \"%s.engm\";\n",mName.c_str());}
	/*Specifies the number of samples to be rendered.*/
	void setNumberOfSamples(unsigned int mes){if(mes == 0) return; fprintf_s(mFile, "setAttr \".mes\" %i;\n", mes);}
	/*Specifies the number of samples to be rendered.*/
	void setNumberOfSamples(const UnsignedintID& mes){fprintf_s(mFile,"connectAttr \"");mes.write(mFile);fprintf_s(mFile,"\" \"%s.mes\";\n",mName.c_str());}
	/*Enable/Disable motion blur. The range of the blur (in frames) can be specified via the motionBlurByFrame attribute, while the number of exposures used in the blur can be specified through the motionBlurSamples attribute.*/
	void setEnableMotionBlur(bool emb){if(emb == false) return; fprintf_s(mFile, "setAttr \".emb\" %i;\n", emb);}
	/*Enable/Disable motion blur. The range of the blur (in frames) can be specified via the motionBlurByFrame attribute, while the number of exposures used in the blur can be specified through the motionBlurSamples attribute.*/
	void setEnableMotionBlur(const BoolID& emb){fprintf_s(mFile,"connectAttr \"");emb.write(mFile);fprintf_s(mFile,"\" \"%s.emb\";\n",mName.c_str());}
	/*Range in frames to be blurred from the current frame.*/
	void setMotionBlurByFrame(float mbbf){if(mbbf == 1.000) return; fprintf_s(mFile, "setAttr \".mbbf\" %f;\n", mbbf);}
	/*Range in frames to be blurred from the current frame.*/
	void setMotionBlurByFrame(const FloatID& mbbf){fprintf_s(mFile,"connectAttr \"");mbbf.write(mFile);fprintf_s(mFile,"\" \"%s.mbbf\";\n",mName.c_str());}
	/*Number of samples used to blur the range specified by the motionBlurByFrame attribute.*/
	void setNumberOfExposures(int mbs){if(mbs == 3) return; fprintf_s(mFile, "setAttr \".mbs\" %i;\n", mbs);}
	/*Number of samples used to blur the range specified by the motionBlurByFrame attribute.*/
	void setNumberOfExposures(const IntID& mbs){fprintf_s(mFile,"connectAttr \"");mbs.write(mFile);fprintf_s(mFile,"\" \"%s.mbs\";\n",mName.c_str());}
	/*
	Sets the transparency sorting method to use to either be per object
	sorting or per polygon sorting.
	*/
	void setTransparencySorting(unsigned int trm){if(trm == 0) return; fprintf_s(mFile, "setAttr \".trm\" %i;\n", trm);}
	/*
	Sets the transparency sorting method to use to either be per object
	sorting or per polygon sorting.
	*/
	void setTransparencySorting(const UnsignedintID& trm){fprintf_s(mFile,"connectAttr \"");trm.write(mFile);fprintf_s(mFile,"\" \"%s.trm\";\n",mName.c_str());}
	/*
	Sets whether to not cast shadows from parts of objects which
	are totally transparent.
	*/
	void setTransparentShadowCasting(bool tshc){if(tshc == true) return; fprintf_s(mFile, "setAttr \".tshc\" %i;\n", tshc);}
	/*
	Sets whether to not cast shadows from parts of objects which
	are totally transparent.
	*/
	void setTransparentShadowCasting(const BoolID& tshc){fprintf_s(mFile,"connectAttr \"");tshc.write(mFile);fprintf_s(mFile,"\" \"%s.tshc\";\n",mName.c_str());}
	/*
	Enable the use of Non Power of Two (NPOT) textures when
	supported by graphics card and its drivers.
	This option will enable NPOT depth map size for the hardware shadows.
	*/
	void setEnableNonPowerOfTwoTexture(bool enpt){if(enpt == true) return; fprintf_s(mFile, "setAttr \".enpt\" %i;\n", enpt);}
	/*
	Enable the use of Non Power of Two (NPOT) textures when
	supported by graphics card and its drivers.
	This option will enable NPOT depth map size for the hardware shadows.
	*/
	void setEnableNonPowerOfTwoTexture(const BoolID& enpt){fprintf_s(mFile,"connectAttr \"");enpt.write(mFile);fprintf_s(mFile,"\" \"%s.enpt\";\n",mName.c_str());}
	/*
	Set the culling method for all geometry to either be double sided,
	single sided, or the value set per geometric object.
	*/
	void setCulling(unsigned int clmt){if(clmt == 0) return; fprintf_s(mFile, "setAttr \".clmt\" %i;\n", clmt);}
	/*
	Set the culling method for all geometry to either be double sided,
	single sided, or the value set per geometric object.
	*/
	void setCulling(const UnsignedintID& clmt){fprintf_s(mFile,"connectAttr \"");clmt.write(mFile);fprintf_s(mFile,"\" \"%s.clmt\";\n",mName.c_str());}
	/*
	Texture compression can reduce memory usage by up to 75%, and may
	increase draw performance. The algorithm used (DXT5) typically
	introduces very little compression artifacts, so it's generally
	appropriate for a wide range of textures.
	*/
	void setTextureCompression(unsigned int tcov){if(tcov == 0) return; fprintf_s(mFile, "setAttr \".tcov\" %i;\n", tcov);}
	/*
	Texture compression can reduce memory usage by up to 75%, and may
	increase draw performance. The algorithm used (DXT5) typically
	introduces very little compression artifacts, so it's generally
	appropriate for a wide range of textures.
	*/
	void setTextureCompression(const UnsignedintID& tcov){fprintf_s(mFile,"connectAttr \"");tcov.write(mFile);fprintf_s(mFile,"\" \"%s.tcov\";\n",mName.c_str());}
	/*
	The threshold value used to determine when the ratio
	of light intensity to light decay makes the light's
	contribution on a surface negligible.
	*/
	void setLightIntensityThreshold(float lith){if(lith == 0.001) return; fprintf_s(mFile, "setAttr \".lith\" %f;\n", lith);}
	/*
	The threshold value used to determine when the ratio
	of light intensity to light decay makes the light's
	contribution on a surface negligible.
	*/
	void setLightIntensityThreshold(const FloatID& lith){fprintf_s(mFile,"connectAttr \"");lith.write(mFile);fprintf_s(mFile,"\" \"%s.lith\";\n",mName.c_str());}
	/*
	Enable the usage of culling of "small" objects to
	increase draw performance. The definition of "small"
	is decided based on the "small object culling threshold"
	"cullingThreshold" attribute.
	*/
	void setSmallObjectCulling(bool sobc){if(sobc == true) return; fprintf_s(mFile, "setAttr \".sobc\" %i;\n", sobc);}
	/*
	Enable the usage of culling of "small" objects to
	increase draw performance. The definition of "small"
	is decided based on the "small object culling threshold"
	"cullingThreshold" attribute.
	*/
	void setSmallObjectCulling(const BoolID& sobc){fprintf_s(mFile,"connectAttr \"");sobc.write(mFile);fprintf_s(mFile,"\" \"%s.sobc\";\n",mName.c_str());}
	/*
	The threshold tolerance used to determine what is
	considered to be small enough that it will not be
	drawn. This is taken as a percentage of the rendered
	image's number of pixels.
	*/
	void setCullingThreshold(float cuth){if(cuth == 0.0) return; fprintf_s(mFile, "setAttr \".cuth\" %f;\n", cuth);}
	/*
	The threshold tolerance used to determine what is
	considered to be small enough that it will not be
	drawn. This is taken as a percentage of the rendered
	image's number of pixels.
	*/
	void setCullingThreshold(const FloatID& cuth){fprintf_s(mFile,"connectAttr \"");cuth.write(mFile);fprintf_s(mFile,"\" \"%s.cuth\";\n",mName.c_str());}
	/*
	Enable the usage of graphics hardware for geometry caching of data
	attributes to improve draw perfomance. This is dependent upon the
	ability of the graphics hardware to support this functionality,
	and the amount of available memory which can be used if supported.
	The maximum memory used can be clamped via the "maximumGeometryCacheSize"
	attribute.
	*/
	void setGraphicsHardwareGeometryCachingData(bool hgcd){if(hgcd == true) return; fprintf_s(mFile, "setAttr \".hgcd\" %i;\n", hgcd);}
	/*
	Enable the usage of graphics hardware for geometry caching of data
	attributes to improve draw perfomance. This is dependent upon the
	ability of the graphics hardware to support this functionality,
	and the amount of available memory which can be used if supported.
	The maximum memory used can be clamped via the "maximumGeometryCacheSize"
	attribute.
	*/
	void setGraphicsHardwareGeometryCachingData(const BoolID& hgcd){fprintf_s(mFile,"connectAttr \"");hgcd.write(mFile);fprintf_s(mFile,"\" \"%s.hgcd\";\n",mName.c_str());}
	/*
	Enable the usage of graphics hardware for geometry caching of data indexing
	to improve draw perfomance. This is dependent upon the
	ability of the graphics hardware to support this functionality,
	and the amount of available memory which can be used if supported.
	The maximum memory used can be clamped via the "maximumGeometryCacheSize"
	attribute.
	*/
	void setGraphicsHardwareGeometryCachingIndexing(bool hgci){if(hgci == true) return; fprintf_s(mFile, "setAttr \".hgci\" %i;\n", hgci);}
	/*
	Enable the usage of graphics hardware for geometry caching of data indexing
	to improve draw perfomance. This is dependent upon the
	ability of the graphics hardware to support this functionality,
	and the amount of available memory which can be used if supported.
	The maximum memory used can be clamped via the "maximumGeometryCacheSize"
	attribute.
	*/
	void setGraphicsHardwareGeometryCachingIndexing(const BoolID& hgci){fprintf_s(mFile,"connectAttr \"");hgci.write(mFile);fprintf_s(mFile,"\" \"%s.hgci\";\n",mName.c_str());}
	/*
	Set a user "maximum" possible amount of memory for the graphics
	hardware geometry cache. The default is 64MB, with the minumum
	amount being 1MB.
	*/
	void setMaximumGeometryCacheSize(int mgcs){if(mgcs == 64) return; fprintf_s(mFile, "setAttr \".mgcs\" %i;\n", mgcs);}
	/*
	Set a user "maximum" possible amount of memory for the graphics
	hardware geometry cache. The default is 64MB, with the minumum
	amount being 1MB.
	*/
	void setMaximumGeometryCacheSize(const IntID& mgcs){fprintf_s(mFile,"connectAttr \"");mgcs.write(mFile);fprintf_s(mFile,"\" \"%s.mgcs\";\n",mName.c_str());}
	/*Enable/disable writing of alpha channel as color image files*/
	void setWriteAlphaAsColor(bool twa){if(twa == false) return; fprintf_s(mFile, "setAttr \".twa\" %i;\n", twa);}
	/*Enable/disable writing of alpha channel as color image files*/
	void setWriteAlphaAsColor(const BoolID& twa){fprintf_s(mFile,"connectAttr \"");twa.write(mFile);fprintf_s(mFile,"\" \"%s.twa\";\n",mName.c_str());}
	/*Enable/disable writing of zdepth as color image files*/
	void setWriteZDepthAsColor(bool twz){if(twz == false) return; fprintf_s(mFile, "setAttr \".twz\" %i;\n", twz);}
	/*Enable/disable writing of zdepth as color image files*/
	void setWriteZDepthAsColor(const BoolID& twz){fprintf_s(mFile,"connectAttr \"");twz.write(mFile);fprintf_s(mFile,"\" \"%s.twz\";\n",mName.c_str());}
	/*Type of Codec.*/
	void setHardwareCodec(int hwcc){if(hwcc == 1919706400) return; fprintf_s(mFile, "setAttr \".hwcc\" %i;\n", hwcc);}
	/*Type of Codec.*/
	void setHardwareCodec(const IntID& hwcc){fprintf_s(mFile,"connectAttr \"");hwcc.write(mFile);fprintf_s(mFile,"\" \"%s.hwcc\";\n",mName.c_str());}
	/*Type of Codec on Mac.*/
	void setHardwareDepth(int hwdp){if(hwdp == 32) return; fprintf_s(mFile, "setAttr \".hwdp\" %i;\n", hwdp);}
	/*Type of Codec on Mac.*/
	void setHardwareDepth(const IntID& hwdp){fprintf_s(mFile,"connectAttr \"");hwdp.write(mFile);fprintf_s(mFile,"\" \"%s.hwdp\";\n",mName.c_str());}
	/*Type of Codec on Mac.*/
	void setHardwareQual(int hwql){if(hwql == 1024) return; fprintf_s(mFile, "setAttr \".hwql\" %i;\n", hwql);}
	/*Type of Codec on Mac.*/
	void setHardwareQual(const IntID& hwql){fprintf_s(mFile,"connectAttr \"");hwql.write(mFile);fprintf_s(mFile,"\" \"%s.hwql\";\n",mName.c_str());}
	/*Frame rate information for compression*/
	void setHardwareFrameRate(int hwfr){if(hwfr == 24) return; fprintf_s(mFile, "setAttr \".hwfr\" %i;\n", hwfr);}
	/*Frame rate information for compression*/
	void setHardwareFrameRate(const IntID& hwfr){fprintf_s(mFile,"connectAttr \"");hwfr.write(mFile);fprintf_s(mFile,"\" \"%s.hwfr\";\n",mName.c_str());}
	/*Objects not lit by a light will not cast shadow from that light*/
	void setShadowsObeyLightLinking(bool soll){if(soll == true) return; fprintf_s(mFile, "setAttr \".soll\" %i;\n", soll);}
	/*Objects not lit by a light will not cast shadow from that light*/
	void setShadowsObeyLightLinking(const BoolID& soll){fprintf_s(mFile,"connectAttr \"");soll.write(mFile);fprintf_s(mFile,"\" \"%s.soll\";\n",mName.c_str());}
	/*Objects not shadow linked to a light will not cast shadow from that light*/
	void setShadowsObeyShadowLinking(bool sosl){if(sosl == false) return; fprintf_s(mFile, "setAttr \".sosl\" %i;\n", sosl);}
	/*Objects not shadow linked to a light will not cast shadow from that light*/
	void setShadowsObeyShadowLinking(const BoolID& sosl){fprintf_s(mFile,"connectAttr \"");sosl.write(mFile);fprintf_s(mFile,"\" \"%s.sosl\";\n",mName.c_str());}
	/*
	When enabled will multiply the specular component with transparency for display.
	By default this is disabled to match Maya's software renderer.
	*/
	void setBlendSpecularWithAlpha(bool bswa){if(bswa == false) return; fprintf_s(mFile, "setAttr \".bswa\" %i;\n", bswa);}
	/*
	When enabled will multiply the specular component with transparency for display.
	By default this is disabled to match Maya's software renderer.
	*/
	void setBlendSpecularWithAlpha(const BoolID& bswa){fprintf_s(mFile,"connectAttr \"");bswa.write(mFile);fprintf_s(mFile,"\" \"%s.bswa\";\n",mName.c_str());}
	/*Determines the shading model used to render with. Default is to emulate the Maya software renderer.*/
	void setShadingModel(unsigned int shml){if(shml == 0) return; fprintf_s(mFile, "setAttr \".shml\" %i;\n", shml);}
	/*Determines the shading model used to render with. Default is to emulate the Maya software renderer.*/
	void setShadingModel(const UnsignedintID& shml){fprintf_s(mFile,"connectAttr \"");shml.write(mFile);fprintf_s(mFile,"\" \"%s.shml\";\n",mName.c_str());}
	/*
	Determines whether to use environment map lookups which match hardware or software rendering. Matching
	software rendering is the default.
	*/
	void setHardwareEnvironmentLookup(bool hwel){if(hwel == false) return; fprintf_s(mFile, "setAttr \".hwel\" %i;\n", hwel);}
	/*
	Determines whether to use environment map lookups which match hardware or software rendering. Matching
	software rendering is the default.
	*/
	void setHardwareEnvironmentLookup(const BoolID& hwel){fprintf_s(mFile,"connectAttr \"");hwel.write(mFile);fprintf_s(mFile,"\" \"%s.hwel\";\n",mName.c_str());}
	/*Baked texture resolution for textures mapped to color channels on shaders.*/
	IntID getColorTextureResolution(){char buffer[4096];sprintf_s (buffer, "%s.ctrs",mName.c_str());return (const char*)buffer;}
	/*Baked texture resolution for textures mapped to bump channel on shaders.*/
	IntID getBumpTextureResolution(){char buffer[4096];sprintf_s (buffer, "%s.btrs",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the desired format of the frame buffer used for output.
	The default is RGBA format with 8 bits fixed point per channel precision.
	Note that not all graphics hardware can support all frame buffer
	formats. If the format is not supported the default format will
	be attempted to be used.
	*/
	UnsignedintID getFrameBufferFormat(){char buffer[4096];sprintf_s (buffer, "%s.fbfm",mName.c_str());return (const char*)buffer;}
	/*
	Enable high quality lighting. This option will enable lighting
	effects like bump mapping and per-pixel specular highlights.
	Render times may be 2 to 5 longer as compared to when this
	option is disabled (ie. low quality lighting).
	*/
	BoolID getEnableHighQualityLighting(){char buffer[4096];sprintf_s (buffer, "%s.ehql",mName.c_str());return (const char*)buffer;}
	/*
	Enable hardware multi-sampling if available. This will give an
	additional 4 samples per exposure at little cost to rendering
	time, although more memory usage may be required.
	*/
	BoolID getEnableAcceleratedMultiSampling(){char buffer[4096];sprintf_s (buffer, "%s.eams",mName.c_str());return (const char*)buffer;}
	/*Enable/Disable edge anti-aliasing. With this flag turned on, hardware multisampling is automatically enabled alongside software multipass rendering. A number of passes can be specified via the multipleExposuresSamples attribute.*/
	BoolID getEnableEdgeAntiAliasing(){char buffer[4096];sprintf_s (buffer, "%s.eeaa",mName.c_str());return (const char*)buffer;}
	/*Enable/Disable geometry mask. When this option is enabled, opaque geometry objects will "mask out" particle objects, while transparent geometry will simply not get drawn. This flag is typically used when compositing particle passes over software-rendered geometry passes.*/
	BoolID getEnableGeometryMask(){char buffer[4096];sprintf_s (buffer, "%s.engm",mName.c_str());return (const char*)buffer;}
	/*Specifies the number of samples to be rendered.*/
	UnsignedintID getNumberOfSamples(){char buffer[4096];sprintf_s (buffer, "%s.mes",mName.c_str());return (const char*)buffer;}
	/*Enable/Disable motion blur. The range of the blur (in frames) can be specified via the motionBlurByFrame attribute, while the number of exposures used in the blur can be specified through the motionBlurSamples attribute.*/
	BoolID getEnableMotionBlur(){char buffer[4096];sprintf_s (buffer, "%s.emb",mName.c_str());return (const char*)buffer;}
	/*Range in frames to be blurred from the current frame.*/
	FloatID getMotionBlurByFrame(){char buffer[4096];sprintf_s (buffer, "%s.mbbf",mName.c_str());return (const char*)buffer;}
	/*Number of samples used to blur the range specified by the motionBlurByFrame attribute.*/
	IntID getNumberOfExposures(){char buffer[4096];sprintf_s (buffer, "%s.mbs",mName.c_str());return (const char*)buffer;}
	/*
	Sets the transparency sorting method to use to either be per object
	sorting or per polygon sorting.
	*/
	UnsignedintID getTransparencySorting(){char buffer[4096];sprintf_s (buffer, "%s.trm",mName.c_str());return (const char*)buffer;}
	/*
	Sets whether to not cast shadows from parts of objects which
	are totally transparent.
	*/
	BoolID getTransparentShadowCasting(){char buffer[4096];sprintf_s (buffer, "%s.tshc",mName.c_str());return (const char*)buffer;}
	/*
	Enable the use of Non Power of Two (NPOT) textures when
	supported by graphics card and its drivers.
	This option will enable NPOT depth map size for the hardware shadows.
	*/
	BoolID getEnableNonPowerOfTwoTexture(){char buffer[4096];sprintf_s (buffer, "%s.enpt",mName.c_str());return (const char*)buffer;}
	/*
	Set the culling method for all geometry to either be double sided,
	single sided, or the value set per geometric object.
	*/
	UnsignedintID getCulling(){char buffer[4096];sprintf_s (buffer, "%s.clmt",mName.c_str());return (const char*)buffer;}
	/*
	Texture compression can reduce memory usage by up to 75%, and may
	increase draw performance. The algorithm used (DXT5) typically
	introduces very little compression artifacts, so it's generally
	appropriate for a wide range of textures.
	*/
	UnsignedintID getTextureCompression(){char buffer[4096];sprintf_s (buffer, "%s.tcov",mName.c_str());return (const char*)buffer;}
	/*
	The threshold value used to determine when the ratio
	of light intensity to light decay makes the light's
	contribution on a surface negligible.
	*/
	FloatID getLightIntensityThreshold(){char buffer[4096];sprintf_s (buffer, "%s.lith",mName.c_str());return (const char*)buffer;}
	/*
	Enable the usage of culling of "small" objects to
	increase draw performance. The definition of "small"
	is decided based on the "small object culling threshold"
	"cullingThreshold" attribute.
	*/
	BoolID getSmallObjectCulling(){char buffer[4096];sprintf_s (buffer, "%s.sobc",mName.c_str());return (const char*)buffer;}
	/*
	The threshold tolerance used to determine what is
	considered to be small enough that it will not be
	drawn. This is taken as a percentage of the rendered
	image's number of pixels.
	*/
	FloatID getCullingThreshold(){char buffer[4096];sprintf_s (buffer, "%s.cuth",mName.c_str());return (const char*)buffer;}
	/*
	Enable the usage of graphics hardware for geometry caching of data
	attributes to improve draw perfomance. This is dependent upon the
	ability of the graphics hardware to support this functionality,
	and the amount of available memory which can be used if supported.
	The maximum memory used can be clamped via the "maximumGeometryCacheSize"
	attribute.
	*/
	BoolID getGraphicsHardwareGeometryCachingData(){char buffer[4096];sprintf_s (buffer, "%s.hgcd",mName.c_str());return (const char*)buffer;}
	/*
	Enable the usage of graphics hardware for geometry caching of data indexing
	to improve draw perfomance. This is dependent upon the
	ability of the graphics hardware to support this functionality,
	and the amount of available memory which can be used if supported.
	The maximum memory used can be clamped via the "maximumGeometryCacheSize"
	attribute.
	*/
	BoolID getGraphicsHardwareGeometryCachingIndexing(){char buffer[4096];sprintf_s (buffer, "%s.hgci",mName.c_str());return (const char*)buffer;}
	/*
	Set a user "maximum" possible amount of memory for the graphics
	hardware geometry cache. The default is 64MB, with the minumum
	amount being 1MB.
	*/
	IntID getMaximumGeometryCacheSize(){char buffer[4096];sprintf_s (buffer, "%s.mgcs",mName.c_str());return (const char*)buffer;}
	/*Enable/disable writing of alpha channel as color image files*/
	BoolID getWriteAlphaAsColor(){char buffer[4096];sprintf_s (buffer, "%s.twa",mName.c_str());return (const char*)buffer;}
	/*Enable/disable writing of zdepth as color image files*/
	BoolID getWriteZDepthAsColor(){char buffer[4096];sprintf_s (buffer, "%s.twz",mName.c_str());return (const char*)buffer;}
	/*Type of Codec.*/
	IntID getHardwareCodec(){char buffer[4096];sprintf_s (buffer, "%s.hwcc",mName.c_str());return (const char*)buffer;}
	/*Type of Codec on Mac.*/
	IntID getHardwareDepth(){char buffer[4096];sprintf_s (buffer, "%s.hwdp",mName.c_str());return (const char*)buffer;}
	/*Type of Codec on Mac.*/
	IntID getHardwareQual(){char buffer[4096];sprintf_s (buffer, "%s.hwql",mName.c_str());return (const char*)buffer;}
	/*Frame rate information for compression*/
	IntID getHardwareFrameRate(){char buffer[4096];sprintf_s (buffer, "%s.hwfr",mName.c_str());return (const char*)buffer;}
	/*Objects not lit by a light will not cast shadow from that light*/
	BoolID getShadowsObeyLightLinking(){char buffer[4096];sprintf_s (buffer, "%s.soll",mName.c_str());return (const char*)buffer;}
	/*Objects not shadow linked to a light will not cast shadow from that light*/
	BoolID getShadowsObeyShadowLinking(){char buffer[4096];sprintf_s (buffer, "%s.sosl",mName.c_str());return (const char*)buffer;}
	/*
	When enabled will multiply the specular component with transparency for display.
	By default this is disabled to match Maya's software renderer.
	*/
	BoolID getBlendSpecularWithAlpha(){char buffer[4096];sprintf_s (buffer, "%s.bswa",mName.c_str());return (const char*)buffer;}
	/*Determines the shading model used to render with. Default is to emulate the Maya software renderer.*/
	UnsignedintID getShadingModel(){char buffer[4096];sprintf_s (buffer, "%s.shml",mName.c_str());return (const char*)buffer;}
	/*
	Determines whether to use environment map lookups which match hardware or software rendering. Matching
	software rendering is the default.
	*/
	BoolID getHardwareEnvironmentLookup(){char buffer[4096];sprintf_s (buffer, "%s.hwel",mName.c_str());return (const char*)buffer;}
protected:
	HardwareRenderGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HARDWARERENDERGLOBALS_H__
