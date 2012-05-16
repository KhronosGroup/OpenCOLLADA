/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PLACE2DTEXTURE_H__
#define __MayaDM_PLACE2DTEXTURE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Place2dTexture : public DependNode
{
public:
public:

	Place2dTexture():DependNode(){}
	Place2dTexture(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "place2dTexture", shared, create){}
	virtual ~Place2dTexture(){}

	void setVertexUvOne(const float2& vt1)
	{
		fprintf(mFile,"\tsetAttr \".vt1\" -type \"float2\" ");
		vt1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexUvOneU(float t1u)
	{
		if(t1u == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt1.t1u\" %f;\n", t1u);
	}
	void setVertexUvOneV(float t1v)
	{
		if(t1v == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt1.t1v\" %f;\n", t1v);
	}
	void setVertexUvTwo(const float2& vt2)
	{
		fprintf(mFile,"\tsetAttr \".vt2\" -type \"float2\" ");
		vt2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexUvTwoU(float t2u)
	{
		if(t2u == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt2.t2u\" %f;\n", t2u);
	}
	void setVertexUvTwoV(float t2v)
	{
		if(t2v == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt2.t2v\" %f;\n", t2v);
	}
	void setVertexUvThree(const float2& vt3)
	{
		fprintf(mFile,"\tsetAttr \".vt3\" -type \"float2\" ");
		vt3.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexUvThreeU(float t3u)
	{
		if(t3u == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt3.t3u\" %f;\n", t3u);
	}
	void setVertexUvThreeV(float t3v)
	{
		if(t3v == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt3.t3v\" %f;\n", t3v);
	}
	void setVertexCameraOne(const float3& vc1)
	{
		fprintf(mFile,"\tsetAttr \".vc1\" -type \"float3\" ");
		vc1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexCameraOneX(float c1x)
	{
		if(c1x == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc1.c1x\" %f;\n", c1x);
	}
	void setVertexCameraOneY(float c1y)
	{
		if(c1y == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc1.c1y\" %f;\n", c1y);
	}
	void setVertexCameraOneZ(float c1z)
	{
		if(c1z == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc1.c1z\" %f;\n", c1z);
	}
	void setCoverage(const float2& c)
	{
		if(c == float2(1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".c\" -type \"float2\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCoverageU(float cu)
	{
		if(cu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cu\" %f;\n", cu);
	}
	void setCoverageV(float cv)
	{
		if(cv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cv\" %f;\n", cv);
	}
	void setTranslateFrame(const float2& tf)
	{
		if(tf == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".tf\" -type \"float2\" ");
		tf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTranslateFrameU(float tfu)
	{
		if(tfu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tf.tfu\" %f;\n", tfu);
	}
	void setTranslateFrameV(float tfv)
	{
		if(tfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tf.tfv\" %f;\n", tfv);
	}
	void setRotateFrame(double rf)
	{
		if(rf == 0) return;
		fprintf(mFile,"\tsetAttr \".rf\" %f;\n", rf);
	}
	void setMirrorU(bool mu)
	{
		if(mu == false) return;
		fprintf(mFile,"\tsetAttr \".mu\" %i;\n", mu);
	}
	void setMirrorV(bool mv)
	{
		if(mv == false) return;
		fprintf(mFile,"\tsetAttr \".mv\" %i;\n", mv);
	}
	void setStagger(bool s)
	{
		if(s == false) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);
	}
	void setWrapU(bool wu)
	{
		if(wu == true) return;
		fprintf(mFile,"\tsetAttr \".wu\" %i;\n", wu);
	}
	void setWrapV(bool wv)
	{
		if(wv == true) return;
		fprintf(mFile,"\tsetAttr \".wv\" %i;\n", wv);
	}
	void setRepeatUV(const float2& re)
	{
		if(re == float2(1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".re\" -type \"float2\" ");
		re.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRepeatU(float reu)
	{
		if(reu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".re.reu\" %f;\n", reu);
	}
	void setRepeatV(float rev)
	{
		if(rev == 0.0) return;
		fprintf(mFile,"\tsetAttr \".re.rev\" %f;\n", rev);
	}
	void setOffset(const float2& of)
	{
		if(of == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".of\" -type \"float2\" ");
		of.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOffsetU(float ofu)
	{
		if(ofu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".of.ofu\" %f;\n", ofu);
	}
	void setOffsetV(float ofv)
	{
		if(ofv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".of.ofv\" %f;\n", ofv);
	}
	void setRotateUV(double r)
	{
		if(r == 0) return;
		fprintf(mFile,"\tsetAttr \".r\" %f;\n", r);
	}
	void setNoiseUV(const float2& n)
	{
		if(n == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".n\" -type \"float2\" ");
		n.write(mFile);
		fprintf(mFile,";\n");
	}
	void setNoiseU(float nu)
	{
		if(nu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n.nu\" %f;\n", nu);
	}
	void setNoiseV(float nv)
	{
		if(nv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n.nv\" %f;\n", nv);
	}
	void setFast(bool fa)
	{
		if(fa == false) return;
		fprintf(mFile,"\tsetAttr \".fa\" %i;\n", fa);
	}
	void getUvCoord()const
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());
	}
	void getUCoord()const
	{
		fprintf(mFile,"\"%s.uv.u\"",mName.c_str());
	}
	void getVCoord()const
	{
		fprintf(mFile,"\"%s.uv.v\"",mName.c_str());
	}
	void getVertexUvOne()const
	{
		fprintf(mFile,"\"%s.vt1\"",mName.c_str());
	}
	void getVertexUvOneU()const
	{
		fprintf(mFile,"\"%s.vt1.t1u\"",mName.c_str());
	}
	void getVertexUvOneV()const
	{
		fprintf(mFile,"\"%s.vt1.t1v\"",mName.c_str());
	}
	void getVertexUvTwo()const
	{
		fprintf(mFile,"\"%s.vt2\"",mName.c_str());
	}
	void getVertexUvTwoU()const
	{
		fprintf(mFile,"\"%s.vt2.t2u\"",mName.c_str());
	}
	void getVertexUvTwoV()const
	{
		fprintf(mFile,"\"%s.vt2.t2v\"",mName.c_str());
	}
	void getVertexUvThree()const
	{
		fprintf(mFile,"\"%s.vt3\"",mName.c_str());
	}
	void getVertexUvThreeU()const
	{
		fprintf(mFile,"\"%s.vt3.t3u\"",mName.c_str());
	}
	void getVertexUvThreeV()const
	{
		fprintf(mFile,"\"%s.vt3.t3v\"",mName.c_str());
	}
	void getVertexCameraOne()const
	{
		fprintf(mFile,"\"%s.vc1\"",mName.c_str());
	}
	void getVertexCameraOneX()const
	{
		fprintf(mFile,"\"%s.vc1.c1x\"",mName.c_str());
	}
	void getVertexCameraOneY()const
	{
		fprintf(mFile,"\"%s.vc1.c1y\"",mName.c_str());
	}
	void getVertexCameraOneZ()const
	{
		fprintf(mFile,"\"%s.vc1.c1z\"",mName.c_str());
	}
	void getUvFilterSize()const
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getUvFilterSizeX()const
	{
		fprintf(mFile,"\"%s.fs.fsx\"",mName.c_str());
	}
	void getUvFilterSizeY()const
	{
		fprintf(mFile,"\"%s.fs.fsy\"",mName.c_str());
	}
	void getCoverage()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getCoverageU()const
	{
		fprintf(mFile,"\"%s.c.cu\"",mName.c_str());
	}
	void getCoverageV()const
	{
		fprintf(mFile,"\"%s.c.cv\"",mName.c_str());
	}
	void getTranslateFrame()const
	{
		fprintf(mFile,"\"%s.tf\"",mName.c_str());
	}
	void getTranslateFrameU()const
	{
		fprintf(mFile,"\"%s.tf.tfu\"",mName.c_str());
	}
	void getTranslateFrameV()const
	{
		fprintf(mFile,"\"%s.tf.tfv\"",mName.c_str());
	}
	void getRotateFrame()const
	{
		fprintf(mFile,"\"%s.rf\"",mName.c_str());
	}
	void getMirrorU()const
	{
		fprintf(mFile,"\"%s.mu\"",mName.c_str());
	}
	void getMirrorV()const
	{
		fprintf(mFile,"\"%s.mv\"",mName.c_str());
	}
	void getStagger()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getWrapU()const
	{
		fprintf(mFile,"\"%s.wu\"",mName.c_str());
	}
	void getWrapV()const
	{
		fprintf(mFile,"\"%s.wv\"",mName.c_str());
	}
	void getRepeatUV()const
	{
		fprintf(mFile,"\"%s.re\"",mName.c_str());
	}
	void getRepeatU()const
	{
		fprintf(mFile,"\"%s.re.reu\"",mName.c_str());
	}
	void getRepeatV()const
	{
		fprintf(mFile,"\"%s.re.rev\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.of\"",mName.c_str());
	}
	void getOffsetU()const
	{
		fprintf(mFile,"\"%s.of.ofu\"",mName.c_str());
	}
	void getOffsetV()const
	{
		fprintf(mFile,"\"%s.of.ofv\"",mName.c_str());
	}
	void getRotateUV()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getNoiseUV()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNoiseU()const
	{
		fprintf(mFile,"\"%s.n.nu\"",mName.c_str());
	}
	void getNoiseV()const
	{
		fprintf(mFile,"\"%s.n.nv\"",mName.c_str());
	}
	void getFast()const
	{
		fprintf(mFile,"\"%s.fa\"",mName.c_str());
	}
	void getOutUV()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getOutU()const
	{
		fprintf(mFile,"\"%s.o.ou\"",mName.c_str());
	}
	void getOutV()const
	{
		fprintf(mFile,"\"%s.o.ov\"",mName.c_str());
	}
	void getOutUvFilterSize()const
	{
		fprintf(mFile,"\"%s.ofs\"",mName.c_str());
	}
	void getOutUvFilterSizeX()const
	{
		fprintf(mFile,"\"%s.ofs.ofsx\"",mName.c_str());
	}
	void getOutUvFilterSizeY()const
	{
		fprintf(mFile,"\"%s.ofs.ofsy\"",mName.c_str());
	}
	void getDoTransform()const
	{
		fprintf(mFile,"\"%s.do\"",mName.c_str());
	}
protected:
	Place2dTexture(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PLACE2DTEXTURE_H__
