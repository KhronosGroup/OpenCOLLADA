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
	Ramp(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture2d(file, name, parent, "ramp", shared, create){}
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
	void setColorEntryList(size_t cel_start,size_t cel_end,ColorEntryList* cel)
	{
		fprintf(mFile,"\tsetAttr \".cel[%i:%i]\" ", cel_start,cel_end);
		size_t size = (cel_end-cel_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cel[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startColorEntryList(size_t cel_start,size_t cel_end)const
	{
		fprintf(mFile,"\tsetAttr \".cel[%i:%i]\"",cel_start,cel_end);
		fprintf(mFile," -type \"ColorEntryList\" ");
	}
	void appendColorEntryList(const ColorEntryList& cel)const
	{
		fprintf(mFile," ");
		cel.write(mFile);
	}
	void endColorEntryList()const
	{
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
	void getType()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getInterpolation()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getColorEntryList(size_t cel_i)const
	{
		fprintf(mFile,"\"%s.cel[%i]\"",mName.c_str(),cel_i);
	}
	void getColorEntryList()const
	{

		fprintf(mFile,"\"%s.cel\"",mName.c_str());
	}
	void getPosition(size_t cel_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].ep\"",mName.c_str(),cel_i);
	}
	void getPosition()const
	{

		fprintf(mFile,"\"%s.cel.ep\"",mName.c_str());
	}
	void getColor(size_t cel_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].ec\"",mName.c_str(),cel_i);
	}
	void getColor()const
	{

		fprintf(mFile,"\"%s.cel.ec\"",mName.c_str());
	}
	void getColorR(size_t cel_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].ec.ecr\"",mName.c_str(),cel_i);
	}
	void getColorR()const
	{

		fprintf(mFile,"\"%s.cel.ec.ecr\"",mName.c_str());
	}
	void getColorG(size_t cel_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].ec.ecg\"",mName.c_str(),cel_i);
	}
	void getColorG()const
	{

		fprintf(mFile,"\"%s.cel.ec.ecg\"",mName.c_str());
	}
	void getColorB(size_t cel_i)const
	{
		fprintf(mFile,"\"%s.cel[%i].ec.ecb\"",mName.c_str(),cel_i);
	}
	void getColorB()const
	{

		fprintf(mFile,"\"%s.cel.ec.ecb\"",mName.c_str());
	}
	void getUWave()const
	{
		fprintf(mFile,"\"%s.uw\"",mName.c_str());
	}
	void getVWave()const
	{
		fprintf(mFile,"\"%s.vw\"",mName.c_str());
	}
	void getNoise()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNoiseFreq()const
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());
	}
	void getHueNoise()const
	{
		fprintf(mFile,"\"%s.hn\"",mName.c_str());
	}
	void getSatNoise()const
	{
		fprintf(mFile,"\"%s.sn\"",mName.c_str());
	}
	void getValNoise()const
	{
		fprintf(mFile,"\"%s.vn\"",mName.c_str());
	}
	void getHueNoiseFreq()const
	{
		fprintf(mFile,"\"%s.hnf\"",mName.c_str());
	}
	void getSatNoiseFreq()const
	{
		fprintf(mFile,"\"%s.snf\"",mName.c_str());
	}
	void getValNoiseFreq()const
	{
		fprintf(mFile,"\"%s.vnf\"",mName.c_str());
	}
protected:
	Ramp(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture2d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RAMP_H__
