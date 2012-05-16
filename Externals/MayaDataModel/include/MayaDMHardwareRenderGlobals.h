/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	HardwareRenderGlobals():DependNode(){}
	HardwareRenderGlobals(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "hardwareRenderGlobals", shared, create){}
	virtual ~HardwareRenderGlobals(){}

	void setColorTextureResolution(int ctrs)
	{
		if(ctrs == 128) return;
		fprintf(mFile,"\tsetAttr \".ctrs\" %i;\n", ctrs);
	}
	void setBumpTextureResolution(int btrs)
	{
		if(btrs == 256) return;
		fprintf(mFile,"\tsetAttr \".btrs\" %i;\n", btrs);
	}
	void setFrameBufferFormat(unsigned int fbfm)
	{
		if(fbfm == 0) return;
		fprintf(mFile,"\tsetAttr \".fbfm\" %i;\n", fbfm);
	}
	void setEnableHighQualityLighting(bool ehql)
	{
		if(ehql == true) return;
		fprintf(mFile,"\tsetAttr \".ehql\" %i;\n", ehql);
	}
	void setEnableAcceleratedMultiSampling(bool eams)
	{
		if(eams == true) return;
		fprintf(mFile,"\tsetAttr \".eams\" %i;\n", eams);
	}
	void setEnableEdgeAntiAliasing(bool eeaa)
	{
		if(eeaa == false) return;
		fprintf(mFile,"\tsetAttr \".eeaa\" %i;\n", eeaa);
	}
	void setEnableGeometryMask(bool engm)
	{
		if(engm == false) return;
		fprintf(mFile,"\tsetAttr \".engm\" %i;\n", engm);
	}
	void setNumberOfSamples(unsigned int mes)
	{
		if(mes == 0) return;
		fprintf(mFile,"\tsetAttr \".mes\" %i;\n", mes);
	}
	void setEnableMotionBlur(bool emb)
	{
		if(emb == false) return;
		fprintf(mFile,"\tsetAttr \".emb\" %i;\n", emb);
	}
	void setMotionBlurByFrame(float mbbf)
	{
		if(mbbf == 1.000) return;
		fprintf(mFile,"\tsetAttr \".mbbf\" %f;\n", mbbf);
	}
	void setNumberOfExposures(int mbs)
	{
		if(mbs == 3) return;
		fprintf(mFile,"\tsetAttr \".mbs\" %i;\n", mbs);
	}
	void setTransparencySorting(unsigned int trm)
	{
		if(trm == 0) return;
		fprintf(mFile,"\tsetAttr \".trm\" %i;\n", trm);
	}
	void setTransparentShadowCasting(bool tshc)
	{
		if(tshc == true) return;
		fprintf(mFile,"\tsetAttr \".tshc\" %i;\n", tshc);
	}
	void setEnableNonPowerOfTwoTexture(bool enpt)
	{
		if(enpt == true) return;
		fprintf(mFile,"\tsetAttr \".enpt\" %i;\n", enpt);
	}
	void setCulling(unsigned int clmt)
	{
		if(clmt == 0) return;
		fprintf(mFile,"\tsetAttr \".clmt\" %i;\n", clmt);
	}
	void setTextureCompression(unsigned int tcov)
	{
		if(tcov == 0) return;
		fprintf(mFile,"\tsetAttr \".tcov\" %i;\n", tcov);
	}
	void setLightIntensityThreshold(float lith)
	{
		if(lith == 0.001) return;
		fprintf(mFile,"\tsetAttr \".lith\" %f;\n", lith);
	}
	void setSmallObjectCulling(bool sobc)
	{
		if(sobc == true) return;
		fprintf(mFile,"\tsetAttr \".sobc\" %i;\n", sobc);
	}
	void setCullingThreshold(float cuth)
	{
		if(cuth == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cuth\" %f;\n", cuth);
	}
	void setGraphicsHardwareGeometryCachingData(bool hgcd)
	{
		if(hgcd == true) return;
		fprintf(mFile,"\tsetAttr \".hgcd\" %i;\n", hgcd);
	}
	void setGraphicsHardwareGeometryCachingIndexing(bool hgci)
	{
		if(hgci == true) return;
		fprintf(mFile,"\tsetAttr \".hgci\" %i;\n", hgci);
	}
	void setMaximumGeometryCacheSize(int mgcs)
	{
		if(mgcs == 64) return;
		fprintf(mFile,"\tsetAttr \".mgcs\" %i;\n", mgcs);
	}
	void setWriteAlphaAsColor(bool twa)
	{
		if(twa == false) return;
		fprintf(mFile,"\tsetAttr \".twa\" %i;\n", twa);
	}
	void setWriteZDepthAsColor(bool twz)
	{
		if(twz == false) return;
		fprintf(mFile,"\tsetAttr \".twz\" %i;\n", twz);
	}
	void setHardwareCodec(int hwcc)
	{
		if(hwcc == 1919706400) return;
		fprintf(mFile,"\tsetAttr \".hwcc\" %i;\n", hwcc);
	}
	void setHardwareDepth(int hwdp)
	{
		if(hwdp == 32) return;
		fprintf(mFile,"\tsetAttr \".hwdp\" %i;\n", hwdp);
	}
	void setHardwareQual(int hwql)
	{
		if(hwql == 1024) return;
		fprintf(mFile,"\tsetAttr \".hwql\" %i;\n", hwql);
	}
	void setHardwareFrameRate(int hwfr)
	{
		if(hwfr == 24) return;
		fprintf(mFile,"\tsetAttr \".hwfr\" %i;\n", hwfr);
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
	void setBlendSpecularWithAlpha(bool bswa)
	{
		if(bswa == false) return;
		fprintf(mFile,"\tsetAttr \".bswa\" %i;\n", bswa);
	}
	void setShadingModel(unsigned int shml)
	{
		if(shml == 0) return;
		fprintf(mFile,"\tsetAttr \".shml\" %i;\n", shml);
	}
	void setHardwareEnvironmentLookup(bool hwel)
	{
		if(hwel == false) return;
		fprintf(mFile,"\tsetAttr \".hwel\" %i;\n", hwel);
	}
	void getColorTextureResolution()const
	{
		fprintf(mFile,"\"%s.ctrs\"",mName.c_str());
	}
	void getBumpTextureResolution()const
	{
		fprintf(mFile,"\"%s.btrs\"",mName.c_str());
	}
	void getFrameBufferFormat()const
	{
		fprintf(mFile,"\"%s.fbfm\"",mName.c_str());
	}
	void getEnableHighQualityLighting()const
	{
		fprintf(mFile,"\"%s.ehql\"",mName.c_str());
	}
	void getEnableAcceleratedMultiSampling()const
	{
		fprintf(mFile,"\"%s.eams\"",mName.c_str());
	}
	void getEnableEdgeAntiAliasing()const
	{
		fprintf(mFile,"\"%s.eeaa\"",mName.c_str());
	}
	void getEnableGeometryMask()const
	{
		fprintf(mFile,"\"%s.engm\"",mName.c_str());
	}
	void getNumberOfSamples()const
	{
		fprintf(mFile,"\"%s.mes\"",mName.c_str());
	}
	void getEnableMotionBlur()const
	{
		fprintf(mFile,"\"%s.emb\"",mName.c_str());
	}
	void getMotionBlurByFrame()const
	{
		fprintf(mFile,"\"%s.mbbf\"",mName.c_str());
	}
	void getNumberOfExposures()const
	{
		fprintf(mFile,"\"%s.mbs\"",mName.c_str());
	}
	void getTransparencySorting()const
	{
		fprintf(mFile,"\"%s.trm\"",mName.c_str());
	}
	void getTransparentShadowCasting()const
	{
		fprintf(mFile,"\"%s.tshc\"",mName.c_str());
	}
	void getEnableNonPowerOfTwoTexture()const
	{
		fprintf(mFile,"\"%s.enpt\"",mName.c_str());
	}
	void getCulling()const
	{
		fprintf(mFile,"\"%s.clmt\"",mName.c_str());
	}
	void getTextureCompression()const
	{
		fprintf(mFile,"\"%s.tcov\"",mName.c_str());
	}
	void getLightIntensityThreshold()const
	{
		fprintf(mFile,"\"%s.lith\"",mName.c_str());
	}
	void getSmallObjectCulling()const
	{
		fprintf(mFile,"\"%s.sobc\"",mName.c_str());
	}
	void getCullingThreshold()const
	{
		fprintf(mFile,"\"%s.cuth\"",mName.c_str());
	}
	void getGraphicsHardwareGeometryCachingData()const
	{
		fprintf(mFile,"\"%s.hgcd\"",mName.c_str());
	}
	void getGraphicsHardwareGeometryCachingIndexing()const
	{
		fprintf(mFile,"\"%s.hgci\"",mName.c_str());
	}
	void getMaximumGeometryCacheSize()const
	{
		fprintf(mFile,"\"%s.mgcs\"",mName.c_str());
	}
	void getWriteAlphaAsColor()const
	{
		fprintf(mFile,"\"%s.twa\"",mName.c_str());
	}
	void getWriteZDepthAsColor()const
	{
		fprintf(mFile,"\"%s.twz\"",mName.c_str());
	}
	void getHardwareCodec()const
	{
		fprintf(mFile,"\"%s.hwcc\"",mName.c_str());
	}
	void getHardwareDepth()const
	{
		fprintf(mFile,"\"%s.hwdp\"",mName.c_str());
	}
	void getHardwareQual()const
	{
		fprintf(mFile,"\"%s.hwql\"",mName.c_str());
	}
	void getHardwareFrameRate()const
	{
		fprintf(mFile,"\"%s.hwfr\"",mName.c_str());
	}
	void getShadowsObeyLightLinking()const
	{
		fprintf(mFile,"\"%s.soll\"",mName.c_str());
	}
	void getShadowsObeyShadowLinking()const
	{
		fprintf(mFile,"\"%s.sosl\"",mName.c_str());
	}
	void getBlendSpecularWithAlpha()const
	{
		fprintf(mFile,"\"%s.bswa\"",mName.c_str());
	}
	void getShadingModel()const
	{
		fprintf(mFile,"\"%s.shml\"",mName.c_str());
	}
	void getHardwareEnvironmentLookup()const
	{
		fprintf(mFile,"\"%s.hwel\"",mName.c_str());
	}
protected:
	HardwareRenderGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HARDWARERENDERGLOBALS_H__
