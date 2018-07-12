/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CACHEFILE_H__
#define __MayaDM_CACHEFILE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCacheBase.h"
namespace MayaDM
{
class CacheFile : public CacheBase
{
public:
public:

	CacheFile():CacheBase(){}
	CacheFile(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:CacheBase(file, name, parent, "cacheFile", shared, create){}
	virtual ~CacheFile(){}

	void setCacheName(const string& cn)
	{
		if(cn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cn\" -type \"string\" ");
		cn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCachePath(const string& cp)
	{
		if(cp == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cp\" -type \"string\" ");
		cp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setChannel(size_t ch_i,const string& ch)
	{
		if(ch == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ch[%i]\" -type \"string\" ",ch_i);
		ch.write(mFile);
		fprintf(mFile,";\n");
	}
	void setChannel(size_t ch_start,size_t ch_end,string* ch)
	{
		fprintf(mFile,"\tsetAttr \".ch[%i:%i]\" ", ch_start,ch_end);
		size_t size = (ch_end-ch_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ch[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startChannel(size_t ch_start,size_t ch_end)const
	{
		fprintf(mFile,"\tsetAttr \".ch[%i:%i]\"",ch_start,ch_end);
		fprintf(mFile," -type \"string\" ");
	}
	void appendChannel(const string& ch)const
	{
		fprintf(mFile," ");
		ch.write(mFile);
	}
	void endChannel()const
	{
		fprintf(mFile,";\n");
	}
	void setPerPtWeights(size_t ppw_i,const doubleArray& ppw)
	{
		if(ppw.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ppw[%i]\" -type \"doubleArray\" ",ppw_i);
		ppw.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPerPtWeights(size_t ppw_start,size_t ppw_end,doubleArray* ppw)
	{
		fprintf(mFile,"\tsetAttr \".ppw[%i:%i]\" ", ppw_start,ppw_end);
		size_t size = (ppw_end-ppw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ppw[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startPerPtWeights(size_t ppw_start,size_t ppw_end)const
	{
		fprintf(mFile,"\tsetAttr \".ppw[%i:%i]\"",ppw_start,ppw_end);
		fprintf(mFile," -type \"doubleArray\" ");
	}
	void appendPerPtWeights(const doubleArray& ppw)const
	{
		fprintf(mFile," ");
		ppw.write(mFile);
	}
	void endPerPtWeights()const
	{
		fprintf(mFile,";\n");
	}
	void setOriginalStart(double os)
	{
		if(os == 0) return;
		fprintf(mFile,"\tsetAttr \".os\" %f;\n", os);
	}
	void setOriginalEnd(double oe)
	{
		if(oe == 0) return;
		fprintf(mFile,"\tsetAttr \".oe\" %f;\n", oe);
	}
	void setSourceStart(double ss)
	{
		if(ss == 0) return;
		fprintf(mFile,"\tsetAttr \".ss\" %f;\n", ss);
	}
	void setSourceEnd(double se)
	{
		if(se == 0) return;
		fprintf(mFile,"\tsetAttr \".se\" %f;\n", se);
	}
	void setStartFrame(double sf)
	{
		if(sf == 0) return;
		fprintf(mFile,"\tsetAttr \".sf\" %f;\n", sf);
	}
	void setScale(double sc)
	{
		if(sc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sc\" %f;\n", sc);
	}
	void setHold(double h)
	{
		if(h == 0) return;
		fprintf(mFile,"\tsetAttr \".h\" %f;\n", h);
	}
	void setPreCycle(double cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cb\" %f;\n", cb);
	}
	void setPostCycle(double ca)
	{
		if(ca == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ca\" %f;\n", ca);
	}
	void setTime(double tim)
	{
		if(tim == 0) return;
		fprintf(mFile,"\tsetAttr \".tim\" %f;\n", tim);
	}
	void setEnable(bool en)
	{
		if(en == 1) return;
		fprintf(mFile,"\tsetAttr \".en\" %i;\n", en);
	}
	void setTrack(short tr)
	{
		if(tr == 0) return;
		fprintf(mFile,"\tsetAttr \".tr\" %i;\n", tr);
	}
	void setTrackState(short ts)
	{
		if(ts == 0) return;
		fprintf(mFile,"\tsetAttr \".ts\" %i;\n", ts);
	}
	void setMultiThread(bool mt)
	{
		if(mt == 0) return;
		fprintf(mFile,"\tsetAttr \".mt\" %i;\n", mt);
	}
	void setMemQueueSize(int qs)
	{
		if(qs == 20) return;
		fprintf(mFile,"\tsetAttr \".qs\" %i;\n", qs);
	}
	void setDisplayLoadProgress(bool dp)
	{
		if(dp == 1) return;
		fprintf(mFile,"\tsetAttr \".dp\" %i;\n", dp);
	}
	void getCacheName()const
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());
	}
	void getCachePath()const
	{
		fprintf(mFile,"\"%s.cp\"",mName.c_str());
	}
	void getChannel(size_t ch_i)const
	{
		fprintf(mFile,"\"%s.ch[%i]\"",mName.c_str(),ch_i);
	}
	void getChannel()const
	{

		fprintf(mFile,"\"%s.ch\"",mName.c_str());
	}
	void getCacheWeights()const
	{
		fprintf(mFile,"\"%s.cw\"",mName.c_str());
	}
	void getPerPtWeights(size_t ppw_i)const
	{
		fprintf(mFile,"\"%s.ppw[%i]\"",mName.c_str(),ppw_i);
	}
	void getPerPtWeights()const
	{

		fprintf(mFile,"\"%s.ppw\"",mName.c_str());
	}
	void getOriginalStart()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getOriginalEnd()const
	{
		fprintf(mFile,"\"%s.oe\"",mName.c_str());
	}
	void getSourceStart()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getSourceEnd()const
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());
	}
	void getStartFrame()const
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getHold()const
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getPreCycle()const
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());
	}
	void getPostCycle()const
	{
		fprintf(mFile,"\"%s.ca\"",mName.c_str());
	}
	void getStart()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getEnd()const
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());
	}
	void getEnable()const
	{
		fprintf(mFile,"\"%s.en\"",mName.c_str());
	}
	void getTrack()const
	{
		fprintf(mFile,"\"%s.tr\"",mName.c_str());
	}
	void getTrackState()const
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());
	}
	void getMultiThread()const
	{
		fprintf(mFile,"\"%s.mt\"",mName.c_str());
	}
	void getMemQueueSize()const
	{
		fprintf(mFile,"\"%s.qs\"",mName.c_str());
	}
	void getDisplayLoadProgress()const
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());
	}
protected:
	CacheFile(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:CacheBase(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CACHEFILE_H__
