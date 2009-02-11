/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMCURVEUA_H__
#define __MayaDM_ANIMCURVEUA_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAnimCurve.h"
namespace MayaDM
{
class AnimCurveUA : public AnimCurve
{
public:
	struct KeyTimeValue{
		double keyTime;
		double keyValue;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", keyTime);
			fprintf(file,"%f", keyValue);
		}
	};
public:
	AnimCurveUA():AnimCurve(){}
	AnimCurveUA(FILE* file,const std::string& name,const std::string& parent=""):AnimCurve(file, name, parent, "animCurveUA"){}
	virtual ~AnimCurveUA(){}
	void setKeyTimeValue(size_t ktv_i,const KeyTimeValue& ktv)
	{
		fprintf(mFile,"\tsetAttr \".ktv[%i]\" ",ktv_i);
		ktv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setKeyTime(size_t ktv_i,double kt)
	{
		if(kt == 0) return;
		fprintf(mFile,"\tsetAttr \".ktv[%i].kt\" %f;\n", ktv_i,kt);

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
protected:
	AnimCurveUA(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AnimCurve(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCURVEUA_H__
