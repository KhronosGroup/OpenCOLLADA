/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISTANCEDIMSHAPE_H__
#define __MayaDM_DISTANCEDIMSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDimensionShape.h"
namespace MayaDM
{
/*
This node is used to measure and visually display distances between two
        specified points. <p/>

        It has two inputs in the form of the two points that the distance has
        to be measured between, and one output, namely the distance. <p/>

        The node is created by the "distanceDimension" command or when the
        "distance" tool is used. Either of the points can be moved using the
        "move" tool and the distance updates interactively. <p/>
*/
class DistanceDimShape : public DimensionShape
{
public:
public:
	DistanceDimShape(FILE* file,const std::string& name,const std::string& parent=""):DimensionShape(file, name, parent, "distanceDimShape"){}
	virtual ~DistanceDimShape(){}
	/*Point to start measuring distance from.*/
	void setStartPoint(const double3& sp){fprintf_s(mFile, "setAttr \".sp\" -type \"double3\" ");sp.write(mFile);fprintf_s(mFile,";\n");}
	/*Point to start measuring distance from.*/
	void setStartPoint(const Double3ID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*x-coord of startPoint*/
	void setStartPointX(double spx){if(spx == 0) return; fprintf_s(mFile, "setAttr \".sp.spx\" %f;\n", spx);}
	/*x-coord of startPoint*/
	void setStartPointX(const DoubleID& spx){fprintf_s(mFile,"connectAttr \"");spx.write(mFile);fprintf_s(mFile,"\" \"%s.sp.spx\";\n",mName.c_str());}
	/*y-coord of startPoint*/
	void setStartPointY(double spy){if(spy == 0) return; fprintf_s(mFile, "setAttr \".sp.spy\" %f;\n", spy);}
	/*y-coord of startPoint*/
	void setStartPointY(const DoubleID& spy){fprintf_s(mFile,"connectAttr \"");spy.write(mFile);fprintf_s(mFile,"\" \"%s.sp.spy\";\n",mName.c_str());}
	/*z-coord of startPoint*/
	void setStartPointZ(double spz){if(spz == 0) return; fprintf_s(mFile, "setAttr \".sp.spz\" %f;\n", spz);}
	/*z-coord of startPoint*/
	void setStartPointZ(const DoubleID& spz){fprintf_s(mFile,"connectAttr \"");spz.write(mFile);fprintf_s(mFile,"\" \"%s.sp.spz\";\n",mName.c_str());}
	/*Point to measure distance to.*/
	void setEndPoint(const double3& ep){fprintf_s(mFile, "setAttr \".ep\" -type \"double3\" ");ep.write(mFile);fprintf_s(mFile,";\n");}
	/*Point to measure distance to.*/
	void setEndPoint(const Double3ID& ep){fprintf_s(mFile,"connectAttr \"");ep.write(mFile);fprintf_s(mFile,"\" \"%s.ep\";\n",mName.c_str());}
	/*x-coord of endPoint*/
	void setEndPointX(double epx){if(epx == 0) return; fprintf_s(mFile, "setAttr \".ep.epx\" %f;\n", epx);}
	/*x-coord of endPoint*/
	void setEndPointX(const DoubleID& epx){fprintf_s(mFile,"connectAttr \"");epx.write(mFile);fprintf_s(mFile,"\" \"%s.ep.epx\";\n",mName.c_str());}
	/*y-coord of endPoint*/
	void setEndPointY(double epy){if(epy == 0) return; fprintf_s(mFile, "setAttr \".ep.epy\" %f;\n", epy);}
	/*y-coord of endPoint*/
	void setEndPointY(const DoubleID& epy){fprintf_s(mFile,"connectAttr \"");epy.write(mFile);fprintf_s(mFile,"\" \"%s.ep.epy\";\n",mName.c_str());}
	/*z-coord of endPoint*/
	void setEndPointZ(double epz){if(epz == 0) return; fprintf_s(mFile, "setAttr \".ep.epz\" %f;\n", epz);}
	/*z-coord of endPoint*/
	void setEndPointZ(const DoubleID& epz){fprintf_s(mFile,"connectAttr \"");epz.write(mFile);fprintf_s(mFile,"\" \"%s.ep.epz\";\n",mName.c_str());}
	/*Resultant distance value.*/
	void setDistance(const DoubleID& dist){fprintf_s(mFile,"connectAttr \"");dist.write(mFile);fprintf_s(mFile,"\" \"%s.dist\";\n",mName.c_str());}
	/*Point to start measuring distance from.*/
	Double3ID getStartPoint(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*x-coord of startPoint*/
	DoubleID getStartPointX(){char buffer[4096];sprintf_s (buffer, "%s.sp.spx",mName.c_str());return (const char*)buffer;}
	/*y-coord of startPoint*/
	DoubleID getStartPointY(){char buffer[4096];sprintf_s (buffer, "%s.sp.spy",mName.c_str());return (const char*)buffer;}
	/*z-coord of startPoint*/
	DoubleID getStartPointZ(){char buffer[4096];sprintf_s (buffer, "%s.sp.spz",mName.c_str());return (const char*)buffer;}
	/*Point to measure distance to.*/
	Double3ID getEndPoint(){char buffer[4096];sprintf_s (buffer, "%s.ep",mName.c_str());return (const char*)buffer;}
	/*x-coord of endPoint*/
	DoubleID getEndPointX(){char buffer[4096];sprintf_s (buffer, "%s.ep.epx",mName.c_str());return (const char*)buffer;}
	/*y-coord of endPoint*/
	DoubleID getEndPointY(){char buffer[4096];sprintf_s (buffer, "%s.ep.epy",mName.c_str());return (const char*)buffer;}
	/*z-coord of endPoint*/
	DoubleID getEndPointZ(){char buffer[4096];sprintf_s (buffer, "%s.ep.epz",mName.c_str());return (const char*)buffer;}
	/*Resultant distance value.*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.dist",mName.c_str());return (const char*)buffer;}
protected:
	DistanceDimShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DimensionShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DISTANCEDIMSHAPE_H__
