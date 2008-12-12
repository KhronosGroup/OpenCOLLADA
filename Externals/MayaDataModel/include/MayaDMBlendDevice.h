/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDDEVICE_H__
#define __MayaDM_BLENDDEVICE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBlend.h"
namespace MayaDM
{
/*
This node provides reliable motion capture device data monitoring
 and fast animation preview functionality for motion capture
 (unclutched) input devices. Its designed role is to service the
 device attribute attachments, (see attachDeviceAttr command),
 device data monitoring control (see enableDevice command), and
 "take" evaluation (see applyTake -preview).

 <p/>This node blends the three possible value sources for a device
 attached attribute:

 <ul>
                <li> Current device data from the device attachment</li>
                <li> applyTake -preview data</li>
                <li> Other keyframe or input data from input[0]</li>
 </ul>

 <p/> The formulaic version of this node:

 <pre>
    pcPrev = blender * input[0] + (1-blender)*previewData(time)
    output = deviceBlend * deviceValue + (1-deviceBlend) * pcPrev
 </pre>

 <p/> where previewData(time) represents the lookup in data of the current
 preview value based on time, data, timeStamp, et. al.  The previewData
 value is a linear interpolation at the current time.

 <p/>In order to support correct unit conversion the input and ouput
 connections have angular, linear, and unitless versions.  Evaluation
 of an output draws input values only from the input attribute
 of the matching type.
 The effect on the node's behavior can be seen by substituting inputLinear
 and outputLinear or inputAngle and outputAngle in the equations above
 for input and output, respectively.


 <h3>Notes:</h3>
 <p/> While each of the inputs is a multi attribute, only the 0th entry
 is ever considered in evaluating the output value.

 <p/> Remember that device data is considered to be in internal unit and
 is not subject to unit conversion.  Thus if a rotational device channel
 is attached to a linear attribute, the rotations in radian will be assigned
 to the linear unit in cm.

 <p/> Preview data is <strong>not</strong> stored in a saved filed.

 <p/> While this node could possibly be used for other purposes
 than functioning as the arbiter of various device and animation
 data, it is not supported for use in any other role.
*/
class BlendDevice : public Blend
{
public:
public:
	BlendDevice(FILE* file,const std::string& name,const std::string& parent=""):Blend(file, name, parent, "blendDevice"){}
	virtual ~BlendDevice(){}
	/*
	The current time value, implicitly connected to the animation time.
	This attribute is internal, do not connect or set.
	*/
	void setTime(const TimeID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*
	The value of the current device state from
	the device attribute attachment. This attribute is internal,
	do not connect or set.
	*/
	void setDeviceValue(const DoubleID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*
	Reflects current clutch/enable state of the device. Act as the
	selector for current device data or animation/preview data.
	This attribute is internal, do not connect or set.
	*/
	void setDeviceBlender(const FloatID& db){fprintf_s(mFile,"connectAttr \"");db.write(mFile);fprintf_s(mFile,"\" \"%s.db\";\n",mName.c_str());}
	/*
	Available for connection (or connected to) the anim curve for
	the device attached attribute, if the attribute is angular.
	*/
	void setInputAngle(size_t ia_i,double ia){if(ia == 0) return; fprintf_s(mFile, "setAttr \".ia[%i]\" %f;\n", ia_i,ia);}
	/*
	Available for connection (or connected to) the anim curve for
	the device attached attribute, if the attribute is angular.
	*/
	void setInputAngle(size_t ia_i,const DoubleID& ia){fprintf_s(mFile,"connectAttr \"");ia.write(mFile);fprintf_s(mFile,"\" \"%s.ia[%i]\";\n",mName.c_str(),ia_i);}
	/*
	Blended output computed from angle inputs.  Typically connected to
	the device attached attribute.
	*/
	void setOutputAngle(const DoubleID& oa){fprintf_s(mFile,"connectAttr \"");oa.write(mFile);fprintf_s(mFile,"\" \"%s.oa\";\n",mName.c_str());}
	/*
	Available for connection (or connected to) the anim curve for
	the device attached attribute, if the attribute is linear
	*/
	void setInputLinear(size_t il_i,double il){if(il == 0) return; fprintf_s(mFile, "setAttr \".il[%i]\" %f;\n", il_i,il);}
	/*
	Available for connection (or connected to) the anim curve for
	the device attached attribute, if the attribute is linear
	*/
	void setInputLinear(size_t il_i,const DoubleID& il){fprintf_s(mFile,"connectAttr \"");il.write(mFile);fprintf_s(mFile,"\" \"%s.il[%i]\";\n",mName.c_str(),il_i);}
	/*
	Blended output computed from linear inputs.  Typically connected to
	the device attached attribute.
	*/
	void setOutputLinear(const DoubleID& ol){fprintf_s(mFile,"connectAttr \"");ol.write(mFile);fprintf_s(mFile,"\" \"%s.ol\";\n",mName.c_str());}
	/*
	Controls the source of animation data as either 0.0 (source is data)
	or 1.0 (source is input[0], inputAngle[0], or inputLinear[0]).
	*/
	void setBlender(const FloatID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*Begining of time range for preview data*/
	void setMinTime(const DoubleID& mnt){fprintf_s(mFile,"connectAttr \"");mnt.write(mFile);fprintf_s(mFile,"\" \"%s.mnt\";\n",mName.c_str());}
	/*
	If non-zero the preview data is periodic, and this attribute
	is the period of the preview data, and the timestamp attribute is
	ignored. If period is set to 0.0, the
	timestamp attribute is used to provide temporal information for the
	preview data.
	*/
	void setPeriod(const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*
	Contains the timestamp for preview data (ignored if period is > 0 )
	Timestamp values are relative to minTime, and must be > 0 and
	monotonically increasing.
	*/
	void setTimeStamp(const DoubleArrayID& ts){fprintf_s(mFile,"connectAttr \"");ts.write(mFile);fprintf_s(mFile,"\" \"%s.ts\";\n",mName.c_str());}
	/*Contain the preview data values from applyTake -preview*/
	void setData(const DoubleArrayID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	Is the record size of the preview data array.
	Combined with offset, allows data to be a 2 dimensional array
	indexed for a particular column.
	*/
	void setStride(const IntID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*
	Is the offset into a record in the preview data array for
	the device preview value for this attribute.
	Combined with stride, allows data to be a 2 dimensional array
	indexed for a particular column.
	*/
	void setOffset(const IntID& off){fprintf_s(mFile,"connectAttr \"");off.write(mFile);fprintf_s(mFile,"\" \"%s.off\";\n",mName.c_str());}
	/*
	The current time value, implicitly connected to the animation time.
	This attribute is internal, do not connect or set.
	*/
	TimeID getTime(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*
	The value of the current device state from
	the device attribute attachment. This attribute is internal,
	do not connect or set.
	*/
	DoubleID getDeviceValue(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*
	Reflects current clutch/enable state of the device. Act as the
	selector for current device data or animation/preview data.
	This attribute is internal, do not connect or set.
	*/
	FloatID getDeviceBlender(){char buffer[4096];sprintf_s (buffer, "%s.db",mName.c_str());return (const char*)buffer;}
	/*
	Available for connection (or connected to) the anim curve for
	the device attached attribute, if the attribute is angular.
	*/
	const DoubleID& getInputAngle(size_t ia_i){char buffer[4096];sprintf_s (buffer, "%s.ia[%i]",mName.c_str(),ia_i);return (const char*)buffer;}
	/*
	Blended output computed from angle inputs.  Typically connected to
	the device attached attribute.
	*/
	DoubleID getOutputAngle(){char buffer[4096];sprintf_s (buffer, "%s.oa",mName.c_str());return (const char*)buffer;}
	/*
	Available for connection (or connected to) the anim curve for
	the device attached attribute, if the attribute is linear
	*/
	const DoubleID& getInputLinear(size_t il_i){char buffer[4096];sprintf_s (buffer, "%s.il[%i]",mName.c_str(),il_i);return (const char*)buffer;}
	/*
	Blended output computed from linear inputs.  Typically connected to
	the device attached attribute.
	*/
	DoubleID getOutputLinear(){char buffer[4096];sprintf_s (buffer, "%s.ol",mName.c_str());return (const char*)buffer;}
	/*
	Controls the source of animation data as either 0.0 (source is data)
	or 1.0 (source is input[0], inputAngle[0], or inputLinear[0]).
	*/
	FloatID getBlender(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*Begining of time range for preview data*/
	DoubleID getMinTime(){char buffer[4096];sprintf_s (buffer, "%s.mnt",mName.c_str());return (const char*)buffer;}
	/*
	If non-zero the preview data is periodic, and this attribute
	is the period of the preview data, and the timestamp attribute is
	ignored. If period is set to 0.0, the
	timestamp attribute is used to provide temporal information for the
	preview data.
	*/
	DoubleID getPeriod(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*
	Contains the timestamp for preview data (ignored if period is > 0 )
	Timestamp values are relative to minTime, and must be > 0 and
	monotonically increasing.
	*/
	DoubleArrayID getTimeStamp(){char buffer[4096];sprintf_s (buffer, "%s.ts",mName.c_str());return (const char*)buffer;}
	/*Contain the preview data values from applyTake -preview*/
	DoubleArrayID getData(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	Is the record size of the preview data array.
	Combined with offset, allows data to be a 2 dimensional array
	indexed for a particular column.
	*/
	IntID getStride(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*
	Is the offset into a record in the preview data array for
	the device preview value for this attribute.
	Combined with stride, allows data to be a 2 dimensional array
	indexed for a particular column.
	*/
	IntID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.off",mName.c_str());return (const char*)buffer;}
protected:
	BlendDevice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Blend(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BLENDDEVICE_H__
