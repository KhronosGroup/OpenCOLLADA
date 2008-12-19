/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILE_H__
#define __MayaDM_FILE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class File : public Texture2d
{
public:
public:
	File(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "file"){}
	virtual ~File(){}
	void setFileTextureName(const string& ftn)
	{
		if(ftn == "NULL") return;
		fprintf(mFile,"setAttr \".ftn\" -type \"string\" ");
		ftn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDisableFileLoad(bool dfl)
	{
		if(dfl == false) return;
		fprintf(mFile,"setAttr \".dfl\" %i;\n", dfl);

	}
	void setUseFrameExtension(bool ufe)
	{
		if(ufe == false) return;
		fprintf(mFile,"setAttr \".ufe\" %i;\n", ufe);

	}
	void setFrameExtension(int fe)
	{
		if(fe == 1) return;
		fprintf(mFile,"setAttr \".fe\" %i;\n", fe);

	}
	void setFrameOffset(int io)
	{
		if(io == 0) return;
		fprintf(mFile,"setAttr \".io\" %i;\n", io);

	}
	void setUseHardwareTextureCycling(bool uhc)
	{
		if(uhc == false) return;
		fprintf(mFile,"setAttr \".uhc\" %i;\n", uhc);

	}
	void setStartCycleExtension(int sce)
	{
		if(sce == 1) return;
		fprintf(mFile,"setAttr \".sce\" %i;\n", sce);

	}
	void setEndCycleExtension(int ece)
	{
		if(ece == 1) return;
		fprintf(mFile,"setAttr \".ece\" %i;\n", ece);

	}
	void setByCycleIncrement(int bci)
	{
		if(bci == 1) return;
		fprintf(mFile,"setAttr \".bci\" %i;\n", bci);

	}
	void setFilterType(unsigned int ft)
	{
		if(ft == 3) return;
		fprintf(mFile,"setAttr \".ft\" %i;\n", ft);

	}
	void setFilterWidth(float fw)
	{
		if(fw == 0.707) return;
		fprintf(mFile,"setAttr \".fw\" %f;\n", fw);

	}
	void setUseCache(bool uca)
	{
		if(uca == false) return;
		fprintf(mFile,"setAttr \".uca\" %i;\n", uca);

	}
	void setUseMaximumRes(bool umr)
	{
		if(umr == false) return;
		fprintf(mFile,"setAttr \".umr\" %i;\n", umr);

	}
	void setCoverage(const float2& c)
	{
		if(c == float2(1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".c\" -type \"float2\" ");
		c.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCoverageU(float cu)
	{
		if(cu == 0.0) return;
		fprintf(mFile,"setAttr \".c.cu\" %f;\n", cu);

	}
	void setCoverageV(float cv)
	{
		if(cv == 0.0) return;
		fprintf(mFile,"setAttr \".c.cv\" %f;\n", cv);

	}
	void setTranslateFrame(const float2& tf)
	{
		if(tf == float2(0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".tf\" -type \"float2\" ");
		tf.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTranslateFrameU(float tfu)
	{
		if(tfu == 0.0) return;
		fprintf(mFile,"setAttr \".tf.tfu\" %f;\n", tfu);

	}
	void setTranslateFrameV(float tfv)
	{
		if(tfv == 0.0) return;
		fprintf(mFile,"setAttr \".tf.tfv\" %f;\n", tfv);

	}
	void setRotateFrame(double rf)
	{
		if(rf == 0) return;
		fprintf(mFile,"setAttr \".rf\" %f;\n", rf);

	}
	void setDoTransform(bool dtf)
	{
		if(dtf == true) return;
		fprintf(mFile,"setAttr \".dtf\" %i;\n", dtf);

	}
	void setMirrorU(bool mu)
	{
		if(mu == false) return;
		fprintf(mFile,"setAttr \".mu\" %i;\n", mu);

	}
	void setMirrorV(bool mv)
	{
		if(mv == false) return;
		fprintf(mFile,"setAttr \".mv\" %i;\n", mv);

	}
	void setStagger(bool s)
	{
		if(s == false) return;
		fprintf(mFile,"setAttr \".s\" %i;\n", s);

	}
	void setWrapU(bool wu)
	{
		if(wu == true) return;
		fprintf(mFile,"setAttr \".wu\" %i;\n", wu);

	}
	void setWrapV(bool wv)
	{
		if(wv == true) return;
		fprintf(mFile,"setAttr \".wv\" %i;\n", wv);

	}
	void setRepeatUV(const float2& re)
	{
		if(re == float2(1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".re\" -type \"float2\" ");
		re.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRepeatU(float reu)
	{
		if(reu == 0.0) return;
		fprintf(mFile,"setAttr \".re.reu\" %f;\n", reu);

	}
	void setRepeatV(float rev)
	{
		if(rev == 0.0) return;
		fprintf(mFile,"setAttr \".re.rev\" %f;\n", rev);

	}
	void setOffset(const float2& of)
	{
		if(of == float2(0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".of\" -type \"float2\" ");
		of.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOffsetU(float ofu)
	{
		if(ofu == 0.0) return;
		fprintf(mFile,"setAttr \".of.ofu\" %f;\n", ofu);

	}
	void setOffsetV(float ofv)
	{
		if(ofv == 0.0) return;
		fprintf(mFile,"setAttr \".of.ofv\" %f;\n", ofv);

	}
	void setRotateUV(double ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"setAttr \".ro\" %f;\n", ro);

	}
	void setNoiseUV(const float2& n)
	{
		if(n == float2(0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".n\" -type \"float2\" ");
		n.write(mFile);
		fprintf(mFile,";\n");

	}
	void setNoiseU(float nu)
	{
		if(nu == 0.0) return;
		fprintf(mFile,"setAttr \".n.nu\" %f;\n", nu);

	}
	void setNoiseV(float nv)
	{
		if(nv == 0.0) return;
		fprintf(mFile,"setAttr \".n.nv\" %f;\n", nv);

	}
	void setBlurPixelation(bool blp)
	{
		if(blp == true) return;
		fprintf(mFile,"setAttr \".blp\" %i;\n", blp);

	}
	void setVertexCameraOne(const float3& vc1)
	{
		fprintf(mFile,"setAttr \".vc1\" -type \"float3\" ");
		vc1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexCameraOneX(float c1x)
	{
		if(c1x == 0.0) return;
		fprintf(mFile,"setAttr \".vc1.c1x\" %f;\n", c1x);

	}
	void setVertexCameraOneY(float c1y)
	{
		if(c1y == 0.0) return;
		fprintf(mFile,"setAttr \".vc1.c1y\" %f;\n", c1y);

	}
	void setVertexCameraOneZ(float c1z)
	{
		if(c1z == 0.0) return;
		fprintf(mFile,"setAttr \".vc1.c1z\" %f;\n", c1z);

	}
	void setVertexCameraTwo(const float3& vc2)
	{
		fprintf(mFile,"setAttr \".vc2\" -type \"float3\" ");
		vc2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexCameraTwoX(float c2x)
	{
		if(c2x == 0.0) return;
		fprintf(mFile,"setAttr \".vc2.c2x\" %f;\n", c2x);

	}
	void setVertexCameraTwoY(float c2y)
	{
		if(c2y == 0.0) return;
		fprintf(mFile,"setAttr \".vc2.c2y\" %f;\n", c2y);

	}
	void setVertexCameraTwoZ(float c2z)
	{
		if(c2z == 0.0) return;
		fprintf(mFile,"setAttr \".vc2.c2z\" %f;\n", c2z);

	}
	void setVertexCameraThree(const float3& vc3)
	{
		fprintf(mFile,"setAttr \".vc3\" -type \"float3\" ");
		vc3.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexCameraThreeX(float c3x)
	{
		if(c3x == 0.0) return;
		fprintf(mFile,"setAttr \".vc3.c3x\" %f;\n", c3x);

	}
	void setVertexCameraThreeY(float c3y)
	{
		if(c3y == 0.0) return;
		fprintf(mFile,"setAttr \".vc3.c3y\" %f;\n", c3y);

	}
	void setVertexCameraThreeZ(float c3z)
	{
		if(c3z == 0.0) return;
		fprintf(mFile,"setAttr \".vc3.c3z\" %f;\n", c3z);

	}
	void setVertexUvOne(const float2& vt1)
	{
		fprintf(mFile,"setAttr \".vt1\" -type \"float2\" ");
		vt1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexUvOneU(float t1u)
	{
		if(t1u == 0.0) return;
		fprintf(mFile,"setAttr \".vt1.t1u\" %f;\n", t1u);

	}
	void setVertexUvOneV(float t1v)
	{
		if(t1v == 0.0) return;
		fprintf(mFile,"setAttr \".vt1.t1v\" %f;\n", t1v);

	}
	void setVertexUvTwo(const float2& vt2)
	{
		fprintf(mFile,"setAttr \".vt2\" -type \"float2\" ");
		vt2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexUvTwoU(float t2u)
	{
		if(t2u == 0.0) return;
		fprintf(mFile,"setAttr \".vt2.t2u\" %f;\n", t2u);

	}
	void setVertexUvTwoV(float t2v)
	{
		if(t2v == 0.0) return;
		fprintf(mFile,"setAttr \".vt2.t2v\" %f;\n", t2v);

	}
	void setVertexUvThree(const float2& vt3)
	{
		fprintf(mFile,"setAttr \".vt3\" -type \"float2\" ");
		vt3.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexUvThreeU(float t3u)
	{
		if(t3u == 0.0) return;
		fprintf(mFile,"setAttr \".vt3.t3u\" %f;\n", t3u);

	}
	void setVertexUvThreeV(float t3v)
	{
		if(t3v == 0.0) return;
		fprintf(mFile,"setAttr \".vt3.t3v\" %f;\n", t3v);

	}
	void setObjectType(char otp)
	{
		if(otp == 0) return;
		fprintf(mFile,"setAttr \".otp\" %;\n", otp);

	}
	void setRayDepth(int rdp)
	{
		if(rdp == 0) return;
		fprintf(mFile,"setAttr \".rdp\" %i;\n", rdp);

	}
	void setPixelCenter(const float2& pct)
	{
		fprintf(mFile,"setAttr \".pct\" -type \"float2\" ");
		pct.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPixelCenterX(float pcx)
	{
		if(pcx == 0.0) return;
		fprintf(mFile,"setAttr \".pct.pcx\" %f;\n", pcx);

	}
	void setPixelCenterY(float pcy)
	{
		if(pcy == 0.0) return;
		fprintf(mFile,"setAttr \".pct.pcy\" %f;\n", pcy);

	}
	void setHdrMapping(unsigned int hm)
	{
		if(hm == 1) return;
		fprintf(mFile,"setAttr \".hm\" %i;\n", hm);

	}
	void setHdrExposure(float he)
	{
		if(he == 0.0) return;
		fprintf(mFile,"setAttr \".he\" %f;\n", he);

	}
	void setPreFilter(bool pf)
	{
		if(pf == false) return;
		fprintf(mFile,"setAttr \".pf\" %i;\n", pf);

	}
	void setPreFilterRadius(float pfr)
	{
		if(pfr == 2.0f) return;
		fprintf(mFile,"setAttr \".pfr\" %f;\n", pfr);

	}
	void getFileTextureName()
	{
		fprintf(mFile,"\"%s.ftn\"",mName.c_str());

	}
	void getDisableFileLoad()
	{
		fprintf(mFile,"\"%s.dfl\"",mName.c_str());

	}
	void getUseFrameExtension()
	{
		fprintf(mFile,"\"%s.ufe\"",mName.c_str());

	}
	void getFrameExtension()
	{
		fprintf(mFile,"\"%s.fe\"",mName.c_str());

	}
	void getFrameOffset()
	{
		fprintf(mFile,"\"%s.io\"",mName.c_str());

	}
	void getUseHardwareTextureCycling()
	{
		fprintf(mFile,"\"%s.uhc\"",mName.c_str());

	}
	void getStartCycleExtension()
	{
		fprintf(mFile,"\"%s.sce\"",mName.c_str());

	}
	void getEndCycleExtension()
	{
		fprintf(mFile,"\"%s.ece\"",mName.c_str());

	}
	void getByCycleIncrement()
	{
		fprintf(mFile,"\"%s.bci\"",mName.c_str());

	}
	void getForceSwatchGen()
	{
		fprintf(mFile,"\"%s.fsg\"",mName.c_str());

	}
	void getCoverage()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getCoverageU()
	{
		fprintf(mFile,"\"%s.c.cu\"",mName.c_str());

	}
	void getCoverageV()
	{
		fprintf(mFile,"\"%s.c.cv\"",mName.c_str());

	}
	void getTranslateFrame()
	{
		fprintf(mFile,"\"%s.tf\"",mName.c_str());

	}
	void getTranslateFrameU()
	{
		fprintf(mFile,"\"%s.tf.tfu\"",mName.c_str());

	}
	void getTranslateFrameV()
	{
		fprintf(mFile,"\"%s.tf.tfv\"",mName.c_str());

	}
	void getRotateFrame()
	{
		fprintf(mFile,"\"%s.rf\"",mName.c_str());

	}
	void getDoTransform()
	{
		fprintf(mFile,"\"%s.dtf\"",mName.c_str());

	}
	void getMirrorU()
	{
		fprintf(mFile,"\"%s.mu\"",mName.c_str());

	}
	void getMirrorV()
	{
		fprintf(mFile,"\"%s.mv\"",mName.c_str());

	}
	void getStagger()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getWrapU()
	{
		fprintf(mFile,"\"%s.wu\"",mName.c_str());

	}
	void getWrapV()
	{
		fprintf(mFile,"\"%s.wv\"",mName.c_str());

	}
	void getRepeatUV()
	{
		fprintf(mFile,"\"%s.re\"",mName.c_str());

	}
	void getRepeatU()
	{
		fprintf(mFile,"\"%s.re.reu\"",mName.c_str());

	}
	void getRepeatV()
	{
		fprintf(mFile,"\"%s.re.rev\"",mName.c_str());

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.of\"",mName.c_str());

	}
	void getOffsetU()
	{
		fprintf(mFile,"\"%s.of.ofu\"",mName.c_str());

	}
	void getOffsetV()
	{
		fprintf(mFile,"\"%s.of.ofv\"",mName.c_str());

	}
	void getRotateUV()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getNoiseUV()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getNoiseU()
	{
		fprintf(mFile,"\"%s.n.nu\"",mName.c_str());

	}
	void getNoiseV()
	{
		fprintf(mFile,"\"%s.n.nv\"",mName.c_str());

	}
	void getBlurPixelation()
	{
		fprintf(mFile,"\"%s.blp\"",mName.c_str());

	}
	void getVertexCameraOne()
	{
		fprintf(mFile,"\"%s.vc1\"",mName.c_str());

	}
	void getVertexCameraOneX()
	{
		fprintf(mFile,"\"%s.vc1.c1x\"",mName.c_str());

	}
	void getVertexCameraOneY()
	{
		fprintf(mFile,"\"%s.vc1.c1y\"",mName.c_str());

	}
	void getVertexCameraOneZ()
	{
		fprintf(mFile,"\"%s.vc1.c1z\"",mName.c_str());

	}
	void getVertexCameraTwo()
	{
		fprintf(mFile,"\"%s.vc2\"",mName.c_str());

	}
	void getVertexCameraTwoX()
	{
		fprintf(mFile,"\"%s.vc2.c2x\"",mName.c_str());

	}
	void getVertexCameraTwoY()
	{
		fprintf(mFile,"\"%s.vc2.c2y\"",mName.c_str());

	}
	void getVertexCameraTwoZ()
	{
		fprintf(mFile,"\"%s.vc2.c2z\"",mName.c_str());

	}
	void getVertexCameraThree()
	{
		fprintf(mFile,"\"%s.vc3\"",mName.c_str());

	}
	void getVertexCameraThreeX()
	{
		fprintf(mFile,"\"%s.vc3.c3x\"",mName.c_str());

	}
	void getVertexCameraThreeY()
	{
		fprintf(mFile,"\"%s.vc3.c3y\"",mName.c_str());

	}
	void getVertexCameraThreeZ()
	{
		fprintf(mFile,"\"%s.vc3.c3z\"",mName.c_str());

	}
	void getVertexUvOne()
	{
		fprintf(mFile,"\"%s.vt1\"",mName.c_str());

	}
	void getVertexUvOneU()
	{
		fprintf(mFile,"\"%s.vt1.t1u\"",mName.c_str());

	}
	void getVertexUvOneV()
	{
		fprintf(mFile,"\"%s.vt1.t1v\"",mName.c_str());

	}
	void getVertexUvTwo()
	{
		fprintf(mFile,"\"%s.vt2\"",mName.c_str());

	}
	void getVertexUvTwoU()
	{
		fprintf(mFile,"\"%s.vt2.t2u\"",mName.c_str());

	}
	void getVertexUvTwoV()
	{
		fprintf(mFile,"\"%s.vt2.t2v\"",mName.c_str());

	}
	void getVertexUvThree()
	{
		fprintf(mFile,"\"%s.vt3\"",mName.c_str());

	}
	void getVertexUvThreeU()
	{
		fprintf(mFile,"\"%s.vt3.t3u\"",mName.c_str());

	}
	void getVertexUvThreeV()
	{
		fprintf(mFile,"\"%s.vt3.t3v\"",mName.c_str());

	}
	void getObjectType()
	{
		fprintf(mFile,"\"%s.otp\"",mName.c_str());

	}
	void getRayDepth()
	{
		fprintf(mFile,"\"%s.rdp\"",mName.c_str());

	}
	void getPixelCenter()
	{
		fprintf(mFile,"\"%s.pct\"",mName.c_str());

	}
	void getPixelCenterX()
	{
		fprintf(mFile,"\"%s.pct.pcx\"",mName.c_str());

	}
	void getPixelCenterY()
	{
		fprintf(mFile,"\"%s.pct.pcy\"",mName.c_str());

	}
	void getOutSize()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getOutSizeX()
	{
		fprintf(mFile,"\"%s.os.osx\"",mName.c_str());

	}
	void getOutSizeY()
	{
		fprintf(mFile,"\"%s.os.osy\"",mName.c_str());

	}
	void getFileHasAlpha()
	{
		fprintf(mFile,"\"%s.fha\"",mName.c_str());

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
	void getPreFilter()
	{
		fprintf(mFile,"\"%s.pf\"",mName.c_str());

	}
	void getPreFilterRadius()
	{
		fprintf(mFile,"\"%s.pfr\"",mName.c_str());

	}
	void getInfoBits()
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());

	}
protected:
	File(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FILE_H__
