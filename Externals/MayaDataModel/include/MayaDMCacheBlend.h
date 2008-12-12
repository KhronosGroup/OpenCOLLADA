/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CACHEBLEND_H__
#define __MayaDM_CACHEBLEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCacheBase.h"
namespace MayaDM
{
/*
<p><pre>
 The cacheBlend node corresponds to a nonlinear track. It can contain
 any number of cacheFiles over time, and controls their evaluation and
 weighting over time.

 To evaluate at a given time, the node determines which caches are active.
 It then does a normalized weighted blend of the active caches based
 on their weight and per-point cacheWeight values.

</pre></p>
*/
class CacheBlend : public CacheBase
{
public:
	/*Parent attribute for input cache vectors.*/
	struct InCache{
		doubleArray* perPtWeights;
		void write(FILE* file) const
		{
			size_t size = sizeof(perPtWeights)/sizeof(doubleArray);
			for(size_t i=0; i<size; ++i)
			{
				perPtWeights[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*Parent attribute for per-cache data.*/
	struct CacheData{
		bool range;
		double weight;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", range);
			fprintf_s(file,"%f", weight);
		}
	};
public:
	CacheBlend(FILE* file,const std::string& name,const std::string& parent=""):CacheBase(file, name, parent, "cacheBlend"){}
	virtual ~CacheBlend(){}
	/*Parent attribute for input cache vectors.*/
	void setInCache(size_t ic_i,const InCache& ic){fprintf_s(mFile, "setAttr \".ic[%i]\" ",ic_i);ic.write(mFile);fprintf_s(mFile,";\n");}
	/*Parent attribute for input cache vectors.*/
	void setInCache(size_t ic_i,const InCacheID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i]\";\n",mName.c_str(),ic_i);}
	/*vector array inputs data to be blended*/
	void setVectorArray(size_t ic_i,size_t va_i,const GenericID& va){fprintf_s(mFile,"connectAttr \"");va.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i].va[%i]\";\n",mName.c_str(),ic_i,va_i);}
	/*
	Per-point weights for the cache. If unset, treated as all 1.0.
	The per-point weights are multiplied by the per-cache weight attribute
	and normalized against the weights of any other active caches.
	*/
	void setPerPtWeights(size_t ic_i,size_t ppw_i,const doubleArray& ppw){if(ppw.size == 0) return; fprintf_s(mFile, "setAttr \".ic[%i].ppw[%i]\" -type \"doubleArray\" ",ic_i,ppw_i);ppw.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Per-point weights for the cache. If unset, treated as all 1.0.
	The per-point weights are multiplied by the per-cache weight attribute
	and normalized against the weights of any other active caches.
	*/
	void setPerPtWeights(size_t ic_i,size_t ppw_i,const DoubleArrayID& ppw){fprintf_s(mFile,"connectAttr \"");ppw.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i].ppw[%i]\";\n",mName.c_str(),ic_i,ppw_i);}
	/*
	This attribute can be used to disable the blend entirely
	so that it does not evaluate any of the input caches at all.
	It does not modify the enable attributes on the input caches
	themselves.
	*/
	void setDisableAll(bool da){if(da == 0) return; fprintf_s(mFile, "setAttr \".da\" %i;\n", da);}
	/*
	This attribute can be used to disable the blend entirely
	so that it does not evaluate any of the input caches at all.
	It does not modify the enable attributes on the input caches
	themselves.
	*/
	void setDisableAll(const BoolID& da){fprintf_s(mFile,"connectAttr \"");da.write(mFile);fprintf_s(mFile,"\" \"%s.da\";\n",mName.c_str());}
	/*Parent attribute for per-cache data.*/
	void setCacheData(size_t cd_i,const CacheData& cd){fprintf_s(mFile, "setAttr \".cd[%i]\" ",cd_i);cd.write(mFile);fprintf_s(mFile,";\n");}
	/*Parent attribute for per-cache data.*/
	void setCacheData(size_t cd_i,const CacheDataID& cd){fprintf_s(mFile,"connectAttr \"");cd.write(mFile);fprintf_s(mFile,"\" \"%s.cd[%i]\";\n",mName.c_str(),cd_i);}
	/*
	The actual start frame for the associated inVector, taking into
	account holds, scales, trims, etcetera.
	*/
	void setStart(size_t cd_i,const TimeID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.cd[%i].st\";\n",mName.c_str(),cd_i);}
	/*
	The actual end frame for the associated inVector, taking into
	account holds, scales, trims, etcetera.
	*/
	void setEnd(size_t cd_i,const TimeID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.cd[%i].e\";\n",mName.c_str(),cd_i);}
	/*Whether the input clip is in range.*/
	void setRange(size_t cd_i,bool ra){if(ra == false) return; fprintf_s(mFile, "setAttr \".cd[%i].ra\" %i;\n", cd_i,ra);}
	/*Whether the input clip is in range.*/
	void setRange(size_t cd_i,const BoolID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.cd[%i].ra\";\n",mName.c_str(),cd_i);}
	/*
	Weight for the cache. This weight will be normalized against any
	other caches on the track at the current time.
	*/
	void setWeight(size_t cd_i,double w){if(w == 1.0) return; fprintf_s(mFile, "setAttr \".cd[%i].w\" %f;\n", cd_i,w);}
	/*
	Weight for the cache. This weight will be normalized against any
	other caches on the track at the current time.
	*/
	void setWeight(size_t cd_i,const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.cd[%i].w\";\n",mName.c_str(),cd_i);}
	/*Parent attribute for input cache vectors.*/
	const InCacheID& getInCache(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i]",mName.c_str(),ic_i);return (const char*)buffer;}
	/*vector array inputs data to be blended*/
	const GenericID& getVectorArray(size_t ic_i,size_t va_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i].va[%i]",mName.c_str(),ic_i,va_i);return (const char*)buffer;}
	/*
	Per-point weights for the cache. If unset, treated as all 1.0.
	The per-point weights are multiplied by the per-cache weight attribute
	and normalized against the weights of any other active caches.
	*/
	const DoubleArrayID& getPerPtWeights(size_t ic_i,size_t ppw_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i].ppw[%i]",mName.c_str(),ic_i,ppw_i);return (const char*)buffer;}
	/*
	This attribute can be used to disable the blend entirely
	so that it does not evaluate any of the input caches at all.
	It does not modify the enable attributes on the input caches
	themselves.
	*/
	BoolID getDisableAll(){char buffer[4096];sprintf_s (buffer, "%s.da",mName.c_str());return (const char*)buffer;}
	/*Parent attribute for per-cache data.*/
	const CacheDataID& getCacheData(size_t cd_i){char buffer[4096];sprintf_s (buffer, "%s.cd[%i]",mName.c_str(),cd_i);return (const char*)buffer;}
	/*
	The actual start frame for the associated inVector, taking into
	account holds, scales, trims, etcetera.
	*/
	const TimeID& getStart(size_t cd_i){char buffer[4096];sprintf_s (buffer, "%s.cd[%i].st",mName.c_str(),cd_i);return (const char*)buffer;}
	/*
	The actual end frame for the associated inVector, taking into
	account holds, scales, trims, etcetera.
	*/
	const TimeID& getEnd(size_t cd_i){char buffer[4096];sprintf_s (buffer, "%s.cd[%i].e",mName.c_str(),cd_i);return (const char*)buffer;}
	/*Whether the input clip is in range.*/
	const BoolID& getRange(size_t cd_i){char buffer[4096];sprintf_s (buffer, "%s.cd[%i].ra",mName.c_str(),cd_i);return (const char*)buffer;}
	/*
	Weight for the cache. This weight will be normalized against any
	other caches on the track at the current time.
	*/
	const DoubleID& getWeight(size_t cd_i){char buffer[4096];sprintf_s (buffer, "%s.cd[%i].w",mName.c_str(),cd_i);return (const char*)buffer;}
protected:
	CacheBlend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CacheBase(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CACHEBLEND_H__
