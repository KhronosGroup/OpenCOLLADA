/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RESULTCURVETIMETOANGULAR_H__
#define __MayaDM_RESULTCURVETIMETOANGULAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMResultCurve.h"
namespace MayaDM
{
/*
This node is the result animation curve created for situations wherein
        the attribute expects "angular" data and is driven by "time".<p/>

        For more information, see the documentation of the Parent "resultCurve"
        node.<p/>
*/
class ResultCurveTimeToAngular : public ResultCurve
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
	ResultCurveTimeToAngular(FILE* file,const std::string& name,const std::string& parent=""):ResultCurve(file, name, parent, "resultCurveTimeToAngular"){}
	virtual ~ResultCurveTimeToAngular(){}
	/*Time at which the result animation curve is to be evaluated*/
	void setInput(const TimeID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Evaluated angle value ofthe result animation curve at the input time*/
	void setOutput(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Keyframe time/value pairs*/
	void setKeyTimeValue(size_t ktv_i,const KeyTimeValue& ktv){fprintf_s(mFile, "setAttr \".ktv[%i]\" ",ktv_i);ktv.write(mFile);fprintf_s(mFile,";\n");}
	/*Keyframe values*/
	void setKeyValue(size_t ktv_i,double kv){if(kv == 0) return; fprintf_s(mFile, "setAttr \".ktv[%i].kv\" %f;\n", ktv_i,kv);}
	/*
	Attribute that receives the result values from the channel that this
	node is displaying the result animation curve for.
	*/
	void setInputResult(const DoubleID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.ir\";\n",mName.c_str());}
	/*Time at which the result animation curve is to be evaluated*/
	TimeID getInput(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Evaluated angle value ofthe result animation curve at the input time*/
	DoubleID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*
	Attribute that receives the result values from the channel that this
	node is displaying the result animation curve for.
	*/
	DoubleID getInputResult(){char buffer[4096];sprintf_s (buffer, "%s.ir",mName.c_str());return (const char*)buffer;}
protected:
	ResultCurveTimeToAngular(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ResultCurve(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RESULTCURVETIMETOANGULAR_H__
