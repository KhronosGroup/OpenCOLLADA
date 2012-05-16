/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_JIGGLE_H__
#define __MayaDM_JIGGLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
class Jiggle : public WeightGeometryFilter
{
public:
	struct CachedDataList{
		struct CachedData{
			void write(FILE* file) const
			{
			}
		} cachedData;
		void write(FILE* file) const
		{
		}
	};
public:

	Jiggle():WeightGeometryFilter(){}
	Jiggle(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:WeightGeometryFilter(file, name, parent, "jiggle", shared, create){}
	virtual ~Jiggle(){}

	void setEnable(unsigned int ebl)
	{
		if(ebl == 2) return;
		fprintf(mFile,"\tsetAttr \".ebl\" %i;\n", ebl);
	}
	void setIgnoreTransform(bool it)
	{
		if(it == false) return;
		fprintf(mFile,"\tsetAttr \".it\" %i;\n", it);
	}
	void setForceAlongNormal(double fan)
	{
		if(fan == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fan\" %f;\n", fan);
	}
	void setForceOnTangent(double fot)
	{
		if(fot == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fot\" %f;\n", fot);
	}
	void setMotionMultiplier(double mm)
	{
		if(mm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mm\" %f;\n", mm);
	}
	void setStiffness(double sf)
	{
		if(sf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sf\" %f;\n", sf);
	}
	void setDamping(double dp)
	{
		if(dp == 0.5) return;
		fprintf(mFile,"\tsetAttr \".dp\" %f;\n", dp);
	}
	void setJiggleWeight(double jw)
	{
		if(jw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".jw\" %f;\n", jw);
	}
	void setDirectionBias(double bias)
	{
		if(bias == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bias\" %f;\n", bias);
	}
	void getDiskCache()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getCurrentTime()const
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());
	}
	void getEnable()const
	{
		fprintf(mFile,"\"%s.ebl\"",mName.c_str());
	}
	void getIgnoreTransform()const
	{
		fprintf(mFile,"\"%s.it\"",mName.c_str());
	}
	void getForceAlongNormal()const
	{
		fprintf(mFile,"\"%s.fan\"",mName.c_str());
	}
	void getForceOnTangent()const
	{
		fprintf(mFile,"\"%s.fot\"",mName.c_str());
	}
	void getMotionMultiplier()const
	{
		fprintf(mFile,"\"%s.mm\"",mName.c_str());
	}
	void getStiffness()const
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());
	}
	void getDamping()const
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());
	}
	void getJiggleWeight()const
	{
		fprintf(mFile,"\"%s.jw\"",mName.c_str());
	}
	void getDirectionBias()const
	{
		fprintf(mFile,"\"%s.bias\"",mName.c_str());
	}
protected:
	Jiggle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:WeightGeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_JIGGLE_H__
