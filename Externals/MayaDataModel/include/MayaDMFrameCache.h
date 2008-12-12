/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FRAMECACHE_H__
#define __MayaDM_FRAMECACHE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    Frame cache node.  Caches a double stream's value across a set of frames.
    Presents outputs based on integer frame offsets (eg. output 1 is the
    stream's value at "frame + 1").
</pre></p>
*/
class FrameCache : public DependNode
{
public:
public:
	FrameCache(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "frameCache"){}
	virtual ~FrameCache(){}
	/*Cache output.  Value at the given frame plus offset of the multi-index.*/
	void setFuture(size_t f_i,const DoubleID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f[%i]\";\n",mName.c_str(),f_i);}
	/*Cache output.  Value at the given frame minus offset of the multi-index.*/
	void setPast(size_t p_i,const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*Value at the frame corresponding to "varyTime"*/
	void setVarying(const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*Time that the "varying" output is based on*/
	void setVaryTime(double vt){if(vt == 0.0) return; fprintf_s(mFile, "setAttr \".vt\" %f;\n", vt);}
	/*Time that the "varying" output is based on*/
	void setVaryTime(const DoubleID& vt){fprintf_s(mFile,"connectAttr \"");vt.write(mFile);fprintf_s(mFile,"\" \"%s.vt\";\n",mName.c_str());}
	/*Input data stream.  Animated number to be cached.*/
	void setStream(double s){if(s == 0.0) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*Input data stream.  Animated number to be cached.*/
	void setStream(const DoubleID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Cache output.  Value at the given frame plus offset of the multi-index.*/
	const DoubleID& getFuture(size_t f_i){char buffer[4096];sprintf_s (buffer, "%s.f[%i]",mName.c_str(),f_i);return (const char*)buffer;}
	/*Cache output.  Value at the given frame minus offset of the multi-index.*/
	const DoubleID& getPast(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*Value at the frame corresponding to "varyTime"*/
	DoubleID getVarying(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*Time that the "varying" output is based on*/
	DoubleID getVaryTime(){char buffer[4096];sprintf_s (buffer, "%s.vt",mName.c_str());return (const char*)buffer;}
	/*Input data stream.  Animated number to be cached.*/
	DoubleID getStream(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
protected:
	FrameCache(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FRAMECACHE_H__
