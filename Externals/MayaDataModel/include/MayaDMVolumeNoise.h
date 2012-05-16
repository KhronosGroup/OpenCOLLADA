/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VOLUMENOISE_H__
#define __MayaDM_VOLUMENOISE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class VolumeNoise : public Texture3d
{
public:
public:

	VolumeNoise():Texture3d(){}
	VolumeNoise(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture3d(file, name, parent, "volumeNoise", shared, create){}
	virtual ~VolumeNoise(){}

	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"\tsetAttr \".xpa\" %f;\n", xpa);
	}
	void setAmplitude(float a)
	{
		if(a == 1.0) return;
		fprintf(mFile,"\tsetAttr \".a\" %f;\n", a);
	}
	void setRatio(float ra)
	{
		if(ra == 0.707) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
	}
	void setThreshold(float th)
	{
		if(th == 0.0) return;
		fprintf(mFile,"\tsetAttr \".th\" %f;\n", th);
	}
	void setScale(const float3& sc)
	{
		if(sc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setScaleX(float sx)
	{
		if(sx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc.sx\" %f;\n", sx);
	}
	void setScaleY(float sy)
	{
		if(sy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc.sy\" %f;\n", sy);
	}
	void setScaleZ(float sz)
	{
		if(sz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc.sz\" %f;\n", sz);
	}
	void setOrigin(const float3& orr)
	{
		if(orr == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".orr\" -type \"float3\" ");
		orr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOriginX(float orx)
	{
		if(orx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".orr.orx\" %f;\n", orx);
	}
	void setOriginY(float ory)
	{
		if(ory == 0.0) return;
		fprintf(mFile,"\tsetAttr \".orr.ory\" %f;\n", ory);
	}
	void setOriginZ(float orz)
	{
		if(orz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".orr.orz\" %f;\n", orz);
	}
	void setDepthMax(short dm)
	{
		if(dm == 3) return;
		fprintf(mFile,"\tsetAttr \".dm\" %i;\n", dm);
	}
	void setFrequency(float fq)
	{
		if(fq == 8.0) return;
		fprintf(mFile,"\tsetAttr \".fq\" %f;\n", fq);
	}
	void setFrequencyRatio(float fr)
	{
		if(fr == 2.0) return;
		fprintf(mFile,"\tsetAttr \".fr\" %f;\n", fr);
	}
	void setInflection(bool in)
	{
		if(in == false) return;
		fprintf(mFile,"\tsetAttr \".in\" %i;\n", in);
	}
	void setTime(float ti)
	{
		if(ti == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ti\" %f;\n", ti);
	}
	void setNoiseType(unsigned int nty)
	{
		if(nty == 1) return;
		fprintf(mFile,"\tsetAttr \".nty\" %i;\n", nty);
	}
	void setDensity(float d)
	{
		if(d == 1.0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setSpottyness(float sp)
	{
		if(sp == 0.1) return;
		fprintf(mFile,"\tsetAttr \".sp\" %f;\n", sp);
	}
	void setSizeRand(float sr)
	{
		if(sr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sr\" %f;\n", sr);
	}
	void setRandomness(float rn)
	{
		if(rn == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rn\" %f;\n", rn);
	}
	void setFalloff(unsigned int fof)
	{
		if(fof == 2) return;
		fprintf(mFile,"\tsetAttr \".fof\" %i;\n", fof);
	}
	void setNumWaves(short nw)
	{
		if(nw == 5) return;
		fprintf(mFile,"\tsetAttr \".nw\" %i;\n", nw);
	}
	void setImplode(float imp)
	{
		if(imp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imp\" %f;\n", imp);
	}
	void setImplodeCenter(const float3& imc)
	{
		if(imc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".imc\" -type \"float3\" ");
		imc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImplodeCenterX(float imx)
	{
		if(imx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imc.imx\" %f;\n", imx);
	}
	void setImplodeCenterY(float imy)
	{
		if(imy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imc.imy\" %f;\n", imy);
	}
	void setImplodeCenterZ(float imz)
	{
		if(imz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imc.imz\" %f;\n", imz);
	}
	void getXPixelAngle()const
	{
		fprintf(mFile,"\"%s.xpa\"",mName.c_str());
	}
	void getRefPointObj()const
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());
	}
	void getRefPointObjX()const
	{
		fprintf(mFile,"\"%s.rpo.rox\"",mName.c_str());
	}
	void getRefPointObjY()const
	{
		fprintf(mFile,"\"%s.rpo.roy\"",mName.c_str());
	}
	void getRefPointObjZ()const
	{
		fprintf(mFile,"\"%s.rpo.roz\"",mName.c_str());
	}
	void getRefPointCamera()const
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());
	}
	void getRefPointCameraX()const
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());
	}
	void getRefPointCameraY()const
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());
	}
	void getRefPointCameraZ()const
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());
	}
	void getAmplitude()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getRatio()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getThreshold()const
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getScaleX()const
	{
		fprintf(mFile,"\"%s.sc.sx\"",mName.c_str());
	}
	void getScaleY()const
	{
		fprintf(mFile,"\"%s.sc.sy\"",mName.c_str());
	}
	void getScaleZ()const
	{
		fprintf(mFile,"\"%s.sc.sz\"",mName.c_str());
	}
	void getOrigin()const
	{
		fprintf(mFile,"\"%s.orr\"",mName.c_str());
	}
	void getOriginX()const
	{
		fprintf(mFile,"\"%s.orr.orx\"",mName.c_str());
	}
	void getOriginY()const
	{
		fprintf(mFile,"\"%s.orr.ory\"",mName.c_str());
	}
	void getOriginZ()const
	{
		fprintf(mFile,"\"%s.orr.orz\"",mName.c_str());
	}
	void getDepthMax()const
	{
		fprintf(mFile,"\"%s.dm\"",mName.c_str());
	}
	void getFrequency()const
	{
		fprintf(mFile,"\"%s.fq\"",mName.c_str());
	}
	void getFrequencyRatio()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
	void getInflection()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.ti\"",mName.c_str());
	}
	void getNoiseType()const
	{
		fprintf(mFile,"\"%s.nty\"",mName.c_str());
	}
	void getDensity()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSpottyness()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getSizeRand()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getRandomness()const
	{
		fprintf(mFile,"\"%s.rn\"",mName.c_str());
	}
	void getFalloff()const
	{
		fprintf(mFile,"\"%s.fof\"",mName.c_str());
	}
	void getNumWaves()const
	{
		fprintf(mFile,"\"%s.nw\"",mName.c_str());
	}
	void getImplode()const
	{
		fprintf(mFile,"\"%s.imp\"",mName.c_str());
	}
	void getImplodeCenter()const
	{
		fprintf(mFile,"\"%s.imc\"",mName.c_str());
	}
	void getImplodeCenterX()const
	{
		fprintf(mFile,"\"%s.imc.imx\"",mName.c_str());
	}
	void getImplodeCenterY()const
	{
		fprintf(mFile,"\"%s.imc.imy\"",mName.c_str());
	}
	void getImplodeCenterZ()const
	{
		fprintf(mFile,"\"%s.imc.imz\"",mName.c_str());
	}
protected:
	VolumeNoise(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture3d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMENOISE_H__
