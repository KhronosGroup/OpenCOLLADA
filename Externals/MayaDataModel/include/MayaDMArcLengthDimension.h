/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ARCLENGTHDIMENSION_H__
#define __MayaDM_ARCLENGTHDIMENSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNurbsDimShape.h"
namespace MayaDM
{
/*
This node is basically used to measure and visually display arcLengths on
        curves and surfaces at the specified point. <p/>

        When dealing with curves, it measures the distance of the specified point
        from the start point of the curve. On the other hand, when dealing with
        surfaces, it measures the distance of the specified point from the start
        point in both the u and v directions. <p/>

        These nodes are created either using the "arcLengthDimension" command
        or by using the "arc Length" tool. After creation, by using the "move"
        tool, the shape can be moved around on the curve/surface, and the
        arcLength values update interactively based on the new position of the
        object. <p/>
*/
class ArcLengthDimension : public NurbsDimShape
{
public:
public:
	ArcLengthDimension(FILE* file,const std::string& name,const std::string& parent=""):NurbsDimShape(file, name, parent, "arcLengthDimension"){}
	virtual ~ArcLengthDimension(){}
	/*Output arcLength value of the curve/surface along u.*/
	void setArcLength(const DoubleID& al){fprintf_s(mFile,"connectAttr \"");al.write(mFile);fprintf_s(mFile,"\" \"%s.al\";\n",mName.c_str());}
	/*Output arcLength value of the curve/surface along v.*/
	void setArcLengthInV(const DoubleID& alv){fprintf_s(mFile,"connectAttr \"");alv.write(mFile);fprintf_s(mFile,"\" \"%s.alv\";\n",mName.c_str());}
	/*Output arcLength value of the curve/surface along u.*/
	DoubleID getArcLength(){char buffer[4096];sprintf_s (buffer, "%s.al",mName.c_str());return (const char*)buffer;}
	/*Output arcLength value of the curve/surface along v.*/
	DoubleID getArcLengthInV(){char buffer[4096];sprintf_s (buffer, "%s.alv",mName.c_str());return (const char*)buffer;}
protected:
	ArcLengthDimension(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):NurbsDimShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ARCLENGTHDIMENSION_H__
