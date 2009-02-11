/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMCURVETA_H__
#define __MayaDM_ANIMCURVETA_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAnimCurve.h"
namespace MayaDM
{
class AnimCurveTA : public AnimCurve
{
public:
	struct KeyTimeValue{
		double keyValue;
		void write(FILE* file) const
		{
			fprintf(file,"%f", keyValue);
		}
	};
public:
	AnimCurveTA():AnimCurve(){}
	AnimCurveTA(FILE* file,const std::string& name,const std::string& parent=""):AnimCurve(file, name, parent, "animCurveTA"){}
	virtual ~AnimCurveTA(){}
	void setKeyTimeValue(size_t ktv_i,const KeyTimeValue& ktv)
	{
		fprintf(mFile,"\tsetAttr \".ktv[%i]\" ",ktv_i);
		ktv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setKeyValue(size_t ktv_i,double kv)
	{
		if(kv == 0) return;
		fprintf(mFile,"\tsetAttr \".ktv[%i].kv\" %f;\n", ktv_i,kv);

	}
	void getInput()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getQuaternionW()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getRawValue()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
protected:
	AnimCurveTA(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AnimCurve(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCURVETA_H__
