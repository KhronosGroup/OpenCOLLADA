/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SHADERGLOW_H__
#define __MayaDM_SHADERGLOW_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
      This node is for environment shader-glow.
      Note, its not a true dependency node, it has attributes
      but no computePlug.  Shader glow can be evaluated by
      calling computeOpticalFX.  Hooking this up in a network
        will not work, it only makes sense when it is connected
        to the postProcesses node.

</pre></p>
*/
class ShaderGlow : public DependNode
{
public:
public:
	ShaderGlow(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "shaderGlow"){}
	virtual ~ShaderGlow(){}
	/*Type of glow: 0 = None, 1 = Linear, 2 = Exponential, 3 = Ball, 4 = Lens Flare, 5= Rim.*/
	void setGlowType(unsigned int gt){if(gt == 1) return; fprintf_s(mFile, "setAttr \".gt\" %i;\n", gt);}
	/*Type of glow: 0 = None, 1 = Linear, 2 = Exponential, 3 = Ball, 4 = Lens Flare, 5= Rim.*/
	void setGlowType(const UnsignedintID& gt){fprintf_s(mFile,"connectAttr \"");gt.write(mFile);fprintf_s(mFile,"\" \"%s.gt\";\n",mName.c_str());}
	/*Type of halo: 0 = None, 1 = Linear, 2 = Exponential, 3 = Ball, 4 = Lens Flare, 5= Rim.*/
	void setHaloType(unsigned int ht){if(ht == 1) return; fprintf_s(mFile, "setAttr \".ht\" %i;\n", ht);}
	/*Type of halo: 0 = None, 1 = Linear, 2 = Exponential, 3 = Ball, 4 = Lens Flare, 5= Rim.*/
	void setHaloType(const UnsignedintID& ht){fprintf_s(mFile,"connectAttr \"");ht.write(mFile);fprintf_s(mFile,"\" \"%s.ht\";\n",mName.c_str());}
	/*Halo intensity.*/
	void setGlowIntensity(float gi){if(gi == 1.0) return; fprintf_s(mFile, "setAttr \".gi\" %f;\n", gi);}
	/*Halo intensity.*/
	void setGlowIntensity(const FloatID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.gi\";\n",mName.c_str());}
	/*The glow color.*/
	void setGlowColor(const float3& gc){if(gc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".gc\" -type \"float3\" ");gc.write(mFile);fprintf_s(mFile,";\n");}
	/*The glow color.*/
	void setGlowColor(const Float3ID& gc){fprintf_s(mFile,"connectAttr \"");gc.write(mFile);fprintf_s(mFile,"\" \"%s.gc\";\n",mName.c_str());}
	/*The red component of the glow color.*/
	void setGlowColorR(float gr){if(gr == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gr\" %f;\n", gr);}
	/*The red component of the glow color.*/
	void setGlowColorR(const FloatID& gr){fprintf_s(mFile,"connectAttr \"");gr.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gr\";\n",mName.c_str());}
	/*The green component of the glow color.*/
	void setGlowColorG(float gg){if(gg == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gg\" %f;\n", gg);}
	/*The green component of the glow color.*/
	void setGlowColorG(const FloatID& gg){fprintf_s(mFile,"connectAttr \"");gg.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gg\";\n",mName.c_str());}
	/*The blue component of the glow color.*/
	void setGlowColorB(float gb){if(gb == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gb\" %f;\n", gb);}
	/*The blue component of the glow color.*/
	void setGlowColorB(const FloatID& gb){fprintf_s(mFile,"connectAttr \"");gb.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gb\";\n",mName.c_str());}
	/*Glow spread.*/
	void setGlowSpread(float gs){if(gs == 0.05) return; fprintf_s(mFile, "setAttr \".gs\" %f;\n", gs);}
	/*Glow spread.*/
	void setGlowSpread(const FloatID& gs){fprintf_s(mFile,"connectAttr \"");gs.write(mFile);fprintf_s(mFile,"\" \"%s.gs\";\n",mName.c_str());}
	/*Glow eccentricity.*/
	void setGlowEccentricity(float gecc){if(gecc == 0.1) return; fprintf_s(mFile, "setAttr \".gecc\" %f;\n", gecc);}
	/*Glow eccentricity.*/
	void setGlowEccentricity(const FloatID& gecc){fprintf_s(mFile,"connectAttr \"");gecc.write(mFile);fprintf_s(mFile,"\" \"%s.gecc\";\n",mName.c_str());}
	/*Glow radial noise.*/
	void setGlowRadialNoise(float gn){if(gn == 0.0) return; fprintf_s(mFile, "setAttr \".gn\" %f;\n", gn);}
	/*Glow radial noise.*/
	void setGlowRadialNoise(const FloatID& gn){fprintf_s(mFile,"connectAttr \"");gn.write(mFile);fprintf_s(mFile,"\" \"%s.gn\";\n",mName.c_str());}
	/*Glow star level.*/
	void setGlowStarLevel(float gv){if(gv == 0.0) return; fprintf_s(mFile, "setAttr \".gv\" %f;\n", gv);}
	/*Glow star level.*/
	void setGlowStarLevel(const FloatID& gv){fprintf_s(mFile,"connectAttr \"");gv.write(mFile);fprintf_s(mFile,"\" \"%s.gv\";\n",mName.c_str());}
	/*Glow opacity.*/
	void setGlowOpacity(float go){if(go == 0.0) return; fprintf_s(mFile, "setAttr \".go\" %f;\n", go);}
	/*Glow opacity.*/
	void setGlowOpacity(const FloatID& go){fprintf_s(mFile,"connectAttr \"");go.write(mFile);fprintf_s(mFile,"\" \"%s.go\";\n",mName.c_str());}
	/*Glow ring intensity.*/
	void setGlowRingIntensity(float gri){if(gri == 0.0) return; fprintf_s(mFile, "setAttr \".gri\" %f;\n", gri);}
	/*Glow ring intensity.*/
	void setGlowRingIntensity(const FloatID& gri){fprintf_s(mFile,"connectAttr \"");gri.write(mFile);fprintf_s(mFile,"\" \"%s.gri\";\n",mName.c_str());}
	/*Glow ring frequency.*/
	void setGlowRingFrequency(float grf){if(grf == 0.5) return; fprintf_s(mFile, "setAttr \".grf\" %f;\n", grf);}
	/*Glow ring frequency.*/
	void setGlowRingFrequency(const FloatID& grf){fprintf_s(mFile,"connectAttr \"");grf.write(mFile);fprintf_s(mFile,"\" \"%s.grf\";\n",mName.c_str());}
	/*Glow filter width.*/
	void setGlowFilterWidth(int gfw){if(gfw == 1) return; fprintf_s(mFile, "setAttr \".gfw\" %i;\n", gfw);}
	/*Glow filter width.*/
	void setGlowFilterWidth(const IntID& gfw){fprintf_s(mFile,"connectAttr \"");gfw.write(mFile);fprintf_s(mFile,"\" \"%s.gfw\";\n",mName.c_str());}
	/*Halo intensity.*/
	void setHaloIntensity(float hi){if(hi == 1.0) return; fprintf_s(mFile, "setAttr \".hi\" %f;\n", hi);}
	/*Halo intensity.*/
	void setHaloIntensity(const FloatID& hi){fprintf_s(mFile,"connectAttr \"");hi.write(mFile);fprintf_s(mFile,"\" \"%s.hi\";\n",mName.c_str());}
	/*The halo color.*/
	void setHaloColor(const float3& hc){if(hc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".hc\" -type \"float3\" ");hc.write(mFile);fprintf_s(mFile,";\n");}
	/*The halo color.*/
	void setHaloColor(const Float3ID& hc){fprintf_s(mFile,"connectAttr \"");hc.write(mFile);fprintf_s(mFile,"\" \"%s.hc\";\n",mName.c_str());}
	/*The red component of the halo color.*/
	void setHaloColorR(float hr){if(hr == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hr\" %f;\n", hr);}
	/*The red component of the halo color.*/
	void setHaloColorR(const FloatID& hr){fprintf_s(mFile,"connectAttr \"");hr.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hr\";\n",mName.c_str());}
	/*The red component of the halo color.*/
	void setHaloColorG(float hg){if(hg == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hg\" %f;\n", hg);}
	/*The red component of the halo color.*/
	void setHaloColorG(const FloatID& hg){fprintf_s(mFile,"connectAttr \"");hg.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hg\";\n",mName.c_str());}
	/*The red component of the halo color.*/
	void setHaloColorB(float hb){if(hb == 0.0) return; fprintf_s(mFile, "setAttr \".hc.hb\" %f;\n", hb);}
	/*The red component of the halo color.*/
	void setHaloColorB(const FloatID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.hc.hb\";\n",mName.c_str());}
	/*Halo spread.*/
	void setHaloSpread(float hs){if(hs == 0.3) return; fprintf_s(mFile, "setAttr \".hs\" %f;\n", hs);}
	/*Halo spread.*/
	void setHaloSpread(const FloatID& hs){fprintf_s(mFile,"connectAttr \"");hs.write(mFile);fprintf_s(mFile,"\" \"%s.hs\";\n",mName.c_str());}
	/*Halo eccentricity.*/
	void setHaloEccentricity(float hecc){if(hecc == 0.1) return; fprintf_s(mFile, "setAttr \".hecc\" %f;\n", hecc);}
	/*Halo eccentricity.*/
	void setHaloEccentricity(const FloatID& hecc){fprintf_s(mFile,"connectAttr \"");hecc.write(mFile);fprintf_s(mFile,"\" \"%s.hecc\";\n",mName.c_str());}
	/*Halo radial noise.*/
	void setHaloRadialNoise(float hn){if(hn == 0.0) return; fprintf_s(mFile, "setAttr \".hn\" %f;\n", hn);}
	/*Halo radial noise.*/
	void setHaloRadialNoise(const FloatID& hn){fprintf_s(mFile,"connectAttr \"");hn.write(mFile);fprintf_s(mFile,"\" \"%s.hn\";\n",mName.c_str());}
	/*Halo star level.*/
	void setHaloStarLevel(float hv){if(hv == 0.0) return; fprintf_s(mFile, "setAttr \".hv\" %f;\n", hv);}
	/*Halo star level.*/
	void setHaloStarLevel(const FloatID& hv){fprintf_s(mFile,"connectAttr \"");hv.write(mFile);fprintf_s(mFile,"\" \"%s.hv\";\n",mName.c_str());}
	/*Halo opacity.*/
	void setHaloOpacity(float ho){if(ho == 0.0) return; fprintf_s(mFile, "setAttr \".ho\" %f;\n", ho);}
	/*Halo opacity.*/
	void setHaloOpacity(const FloatID& ho){fprintf_s(mFile,"connectAttr \"");ho.write(mFile);fprintf_s(mFile,"\" \"%s.ho\";\n",mName.c_str());}
	/*Halo ring intensity.*/
	void setHaloRingIntensity(float hri){if(hri == 0.0) return; fprintf_s(mFile, "setAttr \".hri\" %f;\n", hri);}
	/*Halo ring intensity.*/
	void setHaloRingIntensity(const FloatID& hri){fprintf_s(mFile,"connectAttr \"");hri.write(mFile);fprintf_s(mFile,"\" \"%s.hri\";\n",mName.c_str());}
	/*Halo ring frequency.*/
	void setHaloRingFrequency(float hrf){if(hrf == 0.5) return; fprintf_s(mFile, "setAttr \".hrf\" %f;\n", hrf);}
	/*Halo ring frequency.*/
	void setHaloRingFrequency(const FloatID& hrf){fprintf_s(mFile,"connectAttr \"");hrf.write(mFile);fprintf_s(mFile,"\" \"%s.hrf\";\n",mName.c_str());}
	/*Halo filter width.*/
	void setHaloFilterWidth(int hfw){if(hfw == 1) return; fprintf_s(mFile, "setAttr \".hfw\" %i;\n", hfw);}
	/*Halo filter width.*/
	void setHaloFilterWidth(const IntID& hfw){fprintf_s(mFile,"connectAttr \"");hfw.write(mFile);fprintf_s(mFile,"\" \"%s.hfw\";\n",mName.c_str());}
	/*NoiseThreshold.*/
	void setQuality(float qual){if(qual == 0.5) return; fprintf_s(mFile, "setAttr \".qual\" %f;\n", qual);}
	/*NoiseThreshold.*/
	void setQuality(const FloatID& qual){fprintf_s(mFile,"connectAttr \"");qual.write(mFile);fprintf_s(mFile,"\" \"%s.qual\";\n",mName.c_str());}
	/*NoiseThreshold.*/
	void setThreshold(float th){if(th == 0.0) return; fprintf_s(mFile, "setAttr \".th\" %f;\n", th);}
	/*NoiseThreshold.*/
	void setThreshold(const FloatID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th\";\n",mName.c_str());}
	/*Radial frequency.*/
	void setRadialFrequency(float rf){if(rf == 0.5) return; fprintf_s(mFile, "setAttr \".rf\" %f;\n", rf);}
	/*Radial frequency.*/
	void setRadialFrequency(const FloatID& rf){fprintf_s(mFile,"connectAttr \"");rf.write(mFile);fprintf_s(mFile,"\" \"%s.rf\";\n",mName.c_str());}
	/*Star points.*/
	void setStarPoints(float sp){if(sp == 4.0) return; fprintf_s(mFile, "setAttr \".sp\" %f;\n", sp);}
	/*Star points.*/
	void setStarPoints(const FloatID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*Rotation.*/
	void setRotation(float ra){if(ra == 0.0) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*Rotation.*/
	void setRotation(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*Auto exposure turned on?*/
	void setAutoExposure(bool ae){if(ae == true) return; fprintf_s(mFile, "setAttr \".ae\" %i;\n", ae);}
	/*Auto exposure turned on?*/
	void setAutoExposure(const BoolID& ae){fprintf_s(mFile,"connectAttr \"");ae.write(mFile);fprintf_s(mFile,"\" \"%s.ae\";\n",mName.c_str());}
	/*Type of glow: 0 = None, 1 = Linear, 2 = Exponential, 3 = Ball, 4 = Lens Flare, 5= Rim.*/
	UnsignedintID getGlowType(){char buffer[4096];sprintf_s (buffer, "%s.gt",mName.c_str());return (const char*)buffer;}
	/*Type of halo: 0 = None, 1 = Linear, 2 = Exponential, 3 = Ball, 4 = Lens Flare, 5= Rim.*/
	UnsignedintID getHaloType(){char buffer[4096];sprintf_s (buffer, "%s.ht",mName.c_str());return (const char*)buffer;}
	/*Halo intensity.*/
	FloatID getGlowIntensity(){char buffer[4096];sprintf_s (buffer, "%s.gi",mName.c_str());return (const char*)buffer;}
	/*The glow color.*/
	Float3ID getGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.gc",mName.c_str());return (const char*)buffer;}
	/*The red component of the glow color.*/
	FloatID getGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.gc.gr",mName.c_str());return (const char*)buffer;}
	/*The green component of the glow color.*/
	FloatID getGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.gc.gg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the glow color.*/
	FloatID getGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.gc.gb",mName.c_str());return (const char*)buffer;}
	/*Glow spread.*/
	FloatID getGlowSpread(){char buffer[4096];sprintf_s (buffer, "%s.gs",mName.c_str());return (const char*)buffer;}
	/*Glow eccentricity.*/
	FloatID getGlowEccentricity(){char buffer[4096];sprintf_s (buffer, "%s.gecc",mName.c_str());return (const char*)buffer;}
	/*Glow radial noise.*/
	FloatID getGlowRadialNoise(){char buffer[4096];sprintf_s (buffer, "%s.gn",mName.c_str());return (const char*)buffer;}
	/*Glow star level.*/
	FloatID getGlowStarLevel(){char buffer[4096];sprintf_s (buffer, "%s.gv",mName.c_str());return (const char*)buffer;}
	/*Glow opacity.*/
	FloatID getGlowOpacity(){char buffer[4096];sprintf_s (buffer, "%s.go",mName.c_str());return (const char*)buffer;}
	/*Glow ring intensity.*/
	FloatID getGlowRingIntensity(){char buffer[4096];sprintf_s (buffer, "%s.gri",mName.c_str());return (const char*)buffer;}
	/*Glow ring frequency.*/
	FloatID getGlowRingFrequency(){char buffer[4096];sprintf_s (buffer, "%s.grf",mName.c_str());return (const char*)buffer;}
	/*Glow filter width.*/
	IntID getGlowFilterWidth(){char buffer[4096];sprintf_s (buffer, "%s.gfw",mName.c_str());return (const char*)buffer;}
	/*Halo intensity.*/
	FloatID getHaloIntensity(){char buffer[4096];sprintf_s (buffer, "%s.hi",mName.c_str());return (const char*)buffer;}
	/*The halo color.*/
	Float3ID getHaloColor(){char buffer[4096];sprintf_s (buffer, "%s.hc",mName.c_str());return (const char*)buffer;}
	/*The red component of the halo color.*/
	FloatID getHaloColorR(){char buffer[4096];sprintf_s (buffer, "%s.hc.hr",mName.c_str());return (const char*)buffer;}
	/*The red component of the halo color.*/
	FloatID getHaloColorG(){char buffer[4096];sprintf_s (buffer, "%s.hc.hg",mName.c_str());return (const char*)buffer;}
	/*The red component of the halo color.*/
	FloatID getHaloColorB(){char buffer[4096];sprintf_s (buffer, "%s.hc.hb",mName.c_str());return (const char*)buffer;}
	/*Halo spread.*/
	FloatID getHaloSpread(){char buffer[4096];sprintf_s (buffer, "%s.hs",mName.c_str());return (const char*)buffer;}
	/*Halo eccentricity.*/
	FloatID getHaloEccentricity(){char buffer[4096];sprintf_s (buffer, "%s.hecc",mName.c_str());return (const char*)buffer;}
	/*Halo radial noise.*/
	FloatID getHaloRadialNoise(){char buffer[4096];sprintf_s (buffer, "%s.hn",mName.c_str());return (const char*)buffer;}
	/*Halo star level.*/
	FloatID getHaloStarLevel(){char buffer[4096];sprintf_s (buffer, "%s.hv",mName.c_str());return (const char*)buffer;}
	/*Halo opacity.*/
	FloatID getHaloOpacity(){char buffer[4096];sprintf_s (buffer, "%s.ho",mName.c_str());return (const char*)buffer;}
	/*Halo ring intensity.*/
	FloatID getHaloRingIntensity(){char buffer[4096];sprintf_s (buffer, "%s.hri",mName.c_str());return (const char*)buffer;}
	/*Halo ring frequency.*/
	FloatID getHaloRingFrequency(){char buffer[4096];sprintf_s (buffer, "%s.hrf",mName.c_str());return (const char*)buffer;}
	/*Halo filter width.*/
	IntID getHaloFilterWidth(){char buffer[4096];sprintf_s (buffer, "%s.hfw",mName.c_str());return (const char*)buffer;}
	/*NoiseThreshold.*/
	FloatID getQuality(){char buffer[4096];sprintf_s (buffer, "%s.qual",mName.c_str());return (const char*)buffer;}
	/*NoiseThreshold.*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.th",mName.c_str());return (const char*)buffer;}
	/*Radial frequency.*/
	FloatID getRadialFrequency(){char buffer[4096];sprintf_s (buffer, "%s.rf",mName.c_str());return (const char*)buffer;}
	/*Star points.*/
	FloatID getStarPoints(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*Rotation.*/
	FloatID getRotation(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*Auto exposure turned on?*/
	BoolID getAutoExposure(){char buffer[4096];sprintf_s (buffer, "%s.ae",mName.c_str());return (const char*)buffer;}
protected:
	ShaderGlow(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SHADERGLOW_H__
