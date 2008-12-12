/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTERRESAMPLE_H__
#define __MayaDM_FILTERRESAMPLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFilter.h"
namespace MayaDM
{
/*
This node implements a decimation resampling filter used by the
 applyTake command to process recorded motion capture data.  The
 attributes of the node are settings which affect the operation of
 the filter as it is invoked by applyTake. These settings are
 preserved when the scene file is saved.

 <p/>The resample filter converts from either uniform or non-uniform
 timestep input data samples to the specified uniform timeStep.
 Various time domain filters are available and are specified with
 the kernel attribute which selects the resampling kernel applied to
 the incoming data.

        <table border="1">
                <caption><strong>Kernel Values</strong></caption>
                <tr><td>100</td>
                        <td> Pass through: disables resampling</td></tr>
                <tr><td>200</td>
                        <td> Closest sample to output timestamp</td></tr>
                <tr><td>300</td>
                        <td> Linear interpolation between closest samples</td></tr>
                <tr><td>400</td>
                        <td> Box filter: moving average</td></tr>
                <tr><td>500</td>
                        <td> Tent filter: (1 - |x|)  weighted moving average</td></tr>
                <tr><td>600</td>
                        <td> Gaussian2 Filter: (2^(-2x*x)) weighted moving average </td></tr>
                <tr><td>700</td>
                        <td> Gaussian4 Filter: (2^(-4x*x)) weighted moving average </td></tr>
        </table>

        <h3>Notes</h3>
        This filter is <strong>only</strong> targeted at decimation resampling
        -- interpolation resampling is basically unsupported.  If your
        output framerate is much higher than your input frame rate
        (approximate, as the input timestep is not assumed to be regular)
        the lirp and tent will interpolate (usually) and the rest will
        either average, or use the closest sample (depending on the
        phase and frequency of the input).  However this mode of operation
        is neither supported nor encouraged.

  <p/>Since the base class inputs (comprising the input and output
  data and timestamp values) to this node are unconnectable, this node
        cannot be used in a traditional dependency graph sense.
*/
class FilterResample : public Filter
{
public:
public:
	FilterResample(FILE* file,const std::string& name,const std::string& parent=""):Filter(file, name, parent, "filterResample"){}
	virtual ~FilterResample(){}
	/*
	Sets the output period in the current time unit.
	If zero, the period is 1.0 in the current time unit. Note, if
	the current time units are seconds, or millisecond, this default
	is likely not to be useful or desirable.
	*/
	void setTimeStep(const TimeID& ts){fprintf_s(mFile,"connectAttr \"");ts.write(mFile);fprintf_s(mFile,"\" \"%s.ts\";\n",mName.c_str());}
	/*Kernel to use for the resampling. See table above for enumeration*/
	void setKernel(unsigned int kr){if(kr == 600) return; fprintf_s(mFile, "setAttr \".kr\" %i;\n", kr);}
	/*Kernel to use for the resampling. See table above for enumeration*/
	void setKernel(const UnsignedintID& kr){fprintf_s(mFile,"connectAttr \"");kr.write(mFile);fprintf_s(mFile,"\" \"%s.kr\";\n",mName.c_str());}
	/*
	Sets the output period in the current time unit.
	If zero, the period is 1.0 in the current time unit. Note, if
	the current time units are seconds, or millisecond, this default
	is likely not to be useful or desirable.
	*/
	TimeID getTimeStep(){char buffer[4096];sprintf_s (buffer, "%s.ts",mName.c_str());return (const char*)buffer;}
	/*Kernel to use for the resampling. See table above for enumeration*/
	UnsignedintID getKernel(){char buffer[4096];sprintf_s (buffer, "%s.kr",mName.c_str());return (const char*)buffer;}
protected:
	FilterResample(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Filter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FILTERRESAMPLE_H__
