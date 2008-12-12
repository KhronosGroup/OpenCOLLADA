/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISTANCEBETWEEN_H__
#define __MayaDM_DISTANCEBETWEEN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node computes the distance between two points: point1 and
 point2. If inMatrix1 and inMatrix2 are provided, they are used to
 multiply the points before the computation.

 <p/>The distance result is returned in world units.
*/
class DistanceBetween : public DependNode
{
public:
public:
	DistanceBetween(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "distanceBetween"){}
	virtual ~DistanceBetween(){}
	/*First input point*/
	void setPoint1(const double3& p1){fprintf_s(mFile, "setAttr \".p1\" -type \"double3\" ");p1.write(mFile);fprintf_s(mFile,";\n");}
	/*X of first input point*/
	void setPoint1X(double p1x){if(p1x == 0) return; fprintf_s(mFile, "setAttr \".p1.p1x\" %f;\n", p1x);}
	/*Y of first input point*/
	void setPoint1Y(double p1y){if(p1y == 0) return; fprintf_s(mFile, "setAttr \".p1.p1y\" %f;\n", p1y);}
	/*Z of first input point*/
	void setPoint1Z(double p1z){if(p1z == 0) return; fprintf_s(mFile, "setAttr \".p1.p1z\" %f;\n", p1z);}
	/*Matrix to multiply the first point by*/
	void setInMatrix1(const matrix& im1){if(im1 == identity) return; fprintf_s(mFile, "setAttr \".im1\" -type \"matrix\" ");im1.write(mFile);fprintf_s(mFile,";\n");}
	/*Second input point*/
	void setPoint2(const double3& p2){fprintf_s(mFile, "setAttr \".p2\" -type \"double3\" ");p2.write(mFile);fprintf_s(mFile,";\n");}
	/*X of second input point*/
	void setPoint2X(double p2x){if(p2x == 0) return; fprintf_s(mFile, "setAttr \".p2.p2x\" %f;\n", p2x);}
	/*Y of second input point*/
	void setPoint2Y(double p2y){if(p2y == 0) return; fprintf_s(mFile, "setAttr \".p2.p2y\" %f;\n", p2y);}
	/*Z of second input point*/
	void setPoint2Z(double p2z){if(p2z == 0) return; fprintf_s(mFile, "setAttr \".p2.p2z\" %f;\n", p2z);}
	/*Matrix to multiply the second point by*/
	void setInMatrix2(const matrix& im2){if(im2 == identity) return; fprintf_s(mFile, "setAttr \".im2\" -type \"matrix\" ");im2.write(mFile);fprintf_s(mFile,";\n");}
	/*Output distance*/
	void setDistance(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Output distance*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
protected:
	DistanceBetween(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DISTANCEBETWEEN_H__
