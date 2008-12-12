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
/*
<p><pre>
 The cacheFile node maintains an association between cached data on disk and
 an output attribute. The cached data on disk is usually created by the
 cacheFile command. For example, let's say that you create cache data files
 containing vector arrays for frames 1-100. The cacheFile node can be used
 to read in the data from those files and output it to its vectorArrayOutput
 attribute.

 This output attribute can then be connected to any vectorArray input
 attribute that wants to use the data from disk.

</pre></p>
*/
class CacheFile : public CacheBase
{
public:
public:
	CacheFile(FILE* file,const std::string& name,const std::string& parent=""):CacheBase(file, name, parent, "cacheFile"){}
	virtual ~CacheFile(){}
	/*The name of the disk cache file*/
	void setCacheName(const string& cn){if(cn == "NULL") return; fprintf_s(mFile, "setAttr \".cn\" -type \"string\" ");cn.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the disk cache file*/
	void setCacheName(const StringID& cn){fprintf_s(mFile,"connectAttr \"");cn.write(mFile);fprintf_s(mFile,"\" \"%s.cn\";\n",mName.c_str());}
	/*The path to the disk cache file*/
	void setCachePath(const string& cp){if(cp == "NULL") return; fprintf_s(mFile, "setAttr \".cp\" -type \"string\" ");cp.write(mFile);fprintf_s(mFile,";\n");}
	/*The path to the disk cache file*/
	void setCachePath(const StringID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp\";\n",mName.c_str());}
	/*
	The channel name of the channel in the cache file that should be
	hooked up to the associated outVectorArray
	*/
	void setChannel(size_t ch_i,const string& ch){if(ch == "NULL") return; fprintf_s(mFile, "setAttr \".ch[%i]\" -type \"string\" ",ch_i);ch.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The channel name of the channel in the cache file that should be
	hooked up to the associated outVectorArray
	*/
	void setChannel(size_t ch_i,const StringID& ch){fprintf_s(mFile,"connectAttr \"");ch.write(mFile);fprintf_s(mFile,"\" \"%s.ch[%i]\";\n",mName.c_str(),ch_i);}
	/*Weights for the cache*/
	void setCacheWeights(const DoubleArrayID& cw){fprintf_s(mFile,"connectAttr \"");cw.write(mFile);fprintf_s(mFile,"\" \"%s.cw\";\n",mName.c_str());}
	/*Weights for the cache*/
	void setPerPtWeights(size_t ppw_i,const doubleArray& ppw){if(ppw.size == 0) return; fprintf_s(mFile, "setAttr \".ppw[%i]\" -type \"doubleArray\" ",ppw_i);ppw.write(mFile);fprintf_s(mFile,";\n");}
	/*Weights for the cache*/
	void setPerPtWeights(size_t ppw_i,const DoubleArrayID& ppw){fprintf_s(mFile,"connectAttr \"");ppw.write(mFile);fprintf_s(mFile,"\" \"%s.ppw[%i]\";\n",mName.c_str(),ppw_i);}
	/*
	The time when the original cache starts.
	Used as reference to know where the actual start
	of the cache data on disk.
	*/
	void setOriginalStart(const TimeID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*
	The time when the original cache ends.
	Used as reference to know where the actual end
	of the cache data on disk.
	*/
	void setOriginalEnd(const TimeID& oe){fprintf_s(mFile,"connectAttr \"");oe.write(mFile);fprintf_s(mFile,"\" \"%s.oe\";\n",mName.c_str());}
	/*
	The time when playback starts, in terms of the time on the original cache.
	Can be used to trim the beginning portion of the cache to
	the desired starting point.
	For example, say the original cache was created for time 0-50.
	We stretch this cache out to 0-100, and then truncate the first 25 frames.
	In this case, sourceStart would have value 12.5 (25% of the original cache).
	*/
	void setSourceStart(const TimeID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*
	The time when playback starts, in terms of the time on the original cache.
	Used to trim the ending portion of the cache to
	the desired ending point.
	See description on sourceStart for details.
	*/
	void setSourceEnd(const TimeID& se){fprintf_s(mFile,"connectAttr \"");se.write(mFile);fprintf_s(mFile,"\" \"%s.se\";\n",mName.c_str());}
	/*The start frame where the cache will start playback.*/
	void setStartFrame(const TimeID& sf){fprintf_s(mFile,"connectAttr \"");sf.write(mFile);fprintf_s(mFile,"\" \"%s.sf\";\n",mName.c_str());}
	/*Used to scale the cache playback*/
	void setScale(double sc){if(sc == 1.0) return; fprintf_s(mFile, "setAttr \".sc\" %f;\n", sc);}
	/*Used to scale the cache playback*/
	void setScale(const DoubleID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*Length of time that the cache holds its end value.*/
	void setHold(const TimeID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*
	The preCycle value is used to repeat the cache, in whole or in part,
	before the beginning of the original cache.
	*/
	void setPreCycle(double cb){if(cb == 0.0) return; fprintf_s(mFile, "setAttr \".cb\" %f;\n", cb);}
	/*
	The preCycle value is used to repeat the cache, in whole or in part,
	before the beginning of the original cache.
	*/
	void setPreCycle(const DoubleID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cb\";\n",mName.c_str());}
	/*
	The postCycle value is used to repeat the cache, in whole or in part,
	after the end of the basic cache.
	*/
	void setPostCycle(double ca){if(ca == 0.0) return; fprintf_s(mFile, "setAttr \".ca\" %f;\n", ca);}
	/*
	The postCycle value is used to repeat the cache, in whole or in part,
	after the end of the basic cache.
	*/
	void setPostCycle(const DoubleID& ca){fprintf_s(mFile,"connectAttr \"");ca.write(mFile);fprintf_s(mFile,"\" \"%s.ca\";\n",mName.c_str());}
	/*When the cache playback will begin based on the startFrame and preCycle.*/
	void setStart(const TimeID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*When the cache playback will end based on the startFrame, scale, etc.*/
	void setEnd(const TimeID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e\";\n",mName.c_str());}
	/*The current time.*/
	void setTime(const TimeID& tim){fprintf_s(mFile,"connectAttr \"");tim.write(mFile);fprintf_s(mFile,"\" \"%s.tim\";\n",mName.c_str());}
	/*Whether or not the cache is enabled for playback*/
	void setEnable(bool en){if(en == 1) return; fprintf_s(mFile, "setAttr \".en\" %i;\n", en);}
	/*Whether or not the cache is enabled for playback*/
	void setEnable(const BoolID& en){fprintf_s(mFile,"connectAttr \"");en.write(mFile);fprintf_s(mFile,"\" \"%s.en\";\n",mName.c_str());}
	/*track index for the clip that corresponds to this cache*/
	void setTrack(short tr){if(tr == 0) return; fprintf_s(mFile, "setAttr \".tr\" %i;\n", tr);}
	/*track index for the clip that corresponds to this cache*/
	void setTrack(const ShortID& tr){fprintf_s(mFile,"connectAttr \"");tr.write(mFile);fprintf_s(mFile,"\" \"%s.tr\";\n",mName.c_str());}
	/*
	Flag bits for the track state.  Current mask values are:
	1: when set means that all the caches on the track are locked
	2: when set means that all the caches on the track are soloed
	4: when set means that all the caches on the track are muted
	8: when set means that another track is soloed, so this track acts as if it is muted
	*/
	void setTrackState(short ts){if(ts == 0) return; fprintf_s(mFile, "setAttr \".ts\" %i;\n", ts);}
	/*
	Flag bits for the track state.  Current mask values are:
	1: when set means that all the caches on the track are locked
	2: when set means that all the caches on the track are soloed
	4: when set means that all the caches on the track are muted
	8: when set means that another track is soloed, so this track acts as if it is muted
	*/
	void setTrackState(const ShortID& ts){fprintf_s(mFile,"connectAttr \"");ts.write(mFile);fprintf_s(mFile,"\" \"%s.ts\";\n",mName.c_str());}
	/*Whether or not the cache is setup for multithreading during playback*/
	void setMultiThread(bool mt){if(mt == 0) return; fprintf_s(mFile, "setAttr \".mt\" %i;\n", mt);}
	/*Whether or not the cache is setup for multithreading during playback*/
	void setMultiThread(const BoolID& mt){fprintf_s(mFile,"connectAttr \"");mt.write(mFile);fprintf_s(mFile,"\" \"%s.mt\";\n",mName.c_str());}
	/*
	If multithreading is enabled and is not setup to preload the entire cache,
	then attribute indicates the number of time entries the cache will try to
	preload and keep in memory.
	*/
	void setMemQueueSize(int qs){if(qs == 20) return; fprintf_s(mFile, "setAttr \".qs\" %i;\n", qs);}
	/*
	If multithreading is enabled and is not setup to preload the entire cache,
	then attribute indicates the number of time entries the cache will try to
	preload and keep in memory.
	*/
	void setMemQueueSize(const IntID& qs){fprintf_s(mFile,"connectAttr \"");qs.write(mFile);fprintf_s(mFile,"\" \"%s.qs\";\n",mName.c_str());}
	/*
	Whether or not to display the what percentage of the memory queue
	is full when multithreading is on.
	*/
	void setDisplayLoadProgress(bool dp){if(dp == 1) return; fprintf_s(mFile, "setAttr \".dp\" %i;\n", dp);}
	/*
	Whether or not to display the what percentage of the memory queue
	is full when multithreading is on.
	*/
	void setDisplayLoadProgress(const BoolID& dp){fprintf_s(mFile,"connectAttr \"");dp.write(mFile);fprintf_s(mFile,"\" \"%s.dp\";\n",mName.c_str());}
	/*The name of the disk cache file*/
	StringID getCacheName(){char buffer[4096];sprintf_s (buffer, "%s.cn",mName.c_str());return (const char*)buffer;}
	/*The path to the disk cache file*/
	StringID getCachePath(){char buffer[4096];sprintf_s (buffer, "%s.cp",mName.c_str());return (const char*)buffer;}
	/*
	The channel name of the channel in the cache file that should be
	hooked up to the associated outVectorArray
	*/
	const StringID& getChannel(size_t ch_i){char buffer[4096];sprintf_s (buffer, "%s.ch[%i]",mName.c_str(),ch_i);return (const char*)buffer;}
	/*Weights for the cache*/
	DoubleArrayID getCacheWeights(){char buffer[4096];sprintf_s (buffer, "%s.cw",mName.c_str());return (const char*)buffer;}
	/*Weights for the cache*/
	const DoubleArrayID& getPerPtWeights(size_t ppw_i){char buffer[4096];sprintf_s (buffer, "%s.ppw[%i]",mName.c_str(),ppw_i);return (const char*)buffer;}
	/*
	The time when the original cache starts.
	Used as reference to know where the actual start
	of the cache data on disk.
	*/
	TimeID getOriginalStart(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*
	The time when the original cache ends.
	Used as reference to know where the actual end
	of the cache data on disk.
	*/
	TimeID getOriginalEnd(){char buffer[4096];sprintf_s (buffer, "%s.oe",mName.c_str());return (const char*)buffer;}
	/*
	The time when playback starts, in terms of the time on the original cache.
	Can be used to trim the beginning portion of the cache to
	the desired starting point.
	For example, say the original cache was created for time 0-50.
	We stretch this cache out to 0-100, and then truncate the first 25 frames.
	In this case, sourceStart would have value 12.5 (25% of the original cache).
	*/
	TimeID getSourceStart(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*
	The time when playback starts, in terms of the time on the original cache.
	Used to trim the ending portion of the cache to
	the desired ending point.
	See description on sourceStart for details.
	*/
	TimeID getSourceEnd(){char buffer[4096];sprintf_s (buffer, "%s.se",mName.c_str());return (const char*)buffer;}
	/*The start frame where the cache will start playback.*/
	TimeID getStartFrame(){char buffer[4096];sprintf_s (buffer, "%s.sf",mName.c_str());return (const char*)buffer;}
	/*Used to scale the cache playback*/
	DoubleID getScale(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*Length of time that the cache holds its end value.*/
	TimeID getHold(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*
	The preCycle value is used to repeat the cache, in whole or in part,
	before the beginning of the original cache.
	*/
	DoubleID getPreCycle(){char buffer[4096];sprintf_s (buffer, "%s.cb",mName.c_str());return (const char*)buffer;}
	/*
	The postCycle value is used to repeat the cache, in whole or in part,
	after the end of the basic cache.
	*/
	DoubleID getPostCycle(){char buffer[4096];sprintf_s (buffer, "%s.ca",mName.c_str());return (const char*)buffer;}
	/*When the cache playback will begin based on the startFrame and preCycle.*/
	TimeID getStart(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*When the cache playback will end based on the startFrame, scale, etc.*/
	TimeID getEnd(){char buffer[4096];sprintf_s (buffer, "%s.e",mName.c_str());return (const char*)buffer;}
	/*The current time.*/
	TimeID getTime(){char buffer[4096];sprintf_s (buffer, "%s.tim",mName.c_str());return (const char*)buffer;}
	/*Whether or not the cache is enabled for playback*/
	BoolID getEnable(){char buffer[4096];sprintf_s (buffer, "%s.en",mName.c_str());return (const char*)buffer;}
	/*track index for the clip that corresponds to this cache*/
	ShortID getTrack(){char buffer[4096];sprintf_s (buffer, "%s.tr",mName.c_str());return (const char*)buffer;}
	/*
	Flag bits for the track state.  Current mask values are:
	1: when set means that all the caches on the track are locked
	2: when set means that all the caches on the track are soloed
	4: when set means that all the caches on the track are muted
	8: when set means that another track is soloed, so this track acts as if it is muted
	*/
	ShortID getTrackState(){char buffer[4096];sprintf_s (buffer, "%s.ts",mName.c_str());return (const char*)buffer;}
	/*Whether or not the cache is setup for multithreading during playback*/
	BoolID getMultiThread(){char buffer[4096];sprintf_s (buffer, "%s.mt",mName.c_str());return (const char*)buffer;}
	/*
	If multithreading is enabled and is not setup to preload the entire cache,
	then attribute indicates the number of time entries the cache will try to
	preload and keep in memory.
	*/
	IntID getMemQueueSize(){char buffer[4096];sprintf_s (buffer, "%s.qs",mName.c_str());return (const char*)buffer;}
	/*
	Whether or not to display the what percentage of the memory queue
	is full when multithreading is on.
	*/
	BoolID getDisplayLoadProgress(){char buffer[4096];sprintf_s (buffer, "%s.dp",mName.c_str());return (const char*)buffer;}
protected:
	CacheFile(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CacheBase(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CACHEFILE_H__
