/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NOISE_H__
#define __MayaDM_NOISE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Noise : public Texture2d
{
public:
public:
	Noise(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "noise"){}
	virtual ~Noise(){}
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
	void setImplodeCenter(const float2& imc)
	{
		if(imc == float2(0.5f,0.5f)) return;
		fprintf(mFile,"setAttr \".imc\" -type \"float2\" ");
		imc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImplodeCenterU(float imu)
	{
		if(imu == 0.0) return;
		fprintf(mFile,"setAttr \".imc.imu\" %f;\n", imu);

	}
	void setImplodeCenterV(float imv)
	{
		if(imv == 0.0) return;
		fprintf(mFile,"setAttr \".imc.imv\" %f;\n", imv);

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
	void getImplodeCenterU()
	{
		fprintf(mFile,"\"%s.imc.imu\"",mName.c_str());

	}
	void getImplodeCenterV()
	{
		fprintf(mFile,"\"%s.imc.imv\"",mName.c_str());

	}
protected:
	Noise(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_NOISE_H__
