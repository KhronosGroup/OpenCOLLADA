/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMCURVEUT_H__
#define __MayaDM_ANIMCURVEUT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAnimCurve.h"
namespace MayaDM
{
class AnimCurveUT : public AnimCurve
{
public:
	struct KeyTimeValue{
		double keyTime;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", keyTime);
		}
	};
public:
	AnimCurveUT(FILE* file,const std::string& name,const std::string& parent=""):AnimCurve(file, name, parent, "animCurveUT"){}
	virtual ~AnimCurveUT(){}
	void setKeyTimeValue(size_t ktv_i,const KeyTimeValue& ktv)
	{
		fprintf(mFile,"setAttr \".ktv[%i]\" ",ktv_i);
		ktv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setKeyTime(size_t ktv_i,double kt)
	{
		if(kt == 0) return;
		fprintf(mFile,"setAttr \".ktv[%i].kt\" %f;\n", ktv_i,kt);

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
	AnimCurveUT(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AnimCurve(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCURVEUT_H__
