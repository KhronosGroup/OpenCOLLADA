/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SNAPSHOTSHAPE_H__
#define __MayaDM_SNAPSHOTSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
/*
A snapshot is a piecewise linear curve drawn a series of points.
 The snapshot is not deformable or renderable, but can be used
 to display the trajectory of a node in time.
*/
class SnapshotShape : public GeometryShape
{
public:
public:
	SnapshotShape(FILE* file,const std::string& name,const std::string& parent=""):GeometryShape(file, name, parent, "snapshotShape"){}
	virtual ~SnapshotShape(){}
	/*Stores the list of points that will be drawn by the shape*/
	void setPoints(const pointArray& pts){if(pts.size == 0) return; fprintf_s(mFile, "setAttr \".pts\" -type \"pointArray\" ");pts.write(mFile);fprintf_s(mFile,";\n");}
	/*Stores the list of points that will be drawn by the shape*/
	void setPoints(const PointArrayID& pts){fprintf_s(mFile,"connectAttr \"");pts.write(mFile);fprintf_s(mFile,"\" \"%s.pts\";\n",mName.c_str());}
	/*Stores the list of frame numbers corresponding to the points*/
	void setFrames(const intArray& f){if(f.size == 0) return; fprintf_s(mFile, "setAttr \".f\" -type \"intArray\" ");f.write(mFile);fprintf_s(mFile,";\n");}
	/*Stores the list of frame numbers corresponding to the points*/
	void setFrames(const IntArrayID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*
	whether the snapshot positions are drawn as locators, points or
	connected line segments
	*/
	void setDrawStyle(unsigned int d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	whether the snapshot positions are drawn as locators, points or
	connected line segments
	*/
	void setDrawStyle(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*whether the snapshot positions are drawn with frame numbers*/
	void setShowFrames(bool sf){if(sf == 0) return; fprintf_s(mFile, "setAttr \".sf\" %i;\n", sf);}
	/*whether the snapshot positions are drawn with frame numbers*/
	void setShowFrames(const BoolID& sf){fprintf_s(mFile,"connectAttr \"");sf.write(mFile);fprintf_s(mFile,"\" \"%s.sf\";\n",mName.c_str());}
	/*Stores the list of points that will be drawn by the shape*/
	PointArrayID getPoints(){char buffer[4096];sprintf_s (buffer, "%s.pts",mName.c_str());return (const char*)buffer;}
	/*Stores the list of frame numbers corresponding to the points*/
	IntArrayID getFrames(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*
	whether the snapshot positions are drawn as locators, points or
	connected line segments
	*/
	UnsignedintID getDrawStyle(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*whether the snapshot positions are drawn with frame numbers*/
	BoolID getShowFrames(){char buffer[4096];sprintf_s (buffer, "%s.sf",mName.c_str());return (const char*)buffer;}
protected:
	SnapshotShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SNAPSHOTSHAPE_H__
