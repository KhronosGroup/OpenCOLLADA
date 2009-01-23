/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	CacheFile(FILE* file,const std::string& name,const std::string& parent=""):CacheBase(file, name, parent, "cacheFile"){}
	virtual ~CacheFile(){}
	void setCacheName(const string& cn)
	{
		if(cn == "NULL") return;
		fprintf(mFile,"setAttr \".cn\" -type \"string\" ");
		cn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCachePath(const string& cp)
	{
		if(cp == "NULL") return;
		fprintf(mFile,"setAttr \".cp\" -type \"string\" ");
		cp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setChannel(size_t ch_i,const string& ch)
	{
		if(ch == "NULL") return;
		fprintf(mFile,"setAttr \".ch[%i]\" -type \"string\" ",ch_i);
		ch.write(mFile);
		fprintf(mFile,";\n");

	}
	void setChannel(size_t ch_start,size_t ch_end,string* ch)
	{
		fprintf(mFile,"setAttr \".ch[%i:%i]\" ", ch_start,ch_end);
		size_t size = (ch_end-ch_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ch[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startChannel(size_t ch_start,size_t ch_end)
	{
		fprintf(mFile,"setAttr \".ch[%i:%i]\"",ch_start,ch_end);
		fprintf(mFile," -type \"string\" ");

	}
	void appendChannel(const string& ch)
	{
		fprintf(mFile,"\n");
		ch.write(mFile);

	}
	void endChannel()
	{
		fprintf(mFile,";\n");

	}
	void setPerPtWeights(size_t ppw_i,const doubleArray& ppw)
	{
		if(ppw.size == 0) return;
		fprintf(mFile,"setAttr \".ppw[%i]\" -type \"doubleArray\" ",ppw_i);
		ppw.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPerPtWeights(size_t ppw_start,size_t ppw_end,doubleArray* ppw)
	{
		fprintf(mFile,"setAttr \".ppw[%i:%i]\" ", ppw_start,ppw_end);
		size_t size = (ppw_end-ppw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ppw[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startPerPtWeights(size_t ppw_start,size_t ppw_end)
	{
		fprintf(mFile,"setAttr \".ppw[%i:%i]\"",ppw_start,ppw_end);
		fprintf(mFile," -type \"doubleArray\" ");

	}
	void appendPerPtWeights(const doubleArray& ppw)
	{
		fprintf(mFile,"\n");
		ppw.write(mFile);

	}
	void endPerPtWeights()
	{
		fprintf(mFile,";\n");

	}
	void setScale(double sc)
	{
		if(sc == 1.0) return;
		fprintf(mFile,"setAttr \".sc\" %f;\n", sc);

	}
	void setPreCycle(double cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"setAttr \".cb\" %f;\n", cb);

	}
	void setPostCycle(double ca)
	{
		if(ca == 0.0) return;
		fprintf(mFile,"setAttr \".ca\" %f;\n", ca);

	}
	void setEnable(bool en)
	{
		if(en == 1) return;
		fprintf(mFile,"setAttr \".en\" %i;\n", en);

	}
	void setTrack(short tr)
	{
		if(tr == 0) return;
		fprintf(mFile,"setAttr \".tr\" %i;\n", tr);

	}
	void setTrackState(short ts)
	{
		if(ts == 0) return;
		fprintf(mFile,"setAttr \".ts\" %i;\n", ts);

	}
	void setMultiThread(bool mt)
	{
		if(mt == 0) return;
		fprintf(mFile,"setAttr \".mt\" %i;\n", mt);

	}
	void setMemQueueSize(int qs)
	{
		if(qs == 20) return;
		fprintf(mFile,"setAttr \".qs\" %i;\n", qs);

	}
	void setDisplayLoadProgress(bool dp)
	{
		if(dp == 1) return;
		fprintf(mFile,"setAttr \".dp\" %i;\n", dp);

	}
	void getCacheName()
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());

	}
	void getCachePath()
	{
		fprintf(mFile,"\"%s.cp\"",mName.c_str());

	}
	void getChannel(size_t ch_i)
	{
		fprintf(mFile,"\"%s.ch[%i]\"",mName.c_str(),ch_i);

	}
	void getCacheWeights()
	{
		fprintf(mFile,"\"%s.cw\"",mName.c_str());

	}
	void getPerPtWeights(size_t ppw_i)
	{
		fprintf(mFile,"\"%s.ppw[%i]\"",mName.c_str(),ppw_i);

	}
	void getOriginalStart()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getOriginalEnd()
	{
		fprintf(mFile,"\"%s.oe\"",mName.c_str());

	}
	void getSourceStart()
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getSourceEnd()
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());

	}
	void getStartFrame()
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getHold()
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());

	}
	void getPreCycle()
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());

	}
	void getPostCycle()
	{
		fprintf(mFile,"\"%s.ca\"",mName.c_str());

	}
	void getStart()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getEnd()
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());

	}
	void getTime()
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());

	}
	void getEnable()
	{
		fprintf(mFile,"\"%s.en\"",mName.c_str());

	}
	void getTrack()
	{
		fprintf(mFile,"\"%s.tr\"",mName.c_str());

	}
	void getTrackState()
	{
		fprintf(mFile,"\"%s.ts\"",mName.c_str());

	}
	void getMultiThread()
	{
		fprintf(mFile,"\"%s.mt\"",mName.c_str());

	}
	void getMemQueueSize()
	{
		fprintf(mFile,"\"%s.qs\"",mName.c_str());

	}
	void getDisplayLoadProgress()
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());

	}
protected:
	CacheFile(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CacheBase(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CACHEFILE_H__
