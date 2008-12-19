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
class HardwareRenderGlobals : public DependNode
{
public:
public:
	HardwareRenderGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hardwareRenderGlobals"){}
	virtual ~HardwareRenderGlobals(){}
	void setColorTextureResolution(int ctrs)
	{
		if(ctrs == 128) return;
		fprintf(mFile,"setAttr \".ctrs\" %i;\n", ctrs);

	}
	void setBumpTextureResolution(int btrs)
	{
		if(btrs == 256) return;
		fprintf(mFile,"setAttr \".btrs\" %i;\n", btrs);

	}
	void setFrameBufferFormat(unsigned int fbfm)
	{
		if(fbfm == 0) return;
		fprintf(mFile,"setAttr \".fbfm\" %i;\n", fbfm);

	}
	void setEnableHighQualityLighting(bool ehql)
	{
		if(ehql == true) return;
		fprintf(mFile,"setAttr \".ehql\" %i;\n", ehql);

	}
	void setEnableAcceleratedMultiSampling(bool eams)
	{
		if(eams == true) return;
		fprintf(mFile,"setAttr \".eams\" %i;\n", eams);

	}
	void setEnableEdgeAntiAliasing(bool eeaa)
	{
		if(eeaa == false) return;
		fprintf(mFile,"setAttr \".eeaa\" %i;\n", eeaa);

	}
	void setEnableGeometryMask(bool engm)
	{
		if(engm == false) return;
		fprintf(mFile,"setAttr \".engm\" %i;\n", engm);

	}
	void setNumberOfSamples(unsigned int mes)
	{
		if(mes == 0) return;
		fprintf(mFile,"setAttr \".mes\" %i;\n", mes);

	}
	void setEnableMotionBlur(bool emb)
	{
		if(emb == false) return;
		fprintf(mFile,"setAttr \".emb\" %i;\n", emb);

	}
	void setMotionBlurByFrame(float mbbf)
	{
		if(mbbf == 1.000) return;
		fprintf(mFile,"setAttr \".mbbf\" %f;\n", mbbf);

	}
	void setNumberOfExposures(int mbs)
	{
		if(mbs == 3) return;
		fprintf(mFile,"setAttr \".mbs\" %i;\n", mbs);

	}
	void setTransparencySorting(unsigned int trm)
	{
		if(trm == 0) return;
		fprintf(mFile,"setAttr \".trm\" %i;\n", trm);

	}
	void setTransparentShadowCasting(bool tshc)
	{
		if(tshc == true) return;
		fprintf(mFile,"setAttr \".tshc\" %i;\n", tshc);

	}
	void setEnableNonPowerOfTwoTexture(bool enpt)
	{
		if(enpt == true) return;
		fprintf(mFile,"setAttr \".enpt\" %i;\n", enpt);

	}
	void setCulling(unsigned int clmt)
	{
		if(clmt == 0) return;
		fprintf(mFile,"setAttr \".clmt\" %i;\n", clmt);

	}
	void setTextureCompression(unsigned int tcov)
	{
		if(tcov == 0) return;
		fprintf(mFile,"setAttr \".tcov\" %i;\n", tcov);

	}
	void setLightIntensityThreshold(float lith)
	{
		if(lith == 0.001) return;
		fprintf(mFile,"setAttr \".lith\" %f;\n", lith);

	}
	void setSmallObjectCulling(bool sobc)
	{
		if(sobc == true) return;
		fprintf(mFile,"setAttr \".sobc\" %i;\n", sobc);

	}
	void setCullingThreshold(float cuth)
	{
		if(cuth == 0.0) return;
		fprintf(mFile,"setAttr \".cuth\" %f;\n", cuth);

	}
	void setGraphicsHardwareGeometryCachingData(bool hgcd)
	{
		if(hgcd == true) return;
		fprintf(mFile,"setAttr \".hgcd\" %i;\n", hgcd);

	}
	void setGraphicsHardwareGeometryCachingIndexing(bool hgci)
	{
		if(hgci == true) return;
		fprintf(mFile,"setAttr \".hgci\" %i;\n", hgci);

	}
	void setMaximumGeometryCacheSize(int mgcs)
	{
		if(mgcs == 64) return;
		fprintf(mFile,"setAttr \".mgcs\" %i;\n", mgcs);

	}
	void setWriteAlphaAsColor(bool twa)
	{
		if(twa == false) return;
		fprintf(mFile,"setAttr \".twa\" %i;\n", twa);

	}
	void setWriteZDepthAsColor(bool twz)
	{
		if(twz == false) return;
		fprintf(mFile,"setAttr \".twz\" %i;\n", twz);

	}
	void setHardwareCodec(int hwcc)
	{
		if(hwcc == 1919706400) return;
		fprintf(mFile,"setAttr \".hwcc\" %i;\n", hwcc);

	}
	void setHardwareDepth(int hwdp)
	{
		if(hwdp == 32) return;
		fprintf(mFile,"setAttr \".hwdp\" %i;\n", hwdp);

	}
	void setHardwareQual(int hwql)
	{
		if(hwql == 1024) return;
		fprintf(mFile,"setAttr \".hwql\" %i;\n", hwql);

	}
	void setHardwareFrameRate(int hwfr)
	{
		if(hwfr == 24) return;
		fprintf(mFile,"setAttr \".hwfr\" %i;\n", hwfr);

	}
	void setShadowsObeyLightLinking(bool soll)
	{
		if(soll == true) return;
		fprintf(mFile,"setAttr \".soll\" %i;\n", soll);

	}
	void setShadowsObeyShadowLinking(bool sosl)
	{
		if(sosl == false) return;
		fprintf(mFile,"setAttr \".sosl\" %i;\n", sosl);

	}
	void setBlendSpecularWithAlpha(bool bswa)
	{
		if(bswa == false) return;
		fprintf(mFile,"setAttr \".bswa\" %i;\n", bswa);

	}
	void setShadingModel(unsigned int shml)
	{
		if(shml == 0) return;
		fprintf(mFile,"setAttr \".shml\" %i;\n", shml);

	}
	void setHardwareEnvironmentLookup(bool hwel)
	{
		if(hwel == false) return;
		fprintf(mFile,"setAttr \".hwel\" %i;\n", hwel);

	}
	void getColorTextureResolution()
	{
		fprintf(mFile,"\"%s.ctrs\"",mName.c_str());

	}
	void getBumpTextureResolution()
	{
		fprintf(mFile,"\"%s.btrs\"",mName.c_str());

	}
	void getFrameBufferFormat()
	{
		fprintf(mFile,"\"%s.fbfm\"",mName.c_str());

	}
	void getEnableHighQualityLighting()
	{
		fprintf(mFile,"\"%s.ehql\"",mName.c_str());

	}
	void getEnableAcceleratedMultiSampling()
	{
		fprintf(mFile,"\"%s.eams\"",mName.c_str());

	}
	void getEnableEdgeAntiAliasing()
	{
		fprintf(mFile,"\"%s.eeaa\"",mName.c_str());

	}
	void getEnableGeometryMask()
	{
		fprintf(mFile,"\"%s.engm\"",mName.c_str());

	}
	void getNumberOfSamples()
	{
		fprintf(mFile,"\"%s.mes\"",mName.c_str());

	}
	void getEnableMotionBlur()
	{
		fprintf(mFile,"\"%s.emb\"",mName.c_str());

	}
	void getMotionBlurByFrame()
	{
		fprintf(mFile,"\"%s.mbbf\"",mName.c_str());

	}
	void getNumberOfExposures()
	{
		fprintf(mFile,"\"%s.mbs\"",mName.c_str());

	}
	void getTransparencySorting()
	{
		fprintf(mFile,"\"%s.trm\"",mName.c_str());

	}
	void getTransparentShadowCasting()
	{
		fprintf(mFile,"\"%s.tshc\"",mName.c_str());

	}
	void getEnableNonPowerOfTwoTexture()
	{
		fprintf(mFile,"\"%s.enpt\"",mName.c_str());

	}
	void getCulling()
	{
		fprintf(mFile,"\"%s.clmt\"",mName.c_str());

	}
	void getTextureCompression()
	{
		fprintf(mFile,"\"%s.tcov\"",mName.c_str());

	}
	void getLightIntensityThreshold()
	{
		fprintf(mFile,"\"%s.lith\"",mName.c_str());

	}
	void getSmallObjectCulling()
	{
		fprintf(mFile,"\"%s.sobc\"",mName.c_str());

	}
	void getCullingThreshold()
	{
		fprintf(mFile,"\"%s.cuth\"",mName.c_str());

	}
	void getGraphicsHardwareGeometryCachingData()
	{
		fprintf(mFile,"\"%s.hgcd\"",mName.c_str());

	}
	void getGraphicsHardwareGeometryCachingIndexing()
	{
		fprintf(mFile,"\"%s.hgci\"",mName.c_str());

	}
	void getMaximumGeometryCacheSize()
	{
		fprintf(mFile,"\"%s.mgcs\"",mName.c_str());

	}
	void getWriteAlphaAsColor()
	{
		fprintf(mFile,"\"%s.twa\"",mName.c_str());

	}
	void getWriteZDepthAsColor()
	{
		fprintf(mFile,"\"%s.twz\"",mName.c_str());

	}
	void getHardwareCodec()
	{
		fprintf(mFile,"\"%s.hwcc\"",mName.c_str());

	}
	void getHardwareDepth()
	{
		fprintf(mFile,"\"%s.hwdp\"",mName.c_str());

	}
	void getHardwareQual()
	{
		fprintf(mFile,"\"%s.hwql\"",mName.c_str());

	}
	void getHardwareFrameRate()
	{
		fprintf(mFile,"\"%s.hwfr\"",mName.c_str());

	}
	void getShadowsObeyLightLinking()
	{
		fprintf(mFile,"\"%s.soll\"",mName.c_str());

	}
	void getShadowsObeyShadowLinking()
	{
		fprintf(mFile,"\"%s.sosl\"",mName.c_str());

	}
	void getBlendSpecularWithAlpha()
	{
		fprintf(mFile,"\"%s.bswa\"",mName.c_str());

	}
	void getShadingModel()
	{
		fprintf(mFile,"\"%s.shml\"",mName.c_str());

	}
	void getHardwareEnvironmentLookup()
	{
		fprintf(mFile,"\"%s.hwel\"",mName.c_str());

	}
protected:
	HardwareRenderGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HARDWARERENDERGLOBALS_H__
