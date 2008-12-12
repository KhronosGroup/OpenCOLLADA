/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SKETCHPLANE_H__
#define __MayaDM_SKETCHPLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPlane.h"
namespace MayaDM
{
/*
This node defines an infinite plane perpendicular to the Z axis,
        passing through the origin, (i.e the X-Y plane).  It is a
        non-renderable object which appears as a 2cm x 2cm square centered
        about the origin.<p/>

        Sketch planes can be used as a "live" construction surface (using the
        makeLive command or interactively). When live, the sketch plane
        replaces the ground plane as the "surface" on which points are
        placed when using one of the curve creation tools or on which
        objects are moved relative to. By transforming the sketch plane,
        planar curves can be created in arbitrary planes or objects can
        be moved in an arbitrary plane.<p/>

  A live sketch plane is drawn with an internal grid. The
  planeDivisionSpacing determines the size of the grid squares. These
  grid squares are further subdivided based on the number of
  planeDivisions. <p/>
*/
class SketchPlane : public Plane
{
public:
public:
	SketchPlane(FILE* file,const std::string& name,const std::string& parent=""):Plane(file, name, parent, "sketchPlane"){}
	virtual ~SketchPlane(){}
protected:
	SketchPlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Plane(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SKETCHPLANE_H__
