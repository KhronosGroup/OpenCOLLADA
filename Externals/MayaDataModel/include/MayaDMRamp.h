/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RAMP_H__
#define __MayaDM_RAMP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Ramp : public Texture2d
{
public:
	struct ColorEntryList{
		float position;
		float3 color;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", position);
			color.write(file);
		}
	};
public:
	Ramp():Texture2d(){}
	Ramp(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "ramp"){}
	virtual ~Ramp(){}
	void setType(unsigned int t)
	{
		if(t == 0) return;
		fprintf(mFile,"\tsetAttr \".t\" %i;\n", t);

	}
	void setInterpolation(unsigned int in)
	{
		if(in == 1) return;
		fprintf(mFile,"\tsetAttr \".in\" %i;\n", in);

	}
	void setColorEntryList(size_t cel_i,const ColorEntryList& cel)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i]\" ",cel_i);
		cel.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPosition(size_t cel_i,float ep)
	{
		if(ep == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cel[%i].ep\" %f;\n", cel_i,ep);

	}
	void setColor(size_t cel_i,const float3& ec)
	{
		if(ec == float3(1.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".cel[%i].ec\" -type \"float3\" ",cel_i);
		ec.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(size_t cel_i,float ecr)
	{
		if(ecr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cel[%i].ec.ecr\" %f;\n", cel_i,ecr);

	}
	void setColorG(size_t cel_i,float ecg)
	{
		if(ecg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cel[%i].ec.ecg\" %f;\n", cel_i,ecg);

	}
	void setColorB(size_t cel_i,float ecb)
	{
		if(ecb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cel[%i].ec.ecb\" %f;\n", cel_i,ecb);

	}
	void setUWave(float uw)
	{
		if(uw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uw\" %f;\n", uw);

	}
	void setVWave(float vw)
	{
		if(vw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vw\" %f;\n", vw);

	}
	void setNoise(float n)
	{
		if(n == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n\" %f;\n", n);

	}
	void setNoiseFreq(float nf)
	{
		if(nf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".nf\" %f;\n", nf);

	}
	void setHueNoise(float hn)
	{
		if(hn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hn\" %f;\n", hn);

	}
	void setSatNoise(float sn)
	{
		if(sn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sn\" %f;\n", sn);

	}
	void setValNoise(float vn)
	{
		if(vn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vn\" %f;\n", vn);

	}
	void setHueNoiseFreq(float hnf)
	{
		if(hnf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hnf\" %f;\n", hnf);

	}
	void setSatNoiseFreq(float snf)
	{
		if(snf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".snf\" %f;\n", snf);

	}
	void setValNoiseFreq(float vnf)
	{
		if(vnf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".vnf\" %f;\n", vnf);

	}
	void getType()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getInterpolation()
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());

	}
	void getColorEntryList(size_t cel_i)
	{
		fprintf(mFile,"\"%s.cel[%i]\"",mName.c_str(),cel_i);

	}
	void getPosition(size_t cel_i)
	{
		fprintf(mFile,"\"%s.cel[%i].ep\"",mName.c_str(),cel_i);

	}
	void getColor(size_t cel_i)
	{
		fprintf(mFile,"\"%s.cel[%i].ec\"",mName.c_str(),cel_i);

	}
	void getColorR(size_t cel_i)
	{
		fprintf(mFile,"\"%s.cel[%i].ec.ecr\"",mName.c_str(),cel_i);

	}
	void getColorG(size_t cel_i)
	{
		fprintf(mFile,"\"%s.cel[%i].ec.ecg\"",mName.c_str(),cel_i);

	}
	void getColorB(size_t cel_i)
	{
		fprintf(mFile,"\"%s.cel[%i].ec.ecb\"",mName.c_str(),cel_i);

	}
	void getUWave()
	{
		fprintf(mFile,"\"%s.uw\"",mName.c_str());

	}
	void getVWave()
	{
		fprintf(mFile,"\"%s.vw\"",mName.c_str());

	}
	void getNoise()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getNoiseFreq()
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());

	}
	void getHueNoise()
	{
		fprintf(mFile,"\"%s.hn\"",mName.c_str());

	}
	void getSatNoise()
	{
		fprintf(mFile,"\"%s.sn\"",mName.c_str());

	}
	void getValNoise()
	{
		fprintf(mFile,"\"%s.vn\"",mName.c_str());

	}
	void getHueNoiseFreq()
	{
		fprintf(mFile,"\"%s.hnf\"",mName.c_str());

	}
	void getSatNoiseFreq()
	{
		fprintf(mFile,"\"%s.snf\"",mName.c_str());

	}
	void getValNoiseFreq()
	{
		fprintf(mFile,"\"%s.vnf\"",mName.c_str());

	}
protected:
	Ramp(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Texture2d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RAMP_H__
