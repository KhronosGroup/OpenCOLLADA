/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTERSIMPLIFY_H__
#define __MayaDM_FILTERSIMPLIFY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFilter.h"
namespace MayaDM
{
/*
This node implements a curve simplification filter, combining nearly
 colinear sets of input points into line segments,
 and is used by the applyTake command to process recorded
 motion capture data.
 The attributes of the node are settings which affect the
 operation of the filter as it is invoked by applyTake.  These settings
 are preserved when the scene file is saved.

 <p/>Curve simplification is achieved by copying to the
 filter output only those data value records which are the the endpoints
 of ranges of nearly colinear values within the input data.
 The colinearity test requires
 that all deleted data points lie within a
 parallelegram connecting the
 end-points with width 2 * tolerance * (max - min),
 where max and min are the extrema of the input data.

        <p/>Points within these parrallelograms are considered colinear
                and not copied to the output data values subject
                to the following additional constraints.
        <ul>
                <li>Data records with time stamps
                        closer than timeTolerance to the last output value time stamp
                        are considered duplicate and skipped.</li>

                <li>Ranges of input values combined into linear segements can be
                        no shorter that minTimeStep and no longer that maxTimeStep
                        in duration.</li>

                <li>If subsequent data records contain identical values,
                        only the first record is treated as valid data,
                        unless allowDuplicates is set.</li>
        </ul>

        <h3>Notes</h3>
  Since the base class inputs (comprising the input and output
  data and timestamp values) to this node are unconnectable, this node
        cannot be used in a traditional dependency graph sense.
*/
class FilterSimplify : public Filter
{
public:
public:
	FilterSimplify(FILE* file,const std::string& name,const std::string& parent=""):Filter(file, name, parent, "filterSimplify"){}
	virtual ~FilterSimplify(){}
	/*
	The fraction of dynamic range of input which defines the limits
	of nearly linear.
	*/
	void setTolerance(double tol){if(tol == 0.001) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*
	The fraction of dynamic range of input which defines the limits
	of nearly linear.
	*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*
	Temporal tolerance for timestamps, in seconds.  Data records
	closer than this value are considered duplicate and skipped.
	*/
	void setTimeTolerance(double tt){if(tt == 0.00) return; fprintf_s(mFile, "setAttr \".tt\" %f;\n", tt);}
	/*
	Temporal tolerance for timestamps, in seconds.  Data records
	closer than this value are considered duplicate and skipped.
	*/
	void setTimeTolerance(const DoubleID& tt){fprintf_s(mFile,"connectAttr \"");tt.write(mFile);fprintf_s(mFile,"\" \"%s.tt\";\n",mName.c_str());}
	/*Minimum time step in seconds between output records.*/
	void setMinTimeStep(double mnt){if(mnt == 0.0) return; fprintf_s(mFile, "setAttr \".mnt\" %f;\n", mnt);}
	/*Minimum time step in seconds between output records.*/
	void setMinTimeStep(const DoubleID& mnt){fprintf_s(mFile,"connectAttr \"");mnt.write(mFile);fprintf_s(mFile,"\" \"%s.mnt\";\n",mName.c_str());}
	/*Max time step in seconds between output records.*/
	void setMaxTimeStep(double mxt){if(mxt == 3600) return; fprintf_s(mFile, "setAttr \".mxt\" %f;\n", mxt);}
	/*Max time step in seconds between output records.*/
	void setMaxTimeStep(const DoubleID& mxt){fprintf_s(mFile,"connectAttr \"");mxt.write(mFile);fprintf_s(mFile,"\" \"%s.mxt\";\n",mName.c_str());}
	/*
	If true, treat ranges of duplicate values as valid data, else ignore
	duplicate values as a device oversampling artifact.
	*/
	void setAllowDuplicates(bool ad){if(ad == true) return; fprintf_s(mFile, "setAttr \".ad\" %i;\n", ad);}
	/*
	If true, treat ranges of duplicate values as valid data, else ignore
	duplicate values as a device oversampling artifact.
	*/
	void setAllowDuplicates(const BoolID& ad){fprintf_s(mFile,"connectAttr \"");ad.write(mFile);fprintf_s(mFile,"\" \"%s.ad\";\n",mName.c_str());}
	/*
	The fraction of dynamic range of input which defines the limits
	of nearly linear.
	*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*
	Temporal tolerance for timestamps, in seconds.  Data records
	closer than this value are considered duplicate and skipped.
	*/
	DoubleID getTimeTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tt",mName.c_str());return (const char*)buffer;}
	/*Minimum time step in seconds between output records.*/
	DoubleID getMinTimeStep(){char buffer[4096];sprintf_s (buffer, "%s.mnt",mName.c_str());return (const char*)buffer;}
	/*Max time step in seconds between output records.*/
	DoubleID getMaxTimeStep(){char buffer[4096];sprintf_s (buffer, "%s.mxt",mName.c_str());return (const char*)buffer;}
	/*
	If true, treat ranges of duplicate values as valid data, else ignore
	duplicate values as a device oversampling artifact.
	*/
	BoolID getAllowDuplicates(){char buffer[4096];sprintf_s (buffer, "%s.ad",mName.c_str());return (const char*)buffer;}
protected:
	FilterSimplify(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Filter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FILTERSIMPLIFY_H__
