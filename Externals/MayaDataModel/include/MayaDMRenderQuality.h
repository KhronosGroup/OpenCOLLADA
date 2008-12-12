/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERQUALITY_H__
#define __MayaDM_RENDERQUALITY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
*/
class RenderQuality : public DependNode
{
public:
public:
	RenderQuality(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "renderQuality"){}
	virtual ~RenderQuality(){}
	/*The global maximum number of recursion levels of reflections; Ray Tracing; This maximum overrides any maximums that may have been set on a per node level.*/
	void setReflections(int rfl){if(rfl == 1) return; fprintf_s(mFile, "setAttr \".rfl\" %i;\n", rfl);}
	/*The global maximum number of recursion levels of reflections; Ray Tracing; This maximum overrides any maximums that may have been set on a per node level.*/
	void setReflections(const IntID& rfl){fprintf_s(mFile,"connectAttr \"");rfl.write(mFile);fprintf_s(mFile,"\" \"%s.rfl\";\n",mName.c_str());}
	/*The global maximum number of recursion levels of refractions; Ray Tracing; This maximum overrides any maximums that may have been set on a per node level.*/
	void setRefractions(int rfr){if(rfr == 6) return; fprintf_s(mFile, "setAttr \".rfr\" %i;\n", rfr);}
	/*The global maximum number of recursion levels of refractions; Ray Tracing; This maximum overrides any maximums that may have been set on a per node level.*/
	void setRefractions(const IntID& rfr){fprintf_s(mFile,"connectAttr \"");rfr.write(mFile);fprintf_s(mFile,"\" \"%s.rfr\";\n",mName.c_str());}
	/*The global maximum level of shadowing recursion; Ray Tracing; This maximum overrides any maximums that may have been set on a per node level.*/
	void setShadows(int sl){if(sl == 2) return; fprintf_s(mFile, "setAttr \".sl\" %i;\n", sl);}
	/*The global maximum level of shadowing recursion; Ray Tracing; This maximum overrides any maximums that may have been set on a per node level.*/
	void setShadows(const IntID& sl){fprintf_s(mFile,"connectAttr \"");sl.write(mFile);fprintf_s(mFile,"\" \"%s.sl\";\n",mName.c_str());}
	/*Ray Trace bias value to escape incorrect self-shadowing.  To be used primarily for motion blur with raytracing effects.*/
	void setRayTraceBias(float rtb){if(rtb == 0.0) return; fprintf_s(mFile, "setAttr \".rtb\" %f;\n", rtb);}
	/*Ray Trace bias value to escape incorrect self-shadowing.  To be used primarily for motion blur with raytracing effects.*/
	void setRayTraceBias(const FloatID& rtb){fprintf_s(mFile,"connectAttr \"");rtb.write(mFile);fprintf_s(mFile,"\" \"%s.rtb\";\n",mName.c_str());}
	/*The anti-aliasing quality of EAS (Abuffer); 3-low 2-medium 1-high 0-highest.*/
	void setEdgeAntiAliasing(unsigned int eaa){if(eaa == 3) return; fprintf_s(mFile, "setAttr \".eaa\" %i;\n", eaa);}
	/*The anti-aliasing quality of EAS (Abuffer); 3-low 2-medium 1-high 0-highest.*/
	void setEdgeAntiAliasing(const UnsignedintID& eaa){fprintf_s(mFile,"connectAttr \"");eaa.write(mFile);fprintf_s(mFile,"\" \"%s.eaa\";\n",mName.c_str());}
	/*If true, over-write the alpha channel with an image representing the shading sample distribution*/
	void setRenderSample(bool rsdn){if(rsdn == false) return; fprintf_s(mFile, "setAttr \".rsdn\" %i;\n", rsdn);}
	/*If true, over-write the alpha channel with an image representing the shading sample distribution*/
	void setRenderSample(const BoolID& rsdn){fprintf_s(mFile,"connectAttr \"");rsdn.write(mFile);fprintf_s(mFile,"\" \"%s.rsdn\";\n",mName.c_str());}
	/*If true, use the multi-pixel filtering. If false, use single pixel filtering.*/
	void setUseMultiPixelFilter(bool ufil){if(ufil == false) return; fprintf_s(mFile, "setAttr \".ufil\" %i;\n", ufil);}
	/*If true, use the multi-pixel filtering. If false, use single pixel filtering.*/
	void setUseMultiPixelFilter(const BoolID& ufil){fprintf_s(mFile,"connectAttr \"");ufil.write(mFile);fprintf_s(mFile,"\" \"%s.ufil\";\n",mName.c_str());}
	/*The type of multipixel filter to use*/
	void setPixelFilterType(unsigned int pft){if(pft == 1) return; fprintf_s(mFile, "setAttr \".pft\" %i;\n", pft);}
	/*The type of multipixel filter to use*/
	void setPixelFilterType(const UnsignedintID& pft){fprintf_s(mFile,"connectAttr \"");pft.write(mFile);fprintf_s(mFile,"\" \"%s.pft\";\n",mName.c_str());}
	/*The x filter size for multipixel filtering in the unit of pixel*/
	void setPixelFilterWidthX(float pfwx){if(pfwx == 2.2) return; fprintf_s(mFile, "setAttr \".pfwx\" %f;\n", pfwx);}
	/*The x filter size for multipixel filtering in the unit of pixel*/
	void setPixelFilterWidthX(const FloatID& pfwx){fprintf_s(mFile,"connectAttr \"");pfwx.write(mFile);fprintf_s(mFile,"\" \"%s.pfwx\";\n",mName.c_str());}
	/*The y filter size for multipixel filtering in the unit of pixel*/
	void setPixelFilterWidthY(float pfwy){if(pfwy == 2.2) return; fprintf_s(mFile, "setAttr \".pfwy\" %f;\n", pfwy);}
	/*The y filter size for multipixel filtering in the unit of pixel*/
	void setPixelFilterWidthY(const FloatID& pfwy){fprintf_s(mFile,"connectAttr \"");pfwy.write(mFile);fprintf_s(mFile,"\" \"%s.pfwy\";\n",mName.c_str());}
	/*The filter weight from plug in multipixel filter*/
	void setPlugInFilterWeight(float pifw){if(pifw == 1.0) return; fprintf_s(mFile, "setAttr \".pifw\" %f;\n", pifw);}
	/*The filter weight from plug in multipixel filter*/
	void setPlugInFilterWeight(const FloatID& pifw){fprintf_s(mFile,"connectAttr \"");pifw.write(mFile);fprintf_s(mFile,"\" \"%s.pifw\";\n",mName.c_str());}
	/*The global number of shading samples per surface in a pixel.*/
	void setShadingSamples(int ss){if(ss == 1) return; fprintf_s(mFile, "setAttr \".ss\" %i;\n", ss);}
	/*The global number of shading samples per surface in a pixel.*/
	void setShadingSamples(const IntID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*The max number of shading samples per surface in a pixel (for adapative shading)*/
	void setMaxShadingSamples(int mss){if(mss == 8) return; fprintf_s(mFile, "setAttr \".mss\" %i;\n", mss);}
	/*The max number of shading samples per surface in a pixel (for adapative shading)*/
	void setMaxShadingSamples(const IntID& mss){fprintf_s(mFile,"connectAttr \"");mss.write(mFile);fprintf_s(mFile,"\" \"%s.mss\";\n",mName.c_str());}
	/*The number of motion blur visibility samples, since this is a different visibility pass than EAS.*/
	void setVisibilitySamples(int mvs){if(mvs == 1) return; fprintf_s(mFile, "setAttr \".mvs\" %i;\n", mvs);}
	/*The number of motion blur visibility samples, since this is a different visibility pass than EAS.*/
	void setVisibilitySamples(const IntID& mvs){fprintf_s(mFile,"connectAttr \"");mvs.write(mFile);fprintf_s(mFile,"\" \"%s.mvs\";\n",mName.c_str());}
	/*The number of motion blur visibility samples, since this is a different visibility pass than EAS.*/
	void setMaxVisibilitySamples(int mvm){if(mvm == 4) return; fprintf_s(mFile, "setAttr \".mvm\" %i;\n", mvm);}
	/*The number of motion blur visibility samples, since this is a different visibility pass than EAS.*/
	void setMaxVisibilitySamples(const IntID& mvm){fprintf_s(mFile,"connectAttr \"");mvm.write(mFile);fprintf_s(mFile,"\" \"%s.mvm\";\n",mName.c_str());}
	/*The global number of volume shading samples.*/
	void setVolumeSamples(int vs){if(vs == 1) return; fprintf_s(mFile, "setAttr \".vs\" %i;\n", vs);}
	/*The global number of volume shading samples.*/
	void setVolumeSamples(const IntID& vs){fprintf_s(mFile,"connectAttr \"");vs.write(mFile);fprintf_s(mFile,"\" \"%s.vs\";\n",mName.c_str());}
	/*The number of particle visibility samples, since this is a different visibility pass than EAS.*/
	void setParticleSamples(int pss){if(pss == 1) return; fprintf_s(mFile, "setAttr \".pss\" %i;\n", pss);}
	/*The number of particle visibility samples, since this is a different visibility pass than EAS.*/
	void setParticleSamples(const IntID& pss){fprintf_s(mFile,"connectAttr \"");pss.write(mFile);fprintf_s(mFile,"\" \"%s.pss\";\n",mName.c_str());}
	/*How should this scene be rendered (1) - Enable secondary ray Ray Trace or (0) strictly use EAS (Abuffer).*/
	void setEnableRaytracing(bool ert){if(ert == false) return; fprintf_s(mFile, "setAttr \".ert\" %i;\n", ert);}
	/*How should this scene be rendered (1) - Enable secondary ray Ray Trace or (0) strictly use EAS (Abuffer).*/
	void setEnableRaytracing(const BoolID& ert){fprintf_s(mFile,"connectAttr \"");ert.write(mFile);fprintf_s(mFile,"\" \"%s.ert\";\n",mName.c_str());}
	/*red channel contrast threshold*/
	void setRedThreshold(float rct){if(rct == 0.4) return; fprintf_s(mFile, "setAttr \".rct\" %f;\n", rct);}
	/*red channel contrast threshold*/
	void setRedThreshold(const FloatID& rct){fprintf_s(mFile,"connectAttr \"");rct.write(mFile);fprintf_s(mFile,"\" \"%s.rct\";\n",mName.c_str());}
	/*green channel contrast threshold*/
	void setGreenThreshold(float gct){if(gct == 0.3) return; fprintf_s(mFile, "setAttr \".gct\" %f;\n", gct);}
	/*green channel contrast threshold*/
	void setGreenThreshold(const FloatID& gct){fprintf_s(mFile,"connectAttr \"");gct.write(mFile);fprintf_s(mFile,"\" \"%s.gct\";\n",mName.c_str());}
	/*green channel contrast threshold*/
	void setBlueThreshold(float bct){if(bct == 0.6) return; fprintf_s(mFile, "setAttr \".bct\" %f;\n", bct);}
	/*green channel contrast threshold*/
	void setBlueThreshold(const FloatID& bct){fprintf_s(mFile,"connectAttr \"");bct.write(mFile);fprintf_s(mFile,"\" \"%s.bct\";\n",mName.c_str());}
	/*pixel coverage contrast threshold (default is 1.0/8.0)*/
	void setCoverageThreshold(float cct){if(cct == 0.125) return; fprintf_s(mFile, "setAttr \".cct\" %f;\n", cct);}
	/*pixel coverage contrast threshold (default is 1.0/8.0)*/
	void setCoverageThreshold(const FloatID& cct){fprintf_s(mFile,"connectAttr \"");cct.write(mFile);fprintf_s(mFile,"\" \"%s.cct\";\n",mName.c_str());}
	/*The global maximum number of recursion levels of reflections; Ray Tracing; This maximum overrides any maximums that may have been set on a per node level.*/
	IntID getReflections(){char buffer[4096];sprintf_s (buffer, "%s.rfl",mName.c_str());return (const char*)buffer;}
	/*The global maximum number of recursion levels of refractions; Ray Tracing; This maximum overrides any maximums that may have been set on a per node level.*/
	IntID getRefractions(){char buffer[4096];sprintf_s (buffer, "%s.rfr",mName.c_str());return (const char*)buffer;}
	/*The global maximum level of shadowing recursion; Ray Tracing; This maximum overrides any maximums that may have been set on a per node level.*/
	IntID getShadows(){char buffer[4096];sprintf_s (buffer, "%s.sl",mName.c_str());return (const char*)buffer;}
	/*Ray Trace bias value to escape incorrect self-shadowing.  To be used primarily for motion blur with raytracing effects.*/
	FloatID getRayTraceBias(){char buffer[4096];sprintf_s (buffer, "%s.rtb",mName.c_str());return (const char*)buffer;}
	/*The anti-aliasing quality of EAS (Abuffer); 3-low 2-medium 1-high 0-highest.*/
	UnsignedintID getEdgeAntiAliasing(){char buffer[4096];sprintf_s (buffer, "%s.eaa",mName.c_str());return (const char*)buffer;}
	/*If true, over-write the alpha channel with an image representing the shading sample distribution*/
	BoolID getRenderSample(){char buffer[4096];sprintf_s (buffer, "%s.rsdn",mName.c_str());return (const char*)buffer;}
	/*If true, use the multi-pixel filtering. If false, use single pixel filtering.*/
	BoolID getUseMultiPixelFilter(){char buffer[4096];sprintf_s (buffer, "%s.ufil",mName.c_str());return (const char*)buffer;}
	/*The type of multipixel filter to use*/
	UnsignedintID getPixelFilterType(){char buffer[4096];sprintf_s (buffer, "%s.pft",mName.c_str());return (const char*)buffer;}
	/*The x filter size for multipixel filtering in the unit of pixel*/
	FloatID getPixelFilterWidthX(){char buffer[4096];sprintf_s (buffer, "%s.pfwx",mName.c_str());return (const char*)buffer;}
	/*The y filter size for multipixel filtering in the unit of pixel*/
	FloatID getPixelFilterWidthY(){char buffer[4096];sprintf_s (buffer, "%s.pfwy",mName.c_str());return (const char*)buffer;}
	/*The filter weight from plug in multipixel filter*/
	FloatID getPlugInFilterWeight(){char buffer[4096];sprintf_s (buffer, "%s.pifw",mName.c_str());return (const char*)buffer;}
	/*The global number of shading samples per surface in a pixel.*/
	IntID getShadingSamples(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*The max number of shading samples per surface in a pixel (for adapative shading)*/
	IntID getMaxShadingSamples(){char buffer[4096];sprintf_s (buffer, "%s.mss",mName.c_str());return (const char*)buffer;}
	/*The number of motion blur visibility samples, since this is a different visibility pass than EAS.*/
	IntID getVisibilitySamples(){char buffer[4096];sprintf_s (buffer, "%s.mvs",mName.c_str());return (const char*)buffer;}
	/*The number of motion blur visibility samples, since this is a different visibility pass than EAS.*/
	IntID getMaxVisibilitySamples(){char buffer[4096];sprintf_s (buffer, "%s.mvm",mName.c_str());return (const char*)buffer;}
	/*The global number of volume shading samples.*/
	IntID getVolumeSamples(){char buffer[4096];sprintf_s (buffer, "%s.vs",mName.c_str());return (const char*)buffer;}
	/*The number of particle visibility samples, since this is a different visibility pass than EAS.*/
	IntID getParticleSamples(){char buffer[4096];sprintf_s (buffer, "%s.pss",mName.c_str());return (const char*)buffer;}
	/*How should this scene be rendered (1) - Enable secondary ray Ray Trace or (0) strictly use EAS (Abuffer).*/
	BoolID getEnableRaytracing(){char buffer[4096];sprintf_s (buffer, "%s.ert",mName.c_str());return (const char*)buffer;}
	/*red channel contrast threshold*/
	FloatID getRedThreshold(){char buffer[4096];sprintf_s (buffer, "%s.rct",mName.c_str());return (const char*)buffer;}
	/*green channel contrast threshold*/
	FloatID getGreenThreshold(){char buffer[4096];sprintf_s (buffer, "%s.gct",mName.c_str());return (const char*)buffer;}
	/*green channel contrast threshold*/
	FloatID getBlueThreshold(){char buffer[4096];sprintf_s (buffer, "%s.bct",mName.c_str());return (const char*)buffer;}
	/*pixel coverage contrast threshold (default is 1.0/8.0)*/
	FloatID getCoverageThreshold(){char buffer[4096];sprintf_s (buffer, "%s.cct",mName.c_str());return (const char*)buffer;}
protected:
	RenderQuality(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RENDERQUALITY_H__
