/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WATER_H__
#define __MayaDM_WATER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Water : public Texture2d
{
public:
public:

	Water():Texture2d(){}
	Water(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture2d(file, name, parent, "water", shared, create){}
	virtual ~Water(){}

	void setNumberOfWaves(short nw)
	{
		if(nw == 8) return;
		fprintf(mFile,"\tsetAttr \".nw\" %i;\n", nw);
	}
	void setWaveTime(float wt)
	{
		if(wt == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wt\" %f;\n", wt);
	}
	void setWaveVelocity(float wv)
	{
		if(wv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".wv\" %f;\n", wv);
	}
	void setWaveAmplitude(float wa)
	{
		if(wa == 0.05) return;
		fprintf(mFile,"\tsetAttr \".wa\" %f;\n", wa);
	}
	void setWaveFrequency(float wf)
	{
		if(wf == 4.0) return;
		fprintf(mFile,"\tsetAttr \".wf\" %f;\n", wf);
	}
	void setSubWaveFrequency(float swf)
	{
		if(swf == 0.125) return;
		fprintf(mFile,"\tsetAttr \".swf\" %f;\n", swf);
	}
	void setSmoothness(float s)
	{
		if(s == 2.0) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
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
	void setRippleTime(float rt)
	{
		if(rt == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rt\" %f;\n", rt);
	}
	void setRippleFrequency(float rf)
	{
		if(rf == 25.0) return;
		fprintf(mFile,"\tsetAttr \".rf\" %f;\n", rf);
	}
	void setRippleAmplitude(float ra)
	{
		if(ra == 0.05) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
	}
	void setDropSize(float ds)
	{
		if(ds == 0.3) return;
		fprintf(mFile,"\tsetAttr \".ds\" %f;\n", ds);
	}
	void setRippleOrigin(const float2& rc)
	{
		if(rc == float2(0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".rc\" -type \"float2\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRippleOriginU(float rcu)
	{
		if(rcu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rcu\" %f;\n", rcu);
	}
	void setRippleOriginV(float rcv)
	{
		if(rcv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rcv\" %f;\n", rcv);
	}
	void setGroupVelocity(float gv)
	{
		if(gv == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gv\" %f;\n", gv);
	}
	void setPhaseVelocity(float pv)
	{
		if(pv == 2.5) return;
		fprintf(mFile,"\tsetAttr \".pv\" %f;\n", pv);
	}
	void setSpreadStart(float ss)
	{
		if(ss == 0.005) return;
		fprintf(mFile,"\tsetAttr \".ss\" %f;\n", ss);
	}
	void setSpreadRate(float sr)
	{
		if(sr == 0.3) return;
		fprintf(mFile,"\tsetAttr \".sr\" %f;\n", sr);
	}
	void setReflectionBox(bool rb)
	{
		if(rb == false) return;
		fprintf(mFile,"\tsetAttr \".rb\" %i;\n", rb);
	}
	void setBoxMin(const float2& bmn)
	{
		if(bmn == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".bmn\" -type \"float2\" ");
		bmn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBoxMinU(float bu1)
	{
		if(bu1 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bmn.bu1\" %f;\n", bu1);
	}
	void setBoxMinV(float bv1)
	{
		if(bv1 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bmn.bv1\" %f;\n", bv1);
	}
	void setBoxMax(const float2& bmx)
	{
		if(bmx == float2(1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".bmx\" -type \"float2\" ");
		bmx.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBoxMaxU(float bu2)
	{
		if(bu2 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bmx.bu2\" %f;\n", bu2);
	}
	void setBoxMaxV(float bv2)
	{
		if(bv2 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bmx.bv2\" %f;\n", bv2);
	}
	void setFast(bool fa)
	{
		if(fa == true) return;
		fprintf(mFile,"\tsetAttr \".fa\" %i;\n", fa);
	}
	void getNumberOfWaves()const
	{
		fprintf(mFile,"\"%s.nw\"",mName.c_str());
	}
	void getWaveTime()const
	{
		fprintf(mFile,"\"%s.wt\"",mName.c_str());
	}
	void getWaveVelocity()const
	{
		fprintf(mFile,"\"%s.wv\"",mName.c_str());
	}
	void getWaveAmplitude()const
	{
		fprintf(mFile,"\"%s.wa\"",mName.c_str());
	}
	void getWaveFrequency()const
	{
		fprintf(mFile,"\"%s.wf\"",mName.c_str());
	}
	void getSubWaveFrequency()const
	{
		fprintf(mFile,"\"%s.swf\"",mName.c_str());
	}
	void getSmoothness()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
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
	void getRippleTime()const
	{
		fprintf(mFile,"\"%s.rt\"",mName.c_str());
	}
	void getRippleFrequency()const
	{
		fprintf(mFile,"\"%s.rf\"",mName.c_str());
	}
	void getRippleAmplitude()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getDropSize()const
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());
	}
	void getRippleOrigin()const
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());
	}
	void getRippleOriginU()const
	{
		fprintf(mFile,"\"%s.rc.rcu\"",mName.c_str());
	}
	void getRippleOriginV()const
	{
		fprintf(mFile,"\"%s.rc.rcv\"",mName.c_str());
	}
	void getGroupVelocity()const
	{
		fprintf(mFile,"\"%s.gv\"",mName.c_str());
	}
	void getPhaseVelocity()const
	{
		fprintf(mFile,"\"%s.pv\"",mName.c_str());
	}
	void getSpreadStart()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getSpreadRate()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getReflectionBox()const
	{
		fprintf(mFile,"\"%s.rb\"",mName.c_str());
	}
	void getBoxMin()const
	{
		fprintf(mFile,"\"%s.bmn\"",mName.c_str());
	}
	void getBoxMinU()const
	{
		fprintf(mFile,"\"%s.bmn.bu1\"",mName.c_str());
	}
	void getBoxMinV()const
	{
		fprintf(mFile,"\"%s.bmn.bv1\"",mName.c_str());
	}
	void getBoxMax()const
	{
		fprintf(mFile,"\"%s.bmx\"",mName.c_str());
	}
	void getBoxMaxU()const
	{
		fprintf(mFile,"\"%s.bmx.bu2\"",mName.c_str());
	}
	void getBoxMaxV()const
	{
		fprintf(mFile,"\"%s.bmx.bv2\"",mName.c_str());
	}
	void getFast()const
	{
		fprintf(mFile,"\"%s.fa\"",mName.c_str());
	}
protected:
	Water(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture2d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_WATER_H__
