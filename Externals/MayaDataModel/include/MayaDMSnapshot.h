/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SNAPSHOT_H__
#define __MayaDM_SNAPSHOT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
    This node is used to evaluate an input geometry or matrix at
  a range of times defined by the "startTime", "endTime" and "increment"
  attribute values. When a geometry is attached as the input, the
  output is a sequence of time-evaluated geometries, which is
  referred to in maya as an "animated snapshot". When a
  matrix is attached as the input, the output is a an array of points
  that indicate the motion trail of the input matrix data.

</pre></p>
*/
class Snapshot : public DependNode
{
public:
public:
	Snapshot(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "snapshot"){}
	virtual ~Snapshot(){}
	/*The first time at which to evaluate the input geometry*/
	void setStartTime(const TimeID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*The last time at which to evaluate the input geometry*/
	void setEndTime(const TimeID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e\";\n",mName.c_str());}
	/*How much time exists between copies of the geometry*/
	void setIncrement(const TimeID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*The input geometry*/
	void setInputGeom(const GeometryID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in\";\n",mName.c_str());}
	/*The output geometry*/
	void setOutputGeom(size_t out_i,const GeometryID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out[%i]\";\n",mName.c_str(),out_i);}
	/*The input matrix.*/
	void setInputMatrix(const matrix& im){if(im == identity) return; fprintf_s(mFile, "setAttr \".im\" -type \"matrix\" ");im.write(mFile);fprintf_s(mFile,";\n");}
	/*The input matrix.*/
	void setInputMatrix(const MatrixID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im\";\n",mName.c_str());}
	/*Offset position for the shape in local space coordinates.*/
	void setLocalPosition(const double3& lp){if(lp == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".lp\" -type \"double3\" ");lp.write(mFile);fprintf_s(mFile,";\n");}
	/*Offset position for the shape in local space coordinates.*/
	void setLocalPosition(const Double3ID& lp){fprintf_s(mFile,"connectAttr \"");lp.write(mFile);fprintf_s(mFile,"\" \"%s.lp\";\n",mName.c_str());}
	/*Local location in X.*/
	void setLocalPositionX(double lpx){if(lpx == 0) return; fprintf_s(mFile, "setAttr \".lp.lpx\" %f;\n", lpx);}
	/*Local location in X.*/
	void setLocalPositionX(const DoubleID& lpx){fprintf_s(mFile,"connectAttr \"");lpx.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpx\";\n",mName.c_str());}
	/*Local location in Y.*/
	void setLocalPositionY(double lpy){if(lpy == 0) return; fprintf_s(mFile, "setAttr \".lp.lpy\" %f;\n", lpy);}
	/*Local location in Y.*/
	void setLocalPositionY(const DoubleID& lpy){fprintf_s(mFile,"connectAttr \"");lpy.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpy\";\n",mName.c_str());}
	/*Local location in Z.*/
	void setLocalPositionZ(double lpz){if(lpz == 0) return; fprintf_s(mFile, "setAttr \".lp.lpz\" %f;\n", lpz);}
	/*Local location in Z.*/
	void setLocalPositionZ(const DoubleID& lpz){fprintf_s(mFile,"connectAttr \"");lpz.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpz\";\n",mName.c_str());}
	/*
	Outputs an array of points that correspond to the locations of the
	translate pivot of the snapshotted object.
	*/
	void setPoints(const PointArrayID& pts){fprintf_s(mFile,"connectAttr \"");pts.write(mFile);fprintf_s(mFile,"\" \"%s.pts\";\n",mName.c_str());}
	/*
	Stores the list of frame numbers corresponding to the points.
	The frame unit is ticks.
	*/
	void setFrames(const IntArrayID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*
	This attribute is used internally to store whether
	dirty messages received by the inputGeom attribute arrive from
	transformations versus modifications to animCurves
	that affect the snapshot calculation. This allows the
	most common case of snapshot usage (that of snapshotting an
	animated object) to work more efficiently.
	*/
	void setAnimCurveChanged(const MessageID& acc){fprintf_s(mFile,"connectAttr \"");acc.write(mFile);fprintf_s(mFile,"\" \"%s.acc\";\n",mName.c_str());}
	/*
	Controls whether the snapshot updates on demand, or updates
	whenever the inputGeom attribute is marked dirty, or only
	update when an input animCurve is modified, versus every time
	the input shape attribute is modified.
	*/
	void setUpdate(unsigned int up){if(up == 1) return; fprintf_s(mFile, "setAttr \".up\" %i;\n", up);}
	/*
	Controls whether the snapshot updates on demand, or updates
	whenever the inputGeom attribute is marked dirty, or only
	update when an input animCurve is modified, versus every time
	the input shape attribute is modified.
	*/
	void setUpdate(const UnsignedintID& up){fprintf_s(mFile,"connectAttr \"");up.write(mFile);fprintf_s(mFile,"\" \"%s.up\";\n",mName.c_str());}
	/*The first time at which to evaluate the input geometry*/
	TimeID getStartTime(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*The last time at which to evaluate the input geometry*/
	TimeID getEndTime(){char buffer[4096];sprintf_s (buffer, "%s.e",mName.c_str());return (const char*)buffer;}
	/*How much time exists between copies of the geometry*/
	TimeID getIncrement(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*The input geometry*/
	GeometryID getInputGeom(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*The output geometry*/
	const GeometryID& getOutputGeom(size_t out_i){char buffer[4096];sprintf_s (buffer, "%s.out[%i]",mName.c_str(),out_i);return (const char*)buffer;}
	/*The input matrix.*/
	MatrixID getInputMatrix(){char buffer[4096];sprintf_s (buffer, "%s.im",mName.c_str());return (const char*)buffer;}
	/*Offset position for the shape in local space coordinates.*/
	Double3ID getLocalPosition(){char buffer[4096];sprintf_s (buffer, "%s.lp",mName.c_str());return (const char*)buffer;}
	/*Local location in X.*/
	DoubleID getLocalPositionX(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpx",mName.c_str());return (const char*)buffer;}
	/*Local location in Y.*/
	DoubleID getLocalPositionY(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpy",mName.c_str());return (const char*)buffer;}
	/*Local location in Z.*/
	DoubleID getLocalPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpz",mName.c_str());return (const char*)buffer;}
	/*
	Outputs an array of points that correspond to the locations of the
	translate pivot of the snapshotted object.
	*/
	PointArrayID getPoints(){char buffer[4096];sprintf_s (buffer, "%s.pts",mName.c_str());return (const char*)buffer;}
	/*
	Stores the list of frame numbers corresponding to the points.
	The frame unit is ticks.
	*/
	IntArrayID getFrames(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is used internally to store whether
	dirty messages received by the inputGeom attribute arrive from
	transformations versus modifications to animCurves
	that affect the snapshot calculation. This allows the
	most common case of snapshot usage (that of snapshotting an
	animated object) to work more efficiently.
	*/
	MessageID getAnimCurveChanged(){char buffer[4096];sprintf_s (buffer, "%s.acc",mName.c_str());return (const char*)buffer;}
	/*
	Controls whether the snapshot updates on demand, or updates
	whenever the inputGeom attribute is marked dirty, or only
	update when an input animCurve is modified, versus every time
	the input shape attribute is modified.
	*/
	UnsignedintID getUpdate(){char buffer[4096];sprintf_s (buffer, "%s.up",mName.c_str());return (const char*)buffer;}
protected:
	Snapshot(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SNAPSHOT_H__
