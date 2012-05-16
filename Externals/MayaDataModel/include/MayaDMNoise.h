/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Noise():Texture2d(){}
	Noise(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture2d(file, name, parent, "noise", shared, create){}
	virtual ~Noise(){}

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
	void setImplodeCenter(const float2& imc)
	{
		if(imc == float2(0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".imc\" -type \"float2\" ");
		imc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImplodeCenterU(float imu)
	{
		if(imu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imc.imu\" %f;\n", imu);
	}
	void setImplodeCenterV(float imv)
	{
		if(imv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imc.imv\" %f;\n", imv);
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
	void getImplodeCenterU()const
	{
		fprintf(mFile,"\"%s.imc.imu\"",mName.c_str());
	}
	void getImplodeCenterV()const
	{
		fprintf(mFile,"\"%s.imc.imv\"",mName.c_str());
	}
protected:
	Noise(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture2d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NOISE_H__
