/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Jiggle(FILE* file,const std::string& name,const std::string& parent=""):WeightGeometryFilter(file, name, parent, "jiggle"){}
	virtual ~Jiggle(){}
	void setEnable(unsigned int ebl)
	{
		if(ebl == 2) return;
		fprintf(mFile,"setAttr \".ebl\" %i;\n", ebl);

	}
	void setIgnoreTransform(bool it)
	{
		if(it == false) return;
		fprintf(mFile,"setAttr \".it\" %i;\n", it);

	}
	void setForceAlongNormal(double fan)
	{
		if(fan == 1.0) return;
		fprintf(mFile,"setAttr \".fan\" %f;\n", fan);

	}
	void setForceOnTangent(double fot)
	{
		if(fot == 1.0) return;
		fprintf(mFile,"setAttr \".fot\" %f;\n", fot);

	}
	void setMotionMultiplier(double mm)
	{
		if(mm == 1.0) return;
		fprintf(mFile,"setAttr \".mm\" %f;\n", mm);

	}
	void setStiffness(double sf)
	{
		if(sf == 0.5) return;
		fprintf(mFile,"setAttr \".sf\" %f;\n", sf);

	}
	void setDamping(double dp)
	{
		if(dp == 0.5) return;
		fprintf(mFile,"setAttr \".dp\" %f;\n", dp);

	}
	void setJiggleWeight(double jw)
	{
		if(jw == 1.0) return;
		fprintf(mFile,"setAttr \".jw\" %f;\n", jw);

	}
	void setDirectionBias(double bias)
	{
		if(bias == 0.0) return;
		fprintf(mFile,"setAttr \".bias\" %f;\n", bias);

	}
	void getDiskCache()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getCurrentTime()
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());

	}
	void getEnable()
	{
		fprintf(mFile,"\"%s.ebl\"",mName.c_str());

	}
	void getIgnoreTransform()
	{
		fprintf(mFile,"\"%s.it\"",mName.c_str());

	}
	void getForceAlongNormal()
	{
		fprintf(mFile,"\"%s.fan\"",mName.c_str());

	}
	void getForceOnTangent()
	{
		fprintf(mFile,"\"%s.fot\"",mName.c_str());

	}
	void getMotionMultiplier()
	{
		fprintf(mFile,"\"%s.mm\"",mName.c_str());

	}
	void getStiffness()
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());

	}
	void getDamping()
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());

	}
	void getJiggleWeight()
	{
		fprintf(mFile,"\"%s.jw\"",mName.c_str());

	}
	void getDirectionBias()
	{
		fprintf(mFile,"\"%s.bias\"",mName.c_str());

	}
protected:
	Jiggle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):WeightGeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_JIGGLE_H__
