/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RESULTCURVE_H__
#define __MayaDM_RESULTCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAnimCurve.h"
namespace MayaDM
{
/*
This is the base node for nodes that are temporarily created by the graph
        editor when the graphEditor is switched to "showResults" mode. A node is
        created for every selected channel.<p/>

        The graphEditor is typically switched to showResults mode when the user
        would like to get a visual display of the animation curve that would be
        driving a channel if it were driven by an animation curve. This option
        is normally used when the channel is being driven by a timeWarp or an
        expression or something on those lines.<p/>

        When a switch is made to "showResults" mode, the time range between which
        the channel needs to be evaluated is dictated by the display boundaries
        of the graphEditor. The sampling frequency at which the evaluation is
        performed defaults to 1.0 time unit (in current units). We do not have
        UI support to modify this value, but, it can be specified (modified)
        by using the "animCurveEditor" command.<p/>

        Result animation curves are only created for situations where time is the
        driving input. There are four types of such curves which are based on the
        type of output attribute of the node. The types supported include:<p/>
        <ul>
         <li> resultCurveTimeToLinear - output type - Distance</li>
         <li> resultCurveTimeToAngular - output type - Angle</li>
         <li> resultCurveTimeToTime - output type - Time</li>
         <li> resultCurveTimeToUnitless - output type - Unitless</li>
  </ul>
        When these nodes are introduced, the graph is wired up in a slightly
        different manner. There is a connection going from the attribute whose
        result is being displayed by this node to the "aInputResult" attribute
        which is defined in the derived classes.
*/
class ResultCurve : public AnimCurve
{
public:
public:
	ResultCurve(FILE* file,const std::string& name,const std::string& parent=""):AnimCurve(file, name, parent, "resultCurve"){}
	virtual ~ResultCurve(){}
	/*Time at which to start the evaluation of the result curve.*/
	void setStart(const TimeID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*Time to perform the evaluation until.*/
	void setEnd(const TimeID& et){fprintf_s(mFile,"connectAttr \"");et.write(mFile);fprintf_s(mFile,"\" \"%s.et\";\n",mName.c_str());}
	/*Specifies the frequency at which the evaluation is to be performed.*/
	void setSampleBy(const TimeID& sby){fprintf_s(mFile,"connectAttr \"");sby.write(mFile);fprintf_s(mFile,"\" \"%s.sby\";\n",mName.c_str());}
	/*Time at which to start the evaluation of the result curve.*/
	TimeID getStart(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*Time to perform the evaluation until.*/
	TimeID getEnd(){char buffer[4096];sprintf_s (buffer, "%s.et",mName.c_str());return (const char*)buffer;}
	/*Specifies the frequency at which the evaluation is to be performed.*/
	TimeID getSampleBy(){char buffer[4096];sprintf_s (buffer, "%s.sby",mName.c_str());return (const char*)buffer;}
protected:
	ResultCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AnimCurve(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RESULTCURVE_H__
