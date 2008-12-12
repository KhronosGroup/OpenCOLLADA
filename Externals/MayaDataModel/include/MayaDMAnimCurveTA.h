/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
This node is an "animCurve" that takes an attribute of type
        "time" as input and has an output attribute of type "angle".
        If the input attribute is not connected, it has an implicit
        connection to the Dependency Graph time node.<p/>

        For more information, see the documentation for the "animCurve" node.<p/>
*/
class AnimCurveTA : public AnimCurve
{
public:
	/*Keyframe time/value pairs*/
	struct KeyTimeValue{
		double keyValue;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f", keyValue);
		}
	};
public:
	AnimCurveTA(FILE* file,const std::string& name,const std::string& parent=""):AnimCurve(file, name, parent, "animCurveTA"){}
	virtual ~AnimCurveTA(){}
	/*Time at which to evaluate the animation curve*/
	void setInput(const TimeID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Evaluated Euler-angle value of the animation curve at the input time.*/
	void setOutput(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*
	Evaluated homogeneous quaternion ordinate of the animation curve
	keyframe at the input time.
	*/
	void setQuaternionW(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*
	Always returns the evaluated curve value in its underlying format,
	thus Euler curves will return Euler values (in radians), quaternion
	curves will be return quaternion values, etc.
	*/
	void setRawValue(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Keyframe time/value pairs*/
	void setKeyTimeValue(size_t ktv_i,const KeyTimeValue& ktv){fprintf_s(mFile, "setAttr \".ktv[%i]\" ",ktv_i);ktv.write(mFile);fprintf_s(mFile,";\n");}
	/*Keyframe values*/
	void setKeyValue(size_t ktv_i,double kv){if(kv == 0) return; fprintf_s(mFile, "setAttr \".ktv[%i].kv\" %f;\n", ktv_i,kv);}
	/*Time at which to evaluate the animation curve*/
	TimeID getInput(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Evaluated Euler-angle value of the animation curve at the input time.*/
	DoubleID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*
	Evaluated homogeneous quaternion ordinate of the animation curve
	keyframe at the input time.
	*/
	DoubleID getQuaternionW(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*
	Always returns the evaluated curve value in its underlying format,
	thus Euler curves will return Euler values (in radians), quaternion
	curves will be return quaternion values, etc.
	*/
	DoubleID getRawValue(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
protected:
	AnimCurveTA(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AnimCurve(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ANIMCURVETA_H__
