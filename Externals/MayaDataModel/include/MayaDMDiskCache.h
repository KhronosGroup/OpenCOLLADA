/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISKCACHE_H__
#define __MayaDM_DISKCACHE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> The diskCache node maintains the relationship between a .iff
 cache file on disk and a node that is utilizing the cache data.
 Each diskCache is registered with the globalCacheControl node,
 which can be used to globally enable and disable the cache.
 The diskCache node returns a "file descriptor" in the form of
 FLfile, which is understood by flib.h/ilib.h from Maya API.
</pre></p>
*/
class DiskCache : public DependNode
{
public:
public:
	DiskCache(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "diskCache"){}
	virtual ~DiskCache(){}
	/*
	The message attribute needs to be connected to the DG node
	which is using this diskCache instance, and which can then
	access the cached file via the method getCacheFile.
	*/
	void setDiskCache(const MessageID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*Enable or disable the disk cache*/
	void setEnable(bool ebl){if(ebl == true) return; fprintf_s(mFile, "setAttr \".ebl\" %i;\n", ebl);}
	/*Enable or disable the disk cache*/
	void setEnable(const BoolID& ebl){fprintf_s(mFile,"connectAttr \"");ebl.write(mFile);fprintf_s(mFile,"\" \"%s.ebl\";\n",mName.c_str());}
	/*The disk cache name*/
	void setCacheName(const string& cn){if(cn == "NULL") return; fprintf_s(mFile, "setAttr \".cn\" -type \"string\" ");cn.write(mFile);fprintf_s(mFile,";\n");}
	/*The disk cache name*/
	void setCacheName(const StringID& cn){fprintf_s(mFile,"connectAttr \"");cn.write(mFile);fprintf_s(mFile,"\" \"%s.cn\";\n",mName.c_str());}
	/*
	The start time in the current disk cache. This attribute is read only.
	Its value is specified at read time by the cache file data.
	*/
	void setStartTime(const TimeID& stim){fprintf_s(mFile,"connectAttr \"");stim.write(mFile);fprintf_s(mFile,"\" \"%s.stim\";\n",mName.c_str());}
	/*
	The end time in the current disk cache. This attribute is read only.
	Its value is specified at read time by the cache file data.
	*/
	void setEndTime(const TimeID& etim){fprintf_s(mFile,"connectAttr \"");etim.write(mFile);fprintf_s(mFile,"\" \"%s.etim\";\n",mName.c_str());}
	/*How frequently the frames are sampled.*/
	void setSamplingType(const UnsignedintID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*
	The oversampling rate of the current disk cache. This attribute is read only.
	Its value is specified at read time by the cache file data.
	*/
	void setSamplingRate(const IntID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	The disk cache type with "mcfi" for particle initial cache, "mcfp" for particle
	playback cache, and "mcj" for jiggle cache.
	*/
	void setCacheType(const string& ct){if(ct == "NULL") return; fprintf_s(mFile, "setAttr \".ct\" -type \"string\" ");ct.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The disk cache type with "mcfi" for particle initial cache, "mcfp" for particle
	playback cache, and "mcj" for jiggle cache.
	*/
	void setCacheType(const StringID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*The hidden disk cache name*/
	void setHiddenCacheName(const string& hcn){if(hcn == "NULL") return; fprintf_s(mFile, "setAttr \".hcn\" -type \"string\" ");hcn.write(mFile);fprintf_s(mFile,";\n");}
	/*The hidden disk cache name*/
	void setHiddenCacheName(const StringID& hcn){fprintf_s(mFile,"connectAttr \"");hcn.write(mFile);fprintf_s(mFile,"\" \"%s.hcn\";\n",mName.c_str());}
	/*
	Maya requires cache modifications (such as Delete, Append
	and Truncate) to be made on local copies of disk cache files.
	When true, Maya places copies of a cache's data file in a uniquely
	named directory in the user's temporary directory
	(described by the MEL command "internalVar -userTmpDir").
	However, for performance reasons, you may wish to disable automatic
	creation of these local disk cache copies by setting
	this attribute to false.
	*/
	void setCopyLocally(bool cpl){if(cpl == true) return; fprintf_s(mFile, "setAttr \".cpl\" %i;\n", cpl);}
	/*
	Maya requires cache modifications (such as Delete, Append
	and Truncate) to be made on local copies of disk cache files.
	When true, Maya places copies of a cache's data file in a uniquely
	named directory in the user's temporary directory
	(described by the MEL command "internalVar -userTmpDir").
	However, for performance reasons, you may wish to disable automatic
	creation of these local disk cache copies by setting
	this attribute to false.
	*/
	void setCopyLocally(const BoolID& cpl){fprintf_s(mFile,"connectAttr \"");cpl.write(mFile);fprintf_s(mFile,"\" \"%s.cpl\";\n",mName.c_str());}
	/*
	The message attribute needs to be connected to the DG node
	which is using this diskCache instance, and which can then
	access the cached file via the method getCacheFile.
	*/
	MessageID getDiskCache(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*Enable or disable the disk cache*/
	BoolID getEnable(){char buffer[4096];sprintf_s (buffer, "%s.ebl",mName.c_str());return (const char*)buffer;}
	/*The disk cache name*/
	StringID getCacheName(){char buffer[4096];sprintf_s (buffer, "%s.cn",mName.c_str());return (const char*)buffer;}
	/*
	The start time in the current disk cache. This attribute is read only.
	Its value is specified at read time by the cache file data.
	*/
	TimeID getStartTime(){char buffer[4096];sprintf_s (buffer, "%s.stim",mName.c_str());return (const char*)buffer;}
	/*
	The end time in the current disk cache. This attribute is read only.
	Its value is specified at read time by the cache file data.
	*/
	TimeID getEndTime(){char buffer[4096];sprintf_s (buffer, "%s.etim",mName.c_str());return (const char*)buffer;}
	/*How frequently the frames are sampled.*/
	UnsignedintID getSamplingType(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*
	The oversampling rate of the current disk cache. This attribute is read only.
	Its value is specified at read time by the cache file data.
	*/
	IntID getSamplingRate(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	The disk cache type with "mcfi" for particle initial cache, "mcfp" for particle
	playback cache, and "mcj" for jiggle cache.
	*/
	StringID getCacheType(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*The hidden disk cache name*/
	StringID getHiddenCacheName(){char buffer[4096];sprintf_s (buffer, "%s.hcn",mName.c_str());return (const char*)buffer;}
	/*
	Maya requires cache modifications (such as Delete, Append
	and Truncate) to be made on local copies of disk cache files.
	When true, Maya places copies of a cache's data file in a uniquely
	named directory in the user's temporary directory
	(described by the MEL command "internalVar -userTmpDir").
	However, for performance reasons, you may wish to disable automatic
	creation of these local disk cache copies by setting
	this attribute to false.
	*/
	BoolID getCopyLocally(){char buffer[4096];sprintf_s (buffer, "%s.cpl",mName.c_str());return (const char*)buffer;}
protected:
	DiskCache(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DISKCACHE_H__
