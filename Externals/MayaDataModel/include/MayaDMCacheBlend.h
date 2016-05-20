/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class CacheBlend : public CacheBase
{
public:
	struct InCache{
		doubleArray* perPtWeights;
		size_t nbPerPtWeights;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbPerPtWeights; ++i)
			{
				perPtWeights[i].write(file);
				if (i + 1<nbPerPtWeights) fprintf(file, " ");
			}
		}
	};
	struct CacheData{
		double start;
		double end;
		bool range;
		double weight;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", start);
			fprintf(file,"%f ", end);
			fprintf(file,"%i ", range);
			fprintf(file,"%f", weight);
		}
	};
public:

	CacheBlend():CacheBase(){}
	CacheBlend(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:CacheBase(file, name, parent, "cacheBlend", shared, create){}
	virtual ~CacheBlend(){}

	void setInCache(size_t ic_i,const InCache& ic)
	{
		fprintf(mFile,"\tsetAttr \".ic[%i]\" ",ic_i);
		ic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInCache(size_t ic_start,size_t ic_end,InCache* ic)
	{
		fprintf(mFile,"\tsetAttr \".ic[%i:%i]\" ", ic_start,ic_end);
		size_t size = (ic_end-ic_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ic[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInCache(size_t ic_start,size_t ic_end)const
	{
		fprintf(mFile,"\tsetAttr \".ic[%i:%i]\"",ic_start,ic_end);
		fprintf(mFile," -type \"InCache\" ");
	}
	void appendInCache(const InCache& ic)const
	{
		fprintf(mFile," ");
		ic.write(mFile);
	}
	void endInCache()const
	{
		fprintf(mFile,";\n");
	}
	void setPerPtWeights(size_t ic_i,size_t ppw_i,const doubleArray& ppw)
	{
		if(ppw.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ic[%i].ppw[%i]\" -type \"doubleArray\" ",ic_i,ppw_i);
		ppw.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPerPtWeights(size_t ic_i,size_t ppw_start,size_t ppw_end,doubleArray* ppw)
	{
		fprintf(mFile,"\tsetAttr \".ic[%i].ppw[%i:%i]\" ", ic_i,ppw_start,ppw_end);
		size_t size = (ppw_end-ppw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ppw[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startPerPtWeights(size_t ic_i,size_t ppw_start,size_t ppw_end)const
	{
		fprintf(mFile,"\tsetAttr \".ic[%i].ppw[%i:%i]\"",ic_i,ppw_start,ppw_end);
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
	void setDisableAll(bool da)
	{
		if(da == 0) return;
		fprintf(mFile,"\tsetAttr \".da\" %i;\n", da);
	}
	void setCacheData(size_t cd_i,const CacheData& cd)
	{
		fprintf(mFile,"\tsetAttr \".cd[%i]\" ",cd_i);
		cd.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCacheData(size_t cd_start,size_t cd_end,CacheData* cd)
	{
		fprintf(mFile,"\tsetAttr \".cd[%i:%i]\" ", cd_start,cd_end);
		size_t size = (cd_end-cd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cd[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCacheData(size_t cd_start,size_t cd_end)const
	{
		fprintf(mFile,"\tsetAttr \".cd[%i:%i]\"",cd_start,cd_end);
		fprintf(mFile," -type \"CacheData\" ");
	}
	void appendCacheData(const CacheData& cd)const
	{
		fprintf(mFile," ");
		cd.write(mFile);
	}
	void endCacheData()const
	{
		fprintf(mFile,";\n");
	}
	void setStart(size_t cd_i,double st)
	{
		if(st == 0) return;
		fprintf(mFile,"\tsetAttr \".cd[%i].st\" %f;\n", cd_i,st);
	}
	void setEnd(size_t cd_i,double e)
	{
		if(e == 0) return;
		fprintf(mFile,"\tsetAttr \".cd[%i].e\" %f;\n", cd_i,e);
	}
	void setRange(size_t cd_i,bool ra)
	{
		if(ra == false) return;
		fprintf(mFile,"\tsetAttr \".cd[%i].ra\" %i;\n", cd_i,ra);
	}
	void setWeight(size_t cd_i,double w)
	{
		if(w == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cd[%i].w\" %f;\n", cd_i,w);
	}
	void getInCache(size_t ic_i)const
	{
		fprintf(mFile,"\"%s.ic[%i]\"",mName.c_str(),ic_i);
	}
	void getInCache()const
	{

		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getVectorArray(size_t ic_i,size_t va_i)const
	{
		fprintf(mFile,"\"%s.ic[%i].va[%i]\"",mName.c_str(),ic_i,va_i);
	}
	void getVectorArray(size_t va_i)const
	{

		fprintf(mFile,"\"%s.ic.va[%i]\"",mName.c_str(),va_i);
	}
	void getPerPtWeights(size_t ic_i,size_t ppw_i)const
	{
		fprintf(mFile,"\"%s.ic[%i].ppw[%i]\"",mName.c_str(),ic_i,ppw_i);
	}
	void getPerPtWeights(size_t ppw_i)const
	{

		fprintf(mFile,"\"%s.ic.ppw[%i]\"",mName.c_str(),ppw_i);
	}
	void getDisableAll()const
	{
		fprintf(mFile,"\"%s.da\"",mName.c_str());
	}
	void getCacheData(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i]\"",mName.c_str(),cd_i);
	}
	void getCacheData()const
	{

		fprintf(mFile,"\"%s.cd\"",mName.c_str());
	}
	void getStart(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i].st\"",mName.c_str(),cd_i);
	}
	void getStart()const
	{

		fprintf(mFile,"\"%s.cd.st\"",mName.c_str());
	}
	void getEnd(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i].e\"",mName.c_str(),cd_i);
	}
	void getEnd()const
	{

		fprintf(mFile,"\"%s.cd.e\"",mName.c_str());
	}
	void getRange(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i].ra\"",mName.c_str(),cd_i);
	}
	void getRange()const
	{

		fprintf(mFile,"\"%s.cd.ra\"",mName.c_str());
	}
	void getWeight(size_t cd_i)const
	{
		fprintf(mFile,"\"%s.cd[%i].w\"",mName.c_str(),cd_i);
	}
	void getWeight()const
	{

		fprintf(mFile,"\"%s.cd.w\"",mName.c_str());
	}
protected:
	CacheBlend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:CacheBase(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CACHEBLEND_H__
