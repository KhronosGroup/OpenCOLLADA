/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	VolumeNoise(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "volumeNoise"){}
	virtual ~VolumeNoise(){}
	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"setAttr \".xpa\" %f;\n", xpa);

	}
	void setAmplitude(float a)
	{
		if(a == 1.0) return;
		fprintf(mFile,"setAttr \".a\" %f;\n", a);

	}
	void setRatio(float ra)
	{
		if(ra == 0.707) return;
		fprintf(mFile,"setAttr \".ra\" %f;\n", ra);

	}
	void setThreshold(float th)
	{
		if(th == 0.0) return;
		fprintf(mFile,"setAttr \".th\" %f;\n", th);

	}
	void setScale(const float3& sc)
	{
		if(sc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScaleX(float sx)
	{
		if(sx == 0.0) return;
		fprintf(mFile,"setAttr \".sc.sx\" %f;\n", sx);

	}
	void setScaleY(float sy)
	{
		if(sy == 0.0) return;
		fprintf(mFile,"setAttr \".sc.sy\" %f;\n", sy);

	}
	void setScaleZ(float sz)
	{
		if(sz == 0.0) return;
		fprintf(mFile,"setAttr \".sc.sz\" %f;\n", sz);

	}
	void setOrigin(const float3& orr)
	{
		if(orr == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".orr\" -type \"float3\" ");
		orr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOriginX(float orx)
	{
		if(orx == 0.0) return;
		fprintf(mFile,"setAttr \".orr.orx\" %f;\n", orx);

	}
	void setOriginY(float ory)
	{
		if(ory == 0.0) return;
		fprintf(mFile,"setAttr \".orr.ory\" %f;\n", ory);

	}
	void setOriginZ(float orz)
	{
		if(orz == 0.0) return;
		fprintf(mFile,"setAttr \".orr.orz\" %f;\n", orz);

	}
	void setDepthMax(short dm)
	{
		if(dm == 3) return;
		fprintf(mFile,"setAttr \".dm\" %i;\n", dm);

	}
	void setFrequency(float fq)
	{
		if(fq == 8.0) return;
		fprintf(mFile,"setAttr \".fq\" %f;\n", fq);

	}
	void setFrequencyRatio(float fr)
	{
		if(fr == 2.0) return;
		fprintf(mFile,"setAttr \".fr\" %f;\n", fr);

	}
	void setInflection(bool in)
	{
		if(in == false) return;
		fprintf(mFile,"setAttr \".in\" %i;\n", in);

	}
	void setTime(float ti)
	{
		if(ti == 0.0) return;
		fprintf(mFile,"setAttr \".ti\" %f;\n", ti);

	}
	void setNoiseType(unsigned int nty)
	{
		if(nty == 1) return;
		fprintf(mFile,"setAttr \".nty\" %i;\n", nty);

	}
	void setDensity(float d)
	{
		if(d == 1.0) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setSpottyness(float sp)
	{
		if(sp == 0.1) return;
		fprintf(mFile,"setAttr \".sp\" %f;\n", sp);

	}
	void setSizeRand(float sr)
	{
		if(sr == 0.0) return;
		fprintf(mFile,"setAttr \".sr\" %f;\n", sr);

	}
	void setRandomness(float rn)
	{
		if(rn == 1.0) return;
		fprintf(mFile,"setAttr \".rn\" %f;\n", rn);

	}
	void setFalloff(unsigned int fof)
	{
		if(fof == 2) return;
		fprintf(mFile,"setAttr \".fof\" %i;\n", fof);

	}
	void setNumWaves(short nw)
	{
		if(nw == 5) return;
		fprintf(mFile,"setAttr \".nw\" %i;\n", nw);

	}
	void setImplode(float imp)
	{
		if(imp == 0.0) return;
		fprintf(mFile,"setAttr \".imp\" %f;\n", imp);

	}
	void setImplodeCenter(const float3& imc)
	{
		if(imc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".imc\" -type \"float3\" ");
		imc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImplodeCenterX(float imx)
	{
		if(imx == 0.0) return;
		fprintf(mFile,"setAttr \".imc.imx\" %f;\n", imx);

	}
	void setImplodeCenterY(float imy)
	{
		if(imy == 0.0) return;
		fprintf(mFile,"setAttr \".imc.imy\" %f;\n", imy);

	}
	void setImplodeCenterZ(float imz)
	{
		if(imz == 0.0) return;
		fprintf(mFile,"setAttr \".imc.imz\" %f;\n", imz);

	}
	void getRefPointObj()
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());

	}
	void getRefPointObjX()
	{
		fprintf(mFile,"\"%s.rpo.rox\"",mName.c_str());

	}
	void getRefPointObjY()
	{
		fprintf(mFile,"\"%s.rpo.roy\"",mName.c_str());

	}
	void getRefPointObjZ()
	{
		fprintf(mFile,"\"%s.rpo.roz\"",mName.c_str());

	}
	void getRefPointCamera()
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());

	}
	void getRefPointCameraX()
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());

	}
	void getRefPointCameraY()
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());

	}
	void getRefPointCameraZ()
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());

	}
	void getAmplitude()
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());

	}
	void getRatio()
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());

	}
	void getThreshold()
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getScaleX()
	{
		fprintf(mFile,"\"%s.sc.sx\"",mName.c_str());

	}
	void getScaleY()
	{
		fprintf(mFile,"\"%s.sc.sy\"",mName.c_str());

	}
	void getScaleZ()
	{
		fprintf(mFile,"\"%s.sc.sz\"",mName.c_str());

	}
	void getOrigin()
	{
		fprintf(mFile,"\"%s.orr\"",mName.c_str());

	}
	void getOriginX()
	{
		fprintf(mFile,"\"%s.orr.orx\"",mName.c_str());

	}
	void getOriginY()
	{
		fprintf(mFile,"\"%s.orr.ory\"",mName.c_str());

	}
	void getOriginZ()
	{
		fprintf(mFile,"\"%s.orr.orz\"",mName.c_str());

	}
	void getDepthMax()
	{
		fprintf(mFile,"\"%s.dm\"",mName.c_str());

	}
	void getFrequency()
	{
		fprintf(mFile,"\"%s.fq\"",mName.c_str());

	}
	void getFrequencyRatio()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getInflection()
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());

	}
	void getTime()
	{
		fprintf(mFile,"\"%s.ti\"",mName.c_str());

	}
	void getNoiseType()
	{
		fprintf(mFile,"\"%s.nty\"",mName.c_str());

	}
	void getDensity()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getSpottyness()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getSizeRand()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getRandomness()
	{
		fprintf(mFile,"\"%s.rn\"",mName.c_str());

	}
	void getFalloff()
	{
		fprintf(mFile,"\"%s.fof\"",mName.c_str());

	}
	void getNumWaves()
	{
		fprintf(mFile,"\"%s.nw\"",mName.c_str());

	}
	void getImplode()
	{
		fprintf(mFile,"\"%s.imp\"",mName.c_str());

	}
	void getImplodeCenter()
	{
		fprintf(mFile,"\"%s.imc\"",mName.c_str());

	}
	void getImplodeCenterX()
	{
		fprintf(mFile,"\"%s.imc.imx\"",mName.c_str());

	}
	void getImplodeCenterY()
	{
		fprintf(mFile,"\"%s.imc.imy\"",mName.c_str());

	}
	void getImplodeCenterZ()
	{
		fprintf(mFile,"\"%s.imc.imz\"",mName.c_str());

	}
protected:
	VolumeNoise(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMENOISE_H__
