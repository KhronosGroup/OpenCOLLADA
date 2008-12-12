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
/*
This node is an "animCurve" that takes an attribute of type
        "double" as input and has an output attribute of type "time".<p/>

        For more information, see the documentation for the "animCurve" node.<p/>
*/
class AnimCurveUT : public AnimCurve
{
public:
	/*Keyframe time/value pairs*/
	struct KeyTimeValue{
		double keyTime;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", keyTime);
		}
	};
public:
	AnimCurveUT(FILE* file,const std::string& name,const std::string& parent=""):AnimCurve(file, name, parent, "animCurveUT"){}
	virtual ~AnimCurveUT(){}
	/*Value at which to evaluate the animation curve*/
	void setInput(const DoubleID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Evaluated time value of the animation curve at the input value*/
	void setOutput(const TimeID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Keyframe time/value pairs*/
	void setKeyTimeValue(size_t ktv_i,const KeyTimeValue& ktv){fprintf_s(mFile, "setAttr \".ktv[%i]\" ",ktv_i);ktv.write(mFile);fprintf_s(mFile,";\n");}
	/*Keyframe times*/
	void setKeyTime(size_t ktv_i,double kt){if(kt == 0) return; fprintf_s(mFile, "setAttr \".ktv[%i].kt\" %f;\n", ktv_i,kt);}
	/*Value at which to evaluate the animation curve*/
	DoubleID getInput(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Evaluated time value of the animation curve at the input value*/
	TimeID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	AnimCurveUT(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AnimCurve(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCURVEUT_H__
