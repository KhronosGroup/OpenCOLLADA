/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OCEAN_H__
#define __MayaDM_OCEAN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Ocean : public Texture2d
{
public:
	struct WaveHeight{
		float waveHeight_Position;
		float waveHeight_FloatValue;
		unsigned int waveHeight_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", waveHeight_Position);
			fprintf(file,"%f ", waveHeight_FloatValue);
			fprintf(file,"%i", waveHeight_Interp);
		}
	};
	struct WaveTurbulence{
		float waveTurbulence_Position;
		float waveTurbulence_FloatValue;
		unsigned int waveTurbulence_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", waveTurbulence_Position);
			fprintf(file,"%f ", waveTurbulence_FloatValue);
			fprintf(file,"%i", waveTurbulence_Interp);
		}
	};
	struct WavePeaking{
		float wavePeaking_Position;
		float wavePeaking_FloatValue;
		unsigned int wavePeaking_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", wavePeaking_Position);
			fprintf(file,"%f ", wavePeaking_FloatValue);
			fprintf(file,"%i", wavePeaking_Interp);
		}
	};
public:

	Ocean():Texture2d(){}
	Ocean(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture2d(file, name, parent, "ocean", shared, create){}
	virtual ~Ocean(){}

	void setTime(float ti)
	{
		if(ti == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ti\" %f;\n", ti);
	}
	void setScale(float sc)
	{
		if(sc == 10.0) return;
		fprintf(mFile,"\tsetAttr \".sc\" %f;\n", sc);
	}
	void setWindUV(const float2& wi)
	{
		if(wi == float2(1.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".wi\" -type \"float2\" ");
		wi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWindU(float wiu)
	{
		if(wiu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wi.wiu\" %f;\n", wiu);
	}
	void setWindV(float wiv)
	{
		if(wiv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wi.wiv\" %f;\n", wiv);
	}
	void setObserverSpeed(float os)
	{
		if(os == 0.0) return;
		fprintf(mFile,"\tsetAttr \".os\" %f;\n", os);
	}
	void setWaveDirSpread(float wd)
	{
		if(wd == 0.2) return;
		fprintf(mFile,"\tsetAttr \".wd\" %f;\n", wd);
	}
	void setNumFrequencies(float nf)
	{
		if(nf == 3.0) return;
		fprintf(mFile,"\tsetAttr \".nf\" %f;\n", nf);
	}
	void setWaveLengthMin(float wlm)
	{
		if(wlm == 0.3) return;
		fprintf(mFile,"\tsetAttr \".wlm\" %f;\n", wlm);
	}
	void setWaveLengthMax(float wlx)
	{
		if(wlx == 4.0) return;
		fprintf(mFile,"\tsetAttr \".wlx\" %f;\n", wlx);
	}
	void setWaveHeight(size_t wh_i,const WaveHeight& wh)
	{
		fprintf(mFile,"\tsetAttr \".wh[%i]\" ",wh_i);
		wh.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWaveHeight(size_t wh_start,size_t wh_end,WaveHeight* wh)
	{
		fprintf(mFile,"\tsetAttr \".wh[%i:%i]\" ", wh_start,wh_end);
		size_t size = (wh_end-wh_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			wh[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWaveHeight(size_t wh_start,size_t wh_end)const
	{
		fprintf(mFile,"\tsetAttr \".wh[%i:%i]\"",wh_start,wh_end);
		fprintf(mFile," -type \"WaveHeight\" ");
	}
	void appendWaveHeight(const WaveHeight& wh)const
	{
		fprintf(mFile," ");
		wh.write(mFile);
	}
	void endWaveHeight()const
	{
		fprintf(mFile,";\n");
	}
	void setWaveHeight_Position(size_t wh_i,float whp)
	{
		if(whp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wh[%i].whp\" %f;\n", wh_i,whp);
	}
	void setWaveHeight_FloatValue(size_t wh_i,float whfv)
	{
		if(whfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wh[%i].whfv\" %f;\n", wh_i,whfv);
	}
	void setWaveHeight_Interp(size_t wh_i,unsigned int whi)
	{
		if(whi == 0) return;
		fprintf(mFile,"\tsetAttr \".wh[%i].whi\" %i;\n", wh_i,whi);
	}
	void setWaveTurbulence(size_t wtb_i,const WaveTurbulence& wtb)
	{
		fprintf(mFile,"\tsetAttr \".wtb[%i]\" ",wtb_i);
		wtb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWaveTurbulence(size_t wtb_start,size_t wtb_end,WaveTurbulence* wtb)
	{
		fprintf(mFile,"\tsetAttr \".wtb[%i:%i]\" ", wtb_start,wtb_end);
		size_t size = (wtb_end-wtb_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			wtb[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWaveTurbulence(size_t wtb_start,size_t wtb_end)const
	{
		fprintf(mFile,"\tsetAttr \".wtb[%i:%i]\"",wtb_start,wtb_end);
		fprintf(mFile," -type \"WaveTurbulence\" ");
	}
	void appendWaveTurbulence(const WaveTurbulence& wtb)const
	{
		fprintf(mFile," ");
		wtb.write(mFile);
	}
	void endWaveTurbulence()const
	{
		fprintf(mFile,";\n");
	}
	void setWaveTurbulence_Position(size_t wtb_i,float wtbp)
	{
		if(wtbp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wtb[%i].wtbp\" %f;\n", wtb_i,wtbp);
	}
	void setWaveTurbulence_FloatValue(size_t wtb_i,float wtbfv)
	{
		if(wtbfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wtb[%i].wtbfv\" %f;\n", wtb_i,wtbfv);
	}
	void setWaveTurbulence_Interp(size_t wtb_i,unsigned int wtbi)
	{
		if(wtbi == 0) return;
		fprintf(mFile,"\tsetAttr \".wtb[%i].wtbi\" %i;\n", wtb_i,wtbi);
	}
	void setWavePeaking(size_t wp_i,const WavePeaking& wp)
	{
		fprintf(mFile,"\tsetAttr \".wp[%i]\" ",wp_i);
		wp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWavePeaking(size_t wp_start,size_t wp_end,WavePeaking* wp)
	{
		fprintf(mFile,"\tsetAttr \".wp[%i:%i]\" ", wp_start,wp_end);
		size_t size = (wp_end-wp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			wp[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWavePeaking(size_t wp_start,size_t wp_end)const
	{
		fprintf(mFile,"\tsetAttr \".wp[%i:%i]\"",wp_start,wp_end);
		fprintf(mFile," -type \"WavePeaking\" ");
	}
	void appendWavePeaking(const WavePeaking& wp)const
	{
		fprintf(mFile," ");
		wp.write(mFile);
	}
	void endWavePeaking()const
	{
		fprintf(mFile,";\n");
	}
	void setWavePeaking_Position(size_t wp_i,float wpp)
	{
		if(wpp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wp[%i].wpp\" %f;\n", wp_i,wpp);
	}
	void setWavePeaking_FloatValue(size_t wp_i,float wpfv)
	{
		if(wpfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wp[%i].wpfv\" %f;\n", wp_i,wpfv);
	}
	void setWavePeaking_Interp(size_t wp_i,unsigned int wpi)
	{
		if(wpi == 0) return;
		fprintf(mFile,"\tsetAttr \".wp[%i].wpi\" %i;\n", wp_i,wpi);
	}
	void setFoamEmission(float fme)
	{
		if(fme == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fme\" %f;\n", fme);
	}
	void setFoamThreshold(float fmt)
	{
		if(fmt == 0.51) return;
		fprintf(mFile,"\tsetAttr \".fmt\" %f;\n", fmt);
	}
	void setColorMode(unsigned int cmd)
	{
		if(cmd == 0) return;
		fprintf(mFile,"\tsetAttr \".cmd\" %i;\n", cmd);
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.ti\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getWindUV()const
	{
		fprintf(mFile,"\"%s.wi\"",mName.c_str());
	}
	void getWindU()const
	{
		fprintf(mFile,"\"%s.wi.wiu\"",mName.c_str());
	}
	void getWindV()const
	{
		fprintf(mFile,"\"%s.wi.wiv\"",mName.c_str());
	}
	void getObserverSpeed()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getWaveDirSpread()const
	{
		fprintf(mFile,"\"%s.wd\"",mName.c_str());
	}
	void getNumFrequencies()const
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());
	}
	void getWaveLengthMin()const
	{
		fprintf(mFile,"\"%s.wlm\"",mName.c_str());
	}
	void getWaveLengthMax()const
	{
		fprintf(mFile,"\"%s.wlx\"",mName.c_str());
	}
	void getWaveHeight(size_t wh_i)const
	{
		fprintf(mFile,"\"%s.wh[%i]\"",mName.c_str(),wh_i);
	}
	void getWaveHeight()const
	{

		fprintf(mFile,"\"%s.wh\"",mName.c_str());
	}
	void getWaveHeight_Position(size_t wh_i)const
	{
		fprintf(mFile,"\"%s.wh[%i].whp\"",mName.c_str(),wh_i);
	}
	void getWaveHeight_Position()const
	{

		fprintf(mFile,"\"%s.wh.whp\"",mName.c_str());
	}
	void getWaveHeight_FloatValue(size_t wh_i)const
	{
		fprintf(mFile,"\"%s.wh[%i].whfv\"",mName.c_str(),wh_i);
	}
	void getWaveHeight_FloatValue()const
	{

		fprintf(mFile,"\"%s.wh.whfv\"",mName.c_str());
	}
	void getWaveHeight_Interp(size_t wh_i)const
	{
		fprintf(mFile,"\"%s.wh[%i].whi\"",mName.c_str(),wh_i);
	}
	void getWaveHeight_Interp()const
	{

		fprintf(mFile,"\"%s.wh.whi\"",mName.c_str());
	}
	void getWaveTurbulence(size_t wtb_i)const
	{
		fprintf(mFile,"\"%s.wtb[%i]\"",mName.c_str(),wtb_i);
	}
	void getWaveTurbulence()const
	{

		fprintf(mFile,"\"%s.wtb\"",mName.c_str());
	}
	void getWaveTurbulence_Position(size_t wtb_i)const
	{
		fprintf(mFile,"\"%s.wtb[%i].wtbp\"",mName.c_str(),wtb_i);
	}
	void getWaveTurbulence_Position()const
	{

		fprintf(mFile,"\"%s.wtb.wtbp\"",mName.c_str());
	}
	void getWaveTurbulence_FloatValue(size_t wtb_i)const
	{
		fprintf(mFile,"\"%s.wtb[%i].wtbfv\"",mName.c_str(),wtb_i);
	}
	void getWaveTurbulence_FloatValue()const
	{

		fprintf(mFile,"\"%s.wtb.wtbfv\"",mName.c_str());
	}
	void getWaveTurbulence_Interp(size_t wtb_i)const
	{
		fprintf(mFile,"\"%s.wtb[%i].wtbi\"",mName.c_str(),wtb_i);
	}
	void getWaveTurbulence_Interp()const
	{

		fprintf(mFile,"\"%s.wtb.wtbi\"",mName.c_str());
	}
	void getWavePeaking(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i]\"",mName.c_str(),wp_i);
	}
	void getWavePeaking()const
	{

		fprintf(mFile,"\"%s.wp\"",mName.c_str());
	}
	void getWavePeaking_Position(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i].wpp\"",mName.c_str(),wp_i);
	}
	void getWavePeaking_Position()const
	{

		fprintf(mFile,"\"%s.wp.wpp\"",mName.c_str());
	}
	void getWavePeaking_FloatValue(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i].wpfv\"",mName.c_str(),wp_i);
	}
	void getWavePeaking_FloatValue()const
	{

		fprintf(mFile,"\"%s.wp.wpfv\"",mName.c_str());
	}
	void getWavePeaking_Interp(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i].wpi\"",mName.c_str(),wp_i);
	}
	void getWavePeaking_Interp()const
	{

		fprintf(mFile,"\"%s.wp.wpi\"",mName.c_str());
	}
	void getFoamEmission()const
	{
		fprintf(mFile,"\"%s.fme\"",mName.c_str());
	}
	void getFoamThreshold()const
	{
		fprintf(mFile,"\"%s.fmt\"",mName.c_str());
	}
	void getColorMode()const
	{
		fprintf(mFile,"\"%s.cmd\"",mName.c_str());
	}
	void getOutFoam()const
	{
		fprintf(mFile,"\"%s.ofm\"",mName.c_str());
	}
protected:
	Ocean(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture2d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OCEAN_H__
