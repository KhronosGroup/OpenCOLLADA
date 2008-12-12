/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKETHREEPOINTCIRCULARARC_H__
#define __MayaDM_MAKETHREEPOINTCIRCULARARC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMMakeCircularArc.h"
namespace MayaDM
{
/*
Compute a non rational circular arc (bspline form) passing
  through three given points in space.
 <br/>
  The degree of the created arc can be linear or cubic and is controlled
  using the attribute "degree". The number of spans of the curve can be
        controlled using the attribute "sections".
 <br/>
        The computed arc's center, radius, sweep angle and the normal
        of the plane containing the arc can be queried using the output
        attributes "center", "radius", "sweep" and "normal" respectively.
  The created arc available at "outputCurve" is non-rational.
 <p/>
*/
class MakeThreePointCircularArc : public MakeCircularArc
{
public:
public:
	MakeThreePointCircularArc(FILE* file,const std::string& name,const std::string& parent=""):MakeCircularArc(file, name, parent, "makeThreePointCircularArc"){}
	virtual ~MakeThreePointCircularArc(){}
	/*The point1 through which the circular arc must pass.*/
	void setPoint1(const double3& pt1){fprintf_s(mFile, "setAttr \".pt1\" -type \"double3\" ");pt1.write(mFile);fprintf_s(mFile,";\n");}
	/*The point1 through which the circular arc must pass.*/
	void setPoint1(const Double3ID& pt1){fprintf_s(mFile,"connectAttr \"");pt1.write(mFile);fprintf_s(mFile,"\" \"%s.pt1\";\n",mName.c_str());}
	/*X of the point1.*/
	void setPoint1X(double p1x){if(p1x == 0) return; fprintf_s(mFile, "setAttr \".pt1.p1x\" %f;\n", p1x);}
	/*X of the point1.*/
	void setPoint1X(const DoubleID& p1x){fprintf_s(mFile,"connectAttr \"");p1x.write(mFile);fprintf_s(mFile,"\" \"%s.pt1.p1x\";\n",mName.c_str());}
	/*Y of the point1.*/
	void setPoint1Y(double p1y){if(p1y == 1) return; fprintf_s(mFile, "setAttr \".pt1.p1y\" %f;\n", p1y);}
	/*Y of the point1.*/
	void setPoint1Y(const DoubleID& p1y){fprintf_s(mFile,"connectAttr \"");p1y.write(mFile);fprintf_s(mFile,"\" \"%s.pt1.p1y\";\n",mName.c_str());}
	/*Z of the point1.*/
	void setPoint1Z(double p1z){if(p1z == 0) return; fprintf_s(mFile, "setAttr \".pt1.p1z\" %f;\n", p1z);}
	/*Z of the point1.*/
	void setPoint1Z(const DoubleID& p1z){fprintf_s(mFile,"connectAttr \"");p1z.write(mFile);fprintf_s(mFile,"\" \"%s.pt1.p1z\";\n",mName.c_str());}
	/*The point2 through which the circular arc must pass.*/
	void setPoint2(const double3& pt2){fprintf_s(mFile, "setAttr \".pt2\" -type \"double3\" ");pt2.write(mFile);fprintf_s(mFile,";\n");}
	/*The point2 through which the circular arc must pass.*/
	void setPoint2(const Double3ID& pt2){fprintf_s(mFile,"connectAttr \"");pt2.write(mFile);fprintf_s(mFile,"\" \"%s.pt2\";\n",mName.c_str());}
	/*X of the point2.*/
	void setPoint2X(double p2x){if(p2x == 0) return; fprintf_s(mFile, "setAttr \".pt2.p2x\" %f;\n", p2x);}
	/*X of the point2.*/
	void setPoint2X(const DoubleID& p2x){fprintf_s(mFile,"connectAttr \"");p2x.write(mFile);fprintf_s(mFile,"\" \"%s.pt2.p2x\";\n",mName.c_str());}
	/*Y of the point2.*/
	void setPoint2Y(double p2y){if(p2y == 0) return; fprintf_s(mFile, "setAttr \".pt2.p2y\" %f;\n", p2y);}
	/*Y of the point2.*/
	void setPoint2Y(const DoubleID& p2y){fprintf_s(mFile,"connectAttr \"");p2y.write(mFile);fprintf_s(mFile,"\" \"%s.pt2.p2y\";\n",mName.c_str());}
	/*Z of the point2.*/
	void setPoint2Z(double p2z){if(p2z == 0) return; fprintf_s(mFile, "setAttr \".pt2.p2z\" %f;\n", p2z);}
	/*Z of the point2.*/
	void setPoint2Z(const DoubleID& p2z){fprintf_s(mFile,"connectAttr \"");p2z.write(mFile);fprintf_s(mFile,"\" \"%s.pt2.p2z\";\n",mName.c_str());}
	/*The point3 through which the circular arc must pass.*/
	void setPoint3(const double3& pt3){fprintf_s(mFile, "setAttr \".pt3\" -type \"double3\" ");pt3.write(mFile);fprintf_s(mFile,";\n");}
	/*The point3 through which the circular arc must pass.*/
	void setPoint3(const Double3ID& pt3){fprintf_s(mFile,"connectAttr \"");pt3.write(mFile);fprintf_s(mFile,"\" \"%s.pt3\";\n",mName.c_str());}
	/*X of the point3.*/
	void setPoint3X(double p3x){if(p3x == 1) return; fprintf_s(mFile, "setAttr \".pt3.p3x\" %f;\n", p3x);}
	/*X of the point3.*/
	void setPoint3X(const DoubleID& p3x){fprintf_s(mFile,"connectAttr \"");p3x.write(mFile);fprintf_s(mFile,"\" \"%s.pt3.p3x\";\n",mName.c_str());}
	/*Y of the point3.*/
	void setPoint3Y(double p3y){if(p3y == 0) return; fprintf_s(mFile, "setAttr \".pt3.p3y\" %f;\n", p3y);}
	/*Y of the point3.*/
	void setPoint3Y(const DoubleID& p3y){fprintf_s(mFile,"connectAttr \"");p3y.write(mFile);fprintf_s(mFile,"\" \"%s.pt3.p3y\";\n",mName.c_str());}
	/*Z of the point3.*/
	void setPoint3Z(double p3z){if(p3z == 0) return; fprintf_s(mFile, "setAttr \".pt3.p3z\" %f;\n", p3z);}
	/*Z of the point3.*/
	void setPoint3Z(const DoubleID& p3z){fprintf_s(mFile,"connectAttr \"");p3z.write(mFile);fprintf_s(mFile,"\" \"%s.pt3.p3z\";\n",mName.c_str());}
	/*The radius of the generated circular arc*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The point1 through which the circular arc must pass.*/
	Double3ID getPoint1(){char buffer[4096];sprintf_s (buffer, "%s.pt1",mName.c_str());return (const char*)buffer;}
	/*X of the point1.*/
	DoubleID getPoint1X(){char buffer[4096];sprintf_s (buffer, "%s.pt1.p1x",mName.c_str());return (const char*)buffer;}
	/*Y of the point1.*/
	DoubleID getPoint1Y(){char buffer[4096];sprintf_s (buffer, "%s.pt1.p1y",mName.c_str());return (const char*)buffer;}
	/*Z of the point1.*/
	DoubleID getPoint1Z(){char buffer[4096];sprintf_s (buffer, "%s.pt1.p1z",mName.c_str());return (const char*)buffer;}
	/*The point2 through which the circular arc must pass.*/
	Double3ID getPoint2(){char buffer[4096];sprintf_s (buffer, "%s.pt2",mName.c_str());return (const char*)buffer;}
	/*X of the point2.*/
	DoubleID getPoint2X(){char buffer[4096];sprintf_s (buffer, "%s.pt2.p2x",mName.c_str());return (const char*)buffer;}
	/*Y of the point2.*/
	DoubleID getPoint2Y(){char buffer[4096];sprintf_s (buffer, "%s.pt2.p2y",mName.c_str());return (const char*)buffer;}
	/*Z of the point2.*/
	DoubleID getPoint2Z(){char buffer[4096];sprintf_s (buffer, "%s.pt2.p2z",mName.c_str());return (const char*)buffer;}
	/*The point3 through which the circular arc must pass.*/
	Double3ID getPoint3(){char buffer[4096];sprintf_s (buffer, "%s.pt3",mName.c_str());return (const char*)buffer;}
	/*X of the point3.*/
	DoubleID getPoint3X(){char buffer[4096];sprintf_s (buffer, "%s.pt3.p3x",mName.c_str());return (const char*)buffer;}
	/*Y of the point3.*/
	DoubleID getPoint3Y(){char buffer[4096];sprintf_s (buffer, "%s.pt3.p3y",mName.c_str());return (const char*)buffer;}
	/*Z of the point3.*/
	DoubleID getPoint3Z(){char buffer[4096];sprintf_s (buffer, "%s.pt3.p3z",mName.c_str());return (const char*)buffer;}
	/*The radius of the generated circular arc*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
protected:
	MakeThreePointCircularArc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):MakeCircularArc(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKETHREEPOINTCIRCULARARC_H__
