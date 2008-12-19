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
class SketchPlane : public Plane
{
public:
	SketchPlane(FILE* file,const std::string& name,const std::string& parent=""):Plane(file, name, parent, "sketchPlane"){}
	virtual ~SketchPlane(){}
protected:
	SketchPlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Plane(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SKETCHPLANE_H__
